#line 1 "mfilescanner.rl"
#include "mfilescanner.h"

#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
extern "C" {
#include <unistd.h>
}

using std::cerr;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::set;
using std::istream;


#line 24 "mfilescanner.cc"
static const int MFileScanner_start = 288;
static const int MFileScanner_first_final = 288;
static const int MFileScanner_error = 0;

static const int MFileScanner_en_in_comment_block = 289;
static const int MFileScanner_en_funcline = 290;
static const int MFileScanner_en_funcbody = 312;
static const int MFileScanner_en_fill_list = 315;
static const int MFileScanner_en_doxy_get_body = 318;
static const int MFileScanner_en_doxyfunction_garble = 326;
static const int MFileScanner_en_doxy_get_brief = 327;
static const int MFileScanner_en_doxyheader = 205;
static const int MFileScanner_en_expect_doxyblock = 220;
static const int MFileScanner_en_script = 221;
static const int MFileScanner_en_funct = 222;
static const int MFileScanner_en_main = 288;
static const int MFileScanner_en_doculine = 333;

#line 707 "mfilescanner.rl"



MFileScanner :: MFileScanner(istream & fin, const std::string & filename, bool latex_output) :
  fin_(fin), filename_(filename),
  latex_output_(latex_output), cscan_(filename_),
  fnname_(filename),
  line(1),
  ts(0), have(0), top(0),
  opt(false), new_syntax_(false), is_script_(false), is_first_function_(true)
{
  string::size_type found = fnname_.rfind("/");
  if(found != string::npos)
    fnname_ = fnname_.substr(found+1);
  for( std::string::size_type i = 0; i < fnname_.size(); ++i )
  {
    if(fnname_[i] == '@')
      fnname_[i] = '_';
    else if(fnname_[i] == '.')
      fnname_[i] = '_';
  }

  cscan_.execute();
};

int MFileScanner :: execute()
{
  std::ios::sync_with_stdio(false);

  
#line 74 "mfilescanner.cc"
	{
	cs = MFileScanner_start;
	top = 0;
	ts = 0;
	te = 0;
	act = 0;
	}
#line 737 "mfilescanner.rl"

  /* Do the first read. */
  bool done = false;
  while ( !done )
  {
    char *p = buf + have;
    char *tmp_p = p, *tmp_p2 = p, *tmp_p3 = p;
    string tmp_string;
    bool docline = false;
    bool latex_begin = true;
    int space = BUFSIZE - have;

    if ( space == 0 )
    {
      /* We filled up the buffer trying to scan a token. */
      cerr << "OUT OF BUFFER SPACE" << endl;
      exit(-1);
    }

    fin_.read( p, space );
    int len = fin_.gcount();
    char *pe = p + len;
    char *rpe = pe;
    char *eof = 0;

    /* If we see eof then append the EOF char. */
    if ( fin_.eof() )
    {
      char eof_c = *pe;
      *pe = '\n';
      pe++;
      *pe = eof_c;
      eof = pe;
      rpe = pe;

      done = true;
    }
    else
    {
      /* Find the last newline by searching backwards. This is where
       * we will stop processing on this iteration. */
      while ( pe >= p )
      {
        if( *pe != '\n')
          pe--;
        else
        {
          if(pe >= p+3
              && *(pe-1) == '.' && *(pe-2) == '.' && *(pe-3) == '.')
            pe-=3;
          else
            break;
        }
      }
    }

    
#line 140 "mfilescanner.cc"
	{
	if ( p == pe )
		goto _test_eof;
	goto _resume;

_again:
	switch ( cs ) {
		case 288: goto st288;
		case 1: goto st1;
		case 0: goto st0;
		case 2: goto st2;
		case 3: goto st3;
		case 4: goto st4;
		case 5: goto st5;
		case 6: goto st6;
		case 7: goto st7;
		case 8: goto st8;
		case 9: goto st9;
		case 10: goto st10;
		case 11: goto st11;
		case 205: goto st205;
		case 206: goto st206;
		case 207: goto st207;
		case 208: goto st208;
		case 209: goto st209;
		case 210: goto st210;
		case 211: goto st211;
		case 212: goto st212;
		case 213: goto st213;
		case 214: goto st214;
		case 215: goto st215;
		case 329: goto st329;
		case 216: goto st216;
		case 217: goto st217;
		case 218: goto st218;
		case 219: goto st219;
		case 220: goto st220;
		case 330: goto st330;
		case 221: goto st221;
		case 331: goto st331;
		case 222: goto st222;
		case 223: goto st223;
		case 224: goto st224;
		case 225: goto st225;
		case 226: goto st226;
		case 227: goto st227;
		case 228: goto st228;
		case 229: goto st229;
		case 230: goto st230;
		case 231: goto st231;
		case 232: goto st232;
		case 233: goto st233;
		case 234: goto st234;
		case 235: goto st235;
		case 236: goto st236;
		case 237: goto st237;
		case 238: goto st238;
		case 239: goto st239;
		case 240: goto st240;
		case 241: goto st241;
		case 332: goto st332;
		case 242: goto st242;
		case 243: goto st243;
		case 244: goto st244;
		case 245: goto st245;
		case 246: goto st246;
		case 247: goto st247;
		case 248: goto st248;
		case 249: goto st249;
		case 250: goto st250;
		case 251: goto st251;
		case 252: goto st252;
		case 253: goto st253;
		case 254: goto st254;
		case 255: goto st255;
		case 256: goto st256;
		case 257: goto st257;
		case 258: goto st258;
		case 259: goto st259;
		case 260: goto st260;
		case 261: goto st261;
		case 262: goto st262;
		case 263: goto st263;
		case 264: goto st264;
		case 265: goto st265;
		case 266: goto st266;
		case 267: goto st267;
		case 268: goto st268;
		case 269: goto st269;
		case 270: goto st270;
		case 271: goto st271;
		case 272: goto st272;
		case 273: goto st273;
		case 274: goto st274;
		case 275: goto st275;
		case 276: goto st276;
		case 277: goto st277;
		case 278: goto st278;
		case 279: goto st279;
		case 280: goto st280;
		case 281: goto st281;
		case 282: goto st282;
		case 283: goto st283;
		case 284: goto st284;
		case 285: goto st285;
		case 286: goto st286;
		case 289: goto st289;
		case 12: goto st12;
		case 290: goto st290;
		case 291: goto st291;
		case 292: goto st292;
		case 293: goto st293;
		case 13: goto st13;
		case 294: goto st294;
		case 14: goto st14;
		case 15: goto st15;
		case 16: goto st16;
		case 295: goto st295;
		case 17: goto st17;
		case 296: goto st296;
		case 18: goto st18;
		case 19: goto st19;
		case 297: goto st297;
		case 298: goto st298;
		case 299: goto st299;
		case 300: goto st300;
		case 301: goto st301;
		case 302: goto st302;
		case 303: goto st303;
		case 304: goto st304;
		case 305: goto st305;
		case 306: goto st306;
		case 307: goto st307;
		case 308: goto st308;
		case 309: goto st309;
		case 310: goto st310;
		case 311: goto st311;
		case 20: goto st20;
		case 21: goto st21;
		case 22: goto st22;
		case 23: goto st23;
		case 24: goto st24;
		case 25: goto st25;
		case 26: goto st26;
		case 27: goto st27;
		case 312: goto st312;
		case 28: goto st28;
		case 313: goto st313;
		case 29: goto st29;
		case 30: goto st30;
		case 31: goto st31;
		case 32: goto st32;
		case 33: goto st33;
		case 314: goto st314;
		case 34: goto st34;
		case 35: goto st35;
		case 36: goto st36;
		case 37: goto st37;
		case 38: goto st38;
		case 39: goto st39;
		case 40: goto st40;
		case 41: goto st41;
		case 42: goto st42;
		case 43: goto st43;
		case 44: goto st44;
		case 45: goto st45;
		case 46: goto st46;
		case 47: goto st47;
		case 48: goto st48;
		case 49: goto st49;
		case 50: goto st50;
		case 51: goto st51;
		case 52: goto st52;
		case 53: goto st53;
		case 54: goto st54;
		case 55: goto st55;
		case 56: goto st56;
		case 57: goto st57;
		case 58: goto st58;
		case 59: goto st59;
		case 60: goto st60;
		case 61: goto st61;
		case 62: goto st62;
		case 63: goto st63;
		case 64: goto st64;
		case 65: goto st65;
		case 66: goto st66;
		case 67: goto st67;
		case 68: goto st68;
		case 69: goto st69;
		case 70: goto st70;
		case 71: goto st71;
		case 72: goto st72;
		case 73: goto st73;
		case 74: goto st74;
		case 75: goto st75;
		case 76: goto st76;
		case 315: goto st315;
		case 316: goto st316;
		case 317: goto st317;
		case 77: goto st77;
		case 78: goto st78;
		case 79: goto st79;
		case 80: goto st80;
		case 81: goto st81;
		case 82: goto st82;
		case 83: goto st83;
		case 84: goto st84;
		case 85: goto st85;
		case 86: goto st86;
		case 87: goto st87;
		case 318: goto st318;
		case 319: goto st319;
		case 320: goto st320;
		case 88: goto st88;
		case 321: goto st321;
		case 89: goto st89;
		case 90: goto st90;
		case 91: goto st91;
		case 92: goto st92;
		case 93: goto st93;
		case 94: goto st94;
		case 95: goto st95;
		case 96: goto st96;
		case 97: goto st97;
		case 98: goto st98;
		case 99: goto st99;
		case 100: goto st100;
		case 101: goto st101;
		case 102: goto st102;
		case 103: goto st103;
		case 104: goto st104;
		case 105: goto st105;
		case 106: goto st106;
		case 107: goto st107;
		case 108: goto st108;
		case 109: goto st109;
		case 110: goto st110;
		case 111: goto st111;
		case 112: goto st112;
		case 113: goto st113;
		case 114: goto st114;
		case 115: goto st115;
		case 116: goto st116;
		case 117: goto st117;
		case 118: goto st118;
		case 119: goto st119;
		case 120: goto st120;
		case 121: goto st121;
		case 122: goto st122;
		case 123: goto st123;
		case 124: goto st124;
		case 125: goto st125;
		case 126: goto st126;
		case 127: goto st127;
		case 128: goto st128;
		case 129: goto st129;
		case 130: goto st130;
		case 131: goto st131;
		case 132: goto st132;
		case 133: goto st133;
		case 134: goto st134;
		case 135: goto st135;
		case 136: goto st136;
		case 137: goto st137;
		case 138: goto st138;
		case 139: goto st139;
		case 140: goto st140;
		case 141: goto st141;
		case 142: goto st142;
		case 143: goto st143;
		case 144: goto st144;
		case 145: goto st145;
		case 146: goto st146;
		case 147: goto st147;
		case 148: goto st148;
		case 149: goto st149;
		case 150: goto st150;
		case 151: goto st151;
		case 152: goto st152;
		case 153: goto st153;
		case 154: goto st154;
		case 155: goto st155;
		case 156: goto st156;
		case 157: goto st157;
		case 158: goto st158;
		case 159: goto st159;
		case 160: goto st160;
		case 161: goto st161;
		case 162: goto st162;
		case 163: goto st163;
		case 164: goto st164;
		case 165: goto st165;
		case 166: goto st166;
		case 167: goto st167;
		case 168: goto st168;
		case 169: goto st169;
		case 170: goto st170;
		case 171: goto st171;
		case 172: goto st172;
		case 173: goto st173;
		case 174: goto st174;
		case 175: goto st175;
		case 176: goto st176;
		case 177: goto st177;
		case 178: goto st178;
		case 179: goto st179;
		case 180: goto st180;
		case 181: goto st181;
		case 182: goto st182;
		case 183: goto st183;
		case 184: goto st184;
		case 185: goto st185;
		case 186: goto st186;
		case 187: goto st187;
		case 188: goto st188;
		case 322: goto st322;
		case 189: goto st189;
		case 323: goto st323;
		case 324: goto st324;
		case 325: goto st325;
		case 190: goto st190;
		case 191: goto st191;
		case 192: goto st192;
		case 193: goto st193;
		case 326: goto st326;
		case 194: goto st194;
		case 195: goto st195;
		case 196: goto st196;
		case 197: goto st197;
		case 198: goto st198;
		case 199: goto st199;
		case 200: goto st200;
		case 201: goto st201;
		case 327: goto st327;
		case 328: goto st328;
		case 202: goto st202;
		case 203: goto st203;
		case 204: goto st204;
		case 333: goto st333;
		case 334: goto st334;
		case 287: goto st287;
		case 335: goto st335;
	default: break;
	}

	if ( ++p == pe )
		goto _test_eof;
_resume:
	switch ( cs )
	{
tr13:
#line 667 "mfilescanner.rl"
	{
    p=tmp_p;
    {goto st222;}
    }
	goto st288;
st288:
#line 1 "mfilescanner.rl"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof288;
case 288:
#line 505 "mfilescanner.cc"
	goto tr413;
tr2:
#line 29 "mfilescanner.rl"
	{line++;}
	goto st1;
tr413:
#line 661 "mfilescanner.rl"
	{ p--; tmp_p = p; }
	goto st1;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
#line 519 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st1;
		case 10: goto tr2;
		case 13: goto st2;
		case 32: goto st3;
		case 37: goto st4;
		case 102: goto st5;
	}
	goto tr0;
tr0:
#line 672 "mfilescanner.rl"
	{
    p=tmp_p;
    {goto st221;}
  }
	goto st0;
tr15:
#line 38 "mfilescanner.rl"
	{
    cout << "*/\n";
    p--;
    {cs = stack[--top];goto _again;}
  }
	goto st0;
tr265:
#line 571 "mfilescanner.rl"
	{
        p = tmp_p - 2;
        {goto st327;}
      }
	goto st0;
tr281:
#line 585 "mfilescanner.rl"
	{
    p--;
    {goto st312;}
  }
	goto st0;
#line 558 "mfilescanner.cc"
st0:
cs = 0;
	goto _out;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	if ( (*p) == 10 )
		goto tr2;
	goto tr0;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
	switch( (*p) ) {
		case 9: goto st3;
		case 10: goto tr2;
		case 13: goto st2;
		case 32: goto st3;
		case 37: goto st4;
	}
	goto tr0;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
	if ( (*p) == 10 )
		goto tr2;
	goto st4;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
	if ( (*p) == 117 )
		goto st6;
	goto tr0;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
	if ( (*p) == 110 )
		goto st7;
	goto tr0;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
	if ( (*p) == 99 )
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
	if ( (*p) == 105 )
		goto st10;
	goto tr0;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
	if ( (*p) == 111 )
		goto st11;
	goto tr0;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
	if ( (*p) == 110 )
		goto tr13;
	goto tr0;
st205:
#line 1 "mfilescanner.rl"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof205;
case 205:
#line 643 "mfilescanner.cc"
	if ( (*p) == 37 )
		goto st206;
	goto st0;
st206:
	if ( ++p == pe )
		goto _test_eof206;
case 206:
	switch( (*p) ) {
		case 9: goto st206;
		case 32: goto st206;
		case 102: goto st207;
	}
	goto tr265;
st207:
	if ( ++p == pe )
		goto _test_eof207;
case 207:
	if ( (*p) == 117 )
		goto st208;
	goto tr265;
st208:
	if ( ++p == pe )
		goto _test_eof208;
case 208:
	if ( (*p) == 110 )
		goto st209;
	goto tr265;
st209:
	if ( ++p == pe )
		goto _test_eof209;
case 209:
	if ( (*p) == 99 )
		goto st210;
	goto tr265;
st210:
	if ( ++p == pe )
		goto _test_eof210;
case 210:
	if ( (*p) == 116 )
		goto st211;
	goto tr265;
st211:
	if ( ++p == pe )
		goto _test_eof211;
case 211:
	if ( (*p) == 105 )
		goto st212;
	goto tr265;
st212:
	if ( ++p == pe )
		goto _test_eof212;
case 212:
	if ( (*p) == 111 )
		goto st213;
	goto tr265;
st213:
	if ( ++p == pe )
		goto _test_eof213;
case 213:
	if ( (*p) == 110 )
		goto st214;
	goto tr265;
st214:
	if ( ++p == pe )
		goto _test_eof214;
case 214:
	switch( (*p) ) {
		case 0: goto tr265;
		case 10: goto tr265;
		case 13: goto tr265;
		case 41: goto st215;
		case 46: goto st216;
		case 59: goto st215;
	}
	goto st214;
st215:
	if ( ++p == pe )
		goto _test_eof215;
case 215:
	switch( (*p) ) {
		case 0: goto tr265;
		case 10: goto tr276;
	}
	goto st215;
tr276:
#line 29 "mfilescanner.rl"
	{line++;}
#line 564 "mfilescanner.rl"
	{ {goto st327;} }
	goto st329;
tr279:
#line 29 "mfilescanner.rl"
	{line++;}
#line 567 "mfilescanner.rl"
	{ {goto st326;} }
	goto st329;
st329:
	if ( ++p == pe )
		goto _test_eof329;
case 329:
#line 744 "mfilescanner.cc"
	goto tr265;
st216:
	if ( ++p == pe )
		goto _test_eof216;
case 216:
	if ( (*p) == 46 )
		goto st217;
	goto tr265;
st217:
	if ( ++p == pe )
		goto _test_eof217;
case 217:
	if ( (*p) == 46 )
		goto st218;
	goto tr265;
st218:
	if ( ++p == pe )
		goto _test_eof218;
case 218:
	switch( (*p) ) {
		case 9: goto st218;
		case 10: goto tr279;
		case 13: goto st219;
		case 32: goto st218;
	}
	goto tr265;
st219:
	if ( ++p == pe )
		goto _test_eof219;
case 219:
	if ( (*p) == 10 )
		goto tr279;
	goto tr265;
st220:
#line 1 "mfilescanner.rl"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof220;
case 220:
#line 784 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st220;
		case 32: goto st220;
		case 37: goto tr283;
	}
	goto tr281;
tr283:
#line 75 "mfilescanner.rl"
	{ tmp_p = p + 1; }
#line 580 "mfilescanner.rl"
	{
        //cout << "/*";
        p--;
        {goto st205;}
      }
	goto st330;
st330:
	if ( ++p == pe )
		goto _test_eof330;
case 330:
#line 805 "mfilescanner.cc"
	goto tr281;
st221:
#line 1 "mfilescanner.rl"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof221;
case 221:
#line 813 "mfilescanner.cc"
	if ( (*p) == 0 )
		goto st0;
	goto tr284;
tr284:
#line 631 "mfilescanner.rl"
	{
       string :: size_type found = filename_.rfind("/");
       if(found == string :: npos)
         found = -1;
       string funcname = filename_.substr(found+1, filename_.size()-3-found);
       cfuncname_.assign( funcname );
       cout << "noret::substitute ";
       if(!is_first_function_)
         cout << "mtoc_subst_" << fnname_ << "_tsbus_cotm_";
       cout << funcname << "() {\n";
       is_script_ = true;
       p--;
       {goto st220;}
     }
	goto st331;
st331:
	if ( ++p == pe )
		goto _test_eof331;
case 331:
#line 838 "mfilescanner.cc"
	goto st0;
tr286:
#line 29 "mfilescanner.rl"
	{line++;}
	goto st222;
tr294:
#line 29 "mfilescanner.rl"
	{line++;}
#line 51 "mfilescanner.rl"
	{
    /*    cout << p << "x" << tmp_p << endl;*/
    cout.write(tmp_p, p-tmp_p+1);
    {stack[top++] = 222; goto st289;}
  }
	goto st222;
st222:
#line 1 "mfilescanner.rl"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof222;
case 222:
#line 860 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st222;
		case 10: goto tr286;
		case 13: goto st223;
		case 32: goto st224;
		case 37: goto st225;
		case 102: goto st227;
	}
	goto st0;
st223:
	if ( ++p == pe )
		goto _test_eof223;
case 223:
	if ( (*p) == 10 )
		goto tr286;
	goto st0;
st224:
	if ( ++p == pe )
		goto _test_eof224;
case 224:
	switch( (*p) ) {
		case 9: goto st224;
		case 10: goto tr286;
		case 13: goto st223;
		case 32: goto st224;
		case 37: goto st225;
	}
	goto st0;
st225:
	if ( ++p == pe )
		goto _test_eof225;
case 225:
	switch( (*p) ) {
		case 0: goto st0;
		case 124: goto tr292;
	}
	goto tr291;
tr291:
#line 69 "mfilescanner.rl"
	{ cout << "/*"; tmp_p = p; }
	goto st226;
tr292:
#line 67 "mfilescanner.rl"
	{ cout << "/**"; tmp_p = p+1; }
	goto st226;
st226:
	if ( ++p == pe )
		goto _test_eof226;
case 226:
#line 910 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr294;
	}
	goto st226;
