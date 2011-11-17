#include "mfilescanner.h"

#include <cassert>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <iterator>
extern "C" {
#include <unistd.h>
}

using std::cerr;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::list;
using std::copy;
using std::map;
using std::set;
using std::istream;
using std::ifstream;
using std::ostream;
using std::ostream_iterator;
using std::ostringstream;

const char * AccessEnumNames[] =
{
  stringify( Public ),
  stringify( Protected ),
  stringify( Private )
};

const char * ClassPartNames[] =
{
  stringify( InClassComment ),
  stringify( Header ),
  stringify( Method ),
  stringify( AtMethod ),
  stringify( MethodDeclaration ),
  stringify( Property ),
  stringify( Event )
};


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
     @{ tmp_p = p+1; fout_ << " *"; }
   # and then some default characters
   . (default - '\n')* . EOL
     @{ fout_.write(tmp_p, p - tmp_p+1); }
  )*
  $!{
    fout_ << "*/\n";
    if(is_getter_ || is_setter_)
    {
      fout_ << "/* ";
    }
    fhold;
    fhold;
    fret;
  };

  action end_doxy_block
  {
    if(!docline)
    {
      p = ts-1;
      /* go backward until first non-whitespace is found */
      for(p=p-1; *p==' ' || *p == '\t'; --p)
        ;

      if(is_class_)
      {
        if(class_part_ == Header)
        {
          end_of_class_doc();
          fgoto classbody;
        } else if(class_part_ == Method || class_part_ == AtMethod)
        {
          if(runMode_.mode == RunMode::ParseParams)
            return 1;
          print_function_synopsis();
          fgoto funcbody;
        }
        else if(class_part_ == MethodDeclaration)
        {
          fgoto funcdef;
        }
        else if(class_part_ == Property)
        {
          fgoto propertybody;
        }
        else if(class_part_ == InClassComment)
        {
          class_part_ = Method;
          fgoto methods;
        }
        else
        {
          cerr << "MTOCPP: missing class part handling for class part: " << ClassPartNames[class_part_] << endl;
        }
      }
      else
      {
        if(runMode_.mode == RunMode::ParseParams)
          return 1;
        print_function_synopsis();
        fgoto funcbody;
      }
    }
  }

  # executed when end of file is reached
  action end_of_file
  {
    end_function();
    for(  list<string>::iterator it = namespaces_.begin();
          it != namespaces_.end(); ++it)
    {
      fout_ << "};\n";
    }
  }

  # executed when we reached a comment block
  action in_c_block
  {
    assert(p >= tmp_p-1);
    fout_.write(tmp_p, p-tmp_p+1);
    fcall in_comment_block;
  }

  action echo { fout_ << fc; }

  action st_tok { tmp_p = p; }

  action echo_tok {
    assert (p >= tmp_p);
    fout_.write(tmp_p, p - tmp_p);
  }

  action string_tok {
    assert ( p >= tmp_p );
    tmp_string.assign(tmp_p, p-tmp_p);
  }

  # common definitions {{{2

  # comment in function body that might also be added to the doxygen block for
  # the function description
  is_doxy_comment =
    (
    # if percent character is followed by a bar we make the comment a doxygen
    # comment
     '|' @{ if(is_getter_ || is_setter_)
            {
              fout_ << "*/";
            }
            fout_ << "/**"; tmp_p = p+1;
          }
     . (default - '\n')*
     . ( EOL . [ \t]*
       . '%' @{
                assert(p >= tmp_p -1);
                fout_.write(tmp_p, p - tmp_p);
                fout_ << " * ";
                tmp_p = p+1;
              }
     . (default - '\n')* )* . EOL
     |
    # else: a regular comment
     ( (default - '|')
       @{
         if(is_getter_ || is_setter_)
         {
           fout_ << "*/";
         }
         fout_ << "/* ";
         tmp_p = p;
         } )
     . (default - '\n')* . EOL
    );

  # comment block in function body
  comment_block = [ \t]* . '%' . is_doxy_comment;

  # an empty line
  empty_line = [\t ]* . EOL;

  # documentation line begin
  doc_begin = [\t ]* . '%' @{ tmp_p = p + 1; };

  # swallow a comment line till the end of the line (make it a c comment)
  garble_comment_line =
    ( (default - [\r\n])* . EOL )
      @{
        if(is_getter_ || is_setter_)
        {
          fout_ << "*/";
        }
        fout_ << "/* ";
        assert( p >= tmp_p );
        fout_.write(tmp_p, p - tmp_p) << "*/\n";
        if(is_getter_ || is_setter_)
        {
          fout_ << "/* ";
        }
      };
  garble_comment_line_wo_eol =
    (default - [\r\n])*;

  # white space or comment
  WSOC =
    ( [ \t]+
      | ('%' @{ tmp_p = p+1; } . garble_comment_line)
      | ('...'.[ \t]*.EOL)
    );

  # matlab identifier
  IDENTEND = [A-Za-z0-9_];
  IDENT = [A-Za-z_]IDENTEND**;


  # matlab identifier with .
  IDENT_W_DOT = [A-Za-z_][A-Za-z0-9_.]**;

  # default arguments in function declarations
  default_arg = [^,)]** @echo;

  #}}}2

  # parameter list for functions {{{2
  paramlist =
    (
     (WSOC | [,\n]
#       @{if(*p=='\n' || paramlist_.size() != 1 || paramlist_[0] != string("this" )) {
#         //buffer_.append(std::string(*p));
#         } }
     | ( '=' . default_arg ) )+
     |
     # matlab identifier (parameter)
     (IDENT | '~' )
       >st_tok
       %{
         assert(p >= tmp_p);
         string s(tmp_p, p - tmp_p);
         bool addBlock = true;
         // do not print this pointer
         if( is_class_ && ( !methodparams_.statical
                            && (
                                ( class_part_ == Method
                                  && cfuncname_ != classname_
                                )
                                || class_part_ == AtMethod
                                || class_part_ == MethodDeclaration
                               )
                          )
                       && ( ! (
                               methodparams_.abstr
                               && !runMode_.remove_first_arg_in_abstract_methods
                              )
                          )
           )
         {
            if(paramlist_.empty())
            {
              addBlock = false;
              paramlist_.push_back(string("this"));
            }
            else if(paramlist_.size() == 1 && paramlist_[0] == string("this"))
              paramlist_.clear();
         }

         if(addBlock) {

#ifdef DEBUG
{
  ostringstream oss;
  oss << "found parameter: " << s;
  debug_output(oss.str(), p);
}
#endif
           postprocess_unused_params(s, param_list_);
           // add an empty docu block for parameter \a s
           if(param_list_.find(s) == param_list_.end())
           {
             param_list_[s] = DocuBlock();
           }
#ifdef DEBUG
{
  ostringstream oss;
  oss << "in paramlist: add to paramlist: " << s;
  debug_output(oss.str(), p);
}
#endif
           paramlist_.push_back(s);
         }
       }
    )**;

  # return parameter list for functions
  lparamlist =
    ( (WSOC | [\n])+
      | ','
      # matlab identifier (return value)
      | ( (IDENT | '~') > st_tok
          %{
            assert(p >= tmp_p);
            string s(tmp_p, p - tmp_p);
            postprocess_unused_params(s, return_list_);
            returnlist_.push_back(s);
            // add an empty docu block for return value \a s
            if(return_list_.find(s) == return_list_.end())
            {
              return_list_[s] = DocuBlock();
            }
          }
        )
    )**;

  # return parameter or return parameter list
  lparams =
    (
      (
        (
         # matlab identifier
         ( IDENT | '~' )
           >st_tok
           %{
             assert(p >= tmp_p);
             string s(tmp_p, p - tmp_p);
             postprocess_unused_params(s, return_list_);
             returnlist_.push_back(s);
             // add an empty docu block for single return value \a s

             if(return_list_.find(s) == return_list_.end())
             {
               return_list_[s] = DocuBlock();
             }
#ifdef DEBUG
  cerr << "\n In return list: " << endl;
#endif
           }
        )
        | ( '['
          . lparamlist
          . ']'
          )
      )
      . ( [ \t]+ | ([ \t].'...'.[ \t]*.EOL))*
      :> '=' . WSOC*
    );
    # }}}2

  # a line in the function body {{{2
  funcline := |*
    # empty line
    ([ \t]+)
      => { fout_.write(ts, te-ts); };

    # line continuation
    ('...' . [ \t]* . EOL)
      => { fout_.write(ts, te-ts); };

    # two single quote in a row need to be changed to nothing
    ('\'\'');

    # a string should not be parsed for comment blocks, so we handle it separately.
    ('\'' . [^'\n]+ . '\'')
      => {
           // change double quotes to quotes and vice versa...
           fout_ << "\" ";
           string s(ts+1, te-ts-2);
           std::replace(s.begin(), s.end(), '\"', '\'');
           fout_ << s;
           fout_ << " \"";
         };

    # ('%' @{ tmp_p = p + 1; } . garble_comment_line);
    (comment_block)
      => {
           assert(p >= tmp_p-1);
           fout_.write(tmp_p, p - tmp_p+1);
           fcall in_comment_block;
         };

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
      assert(tmp_p2 >= tmp_p);
      string s(tmp_p, tmp_p2 - tmp_p);
      fout_ << tmp_string << "." << s << "=";
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
      assert(p >= tmp_p);
      string s(tmp_p, p - tmp_p+1);
      fout_ << tmp_string << "." << s;
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
      => { fout_.write(ts, te-ts); };

    # translate curly brackets in edgy brackets, because otherwise the doxygen
    # parser breaks.
    ('{')
      => { fout_ << '['; };

    ('}')
      => { fout_ << ']'; };

    # simply output all other characters
    (default - [\n{}])
      => { fout_ << fc; };

    # after EOL try to check for new function
    EOL
      => { fout_ << fc; fgoto funcbody; };

  *|;
  # }}}2

  # function body {{{2
  funcbody := |*

      # things that got replaced in function body {{{4
      ('% TO BE ADJUSTED TO NEW SYNTAX\n')
        => {
          new_syntax_ = true;
          fout_ << "*/\n"; //fout_ << "add to special group */\n";
        };

      # a comment block
      (comment_block)
        => {
          assert(p+1 >= tmp_p);
          fout_.write(tmp_p, p - tmp_p+1);
          fcall in_comment_block;
        };

      # empty line
      ([ \t]* . EOL)
        => { fout_ << '\n'; };

      #}}}4

      # things that could end the function body {{{4
      # line not beginning with words 'function' or 'end'
      ([ \t]*
       . ( (default - [ \r\t\n%])+ - ('function'|'end') )
      )
        => {
          p = ts-1;
          // further parse the function body line
#ifdef DEBUG
debug_output("in funcbody: goto funcline", p);
#endif
          fgoto funcline;
        };

      # line only containing word 'end'
      # the keyword needs to be in the same indentation level as beginning function
      ([ \t]* . 'end' . ';'* . (WSOC | EOL ) )
          => {
              if(is_class_ && class_part_ == Method)
              {
                tmp_string.assign(ts,p-ts+1);

                if(tmp_string.find("e") == funcindent_)
                {
                  end_function();
#ifdef DEBUG
debug_output("in funcbody: goto methods", p);
#endif
                  fgoto methods;
                }
              }
              // else
              p=ts-1;
              // further parse the function body line
#ifdef DEBUG
debug_output("in funcbody: goto funcline 2", p);
#endif
              fgoto funcline;
          };

      # line beginning with word 'function'
      ([ \t]*. 'function ')
      {
        p = ts-1;
        if (!is_class_)
        {
          // end the previous function if existent
          end_function();
#ifdef DEBUG
debug_output("in funcbody: goto main", p);
#endif
          fgoto main;
        }
        else
        {
          fgoto funcline;
        }
      };

      (EOF) $eof(end_of_file);

      # }}}4

  *|;
   # }}}2

  # fill a docublock list with input {{{2
  fill_list := |*

  # match an argument
  ( doc_begin . [ \t]*
    . "'"? . ( ([A-Za-z][A-Za-z0-9_{},()[\].]*)  >{tmp_p3 = p;} %{tmp_p2 = p;} ) . "'"? . [ \t]* . ":" @(st_tok)
    . ( default - '\n' )* . EOL
  )
    => {
      assert(tmp_p2 >= tmp_p3);
      tmp_string.assign(tmp_p3, tmp_p2 - tmp_p3);
      //    std::fout_ << tmp_string << '\n';
      assert(p >= tmp_p);
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
      assert(p+1 >= tmp_p);
      string s(tmp_p, p - tmp_p + 1);
      (*clist_)[tmp_string].push_back(s);
      /*fout_ << "add something results in\n" << (*clist_)[tmp_string];*/
    };

  # return on empty line
  ( doc_begin . [ \t]* . EOL )
    => { /*fout_ << "empty line\n";*/ fret; };

   # end of comment block
  ( [\t ]* . ( (default - '%') | EOL) )
    => {
      p =ts-1;
      // fout_ << "*/\n";
      fret;
    };

  *|; #}}}2

  # parse body of documentation block {{{2
  doxy_get_body := |*

    # special lists {{{4

    # begin required_list
    ( doc_begin . [ \t]*
      . /required fields of /i
      . (IDENT >(st_tok) %(string_tok) )
      . [ \t]* . ':' . [ \t]* . EOL
    )
      => {
        //fout_ << tmp_string << '\n';
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
    #}}}4

    # default substitutions {{{4

    # empty line
    ( doc_begin . [ \t]* . EOL )
      => {
        /*fout_ << "*\n  ";*/
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
    ( /see also/i . ':'? )
      => {
        string s;
        assert(ts > tmp_p);
        s.assign(tmp_p+1, ts - tmp_p-1);
        docubody_.push_back(s+"@sa");
        tmp_p = p;
      };

    # lines that could end doxyblock {{{6
    # words
    #    ( default - [ \t:%'`\n] )+
    ( default - [ \t:%\r\n] )+ @(end_doxy_block);

    # non-words/non-whitespace
    #    ([:'`]) => {
    (':') @(end_doxy_block) ;


    # whitespace only
    ( [ \t] );

    # titled paragraph
    ( ':' . EOL )
      @(end_doxy_block)
      @{ if(docline)
         {
           assert(ts > tmp_p);
           docubody_.push_back("@par " + string(tmp_p+1, ts - tmp_p-1)+"\n");
           docline = false;
         }
       };
    # }}}6
    # }}}4

    # end of line {{{4
    ( EOL )
       @(end_doxy_block)
       @{ if(docline)
          {
            int offset = ( latex_begin ? 0 : 1 );
            assert(p >= tmp_p + offset);
            docubody_.push_back(string(tmp_p+1, p - tmp_p - offset));
            docline = false;
          }
        };
      # }}}4

  *|;
  #}}}2

  # doxy header parsing {{{2
  # swallow the synopsis line
  doxyfunction_garble := |*
    garbage = ( (default - '\n' )* -- '...' );

    ( doc_begin . (garbage . '...')+ . [\t ]* .  EOL );

    ( doc_begin . (garbage . '...')* . garbage . EOL )
      => { fgoto doxy_get_brief; };
  *|;


  # read first paragraph
  doxy_get_brief := |*

    # read in one comment line
    ( doc_begin . [\t ]*
      . (default - [\r\n\t ]) . (default - '\n')* . EOL
    )
      => {
        /* fout_ << "*"; fout_.write(tmp_p, p - tmp_p+1); */
        assert(p >= tmp_p);
        docuheader_.push_back(string(tmp_p, p - tmp_p+1));
      };

    # empty line
    ( doc_begin . [\t ]* . EOL )
      => {
        /*fout_ << "*\n";*/
#ifdef DEBUG
  debug_output("in doxy_get_brief: goto: doxy_get_body", p);
#endif
        fgoto doxy_get_body;
      };

    # end of comment block;
    ( [\t ]* . [^%] )
      => {
        p=ts-1;
#ifdef DEBUG
   debug_output("in doxy_get_brief: end!!", p);
#endif
        //fout_ << "*/\n";
        if(is_class_)
        {
#ifdef DEBUG
  debug_output(" in_doxy_get_brief: this is a class",p);
#endif

          if(class_part_ == Header)
          {
#ifdef DEBUG
  debug_output("  in_doxy_get_brief: method: goto classbody",p);
#endif
            end_of_class_doc();
            fgoto classbody;
          } else if(class_part_ == Method || class_part_ == AtMethod)
          {
#ifdef DEBUG
  debug_output("  in_doxy_get_brief: method: goto funcbody",p);
#endif
            if(runMode_.mode == RunMode::ParseParams)
              return 1;
            print_function_synopsis();
            fgoto funcbody;
          }
          else if(class_part_ == MethodDeclaration)
          {
#ifdef DEBUG
  debug_output("  in_doxy_get_brief: method: goto funcdef",p);
#endif
            fgoto funcdef;
          }
          else if(class_part_ == Property)
          {
#ifdef DEBUG
  debug_output("  in_doxy_get_brief: method: goto propertybody",p);
#endif
            fgoto propertybody;
          }
          else if(class_part_ == InClassComment)
          {
            class_part_ = Method;
            fgoto methods;
          }
        }
        else
        {
          if(runMode_.mode == RunMode::ParseParams)
            return 1;
          print_function_synopsis();
          fgoto funcbody;
        }
      };

  *|;
  # }}}2

  # garble synopsis line and then parse the documentation header {{{2
  doxyheader := (
    '%' . [ \t]* .
       (
        ('function '|'classdef ') @{ p = tmp_p-2; fgoto doxyfunction_garble; }
       )
      $!{
#ifdef DEBUG
        debug_output("doxy_get_brief",p);
#endif
        p = tmp_p - 2;
        fgoto doxy_get_brief;
      }
   ); #}}}2

  # helper for setting the access specifier {{{2
  paramaccess =
    ( ('SetAccess' . WSOC* . '=' . WSOC*
      . ( (/public/i
            @{ access_.full = Public;
               access_.set = Public;
             } )
        | ( /protected/i
            @{ access_.full =
                 (access_.get == Public ? Public : Protected );
               access_.set = Protected;
             } )
        | ( /private/i
            @{ access_.full = access_.get;
               access_.set = Private;
             } )
        )
      )
     | ( 'GetAccess' . WSOC* . '=' . WSOC*
      . ( ( /public/i
            @{ access_.full = Public;
               access_.get = Public;
             } )
        | ( /protected/i
            @{ access_.full =
                 (access_.set == Public ? Public : Protected );
               access_.get = Protected;
             } )
        | ( /private/i
            @{ access_.full = access_.set;
               access_.get = Private;
             } )
        )
       )
     | ( 'Access' . WSOC* . '=' . WSOC*
      . ( ( /public/i
            @{ access_.full = Public;
               access_.get = Public;
               access_.set = Public;
             } )
        | ( /protected/i
            @{ access_.full = Protected;
               access_.get = Protected;
               access_.set = Protected;
             } )
        | ( /private/i
            @{ access_.full = Private;
               access_.get = Private;
               access_.set = Private;
             } )
        )
       )
      ); #}}}2

  # method and property params {{{2
  methodparam =
   (
    ( paramaccess )
    | ( ( 'Abstract' . [^,)]* )
        @{
           methodparams_.abstr = true;
         } )
    | ( ( 'Static' . [^,)]* )
        @{
           methodparams_.statical = true;
         } )
    | ( ('Hidden' . [^,)]* )
        @{
           methodparams_.hidden = true;
         } )
    | ( ( 'Sealed' . [^,)]* )
        @{
           methodparams_.sealed = true;
         } )
   );

  propertyparam =
   (
    ( paramaccess )
    | ( ( 'Constant' . [^,)]* )
        @{
           propertyparams_.constant = true;
         } )
    | ( ( 'Transient' . [^,)]* )
        @{
           propertyparams_.transient = true;
         } )
    | ( ( 'Dependent' . [^,)]* )
        @{
           propertyparams_.dependent = true;
         } )
    | ( ( 'Hidden' . [^,)]* )
        @{
           propertyparams_.hidden = true;
         } )
    | ( ( 'SetObservable' . [^,)]* )
        @{
           propertyparams_.setObservable = true;
         } )
    | ( ( 'Abstract' . [^,)]* )
        @{
           propertyparams_.abstr = true;
         } )
   );

  methodparams =
   (
    '(' . WSOC*
    . methodparam
    . ( WSOC* . ',' . WSOC* . methodparam )* . WSOC* . ')'
   );

  propertyparams =
   (
    '(' . WSOC*
    . propertyparam
    . ( WSOC* . ',' . WSOC* . propertyparam )* . WSOC* . ')'
   ); #}}}2

  # swallowing events {{{2
  events := (
    ( ([ \t]* .  'e') >st_tok
      . 'nd' . [ \t;]* . EOL
        @{ tmp_string.assign(tmp_p, p - tmp_p);
                if(tmp_string.find("e") == eventindent_)
                  {
                  fgoto classbody;
                  }
              }
      | (default* - 'end') . EOL )*
   ); #}}}2

  # methods and properties {{{2
  # methods {{{4
  methods := |*
