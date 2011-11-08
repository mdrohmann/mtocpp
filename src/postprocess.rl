#include "config.h"

#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <dirent.h> // New for directory recursion

using std::cin;
using std::cout;
using std::cerr;
using std::ifstream;
using std::ofstream;
using std::string;
using std::ios_base;
using std::endl;

%%{
  machine PostProcess;
  write data;

  # end of file character
  EOF = 0;

  # all but end of file character
  default = ^0;

  # end of line
  EOL = ('\r'? . '\n') @{line++;};

  # matlab identifier
  IDENT = [A-Z\\a-z\-_][A-Z\\a-z0-9\-_]*;

  # matlab ifdentifier without underscore characters
  IDENT_WO_US = [A-Z\\a-z\-][A-Z\\a-z0-9\-]*;

  ANY_TAG = '<' . [^>]* . '>';

  action echo {
    fout << fpc;
    cout << fpc;
  }

  action st_tok { tmp_p = p; }

  action echo_tok { fout.write(tmp_p, p - tmp_p); cout.write(tmp_p, p-tmp_p); }

  rettype:= |*

    # matlab is typeless, so discard the type
    ('matlabtypesubstitute') => {fout << " ";};

    # replace all "::" by "."
    ('::' . [A-Z\\a-z\-_]) => { fout << '.' << *(te-1); };

    # a word
    (any - [\n <>\&:,\t])+ => { fout.write(ts, te-ts); };

    # word separators
    ([\n <>\&:\t]) => {fout << *ts;};

    # comma or &gt; end the type
    (',') => { fhold; fret; };
    ('&gt;') => { p -=4; fret; };
  *|;

  # reconstruct return values
  retval:= |*
    ('&lt;' . ('::')?) => { fcall rettype; };

    # matlab identifier (1 return value)
#    ('&lt;' . (default - [,&])*) => { cerr.write(ts+4, te - ts-4); cerr << std::endl; fout.write(ts+4, te - ts-4); };

    (',' . (default - '\&')*) => { fout << " <span class=\"paramname\">"; fout.write(ts+1, te-ts-1); fout << "</span>"; };

    # end of return value
    ('&gt;') => {
                  if(only_retval) { fout << " ="; }
                  fret;
                };

    # white spaces
    ([ \t\n]*) => { fout.write(ts, te - ts); };

    # typebreak
    ('<br class="typebreak"/>') => {};

    # other tags
    #(ANY_TAG) => { fout.write(ts, te-ts); };

  *|;

  retvals := |*

    ('&lt;') => {};

    ('mlhsInnerSubst') => { fcall retval; };

    ('&gt;') => { fout << "] ="; fgoto main; };

    # white spaces and commata
    ([ \t\n]*) => { fout.write(ts, te - ts); };
    ('<br class="typebreak"/>' . [ \t\n]* . ',') => { fout << ",<br class=\"typebreak\"/>\n"; };
    (',') => { fout << ", "; };

    # other tags
    (ANY_TAG) => { fout.write(ts, te-ts); };

  *|;

  # function name
  mtocsubst:= |*
    '_';

    (IDENT_WO_US);

    '_tsbus_cotm' => { fgoto main; };
  *|;

  main:= |*
   # list of return values
   ('mlhsSubst') => { fout << "function ["; only_retval = false; fgoto retvals; };

   # one return value
   ('mlhsInnerSubst') => { fout << "function "; only_retval = true; fcall retval; fout << " ="; };

   # no return values
   ('noret::substitute') => {fout << "function ";};

   # function name
   ('mtoc_subst_') => { fgoto mtocsubst; };

   # matlab is typeless, so discard the type
   ('matlabtypesubstitute') => {fout << " ";};

   # remove leading "::" (global namespace identifier)
   ([(,>] . '::') => { fout.write(ts, 1); fout << " "; };
   ('&lt;' . '::') => { fout.write(ts, 4); fout << " ";};

   # replace all "::" by "."
   ('::' . [A-Z\\a-z\-_]) => { fout << '.' << *(te-1); };

   # a word
   (any - [\n <>()[\]{}\&:,;_\t])+ => { fout.write(ts, te-ts); };

   # word separators
   ([\n <>()[\]{}\t:;,_\&]) => {fout << *ts;};
   *|;
}%%

class PostProcess {

private:
  string docdir_;
  int          line            , col;
  char        *ts              , *te;
  int          act             , have;
  int          cs;
  int          top;
  int          stack[5];
  bool         only_retval;

public:
  /**
   * @class PostProcess
   * 
   * @change{1,2,dw,2011-11-04} Changed the postprocessor interface from taking a single file argument to
   * assuming the passed string to be a folder whos contents are to be postprocessed. 
   */
  // constructor
  PostProcess(const string &docdir) :
    docdir_(docdir),
    line(1),
    ts(0), te(0), have(0),
    top(0), only_retval(false)
  { }
  
  int execute() {
	  DIR *dp;
	  if ((dp  = opendir(docdir_.c_str())) == NULL) {
		  cerr << "Error opening directory " << docdir_ << endl;
		  return -1;
	  }
	  
	  struct dirent* dirp;
	  string file;
	  while ((dirp = readdir(dp)) != NULL) {
		  file = string(dirp->d_name);
		  // Process only html files
		  if (file.substr(file.find_last_of(".") + 1) == "html" && file.find("8rl") == string::npos) {
			  postprocess(docdir_ + string("/") + file);
		  }
	  }
	  closedir(dp);
	  return 0;
  }

  // run postprocessor
  int postprocess(string file)
  {
    std::ios::sync_with_stdio(false);

    %% write init;

    ifstream is;
    try {
      is.open(file.c_str());
    } catch (std::ifstream::failure e) {
      cerr << "Exception opening/reading file";
      exit(-1);
    }

    is.seekg(0, ios_base::end);
    int length = is.tellg();
    is.seekg(0, ios_base::beg);

    char* buf = new char[(int)(1.1*length)];
    char* p = buf;
//    char * tmp_p = p;

    is.read(buf, length);
    is.close();
    
    ofstream fout;
    try {
      fout.open(file.c_str(), ios_base::trunc);
    } catch (std::ofstream::failure e) {
      cerr << "Exception opening/writing file";
      exit(-1);
    }

    int len = is.gcount();
    char *pe = p + len;
    char *eof = pe;

    %% write exec;

    /* Check if we failed. */
    if ( cs == PostProcess_error )
    {
      /* Machine failed before finding a token. */
      cerr << file << ": PARSE ERROR in line " << line << endl;
      cerr.write(p, 100);
      exit(-1);
    }

    fout.close();
    delete buf;

    return 0;
  }
};

void usage()
{
  cout << "postprocess Version " << MTOCPP_VERSION_MAJOR << "."
    << MTOCPP_VERSION_MINOR << endl;
  cout << "Usage: ./postprocess filename" << endl;
}

int main(int argc, char ** argv)
{
  string docdir;
  if(argc >= 2)
  {
    if (std::string("--help") == std::string(argv[1]))
    {
      usage();
      return 0;
    }
    docdir = argv[1];
  }
  else
  {
    cerr << "wrong number of arguments!" << endl;
    exit(-2);
  }

  cout << "Running mtoc++ postprocessor on directory " << docdir << endl;
  
  PostProcess scanner(docdir);
  scanner.execute();
  return 0;
}

/* vim: set et sw=2 ft=ragel: */