st227:
	if ( ++p == pe )
		goto _test_eof227;
case 227:
	if ( (*p) == 117 )
		goto st228;
	goto st0;
st228:
	if ( ++p == pe )
		goto _test_eof228;
case 228:
	if ( (*p) == 110 )
		goto st229;
	goto st0;
st229:
	if ( ++p == pe )
		goto _test_eof229;
case 229:
	if ( (*p) == 99 )
		goto st230;
	goto st0;
st230:
	if ( ++p == pe )
		goto _test_eof230;
case 230:
	if ( (*p) == 116 )
		goto st231;
	goto st0;
st231:
	if ( ++p == pe )
		goto _test_eof231;
case 231:
	if ( (*p) == 105 )
		goto st232;
	goto st0;
st232:
	if ( ++p == pe )
		goto _test_eof232;
case 232:
	if ( (*p) == 111 )
		goto st233;
	goto st0;
st233:
	if ( ++p == pe )
		goto _test_eof233;
case 233:
	if ( (*p) == 110 )
		goto st234;
	goto st0;
tr310:
#line 29 "mfilescanner.rl"
	{line++;}
	goto st234;
tr307:
#line 29 "mfilescanner.rl"
	{line++;}
#line 79 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st234;
st234:
	if ( ++p == pe )
		goto _test_eof234;
case 234:
#line 982 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st234;
		case 32: goto st234;
		case 37: goto tr302;
		case 46: goto st236;
		case 91: goto tr305;
		case 95: goto tr304;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr304;
	} else if ( (*p) >= 65 )
		goto tr304;
	goto st0;
tr302:
#line 86 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st235;
st235:
	if ( ++p == pe )
		goto _test_eof235;
case 235:
#line 1005 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr307;
	}
	goto st235;
st236:
	if ( ++p == pe )
		goto _test_eof236;
case 236:
	if ( (*p) == 46 )
		goto st237;
	goto st0;
st237:
	if ( ++p == pe )
		goto _test_eof237;
case 237:
	if ( (*p) == 46 )
		goto st238;
	goto st0;
st238:
	if ( ++p == pe )
		goto _test_eof238;
case 238:
	switch( (*p) ) {
		case 9: goto st238;
		case 10: goto tr310;
		case 13: goto st239;
		case 32: goto st238;
	}
	goto st0;
st239:
	if ( ++p == pe )
		goto _test_eof239;
case 239:
	if ( (*p) == 10 )
		goto tr310;
	goto st0;
tr304:
#line 59 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st240;
st240:
	if ( ++p == pe )
		goto _test_eof240;
case 240:
#line 1051 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr312;
		case 10: goto tr313;
		case 13: goto tr314;
		case 32: goto tr312;
		case 37: goto tr315;
		case 40: goto tr316;
		case 46: goto tr317;
		case 59: goto tr319;
		case 61: goto tr320;
		case 95: goto st240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st240;
	} else
		goto st240;
	goto st0;
tr312:
#line 127 "mfilescanner.rl"
	{
             string s(tmp_p, p - tmp_p);
             returnlist_.push_back(s);
             return_list_[s] = DocuBlock();
             cout << "ret::substitutestart::" << s << "::retsubstituteend ";
           }
#line 57 "mfilescanner.rl"
	{ cout << (*p); }
#line 595 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
	goto st241;
tr321:
#line 57 "mfilescanner.rl"
	{ cout << (*p); }
	goto st241;
st241:
	if ( ++p == pe )
		goto _test_eof241;
case 241:
#line 1097 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr321;
		case 10: goto tr322;
		case 13: goto st242;
		case 32: goto tr321;
		case 37: goto tr324;
		case 40: goto tr325;
		case 46: goto st267;
		case 59: goto st271;
		case 61: goto tr328;
	}
	goto st0;
tr313:
#line 595 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
#line 29 "mfilescanner.rl"
	{line++;}
#line 620 "mfilescanner.rl"
	{
                         cout << "noret::substitute ";
                         if(!is_first_function_)
                           cout << "mtoc_subst_" << fnname_ << "_tsbus_cotm_";
                         cout << cfuncname_ << "() {\n";
                         {goto st220;}
                        }
	goto st332;
tr322:
#line 29 "mfilescanner.rl"
	{line++;}
#line 620 "mfilescanner.rl"
	{
                         cout << "noret::substitute ";
                         if(!is_first_function_)
                           cout << "mtoc_subst_" << fnname_ << "_tsbus_cotm_";
                         cout << cfuncname_ << "() {\n";
                         {goto st220;}
                        }
	goto st332;
tr342:
#line 29 "mfilescanner.rl"
	{line++;}
#line 616 "mfilescanner.rl"
	{
             cout << " {\n";
             {goto st220;}
           }
	goto st332;
st332:
	if ( ++p == pe )
		goto _test_eof332;
case 332:
#line 1152 "mfilescanner.cc"
	goto st0;
tr314:
#line 595 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
	goto st242;
st242:
	if ( ++p == pe )
		goto _test_eof242;
case 242:
#line 1165 "mfilescanner.cc"
	if ( (*p) == 10 )
		goto tr322;
	goto st0;
tr324:
#line 86 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st243;
tr315:
#line 595 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
#line 86 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st243;
st243:
	if ( ++p == pe )
		goto _test_eof243;
case 243:
#line 1186 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr330;
	}
	goto st243;
tr379:
#line 29 "mfilescanner.rl"
	{line++;}
	goto st244;
tr330:
#line 29 "mfilescanner.rl"
	{line++;}
#line 79 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st244;
tr390:
#line 595 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
	goto st244;
st244:
	if ( ++p == pe )
		goto _test_eof244;
case 244:
#line 1216 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st244;
		case 10: goto tr322;
		case 13: goto st242;
		case 32: goto st244;
		case 37: goto tr324;
		case 40: goto tr325;
		case 46: goto st267;
		case 59: goto st271;
	}
	goto st0;
tr354:
#line 29 "mfilescanner.rl"
	{line++;}
	goto st245;
tr340:
#line 29 "mfilescanner.rl"
	{line++;}
#line 79 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st245;
tr316:
#line 595 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
#line 603 "mfilescanner.rl"
	{
                 if(!opt)
                 {
                   cout << "noret::substitute ";
                   opt=false;
                 }
                 if(!is_first_function_)
                   cout << "mtoc_subst_" << fnname_ << "_tsbus_cotm_";
                 cout << cfuncname_ << '(';
                 }
	goto st245;
tr333:
#line 57 "mfilescanner.rl"
	{ cout << (*p); }
	goto st245;
tr325:
#line 603 "mfilescanner.rl"
	{
                 if(!opt)
                 {
                   cout << "noret::substitute ";
                   opt=false;
                 }
                 if(!is_first_function_)
                   cout << "mtoc_subst_" << fnname_ << "_tsbus_cotm_";
                 cout << cfuncname_ << '(';
                 }
	goto st245;
tr363:
#line 29 "mfilescanner.rl"
	{line++;}
#line 79 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 57 "mfilescanner.rl"
	{ cout << (*p); }
	goto st245;
tr370:
#line 100 "mfilescanner.rl"
	{
         string s(tmp_p, p - tmp_p);
         param_list_[s] = DocuBlock();
         paramlist_.push_back(s);
         cout << "matlabtypesubstitute " << s;
       }
	goto st245;
tr371:
#line 100 "mfilescanner.rl"
	{
         string s(tmp_p, p - tmp_p);
         param_list_[s] = DocuBlock();
         paramlist_.push_back(s);
         cout << "matlabtypesubstitute " << s;
       }
#line 57 "mfilescanner.rl"
	{ cout << (*p); }
	goto st245;
st245:
	if ( ++p == pe )
		goto _test_eof245;
case 245:
#line 1311 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st245;
		case 10: goto tr333;
		case 32: goto st245;
		case 37: goto tr334;
		case 41: goto tr335;
		case 44: goto tr333;
		case 46: goto st254;
		case 61: goto st258;
		case 95: goto tr338;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr338;
	} else if ( (*p) >= 65 )
		goto tr338;
	goto st0;
tr334:
#line 86 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st246;
tr372:
#line 100 "mfilescanner.rl"
	{
         string s(tmp_p, p - tmp_p);
         param_list_[s] = DocuBlock();
         paramlist_.push_back(s);
         cout << "matlabtypesubstitute " << s;
       }
#line 86 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st246;
st246:
	if ( ++p == pe )
		goto _test_eof246;
case 246:
#line 1348 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr340;
	}
	goto st246;
tr350:
#line 29 "mfilescanner.rl"
	{line++;}
	goto st247;
tr347:
#line 29 "mfilescanner.rl"
	{line++;}
#line 79 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st247;
tr335:
#line 57 "mfilescanner.rl"
	{ cout << (*p); }
	goto st247;
tr373:
#line 100 "mfilescanner.rl"
	{
         string s(tmp_p, p - tmp_p);
         param_list_[s] = DocuBlock();
         paramlist_.push_back(s);
         cout << "matlabtypesubstitute " << s;
       }
#line 57 "mfilescanner.rl"
	{ cout << (*p); }
	goto st247;
st247:
	if ( ++p == pe )
		goto _test_eof247;
case 247:
#line 1386 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st247;
		case 10: goto tr342;
		case 13: goto st248;
		case 32: goto st247;
		case 37: goto tr344;
		case 46: goto st250;
		case 59: goto st247;
	}
	goto st0;
st248:
	if ( ++p == pe )
		goto _test_eof248;
case 248:
	if ( (*p) == 10 )
		goto tr342;
	goto st0;
tr344:
#line 86 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st249;
st249:
	if ( ++p == pe )
		goto _test_eof249;
case 249:
#line 1412 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr347;
	}
	goto st249;
st250:
	if ( ++p == pe )
		goto _test_eof250;
case 250:
	if ( (*p) == 46 )
		goto st251;
	goto st0;
st251:
	if ( ++p == pe )
		goto _test_eof251;
case 251:
	if ( (*p) == 46 )
		goto st252;
	goto st0;
st252:
	if ( ++p == pe )
		goto _test_eof252;
case 252:
	switch( (*p) ) {
		case 9: goto st252;
		case 10: goto tr350;
		case 13: goto st253;
		case 32: goto st252;
	}
	goto st0;
st253:
	if ( ++p == pe )
		goto _test_eof253;
case 253:
	if ( (*p) == 10 )
		goto tr350;
	goto st0;
tr374:
#line 100 "mfilescanner.rl"
	{
         string s(tmp_p, p - tmp_p);
         param_list_[s] = DocuBlock();
         paramlist_.push_back(s);
         cout << "matlabtypesubstitute " << s;
       }
	goto st254;
st254:
	if ( ++p == pe )
		goto _test_eof254;
case 254:
#line 1463 "mfilescanner.cc"
	if ( (*p) == 46 )
		goto st255;
	goto st0;
st255:
	if ( ++p == pe )
		goto _test_eof255;
case 255:
	if ( (*p) == 46 )
		goto st256;
	goto st0;
st256:
	if ( ++p == pe )
		goto _test_eof256;
case 256:
	switch( (*p) ) {
		case 9: goto st256;
		case 10: goto tr354;
		case 13: goto st257;
		case 32: goto st256;
	}
	goto st0;
st257:
	if ( ++p == pe )
		goto _test_eof257;
case 257:
	if ( (*p) == 10 )
		goto tr354;
	goto st0;
tr356:
#line 57 "mfilescanner.rl"
	{ cout << (*p); }
	goto st258;
tr360:
#line 29 "mfilescanner.rl"
	{line++;}
#line 79 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 57 "mfilescanner.rl"
	{ cout << (*p); }
	goto st258;
