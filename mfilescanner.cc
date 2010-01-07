
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
static const int MFileScanner_start = 314;
static const int MFileScanner_first_final = 314;
static const int MFileScanner_error = 0;

static const int MFileScanner_en_in_comment_block = 315;
static const int MFileScanner_en_funcline = 316;
static const int MFileScanner_en_funcbody = 338;
static const int MFileScanner_en_fill_list = 341;
static const int MFileScanner_en_doxy_get_body = 344;
static const int MFileScanner_en_doxyfunction_garble = 347;
static const int MFileScanner_en_doxy_get_brief = 348;
static const int MFileScanner_en_doxyheader = 232;
static const int MFileScanner_en_expect_doxyblock = 247;
static const int MFileScanner_en_script = 248;
static const int MFileScanner_en_funct = 249;
static const int MFileScanner_en_main = 314;


#line 617 "mfilescanner.rl"



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

#line 634 "mfilescanner.rl"

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
		case 314: goto st314;
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
		case 242: goto st242;
		case 350: goto st350;
		case 243: goto st243;
		case 244: goto st244;
		case 245: goto st245;
		case 246: goto st246;
		case 247: goto st247;
		case 351: goto st351;
		case 248: goto st248;
		case 352: goto st352;
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
		case 353: goto st353;
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
		case 303: goto st303;
		case 304: goto st304;
		case 305: goto st305;
		case 306: goto st306;
		case 307: goto st307;
		case 308: goto st308;
		case 309: goto st309;
		case 310: goto st310;
		case 311: goto st311;
		case 312: goto st312;
		case 313: goto st313;
		case 315: goto st315;
		case 12: goto st12;
		case 316: goto st316;
		case 317: goto st317;
		case 318: goto st318;
		case 319: goto st319;
		case 13: goto st13;
		case 320: goto st320;
		case 14: goto st14;
		case 15: goto st15;
		case 16: goto st16;
		case 321: goto st321;
		case 17: goto st17;
		case 322: goto st322;
		case 18: goto st18;
		case 19: goto st19;
		case 323: goto st323;
		case 324: goto st324;
		case 325: goto st325;
		case 326: goto st326;
		case 327: goto st327;
		case 328: goto st328;
		case 329: goto st329;
		case 330: goto st330;
		case 331: goto st331;
		case 332: goto st332;
		case 333: goto st333;
		case 334: goto st334;
		case 335: goto st335;
		case 336: goto st336;
		case 337: goto st337;
		case 20: goto st20;
		case 21: goto st21;
		case 22: goto st22;
		case 23: goto st23;
		case 24: goto st24;
		case 25: goto st25;
		case 26: goto st26;
		case 27: goto st27;
		case 338: goto st338;
		case 28: goto st28;
		case 339: goto st339;
		case 29: goto st29;
		case 30: goto st30;
		case 31: goto st31;
		case 32: goto st32;
		case 340: goto st340;
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
		case 74: goto st74;
		case 75: goto st75;
		case 341: goto st341;
		case 342: goto st342;
		case 343: goto st343;
		case 76: goto st76;
		case 77: goto st77;
		case 78: goto st78;
		case 79: goto st79;
		case 80: goto st80;
		case 81: goto st81;
		case 82: goto st82;
		case 83: goto st83;
		case 84: goto st84;
		case 85: goto st85;
		case 344: goto st344;
		case 345: goto st345;
		case 346: goto st346;
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
		case 191: goto st191;
		case 192: goto st192;
		case 193: goto st193;
		case 194: goto st194;
		case 195: goto st195;
		case 196: goto st196;
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
		case 208: goto st208;
		case 209: goto st209;
		case 210: goto st210;
		case 211: goto st211;
		case 212: goto st212;
		case 213: goto st213;
		case 214: goto st214;
		case 215: goto st215;
		case 216: goto st216;
		case 217: goto st217;
		case 218: goto st218;
		case 219: goto st219;
		case 220: goto st220;
		case 347: goto st347;
		case 221: goto st221;
		case 222: goto st222;
		case 223: goto st223;
		case 224: goto st224;
		case 225: goto st225;
		case 226: goto st226;
		case 227: goto st227;
		case 228: goto st228;
		case 348: goto st348;
		case 349: goto st349;
		case 229: goto st229;
		case 230: goto st230;
		case 231: goto st231;
	default: break;
	}

	if ( ++p == pe )
		goto _test_eof;
_resume:
	switch ( cs )
	{
tr13:
#line 604 "mfilescanner.rl"
	{
    p=tmp_p;
    {goto st249;}
    }
	goto st314;
st314:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof314;
case 314:
#line 509 "mfilescanner.cc"
	goto tr444;
tr2:
#line 28 "mfilescanner.rl"
	{line++;}
	goto st1;
tr444:
#line 598 "mfilescanner.rl"
	{ p--; tmp_p = p; }
	goto st1;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
#line 523 "mfilescanner.cc"
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
#line 609 "mfilescanner.rl"
	{
    p=tmp_p;
    {goto st248;}
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
tr298:
#line 519 "mfilescanner.rl"
	{
        p = tmp_p - 2;
        {goto st348;}
      }
	goto st0;
tr314:
#line 533 "mfilescanner.rl"
	{
    p--;
    {goto st338;}
  }
	goto st0;
#line 562 "mfilescanner.cc"
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
st232:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof232;
case 232:
#line 647 "mfilescanner.cc"
	if ( (*p) == 37 )
		goto st233;
	goto st0;
st233:
	if ( ++p == pe )
		goto _test_eof233;
case 233:
	switch( (*p) ) {
		case 9: goto st233;
		case 32: goto st233;
		case 102: goto st234;
	}
	goto tr298;
st234:
	if ( ++p == pe )
		goto _test_eof234;
case 234:
	if ( (*p) == 117 )
		goto st235;
	goto tr298;
st235:
	if ( ++p == pe )
		goto _test_eof235;
case 235:
	if ( (*p) == 110 )
		goto st236;
	goto tr298;
st236:
	if ( ++p == pe )
		goto _test_eof236;
case 236:
	if ( (*p) == 99 )
		goto st237;
	goto tr298;
st237:
	if ( ++p == pe )
		goto _test_eof237;
case 237:
	if ( (*p) == 116 )
		goto st238;
	goto tr298;
st238:
	if ( ++p == pe )
		goto _test_eof238;
case 238:
	if ( (*p) == 105 )
		goto st239;
	goto tr298;
st239:
	if ( ++p == pe )
		goto _test_eof239;
case 239:
	if ( (*p) == 111 )
		goto st240;
	goto tr298;
st240:
	if ( ++p == pe )
		goto _test_eof240;
case 240:
	if ( (*p) == 110 )
		goto st241;
	goto tr298;
st241:
	if ( ++p == pe )
		goto _test_eof241;
case 241:
	switch( (*p) ) {
		case 0: goto tr298;
		case 10: goto tr298;
		case 41: goto st242;
		case 46: goto st243;
		case 59: goto st242;
	}
	goto st241;
st242:
	if ( ++p == pe )
		goto _test_eof242;
case 242:
	switch( (*p) ) {
		case 0: goto tr298;
		case 10: goto tr309;
	}
	goto st242;
tr309:
#line 28 "mfilescanner.rl"
	{line++;}
#line 512 "mfilescanner.rl"
	{ {goto st348;} }
	goto st350;
tr312:
#line 28 "mfilescanner.rl"
	{line++;}
#line 515 "mfilescanner.rl"
	{ {goto st347;} }
	goto st350;
st350:
	if ( ++p == pe )
		goto _test_eof350;
case 350:
#line 747 "mfilescanner.cc"
	goto tr298;
st243:
	if ( ++p == pe )
		goto _test_eof243;
case 243:
	if ( (*p) == 46 )
		goto st244;
	goto tr298;
st244:
	if ( ++p == pe )
		goto _test_eof244;
case 244:
	if ( (*p) == 46 )
		goto st245;
	goto tr298;
st245:
	if ( ++p == pe )
		goto _test_eof245;
case 245:
	switch( (*p) ) {
		case 9: goto st245;
		case 10: goto tr312;
		case 13: goto st246;
		case 32: goto st245;
	}
	goto tr298;
st246:
	if ( ++p == pe )
		goto _test_eof246;
case 246:
	if ( (*p) == 10 )
		goto tr312;
	goto tr298;
st247:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof247;
case 247:
#line 787 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st247;
		case 32: goto st247;
		case 37: goto tr316;
	}
	goto tr314;
tr316:
#line 74 "mfilescanner.rl"
	{ tmp_p = p + 1; }
#line 528 "mfilescanner.rl"
	{
        //cout << "/*";
        p--;
        {goto st232;}
      }
	goto st351;
st351:
	if ( ++p == pe )
		goto _test_eof351;
case 351:
#line 808 "mfilescanner.cc"
	goto tr314;
st248:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof248;
case 248:
#line 816 "mfilescanner.cc"
	if ( (*p) == 0 )
		goto st0;
	goto tr317;
tr317:
#line 571 "mfilescanner.rl"
	{
       string :: size_type found = filename_.rfind("/");
       if(found == string :: npos)
         found = -1;
       string funcname = filename_.substr(found+1, filename_.size()-3-found);
       cfuncname_.assign( funcname );
       cout << "void " << funcname << "() {\n";
       is_script_ = true;
       p--;
       {goto st247;}
     }
	goto st352;
st352:
	if ( ++p == pe )
		goto _test_eof352;
case 352:
#line 838 "mfilescanner.cc"
	goto st0;
tr319:
#line 28 "mfilescanner.rl"
	{line++;}
	goto st249;
tr327:
#line 28 "mfilescanner.rl"
	{line++;}
#line 50 "mfilescanner.rl"
	{
    /*    cout << p << "x" << tmp_p << endl;*/
    cout.write(tmp_p, p-tmp_p+1);
    {stack[top++] = 249; goto st315;}
  }
	goto st249;
st249:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof249;
case 249:
#line 860 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st249;
		case 10: goto tr319;
		case 13: goto st250;
		case 32: goto st251;
		case 37: goto st252;
		case 102: goto st254;
	}
	goto st0;
st250:
	if ( ++p == pe )
		goto _test_eof250;
case 250:
	if ( (*p) == 10 )
		goto tr319;
	goto st0;
st251:
	if ( ++p == pe )
		goto _test_eof251;
case 251:
	switch( (*p) ) {
		case 9: goto st251;
		case 10: goto tr319;
		case 13: goto st250;
		case 32: goto st251;
		case 37: goto st252;
	}
	goto st0;
st252:
	if ( ++p == pe )
		goto _test_eof252;
case 252:
	switch( (*p) ) {
		case 0: goto st0;
		case 124: goto tr325;
	}
	goto tr324;
tr324:
#line 68 "mfilescanner.rl"
	{ cout << "/*"; tmp_p = p; }
	goto st253;
tr325:
#line 66 "mfilescanner.rl"
	{ cout << "/**"; tmp_p = p+1; }
	goto st253;
st253:
	if ( ++p == pe )
		goto _test_eof253;
case 253:
#line 910 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr327;
	}
	goto st253;
st254:
	if ( ++p == pe )
		goto _test_eof254;
case 254:
	if ( (*p) == 117 )
		goto st255;
	goto st0;
st255:
	if ( ++p == pe )
		goto _test_eof255;
case 255:
	if ( (*p) == 110 )
		goto st256;
	goto st0;
st256:
	if ( ++p == pe )
		goto _test_eof256;
case 256:
	if ( (*p) == 99 )
		goto st257;
	goto st0;
st257:
	if ( ++p == pe )
		goto _test_eof257;
case 257:
	if ( (*p) == 116 )
		goto st258;
	goto st0;
st258:
	if ( ++p == pe )
		goto _test_eof258;
case 258:
	if ( (*p) == 105 )
		goto st259;
	goto st0;
st259:
	if ( ++p == pe )
		goto _test_eof259;
case 259:
	if ( (*p) == 111 )
		goto st260;
	goto st0;
st260:
	if ( ++p == pe )
		goto _test_eof260;
case 260:
	if ( (*p) == 110 )
		goto st261;
	goto st0;
tr343:
#line 28 "mfilescanner.rl"
	{line++;}
	goto st261;
tr340:
#line 28 "mfilescanner.rl"
	{line++;}
#line 78 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st261;
st261:
	if ( ++p == pe )
		goto _test_eof261;
case 261:
#line 982 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st261;
		case 32: goto st261;
		case 37: goto tr335;
		case 46: goto st263;
		case 91: goto tr338;
		case 95: goto tr337;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr337;
	} else if ( (*p) >= 65 )
		goto tr337;
	goto st0;
tr335:
#line 85 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st262;
st262:
	if ( ++p == pe )
		goto _test_eof262;
case 262:
#line 1005 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr340;
	}
	goto st262;
st263:
	if ( ++p == pe )
		goto _test_eof263;
