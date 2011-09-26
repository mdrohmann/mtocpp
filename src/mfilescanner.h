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
  RunMode() : mode(Normal), methodname(),
  /* configuration defaults */
  latex_output(false),
  print_fields(PRINT_FIELDS),
  auto_add_fields(AUTO_ADD_FIELDS),
  auto_add_params(AUTO_ADD_PARAMETERS),
  auto_add_class_properties(AUTO_ADD_CLASS_PROPERTIES),
  auto_add_class(AUTO_ADD_CLASSES),
  remove_first_arg_in_abstract_methods(REMOVE_FIRST_ARG_IN_ABSTRACT_METHODS),
  parse_of_type(ENABLE_OF_TYPE_PARSING),
  void_type_in_return_values(VOID_TYPE_IN_RETURN_VALUES),
  print_return_value_name(PRINT_RETURN_VALUE_NAME)
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
  bool auto_add_class_properties;
  bool auto_add_class;
  bool remove_first_arg_in_abstract_methods;
  bool parse_of_type;
  bool void_type_in_return_values;
  int print_return_value_name;
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
  bool transient;
  bool dependent;
  bool hidden;
  bool setObservable;
  bool abstr;

  std::string ccprefix()
  {
    if(constant)
      return "static const ";
    else
      return "";
  }

public:
  PropParams()
    : constant(false),
      transient(false),
      dependent(false),
      hidden(false),
      setObservable(false),
      abstr(false) {};

  friend std::ostream & operator<<(std::ostream & os, PropParams & pp);
};

struct MethodParams
{
  bool abstr;
  bool statical;
  bool hidden;
  bool sealed;

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
    : abstr(false),
      statical(false),
      hidden(false),
      sealed(false) {};

  friend std::ostream & operator<<(std::ostream & os, MethodParams & mp);
};

template <class ST>
typename std::vector<std::pair<std::string, ST> >::iterator
  key_find(std::vector<std::pair<std::string, ST> > unsorted_map,
           const std::string & key)
{
  typedef typename std :: vector< std :: pair< std :: string, ST > >
            :: iterator                                              iterator;

  iterator it = unsorted_map.begin();
  for(; it!= unsorted_map.end(); ++it)
  {
    if ((*it).first == key)
      break;
  }
  return it;
}

class MFileScanner
{
public:
  typedef std :: vector< std :: string >                             DocuBlock;
  typedef std :: vector< std :: pair< std :: string, DocuBlock > >   DocuList;
  typedef std :: vector< std :: pair< std :: string, DocuList > >    DocuListMap;
  typedef std :: map< std :: string, DocuBlock >                     AltDocuList;
  typedef std :: map< std :: string, AltDocuList >                   AltDocuListMap;
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
  void add_access_info(std::string);
  void add_property_params_info();
  void add_method_params_info();
  void end_of_class_doc();
  std::string access_specifier_string(AccessEnum & access);
  void print_access_specifier(AccessEnum & access);
  void print_pure_function_synopsis();
  void print_function_synopsis();
  void end_of_property_doc();
  void get_typename(const std::string &, std::string &, std::string voidtype = std::string("matlabtypesubstitute"));
  void extract_typen(DocuBlock & db, std::string & typen, bool remove = false);
  void update_method_params(const std::string & methodname);

  void end_method();
  void clear_lists();
  std::string namespace_string();

  void cout_ingroup();
  void cout_docuheader(std::string, bool clear = true);
  void cout_docubody();
  void cout_docuextra();
  const std::string & replace_underscore(std::string & s);

  const std::string & escape_chars(std::string & s);

  void write_docu_block(const DocuBlock & block);

  void write_docu_list(const DocuList & list,
                       const std::string & item_text,
                       const AltDocuList & alternative,
                       bool,
                       const std::string separator,
                       const std::string docu_list_name);

  void write_docu_listmap(const DocuListMap & listmap,
                          const std::string & text,
                          const AltDocuListMap & altlistmap);


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