# kommentare, newlines
# nur bei keyword 'function' => goto funcdef
# abstrakter fall, eine weitere Regel wird benötigt.
# end => classbody
    (empty_line) => {
      if(runMode_.mode != RunMode::ParseMethodParams)
      {
        end_method();
        fout_ << "\n";
      }
    };

    # default: method definition
    ([ \t]* . 'function' )
      => {
        tmp_string.assign(ts, te - ts+1);
        funcindent_ = tmp_string.find_first_not_of(" \t");
        #if DEBUG
            {
              ostringstream oss;
              oss << "in methods: funcindent: " << funcindent_;
              debug_output(oss.str(), p);
            }
        #endif
        p=ts+funcindent_-1;
        fgoto funct;
       };

    # end of methods block
    ([ \t]* . 'end' . [ \t;]* . ('%' . garble_comment_line_wo_eol)? . EOL )
      => {
           if(runMode_.mode != RunMode::ParseMethodParams)
           {
             end_method();
             #if DEBUG
               debug_output("in methods: found end keyword, goto classbody",p);
             #endif
           }
           fgoto classbody;
         };

    # comment between two methods
    ([ \t]* . '%' ) => {
      #if DEBUG
        debug_output("in methods: garble comment line",p);
      #endif

      p = ts-1;
      class_part_ = InClassComment;
/*      fcall in_comment_block; */
      fgoto expect_doxyblock;
    };

    # if we reach this: method declaration without definition is found
    ([ \t]* . [^% \t\n]) =>
    {
      #if DEBUG
        debug_output("in methods: found method declaration, going to funcdef",p);
      #endif
      class_part_ = MethodDeclaration;
      p = ts-1;
      fgoto funcdef;
    };

      *|;


  methodsheader := (
    [ \t]* . methodparams? . [ \t;]* . ( '%' . garble_comment_line_wo_eol )? . EOL
         @{
            print_access_specifier(access_.full);
            fgoto methods;
          }
              );

   #}}}4

  matrix_or_cell := (
      '[' . ( [^[{\]] | [[{] @{fhold; fcall matrix_or_cell;} )* . ']' @{ fret; }
      |
      '{' . ( [^[{}]  | [[{] @{fhold; fcall matrix_or_cell;} )* . '}' @{ fret; }
      );

  matrix = ([[{] @{fhold; fcall matrix_or_cell;} );


  # single property {{{4
  prop = ( ( [ \t]* . (IDENT) >st_tok
                 %{
            string s(tmp_p, p - tmp_p);
            property_list_.push_back(s);
//            fout_ << propertyparams_.ccprefix() << " " << s;
            }
          )
        . ( ';' @{defaultprop_ = "";}
            |
            ([ =]+ %st_tok . ( matrix | [^[{;])* .';')
            @{
              defaultprop_ = string(tmp_p, p - tmp_p);
             }
          )
            . [ \t]* .
        ( '%' %st_tok . ( default - [\r\n] )*
          . EOL
            @{
               docuheader_.push_back(string(tmp_p, p - tmp_p+1));
               end_of_property_doc();
             } | EOL @{ end_of_property_doc(); }
        )
      );

  #}}}4

  property := ( prop* );

  #property body {{{4
  propertybody = (
    ( [ \t]* . ( 'end' . [ \t;]* ) . ('%' . garble_comment_line_wo_eol )? . EOL )
      @{
         fgoto classbody;
       }
    |
    (prop)
    |
    ( (empty_line) @{ fout_ << "\n";} )
    |
    ( ([ \t]* . '%') @{ fhold; fgoto expect_doxyblock; } )
    );

  properties := ( (
    WSOC* . propertyparams? . [ \t;]* . ('%' . garble_comment_line_wo_eol )? . EOL @{
        print_access_specifier(access_.full);
        }
    . propertybody* )
      );
  #}}}4

  #}}}2

  # class body {{{2
  classbody := |*

    # a comment block
    (comment_block)
      => {
        fout_.write(tmp_p, p - tmp_p+1);
        fcall in_comment_block;
      };

    (WSOC) => { fout_.write(ts, te-ts); };

    (EOL) => { fout_ << "\n"; };

    ('end' . [ \t]* ';'?) => {
      fout_ << "\n};\n";
      for(  list<string>::iterator it = namespaces_.begin();
            it != namespaces_.end(); ++it)
      {
        fout_ << "}\n";
      }
    };

    ([ \t]* . 'properties')
      => {
        propertyparams_ = PropParams();
        access_ = AccessStruct();
        class_part_ = Property;
        fgoto properties;
      };
    ([ \t]* . 'methods')
      => {
        methodparams_ = MethodParams();
        access_ = AccessStruct();
        class_part_ = Method;
        fgoto methodsheader;
      };
    ([ \t]* . 'events')
      => {
        std::string tmp_string(ts, te-ts);
        eventindent_ = tmp_string.find("e");
        class_part_ = Event;
        fgoto events;
      };
  *|; #}}}2

  # doxyblock expect {{{2
  # after function declaration expect a documentation block or the function
  # body
  expect_doxyblock :=
  (
    doc_begin
      @{
        //fout_ << "/*";
        p--;
        fgoto doxyheader;
      }
  )
 $!{
    fhold;
#ifdef DEBUG
    debug_output("stopping expect_doxyblock", p);
#endif
    if(is_class_)
    {
      if(class_part_ == Header)
      {
        end_of_class_doc();
        fgoto classbody;
      } else if(class_part_ == Method || class_part_ == AtMethod)
      {
        string endstringtest;
        endstringtest.assign(p, 100);
        string::size_type first_char = endstringtest.find_first_not_of(" \t");
        if(runMode_.mode == RunMode::ParseParams)
          return 1;
        if (endstringtest.substr(first_char, 3) == "end")
        {
          p += first_char+4;
          print_function_synopsis();
          end_function();
          fgoto methods;
        }
        else
        {
          print_function_synopsis();
          fgoto funcbody;
        }
      }
      else if(class_part_ == Property)
      {
        fgoto propertybody;
      }
      else if(class_part_ == InClassComment || class_part_ == MethodDeclaration)
      {
        class_part_ = Method;
        fgoto methods;
      }
      else{
        cerr << "MTOCPP: Do not know where to go from here. Classpart " << ClassPartNames[class_part_] << " is not handled.\n";
      }
    }
    else
    {
      if(runMode_.mode == RunMode::ParseParams)
        return 1;
      print_function_synopsis();
      fgoto funcbody;
    }
  };
  #}}}2

  # function declaration {{{2
  funcdef = (
      (WSOC)* .
      # return values (if found opt = true)
      (lparams)? .
      # matlab identifier (function name stored in cfuncname_)
      ( ('get.' @{is_getter_ = true;} | 'set.' @{is_setter_=true;} )? .
        IDENT
          >st_tok
          %{
            cfuncname_.assign(tmp_p, p - tmp_p);
            #ifdef DEBUG
              cerr << "\n Identifier of function: " << cfuncname_ << endl;
            #endif
            // in ParseMethodParams mode, we only check for the method
            // parameters of a specific method.
            if(is_class_ && class_part_ == MethodDeclaration
               && runMode_.mode == RunMode::ParseMethodParams)
            {
              if(runMode_.methodname == cfuncname_)
              {
                return 0;
              }
            }
            if(runMode_.mode == RunMode::Normal
               && is_class_ && class_part_ == AtMethod)
            {
              update_method_params(cfuncname_);
            }
            is_script_ = false;
          }
      )
      . WSOC*
      . (
           '('
           # parameter list
           . ( paramlist
               %{
                 if(paramlist_.size() == 1 && paramlist_[0] == "this")
                 { paramlist_.clear(); }
               }
             )
           . ')' . ( [ \t] | ('%' @{ tmp_p=p; comment_found=true; }
             . garble_comment_line_wo_eol) | ( ';' ) )*
           . EOL
           @{
             if(comment_found)
             {
                tmp_string.assign(tmp_p+1, p - tmp_p-1);
                tmp_string = string("/* ") + tmp_string + string("*/");
             }
             else
             {
                tmp_string = "";
             }
             comment_found = false;
             if(is_class_ && class_part_ == MethodDeclaration )
             {
               class_part_ = Method;
               #if DEBUG
                 debug_output("in funcdef: end of method declaration, returning to methods",p);
               #endif
               fgoto methods;
             }
             else
             {
               //               fout_ << tmp_string << "{\n";
               // check for documentation block
               fgoto expect_doxyblock;
             }
           }
        # no parameter list && first function => ( script || method )
        | (( [ \t]
              |
             ('%' @{ tmp_p=p; comment_found=true; }
              . garble_comment_line_wo_eol) | ( ';' ) )* . EOL)
            @{
                 if(comment_found)
                 {
                   tmp_string.assign(tmp_p+1, p - tmp_p-1);
                   tmp_string = string("/* ") + tmp_string + string("*/");
                 }
                 else
                 {
                   tmp_string = "";
                 }
                 comment_found = false;
                 #if DEBUG
                   debug_output("in funcdef: script && no parameters: expect doxyblock",p);
                 #endif
                 if(is_class_ && class_part_ == MethodDeclaration)
                 {
                    class_part_ = Method;
                    fgoto methods;
                 }
                 else
                 {
                   fgoto expect_doxyblock;
                 }
             }
        )
      );

  funct :=
  (
    (
      comment_block @in_c_block
      | [ \t]*. EOL
    )*
    . [\t]* . 'function'
    . funcdef
  ) $eof( end_of_file ) ; #}}}2

  # no function definition => a script {{{2
  script := (default)
    @{
       string :: size_type found = filename_.rfind("/");
       if(found == string :: npos)
         found = -1;
       string funcname = filename_.substr(found+1, filename_.size()-3-found);
       cfuncname_.assign( funcname );
  /*     fout_ << "noret::substitute ";
       if(!is_first_function_)
         fout_ << "mtoc_subst_" << fnname_ << "_tsbus_cotm_";
       fout_ << funcname << "() {\n";*/
       is_script_ = true;
       fhold;
       fgoto expect_doxyblock;
     }; #}}}2

  # class definitions {{{2
  classparams =
      '(' . [^)]* . ')';

  superclass =
    ( ( IDENT_W_DOT ) >{ fout_ << "public ::"; }
                      @{ if(*p == '.')
                           fout_ << "::";
                         else fout_ << *p; } );

  superclasses = (
      '<' @{ fout_ << "\n  :"; } . WSOC* . superclass . WSOC*
          . ('&' @{ fout_ << ",\n   "; } . WSOC* . superclass . WSOC*)* );

  classdef := (
      'classdef' . WSOC* . ('(' . WSOC*
        . ( 'Sealed'
          @{
            docuextra_.push_back(std::string("@note This class has the class property 'Sealed' and cannot be derived from."));
           }
          ) . [^)]* . ')')? . WSOC* .
      # matlab identifier (class name stored in classname_)
      ( IDENT
          >st_tok
          %{
            classname_.assign(tmp_p, p - tmp_p);
            is_class_ = true;
            fout_ << "class " << classname_;
          }
      )
      . WSOC*
      . classparams?
      . WSOC*
      . superclasses?
      . [ \t;]*
      . ( '%'. garble_comment_line_wo_eol )?
      EOL
      @{
        fout_ << " {\n";
        fgoto expect_doxyblock;
      } );

  # }}}2

  # main loop {{{2
  expect_function_script_or_class =
  (
    # either we find a function or classdef definition with a possibly
    # preceding comment block or we have a script
    ( any @{ fhold; tmp_p = p; } .
    (
      [ \t]*. '%' . (any - '\n')* . EOL
      | [ \t]*. EOL
    )*
    . [\t]*
    . ( 'function' @{
                     p=tmp_p;
                     if(is_class_ && class_part_ == Header)
                       class_part_ = AtMethod;
                     fgoto funct;
                    }
      | 'classdef' @{
                     p=tmp_p;
                     fgoto classdef;
                    }
      ) )
  $!{
#ifdef DEBUG
    debug_output("goto script",p);
#endif
    p=tmp_p;
    fgoto script;
  }
  );

  main := expect_function_script_or_class*;
  # }}}2

}%%

void MFileScanner :: update_method_params(const std::string & methodname)
{
  istream  *fcin;
  ifstream  fin;
  try
  {
    std::string filename(dirname_ + "/" + classname_ + ".m");
    std::ios_base::iostate oldstate = fin.exceptions();
    fin.exceptions ( ifstream::failbit | ifstream::badbit );
    fin.open(filename.c_str());
    fin.exceptions(oldstate);
    fcin = &fin;
    ostringstream oss;
    RunMode methodParamsMode = runMode_;
    methodParamsMode.mode = RunMode::ParseMethodParams;
    methodParamsMode.methodname = methodname;
    MFileScanner scanner(*fcin, oss, filename, cscan_.get_conffile(), methodParamsMode);
    scanner.execute();
    methodparams_ = scanner.getMethodParams();
  }
  catch (ifstream::failure e)
  {
    std::cerr << "MTOCPP Warning: No method params for @-function " << methodname << " found!\n";
  }
}

void MFileScanner :: print_pure_function_synopsis()
{
  // do we have a constructor?
  if(is_class_ && (cfuncname_ == classname_))
    returnlist_.clear();
  else{
    if(returnlist_.size() == 0)
      fout_ << "noret::substitute ";
    else
    {
      if(returnlist_.size() > 1)
        fout_ << "mlhsSubst<";
      for(unsigned int i=0; i < returnlist_.size(); ++i)
      {
        std::string typen;
        if(runMode_.void_type_in_return_values)
          get_typename(returnlist_[i], typen, "void");
        else
          get_typename(returnlist_[i], typen);

        fout_ << "mlhsInnerSubst<" << typen;
        if (runMode_.print_return_value_name - (returnlist_.size() == 1) > 0)
          fout_ << "," << returnlist_[i];
        fout_ << "> ";
        if (i < returnlist_.size() - 1)
          fout_ << ",";
      }
      if(returnlist_.size() > 1)
        fout_ << "> ";
    }
  }

  bool first = true;
  if(is_first_function_)
  {
    if(is_class_ && class_part_ == AtMethod)
      fout_ << namespace_string() << classname_ << "::";
  }
  else
    fout_ << "mtoc_subst_" << fnname_ << "_tsbus_cotm_";

  fout_ << cfuncname_;

  if(paramlist_.size() == 0)
    fout_ << "()\n  ";
  else
  {
#if DEBUG
    cerr << "paramlist size of " << cfuncname_ << ": " << paramlist_.size() << " first element: " << paramlist_[0] << endl;
#endif
    fout_ << "(";
    for(unsigned int i=0; i < paramlist_.size(); ++i)
    {
      if(!first)
        fout_ << ",";
      else
        first = false;

      std::string typen;// = "matlabtypesubstitute";
      get_typename(paramlist_[i], typen);
      std::string defvalue;
      get_default(paramlist_[i], defvalue);
      fout_ << typen << " " << paramlist_[i];
    }
/*    for(unsigned int i=0; i < returnlist_.size(); ++i)
    {
      std::string typen;// = "matlabtypesubstitute";
      get_typename(returnlist_[i], typen);
    }
*/
    fout_ << ")";
  }
}

void MFileScanner :: print_function_synopsis()
{
  if(is_getter_ || is_setter_)
  {
   fout_ << "/* \n";
  }
  if(is_class_ && (class_part_ == Method
                   || class_part_ == AtMethod
                   || class_part_ == MethodDeclaration)
    )
  {
    fout_ << methodparams_.ccprefix();
  }

  print_pure_function_synopsis();

  if(is_class_ && class_part_ == MethodDeclaration )
    fout_ << methodparams_.ccpostfix() << "\n";
  else
    fout_ << " {\n";
}

std::string MFileScanner :: access_specifier_string(AccessEnum & access)
{
  if(access == Public)
    return "public";
  else if(access == Protected)
    return "protected";
  else if(access == Private)
    return "private";
  return "";
}

void MFileScanner :: print_access_specifier(AccessEnum & access)
{
  const std::string ass = access_specifier_string(access);
  fout_ << ass << ":\n";
}

// constructor
MFileScanner :: MFileScanner(istream & fin, ostream & fout,
                             const std::string & filename,
                             const std::string & conffilename,
                             RunMode runMode = RunMode()
                            ) :
  fin_(fin), fout_(fout), filename_(filename),
  cscan_(filename_, conffilename),
  fnname_(filename), namespaces_(),
  buf(new char[BUFSIZE]), line(1),
  ts(0), have(0), top(0),
  opt(false), new_syntax_(false),
  is_script_(false), is_first_function_(true),
  is_class_(false), is_setter_(false), is_getter_(false),
  classname_(), funcindent_(0), eventindent_(0),
  class_part_(Header),
  access_(), propertyparams_(), methodparams_(), property_list_(),
  runMode_(runMode)
{
  string::size_type found = fnname_.find_last_of('/');
  if(found != string::npos)
    dirname_ = filename.substr(0, found);

  list<string> namespaces;
  string classname;
  string::size_type enddir = dirname_.size();
  string::size_type ppos = 0;
  while (ppos != string::npos)
  {
    ppos = dirname_.find_last_of('/', enddir);
    string directory;
    if(ppos == string::npos)
      directory = dirname_.substr(0, enddir+1);
    else
      directory = dirname_.substr(ppos+1, enddir-ppos);

    if(directory[0] == '+')
    {
      namespaces_.push_front(directory.substr(1));
    }
    else if(directory[0] == '@')
    {
      classname_ = directory.substr(1);
      is_class_ = true;
      if(classname_
          != fnname_.substr(fnname_.find_last_of('/')+1, classname_.size()))
      {
        class_part_ = AtMethod;
        fout_ << "#include \"" << classname_ << ".m\"" << endl;
      }
    }
    else
      break;
    enddir = ppos - 1;
  }
  for (list<string>::iterator it = namespaces_.begin();
       it != namespaces_.end(); ++it)
    fout_ << "namespace " << *it << "{" << endl;

  found = fnname_.rfind("/");
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
  if(cscan_.vars_.find(string("LATEX_OUTPUT"))!=cscan_.vars_.end())
  {
    if(cscan_.vars_[string("LATEX_OUTPUT")][0] == string("true"))
    {
      runMode_.latex_output = true;
    }
    else
    {
      runMode_.latex_output = false;
    }
  }
  if(cscan_.vars_.find(string("PRINT_FIELDS"))!=cscan_.vars_.end())
  {
    if(cscan_.vars_[string("PRINT_FIELDS")][0] == string("true"))
    {
      runMode_.print_fields = true;
    }
    else
    {
      runMode_.print_fields = false;
    }
  }
  if(cscan_.vars_.find(string("COPY_TYPIFIED_FIELD_DOCU"))!=cscan_.vars_.end())
  {
    if(cscan_.vars_[string("COPY_TYPIFIED_FIELD_DOCU")][0] == string("true"))
    {
      runMode_.copy_typified_field_docu = true;
    }
    else
    {
      runMode_.copy_typified_field_docu = false;
    }
  }
  if(cscan_.vars_.find(string("AUTO_ADD_FIELDS"))!=cscan_.vars_.end())
  {
    if(cscan_.vars_[string("AUTO_ADD_FIELDS")][0] == string("true"))
    {
      runMode_.auto_add_fields = true;
    }
    else
    {
      runMode_.auto_add_fields = false;
    }
  }
  if(cscan_.vars_.find(string("AUTO_ADD_PARAMETERS"))!=cscan_.vars_.end())
  {
    if(cscan_.vars_[string("AUTO_ADD_PARAMETERS")][0] == string("true"))
    {
      runMode_.auto_add_params = true;
    }
    else
    {
      runMode_.auto_add_params = false;
    }
  }
  if(cscan_.vars_.find(string("AUTO_ADD_CLASS_PROPERTIES"))!=cscan_.vars_.end())
  {
    if(cscan_.vars_[string("AUTO_ADD_CLASS_PROPERTIES")][0] == string("true"))
    {
      runMode_.auto_add_class_properties = true;
    }
    else
    {
      runMode_.auto_add_class_properties = false;
    }
  }
  if(cscan_.vars_.find(string("AUTO_ADD_CLASSES"))!=cscan_.vars_.end())
  {
    if(cscan_.vars_[string("AUTO_ADD_CLASSES")][0] == string("true"))
    {
      runMode_.auto_add_class = true;
    }
    else
    {
      runMode_.auto_add_class = false;
    }
  }
  if(cscan_.vars_.find(string("REMOVE_FIRST_ARG_IN_ABSTRACT_METHODS"))!=cscan_.vars_.end())
  {
    if(cscan_.vars_[string("REMOVE_FIRST_ARG_IN_ABSTRACT_METHODS")][0] == string("true"))
    {
      runMode_.remove_first_arg_in_abstract_methods = true;
    }
    else
    {
      runMode_.remove_first_arg_in_abstract_methods = false;
    }
  }
  if(cscan_.vars_.find(string("ENABLE_OF_TYPE_PARSING"))!=cscan_.vars_.end())
  {
    if(cscan_.vars_[string("ENABLE_OF_TYPE_PARSING")][0] == string("true"))
    {
      runMode_.parse_of_type = true;
    }
    else
    {
      runMode_.parse_of_type = false;
    }
  }
  if(cscan_.vars_.find(string("VOID_TYPE_IN_RETURN_VALUES"))!=cscan_.vars_.end())
  {
    if(cscan_.vars_[string("VOID_TYPE_IN_RETURN_VALUES")][0] == string("true"))
    {
      runMode_.void_type_in_return_values = true;
    }
    else
    {
      runMode_.void_type_in_return_values = false;
    }
  }
  if(cscan_.vars_.find(string("PRINT_RETURN_VALUE_NAME"))!=cscan_.vars_.end())
  {
    string tmp = cscan_.vars_[string("PRINT_RETURN_VALUE_NAME")][0];
    if(tmp == string("0"))
    {
      runMode_.print_return_value_name = 0;
    }
    else if(tmp == string("1"))
    {
      runMode_.print_return_value_name = 1;
    }
    else
    {
      runMode_.print_return_value_name = 2;
    }
  }
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
    bool comment_found = false;
    int space = BUFSIZE - have;

    if ( space == 0 )
    {
      /* We filled up the buffer trying to scan a token. */
      cerr << "MTOCPP: OUT OF BUFFER SPACE" << endl;
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
      cerr << "MTOCPP:" << std::string(filename_) << ": PARSE ERROR in line " << line << endl;
      debug_output("Grrrr!!!!", p);
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
void MFileScanner::write_docu_block(const DocuBlock & block_orig)
{

  DocuBlock block = block_orig;
  std::string temp;
  extract_typen(block, temp, true);

  bool add_prefix   = false;
  bool latex_begin  = true;
  bool not_verbatim = true;
  for( unsigned int i = 0; i < block.size(); i += 1 )
  {
    // begin all documentation lines after the first one with an asterisk (unless in verbatim mode)
    if(add_prefix)
    {
      if(not_verbatim)
        fout_ << "* ";
      else
        fout_ << "  ";
    }

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
        fout_ << s.substr(i,j-i);
      }
      // use typewriter fonts for words in single quotes
      else if(s[i] == '\'' && not_verbatim && latex_begin)
      {
        if(j != s.size() && s[j] == '\'' && !last_char_escaped)
        {
          if(j==i+1)
            fout_ << '\'';
          else
            fout_ << "<tt>" << s.substr(i+1, j-i-1) << "</tt>";
          ++j;
        }
        else
          fout_ << s.substr(i,j-i);
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
        fout_ << lout << s.substr(i, j-i);
      }
      // new line
      else if(s[i] == '\n')
      {
        fout_ << "\n  ";
        if(latex_begin)
          add_prefix = true;
        else
        {
          fout_ << "  ";
          add_prefix = false;
        }
      }
      else
      {
        fout_ << s.substr(i,j-i);
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
                                   const AltDocuList & alternative,
                                   bool add_undocumented = false,
                                   const string separator = string(),
                                   const string docu_list_name = string())
{
  typedef DocuList :: const_iterator                                 list_iterator;
  typedef AltDocuList :: const_iterator                              alt_list_iterator;
  list_iterator lit = list.begin();
  // iterate over documentation blocks
  for(; lit != list.end(); ++lit)
  {
    std::string name = (*lit).first;
    if (name.substr(0, 6) == std::string("unused")
        && name.find_first_not_of("0123456789", 7) == std::string::npos)
      continue;
    ostringstream oss;
    oss << "* " << item_text << " " << name << separator << "    ";
    const DocuBlock & block = (*lit).second;

    bool use_alternative = false;
    if(block.size() == 1)
    {
      size_t typeof_length = 0;
      if (block[0].substr(0, 9) == std::string(" of type "))
        typeof_length = 9;
      else if (block[0].substr(0, 7) == std::string(" @type "))
        typeof_length = 7;

      if (typeof_length > 0
           && block[0].find_first_of(" ", typeof_length) == std::string::npos)
        use_alternative = true;
    }

    if(block.empty() || use_alternative)
    {
      // then look for alternative documentation block from global
      // configuration file ...
      alt_list_iterator alit = alternative.find((*lit).first);
      if(alit == alternative.end() || (*alit).second.empty())
      {
        string s((*lit).first);
        typedef map< string, string > :: iterator                  MapIterator;
        MapIterator param_type_map_entry = param_type_map_.end();
        if(!docu_list_name.empty() && runMode_.copy_typified_field_docu)
        {
          param_type_map_entry = param_type_map_.find(docu_list_name);
        }

        if(param_type_map_entry != param_type_map_.end())
        {
          // ... or copy documentation brief text from class documentation ...
          string temp = s.substr(0, s.find_first_of("."));
          fout_ << oss.str() << "@copybrief " << (*param_type_map_entry).second << "::" << temp << "\n  ";
        }
        else
        {
          if (add_undocumented)
          {
            // ... or use default text generated from variable name.
            fout_ << oss.str() << replace_underscore(s) << "\n  ";
          }
        }
      }
      else
      {
        fout_ << oss.str();
        write_docu_block((*alit).second);
      }
    }
    else
    {
      fout_ << oss.str();
      write_docu_block(block);
    }
  }
}

// pretty print a documentation block list map \a listmap with prepended title
// \a text. If listmap entry is empty, \a altlistmap is used instead.
void MFileScanner::write_docu_listmap(const DocuListMap & listmap,
                                      const string & text,
                                      const AltDocuListMap & altlistmap)
{
  typedef DocuListMap :: const_iterator                              map_iterator;
  typedef AltDocuListMap :: const_iterator                           alt_map_iterator;
  if(!listmap.empty())
  {
    map_iterator mit = listmap.begin();
    for(; mit != listmap.end(); ++mit)
    {
      fout_ << "*\n  ";
      fout_ << "* " << text << (*mit).first << ":\n  ";
      alt_map_iterator amit = altlistmap.find((*mit).first);
      write_docu_list((*mit).second,
                      "@arg \\c",
                      ( amit != altlistmap.end() ? (*amit).second : AltDocuList() ),
                      runMode_.auto_add_fields,
                      "&nbsp;&mdash;&nbsp;",
                      (*mit).first );
    }
//    fout_ << "* </TABLE>\n  ";

  }
}

string MFileScanner::namespace_string()
{
  ostringstream oss;
  oss << "";
  for( list<string>::iterator it = namespaces_.begin();
       it != namespaces_.end(); ++it)
  {
    oss << *it << "::";
  }
  return oss.str();
}

void MFileScanner::end_of_class_doc()
{
  if (!docuheader_.empty() || runMode_.auto_add_class)
  {
    fout_ << "/** @class \"" << namespace_string() << classname_ << "\"\n  ";

    cout_ingroup();

    fout_ << "* @brief ";
    cout_docuheader(cfuncname_);
    fout_ << "*\n  ";
    cout_docubody();
    fout_ << "*\n ";
    cout_docuextra();
    fout_ << "*/\n";
  }
}


void MFileScanner::end_of_property_doc()
{
  add_property_params_info();
  typedef DocuBlock :: iterator                                      DBIt;
  string typen;
  extract_typen(docuheader_, typen);
  if(typen.empty())
    extract_typen(docubody_, typen);

  string defval;
  extract_default(docubody_, defval);

  if(typen.empty())
    typen = "matlabtypesubstitute";

  fout_ << propertyparams_.ccprefix() << typen << " " << property_list_.back();
  if(defaultprop_.empty())
    fout_ << ";\n";
  else
    fout_ << " = " << defaultprop_ << ";\n";

  if (!docuheader_.empty() || runMode_.auto_add_class_properties)
  {
    fout_ << "/** @var " << property_list_.back() << "\n  ";
    fout_ << "* @brief ";
    cout_docuheader(property_list_.back());
    fout_ << "*\n  ";
    cout_docubody();
    fout_ << "*\n ";
    cout_docuextra();
    fout_ << "*/\n";
  }
  docuheader_.clear();
  docubody_.clear();
  docuextra_.clear();
}

void MFileScanner::cout_docuheader(string altheader, bool clear)
{
  if(docuheader_.empty() && cscan_.docuheader_.empty())
  {
    fout_ << replace_underscore(altheader) << "\n  ";
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
  if(clear)
    docuheader_.clear();
}

void MFileScanner :: cout_docubody()
{
  if(!docubody_.empty())
  {
    fout_ << "*\n  * ";
    write_docu_block(docubody_);
  }
  docubody_.clear();
  if(!cscan_.docubody_.empty())
  {
    fout_ << "*\n  * ";
    write_docu_block(cscan_.docubody_);
  }
}

void MFileScanner :: cout_docuextra()
{
  if(! cscan_.docuextra_.empty())
  {
    fout_ << "*\n  * ";
    write_docu_block(cscan_.docuextra_);
  }
  if(! docuextra_.empty())
  {
    fout_ << "*\n  * ";
    write_docu_block(docuextra_);
  }
  docuextra_.clear();
}

void MFileScanner :: cout_ingroup()
{
  typedef GroupSet     :: iterator group_iterator;
  // add @ingroup commands from the configuration file
  if((! groupset_.empty() || ! cscan_.groupset_.empty() ))
  {
    fout_ << "* @ingroup ";
    bool not_first = false;
    group_iterator git = cscan_.groupset_.begin();
    for(; git != cscan_.groupset_.end(); ++git)
    {
      if(not_first)
        fout_ << " ";
      else
        not_first = true;

      fout_ << *git;
    }
    groupset_.clear();
    fout_ << "\n  ";
  }
}

void MFileScanner::clear_lists()
{
#ifdef DEBUG
  std::cerr << "clear lists" << endl;
#endif
  paramlist_.clear();
  /* param_defaults_.clear(); */
  returnlist_.clear();
  param_list_.clear();
  return_list_.clear();
  required_list_.clear();
  optional_list_.clear();
  retval_list_.clear();
  param_type_map_.clear();
}

/* we come here, from an empty line in a methods block or the end of a
 * methods block
 */
void MFileScanner::end_method()
{
  if (!cfuncname_.empty())
  {

    if(runMode_.mode != RunMode::ParseMethodParams
       && docuheader_.empty()
       && !methodparams_.abstr)
    {
      istream  *fcin;
      ifstream  fin;
      try
      {
        std::string filename(dirname_ + "/" + cfuncname_ + ".m");
        std::ios_base::iostate oldstate = fin.exceptions();
        fin.exceptions ( ifstream::failbit | ifstream::badbit );
        fin.open(filename.c_str());
        fin.exceptions(oldstate);
        fcin = &fin;
        ostringstream oss;
        RunMode paramsMode = runMode_;
        paramsMode.mode = RunMode::ParseParams;
        MFileScanner scanner(*fcin, oss, filename, cscan_.get_conffile(), paramsMode);
        scanner.execute();
        param_list_ = scanner.getParamList();
      }
      catch (ifstream::failure e)
      {
        std::cerr << "MTOCPP Warning: No definition for function " << cfuncname_
          << " found in class " << classname_ << "!\n";
      }
    }

    class_part_ = MethodDeclaration;
    print_function_synopsis();
    class_part_ = Method;

    // for abstract methods: print out documentation of the abstract method
    // declaration
    if(methodparams_.abstr)
      end_function();
    else
    // otherwise: all the following comments are not related to this function
    // anymore, so we delete traces of the method name...
    {
      cfuncname_.clear();
      clear_lists();
    }
  }
  // free documentation block variables
  docuheader_.clear();
  docubody_.clear();
  docuextra_.clear();
}

void MFileScanner::extract_default(DocuBlock & db, std::string & defvalue)
{
  typedef DocuBlock :: iterator                                      DBIt;

  for(DBIt dit = db.begin(); dit != db.end(); ++dit)
  {
    std::string & line   = *dit;
    size_t found         = std::string::npos;
    size_t deflength     = std::string("(default").length();
    found                = line.find("(default");
    if(found != std::string::npos)
    {
      size_t tmp;
      if(line[found+1] == '=')
        tmp = found + deflength + 1;
      else if (line[found+2] == '=')
        tmp = found + deflength + 2;
      else
        found = std::string::npos;

      if (found != std::string::npos)
      {
        defvalue = line.substr(tmp+1);
        defvalue = defvalue.substr(0, defvalue.length() - 1);
      }
    }
    if(found == std::string::npos)
    {
      deflength     = string("@default ").length();
      found         = line.find("@default ");
      if (found != std::string::npos)
      {
        size_t end = line.find("@", found+1);
        if (end == std::string::npos)
          end = line.find("of type");
        if (end == std::string::npos)
          end = line.length();
        end = end - 1;
        size_t start = found + deflength + 1;
        defvalue = line.substr(start, end - start);
        line[found]   = '(';
        line[found+8] = '=';
        line = line.substr(0, found) + "( @b default = "
          + line.substr(found+9,end-found-9) + " )" + line.substr(end);
      }
      else
      {
        defvalue = std::string("");
      }
    }
  }
}

void MFileScanner::get_default(const std::string & paramname, std::string & defvalue)
{
  typedef DocuList :: iterator                                       DLIt;
  DLIt it  = param_list_.find(paramname);
  if(it != param_list_.end() && !(it->second).empty())
  {
    DocuBlock & db   = it->second;
    extract_default(db, defvalue);
  }
  else
  {
    defvalue = std::string("");
  }
}

void MFileScanner::get_typename(const std::string & paramname, std::string & typen, std::string voidtype)
{
  typedef DocuList :: iterator                                       DLIt;
  typedef AltDocuList :: iterator                                    ADLIt;
  typedef DocuBlock :: iterator                                      DBIt;
  DLIt it  = param_list_.find(paramname);
  DocuBlock * pdb;
  if(it != param_list_.end() && !(it->second).empty())
    pdb   = &(it->second);
  else
  {
    it = return_list_.find(paramname);
    if(it != return_list_.end() && !(it->second).empty())
      pdb   = &(it->second);
    else
    {
      ADLIt ait = cscan_.param_list_.find(paramname);
      if(ait != cscan_.param_list_.end() && !(ait->second).empty())
        pdb   = &(ait->second);
      else
      {
        ait = cscan_.return_list_.find(paramname);
        if(ait != cscan_.return_list_.end() && !(ait->second).empty())
          pdb   = &(ait->second);
        else
        {
          typen=voidtype;
          return;
        }
      }
    }
  }

  DocuBlock & db = *pdb;
  extract_typen(db, typen);

  if(typen.empty())
    typen = voidtype;
  else
    param_type_map_[paramname] = typen;
}

// ATTENTION: The get_typename method changes the docublock and removes the
// "@type " respectively "of type" strings if remove is set to true.
void MFileScanner::extract_typen(DocuBlock & db, std::string & typen, bool remove)
{
  int linenr = 1;
  typedef DocuBlock :: iterator                                      DBIt;
  for(DBIt dit = db.begin(); dit != db.end(); ++dit, ++linenr)
  {
    std::string line   = *dit;
    size_t found         = std::string::npos;
    size_t typeof_length = 0;                         // length of string "of type" respectively "@type"
    if(runMode_.parse_of_type && linenr < 2)
    {
      found         = line.find("of type");
      typeof_length = string("of type").length();
    }
    if(found == std::string::npos)
    {
      found         = line.find("@type");
      typeof_length = string("@type").length();
    }
    if(found != std::string::npos)
    {
      size_t typenstart = found + typeof_length;
      // find start of type name
      typenstart=line.find_first_not_of( " \t\n\0", typenstart );
      if (typenstart == std::string::npos)
      {
        // read in next line
        if (remove)
          (*dit).erase(found, line.length() - found - 1);

        ++dit;
        if (dit == db.end())
          break;
        line = *dit;
        found = 0;
        typenstart = line.find_first_not_of( " \t");
      }
      // find end of type name
      size_t typenend =
        line.find_first_of( " \n\0", typenstart );
      typen = line.substr(typenstart, typenend - typenstart);
      // remove trailing '.' if necessary
      if (typen[typen.length()-1] == '.')
      {
        typen = typen.substr(0, typen.length() - 1);
      }
      // add leading '::' just to make sure, we only have global scope variables.
      if(typen[0] != ':')
      {
        for(size_t i=0; i < typen.length(); ++i)
          if(typen.at(i) == '.')
            typen.replace(i,1,std::string("::"));
        typen = string("::") + typen;

//        (*dit).replace(typenstart, typenend - typenstart, typen);
      }
      if (remove)
      {
        (*dit).erase(found, typenend - found);
      }
    }
  }
}

void MFileScanner::add_access_info(std::string what)
{
  if (access_.get != access_.set)
  {
    docuextra_.push_back(std::string("@note This ") + what + std::string(" has non-unique access specifier: "));
    std::string setAccess = access_specifier_string(access_.set);
    std::string getAccess = access_specifier_string(access_.get);
    docuextra_.push_back(std::string("SetAccess = ") + setAccess + ", "
                       + std::string("GetAccess = ") + getAccess + std::string("\n"));
  }
}

void MFileScanner::add_property_params_info()
{
  if (propertyparams_.hidden)
  {
    docuextra_.push_back(std::string("@note This property has the MATLAB parameter 'Hidden' set to true.\n"));
  }
  if (propertyparams_.transient)
  {
    docuextra_.push_back(std::string("@note This property has the MATLAB parameter 'Transient' set to true.\n"));
  }
  if (propertyparams_.dependent)
  {
    docuextra_.push_back(std::string("@note This property has the MATLAB parameter 'Dependent' set to true.\n"));
  }
  if (propertyparams_.setObservable)
  {
    docuextra_.push_back(std::string("@note This property has the MATLAB parameter 'SetObservable' set to true.\n"));
  }
  if (propertyparams_.setObservable)
  {
    docuextra_.push_back(std::string("@note This property is an @em abstract property without implementation.\n"));
  }

  add_access_info("property");
}

void MFileScanner::add_method_params_info()
{
  if (methodparams_.hidden)
  {
    docuextra_.push_back(std::string("@note This method has the MATLAB method property 'Hidden' set to true.\n"));
  }
  if (methodparams_.sealed)
  {
    docuextra_.push_back(std::string("@note This method has the MATLAB method property 'Sealed' set to true. It cannot be overwritten.\n"));
  }
  add_access_info("method");
}

// end a function and pretty print the documentation for this function
void MFileScanner::end_function()
{
  bool is_constructor = false;
  bool is_method = false;
  bool skip_parameters = false;
  /* If copydoc or copydetails is used in the documentation body or the
   * documentation header, the automatic parameter doc strings need to be
   * skipped. */
  if (! docuheader_.empty()
       && docuheader_[0].find("copydoc") != std::string::npos)
  {
    skip_parameters = true;
  }
  if (! docubody_.empty())
  {
    for (unsigned int i = 0; i < docubody_.size(); ++i)
    {
      size_t pos_begin_copy = docubody_[i].find("copydoc");
      if(pos_begin_copy == std::string::npos)
      {
        pos_begin_copy = docubody_[i].find("copydetails");
      }
      if(pos_begin_copy != std::string::npos)
      {
        size_t pos_word_begin = docubody_[i].find_first_of(" \n", pos_begin_copy + 1);
        pos_word_begin        = docubody_[i].find_first_not_of(" \n", pos_word_begin);
        if(pos_word_begin != std::string::npos)
        {
          size_t pos_word_end   = docubody_[i].find_first_of("(", pos_word_begin);
          if(pos_word_end != std::string::npos)
          {
            std::string func      = docubody_[i].substr(pos_word_begin, pos_word_end-pos_word_begin);
            size_t pos_func_beg   = func.find_last_of(":. ");
            func                  = func.substr(pos_func_beg+1);
            if(func == cfuncname_)
            {
              skip_parameters = true;
            }
          }
        }
      }
    }
  }
  if(is_class_)
  {
    if(class_part_ == Property)
      return;

    add_method_params_info();

    if(cfuncname_ == classname_)
      is_constructor = true;
    if(class_part_ == Method)
      is_method = true;
  }
  // end function
  if(!is_method || !methodparams_.abstr)
    fout_ << "}\n";
  if(is_getter_ || is_setter_)
    fout_ << "*/\n";
  if (!docuheader_.empty() || runMode_.auto_add_class_properties)
  {
    // is the first function?
    if(is_first_function_)
    {
      if(! runMode_.latex_output && ! is_class_)
      {
        // Then make a file documentation block
        fout_ << "/** @file \"" << filename_ << "\"\n  ";
        cout_ingroup();
        fout_ << "* @brief ";
        cout_docuheader(cfuncname_, false);
        fout_ << "*/\n";
      }
    }
    fout_ << "/*";
    if(runMode_.latex_output && !is_class_)
    {
      cout_ingroup();
      fout_ << "\n  ";
    }
    if(is_setter_ || is_getter_)
    {
      fout_ << "* @var " << cfuncname_ << "\n  ";
      string temp = (is_setter_ ? "Setter" : "Getter");
      fout_ << "* @par " << temp << " is implemented\n  *";
    }
    else
    {
      // specify the @fn part
      fout_ << "* @fn ";
      print_pure_function_synopsis();

      // specify the @brief part
      fout_ << "\n  * @brief ";
    }
    cout_docuheader(cfuncname_);
    fout_ << "*\n  ";

    // specify the @details part

    // standard body definitions
    cout_docubody();

    if (! skip_parameters)
    {
      // parameters
      if(!param_list_.empty() && !is_getter_ && !is_setter_)
      {
        fout_ << "*\n  ";
        write_docu_list(param_list_, "@param", cscan_.param_list_,
                        runMode_.auto_add_params);
      }

      // return values
      if(!return_list_.empty() && !is_constructor && !is_getter_ && !is_setter_)
      {
        fout_ << "*\n  ";
        write_docu_list(return_list_, "@retval", cscan_.return_list_,
                        runMode_.auto_add_params);
      }

      if(runMode_.print_fields)
      {
        // required fields
        write_docu_listmap(required_list_, "@par Required fields of ", cscan_.field_docu_);

        // optional fields
        write_docu_listmap(optional_list_, "@par Optional fields of ", cscan_.field_docu_);

        // return fields
        write_docu_listmap(retval_list_, "@par Generated fields of ", cscan_.field_docu_);
      }
    }
    #ifdef DEBUG
      std::cerr << "CLEARING LISTS!";
    #endif
    clear_lists();

    // extra docu fields
    cout_docuextra();
    if( new_syntax_ )
    {
      fout_ << "* @synupdate Syntax needs to be updated! \n  ";
    }
    fout_ << "*/\n";
    }
  else
  {
    clear_lists();
  }
  if(!is_method)
    is_first_function_ = false;

  is_setter_ = false; is_getter_ = false;
  cfuncname_.clear();
}

void MFileScanner::debug_output(const std::string & msg, char * p)
{
  std::cerr << "Message: " << msg << "\n";
  std::cerr << "Next 20 characters to parse: \n";
  std::cerr.write(p, 20);
  std::cerr << "\n------------------------------------\n";
  std::cerr << "States are: ClassPart: " << ClassPartNames[class_part_] << "\n"
    << propertyparams_ << methodparams_ << access_;
  std::cerr << "\n------------------------------------\n";
}

void MFileScanner::postprocess_unused_params(std::string & param, DocuList & doculist)
{
  if (param == std::string("~"))
  {
    int counter = 1;
    bool found = true;
    while ( found )
    {
      std::ostringstream oss;
      oss << "unused" << counter;
      if (doculist.find(oss.str()) == doculist.end())
      {
        param = oss.str();
        found = false;
      }
      ++counter;
    }
  }
}


std::ostream & operator<<(std::ostream & os, AccessStruct & as)
{
  os << "AccessStruct: full = " << AccessEnumNames[as.full] << " get  = " <<
    AccessEnumNames[as.get] << " set  = " << AccessEnumNames[as.set] << "\n";
  return os;
}

std::ostream & operator<<(std::ostream & os, PropParams & pp)
{
  os << "PropParams: constant = " << pp.constant << "\n";
  return os;
}

std::ostream & operator<<(std::ostream & os, MethodParams & mp)
{
  std::string abstract = mp.abstr ? "abstract, " : "";
  std::string statics = mp.statical ? "static, " : "";
  os << "MethodParams: " << abstract << statics << "\n";
  return os;
}

/* vim: set et sw=2 ft=ragel foldmethod=marker: */