case 263:
	if ( (*p) == 46 )
		goto st264;
	goto st0;
st264:
	if ( ++p == pe )
		goto _test_eof264;
case 264:
	if ( (*p) == 46 )
		goto st265;
	goto st0;
st265:
	if ( ++p == pe )
		goto _test_eof265;
case 265:
	switch( (*p) ) {
		case 9: goto st265;
		case 10: goto tr343;
		case 13: goto st266;
		case 32: goto st265;
	}
	goto st0;
st266:
	if ( ++p == pe )
		goto _test_eof266;
case 266:
	if ( (*p) == 10 )
		goto tr343;
	goto st0;
tr337:
#line 58 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st267;
st267:
	if ( ++p == pe )
		goto _test_eof267;
case 267:
#line 1051 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr345;
		case 10: goto tr346;
		case 13: goto tr347;
		case 32: goto tr345;
		case 37: goto tr348;
		case 40: goto tr349;
		case 46: goto tr350;
		case 59: goto tr352;
		case 61: goto tr353;
		case 95: goto st267;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st267;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st267;
	} else
		goto st267;
	goto st0;
tr345:
#line 126 "mfilescanner.rl"
	{
             string s(tmp_p, p - tmp_p);
             returnlist_.push_back(s);
             return_list_[s] = DocuBlock();
             cout << "ret::substitutestart::" << s << "::retsubstituteend ";
           }
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
#line 543 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
	goto st268;
tr354:
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st268;
st268:
	if ( ++p == pe )
		goto _test_eof268;
case 268:
#line 1097 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr354;
		case 10: goto tr355;
		case 13: goto st269;
		case 32: goto tr354;
		case 37: goto tr357;
		case 40: goto tr358;
		case 46: goto st294;
		case 59: goto st298;
		case 61: goto tr361;
	}
	goto st0;
tr346:
#line 543 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
#line 28 "mfilescanner.rl"
	{line++;}
#line 566 "mfilescanner.rl"
	{ cout << "void " << cfuncname_ << "() {\n"; {goto st247;} }
	goto st353;
tr355:
#line 28 "mfilescanner.rl"
	{line++;}
#line 566 "mfilescanner.rl"
	{ cout << "void " << cfuncname_ << "() {\n"; {goto st247;} }
	goto st353;
tr375:
#line 28 "mfilescanner.rl"
	{line++;}
#line 562 "mfilescanner.rl"
	{
             cout << " {\n";
             {goto st247;}
           }
	goto st353;
st353:
	if ( ++p == pe )
		goto _test_eof353;
case 353:
#line 1140 "mfilescanner.cc"
	goto st0;
tr347:
#line 543 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
	goto st269;
st269:
	if ( ++p == pe )
		goto _test_eof269;
case 269:
#line 1153 "mfilescanner.cc"
	if ( (*p) == 10 )
		goto tr355;
	goto st0;
tr357:
#line 85 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st270;
tr348:
#line 543 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
#line 85 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st270;
st270:
	if ( ++p == pe )
		goto _test_eof270;
case 270:
#line 1174 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr363;
	}
	goto st270;
tr412:
#line 28 "mfilescanner.rl"
	{line++;}
	goto st271;
tr363:
#line 28 "mfilescanner.rl"
	{line++;}
#line 78 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st271;
tr423:
#line 543 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
	goto st271;
st271:
	if ( ++p == pe )
		goto _test_eof271;
case 271:
#line 1204 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st271;
		case 10: goto tr355;
		case 13: goto st269;
		case 32: goto st271;
		case 37: goto tr357;
		case 40: goto tr358;
		case 46: goto st294;
		case 59: goto st298;
	}
	goto st0;
tr387:
#line 28 "mfilescanner.rl"
	{line++;}
	goto st272;
tr373:
#line 28 "mfilescanner.rl"
	{line++;}
#line 78 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st272;
tr349:
#line 543 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
#line 551 "mfilescanner.rl"
	{
                 if(!opt)
                 {
                   cout << "noret::substitute ";
                   opt=false;
                 }
                 cout << cfuncname_ << '(';
                 }
	goto st272;
tr366:
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st272;
tr358:
#line 551 "mfilescanner.rl"
	{
                 if(!opt)
                 {
                   cout << "noret::substitute ";
                   opt=false;
                 }
                 cout << cfuncname_ << '(';
                 }
	goto st272;
tr396:
#line 28 "mfilescanner.rl"
	{line++;}
#line 78 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st272;
tr403:
#line 99 "mfilescanner.rl"
	{
         string s(tmp_p, p - tmp_p);
         param_list_[s] = DocuBlock();
         paramlist_.push_back(s);
         cout << "type " << s;
       }
	goto st272;
tr404:
#line 99 "mfilescanner.rl"
	{
         string s(tmp_p, p - tmp_p);
         param_list_[s] = DocuBlock();
         paramlist_.push_back(s);
         cout << "type " << s;
       }
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st272;
st272:
	if ( ++p == pe )
		goto _test_eof272;
case 272:
#line 1295 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st272;
		case 10: goto tr366;
		case 32: goto st272;
		case 37: goto tr367;
		case 41: goto tr368;
		case 44: goto tr366;
		case 46: goto st281;
		case 61: goto st285;
		case 95: goto tr371;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr371;
	} else if ( (*p) >= 65 )
		goto tr371;
	goto st0;
tr367:
#line 85 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st273;
tr405:
#line 99 "mfilescanner.rl"
	{
         string s(tmp_p, p - tmp_p);
         param_list_[s] = DocuBlock();
         paramlist_.push_back(s);
         cout << "type " << s;
       }
#line 85 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st273;
st273:
	if ( ++p == pe )
		goto _test_eof273;
case 273:
#line 1332 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr373;
	}
	goto st273;
tr383:
#line 28 "mfilescanner.rl"
	{line++;}
	goto st274;
tr380:
#line 28 "mfilescanner.rl"
	{line++;}
#line 78 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st274;
tr368:
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st274;
tr406:
#line 99 "mfilescanner.rl"
	{
         string s(tmp_p, p - tmp_p);
         param_list_[s] = DocuBlock();
         paramlist_.push_back(s);
         cout << "type " << s;
       }
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st274;
st274:
	if ( ++p == pe )
		goto _test_eof274;
case 274:
#line 1370 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st274;
		case 10: goto tr375;
		case 13: goto st275;
		case 32: goto st274;
		case 37: goto tr377;
		case 46: goto st277;
		case 59: goto st274;
	}
	goto st0;
st275:
	if ( ++p == pe )
		goto _test_eof275;
case 275:
	if ( (*p) == 10 )
		goto tr375;
	goto st0;
tr377:
#line 85 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st276;
st276:
	if ( ++p == pe )
		goto _test_eof276;
case 276:
#line 1396 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr380;
	}
	goto st276;
st277:
	if ( ++p == pe )
		goto _test_eof277;
case 277:
	if ( (*p) == 46 )
		goto st278;
	goto st0;
st278:
	if ( ++p == pe )
		goto _test_eof278;
case 278:
	if ( (*p) == 46 )
		goto st279;
	goto st0;
st279:
	if ( ++p == pe )
		goto _test_eof279;
case 279:
	switch( (*p) ) {
		case 9: goto st279;
		case 10: goto tr383;
		case 13: goto st280;
		case 32: goto st279;
	}
	goto st0;
st280:
	if ( ++p == pe )
		goto _test_eof280;
case 280:
	if ( (*p) == 10 )
		goto tr383;
	goto st0;
tr407:
#line 99 "mfilescanner.rl"
	{
         string s(tmp_p, p - tmp_p);
         param_list_[s] = DocuBlock();
         paramlist_.push_back(s);
         cout << "type " << s;
       }
	goto st281;
st281:
	if ( ++p == pe )
		goto _test_eof281;
case 281:
#line 1447 "mfilescanner.cc"
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
		case 10: goto tr387;
		case 13: goto st284;
		case 32: goto st283;
	}
	goto st0;
st284:
	if ( ++p == pe )
		goto _test_eof284;
case 284:
	if ( (*p) == 10 )
		goto tr387;
	goto st0;
tr389:
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st285;
tr393:
#line 28 "mfilescanner.rl"
	{line++;}
#line 78 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st285;
tr401:
#line 28 "mfilescanner.rl"
	{line++;}
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st285;
tr409:
#line 99 "mfilescanner.rl"
	{
         string s(tmp_p, p - tmp_p);
         param_list_[s] = DocuBlock();
         paramlist_.push_back(s);
         cout << "type " << s;
       }
	goto st285;
st285:
	if ( ++p == pe )
		goto _test_eof285;
case 285:
#line 1510 "mfilescanner.cc"
	switch( (*p) ) {
		case 37: goto tr390;
		case 41: goto tr368;
		case 44: goto tr366;
		case 46: goto tr391;
	}
	goto tr389;
tr392:
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st286;
tr390:
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
#line 85 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st286;
st286:
	if ( ++p == pe )
		goto _test_eof286;
case 286:
#line 1532 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr389;
		case 10: goto tr393;
		case 37: goto tr390;
		case 41: goto st273;
		case 44: goto tr394;
	}
	goto tr392;
tr394:
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st287;
st287:
	if ( ++p == pe )
		goto _test_eof287;
case 287:
#line 1549 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st287;
		case 10: goto tr396;
		case 32: goto st287;
		case 37: goto tr367;
		case 44: goto tr394;
		case 61: goto st286;
	}
	goto st273;
tr391:
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st288;
st288:
	if ( ++p == pe )
		goto _test_eof288;
case 288:
#line 1568 "mfilescanner.cc"
	switch( (*p) ) {
		case 37: goto tr390;
		case 41: goto tr368;
		case 44: goto tr366;
		case 46: goto tr398;
	}
	goto tr389;
tr398:
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st289;
st289:
	if ( ++p == pe )
		goto _test_eof289;
case 289:
#line 1584 "mfilescanner.cc"
	switch( (*p) ) {
		case 37: goto tr390;
		case 41: goto tr368;
		case 44: goto tr366;
		case 46: goto tr399;
	}
	goto tr389;
tr399:
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st290;
st290:
	if ( ++p == pe )
		goto _test_eof290;
case 290:
#line 1600 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr400;
		case 10: goto tr401;
		case 13: goto tr402;
		case 32: goto tr400;
		case 37: goto tr390;
		case 41: goto tr368;
		case 44: goto tr366;
		case 46: goto tr399;
	}
	goto tr389;
tr400:
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st291;
st291:
	if ( ++p == pe )
		goto _test_eof291;
case 291:
#line 1620 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr400;
		case 10: goto tr401;
		case 13: goto tr402;
		case 32: goto tr400;
		case 37: goto tr390;
		case 41: goto tr368;
		case 44: goto tr366;
		case 46: goto tr391;
	}
	goto tr389;
tr402:
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st292;
st292:
	if ( ++p == pe )
		goto _test_eof292;
case 292:
#line 1640 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr401;
		case 37: goto tr390;
		case 41: goto tr368;
		case 44: goto tr366;
		case 46: goto tr391;
	}
	goto tr389;
tr371:
#line 58 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st293;
st293:
	if ( ++p == pe )
		goto _test_eof293;
case 293:
#line 1657 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr403;
		case 10: goto tr404;
		case 32: goto tr403;
		case 37: goto tr405;
		case 41: goto tr406;
		case 44: goto tr404;
		case 46: goto tr407;
		case 61: goto tr409;
		case 95: goto st293;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st293;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st293;
	} else
		goto st293;
	goto st0;
tr350:
#line 543 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
	goto st294;
st294:
	if ( ++p == pe )
		goto _test_eof294;
case 294:
#line 1689 "mfilescanner.cc"
	if ( (*p) == 46 )
		goto st295;
	goto st0;
st295:
	if ( ++p == pe )
		goto _test_eof295;
case 295:
	if ( (*p) == 46 )
		goto st296;
	goto st0;
st296:
	if ( ++p == pe )
		goto _test_eof296;
case 296:
	switch( (*p) ) {
		case 9: goto st296;
		case 10: goto tr412;
		case 13: goto st297;
		case 32: goto st296;
	}
	goto st0;
st297:
	if ( ++p == pe )
		goto _test_eof297;
case 297:
	if ( (*p) == 10 )
		goto tr412;
	goto st0;
tr352:
#line 543 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
	goto st298;
st298:
	if ( ++p == pe )
		goto _test_eof298;
case 298:
#line 1729 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr355;
		case 13: goto st269;
	}
	goto st0;
tr353:
#line 126 "mfilescanner.rl"
	{
             string s(tmp_p, p - tmp_p);
             returnlist_.push_back(s);
             return_list_[s] = DocuBlock();
             cout << "ret::substitutestart::" << s << "::retsubstituteend ";
           }
#line 540 "mfilescanner.rl"
	{opt=true;}
	goto st299;
