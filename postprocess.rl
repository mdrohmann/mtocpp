
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

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

  action echo {
    fout << fpc;
    cout << fpc;
  }

  action st_tok { tmp_p = p; }

  action echo_tok { fout.write(tmp_p, p - tmp_p); cout.write(tmp_p, p-tmp_p); }

  # reconstruct return values
  retvals:= |*
    # matlab identifier (1 return value)
    (IDENT) => { fout.write(ts, te - ts); };

    # end list of return values
    '::retssubstituteend' => { fout << "] ="; fgoto main; };

    # end of return value
    '::retsubstituteend' => { fout << " ="; fgoto main; };

    # return value separator
    '::' => { fout <<", "; };
  *|;

  # function name
  mtocsubst:= |*
    '_';

    (IDENT_WO_US);

    '_tsbus_cotm' => { fgoto main; };
  *|;

  main:= |*
   # list of return values
   ('rets::substitutestart::') => { fout << "function ["; fgoto retvals; };

   # one return value
   ('ret::substitutestart::') => { fout << "function "; fgoto retvals; };

   # no return values
   ('noret::substitute') => {fout << "function ";};

   # function name
   ('mtoc_subst_') => { fgoto mtocsubst; };

   # matlab is typeless, so discard the type
   ('matlabtypesubstitute') => {fout << " ";};

   # a word
   (any - [\n <>()[\]{}\&:;_\t])+ => { fout.write(ts, te-ts); };

   # word separators
   ([\n <>()[\]{}\t:;_\&]) => {fout << *ts;};
   *|;
}%%

class PostProcess
{

public:
  // constructor
  PostProcess(const string & filename) :
    filename_(filename),
    line(1),
    ts(0), te(0), have(0)
  { }

  // run postprocessor
  int execute()
  {
    std::ios::sync_with_stdio(false);

    %% write init;

    ifstream is;
    try
    {
      is.open(filename_.c_str());
    }
    catch (std::ifstream::failure e)
    {
      cerr << "Exception opening/reading file";
      exit(-1);
    }

    is.seekg(0, ios_base::end);
    int length = is.tellg();
    is.seekg(0, ios_base::beg);

    char * buf = new char[(int)(1.1*length)];
    char * p = buf;
//    char * tmp_p = p;

    is.read(buf, length);
    is.close();

    ofstream fout;
    try
    {
      fout.open(filename_.c_str(), ios_base::trunc);
    }
    catch (std::ofstream::failure e)
    {
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
      cerr << filename_ << ": PARSE ERROR in line " << line << endl;
      exit(-1);
    }

    fout.close();
    delete buf;

    return 0;
  }

private:
  string filename_;
  int          line            , col;
  char        *ts              , *te;
  int          act             , have;
  int          cs;
  /*int          top;
  int          stack[5];*/

};

void usage()
{
  cout
    << "Usage: ./postprocess filename" << endl;
}

int main(int argc, char ** argv)
{
  string filename;
  if(argc >= 2)
  {
    if (std::string("--help") == std::string(argv[1]))
    {
      usage();
    }
    filename = argv[1];
  }
  else
  {
    cerr << "wrong number of arguments!" << endl;
    exit(-2);
  }

  PostProcess scanner(filename);
  scanner.execute();
  return 0;
}

/* vim: set et sw=2 ft=ragel: */