tr368:
#line 29 "mfilescanner.rl"
	{line++;}
#line 57 "mfilescanner.rl"
	{ cout << (*p); }
	goto st258;
tr376:
#line 100 "mfilescanner.rl"
	{
         string s(tmp_p, p - tmp_p);
         param_list_[s] = DocuBlock();
         paramlist_.push_back(s);
         cout << "matlabtypesubstitute " << s;
       }
	goto st258;
st258:
	if ( ++p == pe )
		goto _test_eof258;
case 258:
#line 1526 "mfilescanner.cc"
	switch( (*p) ) {
		case 37: goto tr357;
		case 41: goto tr335;
		case 44: goto tr333;
		case 46: goto tr358;
	}
	goto tr356;
tr359:
#line 57 "mfilescanner.rl"
	{ cout << (*p); }
	goto st259;
tr357:
#line 57 "mfilescanner.rl"
	{ cout << (*p); }
#line 86 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st259;
st259:
	if ( ++p == pe )
		goto _test_eof259;
case 259:
#line 1548 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr356;
		case 10: goto tr360;
		case 37: goto tr357;
		case 41: goto st246;
		case 44: goto tr361;
	}
	goto tr359;
tr361:
#line 57 "mfilescanner.rl"
	{ cout << (*p); }
	goto st260;
st260:
	if ( ++p == pe )
		goto _test_eof260;
case 260:
#line 1565 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st260;
		case 10: goto tr363;
		case 32: goto st260;
		case 37: goto tr334;
		case 44: goto tr361;
		case 61: goto st259;
	}
	goto st246;
tr358:
#line 57 "mfilescanner.rl"
	{ cout << (*p); }
	goto st261;
st261:
	if ( ++p == pe )
		goto _test_eof261;
case 261:
#line 1584 "mfilescanner.cc"
	switch( (*p) ) {
		case 37: goto tr357;
		case 41: goto tr335;
		case 44: goto tr333;
		case 46: goto tr365;
	}
	goto tr356;
tr365:
#line 57 "mfilescanner.rl"
	{ cout << (*p); }
	goto st262;
st262:
	if ( ++p == pe )
		goto _test_eof262;
case 262:
#line 1600 "mfilescanner.cc"
	switch( (*p) ) {
		case 37: goto tr357;
		case 41: goto tr335;
		case 44: goto tr333;
		case 46: goto tr366;
	}
	goto tr356;
tr366:
#line 57 "mfilescanner.rl"
	{ cout << (*p); }
	goto st263;
st263:
	if ( ++p == pe )
		goto _test_eof263;
case 263:
#line 1616 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr367;
		case 10: goto tr368;
		case 13: goto tr369;
		case 32: goto tr367;
		case 37: goto tr357;
		case 41: goto tr335;
		case 44: goto tr333;
		case 46: goto tr366;
	}
	goto tr356;
tr367:
#line 57 "mfilescanner.rl"
	{ cout << (*p); }
	goto st264;
st264:
	if ( ++p == pe )
		goto _test_eof264;
case 264:
#line 1636 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr367;
		case 10: goto tr368;
		case 13: goto tr369;
		case 32: goto tr367;
		case 37: goto tr357;
		case 41: goto tr335;
		case 44: goto tr333;
		case 46: goto tr358;
	}
	goto tr356;
tr369:
#line 57 "mfilescanner.rl"
	{ cout << (*p); }
	goto st265;
st265:
	if ( ++p == pe )
		goto _test_eof265;
case 265:
#line 1656 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr368;
		case 37: goto tr357;
		case 41: goto tr335;
		case 44: goto tr333;
		case 46: goto tr358;
	}
	goto tr356;
tr338:
#line 59 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st266;
st266:
	if ( ++p == pe )
		goto _test_eof266;
case 266:
#line 1673 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr370;
		case 10: goto tr371;
		case 32: goto tr370;
		case 37: goto tr372;
		case 41: goto tr373;
		case 44: goto tr371;
		case 46: goto tr374;
		case 61: goto tr376;
		case 95: goto st266;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st266;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st266;
	} else
		goto st266;
	goto st0;
tr317:
#line 595 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
	goto st267;
st267:
	if ( ++p == pe )
		goto _test_eof267;
case 267:
#line 1705 "mfilescanner.cc"
	if ( (*p) == 46 )
		goto st268;
	goto st0;
st268:
	if ( ++p == pe )
		goto _test_eof268;
case 268:
	if ( (*p) == 46 )
		goto st269;
	goto st0;
st269:
	if ( ++p == pe )
		goto _test_eof269;
case 269:
	switch( (*p) ) {
		case 9: goto st269;
		case 10: goto tr379;
		case 13: goto st270;
		case 32: goto st269;
	}
	goto st0;
st270:
	if ( ++p == pe )
		goto _test_eof270;
case 270:
	if ( (*p) == 10 )
		goto tr379;
	goto st0;
tr319:
#line 595 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
	goto st271;
st271:
	if ( ++p == pe )
		goto _test_eof271;
case 271:
#line 1745 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr322;
		case 13: goto st242;
	}
	goto st0;
tr320:
#line 127 "mfilescanner.rl"
	{
             string s(tmp_p, p - tmp_p);
             returnlist_.push_back(s);
             return_list_[s] = DocuBlock();
             cout << "ret::substitutestart::" << s << "::retsubstituteend ";
           }
#line 592 "mfilescanner.rl"
	{opt=true;}
	goto st272;
tr328:
#line 592 "mfilescanner.rl"
	{opt=true;}
	goto st272;
tr385:
#line 29 "mfilescanner.rl"
	{line++;}
#line 79 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 592 "mfilescanner.rl"
	{opt=true;}
	goto st272;
tr388:
#line 29 "mfilescanner.rl"
	{line++;}
#line 592 "mfilescanner.rl"
	{opt=true;}
	goto st272;
st272:
	if ( ++p == pe )
		goto _test_eof272;
case 272:
#line 1787 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr328;
		case 32: goto tr328;
		case 37: goto tr381;
		case 46: goto st274;
		case 95: goto tr383;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr383;
	} else if ( (*p) >= 65 )
		goto tr383;
	goto st0;
tr381:
#line 86 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st273;
st273:
	if ( ++p == pe )
		goto _test_eof273;
case 273:
#line 1809 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr385;
	}
	goto st273;
st274:
	if ( ++p == pe )
		goto _test_eof274;
case 274:
	if ( (*p) == 46 )
		goto st275;
	goto st0;
st275:
	if ( ++p == pe )
		goto _test_eof275;
case 275:
	if ( (*p) == 46 )
		goto st276;
	goto st0;
st276:
	if ( ++p == pe )
		goto _test_eof276;
case 276:
	switch( (*p) ) {
		case 9: goto st276;
		case 10: goto tr388;
		case 13: goto st277;
		case 32: goto st276;
	}
	goto st0;
st277:
	if ( ++p == pe )
		goto _test_eof277;
case 277:
	if ( (*p) == 10 )
		goto tr388;
	goto st0;
tr383:
#line 59 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st278;
st278:
	if ( ++p == pe )
		goto _test_eof278;
case 278:
#line 1855 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr390;
		case 10: goto tr313;
		case 13: goto tr314;
		case 32: goto tr390;
		case 37: goto tr315;
		case 40: goto tr316;
		case 46: goto tr317;
		case 59: goto tr319;
		case 95: goto st278;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st278;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st278;
	} else
		goto st278;
	goto st0;
tr402:
#line 29 "mfilescanner.rl"
	{line++;}
	goto st279;
tr305:
#line 134 "mfilescanner.rl"
	{cout << "rets::substitutestart::";}
	goto st279;
tr399:
#line 29 "mfilescanner.rl"
	{line++;}
#line 79 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st279;
tr394:
#line 110 "mfilescanner.rl"
	{ cout << "::"; }
	goto st279;
tr404:
#line 112 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            returnlist_.push_back(s);
            return_list_[s] = DocuBlock();
            cout << s;
          }
	goto st279;
tr406:
#line 112 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            returnlist_.push_back(s);
            return_list_[s] = DocuBlock();
            cout << s;
          }
#line 110 "mfilescanner.rl"
	{ cout << "::"; }
	goto st279;
st279:
	if ( ++p == pe )
		goto _test_eof279;
case 279:
#line 1921 "mfilescanner.cc"
	switch( (*p) ) {
		case 32: goto st279;
		case 37: goto tr393;
		case 44: goto tr394;
		case 46: goto st281;
		case 93: goto tr397;
		case 95: goto tr396;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto st279;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr396;
	} else
		goto tr396;
	goto st0;
tr393:
#line 86 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st280;
tr405:
#line 112 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            returnlist_.push_back(s);
            return_list_[s] = DocuBlock();
            cout << s;
          }
#line 86 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st280;
st280:
	if ( ++p == pe )
		goto _test_eof280;
case 280:
#line 1958 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr399;
	}
	goto st280;
tr407:
#line 112 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            returnlist_.push_back(s);
            return_list_[s] = DocuBlock();
            cout << s;
          }
	goto st281;
st281:
	if ( ++p == pe )
		goto _test_eof281;
case 281:
#line 1977 "mfilescanner.cc"
	if ( (*p) == 46 )
		goto st282;
	goto st0;
st282:
	if ( ++p == pe )
		goto _test_eof282;
case 282:
	if ( (*p) == 46 )
		goto st283;
	goto st0;
st283:
	if ( ++p == pe )
		goto _test_eof283;
case 283:
	switch( (*p) ) {
		case 9: goto st283;
		case 10: goto tr402;
		case 13: goto st284;
		case 32: goto st283;
	}
	goto st0;
st284:
	if ( ++p == pe )
		goto _test_eof284;
case 284:
	if ( (*p) == 10 )
		goto tr402;
	goto st0;
tr396:
#line 59 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st285;
st285:
	if ( ++p == pe )
		goto _test_eof285;
case 285:
#line 2014 "mfilescanner.cc"
	switch( (*p) ) {
		case 32: goto tr404;
		case 37: goto tr405;
		case 44: goto tr406;
		case 46: goto tr407;
		case 93: goto tr409;
		case 95: goto st285;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr404;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st285;
		} else if ( (*p) >= 65 )
			goto st285;
	} else
		goto st285;
	goto st0;
tr410:
#line 57 "mfilescanner.rl"
	{ cout << (*p); }
	goto st286;
tr397:
#line 136 "mfilescanner.rl"
	{cout << "::retssubstituteend ";}
	goto st286;
tr409:
#line 112 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            returnlist_.push_back(s);
            return_list_[s] = DocuBlock();
            cout << s;
          }
#line 136 "mfilescanner.rl"
	{cout << "::retssubstituteend ";}
	goto st286;
st286:
	if ( ++p == pe )
		goto _test_eof286;
case 286:
#line 2058 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr410;
		case 32: goto tr410;
		case 61: goto tr328;
	}
	goto st0;
tr16:
#line 29 "mfilescanner.rl"
	{line++;}
#line 36 "mfilescanner.rl"
	{ cout.write(tmp_p, p - tmp_p+1); }
	goto st289;
st289:
#line 1 "mfilescanner.rl"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof289;
case 289:
#line 2077 "mfilescanner.cc"
	if ( (*p) == 37 )
		goto tr414;
	goto tr15;
tr414:
#line 34 "mfilescanner.rl"
	{ tmp_p = p+1; cout << " *"; }
	goto st12;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
#line 2089 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr15;
		case 10: goto tr16;
	}
	goto st12;
tr17:
#line 280 "mfilescanner.rl"
	{{p = ((te))-1;}{ cout << (*p); }}
	goto st290;
tr19:
#line 29 "mfilescanner.rl"
	{line++;}
#line 79 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 151 "mfilescanner.rl"
	{te = p+1;}
	goto st290;
tr21:
#line 29 "mfilescanner.rl"
	{line++;}
#line 149 "mfilescanner.rl"
	{te = p+1;{ cout.write(ts, te-ts); }}
	goto st290;
tr23:
#line 271 "mfilescanner.rl"
	{{p = ((te))-1;}{ cout.write(ts, te-ts); }}
	goto st290;
tr25:
#line 198 "mfilescanner.rl"
	{{p = ((te))-1;}{
      string s(tmp_p, p - tmp_p+1);
      cout << tmp_string << "." << s;
      typedef DocuList :: iterator list_iterator;
      typedef DocuListMap :: iterator map_iterator;
      typedef DocuBlock :: iterator iterator;

      // check wether first IDENT is a parameter
      iterator it = find(paramlist_.begin(), paramlist_.end(), tmp_string);
      if(it != paramlist_.end())
      {
        // if it is a parameter ...
        // ... check wether its found field is still missing a DocuBlock in the
        // return, optional and the required list.
        bool missing = true;
        map_iterator rvoit = retval_list_.find(tmp_string);
        if(rvoit != retval_list_.end())
        {
          list_iterator lit = (*rvoit).second.find(s);
          if(lit != (*rvoit).second.end())
            missing = false;
        }
        map_iterator moit = optional_list_.find(tmp_string);
        if(moit != optional_list_.end())
        {
          list_iterator lit = (*moit).second.find(s);
          if(lit != (*moit).second.end())
            missing = false;
        }
        map_iterator roit = required_list_.find(tmp_string);
        if(roit != required_list_.end())
        {
          list_iterator lit = (*roit).second.find(s);
          if(lit != (*roit).second.end())
            missing = false;
        }
        // in case it IS missing, add an empty field to the required block.
        if(missing)
        {
          required_list_[tmp_string][s] = DocuBlock();
        }
      }
    }}
	goto st290;
tr28:
#line 160 "mfilescanner.rl"
	{te = p+1;{
      p--;
      string s(tmp_p, tmp_p2 - tmp_p);
      cout << tmp_string << "." << s << "=";
      typedef DocuList :: iterator list_iterator;
      typedef DocuListMap :: iterator map_iterator;
      typedef DocuBlock :: iterator iterator;

      // check wether first IDENT is a return value
      iterator it = find(returnlist_.begin(), returnlist_.end(), tmp_string);
      if(it != returnlist_.end())
      {
        // if it is a return value...
        // ... check wether its found field is still missing a DocuBlock in the
        // retval list.
        bool missing = true;
        map_iterator rvoit = retval_list_.find(tmp_string);
        if(rvoit != retval_list_.end())
        {
          list_iterator lit = (*rvoit).second.find(s);
          if(lit != (*rvoit).second.end())
            missing = false;
        }
        if(missing)
        {
          retval_list_[tmp_string][s] = DocuBlock();
        }
      }
    }}
	goto st290;
tr40:
#line 29 "mfilescanner.rl"
	{line++;}
#line 256 "mfilescanner.rl"
	{te = p+1;{
        string s;
        if(tmp_string.empty())
        {
          s.assign("@deprecated function deprecated\n");
        }
        else
        {
          s.assign("@deprecated method deprecated, use \'" + tmp_string + "\' instead.\n");
        }
        docuextra_.push_back(s);
        p--;
      }}
	goto st290;
tr415:
#line 280 "mfilescanner.rl"
	{te = p+1;{ cout << (*p); }}
	goto st290;
tr417:
#line 29 "mfilescanner.rl"
	{line++;}
#line 283 "mfilescanner.rl"
	{te = p+1;{ cout << (*p); {goto st312;} }}
	goto st290;
tr423:
#line 274 "mfilescanner.rl"
	{te = p+1;{ cout << '['; }}
	goto st290;
tr424:
#line 277 "mfilescanner.rl"
	{te = p+1;{ cout << ']'; }}
	goto st290;
tr425:
#line 146 "mfilescanner.rl"
	{te = p;p--;{ cout.write(ts, te-ts); }}
	goto st290;
tr426:
#line 280 "mfilescanner.rl"
	{te = p;p--;{ cout << (*p); }}
	goto st290;
tr428:
#line 271 "mfilescanner.rl"
	{te = p;p--;{ cout.write(ts, te-ts); }}
	goto st290;