tr361:
#line 540 "mfilescanner.rl"
	{opt=true;}
	goto st299;
tr418:
#line 28 "mfilescanner.rl"
	{line++;}
#line 78 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 540 "mfilescanner.rl"
	{opt=true;}
	goto st299;
tr421:
#line 28 "mfilescanner.rl"
	{line++;}
#line 540 "mfilescanner.rl"
	{opt=true;}
	goto st299;
st299:
	if ( ++p == pe )
		goto _test_eof299;
case 299:
#line 1771 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr361;
		case 32: goto tr361;
		case 37: goto tr414;
		case 46: goto st301;
		case 95: goto tr416;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr416;
	} else if ( (*p) >= 65 )
		goto tr416;
	goto st0;
tr414:
#line 85 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st300;
st300:
	if ( ++p == pe )
		goto _test_eof300;
case 300:
#line 1793 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr418;
	}
	goto st300;
st301:
	if ( ++p == pe )
		goto _test_eof301;
case 301:
	if ( (*p) == 46 )
		goto st302;
	goto st0;
st302:
	if ( ++p == pe )
		goto _test_eof302;
case 302:
	if ( (*p) == 46 )
		goto st303;
	goto st0;
st303:
	if ( ++p == pe )
		goto _test_eof303;
case 303:
	switch( (*p) ) {
		case 9: goto st303;
		case 10: goto tr421;
		case 13: goto st304;
		case 32: goto st303;
	}
	goto st0;
st304:
	if ( ++p == pe )
		goto _test_eof304;
case 304:
	if ( (*p) == 10 )
		goto tr421;
	goto st0;
tr416:
#line 58 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st305;
st305:
	if ( ++p == pe )
		goto _test_eof305;
case 305:
#line 1839 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr423;
		case 10: goto tr346;
		case 13: goto tr347;
		case 32: goto tr423;
		case 37: goto tr348;
		case 40: goto tr349;
		case 46: goto tr350;
		case 59: goto tr352;
		case 95: goto st305;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st305;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st305;
	} else
		goto st305;
	goto st0;
tr435:
#line 28 "mfilescanner.rl"
	{line++;}
	goto st306;
tr338:
#line 133 "mfilescanner.rl"
	{cout << "rets::substitutestart::";}
	goto st306;
tr432:
#line 28 "mfilescanner.rl"
	{line++;}
#line 78 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st306;
tr427:
#line 109 "mfilescanner.rl"
	{ cout << "::"; }
	goto st306;
tr437:
#line 111 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            returnlist_.push_back(s);
            return_list_[s] = DocuBlock();
            cout << s;
          }
	goto st306;
tr439:
#line 111 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            returnlist_.push_back(s);
            return_list_[s] = DocuBlock();
            cout << s;
          }
#line 109 "mfilescanner.rl"
	{ cout << "::"; }
	goto st306;
st306:
	if ( ++p == pe )
		goto _test_eof306;
case 306:
#line 1905 "mfilescanner.cc"
	switch( (*p) ) {
		case 32: goto st306;
		case 37: goto tr426;
		case 44: goto tr427;
		case 46: goto st308;
		case 93: goto tr430;
		case 95: goto tr429;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto st306;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr429;
	} else
		goto tr429;
	goto st0;
tr426:
#line 85 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st307;
tr438:
#line 111 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            returnlist_.push_back(s);
            return_list_[s] = DocuBlock();
            cout << s;
          }
#line 85 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st307;
st307:
	if ( ++p == pe )
		goto _test_eof307;
case 307:
#line 1942 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr432;
	}
	goto st307;
tr440:
#line 111 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            returnlist_.push_back(s);
            return_list_[s] = DocuBlock();
            cout << s;
          }
	goto st308;
st308:
	if ( ++p == pe )
		goto _test_eof308;
case 308:
#line 1961 "mfilescanner.cc"
	if ( (*p) == 46 )
		goto st309;
	goto st0;
st309:
	if ( ++p == pe )
		goto _test_eof309;
case 309:
	if ( (*p) == 46 )
		goto st310;
	goto st0;
st310:
	if ( ++p == pe )
		goto _test_eof310;
case 310:
	switch( (*p) ) {
		case 9: goto st310;
		case 10: goto tr435;
		case 13: goto st311;
		case 32: goto st310;
	}
	goto st0;
st311:
	if ( ++p == pe )
		goto _test_eof311;
case 311:
	if ( (*p) == 10 )
		goto tr435;
	goto st0;
tr429:
#line 58 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st312;
st312:
	if ( ++p == pe )
		goto _test_eof312;
case 312:
#line 1998 "mfilescanner.cc"
	switch( (*p) ) {
		case 32: goto tr437;
		case 37: goto tr438;
		case 44: goto tr439;
		case 46: goto tr440;
		case 93: goto tr442;
		case 95: goto st312;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr437;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st312;
		} else if ( (*p) >= 65 )
			goto st312;
	} else
		goto st312;
	goto st0;
tr443:
#line 56 "mfilescanner.rl"
	{ cout << (*p); }
	goto st313;
tr430:
#line 135 "mfilescanner.rl"
	{cout << "::retssubstituteend ";}
	goto st313;
tr442:
#line 111 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            returnlist_.push_back(s);
            return_list_[s] = DocuBlock();
            cout << s;
          }
#line 135 "mfilescanner.rl"
	{cout << "::retssubstituteend ";}
	goto st313;
st313:
	if ( ++p == pe )
		goto _test_eof313;
case 313:
#line 2042 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr443;
		case 32: goto tr443;
		case 61: goto tr361;
	}
	goto st0;
tr16:
#line 28 "mfilescanner.rl"
	{line++;}
#line 35 "mfilescanner.rl"
	{ cout.write(tmp_p, p - tmp_p+1); }
	goto st315;
st315:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof315;
case 315:
#line 2061 "mfilescanner.cc"
	if ( (*p) == 37 )
		goto tr445;
	goto tr15;
tr445:
#line 33 "mfilescanner.rl"
	{ tmp_p = p+1; cout << " *"; }
	goto st12;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
#line 2073 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr15;
		case 10: goto tr16;
	}
	goto st12;
tr17:
#line 273 "mfilescanner.rl"
	{{p = ((te))-1;}{ cout << (*p); }}
	goto st316;
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
	goto st316;
tr21:
#line 28 "mfilescanner.rl"
	{line++;}
#line 148 "mfilescanner.rl"
	{te = p+1;{ cout.write(ts, te-ts); }}
	goto st316;
tr23:
#line 270 "mfilescanner.rl"
	{{p = ((te))-1;}{ cout.write(ts, te-ts); }}
	goto st316;
tr25:
#line 197 "mfilescanner.rl"
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
	goto st316;
tr28:
#line 159 "mfilescanner.rl"
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
	goto st316;
tr40:
#line 28 "mfilescanner.rl"
	{line++;}
#line 255 "mfilescanner.rl"
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
	goto st316;
tr446:
#line 273 "mfilescanner.rl"
	{te = p+1;{ cout << (*p); }}
	goto st316;
tr448:
#line 28 "mfilescanner.rl"
	{line++;}
#line 276 "mfilescanner.rl"
	{te = p+1;{ cout << (*p); {goto st338;} }}
	goto st316;
tr454:
#line 145 "mfilescanner.rl"
	{te = p;p--;{ cout.write(ts, te-ts); }}
	goto st316;
tr455:
#line 273 "mfilescanner.rl"
	{te = p;p--;{ cout << (*p); }}
	goto st316;
tr457:
#line 270 "mfilescanner.rl"
	{te = p;p--;{ cout.write(ts, te-ts); }}
	goto st316;
tr459:
#line 197 "mfilescanner.rl"
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
	goto st316;
st316:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof316;
case 316:
#line 1 "NONE"
	{ts = p;}
#line 2276 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st317;
		case 10: goto tr448;
		case 13: goto st318;
		case 32: goto st317;
		case 37: goto tr450;
		case 46: goto tr451;
		case 95: goto tr452;
		case 100: goto tr453;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr452;
	} else if ( (*p) >= 65 )
		goto tr452;
	goto tr446;
st317:
	if ( ++p == pe )
		goto _test_eof317;
case 317:
	switch( (*p) ) {
		case 9: goto st317;
		case 32: goto st317;
	}
	goto tr454;
st318:
	if ( ++p == pe )
		goto _test_eof318;
case 318:
	if ( (*p) == 10 )
		goto tr448;
	goto tr455;
tr450:
#line 1 "NONE"
	{te = p+1;}
#line 150 "mfilescanner.rl"
	{ tmp_p = p + 1; }
	goto st319;
st319:
	if ( ++p == pe )
		goto _test_eof319;
case 319:
#line 2320 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr455;
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
tr451:
#line 1 "NONE"
	{te = p+1;}
	goto st320;
st320:
	if ( ++p == pe )
		goto _test_eof320;
case 320:
#line 2343 "mfilescanner.cc"
	if ( (*p) == 46 )
		goto st14;
	goto tr455;
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
tr452:
#line 1 "NONE"
	{te = p+1;}
	goto st321;
st321:
	if ( ++p == pe )
		goto _test_eof321;
case 321:
#line 2380 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr458;
		case 95: goto tr452;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr452;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr452;
	} else
		goto tr452;
	goto tr457;
tr458:
#line 154 "mfilescanner.rl"
	{tmp_string.assign(ts,p-ts);}
#line 191 "mfilescanner.rl"
	{tmp_string.assign(ts,p-ts);}
	goto st17;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
#line 2404 "mfilescanner.cc"
	if ( (*p) == 95 )
		goto tr24;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr24;
	} else if ( (*p) >= 65 )
		goto tr24;
	goto tr23;
tr24:
#line 1 "NONE"
	{te = p+1;}
#line 58 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st322;
tr461:
#line 1 "NONE"
	{te = p+1;}
	goto st322;
st322:
	if ( ++p == pe )
		goto _test_eof322;
case 322:
#line 2427 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr460;
		case 32: goto tr460;
		case 61: goto tr462;
		case 95: goto tr461;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr461;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr461;
	} else
		goto tr461;
	goto tr459;
tr460:
#line 156 "mfilescanner.rl"
	{tmp_p2 = p;}
	goto st18;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
#line 2451 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st18;
		case 32: goto st18;
		case 61: goto st19;
	}
	goto tr25;
tr462:
#line 156 "mfilescanner.rl"
	{tmp_p2 = p;}
	goto st19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
#line 2466 "mfilescanner.cc"
	if ( (*p) == 61 )
		goto tr25;
	goto tr28;
tr453:
#line 1 "NONE"
	{te = p+1;}
	goto st323;
st323:
	if ( ++p == pe )
		goto _test_eof323;
case 323:
#line 2478 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr458;
		case 95: goto tr452;
		case 105: goto tr463;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr452;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr452;
	} else
		goto tr452;
	goto tr457;
tr463:
#line 1 "NONE"
	{te = p+1;}
	goto st324;
st324:
	if ( ++p == pe )
		goto _test_eof324;
case 324:
#line 2501 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr458;
		case 95: goto tr452;
		case 115: goto tr464;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr452;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr452;
	} else
		goto tr452;
	goto tr457;
tr464:
#line 1 "NONE"
	{te = p+1;}
	goto st325;
st325:
	if ( ++p == pe )
		goto _test_eof325;
case 325:
#line 2524 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr458;
		case 95: goto tr452;
		case 112: goto tr465;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr452;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr452;
	} else
		goto tr452;
	goto tr457;
tr465:
#line 1 "NONE"
	{te = p+1;}
	goto st326;
st326:
	if ( ++p == pe )
		goto _test_eof326;
case 326:
#line 2547 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr458;
		case 95: goto tr466;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr452;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr452;
	} else
		goto tr452;
	goto tr457;
tr466:
#line 1 "NONE"
	{te = p+1;}
	goto st327;
st327:
	if ( ++p == pe )
		goto _test_eof327;
case 327:
#line 2569 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr458;
		case 95: goto tr452;
		case 100: goto tr467;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr452;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr452;
	} else
		goto tr452;
	goto tr457;
tr467:
#line 1 "NONE"
	{te = p+1;}
	goto st328;
st328:
	if ( ++p == pe )
		goto _test_eof328;
case 328:
#line 2592 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr458;
		case 95: goto tr452;
		case 101: goto tr468;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr452;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr452;
	} else
		goto tr452;
	goto tr457;
tr468:
#line 1 "NONE"
	{te = p+1;}
	goto st329;
st329:
	if ( ++p == pe )
		goto _test_eof329;
case 329:
#line 2615 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr458;
		case 95: goto tr452;
		case 112: goto tr469;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr452;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr452;
	} else
		goto tr452;
	goto tr457;
tr469:
#line 1 "NONE"
	{te = p+1;}
	goto st330;
st330:
	if ( ++p == pe )
		goto _test_eof330;
