
#line 1 "mfilescanner.rl"
#include "mfilescanner.h"

#include <cstring>
#include <cstdlib>
#include <iostream>
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
static const int MFileScanner_start = 279;
static const int MFileScanner_first_final = 279;
static const int MFileScanner_error = 0;

static const int MFileScanner_en_in_comment_block = 280;
static const int MFileScanner_en_funcline = 281;
static const int MFileScanner_en_funcbody = 303;
static const int MFileScanner_en_fill_list = 306;
static const int MFileScanner_en_doxy_get_body = 309;
static const int MFileScanner_en_doxyfunction_garble = 312;
static const int MFileScanner_en_doxy_get_brief = 313;
static const int MFileScanner_en_doxyheader = 197;
static const int MFileScanner_en_expect_doxyblock = 212;
static const int MFileScanner_en_script = 213;
static const int MFileScanner_en_funct = 214;
static const int MFileScanner_en_main = 279;


#line 548 "mfilescanner.rl"



MFileScanner :: MFileScanner(istream & fin, const std::string & filename) :
  fin_(fin), filename_(filename), cscan_(filename_),
  line(1),
  ts(0), have(0), top(0),
  opt(false), new_syntax_(false), is_script_(false), is_first_function_(true)
{
  cscan_.execute();
};

int MFileScanner :: execute()
{
  std::ios::sync_with_stdio(false);

  
#line 61 "mfilescanner.cc"
	{
	cs = MFileScanner_start;
	top = 0;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 565 "mfilescanner.rl"

  /* Do the first read. */
  bool done = false;
  while ( !done )
  {
    char *p = buf + have;
    char *tmp_p = p, *tmp_p2 = p, *tmp_p3 = p;
    string tmp_string;
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

    
#line 126 "mfilescanner.cc"
	{
	if ( p == pe )
		goto _test_eof;
	goto _resume;

_again:
	switch ( cs ) {
		case 279: goto st279;
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
		case 197: goto st197;
		case 198: goto st198;
		case 199: goto st199;
		case 200: goto st200;
		case 201: goto st201;
		case 202: goto st202;
		case 203: goto st203;
		case 204: goto st204;
		case 205: goto st205;
		case 206: goto st206;
		case 207: goto st207;
		case 315: goto st315;
		case 208: goto st208;
		case 209: goto st209;
		case 210: goto st210;
		case 211: goto st211;
		case 212: goto st212;
		case 316: goto st316;
		case 213: goto st213;
		case 317: goto st317;
		case 214: goto st214;
		case 215: goto st215;
		case 216: goto st216;
		case 217: goto st217;
		case 218: goto st218;
		case 219: goto st219;
		case 220: goto st220;
		case 221: goto st221;
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
		case 318: goto st318;
		case 234: goto st234;
		case 235: goto st235;
		case 236: goto st236;
		case 237: goto st237;
		case 238: goto st238;
		case 239: goto st239;
		case 240: goto st240;
		case 241: goto st241;
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
		case 280: goto st280;
		case 12: goto st12;
		case 281: goto st281;
		case 282: goto st282;
		case 283: goto st283;
		case 284: goto st284;
		case 13: goto st13;
		case 285: goto st285;
		case 14: goto st14;
		case 15: goto st15;
		case 16: goto st16;
		case 286: goto st286;
		case 17: goto st17;
		case 287: goto st287;
		case 288: goto st288;
		case 289: goto st289;
		case 290: goto st290;
		case 291: goto st291;
		case 292: goto st292;
		case 293: goto st293;
		case 294: goto st294;
		case 295: goto st295;
		case 296: goto st296;
		case 297: goto st297;
		case 298: goto st298;
		case 299: goto st299;
		case 300: goto st300;
		case 301: goto st301;
		case 302: goto st302;
		case 18: goto st18;
		case 19: goto st19;
		case 20: goto st20;
		case 21: goto st21;
		case 22: goto st22;
		case 23: goto st23;
		case 24: goto st24;
		case 25: goto st25;
		case 303: goto st303;
		case 26: goto st26;
		case 304: goto st304;
		case 27: goto st27;
		case 28: goto st28;
		case 29: goto st29;
		case 30: goto st30;
		case 305: goto st305;
		case 31: goto st31;
		case 32: goto st32;
		case 33: goto st33;
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
		case 306: goto st306;
		case 307: goto st307;
		case 308: goto st308;
		case 74: goto st74;
		case 75: goto st75;
		case 76: goto st76;
		case 77: goto st77;
		case 78: goto st78;
		case 79: goto st79;
		case 80: goto st80;
		case 81: goto st81;
		case 82: goto st82;
		case 83: goto st83;
		case 309: goto st309;
		case 310: goto st310;
		case 311: goto st311;
		case 84: goto st84;
		case 85: goto st85;
		case 86: goto st86;
		case 87: goto st87;
		case 88: goto st88;
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
		case 189: goto st189;
		case 190: goto st190;
		case 312: goto st312;
		case 191: goto st191;
		case 192: goto st192;
		case 193: goto st193;
		case 313: goto st313;
		case 314: goto st314;
		case 194: goto st194;
		case 195: goto st195;
		case 196: goto st196;
	default: break;
	}

	if ( ++p == pe )
		goto _test_eof;
_resume:
	switch ( cs )
	{
tr13:
#line 535 "mfilescanner.rl"
	{
    p=tmp_p;
    {goto st214;}
    }
	goto st279;
st279:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof279;
case 279:
#line 474 "mfilescanner.cc"
	goto tr402;
tr2:
#line 28 "mfilescanner.rl"
	{line++;}
	goto st1;
tr402:
#line 529 "mfilescanner.rl"
	{ p--; tmp_p = p; }
	goto st1;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
#line 488 "mfilescanner.cc"
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
#line 540 "mfilescanner.rl"
	{
    p=tmp_p;
    {goto st213;}
  }
	goto st0;
tr15:
#line 37 "mfilescanner.rl"
	{
    cout << "*/\n";
    p--;
    {cs = stack[--top];goto _again;}
  }
	goto st0;
tr256:
#line 450 "mfilescanner.rl"
	{
        p = tmp_p - 2;
        {goto st313;}
      }
	goto st0;
tr272:
#line 464 "mfilescanner.rl"
	{
    p--;
    {goto st303;}
  }
	goto st0;
#line 527 "mfilescanner.cc"
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
st197:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof197;
case 197:
#line 612 "mfilescanner.cc"
	if ( (*p) == 37 )
		goto st198;
	goto st0;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
	switch( (*p) ) {
		case 9: goto st198;
		case 32: goto st198;
		case 102: goto st199;
	}
	goto tr256;
st199:
	if ( ++p == pe )
		goto _test_eof199;
case 199:
	if ( (*p) == 117 )
		goto st200;
	goto tr256;
st200:
	if ( ++p == pe )
		goto _test_eof200;
case 200:
	if ( (*p) == 110 )
		goto st201;
	goto tr256;
st201:
	if ( ++p == pe )
		goto _test_eof201;
case 201:
	if ( (*p) == 99 )
		goto st202;
	goto tr256;
st202:
	if ( ++p == pe )
		goto _test_eof202;
case 202:
	if ( (*p) == 116 )
		goto st203;
	goto tr256;
st203:
	if ( ++p == pe )
		goto _test_eof203;
case 203:
	if ( (*p) == 105 )
		goto st204;
	goto tr256;
st204:
	if ( ++p == pe )
		goto _test_eof204;
case 204:
	if ( (*p) == 111 )
		goto st205;
	goto tr256;
st205:
	if ( ++p == pe )
		goto _test_eof205;
case 205:
	if ( (*p) == 110 )
		goto st206;
	goto tr256;
st206:
	if ( ++p == pe )
		goto _test_eof206;
case 206:
	switch( (*p) ) {
		case 0: goto tr256;
		case 10: goto tr256;
		case 41: goto st207;
		case 46: goto st208;
		case 59: goto st207;
	}
	goto st206;
st207:
	if ( ++p == pe )
		goto _test_eof207;
case 207:
	switch( (*p) ) {
		case 0: goto tr256;
		case 10: goto tr267;
	}
	goto st207;
tr267:
#line 28 "mfilescanner.rl"
	{line++;}
#line 443 "mfilescanner.rl"
	{ {goto st309;} }
	goto st315;
tr270:
#line 28 "mfilescanner.rl"
	{line++;}
#line 446 "mfilescanner.rl"
	{ {goto st312;} }
	goto st315;
st315:
	if ( ++p == pe )
		goto _test_eof315;
case 315:
#line 712 "mfilescanner.cc"
	goto tr256;
st208:
	if ( ++p == pe )
		goto _test_eof208;
case 208:
	if ( (*p) == 46 )
		goto st209;
	goto tr256;
st209:
	if ( ++p == pe )
		goto _test_eof209;
case 209:
	if ( (*p) == 46 )
		goto st210;
	goto tr256;
st210:
	if ( ++p == pe )
		goto _test_eof210;
case 210:
	switch( (*p) ) {
		case 9: goto st210;
		case 10: goto tr270;
		case 13: goto st211;
		case 32: goto st210;
	}
	goto tr256;
st211:
	if ( ++p == pe )
		goto _test_eof211;
case 211:
	if ( (*p) == 10 )
		goto tr270;
	goto tr256;
st212:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof212;
case 212:
#line 752 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st212;
		case 32: goto st212;
		case 37: goto tr274;
	}
	goto tr272;
tr274:
#line 74 "mfilescanner.rl"
	{ tmp_p = p + 1; }
#line 459 "mfilescanner.rl"
	{
        //cout << "/*";
        p--;
        {goto st197;}
      }
	goto st316;
st316:
	if ( ++p == pe )
		goto _test_eof316;
case 316:
#line 773 "mfilescanner.cc"
	goto tr272;
st213:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof213;
case 213:
#line 781 "mfilescanner.cc"
	if ( (*p) == 0 )
		goto st0;
	goto tr275;
tr275:
#line 502 "mfilescanner.rl"
	{
       string :: size_type found = filename_.rfind("/");
       if(found == string :: npos)
         found = -1;
       string funcname = filename_.substr(found+1, filename_.size()-3-found);
       cfuncname_.assign( funcname );
       cout << "void " << funcname << "() {\n";
       is_script_ = true;
       p--;
       {goto st212;}
     }
	goto st317;
st317:
	if ( ++p == pe )
		goto _test_eof317;
case 317:
#line 803 "mfilescanner.cc"
	goto st0;
tr277:
#line 28 "mfilescanner.rl"
	{line++;}
	goto st214;
tr285:
#line 28 "mfilescanner.rl"
	{line++;}
#line 50 "mfilescanner.rl"
	{
    /*    cout << p << "x" << tmp_p << endl;*/
    cout.write(tmp_p, p-tmp_p+1);
    {stack[top++] = 214; goto st280;}
  }
	goto st214;
st214:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof214;
case 214:
#line 825 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st214;
		case 10: goto tr277;
		case 13: goto st215;
		case 32: goto st216;
		case 37: goto st217;
		case 102: goto st219;
	}
	goto st0;
st215:
	if ( ++p == pe )
		goto _test_eof215;
case 215:
	if ( (*p) == 10 )
		goto tr277;
	goto st0;
st216:
	if ( ++p == pe )
		goto _test_eof216;
case 216:
	switch( (*p) ) {
		case 9: goto st216;
		case 10: goto tr277;
		case 13: goto st215;
		case 32: goto st216;
		case 37: goto st217;
	}
	goto st0;
st217:
	if ( ++p == pe )
		goto _test_eof217;
case 217:
	switch( (*p) ) {
		case 0: goto st0;
		case 124: goto tr283;
	}
	goto tr282;
tr282:
#line 68 "mfilescanner.rl"
	{ cout << "/*"; tmp_p = p; }
	goto st218;
tr283:
#line 66 "mfilescanner.rl"
	{ cout << "/**"; tmp_p = p+1; }
	goto st218;
st218:
	if ( ++p == pe )
		goto _test_eof218;
case 218:
#line 875 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr285;
	}
	goto st218;
st219:
	if ( ++p == pe )
		goto _test_eof219;
case 219:
	if ( (*p) == 117 )
		goto st220;
	goto st0;
st220:
	if ( ++p == pe )
		goto _test_eof220;
case 220:
	if ( (*p) == 110 )
		goto st221;
	goto st0;
st221:
	if ( ++p == pe )
		goto _test_eof221;
case 221:
	if ( (*p) == 99 )
		goto st222;
	goto st0;
st222:
	if ( ++p == pe )
		goto _test_eof222;
case 222:
	if ( (*p) == 116 )
		goto st223;
	goto st0;
st223:
	if ( ++p == pe )
		goto _test_eof223;
case 223:
	if ( (*p) == 105 )
		goto st224;
	goto st0;
st224:
	if ( ++p == pe )
		goto _test_eof224;
case 224:
	if ( (*p) == 111 )
		goto st225;
	goto st0;
st225:
	if ( ++p == pe )
		goto _test_eof225;
case 225:
	if ( (*p) == 110 )
		goto st226;
	goto st0;
tr301:
#line 28 "mfilescanner.rl"
	{line++;}
	goto st226;
tr298:
#line 28 "mfilescanner.rl"
	{line++;}
#line 78 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st226;
st226:
	if ( ++p == pe )
		goto _test_eof226;
case 226:
#line 947 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st226;
		case 32: goto st226;
		case 37: goto tr293;
		case 46: goto st228;
		case 91: goto tr296;
		case 95: goto tr295;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr295;
	} else if ( (*p) >= 65 )
		goto tr295;
	goto st0;
tr293:
#line 85 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st227;
st227:
	if ( ++p == pe )
		goto _test_eof227;
case 227:
#line 970 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr298;
	}
	goto st227;
