
#line 1 "postprocess.rl"

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


#line 20 "postprocess.cc"
static const char _PostProcess_to_state_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 12, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 12, 0, 0, 12, 
	0, 0
};

static const char _PostProcess_from_state_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 13, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 13, 0, 0, 13, 
	0, 0
};

static const int PostProcess_start = 91;
static const int PostProcess_first_final = 91;
static const int PostProcess_error = 0;

static const int PostProcess_en_retvals = 124;
static const int PostProcess_en_mtocsubst = 127;
static const int PostProcess_en_main = 91;


#line 90 "postprocess.rl"


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

    
#line 90 "postprocess.cc"
	{
	cs = PostProcess_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 109 "postprocess.rl"

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

    
#line 138 "postprocess.cc"
	{
	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	switch ( _PostProcess_from_state_actions[cs] ) {
	case 13:
#line 1 "NONE"
	{ts = p;}
	break;
#line 150 "postprocess.cc"
	}

	switch ( cs ) {
case 91:
	switch( (*p) ) {
		case 32: goto tr96;
		case 38: goto tr96;
		case 62: goto tr96;
		case 91: goto tr96;
		case 93: goto tr96;
		case 95: goto tr96;
		case 109: goto tr97;
		case 110: goto tr98;
		case 114: goto tr99;
		case 123: goto tr96;
		case 125: goto tr96;
	}
	if ( (*p) < 40 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr96;
	} else if ( (*p) > 41 ) {
		if ( 58 <= (*p) && (*p) <= 60 )
			goto tr96;
	} else
		goto tr96;
	goto tr95;
case 92:
	switch( (*p) ) {
		case 32: goto tr100;
		case 38: goto tr100;
		case 62: goto tr100;
		case 91: goto tr100;
		case 93: goto tr100;
		case 95: goto tr100;
		case 123: goto tr100;
		case 125: goto tr100;
	}
	if ( (*p) < 40 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr100;
	} else if ( (*p) > 41 ) {
		if ( 58 <= (*p) && (*p) <= 60 )
			goto tr100;
	} else
		goto tr100;
	goto tr95;
case 93:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 97: goto tr102;
		case 116: goto tr103;
		case 123: goto tr101;
		case 125: goto tr101;
	}
	if ( (*p) < 40 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr101;
	} else if ( (*p) > 41 ) {
		if ( 58 <= (*p) && (*p) <= 60 )
			goto tr101;
	} else
		goto tr101;
	goto tr95;
case 94:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 116: goto tr104;
		case 123: goto tr101;
		case 125: goto tr101;
	}
	if ( (*p) < 40 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr101;
	} else if ( (*p) > 41 ) {
		if ( 58 <= (*p) && (*p) <= 60 )
			goto tr101;
	} else
		goto tr101;
	goto tr95;
case 95:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 108: goto tr105;
		case 123: goto tr101;
		case 125: goto tr101;
	}
	if ( (*p) < 40 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr101;
	} else if ( (*p) > 41 ) {
		if ( 58 <= (*p) && (*p) <= 60 )
			goto tr101;
	} else
		goto tr101;
	goto tr95;
case 96:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 97: goto tr106;
		case 123: goto tr101;
		case 125: goto tr101;
	}
	if ( (*p) < 40 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr101;
	} else if ( (*p) > 41 ) {
		if ( 58 <= (*p) && (*p) <= 60 )
			goto tr101;
	} else
		goto tr101;
	goto tr95;
case 97:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 98: goto tr107;
		case 123: goto tr101;
		case 125: goto tr101;
	}
	if ( (*p) < 40 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr101;
	} else if ( (*p) > 41 ) {
		if ( 58 <= (*p) && (*p) <= 60 )
			goto tr101;
	} else
		goto tr101;
	goto tr95;
case 98:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 116: goto tr108;
		case 123: goto tr101;
		case 125: goto tr101;
	}
	if ( (*p) < 40 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr101;
	} else if ( (*p) > 41 ) {
		if ( 58 <= (*p) && (*p) <= 60 )
			goto tr101;
	} else
		goto tr101;
	goto tr95;
case 99:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 121: goto tr109;
		case 123: goto tr101;
		case 125: goto tr101;
	}
	if ( (*p) < 40 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr101;
	} else if ( (*p) > 41 ) {
		if ( 58 <= (*p) && (*p) <= 60 )
			goto tr101;
	} else
		goto tr101;
	goto tr95;
