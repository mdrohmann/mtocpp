
#include <string>
#include <fstream>
#include <iostream>

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

  EOF = 0;

  default = ^0;

  EOL = ('\r'? . '\n') @{line++;};

  IDENT = [A-Z\\a-z\-_][A-Z\\a-z0-9\-_]*;

  IDENT_WO_US = [A-Z\\a-z\-][A-Z\\a-z0-9\-]*;

  action echo {
    fout << fpc;
    cout << fpc;
  }

  action st_tok { tmp_p = p; }

  action echo_tok { fout.write(tmp_p, p - tmp_p); cout.write(tmp_p, p-tmp_p); }

  retvals:= |*
    (IDENT) => { fout.write(ts, te - ts); };

    '::retssubstituteend' => { fout << "] ="; fgoto main; };

    '::retsubstituteend' => { fout << " ="; fgoto main; };

    '::' => { fout <<", "; };
  *|;

  mtocsubst:= |*
    '_';

    (IDENT_WO_US);

    '_tsbus_cotm' => { fgoto main; };
  *|;

  main:= |*
   ('rets::substitutestart::') => { fout << "function ["; fgoto retvals; };

   ('ret::substitutestart::') => { fout << "function "; fgoto retvals; };

   ('noret::substitute') => {fout << "function ";};

   ('mtoc_subst_') => { fgoto mtocsubst; };

   ('matlabtypesubstitute') => {fout << " ";};

   (any - [\n <>()[\]{}\&:;_\t])+ => { fout.write(ts, te-ts); };

   ([\n <>()[\]{}\t:;_\&]) => {fout << *ts;};
   *|;
}%%

class PostProcess
{

public:
  PostProcess(const string & filename) :
    filename_(filename),
    line(1),
    ts(0), te(0), have(0)
  { }

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
      cerr << "PARSE ERROR in line " << line << endl;
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

int main(int argc, char ** argv)
{
  string filename;
  if(argc >= 2)
  {
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