st228:
	if ( ++p == pe )
		goto _test_eof228;
case 228:
	if ( (*p) == 46 )
		goto st229;
	goto st0;
st229:
	if ( ++p == pe )
		goto _test_eof229;
case 229:
	if ( (*p) == 46 )
		goto st230;
	goto st0;
st230:
	if ( ++p == pe )
		goto _test_eof230;
case 230:
	switch( (*p) ) {
		case 9: goto st230;
		case 10: goto tr301;
		case 13: goto st231;
		case 32: goto st230;
	}
	goto st0;
st231:
	if ( ++p == pe )
		goto _test_eof231;
case 231:
	if ( (*p) == 10 )
		goto tr301;
	goto st0;
tr295:
#line 58 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st232;
st232:
	if ( ++p == pe )
		goto _test_eof232;
case 232:
#line 1016 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr303;
		case 10: goto tr304;
		case 13: goto tr305;
		case 32: goto tr303;
		case 37: goto tr306;
		case 40: goto tr307;
		case 46: goto tr308;
		case 59: goto tr310;
		case 61: goto tr311;
		case 95: goto st232;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st232;
	} else
		goto st232;
	goto st0;
tr303:
#line 126 "mfilescanner.rl"
	{
             string s(tmp_p, p - tmp_p);
             returnlist_.push_back(s);
             return_list_[s] = DocuBlock();
             cout << "ret::substitutestart::" << s << "::retsubstituteend ";
           }
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
#line 474 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
	goto st233;
tr312:
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st233;
st233:
	if ( ++p == pe )
		goto _test_eof233;
case 233:
#line 1062 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr312;
		case 10: goto tr313;
		case 13: goto st234;
		case 32: goto tr312;
		case 37: goto tr315;
		case 40: goto tr316;
		case 46: goto st259;
		case 59: goto st263;
		case 61: goto tr319;
	}
	goto st0;
tr304:
#line 474 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
#line 28 "mfilescanner.rl"
	{line++;}
#line 497 "mfilescanner.rl"
	{ cout << "void " << cfuncname_ << "() {\n"; {goto st212;} }
	goto st318;
tr313:
#line 28 "mfilescanner.rl"
	{line++;}
#line 497 "mfilescanner.rl"
	{ cout << "void " << cfuncname_ << "() {\n"; {goto st212;} }
	goto st318;
tr333:
#line 28 "mfilescanner.rl"
	{line++;}
#line 493 "mfilescanner.rl"
	{
             cout << " {\n";
             {goto st212;}
           }
	goto st318;
st318:
	if ( ++p == pe )
		goto _test_eof318;
case 318:
#line 1105 "mfilescanner.cc"
	goto st0;
tr305:
#line 474 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
	goto st234;
st234:
	if ( ++p == pe )
		goto _test_eof234;
case 234:
#line 1118 "mfilescanner.cc"
	if ( (*p) == 10 )
		goto tr313;
	goto st0;
tr315:
#line 85 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st235;
tr306:
#line 474 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
#line 85 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st235;
st235:
	if ( ++p == pe )
		goto _test_eof235;
case 235:
#line 1139 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr321;
	}
	goto st235;
tr370:
#line 28 "mfilescanner.rl"
	{line++;}
	goto st236;
tr321:
#line 28 "mfilescanner.rl"
	{line++;}
#line 78 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st236;
tr381:
#line 474 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
	goto st236;
st236:
	if ( ++p == pe )
		goto _test_eof236;
case 236:
#line 1169 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st236;
		case 10: goto tr313;
		case 13: goto st234;
		case 32: goto st236;
		case 37: goto tr315;
		case 40: goto tr316;
		case 46: goto st259;
		case 59: goto st263;
	}
	goto st0;
tr345:
#line 28 "mfilescanner.rl"
	{line++;}
	goto st237;
tr331:
#line 28 "mfilescanner.rl"
	{line++;}
#line 78 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st237;
tr307:
#line 474 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
#line 482 "mfilescanner.rl"
	{
                 if(!opt)
                 {
                   cout << "noret::substitute ";
                   opt=false;
                 }
                 cout << cfuncname_ << '(';
                 }
	goto st237;
tr324:
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st237;
tr316:
#line 482 "mfilescanner.rl"
	{
                 if(!opt)
                 {
                   cout << "noret::substitute ";
                   opt=false;
                 }
                 cout << cfuncname_ << '(';
                 }
	goto st237;
tr354:
#line 28 "mfilescanner.rl"
	{line++;}
#line 78 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st237;
tr361:
#line 99 "mfilescanner.rl"
	{
         string s(tmp_p, p - tmp_p);
         param_list_[s] = DocuBlock();
         paramlist_.push_back(s);
         cout << "type " << s;
       }
	goto st237;
tr362:
#line 99 "mfilescanner.rl"
	{
         string s(tmp_p, p - tmp_p);
         param_list_[s] = DocuBlock();
         paramlist_.push_back(s);
         cout << "type " << s;
       }
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st237;
st237:
	if ( ++p == pe )
		goto _test_eof237;
case 237:
#line 1260 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st237;
		case 10: goto tr324;
		case 32: goto st237;
		case 37: goto tr325;
		case 41: goto tr326;
		case 44: goto tr324;
		case 46: goto st246;
		case 61: goto st250;
		case 95: goto tr329;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr329;
	} else if ( (*p) >= 65 )
		goto tr329;
	goto st0;
tr325:
#line 85 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st238;
tr363:
#line 99 "mfilescanner.rl"
	{
         string s(tmp_p, p - tmp_p);
         param_list_[s] = DocuBlock();
         paramlist_.push_back(s);
         cout << "type " << s;
       }
#line 85 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st238;
st238:
	if ( ++p == pe )
		goto _test_eof238;
case 238:
#line 1297 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr331;
	}
	goto st238;
tr341:
#line 28 "mfilescanner.rl"
	{line++;}
	goto st239;
tr338:
#line 28 "mfilescanner.rl"
	{line++;}
#line 78 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st239;
tr326:
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st239;
tr364:
#line 99 "mfilescanner.rl"
	{
         string s(tmp_p, p - tmp_p);
         param_list_[s] = DocuBlock();
         paramlist_.push_back(s);
         cout << "type " << s;
       }
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st239;
st239:
	if ( ++p == pe )
		goto _test_eof239;
case 239:
#line 1335 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st239;
		case 10: goto tr333;
		case 13: goto st240;
		case 32: goto st239;
		case 37: goto tr335;
		case 46: goto st242;
		case 59: goto st239;
	}
	goto st0;
st240:
	if ( ++p == pe )
		goto _test_eof240;
case 240:
	if ( (*p) == 10 )
		goto tr333;
	goto st0;
tr335:
#line 85 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st241;
st241:
	if ( ++p == pe )
		goto _test_eof241;
case 241:
#line 1361 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr338;
	}
	goto st241;
st242:
	if ( ++p == pe )
		goto _test_eof242;
case 242:
	if ( (*p) == 46 )
		goto st243;
	goto st0;
st243:
	if ( ++p == pe )
		goto _test_eof243;
case 243:
	if ( (*p) == 46 )
		goto st244;
	goto st0;
st244:
	if ( ++p == pe )
		goto _test_eof244;
case 244:
	switch( (*p) ) {
		case 9: goto st244;
		case 10: goto tr341;
		case 13: goto st245;
		case 32: goto st244;
	}
	goto st0;
st245:
	if ( ++p == pe )
		goto _test_eof245;
case 245:
	if ( (*p) == 10 )
		goto tr341;
	goto st0;
tr365:
#line 99 "mfilescanner.rl"
	{
         string s(tmp_p, p - tmp_p);
         param_list_[s] = DocuBlock();
         paramlist_.push_back(s);
         cout << "type " << s;
       }
	goto st246;
st246:
	if ( ++p == pe )
		goto _test_eof246;
case 246:
#line 1412 "mfilescanner.cc"
	if ( (*p) == 46 )
		goto st247;
	goto st0;
st247:
	if ( ++p == pe )
		goto _test_eof247;
case 247:
	if ( (*p) == 46 )
		goto st248;
	goto st0;
st248:
	if ( ++p == pe )
		goto _test_eof248;
case 248:
	switch( (*p) ) {
		case 9: goto st248;
		case 10: goto tr345;
		case 13: goto st249;
		case 32: goto st248;
	}
	goto st0;
st249:
	if ( ++p == pe )
		goto _test_eof249;
case 249:
	if ( (*p) == 10 )
		goto tr345;
	goto st0;
tr347:
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st250;
tr351:
#line 28 "mfilescanner.rl"
	{line++;}
#line 78 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st250;
tr359:
#line 28 "mfilescanner.rl"
	{line++;}
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st250;
tr367:
#line 99 "mfilescanner.rl"
	{
         string s(tmp_p, p - tmp_p);
         param_list_[s] = DocuBlock();
         paramlist_.push_back(s);
         cout << "type " << s;
       }
	goto st250;
st250:
	if ( ++p == pe )
		goto _test_eof250;
case 250:
#line 1475 "mfilescanner.cc"
	switch( (*p) ) {
		case 37: goto tr348;
		case 41: goto tr326;
		case 44: goto tr324;
		case 46: goto tr349;
	}
	goto tr347;
tr350:
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st251;
tr348:
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
#line 85 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st251;
st251:
	if ( ++p == pe )
		goto _test_eof251;
case 251:
#line 1497 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr347;
		case 10: goto tr351;
		case 37: goto tr348;
		case 41: goto st238;
		case 44: goto tr352;
	}
	goto tr350;
tr352:
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st252;
st252:
	if ( ++p == pe )
		goto _test_eof252;
case 252:
#line 1514 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st252;
		case 10: goto tr354;
		case 32: goto st252;
		case 37: goto tr325;
		case 44: goto tr352;
		case 61: goto st251;
	}
	goto st238;
tr349:
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st253;
st253:
	if ( ++p == pe )
		goto _test_eof253;
case 253:
#line 1533 "mfilescanner.cc"
	switch( (*p) ) {
		case 37: goto tr348;
		case 41: goto tr326;
		case 44: goto tr324;
		case 46: goto tr356;
	}
	goto tr347;
tr356:
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st254;
st254:
	if ( ++p == pe )
		goto _test_eof254;
case 254:
#line 1549 "mfilescanner.cc"
	switch( (*p) ) {
		case 37: goto tr348;
		case 41: goto tr326;
		case 44: goto tr324;
		case 46: goto tr357;
	}
	goto tr347;
tr357:
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st255;
st255:
	if ( ++p == pe )
		goto _test_eof255;
case 255:
#line 1565 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr358;
		case 10: goto tr359;
		case 13: goto tr360;
		case 32: goto tr358;
		case 37: goto tr348;
		case 41: goto tr326;
		case 44: goto tr324;
		case 46: goto tr357;
	}
	goto tr347;
tr358:
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st256;
st256:
	if ( ++p == pe )
		goto _test_eof256;
case 256:
#line 1585 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr358;
		case 10: goto tr359;
		case 13: goto tr360;
		case 32: goto tr358;
		case 37: goto tr348;
		case 41: goto tr326;
		case 44: goto tr324;
		case 46: goto tr349;
	}
	goto tr347;