tr430:
#line 198 "mfilescanner.rl"
	{te = p;p--;{
      string s(tmp_p, p - tmp_p+1);
      cout << tmp_string << "." << s;
      typedef DocuList :: iterator list_iterator;
      typedef DocuListMap :: iterator map_iterator;
      typedef DocuBlock :: iterator iterator;

      // check wether first IDENT is a parameter
      iterator it = find(paramlist_.begin(), paramlist_.end(), tmp_string);
      if(it != paramlist_.end())
      {
        // if it is a parameter ...
        // ... check wether its found field is still missing a DocuBlock in the
        // return, optional and the required list.
        bool missing = true;
        map_iterator rvoit = retval_list_.find(tmp_string);
        if(rvoit != retval_list_.end())
        {
          list_iterator lit = (*rvoit).second.find(s);
          if(lit != (*rvoit).second.end())
            missing = false;
        }
        map_iterator moit = optional_list_.find(tmp_string);
        if(moit != optional_list_.end())
        {
          list_iterator lit = (*moit).second.find(s);
          if(lit != (*moit).second.end())
            missing = false;
        }
        map_iterator roit = required_list_.find(tmp_string);
        if(roit != required_list_.end())
        {
          list_iterator lit = (*roit).second.find(s);
          if(lit != (*roit).second.end())
            missing = false;
        }
        // in case it IS missing, add an empty field to the required block.
        if(missing)
        {
          required_list_[tmp_string][s] = DocuBlock();
        }
      }
    }}
	goto st290;
st290:
#line 1 "mfilescanner.rl"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof290;
case 290:
#line 1 "mfilescanner.rl"
	{ts = p;}
#line 2300 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st291;
		case 10: goto tr417;
		case 13: goto st292;
		case 32: goto st291;
		case 37: goto tr419;
		case 46: goto tr420;
		case 95: goto tr421;
		case 100: goto tr422;
		case 123: goto tr423;
		case 125: goto tr424;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr421;
	} else if ( (*p) >= 65 )
		goto tr421;
	goto tr415;
st291:
	if ( ++p == pe )
		goto _test_eof291;
case 291:
	switch( (*p) ) {
		case 9: goto st291;
		case 32: goto st291;
	}
	goto tr425;
st292:
	if ( ++p == pe )
		goto _test_eof292;
case 292:
	if ( (*p) == 10 )
		goto tr417;
	goto tr426;
tr419:
#line 1 "mfilescanner.rl"
	{te = p+1;}
#line 151 "mfilescanner.rl"
	{ tmp_p = p + 1; }
	goto st293;
st293:
	if ( ++p == pe )
		goto _test_eof293;
case 293:
#line 2346 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr426;
		case 10: goto tr19;
	}
	goto st13;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	switch( (*p) ) {
		case 0: goto tr17;
		case 10: goto tr19;
	}
	goto st13;
tr420:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st294;
st294:
	if ( ++p == pe )
		goto _test_eof294;
case 294:
#line 2369 "mfilescanner.cc"
	if ( (*p) == 46 )
		goto st14;
	goto tr426;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
	if ( (*p) == 46 )
		goto st15;
	goto tr17;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
	switch( (*p) ) {
		case 9: goto st15;
		case 10: goto tr21;
		case 13: goto st16;
		case 32: goto st15;
	}
	goto tr17;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
	if ( (*p) == 10 )
		goto tr21;
	goto tr17;
tr421:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st295;
st295:
	if ( ++p == pe )
		goto _test_eof295;
case 295:
#line 2406 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr429;
		case 95: goto tr421;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr421;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr421;
	} else
		goto tr421;
	goto tr428;
tr429:
#line 155 "mfilescanner.rl"
	{tmp_string.assign(ts,p-ts);}
#line 192 "mfilescanner.rl"
	{tmp_string.assign(ts,p-ts);}
	goto st17;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
#line 2430 "mfilescanner.cc"
	if ( (*p) == 95 )
		goto tr24;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr24;
	} else if ( (*p) >= 65 )
		goto tr24;
	goto tr23;
tr24:
#line 1 "mfilescanner.rl"
	{te = p+1;}
#line 59 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st296;
tr432:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st296;
st296:
	if ( ++p == pe )
		goto _test_eof296;
case 296:
#line 2453 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr431;
		case 32: goto tr431;
		case 61: goto tr433;
		case 95: goto tr432;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr432;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr432;
	} else
		goto tr432;
	goto tr430;
tr431:
#line 157 "mfilescanner.rl"
	{tmp_p2 = p;}
	goto st18;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
#line 2477 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st18;
		case 32: goto st18;
		case 61: goto st19;
	}
	goto tr25;
tr433:
#line 157 "mfilescanner.rl"
	{tmp_p2 = p;}
	goto st19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
#line 2492 "mfilescanner.cc"
	if ( (*p) == 61 )
		goto tr25;
	goto tr28;
tr422:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st297;
st297:
	if ( ++p == pe )
		goto _test_eof297;
case 297:
#line 2504 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr429;
		case 95: goto tr421;
		case 105: goto tr434;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr421;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr421;
	} else
		goto tr421;
	goto tr428;
tr434:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st298;
st298:
	if ( ++p == pe )
		goto _test_eof298;
case 298:
#line 2527 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr429;
		case 95: goto tr421;
		case 115: goto tr435;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr421;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr421;
	} else
		goto tr421;
	goto tr428;
tr435:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st299;
st299:
	if ( ++p == pe )
		goto _test_eof299;
case 299:
#line 2550 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr429;
		case 95: goto tr421;
		case 112: goto tr436;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr421;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr421;
	} else
		goto tr421;
	goto tr428;
tr436:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st300;
st300:
	if ( ++p == pe )
		goto _test_eof300;
case 300:
#line 2573 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr429;
		case 95: goto tr437;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr421;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr421;
	} else
		goto tr421;
	goto tr428;
tr437:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st301;
st301:
	if ( ++p == pe )
		goto _test_eof301;
case 301:
#line 2595 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr429;
		case 95: goto tr421;
		case 100: goto tr438;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr421;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr421;
	} else
		goto tr421;
	goto tr428;
tr438:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st302;
st302:
	if ( ++p == pe )
		goto _test_eof302;
case 302:
#line 2618 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr429;
		case 95: goto tr421;
		case 101: goto tr439;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr421;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr421;
	} else
		goto tr421;
	goto tr428;
tr439:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st303;
st303:
	if ( ++p == pe )
		goto _test_eof303;
case 303:
#line 2641 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr429;
		case 95: goto tr421;
		case 112: goto tr440;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr421;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr421;
	} else
		goto tr421;
	goto tr428;
tr440:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st304;
st304:
	if ( ++p == pe )
		goto _test_eof304;
case 304:
#line 2664 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr429;
		case 95: goto tr421;
		case 114: goto tr441;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr421;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr421;
	} else
		goto tr421;
	goto tr428;
tr441:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st305;
st305:
	if ( ++p == pe )
		goto _test_eof305;
case 305:
#line 2687 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr429;
		case 95: goto tr421;
		case 101: goto tr442;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr421;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr421;
	} else
		goto tr421;
	goto tr428;
tr442:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st306;
st306:
	if ( ++p == pe )
		goto _test_eof306;
case 306:
#line 2710 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr429;
		case 95: goto tr421;
		case 99: goto tr443;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr421;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr421;
	} else
		goto tr421;
	goto tr428;
tr443:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st307;
st307:
	if ( ++p == pe )
		goto _test_eof307;
case 307:
#line 2733 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr429;
		case 95: goto tr421;
		case 97: goto tr444;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr421;
	} else if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr421;
	} else
		goto tr421;
	goto tr428;
tr444:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st308;
st308:
	if ( ++p == pe )
		goto _test_eof308;
case 308:
#line 2756 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr429;
		case 95: goto tr421;
		case 116: goto tr445;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr421;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr421;
	} else
		goto tr421;
	goto tr428;
tr445:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st309;
st309:
	if ( ++p == pe )
		goto _test_eof309;
case 309:
#line 2779 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr429;
		case 95: goto tr421;
		case 101: goto tr446;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr421;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr421;
	} else
		goto tr421;
	goto tr428;
tr446:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st310;
st310:
	if ( ++p == pe )
		goto _test_eof310;
case 310:
#line 2802 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr429;
		case 95: goto tr421;
		case 100: goto tr447;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr421;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr421;
	} else
		goto tr421;
	goto tr428;
tr447:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st311;
st311:
	if ( ++p == pe )
		goto _test_eof311;
case 311:
#line 2825 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st20;
		case 32: goto st20;
		case 40: goto st21;
		case 46: goto tr429;
		case 59: goto tr31;
		case 95: goto tr421;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr421;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr421;
	} else
		goto tr421;
	goto tr428;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
	switch( (*p) ) {
		case 9: goto st20;
		case 32: goto st20;
		case 40: goto st21;
		case 59: goto tr31;
	}
	goto tr23;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
	switch( (*p) ) {
		case 9: goto st21;
		case 32: goto st21;
		case 39: goto st22;
	}
	goto tr23;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
	switch( (*p) ) {
		case 10: goto tr23;
		case 39: goto tr34;
	}
	goto tr33;
tr33:
#line 59 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st23;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
#line 2881 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr23;
		case 39: goto tr36;
	}
	goto st23;
tr34:
#line 59 "mfilescanner.rl"
	{ tmp_p = p; }
#line 63 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st24;
tr36:
#line 63 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st24;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
#line 2901 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st24;
		case 32: goto st24;
		case 41: goto st25;
	}
	goto tr23;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
	switch( (*p) ) {
		case 9: goto st25;
		case 32: goto st25;
		case 59: goto st26;
	}
	goto tr23;
tr31:
#line 245 "mfilescanner.rl"
	{tmp_string.assign("");}
	goto st26;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
#line 2926 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st26;
		case 10: goto tr40;
		case 13: goto st27;
		case 32: goto st26;
	}
	goto tr23;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
	if ( (*p) == 10 )
		goto tr40;
	goto tr23;
tr45:
#line 29 "mfilescanner.rl"
	{line++;}
#line 311 "mfilescanner.rl"
	{te = p+1;{
          p = ts-1;
          {goto st290;}
        }}
	goto st312;
tr50:
#line 29 "mfilescanner.rl"
	{line++;}
#line 79 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 311 "mfilescanner.rl"
	{te = p+1;{
          p = ts-1;
          {goto st290;}
        }}
	goto st312;
tr54:
#line 311 "mfilescanner.rl"
	{{p = ((te))-1;}{
          p = ts-1;
          {goto st290;}
        }}
	goto st312;
tr56:
#line 29 "mfilescanner.rl"
	{line++;}
#line 304 "mfilescanner.rl"
	{te = p+1;{ cout << '\n'; }}
	goto st312;
tr63:
#line 29 "mfilescanner.rl"
	{line++;}
#line 297 "mfilescanner.rl"
	{te = p+1;{
          cout.write(tmp_p, p - tmp_p+1);
          {stack[top++] = 312; goto st289;}
        }}
	goto st312;
tr71:
#line 318 "mfilescanner.rl"
	{te = p+1;{
        p = ts-1;
        end_function();
        {goto st288;}
      }}
	goto st312;
tr101:
#line 291 "mfilescanner.rl"
	{te = p+1;{
          new_syntax_ = true;
          cout << "*/\n"; //cout << "add to special group */\n";
        }}
#line 29 "mfilescanner.rl"
	{line++;}
	goto st312;
tr448:
#line 324 "mfilescanner.rl"
	{te = p+1;}
	goto st312;
tr450:
#line 311 "mfilescanner.rl"
	{te = p;p--;{
          p = ts-1;
          {goto st290;}
        }}
	goto st312;
st312:
#line 1 "mfilescanner.rl"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof312;
case 312:
#line 1 "mfilescanner.rl"
	{ts = p;}
#line 3022 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr448;
		case 9: goto st35;
		case 10: goto tr56;
		case 13: goto st36;
		case 32: goto st35;
		case 37: goto st47;
		case 102: goto st39;
	}
	goto st28;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st313;
		case 10: goto tr45;
		case 13: goto st29;
		case 32: goto st313;
		case 37: goto tr47;
		case 46: goto st31;
	}
	goto st28;
st313:
	if ( ++p == pe )
		goto _test_eof313;
case 313:
	switch( (*p) ) {
		case 9: goto st313;
		case 32: goto st313;
	}
	goto tr450;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
	if ( (*p) == 10 )
		goto tr45;
	goto st0;
tr47:
#line 86 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st30;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
#line 3071 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr50;
	}
	goto st30;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st313;
		case 10: goto tr45;
		case 13: goto st29;
		case 32: goto st313;
		case 37: goto tr47;
		case 46: goto st32;
	}
	goto st28;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st313;
		case 10: goto tr45;
		case 13: goto st29;
		case 32: goto st313;
		case 37: goto tr47;
		case 46: goto st33;
	}
	goto st28;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr53;
		case 10: goto tr45;
		case 13: goto st29;
		case 32: goto tr53;
		case 37: goto tr47;
		case 46: goto st33;
	}
	goto st28;
tr53:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st314;
st314:
	if ( ++p == pe )
		goto _test_eof314;
case 314:
#line 3127 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr53;
		case 10: goto tr45;
		case 13: goto st34;
		case 32: goto tr53;
	}
	goto tr450;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
	if ( (*p) == 10 )
		goto tr45;
	goto tr54;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st35;
		case 10: goto tr56;
		case 13: goto st36;
		case 32: goto st35;
		case 37: goto st37;
		case 102: goto st39;
	}
	goto st28;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
	if ( (*p) == 10 )
		goto tr56;
	goto st0;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
	switch( (*p) ) {
		case 0: goto st0;
		case 124: goto tr61;
	}
	goto tr60;
tr60:
#line 69 "mfilescanner.rl"
	{ cout << "/*"; tmp_p = p; }
	goto st38;
tr61:
#line 67 "mfilescanner.rl"
	{ cout << "/**"; tmp_p = p+1; }
	goto st38;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
#line 3184 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr63;
	}
	goto st38;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st313;
		case 10: goto tr45;
		case 13: goto st29;
		case 32: goto st313;
		case 37: goto tr47;
		case 46: goto st31;
		case 117: goto st40;
	}
	goto st28;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st313;
		case 10: goto tr45;
		case 13: goto st29;
		case 32: goto st313;
		case 37: goto tr47;
		case 46: goto st31;
		case 110: goto st41;
	}
	goto st28;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st313;
		case 10: goto tr45;
		case 13: goto st29;
		case 32: goto st313;
		case 37: goto tr47;
		case 46: goto st31;
		case 99: goto st42;
	}
	goto st28;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st313;
		case 10: goto tr45;
		case 13: goto st29;
		case 32: goto st313;
		case 37: goto tr47;
		case 46: goto st31;
		case 116: goto st43;
	}
	goto st28;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st313;
		case 10: goto tr45;
		case 13: goto st29;
		case 32: goto st313;
		case 37: goto tr47;
		case 46: goto st31;
		case 105: goto st44;
	}
	goto st28;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st313;
		case 10: goto tr45;
		case 13: goto st29;
		case 32: goto st313;
		case 37: goto tr47;
		case 46: goto st31;
		case 111: goto st45;
	}
	goto st28;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st313;
		case 10: goto tr45;
		case 13: goto st29;
		case 32: goto st313;
		case 37: goto tr47;
		case 46: goto st31;
		case 110: goto st46;
	}
	goto st28;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
	switch( (*p) ) {
		case 0: goto st0;
		case 13: goto st0;
		case 32: goto tr71;
		case 37: goto st0;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st0;
	goto st28;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
	switch( (*p) ) {
		case 0: goto st0;
		case 32: goto tr72;
		case 124: goto tr61;
	}
	goto tr60;
tr72:
#line 69 "mfilescanner.rl"
	{ cout << "/*"; tmp_p = p; }
	goto st48;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
#line 3326 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr63;
		case 84: goto st49;
	}
	goto st38;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr63;
		case 79: goto st50;
	}
	goto st38;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr63;
		case 32: goto st51;
	}
	goto st38;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr63;
		case 66: goto st52;
	}
	goto st38;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr63;
		case 69: goto st53;
	}
	goto st38;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr63;
		case 32: goto st54;
	}
	goto st38;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr63;
		case 65: goto st55;
	}
	goto st38;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr63;
		case 68: goto st56;
	}
	goto st38;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr63;
		case 74: goto st57;
	}
	goto st38;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr63;
		case 85: goto st58;
	}
	goto st38;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr63;
		case 83: goto st59;
	}
	goto st38;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr63;
		case 84: goto st60;
	}
	goto st38;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr63;
		case 69: goto st61;
	}
	goto st38;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr63;
		case 68: goto st62;
	}
	goto st38;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr63;
		case 32: goto st63;
	}
	goto st38;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr63;
		case 84: goto st64;
	}
	goto st38;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr63;
		case 79: goto st65;
	}
	goto st38;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr63;
		case 32: goto st66;
	}
	goto st38;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr63;
		case 78: goto st67;
	}
	goto st38;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr63;
		case 69: goto st68;
	}
	goto st38;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr63;
		case 87: goto st69;
	}
	goto st38;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr63;
		case 32: goto st70;
	}
	goto st38;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr63;
		case 83: goto st71;
	}
	goto st38;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr63;
		case 89: goto st72;
	}
	goto st38;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr63;
		case 78: goto st73;
	}
	goto st38;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr63;
		case 84: goto st74;
	}
	goto st38;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr63;
		case 65: goto st75;
	}
	goto st38;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr63;
		case 88: goto st76;
	}
	goto st38;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr101;
	}
	goto st38;