case 100:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 112: goto tr110;
		case 123: goto tr101;
		case 125: goto tr101;
	}
	if ( (*p) < 40 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr101;
	} else if ( (*p) > 41 ) {
		if ( 58 <= (*p) && (*p) <= 60 )
			goto tr101;
	} else
		goto tr101;
	goto tr95;
case 101:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 101: goto tr111;
		case 123: goto tr101;
		case 125: goto tr101;
	}
	if ( (*p) < 40 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr101;
	} else if ( (*p) > 41 ) {
		if ( 58 <= (*p) && (*p) <= 60 )
			goto tr101;
	} else
		goto tr101;
	goto tr95;
case 102:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 115: goto tr112;
		case 123: goto tr101;
		case 125: goto tr101;
	}
	if ( (*p) < 40 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr101;
	} else if ( (*p) > 41 ) {
		if ( 58 <= (*p) && (*p) <= 60 )
			goto tr101;
	} else
		goto tr101;
	goto tr95;
case 103:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 117: goto tr113;
		case 123: goto tr101;
		case 125: goto tr101;
	}
	if ( (*p) < 40 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr101;
	} else if ( (*p) > 41 ) {
		if ( 58 <= (*p) && (*p) <= 60 )
			goto tr101;
	} else
		goto tr101;
	goto tr95;
case 104:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 98: goto tr114;
		case 123: goto tr101;
		case 125: goto tr101;
	}
	if ( (*p) < 40 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr101;
	} else if ( (*p) > 41 ) {
		if ( 58 <= (*p) && (*p) <= 60 )
			goto tr101;
	} else
		goto tr101;
	goto tr95;
case 105:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 115: goto tr115;
		case 123: goto tr101;
		case 125: goto tr101;
	}
	if ( (*p) < 40 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr101;
	} else if ( (*p) > 41 ) {
		if ( 58 <= (*p) && (*p) <= 60 )
			goto tr101;
	} else
		goto tr101;
	goto tr95;
case 106:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 116: goto tr116;
		case 123: goto tr101;
		case 125: goto tr101;
	}
	if ( (*p) < 40 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr101;
	} else if ( (*p) > 41 ) {
		if ( 58 <= (*p) && (*p) <= 60 )
			goto tr101;
	} else
		goto tr101;
	goto tr95;
case 107:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 105: goto tr117;
		case 123: goto tr101;
		case 125: goto tr101;
	}
	if ( (*p) < 40 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr101;
	} else if ( (*p) > 41 ) {
		if ( 58 <= (*p) && (*p) <= 60 )
			goto tr101;
	} else
		goto tr101;
	goto tr95;
case 108:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 116: goto tr118;
		case 123: goto tr101;
		case 125: goto tr101;
	}
	if ( (*p) < 40 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr101;
	} else if ( (*p) > 41 ) {
		if ( 58 <= (*p) && (*p) <= 60 )
			goto tr101;
	} else
		goto tr101;
	goto tr95;
case 109:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 117: goto tr119;
		case 123: goto tr101;
		case 125: goto tr101;
	}
	if ( (*p) < 40 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr101;
	} else if ( (*p) > 41 ) {
		if ( 58 <= (*p) && (*p) <= 60 )
			goto tr101;
	} else
		goto tr101;
	goto tr95;
case 110:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 116: goto tr120;
		case 123: goto tr101;
		case 125: goto tr101;
	}
	if ( (*p) < 40 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr101;
	} else if ( (*p) > 41 ) {
		if ( 58 <= (*p) && (*p) <= 60 )
			goto tr101;
	} else
		goto tr101;
	goto tr95;
case 111:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 101: goto tr121;
		case 123: goto tr101;
		case 125: goto tr101;
	}
	if ( (*p) < 40 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr101;
	} else if ( (*p) > 41 ) {
		if ( 58 <= (*p) && (*p) <= 60 )
			goto tr101;
	} else
		goto tr101;
	goto tr95;
case 112:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 111: goto tr122;
		case 123: goto tr101;
		case 125: goto tr101;
	}
	if ( (*p) < 40 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr101;
	} else if ( (*p) > 41 ) {
		if ( 58 <= (*p) && (*p) <= 60 )
			goto tr101;
	} else
		goto tr101;
	goto tr95;
