#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

// 160 KB
#define BUFSIZE 10*16384

using std::cerr;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::set;

%%{
  machine Scanner;
  write data;

  EOF = 0;

  default = ^0;

  in_comment_block :=
  (
   '%'
     @{ tmp_p = p+1; cout << " *"; }
   . (default - '\n')* . '\n'
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
     '%' @{ cout << "/**"; tmp_p = p+1; } . (default - '\n')* . '\n'
     |
     ( (default - '%') @{ cout << "/*"; tmp_p = p; } )
     . (default - '\n')* . '\n'
    );

  comment_block = [ \t]* . '%' . is_doxy_comment;

  doc_begin = [\t ]* . '%' @{ tmp_p = p + 1; };

  garble_comment_line =
    ( (default - '\n')* . '\n' )
      @{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      };

  WSOC =
    ( [ \t]+
      | ('%' @{ tmp_p = p+1; } . garble_comment_line)
      | ('...'.[ \t]*.'\n')
    );

  IDENT = [A-Za-z_][A-Za-z0-9_]**;

  default_arg = [^,)]** @echo;

  paramlist =
    (
     (WSOC | [,\n] | ( '=' . default_arg ) )+
       >echo
     |
     (IDENT)
       >st_tok
       %{
         string s(tmp_p, p - tmp_p);
         param_list_[s] = DocuBlock();
         cout << s;
       }
    )**;

  lparamlist =
    ( (WSOC | [,\n])+
      | ( IDENT > st_tok
          %{
            string s(tmp_p, p - tmp_p);
            return_list_[s] = DocuBlock();
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
             return_list_[s].push_back(s);
             cout << "ret ";
           }
        )
        | ( '[' . lparamlist . ']'
            @{cout << "rets "; }
          )
      )
      . ([ \t]*
          @echo)
      . '=' . WSOC*
    );

  funcline := |*
    ([ \t]+)
      => { cout.write(ts, te-ts); };

    ('...' . [ \t]* . '\n')
      => { cout.write(ts, te-ts); };

    ('%' @{ tmp_p = p + 1; } . garble_comment_line);

    (
     (IDENT
        %{tmp_string.assign(ts,p-ts);})
     . '.'
     . (IDENT
         >(st_tok)
       )
    )
    {
      string s(tmp_p, p - tmp_p+1);
      cout << tmp_string << "." << s;
      typedef DocuListMap :: iterator map_iterator;
      typedef DocuList :: iterator iterator;
      map_iterator moit = optional_list_.find(tmp_string);
      if(moit != optional_list_.end())
      {
        iterator oit = (*moit).second.find(s);
        if(oit == (*moit).second.end())
        {
          (*moit).second[s] = DocuBlock();
        }
      }
      else
      {
        map_iterator mrit = required_list_.find(tmp_string);
        if(mrit != required_list_.end())
        {
          optional_list_[tmp_string][s] = DocuBlock();
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
      . [\t ]* . '\n'
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

    '\n'
      => { cout << fc; fgoto funcbody; };

  *|;

  funcbody := |*

      # a comment block
      ('% TO BE ADJUSTED TO NEW SYNTAX\n')
        => {
          groupset_.clear();
          groupset_.insert("new_syntax");
          cout << "*/\n"; //cout << "add to special group */\n";
        };

      (comment_block)
        => {
          cout.write(tmp_p, p - tmp_p+1);
          fcall in_comment_block;
        };

      # empty line
      ([ \t]* . '\n')
        => { cout << '\n'; };

      # line not beginning with word 'function'
      ([ \t]*
       . ( (default - [ \t\n%])+ - 'function' )
       . ( WSOC | '\n' )
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
    . "'"? . ( IDENT >(st_tok) %(string_tok) ) . "'"? . ":" @(st_tok)
    . ( default - '\n' )* . '\n'
  )
    => {
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
     '\n'
     |
     [ \t] . (default - '\n')* . '\n'
    )
  )
    => {
      string s(tmp_p, p - tmp_p + 1);
      (*clist_)[tmp_string].push_back(s);
      /*cout << "add something results in\n" << (*clist_)[tmp_string];*/
    };

  # return on empty line
  ( doc_begin . [ \t]* . '\n' )
    => { /*cout << "empty line\n";*/ fret; };

  *|;

  doxy_get_body := |*

    # paragraph line
    ( doc_begin
      . ( (default - '\n')* -- /see also/i )
      . [^: \t\n] . [ \t]* . '\n' 
    )
      => {
        /*cout << "*"; cout.write(tmp_p, p - tmp_p+1) << "  ";*/
        docubody_.push_back(string(tmp_p, p - tmp_p + 1));
      };

    # paragraph line with "see also" substituted by "@sa"
    ( doc_begin
      . (default - '\n')* . ( /see also/i %{tmp_p2 = p;} )
      . (default - '\n')* . '\n'
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
      . [ \t]* . ':' . [ \t]* . '\n'
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
      . [ \t]* . ':' . [ \t]* . '\n' )
      => {
        clist_ = &(optional_list_[tmp_string]);
        fcall fill_list;
      };

    # begin parameter list
    ( doc_begin . [ \t]*
      . /arguments/i . [ \t]* . ':'
      . [ \t]* . '\n' )
      => {
        clist_ = &param_list_;
        fcall fill_list;
      };

    # begin return list
    ( doc_begin . [ \t]*
      . /return arguments/i . [ \t]* . ':'
      . [ \t]* . '\n' )
      => {
        clist_ = &return_list_;
        fcall fill_list;
      };

    # empty line
    ( doc_begin . [ \t]* . '\n' )
      => {
        /*cout << "*\n  ";*/
        docubody_.push_back("\n");
      };

    # end of comment block
    ( [\t ]* . ( (default - '%') | '\n') )
      => {
        fhold;
        // cout << "*/\n";
        fgoto funcbody;
      };

  *|;

  doxyfunction_garble := |*
    garbage = doc_begin . (default - [)\n] )*;

    ( garbage . '\n' );

    ( garbage . ')' . ( default - '\n' )* . '\n' )
      => { fgoto doxy_get_body; };
  *|;


  doxy_get_brief := |*

    # read in one comment line
    ( doc_begin . [\t ]*
      . (default - [\n\t ]) . (default - '\n')* . '\n'
    )
      => {
        /* cout << "*"; cout.write(tmp_p, p - tmp_p+1); */
        docuheader_.push_back(string(tmp_p, p - tmp_p+1));
      };

    # empty line
    ( doc_begin . [\t ]* . '\n' )
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
         . ( default - [)\n] )* .
         (
          ( ')' . (default - '\n')* . '\n' )
            @{ fgoto doxy_get_body; }
          |
          ( '\n'
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
      lparams? @{opt=true;} <:
      ( IDENT
          >st_tok
          %{
            if(!opt)
            {
              cout << "void ";
              opt=false;
            }
            cfuncname_.assign(tmp_p, p - tmp_p);
            cout << cfuncname_;
            is_script_ = false;
          }
      )
      . WSOC* . ('(' @echo)
      . paramlist
      . (')' @echo) . WSOC*
      . '\n'
        @{
        cout << " {\n";
        fgoto expect_doxyblock;
        }
      );

  script := (default)
    @{
       string funcname = "script";
       cfuncname_.assign( funcname );
       cout << "void " << funcname << "() {\n";
       is_script_ = true;
       fhold;
       fgoto expect_doxyblock;
     };

#  expect_function_or_script =
#  (
#    # either we find a function definition with a possibly preceding comment
#    # block or we have a script
#    (
#      comment_block @in_c_block
#      | [ \t]*. '\n'
#    )* >(st_tok)
#    . [\t]* . 'function'
#    . funcdef
#  ) $! { cout << "script\n"; p=tmp_p; fgoto script; } $eof( end_of_file )
#  ;

  funct :=
  (
    (
      comment_block @in_c_block
      | [ \t]*. '\n'
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
      [ \t]*. '%' . (any - '\n')* . '\n'
      | [ \t]*. '\n'
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

class Scanner {

private:

typedef vector< string >                                             DocuBlock;
typedef map< string, DocuBlock >                                     DocuList;
typedef map< string, DocuList >                                      DocuListMap;
typedef set< string >                                                GroupSet;

private:
char         buf[BUFSIZE];
int          line            , col;
char        *ts              , *te;
int          act             , have;
int          cs;
int          top;
int          stack[5];
bool         opt;
DocuListMap  required_list_;
DocuListMap  optional_list_;
DocuList     param_list_;
DocuList     return_list_;
DocuList    *clist_;
DocuBlock    docuheader_;
DocuBlock    docubody_;
DocuBlock    docuextra_;
string       cfuncname_;
GroupSet     groupset_;
bool         is_script_;

public:

  Scanner() :
    line(1), col(1),
    ts(0), have(0), top(0),
    opt(false), is_script_(false) 
  {};

  int execute()
  {
    std::ios::sync_with_stdio(false);

    %% write init;

    /* Do the first read. */
    bool done = false;
    while ( !done )
    {
      char *p = buf + have;
      char *tmp_p = p, *tmp_p2 = p;
      string tmp_string;
      int space = BUFSIZE - have;

      if ( space == 0 )
      {
        /* We filled up the buffer trying to scan a token. */
        cerr << "OUT OF BUFFER SPACE" << endl;
        exit(1);
      }

      cin.read( p, space );
      int len = cin.gcount();
      char *pe = p + len;
      char *rpe = pe;
      char *eof = 0;

      /* If we see eof then append the EOF char. */
      if ( cin.eof() )
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
      if ( cs == Scanner_error )
      {
        /* Machine failed before finding a token. */
        cerr << "PARSE ERROR" << endl;
        exit(1);
      }

      /* Now set up the prefix. */
      if ( ts == 0 )
      {
        have = rpe - pe;
/*        cerr << "memmove by " << have << "bytes\n";*/
        memmove( buf, pe, have );
      }
      else
      {
        have = rpe - ts;
/*        cerr << "memmove by " << have << "bytes to ts\n";*/
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

  const string & replace_underscore(std::string & s)
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

  void write_docu_list(const DocuList & list,
                       const string & item_text)
  {
    typedef DocuList :: const_iterator list_iterator;
    list_iterator lit = list.begin();
    for(; lit != list.end(); ++lit)
    {
      cout << "* " << item_text << " " << (*lit).first << " ";
      const DocuBlock & block = (*lit).second;
      if(block.empty())
      {
        std::string s((*lit).first);
        cout << replace_underscore(s) << "\n  ";
      }
      else
      {
        for( unsigned int i = 0; i < block.size(); i += 1 )
        {
          if(i != 0)
            cout << "* ";

          cout << block[i] << "  ";
        }
      }
    }
  }

  void write_docu_listmap(const DocuListMap & listmap,
                          const string & text)
  {
    typedef DocuListMap :: const_iterator map_iterator;
    if(!listmap.empty())
    {
      map_iterator mit = listmap.begin();
      for(; mit != listmap.end(); ++mit)
      {
        cout << "*\n  ";
        cout << "* " << text << (*mit).first << ":\n  ";
        write_docu_list((*mit).second, "@arg \\c");
      }

    }
  }

  void end_function()
  {
    typedef GroupSet :: iterator group_iterator;
    typedef DocuBlock :: iterator block_iterator;
    typedef DocuList :: iterator list_iterator;
    typedef DocuListMap :: iterator map_iterator;
    // end function
    cout << "}\n";
    cout << "/*";
    if(! groupset_.empty())
    {
      // specify the @ingroup command
      cout << "* @ingroup ";
      group_iterator git = groupset_.begin();
      bool not_first = false;
      for(; git != groupset_.end(); ++git)
      {
        if(not_first)
          cout << ", ";
        else
          not_first = true;

        cout << *git;
      }
      cout << "\n  ";
      groupset_.clear();
    }

    // specify the @fn part
    cout << "* @fn " << cfuncname_ << "\n  ";

    // specify the @brief part
    cout << "* @brief ";
    if(docuheader_.empty())
    {
      string s(cfuncname_);
      cout << replace_underscore(s) << "\n  ";
    }
    else
    {
      block_iterator hit = docuheader_.begin();
      bool not_first = false;
      for(; hit != docuheader_.end(); ++hit)
      {
        if(not_first)
          cout << "* ";
        else
          not_first = true;

        cout << *hit << "  ";
      }
    }
    docuheader_.clear();
    // specify the @details part

    // standard body definitions
    if(!docubody_.empty())
    {
      cout << "*\n  ";
      block_iterator bit = docubody_.begin();
      for(; bit != docubody_.end(); ++bit)
        cout << "* " << *bit << "  ";
    }
    docubody_.clear();
    // parameters
    if(!param_list_.empty())
    {
      cout << "*\n  ";
      write_docu_list(param_list_, "@param");
      param_list_.clear();
    }
    // return values
    if(!return_list_.empty())
    {
      cout << "*\n  ";
      write_docu_list(return_list_, "@retval");
      return_list_.clear();
    }
    // required fields
    write_docu_listmap(required_list_, "Required fields of ");
    required_list_.clear();

    // optional fields
    write_docu_listmap(optional_list_, "Optional fields of ");
    optional_list_.clear();

    // extra docu fields
    if(!docuextra_.empty())
    {
      cout << "*\n  ";
      block_iterator bit = docuextra_.begin();
      for(; bit != docuextra_.end(); ++bit)
        cout << "* " << *bit << "  ";
    }
    docuextra_.clear();
    cout << "*/\n";
  }

};

int main()
{
  Scanner scanner;
  scanner.execute();
}

/* vim: set et sw=2 ft=ragel: */

