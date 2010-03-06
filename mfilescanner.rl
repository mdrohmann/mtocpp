#include "mfilescanner.h"

#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
extern "C" {
#include <unistd.h>
}

using std::cerr;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::set;
using std::istream;

%%{
  machine MFileScanner;
  write data;

  # end of file character
  EOF = 0;

  # any character other than end of file
  default = ^0;

  # end of line character
  EOL = ('\r'? . '\n') @{line++;};

  # scanner for comment blocks
  in_comment_block :=
  (
   # comment line begins with a percent sign
   '%'
     @{ tmp_p = p+1; cout << " *"; }
   # and then some default characters
   . (default - '\n')* . EOL
     @{ cout.write(tmp_p, p - tmp_p+1); }
  )*
  $!{
    cout << "*/\n";
    fhold;
    fret;
  };

  # executed when end of file ist reached
  action end_of_file
  {
    end_function();
  }

  # executed when we reached a comment block
  action in_c_block
  {
    cout.write(tmp_p, p-tmp_p+1);
    fcall in_comment_block;
  }

  action echo { cout << fc; }

  action st_tok { tmp_p = p; }

  action echo_tok { cout.write(tmp_p, p - tmp_p); }

  action string_tok { tmp_string.assign(tmp_p, p-tmp_p); }

  # comment in function body that might also be added to the doxygen block for
  # the function description
  is_doxy_comment =
    (
    # if percent character is followed by a bar we make the comment a doxygen
    # comment
     '|' @{ cout << "/**"; tmp_p = p+1; } . (default - '\n')* . EOL
     |
    # else: a regular comment
     ( (default - '|') @{ cout << "/*"; tmp_p = p; } )
     . (default - '\n')* . EOL
    );

  # comment block in function body
  comment_block = [ \t]* . '%' . is_doxy_comment;

  # documentation line begin
  doc_begin = [\t ]* . '%' @{ tmp_p = p + 1; };

  # swallow a comment line till the end of the line (make it a c comment)
  garble_comment_line =
    ( (default - '\n')* . EOL )
      @{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      };

  # white space or comment
  WSOC =
    ( [ \t]+
      | ('%' @{ tmp_p = p+1; } . garble_comment_line)
      | ('...'.[ \t]*.EOL)
    );

  # matlab identifier
  IDENT = [A-Za-z_][A-Za-z0-9_]**;

  # matlab identifier with .
  IDENT_W_DOT = [A-Za-z_][A-Za-z0-9_.]**;

  # default arguments in function declarations
  default_arg = [^,)]** @echo;

  # parameter list for functions
  paramlist =
    (
     (WSOC | [,\n] @echo | ( '=' . default_arg ) )+
     |
     # matlab identifier (parameter)
     (IDENT)
       >st_tok
       %{
         string s(tmp_p, p - tmp_p);
         // add an empty docu block for parameter \a s
         param_list_[s] = DocuBlock();
         paramlist_.push_back(s);
         cout << "matlabtypesubstitute " << s;
       }
    )**;

  # return parameter list for functions
  lparamlist =
    ( (WSOC | [\n])+
      | ',' @{ cout << "::"; }
      # matlab identifier (return value)
      | ( IDENT > st_tok
          %{
            string s(tmp_p, p - tmp_p);
            returnlist_.push_back(s);
            // add an empty docu block for return value \a s
            return_list_[s] = DocuBlock();
            cout << s;
          }
        )
    )**;

  # return parameter or return parameter list
  lparams =
    (
      (
        (
         # matlab identifier
         IDENT
           >st_tok
           %{
             string s(tmp_p, p - tmp_p);
             returnlist_.push_back(s);
             // add an empty docu block for single return value \a s
             return_list_[s] = DocuBlock();
             cout << "ret::substitutestart::" << s << "::retsubstituteend ";
           }
        )
        | ( '[' @{cout << "rets::substitutestart::";}
          . lparamlist
          . ']' @{cout << "::retssubstituteend ";}
          )
      )
      . ([ \t]*
          @echo)
      :> '=' . WSOC*
    );

  funcline := |*
    ([ \t]+)
      => { cout.write(ts, te-ts); };

    ('...' . [ \t]* . EOL)
      => { cout.write(ts, te-ts); };

    ('%' @{ tmp_p = p + 1; } . garble_comment_line);

    # automatically add return value fields to retval_list_
    (
     # matlab identifier (which can be a return value and a structure)
     (IDENT
        %{tmp_string.assign(ts,p-ts);})
     . '.'
     # matlab identifer (fieldname)
     . (IDENT_W_DOT >(st_tok) %{tmp_p2 = p;} )
     # if a value is assigned to this field, the field is generated/modified
     . [ \t]* . '=' . (^'=')
    )
    => {
      fhold;
      // store fieldname
      string s(tmp_p, tmp_p2 - tmp_p);
      cout << tmp_string << "." << s << "=";
      // typedef of iterators
      typedef DocuList     :: iterator list_iterator;
      typedef DocuListMap  :: iterator map_iterator;
      typedef DocuBlock    :: iterator iterator;

      // check wether first IDENT is a return value
      iterator it = find(returnlist_.begin(), returnlist_.end(), tmp_string);
      if(it != returnlist_.end())
      {
        // if it is a return value...
        // ... check wether its found field is still missing a DocuBlock in the
        // retval list.
        bool missing = true;
        map_iterator rvoit = retval_list_.find(tmp_string);
        if(rvoit != retval_list_.end())
        {
          list_iterator lit = (*rvoit).second.find(s);
          if(lit != (*rvoit).second.end())
            missing = false;
        }
        // if it is missing, add an empty docu block
        if(missing)
        {
          retval_list_[tmp_string][s] = DocuBlock();
        }
      }
    };

    # automatically add parameter fields to required_list_
    (
     # matlab identifier (which can be a parameter and a structure)
     (IDENT
        %{tmp_string.assign(ts,p-ts);})
     . '.'
     # matlab identifer (fieldname)
     . (IDENT_W_DOT
         >(st_tok)
       )
    )
    => {
      // store fieldname
      string s(tmp_p, p - tmp_p+1);
      cout << tmp_string << "." << s;
      typedef DocuList     :: iterator list_iterator;
      typedef DocuListMap  :: iterator map_iterator;
      typedef DocuBlock    :: iterator iterator;

      // check wether first IDENT is a parameter
      iterator it = find(paramlist_.begin(), paramlist_.end(), tmp_string);
      if(it != paramlist_.end())
      {
        // if it is a parameter ...
        // ... check wether its found field is still missing a DocuBlock in the
        // return, optional and the required list.
        bool missing = true;
        map_iterator rvoit = retval_list_.find(tmp_string);
        if(rvoit != retval_list_.end())
        {
          list_iterator lit = (*rvoit).second.find(s);
          // found match in retval list
          if(lit != (*rvoit).second.end())
            missing = false;
        }
        map_iterator moit = optional_list_.find(tmp_string);
        if(moit != optional_list_.end())
        {
          // found match in optional list
          list_iterator lit = (*moit).second.find(s);
          if(lit != (*moit).second.end())
            missing = false;
        }
        map_iterator roit = required_list_.find(tmp_string);
        if(roit != required_list_.end())
        {
          // found match in required list
          list_iterator lit = (*roit).second.find(s);
          if(lit != (*roit).second.end())
            missing = false;
        }
        // in case it IS missing, add an empty field to the required block.
        if(missing)
        {
          required_list_[tmp_string][s] = DocuBlock();
        }
      }
    };

    # add a @deprecated command to function declaration if disp_deprecated is
    # used in function body
    ('disp_deprecated' . [ \t]*
      . (
          ';'
            @{tmp_string.assign("");}
          |
          '(' . [\t ]* . "'"
          . ([^\n']*
              >(st_tok)
              %(string_tok)
            )
          . "'" . [\t ]* . ')' . [\t ]* . ';'
        )
      . [\t ]* . EOL
    )
      => {
        string s;
        if(tmp_string.empty())
        {
          s.assign("@deprecated function deprecated\n");
        }
        else
        {
          s.assign("@deprecated method deprecated, use \'" + tmp_string + "\' instead.\n");
        }
        docuextra_.push_back(s);
        fhold;
      };

    # simple matlab identifier
    (IDENT)
      => { cout.write(ts, te-ts); };

    # translate curly brackets in edgy brackets, because otherwise the doxygen
    # parser breaks.
    ('{')
      => { cout << '['; };

    ('}')
      => { cout << ']'; };

    # simply output all other characters
    (default - [\n{}])
      => { cout << fc; };

    # after EOL try to check for new function
    EOL
      => { cout << fc; fgoto funcbody; };

  *|;

  funcbody := |*

      ('% TO BE ADJUSTED TO NEW SYNTAX\n')
        => {
          new_syntax_ = true;
          cout << "*/\n"; //cout << "add to special group */\n";
        };

      # a comment block
      (comment_block)
        => {
          cout.write(tmp_p, p - tmp_p+1);
          fcall in_comment_block;
        };

      # empty line
      ([ \t]* . EOL)
        => { cout << '\n'; };

      # line not beginning with word 'function'
      ([ \t]*
       . ( (default - [ \r\t\n%])+ - 'function' )
       . ( WSOC | EOL )
      )
        => {
          p = ts-1;
          // further parse the function body line
          fgoto funcline;
        };

      # line beginning with word 'function'
      ([ \t]*. 'function ')
      {
        p = ts-1;
        // end the previous function if existent
        end_function();
        fgoto main;
      };

      (EOF) $eof(end_of_file);

  *|;

  # fill a docublock list with input
  fill_list := |*

  # match an argument
  ( doc_begin . [ \t]*
    . "'"? . ( ([A-Za-z][A-Za-z0-9_{},()[\].]*)  >{tmp_p3 = p;} %{tmp_p2 = p;} ) . "'"? . [ \t]* . ":" @(st_tok)
    . ( default - '\n' )* . EOL
  )
    => {
      tmp_string.assign(tmp_p3, tmp_p2 - tmp_p3);
      //    std::cout << tmp_string << '\n';
      (*clist_)[tmp_string].push_back(string(tmp_p+1, p - tmp_p));
    };

  # expand the paragraph for last argument matched
  ( doc_begin . [ \t]*
    # at least one word (non white-space characters and no double-colon)
    . ( default - [ \r\t:\n] )+ .
    # followed by something that is a white-space or a new-line, i.e *no*
    # double-colon
    (
     EOL
     |
     [ \t]+ . (EOL | [^ \r\n\t:] . (default - '\n')* . EOL)
     # [ \t] . (default - '\n')* . EOL
    )
  )
    => {
      string s(tmp_p, p - tmp_p + 1);
      (*clist_)[tmp_string].push_back(s);
      /*cout << "add something results in\n" << (*clist_)[tmp_string];*/
    };

  # return on empty line
  ( doc_begin . [ \t]* . EOL )
    => { /*cout << "empty line\n";*/ fret; };

   # end of comment block
  ( [\t ]* . ( (default - '%') | EOL) )
    => {
      p =ts-1;
      // cout << "*/\n";
      fret;
    };

  *|;

  doxy_get_body := |*

    # begin required_list
    ( doc_begin . [ \t]*
      . /required fields of /i
      . (IDENT >(st_tok) %(string_tok) )
      . [ \t]* . ':' . [ \t]* . EOL
    )
      => {
        //cout << tmp_string << '\n';
        clist_ = &(required_list_[tmp_string]);
        docline = false;
        fcall fill_list;
      };

    # begin optional_list
    ( doc_begin . [ \t]*
      . /optional fields of /i
      . (IDENT
          >(st_tok)
          %(string_tok) )
      . [ \t]* . ':' . [ \t]* . EOL )
      => {
        clist_ = &(optional_list_[tmp_string]);
        docline = false;
        fcall fill_list;
      };

    # begin optional_list
    ( doc_begin . [ \t]*
      . /generated fields of /i
      . (IDENT
          >(st_tok)
          %(string_tok) )
      . [ \t]* . ':' . [ \t]* . EOL )
      => {
        clist_ = &(retval_list_[tmp_string]);
        docline = false;
        fcall fill_list;
      };

    # begin parameter list
    ( doc_begin . [ \t]*
      . /parameters/i . [ \t]* . ':'
      . [ \t]* . EOL )
      => {
        clist_ = &param_list_;
        docline = false;
        fcall fill_list;
      };

    # begin return list
    ( doc_begin . [ \t]*
      . /return values/i . [ \t]* . ':'
      . [ \t]* . EOL )
      => {
        clist_ = &return_list_;
        docline = false;
        fcall fill_list;
      };

    # empty line
    ( doc_begin . [ \t]* . EOL )
      => {
        /*cout << "*\n  ";*/
        docubody_.push_back("\n");
        docline = false;
      };

    # paragraph line
    ( [ \t]* . '%' )
      => {
        if(!docline)
        {
          docline = true;
          tmp_p = p;
        }
      };

    # paragraph line with "see also" substituted by "@sa"
    ( /see also/i )
      => {
        if(!docline)
        {
          p = ts-1;
          fgoto funcbody;
        }
        string s;
        s.assign(tmp_p+1, ts - tmp_p-1);
        docubody_.push_back(s+"@sa ");
        tmp_p = p+1;
      };

    # words
#    ( default - [ \t:%'`\n] )+
    ( default - [ \t:%\r\n] )+
      => {
        if(!docline)
        {
          p = ts-1;
          fgoto funcbody;
        }
      };

    # non-words/non-whitespace
#    ([:'`]) => {
    (':') => {
        if(!docline)
        {
          p = ts-1;
          fgoto funcbody;
        }
      };


    # whitespace only
    ( [ \t] );

    # titled paragraph
    ( ':' . EOL ) =>
    {
        if(! docline)
          fgoto funcbody;
        else
        {
          docubody_.push_back("@par " + string(tmp_p+1, ts - tmp_p-1)+"\n");
          docline = false;
        }
      };

    # end of line
    ( EOL )
      => {
        // cout << "*/\n";
        if(! docline)
          fgoto funcbody;
        else
        {
          int offset = ( latex_begin ? 0 : 1 );
          docubody_.push_back(string(tmp_p+1, p - tmp_p - offset));
          docline = false;
        }
      };

  *|;

  # swallow the synopsis line
  doxyfunction_garble := |*
    garbage = doc_begin . ( (default - '\n' )* -- '...' );

    ( garbage . '...' . [\t ]* .  EOL );

    ( garbage . EOL )
      => { fgoto doxy_get_brief; };
  *|;


  # read first paragraph
  doxy_get_brief := |*

    # read in one comment line
    ( doc_begin . [\t ]*
      . (default - [\r\n\t ]) . (default - '\n')* . EOL
    )
      => {
        /* cout << "*"; cout.write(tmp_p, p - tmp_p+1); */
        docuheader_.push_back(string(tmp_p, p - tmp_p+1));
      };

    # empty line
    ( doc_begin . [\t ]* . EOL )
      => {
        /*cout << "*\n";*/
        fgoto doxy_get_body;
      };

    # end of comment block;
    ( [\t ]* . [^%] ) 
      => {
        fhold;
        //cout << "*/\n";
        fgoto funcbody;
      };

  *|;

  # garble synopsis line and then parse the documentation header
  doxyheader := (
    '%' . [ \t]* .
       ( 'function'
         . ( default - [;)\r\n.] )* .
         (
          ( [);] . (default - '\n')* . EOL )
            @{ fgoto doxy_get_brief; }
          |
          ( '...' . [ \t]* . EOL
            @{ fgoto doxyfunction_garble; }
          )
         )
      )
      $!{
        p = tmp_p - 2;
        fgoto doxy_get_brief;
      }
   );

  # after function declaration expect a documentation block or the function
  # body
  expect_doxyblock :=
  (
    doc_begin
      @{
        //cout << "/*";
        p--;
        fgoto doxyheader;
      }
  ) $!{
    fhold;
    fgoto funcbody;
  };

  # function declaration
  funcdef = (
      WSOC* .
      # return values (if found opt = true)
      (lparams)? @{opt=true;} .
      # matlab identifier (function name stored in cfuncname_)
      ( IDENT
          >st_tok
          %{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
      )
      . WSOC*
      . (
           ('('
                 @{
                 // no return values?
                 if(!opt)
                 {
                   cout << "noret::substitute ";
                   opt=false;
                 }
                 if(!is_first_function_)
                   cout << "mtoc_subst_" << fnname_ << "_tsbus_cotm_";
                 cout << cfuncname_ << '(';
                 })
           # parameter list
           . paramlist
           . (')' @echo) . ( WSOC | ';' )*
           . EOL
           @{
             cout << " {\n";
             // check for documentation block
             fgoto expect_doxyblock;
           }
        # no parameter list => script
        | (';'? . EOL) @{
                         cout << "noret::substitute ";
                         if(!is_first_function_)
                           cout << "mtoc_subst_" << fnname_ << "_tsbus_cotm_";
                         cout << cfuncname_ << "() {\n";
                         fgoto expect_doxyblock;
                        }
        )
      );

  # no function definition => a script
  script := (default)
    @{
       string :: size_type found = filename_.rfind("/");
       if(found == string :: npos)
         found = -1;
       string funcname = filename_.substr(found+1, filename_.size()-3-found);
       cfuncname_.assign( funcname );
       cout << "noret::substitute ";
       if(!is_first_function_)
         cout << "mtoc_subst_" << fnname_ << "_tsbus_cotm_";
       cout << funcname << "() {\n";
       is_script_ = true;
       fhold;
       fgoto expect_doxyblock;
     };

  funct :=
  (
    (
      comment_block @in_c_block
      | [ \t]*. EOL
    )*
    . [\t]* . 'function'
    . funcdef
  ) $eof( end_of_file )
  ;

  expect_function_or_script =
  (
    # either we find a function definition with a possibly preceding comment
    # block or we have a script
    any @{ fhold; tmp_p = p; } .
    (
      [ \t]*. '%' . (any - '\n')* . EOL
      | [ \t]*. EOL
    )*
    . [\t]* . 'function'
    @{
    p=tmp_p;
    fgoto funct;
    }
  )
  $!{
    p=tmp_p;
    fgoto script;
  }
  ;

  main := expect_function_or_script*;

}%%