case 330:
#line 2638 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr458;
		case 95: goto tr452;
		case 114: goto tr470;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr452;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr452;
	} else
		goto tr452;
	goto tr457;
tr470:
#line 1 "NONE"
	{te = p+1;}
	goto st331;
st331:
	if ( ++p == pe )
		goto _test_eof331;
case 331:
#line 2661 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr458;
		case 95: goto tr452;
		case 101: goto tr471;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr452;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr452;
	} else
		goto tr452;
	goto tr457;
tr471:
#line 1 "NONE"
	{te = p+1;}
	goto st332;
st332:
	if ( ++p == pe )
		goto _test_eof332;
case 332:
#line 2684 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr458;
		case 95: goto tr452;
		case 99: goto tr472;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr452;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr452;
	} else
		goto tr452;
	goto tr457;
tr472:
#line 1 "NONE"
	{te = p+1;}
	goto st333;
st333:
	if ( ++p == pe )
		goto _test_eof333;
case 333:
#line 2707 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr458;
		case 95: goto tr452;
		case 97: goto tr473;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr452;
	} else if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr452;
	} else
		goto tr452;
	goto tr457;
tr473:
#line 1 "NONE"
	{te = p+1;}
	goto st334;
st334:
	if ( ++p == pe )
		goto _test_eof334;
case 334:
#line 2730 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr458;
		case 95: goto tr452;
		case 116: goto tr474;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr452;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr452;
	} else
		goto tr452;
	goto tr457;
tr474:
#line 1 "NONE"
	{te = p+1;}
	goto st335;
st335:
	if ( ++p == pe )
		goto _test_eof335;
case 335:
#line 2753 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr458;
		case 95: goto tr452;
		case 101: goto tr475;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr452;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr452;
	} else
		goto tr452;
	goto tr457;
tr475:
#line 1 "NONE"
	{te = p+1;}
	goto st336;
st336:
	if ( ++p == pe )
		goto _test_eof336;
case 336:
#line 2776 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr458;
		case 95: goto tr452;
		case 100: goto tr476;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr452;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr452;
	} else
		goto tr452;
	goto tr457;
tr476:
#line 1 "NONE"
	{te = p+1;}
	goto st337;
st337:
	if ( ++p == pe )
		goto _test_eof337;
case 337:
#line 2799 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st20;
		case 32: goto st20;
		case 40: goto st21;
		case 46: goto tr458;
		case 59: goto tr31;
		case 95: goto tr452;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr452;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr452;
	} else
		goto tr452;
	goto tr457;
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
#line 58 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st23;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
#line 2855 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr23;
		case 39: goto tr36;
	}
	goto st23;
tr34:
#line 58 "mfilescanner.rl"
	{ tmp_p = p; }
#line 62 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st24;
tr36:
#line 62 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st24;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
#line 2875 "mfilescanner.cc"
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
#line 244 "mfilescanner.rl"
	{tmp_string.assign("");}
	goto st26;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
#line 2900 "mfilescanner.cc"
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
#line 28 "mfilescanner.rl"
	{line++;}
#line 304 "mfilescanner.rl"
	{te = p+1;{
          p = ts-1;
          {goto st316;}
        }}
	goto st338;
tr49:
#line 28 "mfilescanner.rl"
	{line++;}
#line 78 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 304 "mfilescanner.rl"
	{te = p+1;{
          p = ts-1;
          {goto st316;}
        }}
	goto st338;
tr53:
#line 304 "mfilescanner.rl"
	{{p = ((te))-1;}{
          p = ts-1;
          {goto st316;}
        }}
	goto st338;
tr55:
#line 28 "mfilescanner.rl"
	{line++;}
#line 297 "mfilescanner.rl"
	{te = p+1;{ cout << '\n'; }}
	goto st338;
tr62:
#line 28 "mfilescanner.rl"
	{line++;}
#line 290 "mfilescanner.rl"
	{te = p+1;{
          cout.write(tmp_p, p - tmp_p+1);
          {stack[top++] = 338; goto st315;}
        }}
	goto st338;
tr70:
#line 311 "mfilescanner.rl"
	{te = p+1;{
        p = ts-1;
        end_function();
        {goto st314;}
      }}
	goto st338;
tr100:
#line 284 "mfilescanner.rl"
	{te = p+1;{
          new_syntax_ = true;
          cout << "*/\n"; //cout << "add to special group */\n";
        }}
#line 28 "mfilescanner.rl"
	{line++;}
	goto st338;
tr477:
#line 317 "mfilescanner.rl"
	{te = p+1;}
	goto st338;
tr479:
#line 304 "mfilescanner.rl"
	{te = p;p--;{
          p = ts-1;
          {goto st316;}
        }}
	goto st338;
st338:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof338;
case 338:
#line 1 "NONE"
	{ts = p;}
#line 2996 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr477;
		case 9: goto st34;
		case 10: goto tr55;
		case 13: goto st35;
		case 32: goto st34;
		case 37: goto st46;
		case 102: goto st38;
	}
	goto st28;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st339;
		case 10: goto tr45;
		case 32: goto st339;
		case 37: goto tr46;
		case 46: goto st30;
	}
	goto st28;
st339:
	if ( ++p == pe )
		goto _test_eof339;
case 339:
	switch( (*p) ) {
		case 9: goto st339;
		case 32: goto st339;
	}
	goto tr479;
tr46:
#line 85 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st29;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
#line 3037 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr49;
	}
	goto st29;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st339;
		case 10: goto tr45;
		case 32: goto st339;
		case 37: goto tr46;
		case 46: goto st31;
	}
	goto st28;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st339;
		case 10: goto tr45;
		case 32: goto st339;
		case 37: goto tr46;
		case 46: goto st32;
	}
	goto st28;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr52;
		case 10: goto tr45;
		case 32: goto tr52;
		case 37: goto tr46;
		case 46: goto st32;
	}
	goto st28;
tr52:
#line 1 "NONE"
	{te = p+1;}
	goto st340;
st340:
	if ( ++p == pe )
		goto _test_eof340;
case 340:
#line 3090 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr52;
		case 10: goto tr45;
		case 13: goto st33;
		case 32: goto tr52;
	}
	goto tr479;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
	if ( (*p) == 10 )
		goto tr45;
	goto tr53;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st34;
		case 10: goto tr55;
		case 13: goto st35;
		case 32: goto st34;
		case 37: goto st36;
		case 102: goto st38;
	}
	goto st28;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st339;
		case 10: goto tr55;
		case 32: goto st339;
		case 37: goto tr46;
		case 46: goto st30;
	}
	goto st28;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
	switch( (*p) ) {
		case 0: goto st0;
		case 124: goto tr60;
	}
	goto tr59;
tr59:
#line 68 "mfilescanner.rl"
	{ cout << "/*"; tmp_p = p; }
	goto st37;
tr60:
#line 66 "mfilescanner.rl"
	{ cout << "/**"; tmp_p = p+1; }
	goto st37;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
#line 3153 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr62;
	}
	goto st37;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st339;
		case 10: goto tr45;
		case 32: goto st339;
		case 37: goto tr46;
		case 46: goto st30;
		case 117: goto st39;
	}
	goto st28;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st339;
		case 10: goto tr45;
		case 32: goto st339;
		case 37: goto tr46;
		case 46: goto st30;
		case 110: goto st40;
	}
	goto st28;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st339;
		case 10: goto tr45;
		case 32: goto st339;
		case 37: goto tr46;
		case 46: goto st30;
		case 99: goto st41;
	}
	goto st28;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st339;
		case 10: goto tr45;
		case 32: goto st339;
		case 37: goto tr46;
		case 46: goto st30;
		case 116: goto st42;
	}
	goto st28;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st339;
		case 10: goto tr45;
		case 32: goto st339;
		case 37: goto tr46;
		case 46: goto st30;
		case 105: goto st43;
	}
	goto st28;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st339;
		case 10: goto tr45;
		case 32: goto st339;
		case 37: goto tr46;
		case 46: goto st30;
		case 111: goto st44;
	}
	goto st28;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st339;
		case 10: goto tr45;
		case 32: goto st339;
		case 37: goto tr46;
		case 46: goto st30;
		case 110: goto st45;
	}
	goto st28;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
	switch( (*p) ) {
		case 0: goto st0;
		case 32: goto tr70;
		case 37: goto st0;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st0;
	goto st28;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
	switch( (*p) ) {
		case 0: goto st0;
		case 32: goto tr71;
		case 124: goto tr60;
	}
	goto tr59;
tr71:
#line 68 "mfilescanner.rl"
	{ cout << "/*"; tmp_p = p; }
	goto st47;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
#line 3287 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr62;
		case 84: goto st48;
	}
	goto st37;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr62;
		case 79: goto st49;
	}
	goto st37;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr62;
		case 32: goto st50;
	}
	goto st37;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr62;
		case 66: goto st51;
	}
	goto st37;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr62;
		case 69: goto st52;
	}
	goto st37;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr62;
		case 32: goto st53;
	}
	goto st37;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr62;
		case 65: goto st54;
	}
	goto st37;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr62;
		case 68: goto st55;
	}
	goto st37;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr62;
		case 74: goto st56;
	}
	goto st37;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr62;
		case 85: goto st57;
	}
	goto st37;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr62;
		case 83: goto st58;
	}
	goto st37;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr62;
		case 84: goto st59;
	}
	goto st37;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr62;
		case 69: goto st60;
	}
	goto st37;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr62;
		case 68: goto st61;
	}
	goto st37;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr62;
		case 32: goto st62;
	}
	goto st37;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr62;
		case 84: goto st63;
	}
	goto st37;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr62;
		case 79: goto st64;
	}
	goto st37;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr62;
		case 32: goto st65;
	}
	goto st37;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr62;
		case 78: goto st66;
	}
	goto st37;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr62;
		case 69: goto st67;
	}
	goto st37;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr62;
		case 87: goto st68;
	}
	goto st37;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr62;
		case 32: goto st69;
	}
	goto st37;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr62;
		case 83: goto st70;
	}
	goto st37;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr62;
		case 89: goto st71;
	}
	goto st37;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr62;
		case 78: goto st72;
	}
	goto st37;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr62;
		case 84: goto st73;
	}
	goto st37;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr62;
		case 65: goto st74;
	}
	goto st37;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr62;
		case 88: goto st75;
	}
	goto st37;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr100;
	}
	goto st37;
tr101:
#line 1 "NONE"
	{	switch( act ) {
	case 0:
	{{goto st0;}}
	break;
	case 19:
	{{p = ((te))-1;}
      p =ts-1;
      // cout << "*/\n";
      {cs = stack[--top];goto _again;}
    }
	break;
	}
	}
	goto st341;
tr104:
#line 28 "mfilescanner.rl"
	{line++;}
#line 355 "mfilescanner.rl"
	{te = p+1;{ /*cout << "empty line\n";*/ {cs = stack[--top];goto _again;} }}
	goto st341;
tr109:
#line 28 "mfilescanner.rl"
	{line++;}
#line 347 "mfilescanner.rl"
	{te = p+1;{
      string s(tmp_p, p - tmp_p + 1);
      (*clist_)[tmp_string].push_back(s);
      /*cout << "add something results in\n" << (*clist_)[tmp_string];*/
    }}
	goto st341;
tr118:
#line 28 "mfilescanner.rl"
	{line++;}
#line 328 "mfilescanner.rl"
	{te = p+1;{
      tmp_string.assign(tmp_p3, tmp_p2 - tmp_p3);
      //    std::cout << tmp_string << '\n';
      (*clist_)[tmp_string].push_back(string(tmp_p+1, p - tmp_p));
    }}
	goto st341;
tr481:
#line 359 "mfilescanner.rl"
	{te = p+1;{
      p =ts-1;
      // cout << "*/\n";
      {cs = stack[--top];goto _again;}
    }}
	goto st341;
tr483:
#line 28 "mfilescanner.rl"
	{line++;}
#line 359 "mfilescanner.rl"
	{te = p+1;{
      p =ts-1;
      // cout << "*/\n";
      {cs = stack[--top];goto _again;}
    }}
	goto st341;
tr486:
#line 359 "mfilescanner.rl"
	{te = p;p--;{
      p =ts-1;
      // cout << "*/\n";
      {cs = stack[--top];goto _again;}
    }}
	goto st341;
st341:
#line 1 "NONE"
	{ts = 0;}
#line 1 "NONE"
	{act = 0;}
	if ( ++p == pe )
		goto _test_eof341;
case 341:
#line 1 "NONE"
	{ts = p;}
#line 3651 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr482;
		case 10: goto tr483;
		case 13: goto st343;
		case 32: goto tr482;
		case 37: goto tr485;
	}
	goto tr481;
tr482:
#line 1 "NONE"
	{te = p+1;}
#line 359 "mfilescanner.rl"
	{act = 19;}
	goto st342;
st342:
	if ( ++p == pe )
		goto _test_eof342;