tr360:
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st257;
st257:
	if ( ++p == pe )
		goto _test_eof257;
case 257:
#line 1605 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr359;
		case 37: goto tr348;
		case 41: goto tr326;
		case 44: goto tr324;
		case 46: goto tr349;
	}
	goto tr347;
tr329:
#line 58 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st258;
st258:
	if ( ++p == pe )
		goto _test_eof258;
case 258:
#line 1622 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr361;
		case 10: goto tr362;
		case 32: goto tr361;
		case 37: goto tr363;
		case 41: goto tr364;
		case 44: goto tr362;
		case 46: goto tr365;
		case 61: goto tr367;
		case 95: goto st258;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st258;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st258;
	} else
		goto st258;
	goto st0;
tr308:
#line 474 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
	goto st259;
st259:
	if ( ++p == pe )
		goto _test_eof259;
case 259:
#line 1654 "mfilescanner.cc"
	if ( (*p) == 46 )
		goto st260;
	goto st0;
st260:
	if ( ++p == pe )
		goto _test_eof260;
case 260:
	if ( (*p) == 46 )
		goto st261;
	goto st0;
st261:
	if ( ++p == pe )
		goto _test_eof261;
case 261:
	switch( (*p) ) {
		case 9: goto st261;
		case 10: goto tr370;
		case 13: goto st262;
		case 32: goto st261;
	}
	goto st0;
st262:
	if ( ++p == pe )
		goto _test_eof262;
case 262:
	if ( (*p) == 10 )
		goto tr370;
	goto st0;
tr310:
#line 474 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
	goto st263;
st263:
	if ( ++p == pe )
		goto _test_eof263;
case 263:
#line 1694 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr313;
		case 13: goto st234;
	}
	goto st0;
tr311:
#line 126 "mfilescanner.rl"
	{
             string s(tmp_p, p - tmp_p);
             returnlist_.push_back(s);
             return_list_[s] = DocuBlock();
             cout << "ret::substitutestart::" << s << "::retsubstituteend ";
           }
#line 471 "mfilescanner.rl"
	{opt=true;}
	goto st264;
tr319:
#line 471 "mfilescanner.rl"
	{opt=true;}
	goto st264;
tr376:
#line 28 "mfilescanner.rl"
	{line++;}
#line 78 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 471 "mfilescanner.rl"
	{opt=true;}
	goto st264;
tr379:
#line 28 "mfilescanner.rl"
	{line++;}
#line 471 "mfilescanner.rl"
	{opt=true;}
	goto st264;
st264:
	if ( ++p == pe )
		goto _test_eof264;
case 264:
#line 1736 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr319;
		case 32: goto tr319;
		case 37: goto tr372;
		case 46: goto st266;
		case 95: goto tr374;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr374;
	} else if ( (*p) >= 65 )
		goto tr374;
	goto st0;
tr372:
#line 85 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st265;
st265:
	if ( ++p == pe )
		goto _test_eof265;
case 265:
#line 1758 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr376;
	}
	goto st265;
st266:
	if ( ++p == pe )
		goto _test_eof266;
case 266:
	if ( (*p) == 46 )
		goto st267;
	goto st0;
st267:
	if ( ++p == pe )
		goto _test_eof267;
case 267:
	if ( (*p) == 46 )
		goto st268;
	goto st0;
st268:
	if ( ++p == pe )
		goto _test_eof268;
case 268:
	switch( (*p) ) {
		case 9: goto st268;
		case 10: goto tr379;
		case 13: goto st269;
		case 32: goto st268;
	}
	goto st0;
st269:
	if ( ++p == pe )
		goto _test_eof269;
case 269:
	if ( (*p) == 10 )
		goto tr379;
	goto st0;
tr374:
#line 58 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st270;
st270:
	if ( ++p == pe )
		goto _test_eof270;
case 270:
#line 1804 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr381;
		case 10: goto tr304;
		case 13: goto tr305;
		case 32: goto tr381;
		case 37: goto tr306;
		case 40: goto tr307;
		case 46: goto tr308;
		case 59: goto tr310;
		case 95: goto st270;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st270;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st270;
	} else
		goto st270;
	goto st0;
tr393:
#line 28 "mfilescanner.rl"
	{line++;}
	goto st271;
tr296:
#line 133 "mfilescanner.rl"
	{cout << "rets::substitutestart::";}
	goto st271;
tr390:
#line 28 "mfilescanner.rl"
	{line++;}
#line 78 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st271;
tr385:
#line 109 "mfilescanner.rl"
	{ cout << "::"; }
	goto st271;
tr395:
#line 111 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            returnlist_.push_back(s);
            return_list_[s] = DocuBlock();
            cout << s;
          }
	goto st271;
tr397:
#line 111 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            returnlist_.push_back(s);
            return_list_[s] = DocuBlock();
            cout << s;
          }
#line 109 "mfilescanner.rl"
	{ cout << "::"; }
	goto st271;
st271:
	if ( ++p == pe )
		goto _test_eof271;
case 271:
#line 1870 "mfilescanner.cc"
	switch( (*p) ) {
		case 32: goto st271;
		case 37: goto tr384;
		case 44: goto tr385;
		case 46: goto st273;
		case 93: goto tr388;
		case 95: goto tr387;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto st271;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr387;
	} else
		goto tr387;
	goto st0;
tr384:
#line 85 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st272;
tr396:
#line 111 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            returnlist_.push_back(s);
            return_list_[s] = DocuBlock();
            cout << s;
          }
#line 85 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st272;
st272:
	if ( ++p == pe )
		goto _test_eof272;
case 272:
#line 1907 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr390;
	}
	goto st272;
tr398:
#line 111 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            returnlist_.push_back(s);
            return_list_[s] = DocuBlock();
            cout << s;
          }
	goto st273;
st273:
	if ( ++p == pe )
		goto _test_eof273;
case 273:
#line 1926 "mfilescanner.cc"
	if ( (*p) == 46 )
		goto st274;
	goto st0;
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
	switch( (*p) ) {
		case 9: goto st275;
		case 10: goto tr393;
		case 13: goto st276;
		case 32: goto st275;
	}
	goto st0;
st276:
	if ( ++p == pe )
		goto _test_eof276;
case 276:
	if ( (*p) == 10 )
		goto tr393;
	goto st0;
tr387:
#line 58 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st277;
st277:
	if ( ++p == pe )
		goto _test_eof277;
case 277:
#line 1963 "mfilescanner.cc"
	switch( (*p) ) {
		case 32: goto tr395;
		case 37: goto tr396;
		case 44: goto tr397;
		case 46: goto tr398;
		case 93: goto tr400;
		case 95: goto st277;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr395;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st277;
		} else if ( (*p) >= 65 )
			goto st277;
	} else
		goto st277;
	goto st0;
tr401:
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st278;
tr388:
#line 135 "mfilescanner.rl"
	{cout << "::retssubstituteend ";}
	goto st278;
tr400:
#line 111 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            returnlist_.push_back(s);
            return_list_[s] = DocuBlock();
            cout << s;
          }
#line 135 "mfilescanner.rl"
	{cout << "::retssubstituteend ";}
	goto st278;
st278:
	if ( ++p == pe )
		goto _test_eof278;
case 278:
#line 2007 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr401;
		case 32: goto tr401;
		case 61: goto tr319;
	}
	goto st0;
tr16:
#line 28 "mfilescanner.rl"
	{line++;}
#line 35 "mfilescanner.rl"
	{ cout.write(tmp_p, p - tmp_p+1); }
	goto st280;
st280:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof280;
case 280:
#line 2026 "mfilescanner.cc"
	if ( (*p) == 37 )
		goto tr403;
	goto tr15;
tr403:
#line 33 "mfilescanner.rl"
	{ tmp_p = p+1; cout << " *"; }
	goto st12;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
#line 2038 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr15;
		case 10: goto tr16;
	}
	goto st12;
tr17:
#line 216 "mfilescanner.rl"
	{{p = ((te))-1;}{ cout << (*p); }}
	goto st281;
tr19:
#line 28 "mfilescanner.rl"
	{line++;}
#line 78 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 150 "mfilescanner.rl"
	{te = p+1;}
	goto st281;
tr21:
#line 28 "mfilescanner.rl"
	{line++;}
#line 148 "mfilescanner.rl"
	{te = p+1;{ cout.write(ts, te-ts); }}
	goto st281;
tr23:
#line 213 "mfilescanner.rl"
	{{p = ((te))-1;}{ cout.write(ts, te-ts); }}
	goto st281;
tr36:
#line 28 "mfilescanner.rl"
	{line++;}
#line 198 "mfilescanner.rl"
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
	goto st281;
tr404:
#line 216 "mfilescanner.rl"
	{te = p+1;{ cout << (*p); }}
	goto st281;
tr406:
#line 28 "mfilescanner.rl"
	{line++;}
#line 219 "mfilescanner.rl"
	{te = p+1;{ cout << (*p); {goto st303;} }}
	goto st281;
tr412:
#line 145 "mfilescanner.rl"
	{te = p;p--;{ cout.write(ts, te-ts); }}
	goto st281;
tr413:
#line 216 "mfilescanner.rl"
	{te = p;p--;{ cout << (*p); }}
	goto st281;
tr415:
#line 213 "mfilescanner.rl"
	{te = p;p--;{ cout.write(ts, te-ts); }}
	goto st281;
tr417:
#line 160 "mfilescanner.rl"
	{te = p;p--;{
      string s(tmp_p, p - tmp_p+1);
      cout << tmp_string << "." << s;
      typedef DocuListMap :: iterator map_iterator;
      typedef DocuList :: iterator iterator;
      map_iterator moit = optional_list_.find(tmp_string);
      if(moit != optional_list_.end())
      {
        iterator oit = (*moit).second.find(s);
        if(oit == (*moit).second.end())
        {
          (*moit).second[s] = DocuBlock();
        }
      }
      else
      {
        map_iterator mrit = required_list_.find(tmp_string);
        if(mrit != required_list_.end())
        {
          optional_list_[tmp_string][s] = DocuBlock();
        }
      }
    }}
	goto st281;
st281:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof281;
case 281:
#line 1 "NONE"
	{ts = p;}
#line 2143 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st282;
		case 10: goto tr406;
		case 13: goto st283;
		case 32: goto st282;
		case 37: goto tr408;
		case 46: goto tr409;
		case 95: goto tr410;
		case 100: goto tr411;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr410;
	} else if ( (*p) >= 65 )
		goto tr410;
	goto tr404;
st282:
	if ( ++p == pe )
		goto _test_eof282;
case 282:
	switch( (*p) ) {
		case 9: goto st282;
		case 32: goto st282;
	}
	goto tr412;
st283:
	if ( ++p == pe )
		goto _test_eof283;
case 283:
	if ( (*p) == 10 )
		goto tr406;
	goto tr413;
tr408:
#line 1 "NONE"
	{te = p+1;}
#line 150 "mfilescanner.rl"
	{ tmp_p = p + 1; }
	goto st284;
st284:
	if ( ++p == pe )
		goto _test_eof284;
case 284:
#line 2187 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr413;
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
tr409:
#line 1 "NONE"
	{te = p+1;}
	goto st285;
st285:
	if ( ++p == pe )
		goto _test_eof285;
case 285:
#line 2210 "mfilescanner.cc"
	if ( (*p) == 46 )
		goto st14;
	goto tr413;
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
tr410:
#line 1 "NONE"
	{te = p+1;}
	goto st286;
st286:
	if ( ++p == pe )
		goto _test_eof286;
case 286:
#line 2247 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr416;
		case 95: goto tr410;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr410;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr410;
	} else
		goto tr410;
	goto tr415;
tr416:
#line 154 "mfilescanner.rl"
	{tmp_string.assign(ts,p-ts);}
	goto st17;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
#line 2269 "mfilescanner.cc"
	if ( (*p) == 95 )
		goto tr24;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr24;
	} else if ( (*p) >= 65 )
		goto tr24;
	goto tr23;
tr24:
#line 58 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st287;
st287:
	if ( ++p == pe )
		goto _test_eof287;
case 287:
#line 2286 "mfilescanner.cc"
	if ( (*p) == 95 )
		goto st287;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st287;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st287;
	} else
		goto st287;
	goto tr417;
tr411:
#line 1 "NONE"
	{te = p+1;}
	goto st288;