// constructor
MFileScanner :: MFileScanner(istream & fin, const std::string & filename,
                             const std::string & conffilename, bool latex_output) :
  fin_(fin), filename_(filename),
  latex_output_(latex_output), cscan_(filename_, conffilename),
  fnname_(filename),
  line(1),
  ts(0), have(0), top(0),
  opt(false), new_syntax_(false), is_script_(false), is_first_function_(true)
{
  string::size_type found = fnname_.rfind("/");
  if(found != string::npos)
    fnname_ = fnname_.substr(found+1);
  for( std::string::size_type i = 0; i < fnname_.size(); ++i )
  {
    if(fnname_[i] == '@')
      fnname_[i] = '_';
    else if(fnname_[i] == '.')
      fnname_[i] = '_';
  }

  cscan_.execute();
};

// run the scanner
int MFileScanner :: execute()
{
  std::ios::sync_with_stdio(false);

  %% write init;

  /* Do the first read. */
  bool done = false;
  while ( !done )
  {
    char *p = buf + have;
    char *tmp_p = p, *tmp_p2 = p, *tmp_p3 = p;
    string tmp_string;
    bool docline = false;
    bool latex_begin = true;
    int space = BUFSIZE - have;

    if ( space == 0 )
    {
      /* We filled up the buffer trying to scan a token. */
      cerr << "OUT OF BUFFER SPACE" << endl;
      exit(-1);
    }

    fin_.read( p, space );
    int len = fin_.gcount();
    char *pe = p + len;
    char *rpe = pe;
    char *eof = 0;

    /* If we see eof then append the EOF char. */
    if ( fin_.eof() )
    {
      char eof_c = *pe;
      *pe = '\n';
      pe++;
      *pe = eof_c;
      eof = pe;
      rpe = pe;

      done = true;
    }
    else
    {
      /* Find the last newline by searching backwards. This is where
       * we will stop processing on this iteration. */
      while ( pe >= p )
      {
        if( *pe != '\n')
          pe--;
        else
        {
          if(pe >= p+3
              && *(pe-1) == '.' && *(pe-2) == '.' && *(pe-3) == '.')
            pe-=3;
          else
            break;
        }
      }
    }

    %% write exec;

    /* Check if we failed. */
    if ( cs == MFileScanner_error )
    {
      /* Machine failed before finding a token. */
      cerr << std::string(filename_) << ": PARSE ERROR in line " << line << endl;
      exit(-1);
    }

    /* Now set up the prefix. */
    if ( ts == 0 )
    {
      have = rpe - pe;
      /* cerr << "memmove by " << have << "bytes\n";*/
      memmove( buf, pe, have );
    }
    else
    {
      have = rpe - ts;
      /* cerr << "memmove by " << have << "bytes to ts\n";*/
      memmove( buf, ts, have );
    }

    if ( ts != 0 )
    {
      te -= (ts-buf);
      ts = buf;
    }
  }

  return 0;
}