case 342:
#line 3671 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr486;
		case 9: goto tr482;
		case 10: goto tr483;
		case 13: goto st343;
		case 32: goto tr482;
		case 37: goto tr485;
	}
	goto tr481;
st343:
	if ( ++p == pe )
		goto _test_eof343;
case 343:
	if ( (*p) == 10 )
		goto tr483;
	goto tr486;
tr485:
#line 74 "mfilescanner.rl"
	{ tmp_p = p + 1; }
	goto st76;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
#line 3696 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr101;
		case 9: goto st76;
		case 10: goto tr104;
		case 13: goto st80;
		case 32: goto st76;
		case 39: goto st81;
		case 58: goto tr101;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr107;
	} else if ( (*p) >= 65 )
		goto tr107;
	goto st77;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
	switch( (*p) ) {
		case 0: goto tr101;
		case 9: goto st78;
		case 10: goto tr109;
		case 32: goto st78;
		case 58: goto tr101;
	}
	goto st77;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
	switch( (*p) ) {
		case 9: goto st78;
		case 10: goto tr109;
		case 32: goto st78;
		case 58: goto tr101;
	}
	goto st79;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
	switch( (*p) ) {
		case 0: goto tr101;
		case 10: goto tr109;
	}
	goto st79;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
	switch( (*p) ) {
		case 0: goto tr101;
		case 9: goto st78;
		case 10: goto tr109;
		case 32: goto st78;
		case 58: goto tr101;
	}
	goto st77;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
	switch( (*p) ) {
		case 0: goto tr101;
		case 9: goto st78;
		case 10: goto tr109;
		case 32: goto st78;
		case 58: goto tr101;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr107;
	} else if ( (*p) >= 65 )
		goto tr107;
	goto st77;
tr107:
#line 325 "mfilescanner.rl"
	{tmp_p3 = p;}
	goto st82;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
#line 3781 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr101;
		case 9: goto tr111;
		case 10: goto tr109;
		case 32: goto tr111;
		case 39: goto tr112;
		case 44: goto st82;
		case 46: goto st82;
		case 58: goto tr114;
		case 93: goto st82;
		case 95: goto st82;
		case 125: goto st82;
	}
	if ( (*p) < 48 ) {
		if ( 40 <= (*p) && (*p) <= 41 )
			goto st82;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 123 )
				goto st82;
		} else if ( (*p) >= 65 )
			goto st82;
	} else
		goto st82;
	goto st77;
tr111:
#line 325 "mfilescanner.rl"
	{tmp_p2 = p;}
	goto st83;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
#line 3815 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st83;
		case 10: goto tr109;
		case 32: goto st83;
		case 58: goto tr116;
	}
	goto st79;
tr116:
#line 58 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st84;
tr114:
#line 325 "mfilescanner.rl"
	{tmp_p2 = p;}
#line 58 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st84;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
#line 3837 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr101;
		case 10: goto tr118;
	}
	goto st84;
tr112:
#line 325 "mfilescanner.rl"
	{tmp_p2 = p;}
	goto st85;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
#line 3851 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr101;
		case 9: goto st83;
		case 10: goto tr109;
		case 32: goto st83;
		case 58: goto tr116;
	}
	goto st77;
tr119:
#line 1 "NONE"
	{	switch( act ) {
	case 0:
	{{goto st0;}}
	break;
	case 28:
	{{p = ((te))-1;}
        p--;
        // cout << "*/\n";
        {goto st338;}
      }
	break;
	}
	}
	goto st344;
tr123:
#line 28 "mfilescanner.rl"
	{line++;}
#line 453 "mfilescanner.rl"
	{te = p+1;{
        /*cout << "*\n  ";*/
        docubody_.push_back("\n");
      }}
	goto st344;
tr130:
#line 28 "mfilescanner.rl"
	{line++;}
#line 446 "mfilescanner.rl"
	{te = p+1;{
        /*cout << "*"; cout.write(tmp_p, p - tmp_p+1) << "  ";*/
        docubody_.push_back(string(tmp_p, p - tmp_p + 1));
      }}
	goto st344;
tr141:
#line 371 "mfilescanner.rl"
	{tmp_p2 = p;}
#line 28 "mfilescanner.rl"
	{line++;}
#line 374 "mfilescanner.rl"
	{te = p+1;{
        string s, res;
        s.assign(tmp_p, p - tmp_p + 1);
        string::size_type size = string("see also").size();
        string::size_type loc = tmp_p2 - tmp_p - size;
        res = s.substr(0, loc) + "@sa" + s.substr(loc + size);
        /*        cout << "*"; cout << res << "  "; */
        docubody_.push_back(res);
      }}
	goto st344;
tr145:
#line 28 "mfilescanner.rl"
	{line++;}
#line 374 "mfilescanner.rl"
	{te = p+1;{
        string s, res;
        s.assign(tmp_p, p - tmp_p + 1);
        string::size_type size = string("see also").size();
        string::size_type loc = tmp_p2 - tmp_p - size;
        res = s.substr(0, loc) + "@sa" + s.substr(loc + size);
        /*        cout << "*"; cout << res << "  "; */
        docubody_.push_back(res);
      }}
	goto st344;
tr166:
#line 28 "mfilescanner.rl"
	{line++;}
#line 424 "mfilescanner.rl"
	{te = p+1;{
        clist_ = &param_list_;
        {stack[top++] = 344; goto st341;}
      }}
	goto st344;
tr195:
#line 28 "mfilescanner.rl"
	{line++;}
#line 415 "mfilescanner.rl"
	{te = p+1;{
        clist_ = &(retval_list_[tmp_string]);
        {stack[top++] = 344; goto st341;}
      }}
	goto st344;
tr226:
#line 28 "mfilescanner.rl"
	{line++;}
#line 403 "mfilescanner.rl"
	{te = p+1;{
        clist_ = &(optional_list_[tmp_string]);
        {stack[top++] = 344; goto st341;}
      }}
	goto st344;
tr258:
#line 28 "mfilescanner.rl"
	{line++;}
#line 390 "mfilescanner.rl"
	{te = p+1;{
        //cout << tmp_string << '\n';
        clist_ = &(required_list_[tmp_string]);
        {stack[top++] = 344; goto st341;}
      }}
	goto st344;
tr278:
#line 28 "mfilescanner.rl"
	{line++;}
#line 433 "mfilescanner.rl"
	{te = p+1;{
        clist_ = &return_list_;
        {stack[top++] = 344; goto st341;}
      }}
	goto st344;
tr487:
#line 460 "mfilescanner.rl"
	{te = p+1;{
        p--;
        // cout << "*/\n";
        {goto st338;}
      }}
	goto st344;
tr489:
#line 28 "mfilescanner.rl"
	{line++;}
#line 460 "mfilescanner.rl"
	{te = p+1;{
        p--;
        // cout << "*/\n";
        {goto st338;}
      }}
	goto st344;
tr492:
#line 460 "mfilescanner.rl"
	{te = p;p--;{
        p--;
        // cout << "*/\n";
        {goto st338;}
      }}
	goto st344;
st344:
#line 1 "NONE"
	{ts = 0;}
#line 1 "NONE"
	{act = 0;}
	if ( ++p == pe )
		goto _test_eof344;
case 344:
#line 1 "NONE"
	{ts = p;}
#line 4006 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr488;
		case 10: goto tr489;
		case 13: goto st346;
		case 32: goto tr488;
		case 37: goto tr491;
	}
	goto tr487;
tr488:
#line 1 "NONE"
	{te = p+1;}
#line 460 "mfilescanner.rl"
	{act = 28;}
	goto st345;
st345:
	if ( ++p == pe )
		goto _test_eof345;
case 345:
#line 4026 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr492;
		case 9: goto tr488;
		case 10: goto tr489;
		case 13: goto st346;
		case 32: goto tr488;
		case 37: goto tr491;
	}
	goto tr487;
st346:
	if ( ++p == pe )
		goto _test_eof346;
case 346:
	if ( (*p) == 10 )
		goto tr489;
	goto tr492;
tr491:
#line 74 "mfilescanner.rl"
	{ tmp_p = p + 1; }
	goto st86;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
#line 4051 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st88;
		case 9: goto st86;
		case 10: goto tr123;
		case 13: goto st109;
		case 32: goto st86;
		case 65: goto st110;
		case 71: goto st122;
		case 79: goto st150;
		case 82: goto st177;
		case 83: goto st90;
		case 97: goto st110;
		case 103: goto st122;
		case 111: goto st150;
		case 114: goto st177;
		case 115: goto st90;
	}
	goto st87;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 83: goto st90;
		case 115: goto st90;
	}
	goto st87;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
	switch( (*p) ) {
		case 9: goto st88;
		case 10: goto tr130;
		case 13: goto st89;
		case 32: goto st88;
	}
	goto tr119;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
	if ( (*p) == 10 )
		goto tr130;
	goto tr119;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 69: goto st91;
		case 83: goto st90;
		case 101: goto st91;
		case 115: goto st90;
	}
	goto st87;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 69: goto st92;
		case 83: goto st90;
		case 101: goto st92;
		case 115: goto st90;
	}
	goto st87;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 32: goto st93;
		case 83: goto st90;
		case 115: goto st90;
	}
	goto st87;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 65: goto st94;
		case 83: goto st90;
		case 97: goto st94;
		case 115: goto st90;
	}
	goto st87;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 76: goto st95;
		case 83: goto st90;
		case 108: goto st95;
		case 115: goto st90;
	}
	goto st87;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 83: goto st96;
		case 115: goto st96;
	}
	goto st87;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 69: goto st91;
		case 79: goto st97;
		case 83: goto st90;
		case 101: goto st91;
		case 111: goto st97;
		case 115: goto st90;
	}
	goto st87;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
	switch( (*p) ) {
		case 0: goto tr119;
		case 9: goto tr140;
		case 10: goto tr141;
		case 13: goto tr142;
		case 32: goto tr140;
		case 83: goto tr143;
		case 115: goto tr143;
	}
	goto tr139;
tr139:
#line 371 "mfilescanner.rl"
	{tmp_p2 = p;}
	goto st98;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
#line 4211 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr119;
		case 10: goto tr145;
		case 83: goto st99;
		case 115: goto st99;
	}
	goto st98;
tr143:
#line 371 "mfilescanner.rl"
	{tmp_p2 = p;}
	goto st99;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
#line 4227 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr119;
		case 10: goto tr145;
		case 69: goto st100;
		case 83: goto st99;
		case 101: goto st100;
		case 115: goto st99;
	}
	goto st98;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
	switch( (*p) ) {
		case 0: goto tr119;
		case 10: goto tr145;
		case 69: goto st101;
		case 83: goto st99;
		case 101: goto st101;
		case 115: goto st99;
	}
	goto st98;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
	switch( (*p) ) {
		case 0: goto tr119;
		case 10: goto tr145;
		case 32: goto st102;
		case 83: goto st99;
		case 115: goto st99;
	}
	goto st98;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
	switch( (*p) ) {
		case 0: goto tr119;
		case 10: goto tr145;
		case 65: goto st103;
		case 83: goto st99;
		case 97: goto st103;
		case 115: goto st99;
	}
	goto st98;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
	switch( (*p) ) {
		case 0: goto tr119;
		case 10: goto tr145;
		case 76: goto st104;
		case 83: goto st99;
		case 108: goto st104;
		case 115: goto st99;
	}
	goto st98;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
	switch( (*p) ) {
		case 0: goto tr119;
		case 10: goto tr145;
		case 83: goto st105;
		case 115: goto st105;
	}
	goto st98;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
	switch( (*p) ) {
		case 0: goto tr119;
		case 10: goto tr145;
		case 69: goto st100;
		case 79: goto st106;
		case 83: goto st99;
		case 101: goto st100;
		case 111: goto st106;
		case 115: goto st99;
	}
	goto st98;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
	switch( (*p) ) {
		case 0: goto tr119;
		case 10: goto tr141;
		case 83: goto tr143;
		case 115: goto tr143;
	}
	goto tr139;
tr140:
#line 371 "mfilescanner.rl"
	{tmp_p2 = p;}
	goto st107;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
#line 4333 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr119;
		case 9: goto st107;
		case 10: goto tr145;
		case 13: goto st108;
		case 32: goto st107;
		case 83: goto st99;
		case 115: goto st99;
	}
	goto st98;
tr142:
#line 371 "mfilescanner.rl"
	{tmp_p2 = p;}
	goto st108;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