case 113:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 99: goto tr123;
		case 123: goto tr101;
		case 125: goto tr101;
	}
	if ( (*p) < 40 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr101;
	} else if ( (*p) > 41 ) {
		if ( 58 <= (*p) && (*p) <= 60 )
			goto tr101;
	} else
		goto tr101;
	goto tr95;
case 114:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr124;
		case 123: goto tr101;
		case 125: goto tr101;
	}
	if ( (*p) < 40 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr101;
	} else if ( (*p) > 41 ) {
		if ( 58 <= (*p) && (*p) <= 60 )
			goto tr101;
	} else
		goto tr101;
	goto tr95;
case 1:
	if ( (*p) == 115 )
		goto tr1;
	goto tr0;
case 2:
	if ( (*p) == 117 )
		goto tr2;
	goto tr0;
case 3:
	if ( (*p) == 98 )
		goto tr3;
	goto tr0;
case 4:
	if ( (*p) == 115 )
		goto tr4;
	goto tr0;
case 5:
	if ( (*p) == 116 )
		goto tr5;
	goto tr0;
case 6:
	if ( (*p) == 95 )
		goto tr6;
	goto tr0;
case 115:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 111: goto tr125;
		case 123: goto tr101;
		case 125: goto tr101;
	}
	if ( (*p) < 40 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr101;
	} else if ( (*p) > 41 ) {
		if ( 58 <= (*p) && (*p) <= 60 )
			goto tr101;
	} else
		goto tr101;
	goto tr95;
case 116:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 114: goto tr126;
		case 123: goto tr101;
		case 125: goto tr101;
	}
	if ( (*p) < 40 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr101;
	} else if ( (*p) > 41 ) {
		if ( 58 <= (*p) && (*p) <= 60 )
			goto tr101;
	} else
		goto tr101;
	goto tr95;
case 117:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 101: goto tr127;
		case 123: goto tr101;
		case 125: goto tr101;
	}
	if ( (*p) < 40 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr101;
	} else if ( (*p) > 41 ) {
		if ( 58 <= (*p) && (*p) <= 60 )
			goto tr101;
	} else
		goto tr101;
	goto tr95;
case 118:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 116: goto tr128;
		case 123: goto tr101;
		case 125: goto tr101;
	}
	if ( (*p) < 40 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr101;
	} else if ( (*p) > 41 ) {
		if ( 58 <= (*p) && (*p) <= 60 )
			goto tr101;
	} else
		goto tr101;
	goto tr95;
case 119:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 58: goto tr129;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 123: goto tr101;
		case 125: goto tr101;
	}
	if ( (*p) < 40 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr101;
	} else if ( (*p) > 41 ) {
		if ( 59 <= (*p) && (*p) <= 60 )
			goto tr101;
	} else
		goto tr101;
	goto tr95;
case 7:
	if ( (*p) == 58 )
		goto tr7;
	goto tr0;
case 8:
	if ( (*p) == 115 )
		goto tr8;
	goto tr0;
case 9:
	if ( (*p) == 117 )
		goto tr9;
	goto tr0;
case 10:
	if ( (*p) == 98 )
		goto tr10;
	goto tr0;
case 11:
	if ( (*p) == 115 )
		goto tr11;
	goto tr0;
case 12:
	if ( (*p) == 116 )
		goto tr12;
	goto tr0;
case 13:
	if ( (*p) == 105 )
		goto tr13;
	goto tr0;
case 14:
	if ( (*p) == 116 )
		goto tr14;
	goto tr0;
case 15:
	if ( (*p) == 117 )
		goto tr15;
	goto tr0;
case 16:
	if ( (*p) == 116 )
		goto tr16;
	goto tr0;
case 17:
	if ( (*p) == 101 )
		goto tr17;
	goto tr0;
case 120:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 101: goto tr130;
		case 123: goto tr101;
		case 125: goto tr101;
	}
	if ( (*p) < 40 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr101;
	} else if ( (*p) > 41 ) {
		if ( 58 <= (*p) && (*p) <= 60 )
			goto tr101;
	} else
		goto tr101;
	goto tr95;
