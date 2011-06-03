#ifndef MFILESCANNER_H_
#define MFILESCANNER_H_

#include "config.h"

#include "confscanner.h"
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <sstream>
#include <fstream>

// 160 KB
#define BUFSIZE 100*16384

#define stringify( name ) #name


struct RunMode
{
  RunMode() : mode(Normal), methodname(), latex_output(false),
  print_fields(true), auto_add_fields(true),
  auto_add_params(true), auto_add_members(true),
  auto_add_class(true)
  {}

  typedef enum
  {
    Normal = 0,
    ParseParams,
    ParseMethodParams
  } Mode;

  Mode mode;
  std::string methodname;
  bool latex_output;
  bool print_fields;
  bool auto_add_fields;
  bool auto_add_params;
  bool auto_add_members;
  bool auto_add_class;
};

typedef enum
{
  Public = 0, Protected, Private
} AccessEnum;


/*extern const char * AccessEnumNames[];*/

typedef enum
{
  InClassComment,
  Header,
  Method,
  AtMethod,
  MethodDeclaration,
  Property,
  Event
} ClassPart;

/*extern const char * ClassPartNames[];*/

struct AccessStruct
{
  AccessEnum full;
  AccessEnum get;
  AccessEnum set;

public:
  AccessStruct()
    : full(Public), get(Public), set(Public) {};

  friend std::ostream & operator<<(std::ostream & os, AccessStruct & as);
};



struct PropParams
{
  bool constant;

  std::string ccprefix()
  {
    if(constant)
      return "static const ";
    else
      return "";
  }

public:
  PropParams()
    : constant(false) {};

  friend std::ostream & operator<<(std::ostream & os, PropParams & pp);
};

struct MethodParams
{
  bool abstr;
  bool statical;

  std::string ccprefix()
  {
    if(statical)
      return "static ";
    else if(abstr)
      return "virtual ";
    else
      return "";
  }
  std::string ccpostfix()
  {
    if(abstr)
      return " = 0;";
    else
      return ";";
  }

public:
  MethodParams()
    : abstr(false), statical(false) {};

  friend std::ostream & operator<<(std::ostream & os, MethodParams & mp);
};

class MFileScanner
{
public:
  typedef std :: vector< std :: string >                             DocuBlock;
  typedef std :: map< std :: string, DocuBlock >                     DocuList;
  typedef std :: map< std :: string, DocuList >                      DocuListMap;
  typedef std :: set< std :: string >                                GroupSet;

public:
  MFileScanner (std::istream & fin, std::ostream & fout,
                const std::string & filename,
                const std::string & conffilename,
                RunMode runmode);

  virtual ~MFileScanner()
  {
    delete buf;
  }

  int execute();

  DocuList & getParamList()
  {
    return param_list_;
  }

  MethodParams & getMethodParams()
  {
    return methodparams_;
  }

  void end_function();


private:
  void end_of_class_doc();
  void print_access_specifier(AccessEnum & access);
  void print_pure_function_synopsis();
  void print_function_synopsis();
  void end_of_property_doc();
  void get_typename(const std::string &, std::string &);
  void extract_typen(std::string & line, std::string & typen);
  void update_method_params(const std::string & methodname);

  void end_method();
  void clear_lists();
  std::string namespace_string();

  void cout_ingroup();
  void cout_docuheader(std::string);
  void cout_docubody();
  void cout_docuextra();
  const std::string & replace_underscore(std::string & s);

  const std::string & escape_chars(std::string & s);

  void write_docu_block(const DocuBlock & block);

  void write_docu_list(const DocuList & list,
                       const std::string & item_text,
                       const DocuList & alternative,
                       bool,
                       const std::string separator,
                       const std::string docu_list_name);

  void write_docu_listmap(const DocuListMap & listmap,
                          const std::string & text,
                          const DocuListMap & altlistmap);


  void debug_output(const std::string & msg, char * p);

private:
  std::istream & fin_;
  std::ostream & fout_;
  const std::string  filename_;
  ConfFileScanner cscan_;
  std::string  fnname_;
  std::list<std::string> namespaces_;
  char         *buf;
  int          line            , col;
  char        *ts              , *te;
  int          act             , have;
  int          cs;
  int          top;
  int          stack[10];
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
  RunMode      runMode_;
  std::string  defaultprop_;
  std::string  dirname_;

  std::map<std::string,std::string> param_type_map_;
};

/* vim: set et sw=2: */
#endif /* MFILESCANNER_H_ */