#line 4352 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr119;
		case 10: goto tr145;
		case 83: goto st99;
		case 115: goto st99;
	}
	goto st98;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 83: goto st90;
		case 115: goto st90;
	}
	goto st87;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 82: goto st111;
		case 83: goto st90;
		case 114: goto st111;
		case 115: goto st90;
	}
	goto st87;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 71: goto st112;
		case 83: goto st90;
		case 103: goto st112;
		case 115: goto st90;
	}
	goto st87;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 83: goto st90;
		case 85: goto st113;
		case 115: goto st90;
		case 117: goto st113;
	}
	goto st87;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 77: goto st114;
		case 83: goto st90;
		case 109: goto st114;
		case 115: goto st90;
	}
	goto st87;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 69: goto st115;
		case 83: goto st90;
		case 101: goto st115;
		case 115: goto st90;
	}
	goto st87;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 78: goto st116;
		case 83: goto st90;
		case 110: goto st116;
		case 115: goto st90;
	}
	goto st87;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 83: goto st90;
		case 84: goto st117;
		case 115: goto st90;
		case 116: goto st117;
	}
	goto st87;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 83: goto st118;
		case 115: goto st118;
	}
	goto st87;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
	switch( (*p) ) {
		case 0: goto st88;
		case 9: goto st119;
		case 10: goto tr130;
		case 32: goto st119;
		case 58: goto st120;
		case 69: goto st91;
		case 83: goto st90;
		case 101: goto st91;
		case 115: goto st90;
	}
	goto st87;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
	switch( (*p) ) {
		case 0: goto st88;
		case 9: goto st119;
		case 10: goto tr130;
		case 32: goto st119;
		case 58: goto st120;
		case 83: goto st90;
		case 115: goto st90;
	}
	goto st87;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
	switch( (*p) ) {
		case 0: goto st88;
		case 9: goto st120;
		case 10: goto tr166;
		case 13: goto st121;
		case 32: goto st120;
		case 83: goto st90;
		case 115: goto st90;
	}
	goto st87;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr166;
		case 83: goto st90;
		case 115: goto st90;
	}
	goto st87;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 69: goto st123;
		case 83: goto st90;
		case 101: goto st123;
		case 115: goto st90;
	}
	goto st87;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 78: goto st124;
		case 83: goto st90;
		case 110: goto st124;
		case 115: goto st90;
	}
	goto st87;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 69: goto st125;
		case 83: goto st90;
		case 101: goto st125;
		case 115: goto st90;
	}
	goto st87;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 82: goto st126;
		case 83: goto st90;
		case 114: goto st126;
		case 115: goto st90;
	}
	goto st87;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 65: goto st127;
		case 83: goto st90;
		case 97: goto st127;
		case 115: goto st90;
	}
	goto st87;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 83: goto st90;
		case 84: goto st128;
		case 115: goto st90;
		case 116: goto st128;
	}
	goto st87;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 69: goto st129;
		case 83: goto st90;
		case 101: goto st129;
		case 115: goto st90;
	}
	goto st87;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 68: goto st130;
		case 83: goto st90;
		case 100: goto st130;
		case 115: goto st90;
	}
	goto st87;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 32: goto st131;
		case 83: goto st90;
		case 115: goto st90;
	}
	goto st87;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 70: goto st132;
		case 83: goto st90;
		case 102: goto st132;
		case 115: goto st90;
	}
	goto st87;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 73: goto st133;
		case 83: goto st90;
		case 105: goto st133;
		case 115: goto st90;
	}
	goto st87;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 69: goto st134;
		case 83: goto st90;
		case 101: goto st134;
		case 115: goto st90;
	}
	goto st87;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 76: goto st135;
		case 83: goto st90;
		case 108: goto st135;
		case 115: goto st90;
	}
	goto st87;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 68: goto st136;
		case 83: goto st90;
		case 100: goto st136;
		case 115: goto st90;
	}
	goto st87;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 83: goto st137;
		case 115: goto st137;
	}
	goto st87;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 32: goto st138;
		case 69: goto st91;
		case 83: goto st90;
		case 101: goto st91;
		case 115: goto st90;
	}
	goto st87;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 79: goto st139;
		case 83: goto st90;
		case 111: goto st139;
		case 115: goto st90;
	}
	goto st87;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 70: goto st140;
		case 83: goto st90;
		case 102: goto st140;
		case 115: goto st90;
	}
	goto st87;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 32: goto st141;
		case 83: goto st90;
		case 115: goto st90;
	}
	goto st87;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 83: goto tr188;
		case 95: goto tr187;
		case 115: goto tr188;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr187;
	} else if ( (*p) >= 65 )
		goto tr187;
	goto st87;
tr187:
#line 58 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st142;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
#line 4797 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st88;
		case 9: goto tr189;
		case 10: goto tr130;
		case 32: goto tr189;
		case 58: goto tr191;
		case 83: goto st146;
		case 95: goto st142;
		case 115: goto st146;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st142;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st142;
	} else
		goto st142;
	goto st87;
tr189:
#line 62 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st143;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
#line 4825 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st88;
		case 9: goto st143;
		case 10: goto tr130;
		case 32: goto st143;
		case 58: goto st144;
		case 83: goto st90;
		case 115: goto st90;
	}
	goto st87;
tr191:
#line 62 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st144;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
#line 4844 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st88;
		case 9: goto st144;
		case 10: goto tr195;
		case 13: goto st145;
		case 32: goto st144;
		case 83: goto st90;
		case 115: goto st90;
	}
	goto st87;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr195;
		case 83: goto st90;
		case 115: goto st90;
	}
	goto st87;
tr188:
#line 58 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st146;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
#line 4874 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st88;
		case 9: goto tr189;
		case 10: goto tr130;
		case 32: goto tr189;
		case 58: goto tr191;
		case 69: goto st147;
		case 83: goto st146;
		case 95: goto st142;
		case 101: goto st147;
		case 115: goto st146;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st142;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st142;
	} else
		goto st142;
	goto st87;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
	switch( (*p) ) {
		case 0: goto st88;
		case 9: goto tr189;
		case 10: goto tr130;
		case 32: goto tr189;
		case 58: goto tr191;
		case 69: goto st148;
		case 83: goto st146;
		case 95: goto st142;
		case 101: goto st148;
		case 115: goto st146;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st142;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st142;
	} else
		goto st142;
	goto st87;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
	switch( (*p) ) {
		case 0: goto st88;
		case 9: goto tr189;
		case 10: goto tr130;
		case 32: goto tr199;
		case 58: goto tr191;
		case 83: goto st146;
		case 95: goto st142;
		case 115: goto st146;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st142;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st142;
	} else
		goto st142;
	goto st87;
tr199:
#line 62 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st149;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
#line 4952 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st88;
		case 9: goto st143;
		case 10: goto tr130;
		case 32: goto st143;
		case 58: goto st144;
		case 65: goto st94;
		case 83: goto st90;
		case 97: goto st94;
		case 115: goto st90;
	}
	goto st87;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 80: goto st151;
		case 83: goto st90;
		case 112: goto st151;
		case 115: goto st90;
	}
	goto st87;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 83: goto st90;
		case 84: goto st152;
		case 115: goto st90;
		case 116: goto st152;
	}
	goto st87;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 73: goto st153;
		case 83: goto st90;
		case 105: goto st153;
		case 115: goto st90;
	}
	goto st87;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 79: goto st154;
		case 83: goto st90;
		case 111: goto st154;
		case 115: goto st90;
	}
	goto st87;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 78: goto st155;
		case 83: goto st90;
		case 110: goto st155;
		case 115: goto st90;
	}
	goto st87;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 65: goto st156;
		case 83: goto st90;
		case 97: goto st156;
		case 115: goto st90;
	}
	goto st87;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 76: goto st157;
		case 83: goto st90;
		case 108: goto st157;
		case 115: goto st90;
	}
	goto st87;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 32: goto st158;
		case 83: goto st90;
		case 115: goto st90;
	}
	goto st87;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 70: goto st159;
		case 83: goto st90;
		case 102: goto st159;
		case 115: goto st90;
	}
	goto st87;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 73: goto st160;
		case 83: goto st90;
		case 105: goto st160;
		case 115: goto st90;
	}
	goto st87;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 69: goto st161;
		case 83: goto st90;
		case 101: goto st161;
		case 115: goto st90;
	}
	goto st87;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 76: goto st162;
		case 83: goto st90;
		case 108: goto st162;
		case 115: goto st90;
	}
	goto st87;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 68: goto st163;
		case 83: goto st90;
		case 100: goto st163;
		case 115: goto st90;
	}
	goto st87;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 83: goto st164;
		case 115: goto st164;
	}
	goto st87;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 32: goto st165;
		case 69: goto st91;
		case 83: goto st90;
		case 101: goto st91;
		case 115: goto st90;
	}
	goto st87;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 79: goto st166;
		case 83: goto st90;
		case 111: goto st166;
		case 115: goto st90;
	}
	goto st87;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 70: goto st167;
		case 83: goto st90;
		case 102: goto st167;
		case 115: goto st90;
	}
	goto st87;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 32: goto st168;
		case 83: goto st90;
		case 115: goto st90;
	}
	goto st87;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 83: goto tr219;
		case 95: goto tr218;
		case 115: goto tr219;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr218;
	} else if ( (*p) >= 65 )
		goto tr218;
	goto st87;
tr218:
#line 58 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st169;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
#line 5221 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st88;
		case 9: goto tr220;
		case 10: goto tr130;
		case 32: goto tr220;
		case 58: goto tr222;
		case 83: goto st173;
		case 95: goto st169;
		case 115: goto st173;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st169;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st169;
	} else
		goto st169;
	goto st87;
tr220:
#line 62 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st170;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
#line 5249 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st88;
		case 9: goto st170;
		case 10: goto tr130;
		case 32: goto st170;
		case 58: goto st171;
		case 83: goto st90;
		case 115: goto st90;
	}
	goto st87;
tr222:
#line 62 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st171;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
#line 5268 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st88;
		case 9: goto st171;
		case 10: goto tr226;
		case 13: goto st172;
		case 32: goto st171;
		case 83: goto st90;
		case 115: goto st90;
	}
	goto st87;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr226;
		case 83: goto st90;
		case 115: goto st90;
	}
	goto st87;
tr219:
#line 58 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st173;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
#line 5298 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st88;
		case 9: goto tr220;
		case 10: goto tr130;
		case 32: goto tr220;
		case 58: goto tr222;
		case 69: goto st174;
		case 83: goto st173;
		case 95: goto st169;
		case 101: goto st174;
		case 115: goto st173;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st169;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st169;
	} else
		goto st169;
	goto st87;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
	switch( (*p) ) {
		case 0: goto st88;
		case 9: goto tr220;
		case 10: goto tr130;
		case 32: goto tr220;
		case 58: goto tr222;
		case 69: goto st175;
		case 83: goto st173;
		case 95: goto st169;
		case 101: goto st175;
		case 115: goto st173;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st169;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st169;
	} else
		goto st169;
	goto st87;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
	switch( (*p) ) {
		case 0: goto st88;
		case 9: goto tr220;
		case 10: goto tr130;
		case 32: goto tr230;
		case 58: goto tr222;
		case 83: goto st173;
		case 95: goto st169;
		case 115: goto st173;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st169;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st169;
	} else
		goto st169;
	goto st87;
tr230:
#line 62 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st176;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
#line 5376 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st88;
		case 9: goto st170;
		case 10: goto tr130;
		case 32: goto st170;
		case 58: goto st171;
		case 65: goto st94;
		case 83: goto st90;
		case 97: goto st94;
		case 115: goto st90;
	}
	goto st87;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 69: goto st178;
		case 83: goto st90;
		case 101: goto st178;
		case 115: goto st90;
	}
	goto st87;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 81: goto st179;
		case 83: goto st90;
		case 84: goto st204;
		case 113: goto st179;
		case 115: goto st90;
		case 116: goto st204;
	}
	goto st87;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 83: goto st90;
		case 85: goto st180;
		case 115: goto st90;
		case 117: goto st180;
	}
	goto st87;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 73: goto st181;
		case 83: goto st90;
		case 105: goto st181;
		case 115: goto st90;
	}
	goto st87;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 82: goto st182;
		case 83: goto st90;
		case 114: goto st182;
		case 115: goto st90;
	}
	goto st87;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 69: goto st183;
		case 83: goto st90;
		case 101: goto st183;
		case 115: goto st90;
	}
	goto st87;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 68: goto st184;
		case 83: goto st90;
		case 100: goto st184;
		case 115: goto st90;
	}
	goto st87;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 32: goto st185;
		case 83: goto st90;
		case 115: goto st90;
	}
	goto st87;
st185:
	if ( ++p == pe )
		goto _test_eof185;
