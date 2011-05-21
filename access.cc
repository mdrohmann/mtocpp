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

// main routine
int main(int argc, char ** argv)
{
  istream * fcin;
  std::ifstream fin;
  string filename;
  if(argc >= 2)
  {
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

  std::string methodname;
  if(argc == 3)
  {
    methodname = std::string(argv[2]);
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
  runMode.mode = RunMode::ParseMethodParams;
  runMode.latex_output = latex_output;
  runMode.methodname = methodname;
  MFileScanner scanner(*fcin, cout, filename, "conf", runMode);
  scanner.execute();
  MethodParams mp = scanner.getMethodParams();
  std::cout << "abstract" << mp.abstr << "statical: " << mp.statical << std::endl;
  return 0;
}
