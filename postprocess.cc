
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
static const int PostProcess_start = 76;
static const int PostProcess_first_final = 76;
static const int PostProcess_error = 0;

static const int PostProcess_en_retvals = 87;
static const int PostProcess_en_main = 76;


#line 57 "postprocess.rl"


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

    
#line 46 "postprocess.cc"
	{
	cs = PostProcess_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 74 "postprocess.rl"

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

    
#line 94 "postprocess.cc"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
tr0:
#line 53 "postprocess.rl"
	{{p = ((te))-1;}{ fout.write(ts, te-ts); }}
	goto st76;
tr11:
#line 51 "postprocess.rl"
	{te = p+1;{fout << "function ";}}
	goto st76;
tr29:
#line 49 "postprocess.rl"
	{te = p+1;{ fout << "function "; {goto st87;} }}
	goto st76;
tr47:
#line 47 "postprocess.rl"
	{te = p+1;{ fout << "function ["; {goto st87;} }}
	goto st76;
tr80:
#line 55 "postprocess.rl"
	{te = p+1;{fout << *ts;}}
	goto st76;
tr83:
#line 53 "postprocess.rl"
	{te = p;p--;{ fout.write(ts, te-ts); }}
	goto st76;
st76:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof76;
case 76:
#line 1 "NONE"
	{ts = p;}
#line 132 "postprocess.cc"
	switch( (*p) ) {
		case 32: goto tr80;
		case 58: goto tr80;
		case 60: goto tr80;
		case 62: goto tr80;
		case 91: goto tr80;
		case 93: goto tr80;
		case 95: goto tr80;
		case 110: goto st78;
		case 114: goto st83;
		case 123: goto tr80;
		case 125: goto tr80;
	}
	if ( (*p) > 10 ) {
		if ( 40 <= (*p) && (*p) <= 41 )
			goto tr80;
	} else if ( (*p) >= 9 )
		goto tr80;
	goto st77;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
	switch( (*p) ) {
		case 32: goto tr83;
		case 58: goto tr83;
		case 60: goto tr83;
		case 62: goto tr83;
		case 91: goto tr83;
		case 93: goto tr83;
		case 95: goto tr83;
		case 123: goto tr83;
		case 125: goto tr83;
	}
	if ( (*p) > 10 ) {
		if ( 40 <= (*p) && (*p) <= 41 )
			goto tr83;
	} else if ( (*p) >= 9 )
		goto tr83;
	goto st77;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
	switch( (*p) ) {
		case 32: goto tr83;
		case 58: goto tr83;
		case 60: goto tr83;
		case 62: goto tr83;
		case 91: goto tr83;
		case 93: goto tr83;
		case 95: goto tr83;
		case 111: goto st79;
		case 123: goto tr83;
		case 125: goto tr83;
	}
	if ( (*p) > 10 ) {
		if ( 40 <= (*p) && (*p) <= 41 )
			goto tr83;
	} else if ( (*p) >= 9 )
		goto tr83;
	goto st77;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
	switch( (*p) ) {
		case 32: goto tr83;
		case 58: goto tr83;
		case 60: goto tr83;
		case 62: goto tr83;
		case 91: goto tr83;
		case 93: goto tr83;
		case 95: goto tr83;
		case 114: goto st80;
		case 123: goto tr83;
		case 125: goto tr83;
	}
	if ( (*p) > 10 ) {
		if ( 40 <= (*p) && (*p) <= 41 )
			goto tr83;
	} else if ( (*p) >= 9 )
		goto tr83;
	goto st77;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
	switch( (*p) ) {
		case 32: goto tr83;
		case 58: goto tr83;
		case 60: goto tr83;
		case 62: goto tr83;
		case 91: goto tr83;
		case 93: goto tr83;
		case 95: goto tr83;
		case 101: goto st81;
		case 123: goto tr83;
		case 125: goto tr83;
	}
	if ( (*p) > 10 ) {
		if ( 40 <= (*p) && (*p) <= 41 )
			goto tr83;
	} else if ( (*p) >= 9 )
		goto tr83;
	goto st77;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
	switch( (*p) ) {
		case 32: goto tr83;
		case 58: goto tr83;
		case 60: goto tr83;
		case 62: goto tr83;
		case 91: goto tr83;
		case 93: goto tr83;
		case 95: goto tr83;
		case 116: goto tr87;
		case 123: goto tr83;
		case 125: goto tr83;
	}
	if ( (*p) > 10 ) {
		if ( 40 <= (*p) && (*p) <= 41 )
			goto tr83;
	} else if ( (*p) >= 9 )
		goto tr83;
	goto st77;
tr87:
#line 1 "NONE"
	{te = p+1;}
	goto st82;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
#line 269 "postprocess.cc"
	switch( (*p) ) {
		case 32: goto tr83;
		case 58: goto st1;
		case 60: goto tr83;
		case 62: goto tr83;
		case 91: goto tr83;
		case 93: goto tr83;
		case 95: goto tr83;
		case 123: goto tr83;
		case 125: goto tr83;
	}
	if ( (*p) > 10 ) {
		if ( 40 <= (*p) && (*p) <= 41 )
			goto tr83;
	} else if ( (*p) >= 9 )
		goto tr83;
	goto st77;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
	if ( (*p) == 58 )
		goto st2;
	goto tr0;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	if ( (*p) == 115 )
		goto st3;
	goto tr0;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
	if ( (*p) == 117 )
		goto st4;
	goto tr0;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
	if ( (*p) == 98 )
		goto st5;
	goto tr0;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
	if ( (*p) == 115 )
		goto st6;
	goto tr0;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
	if ( (*p) == 116 )
		goto st7;
	goto tr0;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
	if ( (*p) == 105 )
		goto st8;
	goto tr0;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
	if ( (*p) == 116 )
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
	if ( (*p) == 116 )
		goto st11;
	goto tr0;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
	if ( (*p) == 101 )
		goto tr11;
	goto tr0;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
	switch( (*p) ) {
		case 32: goto tr83;
		case 58: goto tr83;
		case 60: goto tr83;
		case 62: goto tr83;
		case 91: goto tr83;
		case 93: goto tr83;
		case 95: goto tr83;
		case 101: goto st84;
		case 123: goto tr83;
		case 125: goto tr83;
	}
	if ( (*p) > 10 ) {
		if ( 40 <= (*p) && (*p) <= 41 )
			goto tr83;
	} else if ( (*p) >= 9 )
		goto tr83;
	goto st77;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
	switch( (*p) ) {
		case 32: goto tr83;
		case 58: goto tr83;
		case 60: goto tr83;
		case 62: goto tr83;
		case 91: goto tr83;
		case 93: goto tr83;
		case 95: goto tr83;
		case 116: goto tr90;
		case 123: goto tr83;
		case 125: goto tr83;
	}
	if ( (*p) > 10 ) {
		if ( 40 <= (*p) && (*p) <= 41 )
			goto tr83;
	} else if ( (*p) >= 9 )
		goto tr83;
	goto st77;
tr90:
#line 1 "NONE"
	{te = p+1;}
	goto st85;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
#line 416 "postprocess.cc"
	switch( (*p) ) {
		case 32: goto tr83;
		case 58: goto st12;
		case 60: goto tr83;
		case 62: goto tr83;
		case 91: goto tr83;
		case 93: goto tr83;
		case 95: goto tr83;
		case 115: goto tr92;
		case 123: goto tr83;
		case 125: goto tr83;
	}
	if ( (*p) > 10 ) {
		if ( 40 <= (*p) && (*p) <= 41 )
			goto tr83;
	} else if ( (*p) >= 9 )
		goto tr83;
	goto st77;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
	if ( (*p) == 58 )
		goto st13;
	goto tr0;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	if ( (*p) == 115 )
		goto st14;
	goto tr0;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
	if ( (*p) == 117 )
		goto st15;
	goto tr0;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
	if ( (*p) == 98 )
		goto st16;
	goto tr0;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
	if ( (*p) == 115 )
		goto st17;
	goto tr0;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
	if ( (*p) == 116 )
		goto st18;
	goto tr0;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
	if ( (*p) == 105 )
		goto st19;
	goto tr0;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
	if ( (*p) == 116 )
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
	if ( (*p) == 116 )
		goto st22;
	goto tr0;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
	if ( (*p) == 101 )
		goto st23;
	goto tr0;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	if ( (*p) == 115 )
		goto st24;
	goto tr0;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
	if ( (*p) == 116 )
		goto st25;
	goto tr0;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
	if ( (*p) == 97 )
		goto st26;
	goto tr0;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
	if ( (*p) == 114 )
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
	if ( (*p) == 58 )
		goto st29;
	goto tr0;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
	if ( (*p) == 58 )
		goto tr29;
	goto tr0;
tr92:
#line 1 "NONE"
	{te = p+1;}
	goto st86;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
#line 569 "postprocess.cc"
	switch( (*p) ) {
		case 32: goto tr83;
		case 58: goto st30;
		case 60: goto tr83;
		case 62: goto tr83;
		case 91: goto tr83;
		case 93: goto tr83;
		case 95: goto tr83;
		case 123: goto tr83;
		case 125: goto tr83;
	}
	if ( (*p) > 10 ) {
		if ( 40 <= (*p) && (*p) <= 41 )
			goto tr83;
	} else if ( (*p) >= 9 )
		goto tr83;
	goto st77;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
	if ( (*p) == 58 )
		goto st31;
	goto tr0;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
	if ( (*p) == 115 )
		goto st32;
	goto tr0;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
	if ( (*p) == 117 )
		goto st33;
	goto tr0;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
	if ( (*p) == 98 )
		goto st34;
	goto tr0;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
	if ( (*p) == 115 )
		goto st35;
	goto tr0;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
	if ( (*p) == 116 )
		goto st36;
	goto tr0;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
	if ( (*p) == 105 )
		goto st37;
	goto tr0;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
	if ( (*p) == 116 )
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
	if ( (*p) == 116 )
		goto st40;
	goto tr0;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
	if ( (*p) == 101 )
		goto st41;
	goto tr0;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
	if ( (*p) == 115 )
		goto st42;
	goto tr0;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
	if ( (*p) == 116 )
		goto st43;
	goto tr0;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
	if ( (*p) == 97 )
		goto st44;
	goto tr0;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
	if ( (*p) == 114 )
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
	if ( (*p) == 58 )
		goto st47;
	goto tr0;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
	if ( (*p) == 58 )
		goto tr47;
	goto tr0;
tr50:
#line 43 "postprocess.rl"
	{{p = ((te))-1;}{ fout <<", "; }}
	goto st87;
tr67:
#line 39 "postprocess.rl"
	{te = p+1;{ fout << "] ="; {goto st76;} }}
	goto st87;
tr78:
#line 41 "postprocess.rl"
	{te = p+1;{ fout << " ="; {goto st76;} }}
	goto st87;
tr96:
#line 37 "postprocess.rl"
	{te = p;p--;{ fout.write(ts, te - ts); }}
	goto st87;
tr97:
#line 43 "postprocess.rl"
	{te = p;p--;{ fout <<", "; }}
	goto st87;
st87:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof87;
case 87:
#line 1 "NONE"
	{ts = p;}
#line 741 "postprocess.cc"
	switch( (*p) ) {
		case 45: goto st88;
		case 58: goto st48;
		case 92: goto st88;
		case 95: goto st88;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st88;
	} else if ( (*p) >= 65 )
		goto st88;
	goto st0;
st0:
cs = 0;
	goto _out;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
	switch( (*p) ) {
		case 45: goto st88;
		case 92: goto st88;
		case 95: goto st88;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st88;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st88;
	} else
		goto st88;
	goto tr96;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
	if ( (*p) == 58 )
		goto tr48;
	goto st0;
tr48:
#line 1 "NONE"
	{te = p+1;}
	goto st89;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
#line 790 "postprocess.cc"
	if ( (*p) == 114 )
		goto st49;
	goto tr97;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
	if ( (*p) == 101 )
		goto st50;
	goto tr50;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
	if ( (*p) == 116 )
		goto st51;
	goto tr50;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
	if ( (*p) == 115 )
		goto st52;
	goto tr50;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
	switch( (*p) ) {
		case 115: goto st53;
		case 117: goto st65;
	}
	goto tr50;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
	if ( (*p) == 117 )
		goto st54;
	goto tr50;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
	if ( (*p) == 98 )
		goto st55;
	goto tr50;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
	if ( (*p) == 115 )
		goto st56;
	goto tr50;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
	if ( (*p) == 116 )
		goto st57;
	goto tr50;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
	if ( (*p) == 105 )
		goto st58;
	goto tr50;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
	if ( (*p) == 116 )
		goto st59;
	goto tr50;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
	if ( (*p) == 117 )
		goto st60;
	goto tr50;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
	if ( (*p) == 116 )
		goto st61;
	goto tr50;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
	if ( (*p) == 101 )
		goto st62;
	goto tr50;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
	if ( (*p) == 101 )
		goto st63;
	goto tr50;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
	if ( (*p) == 110 )
		goto st64;
	goto tr50;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
	if ( (*p) == 100 )
		goto tr67;
	goto tr50;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
	if ( (*p) == 98 )
		goto st66;
	goto tr50;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
	if ( (*p) == 115 )
		goto st67;
	goto tr50;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
	if ( (*p) == 116 )
		goto st68;
	goto tr50;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
	if ( (*p) == 105 )
		goto st69;
	goto tr50;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
	if ( (*p) == 116 )
		goto st70;
	goto tr50;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
	if ( (*p) == 117 )
		goto st71;
	goto tr50;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
	if ( (*p) == 116 )
		goto st72;
	goto tr50;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
	if ( (*p) == 101 )
		goto st73;
	goto tr50;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
	if ( (*p) == 101 )
		goto st74;
	goto tr50;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
	if ( (*p) == 110 )
		goto st75;
	goto tr50;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
	if ( (*p) == 100 )
		goto tr78;
	goto tr50;
	}
	_test_eof76: cs = 76; goto _test_eof; 
	_test_eof77: cs = 77; goto _test_eof; 
	_test_eof78: cs = 78; goto _test_eof; 
	_test_eof79: cs = 79; goto _test_eof; 
	_test_eof80: cs = 80; goto _test_eof; 
	_test_eof81: cs = 81; goto _test_eof; 
	_test_eof82: cs = 82; goto _test_eof; 
	_test_eof1: cs = 1; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof83: cs = 83; goto _test_eof; 
	_test_eof84: cs = 84; goto _test_eof; 
	_test_eof85: cs = 85; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
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
	_test_eof86: cs = 86; goto _test_eof; 
	_test_eof30: cs = 30; goto _test_eof; 
	_test_eof31: cs = 31; goto _test_eof; 
	_test_eof32: cs = 32; goto _test_eof; 
	_test_eof33: cs = 33; goto _test_eof; 
	_test_eof34: cs = 34; goto _test_eof; 
	_test_eof35: cs = 35; goto _test_eof; 
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
	_test_eof87: cs = 87; goto _test_eof; 
	_test_eof88: cs = 88; goto _test_eof; 
	_test_eof48: cs = 48; goto _test_eof; 
	_test_eof89: cs = 89; goto _test_eof; 
	_test_eof49: cs = 49; goto _test_eof; 
	_test_eof50: cs = 50; goto _test_eof; 
	_test_eof51: cs = 51; goto _test_eof; 
	_test_eof52: cs = 52; goto _test_eof; 
	_test_eof53: cs = 53; goto _test_eof; 
	_test_eof54: cs = 54; goto _test_eof; 
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

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 77: goto tr83;
	case 78: goto tr83;
	case 79: goto tr83;
	case 80: goto tr83;
	case 81: goto tr83;
	case 82: goto tr83;
	case 1: goto tr0;
	case 2: goto tr0;
	case 3: goto tr0;
	case 4: goto tr0;
	case 5: goto tr0;
	case 6: goto tr0;
	case 7: goto tr0;
	case 8: goto tr0;
	case 9: goto tr0;
	case 10: goto tr0;
	case 11: goto tr0;
	case 83: goto tr83;
	case 84: goto tr83;
	case 85: goto tr83;
	case 12: goto tr0;
	case 13: goto tr0;
	case 14: goto tr0;
	case 15: goto tr0;
	case 16: goto tr0;
	case 17: goto tr0;
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
	case 86: goto tr83;
	case 30: goto tr0;
	case 31: goto tr0;
	case 32: goto tr0;
	case 33: goto tr0;
	case 34: goto tr0;
	case 35: goto tr0;
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
	case 88: goto tr96;
	case 89: goto tr97;
	case 49: goto tr50;
	case 50: goto tr50;
	case 51: goto tr50;
	case 52: goto tr50;
	case 53: goto tr50;
	case 54: goto tr50;
	case 55: goto tr50;
	case 56: goto tr50;
	case 57: goto tr50;
	case 58: goto tr50;
	case 59: goto tr50;
	case 60: goto tr50;
	case 61: goto tr50;
	case 62: goto tr50;
	case 63: goto tr50;
	case 64: goto tr50;
	case 65: goto tr50;
	case 66: goto tr50;
	case 67: goto tr50;
	case 68: goto tr50;
	case 69: goto tr50;
	case 70: goto tr50;
	case 71: goto tr50;
	case 72: goto tr50;
	case 73: goto tr50;
	case 74: goto tr50;
	case 75: goto tr50;
	}
	}

	_out: {}
	}

#line 113 "postprocess.rl"

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

