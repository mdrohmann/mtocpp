#ifndef MFILESCANNER_H_

#define MFILESCANNER_H_

#include "confscanner.h"
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>

// 160 KB
#define BUFSIZE 10*16384

class MFileScanner
{
public:
  typedef std :: vector< std :: string >                             DocuBlock;
  typedef std :: map< std :: string, DocuBlock >                     DocuList;
  typedef std :: map< std :: string, DocuList >                      DocuListMap;
  typedef std :: set< std :: string >                                GroupSet;

public:
  MFileScanner (std::istream & fin, const std::string & filename, bool latex_output);

  int execute();

  void end_function();

private:
  const std::string & replace_underscore(std::string & s);

  const std::string & escape_chars(std::string & s);

  void write_docu_block(const DocuBlock & block);

  void write_docu_list(const DocuList & list,
                       const std::string & item_text,
                       const DocuList & alternative,
                       const std::string separator);

  void write_docu_listmap(const DocuListMap & listmap,
                          const std::string & text,
                          const DocuListMap & altlistmap);


private:
  std::istream & fin_;
  const std::string  filename_;
  bool latex_output_;
  ConfFileScanner cscan_;
  char         buf[BUFSIZE];
  int          line            , col;
  char        *ts              , *te;
  int          act             , have;
  int          cs;
  int          top;
  int          stack[5];
  bool         opt;
  bool         new_syntax_;
  DocuListMap  required_list_;
  DocuListMap  optional_list_;
  DocuListMap  retval_list_;
  DocuList     param_list_;
  DocuList     return_list_;
  DocuBlock    returnlist_;
  DocuList    *clist_;
  DocuBlock    docuheader_;
  DocuBlock    docubody_;
  DocuBlock    docuextra_;
  DocuBlock    paramlist_;
  std::string  cfuncname_;
  GroupSet     groupset_;
  bool         is_script_;
  bool         is_first_function_;
};

/* vim: set et sw=2: */
#endif /* MFILESCANNER_H_ */