// escape '@' and '\' characters in string \a s
const string & MFileScanner::escape_chars(std::string & s)
{
  string::size_type found = s.find_first_of("@\\");
  while(found != string::npos )
  {
    s.insert(found, "\\");
    found = s.find_first_of("@\\",found+2);
  }
  return s;
}

// standard brief text (replace '_' -> ' ' in s)
const string & MFileScanner::replace_underscore(std::string & s)
{
  string::size_type found = s.find("_");
  while(found != string::npos )
  {
    s[found] = ' ';
    found = s.find("_", found+1);
  }
  return s;
}

// pretty print the documentation block \a block
void MFileScanner::write_docu_block(const DocuBlock & block)
{
  bool add_prefix   = false;
  bool latex_begin  = true;
  bool not_verbatim = true;
  for( unsigned int i = 0; i < block.size(); i += 1 )
  {
    // begin all documentation lines after the first one with an asterisk
    if(add_prefix)
      cout << "* ";

    add_prefix = false;
    // read in new line of docu block
    const string & s = block[i];

    // parse for special comments
    string::size_type j=0;
    const char * tokens = "\'`@\n";
    bool last_char_escaped = false;
    for( string::size_type i = 0; j < s.size(); i=j )
    {
      j=s.find_first_of(tokens,i+1);
      if(j==string::npos)
        j=s.size();
      if(s[j-1] == '\\' && not_verbatim && latex_begin)
        --j;
      // respect @code and @verbatim blocks
      if(s[i] == '@')
      {
        if(s.substr(i+1,4) == "code" || s.substr(i+1,8) == "verbatim")
          not_verbatim = false;
        else if(s.substr(i+1,7) == "endcode" || s.substr(i+1,11) == "endverbatim")
          not_verbatim = true;
        cout << s.substr(i,j-i);
      }
      // use typewriter fonts for words in single quotes
      else if(s[i] == '\'' && not_verbatim && latex_begin)
      {
        if(j != s.size() && s[j] == '\'' && !last_char_escaped)
        {
          cout << "<tt>" << s.substr(i+1, j-i-1) << "</tt>";
          ++j;
        }
        else
          cout << s.substr(i,j-i);
      }
      // use latex output for words in backtick quotes
      else if(s[i] == '`' && not_verbatim)
      {
        string lout;
        if(!last_char_escaped)
        {
          // in case of double backtick quotes, use latex block
          if(s[i+1] == '`')
          {
            if(latex_begin)
              lout = "@f[";
            else
              lout = "@f]";
            ++i;
            j=s.find_first_of(tokens,i+1);
            if(j==string::npos)
              j=s.size();
          }
          else
            lout = "@f$";
          if(latex_begin)
            latex_begin = false;
          else
            latex_begin = true;
          ++i;
        }
        else
        {
          lout = "";
        }
        cout << lout << s.substr(i, j-i);
      }
      // new line
      else if(s[i] == '\n')
      {
        cout << "\n  ";
        if(latex_begin)
          add_prefix = true;
        else
        {
          cout << "  ";
          add_prefix = false;
        }
      }
      else
      {
        cout << s.substr(i,j-i);
      }
      if(s[j-1] != '\\' && s[j] == '\\')
      {
        last_char_escaped = true;
      }
      else
        last_char_escaped = false;
      if(s[j] == '\\')
        ++j;
    }
  }
}