st288:
	if ( ++p == pe )
		goto _test_eof288;
case 288:
#line 2306 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr416;
		case 95: goto tr410;
		case 105: goto tr419;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr410;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr410;
	} else
		goto tr410;
	goto tr415;
tr419:
#line 1 "NONE"
	{te = p+1;}
	goto st289;
st289:
	if ( ++p == pe )
		goto _test_eof289;
case 289:
#line 2329 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr416;
		case 95: goto tr410;
		case 115: goto tr420;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr410;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr410;
	} else
		goto tr410;
	goto tr415;
tr420:
#line 1 "NONE"
	{te = p+1;}
	goto st290;
st290:
	if ( ++p == pe )
		goto _test_eof290;
case 290:
#line 2352 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr416;
		case 95: goto tr410;
		case 112: goto tr421;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr410;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr410;
	} else
		goto tr410;
	goto tr415;
tr421:
#line 1 "NONE"
	{te = p+1;}
	goto st291;
st291:
	if ( ++p == pe )
		goto _test_eof291;
case 291:
#line 2375 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr416;
		case 95: goto tr422;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr410;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr410;
	} else
		goto tr410;
	goto tr415;
tr422:
#line 1 "NONE"
	{te = p+1;}
	goto st292;
st292:
	if ( ++p == pe )
		goto _test_eof292;
case 292:
#line 2397 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr416;
		case 95: goto tr410;
		case 100: goto tr423;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr410;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr410;
	} else
		goto tr410;
	goto tr415;
tr423:
#line 1 "NONE"
	{te = p+1;}
	goto st293;
st293:
	if ( ++p == pe )
		goto _test_eof293;
case 293:
#line 2420 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr416;
		case 95: goto tr410;
		case 101: goto tr424;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr410;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr410;
	} else
		goto tr410;
	goto tr415;
tr424:
#line 1 "NONE"
	{te = p+1;}
	goto st294;
st294:
	if ( ++p == pe )
		goto _test_eof294;
case 294:
#line 2443 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr416;
		case 95: goto tr410;
		case 112: goto tr425;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr410;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr410;
	} else
		goto tr410;
	goto tr415;
tr425:
#line 1 "NONE"
	{te = p+1;}
	goto st295;
st295:
	if ( ++p == pe )
		goto _test_eof295;
case 295:
#line 2466 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr416;
		case 95: goto tr410;
		case 114: goto tr426;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr410;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr410;
	} else
		goto tr410;
	goto tr415;
tr426:
#line 1 "NONE"
	{te = p+1;}
	goto st296;
st296:
	if ( ++p == pe )
		goto _test_eof296;
case 296:
#line 2489 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr416;
		case 95: goto tr410;
		case 101: goto tr427;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr410;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr410;
	} else
		goto tr410;
	goto tr415;
tr427:
#line 1 "NONE"
	{te = p+1;}
	goto st297;
st297:
	if ( ++p == pe )
		goto _test_eof297;
case 297:
#line 2512 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr416;
		case 95: goto tr410;
		case 99: goto tr428;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr410;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr410;
	} else
		goto tr410;
	goto tr415;
tr428:
#line 1 "NONE"
	{te = p+1;}
	goto st298;
st298:
	if ( ++p == pe )
		goto _test_eof298;
case 298:
#line 2535 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr416;
		case 95: goto tr410;
		case 97: goto tr429;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr410;
	} else if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr410;
	} else
		goto tr410;
	goto tr415;
tr429:
#line 1 "NONE"
	{te = p+1;}
	goto st299;
st299:
	if ( ++p == pe )
		goto _test_eof299;
case 299:
#line 2558 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr416;
		case 95: goto tr410;
		case 116: goto tr430;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr410;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr410;
	} else
		goto tr410;
	goto tr415;
tr430:
#line 1 "NONE"
	{te = p+1;}
	goto st300;
st300:
	if ( ++p == pe )
		goto _test_eof300;
case 300:
#line 2581 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr416;
		case 95: goto tr410;
		case 101: goto tr431;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr410;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr410;
	} else
		goto tr410;
	goto tr415;
tr431:
#line 1 "NONE"
	{te = p+1;}
	goto st301;
st301:
	if ( ++p == pe )
		goto _test_eof301;
case 301:
#line 2604 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr416;
		case 95: goto tr410;
		case 100: goto tr432;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr410;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr410;
	} else
		goto tr410;
	goto tr415;
tr432:
#line 1 "NONE"
	{te = p+1;}
	goto st302;
st302:
	if ( ++p == pe )
		goto _test_eof302;
case 302:
#line 2627 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st18;
		case 32: goto st18;
		case 40: goto st19;
		case 46: goto tr416;
		case 59: goto tr27;
		case 95: goto tr410;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr410;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr410;
	} else
		goto tr410;
	goto tr415;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
	switch( (*p) ) {
		case 9: goto st18;
		case 32: goto st18;
		case 40: goto st19;
		case 59: goto tr27;
	}
	goto tr23;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
	switch( (*p) ) {
		case 9: goto st19;
		case 32: goto st19;
		case 39: goto st20;
	}
	goto tr23;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
	switch( (*p) ) {
		case 10: goto tr23;
		case 39: goto tr30;
	}
	goto tr29;
tr29:
#line 58 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st21;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
#line 2683 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr23;
		case 39: goto tr32;
	}
	goto st21;
tr30:
#line 58 "mfilescanner.rl"
	{ tmp_p = p; }
#line 62 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st22;
tr32:
#line 62 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st22;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
#line 2703 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st22;
		case 32: goto st22;
		case 41: goto st23;
	}
	goto tr23;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	switch( (*p) ) {
		case 9: goto st23;
		case 32: goto st23;
		case 59: goto st24;
	}
	goto tr23;
tr27:
#line 187 "mfilescanner.rl"
	{tmp_string.assign("");}
	goto st24;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
#line 2728 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st24;
		case 10: goto tr36;
		case 13: goto st25;
		case 32: goto st24;
	}
	goto tr23;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
	if ( (*p) == 10 )
		goto tr36;
	goto tr23;
tr41:
#line 28 "mfilescanner.rl"
	{line++;}
#line 247 "mfilescanner.rl"
	{te = p+1;{
          p = ts-1;
          {goto st281;}
        }}
	goto st303;
tr45:
#line 28 "mfilescanner.rl"
	{line++;}
#line 78 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 247 "mfilescanner.rl"
	{te = p+1;{
          p = ts-1;
          {goto st281;}
        }}
	goto st303;
tr49:
#line 247 "mfilescanner.rl"
	{{p = ((te))-1;}{
          p = ts-1;
          {goto st281;}
        }}
	goto st303;
tr51:
#line 28 "mfilescanner.rl"
	{line++;}
#line 240 "mfilescanner.rl"
	{te = p+1;{ cout << '\n'; }}
	goto st303;
tr58:
#line 28 "mfilescanner.rl"
	{line++;}
#line 233 "mfilescanner.rl"
	{te = p+1;{
          cout.write(tmp_p, p - tmp_p+1);
          {stack[top++] = 303; goto st280;}
        }}
	goto st303;
tr66:
#line 254 "mfilescanner.rl"
	{te = p+1;{
        p = ts-1;
        end_function();
        {goto st279;}
      }}
	goto st303;
tr96:
#line 227 "mfilescanner.rl"
	{te = p+1;{
          new_syntax_ = true;
          cout << "*/\n"; //cout << "add to special group */\n";
        }}
#line 28 "mfilescanner.rl"
	{line++;}
	goto st303;
tr433:
#line 260 "mfilescanner.rl"
	{te = p+1;}
	goto st303;
tr435:
#line 247 "mfilescanner.rl"
	{te = p;p--;{
          p = ts-1;
          {goto st281;}
        }}
	goto st303;
st303:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof303;
case 303:
#line 1 "NONE"
	{ts = p;}
#line 2824 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr433;
		case 9: goto st32;
		case 10: goto tr51;
		case 13: goto st33;
		case 32: goto st32;
		case 37: goto st44;
		case 102: goto st36;
	}
	goto st26;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st304;
		case 10: goto tr41;
		case 32: goto st304;
		case 37: goto tr42;
		case 46: goto st28;
	}
	goto st26;
st304:
	if ( ++p == pe )
		goto _test_eof304;
case 304:
	switch( (*p) ) {
		case 9: goto st304;
		case 32: goto st304;
	}
	goto tr435;
tr42:
#line 85 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st27;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
#line 2865 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr45;
	}
	goto st27;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st304;
		case 10: goto tr41;
		case 32: goto st304;
		case 37: goto tr42;
		case 46: goto st29;
	}
	goto st26;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st304;
		case 10: goto tr41;
		case 32: goto st304;
		case 37: goto tr42;
		case 46: goto st30;
	}
	goto st26;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr48;
		case 10: goto tr41;
		case 32: goto tr48;
		case 37: goto tr42;
		case 46: goto st30;
	}
	goto st26;
tr48:
#line 1 "NONE"
	{te = p+1;}
	goto st305;
st305:
	if ( ++p == pe )
		goto _test_eof305;
case 305:
#line 2918 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr48;
		case 10: goto tr41;
		case 13: goto st31;
		case 32: goto tr48;
	}
	goto tr435;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
	if ( (*p) == 10 )
		goto tr41;
	goto tr49;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st32;
		case 10: goto tr51;
		case 13: goto st33;
		case 32: goto st32;
		case 37: goto st34;
		case 102: goto st36;
	}
	goto st26;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st304;
		case 10: goto tr51;
		case 32: goto st304;
		case 37: goto tr42;
		case 46: goto st28;
	}
	goto st26;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
	switch( (*p) ) {
		case 0: goto st0;
		case 124: goto tr56;
	}
	goto tr55;
tr55:
#line 68 "mfilescanner.rl"
	{ cout << "/*"; tmp_p = p; }
	goto st35;
tr56:
#line 66 "mfilescanner.rl"
	{ cout << "/**"; tmp_p = p+1; }
	goto st35;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
#line 2981 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr58;
	}
	goto st35;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st304;
		case 10: goto tr41;
		case 32: goto st304;
		case 37: goto tr42;
		case 46: goto st28;
		case 117: goto st37;
	}
	goto st26;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st304;
		case 10: goto tr41;
		case 32: goto st304;
		case 37: goto tr42;
		case 46: goto st28;
		case 110: goto st38;
	}
	goto st26;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st304;
		case 10: goto tr41;
		case 32: goto st304;
		case 37: goto tr42;
		case 46: goto st28;
		case 99: goto st39;
	}
	goto st26;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st304;
		case 10: goto tr41;
		case 32: goto st304;
		case 37: goto tr42;
		case 46: goto st28;
		case 116: goto st40;
	}
	goto st26;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st304;
		case 10: goto tr41;
		case 32: goto st304;
		case 37: goto tr42;
		case 46: goto st28;
		case 105: goto st41;
	}
	goto st26;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st304;
		case 10: goto tr41;
		case 32: goto st304;
		case 37: goto tr42;
		case 46: goto st28;
		case 111: goto st42;
	}
	goto st26;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st304;
		case 10: goto tr41;
		case 32: goto st304;
		case 37: goto tr42;
		case 46: goto st28;
		case 110: goto st43;
	}
	goto st26;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
	switch( (*p) ) {
		case 0: goto st0;
		case 32: goto tr66;
		case 37: goto st0;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st0;
	goto st26;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
	switch( (*p) ) {
		case 0: goto st0;
		case 32: goto tr67;
		case 124: goto tr56;
	}
	goto tr55;
tr67:
#line 68 "mfilescanner.rl"
	{ cout << "/*"; tmp_p = p; }
	goto st45;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
#line 3115 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr58;
		case 84: goto st46;
	}
	goto st35;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr58;
		case 79: goto st47;
	}
	goto st35;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr58;
		case 32: goto st48;
	}
	goto st35;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr58;
		case 66: goto st49;
	}
	goto st35;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr58;
		case 69: goto st50;
	}
	goto st35;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr58;
		case 32: goto st51;
	}
	goto st35;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr58;
		case 65: goto st52;
	}
	goto st35;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr58;
		case 68: goto st53;
	}
	goto st35;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr58;
		case 74: goto st54;
	}
	goto st35;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr58;
		case 85: goto st55;
	}
	goto st35;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr58;
		case 83: goto st56;
	}
	goto st35;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr58;
		case 84: goto st57;
	}
	goto st35;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr58;
		case 69: goto st58;
	}
	goto st35;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr58;
		case 68: goto st59;
	}
	goto st35;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr58;
		case 32: goto st60;
	}
	goto st35;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr58;
		case 84: goto st61;
	}
	goto st35;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr58;
		case 79: goto st62;
	}
	goto st35;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr58;
		case 32: goto st63;
	}
	goto st35;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr58;
		case 78: goto st64;
	}
	goto st35;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr58;
		case 69: goto st65;
	}
	goto st35;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr58;
		case 87: goto st66;
	}
	goto st35;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr58;
		case 32: goto st67;
	}
	goto st35;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr58;
		case 83: goto st68;
	}
	goto st35;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr58;
		case 89: goto st69;
	}
	goto st35;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr58;
		case 78: goto st70;
	}
	goto st35;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr58;
		case 84: goto st71;
	}
	goto st35;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr58;
		case 65: goto st72;
	}
	goto st35;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr58;
		case 88: goto st73;
	}
	goto st35;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr96;
	}
	goto st35;