tr102:
#line 1 "mfilescanner.rl"
	{	switch( act ) {
	case 0:
	{{goto st0;}}
	break;
	case 21:
	{{p = ((te))-1;}
      p =ts-1;
      // cout << "*/\n";
      {cs = stack[--top];goto _again;}
    }
	break;
	}
	}
	goto st315;
tr105:
#line 29 "mfilescanner.rl"
	{line++;}
#line 362 "mfilescanner.rl"
	{te = p+1;{ /*cout << "empty line\n";*/ {cs = stack[--top];goto _again;} }}
	goto st315;
tr110:
#line 29 "mfilescanner.rl"
	{line++;}
#line 354 "mfilescanner.rl"
	{te = p+1;{
      string s(tmp_p, p - tmp_p + 1);
      (*clist_)[tmp_string].push_back(s);
      /*cout << "add something results in\n" << (*clist_)[tmp_string];*/
    }}
	goto st315;
tr120:
#line 29 "mfilescanner.rl"
	{line++;}
#line 335 "mfilescanner.rl"
	{te = p+1;{
      tmp_string.assign(tmp_p3, tmp_p2 - tmp_p3);
      //    std::cout << tmp_string << '\n';
      (*clist_)[tmp_string].push_back(string(tmp_p+1, p - tmp_p));
    }}
	goto st315;
tr452:
#line 366 "mfilescanner.rl"
	{te = p+1;{
      p =ts-1;
      // cout << "*/\n";
      {cs = stack[--top];goto _again;}
    }}
	goto st315;
tr454:
#line 29 "mfilescanner.rl"
	{line++;}
#line 366 "mfilescanner.rl"
	{te = p+1;{
      p =ts-1;
      // cout << "*/\n";
      {cs = stack[--top];goto _again;}
    }}
	goto st315;
tr457:
#line 366 "mfilescanner.rl"
	{te = p;p--;{
      p =ts-1;
      // cout << "*/\n";
      {cs = stack[--top];goto _again;}
    }}
	goto st315;
st315:
#line 1 "mfilescanner.rl"
	{ts = 0;}
#line 1 "mfilescanner.rl"
	{act = 0;}
	if ( ++p == pe )
		goto _test_eof315;
case 315:
#line 1 "mfilescanner.rl"
	{ts = p;}
#line 3690 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr453;
		case 10: goto tr454;
		case 13: goto st317;
		case 32: goto tr453;
		case 37: goto tr456;
	}
	goto tr452;
tr453:
#line 1 "mfilescanner.rl"
	{te = p+1;}
#line 366 "mfilescanner.rl"
	{act = 21;}
	goto st316;
st316:
	if ( ++p == pe )
		goto _test_eof316;
case 316:
#line 3710 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr457;
		case 9: goto tr453;
		case 10: goto tr454;
		case 13: goto st317;
		case 32: goto tr453;
		case 37: goto tr456;
	}
	goto tr452;
st317:
	if ( ++p == pe )
		goto _test_eof317;
case 317:
	if ( (*p) == 10 )
		goto tr454;
	goto tr457;
tr456:
#line 75 "mfilescanner.rl"
	{ tmp_p = p + 1; }
	goto st77;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
#line 3735 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr102;
		case 9: goto st77;
		case 10: goto tr105;
		case 13: goto st82;
		case 32: goto st77;
		case 39: goto st83;
		case 58: goto tr102;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr108;
	} else if ( (*p) >= 65 )
		goto tr108;
	goto st78;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
	switch( (*p) ) {
		case 0: goto tr102;
		case 9: goto st79;
		case 10: goto tr110;
		case 13: goto st81;
		case 32: goto st79;
		case 58: goto tr102;
	}
	goto st78;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
	switch( (*p) ) {
		case 9: goto st79;
		case 10: goto tr110;
		case 13: goto st81;
		case 32: goto st79;
		case 58: goto tr102;
	}
	goto st80;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
	switch( (*p) ) {
		case 0: goto tr102;
		case 10: goto tr110;
	}
	goto st80;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
	if ( (*p) == 10 )
		goto tr110;
	goto tr102;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
	if ( (*p) == 10 )
		goto tr105;
	goto tr102;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
	switch( (*p) ) {
		case 0: goto tr102;
		case 9: goto st79;
		case 10: goto tr110;
		case 13: goto st81;
		case 32: goto st79;
		case 58: goto tr102;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr108;
	} else if ( (*p) >= 65 )
		goto tr108;
	goto st78;
tr108:
#line 332 "mfilescanner.rl"
	{tmp_p3 = p;}
	goto st84;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
#line 3825 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr102;
		case 9: goto tr113;
		case 10: goto tr110;
		case 13: goto st81;
		case 32: goto tr113;
		case 39: goto tr114;
		case 44: goto st84;
		case 46: goto st84;
		case 58: goto tr116;
		case 93: goto st84;
		case 95: goto st84;
		case 125: goto st84;
	}
	if ( (*p) < 48 ) {
		if ( 40 <= (*p) && (*p) <= 41 )
			goto st84;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 123 )
				goto st84;
		} else if ( (*p) >= 65 )
			goto st84;
	} else
		goto st84;
	goto st78;
tr113:
#line 332 "mfilescanner.rl"
	{tmp_p2 = p;}
	goto st85;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
#line 3860 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st85;
		case 10: goto tr110;
		case 13: goto st81;
		case 32: goto st85;
		case 58: goto tr118;
	}
	goto st80;
tr118:
#line 59 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st86;
tr116:
#line 332 "mfilescanner.rl"
	{tmp_p2 = p;}
#line 59 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st86;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
#line 3883 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr102;
		case 10: goto tr120;
	}
	goto st86;
tr114:
#line 332 "mfilescanner.rl"
	{tmp_p2 = p;}
	goto st87;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
#line 3897 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr102;
		case 9: goto st85;
		case 10: goto tr110;
		case 13: goto st81;
		case 32: goto st85;
		case 58: goto tr118;
	}
	goto st78;
tr121:
#line 490 "mfilescanner.rl"
	{{p = ((te))-1;}}
	goto st318;
tr124:
#line 445 "mfilescanner.rl"
	{{p = ((te))-1;}{
        if(!docline)
        {
          docline = true;
          tmp_p = p;
        }
      }}
	goto st318;
tr126:
#line 29 "mfilescanner.rl"
	{line++;}
#line 437 "mfilescanner.rl"
	{te = p+1;{
        /*cout << "*\n  ";*/
        docubody_.push_back("\n");
        docline = false;
      }}
	goto st318;
tr141:
#line 29 "mfilescanner.rl"
	{line++;}
#line 419 "mfilescanner.rl"
	{te = p+1;{
        clist_ = &param_list_;
        docline = false;
        {stack[top++] = 318; goto st315;}
      }}
	goto st318;
tr168:
#line 29 "mfilescanner.rl"
	{line++;}
#line 409 "mfilescanner.rl"
	{te = p+1;{
        clist_ = &(retval_list_[tmp_string]);
        docline = false;
        {stack[top++] = 318; goto st315;}
      }}
	goto st318;
tr194:
#line 29 "mfilescanner.rl"
	{line++;}
#line 396 "mfilescanner.rl"
	{te = p+1;{
        clist_ = &(optional_list_[tmp_string]);
        docline = false;
        {stack[top++] = 318; goto st315;}
      }}
	goto st318;
tr221:
#line 29 "mfilescanner.rl"
	{line++;}
#line 382 "mfilescanner.rl"
	{te = p+1;{
        //cout << tmp_string << '\n';
        clist_ = &(required_list_[tmp_string]);
        docline = false;
        {stack[top++] = 318; goto st315;}
      }}
	goto st318;
tr237:
#line 29 "mfilescanner.rl"
	{line++;}
#line 429 "mfilescanner.rl"
	{te = p+1;{
        clist_ = &return_list_;
        docline = false;
        {stack[top++] = 318; goto st315;}
      }}
	goto st318;
tr239:
#line 29 "mfilescanner.rl"
	{line++;}
#line 506 "mfilescanner.rl"
	{te = p+1;{
        // cout << "*/\n";
        if(! docline)
          {goto st312;}
        else
        {
          int offset = ( latex_begin ? 0 : 1 );
          docubody_.push_back(string(tmp_p+1, p - tmp_p - offset));
          docline = false;
        }
      }}
	goto st318;
tr240:
#line 480 "mfilescanner.rl"
	{{p = ((te))-1;}{
        if(!docline)
        {
          p = ts-1;
          {goto st312;}
        }
      }}
	goto st318;
tr241:
#line 29 "mfilescanner.rl"
	{line++;}
#line 494 "mfilescanner.rl"
	{te = p+1;{
        if(! docline)
          {goto st312;}
        else
        {
          docubody_.push_back("@par " + string(tmp_p+1, ts - tmp_p-1)+"\n");
          docline = false;
        }
      }}
	goto st318;
tr242:
#line 470 "mfilescanner.rl"
	{{p = ((te))-1;}{
        if(!docline)
        {
          p = ts-1;
          {goto st312;}
        }
      }}
	goto st318;
tr246:
#line 455 "mfilescanner.rl"
	{te = p+1;{
        if(!docline)
        {
          p = ts-1;
          {goto st312;}
        }
        string s;
        s.assign(tmp_p+1, ts - tmp_p-1);
        docubody_.push_back(s+"@sa ");
        tmp_p = p+1;
      }}
	goto st318;
tr463:
#line 470 "mfilescanner.rl"
	{te = p;p--;{
        if(!docline)
        {
          p = ts-1;
          {goto st312;}
        }
      }}
	goto st318;
tr464:
#line 490 "mfilescanner.rl"
	{te = p;p--;}
	goto st318;
tr465:
#line 445 "mfilescanner.rl"
	{te = p;p--;{
        if(!docline)
        {
          docline = true;
          tmp_p = p;
        }
      }}
	goto st318;
tr466:
#line 480 "mfilescanner.rl"
	{te = p;p--;{
        if(!docline)
        {
          p = ts-1;
          {goto st312;}
        }
      }}
	goto st318;
st318:
#line 1 "mfilescanner.rl"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof318;
case 318:
#line 1 "mfilescanner.rl"
	{ts = p;}
#line 4088 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr459;
		case 10: goto tr239;
		case 13: goto st188;
		case 32: goto tr459;
		case 37: goto tr123;
		case 58: goto tr461;
		case 83: goto st323;
		case 115: goto st323;
	}
	goto st319;
st319:
	if ( ++p == pe )
		goto _test_eof319;
case 319:
	switch( (*p) ) {
		case 0: goto tr463;
		case 13: goto tr463;
		case 32: goto tr463;
		case 37: goto tr463;
		case 58: goto tr463;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto tr463;
	goto st319;
tr459:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st320;
st320:
	if ( ++p == pe )
		goto _test_eof320;
case 320:
#line 4123 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st88;
		case 32: goto st88;
		case 37: goto tr123;
	}
	goto tr464;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
	switch( (*p) ) {
		case 9: goto st88;
		case 32: goto st88;
		case 37: goto tr123;
	}
	goto tr121;
tr123:
#line 1 "mfilescanner.rl"
	{te = p+1;}
#line 75 "mfilescanner.rl"
	{ tmp_p = p + 1; }
	goto st321;
st321:
	if ( ++p == pe )
		goto _test_eof321;
case 321:
#line 4150 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st89;
		case 10: goto tr126;
		case 13: goto st90;
		case 32: goto st89;
		case 65: goto st91;
		case 71: goto st102;
		case 79: goto st126;
		case 82: goto st149;
		case 97: goto st91;
		case 103: goto st102;
		case 111: goto st126;
		case 114: goto st149;
	}
	goto tr465;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
	switch( (*p) ) {
		case 9: goto st89;
		case 10: goto tr126;
		case 13: goto st90;
		case 32: goto st89;
		case 65: goto st91;
		case 71: goto st102;
		case 79: goto st126;
		case 82: goto st149;
		case 97: goto st91;
		case 103: goto st102;
		case 111: goto st126;
		case 114: goto st149;
	}
	goto tr124;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
	if ( (*p) == 10 )
		goto tr126;
	goto tr124;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
	switch( (*p) ) {
		case 82: goto st92;
		case 114: goto st92;
	}
	goto tr124;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	switch( (*p) ) {
		case 71: goto st93;
		case 103: goto st93;
	}
	goto tr124;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
	switch( (*p) ) {
		case 85: goto st94;
		case 117: goto st94;
	}
	goto tr124;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
	switch( (*p) ) {
		case 77: goto st95;
		case 109: goto st95;
	}
	goto tr124;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
	switch( (*p) ) {
		case 69: goto st96;
		case 101: goto st96;
	}
	goto tr124;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
	switch( (*p) ) {
		case 78: goto st97;
		case 110: goto st97;
	}
	goto tr124;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
	switch( (*p) ) {
		case 84: goto st98;
		case 116: goto st98;
	}
	goto tr124;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
	switch( (*p) ) {
		case 83: goto st99;
		case 115: goto st99;
	}
	goto tr124;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
	switch( (*p) ) {
		case 9: goto st99;
		case 32: goto st99;
		case 58: goto st100;
	}
	goto tr124;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
	switch( (*p) ) {
		case 9: goto st100;
		case 10: goto tr141;
		case 13: goto st101;
		case 32: goto st100;
	}
	goto tr124;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
	if ( (*p) == 10 )
		goto tr141;
	goto tr124;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
	switch( (*p) ) {
		case 69: goto st103;
		case 101: goto st103;
	}
	goto tr124;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
	switch( (*p) ) {
		case 78: goto st104;
		case 110: goto st104;
	}
	goto tr124;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
	switch( (*p) ) {
		case 69: goto st105;
		case 101: goto st105;
	}
	goto tr124;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
	switch( (*p) ) {
		case 82: goto st106;
		case 114: goto st106;
	}
	goto tr124;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
	switch( (*p) ) {
		case 65: goto st107;
		case 97: goto st107;
	}
	goto tr124;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
	switch( (*p) ) {
		case 84: goto st108;
		case 116: goto st108;
	}
	goto tr124;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
	switch( (*p) ) {
		case 69: goto st109;
		case 101: goto st109;
	}
	goto tr124;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
	switch( (*p) ) {
		case 68: goto st110;
		case 100: goto st110;
	}
	goto tr124;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
	if ( (*p) == 32 )
		goto st111;
	goto tr124;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
	switch( (*p) ) {
		case 70: goto st112;
		case 102: goto st112;
	}
	goto tr124;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
	switch( (*p) ) {
		case 73: goto st113;
		case 105: goto st113;
	}
	goto tr124;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
	switch( (*p) ) {
		case 69: goto st114;
		case 101: goto st114;
	}
	goto tr124;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
	switch( (*p) ) {
		case 76: goto st115;
		case 108: goto st115;
	}
	goto tr124;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
	switch( (*p) ) {
		case 68: goto st116;
		case 100: goto st116;
	}
	goto tr124;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
	switch( (*p) ) {
		case 83: goto st117;
		case 115: goto st117;
	}
	goto tr124;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
	if ( (*p) == 32 )
		goto st118;
	goto tr124;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
	switch( (*p) ) {
		case 79: goto st119;
		case 111: goto st119;
	}
	goto tr124;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
	switch( (*p) ) {
		case 70: goto st120;
		case 102: goto st120;
	}
	goto tr124;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
	if ( (*p) == 32 )
		goto st121;
	goto tr124;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
	if ( (*p) == 95 )
		goto tr162;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr162;
	} else if ( (*p) >= 65 )
		goto tr162;
	goto tr124;
