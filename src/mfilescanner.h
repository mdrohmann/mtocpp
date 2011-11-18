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
  copy_typified_field_docu(COPY_TYPIFIED_FIELD_DOCU),
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
  bool copy_typified_field_docu;
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
class ordered_map : public std::vector<std::pair<std::string, ST> >
{
public:

  typedef std :: pair< std :: string, ST >                           item;
  typedef std :: vector< item >                                      base_type;
  typedef typename base_type :: iterator                             iterator;
  typedef typename base_type :: const_iterator                       const_iterator;

public:

  ordered_map() : base_type()
  {};

  ST & operator[](const std::string & key)
  {
    iterator it = this->find(key);
    if (it == this->end())
    {
      this->push_back(make_pair(key, ST()));
      it = this->end() - 1;
    }
    return it->second;
  }

  iterator find(const std::string & key)
  {
    iterator it = this->begin();
    for (; it != this->end(); ++it)
    {
      if (it->first == key)
        break;
    }
    return it;
  }
};

/**
 * @class MFileScanner
 *
 * @change{1,2,md,2011-11-17}
 * - Fixed a bug that messed up the documentation if a new line was started after a @@type tag and added a test case to classA.m
 * - Non-standard access modifier strings are now separated by a comma
 * - Fixed a parse error occuring with the new ~-notation in newer MatLab versions. Calls like <tt>foo = bar(par1, ~, par3)</tt> now work.
 * - The order of @@default and @@type tags in parameters (if occurring) is no longer fixed.
 *
 * @new{1,2,md,2011-11-17} New config flag COPY_TYPIFIED_FIELD_DOCU which allows to toggle the automatic insertion of required fields for method parameters.
 * This flag sets whether the documentation of fields in 'Required fields of param', 'Optional fields of param' or 'Generated fields of retval' shall be copied
 * in case the Parameter 'param' or 'retval' have a type.
 */
class MFileScanner
{
public:
  typedef std :: vector< std :: string >                             DocuBlock;
  typedef ordered_map< DocuBlock >                                   DocuList;
  typedef ordered_map< DocuList >                                    DocuListMap;
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
  void get_default(const std::string &, std::string &);
  void extract_typen(DocuBlock & db, std::string & typen, bool remove = false);
  void extract_default(DocuBlock &, std::string &);
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

  void postprocess_unused_params(std::string &, DocuList & );

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
/*  AltDocuList  param_defaults_;*/
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