case 121:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 116: goto tr131;
		case 123: goto tr101;
		case 125: goto tr101;
	}
	if ( (*p) < 40 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr101;
	} else if ( (*p) > 41 ) {
		if ( 58 <= (*p) && (*p) <= 60 )
			goto tr101;
	} else
		goto tr101;
	goto tr95;
case 122:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 58: goto tr132;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 115: goto tr133;
		case 123: goto tr101;
		case 125: goto tr101;
	}
	if ( (*p) < 40 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr101;
	} else if ( (*p) > 41 ) {
		if ( 59 <= (*p) && (*p) <= 60 )
			goto tr101;
	} else
		goto tr101;
	goto tr95;
case 18:
	if ( (*p) == 58 )
		goto tr18;
	goto tr0;
case 19:
	if ( (*p) == 115 )
		goto tr19;
	goto tr0;
case 20:
	if ( (*p) == 117 )
		goto tr20;
	goto tr0;
case 21:
	if ( (*p) == 98 )
		goto tr21;
	goto tr0;
case 22:
	if ( (*p) == 115 )
		goto tr22;
	goto tr0;
case 23:
	if ( (*p) == 116 )
		goto tr23;
	goto tr0;
case 24:
	if ( (*p) == 105 )
		goto tr24;
	goto tr0;
case 25:
	if ( (*p) == 116 )
		goto tr25;
	goto tr0;
case 26:
	if ( (*p) == 117 )
		goto tr26;
	goto tr0;
case 27:
	if ( (*p) == 116 )
		goto tr27;
	goto tr0;
case 28:
	if ( (*p) == 101 )
		goto tr28;
	goto tr0;
case 29:
	if ( (*p) == 115 )
		goto tr29;
	goto tr0;
case 30:
	if ( (*p) == 116 )
		goto tr30;
	goto tr0;
case 31:
	if ( (*p) == 97 )
		goto tr31;
	goto tr0;
case 32:
	if ( (*p) == 114 )
		goto tr32;
	goto tr0;
case 33:
	if ( (*p) == 116 )
		goto tr33;
	goto tr0;
case 34:
	if ( (*p) == 58 )
		goto tr34;
	goto tr0;
case 35:
	if ( (*p) == 58 )
		goto tr35;
	goto tr0;
case 123:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 58: goto tr134;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 123: goto tr101;
		case 125: goto tr101;
	}
	if ( (*p) < 40 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr101;
	} else if ( (*p) > 41 ) {
		if ( 59 <= (*p) && (*p) <= 60 )
			goto tr101;
	} else
		goto tr101;
	goto tr95;
case 36:
	if ( (*p) == 58 )
		goto tr36;
	goto tr0;
case 37:
	if ( (*p) == 115 )
		goto tr37;
	goto tr0;
case 38:
	if ( (*p) == 117 )
		goto tr38;
	goto tr0;
case 39:
	if ( (*p) == 98 )
		goto tr39;
	goto tr0;
case 40:
	if ( (*p) == 115 )
		goto tr40;
	goto tr0;
case 41:
	if ( (*p) == 116 )
		goto tr41;
	goto tr0;
case 42:
	if ( (*p) == 105 )
		goto tr42;
	goto tr0;
case 43:
	if ( (*p) == 116 )
		goto tr43;
	goto tr0;
case 44:
	if ( (*p) == 117 )
		goto tr44;
	goto tr0;
case 45:
	if ( (*p) == 116 )
		goto tr45;
	goto tr0;
case 46:
	if ( (*p) == 101 )
		goto tr46;
	goto tr0;
case 47:
	if ( (*p) == 115 )
		goto tr47;
	goto tr0;
case 48:
	if ( (*p) == 116 )
		goto tr48;
	goto tr0;
case 49:
	if ( (*p) == 97 )
		goto tr49;
	goto tr0;
case 50:
	if ( (*p) == 114 )
		goto tr50;
	goto tr0;
case 51:
	if ( (*p) == 116 )
		goto tr51;
	goto tr0;
case 52:
	if ( (*p) == 58 )
		goto tr52;
	goto tr0;
case 53:
	if ( (*p) == 58 )
		goto tr53;
	goto tr0;
case 124:
	switch( (*p) ) {
		case 45: goto tr135;
		case 58: goto tr136;
		case 92: goto tr135;
		case 95: goto tr135;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr135;
	} else if ( (*p) >= 65 )
		goto tr135;
	goto tr55;