// pretty print the documentation block list \a list for the list item named \a
// item_text. If docu blocks are empty, \a alternative is used. The alternative
// is normally read in by the confscanner.
void MFileScanner::write_docu_list(const DocuList & list,
                                   const string & item_text,
                                   const DocuList & alternative,
                                   const string separator = string())
{
  typedef DocuList :: const_iterator list_iterator;
  list_iterator lit = list.begin();
  // iterate over documentation blocks
  for(; lit != list.end(); ++lit)
  {
    cout << "* " << item_text << " " << (*lit).first << separator << "    ";
    const DocuBlock & block = (*lit).second;
    // block is empty?
    if(block.empty())
    {
      // then look for alternative documentation block form global
      // configuration file or use default text generated from variable name.
      list_iterator alit = alternative.find((*lit).first);
      if(alit == alternative.end() || (*alit).second.empty())
      {
        std::string s((*lit).first);
        cout << replace_underscore(s) << "\n  ";
      }
      else
        write_docu_block((*alit).second);
    }
    else
      write_docu_block(block);
  }
}

// pretty print a documentation block list map \a listmap with prepended title
// \a text. If listmap entry is empty, \a altlistmap is used instead.
void MFileScanner::write_docu_listmap(const DocuListMap & listmap,
                                      const string & text,
                                      const DocuListMap & altlistmap)
{
  typedef DocuListMap :: const_iterator map_iterator;
  if(!listmap.empty())
  {
    map_iterator mit = listmap.begin();
    for(; mit != listmap.end(); ++mit)
    {
      cout << "*\n  ";
      cout << "* " << text << (*mit).first << ":\n  ";
      map_iterator amit = altlistmap.find((*mit).first);
      write_docu_list((*mit).second, "@arg \\c", ( amit != altlistmap.end() ? (*amit).second : DocuList() ), "&nbsp;&mdash;&nbsp;");
    }
//    cout << "* </TABLE>\n  ";

  }
}

