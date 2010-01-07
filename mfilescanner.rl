#include "mfilescanner.h"

#include <cstring>
#include <cstdlib>
#include <iostream>
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

  EOF = 0;

  default = ^0;

  EOL = ('\r'? . '\n') @{line++;};

  in_comment_block :=
  (
   '%'
     @{ tmp_p = p+1; cout << " *"; }
   . (default - '\n')* . EOL
     @{ cout.write(tmp_p, p - tmp_p+1); }
  )*
  $!{
    cout << "*/\n";
    fhold;
    fret;
  };

  action end_of_file
  {
    /*    cout << "EOF\n";*/
    end_function();
  }

  action in_c_block
  {
    /*    cout << p << "x" << tmp_p << endl;*/
    cout.write(tmp_p, p-tmp_p+1);
    fcall in_comment_block;
  }

  action echo { cout << fc; }

  action st_tok { tmp_p = p; }

  action echo_tok { cout.write(tmp_p, p - tmp_p); }

  action string_tok { tmp_string.assign(tmp_p, p-tmp_p); }

  is_doxy_comment =
    (
     '|' @{ cout << "/**"; tmp_p = p+1; } . (default - '\n')* . EOL
     |
     ( (default - '|') @{ cout << "/*"; tmp_p = p; } )
     . (default - '\n')* . EOL
    );

  comment_block = [ \t]* . '%' . is_doxy_comment;

  doc_begin = [\t ]* . '%' @{ tmp_p = p + 1; };

  garble_comment_line =
    ( (default - '\n')* . EOL )
      @{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      };

  WSOC =
    ( [ \t]+
      | ('%' @{ tmp_p = p+1; } . garble_comment_line)
      | ('...'.[ \t]*.EOL)
    );

  IDENT = [A-Za-z_][A-Za-z0-9_]**;

  default_arg = [^,)]** @echo;

  paramlist =
    (
     (WSOC | [,\n] @echo | ( '=' . default_arg ) )+
     |
     (IDENT)
       >st_tok
       %{
         string s(tmp_p, p - tmp_p);
         param_list_[s] = DocuBlock();
         paramlist_.push_back(s);
         cout << "type " << s;
       }
    )**;

  lparamlist =
    ( (WSOC | [\n])+
      | ',' @{ cout << "::"; }
      | ( IDENT > st_tok
          %{
            string s(tmp_p, p - tmp_p);
            returnlist_.push_back(s);
            return_list_[s] = DocuBlock();
            cout << s;
          }
        )
    )**;

  lparams =
    (
      (
        (
         IDENT
           >st_tok
           %{
             string s(tmp_p, p - tmp_p);
             returnlist_.push_back(s);
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

    (
     (IDENT
        %{tmp_string.assign(ts,p-ts);})
     . '.'
     . (IDENT >(st_tok) %{tmp_p2 = p;} )
     . [ \t]* . '=' . (^'=')
    )
    => {
      fhold;
      string s(tmp_p, tmp_p2 - tmp_p);
      cout << tmp_string << "." << s << "=";
      typedef DocuList :: iterator list_iterator;
      typedef DocuListMap :: iterator map_iterator;
      typedef DocuBlock :: iterator iterator;

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
        if(missing)
        {
          retval_list_[tmp_string][s] = DocuBlock();
        }
      }
    };

    (
     (IDENT
        %{tmp_string.assign(ts,p-ts);})
     . '.'
     . (IDENT
         >(st_tok)
       )
    )
    => {
      string s(tmp_p, p - tmp_p+1);
      cout << tmp_string << "." << s;
      typedef DocuList :: iterator list_iterator;
      typedef DocuListMap :: iterator map_iterator;
      typedef DocuBlock :: iterator iterator;

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
          if(lit != (*rvoit).second.end())
            missing = false;
        }
        map_iterator moit = optional_list_.find(tmp_string);
        if(moit != optional_list_.end())
        {
          list_iterator lit = (*moit).second.find(s);
          if(lit != (*moit).second.end())
            missing = false;
        }
        map_iterator roit = required_list_.find(tmp_string);
        if(roit != required_list_.end())
        {
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

    (IDENT)
      => { cout.write(ts, te-ts); };

    (default - '\n')
      => { cout << fc; };

    EOL
      => { cout << fc; fgoto funcbody; };

  *|;

  funcbody := |*

      # a comment block
      ('% TO BE ADJUSTED TO NEW SYNTAX\n')
        => {
          new_syntax_ = true;
          cout << "*/\n"; //cout << "add to special group */\n";
        };

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
       . ( (default - [ \t\n%])+ - 'function' )
       . ( WSOC | EOL )
      )
        => {
          p = ts-1;
          fgoto funcline;
        };

      # line beginning with word 'function'
      ([ \t]*. 'function ')
      {
        p = ts-1;
        end_function();
        fgoto main;
      };

      (EOF) $eof(end_of_file);

  *|;

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
    . ( default - [ \t:\n] )+ .
    # followed by something that is a white-space or a new-line, i.e *no*
    # double-colon
    (
     EOL
     |
     [ \t]+ . (EOL | [^ \n\t:] . (default - '\n')* . EOL)
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

    # paragraph line with "see also" substituted by "@sa"
    ( doc_begin
      . (default - '\n')* . ( /see also/i %{tmp_p2 = p;} )
      . (default - '\n')* . EOL
    )
      => {
        string s, res;
        s.assign(tmp_p, p - tmp_p + 1);
        string::size_type size = string("see also").size();
        string::size_type loc = tmp_p2 - tmp_p - size;
        res = s.substr(0, loc) + "@sa" + s.substr(loc + size);
        /*        cout << "*"; cout << res << "  "; */
        docubody_.push_back(res);
      };

    # begin required_list
    ( doc_begin . [ \t]*
      . /required fields of /i
      . (IDENT >(st_tok) %(string_tok) )
      . [ \t]* . ':' . [ \t]* . EOL
    )
      => {
        //cout << tmp_string << '\n';
        clist_ = &(required_list_[tmp_string]);
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
        fcall fill_list;
      };

    # begin parameter list
    ( doc_begin . [ \t]*
      . /arguments/i . [ \t]* . ':'
      . [ \t]* . EOL )
      => {
        clist_ = &param_list_;
        fcall fill_list;
      };

    # begin return list
    ( doc_begin . [ \t]*
      . /return arguments/i . [ \t]* . ':'
      . [ \t]* . EOL )
      => {
        clist_ = &return_list_;
        fcall fill_list;
      };

    # paragraph line
    ( doc_begin
      . ( (default - '\n')* -- ( /see also/i ) )#| (/required fields of [ \t]*/i . IDENT . [\t ]* . ':' . [\t ]* . EOL)
                                             #| (/optional fields of [ \t]*/i . IDENT . [\t ]* . ':' . [\t ]* . EOL)
                                             #| /arguments [ \t]*:[ \t]*\n/i
                                             #| /return arguments[ \t]*:[\t ]*\n/i ) )
      . [^ \t\n] . [ \t]* . EOL
    )
      => {
        /*cout << "*"; cout.write(tmp_p, p - tmp_p+1) << "  ";*/
        docubody_.push_back(string(tmp_p, p - tmp_p + 1));
      };

    # empty line
    ( doc_begin . [ \t]* . EOL )
      => {
        /*cout << "*\n  ";*/
        docubody_.push_back("\n");
      };

    # end of comment block
    ( [\t ]* . ( (default - '%') | EOL) )
      => {
        fhold;
        // cout << "*/\n";
        fgoto funcbody;
      };

  *|;

  doxyfunction_garble := |*
    garbage = doc_begin . ( (default - '\n' )* -- '...' );

    ( garbage . '...' . [\t ]* .  EOL );

    ( garbage . EOL )
      => { fgoto doxy_get_brief; };
  *|;


  doxy_get_brief := |*

    # read in one comment line
    ( doc_begin . [\t ]*
      . (default - [\n\t ]) . (default - '\n')* . EOL
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

  doxyheader := (
    '%' . [ \t]* .
       ( 'function'
         . ( default - [;)\n.] )* .
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

  funcdef = (
      WSOC* .
      (lparams)? @{opt=true;} .
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
                 if(!opt)
                 {
                   cout << "noret::substitute ";
                   opt=false;
                 }
                 cout << cfuncname_ << '(';
                 })
           . paramlist
           . (')' @echo) . ( WSOC | ';' )*
           . EOL
           @{
             cout << " {\n";
             fgoto expect_doxyblock;
           }
        | (';'? . EOL) @{ cout << "void " << cfuncname_ << "() {\n"; fgoto expect_doxyblock; }
        )
      );

  script := (default)
    @{
       string :: size_type found = filename_.rfind("/");
       if(found == string :: npos)
         found = -1;
       string funcname = filename_.substr(found+1, filename_.size()-3-found);
       cfuncname_.assign( funcname );
       cout << "void " << funcname << "() {\n";
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


MFileScanner :: MFileScanner(istream & fin, const std::string & filename, bool latex_output) :
  fin_(fin), filename_(filename), latex_output_(latex_output), cscan_(filename_),
  line(1),
  ts(0), have(0), top(0),
  opt(false), new_syntax_(false), is_script_(false), is_first_function_(true)
{
  cscan_.execute();
};

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
      cerr << "PARSE ERROR in line " << line << endl;
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

const string & MFileScanner::replace_underscore(std::string & s)
{
  // standard brief text (replace '_' -> ' ' in cfuncname_)
  string::size_type found = s.find("_");
  while(found != string::npos )
  {
    s[found] = ' ';
    found = s.find("_", found+1);
  }
  return s;
}

void MFileScanner::write_docu_block(const DocuBlock & block)
{
  for( unsigned int i = 0; i < block.size(); i += 1 )
  {
    if(i != 0)
      cout << "* ";

    cout << block[i] << "  ";
  }
}

void MFileScanner::write_docu_list(const DocuList & list,
                                   const string & item_text,
                                   const DocuList & alternative)
{
  typedef DocuList :: const_iterator list_iterator;
  list_iterator lit = list.begin();
  for(; lit != list.end(); ++lit)
  {
    cout << "* " << item_text << " " << (*lit).first << " ";
    const DocuBlock & block = (*lit).second;
    if(block.empty())
    {
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
      write_docu_list((*mit).second, "@arg \\c", ( amit != altlistmap.end() ? (*amit).second : DocuList() ));
    }

  }
}

void MFileScanner::end_function()
{
  typedef GroupSet :: iterator group_iterator;
  typedef DocuBlock :: iterator block_iterator;
  typedef DocuList :: iterator list_iterator;
  typedef DocuListMap :: iterator map_iterator;
  // end function
  cout << "}\n";
  if(is_first_function_)
  {
    string tempfname(filename_);
    string::size_type found = tempfname.rfind("/");
    if(found != string::npos)
      tempfname = tempfname.substr(found+1);
    if(! latex_output_ )
    {
      cout << "/** @file " << escape_chars(tempfname) << "\n  ";
      if((! groupset_.empty() || ! cscan_.groupset_.empty() ))
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
        groupset_.clear();
      }
      //    cout << "\n  " << "* @brief " << tempfname << " ";
      is_first_function_ = false;
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
  cout << cfuncname_;
  if(paramlist_.size() == 0)
    cout << "\n  ";
  else
  {
    cout << "(";
    for(unsigned int i=0; i < paramlist_.size(); ++i)
    {
      if(!first)
        cout << ", ";
      else
        first = false;
      cout << "type " << paramlist_[i];
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
    bool not_first = false;
    block_iterator hit = docuheader_.begin();
    for(; hit != docuheader_.end(); ++hit)
    {
      if(not_first)
        cout << "* ";
      else
        not_first = true;

      cout << *hit << "  ";
    }
    hit = cscan_.docuheader_.begin();
    for(; hit != cscan_.docuheader_.end(); ++hit)
    {
      if(not_first)
        cout << "* ";
      else
        not_first = true;

      cout << *hit << "  ";
    }
  }
  docuheader_.clear();
  cout << "*\n  ";
  // specify the @details part

  // standard body definitions
  if(!docubody_.empty() || !cscan_.docubody_.empty())
  {
    cout << "*\n  ";
    block_iterator bit = docubody_.begin();
    for(; bit != docubody_.end(); ++bit)
      cout << "* " << *bit << "  ";
    bit = cscan_.docubody_.begin();
    for(; bit != cscan_.docubody_.end(); ++bit)
      cout << "* " << *bit << "  ";
  }
  docubody_.clear();
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
  if(!docuextra_.empty() || ! cscan_.docuextra_.empty())
  {
    cout << "*\n  ";
    block_iterator bit = docuextra_.begin();
    for(; bit != docuextra_.end(); ++bit)
      cout << "* " << *bit << "  ";
    bit = cscan_.docuextra_.begin();
    for(; bit != cscan_.docuextra_.end(); ++bit)
      cout << "* " << *bit << "  ";
  }
  if( new_syntax_ )
  {
    cout << "* @synupdate Syntax needs to be updated! \n  ";
  }
  docuextra_.clear();
  cout << "*/\n";
}

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

  char buf[1000];
  getcwd(buf, 1000);

  string::size_type found = 0;
  string cwd(buf);
  found = filename.find(cwd);
  if(found!=string::npos)
    filename = filename.substr(cwd.size()+1);
  MFileScanner scanner(*fcin, filename, latex_output);
  cerr << "************" << filename << endl;
  scanner.execute();
  return 0;
}

/* vim: set et sw=2 ft=ragel: */