case 0:
	goto _out;
case 125:
	switch( (*p) ) {
		case 45: goto tr135;
		case 92: goto tr135;
		case 95: goto tr135;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr135;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr135;
	} else
		goto tr135;
	goto tr137;
case 54:
	if ( (*p) == 58 )
		goto tr54;
	goto tr55;
case 126:
	if ( (*p) == 114 )
		goto tr139;
	goto tr138;
case 55:
	if ( (*p) == 101 )
		goto tr57;
	goto tr56;
case 56:
	if ( (*p) == 116 )
		goto tr58;
	goto tr56;
case 57:
	if ( (*p) == 115 )
		goto tr59;
	goto tr56;
case 58:
	switch( (*p) ) {
		case 115: goto tr60;
		case 117: goto tr61;
	}
	goto tr56;
case 59:
	if ( (*p) == 117 )
		goto tr62;
	goto tr56;
case 60:
	if ( (*p) == 98 )
		goto tr63;
	goto tr56;
case 61:
	if ( (*p) == 115 )
		goto tr64;
	goto tr56;
case 62:
	if ( (*p) == 116 )
		goto tr65;
	goto tr56;
case 63:
	if ( (*p) == 105 )
		goto tr66;
	goto tr56;
case 64:
	if ( (*p) == 116 )
		goto tr67;
	goto tr56;
case 65:
	if ( (*p) == 117 )
		goto tr68;
	goto tr56;
case 66:
	if ( (*p) == 116 )
		goto tr69;
	goto tr56;
case 67:
	if ( (*p) == 101 )
		goto tr70;
	goto tr56;
case 68:
	if ( (*p) == 101 )
		goto tr71;
	goto tr56;
case 69:
	if ( (*p) == 110 )
		goto tr72;
	goto tr56;
case 70:
	if ( (*p) == 100 )
		goto tr73;
	goto tr56;
case 71:
	if ( (*p) == 98 )
		goto tr74;
	goto tr56;
case 72:
	if ( (*p) == 115 )
		goto tr75;
	goto tr56;
case 73:
	if ( (*p) == 116 )
		goto tr76;
	goto tr56;
case 74:
	if ( (*p) == 105 )
		goto tr77;
	goto tr56;
case 75:
	if ( (*p) == 116 )
		goto tr78;
	goto tr56;
case 76:
	if ( (*p) == 117 )
		goto tr79;
	goto tr56;
case 77:
	if ( (*p) == 116 )
		goto tr80;
	goto tr56;
case 78:
	if ( (*p) == 101 )
		goto tr81;
	goto tr56;
case 79:
	if ( (*p) == 101 )
		goto tr82;
	goto tr56;
case 80:
	if ( (*p) == 110 )
		goto tr83;
	goto tr56;
case 81:
	if ( (*p) == 100 )
		goto tr84;
	goto tr56;
case 127:
	switch( (*p) ) {
		case 45: goto tr140;
		case 92: goto tr140;
		case 95: goto tr141;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr140;
	} else if ( (*p) >= 65 )
		goto tr140;
	goto tr55;
case 128:
	switch( (*p) ) {
		case 45: goto tr140;
		case 92: goto tr140;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr140;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr140;
	} else
		goto tr140;
	goto tr142;
case 129:
	if ( (*p) == 116 )
		goto tr144;
	goto tr143;
case 82:
	if ( (*p) == 115 )
		goto tr86;
	goto tr85;
case 83:
	if ( (*p) == 98 )
		goto tr87;
	goto tr85;
case 84:
	if ( (*p) == 117 )
		goto tr88;
	goto tr85;
case 85:
	if ( (*p) == 115 )
		goto tr89;
	goto tr85;
case 86:
	if ( (*p) == 95 )
		goto tr90;
	goto tr85;
case 87:
	if ( (*p) == 99 )
		goto tr91;
	goto tr85;
case 88:
	if ( (*p) == 111 )
		goto tr92;
	goto tr85;
case 89:
	if ( (*p) == 116 )
		goto tr93;
	goto tr85;