tr162:
#line 59 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st122;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
#line 4477 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr163;
		case 32: goto tr163;
		case 58: goto tr165;
		case 95: goto st122;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st122;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st122;
	} else
		goto st122;
	goto tr124;
tr163:
#line 63 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st123;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
#line 4501 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st123;
		case 32: goto st123;
		case 58: goto st124;
	}
	goto tr124;
tr165:
#line 63 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st124;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
#line 4516 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st124;
		case 10: goto tr168;
		case 13: goto st125;
		case 32: goto st124;
	}
	goto tr124;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
	if ( (*p) == 10 )
		goto tr168;
	goto tr124;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
	switch( (*p) ) {
		case 80: goto st127;
		case 112: goto st127;
	}
	goto tr124;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
	switch( (*p) ) {
		case 84: goto st128;
		case 116: goto st128;
	}
	goto tr124;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
	switch( (*p) ) {
		case 73: goto st129;
		case 105: goto st129;
	}
	goto tr124;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	switch( (*p) ) {
		case 79: goto st130;
		case 111: goto st130;
	}
	goto tr124;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
	switch( (*p) ) {
		case 78: goto st131;
		case 110: goto st131;
	}
	goto tr124;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
	switch( (*p) ) {
		case 65: goto st132;
		case 97: goto st132;
	}
	goto tr124;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
	switch( (*p) ) {
		case 76: goto st133;
		case 108: goto st133;
	}
	goto tr124;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
	if ( (*p) == 32 )
		goto st134;
	goto tr124;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
	switch( (*p) ) {
		case 70: goto st135;
		case 102: goto st135;
	}
	goto tr124;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
	switch( (*p) ) {
		case 73: goto st136;
		case 105: goto st136;
	}
	goto tr124;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
	switch( (*p) ) {
		case 69: goto st137;
		case 101: goto st137;
	}
	goto tr124;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
	switch( (*p) ) {
		case 76: goto st138;
		case 108: goto st138;
	}
	goto tr124;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
	switch( (*p) ) {
		case 68: goto st139;
		case 100: goto st139;
	}
	goto tr124;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
	switch( (*p) ) {
		case 83: goto st140;
		case 115: goto st140;
	}
	goto tr124;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
	if ( (*p) == 32 )
		goto st141;
	goto tr124;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
	switch( (*p) ) {
		case 79: goto st142;
		case 111: goto st142;
	}
	goto tr124;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
	switch( (*p) ) {
		case 70: goto st143;
		case 102: goto st143;
	}
	goto tr124;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
	if ( (*p) == 32 )
		goto st144;
	goto tr124;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
	if ( (*p) == 95 )
		goto tr188;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr188;
	} else if ( (*p) >= 65 )
		goto tr188;
	goto tr124;
tr188:
#line 59 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st145;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
#line 4707 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr189;
		case 32: goto tr189;
		case 58: goto tr191;
		case 95: goto st145;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st145;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st145;
	} else
		goto st145;
	goto tr124;
tr189:
#line 63 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st146;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
#line 4731 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st146;
		case 32: goto st146;
		case 58: goto st147;
	}
	goto tr124;
tr191:
#line 63 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st147;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
#line 4746 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st147;
		case 10: goto tr194;
		case 13: goto st148;
		case 32: goto st147;
	}
	goto tr124;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
	if ( (*p) == 10 )
		goto tr194;
	goto tr124;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
	switch( (*p) ) {
		case 69: goto st150;
		case 101: goto st150;
	}
	goto tr124;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
	switch( (*p) ) {
		case 81: goto st151;
		case 84: goto st172;
		case 113: goto st151;
		case 116: goto st172;
	}
	goto tr124;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
	switch( (*p) ) {
		case 85: goto st152;
		case 117: goto st152;
	}
	goto tr124;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
	switch( (*p) ) {
		case 73: goto st153;
		case 105: goto st153;
	}
	goto tr124;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
	switch( (*p) ) {
		case 82: goto st154;
		case 114: goto st154;
	}
	goto tr124;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
	switch( (*p) ) {
		case 69: goto st155;
		case 101: goto st155;
	}
	goto tr124;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
	switch( (*p) ) {
		case 68: goto st156;
		case 100: goto st156;
	}
	goto tr124;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
	if ( (*p) == 32 )
		goto st157;
	goto tr124;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
	switch( (*p) ) {
		case 70: goto st158;
		case 102: goto st158;
	}
	goto tr124;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
	switch( (*p) ) {
		case 73: goto st159;
		case 105: goto st159;
	}
	goto tr124;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
	switch( (*p) ) {
		case 69: goto st160;
		case 101: goto st160;
	}
	goto tr124;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
	switch( (*p) ) {
		case 76: goto st161;
		case 108: goto st161;
	}
	goto tr124;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
	switch( (*p) ) {
		case 68: goto st162;
		case 100: goto st162;
	}
	goto tr124;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
	switch( (*p) ) {
		case 83: goto st163;
		case 115: goto st163;
	}
	goto tr124;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
	if ( (*p) == 32 )
		goto st164;
	goto tr124;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
	switch( (*p) ) {
		case 79: goto st165;
		case 111: goto st165;
	}
	goto tr124;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
	switch( (*p) ) {
		case 70: goto st166;
		case 102: goto st166;
	}
	goto tr124;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
	if ( (*p) == 32 )
		goto st167;
	goto tr124;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
	if ( (*p) == 95 )
		goto tr215;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr215;
	} else if ( (*p) >= 65 )
		goto tr215;
	goto tr124;
tr215:
#line 59 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st168;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
#line 4939 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr216;
		case 32: goto tr216;
		case 58: goto tr218;
		case 95: goto st168;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st168;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st168;
	} else
		goto st168;
	goto tr124;
tr216:
#line 63 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st169;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
#line 4963 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st169;
		case 32: goto st169;
		case 58: goto st170;
	}
	goto tr124;
tr218:
#line 63 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st170;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
#line 4978 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st170;
		case 10: goto tr221;
		case 13: goto st171;
		case 32: goto st170;
	}
	goto tr124;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
	if ( (*p) == 10 )
		goto tr221;
	goto tr124;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
	switch( (*p) ) {
		case 85: goto st173;
		case 117: goto st173;
	}
	goto tr124;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
	switch( (*p) ) {
		case 82: goto st174;
		case 114: goto st174;
	}
	goto tr124;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
	switch( (*p) ) {
		case 78: goto st175;
		case 110: goto st175;
	}
	goto tr124;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
	if ( (*p) == 32 )
		goto st176;
	goto tr124;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
	switch( (*p) ) {
		case 65: goto st177;
		case 97: goto st177;
	}
	goto tr124;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
	switch( (*p) ) {
		case 82: goto st178;
		case 114: goto st178;
	}
	goto tr124;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
	switch( (*p) ) {
		case 71: goto st179;
		case 103: goto st179;
	}
	goto tr124;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
	switch( (*p) ) {
		case 85: goto st180;
		case 117: goto st180;
	}
	goto tr124;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
	switch( (*p) ) {
		case 77: goto st181;
		case 109: goto st181;
	}
	goto tr124;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
	switch( (*p) ) {
		case 69: goto st182;
		case 101: goto st182;
	}
	goto tr124;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
	switch( (*p) ) {
		case 78: goto st183;
		case 110: goto st183;
	}
	goto tr124;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
	switch( (*p) ) {
		case 84: goto st184;
		case 116: goto st184;
	}
	goto tr124;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
	switch( (*p) ) {
		case 83: goto st185;
		case 115: goto st185;
	}
	goto tr124;
st185:
	if ( ++p == pe )
		goto _test_eof185;
case 185:
	switch( (*p) ) {
		case 9: goto st185;
		case 32: goto st185;
		case 58: goto st186;
	}
	goto tr124;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
	switch( (*p) ) {
		case 9: goto st186;
		case 10: goto tr237;
		case 13: goto st187;
		case 32: goto st186;
	}
	goto tr124;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
	if ( (*p) == 10 )
		goto tr237;
	goto tr124;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
	if ( (*p) == 10 )
		goto tr239;
	goto st0;
tr461:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st322;
st322:
	if ( ++p == pe )
		goto _test_eof322;
case 322:
#line 5151 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr241;
		case 13: goto st189;
	}
	goto tr466;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
	if ( (*p) == 10 )
		goto tr241;
	goto tr240;
st323:
	if ( ++p == pe )
		goto _test_eof323;
case 323:
	switch( (*p) ) {
		case 0: goto tr463;
		case 13: goto tr463;
		case 32: goto tr463;
		case 37: goto tr463;
		case 58: goto tr463;
		case 69: goto st324;
		case 101: goto st324;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto tr463;
	goto st319;
st324:
	if ( ++p == pe )
		goto _test_eof324;
case 324:
	switch( (*p) ) {
		case 0: goto tr463;
		case 13: goto tr463;
		case 32: goto tr463;
		case 37: goto tr463;
		case 58: goto tr463;
		case 69: goto tr469;
		case 101: goto tr469;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto tr463;
	goto st319;
tr469:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st325;
st325:
	if ( ++p == pe )
		goto _test_eof325;
case 325:
#line 5204 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr463;
		case 13: goto tr463;
		case 32: goto st190;
		case 37: goto tr463;
		case 58: goto tr463;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto tr463;
	goto st319;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
	switch( (*p) ) {
		case 65: goto st191;
		case 97: goto st191;
	}
	goto tr242;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
	switch( (*p) ) {
		case 76: goto st192;
		case 108: goto st192;
	}
	goto tr242;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
	switch( (*p) ) {
		case 83: goto st193;
		case 115: goto st193;
	}
	goto tr242;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
	switch( (*p) ) {
		case 79: goto tr246;
		case 111: goto tr246;
	}
	goto tr242;
tr250:
#line 29 "mfilescanner.rl"
	{line++;}
#line 526 "mfilescanner.rl"
	{te = p+1;{ {goto st327;} }}
	goto st326;
tr255:
#line 29 "mfilescanner.rl"
	{line++;}
#line 523 "mfilescanner.rl"
	{te = p+1;}
	goto st326;
st326:
#line 1 "mfilescanner.rl"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof326;
case 326:
#line 1 "mfilescanner.rl"
	{ts = p;}
#line 5271 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st194;
		case 32: goto st194;
		case 37: goto tr248;
	}
	goto st0;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
	switch( (*p) ) {
		case 9: goto st194;
		case 32: goto st194;
		case 37: goto tr248;
	}
	goto st0;
tr248:
#line 75 "mfilescanner.rl"
	{ tmp_p = p + 1; }
	goto st195;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
#line 5296 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr250;
		case 46: goto st196;
	}
	goto st195;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr250;
		case 46: goto st197;
	}
	goto st195;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr250;
		case 46: goto st198;
	}
	goto st195;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
	switch( (*p) ) {
		case 9: goto st199;
		case 10: goto tr255;
		case 13: goto st200;
		case 32: goto st199;
		case 46: goto st201;
	}
	goto st0;
st199:
	if ( ++p == pe )
		goto _test_eof199;
case 199:
	switch( (*p) ) {
		case 9: goto st199;
		case 10: goto tr255;
		case 13: goto st200;
		case 32: goto st199;
	}
	goto st0;
st200:
	if ( ++p == pe )
		goto _test_eof200;
case 200:
	if ( (*p) == 10 )
		goto tr255;
	goto st0;
st201:
	if ( ++p == pe )
		goto _test_eof201;
case 201:
	switch( (*p) ) {
		case 9: goto st199;
		case 10: goto tr255;
		case 13: goto st200;
		case 32: goto st199;
		case 46: goto st199;
	}
	goto st0;
tr258:
#line 1 "mfilescanner.rl"
	{	switch( act ) {
	case 0:
	{{goto st0;}}
	break;
	case 39:
	{{p = ((te))-1;}
        p--;
        //cout << "*/\n";
        {goto st312;}
      }
	break;
	}
	}
	goto st327;
tr261:
#line 29 "mfilescanner.rl"
	{line++;}
#line 543 "mfilescanner.rl"
	{te = p+1;{
        /*cout << "*\n";*/
        {goto st318;}
      }}
	goto st327;
tr263:
#line 29 "mfilescanner.rl"
	{line++;}
#line 536 "mfilescanner.rl"
	{te = p+1;{
        /* cout << "*"; cout.write(tmp_p, p - tmp_p+1); */
        docuheader_.push_back(string(tmp_p, p - tmp_p+1));
      }}
	goto st327;
tr471:
#line 550 "mfilescanner.rl"
	{te = p+1;{
        p--;
        //cout << "*/\n";
        {goto st312;}
      }}
	goto st327;
tr474:
#line 550 "mfilescanner.rl"
	{te = p;p--;{
        p--;
        //cout << "*/\n";
        {goto st312;}
      }}
	goto st327;
st327:
#line 1 "mfilescanner.rl"
	{ts = 0;}
#line 1 "mfilescanner.rl"
	{act = 0;}
	if ( ++p == pe )
		goto _test_eof327;
case 327:
#line 1 "mfilescanner.rl"
	{ts = p;}
#line 5425 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr472;
		case 32: goto tr472;
		case 37: goto tr473;
	}
	goto tr471;
tr472:
#line 1 "mfilescanner.rl"
	{te = p+1;}
#line 550 "mfilescanner.rl"
	{act = 39;}
	goto st328;
st328:
	if ( ++p == pe )
		goto _test_eof328;
case 328:
#line 5442 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr472;
		case 32: goto tr472;
		case 37: goto tr473;
	}
	goto tr471;
tr473:
#line 75 "mfilescanner.rl"
	{ tmp_p = p + 1; }
	goto st202;
st202:
	if ( ++p == pe )
		goto _test_eof202;
case 202:
#line 5457 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr258;
		case 9: goto st202;
		case 10: goto tr261;
		case 13: goto st204;
		case 32: goto st202;
	}
	goto st203;
st203:
	if ( ++p == pe )
		goto _test_eof203;
case 203:
	switch( (*p) ) {
		case 0: goto tr258;
		case 10: goto tr263;
	}
	goto st203;
st204:
	if ( ++p == pe )
		goto _test_eof204;
case 204:
	if ( (*p) == 10 )
		goto tr261;
	goto tr258;
tr412:
#line 683 "mfilescanner.rl"
	{te = p+1;{
    if(!latex_begin)
      cout << "<tt>";
    cout.write(ts+1, te-ts-2);
    if(!latex_begin)
      cout << "</tt>";
  }}
	goto st333;
tr477:
#line 681 "mfilescanner.rl"
	{te = p;p--;{ cout.write(ts, te-ts); }}
	goto st333;
tr478:
#line 705 "mfilescanner.rl"
	{te = p;p--;{ cout << "@f$"; }}
	goto st333;
tr479:
#line 692 "mfilescanner.rl"
	{te = p+1;{
    if(latex_begin)
    {
      cout << "@f[";
      latex_begin=false;
    }
    else
    {
      cout << "@f]";
      latex_begin=true;
    }
  }}
	goto st333;
st333:
#line 1 "mfilescanner.rl"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof333;
case 333:
#line 1 "mfilescanner.rl"
	{ts = p;}
#line 5523 "mfilescanner.cc"
	switch( (*p) ) {
		case 39: goto st287;
		case 96: goto st335;
	}
	goto st334;
st334:
	if ( ++p == pe )
		goto _test_eof334;
case 334:
	switch( (*p) ) {
		case 39: goto tr477;
		case 96: goto tr477;
	}
	goto st334;
st287:
	if ( ++p == pe )
		goto _test_eof287;
case 287:
	switch( (*p) ) {
		case 32: goto st287;
		case 36: goto st287;
		case 39: goto tr412;
		case 44: goto st287;
		case 93: goto st287;
		case 95: goto st287;
		case 125: goto st287;
	}
	if ( (*p) < 46 ) {
		if ( 40 <= (*p) && (*p) <= 41 )
			goto st287;
	} else if ( (*p) > 47 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 123 )
				goto st287;
		} else if ( (*p) >= 65 )
			goto st287;
	} else
		goto st287;
	goto st0;