tr97:
#line 1 "NONE"
	{	switch( act ) {
	case 0:
	{{goto st0;}}
	break;
	case 18:
	{{p = ((te))-1;}
      p =ts-1;
      // cout << "*/\n";
      {cs = stack[--top];goto _again;}
    }
	break;
	}
	}
	goto st306;
tr100:
#line 28 "mfilescanner.rl"
	{line++;}
#line 298 "mfilescanner.rl"
	{te = p+1;{ /*cout << "empty line\n";*/ {cs = stack[--top];goto _again;} }}
	goto st306;
tr105:
#line 28 "mfilescanner.rl"
	{line++;}
#line 290 "mfilescanner.rl"
	{te = p+1;{
      string s(tmp_p, p - tmp_p + 1);
      (*clist_)[tmp_string].push_back(s);
      /*cout << "add something results in\n" << (*clist_)[tmp_string];*/
    }}
	goto st306;
tr114:
#line 28 "mfilescanner.rl"
	{line++;}
#line 271 "mfilescanner.rl"
	{te = p+1;{
      tmp_string.assign(tmp_p3, tmp_p2 - tmp_p3);
      //    std::cout << tmp_string << '\n';
      (*clist_)[tmp_string].push_back(string(tmp_p+1, p - tmp_p));
    }}
	goto st306;
tr437:
#line 302 "mfilescanner.rl"
	{te = p+1;{
      p =ts-1;
      // cout << "*/\n";
      {cs = stack[--top];goto _again;}
    }}
	goto st306;
tr439:
#line 28 "mfilescanner.rl"
	{line++;}
#line 302 "mfilescanner.rl"
	{te = p+1;{
      p =ts-1;
      // cout << "*/\n";
      {cs = stack[--top];goto _again;}
    }}
	goto st306;
tr442:
#line 302 "mfilescanner.rl"
	{te = p;p--;{
      p =ts-1;
      // cout << "*/\n";
      {cs = stack[--top];goto _again;}
    }}
	goto st306;
st306:
#line 1 "NONE"
	{ts = 0;}
#line 1 "NONE"
	{act = 0;}
	if ( ++p == pe )
		goto _test_eof306;
case 306:
#line 1 "NONE"
	{ts = p;}
#line 3479 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr438;
		case 10: goto tr439;
		case 13: goto st308;
		case 32: goto tr438;
		case 37: goto tr441;
	}
	goto tr437;
tr438:
#line 1 "NONE"
	{te = p+1;}
#line 302 "mfilescanner.rl"
	{act = 18;}
	goto st307;
st307:
	if ( ++p == pe )
		goto _test_eof307;
case 307:
#line 3499 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr442;
		case 9: goto tr438;
		case 10: goto tr439;
		case 13: goto st308;
		case 32: goto tr438;
		case 37: goto tr441;
	}
	goto tr437;
st308:
	if ( ++p == pe )
		goto _test_eof308;
case 308:
	if ( (*p) == 10 )
		goto tr439;
	goto tr442;
tr441:
#line 74 "mfilescanner.rl"
	{ tmp_p = p + 1; }
	goto st74;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
#line 3524 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr97;
		case 9: goto st74;
		case 10: goto tr100;
		case 13: goto st78;
		case 32: goto st74;
		case 39: goto st79;
		case 58: goto tr97;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr103;
	} else if ( (*p) >= 65 )
		goto tr103;
	goto st75;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
	switch( (*p) ) {
		case 0: goto tr97;
		case 9: goto st76;
		case 10: goto tr105;
		case 32: goto st76;
		case 58: goto tr97;
	}
	goto st75;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
	switch( (*p) ) {
		case 9: goto st76;
		case 10: goto tr105;
		case 32: goto st76;
		case 58: goto tr97;
	}
	goto st77;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
	switch( (*p) ) {
		case 0: goto tr97;
		case 10: goto tr105;
	}
	goto st77;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
	switch( (*p) ) {
		case 0: goto tr97;
		case 9: goto st76;
		case 10: goto tr105;
		case 32: goto st76;
		case 58: goto tr97;
	}
	goto st75;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
	switch( (*p) ) {
		case 0: goto tr97;
		case 9: goto st76;
		case 10: goto tr105;
		case 32: goto st76;
		case 58: goto tr97;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr103;
	} else if ( (*p) >= 65 )
		goto tr103;
	goto st75;
tr103:
#line 268 "mfilescanner.rl"
	{tmp_p3 = p;}
	goto st80;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
#line 3609 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr97;
		case 9: goto tr107;
		case 10: goto tr105;
		case 32: goto tr107;
		case 39: goto tr108;
		case 46: goto st80;
		case 58: goto tr110;
		case 93: goto st80;
		case 95: goto st80;
		case 125: goto st80;
	}
	if ( (*p) < 48 ) {
		if ( 40 <= (*p) && (*p) <= 41 )
			goto st80;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 123 )
				goto st80;
		} else if ( (*p) >= 65 )
			goto st80;
	} else
		goto st80;
	goto st75;
tr107:
#line 268 "mfilescanner.rl"
	{tmp_p2 = p;}
	goto st81;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
#line 3642 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st81;
		case 10: goto tr105;
		case 32: goto st81;
		case 58: goto tr112;
	}
	goto st77;
tr112:
#line 58 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st82;
tr110:
#line 268 "mfilescanner.rl"
	{tmp_p2 = p;}
#line 58 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st82;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
#line 3664 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr97;
		case 10: goto tr114;
	}
	goto st82;
tr108:
#line 268 "mfilescanner.rl"
	{tmp_p2 = p;}
	goto st83;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
#line 3678 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr97;
		case 9: goto st81;
		case 10: goto tr105;
		case 32: goto st81;
		case 58: goto tr112;
	}
	goto st75;
tr115:
#line 1 "NONE"
	{	switch( act ) {
	case 0:
	{{goto st0;}}
	break;
	case 26:
	{{p = ((te))-1;}
        p--;
        // cout << "*/\n";
        {goto st303;}
      }
	break;
	}
	}
	goto st309;
tr119:
#line 28 "mfilescanner.rl"
	{line++;}
#line 384 "mfilescanner.rl"
	{te = p+1;{
        /*cout << "*\n  ";*/
        docubody_.push_back("\n");
      }}
	goto st309;
tr125:
#line 28 "mfilescanner.rl"
	{line++;}
#line 377 "mfilescanner.rl"
	{te = p+1;{
        /*cout << "*"; cout.write(tmp_p, p - tmp_p+1) << "  ";*/
        docubody_.push_back(string(tmp_p, p - tmp_p + 1));
      }}
	goto st309;
tr136:
#line 314 "mfilescanner.rl"
	{tmp_p2 = p;}
#line 28 "mfilescanner.rl"
	{line++;}
#line 317 "mfilescanner.rl"
	{te = p+1;{
        string s, res;
        s.assign(tmp_p, p - tmp_p + 1);
        string::size_type size = string("see also").size();
        string::size_type loc = tmp_p2 - tmp_p - size;
        res = s.substr(0, loc) + "@sa" + s.substr(loc + size);
        /*        cout << "*"; cout << res << "  "; */
        docubody_.push_back(res);
      }}
	goto st309;
tr140:
#line 28 "mfilescanner.rl"
	{line++;}
#line 317 "mfilescanner.rl"
	{te = p+1;{
        string s, res;
        s.assign(tmp_p, p - tmp_p + 1);
        string::size_type size = string("see also").size();
        string::size_type loc = tmp_p2 - tmp_p - size;
        res = s.substr(0, loc) + "@sa" + s.substr(loc + size);
        /*        cout << "*"; cout << res << "  "; */
        docubody_.push_back(res);
      }}
	goto st309;
tr161:
#line 28 "mfilescanner.rl"
	{line++;}
#line 355 "mfilescanner.rl"
	{te = p+1;{
        clist_ = &param_list_;
        {stack[top++] = 309; goto st306;}
      }}
	goto st309;
tr189:
#line 28 "mfilescanner.rl"
	{line++;}
#line 346 "mfilescanner.rl"
	{te = p+1;{
        clist_ = &(optional_list_[tmp_string]);
        {stack[top++] = 309; goto st306;}
      }}
	goto st309;
tr221:
#line 28 "mfilescanner.rl"
	{line++;}
#line 333 "mfilescanner.rl"
	{te = p+1;{
        //cout << tmp_string << '\n';
        clist_ = &(required_list_[tmp_string]);
        {stack[top++] = 309; goto st306;}
      }}
	goto st309;
tr241:
#line 28 "mfilescanner.rl"
	{line++;}
#line 364 "mfilescanner.rl"
	{te = p+1;{
        clist_ = &return_list_;
        {stack[top++] = 309; goto st306;}
      }}
	goto st309;
tr443:
#line 391 "mfilescanner.rl"
	{te = p+1;{
        p--;
        // cout << "*/\n";
        {goto st303;}
      }}
	goto st309;
tr445:
#line 28 "mfilescanner.rl"
	{line++;}
#line 391 "mfilescanner.rl"
	{te = p+1;{
        p--;
        // cout << "*/\n";
        {goto st303;}
      }}
	goto st309;
tr448:
#line 391 "mfilescanner.rl"
	{te = p;p--;{
        p--;
        // cout << "*/\n";
        {goto st303;}
      }}
	goto st309;
st309:
#line 1 "NONE"
	{ts = 0;}
#line 1 "NONE"
	{act = 0;}
	if ( ++p == pe )
		goto _test_eof309;
case 309:
#line 1 "NONE"
	{ts = p;}
#line 3824 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr444;
		case 10: goto tr445;
		case 13: goto st311;
		case 32: goto tr444;
		case 37: goto tr447;
	}
	goto tr443;
tr444:
#line 1 "NONE"
	{te = p+1;}
#line 391 "mfilescanner.rl"
	{act = 26;}
	goto st310;
st310:
	if ( ++p == pe )
		goto _test_eof310;
case 310:
#line 3844 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr448;
		case 9: goto tr444;
		case 10: goto tr445;
		case 13: goto st311;
		case 32: goto tr444;
		case 37: goto tr447;
	}
	goto tr443;
st311:
	if ( ++p == pe )
		goto _test_eof311;
case 311:
	if ( (*p) == 10 )
		goto tr445;
	goto tr448;
tr447:
#line 74 "mfilescanner.rl"
	{ tmp_p = p + 1; }
	goto st84;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
#line 3869 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st86;
		case 9: goto st84;
		case 10: goto tr119;
		case 13: goto st107;
		case 32: goto st84;
		case 65: goto st108;
		case 79: goto st120;
		case 82: goto st147;
		case 83: goto st88;
		case 97: goto st108;
		case 111: goto st120;
		case 114: goto st147;
		case 115: goto st88;
	}
	goto st85;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 83: goto st88;
		case 115: goto st88;
	}
	goto st85;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
	switch( (*p) ) {
		case 9: goto st86;
		case 10: goto tr125;
		case 13: goto st87;
		case 32: goto st86;
	}
	goto tr115;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
	if ( (*p) == 10 )
		goto tr125;
	goto tr115;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 69: goto st89;
		case 83: goto st88;
		case 101: goto st89;
		case 115: goto st88;
	}
	goto st85;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 69: goto st90;
		case 83: goto st88;
		case 101: goto st90;
		case 115: goto st88;
	}
	goto st85;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 32: goto st91;
		case 83: goto st88;
		case 115: goto st88;
	}
	goto st85;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 65: goto st92;
		case 83: goto st88;
		case 97: goto st92;
		case 115: goto st88;
	}
	goto st85;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 76: goto st93;
		case 83: goto st88;
		case 108: goto st93;
		case 115: goto st88;
	}
	goto st85;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 83: goto st94;
		case 115: goto st94;
	}
	goto st85;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 69: goto st89;
		case 79: goto st95;
		case 83: goto st88;
		case 101: goto st89;
		case 111: goto st95;
		case 115: goto st88;
	}
	goto st85;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
	switch( (*p) ) {
		case 0: goto tr115;
		case 9: goto tr135;
		case 10: goto tr136;
		case 13: goto tr137;
		case 32: goto tr135;
		case 83: goto tr138;
		case 115: goto tr138;
	}
	goto tr134;