case 185:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 70: goto st186;
		case 83: goto st90;
		case 102: goto st186;
		case 115: goto st90;
	}
	goto st87;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 73: goto st187;
		case 83: goto st90;
		case 105: goto st187;
		case 115: goto st90;
	}
	goto st87;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 69: goto st188;
		case 83: goto st90;
		case 101: goto st188;
		case 115: goto st90;
	}
	goto st87;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 76: goto st189;
		case 83: goto st90;
		case 108: goto st189;
		case 115: goto st90;
	}
	goto st87;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 68: goto st190;
		case 83: goto st90;
		case 100: goto st190;
		case 115: goto st90;
	}
	goto st87;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 83: goto st191;
		case 115: goto st191;
	}
	goto st87;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 32: goto st192;
		case 69: goto st91;
		case 83: goto st90;
		case 101: goto st91;
		case 115: goto st90;
	}
	goto st87;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 79: goto st193;
		case 83: goto st90;
		case 111: goto st193;
		case 115: goto st90;
	}
	goto st87;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 70: goto st194;
		case 83: goto st90;
		case 102: goto st194;
		case 115: goto st90;
	}
	goto st87;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 32: goto st195;
		case 83: goto st90;
		case 115: goto st90;
	}
	goto st87;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 83: goto tr251;
		case 95: goto tr250;
		case 115: goto tr251;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr250;
	} else if ( (*p) >= 65 )
		goto tr250;
	goto st87;
tr250:
#line 58 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st196;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
#line 5647 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st88;
		case 9: goto tr252;
		case 10: goto tr130;
		case 32: goto tr252;
		case 58: goto tr254;
		case 83: goto st200;
		case 95: goto st196;
		case 115: goto st200;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st196;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st196;
	} else
		goto st196;
	goto st87;
tr252:
#line 62 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st197;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
#line 5675 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st88;
		case 9: goto st197;
		case 10: goto tr130;
		case 32: goto st197;
		case 58: goto st198;
		case 83: goto st90;
		case 115: goto st90;
	}
	goto st87;
tr254:
#line 62 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st198;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
#line 5694 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st88;
		case 9: goto st198;
		case 10: goto tr258;
		case 13: goto st199;
		case 32: goto st198;
		case 83: goto st90;
		case 115: goto st90;
	}
	goto st87;
st199:
	if ( ++p == pe )
		goto _test_eof199;
case 199:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr258;
		case 83: goto st90;
		case 115: goto st90;
	}
	goto st87;
tr251:
#line 58 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st200;
st200:
	if ( ++p == pe )
		goto _test_eof200;
case 200:
#line 5724 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st88;
		case 9: goto tr252;
		case 10: goto tr130;
		case 32: goto tr252;
		case 58: goto tr254;
		case 69: goto st201;
		case 83: goto st200;
		case 95: goto st196;
		case 101: goto st201;
		case 115: goto st200;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st196;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st196;
	} else
		goto st196;
	goto st87;
st201:
	if ( ++p == pe )
		goto _test_eof201;
case 201:
	switch( (*p) ) {
		case 0: goto st88;
		case 9: goto tr252;
		case 10: goto tr130;
		case 32: goto tr252;
		case 58: goto tr254;
		case 69: goto st202;
		case 83: goto st200;
		case 95: goto st196;
		case 101: goto st202;
		case 115: goto st200;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st196;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st196;
	} else
		goto st196;
	goto st87;
st202:
	if ( ++p == pe )
		goto _test_eof202;
case 202:
	switch( (*p) ) {
		case 0: goto st88;
		case 9: goto tr252;
		case 10: goto tr130;
		case 32: goto tr262;
		case 58: goto tr254;
		case 83: goto st200;
		case 95: goto st196;
		case 115: goto st200;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st196;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st196;
	} else
		goto st196;
	goto st87;
tr262:
#line 62 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st203;
st203:
	if ( ++p == pe )
		goto _test_eof203;
case 203:
#line 5802 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st88;
		case 9: goto st197;
		case 10: goto tr130;
		case 32: goto st197;
		case 58: goto st198;
		case 65: goto st94;
		case 83: goto st90;
		case 97: goto st94;
		case 115: goto st90;
	}
	goto st87;
st204:
	if ( ++p == pe )
		goto _test_eof204;
case 204:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 83: goto st90;
		case 85: goto st205;
		case 115: goto st90;
		case 117: goto st205;
	}
	goto st87;
st205:
	if ( ++p == pe )
		goto _test_eof205;
case 205:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 82: goto st206;
		case 83: goto st90;
		case 114: goto st206;
		case 115: goto st90;
	}
	goto st87;
st206:
	if ( ++p == pe )
		goto _test_eof206;
case 206:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 78: goto st207;
		case 83: goto st90;
		case 110: goto st207;
		case 115: goto st90;
	}
	goto st87;
st207:
	if ( ++p == pe )
		goto _test_eof207;
case 207:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 32: goto st208;
		case 83: goto st90;
		case 115: goto st90;
	}
	goto st87;
st208:
	if ( ++p == pe )
		goto _test_eof208;
case 208:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 65: goto st209;
		case 83: goto st90;
		case 97: goto st209;
		case 115: goto st90;
	}
	goto st87;
st209:
	if ( ++p == pe )
		goto _test_eof209;
case 209:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 82: goto st210;
		case 83: goto st90;
		case 114: goto st210;
		case 115: goto st90;
	}
	goto st87;
st210:
	if ( ++p == pe )
		goto _test_eof210;
case 210:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 71: goto st211;
		case 83: goto st90;
		case 103: goto st211;
		case 115: goto st90;
	}
	goto st87;
st211:
	if ( ++p == pe )
		goto _test_eof211;
case 211:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 83: goto st90;
		case 85: goto st212;
		case 115: goto st90;
		case 117: goto st212;
	}
	goto st87;
st212:
	if ( ++p == pe )
		goto _test_eof212;
case 212:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 77: goto st213;
		case 83: goto st90;
		case 109: goto st213;
		case 115: goto st90;
	}
	goto st87;
st213:
	if ( ++p == pe )
		goto _test_eof213;
case 213:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 69: goto st214;
		case 83: goto st90;
		case 101: goto st214;
		case 115: goto st90;
	}
	goto st87;
st214:
	if ( ++p == pe )
		goto _test_eof214;
case 214:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 78: goto st215;
		case 83: goto st90;
		case 110: goto st215;
		case 115: goto st90;
	}
	goto st87;
st215:
	if ( ++p == pe )
		goto _test_eof215;
case 215:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 83: goto st90;
		case 84: goto st216;
		case 115: goto st90;
		case 116: goto st216;
	}
	goto st87;
st216:
	if ( ++p == pe )
		goto _test_eof216;
case 216:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr130;
		case 83: goto st217;
		case 115: goto st217;
	}
	goto st87;
st217:
	if ( ++p == pe )
		goto _test_eof217;
case 217:
	switch( (*p) ) {
		case 0: goto st88;
		case 9: goto st218;
		case 10: goto tr130;
		case 32: goto st218;
		case 58: goto st219;
		case 69: goto st91;
		case 83: goto st90;
		case 101: goto st91;
		case 115: goto st90;
	}
	goto st87;
st218:
	if ( ++p == pe )
		goto _test_eof218;
case 218:
	switch( (*p) ) {
		case 0: goto st88;
		case 9: goto st218;
		case 10: goto tr130;
		case 32: goto st218;
		case 58: goto st219;
		case 83: goto st90;
		case 115: goto st90;
	}
	goto st87;
st219:
	if ( ++p == pe )
		goto _test_eof219;
case 219:
	switch( (*p) ) {
		case 0: goto st88;
		case 9: goto st219;
		case 10: goto tr278;
		case 13: goto st220;
		case 32: goto st219;
		case 83: goto st90;
		case 115: goto st90;
	}
	goto st87;
st220:
	if ( ++p == pe )
		goto _test_eof220;
case 220:
	switch( (*p) ) {
		case 0: goto st88;
		case 10: goto tr278;
		case 83: goto st90;
		case 115: goto st90;
	}
	goto st87;
tr283:
#line 28 "mfilescanner.rl"
	{line++;}
#line 474 "mfilescanner.rl"
	{te = p+1;{ {goto st348;} }}
	goto st347;
tr288:
#line 28 "mfilescanner.rl"
	{line++;}
#line 471 "mfilescanner.rl"
	{te = p+1;}
	goto st347;
st347:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof347;
case 347:
#line 1 "NONE"
	{ts = p;}
#line 6056 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st221;
		case 32: goto st221;
		case 37: goto tr281;
	}
	goto st0;
st221:
	if ( ++p == pe )
		goto _test_eof221;
case 221:
	switch( (*p) ) {
		case 9: goto st221;
		case 32: goto st221;
		case 37: goto tr281;
	}
	goto st0;
tr281:
#line 74 "mfilescanner.rl"
	{ tmp_p = p + 1; }
	goto st222;
st222:
	if ( ++p == pe )
		goto _test_eof222;
case 222:
#line 6081 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr283;
		case 46: goto st223;
	}
	goto st222;
st223:
	if ( ++p == pe )
		goto _test_eof223;
case 223:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr283;
		case 46: goto st224;
	}
	goto st222;
st224:
	if ( ++p == pe )
		goto _test_eof224;
case 224:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr283;
		case 46: goto st225;
	}
	goto st222;
st225:
	if ( ++p == pe )
		goto _test_eof225;
case 225:
	switch( (*p) ) {
		case 9: goto st226;
		case 10: goto tr288;
		case 13: goto st227;
		case 32: goto st226;
		case 46: goto st228;
	}
	goto st0;
st226:
	if ( ++p == pe )
		goto _test_eof226;
case 226:
	switch( (*p) ) {
		case 9: goto st226;
		case 10: goto tr288;
		case 13: goto st227;
		case 32: goto st226;
	}
	goto st0;
st227:
	if ( ++p == pe )
		goto _test_eof227;
case 227:
	if ( (*p) == 10 )
		goto tr288;
	goto st0;
st228:
	if ( ++p == pe )
		goto _test_eof228;
case 228:
	switch( (*p) ) {
		case 9: goto st226;
		case 10: goto tr288;
		case 13: goto st227;
		case 32: goto st226;
		case 46: goto st226;
	}
	goto st0;
tr291:
#line 1 "NONE"
	{	switch( act ) {
	case 0:
	{{goto st0;}}
	break;
	case 33:
	{{p = ((te))-1;}
        p--;
        //cout << "*/\n";
        {goto st338;}
      }
	break;
	}
	}
	goto st348;
tr294:
#line 28 "mfilescanner.rl"
	{line++;}
#line 491 "mfilescanner.rl"
	{te = p+1;{
        /*cout << "*\n";*/
        {goto st344;}
      }}
	goto st348;
tr296:
#line 28 "mfilescanner.rl"
	{line++;}
#line 484 "mfilescanner.rl"
	{te = p+1;{
        /* cout << "*"; cout.write(tmp_p, p - tmp_p+1); */
        docuheader_.push_back(string(tmp_p, p - tmp_p+1));
      }}
	goto st348;
tr493:
#line 498 "mfilescanner.rl"
	{te = p+1;{
        p--;
        //cout << "*/\n";
        {goto st338;}
      }}
	goto st348;
tr496:
#line 498 "mfilescanner.rl"
	{te = p;p--;{
        p--;
        //cout << "*/\n";
        {goto st338;}
      }}
	goto st348;
st348:
#line 1 "NONE"
	{ts = 0;}
#line 1 "NONE"
	{act = 0;}
	if ( ++p == pe )
		goto _test_eof348;
case 348:
#line 1 "NONE"
	{ts = p;}
#line 6210 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr494;
		case 32: goto tr494;
		case 37: goto tr495;
	}
	goto tr493;
tr494:
#line 1 "NONE"
	{te = p+1;}
#line 498 "mfilescanner.rl"
	{act = 33;}
	goto st349;
st349:
	if ( ++p == pe )
		goto _test_eof349;
case 349:
#line 6227 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr494;
		case 32: goto tr494;
		case 37: goto tr495;
	}
	goto tr493;
tr495:
#line 74 "mfilescanner.rl"
	{ tmp_p = p + 1; }
	goto st229;
st229:
	if ( ++p == pe )
		goto _test_eof229;
case 229:
#line 6242 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr291;
		case 9: goto st229;
		case 10: goto tr294;
		case 13: goto st231;
		case 32: goto st229;
	}
	goto st230;
st230:
	if ( ++p == pe )
		goto _test_eof230;
case 230:
	switch( (*p) ) {
		case 0: goto tr291;
		case 10: goto tr296;
	}
	goto st230;
st231:
	if ( ++p == pe )
		goto _test_eof231;