case 90:
	if ( (*p) == 109 )
		goto tr94;
	goto tr85;
	}

	tr55: cs = 0; goto _again;
	tr124: cs = 1; goto _again;
	tr1: cs = 2; goto _again;
	tr2: cs = 3; goto _again;
	tr3: cs = 4; goto _again;
	tr4: cs = 5; goto _again;
	tr5: cs = 6; goto _again;
	tr129: cs = 7; goto _again;
	tr7: cs = 8; goto _again;
	tr8: cs = 9; goto _again;
	tr9: cs = 10; goto _again;
	tr10: cs = 11; goto _again;
	tr11: cs = 12; goto _again;
	tr12: cs = 13; goto _again;
	tr13: cs = 14; goto _again;
	tr14: cs = 15; goto _again;
	tr15: cs = 16; goto _again;
	tr16: cs = 17; goto _again;
	tr132: cs = 18; goto _again;
	tr18: cs = 19; goto _again;
	tr19: cs = 20; goto _again;
	tr20: cs = 21; goto _again;
	tr21: cs = 22; goto _again;
	tr22: cs = 23; goto _again;
	tr23: cs = 24; goto _again;
	tr24: cs = 25; goto _again;
	tr25: cs = 26; goto _again;
	tr26: cs = 27; goto _again;
	tr27: cs = 28; goto _again;
	tr28: cs = 29; goto _again;
	tr29: cs = 30; goto _again;
	tr30: cs = 31; goto _again;
	tr31: cs = 32; goto _again;
	tr32: cs = 33; goto _again;
	tr33: cs = 34; goto _again;
	tr34: cs = 35; goto _again;
	tr134: cs = 36; goto _again;
	tr36: cs = 37; goto _again;
	tr37: cs = 38; goto _again;
	tr38: cs = 39; goto _again;
	tr39: cs = 40; goto _again;
	tr40: cs = 41; goto _again;
	tr41: cs = 42; goto _again;
	tr42: cs = 43; goto _again;
	tr43: cs = 44; goto _again;
	tr44: cs = 45; goto _again;
	tr45: cs = 46; goto _again;
	tr46: cs = 47; goto _again;
	tr47: cs = 48; goto _again;
	tr48: cs = 49; goto _again;
	tr49: cs = 50; goto _again;
	tr50: cs = 51; goto _again;
	tr51: cs = 52; goto _again;
	tr52: cs = 53; goto _again;
	tr136: cs = 54; goto _again;
	tr139: cs = 55; goto _again;
	tr57: cs = 56; goto _again;
	tr58: cs = 57; goto _again;
	tr59: cs = 58; goto _again;
	tr60: cs = 59; goto _again;
	tr62: cs = 60; goto _again;
	tr63: cs = 61; goto _again;
	tr64: cs = 62; goto _again;
	tr65: cs = 63; goto _again;
	tr66: cs = 64; goto _again;
	tr67: cs = 65; goto _again;
	tr68: cs = 66; goto _again;
	tr69: cs = 67; goto _again;
	tr70: cs = 68; goto _again;
	tr71: cs = 69; goto _again;
	tr72: cs = 70; goto _again;
	tr61: cs = 71; goto _again;
	tr74: cs = 72; goto _again;
	tr75: cs = 73; goto _again;
	tr76: cs = 74; goto _again;
	tr77: cs = 75; goto _again;
	tr78: cs = 76; goto _again;
	tr79: cs = 77; goto _again;
	tr80: cs = 78; goto _again;
	tr81: cs = 79; goto _again;
	tr82: cs = 80; goto _again;
	tr83: cs = 81; goto _again;
	tr144: cs = 82; goto _again;
	tr86: cs = 83; goto _again;
	tr87: cs = 84; goto _again;
	tr88: cs = 85; goto _again;
	tr89: cs = 86; goto _again;
	tr90: cs = 87; goto _again;
	tr91: cs = 88; goto _again;
	tr92: cs = 89; goto _again;
	tr93: cs = 90; goto _again;
	tr0: cs = 91; goto f0;
	tr6: cs = 91; goto f1;
	tr17: cs = 91; goto f2;
	tr35: cs = 91; goto f3;
	tr53: cs = 91; goto f4;
	tr96: cs = 91; goto f14;
	tr100: cs = 91; goto f15;
	tr101: cs = 91; goto f16;
	tr95: cs = 92; goto f13;
	tr121: cs = 92; goto f17;
	tr97: cs = 93; goto _again;
	tr102: cs = 94; goto _again;
	tr104: cs = 95; goto _again;
	tr105: cs = 96; goto _again;
	tr106: cs = 97; goto _again;
	tr107: cs = 98; goto _again;
	tr108: cs = 99; goto _again;
	tr109: cs = 100; goto _again;
	tr110: cs = 101; goto _again;
	tr111: cs = 102; goto _again;
	tr112: cs = 103; goto _again;
	tr113: cs = 104; goto _again;
	tr114: cs = 105; goto _again;
	tr115: cs = 106; goto _again;
	tr116: cs = 107; goto _again;
	tr117: cs = 108; goto _again;
	tr118: cs = 109; goto _again;
	tr119: cs = 110; goto _again;
	tr120: cs = 111; goto _again;
	tr103: cs = 112; goto _again;
	tr122: cs = 113; goto _again;
	tr123: cs = 114; goto f5;
	tr98: cs = 115; goto _again;
	tr125: cs = 116; goto _again;
	tr126: cs = 117; goto _again;
	tr127: cs = 118; goto _again;
	tr128: cs = 119; goto f5;
	tr99: cs = 120; goto _again;
	tr130: cs = 121; goto _again;
	tr131: cs = 122; goto f5;
	tr133: cs = 123; goto f5;
	tr56: cs = 124; goto f6;
	tr73: cs = 124; goto f7;
	tr84: cs = 124; goto f8;
	tr137: cs = 124; goto f18;
	tr138: cs = 124; goto f19;
	tr135: cs = 125; goto _again;
	tr54: cs = 126; goto f5;
	tr85: cs = 127; goto f9;
	tr94: cs = 127; goto f10;
	tr142: cs = 127; goto f20;
	tr143: cs = 127; goto f21;
	tr140: cs = 128; goto _again;
	tr141: cs = 129; goto f5;

