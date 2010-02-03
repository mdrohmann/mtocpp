
#line 1 "postprocess.rl"

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


#line 19 "postprocess.cc"
static const int PostProcess_start = 91;
static const int PostProcess_first_final = 91;
static const int PostProcess_error = 0;

static const int PostProcess_en_retvals = 124;
static const int PostProcess_en_mtocsubst = 127;
static const int PostProcess_en_main = 91;


#line 71 "postprocess.rl"


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

    
#line 47 "postprocess.cc"
	{
	cs = PostProcess_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 88 "postprocess.rl"

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

    
#line 95 "postprocess.cc"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
tr0:
#line 67 "postprocess.rl"
	{{p = ((te))-1;}{ fout.write(ts, te-ts); }}
	goto st91;
tr6:
#line 63 "postprocess.rl"
	{te = p+1;{ {goto st127;} }}
	goto st91;
tr17:
#line 61 "postprocess.rl"
	{te = p+1;{fout << "function ";}}
	goto st91;
tr35:
#line 59 "postprocess.rl"
	{te = p+1;{ fout << "function "; {goto st124;} }}
	goto st91;
tr53:
#line 57 "postprocess.rl"
	{te = p+1;{ fout << "function ["; {goto st124;} }}
	goto st91;
tr96:
#line 69 "postprocess.rl"
	{te = p+1;{fout << *ts;}}
	goto st91;
tr100:
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
	goto st91;
tr101:
#line 67 "postprocess.rl"
	{te = p;p--;{ fout.write(ts, te-ts); }}
	goto st91;
st91:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof91;
case 91:
#line 1 "NONE"
	{ts = p;}
#line 149 "postprocess.cc"
	switch( (*p) ) {
		case 32: goto tr96;
		case 38: goto tr96;
		case 62: goto tr96;
		case 91: goto tr96;
		case 93: goto tr96;
		case 95: goto tr96;
		case 109: goto st93;
		case 110: goto st115;
		case 114: goto st120;
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
tr95:
#line 1 "NONE"
	{te = p+1;}
#line 67 "postprocess.rl"
	{act = 13;}
	goto st92;
tr121:
#line 1 "NONE"
	{te = p+1;}
#line 65 "postprocess.rl"
	{act = 12;}
	goto st92;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
#line 188 "postprocess.cc"
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
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 97: goto st94;
		case 116: goto st112;
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
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 116: goto st95;
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
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 108: goto st96;
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
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 97: goto st97;
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
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 98: goto st98;
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
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 116: goto st99;
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
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 121: goto st100;
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
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 112: goto st101;
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
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 101: goto st102;
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
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 115: goto st103;
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
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 117: goto st104;
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
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 98: goto st105;
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
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 115: goto st106;
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
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 116: goto st107;
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
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 105: goto st108;
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
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 116: goto st109;
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
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 117: goto st110;
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
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 116: goto st111;
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
st111:
	if ( ++p == pe )
		goto _test_eof111;
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
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 111: goto st113;
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
st113:
	if ( ++p == pe )
		goto _test_eof113;
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
tr123:
#line 1 "NONE"
	{te = p+1;}
	goto st114;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
#line 721 "postprocess.cc"
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto st1;
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
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
	if ( (*p) == 115 )
		goto st2;
	goto tr0;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	if ( (*p) == 117 )
		goto st3;
	goto tr0;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
	if ( (*p) == 98 )
		goto st4;
	goto tr0;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
	if ( (*p) == 115 )
		goto st5;
	goto tr0;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
	if ( (*p) == 116 )
		goto st6;
	goto tr0;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
	if ( (*p) == 95 )
		goto tr6;
	goto tr0;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 111: goto st116;
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
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 114: goto st117;
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
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 101: goto st118;
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
st118:
	if ( ++p == pe )
		goto _test_eof118;
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
tr128:
#line 1 "NONE"
	{te = p+1;}
	goto st119;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
#line 887 "postprocess.cc"
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 58: goto st7;
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
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
	if ( (*p) == 58 )
		goto st8;
	goto tr0;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
	if ( (*p) == 115 )
		goto st9;
	goto tr0;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
	if ( (*p) == 117 )
		goto st10;
	goto tr0;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
	if ( (*p) == 98 )
		goto st11;
	goto tr0;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
	if ( (*p) == 115 )
		goto st12;
	goto tr0;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
	if ( (*p) == 116 )
		goto st13;
	goto tr0;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	if ( (*p) == 105 )
		goto st14;
	goto tr0;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
	if ( (*p) == 116 )
		goto st15;
	goto tr0;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
	if ( (*p) == 117 )
		goto st16;
	goto tr0;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
	if ( (*p) == 116 )
		goto st17;
	goto tr0;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
	if ( (*p) == 101 )
		goto tr17;
	goto tr0;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 62: goto tr101;
		case 91: goto tr101;
		case 93: goto tr101;
		case 95: goto tr101;
		case 101: goto st121;
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
st121:
	if ( ++p == pe )
		goto _test_eof121;
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
tr131:
#line 1 "NONE"
	{te = p+1;}
	goto st122;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
#line 1041 "postprocess.cc"
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 58: goto st18;
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
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
	if ( (*p) == 58 )
		goto st19;
	goto tr0;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
	if ( (*p) == 115 )
		goto st20;
	goto tr0;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
	if ( (*p) == 117 )
		goto st21;
	goto tr0;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
	if ( (*p) == 98 )
		goto st22;
	goto tr0;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
	if ( (*p) == 115 )
		goto st23;
	goto tr0;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	if ( (*p) == 116 )
		goto st24;
	goto tr0;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
	if ( (*p) == 105 )
		goto st25;
	goto tr0;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
	if ( (*p) == 116 )
		goto st26;
	goto tr0;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
	if ( (*p) == 117 )
		goto st27;
	goto tr0;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
	if ( (*p) == 116 )
		goto st28;
	goto tr0;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
	if ( (*p) == 101 )
		goto st29;
	goto tr0;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
	if ( (*p) == 115 )
		goto st30;
	goto tr0;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
	if ( (*p) == 116 )
		goto st31;
	goto tr0;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
	if ( (*p) == 97 )
		goto st32;
	goto tr0;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
	if ( (*p) == 114 )
		goto st33;
	goto tr0;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
	if ( (*p) == 116 )
		goto st34;
	goto tr0;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
	if ( (*p) == 58 )
		goto st35;
	goto tr0;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
	if ( (*p) == 58 )
		goto tr35;
	goto tr0;
tr133:
#line 1 "NONE"
	{te = p+1;}
	goto st123;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
#line 1197 "postprocess.cc"
	switch( (*p) ) {
		case 32: goto tr101;
		case 38: goto tr101;
		case 58: goto st36;
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
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
	if ( (*p) == 58 )
		goto st37;
	goto tr0;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
	if ( (*p) == 115 )
		goto st38;
	goto tr0;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
	if ( (*p) == 117 )
		goto st39;
	goto tr0;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
	if ( (*p) == 98 )
		goto st40;
	goto tr0;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
	if ( (*p) == 115 )
		goto st41;
	goto tr0;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
	if ( (*p) == 116 )
		goto st42;
	goto tr0;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
	if ( (*p) == 105 )
		goto st43;
	goto tr0;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
	if ( (*p) == 116 )
		goto st44;
	goto tr0;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
	if ( (*p) == 117 )
		goto st45;
	goto tr0;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
	if ( (*p) == 116 )
		goto st46;
	goto tr0;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
	if ( (*p) == 101 )
		goto st47;
	goto tr0;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
	if ( (*p) == 115 )
		goto st48;
	goto tr0;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
	if ( (*p) == 116 )
		goto st49;
	goto tr0;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
	if ( (*p) == 97 )
		goto st50;
	goto tr0;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
	if ( (*p) == 114 )
		goto st51;
	goto tr0;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
	if ( (*p) == 116 )
		goto st52;
	goto tr0;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
	if ( (*p) == 58 )
		goto st53;
	goto tr0;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
	if ( (*p) == 58 )
		goto tr53;
	goto tr0;
tr56:
#line 45 "postprocess.rl"
	{{p = ((te))-1;}{ fout <<", "; }}
	goto st124;
tr73:
#line 41 "postprocess.rl"
	{te = p+1;{ fout << "] ="; {goto st91;} }}
	goto st124;
tr84:
#line 43 "postprocess.rl"
	{te = p+1;{ fout << " ="; {goto st91;} }}
	goto st124;
tr137:
#line 39 "postprocess.rl"
	{te = p;p--;{ fout.write(ts, te - ts); }}
	goto st124;
tr138:
#line 45 "postprocess.rl"
	{te = p;p--;{ fout <<", "; }}
	goto st124;
st124:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof124;
case 124:
#line 1 "NONE"
	{ts = p;}
#line 1372 "postprocess.cc"
	switch( (*p) ) {
		case 45: goto st125;
		case 58: goto st54;
		case 92: goto st125;
		case 95: goto st125;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st125;
	} else if ( (*p) >= 65 )
		goto st125;
	goto st0;
st0:
cs = 0;
	goto _out;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
	switch( (*p) ) {
		case 45: goto st125;
		case 92: goto st125;
		case 95: goto st125;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st125;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st125;
	} else
		goto st125;
	goto tr137;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
	if ( (*p) == 58 )
		goto tr54;
	goto st0;
tr54:
#line 1 "NONE"
	{te = p+1;}
	goto st126;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
#line 1421 "postprocess.cc"
	if ( (*p) == 114 )
		goto st55;
	goto tr138;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
	if ( (*p) == 101 )
		goto st56;
	goto tr56;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
	if ( (*p) == 116 )
		goto st57;
	goto tr56;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
	if ( (*p) == 115 )
		goto st58;
	goto tr56;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
	switch( (*p) ) {
		case 115: goto st59;
		case 117: goto st71;
	}
	goto tr56;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
	if ( (*p) == 117 )
		goto st60;
	goto tr56;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
	if ( (*p) == 98 )
		goto st61;
	goto tr56;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
	if ( (*p) == 115 )
		goto st62;
	goto tr56;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
	if ( (*p) == 116 )
		goto st63;
	goto tr56;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
	if ( (*p) == 105 )
		goto st64;
	goto tr56;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
	if ( (*p) == 116 )
		goto st65;
	goto tr56;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
	if ( (*p) == 117 )
		goto st66;
	goto tr56;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
	if ( (*p) == 116 )
		goto st67;
	goto tr56;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
	if ( (*p) == 101 )
		goto st68;
	goto tr56;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
	if ( (*p) == 101 )
		goto st69;
	goto tr56;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
	if ( (*p) == 110 )
		goto st70;
	goto tr56;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
	if ( (*p) == 100 )
		goto tr73;
	goto tr56;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
	if ( (*p) == 98 )
		goto st72;
	goto tr56;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
	if ( (*p) == 115 )
		goto st73;
	goto tr56;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
	if ( (*p) == 116 )
		goto st74;
	goto tr56;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
	if ( (*p) == 105 )
		goto st75;
	goto tr56;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
	if ( (*p) == 116 )
		goto st76;
	goto tr56;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
	if ( (*p) == 117 )
		goto st77;
	goto tr56;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
	if ( (*p) == 116 )
		goto st78;
	goto tr56;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
	if ( (*p) == 101 )
		goto st79;
	goto tr56;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
	if ( (*p) == 101 )
		goto st80;
	goto tr56;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
	if ( (*p) == 110 )
		goto st81;
	goto tr56;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
	if ( (*p) == 100 )
		goto tr84;
	goto tr56;
tr85:
#line 49 "postprocess.rl"
	{{p = ((te))-1;}}
	goto st127;
tr94:
#line 53 "postprocess.rl"
	{te = p+1;{ {goto st91;} }}
	goto st127;
tr142:
#line 51 "postprocess.rl"
	{te = p;p--;}
	goto st127;
tr143:
#line 49 "postprocess.rl"
	{te = p;p--;}
	goto st127;
st127:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof127;
case 127:
#line 1 "NONE"
	{ts = p;}
#line 1640 "postprocess.cc"
	switch( (*p) ) {
		case 45: goto st128;
		case 92: goto st128;
		case 95: goto tr141;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st128;
	} else if ( (*p) >= 65 )
		goto st128;
	goto st0;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
	switch( (*p) ) {
		case 45: goto st128;
		case 92: goto st128;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st128;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st128;
	} else
		goto st128;
	goto tr142;
tr141:
#line 1 "NONE"
	{te = p+1;}
	goto st129;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
#line 1677 "postprocess.cc"
	if ( (*p) == 116 )
		goto st82;
	goto tr143;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
	if ( (*p) == 115 )
		goto st83;
	goto tr85;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
	if ( (*p) == 98 )
		goto st84;
	goto tr85;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
	if ( (*p) == 117 )
		goto st85;
	goto tr85;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
	if ( (*p) == 115 )
		goto st86;
	goto tr85;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
	if ( (*p) == 95 )
		goto st87;
	goto tr85;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
	if ( (*p) == 99 )
		goto st88;
	goto tr85;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
	if ( (*p) == 111 )
		goto st89;
	goto tr85;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
	if ( (*p) == 116 )
		goto st90;
	goto tr85;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
	if ( (*p) == 109 )
		goto tr94;
	goto tr85;
	}
	_test_eof91: cs = 91; goto _test_eof; 
	_test_eof92: cs = 92; goto _test_eof; 
	_test_eof93: cs = 93; goto _test_eof; 
	_test_eof94: cs = 94; goto _test_eof; 
	_test_eof95: cs = 95; goto _test_eof; 
	_test_eof96: cs = 96; goto _test_eof; 
	_test_eof97: cs = 97; goto _test_eof; 
	_test_eof98: cs = 98; goto _test_eof; 
	_test_eof99: cs = 99; goto _test_eof; 
	_test_eof100: cs = 100; goto _test_eof; 
	_test_eof101: cs = 101; goto _test_eof; 
	_test_eof102: cs = 102; goto _test_eof; 
	_test_eof103: cs = 103; goto _test_eof; 
	_test_eof104: cs = 104; goto _test_eof; 
	_test_eof105: cs = 105; goto _test_eof; 
	_test_eof106: cs = 106; goto _test_eof; 
	_test_eof107: cs = 107; goto _test_eof; 
	_test_eof108: cs = 108; goto _test_eof; 
	_test_eof109: cs = 109; goto _test_eof; 
	_test_eof110: cs = 110; goto _test_eof; 
	_test_eof111: cs = 111; goto _test_eof; 
	_test_eof112: cs = 112; goto _test_eof; 
	_test_eof113: cs = 113; goto _test_eof; 
	_test_eof114: cs = 114; goto _test_eof; 
	_test_eof1: cs = 1; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof115: cs = 115; goto _test_eof; 
	_test_eof116: cs = 116; goto _test_eof; 
	_test_eof117: cs = 117; goto _test_eof; 
	_test_eof118: cs = 118; goto _test_eof; 
	_test_eof119: cs = 119; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof120: cs = 120; goto _test_eof; 
	_test_eof121: cs = 121; goto _test_eof; 
	_test_eof122: cs = 122; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof23: cs = 23; goto _test_eof; 
	_test_eof24: cs = 24; goto _test_eof; 
	_test_eof25: cs = 25; goto _test_eof; 
	_test_eof26: cs = 26; goto _test_eof; 
	_test_eof27: cs = 27; goto _test_eof; 
	_test_eof28: cs = 28; goto _test_eof; 
	_test_eof29: cs = 29; goto _test_eof; 
	_test_eof30: cs = 30; goto _test_eof; 
	_test_eof31: cs = 31; goto _test_eof; 
	_test_eof32: cs = 32; goto _test_eof; 
	_test_eof33: cs = 33; goto _test_eof; 
	_test_eof34: cs = 34; goto _test_eof; 
	_test_eof35: cs = 35; goto _test_eof; 
	_test_eof123: cs = 123; goto _test_eof; 
	_test_eof36: cs = 36; goto _test_eof; 
	_test_eof37: cs = 37; goto _test_eof; 
	_test_eof38: cs = 38; goto _test_eof; 
	_test_eof39: cs = 39; goto _test_eof; 
	_test_eof40: cs = 40; goto _test_eof; 
	_test_eof41: cs = 41; goto _test_eof; 
	_test_eof42: cs = 42; goto _test_eof; 
	_test_eof43: cs = 43; goto _test_eof; 
	_test_eof44: cs = 44; goto _test_eof; 
	_test_eof45: cs = 45; goto _test_eof; 
	_test_eof46: cs = 46; goto _test_eof; 
	_test_eof47: cs = 47; goto _test_eof; 
	_test_eof48: cs = 48; goto _test_eof; 
	_test_eof49: cs = 49; goto _test_eof; 
	_test_eof50: cs = 50; goto _test_eof; 
	_test_eof51: cs = 51; goto _test_eof; 
	_test_eof52: cs = 52; goto _test_eof; 
	_test_eof53: cs = 53; goto _test_eof; 
	_test_eof124: cs = 124; goto _test_eof; 
	_test_eof125: cs = 125; goto _test_eof; 
	_test_eof54: cs = 54; goto _test_eof; 
	_test_eof126: cs = 126; goto _test_eof; 
	_test_eof55: cs = 55; goto _test_eof; 
	_test_eof56: cs = 56; goto _test_eof; 
	_test_eof57: cs = 57; goto _test_eof; 
	_test_eof58: cs = 58; goto _test_eof; 
	_test_eof59: cs = 59; goto _test_eof; 
	_test_eof60: cs = 60; goto _test_eof; 
	_test_eof61: cs = 61; goto _test_eof; 
	_test_eof62: cs = 62; goto _test_eof; 
	_test_eof63: cs = 63; goto _test_eof; 
	_test_eof64: cs = 64; goto _test_eof; 
	_test_eof65: cs = 65; goto _test_eof; 
	_test_eof66: cs = 66; goto _test_eof; 
	_test_eof67: cs = 67; goto _test_eof; 
	_test_eof68: cs = 68; goto _test_eof; 
	_test_eof69: cs = 69; goto _test_eof; 
	_test_eof70: cs = 70; goto _test_eof; 
	_test_eof71: cs = 71; goto _test_eof; 
	_test_eof72: cs = 72; goto _test_eof; 
	_test_eof73: cs = 73; goto _test_eof; 
	_test_eof74: cs = 74; goto _test_eof; 
	_test_eof75: cs = 75; goto _test_eof; 
	_test_eof76: cs = 76; goto _test_eof; 
	_test_eof77: cs = 77; goto _test_eof; 
	_test_eof78: cs = 78; goto _test_eof; 
	_test_eof79: cs = 79; goto _test_eof; 
	_test_eof80: cs = 80; goto _test_eof; 
	_test_eof81: cs = 81; goto _test_eof; 
	_test_eof127: cs = 127; goto _test_eof; 
	_test_eof128: cs = 128; goto _test_eof; 
	_test_eof129: cs = 129; goto _test_eof; 
	_test_eof82: cs = 82; goto _test_eof; 
	_test_eof83: cs = 83; goto _test_eof; 
	_test_eof84: cs = 84; goto _test_eof; 
	_test_eof85: cs = 85; goto _test_eof; 
	_test_eof86: cs = 86; goto _test_eof; 
	_test_eof87: cs = 87; goto _test_eof; 
	_test_eof88: cs = 88; goto _test_eof; 
	_test_eof89: cs = 89; goto _test_eof; 
	_test_eof90: cs = 90; goto _test_eof; 

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

#line 127 "postprocess.rl"

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