tr134:
#line 314 "mfilescanner.rl"
	{tmp_p2 = p;}
	goto st96;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
#line 4027 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr115;
		case 10: goto tr140;
		case 83: goto st97;
		case 115: goto st97;
	}
	goto st96;
tr138:
#line 314 "mfilescanner.rl"
	{tmp_p2 = p;}
	goto st97;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
#line 4043 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr115;
		case 10: goto tr140;
		case 69: goto st98;
		case 83: goto st97;
		case 101: goto st98;
		case 115: goto st97;
	}
	goto st96;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
	switch( (*p) ) {
		case 0: goto tr115;
		case 10: goto tr140;
		case 69: goto st99;
		case 83: goto st97;
		case 101: goto st99;
		case 115: goto st97;
	}
	goto st96;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
	switch( (*p) ) {
		case 0: goto tr115;
		case 10: goto tr140;
		case 32: goto st100;
		case 83: goto st97;
		case 115: goto st97;
	}
	goto st96;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
	switch( (*p) ) {
		case 0: goto tr115;
		case 10: goto tr140;
		case 65: goto st101;
		case 83: goto st97;
		case 97: goto st101;
		case 115: goto st97;
	}
	goto st96;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
	switch( (*p) ) {
		case 0: goto tr115;
		case 10: goto tr140;
		case 76: goto st102;
		case 83: goto st97;
		case 108: goto st102;
		case 115: goto st97;
	}
	goto st96;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
	switch( (*p) ) {
		case 0: goto tr115;
		case 10: goto tr140;
		case 83: goto st103;
		case 115: goto st103;
	}
	goto st96;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
	switch( (*p) ) {
		case 0: goto tr115;
		case 10: goto tr140;
		case 69: goto st98;
		case 79: goto st104;
		case 83: goto st97;
		case 101: goto st98;
		case 111: goto st104;
		case 115: goto st97;
	}
	goto st96;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
	switch( (*p) ) {
		case 0: goto tr115;
		case 10: goto tr136;
		case 83: goto tr138;
		case 115: goto tr138;
	}
	goto tr134;
tr135:
#line 314 "mfilescanner.rl"
	{tmp_p2 = p;}
	goto st105;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
#line 4149 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr115;
		case 9: goto st105;
		case 10: goto tr140;
		case 13: goto st106;
		case 32: goto st105;
		case 83: goto st97;
		case 115: goto st97;
	}
	goto st96;
tr137:
#line 314 "mfilescanner.rl"
	{tmp_p2 = p;}
	goto st106;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
#line 4168 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr115;
		case 10: goto tr140;
		case 83: goto st97;
		case 115: goto st97;
	}
	goto st96;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 83: goto st88;
		case 115: goto st88;
	}
	goto st85;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 82: goto st109;
		case 83: goto st88;
		case 114: goto st109;
		case 115: goto st88;
	}
	goto st85;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 71: goto st110;
		case 83: goto st88;
		case 103: goto st110;
		case 115: goto st88;
	}
	goto st85;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 83: goto st88;
		case 85: goto st111;
		case 115: goto st88;
		case 117: goto st111;
	}
	goto st85;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 77: goto st112;
		case 83: goto st88;
		case 109: goto st112;
		case 115: goto st88;
	}
	goto st85;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 69: goto st113;
		case 83: goto st88;
		case 101: goto st113;
		case 115: goto st88;
	}
	goto st85;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 78: goto st114;
		case 83: goto st88;
		case 110: goto st114;
		case 115: goto st88;
	}
	goto st85;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 83: goto st88;
		case 84: goto st115;
		case 115: goto st88;
		case 116: goto st115;
	}
	goto st85;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 83: goto st116;
		case 115: goto st116;
	}
	goto st85;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
	switch( (*p) ) {
		case 0: goto st86;
		case 9: goto st117;
		case 10: goto tr125;
		case 32: goto st117;
		case 58: goto st118;
		case 69: goto st89;
		case 83: goto st88;
		case 101: goto st89;
		case 115: goto st88;
	}
	goto st85;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
	switch( (*p) ) {
		case 0: goto st86;
		case 9: goto st117;
		case 10: goto tr125;
		case 32: goto st117;
		case 58: goto st118;
		case 83: goto st88;
		case 115: goto st88;
	}
	goto st85;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
	switch( (*p) ) {
		case 0: goto st86;
		case 9: goto st118;
		case 10: goto tr161;
		case 13: goto st119;
		case 32: goto st118;
		case 83: goto st88;
		case 115: goto st88;
	}
	goto st85;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr161;
		case 83: goto st88;
		case 115: goto st88;
	}
	goto st85;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 80: goto st121;
		case 83: goto st88;
		case 112: goto st121;
		case 115: goto st88;
	}
	goto st85;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 83: goto st88;
		case 84: goto st122;
		case 115: goto st88;
		case 116: goto st122;
	}
	goto st85;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 73: goto st123;
		case 83: goto st88;
		case 105: goto st123;
		case 115: goto st88;
	}
	goto st85;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 79: goto st124;
		case 83: goto st88;
		case 111: goto st124;
		case 115: goto st88;
	}
	goto st85;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 78: goto st125;
		case 83: goto st88;
		case 110: goto st125;
		case 115: goto st88;
	}
	goto st85;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 65: goto st126;
		case 83: goto st88;
		case 97: goto st126;
		case 115: goto st88;
	}
	goto st85;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 76: goto st127;
		case 83: goto st88;
		case 108: goto st127;
		case 115: goto st88;
	}
	goto st85;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 32: goto st128;
		case 83: goto st88;
		case 115: goto st88;
	}
	goto st85;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 70: goto st129;
		case 83: goto st88;
		case 102: goto st129;
		case 115: goto st88;
	}
	goto st85;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 73: goto st130;
		case 83: goto st88;
		case 105: goto st130;
		case 115: goto st88;
	}
	goto st85;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 69: goto st131;
		case 83: goto st88;
		case 101: goto st131;
		case 115: goto st88;
	}
	goto st85;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 76: goto st132;
		case 83: goto st88;
		case 108: goto st132;
		case 115: goto st88;
	}
	goto st85;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 68: goto st133;
		case 83: goto st88;
		case 100: goto st133;
		case 115: goto st88;
	}
	goto st85;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 83: goto st134;
		case 115: goto st134;
	}
	goto st85;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 32: goto st135;
		case 69: goto st89;
		case 83: goto st88;
		case 101: goto st89;
		case 115: goto st88;
	}
	goto st85;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 79: goto st136;
		case 83: goto st88;
		case 111: goto st136;
		case 115: goto st88;
	}
	goto st85;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 70: goto st137;
		case 83: goto st88;
		case 102: goto st137;
		case 115: goto st88;
	}
	goto st85;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 32: goto st138;
		case 83: goto st88;
		case 115: goto st88;
	}
	goto st85;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 83: goto tr182;
		case 95: goto tr181;
		case 115: goto tr182;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr181;
	} else if ( (*p) >= 65 )
		goto tr181;
	goto st85;
tr181:
#line 58 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st139;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
#line 4600 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st86;
		case 9: goto tr183;
		case 10: goto tr125;
		case 32: goto tr183;
		case 58: goto tr185;
		case 83: goto st143;
		case 95: goto st139;
		case 115: goto st143;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st139;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st139;
	} else
		goto st139;
	goto st85;
tr183:
#line 62 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st140;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
#line 4628 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st86;
		case 9: goto st140;
		case 10: goto tr125;
		case 32: goto st140;
		case 58: goto st141;
		case 83: goto st88;
		case 115: goto st88;
	}
	goto st85;
tr185:
#line 62 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st141;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
#line 4647 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st86;
		case 9: goto st141;
		case 10: goto tr189;
		case 13: goto st142;
		case 32: goto st141;
		case 83: goto st88;
		case 115: goto st88;
	}
	goto st85;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr189;
		case 83: goto st88;
		case 115: goto st88;
	}
	goto st85;
tr182:
#line 58 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st143;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
#line 4677 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st86;
		case 9: goto tr183;
		case 10: goto tr125;
		case 32: goto tr183;
		case 58: goto tr185;
		case 69: goto st144;
		case 83: goto st143;
		case 95: goto st139;
		case 101: goto st144;
		case 115: goto st143;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st139;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st139;
	} else
		goto st139;
	goto st85;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
	switch( (*p) ) {
		case 0: goto st86;
		case 9: goto tr183;
		case 10: goto tr125;
		case 32: goto tr183;
		case 58: goto tr185;
		case 69: goto st145;
		case 83: goto st143;
		case 95: goto st139;
		case 101: goto st145;
		case 115: goto st143;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st139;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st139;
	} else
		goto st139;
	goto st85;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
	switch( (*p) ) {
		case 0: goto st86;
		case 9: goto tr183;
		case 10: goto tr125;
		case 32: goto tr193;
		case 58: goto tr185;
		case 83: goto st143;
		case 95: goto st139;
		case 115: goto st143;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st139;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st139;
	} else
		goto st139;
	goto st85;
tr193:
#line 62 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st146;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
#line 4755 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st86;
		case 9: goto st140;
		case 10: goto tr125;
		case 32: goto st140;
		case 58: goto st141;
		case 65: goto st92;
		case 83: goto st88;
		case 97: goto st92;
		case 115: goto st88;
	}
	goto st85;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 69: goto st148;
		case 83: goto st88;
		case 101: goto st148;
		case 115: goto st88;
	}
	goto st85;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 81: goto st149;
		case 83: goto st88;
		case 84: goto st174;
		case 113: goto st149;
		case 115: goto st88;
		case 116: goto st174;
	}
	goto st85;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 83: goto st88;
		case 85: goto st150;
		case 115: goto st88;
		case 117: goto st150;
	}
	goto st85;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 73: goto st151;
		case 83: goto st88;
		case 105: goto st151;
		case 115: goto st88;
	}
	goto st85;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 82: goto st152;
		case 83: goto st88;
		case 114: goto st152;
		case 115: goto st88;
	}
	goto st85;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 69: goto st153;
		case 83: goto st88;
		case 101: goto st153;
		case 115: goto st88;
	}
	goto st85;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 68: goto st154;
		case 83: goto st88;
		case 100: goto st154;
		case 115: goto st88;
	}
	goto st85;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 32: goto st155;
		case 83: goto st88;
		case 115: goto st88;
	}
	goto st85;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 70: goto st156;
		case 83: goto st88;
		case 102: goto st156;
		case 115: goto st88;
	}
	goto st85;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 73: goto st157;
		case 83: goto st88;
		case 105: goto st157;
		case 115: goto st88;
	}
	goto st85;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 69: goto st158;
		case 83: goto st88;
		case 101: goto st158;
		case 115: goto st88;
	}
	goto st85;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 76: goto st159;
		case 83: goto st88;
		case 108: goto st159;
		case 115: goto st88;
	}
	goto st85;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 68: goto st160;
		case 83: goto st88;
		case 100: goto st160;
		case 115: goto st88;
	}
	goto st85;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 83: goto st161;
		case 115: goto st161;
	}
	goto st85;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 32: goto st162;
		case 69: goto st89;
		case 83: goto st88;
		case 101: goto st89;
		case 115: goto st88;
	}
	goto st85;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 79: goto st163;
		case 83: goto st88;
		case 111: goto st163;
		case 115: goto st88;
	}
	goto st85;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 70: goto st164;
		case 83: goto st88;
		case 102: goto st164;
		case 115: goto st88;
	}
	goto st85;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 32: goto st165;
		case 83: goto st88;
		case 115: goto st88;
	}
	goto st85;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 83: goto tr214;
		case 95: goto tr213;
		case 115: goto tr214;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr213;
	} else if ( (*p) >= 65 )
		goto tr213;
	goto st85;