st335:
	if ( ++p == pe )
		goto _test_eof335;
case 335:
	if ( (*p) == 96 )
		goto tr479;
	goto tr478;
	}
	_test_eof288: cs = 288; goto _test_eof; 
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
	_test_eof205: cs = 205; goto _test_eof; 
	_test_eof206: cs = 206; goto _test_eof; 
	_test_eof207: cs = 207; goto _test_eof; 
	_test_eof208: cs = 208; goto _test_eof; 
	_test_eof209: cs = 209; goto _test_eof; 
	_test_eof210: cs = 210; goto _test_eof; 
	_test_eof211: cs = 211; goto _test_eof; 
	_test_eof212: cs = 212; goto _test_eof; 
	_test_eof213: cs = 213; goto _test_eof; 
	_test_eof214: cs = 214; goto _test_eof; 
	_test_eof215: cs = 215; goto _test_eof; 
	_test_eof329: cs = 329; goto _test_eof; 
	_test_eof216: cs = 216; goto _test_eof; 
	_test_eof217: cs = 217; goto _test_eof; 
	_test_eof218: cs = 218; goto _test_eof; 
	_test_eof219: cs = 219; goto _test_eof; 
	_test_eof220: cs = 220; goto _test_eof; 
	_test_eof330: cs = 330; goto _test_eof; 
	_test_eof221: cs = 221; goto _test_eof; 
	_test_eof331: cs = 331; goto _test_eof; 
	_test_eof222: cs = 222; goto _test_eof; 
	_test_eof223: cs = 223; goto _test_eof; 
	_test_eof224: cs = 224; goto _test_eof; 
	_test_eof225: cs = 225; goto _test_eof; 
	_test_eof226: cs = 226; goto _test_eof; 
	_test_eof227: cs = 227; goto _test_eof; 
	_test_eof228: cs = 228; goto _test_eof; 
	_test_eof229: cs = 229; goto _test_eof; 
	_test_eof230: cs = 230; goto _test_eof; 
	_test_eof231: cs = 231; goto _test_eof; 
	_test_eof232: cs = 232; goto _test_eof; 
	_test_eof233: cs = 233; goto _test_eof; 
	_test_eof234: cs = 234; goto _test_eof; 
	_test_eof235: cs = 235; goto _test_eof; 
	_test_eof236: cs = 236; goto _test_eof; 
	_test_eof237: cs = 237; goto _test_eof; 
	_test_eof238: cs = 238; goto _test_eof; 
	_test_eof239: cs = 239; goto _test_eof; 
	_test_eof240: cs = 240; goto _test_eof; 
	_test_eof241: cs = 241; goto _test_eof; 
	_test_eof332: cs = 332; goto _test_eof; 
	_test_eof242: cs = 242; goto _test_eof; 
	_test_eof243: cs = 243; goto _test_eof; 
	_test_eof244: cs = 244; goto _test_eof; 
	_test_eof245: cs = 245; goto _test_eof; 
	_test_eof246: cs = 246; goto _test_eof; 
	_test_eof247: cs = 247; goto _test_eof; 
	_test_eof248: cs = 248; goto _test_eof; 
	_test_eof249: cs = 249; goto _test_eof; 
	_test_eof250: cs = 250; goto _test_eof; 
	_test_eof251: cs = 251; goto _test_eof; 
	_test_eof252: cs = 252; goto _test_eof; 
	_test_eof253: cs = 253; goto _test_eof; 
	_test_eof254: cs = 254; goto _test_eof; 
	_test_eof255: cs = 255; goto _test_eof; 
	_test_eof256: cs = 256; goto _test_eof; 
	_test_eof257: cs = 257; goto _test_eof; 
	_test_eof258: cs = 258; goto _test_eof; 
	_test_eof259: cs = 259; goto _test_eof; 
	_test_eof260: cs = 260; goto _test_eof; 
	_test_eof261: cs = 261; goto _test_eof; 
	_test_eof262: cs = 262; goto _test_eof; 
	_test_eof263: cs = 263; goto _test_eof; 
	_test_eof264: cs = 264; goto _test_eof; 
	_test_eof265: cs = 265; goto _test_eof; 
	_test_eof266: cs = 266; goto _test_eof; 
	_test_eof267: cs = 267; goto _test_eof; 
	_test_eof268: cs = 268; goto _test_eof; 
	_test_eof269: cs = 269; goto _test_eof; 
	_test_eof270: cs = 270; goto _test_eof; 
	_test_eof271: cs = 271; goto _test_eof; 
	_test_eof272: cs = 272; goto _test_eof; 
	_test_eof273: cs = 273; goto _test_eof; 
	_test_eof274: cs = 274; goto _test_eof; 
	_test_eof275: cs = 275; goto _test_eof; 
	_test_eof276: cs = 276; goto _test_eof; 
	_test_eof277: cs = 277; goto _test_eof; 
	_test_eof278: cs = 278; goto _test_eof; 
	_test_eof279: cs = 279; goto _test_eof; 
	_test_eof280: cs = 280; goto _test_eof; 
	_test_eof281: cs = 281; goto _test_eof; 
	_test_eof282: cs = 282; goto _test_eof; 
	_test_eof283: cs = 283; goto _test_eof; 
	_test_eof284: cs = 284; goto _test_eof; 
	_test_eof285: cs = 285; goto _test_eof; 
	_test_eof286: cs = 286; goto _test_eof; 
	_test_eof289: cs = 289; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof290: cs = 290; goto _test_eof; 
	_test_eof291: cs = 291; goto _test_eof; 
	_test_eof292: cs = 292; goto _test_eof; 
	_test_eof293: cs = 293; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof294: cs = 294; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof295: cs = 295; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof296: cs = 296; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof297: cs = 297; goto _test_eof; 
	_test_eof298: cs = 298; goto _test_eof; 
	_test_eof299: cs = 299; goto _test_eof; 
	_test_eof300: cs = 300; goto _test_eof; 
	_test_eof301: cs = 301; goto _test_eof; 
	_test_eof302: cs = 302; goto _test_eof; 
	_test_eof303: cs = 303; goto _test_eof; 
	_test_eof304: cs = 304; goto _test_eof; 
	_test_eof305: cs = 305; goto _test_eof; 
	_test_eof306: cs = 306; goto _test_eof; 
	_test_eof307: cs = 307; goto _test_eof; 
	_test_eof308: cs = 308; goto _test_eof; 
	_test_eof309: cs = 309; goto _test_eof; 
	_test_eof310: cs = 310; goto _test_eof; 
	_test_eof311: cs = 311; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof23: cs = 23; goto _test_eof; 
	_test_eof24: cs = 24; goto _test_eof; 
	_test_eof25: cs = 25; goto _test_eof; 
	_test_eof26: cs = 26; goto _test_eof; 
	_test_eof27: cs = 27; goto _test_eof; 
	_test_eof312: cs = 312; goto _test_eof; 
	_test_eof28: cs = 28; goto _test_eof; 
	_test_eof313: cs = 313; goto _test_eof; 
	_test_eof29: cs = 29; goto _test_eof; 
	_test_eof30: cs = 30; goto _test_eof; 
	_test_eof31: cs = 31; goto _test_eof; 
	_test_eof32: cs = 32; goto _test_eof; 
	_test_eof33: cs = 33; goto _test_eof; 
	_test_eof314: cs = 314; goto _test_eof; 
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
	_test_eof48: cs = 48; goto _test_eof; 
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
	_test_eof76: cs = 76; goto _test_eof; 
	_test_eof315: cs = 315; goto _test_eof; 
	_test_eof316: cs = 316; goto _test_eof; 
	_test_eof317: cs = 317; goto _test_eof; 
	_test_eof77: cs = 77; goto _test_eof; 
	_test_eof78: cs = 78; goto _test_eof; 
	_test_eof79: cs = 79; goto _test_eof; 
	_test_eof80: cs = 80; goto _test_eof; 
	_test_eof81: cs = 81; goto _test_eof; 
	_test_eof82: cs = 82; goto _test_eof; 
	_test_eof83: cs = 83; goto _test_eof; 
	_test_eof84: cs = 84; goto _test_eof; 
	_test_eof85: cs = 85; goto _test_eof; 
	_test_eof86: cs = 86; goto _test_eof; 
	_test_eof87: cs = 87; goto _test_eof; 
	_test_eof318: cs = 318; goto _test_eof; 
	_test_eof319: cs = 319; goto _test_eof; 
	_test_eof320: cs = 320; goto _test_eof; 
	_test_eof88: cs = 88; goto _test_eof; 
	_test_eof321: cs = 321; goto _test_eof; 
	_test_eof89: cs = 89; goto _test_eof; 
	_test_eof90: cs = 90; goto _test_eof; 
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
	_test_eof115: cs = 115; goto _test_eof; 
	_test_eof116: cs = 116; goto _test_eof; 
	_test_eof117: cs = 117; goto _test_eof; 
	_test_eof118: cs = 118; goto _test_eof; 
	_test_eof119: cs = 119; goto _test_eof; 
	_test_eof120: cs = 120; goto _test_eof; 
	_test_eof121: cs = 121; goto _test_eof; 
	_test_eof122: cs = 122; goto _test_eof; 
	_test_eof123: cs = 123; goto _test_eof; 
	_test_eof124: cs = 124; goto _test_eof; 
	_test_eof125: cs = 125; goto _test_eof; 
	_test_eof126: cs = 126; goto _test_eof; 
	_test_eof127: cs = 127; goto _test_eof; 
	_test_eof128: cs = 128; goto _test_eof; 
	_test_eof129: cs = 129; goto _test_eof; 
	_test_eof130: cs = 130; goto _test_eof; 
	_test_eof131: cs = 131; goto _test_eof; 
	_test_eof132: cs = 132; goto _test_eof; 
	_test_eof133: cs = 133; goto _test_eof; 
	_test_eof134: cs = 134; goto _test_eof; 
	_test_eof135: cs = 135; goto _test_eof; 
	_test_eof136: cs = 136; goto _test_eof; 
	_test_eof137: cs = 137; goto _test_eof; 
	_test_eof138: cs = 138; goto _test_eof; 
	_test_eof139: cs = 139; goto _test_eof; 
	_test_eof140: cs = 140; goto _test_eof; 
	_test_eof141: cs = 141; goto _test_eof; 
	_test_eof142: cs = 142; goto _test_eof; 
	_test_eof143: cs = 143; goto _test_eof; 
	_test_eof144: cs = 144; goto _test_eof; 
	_test_eof145: cs = 145; goto _test_eof; 
	_test_eof146: cs = 146; goto _test_eof; 
	_test_eof147: cs = 147; goto _test_eof; 
	_test_eof148: cs = 148; goto _test_eof; 
	_test_eof149: cs = 149; goto _test_eof; 
	_test_eof150: cs = 150; goto _test_eof; 
	_test_eof151: cs = 151; goto _test_eof; 
	_test_eof152: cs = 152; goto _test_eof; 
	_test_eof153: cs = 153; goto _test_eof; 
	_test_eof154: cs = 154; goto _test_eof; 
	_test_eof155: cs = 155; goto _test_eof; 
	_test_eof156: cs = 156; goto _test_eof; 
	_test_eof157: cs = 157; goto _test_eof; 
	_test_eof158: cs = 158; goto _test_eof; 
	_test_eof159: cs = 159; goto _test_eof; 
	_test_eof160: cs = 160; goto _test_eof; 
	_test_eof161: cs = 161; goto _test_eof; 
	_test_eof162: cs = 162; goto _test_eof; 
	_test_eof163: cs = 163; goto _test_eof; 
	_test_eof164: cs = 164; goto _test_eof; 
	_test_eof165: cs = 165; goto _test_eof; 
	_test_eof166: cs = 166; goto _test_eof; 
	_test_eof167: cs = 167; goto _test_eof; 
	_test_eof168: cs = 168; goto _test_eof; 
	_test_eof169: cs = 169; goto _test_eof; 
	_test_eof170: cs = 170; goto _test_eof; 
	_test_eof171: cs = 171; goto _test_eof; 
	_test_eof172: cs = 172; goto _test_eof; 
	_test_eof173: cs = 173; goto _test_eof; 
	_test_eof174: cs = 174; goto _test_eof; 
	_test_eof175: cs = 175; goto _test_eof; 
	_test_eof176: cs = 176; goto _test_eof; 
	_test_eof177: cs = 177; goto _test_eof; 
	_test_eof178: cs = 178; goto _test_eof; 
	_test_eof179: cs = 179; goto _test_eof; 
	_test_eof180: cs = 180; goto _test_eof; 
	_test_eof181: cs = 181; goto _test_eof; 
	_test_eof182: cs = 182; goto _test_eof; 
	_test_eof183: cs = 183; goto _test_eof; 
	_test_eof184: cs = 184; goto _test_eof; 
	_test_eof185: cs = 185; goto _test_eof; 
	_test_eof186: cs = 186; goto _test_eof; 
	_test_eof187: cs = 187; goto _test_eof; 
	_test_eof188: cs = 188; goto _test_eof; 
	_test_eof322: cs = 322; goto _test_eof; 
	_test_eof189: cs = 189; goto _test_eof; 
	_test_eof323: cs = 323; goto _test_eof; 
	_test_eof324: cs = 324; goto _test_eof; 
	_test_eof325: cs = 325; goto _test_eof; 
	_test_eof190: cs = 190; goto _test_eof; 
	_test_eof191: cs = 191; goto _test_eof; 
	_test_eof192: cs = 192; goto _test_eof; 
	_test_eof193: cs = 193; goto _test_eof; 
	_test_eof326: cs = 326; goto _test_eof; 
	_test_eof194: cs = 194; goto _test_eof; 
	_test_eof195: cs = 195; goto _test_eof; 
	_test_eof196: cs = 196; goto _test_eof; 
	_test_eof197: cs = 197; goto _test_eof; 
	_test_eof198: cs = 198; goto _test_eof; 
	_test_eof199: cs = 199; goto _test_eof; 
	_test_eof200: cs = 200; goto _test_eof; 
	_test_eof201: cs = 201; goto _test_eof; 
	_test_eof327: cs = 327; goto _test_eof; 
	_test_eof328: cs = 328; goto _test_eof; 
	_test_eof202: cs = 202; goto _test_eof; 
	_test_eof203: cs = 203; goto _test_eof; 
	_test_eof204: cs = 204; goto _test_eof; 
	_test_eof333: cs = 333; goto _test_eof; 
	_test_eof334: cs = 334; goto _test_eof; 
	_test_eof287: cs = 287; goto _test_eof; 
	_test_eof335: cs = 335; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 291: goto tr425;
	case 292: goto tr426;
	case 293: goto tr426;
	case 13: goto tr17;
	case 294: goto tr426;
	case 14: goto tr17;
	case 15: goto tr17;
	case 16: goto tr17;
	case 295: goto tr428;
	case 17: goto tr23;
	case 296: goto tr430;
	case 18: goto tr25;
	case 19: goto tr25;
	case 297: goto tr428;
	case 298: goto tr428;
	case 299: goto tr428;
	case 300: goto tr428;
	case 301: goto tr428;
	case 302: goto tr428;
	case 303: goto tr428;
	case 304: goto tr428;
	case 305: goto tr428;
	case 306: goto tr428;
	case 307: goto tr428;
	case 308: goto tr428;
	case 309: goto tr428;
	case 310: goto tr428;
	case 311: goto tr428;
	case 20: goto tr23;
	case 21: goto tr23;
	case 22: goto tr23;
	case 23: goto tr23;
	case 24: goto tr23;
	case 25: goto tr23;
	case 26: goto tr23;
	case 27: goto tr23;
	case 313: goto tr450;
	case 314: goto tr450;
	case 34: goto tr54;
	case 316: goto tr457;
	case 317: goto tr457;
	case 77: goto tr102;
	case 78: goto tr102;
	case 79: goto tr102;
	case 80: goto tr102;
	case 81: goto tr102;
	case 82: goto tr102;
	case 83: goto tr102;
	case 84: goto tr102;
	case 85: goto tr102;
	case 86: goto tr102;
	case 87: goto tr102;
	case 319: goto tr463;
	case 320: goto tr464;
	case 88: goto tr121;
	case 321: goto tr465;
	case 89: goto tr124;
	case 90: goto tr124;
	case 91: goto tr124;
	case 92: goto tr124;
	case 93: goto tr124;
	case 94: goto tr124;
	case 95: goto tr124;
	case 96: goto tr124;
	case 97: goto tr124;
	case 98: goto tr124;
	case 99: goto tr124;
	case 100: goto tr124;
	case 101: goto tr124;
	case 102: goto tr124;
	case 103: goto tr124;
	case 104: goto tr124;
	case 105: goto tr124;
	case 106: goto tr124;
	case 107: goto tr124;
	case 108: goto tr124;
	case 109: goto tr124;
	case 110: goto tr124;
	case 111: goto tr124;
	case 112: goto tr124;
	case 113: goto tr124;
	case 114: goto tr124;
	case 115: goto tr124;
	case 116: goto tr124;
	case 117: goto tr124;
	case 118: goto tr124;
	case 119: goto tr124;
	case 120: goto tr124;
	case 121: goto tr124;
	case 122: goto tr124;
	case 123: goto tr124;
	case 124: goto tr124;
	case 125: goto tr124;
	case 126: goto tr124;
	case 127: goto tr124;
	case 128: goto tr124;
	case 129: goto tr124;
	case 130: goto tr124;
	case 131: goto tr124;
	case 132: goto tr124;
	case 133: goto tr124;
	case 134: goto tr124;
	case 135: goto tr124;
	case 136: goto tr124;
	case 137: goto tr124;
	case 138: goto tr124;
	case 139: goto tr124;
	case 140: goto tr124;
	case 141: goto tr124;
	case 142: goto tr124;
	case 143: goto tr124;
	case 144: goto tr124;
	case 145: goto tr124;
	case 146: goto tr124;
	case 147: goto tr124;
	case 148: goto tr124;
	case 149: goto tr124;
	case 150: goto tr124;
	case 151: goto tr124;
	case 152: goto tr124;
	case 153: goto tr124;
	case 154: goto tr124;
	case 155: goto tr124;
	case 156: goto tr124;
	case 157: goto tr124;
	case 158: goto tr124;
	case 159: goto tr124;
	case 160: goto tr124;
	case 161: goto tr124;
	case 162: goto tr124;
	case 163: goto tr124;
	case 164: goto tr124;
	case 165: goto tr124;
	case 166: goto tr124;
	case 167: goto tr124;
	case 168: goto tr124;
	case 169: goto tr124;
	case 170: goto tr124;
	case 171: goto tr124;
	case 172: goto tr124;
	case 173: goto tr124;
	case 174: goto tr124;
	case 175: goto tr124;
	case 176: goto tr124;
	case 177: goto tr124;
	case 178: goto tr124;
	case 179: goto tr124;
	case 180: goto tr124;
	case 181: goto tr124;
	case 182: goto tr124;
	case 183: goto tr124;
	case 184: goto tr124;
	case 185: goto tr124;
	case 186: goto tr124;
	case 187: goto tr124;
	case 322: goto tr466;
	case 189: goto tr240;
	case 323: goto tr463;
	case 324: goto tr463;
	case 325: goto tr463;
	case 190: goto tr242;
	case 191: goto tr242;
	case 192: goto tr242;
	case 193: goto tr242;
	case 328: goto tr474;
	case 202: goto tr258;
	case 203: goto tr258;
	case 204: goto tr258;
	case 334: goto tr477;
	case 335: goto tr478;
	case 12: 