f5:
#line 1 "NONE"
	{te = p+1;}
	goto _again;
f7:
#line 50 "postprocess.rl"
	{te = p+1;{ fout << "] ="; {cs = 91; goto _again;} }}
	goto _again;
f8:
#line 53 "postprocess.rl"
	{te = p+1;{ fout << " ="; {cs = 91; goto _again;} }}
	goto _again;
f18:
#line 47 "postprocess.rl"
	{te = p;p--;{ fout.write(ts, te - ts); }}
	goto _again;
f19:
#line 56 "postprocess.rl"
	{te = p;p--;{ fout <<", "; }}
	goto _again;
f6:
#line 56 "postprocess.rl"
	{{p = ((te))-1;}{ fout <<", "; }}
	goto _again;
f10:
#line 65 "postprocess.rl"
	{te = p+1;{ {cs = 91; goto _again;} }}
	goto _again;
f21:
#line 61 "postprocess.rl"
	{te = p;p--;}
	goto _again;
f20:
#line 63 "postprocess.rl"
	{te = p;p--;}
	goto _again;
f9:
#line 61 "postprocess.rl"
	{{p = ((te))-1;}}
	goto _again;
f4:
#line 70 "postprocess.rl"
	{te = p+1;{ fout << "function ["; {cs = 124; goto _again;} }}
	goto _again;
f3:
#line 73 "postprocess.rl"
	{te = p+1;{ fout << "function "; {cs = 124; goto _again;} }}
	goto _again;
f2:
#line 76 "postprocess.rl"
	{te = p+1;{fout << "function ";}}
	goto _again;
f1:
#line 79 "postprocess.rl"
	{te = p+1;{ {cs = 127; goto _again;} }}
	goto _again;
f14:
#line 88 "postprocess.rl"
	{te = p+1;{fout << *ts;}}
	goto _again;
f16:
#line 85 "postprocess.rl"
	{te = p;p--;{ fout.write(ts, te-ts); }}
	goto _again;
f0:
#line 85 "postprocess.rl"
	{{p = ((te))-1;}{ fout.write(ts, te-ts); }}
	goto _again;
f15:
#line 1 "NONE"
	{	switch( act ) {
	case 12:
	{{p = ((te))-1;}fout << " ";}
	break;
	case 13:
	{{p = ((te))-1;} fout.write(ts, te-ts); }
	break;
	}
	}
	goto _again;
f17:
#line 1 "NONE"
	{te = p+1;}