tr213:
#line 58 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st166;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
#line 5026 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st86;
		case 9: goto tr215;
		case 10: goto tr125;
		case 32: goto tr215;
		case 58: goto tr217;
		case 83: goto st170;
		case 95: goto st166;
		case 115: goto st170;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st166;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st166;
	} else
		goto st166;
	goto st85;
tr215:
#line 62 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st167;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
#line 5054 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st86;
		case 9: goto st167;
		case 10: goto tr125;
		case 32: goto st167;
		case 58: goto st168;
		case 83: goto st88;
		case 115: goto st88;
	}
	goto st85;
tr217:
#line 62 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st168;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
#line 5073 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st86;
		case 9: goto st168;
		case 10: goto tr221;
		case 13: goto st169;
		case 32: goto st168;
		case 83: goto st88;
		case 115: goto st88;
	}
	goto st85;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr221;
		case 83: goto st88;
		case 115: goto st88;
	}
	goto st85;
tr214:
#line 58 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st170;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
#line 5103 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st86;
		case 9: goto tr215;
		case 10: goto tr125;
		case 32: goto tr215;
		case 58: goto tr217;
		case 69: goto st171;
		case 83: goto st170;
		case 95: goto st166;
		case 101: goto st171;
		case 115: goto st170;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st166;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st166;
	} else
		goto st166;
	goto st85;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
	switch( (*p) ) {
		case 0: goto st86;
		case 9: goto tr215;
		case 10: goto tr125;
		case 32: goto tr215;
		case 58: goto tr217;
		case 69: goto st172;
		case 83: goto st170;
		case 95: goto st166;
		case 101: goto st172;
		case 115: goto st170;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st166;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st166;
	} else
		goto st166;
	goto st85;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
	switch( (*p) ) {
		case 0: goto st86;
		case 9: goto tr215;
		case 10: goto tr125;
		case 32: goto tr225;
		case 58: goto tr217;
		case 83: goto st170;
		case 95: goto st166;
		case 115: goto st170;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st166;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st166;
	} else
		goto st166;
	goto st85;
tr225:
#line 62 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st173;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
#line 5181 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st86;
		case 9: goto st167;
		case 10: goto tr125;
		case 32: goto st167;
		case 58: goto st168;
		case 65: goto st92;
		case 83: goto st88;
		case 97: goto st92;
		case 115: goto st88;
	}
	goto st85;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 83: goto st88;
		case 85: goto st175;
		case 115: goto st88;
		case 117: goto st175;
	}
	goto st85;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 82: goto st176;
		case 83: goto st88;
		case 114: goto st176;
		case 115: goto st88;
	}
	goto st85;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 78: goto st177;
		case 83: goto st88;
		case 110: goto st177;
		case 115: goto st88;
	}
	goto st85;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 32: goto st178;
		case 83: goto st88;
		case 115: goto st88;
	}
	goto st85;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 65: goto st179;
		case 83: goto st88;
		case 97: goto st179;
		case 115: goto st88;
	}
	goto st85;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 82: goto st180;
		case 83: goto st88;
		case 114: goto st180;
		case 115: goto st88;
	}
	goto st85;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 71: goto st181;
		case 83: goto st88;
		case 103: goto st181;
		case 115: goto st88;
	}
	goto st85;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 83: goto st88;
		case 85: goto st182;
		case 115: goto st88;
		case 117: goto st182;
	}
	goto st85;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 77: goto st183;
		case 83: goto st88;
		case 109: goto st183;
		case 115: goto st88;
	}
	goto st85;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 69: goto st184;
		case 83: goto st88;
		case 101: goto st184;
		case 115: goto st88;
	}
	goto st85;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 78: goto st185;
		case 83: goto st88;
		case 110: goto st185;
		case 115: goto st88;
	}
	goto st85;
st185:
	if ( ++p == pe )
		goto _test_eof185;
case 185:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 83: goto st88;
		case 84: goto st186;
		case 115: goto st88;
		case 116: goto st186;
	}
	goto st85;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr125;
		case 83: goto st187;
		case 115: goto st187;
	}
	goto st85;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
	switch( (*p) ) {
		case 0: goto st86;
		case 9: goto st188;
		case 10: goto tr125;
		case 32: goto st188;
		case 58: goto st189;
		case 69: goto st89;
		case 83: goto st88;
		case 101: goto st89;
		case 115: goto st88;
	}
	goto st85;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
	switch( (*p) ) {
		case 0: goto st86;
		case 9: goto st188;
		case 10: goto tr125;
		case 32: goto st188;
		case 58: goto st189;
		case 83: goto st88;
		case 115: goto st88;
	}
	goto st85;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
	switch( (*p) ) {
		case 0: goto st86;
		case 9: goto st189;
		case 10: goto tr241;
		case 13: goto st190;
		case 32: goto st189;
		case 83: goto st88;
		case 115: goto st88;
	}
	goto st85;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
	switch( (*p) ) {
		case 0: goto st86;
		case 10: goto tr241;
		case 83: goto st88;
		case 115: goto st88;
	}
	goto st85;
tr246:
#line 28 "mfilescanner.rl"
	{line++;}
#line 402 "mfilescanner.rl"
	{te = p+1;}
	goto st312;
tr248:
#line 28 "mfilescanner.rl"
	{line++;}
#line 405 "mfilescanner.rl"
	{te = p+1;{ {goto st309;} }}
	goto st312;
st312:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof312;
case 312:
#line 1 "NONE"
	{ts = p;}
#line 5435 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st191;
		case 32: goto st191;
		case 37: goto tr244;
	}
	goto st0;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
	switch( (*p) ) {
		case 9: goto st191;
		case 32: goto st191;
		case 37: goto tr244;
	}
	goto st0;
tr244:
#line 74 "mfilescanner.rl"
	{ tmp_p = p + 1; }
	goto st192;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
#line 5460 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr246;
		case 41: goto st193;
		case 59: goto st193;
	}
	goto st192;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr248;
	}
	goto st193;
tr249:
#line 1 "NONE"
	{	switch( act ) {
	case 0:
	{{goto st0;}}
	break;
	case 31:
	{{p = ((te))-1;}
        p--;
        //cout << "*/\n";
        {goto st303;}
      }
	break;
	}
	}
	goto st313;
tr252:
#line 28 "mfilescanner.rl"
	{line++;}
#line 422 "mfilescanner.rl"
	{te = p+1;{
        /*cout << "*\n";*/
        {goto st309;}
      }}
	goto st313;
tr254:
#line 28 "mfilescanner.rl"
	{line++;}
#line 415 "mfilescanner.rl"
	{te = p+1;{
        /* cout << "*"; cout.write(tmp_p, p - tmp_p+1); */
        docuheader_.push_back(string(tmp_p, p - tmp_p+1));
      }}
	goto st313;
tr449:
#line 429 "mfilescanner.rl"
	{te = p+1;{
        p--;
        //cout << "*/\n";
        {goto st303;}
      }}
	goto st313;
tr452:
#line 429 "mfilescanner.rl"
	{te = p;p--;{
        p--;
        //cout << "*/\n";
        {goto st303;}
      }}
	goto st313;
st313:
#line 1 "NONE"
	{ts = 0;}
#line 1 "NONE"
	{act = 0;}
	if ( ++p == pe )
		goto _test_eof313;
case 313:
#line 1 "NONE"
	{ts = p;}
#line 5537 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr450;
		case 32: goto tr450;
		case 37: goto tr451;
	}
	goto tr449;
tr450:
#line 1 "NONE"
	{te = p+1;}
#line 429 "mfilescanner.rl"
	{act = 31;}
	goto st314;
st314:
	if ( ++p == pe )
		goto _test_eof314;
case 314:
#line 5554 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr450;
		case 32: goto tr450;
		case 37: goto tr451;
	}
	goto tr449;
tr451:
#line 74 "mfilescanner.rl"
	{ tmp_p = p + 1; }
	goto st194;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