// end a function and pretty print the documentation for this function
void MFileScanner::end_function()
{
  typedef GroupSet     :: iterator group_iterator;
  typedef DocuBlock    :: iterator block_iterator;
  typedef DocuList     :: iterator list_iterator;
  typedef DocuListMap  :: iterator map_iterator;
  // end function
  cout << "}\n";
  // is the first function?
  if(is_first_function_)
  {
    string tempfname(filename_);

    if(! latex_output_ )
    {
      // Then make a file documentation block
      cout << "/** @file \"" << tempfname << "\"\n  ";

      // add @ingroup commands from the configuration file
      if((! groupset_.empty() || ! cscan_.groupset_.empty() ))
      {
        cout << "* @ingroup ";
        bool not_first = false;
        group_iterator git = cscan_.groupset_.begin();
        for(; git != cscan_.groupset_.end(); ++git)
        {
          if(not_first)
            cout << " ";
          else
            not_first = true;

          cout << *git;
        }
        groupset_.clear();
      }
      cout << "*/\n";
    }
  }
  cout << "/*";
  if(latex_output_)
  {
    if(! cscan_.groupset_.empty() )
    {
      // specify the @ingroup command
      cout << "* @ingroup ";
      bool not_first = false;
      group_iterator git = cscan_.groupset_.begin();
      for(; git != cscan_.groupset_.end(); ++git)
      {
        if(not_first)
          cout << " ";
        else
          not_first = true;

        cout << *git;
      }
    }
    cout << "\n  ";
  }
  // specify the @fn part
  cout << "* @fn ";
  if(returnlist_.size() == 0)
    cout << "noret::substitute ";
  else if(returnlist_.size() == 1)
  {
    cout << "ret::substitutestart::" << returnlist_[0] << "::retsubstituteend ";
  }
  else
  {
    cout << "rets::substitutestart::";
    for(unsigned int i = 0; i < returnlist_.size(); ++i)
    {
      if(i != 0)
        cout << "::";

      cout << returnlist_[i];
    }
    cout << "::retssubstituteend ";
  }
  returnlist_.clear();

  bool first = true;
  if(!is_first_function_)
    cout << "mtoc_subst_" << fnname_ << "_tsbus_cotm_";
  cout << cfuncname_;
  if(paramlist_.size() == 0)
    cout << "\n  ";
  else
  {
    cout << "(";
    for(unsigned int i=0; i < paramlist_.size(); ++i)
    {
      if(!first)
        cout << ",";
      else
        first = false;
      cout << "matlabtypesubstitute " << paramlist_[i];
    }
    paramlist_.clear();
    cout << ")\n  ";
  }

  // specify the @brief part
  cout << "* @brief ";
  if(docuheader_.empty() && cscan_.docuheader_.empty())
  {
    string s(cfuncname_);
    cout << replace_underscore(s) << "\n  ";
  }
  else
  {
    if(! docuheader_.empty())
    {
      write_docu_block(docuheader_);
    }
    if(! cscan_.docuheader_.empty())
    {
      write_docu_block(cscan_.docuheader_);
    }
  }
  docuheader_.clear();
  cout << "*\n  ";

  // specify the @details part

  // standard body definitions
  if(!docubody_.empty())
  {
    cout << "*\n  * ";
    write_docu_block(docubody_);
  }
  docubody_.clear();
  if(!cscan_.docubody_.empty())
  {
    cout << "*\n  * ";
    write_docu_block(cscan_.docubody_);
  }
  // parameters
  if(!param_list_.empty())
  {
    cout << "*\n  ";
    write_docu_list(param_list_, "@param", cscan_.param_list_);
    param_list_.clear();
  }
  // return values
  if(!return_list_.empty())
  {
    cout << "*\n  ";
    write_docu_list(return_list_, "@retval", cscan_.return_list_);
    return_list_.clear();
  }
  // required fields
  write_docu_listmap(required_list_, "@par Required fields of ", cscan_.field_docu_);
  required_list_.clear();

  // optional fields
  write_docu_listmap(optional_list_, "@par Optional fields of ", cscan_.field_docu_);
  optional_list_.clear();

  // return fields
  write_docu_listmap(retval_list_, "@par Generated fields of ", cscan_.field_docu_);
  retval_list_.clear();

  // extra docu fields
  if(! cscan_.docuextra_.empty())
  {
    cout << "*\n  * ";
    write_docu_block(cscan_.docuextra_);
  }
  if( new_syntax_ )
  {
    cout << "* @synupdate Syntax needs to be updated! \n  ";
  }
  docuextra_.clear();
  cout << "*/\n";
  is_first_function_ = false;
}

// main routine
int main(int argc, char ** argv)
{
  istream * fcin;
  std::ifstream fin;
  string filename;
  if(argc >= 2)
  {
    try
    {
      fin.open(argv[1]);
      fcin = &fin;
      filename = argv[1];
    }
    catch (std::ifstream::failure e)
    {
      cout << "Exception opening/reading file";
      exit(-1);
    }
  }
  else
  {
    fcin = &cin;
    filename = "stdin";
  }

  bool latex_output = false;
  if(argc == 3)
  {
    latex_output = (strncmp(argv[2],"1",1)==0) ? true : false;
  }

  std::string conffilename;
  if(argc == 4)
  {
    conffilename = std::string(argv[3]);
  }

  char buf[1000];
  char * dummy = getcwd(buf, 1000);
  dummy = 0;

  string::size_type found = 0;
  string cwd(buf);
  found = filename.find(cwd);
  if(found!=string::npos)
    filename = filename.substr(cwd.size()+1);
  MFileScanner scanner(*fcin, filename, conffilename, latex_output);
  scanner.execute();
  return 0;
}

/* vim: set et sw=2 ft=ragel: */

