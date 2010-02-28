#include "confscanner.h"

extern "C" {
#include <fnmatch.h>
}

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::set;
using std::ifstream;

%%{
  machine ConfFileScanner;
  write data;

  action st_tok { /*cerr << "st_tok" << line << "\n";*/ tmp_p = p; }

  action string_tok {
    tmp_string.assign(tmp_p, p-tmp_p);
  }

  action group_add
  {
//    cerr << "in group add: " << endl;
    if(match_at_level_[level_])
    {
//      cerr << "do it" << endl;
      tmp_string.assign(tmp_p, p-tmp_p);
      // clear groupset_ first, if we did not use '+='
      if(!arg_to_be_added_)
        groupset_.clear();

      groupset_.insert(tmp_string);
    }
  }

  action set_docu_block
  {
    tmp_string.assign(tmp_p, p-tmp_p);
    if(tmp_string == "brief")
      cblock_ = &docuheader_;
    else if(tmp_string == "doc")
      cblock_ = &docubody_;
    else if(tmp_string == "extra")
      cblock_ = &docuextra_;
  }

  action set_docu_list
  {
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "docu_list: " << tmp_string << "\n";
    if(tmp_string == "params")
    {
      //cerr << "paramlist\n";
      clist_ = &param_list_;
    }
    else if(tmp_string == "return")
      clist_ = &return_list_;
  }

  action set_docu_list_map
  {
    tmp_string.assign(tmp_p, p-tmp_p);
    if(tmp_string == "fields")
      clistmap_ = &field_docu_;
  }

  action add_block_line
  {
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      string :: size_type found = tmp_string.find_first_not_of(" \t");
      if(found == string::npos || string(tmp_string.substr(found)) != "\"\"")
      {
        found = tmp_string.rfind("\"");
        if(found != string::npos && string(tmp_string.substr(found-1)) == "\"\"")
        {
          //cerr << "a1: " << tmp_string.substr(0, found-1) + '\n';
          (*cblock_).push_back(tmp_string.substr(0, found-1) + '\n');
          //cerr << "after a1: " << param_list_["detailed_data"][0];
        }
        else
        {
          //cerr << "a2: " << tmp_string + '\n';
          (*cblock_).push_back(tmp_string + '\n');
        }
      }
      opt = true;
    }
  }

  action set_block_from_list
  {
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }

  action set_block_from_listmap
  {
    string s(tmp_p, p-tmp_p);
    cblock_ = &((*clistmap_)[tmp_string][s]);
  }

  action reg_glob
  {
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }

  EOF = 0;

  EOL = '\r'? . '\n';

  default = ^0;

  IDENT = [A-Z]+;

  MIDENT = [A-Za-z][A-Za-z0-9_]*;

  GLOB = (default - [\n \t;\{])+;

  garbling := (default - '\n')* . EOL @{line++;fret;};

  add_param_docu_block = ('brief'|'doc'|'extra');
  add_param_docu_list = ('params'|'return');
  add_param_docu_list_map = ('fields');

  MWSOC = (
           [ \t]
           | EOL @{line++;}
           | (('#'. any) -'##') @{ /*cerr << "l: " << line << "\n";*/ fhold;fcall garbling; }
          );
#  MWSOC = ( [ \t\n]);

  EQ = ('+'? @{arg_to_be_added_ = true;} . '=');

  ENDRULE = ';' @{arg_to_be_added_ = false;};

  docu_block_line :=
    (
     ( ( default - ["\n] )+ >{ if(opt) { tmp_p = p; } } )
     |
     EOL @(add_block_line) @{line++;}
     |
     '"""' @(add_block_line) @{fret;}
     |
     ('"'{1,2} . (default - ["\n])) @{ fhold; opt=false; }
    )**;

  docu_block = ('"""'
                @{
                opt=true;
                if(!arg_to_be_added_)
                  (*cblock_).clear();
                fcall docu_block_line;
                }
               );

  docu_list_item =
    (
     ( MIDENT
         >{tmp_p = p;}
         %(set_block_from_list)
     ) . MWSOC*
     . '=>' . MWSOC* . docu_block
    );

  docu_list = (
    (
     '('
     . ( MWSOC* . docu_list_item . MWSOC* . ',')*
     . MWSOC* . docu_list_item . MWSOC* . ')'
    )
    |
    docu_list_item
  );

  docu_list_map_item =
    (
     (MIDENT
       >{tmp_p = p;/* cerr << "dlmi\n";*/} %(string_tok)
     )
     . '.'
     .(MIDENT
       >{tmp_p = p;/* cerr << "dlmi2\n";*/} %(set_block_from_listmap)
      )
     . MWSOC*
     . '=>' . MWSOC* . docu_block
    );

  docu_list_map = (
    (
     '('
     . ( MWSOC* . docu_list_map_item . MWSOC* . ',')*
     . MWSOC* . docu_list_map_item . MWSOC* . ')'
    )
    |
    docu_list_map_item
  );

  globlist =
    (GLOB >{/*cerr << "glob_list";*/ tmp_p = p;} %(reg_glob))
    . (MWSOC* . [ \t]+ . MWSOC*
        . (GLOB >{/*cerr << "glob list2";*/ tmp_p = p;} %(reg_glob)))*;

  grouplist = (
    ((MIDENT >(st_tok)
             %(group_add))
     . ',')*
    .(MIDENT >(st_tok)
      %(group_add))
    );

  rules := (
    # glob list
    ('glob' .MWSOC* . '=' . MWSOC* . globlist . MWSOC* . '{')
      @{ check_glob_level_up(); fcall rules; }
    |
    (MWSOC)
    |
    # groups rule
    ('groups'. MWSOC* . EQ
     . MWSOC* . grouplist . MWSOC* . ENDRULE)
    |
    # add rule
    ('add(' %{/*cerr << "add:" << '\n';*/ tmp_p = p;}
     . (
        ((add_param_docu_block
            %(set_docu_block)
         )
         . ')' . MWSOC* . EQ
         . MWSOC* . docu_block . MWSOC* . ENDRULE )
        |
        ((add_param_docu_list
            %(set_docu_list)
         )
         . ')' . MWSOC* . EQ
         . MWSOC* :> docu_list . MWSOC* . ENDRULE )
        |
        ((add_param_docu_list_map
            %(set_docu_list_map)
         )
         . ')' . MWSOC* . EQ
         . MWSOC* :> docu_list_map . MWSOC* ENDRULE )
       )
    )
    |
    # go level down
    ('}') @{ go_level_down(); fret; }
    )*;

  main := (
           MWSOC
           | (
              (IDENT
                 >(st_tok)
                 %(string_tok)
              ). MWSOC* . ':=' . MWSOC*
              . (GLOB >st_tok @{/*TODO*/})
              . (MWSOC* . (GLOB >st_tok @{/*TODO*/}))*
              . MWSOC*
              . ';'
             )
           |
           '##' . [ \t]* . EOL @{ line++; /*cerr<<"-> rules\n";*/ fgoto rules; }
          )**;
}%%

void ConfFileScanner :: go_level_down()
{
  globlist_stack_.pop_back();
  globlist_stack_.back().clear();
  level_--;
}

bool ConfFileScanner :: check_for_match(int l, const char * str,
                                        bool match_path_sep)
{
  typedef GlobList :: iterator iterator;
  GlobList & gl = globlist_stack_[l];
  /*  cerr << "globlist at level" << l << "\n  ";
  for(unsigned int i = 0; i < gl.size(); ++i)
  {
    cerr << gl[i] << " ";
  }
  cerr << endl;*/
  iterator endit = gl.end();
  int flags = (match_path_sep? FNM_PATHNAME : 0);
  // cerr << "checking for match at level " << l <<" of string " << str << ":" << endl;
  for( iterator it = gl.begin(); it != endit; it++ )
  {
    // cerr << "with pattern: " << (*it).c_str() << endl;
    if(fnmatch((*it).c_str(), str, flags) == 0)
    {
      // cerr << "SUCCESS!" << endl;
      return true;
    }
  }
  return false;
}

bool ConfFileScanner :: check_glob_rec(int l, const string & s)
{
  string str;
  string :: size_type found;
  if(l == level_+1)
    return true;
/*  if(l == level_)
  {*/
    /* true if all leading directories in path or the whole path string are
     * matched by pattern
     */
/*    found = s.rfind("/");
    if(found != string::npos)
    {
      str = s.substr(0, found);
      if(check_for_match(l, str.c_str()))
        return true;
    }
    // else: try to match complete string
    return check_for_match(l, s.c_str());
  }*/

  found = s.find("/"); // try to match dir in path
  while(found != string :: npos)
  {
    str = s.substr(0, found);
//    cerr << str << endl;
    if(check_for_match(l, str.c_str())
        && check_glob_rec(l+1, s.substr(found+1)))
      return true;

    found = s.find("/", found+1); // try to match more dirs
  }
  if(l == level_) // try also to match the entire string
  {
    if(check_for_match(l, s.c_str()))
      return true;
  }

  return false;
}

void ConfFileScanner :: check_glob_level_up()
{
  match_at_level_[level_+1] = check_glob_rec(0, filename_);
/*  cerr << "going one level up, match at this level is: "
       << (match_at_level_[level_+1] ? "true" : "false");
  cerr << endl;*/

  globlist_stack_.push_back(GlobList());
  level_++;
}

ConfFileScanner
:: ConfFileScanner(const std::string & filename)
 : line(1), have(0), top(0), opt(true),
   filename_(filename),
   confistream_(set_conffile()),
   level_(0),
   arg_to_be_added_(false)
{
  globlist_stack_.push_back(GlobList());
  match_at_level_[0] = true;
}

const char * ConfFileScanner ::
set_conffile()
{
  conffile_ = "doxygen/mtoc.conf";
  return conffile_.c_str();
}

int ConfFileScanner :: execute()
{
  //cerr << "execute\n";
  std::ios::sync_with_stdio(false);

  %% write init;

  /* Do the first read. */
  bool done = false;
  while ( !done )
  {
    char *p = buf + have;
    char *tmp_p = p;// *tmp_p2 = p;
    string tmp_string;
    int space = BUFSIZE - have;

    if ( space == 0 )
    {
      /* We filled up the buffer trying to scan a token. */
      cerr << "OUT OF BUFFER SPACE" << endl;
      exit(1);
    }

    confistream_.read( p, space );
    int len = confistream_.gcount();
    char *pe = p + len;
    char *rpe = pe;
    char *eof = 0;

    /* If we see eof then append the EOF char. */
    if ( confistream_.eof() )
    {
      eof = pe;
      done = true;
    }
    else
    {
      /* Find the last semicolon by searching backwards. This
       * is where we will stop processing on this iteration. */
      while ( *pe!= ';' && pe > p )
        pe--;
    }

    %% write exec;

    /* Check if we failed. */
    if ( cs == ConfFileScanner_error )
    {
      /* Machine failed before finding a token. */
      cerr << "in conffile: PARSE ERROR in line " << line << endl;
      exit(1);
    }

    have = rpe - pe;
    /* cerr << "memmove by " << have << "bytes\n";*/
    memmove( buf, pe, have );
  }

  return 0;
}
/* vim: set et sw=2 ft=ragel: */