case 231:
	switch( (*p) ) {
		case 0: goto tr291;
		case 10: goto tr296;
	}
	goto st230;
	}
	_test_eof314: cs = 314; goto _test_eof; 
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
	_test_eof242: cs = 242; goto _test_eof; 
	_test_eof350: cs = 350; goto _test_eof; 
	_test_eof243: cs = 243; goto _test_eof; 
	_test_eof244: cs = 244; goto _test_eof; 
	_test_eof245: cs = 245; goto _test_eof; 
	_test_eof246: cs = 246; goto _test_eof; 
	_test_eof247: cs = 247; goto _test_eof; 
	_test_eof351: cs = 351; goto _test_eof; 
	_test_eof248: cs = 248; goto _test_eof; 
	_test_eof352: cs = 352; goto _test_eof; 
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
	_test_eof353: cs = 353; goto _test_eof; 
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
	_test_eof303: cs = 303; goto _test_eof; 
	_test_eof304: cs = 304; goto _test_eof; 
	_test_eof305: cs = 305; goto _test_eof; 
	_test_eof306: cs = 306; goto _test_eof; 
	_test_eof307: cs = 307; goto _test_eof; 
	_test_eof308: cs = 308; goto _test_eof; 
	_test_eof309: cs = 309; goto _test_eof; 
	_test_eof310: cs = 310; goto _test_eof; 
	_test_eof311: cs = 311; goto _test_eof; 
	_test_eof312: cs = 312; goto _test_eof; 
	_test_eof313: cs = 313; goto _test_eof; 
	_test_eof315: cs = 315; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof316: cs = 316; goto _test_eof; 
	_test_eof317: cs = 317; goto _test_eof; 
	_test_eof318: cs = 318; goto _test_eof; 
	_test_eof319: cs = 319; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof320: cs = 320; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof321: cs = 321; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof322: cs = 322; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof323: cs = 323; goto _test_eof; 
	_test_eof324: cs = 324; goto _test_eof; 
	_test_eof325: cs = 325; goto _test_eof; 
	_test_eof326: cs = 326; goto _test_eof; 
	_test_eof327: cs = 327; goto _test_eof; 
	_test_eof328: cs = 328; goto _test_eof; 
	_test_eof329: cs = 329; goto _test_eof; 
	_test_eof330: cs = 330; goto _test_eof; 
	_test_eof331: cs = 331; goto _test_eof; 
	_test_eof332: cs = 332; goto _test_eof; 
	_test_eof333: cs = 333; goto _test_eof; 
	_test_eof334: cs = 334; goto _test_eof; 
	_test_eof335: cs = 335; goto _test_eof; 
	_test_eof336: cs = 336; goto _test_eof; 
	_test_eof337: cs = 337; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof23: cs = 23; goto _test_eof; 
	_test_eof24: cs = 24; goto _test_eof; 
	_test_eof25: cs = 25; goto _test_eof; 
	_test_eof26: cs = 26; goto _test_eof; 
	_test_eof27: cs = 27; goto _test_eof; 
	_test_eof338: cs = 338; goto _test_eof; 
	_test_eof28: cs = 28; goto _test_eof; 
	_test_eof339: cs = 339; goto _test_eof; 
	_test_eof29: cs = 29; goto _test_eof; 
	_test_eof30: cs = 30; goto _test_eof; 
	_test_eof31: cs = 31; goto _test_eof; 
	_test_eof32: cs = 32; goto _test_eof; 
	_test_eof340: cs = 340; goto _test_eof; 
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
	_test_eof74: cs = 74; goto _test_eof; 
	_test_eof75: cs = 75; goto _test_eof; 
	_test_eof341: cs = 341; goto _test_eof; 
	_test_eof342: cs = 342; goto _test_eof; 
	_test_eof343: cs = 343; goto _test_eof; 
	_test_eof76: cs = 76; goto _test_eof; 
	_test_eof77: cs = 77; goto _test_eof; 
	_test_eof78: cs = 78; goto _test_eof; 
	_test_eof79: cs = 79; goto _test_eof; 
	_test_eof80: cs = 80; goto _test_eof; 
	_test_eof81: cs = 81; goto _test_eof; 
	_test_eof82: cs = 82; goto _test_eof; 
	_test_eof83: cs = 83; goto _test_eof; 
	_test_eof84: cs = 84; goto _test_eof; 
	_test_eof85: cs = 85; goto _test_eof; 
	_test_eof344: cs = 344; goto _test_eof; 
	_test_eof345: cs = 345; goto _test_eof; 
	_test_eof346: cs = 346; goto _test_eof; 
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
	_test_eof191: cs = 191; goto _test_eof; 
	_test_eof192: cs = 192; goto _test_eof; 
	_test_eof193: cs = 193; goto _test_eof; 
	_test_eof194: cs = 194; goto _test_eof; 
	_test_eof195: cs = 195; goto _test_eof; 
	_test_eof196: cs = 196; goto _test_eof; 
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
	_test_eof208: cs = 208; goto _test_eof; 
	_test_eof209: cs = 209; goto _test_eof; 
	_test_eof210: cs = 210; goto _test_eof; 
	_test_eof211: cs = 211; goto _test_eof; 
	_test_eof212: cs = 212; goto _test_eof; 
	_test_eof213: cs = 213; goto _test_eof; 
	_test_eof214: cs = 214; goto _test_eof; 
	_test_eof215: cs = 215; goto _test_eof; 
	_test_eof216: cs = 216; goto _test_eof; 
	_test_eof217: cs = 217; goto _test_eof; 
	_test_eof218: cs = 218; goto _test_eof; 
	_test_eof219: cs = 219; goto _test_eof; 
	_test_eof220: cs = 220; goto _test_eof; 
	_test_eof347: cs = 347; goto _test_eof; 
	_test_eof221: cs = 221; goto _test_eof; 
	_test_eof222: cs = 222; goto _test_eof; 
	_test_eof223: cs = 223; goto _test_eof; 
	_test_eof224: cs = 224; goto _test_eof; 
	_test_eof225: cs = 225; goto _test_eof; 
	_test_eof226: cs = 226; goto _test_eof; 
	_test_eof227: cs = 227; goto _test_eof; 
	_test_eof228: cs = 228; goto _test_eof; 
	_test_eof348: cs = 348; goto _test_eof; 
	_test_eof349: cs = 349; goto _test_eof; 
	_test_eof229: cs = 229; goto _test_eof; 
	_test_eof230: cs = 230; goto _test_eof; 
	_test_eof231: cs = 231; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 317: goto tr454;
	case 318: goto tr455;
	case 319: goto tr455;
	case 13: goto tr17;
	case 320: goto tr455;
	case 14: goto tr17;
	case 15: goto tr17;
	case 16: goto tr17;
	case 321: goto tr457;
	case 17: goto tr23;
	case 322: goto tr459;
	case 18: goto tr25;
	case 19: goto tr25;
	case 323: goto tr457;
	case 324: goto tr457;
	case 325: goto tr457;
	case 326: goto tr457;
	case 327: goto tr457;
	case 328: goto tr457;
	case 329: goto tr457;
	case 330: goto tr457;
	case 331: goto tr457;
	case 332: goto tr457;
	case 333: goto tr457;
	case 334: goto tr457;
	case 335: goto tr457;
	case 336: goto tr457;
	case 337: goto tr457;
	case 20: goto tr23;
	case 21: goto tr23;
	case 22: goto tr23;
	case 23: goto tr23;
	case 24: goto tr23;
	case 25: goto tr23;
	case 26: goto tr23;
	case 27: goto tr23;
	case 339: goto tr479;
	case 340: goto tr479;
	case 33: goto tr53;
	case 342: goto tr486;
	case 343: goto tr486;
	case 76: goto tr101;
	case 77: goto tr101;
	case 78: goto tr101;
	case 79: goto tr101;
	case 80: goto tr101;
	case 81: goto tr101;
	case 82: goto tr101;
	case 83: goto tr101;
	case 84: goto tr101;
	case 85: goto tr101;
	case 345: goto tr492;
	case 346: goto tr492;
	case 86: goto tr119;
	case 87: goto tr119;
	case 88: goto tr119;
	case 89: goto tr119;
	case 90: goto tr119;
	case 91: goto tr119;
	case 92: goto tr119;
	case 93: goto tr119;
	case 94: goto tr119;
	case 95: goto tr119;
	case 96: goto tr119;
	case 97: goto tr119;
	case 98: goto tr119;
	case 99: goto tr119;
	case 100: goto tr119;
	case 101: goto tr119;
	case 102: goto tr119;
	case 103: goto tr119;
	case 104: goto tr119;
	case 105: goto tr119;
	case 106: goto tr119;
	case 107: goto tr119;
	case 108: goto tr119;
	case 109: goto tr119;
	case 110: goto tr119;
	case 111: goto tr119;
	case 112: goto tr119;
	case 113: goto tr119;
	case 114: goto tr119;
	case 115: goto tr119;
	case 116: goto tr119;
	case 117: goto tr119;
	case 118: goto tr119;
	case 119: goto tr119;
	case 120: goto tr119;
	case 121: goto tr119;
	case 122: goto tr119;
	case 123: goto tr119;
	case 124: goto tr119;
	case 125: goto tr119;
	case 126: goto tr119;
	case 127: goto tr119;
	case 128: goto tr119;
	case 129: goto tr119;
	case 130: goto tr119;
	case 131: goto tr119;
	case 132: goto tr119;
	case 133: goto tr119;
	case 134: goto tr119;
	case 135: goto tr119;
	case 136: goto tr119;
	case 137: goto tr119;
	case 138: goto tr119;
	case 139: goto tr119;
	case 140: goto tr119;
	case 141: goto tr119;
	case 142: goto tr119;
	case 143: goto tr119;
	case 144: goto tr119;
	case 145: goto tr119;
	case 146: goto tr119;
	case 147: goto tr119;
	case 148: goto tr119;
	case 149: goto tr119;
	case 150: goto tr119;
	case 151: goto tr119;
	case 152: goto tr119;
	case 153: goto tr119;
	case 154: goto tr119;
	case 155: goto tr119;
	case 156: goto tr119;
	case 157: goto tr119;
	case 158: goto tr119;
	case 159: goto tr119;
	case 160: goto tr119;
	case 161: goto tr119;
	case 162: goto tr119;
	case 163: goto tr119;
	case 164: goto tr119;
	case 165: goto tr119;
	case 166: goto tr119;
	case 167: goto tr119;
	case 168: goto tr119;
	case 169: goto tr119;
	case 170: goto tr119;
	case 171: goto tr119;
	case 172: goto tr119;
	case 173: goto tr119;
	case 174: goto tr119;
	case 175: goto tr119;
	case 176: goto tr119;
	case 177: goto tr119;
	case 178: goto tr119;
	case 179: goto tr119;
	case 180: goto tr119;
	case 181: goto tr119;
	case 182: goto tr119;
	case 183: goto tr119;
	case 184: goto tr119;
	case 185: goto tr119;
	case 186: goto tr119;
	case 187: goto tr119;
	case 188: goto tr119;
	case 189: goto tr119;
	case 190: goto tr119;
	case 191: goto tr119;
	case 192: goto tr119;
	case 193: goto tr119;
	case 194: goto tr119;
	case 195: goto tr119;
	case 196: goto tr119;
	case 197: goto tr119;
	case 198: goto tr119;
	case 199: goto tr119;
	case 200: goto tr119;
	case 201: goto tr119;
	case 202: goto tr119;
	case 203: goto tr119;
	case 204: goto tr119;
	case 205: goto tr119;
	case 206: goto tr119;
	case 207: goto tr119;
	case 208: goto tr119;
	case 209: goto tr119;
	case 210: goto tr119;
	case 211: goto tr119;
	case 212: goto tr119;
	case 213: goto tr119;
	case 214: goto tr119;
	case 215: goto tr119;
	case 216: goto tr119;
	case 217: goto tr119;
	case 218: goto tr119;
	case 219: goto tr119;
	case 220: goto tr119;
	case 349: goto tr496;
	case 229: goto tr291;
	case 230: goto tr291;
	case 231: goto tr291;
	case 12: 
#line 37 "mfilescanner.rl"
	{
    cout << "*/\n";
    p--;
    {cs = stack[--top];goto _again;}
  }
	break;
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
	case 287: 
	case 288: 
	case 289: 
	case 290: 
	case 291: 
	case 292: 
	case 293: 
	case 294: 
	case 295: 
	case 296: 
	case 297: 
	case 298: 
	case 299: 
	case 300: 
	case 301: 
	case 302: 
	case 303: 
	case 304: 
	case 305: 
	case 306: 
	case 307: 
	case 308: 
	case 309: 
	case 310: 
	case 311: 
	case 312: 
	case 313: 
	case 338: 
	case 353: 
#line 44 "mfilescanner.rl"
	{
    /*    cout << "EOF\n";*/
    end_function();
  }
	break;
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
#line 519 "mfilescanner.rl"
	{
        p = tmp_p - 2;
        {goto st348;}
      }
	break;
	case 247: 
#line 533 "mfilescanner.rl"
	{
    p--;
    {goto st338;}
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
#line 609 "mfilescanner.rl"
	{
    p=tmp_p;
    {goto st248;}
  }
	break;
#line 6945 "mfilescanner.cc"
	}
	}

	_out: {}
	}

#line 689 "mfilescanner.rl"

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
    is_first_function_ = false;
    cout << "*/\n";
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

  // return fields
  write_docu_listmap(retval_list_, "@par Generated fields of ", cscan_.field_docu_);
  retval_list_.clear();

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