#line 5569 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr249;
		case 9: goto st194;
		case 10: goto tr252;
		case 13: goto st196;
		case 32: goto st194;
	}
	goto st195;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
	switch( (*p) ) {
		case 0: goto tr249;
		case 10: goto tr254;
	}
	goto st195;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
	switch( (*p) ) {
		case 0: goto tr249;
		case 10: goto tr254;
	}
	goto st195;
	}
	_test_eof279: cs = 279; goto _test_eof; 
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
	_test_eof197: cs = 197; goto _test_eof; 
	_test_eof198: cs = 198; goto _test_eof; 
	_test_eof199: cs = 199; goto _test_eof; 
	_test_eof200: cs = 200; goto _test_eof; 
	_test_eof201: cs = 201; goto _test_eof; 
	_test_eof202: cs = 202; goto _test_eof; 
	_test_eof203: cs = 203; goto _test_eof; 
	_test_eof204: cs = 204; goto _test_eof; 
	_test_eof205: cs = 205; goto _test_eof; 
	_test_eof206: cs = 206; goto _test_eof; 
	_test_eof207: cs = 207; goto _test_eof; 
	_test_eof315: cs = 315; goto _test_eof; 
	_test_eof208: cs = 208; goto _test_eof; 
	_test_eof209: cs = 209; goto _test_eof; 
	_test_eof210: cs = 210; goto _test_eof; 
	_test_eof211: cs = 211; goto _test_eof; 
	_test_eof212: cs = 212; goto _test_eof; 
	_test_eof316: cs = 316; goto _test_eof; 
	_test_eof213: cs = 213; goto _test_eof; 
	_test_eof317: cs = 317; goto _test_eof; 
	_test_eof214: cs = 214; goto _test_eof; 
	_test_eof215: cs = 215; goto _test_eof; 
	_test_eof216: cs = 216; goto _test_eof; 
	_test_eof217: cs = 217; goto _test_eof; 
	_test_eof218: cs = 218; goto _test_eof; 
	_test_eof219: cs = 219; goto _test_eof; 
	_test_eof220: cs = 220; goto _test_eof; 
	_test_eof221: cs = 221; goto _test_eof; 
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
	_test_eof318: cs = 318; goto _test_eof; 
	_test_eof234: cs = 234; goto _test_eof; 
	_test_eof235: cs = 235; goto _test_eof; 
	_test_eof236: cs = 236; goto _test_eof; 
	_test_eof237: cs = 237; goto _test_eof; 
	_test_eof238: cs = 238; goto _test_eof; 
	_test_eof239: cs = 239; goto _test_eof; 
	_test_eof240: cs = 240; goto _test_eof; 
	_test_eof241: cs = 241; goto _test_eof; 
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
	_test_eof280: cs = 280; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof281: cs = 281; goto _test_eof; 
	_test_eof282: cs = 282; goto _test_eof; 
	_test_eof283: cs = 283; goto _test_eof; 
	_test_eof284: cs = 284; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof285: cs = 285; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof286: cs = 286; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof287: cs = 287; goto _test_eof; 
	_test_eof288: cs = 288; goto _test_eof; 
	_test_eof289: cs = 289; goto _test_eof; 
	_test_eof290: cs = 290; goto _test_eof; 
	_test_eof291: cs = 291; goto _test_eof; 
	_test_eof292: cs = 292; goto _test_eof; 
	_test_eof293: cs = 293; goto _test_eof; 
	_test_eof294: cs = 294; goto _test_eof; 
	_test_eof295: cs = 295; goto _test_eof; 
	_test_eof296: cs = 296; goto _test_eof; 
	_test_eof297: cs = 297; goto _test_eof; 
	_test_eof298: cs = 298; goto _test_eof; 
	_test_eof299: cs = 299; goto _test_eof; 
	_test_eof300: cs = 300; goto _test_eof; 
	_test_eof301: cs = 301; goto _test_eof; 
	_test_eof302: cs = 302; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof23: cs = 23; goto _test_eof; 
	_test_eof24: cs = 24; goto _test_eof; 
	_test_eof25: cs = 25; goto _test_eof; 
	_test_eof303: cs = 303; goto _test_eof; 
	_test_eof26: cs = 26; goto _test_eof; 
	_test_eof304: cs = 304; goto _test_eof; 
	_test_eof27: cs = 27; goto _test_eof; 
	_test_eof28: cs = 28; goto _test_eof; 
	_test_eof29: cs = 29; goto _test_eof; 
	_test_eof30: cs = 30; goto _test_eof; 
	_test_eof305: cs = 305; goto _test_eof; 
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
	_test_eof306: cs = 306; goto _test_eof; 
	_test_eof307: cs = 307; goto _test_eof; 
	_test_eof308: cs = 308; goto _test_eof; 
	_test_eof74: cs = 74; goto _test_eof; 
	_test_eof75: cs = 75; goto _test_eof; 
	_test_eof76: cs = 76; goto _test_eof; 
	_test_eof77: cs = 77; goto _test_eof; 
	_test_eof78: cs = 78; goto _test_eof; 
	_test_eof79: cs = 79; goto _test_eof; 
	_test_eof80: cs = 80; goto _test_eof; 
	_test_eof81: cs = 81; goto _test_eof; 
	_test_eof82: cs = 82; goto _test_eof; 
	_test_eof83: cs = 83; goto _test_eof; 
	_test_eof309: cs = 309; goto _test_eof; 
	_test_eof310: cs = 310; goto _test_eof; 
	_test_eof311: cs = 311; goto _test_eof; 
	_test_eof84: cs = 84; goto _test_eof; 
	_test_eof85: cs = 85; goto _test_eof; 
	_test_eof86: cs = 86; goto _test_eof; 
	_test_eof87: cs = 87; goto _test_eof; 
	_test_eof88: cs = 88; goto _test_eof; 
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
	_test_eof189: cs = 189; goto _test_eof; 
	_test_eof190: cs = 190; goto _test_eof; 
	_test_eof312: cs = 312; goto _test_eof; 
	_test_eof191: cs = 191; goto _test_eof; 
	_test_eof192: cs = 192; goto _test_eof; 
	_test_eof193: cs = 193; goto _test_eof; 
	_test_eof313: cs = 313; goto _test_eof; 
	_test_eof314: cs = 314; goto _test_eof; 
	_test_eof194: cs = 194; goto _test_eof; 
	_test_eof195: cs = 195; goto _test_eof; 
	_test_eof196: cs = 196; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 282: goto tr412;
	case 283: goto tr413;
	case 284: goto tr413;
	case 13: goto tr17;
	case 285: goto tr413;
	case 14: goto tr17;
	case 15: goto tr17;
	case 16: goto tr17;
	case 286: goto tr415;
	case 17: goto tr23;
	case 287: goto tr417;
	case 288: goto tr415;
	case 289: goto tr415;
	case 290: goto tr415;
	case 291: goto tr415;
	case 292: goto tr415;
	case 293: goto tr415;
	case 294: goto tr415;
	case 295: goto tr415;
	case 296: goto tr415;
	case 297: goto tr415;
	case 298: goto tr415;
	case 299: goto tr415;
	case 300: goto tr415;
	case 301: goto tr415;
	case 302: goto tr415;
	case 18: goto tr23;
	case 19: goto tr23;
	case 20: goto tr23;
	case 21: goto tr23;
	case 22: goto tr23;
	case 23: goto tr23;
	case 24: goto tr23;
	case 25: goto tr23;
	case 304: goto tr435;
	case 305: goto tr435;
	case 31: goto tr49;
	case 307: goto tr442;
	case 308: goto tr442;
	case 74: goto tr97;
	case 75: goto tr97;
	case 76: goto tr97;
	case 77: goto tr97;
	case 78: goto tr97;
	case 79: goto tr97;
	case 80: goto tr97;
	case 81: goto tr97;
	case 82: goto tr97;
	case 83: goto tr97;
	case 310: goto tr448;
	case 311: goto tr448;
	case 84: goto tr115;
	case 85: goto tr115;
	case 86: goto tr115;
	case 87: goto tr115;
	case 88: goto tr115;
	case 89: goto tr115;
	case 90: goto tr115;
	case 91: goto tr115;
	case 92: goto tr115;
	case 93: goto tr115;
	case 94: goto tr115;
	case 95: goto tr115;
	case 96: goto tr115;
	case 97: goto tr115;
	case 98: goto tr115;
	case 99: goto tr115;
	case 100: goto tr115;
	case 101: goto tr115;
	case 102: goto tr115;
	case 103: goto tr115;
	case 104: goto tr115;
	case 105: goto tr115;
	case 106: goto tr115;
	case 107: goto tr115;
	case 108: goto tr115;
	case 109: goto tr115;
	case 110: goto tr115;
	case 111: goto tr115;
	case 112: goto tr115;
	case 113: goto tr115;
	case 114: goto tr115;
	case 115: goto tr115;
	case 116: goto tr115;
	case 117: goto tr115;
	case 118: goto tr115;
	case 119: goto tr115;
	case 120: goto tr115;
	case 121: goto tr115;
	case 122: goto tr115;
	case 123: goto tr115;
	case 124: goto tr115;
	case 125: goto tr115;
	case 126: goto tr115;
	case 127: goto tr115;
	case 128: goto tr115;
	case 129: goto tr115;
	case 130: goto tr115;
	case 131: goto tr115;
	case 132: goto tr115;
	case 133: goto tr115;
	case 134: goto tr115;
	case 135: goto tr115;
	case 136: goto tr115;
	case 137: goto tr115;
	case 138: goto tr115;
	case 139: goto tr115;
	case 140: goto tr115;
	case 141: goto tr115;
	case 142: goto tr115;
	case 143: goto tr115;
	case 144: goto tr115;
	case 145: goto tr115;
	case 146: goto tr115;
	case 147: goto tr115;
	case 148: goto tr115;
	case 149: goto tr115;
	case 150: goto tr115;
	case 151: goto tr115;
	case 152: goto tr115;
	case 153: goto tr115;
	case 154: goto tr115;
	case 155: goto tr115;
	case 156: goto tr115;
	case 157: goto tr115;
	case 158: goto tr115;
	case 159: goto tr115;
	case 160: goto tr115;
	case 161: goto tr115;
	case 162: goto tr115;
	case 163: goto tr115;
	case 164: goto tr115;
	case 165: goto tr115;
	case 166: goto tr115;
	case 167: goto tr115;
	case 168: goto tr115;
	case 169: goto tr115;
	case 170: goto tr115;
	case 171: goto tr115;
	case 172: goto tr115;
	case 173: goto tr115;
	case 174: goto tr115;
	case 175: goto tr115;
	case 176: goto tr115;
	case 177: goto tr115;
	case 178: goto tr115;
	case 179: goto tr115;
	case 180: goto tr115;
	case 181: goto tr115;
	case 182: goto tr115;
	case 183: goto tr115;
	case 184: goto tr115;
	case 185: goto tr115;
	case 186: goto tr115;
	case 187: goto tr115;
	case 188: goto tr115;
	case 189: goto tr115;
	case 190: goto tr115;
	case 314: goto tr452;
	case 194: goto tr249;
	case 195: goto tr249;
	case 196: goto tr249;
	case 12: 
#line 37 "mfilescanner.rl"
	{
    cout << "*/\n";
    p--;
    {cs = stack[--top];goto _again;}
  }
	break;
	case 214: 
	case 215: 
	case 216: 
	case 217: 
	case 218: 
	case 219: 
	case 220: 
	case 221: 
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
	case 303: 
	case 318: 
#line 44 "mfilescanner.rl"
	{
    /*    cout << "EOF\n";*/
    end_function();
  }
	break;
	case 198: 
	case 199: 
	case 200: 
	case 201: 
	case 202: 
	case 203: 
	case 204: 
	case 205: 
	case 206: 
	case 207: 
	case 208: 
	case 209: 
	case 210: 
	case 211: 
#line 450 "mfilescanner.rl"
	{
        p = tmp_p - 2;
        {goto st313;}
      }
	break;
	case 212: 
#line 464 "mfilescanner.rl"
	{
    p--;
    {goto st303;}
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
#line 540 "mfilescanner.rl"
	{
    p=tmp_p;
    {goto st213;}
  }
	break;
#line 6207 "mfilescanner.cc"
	}
	}

	_out: {}
	}

#line 620 "mfilescanner.rl"

    /* Check if we failed. */
    if ( cs == MFileScanner_error )
    {
      /* Machine failed before finding a token. */
      cerr << "PARSE ERROR in line " << line << endl;
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
  for( unsigned int i = 0; i < block.size(); i += 1 )
  {
    if(i != 0)
      cout << "* ";

    cout << block[i] << "  ";
  }
}

void MFileScanner::write_docu_list(const DocuList & list,
                                   const string & item_text,
                                   const DocuList & alternative)
{
  typedef DocuList :: const_iterator list_iterator;
  list_iterator lit = list.begin();
  for(; lit != list.end(); ++lit)
  {
    cout << "* " << item_text << " " << (*lit).first << " ";
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
      write_docu_list((*mit).second, "@arg \\c", ( amit != altlistmap.end() ? (*amit).second : DocuList() ));
    }

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
    string::size_type found = tempfname.rfind("/");
    if(found != string::npos)
      tempfname = tempfname.substr(found+1);
    cout << "/** @file " << escape_chars(tempfname) << "\n  ";
    if((! groupset_.empty() || ! cscan_.groupset_.empty() ))
    {
      // specify the @ingroup command
      cout << "* @ingroup ";
      bool not_first = false;
      group_iterator git = groupset_.begin();
      for(; git != groupset_.end(); ++git)
      {
        if(not_first)
          cout << " ";
        else
          not_first = true;

        cout << *git;
      }
      git = cscan_.groupset_.begin();
      for(; git != cscan_.groupset_.end(); ++git)
      {
        if(not_first)
          cout << " ";
        else
          not_first = true;

        cout << *git;
      }
      cout << "*/\n";
      groupset_.clear();
    }
    is_first_function_ = false;
  }
//  cout << "/*";
/*  if(! cscan_.groupset_.empty() )
  {
    // specify the @ingroup command
    cout << "/"<<"** @package ";
    bool not_first = false;
    group_iterator git = cscan_.groupset_.begin();
    for(; git != cscan_.groupset_.end(); ++git)
    {
      if(not_first)
        cout << " ";
      else
        not_first = true;

      cout << *git;
    }*/
//    cout << "\n  * test*/\n  ";
//  }
  cout << "/*";
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
  cout << cfuncname_;
  if(paramlist_.size() == 0)
    cout << "\n  ";
  else
  {
    cout << "(";
    for(unsigned int i=0; i < paramlist_.size(); ++i)
    {
      if(!first)
        cout << ", ";
      else
        first = false;
      cout << "type " << paramlist_[i];
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
    bool not_first = false;
    block_iterator hit = docuheader_.begin();
    for(; hit != docuheader_.end(); ++hit)
    {
      if(not_first)
        cout << "* ";
      else
        not_first = true;

      cout << *hit << "  ";
    }
    hit = cscan_.docuheader_.begin();
    for(; hit != cscan_.docuheader_.end(); ++hit)
    {
      if(not_first)
        cout << "* ";
      else
        not_first = true;

      cout << *hit << "  ";
    }
  }
  docuheader_.clear();
  cout << "*\n  ";
  // specify the @details part

  // standard body definitions
  if(!docubody_.empty() || !cscan_.docubody_.empty())
  {
    cout << "*\n  ";
    block_iterator bit = docubody_.begin();
    for(; bit != docubody_.end(); ++bit)
      cout << "* " << *bit << "  ";
    bit = cscan_.docubody_.begin();
    for(; bit != cscan_.docubody_.end(); ++bit)
      cout << "* " << *bit << "  ";
  }
  docubody_.clear();
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

  // extra docu fields
  if(!docuextra_.empty() || ! cscan_.docuextra_.empty())
  {
    cout << "*\n  ";
    block_iterator bit = docuextra_.begin();
    for(; bit != docuextra_.end(); ++bit)
      cout << "* " << *bit << "  ";
    bit = cscan_.docuextra_.begin();
    for(; bit != cscan_.docuextra_.end(); ++bit)
      cout << "* " << *bit << "  ";
  }
  if( new_syntax_ )
  {
    cout << "* @synupdate Syntax needs to be updated! \n  ";
  }
  docuextra_.clear();
  cout << "*/\n";
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

  char buf[1000];
  getcwd(buf, 1000);

  string::size_type found = 0;
  string cwd(buf);
  found = filename.find(cwd);
  if(found!=string::npos)
    filename = filename.substr(cwd.size()+1);
  MFileScanner scanner(*fcin, filename);
  cerr << "************" << filename << endl;
  scanner.execute();
  return 0;
}

/* vim: set et sw=2 ft=ragel: */