#line 82 "postprocess.rl"
	{act = 12;}
	goto _again;
f13:
#line 1 "NONE"
	{te = p+1;}
#line 85 "postprocess.rl"
	{act = 13;}
	goto _again;

_again:
	switch ( _PostProcess_to_state_actions[cs] ) {
	case 12:
#line 1 "NONE"
	{ts = 0;}
	break;
#line 1522 "postprocess.cc"
	}

	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 92: goto tr100;
	case 93: goto tr101;
	case 94: goto tr101;
	case 95: goto tr101;
	case 96: goto tr101;
	case 97: goto tr101;
	case 98: goto tr101;
	case 99: goto tr101;
	case 100: goto tr101;
	case 101: goto tr101;
	case 102: goto tr101;
	case 103: goto tr101;
	case 104: goto tr101;
	case 105: goto tr101;
	case 106: goto tr101;
	case 107: goto tr101;
	case 108: goto tr101;
	case 109: goto tr101;
	case 110: goto tr101;
	case 111: goto tr101;
	case 112: goto tr101;
	case 113: goto tr101;
	case 114: goto tr101;
	case 1: goto tr0;
	case 2: goto tr0;
	case 3: goto tr0;
	case 4: goto tr0;
	case 5: goto tr0;
	case 6: goto tr0;
	case 115: goto tr101;
	case 116: goto tr101;
	case 117: goto tr101;
	case 118: goto tr101;
	case 119: goto tr101;
	case 7: goto tr0;
	case 8: goto tr0;
	case 9: goto tr0;
	case 10: goto tr0;
	case 11: goto tr0;
	case 12: goto tr0;
	case 13: goto tr0;
	case 14: goto tr0;
	case 15: goto tr0;
	case 16: goto tr0;
	case 17: goto tr0;
	case 120: goto tr101;
	case 121: goto tr101;
	case 122: goto tr101;
	case 18: goto tr0;
	case 19: goto tr0;
	case 20: goto tr0;
	case 21: goto tr0;
	case 22: goto tr0;
	case 23: goto tr0;
	case 24: goto tr0;
	case 25: goto tr0;
	case 26: goto tr0;
	case 27: goto tr0;
	case 28: goto tr0;
	case 29: goto tr0;
	case 30: goto tr0;
	case 31: goto tr0;
	case 32: goto tr0;
	case 33: goto tr0;
	case 34: goto tr0;
	case 35: goto tr0;
	case 123: goto tr101;
	case 36: goto tr0;
	case 37: goto tr0;
	case 38: goto tr0;
	case 39: goto tr0;
	case 40: goto tr0;
	case 41: goto tr0;
	case 42: goto tr0;
	case 43: goto tr0;
	case 44: goto tr0;
	case 45: goto tr0;
	case 46: goto tr0;
	case 47: goto tr0;
	case 48: goto tr0;
	case 49: goto tr0;
	case 50: goto tr0;
	case 51: goto tr0;
	case 52: goto tr0;
	case 53: goto tr0;
	case 125: goto tr137;
	case 126: goto tr138;
	case 55: goto tr56;
	case 56: goto tr56;
	case 57: goto tr56;
	case 58: goto tr56;
	case 59: goto tr56;
	case 60: goto tr56;
	case 61: goto tr56;
	case 62: goto tr56;
	case 63: goto tr56;
	case 64: goto tr56;
	case 65: goto tr56;
	case 66: goto tr56;
	case 67: goto tr56;
	case 68: goto tr56;
	case 69: goto tr56;
	case 70: goto tr56;
	case 71: goto tr56;
	case 72: goto tr56;
	case 73: goto tr56;
	case 74: goto tr56;
	case 75: goto tr56;
	case 76: goto tr56;
	case 77: goto tr56;
	case 78: goto tr56;
	case 79: goto tr56;
	case 80: goto tr56;
	case 81: goto tr56;
	case 128: goto tr142;
	case 129: goto tr143;
	case 82: goto tr85;
	case 83: goto tr85;
	case 84: goto tr85;
	case 85: goto tr85;
	case 86: goto tr85;
	case 87: goto tr85;
	case 88: goto tr85;
	case 89: goto tr85;
	case 90: goto tr85;
	}
	}

	_out: {}
	}

#line 148 "postprocess.rl"

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

