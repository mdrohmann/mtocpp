#ifndef MFILESCANNER_H_

#define MFILESCANNER_H_

#include "confscanner.h"
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <sstream>
#include <fstream>

// 160 KB
#define BUFSIZE 10*16384

typedef enum
{
  Public, Protected, Private
} AccessEnum;

typedef enum
{
  Header,
  Method,
  AtMethod,
  MethodDeclaration,
  Property,
  Event
} ClassPart;

struct AccessStruct
{
  AccessEnum full;
  AccessEnum get;
  AccessEnum set;

public:
  AccessStruct()
    : full(Public), get(Public), set(Public) {};
};

struct PropParams
{
  bool constant;

  std::string ccprefix()
  {
    if(constant)
      return "static const matlabtypesubstitute";
    else
      return "matlabtypesubstitute";
  }

public:
  PropParams()
    : constant(false) {};
};

struct MethodParams
{
  bool abstr;
  bool statical;

  std::string ccprefix()
  {
    if(statical)
      return "static ";
    else
      return "";
  }
  std::string ccpostfix()
  {
    if(abstr)
      return " = 0;";
    else
      return " {";
  }

public:
  MethodParams()
    : abstr(false), statical(false) {};
};

class MFileScanner
{
public:
  typedef std :: vector< std :: string >                             DocuBlock;
  typedef std :: map< std :: string, DocuBlock >                     DocuList;
  typedef std :: map< std :: string, DocuList >                      DocuListMap;
  typedef std :: set< std :: string >                                GroupSet;

public:
  MFileScanner (std::istream & fin, const std::string & filename, const
                std::string & conffilename, bool latex_output);

  int execute();

  void end_function();

private:
  void end_of_class_doc();
  void print_access_specifier(AccessEnum & access);
  void print_function_synopsis();
  void end_of_property_doc();

  void clear_lists();
  std::string namespace_string();

  void cout_ingroup();
  void cout_docuheader();
  void cout_docubody();
  void cout_docuextra();
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
  std::string  fnname_;
  std::list<std::string> namespaces_;
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
  bool         is_class_;
  bool         is_setter_;
  bool         is_getter_;
  std::string  classname_;
  std::string::size_type funcindent_;
  std::string::size_type eventindent_;
  ClassPart    class_part_;
  AccessStruct access_;
  PropParams   propertyparams_;
  MethodParams methodparams_;
  std::vector<std::string> property_list_;

};

/* vim: set et sw=2: */
#endif /* MFILESCANNER_H_ */

