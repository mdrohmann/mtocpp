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

void usage()
{
  cout
    << "Usage: mtoc mfile [latex_output] [conf]\n"
    << "       mtoc --help\n\n"
    << "mtoc parses a Matlab m-file 'mfile'.\n"
    << "If 'latex_output' is set to 1, the output is optimized for latex output.\n"
    << "The default is 0.\n"
    << "A configuration file needs to be given or it must exist in\n"
    << "'./doxygen/mtoc.conf'." << endl;
}

// main routine
int main(int argc, char ** argv)
{
  istream * fcin;
  std::ifstream fin;
  string filename;
  if(argc >= 2)
  {
    if (string(argv[1]) == string("--help"))
    {
      usage();
      exit(0);
    }
    std::ios_base::iostate oldstate = fin.exceptions();
    fin.exceptions ( ifstream::failbit );
    try
    {
      fin.open(argv[1]);
      fcin = &fin;
      filename = argv[1];
    }
    catch (std::ifstream::failure e)
    {
      cout << "Exception opening/reading file";
      usage();
      exit(-1);
    }
    fin.exceptions(oldstate);
  }
  else
  {
    fcin = &cin;
    filename = "stdin";
  }

  bool latex_output = false;
  if(argc == 3)
  {
    latex_output = (strncmp(argv[2],"1",1)==0) ? true : false;
  }

  std::string conffilename;
  if(argc == 4)
  {
    conffilename = std::string(argv[3]);
  }

  char buf[1000];
  char * dummy = getcwd(buf, 1000);
  dummy = 0;

  string::size_type found = 0;
  string cwd(buf);
  found = filename.find(cwd);
  if(found!=string::npos)
  {
    filename = filename.substr(cwd.size()+1);
  }
  RunMode runMode;
  runMode.latex_output = latex_output;
  MFileScanner scanner(*fcin, cout, filename, conffilename, runMode);
  scanner.execute();
  return 0;
}

/* vim: set et sw=2 ft=ragel foldmethod=marker: */