#line 38 "mfilescanner.rl"
	{
    cout << "*/\n";
    p--;
    {cs = stack[--top];goto _again;}
  }
	break;
	case 222: 
	case 223: 
	case 224: 
	case 225: 
	case 226: 
	case 227: 
	case 228: 
	case 229: 
	case 230: 
	case 231: 
	case 232: 
	case 233: 
	case 234: 
	case 235: 
	case 236: 
	case 237: 
	case 238: 
	case 239: 
	case 240: 
	case 241: 
	case 242: 
	case 243: 
	case 244: 
	case 245: 
	case 246: 
	case 247: 
	case 248: 
	case 249: 
	case 250: 
	case 251: 
	case 252: 
	case 253: 
	case 254: 
	case 255: 
	case 256: 
	case 257: 
	case 258: 
	case 259: 
	case 260: 
	case 261: 
	case 262: 
	case 263: 
	case 264: 
	case 265: 
	case 266: 
	case 267: 
	case 268: 
	case 269: 
	case 270: 
	case 271: 
	case 272: 
	case 273: 
	case 274: 
	case 275: 
	case 276: 
	case 277: 
	case 278: 
	case 279: 
	case 280: 
	case 281: 
	case 282: 
	case 283: 
	case 284: 
	case 285: 
	case 286: 
	case 312: 
	case 332: 
#line 45 "mfilescanner.rl"
	{
    /*    cout << "EOF\n";*/
    end_function();
  }
	break;
	case 206: 
	case 207: 
	case 208: 
	case 209: 
	case 210: 
	case 211: 
	case 212: 
	case 213: 
	case 214: 
	case 215: 
	case 216: 
	case 217: 
	case 218: 
	case 219: 
#line 571 "mfilescanner.rl"
	{
        p = tmp_p - 2;
        {goto st327;}
      }
	break;
	case 220: 
#line 585 "mfilescanner.rl"
	{
    p--;
    {goto st312;}
  }
	break;
	case 1: 
	case 2: 
	case 3: 
	case 4: 
	case 5: 
	case 6: 
	case 7: 
	case 8: 
	case 9: 
	case 10: 
	case 11: 
#line 672 "mfilescanner.rl"
	{
    p=tmp_p;
    {goto st221;}
  }
	break;
#line 6206 "mfilescanner.cc"
	}
	}

	_out: {}
	}
#line 794 "mfilescanner.rl"

    /* Check if we failed. */
    if ( cs == MFileScanner_error )
    {
      /* Machine failed before finding a token. */
      cerr << std::string(filename_) << ": PARSE ERROR in line " << line << endl;
      exit(-1);
    }

    /* Now set up the prefix. */
    if ( ts == 0 )
    {
      have = rpe - pe;
      /* cerr << "memmove by " << have << "bytes\n";*/
      memmove( buf, pe, have );
    }
    else
    {
      have = rpe - ts;
      /* cerr << "memmove by " << have << "bytes to ts\n";*/
      memmove( buf, ts, have );
    }

    if ( ts != 0 )
    {
      te -= (ts-buf);
      ts = buf;
    }
  }

  return 0;
}

const string & MFileScanner::escape_chars(std::string & s)
{
  string::size_type found = s.find_first_of("@\\");
  while(found != string::npos )
  {
    s.insert(found, "\\");
    found = s.find_first_of("@\\",found+2);
  }
  return s;
}

const string & MFileScanner::replace_underscore(std::string & s)
{
  // standard brief text (replace '_' -> ' ' in cfuncname_)
  string::size_type found = s.find("_");
  while(found != string::npos )
  {
    s[found] = ' ';
    found = s.find("_", found+1);
  }
  return s;
}

void MFileScanner::write_docu_block(const DocuBlock & block)
{
  bool add_prefix = false;
  bool latex_begin = true;
  bool not_verbatim = true;
  for( unsigned int i = 0; i < block.size(); i += 1 )
  {
    if(add_prefix)
      cout << "* ";

    add_prefix = false;
    const string & s = block[i];
    string::size_type j=0;
    const char * tokens = "\'`@\n";
    bool last_char_escaped = false;
    for( string::size_type i = 0; j < s.size(); i=j )
    {
      j=s.find_first_of(tokens,i+1);
      if(j==string::npos)
        j=s.size();
      if(s[j-1] == '\\' && not_verbatim && latex_begin)
        --j;
      if(s[i] == '@')
      {
        if(s.substr(i+1,4) == "code" || s.substr(i+1,8) == "verbatim")
          not_verbatim = false;
        else if(s.substr(i+1,7) == "endcode" || s.substr(i+1,11) == "endverbatim")
          not_verbatim = true;
        cout << s.substr(i,j-i);
      }
      else if(s[i] == '\'' && not_verbatim && latex_begin)
      {
        if(j != s.size() && s[j] == '\'' && !last_char_escaped)
        {
          cout << "<tt>" << s.substr(i+1, j-i-1) << "</tt>";
          ++j;
        }
        else
          cout << s.substr(i,j-i);
      }
      else if(s[i] == '`' && not_verbatim)
      {
        string lout;
        if(!last_char_escaped)
        {
          if(s[i+1] == '`')
          {
            if(latex_begin)
              lout = "@f[";
            else
              lout = "@f]";
            ++i;
            j=s.find_first_of(tokens,i+1);
            if(j==string::npos)
              j=s.size();
          }
          else
            lout = "@f$";
          if(latex_begin)
            latex_begin = false;
          else
            latex_begin = true;
          ++i;
        }
        else
        {
          lout = "";
        }
        cout << lout << s.substr(i, j-i);
      }
      else if(s[i] == '\n')
      {
        cout << "\n  ";
        if(latex_begin)
          add_prefix = true;
        else
        {
          cout << "  ";
          add_prefix = false;
        }
      }
      else
      {
        cout << s.substr(i,j-i);
      }
      if(s[j-1] != '\\' && s[j] == '\\')
      {
        last_char_escaped = true;
      }
      else
        last_char_escaped = false;
      if(s[j] == '\\')
        ++j;
    }
  }
}

void MFileScanner::write_docu_list(const DocuList & list,
                                   const string & item_text,
                                   const DocuList & alternative,
                                   const string separator = string())
{
  typedef DocuList :: const_iterator list_iterator;
  list_iterator lit = list.begin();
  for(; lit != list.end(); ++lit)
  {
    cout << "* " << item_text << " " << (*lit).first << separator << "    ";
    const DocuBlock & block = (*lit).second;
    if(block.empty())
    {
      list_iterator alit = alternative.find((*lit).first);
      if(alit == alternative.end() || (*alit).second.empty())
      {
        std::string s((*lit).first);
        cout << replace_underscore(s) << "\n  ";
      }
      else
        write_docu_block((*alit).second);
    }
    else
      write_docu_block(block);
  }
}

void MFileScanner::write_docu_listmap(const DocuListMap & listmap,
                                      const string & text,
                                      const DocuListMap & altlistmap)
{
  typedef DocuListMap :: const_iterator map_iterator;
  if(!listmap.empty())
  {
    map_iterator mit = listmap.begin();
    for(; mit != listmap.end(); ++mit)
    {
      cout << "*\n  ";
      cout << "* " << text << (*mit).first << ":\n  ";
      map_iterator amit = altlistmap.find((*mit).first);
      write_docu_list((*mit).second, "@arg \\c", ( amit != altlistmap.end() ? (*amit).second : DocuList() ), "&nbsp;&mdash;&nbsp;");
    }
//    cout << "* </TABLE>\n  ";

  }
}

void MFileScanner::end_function()
{
  typedef GroupSet :: iterator group_iterator;
  typedef DocuBlock :: iterator block_iterator;
  typedef DocuList :: iterator list_iterator;
  typedef DocuListMap :: iterator map_iterator;
  // end function
  cout << "}\n";
  if(is_first_function_)
  {
    string tempfname(filename_);
//    string::size_type found = tempfname.rfind("/");
//    if(found != string::npos)
//      tempfname = tempfname.substr(found+1);
    if(! latex_output_ )
    {
      cout << "/** @file \"" << tempfname << "\"\n  ";
      if((! groupset_.empty() || ! cscan_.groupset_.empty() ))
      {
        // specify the @ingroup command
        cout << "* @ingroup ";
        bool not_first = false;
        group_iterator git = cscan_.groupset_.begin();
        for(; git != cscan_.groupset_.end(); ++git)
        {
          if(not_first)
            cout << " ";
          else
            not_first = true;

          cout << *git;
        }
        groupset_.clear();
      }
      //    cout << "\n  " << "* @brief " << tempfname << " ";
      cout << "*/\n";
    }
  }
  cout << "/*";
  if(latex_output_)
  {
    if(! cscan_.groupset_.empty() )
    {
      // specify the @ingroup command
      cout << "* @ingroup ";
      bool not_first = false;
      group_iterator git = cscan_.groupset_.begin();
      for(; git != cscan_.groupset_.end(); ++git)
      {
        if(not_first)
          cout << " ";
        else
          not_first = true;

        cout << *git;
      }
    }
    cout << "\n  ";
  }
  // specify the @fn part
  cout << "* @fn ";
  if(returnlist_.size() == 0)
    cout << "noret::substitute ";
  else if(returnlist_.size() == 1)
  {
    cout << "ret::substitutestart::" << returnlist_[0] << "::retsubstituteend ";
  }
  else
  {
    cout << "rets::substitutestart::";
    for(unsigned int i = 0; i < returnlist_.size(); ++i)
    {
      if(i != 0)
        cout << "::";

      cout << returnlist_[i];
    }
    cout << "::retssubstituteend ";
  }
  returnlist_.clear();

  bool first = true;
  if(!is_first_function_)
    cout << "mtoc_subst_" << fnname_ << "_tsbus_cotm_";
  cout << cfuncname_;
  if(paramlist_.size() == 0)
    cout << "\n  ";
  else
  {
    cout << "(";
    for(unsigned int i=0; i < paramlist_.size(); ++i)
    {
      if(!first)
        cout << ",";
      else
        first = false;
      cout << "matlabtypesubstitute " << paramlist_[i];
    }
    paramlist_.clear();
    cout << ")\n  ";
  }

  // specify the @brief part
  cout << "* @brief ";
  if(docuheader_.empty() && cscan_.docuheader_.empty())
  {
    string s(cfuncname_);
    cout << replace_underscore(s) << "\n  ";
  }
  else
  {
    if(! docuheader_.empty())
    {
      write_docu_block(docuheader_);
    }
    if(! cscan_.docuheader_.empty())
    {
      write_docu_block(cscan_.docuheader_);
    }
  }
  docuheader_.clear();
  cout << "*\n  ";
  // specify the @details part

  // standard body definitions
  if(!docubody_.empty())
  {
    cout << "*\n  * ";
    write_docu_block(docubody_);
  }
  docubody_.clear();
  if(!cscan_.docubody_.empty())
  {
    cout << "*\n  * ";
    write_docu_block(cscan_.docubody_);
  }
  // parameters
  if(!param_list_.empty())
  {
    cout << "*\n  ";
    write_docu_list(param_list_, "@param", cscan_.param_list_);
    param_list_.clear();
  }
  // return values
  if(!return_list_.empty())
  {
    cout << "*\n  ";
    write_docu_list(return_list_, "@retval", cscan_.return_list_);
    return_list_.clear();
  }
  // required fields
  write_docu_listmap(required_list_, "@par Required fields of ", cscan_.field_docu_);
  required_list_.clear();

  // optional fields
  write_docu_listmap(optional_list_, "@par Optional fields of ", cscan_.field_docu_);
  optional_list_.clear();

  // return fields
  write_docu_listmap(retval_list_, "@par Generated fields of ", cscan_.field_docu_);
  retval_list_.clear();

  // extra docu fields
  if(! cscan_.docuextra_.empty())
  {
    cout << "*\n  * ";
    write_docu_block(cscan_.docuextra_);
  }
  if( new_syntax_ )
  {
    cout << "* @synupdate Syntax needs to be updated! \n  ";
  }
  docuextra_.clear();
  cout << "*/\n";
  is_first_function_ = false;
}

int main(int argc, char ** argv)
{
  istream * fcin;
  std::ifstream fin;
  string filename;
  if(argc >= 2)
  {
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

  char buf[1000];
  char * dummy = getcwd(buf, 1000);
  dummy = 0;

  string::size_type found = 0;
  string cwd(buf);
  found = filename.find(cwd);
  if(found!=string::npos)
    filename = filename.substr(cwd.size()+1);
  MFileScanner scanner(*fcin, filename, latex_output);
  scanner.execute();
  return 0;
}

/* vim: set et sw=2 ft=ragel: */

