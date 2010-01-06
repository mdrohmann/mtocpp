
#line 1 "confscanner.rl"
#include "confscanner.h"

extern "C" {
#include <fnmatch.h>
}

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::set;
using std::ifstream;


#line 20 "confscanner.cc"
static const int ConfFileScanner_start = 879;
static const int ConfFileScanner_first_final = 879;
static const int ConfFileScanner_error = 0;

static const int ConfFileScanner_en_garbling = 22;
static const int ConfFileScanner_en_docu_block_line = 884;
static const int ConfFileScanner_en_rules = 886;
static const int ConfFileScanner_en_main = 879;


#line 278 "confscanner.rl"


void ConfFileScanner :: go_level_down()
{
  globlist_stack_.pop_back();
  globlist_stack_.back().clear();
  level_--;
}

bool ConfFileScanner :: check_for_match(int l, const char * str,
                                        bool match_path_sep)
{
  typedef GlobList :: iterator iterator;
  GlobList & gl = globlist_stack_[l];
  /*  cerr << "globlist at level" << l << "\n  ";
  for(unsigned int i = 0; i < gl.size(); ++i)
  {
    cerr << gl[i] << " ";
  }
  cerr << endl;*/
  iterator endit = gl.end();
  int flags = (match_path_sep? FNM_PATHNAME : 0);
  // cerr << "checking for match at level " << l <<" of string " << str << ":" << endl;
  for( iterator it = gl.begin(); it != endit; it++ )
  {
    // cerr << "with pattern: " << (*it).c_str() << endl;
    if(fnmatch((*it).c_str(), str, flags) == 0)
    {
      // cerr << "SUCCESS!" << endl;
      return true;
    }
  }
  return false;
}

bool ConfFileScanner :: check_glob_rec(int l, const string & s)
{
  string str;
  string :: size_type found;
  if(l == level_+1)
    return true;
/*  if(l == level_)
  {*/
    /* true if all leading directories in path or the whole path string are
     * matched by pattern
     */
/*    found = s.rfind("/");
    if(found != string::npos)
    {
      str = s.substr(0, found);
      if(check_for_match(l, str.c_str()))
        return true;
    }
    // else: try to match complete string
    return check_for_match(l, s.c_str());
  }*/

  found = s.find("/"); // try to match dir in path
  while(found != string :: npos)
  {
    str = s.substr(0, found);
//    cerr << str << endl;
    if(check_for_match(l, str.c_str())
        && check_glob_rec(l+1, s.substr(found+1)))
      return true;

    found = s.find("/", found+1); // try to match more dirs
  }
  if(l == level_) // try also to match the entire string
  {
    if(check_for_match(l, s.c_str()))
      return true;
  }

  return false;
}

void ConfFileScanner :: check_glob_level_up()
{
  match_at_level_[level_+1] = check_glob_rec(0, filename_);
/*  cerr << "going one level up, match at this level is: "
       << (match_at_level_[level_+1] ? "true" : "false");
  cerr << endl;*/

  globlist_stack_.push_back(GlobList());
  level_++;
}

ConfFileScanner
:: ConfFileScanner(const std::string & filename)
 : line(1), have(0), top(0), opt(true),
   filename_(filename),
   confistream_(set_conffile()),
   level_(0),
   arg_to_be_added_(false)
{
  globlist_stack_.push_back(GlobList());
  match_at_level_[0] = true;
}

const char * ConfFileScanner ::
set_conffile()
{
  conffile_ = "sample.conf";
  return conffile_.c_str();
}

int ConfFileScanner :: execute()
{
  //cerr << "execute\n";
  std::ios::sync_with_stdio(false);

  
#line 145 "confscanner.cc"
	{
	cs = ConfFileScanner_start;
	top = 0;
	}

#line 391 "confscanner.rl"

  /* Do the first read. */
  bool done = false;
  while ( !done )
  {
    char *p = buf + have;
    char *tmp_p = p;// *tmp_p2 = p;
    string tmp_string;
    int space = BUFSIZE - have;

    if ( space == 0 )
    {
      /* We filled up the buffer trying to scan a token. */
      cerr << "OUT OF BUFFER SPACE" << endl;
      exit(1);
    }

    confistream_.read( p, space );
    int len = confistream_.gcount();
    char *pe = p + len;
    char *rpe = pe;
    char *eof = 0;

    /* If we see eof then append the EOF char. */
    if ( confistream_.eof() )
    {
      eof = pe;
      done = true;
    }
    else
    {
      /* Find the last semicolon by searching backwards. This
       * is where we will stop processing on this iteration. */
      while ( *pe!= ';' && pe > p )
        pe--;
    }

    
#line 190 "confscanner.cc"
	{
	if ( p == pe )
		goto _test_eof;
	goto _resume;

_again:
	switch ( cs ) {
		case 879: goto st879;
		case 0: goto st0;
		case 1: goto st1;
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
		case 12: goto st12;
		case 13: goto st13;
		case 14: goto st14;
		case 15: goto st15;
		case 880: goto st880;
		case 16: goto st16;
		case 17: goto st17;
		case 18: goto st18;
		case 19: goto st19;
		case 20: goto st20;
		case 881: goto st881;
		case 21: goto st21;
		case 882: goto st882;
		case 22: goto st22;
		case 883: goto st883;
		case 884: goto st884;
		case 885: goto st885;
		case 23: goto st23;
		case 24: goto st24;
		case 886: goto st886;
		case 25: goto st25;
		case 26: goto st26;
		case 27: goto st27;
		case 28: goto st28;
		case 29: goto st29;
		case 30: goto st30;
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
		case 887: goto st887;
		case 888: goto st888;
		case 142: goto st142;
		case 143: goto st143;
		case 889: goto st889;
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
		case 890: goto st890;
		case 169: goto st169;
		case 170: goto st170;
		case 891: goto st891;
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
		case 892: goto st892;
		case 185: goto st185;
		case 186: goto st186;
		case 893: goto st893;
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
		case 894: goto st894;
		case 895: goto st895;
		case 202: goto st202;
		case 203: goto st203;
		case 896: goto st896;
		case 897: goto st897;
		case 204: goto st204;
		case 205: goto st205;
		case 898: goto st898;
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
		case 221: goto st221;
		case 899: goto st899;
		case 222: goto st222;
		case 223: goto st223;
		case 224: goto st224;
		case 900: goto st900;
		case 901: goto st901;
		case 225: goto st225;
		case 226: goto st226;
		case 902: goto st902;
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
		case 903: goto st903;
		case 275: goto st275;
		case 276: goto st276;
		case 904: goto st904;
		case 277: goto st277;
		case 278: goto st278;
		case 279: goto st279;
		case 280: goto st280;
		case 281: goto st281;
		case 282: goto st282;
		case 905: goto st905;
		case 283: goto st283;
		case 284: goto st284;
		case 285: goto st285;
		case 286: goto st286;
		case 906: goto st906;
		case 287: goto st287;
		case 288: goto st288;
		case 907: goto st907;
		case 289: goto st289;
		case 290: goto st290;
		case 291: goto st291;
		case 292: goto st292;
		case 293: goto st293;
		case 294: goto st294;
		case 908: goto st908;
		case 295: goto st295;
		case 296: goto st296;
		case 909: goto st909;
		case 297: goto st297;
		case 298: goto st298;
		case 910: goto st910;
		case 299: goto st299;
		case 300: goto st300;
		case 301: goto st301;
		case 302: goto st302;
		case 303: goto st303;
		case 304: goto st304;
		case 305: goto st305;
		case 911: goto st911;
		case 306: goto st306;
		case 307: goto st307;
		case 912: goto st912;
		case 308: goto st308;
		case 309: goto st309;
		case 913: goto st913;
		case 310: goto st310;
		case 311: goto st311;
		case 312: goto st312;
		case 313: goto st313;
		case 314: goto st314;
		case 315: goto st315;
		case 316: goto st316;
		case 317: goto st317;
		case 318: goto st318;
		case 319: goto st319;
		case 320: goto st320;
		case 321: goto st321;
		case 914: goto st914;
		case 915: goto st915;
		case 322: goto st322;
		case 323: goto st323;
		case 916: goto st916;
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
		case 338: goto st338;
		case 339: goto st339;
		case 340: goto st340;
		case 341: goto st341;
		case 342: goto st342;
		case 343: goto st343;
		case 344: goto st344;
		case 345: goto st345;
		case 917: goto st917;
		case 346: goto st346;
		case 347: goto st347;
		case 918: goto st918;
		case 348: goto st348;
		case 349: goto st349;
		case 350: goto st350;
		case 351: goto st351;
		case 352: goto st352;
		case 353: goto st353;
		case 354: goto st354;
		case 355: goto st355;
		case 356: goto st356;
		case 357: goto st357;
		case 358: goto st358;
		case 919: goto st919;
		case 359: goto st359;
		case 360: goto st360;
		case 920: goto st920;
		case 361: goto st361;
		case 362: goto st362;
		case 363: goto st363;
		case 364: goto st364;
		case 365: goto st365;
		case 366: goto st366;
		case 921: goto st921;
		case 367: goto st367;
		case 368: goto st368;
		case 369: goto st369;
		case 370: goto st370;
		case 371: goto st371;
		case 372: goto st372;
		case 373: goto st373;
		case 374: goto st374;
		case 375: goto st375;
		case 376: goto st376;
		case 377: goto st377;
		case 922: goto st922;
		case 378: goto st378;
		case 379: goto st379;
		case 923: goto st923;
		case 380: goto st380;
		case 381: goto st381;
		case 382: goto st382;
		case 383: goto st383;
		case 384: goto st384;
		case 385: goto st385;
		case 386: goto st386;
		case 387: goto st387;
		case 388: goto st388;
		case 389: goto st389;
		case 390: goto st390;
		case 391: goto st391;
		case 392: goto st392;
		case 924: goto st924;
		case 393: goto st393;
		case 394: goto st394;
		case 395: goto st395;
		case 396: goto st396;
		case 397: goto st397;
		case 398: goto st398;
		case 399: goto st399;
		case 400: goto st400;
		case 925: goto st925;
		case 401: goto st401;
		case 402: goto st402;
		case 403: goto st403;
		case 404: goto st404;
		case 405: goto st405;
		case 406: goto st406;
		case 407: goto st407;
		case 408: goto st408;
		case 409: goto st409;
		case 410: goto st410;
		case 411: goto st411;
		case 412: goto st412;
		case 413: goto st413;
		case 414: goto st414;
		case 415: goto st415;
		case 416: goto st416;
		case 417: goto st417;
		case 418: goto st418;
		case 419: goto st419;
		case 420: goto st420;
		case 926: goto st926;
		case 421: goto st421;
		case 422: goto st422;
		case 927: goto st927;
		case 423: goto st423;
		case 424: goto st424;
		case 425: goto st425;
		case 426: goto st426;
		case 427: goto st427;
		case 428: goto st428;
		case 429: goto st429;
		case 928: goto st928;
		case 430: goto st430;
		case 431: goto st431;
		case 432: goto st432;
		case 433: goto st433;
		case 434: goto st434;
		case 435: goto st435;
		case 436: goto st436;
		case 437: goto st437;
		case 929: goto st929;
		case 438: goto st438;
		case 439: goto st439;
		case 440: goto st440;
		case 441: goto st441;
		case 442: goto st442;
		case 443: goto st443;
		case 444: goto st444;
		case 445: goto st445;
		case 446: goto st446;
		case 447: goto st447;
		case 448: goto st448;
		case 449: goto st449;
		case 450: goto st450;
		case 451: goto st451;
		case 452: goto st452;
		case 453: goto st453;
		case 454: goto st454;
		case 455: goto st455;
		case 456: goto st456;
		case 457: goto st457;
		case 458: goto st458;
		case 459: goto st459;
		case 460: goto st460;
		case 461: goto st461;
		case 462: goto st462;
		case 930: goto st930;
		case 463: goto st463;
		case 464: goto st464;
		case 931: goto st931;
		case 465: goto st465;
		case 466: goto st466;
		case 467: goto st467;
		case 468: goto st468;
		case 469: goto st469;
		case 470: goto st470;
		case 471: goto st471;
		case 932: goto st932;
		case 472: goto st472;
		case 473: goto st473;
		case 933: goto st933;
		case 474: goto st474;
		case 475: goto st475;
		case 934: goto st934;
		case 476: goto st476;
		case 477: goto st477;
		case 478: goto st478;
		case 479: goto st479;
		case 480: goto st480;
		case 481: goto st481;
		case 482: goto st482;
		case 483: goto st483;
		case 484: goto st484;
		case 485: goto st485;
		case 486: goto st486;
		case 487: goto st487;
		case 488: goto st488;
		case 489: goto st489;
		case 490: goto st490;
		case 491: goto st491;
		case 492: goto st492;
		case 493: goto st493;
		case 935: goto st935;
		case 494: goto st494;
		case 495: goto st495;
		case 496: goto st496;
		case 497: goto st497;
		case 498: goto st498;
		case 499: goto st499;
		case 500: goto st500;
		case 501: goto st501;
		case 502: goto st502;
		case 503: goto st503;
		case 504: goto st504;
		case 505: goto st505;
		case 506: goto st506;
		case 507: goto st507;
		case 936: goto st936;
		case 508: goto st508;
		case 509: goto st509;
		case 937: goto st937;
		case 510: goto st510;
		case 511: goto st511;
		case 512: goto st512;
		case 513: goto st513;
		case 514: goto st514;
		case 938: goto st938;
		case 515: goto st515;
		case 516: goto st516;
		case 517: goto st517;
		case 518: goto st518;
		case 519: goto st519;
		case 520: goto st520;
		case 521: goto st521;
		case 522: goto st522;
		case 523: goto st523;
		case 524: goto st524;
		case 525: goto st525;
		case 526: goto st526;
		case 527: goto st527;
		case 528: goto st528;
		case 529: goto st529;
		case 530: goto st530;
		case 531: goto st531;
		case 532: goto st532;
		case 533: goto st533;
		case 534: goto st534;
		case 535: goto st535;
		case 536: goto st536;
		case 537: goto st537;
		case 538: goto st538;
		case 539: goto st539;
		case 540: goto st540;
		case 541: goto st541;
		case 542: goto st542;
		case 543: goto st543;
		case 544: goto st544;
		case 545: goto st545;
		case 546: goto st546;
		case 547: goto st547;
		case 548: goto st548;
		case 549: goto st549;
		case 550: goto st550;
		case 551: goto st551;
		case 552: goto st552;
		case 553: goto st553;
		case 554: goto st554;
		case 555: goto st555;
		case 556: goto st556;
		case 557: goto st557;
		case 558: goto st558;
		case 559: goto st559;
		case 560: goto st560;
		case 561: goto st561;
		case 562: goto st562;
		case 563: goto st563;
		case 564: goto st564;
		case 565: goto st565;
		case 566: goto st566;
		case 567: goto st567;
		case 568: goto st568;
		case 569: goto st569;
		case 570: goto st570;
		case 571: goto st571;
		case 572: goto st572;
		case 573: goto st573;
		case 574: goto st574;
		case 575: goto st575;
		case 576: goto st576;
		case 577: goto st577;
		case 578: goto st578;
		case 579: goto st579;
		case 580: goto st580;
		case 581: goto st581;
		case 582: goto st582;
		case 583: goto st583;
		case 939: goto st939;
		case 584: goto st584;
		case 585: goto st585;
		case 940: goto st940;
		case 586: goto st586;
		case 587: goto st587;
		case 588: goto st588;
		case 589: goto st589;
		case 590: goto st590;
		case 591: goto st591;
		case 941: goto st941;
		case 592: goto st592;
		case 593: goto st593;
		case 594: goto st594;
		case 595: goto st595;
		case 942: goto st942;
		case 596: goto st596;
		case 597: goto st597;
		case 943: goto st943;
		case 598: goto st598;
		case 599: goto st599;
		case 600: goto st600;
		case 601: goto st601;
		case 602: goto st602;
		case 603: goto st603;
		case 944: goto st944;
		case 604: goto st604;
		case 605: goto st605;
		case 945: goto st945;
		case 606: goto st606;
		case 607: goto st607;
		case 946: goto st946;
		case 608: goto st608;
		case 609: goto st609;
		case 610: goto st610;
		case 611: goto st611;
		case 612: goto st612;
		case 613: goto st613;
		case 614: goto st614;
		case 947: goto st947;
		case 615: goto st615;
		case 616: goto st616;
		case 948: goto st948;
		case 617: goto st617;
		case 618: goto st618;
		case 949: goto st949;
		case 619: goto st619;
		case 620: goto st620;
		case 621: goto st621;
		case 622: goto st622;
		case 623: goto st623;
		case 624: goto st624;
		case 625: goto st625;
		case 626: goto st626;
		case 627: goto st627;
		case 628: goto st628;
		case 629: goto st629;
		case 630: goto st630;
		case 631: goto st631;
		case 632: goto st632;
		case 633: goto st633;
		case 950: goto st950;
		case 634: goto st634;
		case 635: goto st635;
		case 951: goto st951;
		case 636: goto st636;
		case 637: goto st637;
		case 638: goto st638;
		case 639: goto st639;
		case 640: goto st640;
		case 641: goto st641;
		case 642: goto st642;
		case 643: goto st643;
		case 644: goto st644;
		case 645: goto st645;
		case 646: goto st646;
		case 647: goto st647;
		case 648: goto st648;
		case 649: goto st649;
		case 650: goto st650;
		case 651: goto st651;
		case 652: goto st652;
		case 653: goto st653;
		case 654: goto st654;
		case 952: goto st952;
		case 655: goto st655;
		case 656: goto st656;
		case 657: goto st657;
		case 658: goto st658;
		case 659: goto st659;
		case 660: goto st660;
		case 661: goto st661;
		case 662: goto st662;
		case 663: goto st663;
		case 664: goto st664;
		case 665: goto st665;
		case 666: goto st666;
		case 667: goto st667;
		case 668: goto st668;
		case 669: goto st669;
		case 953: goto st953;
		case 670: goto st670;
		case 671: goto st671;
		case 672: goto st672;
		case 673: goto st673;
		case 674: goto st674;
		case 675: goto st675;
		case 676: goto st676;
		case 677: goto st677;
		case 678: goto st678;
		case 679: goto st679;
		case 680: goto st680;
		case 681: goto st681;
		case 682: goto st682;
		case 683: goto st683;
		case 954: goto st954;
		case 684: goto st684;
		case 685: goto st685;
		case 686: goto st686;
		case 687: goto st687;
		case 688: goto st688;
		case 689: goto st689;
		case 690: goto st690;
		case 691: goto st691;
		case 692: goto st692;
		case 693: goto st693;
		case 694: goto st694;
		case 695: goto st695;
		case 696: goto st696;
		case 697: goto st697;
		case 698: goto st698;
		case 699: goto st699;
		case 955: goto st955;
		case 700: goto st700;
		case 701: goto st701;
		case 956: goto st956;
		case 702: goto st702;
		case 703: goto st703;
		case 704: goto st704;
		case 705: goto st705;
		case 706: goto st706;
		case 707: goto st707;
		case 957: goto st957;
		case 708: goto st708;
		case 709: goto st709;
		case 710: goto st710;
		case 711: goto st711;
		case 712: goto st712;
		case 713: goto st713;
		case 714: goto st714;
		case 715: goto st715;
		case 716: goto st716;
		case 717: goto st717;
		case 718: goto st718;
		case 719: goto st719;
		case 958: goto st958;
		case 720: goto st720;
		case 721: goto st721;
		case 959: goto st959;
		case 722: goto st722;
		case 723: goto st723;
		case 724: goto st724;
		case 725: goto st725;
		case 726: goto st726;
		case 727: goto st727;
		case 728: goto st728;
		case 960: goto st960;
		case 729: goto st729;
		case 730: goto st730;
		case 731: goto st731;
		case 732: goto st732;
		case 733: goto st733;
		case 734: goto st734;
		case 961: goto st961;
		case 735: goto st735;
		case 736: goto st736;
		case 962: goto st962;
		case 737: goto st737;
		case 738: goto st738;
		case 739: goto st739;
		case 740: goto st740;
		case 741: goto st741;
		case 742: goto st742;
		case 743: goto st743;
		case 744: goto st744;
		case 745: goto st745;
		case 746: goto st746;
		case 747: goto st747;
		case 748: goto st748;
		case 963: goto st963;
		case 749: goto st749;
		case 750: goto st750;
		case 964: goto st964;
		case 751: goto st751;
		case 752: goto st752;
		case 753: goto st753;
		case 754: goto st754;
		case 755: goto st755;
		case 756: goto st756;
		case 757: goto st757;
		case 965: goto st965;
		case 758: goto st758;
		case 759: goto st759;
		case 760: goto st760;
		case 761: goto st761;
		case 762: goto st762;
		case 763: goto st763;
		case 764: goto st764;
		case 765: goto st765;
		case 766: goto st766;
		case 767: goto st767;
		case 768: goto st768;
		case 769: goto st769;
		case 966: goto st966;
		case 770: goto st770;
		case 771: goto st771;
		case 967: goto st967;
		case 772: goto st772;
		case 773: goto st773;
		case 774: goto st774;
		case 775: goto st775;
		case 776: goto st776;
		case 777: goto st777;
		case 778: goto st778;
		case 779: goto st779;
		case 968: goto st968;
		case 780: goto st780;
		case 781: goto st781;
		case 782: goto st782;
		case 783: goto st783;
		case 784: goto st784;
		case 785: goto st785;
		case 786: goto st786;
		case 787: goto st787;
		case 969: goto st969;
		case 788: goto st788;
		case 789: goto st789;
		case 790: goto st790;
		case 791: goto st791;
		case 792: goto st792;
		case 793: goto st793;
		case 794: goto st794;
		case 795: goto st795;
		case 796: goto st796;
		case 797: goto st797;
		case 798: goto st798;
		case 799: goto st799;
		case 800: goto st800;
		case 801: goto st801;
		case 802: goto st802;
		case 803: goto st803;
		case 804: goto st804;
		case 805: goto st805;
		case 806: goto st806;
		case 807: goto st807;
		case 970: goto st970;
		case 808: goto st808;
		case 809: goto st809;
		case 971: goto st971;
		case 810: goto st810;
		case 811: goto st811;
		case 812: goto st812;
		case 813: goto st813;
		case 814: goto st814;
		case 972: goto st972;
		case 815: goto st815;
		case 816: goto st816;
		case 817: goto st817;
		case 818: goto st818;
		case 819: goto st819;
		case 820: goto st820;
		case 821: goto st821;
		case 822: goto st822;
		case 823: goto st823;
		case 824: goto st824;
		case 825: goto st825;
		case 826: goto st826;
		case 827: goto st827;
		case 828: goto st828;
		case 829: goto st829;
		case 830: goto st830;
		case 831: goto st831;
		case 832: goto st832;
		case 833: goto st833;
		case 834: goto st834;
		case 835: goto st835;
		case 836: goto st836;
		case 837: goto st837;
		case 838: goto st838;
		case 839: goto st839;
		case 840: goto st840;
		case 841: goto st841;
		case 842: goto st842;
		case 843: goto st843;
		case 844: goto st844;
		case 845: goto st845;
		case 846: goto st846;
		case 847: goto st847;
		case 848: goto st848;
		case 849: goto st849;
		case 850: goto st850;
		case 851: goto st851;
		case 852: goto st852;
		case 853: goto st853;
		case 854: goto st854;
		case 855: goto st855;
		case 856: goto st856;
		case 857: goto st857;
		case 858: goto st858;
		case 859: goto st859;
		case 860: goto st860;
		case 861: goto st861;
		case 862: goto st862;
		case 863: goto st863;
		case 864: goto st864;
		case 865: goto st865;
		case 866: goto st866;
		case 867: goto st867;
		case 868: goto st868;
		case 869: goto st869;
		case 870: goto st870;
		case 871: goto st871;
		case 872: goto st872;
		case 873: goto st873;
		case 874: goto st874;
		case 875: goto st875;
		case 876: goto st876;
		case 877: goto st877;
		case 878: goto st878;
	default: break;
	}

	if ( ++p == pe )
		goto _test_eof;
_resume:
	switch ( cs )
	{
tr0:
#line 141 "confscanner.rl"
	{line++;}
	goto st879;
tr2:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 879; goto st22;} }
	goto st879;
tr4:
#line 276 "confscanner.rl"
	{ line++; /*cerr<<"-> rules\n";*/ {goto st886;} }
	goto st879;
st879:
	if ( ++p == pe )
		goto _test_eof879;
case 879:
#line 1195 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st879;
		case 10: goto tr0;
		case 13: goto st1;
		case 32: goto st879;
		case 35: goto st2;
	}
	if ( 65 <= (*p) && (*p) <= 90 )
		goto tr1759;
	goto st0;
st0:
cs = 0;
	goto _out;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
	if ( (*p) == 10 )
		goto tr0;
	goto st0;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	if ( (*p) == 35 )
		goto st3;
	goto tr2;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
	switch( (*p) ) {
		case 9: goto st3;
		case 10: goto tr4;
		case 13: goto st4;
		case 32: goto st3;
	}
	goto st0;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
	if ( (*p) == 10 )
		goto tr4;
	goto st0;
tr1759:
#line 20 "confscanner.rl"
	{ /*cerr << "st_tok" << line << "\n";*/ tmp_p = p; }
	goto st5;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
#line 1249 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto tr6;
		case 10: goto tr7;
		case 13: goto tr8;
		case 32: goto tr6;
		case 35: goto tr9;
		case 58: goto tr10;
	}
	if ( 65 <= (*p) && (*p) <= 90 )
		goto st5;
	goto st0;
tr13:
#line 141 "confscanner.rl"
	{line++;}
	goto st6;
tr17:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 6; goto st22;} }
	goto st6;
tr6:
#line 22 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
  }
	goto st6;
tr7:
#line 22 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st6;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
#line 1287 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st6;
		case 10: goto tr13;
		case 13: goto st7;
		case 32: goto st6;
		case 35: goto st8;
		case 58: goto st9;
	}
	goto st0;
tr8:
#line 22 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
  }
	goto st7;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
#line 1307 "confscanner.cc"
	if ( (*p) == 10 )
		goto tr13;
	goto st0;
tr9:
#line 22 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
  }
	goto st8;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
#line 1321 "confscanner.cc"
	if ( (*p) == 35 )
		goto st0;
	goto tr17;
tr10:
#line 22 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
  }
	goto st9;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
#line 1335 "confscanner.cc"
	if ( (*p) == 61 )
		goto st10;
	goto st0;
tr20:
#line 141 "confscanner.rl"
	{line++;}
	goto st10;
tr49:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 10; goto st22;} }
	goto st10;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
#line 1351 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st10;
		case 10: goto tr20;
		case 13: goto tr21;
		case 32: goto st10;
		case 35: goto tr22;
		case 59: goto st0;
		case 123: goto st0;
	}
	goto tr19;
tr19:
#line 20 "confscanner.rl"
	{ /*cerr << "st_tok" << line << "\n";*/ tmp_p = p; }
#line 270 "confscanner.rl"
	{/*TODO*/}
	goto st11;
tr38:
#line 270 "confscanner.rl"
	{/*TODO*/}
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 11; goto st22;} }
#line 271 "confscanner.rl"
	{/*TODO*/}
#line 20 "confscanner.rl"
	{ /*cerr << "st_tok" << line << "\n";*/ tmp_p = p; }
	goto st11;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
#line 1383 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st13;
		case 10: goto tr25;
		case 32: goto st13;
		case 35: goto tr26;
		case 59: goto st879;
		case 123: goto st0;
	}
	goto tr23;
tr23:
#line 270 "confscanner.rl"
	{/*TODO*/}
#line 20 "confscanner.rl"
	{ /*cerr << "st_tok" << line << "\n";*/ tmp_p = p; }
#line 271 "confscanner.rl"
	{/*TODO*/}
	goto st12;
tr28:
#line 270 "confscanner.rl"
	{/*TODO*/}
#line 271 "confscanner.rl"
	{/*TODO*/}
#line 20 "confscanner.rl"
	{ /*cerr << "st_tok" << line << "\n";*/ tmp_p = p; }
	goto st12;
tr40:
#line 20 "confscanner.rl"
	{ /*cerr << "st_tok" << line << "\n";*/ tmp_p = p; }
#line 270 "confscanner.rl"
	{/*TODO*/}
#line 271 "confscanner.rl"
	{/*TODO*/}
	goto st12;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
#line 1422 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st13;
		case 10: goto tr25;
		case 32: goto st13;
		case 35: goto tr29;
		case 59: goto st879;
		case 123: goto st0;
	}
	goto tr28;
tr25:
#line 141 "confscanner.rl"
	{line++;}
	goto st13;
tr35:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 13; goto st22;} }
	goto st13;
tr34:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 13; goto st22;} }
#line 271 "confscanner.rl"
	{/*TODO*/}
#line 20 "confscanner.rl"
	{ /*cerr << "st_tok" << line << "\n";*/ tmp_p = p; }
	goto st13;
tr36:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 13; goto st22;} }
#line 141 "confscanner.rl"
	{line++;}
	goto st13;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
#line 1459 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st13;
		case 10: goto tr25;
		case 32: goto st13;
		case 35: goto tr31;
		case 59: goto st879;
		case 123: goto st0;
	}
	goto tr30;
tr30:
#line 20 "confscanner.rl"
	{ /*cerr << "st_tok" << line << "\n";*/ tmp_p = p; }
#line 271 "confscanner.rl"
	{/*TODO*/}
	goto st14;
tr32:
#line 271 "confscanner.rl"
	{/*TODO*/}
#line 20 "confscanner.rl"
	{ /*cerr << "st_tok" << line << "\n";*/ tmp_p = p; }
	goto st14;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
#line 1486 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st13;
		case 10: goto tr25;
		case 32: goto st13;
		case 35: goto tr33;
		case 59: goto st879;
		case 123: goto st0;
	}
	goto tr32;
tr31:
#line 20 "confscanner.rl"
	{ /*cerr << "st_tok" << line << "\n";*/ tmp_p = p; }
#line 271 "confscanner.rl"
	{/*TODO*/}
	goto st15;
tr33:
#line 271 "confscanner.rl"
	{/*TODO*/}
#line 20 "confscanner.rl"
	{ /*cerr << "st_tok" << line << "\n";*/ tmp_p = p; }
	goto st15;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
#line 1513 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr35;
		case 9: goto tr35;
		case 10: goto tr36;
		case 32: goto tr35;
		case 35: goto tr33;
		case 59: goto tr37;
		case 123: goto tr35;
	}
	goto tr34;
tr37:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 880; goto st22;} }
	goto st880;
st880:
	if ( ++p == pe )
		goto _test_eof880;
case 880:
#line 1532 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st13;
		case 10: goto tr25;
		case 32: goto st13;
		case 35: goto tr31;
		case 59: goto st879;
		case 123: goto st0;
	}
	goto tr30;
tr26:
#line 270 "confscanner.rl"
	{/*TODO*/}
#line 20 "confscanner.rl"
	{ /*cerr << "st_tok" << line << "\n";*/ tmp_p = p; }
#line 271 "confscanner.rl"
	{/*TODO*/}
	goto st16;
tr29:
#line 270 "confscanner.rl"
	{/*TODO*/}
#line 271 "confscanner.rl"
	{/*TODO*/}
#line 20 "confscanner.rl"
	{ /*cerr << "st_tok" << line << "\n";*/ tmp_p = p; }
	goto st16;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
#line 1563 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr35;
		case 9: goto tr35;
		case 10: goto tr36;
		case 32: goto tr35;
		case 35: goto tr29;
		case 59: goto tr37;
		case 123: goto tr35;
	}
	goto tr38;
tr21:
#line 20 "confscanner.rl"
	{ /*cerr << "st_tok" << line << "\n";*/ tmp_p = p; }
#line 270 "confscanner.rl"
	{/*TODO*/}
	goto st17;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
#line 1584 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st13;
		case 10: goto tr39;
		case 32: goto st13;
		case 35: goto tr26;
		case 59: goto st879;
		case 123: goto st0;
	}
	goto tr23;
tr39:
#line 141 "confscanner.rl"
	{line++;}
	goto st18;
tr45:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 18; goto st22;} }
	goto st18;
tr46:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 18; goto st22;} }
#line 141 "confscanner.rl"
	{line++;}
	goto st18;
tr44:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 18; goto st22;} }
#line 270 "confscanner.rl"
	{/*TODO*/}
#line 271 "confscanner.rl"
	{/*TODO*/}
#line 20 "confscanner.rl"
	{ /*cerr << "st_tok" << line << "\n";*/ tmp_p = p; }
	goto st18;
tr48:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 18; goto st22;} }
#line 270 "confscanner.rl"
	{/*TODO*/}
#line 20 "confscanner.rl"
	{ /*cerr << "st_tok" << line << "\n";*/ tmp_p = p; }
#line 271 "confscanner.rl"
	{/*TODO*/}
	goto st18;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
#line 1633 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st18;
		case 10: goto tr39;
		case 13: goto tr42;
		case 32: goto st18;
		case 35: goto tr43;
		case 59: goto st879;
		case 123: goto st0;
	}
	goto tr40;
tr42:
#line 20 "confscanner.rl"
	{ /*cerr << "st_tok" << line << "\n";*/ tmp_p = p; }
#line 270 "confscanner.rl"
	{/*TODO*/}
#line 271 "confscanner.rl"
	{/*TODO*/}
	goto st19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
#line 1657 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st13;
		case 10: goto tr39;
		case 32: goto st13;
		case 35: goto tr29;
		case 59: goto st879;
		case 123: goto st0;
	}
	goto tr28;
tr43:
#line 20 "confscanner.rl"
	{ /*cerr << "st_tok" << line << "\n";*/ tmp_p = p; }
#line 270 "confscanner.rl"
	{/*TODO*/}
#line 271 "confscanner.rl"
	{/*TODO*/}
	goto st20;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
#line 1680 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr45;
		case 9: goto tr45;
		case 10: goto tr46;
		case 32: goto tr45;
		case 35: goto tr29;
		case 59: goto tr47;
		case 123: goto tr45;
	}
	goto tr44;
tr47:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 881; goto st22;} }
	goto st881;
st881:
	if ( ++p == pe )
		goto _test_eof881;
case 881:
#line 1699 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st18;
		case 10: goto tr39;
		case 13: goto tr42;
		case 32: goto st18;
		case 35: goto tr43;
		case 59: goto st879;
		case 123: goto st0;
	}
	goto tr40;
tr22:
#line 20 "confscanner.rl"
	{ /*cerr << "st_tok" << line << "\n";*/ tmp_p = p; }
#line 270 "confscanner.rl"
	{/*TODO*/}
	goto st21;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
#line 1721 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr49;
		case 9: goto tr45;
		case 10: goto tr46;
		case 32: goto tr45;
		case 35: goto tr26;
		case 59: goto tr50;
		case 123: goto tr49;
	}
	goto tr48;
tr50:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 882; goto st22;} }
	goto st882;
st882:
	if ( ++p == pe )
		goto _test_eof882;
case 882:
#line 1740 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st10;
		case 10: goto tr20;
		case 13: goto tr21;
		case 32: goto st10;
		case 35: goto tr22;
		case 59: goto st0;
		case 123: goto st0;
	}
	goto tr19;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr52;
	}
	goto st22;
tr52:
#line 133 "confscanner.rl"
	{line++;{cs = stack[--top];goto _again;}}
	goto st883;
st883:
	if ( ++p == pe )
		goto _test_eof883;
case 883:
#line 1769 "confscanner.cc"
	goto st0;
tr53:
#line 158 "confscanner.rl"
	{ p--; opt=false; }
	goto st884;
tr55:
#line 73 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      string :: size_type found = tmp_string.find_first_not_of(" \t");
      if(found == string::npos || string(tmp_string.substr(found)) != "\"\"")
      {
        found = tmp_string.rfind("\"");
        if(found != string::npos && string(tmp_string.substr(found-1)) == "\"\"")
        {
          //cerr << "a1: " << tmp_string.substr(0, found-1) + '\n';
          (*cblock_).push_back(tmp_string.substr(0, found-1) + '\n');
          //cerr << "after a1: " << param_list_["detailed_data"][0];
        }
        else
        {
          //cerr << "a2: " << tmp_string + '\n';
          (*cblock_).push_back(tmp_string + '\n');
        }
      }
      opt = true;
    }
  }
#line 156 "confscanner.rl"
	{{cs = stack[--top];goto _again;}}
	goto st884;
tr1761:
#line 73 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      string :: size_type found = tmp_string.find_first_not_of(" \t");
      if(found == string::npos || string(tmp_string.substr(found)) != "\"\"")
      {
        found = tmp_string.rfind("\"");
        if(found != string::npos && string(tmp_string.substr(found-1)) == "\"\"")
        {
          //cerr << "a1: " << tmp_string.substr(0, found-1) + '\n';
          (*cblock_).push_back(tmp_string.substr(0, found-1) + '\n');
          //cerr << "after a1: " << param_list_["detailed_data"][0];
        }
        else
        {
          //cerr << "a2: " << tmp_string + '\n';
          (*cblock_).push_back(tmp_string + '\n');
        }
      }
      opt = true;
    }
  }
#line 154 "confscanner.rl"
	{line++;}
	goto st884;
st884:
	if ( ++p == pe )
		goto _test_eof884;
case 884:
#line 1835 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1761;
		case 34: goto st23;
	}
	goto tr1760;
tr1760:
#line 152 "confscanner.rl"
	{ if(opt) { tmp_p = p; } }
	goto st885;
st885:
	if ( ++p == pe )
		goto _test_eof885;
case 885:
#line 1850 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1761;
		case 34: goto st23;
	}
	goto st885;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto st0;
		case 34: goto st24;
	}
	goto tr53;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto st0;
		case 34: goto tr55;
	}
	goto tr53;
tr56:
#line 141 "confscanner.rl"
	{line++;}
	goto st886;
tr57:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 886; goto st22;} }
	goto st886;
tr89:
#line 148 "confscanner.rl"
	{arg_to_be_added_ = false;}
	goto st886;
tr240:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 886; goto st886;} }
	goto st886;
tr246:
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 886; goto st886;} }
	goto st886;
tr736:
#line 27 "confscanner.rl"
	{
//    cerr << "in group add: " << endl;
    if(match_at_level_[level_])
    {
//      cerr << "do it" << endl;
      tmp_string.assign(tmp_p, p-tmp_p);
      // clear groupset_ first, if we did not use '+='
      if(!arg_to_be_added_)
        groupset_.clear();

      groupset_.insert(tmp_string);
    }
  }
#line 148 "confscanner.rl"
	{arg_to_be_added_ = false;}
	goto st886;
tr1769:
#line 260 "confscanner.rl"
	{ go_level_down(); {cs = stack[--top];goto _again;} }
	goto st886;
st886:
	if ( ++p == pe )
		goto _test_eof886;
case 886:
#line 1930 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st886;
		case 10: goto tr56;
		case 13: goto st25;
		case 32: goto st886;
		case 35: goto st26;
		case 97: goto st27;
		case 103: goto st127;
		case 125: goto tr1769;
	}
	goto st0;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
	if ( (*p) == 10 )
		goto tr56;
	goto st0;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
	if ( (*p) == 35 )
		goto st0;
	goto tr57;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
	if ( (*p) == 100 )
		goto st28;
	goto st0;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
	if ( (*p) == 100 )
		goto st29;
	goto st0;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
	if ( (*p) == 40 )
		goto st30;
	goto st0;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
	switch( (*p) ) {
		case 98: goto tr61;
		case 100: goto tr62;
		case 101: goto tr63;
		case 102: goto tr64;
		case 112: goto tr65;
		case 114: goto tr66;
	}
	goto st0;
tr61:
#line 237 "confscanner.rl"
	{/*cerr << "add:" << '\n';*/ tmp_p = p;}
	goto st31;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
#line 1998 "confscanner.cc"
	if ( (*p) == 114 )
		goto st32;
	goto st0;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
	if ( (*p) == 105 )
		goto st33;
	goto st0;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
	if ( (*p) == 101 )
		goto st34;
	goto st0;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
	if ( (*p) == 102 )
		goto st35;
	goto st0;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
	if ( (*p) == 41 )
		goto tr71;
	goto st0;
tr73:
#line 141 "confscanner.rl"
	{line++;}
	goto st36;
tr78:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 36; goto st22;} }
	goto st36;
tr71:
#line 42 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    if(tmp_string == "brief")
      cblock_ = &docuheader_;
    else if(tmp_string == "doc")
      cblock_ = &docubody_;
    else if(tmp_string == "extra")
      cblock_ = &docuextra_;
  }
	goto st36;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
#line 2054 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st36;
		case 10: goto tr73;
		case 13: goto st37;
		case 32: goto st36;
		case 35: goto st38;
		case 43: goto tr76;
		case 61: goto st40;
	}
	goto st0;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
	if ( (*p) == 10 )
		goto tr73;
	goto st0;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
	if ( (*p) == 35 )
		goto st0;
	goto tr78;
tr76:
#line 146 "confscanner.rl"
	{arg_to_be_added_ = true;}
	goto st39;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
#line 2087 "confscanner.cc"
	if ( (*p) == 61 )
		goto st40;
	goto st0;
tr79:
#line 141 "confscanner.rl"
	{line++;}
	goto st40;
tr91:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 40; goto st22;} }
	goto st40;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
#line 2103 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st40;
		case 10: goto tr79;
		case 13: goto st41;
		case 32: goto st40;
		case 34: goto st42;
		case 35: goto st47;
	}
	goto st0;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
	if ( (*p) == 10 )
		goto tr79;
	goto st0;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
	if ( (*p) == 34 )
		goto st43;
	goto st0;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
	if ( (*p) == 34 )
		goto tr84;
	goto st0;
tr86:
#line 141 "confscanner.rl"
	{line++;}
	goto st44;
tr90:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 44; goto st22;} }
	goto st44;
tr84:
#line 162 "confscanner.rl"
	{
                opt=true;
                if(!arg_to_be_added_)
                  (*cblock_).clear();
                {stack[top++] = 44; goto st884;}
                }
	goto st44;
tr830:
#line 27 "confscanner.rl"
	{
//    cerr << "in group add: " << endl;
    if(match_at_level_[level_])
    {
//      cerr << "do it" << endl;
      tmp_string.assign(tmp_p, p-tmp_p);
      // clear groupset_ first, if we did not use '+='
      if(!arg_to_be_added_)
        groupset_.clear();

      groupset_.insert(tmp_string);
    }
  }
	goto st44;
tr831:
#line 27 "confscanner.rl"
	{
//    cerr << "in group add: " << endl;
    if(match_at_level_[level_])
    {
//      cerr << "do it" << endl;
      tmp_string.assign(tmp_p, p-tmp_p);
      // clear groupset_ first, if we did not use '+='
      if(!arg_to_be_added_)
        groupset_.clear();

      groupset_.insert(tmp_string);
    }
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st44;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
#line 2189 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st44;
		case 10: goto tr86;
		case 13: goto st45;
		case 32: goto st44;
		case 35: goto st46;
		case 59: goto tr89;
	}
	goto st0;
tr832:
#line 27 "confscanner.rl"
	{
//    cerr << "in group add: " << endl;
    if(match_at_level_[level_])
    {
//      cerr << "do it" << endl;
      tmp_string.assign(tmp_p, p-tmp_p);
      // clear groupset_ first, if we did not use '+='
      if(!arg_to_be_added_)
        groupset_.clear();

      groupset_.insert(tmp_string);
    }
  }
	goto st45;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
#line 2219 "confscanner.cc"
	if ( (*p) == 10 )
		goto tr86;
	goto st0;
tr833:
#line 27 "confscanner.rl"
	{
//    cerr << "in group add: " << endl;
    if(match_at_level_[level_])
    {
//      cerr << "do it" << endl;
      tmp_string.assign(tmp_p, p-tmp_p);
      // clear groupset_ first, if we did not use '+='
      if(!arg_to_be_added_)
        groupset_.clear();

      groupset_.insert(tmp_string);
    }
  }
	goto st46;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
#line 2243 "confscanner.cc"
	if ( (*p) == 35 )
		goto st0;
	goto tr90;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
	if ( (*p) == 35 )
		goto st0;
	goto tr91;
tr62:
#line 237 "confscanner.rl"
	{/*cerr << "add:" << '\n';*/ tmp_p = p;}
	goto st48;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
#line 2262 "confscanner.cc"
	if ( (*p) == 111 )
		goto st49;
	goto st0;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
	if ( (*p) == 99 )
		goto st35;
	goto st0;
tr63:
#line 237 "confscanner.rl"
	{/*cerr << "add:" << '\n';*/ tmp_p = p;}
	goto st50;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
#line 2281 "confscanner.cc"
	if ( (*p) == 120 )
		goto st51;
	goto st0;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
	if ( (*p) == 116 )
		goto st52;
	goto st0;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
	if ( (*p) == 114 )
		goto st53;
	goto st0;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
	if ( (*p) == 97 )
		goto st35;
	goto st0;
tr64:
#line 237 "confscanner.rl"
	{/*cerr << "add:" << '\n';*/ tmp_p = p;}
	goto st54;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
#line 2314 "confscanner.cc"
	if ( (*p) == 105 )
		goto st55;
	goto st0;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
	if ( (*p) == 101 )
		goto st56;
	goto st0;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
	if ( (*p) == 108 )
		goto st57;
	goto st0;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
	if ( (*p) == 100 )
		goto st58;
	goto st0;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
	if ( (*p) == 115 )
		goto st59;
	goto st0;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
	if ( (*p) == 41 )
		goto tr101;
	goto st0;
tr103:
#line 141 "confscanner.rl"
	{line++;}
	goto st60;
tr108:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 60; goto st22;} }
	goto st60;
tr101:
#line 66 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    if(tmp_string == "fields")
      clistmap_ = &field_docu_;
  }
	goto st60;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
#line 2373 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st60;
		case 10: goto tr103;
		case 13: goto st61;
		case 32: goto st60;
		case 35: goto st62;
		case 43: goto tr106;
		case 61: goto st64;
	}
	goto st0;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
	if ( (*p) == 10 )
		goto tr103;
	goto st0;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
	if ( (*p) == 35 )
		goto st0;
	goto tr108;
tr106:
#line 146 "confscanner.rl"
	{arg_to_be_added_ = true;}
	goto st63;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
#line 2406 "confscanner.cc"
	if ( (*p) == 61 )
		goto st64;
	goto st0;
tr109:
#line 141 "confscanner.rl"
	{line++;}
	goto st64;
tr114:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 64; goto st22;} }
	goto st64;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
#line 2422 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st64;
		case 10: goto tr109;
		case 13: goto st65;
		case 32: goto st64;
		case 35: goto st66;
		case 40: goto st67;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr113;
	} else if ( (*p) >= 65 )
		goto tr113;
	goto st0;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
	if ( (*p) == 10 )
		goto tr109;
	goto st0;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
	if ( (*p) == 35 )
		goto st0;
	goto tr114;
tr115:
#line 141 "confscanner.rl"
	{line++;}
	goto st67;
tr119:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 67; goto st22;} }
	goto st67;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
#line 2463 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st67;
		case 10: goto tr115;
		case 13: goto st68;
		case 32: goto st67;
		case 35: goto st69;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr118;
	} else if ( (*p) >= 65 )
		goto tr118;
	goto st0;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
	if ( (*p) == 10 )
		goto tr115;
	goto st0;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
	if ( (*p) == 35 )
		goto st0;
	goto tr119;
tr118:
#line 192 "confscanner.rl"
	{tmp_p = p;/* cerr << "dlmi\n";*/}
	goto st70;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
#line 2499 "confscanner.cc"
	switch( (*p) ) {
		case 46: goto tr120;
		case 95: goto st70;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st70;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st70;
	} else
		goto st70;
	goto st0;
tr120:
#line 22 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
  }
	goto st71;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
#line 2523 "confscanner.cc"
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr122;
	} else if ( (*p) >= 65 )
		goto tr122;
	goto st0;
tr122:
#line 196 "confscanner.rl"
	{tmp_p = p;/* cerr << "dlmi2\n";*/}
	goto st72;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
#line 2538 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto tr123;
		case 10: goto tr124;
		case 13: goto tr125;
		case 32: goto tr123;
		case 35: goto tr126;
		case 61: goto tr128;
		case 95: goto st72;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st72;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st72;
	} else
		goto st72;
	goto st0;
tr130:
#line 141 "confscanner.rl"
	{line++;}
	goto st73;
tr134:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 73; goto st22;} }
	goto st73;
tr123:
#line 108 "confscanner.rl"
	{
    string s(tmp_p, p-tmp_p);
    cblock_ = &((*clistmap_)[tmp_string][s]);
  }
	goto st73;
tr124:
#line 108 "confscanner.rl"
	{
    string s(tmp_p, p-tmp_p);
    cblock_ = &((*clistmap_)[tmp_string][s]);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st73;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
#line 2585 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st73;
		case 10: goto tr130;
		case 13: goto st74;
		case 32: goto st73;
		case 35: goto st75;
		case 61: goto st76;
	}
	goto st0;
tr125:
#line 108 "confscanner.rl"
	{
    string s(tmp_p, p-tmp_p);
    cblock_ = &((*clistmap_)[tmp_string][s]);
  }
	goto st74;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
#line 2606 "confscanner.cc"
	if ( (*p) == 10 )
		goto tr130;
	goto st0;
tr126:
#line 108 "confscanner.rl"
	{
    string s(tmp_p, p-tmp_p);
    cblock_ = &((*clistmap_)[tmp_string][s]);
  }
	goto st75;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
#line 2621 "confscanner.cc"
	if ( (*p) == 35 )
		goto st0;
	goto tr134;
tr128:
#line 108 "confscanner.rl"
	{
    string s(tmp_p, p-tmp_p);
    cblock_ = &((*clistmap_)[tmp_string][s]);
  }
	goto st76;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
#line 2636 "confscanner.cc"
	if ( (*p) == 62 )
		goto st77;
	goto st0;
tr136:
#line 141 "confscanner.rl"
	{line++;}
	goto st77;
tr147:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 77; goto st22;} }
	goto st77;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
#line 2652 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st77;
		case 10: goto tr136;
		case 13: goto st78;
		case 32: goto st77;
		case 34: goto st79;
		case 35: goto st84;
	}
	goto st0;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
	if ( (*p) == 10 )
		goto tr136;
	goto st0;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
	if ( (*p) == 34 )
		goto st80;
	goto st0;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
	if ( (*p) == 34 )
		goto tr141;
	goto st0;
tr143:
#line 141 "confscanner.rl"
	{line++;}
	goto st81;
tr146:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 81; goto st22;} }
	goto st81;
tr141:
#line 162 "confscanner.rl"
	{
                opt=true;
                if(!arg_to_be_added_)
                  (*cblock_).clear();
                {stack[top++] = 81; goto st884;}
                }
	goto st81;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
#line 2704 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st81;
		case 10: goto tr143;
		case 13: goto st82;
		case 32: goto st81;
		case 35: goto st83;
		case 41: goto st44;
		case 44: goto st67;
	}
	goto st0;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
	if ( (*p) == 10 )
		goto tr143;
	goto st0;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
	if ( (*p) == 35 )
		goto st0;
	goto tr146;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
	if ( (*p) == 35 )
		goto st0;
	goto tr147;
tr113:
#line 192 "confscanner.rl"
	{tmp_p = p;/* cerr << "dlmi\n";*/}
	goto st85;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
#line 2744 "confscanner.cc"
	switch( (*p) ) {
		case 46: goto tr148;
		case 95: goto st85;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st85;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st85;
	} else
		goto st85;
	goto st0;
tr148:
#line 22 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
  }
	goto st86;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
#line 2768 "confscanner.cc"
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr150;
	} else if ( (*p) >= 65 )
		goto tr150;
	goto st0;
tr150:
#line 196 "confscanner.rl"
	{tmp_p = p;/* cerr << "dlmi2\n";*/}
	goto st87;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
#line 2783 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto tr151;
		case 10: goto tr152;
		case 13: goto tr153;
		case 32: goto tr151;
		case 35: goto tr154;
		case 61: goto tr156;
		case 95: goto st87;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st87;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st87;
	} else
		goto st87;
	goto st0;
tr158:
#line 141 "confscanner.rl"
	{line++;}
	goto st88;
tr162:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 88; goto st22;} }
	goto st88;
tr151:
#line 108 "confscanner.rl"
	{
    string s(tmp_p, p-tmp_p);
    cblock_ = &((*clistmap_)[tmp_string][s]);
  }
	goto st88;
tr152:
#line 108 "confscanner.rl"
	{
    string s(tmp_p, p-tmp_p);
    cblock_ = &((*clistmap_)[tmp_string][s]);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st88;
tr212:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st88;
tr213:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st88;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
#line 2854 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st88;
		case 10: goto tr158;
		case 13: goto st89;
		case 32: goto st88;
		case 35: goto st90;
		case 61: goto st91;
	}
	goto st0;
tr153:
#line 108 "confscanner.rl"
	{
    string s(tmp_p, p-tmp_p);
    cblock_ = &((*clistmap_)[tmp_string][s]);
  }
	goto st89;
tr214:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st89;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
#line 2886 "confscanner.cc"
	if ( (*p) == 10 )
		goto tr158;
	goto st0;
tr154:
#line 108 "confscanner.rl"
	{
    string s(tmp_p, p-tmp_p);
    cblock_ = &((*clistmap_)[tmp_string][s]);
  }
	goto st90;
tr215:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st90;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
#line 2912 "confscanner.cc"
	if ( (*p) == 35 )
		goto st0;
	goto tr162;
tr156:
#line 108 "confscanner.rl"
	{
    string s(tmp_p, p-tmp_p);
    cblock_ = &((*clistmap_)[tmp_string][s]);
  }
	goto st91;
tr217:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st91;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
#line 2938 "confscanner.cc"
	if ( (*p) == 62 )
		goto st40;
	goto st0;
tr65:
#line 237 "confscanner.rl"
	{/*cerr << "add:" << '\n';*/ tmp_p = p;}
	goto st92;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
#line 2950 "confscanner.cc"
	if ( (*p) == 97 )
		goto st93;
	goto st0;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
	if ( (*p) == 114 )
		goto st94;
	goto st0;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
	if ( (*p) == 97 )
		goto st95;
	goto st0;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
	if ( (*p) == 109 )
		goto st96;
	goto st0;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
	if ( (*p) == 115 )
		goto st97;
	goto st0;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
	if ( (*p) == 41 )
		goto tr168;
	goto st0;
tr170:
#line 141 "confscanner.rl"
	{line++;}
	goto st98;
tr175:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 98; goto st22;} }
	goto st98;
tr168:
#line 53 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "docu_list: " << tmp_string << "\n";
    if(tmp_string == "params")
    {
      //cerr << "paramlist\n";
      clist_ = &param_list_;
    }
    else if(tmp_string == "return")
      clist_ = &return_list_;
  }
	goto st98;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
#line 3015 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st98;
		case 10: goto tr170;
		case 13: goto st99;
		case 32: goto st98;
		case 35: goto st100;
		case 43: goto tr173;
		case 61: goto st102;
	}
	goto st0;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
	if ( (*p) == 10 )
		goto tr170;
	goto st0;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
	if ( (*p) == 35 )
		goto st0;
	goto tr175;
tr173:
#line 146 "confscanner.rl"
	{arg_to_be_added_ = true;}
	goto st101;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
#line 3048 "confscanner.cc"
	if ( (*p) == 61 )
		goto st102;
	goto st0;
tr176:
#line 141 "confscanner.rl"
	{line++;}
	goto st102;
tr181:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 102; goto st22;} }
	goto st102;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
#line 3064 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st102;
		case 10: goto tr176;
		case 13: goto st103;
		case 32: goto st102;
		case 35: goto st104;
		case 40: goto st105;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr180;
	} else if ( (*p) >= 65 )
		goto tr180;
	goto st0;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
	if ( (*p) == 10 )
		goto tr176;
	goto st0;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
	if ( (*p) == 35 )
		goto st0;
	goto tr181;
tr182:
#line 141 "confscanner.rl"
	{line++;}
	goto st105;
tr186:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 105; goto st22;} }
	goto st105;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
#line 3105 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st105;
		case 10: goto tr182;
		case 13: goto st106;
		case 32: goto st105;
		case 35: goto st107;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr185;
	} else if ( (*p) >= 65 )
		goto tr185;
	goto st0;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
	if ( (*p) == 10 )
		goto tr182;
	goto st0;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
	if ( (*p) == 35 )
		goto st0;
	goto tr186;
tr185:
#line 173 "confscanner.rl"
	{tmp_p = p;}
	goto st108;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
#line 3141 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto tr187;
		case 10: goto tr188;
		case 13: goto tr189;
		case 32: goto tr187;
		case 35: goto tr190;
		case 61: goto tr192;
		case 95: goto st108;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st108;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st108;
	} else
		goto st108;
	goto st0;
tr194:
#line 141 "confscanner.rl"
	{line++;}
	goto st109;
tr198:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 109; goto st22;} }
	goto st109;
tr187:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st109;
tr188:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st109;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
#line 3196 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st109;
		case 10: goto tr194;
		case 13: goto st110;
		case 32: goto st109;
		case 35: goto st111;
		case 61: goto st112;
	}
	goto st0;
tr189:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st110;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
#line 3221 "confscanner.cc"
	if ( (*p) == 10 )
		goto tr194;
	goto st0;
tr190:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st111;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
#line 3240 "confscanner.cc"
	if ( (*p) == 35 )
		goto st0;
	goto tr198;
tr192:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st112;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
#line 3259 "confscanner.cc"
	if ( (*p) == 62 )
		goto st113;
	goto st0;
tr200:
#line 141 "confscanner.rl"
	{line++;}
	goto st113;
tr211:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 113; goto st22;} }
	goto st113;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
#line 3275 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st113;
		case 10: goto tr200;
		case 13: goto st114;
		case 32: goto st113;
		case 34: goto st115;
		case 35: goto st120;
	}
	goto st0;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
	if ( (*p) == 10 )
		goto tr200;
	goto st0;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
	if ( (*p) == 34 )
		goto st116;
	goto st0;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
	if ( (*p) == 34 )
		goto tr205;
	goto st0;
tr207:
#line 141 "confscanner.rl"
	{line++;}
	goto st117;
tr210:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 117; goto st22;} }
	goto st117;
tr205:
#line 162 "confscanner.rl"
	{
                opt=true;
                if(!arg_to_be_added_)
                  (*cblock_).clear();
                {stack[top++] = 117; goto st884;}
                }
	goto st117;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
#line 3327 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st117;
		case 10: goto tr207;
		case 13: goto st118;
		case 32: goto st117;
		case 35: goto st119;
		case 41: goto st44;
		case 44: goto st105;
	}
	goto st0;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
	if ( (*p) == 10 )
		goto tr207;
	goto st0;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
	if ( (*p) == 35 )
		goto st0;
	goto tr210;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
	if ( (*p) == 35 )
		goto st0;
	goto tr211;
tr180:
#line 173 "confscanner.rl"
	{tmp_p = p;}
	goto st121;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
#line 3367 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto tr212;
		case 10: goto tr213;
		case 13: goto tr214;
		case 32: goto tr212;
		case 35: goto tr215;
		case 61: goto tr217;
		case 95: goto st121;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st121;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st121;
	} else
		goto st121;
	goto st0;
tr66:
#line 237 "confscanner.rl"
	{/*cerr << "add:" << '\n';*/ tmp_p = p;}
	goto st122;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
#line 3394 "confscanner.cc"
	if ( (*p) == 101 )
		goto st123;
	goto st0;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
	if ( (*p) == 116 )
		goto st124;
	goto st0;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
	if ( (*p) == 117 )
		goto st125;
	goto st0;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
	if ( (*p) == 114 )
		goto st126;
	goto st0;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
	if ( (*p) == 110 )
		goto st97;
	goto st0;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
	switch( (*p) ) {
		case 108: goto st128;
		case 114: goto st875;
	}
	goto st0;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
	if ( (*p) == 111 )
		goto st129;
	goto st0;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	if ( (*p) == 98 )
		goto st130;
	goto st0;
tr226:
#line 141 "confscanner.rl"
	{line++;}
	goto st130;
tr230:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 130; goto st22;} }
	goto st130;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
#line 3461 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st130;
		case 10: goto tr226;
		case 13: goto st131;
		case 32: goto st130;
		case 35: goto st132;
		case 61: goto st133;
	}
	goto st0;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
	if ( (*p) == 10 )
		goto tr226;
	goto st0;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
	if ( (*p) == 35 )
		goto st0;
	goto tr230;
tr232:
#line 141 "confscanner.rl"
	{line++;}
	goto st133;
tr1403:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 133; goto st22;} }
	goto st133;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
#line 3497 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st133;
		case 10: goto tr232;
		case 13: goto tr233;
		case 32: goto st133;
		case 35: goto tr234;
		case 59: goto st0;
		case 123: goto st0;
	}
	goto tr231;
tr371:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 134; goto st22;} }
	goto st134;
tr231:
#line 213 "confscanner.rl"
	{/*cerr << "glob_list";*/ tmp_p = p;}
	goto st134;
tr238:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st134;
tr365:
#line 213 "confscanner.rl"
	{/*cerr << "glob_list";*/ tmp_p = p;}
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st134;
tr374:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 134; goto st22;} }
	goto st134;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
#line 3547 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
tr243:
#line 141 "confscanner.rl"
	{line++;}
	goto st135;
tr1749:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 135; goto st22;} }
	goto st135;
tr236:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st135;
tr1747:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st135;
tr256:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 135; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st135;
tr1750:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 135; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st135;
tr372:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 135; goto st22;} }
	goto st135;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
#line 3626 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st135;
		case 10: goto tr243;
		case 13: goto tr244;
		case 32: goto st135;
		case 35: goto tr245;
		case 59: goto st0;
		case 123: goto tr246;
	}
	goto tr241;
tr255:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 136; goto st22;} }
	goto st136;
tr241:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st136;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
#line 3650 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr250:
#line 141 "confscanner.rl"
	{line++;}
	goto st137;
tr253:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 137; goto st22;} }
	goto st137;
tr237:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st137;
tr254:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st137;
tr257:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 137; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st137;
tr373:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 137; goto st22;} }
#line 141 "confscanner.rl"
	{line++;}
	goto st137;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
#line 3722 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st135;
		case 10: goto tr250;
		case 13: goto st138;
		case 32: goto st135;
		case 35: goto st139;
		case 123: goto tr246;
	}
	goto st0;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
	if ( (*p) == 10 )
		goto tr250;
	goto st0;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
	if ( (*p) == 35 )
		goto st0;
	goto tr253;
tr248:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st140;
tr258:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 140; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st140;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
#line 3770 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr254;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr249:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st141;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
#line 3795 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr253;
		case 9: goto tr256;
		case 10: goto tr257;
		case 13: goto tr258;
		case 32: goto tr256;
		case 35: goto tr249;
		case 59: goto tr253;
		case 123: goto tr259;
	}
	goto tr255;
tr1746:
#line 141 "confscanner.rl"
	{line++;}
	goto st887;
tr425:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 887; goto st22;} }
	goto st887;
tr1354:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st887;
tr423:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st887;
tr426:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 887; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st887;
tr259:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 887; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 887; goto st886;} }
	goto st887;
tr1357:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 887; goto st22;} }
#line 141 "confscanner.rl"
	{line++;}
	goto st887;
tr375:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 887; goto st22;} }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 887; goto st886;} }
	goto st887;
st887:
	if ( ++p == pe )
		goto _test_eof887;
case 887:
#line 3893 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st888;
		case 10: goto tr1746;
		case 13: goto st870;
		case 32: goto st888;
		case 35: goto st871;
		case 97: goto st27;
		case 103: goto st127;
		case 123: goto tr246;
		case 125: goto tr1769;
	}
	goto st0;
tr1773:
#line 141 "confscanner.rl"
	{line++;}
	goto st888;
tr262:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 888; goto st22;} }
	goto st888;
tr1779:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st888;
tr260:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st888;
tr263:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 888; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st888;
tr264:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 888; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st888;
tr266:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 888; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 888; goto st886;} }
	goto st888;
tr1356:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 888; goto st22;} }
	goto st888;
st888:
	if ( ++p == pe )
		goto _test_eof888;
case 888:
#line 3986 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st888;
		case 10: goto tr1773;
		case 13: goto tr1774;
		case 32: goto st888;
		case 35: goto tr1775;
		case 59: goto st0;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr246;
		case 125: goto tr1778;
	}
	goto tr241;
tr1774:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st142;
tr1780:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st142;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
#line 4020 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr260;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1775:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st143;
tr1781:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st143;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
#line 4051 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr262;
		case 9: goto tr263;
		case 10: goto tr264;
		case 13: goto tr265;
		case 32: goto tr263;
		case 35: goto tr249;
		case 59: goto tr262;
		case 123: goto tr266;
	}
	goto tr261;
tr261:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 889; goto st22;} }
	goto st889;
tr265:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 889; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st889;
st889:
	if ( ++p == pe )
		goto _test_eof889;
case 889:
#line 4082 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1779;
		case 10: goto tr260;
		case 13: goto tr1780;
		case 32: goto tr1779;
		case 35: goto tr1781;
		case 59: goto st0;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr240;
		case 125: goto tr1778;
	}
	goto tr241;
tr1776:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st144;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
#line 4105 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 100: goto st145;
		case 123: goto tr240;
	}
	goto st136;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 100: goto st146;
		case 123: goto tr240;
	}
	goto st136;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 40: goto st147;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 98: goto tr270;
		case 100: goto tr271;
		case 101: goto tr272;
		case 102: goto tr273;
		case 112: goto tr274;
		case 114: goto tr275;
		case 123: goto tr240;
	}
	goto st136;
tr270:
#line 237 "confscanner.rl"
	{/*cerr << "add:" << '\n';*/ tmp_p = p;}
	goto st148;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
#line 4179 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 114: goto st149;
		case 123: goto tr240;
	}
	goto st136;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 105: goto st150;
		case 123: goto tr240;
	}
	goto st136;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 101: goto st151;
		case 123: goto tr240;
	}
	goto st136;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 102: goto st152;
		case 123: goto tr240;
	}
	goto st136;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 41: goto tr280;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1706:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 153; goto st22;} }
	goto st153;
tr280:
#line 42 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    if(tmp_string == "brief")
      cblock_ = &docuheader_;
    else if(tmp_string == "doc")
      cblock_ = &docubody_;
    else if(tmp_string == "extra")
      cblock_ = &docuextra_;
  }
	goto st153;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
#line 4276 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr281;
		case 10: goto tr282;
		case 13: goto tr283;
		case 32: goto tr281;
		case 35: goto tr284;
		case 43: goto tr285;
		case 59: goto st0;
		case 61: goto st159;
		case 123: goto tr240;
	}
	goto st136;
tr288:
#line 141 "confscanner.rl"
	{line++;}
	goto st154;
tr295:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 154; goto st22;} }
	goto st154;
tr281:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st154;
tr293:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st154;
tr296:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 154; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st154;
tr297:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 154; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st154;
tr413:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 154; goto st22;} }
	goto st154;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
#line 4357 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st154;
		case 10: goto tr288;
		case 13: goto tr289;
		case 32: goto st154;
		case 35: goto tr290;
		case 43: goto tr291;
		case 59: goto st0;
		case 61: goto tr292;
		case 123: goto tr246;
	}
	goto tr241;
tr289:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st155;
tr300:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st155;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
#line 4390 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr293;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr290:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st156;
tr301:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st156;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
#line 4421 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr295;
		case 9: goto tr296;
		case 10: goto tr297;
		case 13: goto tr298;
		case 32: goto tr296;
		case 35: goto tr249;
		case 59: goto tr295;
		case 123: goto tr299;
	}
	goto tr294;
tr294:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 157; goto st22;} }
	goto st157;
tr298:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 157; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st157;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
#line 4452 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr281;
		case 10: goto tr293;
		case 13: goto tr300;
		case 32: goto tr281;
		case 35: goto tr301;
		case 43: goto tr291;
		case 59: goto st0;
		case 61: goto tr292;
		case 123: goto tr240;
	}
	goto tr241;
tr285:
#line 146 "confscanner.rl"
	{arg_to_be_added_ = true;}
	goto st158;
tr291:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 146 "confscanner.rl"
	{arg_to_be_added_ = true;}
	goto st158;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
#line 4480 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 61: goto st159;
		case 123: goto tr240;
	}
	goto st136;
tr1701:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 159; goto st22;} }
	goto st159;
tr292:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st159;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
#line 4505 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr302;
		case 10: goto tr303;
		case 13: goto tr304;
		case 32: goto tr302;
		case 34: goto st162;
		case 35: goto tr306;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr308:
#line 141 "confscanner.rl"
	{line++;}
	goto st160;
tr1694:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 160; goto st22;} }
	goto st160;
tr302:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st160;
tr312:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st160;
tr1695:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 160; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st160;
tr1696:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 160; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st160;
tr453:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 160; goto st22;} }
	goto st160;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
#line 4585 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st160;
		case 10: goto tr308;
		case 13: goto tr309;
		case 32: goto st160;
		case 34: goto tr310;
		case 35: goto tr311;
		case 59: goto st0;
		case 123: goto tr246;
	}
	goto tr241;
tr309:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st161;
tr1698:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st161;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
#line 4617 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr312;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr310:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st162;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
#line 4637 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 34: goto st163;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 34: goto tr314;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr738:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 164; goto st22;} }
	goto st164;
tr314:
#line 162 "confscanner.rl"
	{
                opt=true;
                if(!arg_to_be_added_)
                  (*cblock_).clear();
                {stack[top++] = 164; goto st884;}
                }
	goto st164;
tr585:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st164;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
#line 4687 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr315;
		case 10: goto tr316;
		case 13: goto tr317;
		case 32: goto tr315;
		case 35: goto tr318;
		case 59: goto tr89;
		case 123: goto tr240;
	}
	goto st136;
tr320:
#line 141 "confscanner.rl"
	{line++;}
	goto st165;
tr325:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 165; goto st22;} }
	goto st165;
tr315:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st165;
tr323:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st165;
tr326:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 165; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st165;
tr327:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 165; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st165;
tr446:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 165; goto st22;} }
	goto st165;
tr730:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 27 "confscanner.rl"
	{
//    cerr << "in group add: " << endl;
    if(match_at_level_[level_])
    {
//      cerr << "do it" << endl;
      tmp_string.assign(tmp_p, p-tmp_p);
      // clear groupset_ first, if we did not use '+='
      if(!arg_to_be_added_)
        groupset_.clear();

      groupset_.insert(tmp_string);
    }
  }
	goto st165;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
#line 4789 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st165;
		case 10: goto tr320;
		case 13: goto tr321;
		case 32: goto st165;
		case 35: goto tr322;
		case 59: goto tr89;
		case 123: goto tr246;
	}
	goto tr241;
tr321:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st166;
tr330:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st166;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
#line 4820 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr323;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr322:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st167;
tr331:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st167;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
#line 4851 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr325;
		case 9: goto tr326;
		case 10: goto tr327;
		case 13: goto tr328;
		case 32: goto tr326;
		case 35: goto tr249;
		case 59: goto tr325;
		case 123: goto tr329;
	}
	goto tr324;
tr324:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 168; goto st22;} }
	goto st168;
tr328:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 168; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st168;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
#line 4882 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr315;
		case 10: goto tr323;
		case 13: goto tr330;
		case 32: goto tr315;
		case 35: goto tr331;
		case 59: goto tr89;
		case 123: goto tr240;
	}
	goto tr241;
tr1783:
#line 141 "confscanner.rl"
	{line++;}
	goto st890;
tr334:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 890; goto st22;} }
	goto st890;
tr1786:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st890;
tr332:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st890;
tr335:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 890; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st890;
tr336:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 890; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st890;
tr329:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 890; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 890; goto st886;} }
	goto st890;
st890:
	if ( ++p == pe )
		goto _test_eof890;
case 890:
#line 4963 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st890;
		case 10: goto tr1783;
		case 13: goto tr1784;
		case 32: goto st890;
		case 35: goto tr1785;
		case 59: goto tr89;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr246;
		case 125: goto tr1778;
	}
	goto tr241;
tr1784:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st169;
tr1787:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st169;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
#line 4997 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr332;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1785:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st170;
tr1788:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st170;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
#line 5028 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr334;
		case 9: goto tr335;
		case 10: goto tr336;
		case 13: goto tr337;
		case 32: goto tr335;
		case 35: goto tr249;
		case 59: goto tr334;
		case 123: goto tr329;
	}
	goto tr333;
tr333:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 891; goto st22;} }
	goto st891;
tr337:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 891; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st891;
st891:
	if ( ++p == pe )
		goto _test_eof891;
case 891:
#line 5059 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1786;
		case 10: goto tr332;
		case 13: goto tr1787;
		case 32: goto tr1786;
		case 35: goto tr1788;
		case 59: goto tr89;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr240;
		case 125: goto tr1778;
	}
	goto tr241;
tr1777:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st171;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
#line 5082 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 108: goto st172;
		case 114: goto st827;
		case 123: goto tr240;
	}
	goto st136;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 111: goto st173;
		case 123: goto tr240;
	}
	goto st136;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 98: goto st174;
		case 123: goto tr240;
	}
	goto st136;
tr674:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 174; goto st22;} }
	goto st174;
tr676:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 174; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st174;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
#line 5147 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr342;
		case 10: goto tr343;
		case 13: goto tr344;
		case 32: goto tr342;
		case 35: goto tr345;
		case 59: goto st0;
		case 61: goto st179;
		case 123: goto tr240;
	}
	goto st136;
tr348:
#line 141 "confscanner.rl"
	{line++;}
	goto st175;
tr354:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 175; goto st22;} }
	goto st175;
tr342:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st175;
tr352:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st175;
tr355:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 175; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st175;
tr356:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 175; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st175;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
#line 5216 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st175;
		case 10: goto tr348;
		case 13: goto tr349;
		case 32: goto st175;
		case 35: goto tr350;
		case 59: goto st0;
		case 61: goto tr351;
		case 123: goto tr246;
	}
	goto tr241;
tr349:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st176;
tr359:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st176;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
#line 5248 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr352;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr350:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st177;
tr360:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st177;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
#line 5279 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr354;
		case 9: goto tr355;
		case 10: goto tr356;
		case 13: goto tr357;
		case 32: goto tr355;
		case 35: goto tr249;
		case 59: goto tr354;
		case 123: goto tr358;
	}
	goto tr353;
tr353:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 178; goto st22;} }
	goto st178;
tr357:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 178; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st178;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
#line 5310 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr342;
		case 10: goto tr352;
		case 13: goto tr359;
		case 32: goto tr342;
		case 35: goto tr360;
		case 59: goto st0;
		case 61: goto tr351;
		case 123: goto tr240;
	}
	goto tr241;
tr1311:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 179; goto st22;} }
	goto st179;
tr351:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st179;
tr1314:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 179; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st179;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
#line 5346 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr361;
		case 10: goto tr362;
		case 13: goto tr363;
		case 32: goto tr361;
		case 35: goto tr364;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto tr231;
tr367:
#line 141 "confscanner.rl"
	{line++;}
	goto st180;
tr377:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 180; goto st22;} }
	goto st180;
tr361:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st180;
tr370:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st180;
tr378:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 180; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st180;
tr379:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 180; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st180;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
#line 5414 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st180;
		case 10: goto tr367;
		case 13: goto tr368;
		case 32: goto st180;
		case 35: goto tr369;
		case 59: goto st0;
		case 123: goto tr246;
	}
	goto tr365;
tr368:
#line 213 "confscanner.rl"
	{/*cerr << "glob_list";*/ tmp_p = p;}
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st181;
tr382:
#line 213 "confscanner.rl"
	{/*cerr << "glob_list";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st181;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
#line 5449 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr370;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
tr239:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st182;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
#line 5474 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr253;
		case 9: goto tr372;
		case 10: goto tr373;
		case 13: goto tr374;
		case 32: goto tr372;
		case 35: goto tr239;
		case 59: goto tr253;
		case 123: goto tr375;
	}
	goto tr371;
tr369:
#line 213 "confscanner.rl"
	{/*cerr << "glob_list";*/ tmp_p = p;}
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st183;
tr383:
#line 213 "confscanner.rl"
	{/*cerr << "glob_list";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st183;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
#line 5509 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr377;
		case 9: goto tr378;
		case 10: goto tr379;
		case 13: goto tr380;
		case 32: goto tr378;
		case 35: goto tr239;
		case 59: goto tr377;
		case 123: goto tr381;
	}
	goto tr376;
tr376:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 184; goto st22;} }
	goto st184;
tr380:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 184; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st184;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
#line 5540 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr361;
		case 10: goto tr370;
		case 13: goto tr382;
		case 32: goto tr361;
		case 35: goto tr383;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto tr365;
tr1790:
#line 141 "confscanner.rl"
	{line++;}
	goto st892;
tr386:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 892; goto st22;} }
	goto st892;
tr1796:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st892;
tr384:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st892;
tr387:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 892; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st892;
tr388:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 892; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st892;
tr381:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 892; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 892; goto st886;} }
	goto st892;
st892:
	if ( ++p == pe )
		goto _test_eof892;
case 892:
#line 5621 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st892;
		case 10: goto tr1790;
		case 13: goto tr1791;
		case 32: goto st892;
		case 35: goto tr1792;
		case 59: goto st0;
		case 97: goto tr1793;
		case 103: goto tr1794;
		case 123: goto tr246;
		case 125: goto tr1795;
	}
	goto tr365;
tr1791:
#line 213 "confscanner.rl"
	{/*cerr << "glob_list";*/ tmp_p = p;}
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st185;
tr1797:
#line 213 "confscanner.rl"
	{/*cerr << "glob_list";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st185;
st185:
	if ( ++p == pe )
		goto _test_eof185;
case 185:
#line 5659 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr384;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
tr1792:
#line 213 "confscanner.rl"
	{/*cerr << "glob_list";*/ tmp_p = p;}
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st186;
tr1798:
#line 213 "confscanner.rl"
	{/*cerr << "glob_list";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st186;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
#line 5694 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr386;
		case 9: goto tr387;
		case 10: goto tr388;
		case 13: goto tr389;
		case 32: goto tr387;
		case 35: goto tr239;
		case 59: goto tr386;
		case 123: goto tr381;
	}
	goto tr385;
tr385:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 893; goto st22;} }
	goto st893;
tr389:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 893; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st893;
st893:
	if ( ++p == pe )
		goto _test_eof893;
case 893:
#line 5725 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1796;
		case 10: goto tr384;
		case 13: goto tr1797;
		case 32: goto tr1796;
		case 35: goto tr1798;
		case 59: goto st0;
		case 97: goto tr1793;
		case 103: goto tr1794;
		case 123: goto tr240;
		case 125: goto tr1795;
	}
	goto tr365;
tr1983:
#line 213 "confscanner.rl"
	{/*cerr << "glob_list";*/ tmp_p = p;}
	goto st187;
tr1793:
#line 213 "confscanner.rl"
	{/*cerr << "glob_list";*/ tmp_p = p;}
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st187;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
#line 5754 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 100: goto st188;
		case 123: goto tr240;
	}
	goto st134;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 100: goto st189;
		case 123: goto tr240;
	}
	goto st134;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 40: goto st190;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 98: goto tr393;
		case 100: goto tr394;
		case 101: goto tr395;
		case 102: goto tr396;
		case 112: goto tr397;
		case 114: goto tr398;
		case 123: goto tr240;
	}
	goto st134;
tr393:
#line 237 "confscanner.rl"
	{/*cerr << "add:" << '\n';*/ tmp_p = p;}
	goto st191;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
#line 5828 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 114: goto st192;
		case 123: goto tr240;
	}
	goto st134;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 105: goto st193;
		case 123: goto tr240;
	}
	goto st134;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 101: goto st194;
		case 123: goto tr240;
	}
	goto st134;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 102: goto st195;
		case 123: goto tr240;
	}
	goto st134;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 41: goto tr403;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
tr412:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 196; goto st22;} }
	goto st196;
tr403:
#line 42 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    if(tmp_string == "brief")
      cblock_ = &docuheader_;
    else if(tmp_string == "doc")
      cblock_ = &docubody_;
    else if(tmp_string == "extra")
      cblock_ = &docuextra_;
  }
	goto st196;
tr415:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 196; goto st22;} }
	goto st196;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
#line 5936 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr281;
		case 10: goto tr282;
		case 13: goto tr404;
		case 32: goto tr281;
		case 35: goto tr405;
		case 43: goto tr406;
		case 59: goto st0;
		case 61: goto st209;
		case 123: goto tr240;
	}
	goto st134;
tr408:
#line 141 "confscanner.rl"
	{line++;}
	goto st197;
tr411:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 197; goto st22;} }
	goto st197;
tr282:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st197;
tr1705:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st197;
tr1707:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 197; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st197;
tr414:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 197; goto st22;} }
#line 141 "confscanner.rl"
	{line++;}
	goto st197;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
#line 6010 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st154;
		case 10: goto tr408;
		case 13: goto st198;
		case 32: goto st154;
		case 35: goto st199;
		case 43: goto tr76;
		case 61: goto st40;
		case 123: goto tr246;
	}
	goto st0;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
	if ( (*p) == 10 )
		goto tr408;
	goto st0;
st199:
	if ( ++p == pe )
		goto _test_eof199;
case 199:
	if ( (*p) == 35 )
		goto st0;
	goto tr411;
tr404:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st200;
st200:
	if ( ++p == pe )
		goto _test_eof200;
case 200:
#line 6049 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr282;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
tr405:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st201;
st201:
	if ( ++p == pe )
		goto _test_eof201;
case 201:
#line 6074 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr411;
		case 9: goto tr413;
		case 10: goto tr414;
		case 13: goto tr415;
		case 32: goto tr413;
		case 35: goto tr239;
		case 59: goto tr411;
		case 123: goto tr416;
	}
	goto tr412;
tr428:
#line 141 "confscanner.rl"
	{line++;}
	goto st894;
tr429:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 894; goto st22;} }
	goto st894;
tr1709:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 894; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 894; goto st886;} }
	goto st894;
tr416:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 894; goto st22;} }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 894; goto st886;} }
	goto st894;
st894:
	if ( ++p == pe )
		goto _test_eof894;
case 894:
#line 6124 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st895;
		case 10: goto tr428;
		case 13: goto st206;
		case 32: goto st895;
		case 35: goto st207;
		case 43: goto tr76;
		case 61: goto st40;
		case 97: goto st27;
		case 103: goto st127;
		case 123: goto tr246;
		case 125: goto tr1769;
	}
	goto st0;
tr1802:
#line 141 "confscanner.rl"
	{line++;}
	goto st895;
tr419:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 895; goto st22;} }
	goto st895;
tr1805:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st895;
tr417:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st895;
tr420:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 895; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st895;
tr421:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 895; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st895;
tr299:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 895; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 895; goto st886;} }
	goto st895;
st895:
	if ( ++p == pe )
		goto _test_eof895;
case 895:
#line 6208 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st895;
		case 10: goto tr1802;
		case 13: goto tr1803;
		case 32: goto st895;
		case 35: goto tr1804;
		case 43: goto tr291;
		case 59: goto st0;
		case 61: goto tr292;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr246;
		case 125: goto tr1778;
	}
	goto tr241;
tr1803:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st202;
tr1806:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st202;
st202:
	if ( ++p == pe )
		goto _test_eof202;
case 202:
#line 6244 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr417;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1804:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st203;
tr1807:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st203;
st203:
	if ( ++p == pe )
		goto _test_eof203;
case 203:
#line 6275 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr419;
		case 9: goto tr420;
		case 10: goto tr421;
		case 13: goto tr422;
		case 32: goto tr420;
		case 35: goto tr249;
		case 59: goto tr419;
		case 123: goto tr299;
	}
	goto tr418;
tr418:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 896; goto st22;} }
	goto st896;
tr422:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 896; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st896;
st896:
	if ( ++p == pe )
		goto _test_eof896;
case 896:
#line 6306 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1805;
		case 10: goto tr417;
		case 13: goto tr1806;
		case 32: goto tr1805;
		case 35: goto tr1807;
		case 43: goto tr291;
		case 59: goto st0;
		case 61: goto tr292;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr240;
		case 125: goto tr1778;
	}
	goto tr241;
tr424:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 897; goto st22;} }
	goto st897;
tr1812:
#line 260 "confscanner.rl"
	{ go_level_down(); {cs = stack[--top];goto _again;} }
	goto st897;
tr1778:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 260 "confscanner.rl"
	{ go_level_down(); {cs = stack[--top];goto _again;} }
	goto st897;
st897:
	if ( ++p == pe )
		goto _test_eof897;
case 897:
#line 6341 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1779;
		case 10: goto tr1354;
		case 13: goto tr1808;
		case 32: goto tr1779;
		case 35: goto tr1809;
		case 59: goto st0;
		case 97: goto st144;
		case 103: goto st171;
		case 123: goto tr240;
		case 125: goto tr1812;
	}
	goto st136;
tr1808:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st204;
st204:
	if ( ++p == pe )
		goto _test_eof204;
case 204:
#line 6369 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr423;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1809:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st205;
st205:
	if ( ++p == pe )
		goto _test_eof205;
case 205:
#line 6394 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr425;
		case 9: goto tr263;
		case 10: goto tr426;
		case 13: goto tr427;
		case 32: goto tr263;
		case 35: goto tr249;
		case 59: goto tr425;
		case 123: goto tr259;
	}
	goto tr424;
tr427:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 898; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st898;
st898:
	if ( ++p == pe )
		goto _test_eof898;
case 898:
#line 6421 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1779;
		case 10: goto tr423;
		case 13: goto tr1808;
		case 32: goto tr1779;
		case 35: goto tr1809;
		case 59: goto st0;
		case 97: goto st144;
		case 103: goto st171;
		case 123: goto tr240;
		case 125: goto tr1812;
	}
	goto st136;
st206:
	if ( ++p == pe )
		goto _test_eof206;
case 206:
	if ( (*p) == 10 )
		goto tr428;
	goto st0;
st207:
	if ( ++p == pe )
		goto _test_eof207;
case 207:
	if ( (*p) == 35 )
		goto st0;
	goto tr429;
tr406:
#line 146 "confscanner.rl"
	{arg_to_be_added_ = true;}
	goto st208;
st208:
	if ( ++p == pe )
		goto _test_eof208;
case 208:
#line 6458 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 61: goto st209;
		case 123: goto tr240;
	}
	goto st134;
tr452:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 209; goto st22;} }
	goto st209;
tr1547:
#line 213 "confscanner.rl"
	{/*cerr << "glob_list";*/ tmp_p = p;}
	goto st209;
tr455:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 209; goto st22;} }
	goto st209;
st209:
	if ( ++p == pe )
		goto _test_eof209;
case 209:
#line 6494 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr302;
		case 10: goto tr303;
		case 13: goto tr430;
		case 32: goto tr302;
		case 34: goto st214;
		case 35: goto tr432;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
tr433:
#line 141 "confscanner.rl"
	{line++;}
	goto st210;
tr436:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 210; goto st22;} }
	goto st210;
tr303:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st210;
tr1700:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st210;
tr1702:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 210; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st210;
tr454:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 210; goto st22;} }
#line 141 "confscanner.rl"
	{line++;}
	goto st210;
st210:
	if ( ++p == pe )
		goto _test_eof210;
case 210:
#line 6567 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st160;
		case 10: goto tr433;
		case 13: goto st211;
		case 32: goto st160;
		case 34: goto st42;
		case 35: goto st212;
		case 123: goto tr246;
	}
	goto st0;
st211:
	if ( ++p == pe )
		goto _test_eof211;
case 211:
	if ( (*p) == 10 )
		goto tr433;
	goto st0;
st212:
	if ( ++p == pe )
		goto _test_eof212;
case 212:
	if ( (*p) == 35 )
		goto st0;
	goto tr436;
tr430:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st213;
st213:
	if ( ++p == pe )
		goto _test_eof213;
case 213:
#line 6605 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr303;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
st214:
	if ( ++p == pe )
		goto _test_eof214;
case 214:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 34: goto st215;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
st215:
	if ( ++p == pe )
		goto _test_eof215;
case 215:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 34: goto tr438;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
tr445:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 216; goto st22;} }
	goto st216;
tr438:
#line 162 "confscanner.rl"
	{
                opt=true;
                if(!arg_to_be_added_)
                  (*cblock_).clear();
                {stack[top++] = 216; goto st884;}
                }
	goto st216;
tr448:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 216; goto st22;} }
	goto st216;
st216:
	if ( ++p == pe )
		goto _test_eof216;
case 216:
#line 6677 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr315;
		case 10: goto tr316;
		case 13: goto tr439;
		case 32: goto tr315;
		case 35: goto tr440;
		case 59: goto tr89;
		case 123: goto tr240;
	}
	goto st134;
tr441:
#line 141 "confscanner.rl"
	{line++;}
	goto st217;
tr444:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 217; goto st22;} }
	goto st217;
tr316:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st217;
tr737:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st217;
tr739:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 217; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st217;
tr447:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 217; goto st22;} }
#line 141 "confscanner.rl"
	{line++;}
	goto st217;
tr731:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
#line 27 "confscanner.rl"
	{
//    cerr << "in group add: " << endl;
    if(match_at_level_[level_])
    {
//      cerr << "do it" << endl;
      tmp_string.assign(tmp_p, p-tmp_p);
      // clear groupset_ first, if we did not use '+='
      if(!arg_to_be_added_)
        groupset_.clear();

      groupset_.insert(tmp_string);
    }
  }
	goto st217;
st217:
	if ( ++p == pe )
		goto _test_eof217;
case 217:
#line 6774 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st165;
		case 10: goto tr441;
		case 13: goto st218;
		case 32: goto st165;
		case 35: goto st219;
		case 59: goto tr89;
		case 123: goto tr246;
	}
	goto st0;
st218:
	if ( ++p == pe )
		goto _test_eof218;
case 218:
	if ( (*p) == 10 )
		goto tr441;
	goto st0;
st219:
	if ( ++p == pe )
		goto _test_eof219;
case 219:
	if ( (*p) == 35 )
		goto st0;
	goto tr444;
tr439:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st220;
tr1350:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 27 "confscanner.rl"
	{
//    cerr << "in group add: " << endl;
    if(match_at_level_[level_])
    {
//      cerr << "do it" << endl;
      tmp_string.assign(tmp_p, p-tmp_p);
      // clear groupset_ first, if we did not use '+='
      if(!arg_to_be_added_)
        groupset_.clear();

      groupset_.insert(tmp_string);
    }
  }
	goto st220;
st220:
	if ( ++p == pe )
		goto _test_eof220;
case 220:
#line 6835 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr316;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
tr440:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st221;
tr1351:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 27 "confscanner.rl"
	{
//    cerr << "in group add: " << endl;
    if(match_at_level_[level_])
    {
//      cerr << "do it" << endl;
      tmp_string.assign(tmp_p, p-tmp_p);
      // clear groupset_ first, if we did not use '+='
      if(!arg_to_be_added_)
        groupset_.clear();

      groupset_.insert(tmp_string);
    }
  }
	goto st221;
st221:
	if ( ++p == pe )
		goto _test_eof221;
case 221:
#line 6883 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr444;
		case 9: goto tr446;
		case 10: goto tr447;
		case 13: goto tr448;
		case 32: goto tr446;
		case 35: goto tr239;
		case 59: goto tr444;
		case 123: goto tr449;
	}
	goto tr445;
tr450:
#line 141 "confscanner.rl"
	{line++;}
	goto st899;
tr451:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 899; goto st22;} }
	goto st899;
tr741:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 899; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 899; goto st886;} }
	goto st899;
tr449:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 899; goto st22;} }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 899; goto st886;} }
	goto st899;
st899:
	if ( ++p == pe )
		goto _test_eof899;
case 899:
#line 6933 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st890;
		case 10: goto tr450;
		case 13: goto st222;
		case 32: goto st890;
		case 35: goto st223;
		case 59: goto tr89;
		case 97: goto st27;
		case 103: goto st127;
		case 123: goto tr246;
		case 125: goto tr1769;
	}
	goto st0;
st222:
	if ( ++p == pe )
		goto _test_eof222;
case 222:
	if ( (*p) == 10 )
		goto tr450;
	goto st0;
st223:
	if ( ++p == pe )
		goto _test_eof223;
case 223:
	if ( (*p) == 35 )
		goto st0;
	goto tr451;
tr432:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st224;
st224:
	if ( ++p == pe )
		goto _test_eof224;
case 224:
#line 6974 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr436;
		case 9: goto tr453;
		case 10: goto tr454;
		case 13: goto tr455;
		case 32: goto tr453;
		case 35: goto tr239;
		case 59: goto tr436;
		case 123: goto tr456;
	}
	goto tr452;
tr464:
#line 141 "confscanner.rl"
	{line++;}
	goto st900;
tr465:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 900; goto st22;} }
	goto st900;
tr1704:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 900; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 900; goto st886;} }
	goto st900;
tr456:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 900; goto st22;} }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 900; goto st886;} }
	goto st900;
st900:
	if ( ++p == pe )
		goto _test_eof900;
case 900:
#line 7024 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st901;
		case 10: goto tr464;
		case 13: goto st227;
		case 32: goto st901;
		case 34: goto st42;
		case 35: goto st228;
		case 97: goto st27;
		case 103: goto st127;
		case 123: goto tr246;
		case 125: goto tr1769;
	}
	goto st0;
tr1818:
#line 141 "confscanner.rl"
	{line++;}
	goto st901;
tr459:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 901; goto st22;} }
	goto st901;
tr1821:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st901;
tr457:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st901;
tr460:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 901; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st901;
tr461:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 901; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st901;
tr463:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 901; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 901; goto st886;} }
	goto st901;
st901:
	if ( ++p == pe )
		goto _test_eof901;
case 901:
#line 7107 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st901;
		case 10: goto tr1818;
		case 13: goto tr1819;
		case 32: goto st901;
		case 34: goto tr310;
		case 35: goto tr1820;
		case 59: goto st0;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr246;
		case 125: goto tr1778;
	}
	goto tr241;
tr1819:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st225;
tr1822:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st225;
st225:
	if ( ++p == pe )
		goto _test_eof225;
case 225:
#line 7142 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr457;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1820:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st226;
tr1823:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st226;
st226:
	if ( ++p == pe )
		goto _test_eof226;
case 226:
#line 7173 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr459;
		case 9: goto tr460;
		case 10: goto tr461;
		case 13: goto tr462;
		case 32: goto tr460;
		case 35: goto tr249;
		case 59: goto tr459;
		case 123: goto tr463;
	}
	goto tr458;
tr458:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 902; goto st22;} }
	goto st902;
tr462:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 902; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st902;
st902:
	if ( ++p == pe )
		goto _test_eof902;
case 902:
#line 7204 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1821;
		case 10: goto tr457;
		case 13: goto tr1822;
		case 32: goto tr1821;
		case 34: goto tr310;
		case 35: goto tr1823;
		case 59: goto st0;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr240;
		case 125: goto tr1778;
	}
	goto tr241;
st227:
	if ( ++p == pe )
		goto _test_eof227;
case 227:
	if ( (*p) == 10 )
		goto tr464;
	goto st0;
st228:
	if ( ++p == pe )
		goto _test_eof228;
case 228:
	if ( (*p) == 35 )
		goto st0;
	goto tr465;
tr394:
#line 237 "confscanner.rl"
	{/*cerr << "add:" << '\n';*/ tmp_p = p;}
	goto st229;
st229:
	if ( ++p == pe )
		goto _test_eof229;
case 229:
#line 7242 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 111: goto st230;
		case 123: goto tr240;
	}
	goto st134;
st230:
	if ( ++p == pe )
		goto _test_eof230;
case 230:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 99: goto st195;
		case 123: goto tr240;
	}
	goto st134;
tr395:
#line 237 "confscanner.rl"
	{/*cerr << "add:" << '\n';*/ tmp_p = p;}
	goto st231;
st231:
	if ( ++p == pe )
		goto _test_eof231;
case 231:
#line 7279 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 120: goto st232;
		case 123: goto tr240;
	}
	goto st134;
st232:
	if ( ++p == pe )
		goto _test_eof232;
case 232:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 116: goto st233;
		case 123: goto tr240;
	}
	goto st134;
st233:
	if ( ++p == pe )
		goto _test_eof233;
case 233:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 114: goto st234;
		case 123: goto tr240;
	}
	goto st134;
st234:
	if ( ++p == pe )
		goto _test_eof234;
case 234:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 97: goto st195;
		case 123: goto tr240;
	}
	goto st134;
tr396:
#line 237 "confscanner.rl"
	{/*cerr << "add:" << '\n';*/ tmp_p = p;}
	goto st235;
st235:
	if ( ++p == pe )
		goto _test_eof235;
case 235:
#line 7348 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 105: goto st236;
		case 123: goto tr240;
	}
	goto st134;
st236:
	if ( ++p == pe )
		goto _test_eof236;
case 236:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 101: goto st237;
		case 123: goto tr240;
	}
	goto st134;
st237:
	if ( ++p == pe )
		goto _test_eof237;
case 237:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 108: goto st238;
		case 123: goto tr240;
	}
	goto st134;
st238:
	if ( ++p == pe )
		goto _test_eof238;
case 238:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 100: goto st239;
		case 123: goto tr240;
	}
	goto st134;
st239:
	if ( ++p == pe )
		goto _test_eof239;
case 239:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 115: goto st240;
		case 123: goto tr240;
	}
	goto st134;
st240:
	if ( ++p == pe )
		goto _test_eof240;
case 240:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 41: goto tr475;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
tr1020:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 241; goto st22;} }
	goto st241;
tr475:
#line 66 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    if(tmp_string == "fields")
      clistmap_ = &field_docu_;
  }
	goto st241;
tr1023:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 241; goto st22;} }
	goto st241;
st241:
	if ( ++p == pe )
		goto _test_eof241;
case 241:
#line 7468 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr476;
		case 10: goto tr477;
		case 13: goto tr478;
		case 32: goto tr476;
		case 35: goto tr479;
		case 43: goto tr480;
		case 59: goto st0;
		case 61: goto st518;
		case 123: goto tr240;
	}
	goto st134;
tr483:
#line 141 "confscanner.rl"
	{line++;}
	goto st242;
tr490:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 242; goto st22;} }
	goto st242;
tr476:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st242;
tr488:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st242;
tr491:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 242; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st242;
tr492:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 242; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st242;
tr1021:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 242; goto st22;} }
	goto st242;
st242:
	if ( ++p == pe )
		goto _test_eof242;
case 242:
#line 7549 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st242;
		case 10: goto tr483;
		case 13: goto tr484;
		case 32: goto st242;
		case 35: goto tr485;
		case 43: goto tr486;
		case 59: goto st0;
		case 61: goto tr487;
		case 123: goto tr246;
	}
	goto tr241;
tr484:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st243;
tr495:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st243;
st243:
	if ( ++p == pe )
		goto _test_eof243;
case 243:
#line 7582 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr488;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr485:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st244;
tr496:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st244;
st244:
	if ( ++p == pe )
		goto _test_eof244;
case 244:
#line 7613 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr490;
		case 9: goto tr491;
		case 10: goto tr492;
		case 13: goto tr493;
		case 32: goto tr491;
		case 35: goto tr249;
		case 59: goto tr490;
		case 123: goto tr494;
	}
	goto tr489;
tr489:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 245; goto st22;} }
	goto st245;
tr493:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 245; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st245;
st245:
	if ( ++p == pe )
		goto _test_eof245;
case 245:
#line 7644 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr476;
		case 10: goto tr488;
		case 13: goto tr495;
		case 32: goto tr476;
		case 35: goto tr496;
		case 43: goto tr486;
		case 59: goto st0;
		case 61: goto tr487;
		case 123: goto tr240;
	}
	goto tr241;
tr1722:
#line 146 "confscanner.rl"
	{arg_to_be_added_ = true;}
	goto st246;
tr486:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 146 "confscanner.rl"
	{arg_to_be_added_ = true;}
	goto st246;
st246:
	if ( ++p == pe )
		goto _test_eof246;
case 246:
#line 7672 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 61: goto st247;
		case 123: goto tr240;
	}
	goto st136;
tr994:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 247; goto st22;} }
	goto st247;
tr487:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st247;
st247:
	if ( ++p == pe )
		goto _test_eof247;
case 247:
#line 7697 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr498;
		case 10: goto tr499;
		case 13: goto tr500;
		case 32: goto tr498;
		case 35: goto tr501;
		case 40: goto st252;
		case 59: goto st0;
		case 123: goto tr240;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr503;
	} else if ( (*p) >= 65 )
		goto tr503;
	goto st136;
tr505:
#line 141 "confscanner.rl"
	{line++;}
	goto st248;
tr512:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 248; goto st22;} }
	goto st248;
tr498:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st248;
tr510:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st248;
tr513:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 248; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st248;
tr514:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 248; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st248;
tr1032:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 248; goto st22;} }
	goto st248;
st248:
	if ( ++p == pe )
		goto _test_eof248;
case 248:
#line 7782 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st248;
		case 10: goto tr505;
		case 13: goto tr506;
		case 32: goto st248;
		case 35: goto tr507;
		case 40: goto tr508;
		case 59: goto st0;
		case 123: goto tr246;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr509;
	} else if ( (*p) >= 65 )
		goto tr509;
	goto tr241;
tr506:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st249;
tr517:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st249;
st249:
	if ( ++p == pe )
		goto _test_eof249;
case 249:
#line 7819 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr510;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr507:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st250;
tr518:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st250;
st250:
	if ( ++p == pe )
		goto _test_eof250;
case 250:
#line 7850 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr512;
		case 9: goto tr513;
		case 10: goto tr514;
		case 13: goto tr515;
		case 32: goto tr513;
		case 35: goto tr249;
		case 59: goto tr512;
		case 123: goto tr516;
	}
	goto tr511;
tr511:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 251; goto st22;} }
	goto st251;
tr515:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 251; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st251;
st251:
	if ( ++p == pe )
		goto _test_eof251;
case 251:
#line 7881 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr498;
		case 10: goto tr510;
		case 13: goto tr517;
		case 32: goto tr498;
		case 35: goto tr518;
		case 40: goto tr508;
		case 59: goto st0;
		case 123: goto tr240;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr509;
	} else if ( (*p) >= 65 )
		goto tr509;
	goto tr241;
tr907:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 252; goto st22;} }
	goto st252;
tr508:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st252;
st252:
	if ( ++p == pe )
		goto _test_eof252;
case 252:
#line 7911 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr519;
		case 10: goto tr520;
		case 13: goto tr521;
		case 32: goto tr519;
		case 35: goto tr522;
		case 59: goto st0;
		case 123: goto tr240;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr523;
	} else if ( (*p) >= 65 )
		goto tr523;
	goto st136;
tr525:
#line 141 "confscanner.rl"
	{line++;}
	goto st253;
tr531:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 253; goto st22;} }
	goto st253;
tr519:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st253;
tr529:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st253;
tr532:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 253; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st253;
tr533:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 253; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st253;
tr1040:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 253; goto st22;} }
	goto st253;
st253:
	if ( ++p == pe )
		goto _test_eof253;
case 253:
#line 7995 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st253;
		case 10: goto tr525;
		case 13: goto tr526;
		case 32: goto st253;
		case 35: goto tr527;
		case 59: goto st0;
		case 123: goto tr246;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr528;
	} else if ( (*p) >= 65 )
		goto tr528;
	goto tr241;
tr526:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st254;
tr536:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st254;
st254:
	if ( ++p == pe )
		goto _test_eof254;
case 254:
#line 8031 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr529;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr527:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st255;
tr537:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st255;
st255:
	if ( ++p == pe )
		goto _test_eof255;
case 255:
#line 8062 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr531;
		case 9: goto tr532;
		case 10: goto tr533;
		case 13: goto tr534;
		case 32: goto tr532;
		case 35: goto tr249;
		case 59: goto tr531;
		case 123: goto tr535;
	}
	goto tr530;
tr530:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 256; goto st22;} }
	goto st256;
tr534:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 256; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st256;
st256:
	if ( ++p == pe )
		goto _test_eof256;
case 256:
#line 8093 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr519;
		case 10: goto tr529;
		case 13: goto tr536;
		case 32: goto tr519;
		case 35: goto tr537;
		case 59: goto st0;
		case 123: goto tr240;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr528;
	} else if ( (*p) >= 65 )
		goto tr528;
	goto tr241;
tr523:
#line 192 "confscanner.rl"
	{tmp_p = p;/* cerr << "dlmi\n";*/}
	goto st257;
tr528:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 192 "confscanner.rl"
	{tmp_p = p;/* cerr << "dlmi\n";*/}
	goto st257;
st257:
	if ( ++p == pe )
		goto _test_eof257;
case 257:
#line 8124 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 46: goto tr538;
		case 59: goto st0;
		case 95: goto st257;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st257;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st257;
	} else
		goto st257;
	goto st136;
tr538:
#line 22 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
  }
	goto st258;
st258:
	if ( ++p == pe )
		goto _test_eof258;
case 258:
#line 8156 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr540;
	} else if ( (*p) >= 65 )
		goto tr540;
	goto st136;
tr540:
#line 196 "confscanner.rl"
	{tmp_p = p;/* cerr << "dlmi2\n";*/}
	goto st259;
st259:
	if ( ++p == pe )
		goto _test_eof259;
case 259:
#line 8181 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr541;
		case 10: goto tr542;
		case 13: goto tr543;
		case 32: goto tr541;
		case 35: goto tr544;
		case 59: goto st0;
		case 61: goto tr546;
		case 95: goto st259;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st259;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st259;
	} else
		goto st259;
	goto st136;
tr548:
#line 141 "confscanner.rl"
	{line++;}
	goto st260;
tr554:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 260; goto st22;} }
	goto st260;
tr559:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st260;
tr552:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st260;
tr555:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 260; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st260;
tr556:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 260; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st260;
tr1052:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 260; goto st22;} }
	goto st260;
tr541:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 108 "confscanner.rl"
	{
    string s(tmp_p, p-tmp_p);
    cblock_ = &((*clistmap_)[tmp_string][s]);
  }
	goto st260;
st260:
	if ( ++p == pe )
		goto _test_eof260;
case 260:
#line 8284 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st260;
		case 10: goto tr548;
		case 13: goto tr549;
		case 32: goto st260;
		case 35: goto tr550;
		case 59: goto st0;
		case 61: goto tr551;
		case 123: goto tr246;
	}
	goto tr241;
tr549:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st261;
tr560:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st261;
st261:
	if ( ++p == pe )
		goto _test_eof261;
case 261:
#line 8316 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr552;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr550:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st262;
tr561:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st262;
st262:
	if ( ++p == pe )
		goto _test_eof262;
case 262:
#line 8347 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr554;
		case 9: goto tr555;
		case 10: goto tr556;
		case 13: goto tr557;
		case 32: goto tr555;
		case 35: goto tr249;
		case 59: goto tr554;
		case 123: goto tr558;
	}
	goto tr553;
tr553:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 263; goto st22;} }
	goto st263;
tr557:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 263; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st263;
st263:
	if ( ++p == pe )
		goto _test_eof263;
case 263:
#line 8378 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr559;
		case 10: goto tr552;
		case 13: goto tr560;
		case 32: goto tr559;
		case 35: goto tr561;
		case 59: goto st0;
		case 61: goto tr551;
		case 123: goto tr240;
	}
	goto tr241;
tr546:
#line 108 "confscanner.rl"
	{
    string s(tmp_p, p-tmp_p);
    cblock_ = &((*clistmap_)[tmp_string][s]);
  }
	goto st264;
tr551:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st264;
st264:
	if ( ++p == pe )
		goto _test_eof264;
case 264:
#line 8406 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 62: goto st265;
		case 123: goto tr240;
	}
	goto st136;
tr631:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 265; goto st22;} }
	goto st265;
st265:
	if ( ++p == pe )
		goto _test_eof265;
case 265:
#line 8427 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr563;
		case 10: goto tr564;
		case 13: goto tr565;
		case 32: goto tr563;
		case 34: goto st268;
		case 35: goto tr567;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr569:
#line 141 "confscanner.rl"
	{line++;}
	goto st266;
tr613:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 266; goto st22;} }
	goto st266;
tr563:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st266;
tr573:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st266;
tr614:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 266; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st266;
tr615:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 266; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st266;
tr1074:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 266; goto st22;} }
	goto st266;
st266:
	if ( ++p == pe )
		goto _test_eof266;
case 266:
#line 8507 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st266;
		case 10: goto tr569;
		case 13: goto tr570;
		case 32: goto st266;
		case 34: goto tr571;
		case 35: goto tr572;
		case 59: goto st0;
		case 123: goto tr246;
	}
	goto tr241;
tr570:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st267;
tr618:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st267;
st267:
	if ( ++p == pe )
		goto _test_eof267;
case 267:
#line 8539 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr573;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr571:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st268;
st268:
	if ( ++p == pe )
		goto _test_eof268;
case 268:
#line 8559 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 34: goto st269;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
st269:
	if ( ++p == pe )
		goto _test_eof269;
case 269:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 34: goto tr575;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr606:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 270; goto st22;} }
	goto st270;
tr575:
#line 162 "confscanner.rl"
	{
                opt=true;
                if(!arg_to_be_added_)
                  (*cblock_).clear();
                {stack[top++] = 270; goto st884;}
                }
	goto st270;
st270:
	if ( ++p == pe )
		goto _test_eof270;
case 270:
#line 8605 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr576;
		case 10: goto tr577;
		case 13: goto tr578;
		case 32: goto tr576;
		case 35: goto tr579;
		case 41: goto st164;
		case 44: goto st252;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr582:
#line 141 "confscanner.rl"
	{line++;}
	goto st271;
tr588:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 271; goto st22;} }
	goto st271;
tr576:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st271;
tr586:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st271;
tr589:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 271; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st271;
tr590:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 271; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st271;
tr1069:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 271; goto st22;} }
	goto st271;
st271:
	if ( ++p == pe )
		goto _test_eof271;
case 271:
#line 8686 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st271;
		case 10: goto tr582;
		case 13: goto tr583;
		case 32: goto st271;
		case 35: goto tr584;
		case 41: goto tr585;
		case 44: goto tr508;
		case 59: goto st0;
		case 123: goto tr246;
	}
	goto tr241;
tr583:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st272;
tr593:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st272;
st272:
	if ( ++p == pe )
		goto _test_eof272;
case 272:
#line 8719 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr586;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr584:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st273;
tr594:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st273;
st273:
	if ( ++p == pe )
		goto _test_eof273;
case 273:
#line 8750 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr588;
		case 9: goto tr589;
		case 10: goto tr590;
		case 13: goto tr591;
		case 32: goto tr589;
		case 35: goto tr249;
		case 59: goto tr588;
		case 123: goto tr592;
	}
	goto tr587;
tr587:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 274; goto st22;} }
	goto st274;
tr591:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 274; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st274;
st274:
	if ( ++p == pe )
		goto _test_eof274;
case 274:
#line 8781 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr576;
		case 10: goto tr586;
		case 13: goto tr593;
		case 32: goto tr576;
		case 35: goto tr594;
		case 41: goto tr585;
		case 44: goto tr508;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto tr241;
tr1825:
#line 141 "confscanner.rl"
	{line++;}
	goto st903;
tr597:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 903; goto st22;} }
	goto st903;
tr1828:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st903;
tr595:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st903;
tr598:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 903; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st903;
tr599:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 903; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st903;
tr592:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 903; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 903; goto st886;} }
	goto st903;
st903:
	if ( ++p == pe )
		goto _test_eof903;
case 903:
#line 8864 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st903;
		case 10: goto tr1825;
		case 13: goto tr1826;
		case 32: goto st903;
		case 35: goto tr1827;
		case 41: goto tr585;
		case 44: goto tr508;
		case 59: goto st0;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr246;
		case 125: goto tr1778;
	}
	goto tr241;
tr1826:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st275;
tr1829:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st275;
st275:
	if ( ++p == pe )
		goto _test_eof275;
case 275:
#line 8900 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr595;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1827:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st276;
tr1830:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st276;
st276:
	if ( ++p == pe )
		goto _test_eof276;
case 276:
#line 8931 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr597;
		case 9: goto tr598;
		case 10: goto tr599;
		case 13: goto tr600;
		case 32: goto tr598;
		case 35: goto tr249;
		case 59: goto tr597;
		case 123: goto tr592;
	}
	goto tr596;
tr596:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 904; goto st22;} }
	goto st904;
tr600:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 904; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st904;
st904:
	if ( ++p == pe )
		goto _test_eof904;
case 904:
#line 8962 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1828;
		case 10: goto tr595;
		case 13: goto tr1829;
		case 32: goto tr1828;
		case 35: goto tr1830;
		case 41: goto tr585;
		case 44: goto tr508;
		case 59: goto st0;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr240;
		case 125: goto tr1778;
	}
	goto tr241;
tr601:
#line 141 "confscanner.rl"
	{line++;}
	goto st277;
tr604:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 277; goto st22;} }
	goto st277;
tr577:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st277;
tr605:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st277;
tr607:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 277; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st277;
tr1070:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 277; goto st22;} }
#line 141 "confscanner.rl"
	{line++;}
	goto st277;
st277:
	if ( ++p == pe )
		goto _test_eof277;
case 277:
#line 9039 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st271;
		case 10: goto tr601;
		case 13: goto st278;
		case 32: goto st271;
		case 35: goto st279;
		case 41: goto st44;
		case 44: goto st67;
		case 123: goto tr246;
	}
	goto st0;
st278:
	if ( ++p == pe )
		goto _test_eof278;
case 278:
	if ( (*p) == 10 )
		goto tr601;
	goto st0;
st279:
	if ( ++p == pe )
		goto _test_eof279;
case 279:
	if ( (*p) == 35 )
		goto st0;
	goto tr604;
tr578:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st280;
st280:
	if ( ++p == pe )
		goto _test_eof280;
case 280:
#line 9078 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr605;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr579:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st281;
st281:
	if ( ++p == pe )
		goto _test_eof281;
case 281:
#line 9103 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr604;
		case 9: goto tr589;
		case 10: goto tr607;
		case 13: goto tr608;
		case 32: goto tr589;
		case 35: goto tr249;
		case 59: goto tr604;
		case 123: goto tr609;
	}
	goto tr606;
tr608:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 282; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st282;
st282:
	if ( ++p == pe )
		goto _test_eof282;
case 282:
#line 9130 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr576;
		case 10: goto tr605;
		case 13: goto tr578;
		case 32: goto tr576;
		case 35: goto tr579;
		case 41: goto st164;
		case 44: goto st252;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr610:
#line 141 "confscanner.rl"
	{line++;}
	goto st905;
tr611:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 905; goto st22;} }
	goto st905;
tr609:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 905; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 905; goto st886;} }
	goto st905;
tr1072:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 905; goto st22;} }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 905; goto st886;} }
	goto st905;
st905:
	if ( ++p == pe )
		goto _test_eof905;
case 905:
#line 9182 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st903;
		case 10: goto tr610;
		case 13: goto st283;
		case 32: goto st903;
		case 35: goto st284;
		case 41: goto st44;
		case 44: goto st67;
		case 97: goto st27;
		case 103: goto st127;
		case 123: goto tr246;
		case 125: goto tr1769;
	}
	goto st0;
st283:
	if ( ++p == pe )
		goto _test_eof283;
case 283:
	if ( (*p) == 10 )
		goto tr610;
	goto st0;
st284:
	if ( ++p == pe )
		goto _test_eof284;
case 284:
	if ( (*p) == 35 )
		goto st0;
	goto tr611;
tr572:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st285;
tr619:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st285;
st285:
	if ( ++p == pe )
		goto _test_eof285;
case 285:
#line 9230 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr613;
		case 9: goto tr614;
		case 10: goto tr615;
		case 13: goto tr616;
		case 32: goto tr614;
		case 35: goto tr249;
		case 59: goto tr613;
		case 123: goto tr617;
	}
	goto tr612;
tr612:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 286; goto st22;} }
	goto st286;
tr616:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 286; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st286;
st286:
	if ( ++p == pe )
		goto _test_eof286;
case 286:
#line 9261 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr563;
		case 10: goto tr573;
		case 13: goto tr618;
		case 32: goto tr563;
		case 34: goto tr571;
		case 35: goto tr619;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto tr241;
tr1834:
#line 141 "confscanner.rl"
	{line++;}
	goto st906;
tr622:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 906; goto st22;} }
	goto st906;
tr1837:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st906;
tr620:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st906;
tr623:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 906; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st906;
tr624:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 906; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st906;
tr617:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 906; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 906; goto st886;} }
	goto st906;
st906:
	if ( ++p == pe )
		goto _test_eof906;
case 906:
#line 9343 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st906;
		case 10: goto tr1834;
		case 13: goto tr1835;
		case 32: goto st906;
		case 34: goto tr571;
		case 35: goto tr1836;
		case 59: goto st0;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr246;
		case 125: goto tr1778;
	}
	goto tr241;
tr1835:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st287;
tr1838:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st287;
st287:
	if ( ++p == pe )
		goto _test_eof287;
case 287:
#line 9378 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr620;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1836:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st288;
tr1839:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st288;
st288:
	if ( ++p == pe )
		goto _test_eof288;
case 288:
#line 9409 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr622;
		case 9: goto tr623;
		case 10: goto tr624;
		case 13: goto tr625;
		case 32: goto tr623;
		case 35: goto tr249;
		case 59: goto tr622;
		case 123: goto tr617;
	}
	goto tr621;
tr621:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 907; goto st22;} }
	goto st907;
tr625:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 907; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st907;
st907:
	if ( ++p == pe )
		goto _test_eof907;
case 907:
#line 9440 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1837;
		case 10: goto tr620;
		case 13: goto tr1838;
		case 32: goto tr1837;
		case 34: goto tr571;
		case 35: goto tr1839;
		case 59: goto st0;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr240;
		case 125: goto tr1778;
	}
	goto tr241;
tr626:
#line 141 "confscanner.rl"
	{line++;}
	goto st289;
tr629:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 289; goto st22;} }
	goto st289;
tr564:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st289;
tr630:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st289;
tr632:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 289; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st289;
tr1075:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 289; goto st22;} }
#line 141 "confscanner.rl"
	{line++;}
	goto st289;
st289:
	if ( ++p == pe )
		goto _test_eof289;
case 289:
#line 9516 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st266;
		case 10: goto tr626;
		case 13: goto st290;
		case 32: goto st266;
		case 34: goto st79;
		case 35: goto st291;
		case 123: goto tr246;
	}
	goto st0;
st290:
	if ( ++p == pe )
		goto _test_eof290;
case 290:
	if ( (*p) == 10 )
		goto tr626;
	goto st0;
st291:
	if ( ++p == pe )
		goto _test_eof291;
case 291:
	if ( (*p) == 35 )
		goto st0;
	goto tr629;
tr565:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st292;
st292:
	if ( ++p == pe )
		goto _test_eof292;
case 292:
#line 9554 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr630;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr567:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st293;
st293:
	if ( ++p == pe )
		goto _test_eof293;
case 293:
#line 9579 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr629;
		case 9: goto tr614;
		case 10: goto tr632;
		case 13: goto tr633;
		case 32: goto tr614;
		case 35: goto tr249;
		case 59: goto tr629;
		case 123: goto tr634;
	}
	goto tr631;
tr633:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 294; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st294;
st294:
	if ( ++p == pe )
		goto _test_eof294;
case 294:
#line 9606 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr563;
		case 10: goto tr630;
		case 13: goto tr565;
		case 32: goto tr563;
		case 34: goto st268;
		case 35: goto tr567;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr635:
#line 141 "confscanner.rl"
	{line++;}
	goto st908;
tr636:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 908; goto st22;} }
	goto st908;
tr634:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 908; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 908; goto st886;} }
	goto st908;
tr1077:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 908; goto st22;} }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 908; goto st886;} }
	goto st908;
st908:
	if ( ++p == pe )
		goto _test_eof908;
case 908:
#line 9657 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st906;
		case 10: goto tr635;
		case 13: goto st295;
		case 32: goto st906;
		case 34: goto st79;
		case 35: goto st296;
		case 97: goto st27;
		case 103: goto st127;
		case 123: goto tr246;
		case 125: goto tr1769;
	}
	goto st0;
st295:
	if ( ++p == pe )
		goto _test_eof295;
case 295:
	if ( (*p) == 10 )
		goto tr635;
	goto st0;
st296:
	if ( ++p == pe )
		goto _test_eof296;
case 296:
	if ( (*p) == 35 )
		goto st0;
	goto tr636;
tr1843:
#line 141 "confscanner.rl"
	{line++;}
	goto st909;
tr639:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 909; goto st22;} }
	goto st909;
tr1846:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st909;
tr637:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st909;
tr640:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 909; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st909;
tr641:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 909; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st909;
tr558:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 909; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 909; goto st886;} }
	goto st909;
st909:
	if ( ++p == pe )
		goto _test_eof909;
case 909:
#line 9754 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st909;
		case 10: goto tr1843;
		case 13: goto tr1844;
		case 32: goto st909;
		case 35: goto tr1845;
		case 59: goto st0;
		case 61: goto tr551;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr246;
		case 125: goto tr1778;
	}
	goto tr241;
tr1844:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st297;
tr1847:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st297;
st297:
	if ( ++p == pe )
		goto _test_eof297;
case 297:
#line 9789 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr637;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1845:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st298;
tr1848:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st298;
st298:
	if ( ++p == pe )
		goto _test_eof298;
case 298:
#line 9820 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr639;
		case 9: goto tr640;
		case 10: goto tr641;
		case 13: goto tr642;
		case 32: goto tr640;
		case 35: goto tr249;
		case 59: goto tr639;
		case 123: goto tr558;
	}
	goto tr638;
tr638:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 910; goto st22;} }
	goto st910;
tr642:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 910; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st910;
st910:
	if ( ++p == pe )
		goto _test_eof910;
case 910:
#line 9851 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1846;
		case 10: goto tr637;
		case 13: goto tr1847;
		case 32: goto tr1846;
		case 35: goto tr1848;
		case 59: goto st0;
		case 61: goto tr551;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr240;
		case 125: goto tr1778;
	}
	goto tr241;
tr643:
#line 141 "confscanner.rl"
	{line++;}
	goto st299;
tr646:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 299; goto st22;} }
	goto st299;
tr652:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st299;
tr647:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st299;
tr649:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 299; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st299;
tr1053:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 299; goto st22;} }
#line 141 "confscanner.rl"
	{line++;}
	goto st299;
tr542:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
#line 108 "confscanner.rl"
	{
    string s(tmp_p, p-tmp_p);
    cblock_ = &((*clistmap_)[tmp_string][s]);
  }
	goto st299;
st299:
	if ( ++p == pe )
		goto _test_eof299;
case 299:
#line 9943 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st260;
		case 10: goto tr643;
		case 13: goto st300;
		case 32: goto st260;
		case 35: goto st301;
		case 61: goto st76;
		case 123: goto tr246;
	}
	goto st0;
st300:
	if ( ++p == pe )
		goto _test_eof300;
case 300:
	if ( (*p) == 10 )
		goto tr643;
	goto st0;
st301:
	if ( ++p == pe )
		goto _test_eof301;
case 301:
	if ( (*p) == 35 )
		goto st0;
	goto tr646;
tr653:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st302;
tr543:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 108 "confscanner.rl"
	{
    string s(tmp_p, p-tmp_p);
    cblock_ = &((*clistmap_)[tmp_string][s]);
  }
	goto st302;
st302:
	if ( ++p == pe )
		goto _test_eof302;
case 302:
#line 9995 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr647;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr654:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st303;
tr544:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 108 "confscanner.rl"
	{
    string s(tmp_p, p-tmp_p);
    cblock_ = &((*clistmap_)[tmp_string][s]);
  }
	goto st303;
st303:
	if ( ++p == pe )
		goto _test_eof303;
case 303:
#line 10034 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr646;
		case 9: goto tr555;
		case 10: goto tr649;
		case 13: goto tr650;
		case 32: goto tr555;
		case 35: goto tr249;
		case 59: goto tr646;
		case 123: goto tr651;
	}
	goto tr648;
tr648:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 304; goto st22;} }
	goto st304;
st304:
	if ( ++p == pe )
		goto _test_eof304;
case 304:
#line 10054 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr559;
		case 10: goto tr652;
		case 13: goto tr653;
		case 32: goto tr559;
		case 35: goto tr654;
		case 59: goto st0;
		case 61: goto st264;
		case 123: goto tr240;
	}
	goto st136;
tr650:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 305; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st305;
st305:
	if ( ++p == pe )
		goto _test_eof305;
case 305:
#line 10082 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr559;
		case 10: goto tr647;
		case 13: goto tr653;
		case 32: goto tr559;
		case 35: goto tr654;
		case 59: goto st0;
		case 61: goto st264;
		case 123: goto tr240;
	}
	goto st136;
tr656:
#line 141 "confscanner.rl"
	{line++;}
	goto st911;
tr657:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 911; goto st22;} }
	goto st911;
tr651:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 911; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 911; goto st886;} }
	goto st911;
tr1055:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 911; goto st22;} }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 911; goto st886;} }
	goto st911;
st911:
	if ( ++p == pe )
		goto _test_eof911;
case 911:
#line 10133 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st909;
		case 10: goto tr656;
		case 13: goto st306;
		case 32: goto st909;
		case 35: goto st307;
		case 61: goto st76;
		case 97: goto st27;
		case 103: goto st127;
		case 123: goto tr246;
		case 125: goto tr1769;
	}
	goto st0;
st306:
	if ( ++p == pe )
		goto _test_eof306;
case 306:
	if ( (*p) == 10 )
		goto tr656;
	goto st0;
st307:
	if ( ++p == pe )
		goto _test_eof307;
case 307:
	if ( (*p) == 35 )
		goto st0;
	goto tr657;
tr1852:
#line 141 "confscanner.rl"
	{line++;}
	goto st912;
tr660:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 912; goto st22;} }
	goto st912;
tr1857:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st912;
tr658:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st912;
tr661:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 912; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st912;
tr662:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 912; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st912;
tr535:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 912; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 912; goto st886;} }
	goto st912;
st912:
	if ( ++p == pe )
		goto _test_eof912;
case 912:
#line 10230 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st912;
		case 10: goto tr1852;
		case 13: goto tr1853;
		case 32: goto st912;
		case 35: goto tr1854;
		case 59: goto st0;
		case 97: goto tr1855;
		case 103: goto tr1856;
		case 123: goto tr246;
		case 125: goto tr1778;
	}
	if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr528;
	} else if ( (*p) >= 65 )
		goto tr528;
	goto tr241;
tr1853:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st308;
tr1858:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st308;
st308:
	if ( ++p == pe )
		goto _test_eof308;
case 308:
#line 10269 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr658;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1854:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st309;
tr1859:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st309;
st309:
	if ( ++p == pe )
		goto _test_eof309;
case 309:
#line 10300 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr660;
		case 9: goto tr661;
		case 10: goto tr662;
		case 13: goto tr663;
		case 32: goto tr661;
		case 35: goto tr249;
		case 59: goto tr660;
		case 123: goto tr535;
	}
	goto tr659;
tr659:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 913; goto st22;} }
	goto st913;
tr663:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 913; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st913;
st913:
	if ( ++p == pe )
		goto _test_eof913;
case 913:
#line 10331 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1857;
		case 10: goto tr658;
		case 13: goto tr1858;
		case 32: goto tr1857;
		case 35: goto tr1859;
		case 59: goto st0;
		case 97: goto tr1855;
		case 103: goto tr1856;
		case 123: goto tr240;
		case 125: goto tr1778;
	}
	if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr528;
	} else if ( (*p) >= 65 )
		goto tr528;
	goto tr241;
tr1855:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 192 "confscanner.rl"
	{tmp_p = p;/* cerr << "dlmi\n";*/}
	goto st310;
st310:
	if ( ++p == pe )
		goto _test_eof310;
case 310:
#line 10361 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 46: goto tr538;
		case 59: goto st0;
		case 95: goto st257;
		case 100: goto st311;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st257;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st257;
	} else
		goto st257;
	goto st136;
st311:
	if ( ++p == pe )
		goto _test_eof311;
case 311:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 46: goto tr538;
		case 59: goto st0;
		case 95: goto st257;
		case 100: goto st312;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st257;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st257;
	} else
		goto st257;
	goto st136;
st312:
	if ( ++p == pe )
		goto _test_eof312;
case 312:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 40: goto st147;
		case 46: goto tr538;
		case 59: goto st0;
		case 95: goto st257;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st257;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st257;
	} else
		goto st257;
	goto st136;
tr1856:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 192 "confscanner.rl"
	{tmp_p = p;/* cerr << "dlmi\n";*/}
	goto st313;
st313:
	if ( ++p == pe )
		goto _test_eof313;
case 313:
#line 10446 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 46: goto tr538;
		case 59: goto st0;
		case 95: goto st257;
		case 108: goto st314;
		case 114: goto st326;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st257;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st257;
	} else
		goto st257;
	goto st136;
st314:
	if ( ++p == pe )
		goto _test_eof314;
case 314:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 46: goto tr538;
		case 59: goto st0;
		case 95: goto st257;
		case 111: goto st315;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st257;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st257;
	} else
		goto st257;
	goto st136;
st315:
	if ( ++p == pe )
		goto _test_eof315;
case 315:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 46: goto tr538;
		case 59: goto st0;
		case 95: goto st257;
		case 98: goto st316;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st257;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st257;
	} else
		goto st257;
	goto st136;
st316:
	if ( ++p == pe )
		goto _test_eof316;
case 316:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr342;
		case 10: goto tr343;
		case 13: goto tr344;
		case 32: goto tr342;
		case 35: goto tr345;
		case 46: goto tr538;
		case 59: goto st0;
		case 61: goto st179;
		case 95: goto st257;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st257;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st257;
	} else
		goto st257;
	goto st136;
tr670:
#line 141 "confscanner.rl"
	{line++;}
	goto st317;
tr673:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 317; goto st22;} }
	goto st317;
tr343:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st317;
tr675:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 317; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st317;
st317:
	if ( ++p == pe )
		goto _test_eof317;
case 317:
#line 10584 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st175;
		case 10: goto tr670;
		case 13: goto st318;
		case 32: goto st175;
		case 35: goto st319;
		case 61: goto st133;
		case 123: goto tr246;
	}
	goto st0;
st318:
	if ( ++p == pe )
		goto _test_eof318;
case 318:
	if ( (*p) == 10 )
		goto tr670;
	goto st0;
st319:
	if ( ++p == pe )
		goto _test_eof319;
case 319:
	if ( (*p) == 35 )
		goto st0;
	goto tr673;
tr344:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st320;
st320:
	if ( ++p == pe )
		goto _test_eof320;
case 320:
#line 10622 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr343;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr345:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st321;
st321:
	if ( ++p == pe )
		goto _test_eof321;
case 321:
#line 10647 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr673;
		case 9: goto tr355;
		case 10: goto tr675;
		case 13: goto tr676;
		case 32: goto tr355;
		case 35: goto tr249;
		case 59: goto tr673;
		case 123: goto tr677;
	}
	goto tr674;
tr684:
#line 141 "confscanner.rl"
	{line++;}
	goto st914;
tr685:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 914; goto st22;} }
	goto st914;
tr677:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 914; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 914; goto st886;} }
	goto st914;
st914:
	if ( ++p == pe )
		goto _test_eof914;
case 914:
#line 10684 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st915;
		case 10: goto tr684;
		case 13: goto st324;
		case 32: goto st915;
		case 35: goto st325;
		case 61: goto st133;
		case 97: goto st27;
		case 103: goto st127;
		case 123: goto tr246;
		case 125: goto tr1769;
	}
	goto st0;
tr1863:
#line 141 "confscanner.rl"
	{line++;}
	goto st915;
tr680:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 915; goto st22;} }
	goto st915;
tr1866:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st915;
tr678:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st915;
tr681:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 915; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st915;
tr682:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 915; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st915;
tr358:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 915; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 915; goto st886;} }
	goto st915;
st915:
	if ( ++p == pe )
		goto _test_eof915;
case 915:
#line 10767 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st915;
		case 10: goto tr1863;
		case 13: goto tr1864;
		case 32: goto st915;
		case 35: goto tr1865;
		case 59: goto st0;
		case 61: goto tr351;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr246;
		case 125: goto tr1778;
	}
	goto tr241;
tr1864:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st322;
tr1867:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st322;
st322:
	if ( ++p == pe )
		goto _test_eof322;
case 322:
#line 10802 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr678;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1865:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st323;
tr1868:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st323;
st323:
	if ( ++p == pe )
		goto _test_eof323;
case 323:
#line 10833 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr680;
		case 9: goto tr681;
		case 10: goto tr682;
		case 13: goto tr683;
		case 32: goto tr681;
		case 35: goto tr249;
		case 59: goto tr680;
		case 123: goto tr358;
	}
	goto tr679;
tr679:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 916; goto st22;} }
	goto st916;
tr683:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 916; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st916;
st916:
	if ( ++p == pe )
		goto _test_eof916;
case 916:
#line 10864 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1866;
		case 10: goto tr678;
		case 13: goto tr1867;
		case 32: goto tr1866;
		case 35: goto tr1868;
		case 59: goto st0;
		case 61: goto tr351;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr240;
		case 125: goto tr1778;
	}
	goto tr241;
st324:
	if ( ++p == pe )
		goto _test_eof324;
case 324:
	if ( (*p) == 10 )
		goto tr684;
	goto st0;
st325:
	if ( ++p == pe )
		goto _test_eof325;
case 325:
	if ( (*p) == 35 )
		goto st0;
	goto tr685;
st326:
	if ( ++p == pe )
		goto _test_eof326;
case 326:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 46: goto tr538;
		case 59: goto st0;
		case 95: goto st257;
		case 111: goto st327;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st257;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st257;
	} else
		goto st257;
	goto st136;
st327:
	if ( ++p == pe )
		goto _test_eof327;
case 327:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 46: goto tr538;
		case 59: goto st0;
		case 95: goto st257;
		case 117: goto st328;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st257;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st257;
	} else
		goto st257;
	goto st136;
st328:
	if ( ++p == pe )
		goto _test_eof328;
case 328:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 46: goto tr538;
		case 59: goto st0;
		case 95: goto st257;
		case 112: goto st329;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st257;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st257;
	} else
		goto st257;
	goto st136;
st329:
	if ( ++p == pe )
		goto _test_eof329;
case 329:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 46: goto tr538;
		case 59: goto st0;
		case 95: goto st257;
		case 115: goto st330;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st257;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st257;
	} else
		goto st257;
	goto st136;
st330:
	if ( ++p == pe )
		goto _test_eof330;
case 330:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr690;
		case 10: goto tr691;
		case 13: goto tr692;
		case 32: goto tr690;
		case 35: goto tr693;
		case 43: goto tr694;
		case 46: goto tr538;
		case 59: goto st0;
		case 61: goto st336;
		case 95: goto st257;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st257;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st257;
	} else
		goto st257;
	goto st136;
tr697:
#line 141 "confscanner.rl"
	{line++;}
	goto st331;
tr704:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 331; goto st22;} }
	goto st331;
tr690:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st331;
tr702:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st331;
tr705:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 331; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st331;
tr706:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 331; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st331;
tr1338:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 331; goto st22;} }
	goto st331;
st331:
	if ( ++p == pe )
		goto _test_eof331;
case 331:
#line 11092 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st331;
		case 10: goto tr697;
		case 13: goto tr698;
		case 32: goto st331;
		case 35: goto tr699;
		case 43: goto tr700;
		case 59: goto st0;
		case 61: goto tr701;
		case 123: goto tr246;
	}
	goto tr241;
tr698:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st332;
tr709:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st332;
st332:
	if ( ++p == pe )
		goto _test_eof332;
case 332:
#line 11125 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr702;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr699:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st333;
tr710:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st333;
st333:
	if ( ++p == pe )
		goto _test_eof333;
case 333:
#line 11156 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr704;
		case 9: goto tr705;
		case 10: goto tr706;
		case 13: goto tr707;
		case 32: goto tr705;
		case 35: goto tr249;
		case 59: goto tr704;
		case 123: goto tr708;
	}
	goto tr703;
tr703:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 334; goto st22;} }
	goto st334;
tr707:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 334; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st334;
st334:
	if ( ++p == pe )
		goto _test_eof334;
case 334:
#line 11187 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr690;
		case 10: goto tr702;
		case 13: goto tr709;
		case 32: goto tr690;
		case 35: goto tr710;
		case 43: goto tr700;
		case 59: goto st0;
		case 61: goto tr701;
		case 123: goto tr240;
	}
	goto tr241;
tr694:
#line 146 "confscanner.rl"
	{arg_to_be_added_ = true;}
	goto st335;
tr700:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 146 "confscanner.rl"
	{arg_to_be_added_ = true;}
	goto st335;
st335:
	if ( ++p == pe )
		goto _test_eof335;
case 335:
#line 11215 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 61: goto st336;
		case 123: goto tr240;
	}
	goto st136;
tr851:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 336; goto st22;} }
	goto st336;
tr701:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st336;
st336:
	if ( ++p == pe )
		goto _test_eof336;
case 336:
#line 11240 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr711;
		case 10: goto tr712;
		case 13: goto tr713;
		case 32: goto tr711;
		case 35: goto tr714;
		case 59: goto st0;
		case 123: goto tr240;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr715;
	} else if ( (*p) >= 65 )
		goto tr715;
	goto st136;
tr717:
#line 141 "confscanner.rl"
	{line++;}
	goto st337;
tr723:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 337; goto st22;} }
	goto st337;
tr711:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st337;
tr721:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st337;
tr724:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 337; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st337;
tr725:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 337; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st337;
tr1346:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 337; goto st22;} }
	goto st337;
st337:
	if ( ++p == pe )
		goto _test_eof337;
case 337:
#line 11324 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st337;
		case 10: goto tr717;
		case 13: goto tr718;
		case 32: goto st337;
		case 35: goto tr719;
		case 59: goto st0;
		case 123: goto tr246;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr720;
	} else if ( (*p) >= 65 )
		goto tr720;
	goto tr241;
tr718:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st338;
tr728:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st338;
st338:
	if ( ++p == pe )
		goto _test_eof338;
case 338:
#line 11360 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr721;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr719:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st339;
tr729:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st339;
st339:
	if ( ++p == pe )
		goto _test_eof339;
case 339:
#line 11391 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr723;
		case 9: goto tr724;
		case 10: goto tr725;
		case 13: goto tr726;
		case 32: goto tr724;
		case 35: goto tr249;
		case 59: goto tr723;
		case 123: goto tr727;
	}
	goto tr722;
tr722:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 340; goto st22;} }
	goto st340;
tr726:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 340; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st340;
st340:
	if ( ++p == pe )
		goto _test_eof340;
case 340:
#line 11422 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr711;
		case 10: goto tr721;
		case 13: goto tr728;
		case 32: goto tr711;
		case 35: goto tr729;
		case 59: goto st0;
		case 123: goto tr240;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr720;
	} else if ( (*p) >= 65 )
		goto tr720;
	goto tr241;
tr715:
#line 20 "confscanner.rl"
	{ /*cerr << "st_tok" << line << "\n";*/ tmp_p = p; }
	goto st341;
tr720:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 20 "confscanner.rl"
	{ /*cerr << "st_tok" << line << "\n";*/ tmp_p = p; }
	goto st341;
st341:
	if ( ++p == pe )
		goto _test_eof341;
case 341:
#line 11453 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr730;
		case 10: goto tr731;
		case 13: goto tr732;
		case 32: goto tr730;
		case 35: goto tr733;
		case 44: goto tr734;
		case 59: goto tr736;
		case 95: goto st341;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st341;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st341;
	} else
		goto st341;
	goto st136;
tr317:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st342;
tr732:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 27 "confscanner.rl"
	{
//    cerr << "in group add: " << endl;
    if(match_at_level_[level_])
    {
//      cerr << "do it" << endl;
      tmp_string.assign(tmp_p, p-tmp_p);
      // clear groupset_ first, if we did not use '+='
      if(!arg_to_be_added_)
        groupset_.clear();

      groupset_.insert(tmp_string);
    }
  }
	goto st342;
st342:
	if ( ++p == pe )
		goto _test_eof342;
case 342:
#line 11511 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr737;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr318:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st343;
tr733:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 27 "confscanner.rl"
	{
//    cerr << "in group add: " << endl;
    if(match_at_level_[level_])
    {
//      cerr << "do it" << endl;
      tmp_string.assign(tmp_p, p-tmp_p);
      // clear groupset_ first, if we did not use '+='
      if(!arg_to_be_added_)
        groupset_.clear();

      groupset_.insert(tmp_string);
    }
  }
	goto st343;
st343:
	if ( ++p == pe )
		goto _test_eof343;
case 343:
#line 11559 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr444;
		case 9: goto tr326;
		case 10: goto tr739;
		case 13: goto tr740;
		case 32: goto tr326;
		case 35: goto tr249;
		case 59: goto tr444;
		case 123: goto tr741;
	}
	goto tr738;
tr740:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 344; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st344;
st344:
	if ( ++p == pe )
		goto _test_eof344;
case 344:
#line 11586 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr315;
		case 10: goto tr737;
		case 13: goto tr317;
		case 32: goto tr315;
		case 35: goto tr318;
		case 59: goto tr89;
		case 123: goto tr240;
	}
	goto st136;
tr734:
#line 27 "confscanner.rl"
	{
//    cerr << "in group add: " << endl;
    if(match_at_level_[level_])
    {
//      cerr << "do it" << endl;
      tmp_string.assign(tmp_p, p-tmp_p);
      // clear groupset_ first, if we did not use '+='
      if(!arg_to_be_added_)
        groupset_.clear();

      groupset_.insert(tmp_string);
    }
  }
	goto st345;
st345:
	if ( ++p == pe )
		goto _test_eof345;
case 345:
#line 11618 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr715;
	} else if ( (*p) >= 65 )
		goto tr715;
	goto st136;
tr1870:
#line 141 "confscanner.rl"
	{line++;}
	goto st917;
tr744:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 917; goto st22;} }
	goto st917;
tr1875:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st917;
tr742:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st917;
tr745:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 917; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st917;
tr746:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 917; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st917;
tr727:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 917; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 917; goto st886;} }
	goto st917;
st917:
	if ( ++p == pe )
		goto _test_eof917;
case 917:
#line 11704 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st917;
		case 10: goto tr1870;
		case 13: goto tr1871;
		case 32: goto st917;
		case 35: goto tr1872;
		case 59: goto st0;
		case 97: goto tr1873;
		case 103: goto tr1874;
		case 123: goto tr246;
		case 125: goto tr1778;
	}
	if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr720;
	} else if ( (*p) >= 65 )
		goto tr720;
	goto tr241;
tr1871:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st346;
tr1876:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st346;
st346:
	if ( ++p == pe )
		goto _test_eof346;
case 346:
#line 11743 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr742;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1872:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st347;
tr1877:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st347;
st347:
	if ( ++p == pe )
		goto _test_eof347;
case 347:
#line 11774 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr744;
		case 9: goto tr745;
		case 10: goto tr746;
		case 13: goto tr747;
		case 32: goto tr745;
		case 35: goto tr249;
		case 59: goto tr744;
		case 123: goto tr727;
	}
	goto tr743;
tr743:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 918; goto st22;} }
	goto st918;
tr747:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 918; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st918;
st918:
	if ( ++p == pe )
		goto _test_eof918;
case 918:
#line 11805 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1875;
		case 10: goto tr742;
		case 13: goto tr1876;
		case 32: goto tr1875;
		case 35: goto tr1877;
		case 59: goto st0;
		case 97: goto tr1873;
		case 103: goto tr1874;
		case 123: goto tr240;
		case 125: goto tr1778;
	}
	if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr720;
	} else if ( (*p) >= 65 )
		goto tr720;
	goto tr241;
tr1873:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 20 "confscanner.rl"
	{ /*cerr << "st_tok" << line << "\n";*/ tmp_p = p; }
	goto st348;
st348:
	if ( ++p == pe )
		goto _test_eof348;
case 348:
#line 11835 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr730;
		case 10: goto tr731;
		case 13: goto tr732;
		case 32: goto tr730;
		case 35: goto tr733;
		case 44: goto tr734;
		case 59: goto tr736;
		case 95: goto st341;
		case 100: goto st349;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st341;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st341;
	} else
		goto st341;
	goto st136;
st349:
	if ( ++p == pe )
		goto _test_eof349;
case 349:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr730;
		case 10: goto tr731;
		case 13: goto tr732;
		case 32: goto tr730;
		case 35: goto tr733;
		case 44: goto tr734;
		case 59: goto tr736;
		case 95: goto st341;
		case 100: goto st350;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st341;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st341;
	} else
		goto st341;
	goto st136;
st350:
	if ( ++p == pe )
		goto _test_eof350;
case 350:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr730;
		case 10: goto tr731;
		case 13: goto tr732;
		case 32: goto tr730;
		case 35: goto tr733;
		case 40: goto st147;
		case 44: goto tr734;
		case 59: goto tr736;
		case 95: goto st341;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st341;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st341;
	} else
		goto st341;
	goto st136;
tr1874:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 20 "confscanner.rl"
	{ /*cerr << "st_tok" << line << "\n";*/ tmp_p = p; }
	goto st351;
st351:
	if ( ++p == pe )
		goto _test_eof351;
case 351:
#line 11920 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr730;
		case 10: goto tr731;
		case 13: goto tr732;
		case 32: goto tr730;
		case 35: goto tr733;
		case 44: goto tr734;
		case 59: goto tr736;
		case 95: goto st341;
		case 108: goto st352;
		case 114: goto st369;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st341;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st341;
	} else
		goto st341;
	goto st136;
st352:
	if ( ++p == pe )
		goto _test_eof352;
case 352:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr730;
		case 10: goto tr731;
		case 13: goto tr732;
		case 32: goto tr730;
		case 35: goto tr733;
		case 44: goto tr734;
		case 59: goto tr736;
		case 95: goto st341;
		case 111: goto st353;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st341;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st341;
	} else
		goto st341;
	goto st136;
st353:
	if ( ++p == pe )
		goto _test_eof353;
case 353:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr730;
		case 10: goto tr731;
		case 13: goto tr732;
		case 32: goto tr730;
		case 35: goto tr733;
		case 44: goto tr734;
		case 59: goto tr736;
		case 95: goto st341;
		case 98: goto st354;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st341;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st341;
	} else
		goto st341;
	goto st136;
st354:
	if ( ++p == pe )
		goto _test_eof354;
case 354:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr754;
		case 10: goto tr755;
		case 13: goto tr756;
		case 32: goto tr754;
		case 35: goto tr757;
		case 44: goto tr734;
		case 59: goto tr736;
		case 61: goto st179;
		case 95: goto st341;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st341;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st341;
	} else
		goto st341;
	goto st136;
tr759:
#line 141 "confscanner.rl"
	{line++;}
	goto st355;
tr764:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 355; goto st22;} }
	goto st355;
tr769:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st355;
tr762:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st355;
tr765:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 355; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st355;
tr766:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 355; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st355;
tr754:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 27 "confscanner.rl"
	{
//    cerr << "in group add: " << endl;
    if(match_at_level_[level_])
    {
//      cerr << "do it" << endl;
      tmp_string.assign(tmp_p, p-tmp_p);
      // clear groupset_ first, if we did not use '+='
      if(!arg_to_be_added_)
        groupset_.clear();

      groupset_.insert(tmp_string);
    }
  }
	goto st355;
st355:
	if ( ++p == pe )
		goto _test_eof355;
case 355:
#line 12101 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st355;
		case 10: goto tr759;
		case 13: goto tr760;
		case 32: goto st355;
		case 35: goto tr761;
		case 59: goto tr89;
		case 61: goto tr351;
		case 123: goto tr246;
	}
	goto tr241;
tr760:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st356;
tr770:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st356;
st356:
	if ( ++p == pe )
		goto _test_eof356;
case 356:
#line 12133 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr762;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr761:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st357;
tr771:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st357;
st357:
	if ( ++p == pe )
		goto _test_eof357;
case 357:
#line 12164 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr764;
		case 9: goto tr765;
		case 10: goto tr766;
		case 13: goto tr767;
		case 32: goto tr765;
		case 35: goto tr249;
		case 59: goto tr764;
		case 123: goto tr768;
	}
	goto tr763;
tr763:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 358; goto st22;} }
	goto st358;
tr767:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 358; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st358;
st358:
	if ( ++p == pe )
		goto _test_eof358;
case 358:
#line 12195 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr769;
		case 10: goto tr762;
		case 13: goto tr770;
		case 32: goto tr769;
		case 35: goto tr771;
		case 59: goto tr89;
		case 61: goto tr351;
		case 123: goto tr240;
	}
	goto tr241;
tr1879:
#line 141 "confscanner.rl"
	{line++;}
	goto st919;
tr774:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 919; goto st22;} }
	goto st919;
tr1882:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st919;
tr772:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st919;
tr775:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 919; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st919;
tr776:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 919; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st919;
tr768:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 919; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 919; goto st886;} }
	goto st919;
st919:
	if ( ++p == pe )
		goto _test_eof919;
case 919:
#line 12277 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st919;
		case 10: goto tr1879;
		case 13: goto tr1880;
		case 32: goto st919;
		case 35: goto tr1881;
		case 59: goto tr89;
		case 61: goto tr351;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr246;
		case 125: goto tr1778;
	}
	goto tr241;
tr1880:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st359;
tr1883:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st359;
st359:
	if ( ++p == pe )
		goto _test_eof359;
case 359:
#line 12312 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr772;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1881:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st360;
tr1884:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st360;
st360:
	if ( ++p == pe )
		goto _test_eof360;
case 360:
#line 12343 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr774;
		case 9: goto tr775;
		case 10: goto tr776;
		case 13: goto tr777;
		case 32: goto tr775;
		case 35: goto tr249;
		case 59: goto tr774;
		case 123: goto tr768;
	}
	goto tr773;
tr773:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 920; goto st22;} }
	goto st920;
tr777:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 920; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st920;
st920:
	if ( ++p == pe )
		goto _test_eof920;
case 920:
#line 12374 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1882;
		case 10: goto tr772;
		case 13: goto tr1883;
		case 32: goto tr1882;
		case 35: goto tr1884;
		case 59: goto tr89;
		case 61: goto tr351;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr240;
		case 125: goto tr1778;
	}
	goto tr241;
tr778:
#line 141 "confscanner.rl"
	{line++;}
	goto st361;
tr781:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 361; goto st22;} }
	goto st361;
tr782:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st361;
tr784:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 361; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st361;
tr755:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 27 "confscanner.rl"
	{
//    cerr << "in group add: " << endl;
    if(match_at_level_[level_])
    {
//      cerr << "do it" << endl;
      tmp_string.assign(tmp_p, p-tmp_p);
      // clear groupset_ first, if we did not use '+='
      if(!arg_to_be_added_)
        groupset_.clear();

      groupset_.insert(tmp_string);
    }
  }
	goto st361;
st361:
	if ( ++p == pe )
		goto _test_eof361;
case 361:
#line 12451 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st355;
		case 10: goto tr778;
		case 13: goto st362;
		case 32: goto st355;
		case 35: goto st363;
		case 59: goto tr89;
		case 61: goto st133;
		case 123: goto tr246;
	}
	goto st0;
st362:
	if ( ++p == pe )
		goto _test_eof362;
case 362:
	if ( (*p) == 10 )
		goto tr778;
	goto st0;
st363:
	if ( ++p == pe )
		goto _test_eof363;
case 363:
	if ( (*p) == 35 )
		goto st0;
	goto tr781;
tr787:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st364;
tr756:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 27 "confscanner.rl"
	{
//    cerr << "in group add: " << endl;
    if(match_at_level_[level_])
    {
//      cerr << "do it" << endl;
      tmp_string.assign(tmp_p, p-tmp_p);
      // clear groupset_ first, if we did not use '+='
      if(!arg_to_be_added_)
        groupset_.clear();

      groupset_.insert(tmp_string);
    }
  }
	goto st364;
st364:
	if ( ++p == pe )
		goto _test_eof364;
case 364:
#line 12513 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr782;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr788:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st365;
tr757:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 27 "confscanner.rl"
	{
//    cerr << "in group add: " << endl;
    if(match_at_level_[level_])
    {
//      cerr << "do it" << endl;
      tmp_string.assign(tmp_p, p-tmp_p);
      // clear groupset_ first, if we did not use '+='
      if(!arg_to_be_added_)
        groupset_.clear();

      groupset_.insert(tmp_string);
    }
  }
	goto st365;
st365:
	if ( ++p == pe )
		goto _test_eof365;
case 365:
#line 12561 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr781;
		case 9: goto tr765;
		case 10: goto tr784;
		case 13: goto tr785;
		case 32: goto tr765;
		case 35: goto tr249;
		case 59: goto tr781;
		case 123: goto tr786;
	}
	goto tr783;
tr783:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 366; goto st22;} }
	goto st366;
tr785:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 366; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st366;
st366:
	if ( ++p == pe )
		goto _test_eof366;
case 366:
#line 12592 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr769;
		case 10: goto tr782;
		case 13: goto tr787;
		case 32: goto tr769;
		case 35: goto tr788;
		case 59: goto tr89;
		case 61: goto st179;
		case 123: goto tr240;
	}
	goto st136;
tr789:
#line 141 "confscanner.rl"
	{line++;}
	goto st921;
tr790:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 921; goto st22;} }
	goto st921;
tr786:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 921; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 921; goto st886;} }
	goto st921;
st921:
	if ( ++p == pe )
		goto _test_eof921;
case 921:
#line 12630 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st919;
		case 10: goto tr789;
		case 13: goto st367;
		case 32: goto st919;
		case 35: goto st368;
		case 59: goto tr89;
		case 61: goto st133;
		case 97: goto st27;
		case 103: goto st127;
		case 123: goto tr246;
		case 125: goto tr1769;
	}
	goto st0;
st367:
	if ( ++p == pe )
		goto _test_eof367;
case 367:
	if ( (*p) == 10 )
		goto tr789;
	goto st0;
st368:
	if ( ++p == pe )
		goto _test_eof368;
case 368:
	if ( (*p) == 35 )
		goto st0;
	goto tr790;
st369:
	if ( ++p == pe )
		goto _test_eof369;
case 369:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr730;
		case 10: goto tr731;
		case 13: goto tr732;
		case 32: goto tr730;
		case 35: goto tr733;
		case 44: goto tr734;
		case 59: goto tr736;
		case 95: goto st341;
		case 111: goto st370;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st341;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st341;
	} else
		goto st341;
	goto st136;
st370:
	if ( ++p == pe )
		goto _test_eof370;
case 370:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr730;
		case 10: goto tr731;
		case 13: goto tr732;
		case 32: goto tr730;
		case 35: goto tr733;
		case 44: goto tr734;
		case 59: goto tr736;
		case 95: goto st341;
		case 117: goto st371;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st341;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st341;
	} else
		goto st341;
	goto st136;
st371:
	if ( ++p == pe )
		goto _test_eof371;
case 371:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr730;
		case 10: goto tr731;
		case 13: goto tr732;
		case 32: goto tr730;
		case 35: goto tr733;
		case 44: goto tr734;
		case 59: goto tr736;
		case 95: goto st341;
		case 112: goto st372;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st341;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st341;
	} else
		goto st341;
	goto st136;
st372:
	if ( ++p == pe )
		goto _test_eof372;
case 372:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr730;
		case 10: goto tr731;
		case 13: goto tr732;
		case 32: goto tr730;
		case 35: goto tr733;
		case 44: goto tr734;
		case 59: goto tr736;
		case 95: goto st341;
		case 115: goto st373;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st341;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st341;
	} else
		goto st341;
	goto st136;
st373:
	if ( ++p == pe )
		goto _test_eof373;
case 373:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr795;
		case 10: goto tr796;
		case 13: goto tr797;
		case 32: goto tr795;
		case 35: goto tr798;
		case 43: goto tr694;
		case 44: goto tr734;
		case 59: goto tr736;
		case 61: goto st336;
		case 95: goto st341;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st341;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st341;
	} else
		goto st341;
	goto st136;
tr800:
#line 141 "confscanner.rl"
	{line++;}
	goto st374;
tr805:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 374; goto st22;} }
	goto st374;
tr810:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st374;
tr803:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st374;
tr806:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 374; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st374;
tr807:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 374; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st374;
tr795:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 27 "confscanner.rl"
	{
//    cerr << "in group add: " << endl;
    if(match_at_level_[level_])
    {
//      cerr << "do it" << endl;
      tmp_string.assign(tmp_p, p-tmp_p);
      // clear groupset_ first, if we did not use '+='
      if(!arg_to_be_added_)
        groupset_.clear();

      groupset_.insert(tmp_string);
    }
  }
	goto st374;
st374:
	if ( ++p == pe )
		goto _test_eof374;
case 374:
#line 12869 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st374;
		case 10: goto tr800;
		case 13: goto tr801;
		case 32: goto st374;
		case 35: goto tr802;
		case 43: goto tr700;
		case 59: goto tr89;
		case 61: goto tr701;
		case 123: goto tr246;
	}
	goto tr241;
tr801:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st375;
tr811:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st375;
st375:
	if ( ++p == pe )
		goto _test_eof375;
case 375:
#line 12902 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr803;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr802:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st376;
tr812:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st376;
st376:
	if ( ++p == pe )
		goto _test_eof376;
case 376:
#line 12933 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr805;
		case 9: goto tr806;
		case 10: goto tr807;
		case 13: goto tr808;
		case 32: goto tr806;
		case 35: goto tr249;
		case 59: goto tr805;
		case 123: goto tr809;
	}
	goto tr804;
tr804:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 377; goto st22;} }
	goto st377;
tr808:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 377; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st377;
st377:
	if ( ++p == pe )
		goto _test_eof377;
case 377:
#line 12964 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr810;
		case 10: goto tr803;
		case 13: goto tr811;
		case 32: goto tr810;
		case 35: goto tr812;
		case 43: goto tr700;
		case 59: goto tr89;
		case 61: goto tr701;
		case 123: goto tr240;
	}
	goto tr241;
tr1888:
#line 141 "confscanner.rl"
	{line++;}
	goto st922;
tr815:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 922; goto st22;} }
	goto st922;
tr1891:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st922;
tr813:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st922;
tr816:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 922; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st922;
tr817:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 922; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st922;
tr809:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 922; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 922; goto st886;} }
	goto st922;
st922:
	if ( ++p == pe )
		goto _test_eof922;
case 922:
#line 13047 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st922;
		case 10: goto tr1888;
		case 13: goto tr1889;
		case 32: goto st922;
		case 35: goto tr1890;
		case 43: goto tr700;
		case 59: goto tr89;
		case 61: goto tr701;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr246;
		case 125: goto tr1778;
	}
	goto tr241;
tr1889:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st378;
tr1892:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st378;
st378:
	if ( ++p == pe )
		goto _test_eof378;
case 378:
#line 13083 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr813;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1890:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st379;
tr1893:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st379;
st379:
	if ( ++p == pe )
		goto _test_eof379;
case 379:
#line 13114 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr815;
		case 9: goto tr816;
		case 10: goto tr817;
		case 13: goto tr818;
		case 32: goto tr816;
		case 35: goto tr249;
		case 59: goto tr815;
		case 123: goto tr809;
	}
	goto tr814;
tr814:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 923; goto st22;} }
	goto st923;
tr818:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 923; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st923;
st923:
	if ( ++p == pe )
		goto _test_eof923;
case 923:
#line 13145 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1891;
		case 10: goto tr813;
		case 13: goto tr1892;
		case 32: goto tr1891;
		case 35: goto tr1893;
		case 43: goto tr700;
		case 59: goto tr89;
		case 61: goto tr701;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr240;
		case 125: goto tr1778;
	}
	goto tr241;
tr819:
#line 141 "confscanner.rl"
	{line++;}
	goto st380;
tr824:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 380; goto st22;} }
	goto st380;
tr841:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st380;
tr836:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st380;
tr838:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 380; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st380;
tr796:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
#line 27 "confscanner.rl"
	{
//    cerr << "in group add: " << endl;
    if(match_at_level_[level_])
    {
//      cerr << "do it" << endl;
      tmp_string.assign(tmp_p, p-tmp_p);
      // clear groupset_ first, if we did not use '+='
      if(!arg_to_be_added_)
        groupset_.clear();

      groupset_.insert(tmp_string);
    }
  }
	goto st380;
st380:
	if ( ++p == pe )
		goto _test_eof380;
case 380:
#line 13234 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st374;
		case 10: goto tr819;
		case 13: goto st381;
		case 32: goto st374;
		case 35: goto st382;
		case 43: goto tr822;
		case 59: goto tr89;
		case 61: goto st384;
		case 123: goto tr246;
	}
	goto st0;
st381:
	if ( ++p == pe )
		goto _test_eof381;
case 381:
	if ( (*p) == 10 )
		goto tr819;
	goto st0;
st382:
	if ( ++p == pe )
		goto _test_eof382;
case 382:
	if ( (*p) == 35 )
		goto st0;
	goto tr824;
tr822:
#line 146 "confscanner.rl"
	{arg_to_be_added_ = true;}
	goto st383;
st383:
	if ( ++p == pe )
		goto _test_eof383;
case 383:
#line 13269 "confscanner.cc"
	if ( (*p) == 61 )
		goto st384;
	goto st0;
tr825:
#line 141 "confscanner.rl"
	{line++;}
	goto st384;
tr829:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 384; goto st22;} }
	goto st384;
st384:
	if ( ++p == pe )
		goto _test_eof384;
case 384:
#line 13285 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st384;
		case 10: goto tr825;
		case 13: goto st385;
		case 32: goto st384;
		case 35: goto st386;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr828;
	} else if ( (*p) >= 65 )
		goto tr828;
	goto st0;
st385:
	if ( ++p == pe )
		goto _test_eof385;
case 385:
	if ( (*p) == 10 )
		goto tr825;
	goto st0;
st386:
	if ( ++p == pe )
		goto _test_eof386;
case 386:
	if ( (*p) == 35 )
		goto st0;
	goto tr829;
tr828:
#line 20 "confscanner.rl"
	{ /*cerr << "st_tok" << line << "\n";*/ tmp_p = p; }
	goto st387;
st387:
	if ( ++p == pe )
		goto _test_eof387;
case 387:
#line 13321 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto tr830;
		case 10: goto tr831;
		case 13: goto tr832;
		case 32: goto tr830;
		case 35: goto tr833;
		case 44: goto tr834;
		case 59: goto tr736;
		case 95: goto st387;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st387;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st387;
	} else
		goto st387;
	goto st0;
tr834:
#line 27 "confscanner.rl"
	{
//    cerr << "in group add: " << endl;
    if(match_at_level_[level_])
    {
//      cerr << "do it" << endl;
      tmp_string.assign(tmp_p, p-tmp_p);
      // clear groupset_ first, if we did not use '+='
      if(!arg_to_be_added_)
        groupset_.clear();

      groupset_.insert(tmp_string);
    }
  }
	goto st388;
st388:
	if ( ++p == pe )
		goto _test_eof388;
case 388:
#line 13361 "confscanner.cc"
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr828;
	} else if ( (*p) >= 65 )
		goto tr828;
	goto st0;
tr842:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st389;
tr797:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 27 "confscanner.rl"
	{
//    cerr << "in group add: " << endl;
    if(match_at_level_[level_])
    {
//      cerr << "do it" << endl;
      tmp_string.assign(tmp_p, p-tmp_p);
      // clear groupset_ first, if we did not use '+='
      if(!arg_to_be_added_)
        groupset_.clear();

      groupset_.insert(tmp_string);
    }
  }
	goto st389;
st389:
	if ( ++p == pe )
		goto _test_eof389;
case 389:
#line 13404 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr836;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr843:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st390;
tr798:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 27 "confscanner.rl"
	{
//    cerr << "in group add: " << endl;
    if(match_at_level_[level_])
    {
//      cerr << "do it" << endl;
      tmp_string.assign(tmp_p, p-tmp_p);
      // clear groupset_ first, if we did not use '+='
      if(!arg_to_be_added_)
        groupset_.clear();

      groupset_.insert(tmp_string);
    }
  }
	goto st390;
st390:
	if ( ++p == pe )
		goto _test_eof390;
case 390:
#line 13452 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr824;
		case 9: goto tr806;
		case 10: goto tr838;
		case 13: goto tr839;
		case 32: goto tr806;
		case 35: goto tr249;
		case 59: goto tr824;
		case 123: goto tr840;
	}
	goto tr837;
tr837:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 391; goto st22;} }
	goto st391;
st391:
	if ( ++p == pe )
		goto _test_eof391;
case 391:
#line 13472 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr810;
		case 10: goto tr841;
		case 13: goto tr842;
		case 32: goto tr810;
		case 35: goto tr843;
		case 43: goto tr694;
		case 59: goto tr89;
		case 61: goto st336;
		case 123: goto tr240;
	}
	goto st136;
tr839:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 392; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st392;
st392:
	if ( ++p == pe )
		goto _test_eof392;
case 392:
#line 13501 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr810;
		case 10: goto tr836;
		case 13: goto tr842;
		case 32: goto tr810;
		case 35: goto tr843;
		case 43: goto tr694;
		case 59: goto tr89;
		case 61: goto st336;
		case 123: goto tr240;
	}
	goto st136;
tr844:
#line 141 "confscanner.rl"
	{line++;}
	goto st924;
tr845:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 924; goto st22;} }
	goto st924;
tr840:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 924; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 924; goto st886;} }
	goto st924;
st924:
	if ( ++p == pe )
		goto _test_eof924;
case 924:
#line 13540 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st922;
		case 10: goto tr844;
		case 13: goto st393;
		case 32: goto st922;
		case 35: goto st394;
		case 43: goto tr822;
		case 59: goto tr89;
		case 61: goto st384;
		case 97: goto st27;
		case 103: goto st127;
		case 123: goto tr246;
		case 125: goto tr1769;
	}
	goto st0;
st393:
	if ( ++p == pe )
		goto _test_eof393;
case 393:
	if ( (*p) == 10 )
		goto tr844;
	goto st0;
st394:
	if ( ++p == pe )
		goto _test_eof394;
case 394:
	if ( (*p) == 35 )
		goto st0;
	goto tr845;
tr846:
#line 141 "confscanner.rl"
	{line++;}
	goto st395;
tr849:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 395; goto st22;} }
	goto st395;
tr712:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st395;
tr850:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st395;
tr852:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 395; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st395;
tr1347:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 395; goto st22;} }
#line 141 "confscanner.rl"
	{line++;}
	goto st395;
st395:
	if ( ++p == pe )
		goto _test_eof395;
case 395:
#line 13630 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st337;
		case 10: goto tr846;
		case 13: goto st396;
		case 32: goto st337;
		case 35: goto st397;
		case 123: goto tr246;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr828;
	} else if ( (*p) >= 65 )
		goto tr828;
	goto st0;
st396:
	if ( ++p == pe )
		goto _test_eof396;
case 396:
	if ( (*p) == 10 )
		goto tr846;
	goto st0;
st397:
	if ( ++p == pe )
		goto _test_eof397;
case 397:
	if ( (*p) == 35 )
		goto st0;
	goto tr849;
tr713:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st398;
st398:
	if ( ++p == pe )
		goto _test_eof398;
case 398:
#line 13672 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr850;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr714:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st399;
st399:
	if ( ++p == pe )
		goto _test_eof399;
case 399:
#line 13697 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr849;
		case 9: goto tr724;
		case 10: goto tr852;
		case 13: goto tr853;
		case 32: goto tr724;
		case 35: goto tr249;
		case 59: goto tr849;
		case 123: goto tr854;
	}
	goto tr851;
tr853:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 400; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st400;
st400:
	if ( ++p == pe )
		goto _test_eof400;
case 400:
#line 13724 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr711;
		case 10: goto tr850;
		case 13: goto tr713;
		case 32: goto tr711;
		case 35: goto tr714;
		case 59: goto st0;
		case 123: goto tr240;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr715;
	} else if ( (*p) >= 65 )
		goto tr715;
	goto st136;
tr855:
#line 141 "confscanner.rl"
	{line++;}
	goto st925;
tr856:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 925; goto st22;} }
	goto st925;
tr854:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 925; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 925; goto st886;} }
	goto st925;
tr1349:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 925; goto st22;} }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 925; goto st886;} }
	goto st925;
st925:
	if ( ++p == pe )
		goto _test_eof925;
case 925:
#line 13779 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st917;
		case 10: goto tr855;
		case 13: goto st401;
		case 32: goto st917;
		case 35: goto st402;
		case 97: goto tr1898;
		case 103: goto tr1899;
		case 123: goto tr246;
		case 125: goto tr1769;
	}
	if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr828;
	} else if ( (*p) >= 65 )
		goto tr828;
	goto st0;
st401:
	if ( ++p == pe )
		goto _test_eof401;
case 401:
	if ( (*p) == 10 )
		goto tr855;
	goto st0;
st402:
	if ( ++p == pe )
		goto _test_eof402;
case 402:
	if ( (*p) == 35 )
		goto st0;
	goto tr856;
tr1898:
#line 20 "confscanner.rl"
	{ /*cerr << "st_tok" << line << "\n";*/ tmp_p = p; }
	goto st403;
st403:
	if ( ++p == pe )
		goto _test_eof403;
case 403:
#line 13819 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto tr830;
		case 10: goto tr831;
		case 13: goto tr832;
		case 32: goto tr830;
		case 35: goto tr833;
		case 44: goto tr834;
		case 59: goto tr736;
		case 95: goto st387;
		case 100: goto st404;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st387;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st387;
	} else
		goto st387;
	goto st0;
st404:
	if ( ++p == pe )
		goto _test_eof404;
case 404:
	switch( (*p) ) {
		case 9: goto tr830;
		case 10: goto tr831;
		case 13: goto tr832;
		case 32: goto tr830;
		case 35: goto tr833;
		case 44: goto tr834;
		case 59: goto tr736;
		case 95: goto st387;
		case 100: goto st405;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st387;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st387;
	} else
		goto st387;
	goto st0;
st405:
	if ( ++p == pe )
		goto _test_eof405;
case 405:
	switch( (*p) ) {
		case 9: goto tr830;
		case 10: goto tr831;
		case 13: goto tr832;
		case 32: goto tr830;
		case 35: goto tr833;
		case 40: goto st30;
		case 44: goto tr834;
		case 59: goto tr736;
		case 95: goto st387;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st387;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st387;
	} else
		goto st387;
	goto st0;
tr1899:
#line 20 "confscanner.rl"
	{ /*cerr << "st_tok" << line << "\n";*/ tmp_p = p; }
	goto st406;
st406:
	if ( ++p == pe )
		goto _test_eof406;
case 406:
#line 13896 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto tr830;
		case 10: goto tr831;
		case 13: goto tr832;
		case 32: goto tr830;
		case 35: goto tr833;
		case 44: goto tr834;
		case 59: goto tr736;
		case 95: goto st387;
		case 108: goto st407;
		case 114: goto st413;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st387;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st387;
	} else
		goto st387;
	goto st0;
st407:
	if ( ++p == pe )
		goto _test_eof407;
case 407:
	switch( (*p) ) {
		case 9: goto tr830;
		case 10: goto tr831;
		case 13: goto tr832;
		case 32: goto tr830;
		case 35: goto tr833;
		case 44: goto tr834;
		case 59: goto tr736;
		case 95: goto st387;
		case 111: goto st408;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st387;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st387;
	} else
		goto st387;
	goto st0;
st408:
	if ( ++p == pe )
		goto _test_eof408;
case 408:
	switch( (*p) ) {
		case 9: goto tr830;
		case 10: goto tr831;
		case 13: goto tr832;
		case 32: goto tr830;
		case 35: goto tr833;
		case 44: goto tr834;
		case 59: goto tr736;
		case 95: goto st387;
		case 98: goto st409;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st387;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st387;
	} else
		goto st387;
	goto st0;
st409:
	if ( ++p == pe )
		goto _test_eof409;
case 409:
	switch( (*p) ) {
		case 9: goto tr863;
		case 10: goto tr864;
		case 13: goto tr865;
		case 32: goto tr863;
		case 35: goto tr866;
		case 44: goto tr834;
		case 59: goto tr736;
		case 61: goto st133;
		case 95: goto st387;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st387;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st387;
	} else
		goto st387;
	goto st0;
tr868:
#line 141 "confscanner.rl"
	{line++;}
	goto st410;
tr871:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 410; goto st22;} }
	goto st410;
tr863:
#line 27 "confscanner.rl"
	{
//    cerr << "in group add: " << endl;
    if(match_at_level_[level_])
    {
//      cerr << "do it" << endl;
      tmp_string.assign(tmp_p, p-tmp_p);
      // clear groupset_ first, if we did not use '+='
      if(!arg_to_be_added_)
        groupset_.clear();

      groupset_.insert(tmp_string);
    }
  }
	goto st410;
tr864:
#line 141 "confscanner.rl"
	{line++;}
#line 27 "confscanner.rl"
	{
//    cerr << "in group add: " << endl;
    if(match_at_level_[level_])
    {
//      cerr << "do it" << endl;
      tmp_string.assign(tmp_p, p-tmp_p);
      // clear groupset_ first, if we did not use '+='
      if(!arg_to_be_added_)
        groupset_.clear();

      groupset_.insert(tmp_string);
    }
  }
	goto st410;
st410:
	if ( ++p == pe )
		goto _test_eof410;
case 410:
#line 14036 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st410;
		case 10: goto tr868;
		case 13: goto st411;
		case 32: goto st410;
		case 35: goto st412;
		case 59: goto tr89;
		case 61: goto st133;
	}
	goto st0;
tr865:
#line 27 "confscanner.rl"
	{
//    cerr << "in group add: " << endl;
    if(match_at_level_[level_])
    {
//      cerr << "do it" << endl;
      tmp_string.assign(tmp_p, p-tmp_p);
      // clear groupset_ first, if we did not use '+='
      if(!arg_to_be_added_)
        groupset_.clear();

      groupset_.insert(tmp_string);
    }
  }
	goto st411;
st411:
	if ( ++p == pe )
		goto _test_eof411;
case 411:
#line 14067 "confscanner.cc"
	if ( (*p) == 10 )
		goto tr868;
	goto st0;
tr866:
#line 27 "confscanner.rl"
	{
//    cerr << "in group add: " << endl;
    if(match_at_level_[level_])
    {
//      cerr << "do it" << endl;
      tmp_string.assign(tmp_p, p-tmp_p);
      // clear groupset_ first, if we did not use '+='
      if(!arg_to_be_added_)
        groupset_.clear();

      groupset_.insert(tmp_string);
    }
  }
	goto st412;
st412:
	if ( ++p == pe )
		goto _test_eof412;
case 412:
#line 14091 "confscanner.cc"
	if ( (*p) == 35 )
		goto st0;
	goto tr871;
st413:
	if ( ++p == pe )
		goto _test_eof413;
case 413:
	switch( (*p) ) {
		case 9: goto tr830;
		case 10: goto tr831;
		case 13: goto tr832;
		case 32: goto tr830;
		case 35: goto tr833;
		case 44: goto tr834;
		case 59: goto tr736;
		case 95: goto st387;
		case 111: goto st414;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st387;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st387;
	} else
		goto st387;
	goto st0;
st414:
	if ( ++p == pe )
		goto _test_eof414;
case 414:
	switch( (*p) ) {
		case 9: goto tr830;
		case 10: goto tr831;
		case 13: goto tr832;
		case 32: goto tr830;
		case 35: goto tr833;
		case 44: goto tr834;
		case 59: goto tr736;
		case 95: goto st387;
		case 117: goto st415;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st387;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st387;
	} else
		goto st387;
	goto st0;
st415:
	if ( ++p == pe )
		goto _test_eof415;
case 415:
	switch( (*p) ) {
		case 9: goto tr830;
		case 10: goto tr831;
		case 13: goto tr832;
		case 32: goto tr830;
		case 35: goto tr833;
		case 44: goto tr834;
		case 59: goto tr736;
		case 95: goto st387;
		case 112: goto st416;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st387;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st387;
	} else
		goto st387;
	goto st0;
st416:
	if ( ++p == pe )
		goto _test_eof416;
case 416:
	switch( (*p) ) {
		case 9: goto tr830;
		case 10: goto tr831;
		case 13: goto tr832;
		case 32: goto tr830;
		case 35: goto tr833;
		case 44: goto tr834;
		case 59: goto tr736;
		case 95: goto st387;
		case 115: goto st417;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st387;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st387;
	} else
		goto st387;
	goto st0;
st417:
	if ( ++p == pe )
		goto _test_eof417;
case 417:
	switch( (*p) ) {
		case 9: goto tr876;
		case 10: goto tr877;
		case 13: goto tr878;
		case 32: goto tr876;
		case 35: goto tr879;
		case 43: goto tr822;
		case 44: goto tr834;
		case 59: goto tr736;
		case 61: goto st384;
		case 95: goto st387;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st387;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st387;
	} else
		goto st387;
	goto st0;
tr881:
#line 141 "confscanner.rl"
	{line++;}
	goto st418;
tr884:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 418; goto st22;} }
	goto st418;
tr876:
#line 27 "confscanner.rl"
	{
//    cerr << "in group add: " << endl;
    if(match_at_level_[level_])
    {
//      cerr << "do it" << endl;
      tmp_string.assign(tmp_p, p-tmp_p);
      // clear groupset_ first, if we did not use '+='
      if(!arg_to_be_added_)
        groupset_.clear();

      groupset_.insert(tmp_string);
    }
  }
	goto st418;
tr877:
#line 141 "confscanner.rl"
	{line++;}
#line 27 "confscanner.rl"
	{
//    cerr << "in group add: " << endl;
    if(match_at_level_[level_])
    {
//      cerr << "do it" << endl;
      tmp_string.assign(tmp_p, p-tmp_p);
      // clear groupset_ first, if we did not use '+='
      if(!arg_to_be_added_)
        groupset_.clear();

      groupset_.insert(tmp_string);
    }
  }
	goto st418;
st418:
	if ( ++p == pe )
		goto _test_eof418;
case 418:
#line 14262 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st418;
		case 10: goto tr881;
		case 13: goto st419;
		case 32: goto st418;
		case 35: goto st420;
		case 43: goto tr822;
		case 59: goto tr89;
		case 61: goto st384;
	}
	goto st0;
tr878:
#line 27 "confscanner.rl"
	{
//    cerr << "in group add: " << endl;
    if(match_at_level_[level_])
    {
//      cerr << "do it" << endl;
      tmp_string.assign(tmp_p, p-tmp_p);
      // clear groupset_ first, if we did not use '+='
      if(!arg_to_be_added_)
        groupset_.clear();

      groupset_.insert(tmp_string);
    }
  }
	goto st419;
st419:
	if ( ++p == pe )
		goto _test_eof419;
case 419:
#line 14294 "confscanner.cc"
	if ( (*p) == 10 )
		goto tr881;
	goto st0;
tr879:
#line 27 "confscanner.rl"
	{
//    cerr << "in group add: " << endl;
    if(match_at_level_[level_])
    {
//      cerr << "do it" << endl;
      tmp_string.assign(tmp_p, p-tmp_p);
      // clear groupset_ first, if we did not use '+='
      if(!arg_to_be_added_)
        groupset_.clear();

      groupset_.insert(tmp_string);
    }
  }
	goto st420;
st420:
	if ( ++p == pe )
		goto _test_eof420;
case 420:
#line 14318 "confscanner.cc"
	if ( (*p) == 35 )
		goto st0;
	goto tr884;
tr1901:
#line 141 "confscanner.rl"
	{line++;}
	goto st926;
tr887:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 926; goto st22;} }
	goto st926;
tr1904:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st926;
tr885:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st926;
tr888:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 926; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st926;
tr889:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 926; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st926;
tr708:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 926; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 926; goto st886;} }
	goto st926;
st926:
	if ( ++p == pe )
		goto _test_eof926;
case 926:
#line 14391 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st926;
		case 10: goto tr1901;
		case 13: goto tr1902;
		case 32: goto st926;
		case 35: goto tr1903;
		case 43: goto tr700;
		case 59: goto st0;
		case 61: goto tr701;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr246;
		case 125: goto tr1778;
	}
	goto tr241;
tr1902:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st421;
tr1905:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st421;
st421:
	if ( ++p == pe )
		goto _test_eof421;
case 421:
#line 14427 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr885;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1903:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st422;
tr1906:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st422;
st422:
	if ( ++p == pe )
		goto _test_eof422;
case 422:
#line 14458 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr887;
		case 9: goto tr888;
		case 10: goto tr889;
		case 13: goto tr890;
		case 32: goto tr888;
		case 35: goto tr249;
		case 59: goto tr887;
		case 123: goto tr708;
	}
	goto tr886;
tr886:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 927; goto st22;} }
	goto st927;
tr890:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 927; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st927;
st927:
	if ( ++p == pe )
		goto _test_eof927;
case 927:
#line 14489 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1904;
		case 10: goto tr885;
		case 13: goto tr1905;
		case 32: goto tr1904;
		case 35: goto tr1906;
		case 43: goto tr700;
		case 59: goto st0;
		case 61: goto tr701;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr240;
		case 125: goto tr1778;
	}
	goto tr241;
tr891:
#line 141 "confscanner.rl"
	{line++;}
	goto st423;
tr894:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 423; goto st22;} }
	goto st423;
tr691:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st423;
tr895:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st423;
tr897:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 423; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st423;
tr1339:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 423; goto st22;} }
#line 141 "confscanner.rl"
	{line++;}
	goto st423;
st423:
	if ( ++p == pe )
		goto _test_eof423;
case 423:
#line 14566 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st331;
		case 10: goto tr891;
		case 13: goto st424;
		case 32: goto st331;
		case 35: goto st425;
		case 43: goto tr822;
		case 61: goto st384;
		case 123: goto tr246;
	}
	goto st0;
st424:
	if ( ++p == pe )
		goto _test_eof424;
case 424:
	if ( (*p) == 10 )
		goto tr891;
	goto st0;
st425:
	if ( ++p == pe )
		goto _test_eof425;
case 425:
	if ( (*p) == 35 )
		goto st0;
	goto tr894;
tr692:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st426;
st426:
	if ( ++p == pe )
		goto _test_eof426;
case 426:
#line 14605 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr895;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr693:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st427;
st427:
	if ( ++p == pe )
		goto _test_eof427;
case 427:
#line 14630 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr894;
		case 9: goto tr705;
		case 10: goto tr897;
		case 13: goto tr898;
		case 32: goto tr705;
		case 35: goto tr249;
		case 59: goto tr894;
		case 123: goto tr899;
	}
	goto tr896;
tr896:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 428; goto st22;} }
	goto st428;
st428:
	if ( ++p == pe )
		goto _test_eof428;
case 428:
#line 14650 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr690;
		case 10: goto tr691;
		case 13: goto tr692;
		case 32: goto tr690;
		case 35: goto tr693;
		case 43: goto tr694;
		case 59: goto st0;
		case 61: goto st336;
		case 123: goto tr240;
	}
	goto st136;
tr898:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 429; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st429;
st429:
	if ( ++p == pe )
		goto _test_eof429;
case 429:
#line 14679 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr690;
		case 10: goto tr895;
		case 13: goto tr692;
		case 32: goto tr690;
		case 35: goto tr693;
		case 43: goto tr694;
		case 59: goto st0;
		case 61: goto st336;
		case 123: goto tr240;
	}
	goto st136;
tr900:
#line 141 "confscanner.rl"
	{line++;}
	goto st928;
tr901:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 928; goto st22;} }
	goto st928;
tr899:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 928; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 928; goto st886;} }
	goto st928;
tr1341:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 928; goto st22;} }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 928; goto st886;} }
	goto st928;
st928:
	if ( ++p == pe )
		goto _test_eof928;
case 928:
#line 14731 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st926;
		case 10: goto tr900;
		case 13: goto st430;
		case 32: goto st926;
		case 35: goto st431;
		case 43: goto tr822;
		case 61: goto st384;
		case 97: goto st27;
		case 103: goto st127;
		case 123: goto tr246;
		case 125: goto tr1769;
	}
	goto st0;
st430:
	if ( ++p == pe )
		goto _test_eof430;
case 430:
	if ( (*p) == 10 )
		goto tr900;
	goto st0;
st431:
	if ( ++p == pe )
		goto _test_eof431;
case 431:
	if ( (*p) == 35 )
		goto st0;
	goto tr901;
tr902:
#line 141 "confscanner.rl"
	{line++;}
	goto st432;
tr905:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 432; goto st22;} }
	goto st432;
tr520:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st432;
tr906:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st432;
tr908:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 432; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st432;
tr1041:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 432; goto st22;} }
#line 141 "confscanner.rl"
	{line++;}
	goto st432;
st432:
	if ( ++p == pe )
		goto _test_eof432;
case 432:
#line 14820 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st253;
		case 10: goto tr902;
		case 13: goto st433;
		case 32: goto st253;
		case 35: goto st434;
		case 123: goto tr246;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr118;
	} else if ( (*p) >= 65 )
		goto tr118;
	goto st0;
st433:
	if ( ++p == pe )
		goto _test_eof433;
case 433:
	if ( (*p) == 10 )
		goto tr902;
	goto st0;
st434:
	if ( ++p == pe )
		goto _test_eof434;
case 434:
	if ( (*p) == 35 )
		goto st0;
	goto tr905;
tr521:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st435;
st435:
	if ( ++p == pe )
		goto _test_eof435;
case 435:
#line 14862 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr906;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr522:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st436;
st436:
	if ( ++p == pe )
		goto _test_eof436;
case 436:
#line 14887 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr905;
		case 9: goto tr532;
		case 10: goto tr908;
		case 13: goto tr909;
		case 32: goto tr532;
		case 35: goto tr249;
		case 59: goto tr905;
		case 123: goto tr910;
	}
	goto tr907;
tr909:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 437; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st437;
st437:
	if ( ++p == pe )
		goto _test_eof437;
case 437:
#line 14914 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr519;
		case 10: goto tr906;
		case 13: goto tr521;
		case 32: goto tr519;
		case 35: goto tr522;
		case 59: goto st0;
		case 123: goto tr240;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr523;
	} else if ( (*p) >= 65 )
		goto tr523;
	goto st136;
tr911:
#line 141 "confscanner.rl"
	{line++;}
	goto st929;
tr912:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 929; goto st22;} }
	goto st929;
tr910:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 929; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 929; goto st886;} }
	goto st929;
tr1043:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 929; goto st22;} }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 929; goto st886;} }
	goto st929;
st929:
	if ( ++p == pe )
		goto _test_eof929;
case 929:
#line 14969 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st912;
		case 10: goto tr911;
		case 13: goto st438;
		case 32: goto st912;
		case 35: goto st439;
		case 97: goto tr1911;
		case 103: goto tr1912;
		case 123: goto tr246;
		case 125: goto tr1769;
	}
	if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr118;
	} else if ( (*p) >= 65 )
		goto tr118;
	goto st0;
st438:
	if ( ++p == pe )
		goto _test_eof438;
case 438:
	if ( (*p) == 10 )
		goto tr911;
	goto st0;
st439:
	if ( ++p == pe )
		goto _test_eof439;
case 439:
	if ( (*p) == 35 )
		goto st0;
	goto tr912;
tr1911:
#line 192 "confscanner.rl"
	{tmp_p = p;/* cerr << "dlmi\n";*/}
	goto st440;
st440:
	if ( ++p == pe )
		goto _test_eof440;
case 440:
#line 15009 "confscanner.cc"
	switch( (*p) ) {
		case 46: goto tr120;
		case 95: goto st70;
		case 100: goto st441;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st70;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st70;
	} else
		goto st70;
	goto st0;
st441:
	if ( ++p == pe )
		goto _test_eof441;
case 441:
	switch( (*p) ) {
		case 46: goto tr120;
		case 95: goto st70;
		case 100: goto st442;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st70;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st70;
	} else
		goto st70;
	goto st0;
st442:
	if ( ++p == pe )
		goto _test_eof442;
case 442:
	switch( (*p) ) {
		case 40: goto st30;
		case 46: goto tr120;
		case 95: goto st70;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st70;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st70;
	} else
		goto st70;
	goto st0;
tr1912:
#line 192 "confscanner.rl"
	{tmp_p = p;/* cerr << "dlmi\n";*/}
	goto st443;
st443:
	if ( ++p == pe )
		goto _test_eof443;
case 443:
#line 15068 "confscanner.cc"
	switch( (*p) ) {
		case 46: goto tr120;
		case 95: goto st70;
		case 108: goto st444;
		case 114: goto st447;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st70;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st70;
	} else
		goto st70;
	goto st0;
st444:
	if ( ++p == pe )
		goto _test_eof444;
case 444:
	switch( (*p) ) {
		case 46: goto tr120;
		case 95: goto st70;
		case 111: goto st445;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st70;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st70;
	} else
		goto st70;
	goto st0;
st445:
	if ( ++p == pe )
		goto _test_eof445;
case 445:
	switch( (*p) ) {
		case 46: goto tr120;
		case 95: goto st70;
		case 98: goto st446;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st70;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st70;
	} else
		goto st70;
	goto st0;
st446:
	if ( ++p == pe )
		goto _test_eof446;
case 446:
	switch( (*p) ) {
		case 9: goto st130;
		case 10: goto tr226;
		case 13: goto st131;
		case 32: goto st130;
		case 35: goto st132;
		case 46: goto tr120;
		case 61: goto st133;
		case 95: goto st70;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st70;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st70;
	} else
		goto st70;
	goto st0;
st447:
	if ( ++p == pe )
		goto _test_eof447;
case 447:
	switch( (*p) ) {
		case 46: goto tr120;
		case 95: goto st70;
		case 111: goto st448;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st70;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st70;
	} else
		goto st70;
	goto st0;
st448:
	if ( ++p == pe )
		goto _test_eof448;
case 448:
	switch( (*p) ) {
		case 46: goto tr120;
		case 95: goto st70;
		case 117: goto st449;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st70;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st70;
	} else
		goto st70;
	goto st0;
st449:
	if ( ++p == pe )
		goto _test_eof449;
case 449:
	switch( (*p) ) {
		case 46: goto tr120;
		case 95: goto st70;
		case 112: goto st450;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st70;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st70;
	} else
		goto st70;
	goto st0;
st450:
	if ( ++p == pe )
		goto _test_eof450;
case 450:
	switch( (*p) ) {
		case 46: goto tr120;
		case 95: goto st70;
		case 115: goto st451;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st70;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st70;
	} else
		goto st70;
	goto st0;
st451:
	if ( ++p == pe )
		goto _test_eof451;
case 451:
	switch( (*p) ) {
		case 9: goto st452;
		case 10: goto tr924;
		case 13: goto st453;
		case 32: goto st452;
		case 35: goto st454;
		case 43: goto tr822;
		case 46: goto tr120;
		case 61: goto st384;
		case 95: goto st70;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st70;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st70;
	} else
		goto st70;
	goto st0;
tr924:
#line 141 "confscanner.rl"
	{line++;}
	goto st452;
tr927:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 452; goto st22;} }
	goto st452;
st452:
	if ( ++p == pe )
		goto _test_eof452;
case 452:
#line 15251 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st452;
		case 10: goto tr924;
		case 13: goto st453;
		case 32: goto st452;
		case 35: goto st454;
		case 43: goto tr822;
		case 61: goto st384;
	}
	goto st0;
st453:
	if ( ++p == pe )
		goto _test_eof453;
case 453:
	if ( (*p) == 10 )
		goto tr924;
	goto st0;
st454:
	if ( ++p == pe )
		goto _test_eof454;
case 454:
	if ( (*p) == 35 )
		goto st0;
	goto tr927;
tr503:
#line 192 "confscanner.rl"
	{tmp_p = p;/* cerr << "dlmi\n";*/}
	goto st455;
tr509:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 192 "confscanner.rl"
	{tmp_p = p;/* cerr << "dlmi\n";*/}
	goto st455;
st455:
	if ( ++p == pe )
		goto _test_eof455;
case 455:
#line 15290 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 46: goto tr928;
		case 59: goto st0;
		case 95: goto st455;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st455;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st455;
	} else
		goto st455;
	goto st136;
tr928:
#line 22 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
  }
	goto st456;
st456:
	if ( ++p == pe )
		goto _test_eof456;
case 456:
#line 15322 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr930;
	} else if ( (*p) >= 65 )
		goto tr930;
	goto st136;
tr930:
#line 196 "confscanner.rl"
	{tmp_p = p;/* cerr << "dlmi2\n";*/}
	goto st457;
st457:
	if ( ++p == pe )
		goto _test_eof457;
case 457:
#line 15347 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr931;
		case 10: goto tr932;
		case 13: goto tr933;
		case 32: goto tr931;
		case 35: goto tr934;
		case 59: goto st0;
		case 61: goto tr936;
		case 95: goto st457;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st457;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st457;
	} else
		goto st457;
	goto st136;
tr938:
#line 141 "confscanner.rl"
	{line++;}
	goto st458;
tr944:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 458; goto st22;} }
	goto st458;
tr949:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st458;
tr942:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st458;
tr945:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 458; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st458;
tr946:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 458; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st458;
tr1086:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 458; goto st22;} }
	goto st458;
tr931:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 108 "confscanner.rl"
	{
    string s(tmp_p, p-tmp_p);
    cblock_ = &((*clistmap_)[tmp_string][s]);
  }
	goto st458;
tr1509:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st458;
st458:
	if ( ++p == pe )
		goto _test_eof458;
case 458:
#line 15468 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st458;
		case 10: goto tr938;
		case 13: goto tr939;
		case 32: goto st458;
		case 35: goto tr940;
		case 59: goto st0;
		case 61: goto tr941;
		case 123: goto tr246;
	}
	goto tr241;
tr939:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st459;
tr950:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st459;
st459:
	if ( ++p == pe )
		goto _test_eof459;
case 459:
#line 15500 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr942;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr940:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st460;
tr951:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st460;
st460:
	if ( ++p == pe )
		goto _test_eof460;
case 460:
#line 15531 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr944;
		case 9: goto tr945;
		case 10: goto tr946;
		case 13: goto tr947;
		case 32: goto tr945;
		case 35: goto tr249;
		case 59: goto tr944;
		case 123: goto tr948;
	}
	goto tr943;
tr943:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 461; goto st22;} }
	goto st461;
tr947:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 461; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st461;
st461:
	if ( ++p == pe )
		goto _test_eof461;
case 461:
#line 15562 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr949;
		case 10: goto tr942;
		case 13: goto tr950;
		case 32: goto tr949;
		case 35: goto tr951;
		case 59: goto st0;
		case 61: goto tr941;
		case 123: goto tr240;
	}
	goto tr241;
tr936:
#line 108 "confscanner.rl"
	{
    string s(tmp_p, p-tmp_p);
    cblock_ = &((*clistmap_)[tmp_string][s]);
  }
	goto st462;
tr1514:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st462;
tr941:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st462;
st462:
	if ( ++p == pe )
		goto _test_eof462;
case 462:
#line 15601 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 62: goto st159;
		case 123: goto tr240;
	}
	goto st136;
tr1914:
#line 141 "confscanner.rl"
	{line++;}
	goto st930;
tr954:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 930; goto st22;} }
	goto st930;
tr1917:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st930;
tr952:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st930;
tr955:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 930; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st930;
tr956:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 930; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st930;
tr948:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 930; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 930; goto st886;} }
	goto st930;
st930:
	if ( ++p == pe )
		goto _test_eof930;
case 930:
#line 15683 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st930;
		case 10: goto tr1914;
		case 13: goto tr1915;
		case 32: goto st930;
		case 35: goto tr1916;
		case 59: goto st0;
		case 61: goto tr941;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr246;
		case 125: goto tr1778;
	}
	goto tr241;
tr1915:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st463;
tr1918:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st463;
st463:
	if ( ++p == pe )
		goto _test_eof463;
case 463:
#line 15718 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr952;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1916:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st464;
tr1919:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st464;
st464:
	if ( ++p == pe )
		goto _test_eof464;
case 464:
#line 15749 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr954;
		case 9: goto tr955;
		case 10: goto tr956;
		case 13: goto tr957;
		case 32: goto tr955;
		case 35: goto tr249;
		case 59: goto tr954;
		case 123: goto tr948;
	}
	goto tr953;
tr953:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 931; goto st22;} }
	goto st931;
tr957:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 931; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st931;
st931:
	if ( ++p == pe )
		goto _test_eof931;
case 931:
#line 15780 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1917;
		case 10: goto tr952;
		case 13: goto tr1918;
		case 32: goto tr1917;
		case 35: goto tr1919;
		case 59: goto st0;
		case 61: goto tr941;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr240;
		case 125: goto tr1778;
	}
	goto tr241;
tr958:
#line 141 "confscanner.rl"
	{line++;}
	goto st465;
tr961:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 465; goto st22;} }
	goto st465;
tr967:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st465;
tr962:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st465;
tr964:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 465; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st465;
tr1087:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 465; goto st22;} }
#line 141 "confscanner.rl"
	{line++;}
	goto st465;
tr932:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
#line 108 "confscanner.rl"
	{
    string s(tmp_p, p-tmp_p);
    cblock_ = &((*clistmap_)[tmp_string][s]);
  }
	goto st465;
tr1510:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st465;
st465:
	if ( ++p == pe )
		goto _test_eof465;
case 465:
#line 15892 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st458;
		case 10: goto tr958;
		case 13: goto st466;
		case 32: goto st458;
		case 35: goto st467;
		case 61: goto st91;
		case 123: goto tr246;
	}
	goto st0;
st466:
	if ( ++p == pe )
		goto _test_eof466;
case 466:
	if ( (*p) == 10 )
		goto tr958;
	goto st0;
st467:
	if ( ++p == pe )
		goto _test_eof467;
case 467:
	if ( (*p) == 35 )
		goto st0;
	goto tr961;
tr968:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st468;
tr933:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 108 "confscanner.rl"
	{
    string s(tmp_p, p-tmp_p);
    cblock_ = &((*clistmap_)[tmp_string][s]);
  }
	goto st468;
tr1511:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st468;
st468:
	if ( ++p == pe )
		goto _test_eof468;
case 468:
#line 15962 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr962;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr969:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st469;
tr934:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 108 "confscanner.rl"
	{
    string s(tmp_p, p-tmp_p);
    cblock_ = &((*clistmap_)[tmp_string][s]);
  }
	goto st469;
tr1512:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st469;
st469:
	if ( ++p == pe )
		goto _test_eof469;
case 469:
#line 16019 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr961;
		case 9: goto tr945;
		case 10: goto tr964;
		case 13: goto tr965;
		case 32: goto tr945;
		case 35: goto tr249;
		case 59: goto tr961;
		case 123: goto tr966;
	}
	goto tr963;
tr963:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 470; goto st22;} }
	goto st470;
st470:
	if ( ++p == pe )
		goto _test_eof470;
case 470:
#line 16039 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr949;
		case 10: goto tr967;
		case 13: goto tr968;
		case 32: goto tr949;
		case 35: goto tr969;
		case 59: goto st0;
		case 61: goto st462;
		case 123: goto tr240;
	}
	goto st136;
tr965:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 471; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st471;
st471:
	if ( ++p == pe )
		goto _test_eof471;
case 471:
#line 16067 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr949;
		case 10: goto tr962;
		case 13: goto tr968;
		case 32: goto tr949;
		case 35: goto tr969;
		case 59: goto st0;
		case 61: goto st462;
		case 123: goto tr240;
	}
	goto st136;
tr971:
#line 141 "confscanner.rl"
	{line++;}
	goto st932;
tr972:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 932; goto st22;} }
	goto st932;
tr966:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 932; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 932; goto st886;} }
	goto st932;
tr1089:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 932; goto st22;} }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 932; goto st886;} }
	goto st932;
st932:
	if ( ++p == pe )
		goto _test_eof932;
case 932:
#line 16118 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st930;
		case 10: goto tr971;
		case 13: goto st472;
		case 32: goto st930;
		case 35: goto st473;
		case 61: goto st91;
		case 97: goto st27;
		case 103: goto st127;
		case 123: goto tr246;
		case 125: goto tr1769;
	}
	goto st0;
st472:
	if ( ++p == pe )
		goto _test_eof472;
case 472:
	if ( (*p) == 10 )
		goto tr971;
	goto st0;
st473:
	if ( ++p == pe )
		goto _test_eof473;
case 473:
	if ( (*p) == 35 )
		goto st0;
	goto tr972;
tr1923:
#line 141 "confscanner.rl"
	{line++;}
	goto st933;
tr975:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 933; goto st22;} }
	goto st933;
tr1928:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st933;
tr973:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st933;
tr976:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 933; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st933;
tr977:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 933; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st933;
tr516:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 933; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 933; goto st886;} }
	goto st933;
st933:
	if ( ++p == pe )
		goto _test_eof933;
case 933:
#line 16215 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st933;
		case 10: goto tr1923;
		case 13: goto tr1924;
		case 32: goto st933;
		case 35: goto tr1925;
		case 40: goto tr508;
		case 59: goto st0;
		case 97: goto tr1926;
		case 103: goto tr1927;
		case 123: goto tr246;
		case 125: goto tr1778;
	}
	if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr509;
	} else if ( (*p) >= 65 )
		goto tr509;
	goto tr241;
tr1924:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st474;
tr1929:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st474;
st474:
	if ( ++p == pe )
		goto _test_eof474;
case 474:
#line 16255 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr973;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1925:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st475;
tr1930:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st475;
st475:
	if ( ++p == pe )
		goto _test_eof475;
case 475:
#line 16286 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr975;
		case 9: goto tr976;
		case 10: goto tr977;
		case 13: goto tr978;
		case 32: goto tr976;
		case 35: goto tr249;
		case 59: goto tr975;
		case 123: goto tr516;
	}
	goto tr974;
tr974:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 934; goto st22;} }
	goto st934;
tr978:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 934; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st934;
st934:
	if ( ++p == pe )
		goto _test_eof934;
case 934:
#line 16317 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1928;
		case 10: goto tr973;
		case 13: goto tr1929;
		case 32: goto tr1928;
		case 35: goto tr1930;
		case 40: goto tr508;
		case 59: goto st0;
		case 97: goto tr1926;
		case 103: goto tr1927;
		case 123: goto tr240;
		case 125: goto tr1778;
	}
	if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr509;
	} else if ( (*p) >= 65 )
		goto tr509;
	goto tr241;
tr1926:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 192 "confscanner.rl"
	{tmp_p = p;/* cerr << "dlmi\n";*/}
	goto st476;
st476:
	if ( ++p == pe )
		goto _test_eof476;
case 476:
#line 16348 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 46: goto tr928;
		case 59: goto st0;
		case 95: goto st455;
		case 100: goto st477;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st455;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st455;
	} else
		goto st455;
	goto st136;
st477:
	if ( ++p == pe )
		goto _test_eof477;
case 477:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 46: goto tr928;
		case 59: goto st0;
		case 95: goto st455;
		case 100: goto st478;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st455;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st455;
	} else
		goto st455;
	goto st136;
st478:
	if ( ++p == pe )
		goto _test_eof478;
case 478:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 40: goto st147;
		case 46: goto tr928;
		case 59: goto st0;
		case 95: goto st455;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st455;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st455;
	} else
		goto st455;
	goto st136;
tr1927:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 192 "confscanner.rl"
	{tmp_p = p;/* cerr << "dlmi\n";*/}
	goto st479;
st479:
	if ( ++p == pe )
		goto _test_eof479;
case 479:
#line 16433 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 46: goto tr928;
		case 59: goto st0;
		case 95: goto st455;
		case 108: goto st480;
		case 114: goto st483;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st455;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st455;
	} else
		goto st455;
	goto st136;
st480:
	if ( ++p == pe )
		goto _test_eof480;
case 480:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 46: goto tr928;
		case 59: goto st0;
		case 95: goto st455;
		case 111: goto st481;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st455;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st455;
	} else
		goto st455;
	goto st136;
st481:
	if ( ++p == pe )
		goto _test_eof481;
case 481:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 46: goto tr928;
		case 59: goto st0;
		case 95: goto st455;
		case 98: goto st482;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st455;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st455;
	} else
		goto st455;
	goto st136;
st482:
	if ( ++p == pe )
		goto _test_eof482;
case 482:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr342;
		case 10: goto tr343;
		case 13: goto tr344;
		case 32: goto tr342;
		case 35: goto tr345;
		case 46: goto tr928;
		case 59: goto st0;
		case 61: goto st179;
		case 95: goto st455;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st455;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st455;
	} else
		goto st455;
	goto st136;
st483:
	if ( ++p == pe )
		goto _test_eof483;
case 483:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 46: goto tr928;
		case 59: goto st0;
		case 95: goto st455;
		case 111: goto st484;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st455;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st455;
	} else
		goto st455;
	goto st136;
st484:
	if ( ++p == pe )
		goto _test_eof484;
case 484:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 46: goto tr928;
		case 59: goto st0;
		case 95: goto st455;
		case 117: goto st485;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st455;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st455;
	} else
		goto st455;
	goto st136;
st485:
	if ( ++p == pe )
		goto _test_eof485;
case 485:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 46: goto tr928;
		case 59: goto st0;
		case 95: goto st455;
		case 112: goto st486;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st455;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st455;
	} else
		goto st455;
	goto st136;
st486:
	if ( ++p == pe )
		goto _test_eof486;
case 486:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 46: goto tr928;
		case 59: goto st0;
		case 95: goto st455;
		case 115: goto st487;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st455;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st455;
	} else
		goto st455;
	goto st136;
st487:
	if ( ++p == pe )
		goto _test_eof487;
case 487:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr690;
		case 10: goto tr691;
		case 13: goto tr692;
		case 32: goto tr690;
		case 35: goto tr693;
		case 43: goto tr694;
		case 46: goto tr928;
		case 59: goto st0;
		case 61: goto st336;
		case 95: goto st455;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st455;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st455;
	} else
		goto st455;
	goto st136;
tr989:
#line 141 "confscanner.rl"
	{line++;}
	goto st488;
tr992:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 488; goto st22;} }
	goto st488;
tr499:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st488;
tr993:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st488;
tr995:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 488; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st488;
tr1033:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 488; goto st22;} }
#line 141 "confscanner.rl"
	{line++;}
	goto st488;
st488:
	if ( ++p == pe )
		goto _test_eof488;
case 488:
#line 16726 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st248;
		case 10: goto tr989;
		case 13: goto st489;
		case 32: goto st248;
		case 35: goto st490;
		case 40: goto st67;
		case 123: goto tr246;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr113;
	} else if ( (*p) >= 65 )
		goto tr113;
	goto st0;
st489:
	if ( ++p == pe )
		goto _test_eof489;
case 489:
	if ( (*p) == 10 )
		goto tr989;
	goto st0;
st490:
	if ( ++p == pe )
		goto _test_eof490;
case 490:
	if ( (*p) == 35 )
		goto st0;
	goto tr992;
tr500:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st491;
st491:
	if ( ++p == pe )
		goto _test_eof491;
case 491:
#line 16769 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr993;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr501:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st492;
st492:
	if ( ++p == pe )
		goto _test_eof492;
case 492:
#line 16794 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr992;
		case 9: goto tr513;
		case 10: goto tr995;
		case 13: goto tr996;
		case 32: goto tr513;
		case 35: goto tr249;
		case 59: goto tr992;
		case 123: goto tr997;
	}
	goto tr994;
tr996:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 493; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st493;
st493:
	if ( ++p == pe )
		goto _test_eof493;
case 493:
#line 16821 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr498;
		case 10: goto tr993;
		case 13: goto tr500;
		case 32: goto tr498;
		case 35: goto tr501;
		case 40: goto st252;
		case 59: goto st0;
		case 123: goto tr240;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr503;
	} else if ( (*p) >= 65 )
		goto tr503;
	goto st136;
tr998:
#line 141 "confscanner.rl"
	{line++;}
	goto st935;
tr999:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 935; goto st22;} }
	goto st935;
tr997:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 935; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 935; goto st886;} }
	goto st935;
tr1035:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 935; goto st22;} }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 935; goto st886;} }
	goto st935;
st935:
	if ( ++p == pe )
		goto _test_eof935;
case 935:
#line 16877 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st933;
		case 10: goto tr998;
		case 13: goto st494;
		case 32: goto st933;
		case 35: goto st495;
		case 40: goto st67;
		case 97: goto tr1933;
		case 103: goto tr1934;
		case 123: goto tr246;
		case 125: goto tr1769;
	}
	if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr113;
	} else if ( (*p) >= 65 )
		goto tr113;
	goto st0;
st494:
	if ( ++p == pe )
		goto _test_eof494;
case 494:
	if ( (*p) == 10 )
		goto tr998;
	goto st0;
st495:
	if ( ++p == pe )
		goto _test_eof495;
case 495:
	if ( (*p) == 35 )
		goto st0;
	goto tr999;
tr1933:
#line 192 "confscanner.rl"
	{tmp_p = p;/* cerr << "dlmi\n";*/}
	goto st496;
st496:
	if ( ++p == pe )
		goto _test_eof496;
case 496:
#line 16918 "confscanner.cc"
	switch( (*p) ) {
		case 46: goto tr148;
		case 95: goto st85;
		case 100: goto st497;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st85;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st85;
	} else
		goto st85;
	goto st0;
st497:
	if ( ++p == pe )
		goto _test_eof497;
case 497:
	switch( (*p) ) {
		case 46: goto tr148;
		case 95: goto st85;
		case 100: goto st498;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st85;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st85;
	} else
		goto st85;
	goto st0;
st498:
	if ( ++p == pe )
		goto _test_eof498;
case 498:
	switch( (*p) ) {
		case 40: goto st30;
		case 46: goto tr148;
		case 95: goto st85;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st85;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st85;
	} else
		goto st85;
	goto st0;
tr1934:
#line 192 "confscanner.rl"
	{tmp_p = p;/* cerr << "dlmi\n";*/}
	goto st499;
st499:
	if ( ++p == pe )
		goto _test_eof499;
case 499:
#line 16977 "confscanner.cc"
	switch( (*p) ) {
		case 46: goto tr148;
		case 95: goto st85;
		case 108: goto st500;
		case 114: goto st503;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st85;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st85;
	} else
		goto st85;
	goto st0;
st500:
	if ( ++p == pe )
		goto _test_eof500;
case 500:
	switch( (*p) ) {
		case 46: goto tr148;
		case 95: goto st85;
		case 111: goto st501;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st85;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st85;
	} else
		goto st85;
	goto st0;
st501:
	if ( ++p == pe )
		goto _test_eof501;
case 501:
	switch( (*p) ) {
		case 46: goto tr148;
		case 95: goto st85;
		case 98: goto st502;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st85;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st85;
	} else
		goto st85;
	goto st0;
st502:
	if ( ++p == pe )
		goto _test_eof502;
case 502:
	switch( (*p) ) {
		case 9: goto st130;
		case 10: goto tr226;
		case 13: goto st131;
		case 32: goto st130;
		case 35: goto st132;
		case 46: goto tr148;
		case 61: goto st133;
		case 95: goto st85;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st85;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st85;
	} else
		goto st85;
	goto st0;
st503:
	if ( ++p == pe )
		goto _test_eof503;
case 503:
	switch( (*p) ) {
		case 46: goto tr148;
		case 95: goto st85;
		case 111: goto st504;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st85;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st85;
	} else
		goto st85;
	goto st0;
st504:
	if ( ++p == pe )
		goto _test_eof504;
case 504:
	switch( (*p) ) {
		case 46: goto tr148;
		case 95: goto st85;
		case 117: goto st505;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st85;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st85;
	} else
		goto st85;
	goto st0;
st505:
	if ( ++p == pe )
		goto _test_eof505;
case 505:
	switch( (*p) ) {
		case 46: goto tr148;
		case 95: goto st85;
		case 112: goto st506;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st85;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st85;
	} else
		goto st85;
	goto st0;
st506:
	if ( ++p == pe )
		goto _test_eof506;
case 506:
	switch( (*p) ) {
		case 46: goto tr148;
		case 95: goto st85;
		case 115: goto st507;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st85;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st85;
	} else
		goto st85;
	goto st0;
st507:
	if ( ++p == pe )
		goto _test_eof507;
case 507:
	switch( (*p) ) {
		case 9: goto st452;
		case 10: goto tr924;
		case 13: goto st453;
		case 32: goto st452;
		case 35: goto st454;
		case 43: goto tr822;
		case 46: goto tr148;
		case 61: goto st384;
		case 95: goto st85;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st85;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st85;
	} else
		goto st85;
	goto st0;
tr1936:
#line 141 "confscanner.rl"
	{line++;}
	goto st936;
tr1012:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 936; goto st22;} }
	goto st936;
tr1939:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st936;
tr1010:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st936;
tr1013:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 936; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st936;
tr1014:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 936; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st936;
tr494:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 936; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 936; goto st886;} }
	goto st936;
st936:
	if ( ++p == pe )
		goto _test_eof936;
case 936:
#line 17217 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st936;
		case 10: goto tr1936;
		case 13: goto tr1937;
		case 32: goto st936;
		case 35: goto tr1938;
		case 43: goto tr486;
		case 59: goto st0;
		case 61: goto tr487;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr246;
		case 125: goto tr1778;
	}
	goto tr241;
tr1937:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st508;
tr1940:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st508;
st508:
	if ( ++p == pe )
		goto _test_eof508;
case 508:
#line 17253 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1010;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1938:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st509;
tr1941:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st509;
st509:
	if ( ++p == pe )
		goto _test_eof509;
case 509:
#line 17284 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1012;
		case 9: goto tr1013;
		case 10: goto tr1014;
		case 13: goto tr1015;
		case 32: goto tr1013;
		case 35: goto tr249;
		case 59: goto tr1012;
		case 123: goto tr494;
	}
	goto tr1011;
tr1011:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 937; goto st22;} }
	goto st937;
tr1015:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 937; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st937;
st937:
	if ( ++p == pe )
		goto _test_eof937;
case 937:
#line 17315 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1939;
		case 10: goto tr1010;
		case 13: goto tr1940;
		case 32: goto tr1939;
		case 35: goto tr1941;
		case 43: goto tr486;
		case 59: goto st0;
		case 61: goto tr487;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr240;
		case 125: goto tr1778;
	}
	goto tr241;
tr1016:
#line 141 "confscanner.rl"
	{line++;}
	goto st510;
tr1019:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 510; goto st22;} }
	goto st510;
tr477:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st510;
tr1723:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st510;
tr1725:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 510; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st510;
tr1022:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 510; goto st22;} }
#line 141 "confscanner.rl"
	{line++;}
	goto st510;
st510:
	if ( ++p == pe )
		goto _test_eof510;
case 510:
#line 17392 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st242;
		case 10: goto tr1016;
		case 13: goto st511;
		case 32: goto st242;
		case 35: goto st512;
		case 43: goto tr106;
		case 61: goto st64;
		case 123: goto tr246;
	}
	goto st0;
st511:
	if ( ++p == pe )
		goto _test_eof511;
case 511:
	if ( (*p) == 10 )
		goto tr1016;
	goto st0;
st512:
	if ( ++p == pe )
		goto _test_eof512;
case 512:
	if ( (*p) == 35 )
		goto st0;
	goto tr1019;
tr478:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st513;
st513:
	if ( ++p == pe )
		goto _test_eof513;
case 513:
#line 17431 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr477;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
tr479:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st514;
st514:
	if ( ++p == pe )
		goto _test_eof514;
case 514:
#line 17456 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1019;
		case 9: goto tr1021;
		case 10: goto tr1022;
		case 13: goto tr1023;
		case 32: goto tr1021;
		case 35: goto tr239;
		case 59: goto tr1019;
		case 123: goto tr1024;
	}
	goto tr1020;
tr1025:
#line 141 "confscanner.rl"
	{line++;}
	goto st938;
tr1026:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 938; goto st22;} }
	goto st938;
tr1727:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 938; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 938; goto st886;} }
	goto st938;
tr1024:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 938; goto st22;} }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 938; goto st886;} }
	goto st938;
st938:
	if ( ++p == pe )
		goto _test_eof938;
case 938:
#line 17506 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st936;
		case 10: goto tr1025;
		case 13: goto st515;
		case 32: goto st936;
		case 35: goto st516;
		case 43: goto tr106;
		case 61: goto st64;
		case 97: goto st27;
		case 103: goto st127;
		case 123: goto tr246;
		case 125: goto tr1769;
	}
	goto st0;
st515:
	if ( ++p == pe )
		goto _test_eof515;
case 515:
	if ( (*p) == 10 )
		goto tr1025;
	goto st0;
st516:
	if ( ++p == pe )
		goto _test_eof516;
case 516:
	if ( (*p) == 35 )
		goto st0;
	goto tr1026;
tr480:
#line 146 "confscanner.rl"
	{arg_to_be_added_ = true;}
	goto st517;
st517:
	if ( ++p == pe )
		goto _test_eof517;
case 517:
#line 17543 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 61: goto st518;
		case 123: goto tr240;
	}
	goto st134;
tr1031:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 518; goto st22;} }
	goto st518;
tr1034:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 518; goto st22;} }
	goto st518;
st518:
	if ( ++p == pe )
		goto _test_eof518;
case 518:
#line 17575 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr498;
		case 10: goto tr499;
		case 13: goto tr1027;
		case 32: goto tr498;
		case 35: goto tr1028;
		case 40: goto st521;
		case 59: goto st0;
		case 123: goto tr240;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1030;
	} else if ( (*p) >= 65 )
		goto tr1030;
	goto st134;
tr1027:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st519;
st519:
	if ( ++p == pe )
		goto _test_eof519;
case 519:
#line 17606 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr499;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
tr1028:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st520;
st520:
	if ( ++p == pe )
		goto _test_eof520;
case 520:
#line 17631 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr992;
		case 9: goto tr1032;
		case 10: goto tr1033;
		case 13: goto tr1034;
		case 32: goto tr1032;
		case 35: goto tr239;
		case 59: goto tr992;
		case 123: goto tr1035;
	}
	goto tr1031;
tr1039:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 521; goto st22;} }
	goto st521;
tr1042:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 521; goto st22;} }
	goto st521;
st521:
	if ( ++p == pe )
		goto _test_eof521;
case 521:
#line 17662 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr519;
		case 10: goto tr520;
		case 13: goto tr1036;
		case 32: goto tr519;
		case 35: goto tr1037;
		case 59: goto st0;
		case 123: goto tr240;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1038;
	} else if ( (*p) >= 65 )
		goto tr1038;
	goto st134;
tr1036:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st522;
st522:
	if ( ++p == pe )
		goto _test_eof522;
case 522:
#line 17692 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr520;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
tr1037:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st523;
st523:
	if ( ++p == pe )
		goto _test_eof523;
case 523:
#line 17717 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr905;
		case 9: goto tr1040;
		case 10: goto tr1041;
		case 13: goto tr1042;
		case 32: goto tr1040;
		case 35: goto tr239;
		case 59: goto tr905;
		case 123: goto tr1043;
	}
	goto tr1039;
tr1038:
#line 192 "confscanner.rl"
	{tmp_p = p;/* cerr << "dlmi\n";*/}
	goto st524;
st524:
	if ( ++p == pe )
		goto _test_eof524;
case 524:
#line 17737 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 46: goto tr1044;
		case 59: goto st0;
		case 95: goto st524;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st524;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st524;
	} else
		goto st524;
	goto st134;
tr1044:
#line 22 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
  }
	goto st525;
st525:
	if ( ++p == pe )
		goto _test_eof525;
case 525:
#line 17769 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1046;
	} else if ( (*p) >= 65 )
		goto tr1046;
	goto st134;
tr1046:
#line 196 "confscanner.rl"
	{tmp_p = p;/* cerr << "dlmi2\n";*/}
	goto st526;
st526:
	if ( ++p == pe )
		goto _test_eof526;
case 526:
#line 17794 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr541;
		case 10: goto tr542;
		case 13: goto tr1047;
		case 32: goto tr541;
		case 35: goto tr1048;
		case 59: goto st0;
		case 61: goto tr1050;
		case 95: goto st526;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st526;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st526;
	} else
		goto st526;
	goto st134;
tr1056:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st527;
tr1047:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 108 "confscanner.rl"
	{
    string s(tmp_p, p-tmp_p);
    cblock_ = &((*clistmap_)[tmp_string][s]);
  }
	goto st527;
st527:
	if ( ++p == pe )
		goto _test_eof527;
case 527:
#line 17843 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr652;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
tr1057:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st528;
tr1048:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 108 "confscanner.rl"
	{
    string s(tmp_p, p-tmp_p);
    cblock_ = &((*clistmap_)[tmp_string][s]);
  }
	goto st528;
st528:
	if ( ++p == pe )
		goto _test_eof528;
case 528:
#line 17882 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr646;
		case 9: goto tr1052;
		case 10: goto tr1053;
		case 13: goto tr1054;
		case 32: goto tr1052;
		case 35: goto tr239;
		case 59: goto tr646;
		case 123: goto tr1055;
	}
	goto tr1051;
tr1051:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 529; goto st22;} }
	goto st529;
tr1054:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 529; goto st22;} }
	goto st529;
st529:
	if ( ++p == pe )
		goto _test_eof529;
case 529:
#line 17913 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr559;
		case 10: goto tr652;
		case 13: goto tr1056;
		case 32: goto tr559;
		case 35: goto tr1057;
		case 59: goto st0;
		case 61: goto st530;
		case 123: goto tr240;
	}
	goto st134;
tr1050:
#line 108 "confscanner.rl"
	{
    string s(tmp_p, p-tmp_p);
    cblock_ = &((*clistmap_)[tmp_string][s]);
  }
	goto st530;
st530:
	if ( ++p == pe )
		goto _test_eof530;
case 530:
#line 17937 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 62: goto st531;
		case 123: goto tr240;
	}
	goto st134;
tr1073:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 531; goto st22;} }
	goto st531;
tr1076:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 531; goto st22;} }
	goto st531;
st531:
	if ( ++p == pe )
		goto _test_eof531;
case 531:
#line 17969 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr563;
		case 10: goto tr564;
		case 13: goto tr1060;
		case 32: goto tr563;
		case 34: goto st533;
		case 35: goto tr1062;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
tr1060:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st532;
st532:
	if ( ++p == pe )
		goto _test_eof532;
case 532:
#line 17995 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr564;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
st533:
	if ( ++p == pe )
		goto _test_eof533;
case 533:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 34: goto st534;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
st534:
	if ( ++p == pe )
		goto _test_eof534;
case 534:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 34: goto tr1064;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
tr1068:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 535; goto st22;} }
	goto st535;
tr1064:
#line 162 "confscanner.rl"
	{
                opt=true;
                if(!arg_to_be_added_)
                  (*cblock_).clear();
                {stack[top++] = 535; goto st884;}
                }
	goto st535;
tr1071:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 535; goto st22;} }
	goto st535;
st535:
	if ( ++p == pe )
		goto _test_eof535;
case 535:
#line 18067 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr576;
		case 10: goto tr577;
		case 13: goto tr1065;
		case 32: goto tr576;
		case 35: goto tr1066;
		case 41: goto st216;
		case 44: goto st521;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
tr1065:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st536;
st536:
	if ( ++p == pe )
		goto _test_eof536;
case 536:
#line 18094 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr577;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
tr1066:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st537;
st537:
	if ( ++p == pe )
		goto _test_eof537;
case 537:
#line 18119 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr604;
		case 9: goto tr1069;
		case 10: goto tr1070;
		case 13: goto tr1071;
		case 32: goto tr1069;
		case 35: goto tr239;
		case 59: goto tr604;
		case 123: goto tr1072;
	}
	goto tr1068;
tr1062:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st538;
st538:
	if ( ++p == pe )
		goto _test_eof538;
case 538:
#line 18144 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr629;
		case 9: goto tr1074;
		case 10: goto tr1075;
		case 13: goto tr1076;
		case 32: goto tr1074;
		case 35: goto tr239;
		case 59: goto tr629;
		case 123: goto tr1077;
	}
	goto tr1073;
tr1030:
#line 192 "confscanner.rl"
	{tmp_p = p;/* cerr << "dlmi\n";*/}
	goto st539;
st539:
	if ( ++p == pe )
		goto _test_eof539;
case 539:
#line 18164 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 46: goto tr1078;
		case 59: goto st0;
		case 95: goto st539;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st539;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st539;
	} else
		goto st539;
	goto st134;
tr1078:
#line 22 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
  }
	goto st540;
st540:
	if ( ++p == pe )
		goto _test_eof540;
case 540:
#line 18196 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1080;
	} else if ( (*p) >= 65 )
		goto tr1080;
	goto st134;
tr1080:
#line 196 "confscanner.rl"
	{tmp_p = p;/* cerr << "dlmi2\n";*/}
	goto st541;
st541:
	if ( ++p == pe )
		goto _test_eof541;
case 541:
#line 18221 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr931;
		case 10: goto tr932;
		case 13: goto tr1081;
		case 32: goto tr931;
		case 35: goto tr1082;
		case 59: goto st0;
		case 61: goto tr1084;
		case 95: goto st541;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st541;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st541;
	} else
		goto st541;
	goto st134;
tr1090:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st542;
tr1081:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 108 "confscanner.rl"
	{
    string s(tmp_p, p-tmp_p);
    cblock_ = &((*clistmap_)[tmp_string][s]);
  }
	goto st542;
tr1681:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st542;
st542:
	if ( ++p == pe )
		goto _test_eof542;
case 542:
#line 18288 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr967;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
tr1091:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st543;
tr1082:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 108 "confscanner.rl"
	{
    string s(tmp_p, p-tmp_p);
    cblock_ = &((*clistmap_)[tmp_string][s]);
  }
	goto st543;
tr1682:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st543;
st543:
	if ( ++p == pe )
		goto _test_eof543;
case 543:
#line 18345 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr961;
		case 9: goto tr1086;
		case 10: goto tr1087;
		case 13: goto tr1088;
		case 32: goto tr1086;
		case 35: goto tr239;
		case 59: goto tr961;
		case 123: goto tr1089;
	}
	goto tr1085;
tr1085:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 544; goto st22;} }
	goto st544;
tr1088:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 544; goto st22;} }
	goto st544;
st544:
	if ( ++p == pe )
		goto _test_eof544;
case 544:
#line 18376 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr949;
		case 10: goto tr967;
		case 13: goto tr1090;
		case 32: goto tr949;
		case 35: goto tr1091;
		case 59: goto st0;
		case 61: goto st545;
		case 123: goto tr240;
	}
	goto st134;
tr1084:
#line 108 "confscanner.rl"
	{
    string s(tmp_p, p-tmp_p);
    cblock_ = &((*clistmap_)[tmp_string][s]);
  }
	goto st545;
tr1684:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st545;
st545:
	if ( ++p == pe )
		goto _test_eof545;
case 545:
#line 18411 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 62: goto st209;
		case 123: goto tr240;
	}
	goto st134;
tr397:
#line 237 "confscanner.rl"
	{/*cerr << "add:" << '\n';*/ tmp_p = p;}
	goto st546;
st546:
	if ( ++p == pe )
		goto _test_eof546;
case 546:
#line 18432 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 97: goto st547;
		case 123: goto tr240;
	}
	goto st134;
st547:
	if ( ++p == pe )
		goto _test_eof547;
case 547:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 114: goto st548;
		case 123: goto tr240;
	}
	goto st134;
st548:
	if ( ++p == pe )
		goto _test_eof548;
case 548:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 97: goto st549;
		case 123: goto tr240;
	}
	goto st134;
st549:
	if ( ++p == pe )
		goto _test_eof549;
case 549:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 109: goto st550;
		case 123: goto tr240;
	}
	goto st134;
st550:
	if ( ++p == pe )
		goto _test_eof550;
case 550:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 115: goto st551;
		case 123: goto tr240;
	}
	goto st134;
st551:
	if ( ++p == pe )
		goto _test_eof551;
case 551:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 41: goto tr1098;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
tr1666:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 552; goto st22;} }
	goto st552;
tr1098:
#line 53 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "docu_list: " << tmp_string << "\n";
    if(tmp_string == "params")
    {
      //cerr << "paramlist\n";
      clist_ = &param_list_;
    }
    else if(tmp_string == "return")
      clist_ = &return_list_;
  }
	goto st552;
tr1669:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 552; goto st22;} }
	goto st552;
st552:
	if ( ++p == pe )
		goto _test_eof552;
case 552:
#line 18558 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1099;
		case 10: goto tr1100;
		case 13: goto tr1101;
		case 32: goto tr1099;
		case 35: goto tr1102;
		case 43: goto tr1103;
		case 59: goto st0;
		case 61: goto st818;
		case 123: goto tr240;
	}
	goto st134;
tr1106:
#line 141 "confscanner.rl"
	{line++;}
	goto st553;
tr1113:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 553; goto st22;} }
	goto st553;
tr1099:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st553;
tr1111:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st553;
tr1114:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 553; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st553;
tr1115:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 553; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st553;
tr1667:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 553; goto st22;} }
	goto st553;
st553:
	if ( ++p == pe )
		goto _test_eof553;
case 553:
#line 18639 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st553;
		case 10: goto tr1106;
		case 13: goto tr1107;
		case 32: goto st553;
		case 35: goto tr1108;
		case 43: goto tr1109;
		case 59: goto st0;
		case 61: goto tr1110;
		case 123: goto tr246;
	}
	goto tr241;
tr1107:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st554;
tr1118:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st554;
st554:
	if ( ++p == pe )
		goto _test_eof554;
case 554:
#line 18672 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1111;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1108:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st555;
tr1119:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st555;
st555:
	if ( ++p == pe )
		goto _test_eof555;
case 555:
#line 18703 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1113;
		case 9: goto tr1114;
		case 10: goto tr1115;
		case 13: goto tr1116;
		case 32: goto tr1114;
		case 35: goto tr249;
		case 59: goto tr1113;
		case 123: goto tr1117;
	}
	goto tr1112;
tr1112:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 556; goto st22;} }
	goto st556;
tr1116:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 556; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st556;
st556:
	if ( ++p == pe )
		goto _test_eof556;
case 556:
#line 18734 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1099;
		case 10: goto tr1111;
		case 13: goto tr1118;
		case 32: goto tr1099;
		case 35: goto tr1119;
		case 43: goto tr1109;
		case 59: goto st0;
		case 61: goto tr1110;
		case 123: goto tr240;
	}
	goto tr241;
tr1736:
#line 146 "confscanner.rl"
	{arg_to_be_added_ = true;}
	goto st557;
tr1109:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 146 "confscanner.rl"
	{arg_to_be_added_ = true;}
	goto st557;
st557:
	if ( ++p == pe )
		goto _test_eof557;
case 557:
#line 18762 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 61: goto st558;
		case 123: goto tr240;
	}
	goto st136;
tr1620:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 558; goto st22;} }
	goto st558;
tr1110:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st558;
st558:
	if ( ++p == pe )
		goto _test_eof558;
case 558:
#line 18787 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1121;
		case 10: goto tr1122;
		case 13: goto tr1123;
		case 32: goto tr1121;
		case 35: goto tr1124;
		case 40: goto st563;
		case 59: goto st0;
		case 123: goto tr240;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1126;
	} else if ( (*p) >= 65 )
		goto tr1126;
	goto st136;
tr1128:
#line 141 "confscanner.rl"
	{line++;}
	goto st559;
tr1135:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 559; goto st22;} }
	goto st559;
tr1121:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st559;
tr1133:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st559;
tr1136:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 559; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st559;
tr1137:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 559; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st559;
tr1677:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 559; goto st22;} }
	goto st559;
st559:
	if ( ++p == pe )
		goto _test_eof559;
case 559:
#line 18872 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st559;
		case 10: goto tr1128;
		case 13: goto tr1129;
		case 32: goto st559;
		case 35: goto tr1130;
		case 40: goto tr1131;
		case 59: goto st0;
		case 123: goto tr246;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1132;
	} else if ( (*p) >= 65 )
		goto tr1132;
	goto tr241;
tr1129:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st560;
tr1140:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st560;
st560:
	if ( ++p == pe )
		goto _test_eof560;
case 560:
#line 18909 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1133;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1130:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st561;
tr1141:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st561;
st561:
	if ( ++p == pe )
		goto _test_eof561;
case 561:
#line 18940 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1135;
		case 9: goto tr1136;
		case 10: goto tr1137;
		case 13: goto tr1138;
		case 32: goto tr1136;
		case 35: goto tr249;
		case 59: goto tr1135;
		case 123: goto tr1139;
	}
	goto tr1134;
tr1134:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 562; goto st22;} }
	goto st562;
tr1138:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 562; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st562;
st562:
	if ( ++p == pe )
		goto _test_eof562;
case 562:
#line 18971 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1121;
		case 10: goto tr1133;
		case 13: goto tr1140;
		case 32: goto tr1121;
		case 35: goto tr1141;
		case 40: goto tr1131;
		case 59: goto st0;
		case 123: goto tr240;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1132;
	} else if ( (*p) >= 65 )
		goto tr1132;
	goto tr241;
tr1505:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 563; goto st22;} }
	goto st563;
tr1131:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st563;
st563:
	if ( ++p == pe )
		goto _test_eof563;
case 563:
#line 19001 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1142;
		case 10: goto tr1143;
		case 13: goto tr1144;
		case 32: goto tr1142;
		case 35: goto tr1145;
		case 59: goto st0;
		case 123: goto tr240;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1146;
	} else if ( (*p) >= 65 )
		goto tr1146;
	goto st136;
tr1148:
#line 141 "confscanner.rl"
	{line++;}
	goto st564;
tr1154:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 564; goto st22;} }
	goto st564;
tr1142:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st564;
tr1152:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st564;
tr1155:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 564; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st564;
tr1156:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 564; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st564;
tr1380:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 564; goto st22;} }
	goto st564;
st564:
	if ( ++p == pe )
		goto _test_eof564;
case 564:
#line 19085 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st564;
		case 10: goto tr1148;
		case 13: goto tr1149;
		case 32: goto st564;
		case 35: goto tr1150;
		case 59: goto st0;
		case 123: goto tr246;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1151;
	} else if ( (*p) >= 65 )
		goto tr1151;
	goto tr241;
tr1149:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st565;
tr1159:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st565;
st565:
	if ( ++p == pe )
		goto _test_eof565;
case 565:
#line 19121 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1152;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1150:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st566;
tr1160:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st566;
st566:
	if ( ++p == pe )
		goto _test_eof566;
case 566:
#line 19152 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1154;
		case 9: goto tr1155;
		case 10: goto tr1156;
		case 13: goto tr1157;
		case 32: goto tr1155;
		case 35: goto tr249;
		case 59: goto tr1154;
		case 123: goto tr1158;
	}
	goto tr1153;
tr1153:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 567; goto st22;} }
	goto st567;
tr1157:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 567; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st567;
st567:
	if ( ++p == pe )
		goto _test_eof567;
case 567:
#line 19183 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1142;
		case 10: goto tr1152;
		case 13: goto tr1159;
		case 32: goto tr1142;
		case 35: goto tr1160;
		case 59: goto st0;
		case 123: goto tr240;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1151;
	} else if ( (*p) >= 65 )
		goto tr1151;
	goto tr241;
tr1146:
#line 173 "confscanner.rl"
	{tmp_p = p;}
	goto st568;
tr1151:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 173 "confscanner.rl"
	{tmp_p = p;}
	goto st568;
st568:
	if ( ++p == pe )
		goto _test_eof568;
case 568:
#line 19214 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1161;
		case 10: goto tr1162;
		case 13: goto tr1163;
		case 32: goto tr1161;
		case 35: goto tr1164;
		case 59: goto st0;
		case 61: goto tr1166;
		case 95: goto st568;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st568;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st568;
	} else
		goto st568;
	goto st136;
tr1168:
#line 141 "confscanner.rl"
	{line++;}
	goto st569;
tr1174:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 569; goto st22;} }
	goto st569;
tr1179:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st569;
tr1172:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st569;
tr1175:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 569; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st569;
tr1176:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 569; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st569;
tr1426:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 569; goto st22;} }
	goto st569;
tr1161:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st569;
st569:
	if ( ++p == pe )
		goto _test_eof569;
case 569:
#line 19321 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st569;
		case 10: goto tr1168;
		case 13: goto tr1169;
		case 32: goto st569;
		case 35: goto tr1170;
		case 59: goto st0;
		case 61: goto tr1171;
		case 123: goto tr246;
	}
	goto tr241;
tr1169:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st570;
tr1180:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st570;
st570:
	if ( ++p == pe )
		goto _test_eof570;
case 570:
#line 19353 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1172;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1170:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st571;
tr1181:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st571;
st571:
	if ( ++p == pe )
		goto _test_eof571;
case 571:
#line 19384 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1174;
		case 9: goto tr1175;
		case 10: goto tr1176;
		case 13: goto tr1177;
		case 32: goto tr1175;
		case 35: goto tr249;
		case 59: goto tr1174;
		case 123: goto tr1178;
	}
	goto tr1173;
tr1173:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 572; goto st22;} }
	goto st572;
tr1177:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 572; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st572;
st572:
	if ( ++p == pe )
		goto _test_eof572;
case 572:
#line 19415 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1179;
		case 10: goto tr1172;
		case 13: goto tr1180;
		case 32: goto tr1179;
		case 35: goto tr1181;
		case 59: goto st0;
		case 61: goto tr1171;
		case 123: goto tr240;
	}
	goto tr241;
tr1166:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st573;
tr1171:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st573;
st573:
	if ( ++p == pe )
		goto _test_eof573;
case 573:
#line 19447 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 62: goto st574;
		case 123: goto tr240;
	}
	goto st136;
tr1249:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 574; goto st22;} }
	goto st574;
st574:
	if ( ++p == pe )
		goto _test_eof574;
case 574:
#line 19468 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1183;
		case 10: goto tr1184;
		case 13: goto tr1185;
		case 32: goto tr1183;
		case 34: goto st577;
		case 35: goto tr1187;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1189:
#line 141 "confscanner.rl"
	{line++;}
	goto st575;
tr1231:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 575; goto st22;} }
	goto st575;
tr1183:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st575;
tr1193:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st575;
tr1232:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 575; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st575;
tr1233:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 575; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st575;
tr1435:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 575; goto st22;} }
	goto st575;
st575:
	if ( ++p == pe )
		goto _test_eof575;
case 575:
#line 19548 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st575;
		case 10: goto tr1189;
		case 13: goto tr1190;
		case 32: goto st575;
		case 34: goto tr1191;
		case 35: goto tr1192;
		case 59: goto st0;
		case 123: goto tr246;
	}
	goto tr241;
tr1190:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st576;
tr1236:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st576;
st576:
	if ( ++p == pe )
		goto _test_eof576;
case 576:
#line 19580 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1193;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1191:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st577;
st577:
	if ( ++p == pe )
		goto _test_eof577;
case 577:
#line 19600 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 34: goto st578;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
st578:
	if ( ++p == pe )
		goto _test_eof578;
case 578:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 34: goto tr1195;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1224:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 579; goto st22;} }
	goto st579;
tr1195:
#line 162 "confscanner.rl"
	{
                opt=true;
                if(!arg_to_be_added_)
                  (*cblock_).clear();
                {stack[top++] = 579; goto st884;}
                }
	goto st579;
st579:
	if ( ++p == pe )
		goto _test_eof579;
case 579:
#line 19646 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1196;
		case 10: goto tr1197;
		case 13: goto tr1198;
		case 32: goto tr1196;
		case 35: goto tr1199;
		case 41: goto st164;
		case 44: goto st563;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1201:
#line 141 "confscanner.rl"
	{line++;}
	goto st580;
tr1206:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 580; goto st22;} }
	goto st580;
tr1196:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st580;
tr1204:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st580;
tr1207:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 580; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st580;
tr1208:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 580; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st580;
tr1368:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 580; goto st22;} }
	goto st580;
st580:
	if ( ++p == pe )
		goto _test_eof580;
case 580:
#line 19727 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st580;
		case 10: goto tr1201;
		case 13: goto tr1202;
		case 32: goto st580;
		case 35: goto tr1203;
		case 41: goto tr585;
		case 44: goto tr1131;
		case 59: goto st0;
		case 123: goto tr246;
	}
	goto tr241;
tr1202:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st581;
tr1211:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st581;
st581:
	if ( ++p == pe )
		goto _test_eof581;
case 581:
#line 19760 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1204;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1203:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st582;
tr1212:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st582;
st582:
	if ( ++p == pe )
		goto _test_eof582;
case 582:
#line 19791 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1206;
		case 9: goto tr1207;
		case 10: goto tr1208;
		case 13: goto tr1209;
		case 32: goto tr1207;
		case 35: goto tr249;
		case 59: goto tr1206;
		case 123: goto tr1210;
	}
	goto tr1205;
tr1205:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 583; goto st22;} }
	goto st583;
tr1209:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 583; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st583;
st583:
	if ( ++p == pe )
		goto _test_eof583;
case 583:
#line 19822 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1196;
		case 10: goto tr1204;
		case 13: goto tr1211;
		case 32: goto tr1196;
		case 35: goto tr1212;
		case 41: goto tr585;
		case 44: goto tr1131;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto tr241;
tr1945:
#line 141 "confscanner.rl"
	{line++;}
	goto st939;
tr1215:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 939; goto st22;} }
	goto st939;
tr1948:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st939;
tr1213:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st939;
tr1216:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 939; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st939;
tr1217:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 939; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st939;
tr1210:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 939; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 939; goto st886;} }
	goto st939;
st939:
	if ( ++p == pe )
		goto _test_eof939;
case 939:
#line 19905 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st939;
		case 10: goto tr1945;
		case 13: goto tr1946;
		case 32: goto st939;
		case 35: goto tr1947;
		case 41: goto tr585;
		case 44: goto tr1131;
		case 59: goto st0;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr246;
		case 125: goto tr1778;
	}
	goto tr241;
tr1946:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st584;
tr1949:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st584;
st584:
	if ( ++p == pe )
		goto _test_eof584;
case 584:
#line 19941 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1213;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1947:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st585;
tr1950:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st585;
st585:
	if ( ++p == pe )
		goto _test_eof585;
case 585:
#line 19972 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1215;
		case 9: goto tr1216;
		case 10: goto tr1217;
		case 13: goto tr1218;
		case 32: goto tr1216;
		case 35: goto tr249;
		case 59: goto tr1215;
		case 123: goto tr1210;
	}
	goto tr1214;
tr1214:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 940; goto st22;} }
	goto st940;
tr1218:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 940; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st940;
st940:
	if ( ++p == pe )
		goto _test_eof940;
case 940:
#line 20003 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1948;
		case 10: goto tr1213;
		case 13: goto tr1949;
		case 32: goto tr1948;
		case 35: goto tr1950;
		case 41: goto tr585;
		case 44: goto tr1131;
		case 59: goto st0;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr240;
		case 125: goto tr1778;
	}
	goto tr241;
tr1219:
#line 141 "confscanner.rl"
	{line++;}
	goto st586;
tr1222:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 586; goto st22;} }
	goto st586;
tr1197:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st586;
tr1223:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st586;
tr1225:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 586; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st586;
tr1369:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 586; goto st22;} }
#line 141 "confscanner.rl"
	{line++;}
	goto st586;
st586:
	if ( ++p == pe )
		goto _test_eof586;
case 586:
#line 20080 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st580;
		case 10: goto tr1219;
		case 13: goto st587;
		case 32: goto st580;
		case 35: goto st588;
		case 41: goto st44;
		case 44: goto st105;
		case 123: goto tr246;
	}
	goto st0;
st587:
	if ( ++p == pe )
		goto _test_eof587;
case 587:
	if ( (*p) == 10 )
		goto tr1219;
	goto st0;
st588:
	if ( ++p == pe )
		goto _test_eof588;
case 588:
	if ( (*p) == 35 )
		goto st0;
	goto tr1222;
tr1198:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st589;
st589:
	if ( ++p == pe )
		goto _test_eof589;
case 589:
#line 20119 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1223;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1199:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st590;
st590:
	if ( ++p == pe )
		goto _test_eof590;
case 590:
#line 20144 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1222;
		case 9: goto tr1207;
		case 10: goto tr1225;
		case 13: goto tr1226;
		case 32: goto tr1207;
		case 35: goto tr249;
		case 59: goto tr1222;
		case 123: goto tr1227;
	}
	goto tr1224;
tr1226:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 591; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st591;
st591:
	if ( ++p == pe )
		goto _test_eof591;
case 591:
#line 20171 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1196;
		case 10: goto tr1223;
		case 13: goto tr1198;
		case 32: goto tr1196;
		case 35: goto tr1199;
		case 41: goto st164;
		case 44: goto st563;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1228:
#line 141 "confscanner.rl"
	{line++;}
	goto st941;
tr1229:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 941; goto st22;} }
	goto st941;
tr1227:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 941; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 941; goto st886;} }
	goto st941;
tr1371:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 941; goto st22;} }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 941; goto st886;} }
	goto st941;
st941:
	if ( ++p == pe )
		goto _test_eof941;
case 941:
#line 20223 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st939;
		case 10: goto tr1228;
		case 13: goto st592;
		case 32: goto st939;
		case 35: goto st593;
		case 41: goto st44;
		case 44: goto st105;
		case 97: goto st27;
		case 103: goto st127;
		case 123: goto tr246;
		case 125: goto tr1769;
	}
	goto st0;
st592:
	if ( ++p == pe )
		goto _test_eof592;
case 592:
	if ( (*p) == 10 )
		goto tr1228;
	goto st0;
st593:
	if ( ++p == pe )
		goto _test_eof593;
case 593:
	if ( (*p) == 35 )
		goto st0;
	goto tr1229;
tr1192:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st594;
tr1237:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st594;
st594:
	if ( ++p == pe )
		goto _test_eof594;
case 594:
#line 20271 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1231;
		case 9: goto tr1232;
		case 10: goto tr1233;
		case 13: goto tr1234;
		case 32: goto tr1232;
		case 35: goto tr249;
		case 59: goto tr1231;
		case 123: goto tr1235;
	}
	goto tr1230;
tr1230:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 595; goto st22;} }
	goto st595;
tr1234:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 595; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st595;
st595:
	if ( ++p == pe )
		goto _test_eof595;
case 595:
#line 20302 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1183;
		case 10: goto tr1193;
		case 13: goto tr1236;
		case 32: goto tr1183;
		case 34: goto tr1191;
		case 35: goto tr1237;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto tr241;
tr1954:
#line 141 "confscanner.rl"
	{line++;}
	goto st942;
tr1240:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 942; goto st22;} }
	goto st942;
tr1957:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st942;
tr1238:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st942;
tr1241:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 942; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st942;
tr1242:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 942; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st942;
tr1235:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 942; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 942; goto st886;} }
	goto st942;
st942:
	if ( ++p == pe )
		goto _test_eof942;
case 942:
#line 20384 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st942;
		case 10: goto tr1954;
		case 13: goto tr1955;
		case 32: goto st942;
		case 34: goto tr1191;
		case 35: goto tr1956;
		case 59: goto st0;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr246;
		case 125: goto tr1778;
	}
	goto tr241;
tr1955:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st596;
tr1958:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st596;
st596:
	if ( ++p == pe )
		goto _test_eof596;
case 596:
#line 20419 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1238;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1956:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st597;
tr1959:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st597;
st597:
	if ( ++p == pe )
		goto _test_eof597;
case 597:
#line 20450 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1240;
		case 9: goto tr1241;
		case 10: goto tr1242;
		case 13: goto tr1243;
		case 32: goto tr1241;
		case 35: goto tr249;
		case 59: goto tr1240;
		case 123: goto tr1235;
	}
	goto tr1239;
tr1239:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 943; goto st22;} }
	goto st943;
tr1243:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 943; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st943;
st943:
	if ( ++p == pe )
		goto _test_eof943;
case 943:
#line 20481 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1957;
		case 10: goto tr1238;
		case 13: goto tr1958;
		case 32: goto tr1957;
		case 34: goto tr1191;
		case 35: goto tr1959;
		case 59: goto st0;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr240;
		case 125: goto tr1778;
	}
	goto tr241;
tr1244:
#line 141 "confscanner.rl"
	{line++;}
	goto st598;
tr1247:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 598; goto st22;} }
	goto st598;
tr1184:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st598;
tr1248:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st598;
tr1250:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 598; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st598;
tr1436:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 598; goto st22;} }
#line 141 "confscanner.rl"
	{line++;}
	goto st598;
st598:
	if ( ++p == pe )
		goto _test_eof598;
case 598:
#line 20557 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st575;
		case 10: goto tr1244;
		case 13: goto st599;
		case 32: goto st575;
		case 34: goto st115;
		case 35: goto st600;
		case 123: goto tr246;
	}
	goto st0;
st599:
	if ( ++p == pe )
		goto _test_eof599;
case 599:
	if ( (*p) == 10 )
		goto tr1244;
	goto st0;
st600:
	if ( ++p == pe )
		goto _test_eof600;
case 600:
	if ( (*p) == 35 )
		goto st0;
	goto tr1247;
tr1185:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st601;
st601:
	if ( ++p == pe )
		goto _test_eof601;
case 601:
#line 20595 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1248;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1187:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st602;
st602:
	if ( ++p == pe )
		goto _test_eof602;
case 602:
#line 20620 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1247;
		case 9: goto tr1232;
		case 10: goto tr1250;
		case 13: goto tr1251;
		case 32: goto tr1232;
		case 35: goto tr249;
		case 59: goto tr1247;
		case 123: goto tr1252;
	}
	goto tr1249;
tr1251:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 603; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st603;
st603:
	if ( ++p == pe )
		goto _test_eof603;
case 603:
#line 20647 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1183;
		case 10: goto tr1248;
		case 13: goto tr1185;
		case 32: goto tr1183;
		case 34: goto st577;
		case 35: goto tr1187;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1253:
#line 141 "confscanner.rl"
	{line++;}
	goto st944;
tr1254:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 944; goto st22;} }
	goto st944;
tr1252:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 944; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 944; goto st886;} }
	goto st944;
tr1438:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 944; goto st22;} }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 944; goto st886;} }
	goto st944;
st944:
	if ( ++p == pe )
		goto _test_eof944;
case 944:
#line 20698 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st942;
		case 10: goto tr1253;
		case 13: goto st604;
		case 32: goto st942;
		case 34: goto st115;
		case 35: goto st605;
		case 97: goto st27;
		case 103: goto st127;
		case 123: goto tr246;
		case 125: goto tr1769;
	}
	goto st0;
st604:
	if ( ++p == pe )
		goto _test_eof604;
case 604:
	if ( (*p) == 10 )
		goto tr1253;
	goto st0;
st605:
	if ( ++p == pe )
		goto _test_eof605;
case 605:
	if ( (*p) == 35 )
		goto st0;
	goto tr1254;
tr1963:
#line 141 "confscanner.rl"
	{line++;}
	goto st945;
tr1257:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 945; goto st22;} }
	goto st945;
tr1966:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st945;
tr1255:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st945;
tr1258:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 945; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st945;
tr1259:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 945; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st945;
tr1178:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 945; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 945; goto st886;} }
	goto st945;
st945:
	if ( ++p == pe )
		goto _test_eof945;
case 945:
#line 20795 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st945;
		case 10: goto tr1963;
		case 13: goto tr1964;
		case 32: goto st945;
		case 35: goto tr1965;
		case 59: goto st0;
		case 61: goto tr1171;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr246;
		case 125: goto tr1778;
	}
	goto tr241;
tr1964:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st606;
tr1967:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st606;
st606:
	if ( ++p == pe )
		goto _test_eof606;
case 606:
#line 20830 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1255;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1965:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st607;
tr1968:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st607;
st607:
	if ( ++p == pe )
		goto _test_eof607;
case 607:
#line 20861 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1257;
		case 9: goto tr1258;
		case 10: goto tr1259;
		case 13: goto tr1260;
		case 32: goto tr1258;
		case 35: goto tr249;
		case 59: goto tr1257;
		case 123: goto tr1178;
	}
	goto tr1256;
tr1256:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 946; goto st22;} }
	goto st946;
tr1260:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 946; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st946;
st946:
	if ( ++p == pe )
		goto _test_eof946;
case 946:
#line 20892 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1966;
		case 10: goto tr1255;
		case 13: goto tr1967;
		case 32: goto tr1966;
		case 35: goto tr1968;
		case 59: goto st0;
		case 61: goto tr1171;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr240;
		case 125: goto tr1778;
	}
	goto tr241;
tr1261:
#line 141 "confscanner.rl"
	{line++;}
	goto st608;
tr1264:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 608; goto st22;} }
	goto st608;
tr1270:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st608;
tr1265:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st608;
tr1267:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 608; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st608;
tr1427:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 608; goto st22;} }
#line 141 "confscanner.rl"
	{line++;}
	goto st608;
tr1162:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st608;
st608:
	if ( ++p == pe )
		goto _test_eof608;
case 608:
#line 20988 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st569;
		case 10: goto tr1261;
		case 13: goto st609;
		case 32: goto st569;
		case 35: goto st610;
		case 61: goto st112;
		case 123: goto tr246;
	}
	goto st0;
st609:
	if ( ++p == pe )
		goto _test_eof609;
case 609:
	if ( (*p) == 10 )
		goto tr1261;
	goto st0;
st610:
	if ( ++p == pe )
		goto _test_eof610;
case 610:
	if ( (*p) == 35 )
		goto st0;
	goto tr1264;
tr1271:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st611;
tr1163:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st611;
st611:
	if ( ++p == pe )
		goto _test_eof611;
case 611:
#line 21044 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1265;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1272:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st612;
tr1164:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st612;
st612:
	if ( ++p == pe )
		goto _test_eof612;
case 612:
#line 21087 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1264;
		case 9: goto tr1175;
		case 10: goto tr1267;
		case 13: goto tr1268;
		case 32: goto tr1175;
		case 35: goto tr249;
		case 59: goto tr1264;
		case 123: goto tr1269;
	}
	goto tr1266;
tr1266:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 613; goto st22;} }
	goto st613;
st613:
	if ( ++p == pe )
		goto _test_eof613;
case 613:
#line 21107 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1179;
		case 10: goto tr1270;
		case 13: goto tr1271;
		case 32: goto tr1179;
		case 35: goto tr1272;
		case 59: goto st0;
		case 61: goto st573;
		case 123: goto tr240;
	}
	goto st136;
tr1268:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 614; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st614;
st614:
	if ( ++p == pe )
		goto _test_eof614;
case 614:
#line 21135 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1179;
		case 10: goto tr1265;
		case 13: goto tr1271;
		case 32: goto tr1179;
		case 35: goto tr1272;
		case 59: goto st0;
		case 61: goto st573;
		case 123: goto tr240;
	}
	goto st136;
tr1274:
#line 141 "confscanner.rl"
	{line++;}
	goto st947;
tr1275:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 947; goto st22;} }
	goto st947;
tr1269:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 947; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 947; goto st886;} }
	goto st947;
tr1429:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 947; goto st22;} }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 947; goto st886;} }
	goto st947;
st947:
	if ( ++p == pe )
		goto _test_eof947;
case 947:
#line 21186 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st945;
		case 10: goto tr1274;
		case 13: goto st615;
		case 32: goto st945;
		case 35: goto st616;
		case 61: goto st112;
		case 97: goto st27;
		case 103: goto st127;
		case 123: goto tr246;
		case 125: goto tr1769;
	}
	goto st0;
st615:
	if ( ++p == pe )
		goto _test_eof615;
case 615:
	if ( (*p) == 10 )
		goto tr1274;
	goto st0;
st616:
	if ( ++p == pe )
		goto _test_eof616;
case 616:
	if ( (*p) == 35 )
		goto st0;
	goto tr1275;
tr1972:
#line 141 "confscanner.rl"
	{line++;}
	goto st948;
tr1278:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 948; goto st22;} }
	goto st948;
tr1977:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st948;
tr1276:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st948;
tr1279:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 948; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st948;
tr1280:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 948; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st948;
tr1158:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 948; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 948; goto st886;} }
	goto st948;
st948:
	if ( ++p == pe )
		goto _test_eof948;
case 948:
#line 21283 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st948;
		case 10: goto tr1972;
		case 13: goto tr1973;
		case 32: goto st948;
		case 35: goto tr1974;
		case 59: goto st0;
		case 97: goto tr1975;
		case 103: goto tr1976;
		case 123: goto tr246;
		case 125: goto tr1778;
	}
	if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr1151;
	} else if ( (*p) >= 65 )
		goto tr1151;
	goto tr241;
tr1973:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st617;
tr1978:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st617;
st617:
	if ( ++p == pe )
		goto _test_eof617;
case 617:
#line 21322 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1276;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1974:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st618;
tr1979:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st618;
st618:
	if ( ++p == pe )
		goto _test_eof618;
case 618:
#line 21353 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1278;
		case 9: goto tr1279;
		case 10: goto tr1280;
		case 13: goto tr1281;
		case 32: goto tr1279;
		case 35: goto tr249;
		case 59: goto tr1278;
		case 123: goto tr1158;
	}
	goto tr1277;
tr1277:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 949; goto st22;} }
	goto st949;
tr1281:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 949; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st949;
st949:
	if ( ++p == pe )
		goto _test_eof949;
case 949:
#line 21384 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1977;
		case 10: goto tr1276;
		case 13: goto tr1978;
		case 32: goto tr1977;
		case 35: goto tr1979;
		case 59: goto st0;
		case 97: goto tr1975;
		case 103: goto tr1976;
		case 123: goto tr240;
		case 125: goto tr1778;
	}
	if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr1151;
	} else if ( (*p) >= 65 )
		goto tr1151;
	goto tr241;
tr1975:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 173 "confscanner.rl"
	{tmp_p = p;}
	goto st619;
st619:
	if ( ++p == pe )
		goto _test_eof619;
case 619:
#line 21414 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1161;
		case 10: goto tr1162;
		case 13: goto tr1163;
		case 32: goto tr1161;
		case 35: goto tr1164;
		case 59: goto st0;
		case 61: goto tr1166;
		case 95: goto st568;
		case 100: goto st620;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st568;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st568;
	} else
		goto st568;
	goto st136;
st620:
	if ( ++p == pe )
		goto _test_eof620;
case 620:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1161;
		case 10: goto tr1162;
		case 13: goto tr1163;
		case 32: goto tr1161;
		case 35: goto tr1164;
		case 59: goto st0;
		case 61: goto tr1166;
		case 95: goto st568;
		case 100: goto st621;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st568;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st568;
	} else
		goto st568;
	goto st136;
st621:
	if ( ++p == pe )
		goto _test_eof621;
case 621:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1161;
		case 10: goto tr1162;
		case 13: goto tr1163;
		case 32: goto tr1161;
		case 35: goto tr1164;
		case 40: goto st147;
		case 59: goto st0;
		case 61: goto tr1166;
		case 95: goto st568;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st568;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st568;
	} else
		goto st568;
	goto st136;
tr1976:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 173 "confscanner.rl"
	{tmp_p = p;}
	goto st622;
st622:
	if ( ++p == pe )
		goto _test_eof622;
case 622:
#line 21499 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1161;
		case 10: goto tr1162;
		case 13: goto tr1163;
		case 32: goto tr1161;
		case 35: goto tr1164;
		case 59: goto st0;
		case 61: goto tr1166;
		case 95: goto st568;
		case 108: goto st623;
		case 114: goto st710;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st568;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st568;
	} else
		goto st568;
	goto st136;
st623:
	if ( ++p == pe )
		goto _test_eof623;
case 623:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1161;
		case 10: goto tr1162;
		case 13: goto tr1163;
		case 32: goto tr1161;
		case 35: goto tr1164;
		case 59: goto st0;
		case 61: goto tr1166;
		case 95: goto st568;
		case 111: goto st624;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st568;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st568;
	} else
		goto st568;
	goto st136;
st624:
	if ( ++p == pe )
		goto _test_eof624;
case 624:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1161;
		case 10: goto tr1162;
		case 13: goto tr1163;
		case 32: goto tr1161;
		case 35: goto tr1164;
		case 59: goto st0;
		case 61: goto tr1166;
		case 95: goto st568;
		case 98: goto st625;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st568;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st568;
	} else
		goto st568;
	goto st136;
st625:
	if ( ++p == pe )
		goto _test_eof625;
case 625:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1288;
		case 10: goto tr1289;
		case 13: goto tr1290;
		case 32: goto tr1288;
		case 35: goto tr1291;
		case 59: goto st0;
		case 61: goto tr1292;
		case 95: goto st568;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st568;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st568;
	} else
		goto st568;
	goto st136;
tr1294:
#line 141 "confscanner.rl"
	{line++;}
	goto st626;
tr1300:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 626; goto st22;} }
	goto st626;
tr1305:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st626;
tr1298:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st626;
tr1301:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 626; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st626;
tr1302:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 626; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st626;
tr1288:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st626;
st626:
	if ( ++p == pe )
		goto _test_eof626;
case 626:
#line 21674 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st626;
		case 10: goto tr1294;
		case 13: goto tr1295;
		case 32: goto st626;
		case 35: goto tr1296;
		case 59: goto st0;
		case 61: goto tr1297;
		case 123: goto tr246;
	}
	goto tr241;
tr1295:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st627;
tr1306:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st627;
st627:
	if ( ++p == pe )
		goto _test_eof627;
case 627:
#line 21706 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1298;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1296:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st628;
tr1307:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st628;
st628:
	if ( ++p == pe )
		goto _test_eof628;
case 628:
#line 21737 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1300;
		case 9: goto tr1301;
		case 10: goto tr1302;
		case 13: goto tr1303;
		case 32: goto tr1301;
		case 35: goto tr249;
		case 59: goto tr1300;
		case 123: goto tr1304;
	}
	goto tr1299;
tr1299:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 629; goto st22;} }
	goto st629;
tr1303:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 629; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st629;
st629:
	if ( ++p == pe )
		goto _test_eof629;
case 629:
#line 21768 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1305;
		case 10: goto tr1298;
		case 13: goto tr1306;
		case 32: goto tr1305;
		case 35: goto tr1307;
		case 59: goto st0;
		case 61: goto tr1297;
		case 123: goto tr240;
	}
	goto tr241;
tr1292:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st630;
tr1297:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st630;
st630:
	if ( ++p == pe )
		goto _test_eof630;
case 630:
#line 21800 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr361;
		case 10: goto tr362;
		case 13: goto tr363;
		case 32: goto tr361;
		case 35: goto tr364;
		case 59: goto st0;
		case 62: goto tr1308;
		case 123: goto tr240;
	}
	goto tr231;
tr1309:
#line 141 "confscanner.rl"
	{line++;}
	goto st631;
tr1312:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 631; goto st22;} }
	goto st631;
tr362:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st631;
tr1313:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 631; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st631;
st631:
	if ( ++p == pe )
		goto _test_eof631;
case 631:
#line 21849 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st180;
		case 10: goto tr1309;
		case 13: goto tr233;
		case 32: goto st180;
		case 35: goto tr1310;
		case 59: goto st0;
		case 123: goto tr246;
	}
	goto tr231;
tr233:
#line 213 "confscanner.rl"
	{/*cerr << "glob_list";*/ tmp_p = p;}
	goto st632;
tr363:
#line 213 "confscanner.rl"
	{/*cerr << "glob_list";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st632;
st632:
	if ( ++p == pe )
		goto _test_eof632;
case 632:
#line 21880 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr362;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
tr1310:
#line 213 "confscanner.rl"
	{/*cerr << "glob_list";*/ tmp_p = p;}
	goto st633;
tr364:
#line 213 "confscanner.rl"
	{/*cerr << "glob_list";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st633;
st633:
	if ( ++p == pe )
		goto _test_eof633;
case 633:
#line 21911 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1312;
		case 9: goto tr378;
		case 10: goto tr1313;
		case 13: goto tr1314;
		case 32: goto tr378;
		case 35: goto tr239;
		case 59: goto tr1312;
		case 123: goto tr1315;
	}
	goto tr1311;
tr1980:
#line 141 "confscanner.rl"
	{line++;}
	goto st950;
tr1318:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 950; goto st22;} }
	goto st950;
tr1316:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st950;
tr1319:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 950; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st950;
tr1315:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 950; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 950; goto st886;} }
	goto st950;
st950:
	if ( ++p == pe )
		goto _test_eof950;
case 950:
#line 21972 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st892;
		case 10: goto tr1980;
		case 13: goto tr1981;
		case 32: goto st892;
		case 35: goto tr1982;
		case 59: goto st0;
		case 97: goto tr1983;
		case 103: goto tr1984;
		case 123: goto tr246;
		case 125: goto tr1985;
	}
	goto tr231;
tr1981:
#line 213 "confscanner.rl"
	{/*cerr << "glob_list";*/ tmp_p = p;}
	goto st634;
tr1986:
#line 213 "confscanner.rl"
	{/*cerr << "glob_list";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st634;
st634:
	if ( ++p == pe )
		goto _test_eof634;
case 634:
#line 22006 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1316;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
tr1982:
#line 213 "confscanner.rl"
	{/*cerr << "glob_list";*/ tmp_p = p;}
	goto st635;
tr1987:
#line 213 "confscanner.rl"
	{/*cerr << "glob_list";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st635;
st635:
	if ( ++p == pe )
		goto _test_eof635;
case 635:
#line 22037 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1318;
		case 9: goto tr387;
		case 10: goto tr1319;
		case 13: goto tr1320;
		case 32: goto tr387;
		case 35: goto tr239;
		case 59: goto tr1318;
		case 123: goto tr1315;
	}
	goto tr1317;
tr1317:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 951; goto st22;} }
	goto st951;
tr1320:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 951; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st951;
st951:
	if ( ++p == pe )
		goto _test_eof951;
case 951:
#line 22068 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1796;
		case 10: goto tr1316;
		case 13: goto tr1986;
		case 32: goto tr1796;
		case 35: goto tr1987;
		case 59: goto st0;
		case 97: goto tr1983;
		case 103: goto tr1984;
		case 123: goto tr240;
		case 125: goto tr1985;
	}
	goto tr231;
tr1984:
#line 213 "confscanner.rl"
	{/*cerr << "glob_list";*/ tmp_p = p;}
	goto st636;
tr1794:
#line 213 "confscanner.rl"
	{/*cerr << "glob_list";*/ tmp_p = p;}
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st636;
st636:
	if ( ++p == pe )
		goto _test_eof636;
case 636:
#line 22097 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 108: goto st637;
		case 114: goto st642;
		case 123: goto tr240;
	}
	goto st134;
st637:
	if ( ++p == pe )
		goto _test_eof637;
case 637:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 111: goto st638;
		case 123: goto tr240;
	}
	goto st134;
st638:
	if ( ++p == pe )
		goto _test_eof638;
case 638:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 98: goto st639;
		case 123: goto tr240;
	}
	goto st134;
tr1327:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 639; goto st22;} }
	goto st639;
tr1328:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 639; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st639;
st639:
	if ( ++p == pe )
		goto _test_eof639;
case 639:
#line 22162 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr342;
		case 10: goto tr343;
		case 13: goto tr1325;
		case 32: goto tr342;
		case 35: goto tr1326;
		case 59: goto st0;
		case 61: goto st179;
		case 123: goto tr240;
	}
	goto st134;
tr1325:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st640;
st640:
	if ( ++p == pe )
		goto _test_eof640;
case 640:
#line 22188 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr343;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
tr1326:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st641;
st641:
	if ( ++p == pe )
		goto _test_eof641;
case 641:
#line 22213 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr673;
		case 9: goto tr355;
		case 10: goto tr675;
		case 13: goto tr1328;
		case 32: goto tr355;
		case 35: goto tr239;
		case 59: goto tr673;
		case 123: goto tr677;
	}
	goto tr1327;
st642:
	if ( ++p == pe )
		goto _test_eof642;
case 642:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 111: goto st643;
		case 123: goto tr240;
	}
	goto st134;
st643:
	if ( ++p == pe )
		goto _test_eof643;
case 643:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 117: goto st644;
		case 123: goto tr240;
	}
	goto st134;
st644:
	if ( ++p == pe )
		goto _test_eof644;
case 644:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 112: goto st645;
		case 123: goto tr240;
	}
	goto st134;
st645:
	if ( ++p == pe )
		goto _test_eof645;
case 645:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 115: goto st646;
		case 123: goto tr240;
	}
	goto st134;
tr1337:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 646; goto st22;} }
	goto st646;
tr1340:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 646; goto st22;} }
	goto st646;
st646:
	if ( ++p == pe )
		goto _test_eof646;
case 646:
#line 22308 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr690;
		case 10: goto tr691;
		case 13: goto tr1333;
		case 32: goto tr690;
		case 35: goto tr1334;
		case 43: goto tr1335;
		case 59: goto st0;
		case 61: goto st650;
		case 123: goto tr240;
	}
	goto st134;
tr1333:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st647;
st647:
	if ( ++p == pe )
		goto _test_eof647;
case 647:
#line 22335 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr691;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
tr1334:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st648;
st648:
	if ( ++p == pe )
		goto _test_eof648;
case 648:
#line 22360 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr894;
		case 9: goto tr1338;
		case 10: goto tr1339;
		case 13: goto tr1340;
		case 32: goto tr1338;
		case 35: goto tr239;
		case 59: goto tr894;
		case 123: goto tr1341;
	}
	goto tr1337;
tr1335:
#line 146 "confscanner.rl"
	{arg_to_be_added_ = true;}
	goto st649;
st649:
	if ( ++p == pe )
		goto _test_eof649;
case 649:
#line 22380 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 61: goto st650;
		case 123: goto tr240;
	}
	goto st134;
tr1345:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 650; goto st22;} }
	goto st650;
tr1348:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 650; goto st22;} }
	goto st650;
st650:
	if ( ++p == pe )
		goto _test_eof650;
case 650:
#line 22412 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr711;
		case 10: goto tr712;
		case 13: goto tr1342;
		case 32: goto tr711;
		case 35: goto tr1343;
		case 59: goto st0;
		case 123: goto tr240;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1344;
	} else if ( (*p) >= 65 )
		goto tr1344;
	goto st134;
tr1342:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st651;
st651:
	if ( ++p == pe )
		goto _test_eof651;
case 651:
#line 22442 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr712;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
tr1343:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st652;
st652:
	if ( ++p == pe )
		goto _test_eof652;
case 652:
#line 22467 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr849;
		case 9: goto tr1346;
		case 10: goto tr1347;
		case 13: goto tr1348;
		case 32: goto tr1346;
		case 35: goto tr239;
		case 59: goto tr849;
		case 123: goto tr1349;
	}
	goto tr1345;
tr1344:
#line 20 "confscanner.rl"
	{ /*cerr << "st_tok" << line << "\n";*/ tmp_p = p; }
	goto st653;
st653:
	if ( ++p == pe )
		goto _test_eof653;
case 653:
#line 22487 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr730;
		case 10: goto tr731;
		case 13: goto tr1350;
		case 32: goto tr730;
		case 35: goto tr1351;
		case 44: goto tr1352;
		case 59: goto tr736;
		case 95: goto st653;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st653;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st653;
	} else
		goto st653;
	goto st134;
tr1352:
#line 27 "confscanner.rl"
	{
//    cerr << "in group add: " << endl;
    if(match_at_level_[level_])
    {
//      cerr << "do it" << endl;
      tmp_string.assign(tmp_p, p-tmp_p);
      // clear groupset_ first, if we did not use '+='
      if(!arg_to_be_added_)
        groupset_.clear();

      groupset_.insert(tmp_string);
    }
  }
	goto st654;
st654:
	if ( ++p == pe )
		goto _test_eof654;
case 654:
#line 22529 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1344;
	} else if ( (*p) >= 65 )
		goto tr1344;
	goto st134;
tr1355:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 952; goto st22;} }
	goto st952;
tr1358:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 952; goto st22;} }
	goto st952;
tr1992:
#line 260 "confscanner.rl"
	{ go_level_down(); {cs = stack[--top];goto _again;} }
	goto st952;
tr1795:
#line 213 "confscanner.rl"
	{/*cerr << "glob_list";*/ tmp_p = p;}
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 260 "confscanner.rl"
	{ go_level_down(); {cs = stack[--top];goto _again;} }
	goto st952;
tr1985:
#line 213 "confscanner.rl"
	{/*cerr << "glob_list";*/ tmp_p = p;}
#line 260 "confscanner.rl"
	{ go_level_down(); {cs = stack[--top];goto _again;} }
	goto st952;
st952:
	if ( ++p == pe )
		goto _test_eof952;
case 952:
#line 22583 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1779;
		case 10: goto tr1354;
		case 13: goto tr1988;
		case 32: goto tr1779;
		case 35: goto tr1989;
		case 59: goto st0;
		case 97: goto st187;
		case 103: goto st636;
		case 123: goto tr240;
		case 125: goto tr1992;
	}
	goto st134;
tr1988:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st655;
st655:
	if ( ++p == pe )
		goto _test_eof655;
case 655:
#line 22611 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1354;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
tr1989:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st656;
st656:
	if ( ++p == pe )
		goto _test_eof656;
case 656:
#line 22636 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr425;
		case 9: goto tr1356;
		case 10: goto tr1357;
		case 13: goto tr1358;
		case 32: goto tr1356;
		case 35: goto tr239;
		case 59: goto tr425;
		case 123: goto tr375;
	}
	goto tr1355;
tr1434:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 657; goto st22;} }
	goto st657;
tr1308:
#line 213 "confscanner.rl"
	{/*cerr << "glob_list";*/ tmp_p = p;}
	goto st657;
tr1437:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 657; goto st22;} }
	goto st657;
st657:
	if ( ++p == pe )
		goto _test_eof657;
case 657:
#line 22671 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1183;
		case 10: goto tr1184;
		case 13: goto tr1359;
		case 32: goto tr1183;
		case 34: goto st659;
		case 35: goto tr1361;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
tr1359:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st658;
st658:
	if ( ++p == pe )
		goto _test_eof658;
case 658:
#line 22697 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1184;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
st659:
	if ( ++p == pe )
		goto _test_eof659;
case 659:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 34: goto st660;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
st660:
	if ( ++p == pe )
		goto _test_eof660;
case 660:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 34: goto tr1363;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
tr1367:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 661; goto st22;} }
	goto st661;
tr1363:
#line 162 "confscanner.rl"
	{
                opt=true;
                if(!arg_to_be_added_)
                  (*cblock_).clear();
                {stack[top++] = 661; goto st884;}
                }
	goto st661;
tr1370:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 661; goto st22;} }
	goto st661;
st661:
	if ( ++p == pe )
		goto _test_eof661;
case 661:
#line 22769 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1196;
		case 10: goto tr1197;
		case 13: goto tr1364;
		case 32: goto tr1196;
		case 35: goto tr1365;
		case 41: goto st216;
		case 44: goto st664;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
tr1364:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st662;
st662:
	if ( ++p == pe )
		goto _test_eof662;
case 662:
#line 22796 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1197;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
tr1365:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st663;
st663:
	if ( ++p == pe )
		goto _test_eof663;
case 663:
#line 22821 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1222;
		case 9: goto tr1368;
		case 10: goto tr1369;
		case 13: goto tr1370;
		case 32: goto tr1368;
		case 35: goto tr239;
		case 59: goto tr1222;
		case 123: goto tr1371;
	}
	goto tr1367;
tr1379:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 664; goto st22;} }
	goto st664;
tr1382:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 664; goto st22;} }
	goto st664;
st664:
	if ( ++p == pe )
		goto _test_eof664;
case 664:
#line 22852 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1142;
		case 10: goto tr1143;
		case 13: goto tr1372;
		case 32: goto tr1142;
		case 35: goto tr1373;
		case 59: goto st0;
		case 123: goto tr240;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1374;
	} else if ( (*p) >= 65 )
		goto tr1374;
	goto st134;
tr1375:
#line 141 "confscanner.rl"
	{line++;}
	goto st665;
tr1378:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 665; goto st22;} }
	goto st665;
tr1143:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st665;
tr1504:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st665;
tr1506:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 665; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st665;
tr1381:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 665; goto st22;} }
#line 141 "confscanner.rl"
	{line++;}
	goto st665;
st665:
	if ( ++p == pe )
		goto _test_eof665;
case 665:
#line 22929 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st564;
		case 10: goto tr1375;
		case 13: goto st666;
		case 32: goto st564;
		case 35: goto st667;
		case 123: goto tr246;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr185;
	} else if ( (*p) >= 65 )
		goto tr185;
	goto st0;
st666:
	if ( ++p == pe )
		goto _test_eof666;
case 666:
	if ( (*p) == 10 )
		goto tr1375;
	goto st0;
st667:
	if ( ++p == pe )
		goto _test_eof667;
case 667:
	if ( (*p) == 35 )
		goto st0;
	goto tr1378;
tr1372:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st668;
st668:
	if ( ++p == pe )
		goto _test_eof668;
case 668:
#line 22971 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1143;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
tr1373:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st669;
st669:
	if ( ++p == pe )
		goto _test_eof669;
case 669:
#line 22996 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1378;
		case 9: goto tr1380;
		case 10: goto tr1381;
		case 13: goto tr1382;
		case 32: goto tr1380;
		case 35: goto tr239;
		case 59: goto tr1378;
		case 123: goto tr1383;
	}
	goto tr1379;
tr1384:
#line 141 "confscanner.rl"
	{line++;}
	goto st953;
tr1385:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 953; goto st22;} }
	goto st953;
tr1508:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 953; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 953; goto st886;} }
	goto st953;
tr1383:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 953; goto st22;} }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 953; goto st886;} }
	goto st953;
st953:
	if ( ++p == pe )
		goto _test_eof953;
case 953:
#line 23046 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st948;
		case 10: goto tr1384;
		case 13: goto st670;
		case 32: goto st948;
		case 35: goto st671;
		case 97: goto tr1995;
		case 103: goto tr1996;
		case 123: goto tr246;
		case 125: goto tr1769;
	}
	if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr185;
	} else if ( (*p) >= 65 )
		goto tr185;
	goto st0;
st670:
	if ( ++p == pe )
		goto _test_eof670;
case 670:
	if ( (*p) == 10 )
		goto tr1384;
	goto st0;
st671:
	if ( ++p == pe )
		goto _test_eof671;
case 671:
	if ( (*p) == 35 )
		goto st0;
	goto tr1385;
tr1995:
#line 173 "confscanner.rl"
	{tmp_p = p;}
	goto st672;
st672:
	if ( ++p == pe )
		goto _test_eof672;
case 672:
#line 23086 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto tr187;
		case 10: goto tr188;
		case 13: goto tr189;
		case 32: goto tr187;
		case 35: goto tr190;
		case 61: goto tr192;
		case 95: goto st108;
		case 100: goto st673;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st108;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st108;
	} else
		goto st108;
	goto st0;
st673:
	if ( ++p == pe )
		goto _test_eof673;
case 673:
	switch( (*p) ) {
		case 9: goto tr187;
		case 10: goto tr188;
		case 13: goto tr189;
		case 32: goto tr187;
		case 35: goto tr190;
		case 61: goto tr192;
		case 95: goto st108;
		case 100: goto st674;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st108;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st108;
	} else
		goto st108;
	goto st0;
st674:
	if ( ++p == pe )
		goto _test_eof674;
case 674:
	switch( (*p) ) {
		case 9: goto tr187;
		case 10: goto tr188;
		case 13: goto tr189;
		case 32: goto tr187;
		case 35: goto tr190;
		case 40: goto st30;
		case 61: goto tr192;
		case 95: goto st108;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st108;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st108;
	} else
		goto st108;
	goto st0;
tr1996:
#line 173 "confscanner.rl"
	{tmp_p = p;}
	goto st675;
st675:
	if ( ++p == pe )
		goto _test_eof675;
case 675:
#line 23160 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto tr187;
		case 10: goto tr188;
		case 13: goto tr189;
		case 32: goto tr187;
		case 35: goto tr190;
		case 61: goto tr192;
		case 95: goto st108;
		case 108: goto st676;
		case 114: goto st685;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st108;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st108;
	} else
		goto st108;
	goto st0;
st676:
	if ( ++p == pe )
		goto _test_eof676;
case 676:
	switch( (*p) ) {
		case 9: goto tr187;
		case 10: goto tr188;
		case 13: goto tr189;
		case 32: goto tr187;
		case 35: goto tr190;
		case 61: goto tr192;
		case 95: goto st108;
		case 111: goto st677;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st108;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st108;
	} else
		goto st108;
	goto st0;
st677:
	if ( ++p == pe )
		goto _test_eof677;
case 677:
	switch( (*p) ) {
		case 9: goto tr187;
		case 10: goto tr188;
		case 13: goto tr189;
		case 32: goto tr187;
		case 35: goto tr190;
		case 61: goto tr192;
		case 95: goto st108;
		case 98: goto st678;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st108;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st108;
	} else
		goto st108;
	goto st0;
st678:
	if ( ++p == pe )
		goto _test_eof678;
case 678:
	switch( (*p) ) {
		case 9: goto tr1392;
		case 10: goto tr1393;
		case 13: goto tr1394;
		case 32: goto tr1392;
		case 35: goto tr1395;
		case 61: goto tr1396;
		case 95: goto st108;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st108;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st108;
	} else
		goto st108;
	goto st0;
tr1398:
#line 141 "confscanner.rl"
	{line++;}
	goto st679;
tr1402:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 679; goto st22;} }
	goto st679;
tr1392:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st679;
tr1393:
#line 141 "confscanner.rl"
	{line++;}
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st679;
st679:
	if ( ++p == pe )
		goto _test_eof679;
case 679:
#line 23285 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st679;
		case 10: goto tr1398;
		case 13: goto st680;
		case 32: goto st679;
		case 35: goto st681;
		case 61: goto st682;
	}
	goto st0;
tr1394:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st680;
st680:
	if ( ++p == pe )
		goto _test_eof680;
case 680:
#line 23310 "confscanner.cc"
	if ( (*p) == 10 )
		goto tr1398;
	goto st0;
tr1395:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st681;
st681:
	if ( ++p == pe )
		goto _test_eof681;
case 681:
#line 23329 "confscanner.cc"
	if ( (*p) == 35 )
		goto st0;
	goto tr1402;
tr1396:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st682;
st682:
	if ( ++p == pe )
		goto _test_eof682;
case 682:
#line 23348 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st133;
		case 10: goto tr232;
		case 13: goto tr233;
		case 32: goto st133;
		case 35: goto tr234;
		case 59: goto st0;
		case 62: goto tr1308;
		case 123: goto st0;
	}
	goto tr231;
tr234:
#line 213 "confscanner.rl"
	{/*cerr << "glob_list";*/ tmp_p = p;}
	goto st683;
st683:
	if ( ++p == pe )
		goto _test_eof683;
case 683:
#line 23369 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1403;
		case 9: goto tr378;
		case 10: goto tr1313;
		case 13: goto tr1314;
		case 32: goto tr378;
		case 35: goto tr239;
		case 59: goto tr1403;
		case 123: goto tr1404;
	}
	goto tr1311;
tr1998:
#line 141 "confscanner.rl"
	{line++;}
	goto st954;
tr1405:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 954; goto st22;} }
	goto st954;
tr1404:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 954; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 954; goto st886;} }
	goto st954;
st954:
	if ( ++p == pe )
		goto _test_eof954;
case 954:
#line 23406 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st954;
		case 10: goto tr1998;
		case 13: goto tr1981;
		case 32: goto st954;
		case 35: goto tr1999;
		case 59: goto st0;
		case 97: goto tr1983;
		case 103: goto tr1984;
		case 123: goto st0;
		case 125: goto tr1985;
	}
	goto tr231;
tr1999:
#line 213 "confscanner.rl"
	{/*cerr << "glob_list";*/ tmp_p = p;}
	goto st684;
st684:
	if ( ++p == pe )
		goto _test_eof684;
case 684:
#line 23429 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1405;
		case 9: goto tr387;
		case 10: goto tr1319;
		case 13: goto tr1320;
		case 32: goto tr387;
		case 35: goto tr239;
		case 59: goto tr1405;
		case 123: goto tr1404;
	}
	goto tr1317;
st685:
	if ( ++p == pe )
		goto _test_eof685;
case 685:
	switch( (*p) ) {
		case 9: goto tr187;
		case 10: goto tr188;
		case 13: goto tr189;
		case 32: goto tr187;
		case 35: goto tr190;
		case 61: goto tr192;
		case 95: goto st108;
		case 111: goto st686;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st108;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st108;
	} else
		goto st108;
	goto st0;
st686:
	if ( ++p == pe )
		goto _test_eof686;
case 686:
	switch( (*p) ) {
		case 9: goto tr187;
		case 10: goto tr188;
		case 13: goto tr189;
		case 32: goto tr187;
		case 35: goto tr190;
		case 61: goto tr192;
		case 95: goto st108;
		case 117: goto st687;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st108;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st108;
	} else
		goto st108;
	goto st0;
st687:
	if ( ++p == pe )
		goto _test_eof687;
case 687:
	switch( (*p) ) {
		case 9: goto tr187;
		case 10: goto tr188;
		case 13: goto tr189;
		case 32: goto tr187;
		case 35: goto tr190;
		case 61: goto tr192;
		case 95: goto st108;
		case 112: goto st688;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st108;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st108;
	} else
		goto st108;
	goto st0;
st688:
	if ( ++p == pe )
		goto _test_eof688;
case 688:
	switch( (*p) ) {
		case 9: goto tr187;
		case 10: goto tr188;
		case 13: goto tr189;
		case 32: goto tr187;
		case 35: goto tr190;
		case 61: goto tr192;
		case 95: goto st108;
		case 115: goto st689;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st108;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st108;
	} else
		goto st108;
	goto st0;
st689:
	if ( ++p == pe )
		goto _test_eof689;
case 689:
	switch( (*p) ) {
		case 9: goto tr1410;
		case 10: goto tr1411;
		case 13: goto tr1412;
		case 32: goto tr1410;
		case 35: goto tr1413;
		case 43: goto tr822;
		case 61: goto tr1414;
		case 95: goto st108;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st108;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st108;
	} else
		goto st108;
	goto st0;
tr1416:
#line 141 "confscanner.rl"
	{line++;}
	goto st690;
tr1420:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 690; goto st22;} }
	goto st690;
tr1410:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st690;
tr1411:
#line 141 "confscanner.rl"
	{line++;}
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st690;
st690:
	if ( ++p == pe )
		goto _test_eof690;
case 690:
#line 23592 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st690;
		case 10: goto tr1416;
		case 13: goto st691;
		case 32: goto st690;
		case 35: goto st692;
		case 43: goto tr822;
		case 61: goto st693;
	}
	goto st0;
tr1412:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st691;
st691:
	if ( ++p == pe )
		goto _test_eof691;
case 691:
#line 23618 "confscanner.cc"
	if ( (*p) == 10 )
		goto tr1416;
	goto st0;
tr1413:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st692;
st692:
	if ( ++p == pe )
		goto _test_eof692;
case 692:
#line 23637 "confscanner.cc"
	if ( (*p) == 35 )
		goto st0;
	goto tr1420;
tr1414:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st693;
st693:
	if ( ++p == pe )
		goto _test_eof693;
case 693:
#line 23656 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st384;
		case 10: goto tr825;
		case 13: goto st385;
		case 32: goto st384;
		case 35: goto st386;
		case 62: goto st113;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr828;
	} else if ( (*p) >= 65 )
		goto tr828;
	goto st0;
tr1374:
#line 173 "confscanner.rl"
	{tmp_p = p;}
	goto st694;
st694:
	if ( ++p == pe )
		goto _test_eof694;
case 694:
#line 23679 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1161;
		case 10: goto tr1162;
		case 13: goto tr1421;
		case 32: goto tr1161;
		case 35: goto tr1422;
		case 59: goto st0;
		case 61: goto tr1424;
		case 95: goto st694;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st694;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st694;
	} else
		goto st694;
	goto st134;
tr1430:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st695;
tr1421:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st695;
st695:
	if ( ++p == pe )
		goto _test_eof695;
case 695:
#line 23732 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1270;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
tr1431:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st696;
tr1422:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st696;
st696:
	if ( ++p == pe )
		goto _test_eof696;
case 696:
#line 23775 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1264;
		case 9: goto tr1426;
		case 10: goto tr1427;
		case 13: goto tr1428;
		case 32: goto tr1426;
		case 35: goto tr239;
		case 59: goto tr1264;
		case 123: goto tr1429;
	}
	goto tr1425;
tr1425:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 697; goto st22;} }
	goto st697;
tr1428:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 697; goto st22;} }
	goto st697;
st697:
	if ( ++p == pe )
		goto _test_eof697;
case 697:
#line 23806 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1179;
		case 10: goto tr1270;
		case 13: goto tr1430;
		case 32: goto tr1179;
		case 35: goto tr1431;
		case 59: goto st0;
		case 61: goto st698;
		case 123: goto tr240;
	}
	goto st134;
tr1424:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st698;
st698:
	if ( ++p == pe )
		goto _test_eof698;
case 698:
#line 23834 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 62: goto st657;
		case 123: goto tr240;
	}
	goto st134;
tr1361:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st699;
st699:
	if ( ++p == pe )
		goto _test_eof699;
case 699:
#line 23860 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1247;
		case 9: goto tr1435;
		case 10: goto tr1436;
		case 13: goto tr1437;
		case 32: goto tr1435;
		case 35: goto tr239;
		case 59: goto tr1247;
		case 123: goto tr1438;
	}
	goto tr1434;
tr2001:
#line 141 "confscanner.rl"
	{line++;}
	goto st955;
tr1441:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 955; goto st22;} }
	goto st955;
tr2004:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st955;
tr1439:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st955;
tr1442:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 955; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st955;
tr1443:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 955; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st955;
tr1304:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 955; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 955; goto st886;} }
	goto st955;
st955:
	if ( ++p == pe )
		goto _test_eof955;
case 955:
#line 23941 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st955;
		case 10: goto tr2001;
		case 13: goto tr2002;
		case 32: goto st955;
		case 35: goto tr2003;
		case 59: goto st0;
		case 61: goto tr1297;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr246;
		case 125: goto tr1778;
	}
	goto tr241;
tr2002:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st700;
tr2005:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st700;
st700:
	if ( ++p == pe )
		goto _test_eof700;
case 700:
#line 23976 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1439;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr2003:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st701;
tr2006:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st701;
st701:
	if ( ++p == pe )
		goto _test_eof701;
case 701:
#line 24007 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1441;
		case 9: goto tr1442;
		case 10: goto tr1443;
		case 13: goto tr1444;
		case 32: goto tr1442;
		case 35: goto tr249;
		case 59: goto tr1441;
		case 123: goto tr1304;
	}
	goto tr1440;
tr1440:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 956; goto st22;} }
	goto st956;
tr1444:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 956; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st956;
st956:
	if ( ++p == pe )
		goto _test_eof956;
case 956:
#line 24038 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr2004;
		case 10: goto tr1439;
		case 13: goto tr2005;
		case 32: goto tr2004;
		case 35: goto tr2006;
		case 59: goto st0;
		case 61: goto tr1297;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr240;
		case 125: goto tr1778;
	}
	goto tr241;
tr1445:
#line 141 "confscanner.rl"
	{line++;}
	goto st702;
tr1448:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 702; goto st22;} }
	goto st702;
tr1449:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st702;
tr1451:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 702; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st702;
tr1289:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st702;
st702:
	if ( ++p == pe )
		goto _test_eof702;
case 702:
#line 24110 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st626;
		case 10: goto tr1445;
		case 13: goto st703;
		case 32: goto st626;
		case 35: goto st704;
		case 61: goto st682;
		case 123: goto tr246;
	}
	goto st0;
st703:
	if ( ++p == pe )
		goto _test_eof703;
case 703:
	if ( (*p) == 10 )
		goto tr1445;
	goto st0;
st704:
	if ( ++p == pe )
		goto _test_eof704;
case 704:
	if ( (*p) == 35 )
		goto st0;
	goto tr1448;
tr1454:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st705;
tr1290:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st705;
st705:
	if ( ++p == pe )
		goto _test_eof705;
case 705:
#line 24166 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1449;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1455:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st706;
tr1291:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st706;
st706:
	if ( ++p == pe )
		goto _test_eof706;
case 706:
#line 24209 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1448;
		case 9: goto tr1301;
		case 10: goto tr1451;
		case 13: goto tr1452;
		case 32: goto tr1301;
		case 35: goto tr249;
		case 59: goto tr1448;
		case 123: goto tr1453;
	}
	goto tr1450;
tr1450:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 707; goto st22;} }
	goto st707;
tr1452:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 707; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st707;
st707:
	if ( ++p == pe )
		goto _test_eof707;
case 707:
#line 24240 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1305;
		case 10: goto tr1449;
		case 13: goto tr1454;
		case 32: goto tr1305;
		case 35: goto tr1455;
		case 59: goto st0;
		case 61: goto st630;
		case 123: goto tr240;
	}
	goto st136;
tr1457:
#line 141 "confscanner.rl"
	{line++;}
	goto st957;
tr1458:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 957; goto st22;} }
	goto st957;
tr1453:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 957; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 957; goto st886;} }
	goto st957;
st957:
	if ( ++p == pe )
		goto _test_eof957;
case 957:
#line 24278 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st955;
		case 10: goto tr1457;
		case 13: goto st708;
		case 32: goto st955;
		case 35: goto st709;
		case 61: goto st682;
		case 97: goto st27;
		case 103: goto st127;
		case 123: goto tr246;
		case 125: goto tr1769;
	}
	goto st0;
st708:
	if ( ++p == pe )
		goto _test_eof708;
case 708:
	if ( (*p) == 10 )
		goto tr1457;
	goto st0;
st709:
	if ( ++p == pe )
		goto _test_eof709;
case 709:
	if ( (*p) == 35 )
		goto st0;
	goto tr1458;
st710:
	if ( ++p == pe )
		goto _test_eof710;
case 710:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1161;
		case 10: goto tr1162;
		case 13: goto tr1163;
		case 32: goto tr1161;
		case 35: goto tr1164;
		case 59: goto st0;
		case 61: goto tr1166;
		case 95: goto st568;
		case 111: goto st711;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st568;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st568;
	} else
		goto st568;
	goto st136;
st711:
	if ( ++p == pe )
		goto _test_eof711;
case 711:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1161;
		case 10: goto tr1162;
		case 13: goto tr1163;
		case 32: goto tr1161;
		case 35: goto tr1164;
		case 59: goto st0;
		case 61: goto tr1166;
		case 95: goto st568;
		case 117: goto st712;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st568;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st568;
	} else
		goto st568;
	goto st136;
st712:
	if ( ++p == pe )
		goto _test_eof712;
case 712:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1161;
		case 10: goto tr1162;
		case 13: goto tr1163;
		case 32: goto tr1161;
		case 35: goto tr1164;
		case 59: goto st0;
		case 61: goto tr1166;
		case 95: goto st568;
		case 112: goto st713;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st568;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st568;
	} else
		goto st568;
	goto st136;
st713:
	if ( ++p == pe )
		goto _test_eof713;
case 713:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1161;
		case 10: goto tr1162;
		case 13: goto tr1163;
		case 32: goto tr1161;
		case 35: goto tr1164;
		case 59: goto st0;
		case 61: goto tr1166;
		case 95: goto st568;
		case 115: goto st714;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st568;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st568;
	} else
		goto st568;
	goto st136;
st714:
	if ( ++p == pe )
		goto _test_eof714;
case 714:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1463;
		case 10: goto tr1464;
		case 13: goto tr1465;
		case 32: goto tr1463;
		case 35: goto tr1466;
		case 43: goto tr694;
		case 59: goto st0;
		case 61: goto tr1467;
		case 95: goto st568;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st568;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st568;
	} else
		goto st568;
	goto st136;
tr1469:
#line 141 "confscanner.rl"
	{line++;}
	goto st715;
tr1475:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 715; goto st22;} }
	goto st715;
tr1480:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st715;
tr1473:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st715;
tr1476:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 715; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st715;
tr1477:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 715; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st715;
tr1463:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st715;
st715:
	if ( ++p == pe )
		goto _test_eof715;
case 715:
#line 24510 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st715;
		case 10: goto tr1469;
		case 13: goto tr1470;
		case 32: goto st715;
		case 35: goto tr1471;
		case 43: goto tr700;
		case 59: goto st0;
		case 61: goto tr1472;
		case 123: goto tr246;
	}
	goto tr241;
tr1470:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st716;
tr1481:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st716;
st716:
	if ( ++p == pe )
		goto _test_eof716;
case 716:
#line 24543 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1473;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1471:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st717;
tr1482:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st717;
st717:
	if ( ++p == pe )
		goto _test_eof717;
case 717:
#line 24574 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1475;
		case 9: goto tr1476;
		case 10: goto tr1477;
		case 13: goto tr1478;
		case 32: goto tr1476;
		case 35: goto tr249;
		case 59: goto tr1475;
		case 123: goto tr1479;
	}
	goto tr1474;
tr1474:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 718; goto st22;} }
	goto st718;
tr1478:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 718; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st718;
st718:
	if ( ++p == pe )
		goto _test_eof718;
case 718:
#line 24605 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1480;
		case 10: goto tr1473;
		case 13: goto tr1481;
		case 32: goto tr1480;
		case 35: goto tr1482;
		case 43: goto tr700;
		case 59: goto st0;
		case 61: goto tr1472;
		case 123: goto tr240;
	}
	goto tr241;
tr1467:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st719;
tr1472:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st719;
st719:
	if ( ++p == pe )
		goto _test_eof719;
case 719:
#line 24638 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr711;
		case 10: goto tr712;
		case 13: goto tr713;
		case 32: goto tr711;
		case 35: goto tr714;
		case 59: goto st0;
		case 62: goto st574;
		case 123: goto tr240;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr715;
	} else if ( (*p) >= 65 )
		goto tr715;
	goto st136;
tr2010:
#line 141 "confscanner.rl"
	{line++;}
	goto st958;
tr1485:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 958; goto st22;} }
	goto st958;
tr2013:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st958;
tr1483:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st958;
tr1486:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 958; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st958;
tr1487:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 958; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st958;
tr1479:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 958; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 958; goto st886;} }
	goto st958;
st958:
	if ( ++p == pe )
		goto _test_eof958;
case 958:
#line 24725 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st958;
		case 10: goto tr2010;
		case 13: goto tr2011;
		case 32: goto st958;
		case 35: goto tr2012;
		case 43: goto tr700;
		case 59: goto st0;
		case 61: goto tr1472;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr246;
		case 125: goto tr1778;
	}
	goto tr241;
tr2011:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st720;
tr2014:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st720;
st720:
	if ( ++p == pe )
		goto _test_eof720;
case 720:
#line 24761 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1483;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr2012:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st721;
tr2015:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st721;
st721:
	if ( ++p == pe )
		goto _test_eof721;
case 721:
#line 24792 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1485;
		case 9: goto tr1486;
		case 10: goto tr1487;
		case 13: goto tr1488;
		case 32: goto tr1486;
		case 35: goto tr249;
		case 59: goto tr1485;
		case 123: goto tr1479;
	}
	goto tr1484;
tr1484:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 959; goto st22;} }
	goto st959;
tr1488:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 959; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st959;
st959:
	if ( ++p == pe )
		goto _test_eof959;
case 959:
#line 24823 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr2013;
		case 10: goto tr1483;
		case 13: goto tr2014;
		case 32: goto tr2013;
		case 35: goto tr2015;
		case 43: goto tr700;
		case 59: goto st0;
		case 61: goto tr1472;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr240;
		case 125: goto tr1778;
	}
	goto tr241;
tr1489:
#line 141 "confscanner.rl"
	{line++;}
	goto st722;
tr1492:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 722; goto st22;} }
	goto st722;
tr1498:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st722;
tr1493:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st722;
tr1495:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 722; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st722;
tr1464:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st722;
st722:
	if ( ++p == pe )
		goto _test_eof722;
case 722:
#line 24907 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st715;
		case 10: goto tr1489;
		case 13: goto st723;
		case 32: goto st715;
		case 35: goto st724;
		case 43: goto tr822;
		case 61: goto st693;
		case 123: goto tr246;
	}
	goto st0;
st723:
	if ( ++p == pe )
		goto _test_eof723;
case 723:
	if ( (*p) == 10 )
		goto tr1489;
	goto st0;
st724:
	if ( ++p == pe )
		goto _test_eof724;
case 724:
	if ( (*p) == 35 )
		goto st0;
	goto tr1492;
tr1499:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st725;
tr1465:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st725;
st725:
	if ( ++p == pe )
		goto _test_eof725;
case 725:
#line 24964 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1493;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1500:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st726;
tr1466:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st726;
st726:
	if ( ++p == pe )
		goto _test_eof726;
case 726:
#line 25007 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1492;
		case 9: goto tr1476;
		case 10: goto tr1495;
		case 13: goto tr1496;
		case 32: goto tr1476;
		case 35: goto tr249;
		case 59: goto tr1492;
		case 123: goto tr1497;
	}
	goto tr1494;
tr1494:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 727; goto st22;} }
	goto st727;
st727:
	if ( ++p == pe )
		goto _test_eof727;
case 727:
#line 25027 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1480;
		case 10: goto tr1498;
		case 13: goto tr1499;
		case 32: goto tr1480;
		case 35: goto tr1500;
		case 43: goto tr694;
		case 59: goto st0;
		case 61: goto st719;
		case 123: goto tr240;
	}
	goto st136;
tr1496:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 728; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st728;
st728:
	if ( ++p == pe )
		goto _test_eof728;
case 728:
#line 25056 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1480;
		case 10: goto tr1493;
		case 13: goto tr1499;
		case 32: goto tr1480;
		case 35: goto tr1500;
		case 43: goto tr694;
		case 59: goto st0;
		case 61: goto st719;
		case 123: goto tr240;
	}
	goto st136;
tr1502:
#line 141 "confscanner.rl"
	{line++;}
	goto st960;
tr1503:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 960; goto st22;} }
	goto st960;
tr1497:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 960; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 960; goto st886;} }
	goto st960;
st960:
	if ( ++p == pe )
		goto _test_eof960;
case 960:
#line 25095 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st958;
		case 10: goto tr1502;
		case 13: goto st729;
		case 32: goto st958;
		case 35: goto st730;
		case 43: goto tr822;
		case 61: goto st693;
		case 97: goto st27;
		case 103: goto st127;
		case 123: goto tr246;
		case 125: goto tr1769;
	}
	goto st0;
st729:
	if ( ++p == pe )
		goto _test_eof729;
case 729:
	if ( (*p) == 10 )
		goto tr1502;
	goto st0;
st730:
	if ( ++p == pe )
		goto _test_eof730;
case 730:
	if ( (*p) == 35 )
		goto st0;
	goto tr1503;
tr1144:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st731;
st731:
	if ( ++p == pe )
		goto _test_eof731;
case 731:
#line 25137 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1504;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1145:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st732;
st732:
	if ( ++p == pe )
		goto _test_eof732;
case 732:
#line 25162 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1378;
		case 9: goto tr1155;
		case 10: goto tr1506;
		case 13: goto tr1507;
		case 32: goto tr1155;
		case 35: goto tr249;
		case 59: goto tr1378;
		case 123: goto tr1508;
	}
	goto tr1505;
tr1507:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 733; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st733;
st733:
	if ( ++p == pe )
		goto _test_eof733;
case 733:
#line 25189 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1142;
		case 10: goto tr1504;
		case 13: goto tr1144;
		case 32: goto tr1142;
		case 35: goto tr1145;
		case 59: goto st0;
		case 123: goto tr240;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1146;
	} else if ( (*p) >= 65 )
		goto tr1146;
	goto st136;
tr1126:
#line 173 "confscanner.rl"
	{tmp_p = p;}
	goto st734;
tr1132:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 173 "confscanner.rl"
	{tmp_p = p;}
	goto st734;
st734:
	if ( ++p == pe )
		goto _test_eof734;
case 734:
#line 25220 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1509;
		case 10: goto tr1510;
		case 13: goto tr1511;
		case 32: goto tr1509;
		case 35: goto tr1512;
		case 59: goto st0;
		case 61: goto tr1514;
		case 95: goto st734;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st734;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st734;
	} else
		goto st734;
	goto st136;
tr2019:
#line 141 "confscanner.rl"
	{line++;}
	goto st961;
tr1517:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 961; goto st22;} }
	goto st961;
tr2024:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st961;
tr1515:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st961;
tr1518:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 961; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st961;
tr1519:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 961; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st961;
tr1139:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 961; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 961; goto st886;} }
	goto st961;
st961:
	if ( ++p == pe )
		goto _test_eof961;
case 961:
#line 25311 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st961;
		case 10: goto tr2019;
		case 13: goto tr2020;
		case 32: goto st961;
		case 35: goto tr2021;
		case 40: goto tr1131;
		case 59: goto st0;
		case 97: goto tr2022;
		case 103: goto tr2023;
		case 123: goto tr246;
		case 125: goto tr1778;
	}
	if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr1132;
	} else if ( (*p) >= 65 )
		goto tr1132;
	goto tr241;
tr2020:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st735;
tr2025:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st735;
st735:
	if ( ++p == pe )
		goto _test_eof735;
case 735:
#line 25351 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1515;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr2021:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st736;
tr2026:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st736;
st736:
	if ( ++p == pe )
		goto _test_eof736;
case 736:
#line 25382 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1517;
		case 9: goto tr1518;
		case 10: goto tr1519;
		case 13: goto tr1520;
		case 32: goto tr1518;
		case 35: goto tr249;
		case 59: goto tr1517;
		case 123: goto tr1139;
	}
	goto tr1516;
tr1516:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 962; goto st22;} }
	goto st962;
tr1520:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 962; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st962;
st962:
	if ( ++p == pe )
		goto _test_eof962;
case 962:
#line 25413 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr2024;
		case 10: goto tr1515;
		case 13: goto tr2025;
		case 32: goto tr2024;
		case 35: goto tr2026;
		case 40: goto tr1131;
		case 59: goto st0;
		case 97: goto tr2022;
		case 103: goto tr2023;
		case 123: goto tr240;
		case 125: goto tr1778;
	}
	if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr1132;
	} else if ( (*p) >= 65 )
		goto tr1132;
	goto tr241;
tr2022:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 173 "confscanner.rl"
	{tmp_p = p;}
	goto st737;
st737:
	if ( ++p == pe )
		goto _test_eof737;
case 737:
#line 25444 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1509;
		case 10: goto tr1510;
		case 13: goto tr1511;
		case 32: goto tr1509;
		case 35: goto tr1512;
		case 59: goto st0;
		case 61: goto tr1514;
		case 95: goto st734;
		case 100: goto st738;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st734;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st734;
	} else
		goto st734;
	goto st136;
st738:
	if ( ++p == pe )
		goto _test_eof738;
case 738:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1509;
		case 10: goto tr1510;
		case 13: goto tr1511;
		case 32: goto tr1509;
		case 35: goto tr1512;
		case 59: goto st0;
		case 61: goto tr1514;
		case 95: goto st734;
		case 100: goto st739;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st734;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st734;
	} else
		goto st734;
	goto st136;
st739:
	if ( ++p == pe )
		goto _test_eof739;
case 739:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1509;
		case 10: goto tr1510;
		case 13: goto tr1511;
		case 32: goto tr1509;
		case 35: goto tr1512;
		case 40: goto st147;
		case 59: goto st0;
		case 61: goto tr1514;
		case 95: goto st734;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st734;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st734;
	} else
		goto st734;
	goto st136;
tr2023:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 173 "confscanner.rl"
	{tmp_p = p;}
	goto st740;
st740:
	if ( ++p == pe )
		goto _test_eof740;
case 740:
#line 25529 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1509;
		case 10: goto tr1510;
		case 13: goto tr1511;
		case 32: goto tr1509;
		case 35: goto tr1512;
		case 59: goto st0;
		case 61: goto tr1514;
		case 95: goto st734;
		case 108: goto st741;
		case 114: goto st760;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st734;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st734;
	} else
		goto st734;
	goto st136;
st741:
	if ( ++p == pe )
		goto _test_eof741;
case 741:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1509;
		case 10: goto tr1510;
		case 13: goto tr1511;
		case 32: goto tr1509;
		case 35: goto tr1512;
		case 59: goto st0;
		case 61: goto tr1514;
		case 95: goto st734;
		case 111: goto st742;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st734;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st734;
	} else
		goto st734;
	goto st136;
st742:
	if ( ++p == pe )
		goto _test_eof742;
case 742:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1509;
		case 10: goto tr1510;
		case 13: goto tr1511;
		case 32: goto tr1509;
		case 35: goto tr1512;
		case 59: goto st0;
		case 61: goto tr1514;
		case 95: goto st734;
		case 98: goto st743;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st734;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st734;
	} else
		goto st734;
	goto st136;
st743:
	if ( ++p == pe )
		goto _test_eof743;
case 743:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1527;
		case 10: goto tr1528;
		case 13: goto tr1529;
		case 32: goto tr1527;
		case 35: goto tr1530;
		case 59: goto st0;
		case 61: goto tr1531;
		case 95: goto st734;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st734;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st734;
	} else
		goto st734;
	goto st136;
tr1533:
#line 141 "confscanner.rl"
	{line++;}
	goto st744;
tr1539:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 744; goto st22;} }
	goto st744;
tr1544:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st744;
tr1537:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st744;
tr1540:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 744; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st744;
tr1541:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 744; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st744;
tr1527:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st744;
st744:
	if ( ++p == pe )
		goto _test_eof744;
case 744:
#line 25704 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st744;
		case 10: goto tr1533;
		case 13: goto tr1534;
		case 32: goto st744;
		case 35: goto tr1535;
		case 59: goto st0;
		case 61: goto tr1536;
		case 123: goto tr246;
	}
	goto tr241;
tr1534:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st745;
tr1545:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st745;
st745:
	if ( ++p == pe )
		goto _test_eof745;
case 745:
#line 25736 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1537;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1535:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st746;
tr1546:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st746;
st746:
	if ( ++p == pe )
		goto _test_eof746;
case 746:
#line 25767 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1539;
		case 9: goto tr1540;
		case 10: goto tr1541;
		case 13: goto tr1542;
		case 32: goto tr1540;
		case 35: goto tr249;
		case 59: goto tr1539;
		case 123: goto tr1543;
	}
	goto tr1538;
tr1538:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 747; goto st22;} }
	goto st747;
tr1542:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 747; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st747;
st747:
	if ( ++p == pe )
		goto _test_eof747;
case 747:
#line 25798 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1544;
		case 10: goto tr1537;
		case 13: goto tr1545;
		case 32: goto tr1544;
		case 35: goto tr1546;
		case 59: goto st0;
		case 61: goto tr1536;
		case 123: goto tr240;
	}
	goto tr241;
tr1531:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st748;
tr1536:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st748;
st748:
	if ( ++p == pe )
		goto _test_eof748;
case 748:
#line 25830 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr361;
		case 10: goto tr362;
		case 13: goto tr363;
		case 32: goto tr361;
		case 35: goto tr364;
		case 59: goto st0;
		case 62: goto tr1547;
		case 123: goto tr240;
	}
	goto tr231;
tr2028:
#line 141 "confscanner.rl"
	{line++;}
	goto st963;
tr1550:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 963; goto st22;} }
	goto st963;
tr2031:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st963;
tr1548:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st963;
tr1551:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 963; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st963;
tr1552:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 963; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st963;
tr1543:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 963; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 963; goto st886;} }
	goto st963;
st963:
	if ( ++p == pe )
		goto _test_eof963;
case 963:
#line 25912 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st963;
		case 10: goto tr2028;
		case 13: goto tr2029;
		case 32: goto st963;
		case 35: goto tr2030;
		case 59: goto st0;
		case 61: goto tr1536;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr246;
		case 125: goto tr1778;
	}
	goto tr241;
tr2029:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st749;
tr2032:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st749;
st749:
	if ( ++p == pe )
		goto _test_eof749;
case 749:
#line 25947 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1548;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr2030:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st750;
tr2033:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st750;
st750:
	if ( ++p == pe )
		goto _test_eof750;
case 750:
#line 25978 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1550;
		case 9: goto tr1551;
		case 10: goto tr1552;
		case 13: goto tr1553;
		case 32: goto tr1551;
		case 35: goto tr249;
		case 59: goto tr1550;
		case 123: goto tr1543;
	}
	goto tr1549;
tr1549:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 964; goto st22;} }
	goto st964;
tr1553:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 964; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st964;
st964:
	if ( ++p == pe )
		goto _test_eof964;
case 964:
#line 26009 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr2031;
		case 10: goto tr1548;
		case 13: goto tr2032;
		case 32: goto tr2031;
		case 35: goto tr2033;
		case 59: goto st0;
		case 61: goto tr1536;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr240;
		case 125: goto tr1778;
	}
	goto tr241;
tr1554:
#line 141 "confscanner.rl"
	{line++;}
	goto st751;
tr1558:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 751; goto st22;} }
	goto st751;
tr1559:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st751;
tr1561:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 751; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st751;
tr1528:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st751;
st751:
	if ( ++p == pe )
		goto _test_eof751;
case 751:
#line 26081 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st744;
		case 10: goto tr1554;
		case 13: goto st752;
		case 32: goto st744;
		case 35: goto st753;
		case 61: goto st754;
		case 123: goto tr246;
	}
	goto st0;
st752:
	if ( ++p == pe )
		goto _test_eof752;
case 752:
	if ( (*p) == 10 )
		goto tr1554;
	goto st0;
st753:
	if ( ++p == pe )
		goto _test_eof753;
case 753:
	if ( (*p) == 35 )
		goto st0;
	goto tr1558;
tr1636:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st754;
st754:
	if ( ++p == pe )
		goto _test_eof754;
case 754:
#line 26121 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st133;
		case 10: goto tr232;
		case 13: goto tr233;
		case 32: goto st133;
		case 35: goto tr234;
		case 59: goto st0;
		case 62: goto tr1547;
		case 123: goto st0;
	}
	goto tr231;
tr1564:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st755;
tr1529:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st755;
st755:
	if ( ++p == pe )
		goto _test_eof755;
case 755:
#line 26165 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1559;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1565:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st756;
tr1530:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st756;
st756:
	if ( ++p == pe )
		goto _test_eof756;
case 756:
#line 26208 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1558;
		case 9: goto tr1540;
		case 10: goto tr1561;
		case 13: goto tr1562;
		case 32: goto tr1540;
		case 35: goto tr249;
		case 59: goto tr1558;
		case 123: goto tr1563;
	}
	goto tr1560;
tr1560:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 757; goto st22;} }
	goto st757;
tr1562:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 757; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st757;
st757:
	if ( ++p == pe )
		goto _test_eof757;
case 757:
#line 26239 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1544;
		case 10: goto tr1559;
		case 13: goto tr1564;
		case 32: goto tr1544;
		case 35: goto tr1565;
		case 59: goto st0;
		case 61: goto st748;
		case 123: goto tr240;
	}
	goto st136;
tr1567:
#line 141 "confscanner.rl"
	{line++;}
	goto st965;
tr1568:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 965; goto st22;} }
	goto st965;
tr1563:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 965; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 965; goto st886;} }
	goto st965;
st965:
	if ( ++p == pe )
		goto _test_eof965;
case 965:
#line 26277 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st963;
		case 10: goto tr1567;
		case 13: goto st758;
		case 32: goto st963;
		case 35: goto st759;
		case 61: goto st754;
		case 97: goto st27;
		case 103: goto st127;
		case 123: goto tr246;
		case 125: goto tr1769;
	}
	goto st0;
st758:
	if ( ++p == pe )
		goto _test_eof758;
case 758:
	if ( (*p) == 10 )
		goto tr1567;
	goto st0;
st759:
	if ( ++p == pe )
		goto _test_eof759;
case 759:
	if ( (*p) == 35 )
		goto st0;
	goto tr1568;
st760:
	if ( ++p == pe )
		goto _test_eof760;
case 760:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1509;
		case 10: goto tr1510;
		case 13: goto tr1511;
		case 32: goto tr1509;
		case 35: goto tr1512;
		case 59: goto st0;
		case 61: goto tr1514;
		case 95: goto st734;
		case 111: goto st761;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st734;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st734;
	} else
		goto st734;
	goto st136;
st761:
	if ( ++p == pe )
		goto _test_eof761;
case 761:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1509;
		case 10: goto tr1510;
		case 13: goto tr1511;
		case 32: goto tr1509;
		case 35: goto tr1512;
		case 59: goto st0;
		case 61: goto tr1514;
		case 95: goto st734;
		case 117: goto st762;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st734;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st734;
	} else
		goto st734;
	goto st136;
st762:
	if ( ++p == pe )
		goto _test_eof762;
case 762:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1509;
		case 10: goto tr1510;
		case 13: goto tr1511;
		case 32: goto tr1509;
		case 35: goto tr1512;
		case 59: goto st0;
		case 61: goto tr1514;
		case 95: goto st734;
		case 112: goto st763;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st734;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st734;
	} else
		goto st734;
	goto st136;
st763:
	if ( ++p == pe )
		goto _test_eof763;
case 763:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1509;
		case 10: goto tr1510;
		case 13: goto tr1511;
		case 32: goto tr1509;
		case 35: goto tr1512;
		case 59: goto st0;
		case 61: goto tr1514;
		case 95: goto st734;
		case 115: goto st764;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st734;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st734;
	} else
		goto st734;
	goto st136;
st764:
	if ( ++p == pe )
		goto _test_eof764;
case 764:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1573;
		case 10: goto tr1574;
		case 13: goto tr1575;
		case 32: goto tr1573;
		case 35: goto tr1576;
		case 43: goto tr694;
		case 59: goto st0;
		case 61: goto tr1577;
		case 95: goto st734;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st734;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st734;
	} else
		goto st734;
	goto st136;
tr1579:
#line 141 "confscanner.rl"
	{line++;}
	goto st765;
tr1585:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 765; goto st22;} }
	goto st765;
tr1590:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st765;
tr1583:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st765;
tr1586:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 765; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st765;
tr1587:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 765; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st765;
tr1573:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st765;
st765:
	if ( ++p == pe )
		goto _test_eof765;
case 765:
#line 26509 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st765;
		case 10: goto tr1579;
		case 13: goto tr1580;
		case 32: goto st765;
		case 35: goto tr1581;
		case 43: goto tr700;
		case 59: goto st0;
		case 61: goto tr1582;
		case 123: goto tr246;
	}
	goto tr241;
tr1580:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st766;
tr1591:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st766;
st766:
	if ( ++p == pe )
		goto _test_eof766;
case 766:
#line 26542 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1583;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1581:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st767;
tr1592:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st767;
st767:
	if ( ++p == pe )
		goto _test_eof767;
case 767:
#line 26573 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1585;
		case 9: goto tr1586;
		case 10: goto tr1587;
		case 13: goto tr1588;
		case 32: goto tr1586;
		case 35: goto tr249;
		case 59: goto tr1585;
		case 123: goto tr1589;
	}
	goto tr1584;
tr1584:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 768; goto st22;} }
	goto st768;
tr1588:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 768; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st768;
st768:
	if ( ++p == pe )
		goto _test_eof768;
case 768:
#line 26604 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1590;
		case 10: goto tr1583;
		case 13: goto tr1591;
		case 32: goto tr1590;
		case 35: goto tr1592;
		case 43: goto tr700;
		case 59: goto st0;
		case 61: goto tr1582;
		case 123: goto tr240;
	}
	goto tr241;
tr1577:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st769;
tr1582:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st769;
st769:
	if ( ++p == pe )
		goto _test_eof769;
case 769:
#line 26637 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr711;
		case 10: goto tr712;
		case 13: goto tr713;
		case 32: goto tr711;
		case 35: goto tr714;
		case 59: goto st0;
		case 62: goto st159;
		case 123: goto tr240;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr715;
	} else if ( (*p) >= 65 )
		goto tr715;
	goto st136;
tr2037:
#line 141 "confscanner.rl"
	{line++;}
	goto st966;
tr1595:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 966; goto st22;} }
	goto st966;
tr2040:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st966;
tr1593:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st966;
tr1596:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 966; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st966;
tr1597:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 966; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st966;
tr1589:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 966; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 966; goto st886;} }
	goto st966;
st966:
	if ( ++p == pe )
		goto _test_eof966;
case 966:
#line 26724 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st966;
		case 10: goto tr2037;
		case 13: goto tr2038;
		case 32: goto st966;
		case 35: goto tr2039;
		case 43: goto tr700;
		case 59: goto st0;
		case 61: goto tr1582;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr246;
		case 125: goto tr1778;
	}
	goto tr241;
tr2038:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st770;
tr2041:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st770;
st770:
	if ( ++p == pe )
		goto _test_eof770;
case 770:
#line 26760 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1593;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr2039:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st771;
tr2042:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st771;
st771:
	if ( ++p == pe )
		goto _test_eof771;
case 771:
#line 26791 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1595;
		case 9: goto tr1596;
		case 10: goto tr1597;
		case 13: goto tr1598;
		case 32: goto tr1596;
		case 35: goto tr249;
		case 59: goto tr1595;
		case 123: goto tr1589;
	}
	goto tr1594;
tr1594:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 967; goto st22;} }
	goto st967;
tr1598:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 967; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st967;
st967:
	if ( ++p == pe )
		goto _test_eof967;
case 967:
#line 26822 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr2040;
		case 10: goto tr1593;
		case 13: goto tr2041;
		case 32: goto tr2040;
		case 35: goto tr2042;
		case 43: goto tr700;
		case 59: goto st0;
		case 61: goto tr1582;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr240;
		case 125: goto tr1778;
	}
	goto tr241;
tr1599:
#line 141 "confscanner.rl"
	{line++;}
	goto st772;
tr1603:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 772; goto st22;} }
	goto st772;
tr1609:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st772;
tr1604:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st772;
tr1606:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 772; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st772;
tr1574:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st772;
st772:
	if ( ++p == pe )
		goto _test_eof772;
case 772:
#line 26906 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st765;
		case 10: goto tr1599;
		case 13: goto st773;
		case 32: goto st765;
		case 35: goto st774;
		case 43: goto tr822;
		case 61: goto st775;
		case 123: goto tr246;
	}
	goto st0;
st773:
	if ( ++p == pe )
		goto _test_eof773;
case 773:
	if ( (*p) == 10 )
		goto tr1599;
	goto st0;
st774:
	if ( ++p == pe )
		goto _test_eof774;
case 774:
	if ( (*p) == 35 )
		goto st0;
	goto tr1603;
tr1650:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st775;
st775:
	if ( ++p == pe )
		goto _test_eof775;
case 775:
#line 26947 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st384;
		case 10: goto tr825;
		case 13: goto st385;
		case 32: goto st384;
		case 35: goto st386;
		case 62: goto st40;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr828;
	} else if ( (*p) >= 65 )
		goto tr828;
	goto st0;
tr1610:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st776;
tr1575:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st776;
st776:
	if ( ++p == pe )
		goto _test_eof776;
case 776:
#line 26993 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1604;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1611:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st777;
tr1576:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st777;
st777:
	if ( ++p == pe )
		goto _test_eof777;
case 777:
#line 27036 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1603;
		case 9: goto tr1586;
		case 10: goto tr1606;
		case 13: goto tr1607;
		case 32: goto tr1586;
		case 35: goto tr249;
		case 59: goto tr1603;
		case 123: goto tr1608;
	}
	goto tr1605;
tr1605:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 778; goto st22;} }
	goto st778;
st778:
	if ( ++p == pe )
		goto _test_eof778;
case 778:
#line 27056 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1590;
		case 10: goto tr1609;
		case 13: goto tr1610;
		case 32: goto tr1590;
		case 35: goto tr1611;
		case 43: goto tr694;
		case 59: goto st0;
		case 61: goto st769;
		case 123: goto tr240;
	}
	goto st136;
tr1607:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 779; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st779;
st779:
	if ( ++p == pe )
		goto _test_eof779;
case 779:
#line 27085 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1590;
		case 10: goto tr1604;
		case 13: goto tr1610;
		case 32: goto tr1590;
		case 35: goto tr1611;
		case 43: goto tr694;
		case 59: goto st0;
		case 61: goto st769;
		case 123: goto tr240;
	}
	goto st136;
tr1613:
#line 141 "confscanner.rl"
	{line++;}
	goto st968;
tr1614:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 968; goto st22;} }
	goto st968;
tr1608:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 968; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 968; goto st886;} }
	goto st968;
st968:
	if ( ++p == pe )
		goto _test_eof968;
case 968:
#line 27124 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st966;
		case 10: goto tr1613;
		case 13: goto st780;
		case 32: goto st966;
		case 35: goto st781;
		case 43: goto tr822;
		case 61: goto st775;
		case 97: goto st27;
		case 103: goto st127;
		case 123: goto tr246;
		case 125: goto tr1769;
	}
	goto st0;
st780:
	if ( ++p == pe )
		goto _test_eof780;
case 780:
	if ( (*p) == 10 )
		goto tr1613;
	goto st0;
st781:
	if ( ++p == pe )
		goto _test_eof781;
case 781:
	if ( (*p) == 35 )
		goto st0;
	goto tr1614;
tr1615:
#line 141 "confscanner.rl"
	{line++;}
	goto st782;
tr1618:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 782; goto st22;} }
	goto st782;
tr1122:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st782;
tr1619:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st782;
tr1621:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 782; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st782;
tr1678:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 782; goto st22;} }
#line 141 "confscanner.rl"
	{line++;}
	goto st782;
st782:
	if ( ++p == pe )
		goto _test_eof782;
case 782:
#line 27213 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st559;
		case 10: goto tr1615;
		case 13: goto st783;
		case 32: goto st559;
		case 35: goto st784;
		case 40: goto st105;
		case 123: goto tr246;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr180;
	} else if ( (*p) >= 65 )
		goto tr180;
	goto st0;
st783:
	if ( ++p == pe )
		goto _test_eof783;
case 783:
	if ( (*p) == 10 )
		goto tr1615;
	goto st0;
st784:
	if ( ++p == pe )
		goto _test_eof784;
case 784:
	if ( (*p) == 35 )
		goto st0;
	goto tr1618;
tr1123:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st785;
st785:
	if ( ++p == pe )
		goto _test_eof785;
case 785:
#line 27256 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1619;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1124:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st786;
st786:
	if ( ++p == pe )
		goto _test_eof786;
case 786:
#line 27281 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1618;
		case 9: goto tr1136;
		case 10: goto tr1621;
		case 13: goto tr1622;
		case 32: goto tr1136;
		case 35: goto tr249;
		case 59: goto tr1618;
		case 123: goto tr1623;
	}
	goto tr1620;
tr1622:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 787; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st787;
st787:
	if ( ++p == pe )
		goto _test_eof787;
case 787:
#line 27308 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1121;
		case 10: goto tr1619;
		case 13: goto tr1123;
		case 32: goto tr1121;
		case 35: goto tr1124;
		case 40: goto st563;
		case 59: goto st0;
		case 123: goto tr240;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1126;
	} else if ( (*p) >= 65 )
		goto tr1126;
	goto st136;
tr1624:
#line 141 "confscanner.rl"
	{line++;}
	goto st969;
tr1625:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 969; goto st22;} }
	goto st969;
tr1623:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 969; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 969; goto st886;} }
	goto st969;
tr1680:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 969; goto st22;} }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 969; goto st886;} }
	goto st969;
st969:
	if ( ++p == pe )
		goto _test_eof969;
case 969:
#line 27364 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st961;
		case 10: goto tr1624;
		case 13: goto st788;
		case 32: goto st961;
		case 35: goto st789;
		case 40: goto st105;
		case 97: goto tr2047;
		case 103: goto tr2048;
		case 123: goto tr246;
		case 125: goto tr1769;
	}
	if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr180;
	} else if ( (*p) >= 65 )
		goto tr180;
	goto st0;
st788:
	if ( ++p == pe )
		goto _test_eof788;
case 788:
	if ( (*p) == 10 )
		goto tr1624;
	goto st0;
st789:
	if ( ++p == pe )
		goto _test_eof789;
case 789:
	if ( (*p) == 35 )
		goto st0;
	goto tr1625;
tr2047:
#line 173 "confscanner.rl"
	{tmp_p = p;}
	goto st790;
st790:
	if ( ++p == pe )
		goto _test_eof790;
case 790:
#line 27405 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto tr212;
		case 10: goto tr213;
		case 13: goto tr214;
		case 32: goto tr212;
		case 35: goto tr215;
		case 61: goto tr217;
		case 95: goto st121;
		case 100: goto st791;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st121;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st121;
	} else
		goto st121;
	goto st0;
st791:
	if ( ++p == pe )
		goto _test_eof791;
case 791:
	switch( (*p) ) {
		case 9: goto tr212;
		case 10: goto tr213;
		case 13: goto tr214;
		case 32: goto tr212;
		case 35: goto tr215;
		case 61: goto tr217;
		case 95: goto st121;
		case 100: goto st792;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st121;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st121;
	} else
		goto st121;
	goto st0;
st792:
	if ( ++p == pe )
		goto _test_eof792;
case 792:
	switch( (*p) ) {
		case 9: goto tr212;
		case 10: goto tr213;
		case 13: goto tr214;
		case 32: goto tr212;
		case 35: goto tr215;
		case 40: goto st30;
		case 61: goto tr217;
		case 95: goto st121;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st121;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st121;
	} else
		goto st121;
	goto st0;
tr2048:
#line 173 "confscanner.rl"
	{tmp_p = p;}
	goto st793;
st793:
	if ( ++p == pe )
		goto _test_eof793;
case 793:
#line 27479 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto tr212;
		case 10: goto tr213;
		case 13: goto tr214;
		case 32: goto tr212;
		case 35: goto tr215;
		case 61: goto tr217;
		case 95: goto st121;
		case 108: goto st794;
		case 114: goto st800;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st121;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st121;
	} else
		goto st121;
	goto st0;
st794:
	if ( ++p == pe )
		goto _test_eof794;
case 794:
	switch( (*p) ) {
		case 9: goto tr212;
		case 10: goto tr213;
		case 13: goto tr214;
		case 32: goto tr212;
		case 35: goto tr215;
		case 61: goto tr217;
		case 95: goto st121;
		case 111: goto st795;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st121;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st121;
	} else
		goto st121;
	goto st0;
st795:
	if ( ++p == pe )
		goto _test_eof795;
case 795:
	switch( (*p) ) {
		case 9: goto tr212;
		case 10: goto tr213;
		case 13: goto tr214;
		case 32: goto tr212;
		case 35: goto tr215;
		case 61: goto tr217;
		case 95: goto st121;
		case 98: goto st796;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st121;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st121;
	} else
		goto st121;
	goto st0;
st796:
	if ( ++p == pe )
		goto _test_eof796;
case 796:
	switch( (*p) ) {
		case 9: goto tr1632;
		case 10: goto tr1633;
		case 13: goto tr1634;
		case 32: goto tr1632;
		case 35: goto tr1635;
		case 61: goto tr1636;
		case 95: goto st121;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st121;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st121;
	} else
		goto st121;
	goto st0;
tr1638:
#line 141 "confscanner.rl"
	{line++;}
	goto st797;
tr1641:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 797; goto st22;} }
	goto st797;
tr1632:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st797;
tr1633:
#line 141 "confscanner.rl"
	{line++;}
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st797;
st797:
	if ( ++p == pe )
		goto _test_eof797;
case 797:
#line 27604 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st797;
		case 10: goto tr1638;
		case 13: goto st798;
		case 32: goto st797;
		case 35: goto st799;
		case 61: goto st754;
	}
	goto st0;
tr1634:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st798;
st798:
	if ( ++p == pe )
		goto _test_eof798;
case 798:
#line 27629 "confscanner.cc"
	if ( (*p) == 10 )
		goto tr1638;
	goto st0;
tr1635:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st799;
st799:
	if ( ++p == pe )
		goto _test_eof799;
case 799:
#line 27648 "confscanner.cc"
	if ( (*p) == 35 )
		goto st0;
	goto tr1641;
st800:
	if ( ++p == pe )
		goto _test_eof800;
case 800:
	switch( (*p) ) {
		case 9: goto tr212;
		case 10: goto tr213;
		case 13: goto tr214;
		case 32: goto tr212;
		case 35: goto tr215;
		case 61: goto tr217;
		case 95: goto st121;
		case 111: goto st801;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st121;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st121;
	} else
		goto st121;
	goto st0;
st801:
	if ( ++p == pe )
		goto _test_eof801;
case 801:
	switch( (*p) ) {
		case 9: goto tr212;
		case 10: goto tr213;
		case 13: goto tr214;
		case 32: goto tr212;
		case 35: goto tr215;
		case 61: goto tr217;
		case 95: goto st121;
		case 117: goto st802;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st121;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st121;
	} else
		goto st121;
	goto st0;
st802:
	if ( ++p == pe )
		goto _test_eof802;
case 802:
	switch( (*p) ) {
		case 9: goto tr212;
		case 10: goto tr213;
		case 13: goto tr214;
		case 32: goto tr212;
		case 35: goto tr215;
		case 61: goto tr217;
		case 95: goto st121;
		case 112: goto st803;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st121;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st121;
	} else
		goto st121;
	goto st0;
st803:
	if ( ++p == pe )
		goto _test_eof803;
case 803:
	switch( (*p) ) {
		case 9: goto tr212;
		case 10: goto tr213;
		case 13: goto tr214;
		case 32: goto tr212;
		case 35: goto tr215;
		case 61: goto tr217;
		case 95: goto st121;
		case 115: goto st804;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st121;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st121;
	} else
		goto st121;
	goto st0;
st804:
	if ( ++p == pe )
		goto _test_eof804;
case 804:
	switch( (*p) ) {
		case 9: goto tr1646;
		case 10: goto tr1647;
		case 13: goto tr1648;
		case 32: goto tr1646;
		case 35: goto tr1649;
		case 43: goto tr822;
		case 61: goto tr1650;
		case 95: goto st121;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st121;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st121;
	} else
		goto st121;
	goto st0;
tr1652:
#line 141 "confscanner.rl"
	{line++;}
	goto st805;
tr1655:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 805; goto st22;} }
	goto st805;
tr1646:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st805;
tr1647:
#line 141 "confscanner.rl"
	{line++;}
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st805;
st805:
	if ( ++p == pe )
		goto _test_eof805;
case 805:
#line 27803 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st805;
		case 10: goto tr1652;
		case 13: goto st806;
		case 32: goto st805;
		case 35: goto st807;
		case 43: goto tr822;
		case 61: goto st775;
	}
	goto st0;
tr1648:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st806;
st806:
	if ( ++p == pe )
		goto _test_eof806;
case 806:
#line 27829 "confscanner.cc"
	if ( (*p) == 10 )
		goto tr1652;
	goto st0;
tr1649:
#line 98 "confscanner.rl"
	{
    if(match_at_level_[level_])
    {
      tmp_string.assign(tmp_p, p-tmp_p);
      //cerr << "ts:" << tmp_string << ":ets\n";//<< " " << tmp_p << "p: " << p << "\n";
      cblock_ = &((*clist_)[tmp_string]);
    }
  }
	goto st807;
st807:
	if ( ++p == pe )
		goto _test_eof807;
case 807:
#line 27848 "confscanner.cc"
	if ( (*p) == 35 )
		goto st0;
	goto tr1655;
tr2050:
#line 141 "confscanner.rl"
	{line++;}
	goto st970;
tr1658:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 970; goto st22;} }
	goto st970;
tr2053:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st970;
tr1656:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st970;
tr1659:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 970; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st970;
tr1660:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 970; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st970;
tr1117:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 970; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 970; goto st886;} }
	goto st970;
st970:
	if ( ++p == pe )
		goto _test_eof970;
case 970:
#line 27921 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st970;
		case 10: goto tr2050;
		case 13: goto tr2051;
		case 32: goto st970;
		case 35: goto tr2052;
		case 43: goto tr1109;
		case 59: goto st0;
		case 61: goto tr1110;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr246;
		case 125: goto tr1778;
	}
	goto tr241;
tr2051:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st808;
tr2054:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st808;
st808:
	if ( ++p == pe )
		goto _test_eof808;
case 808:
#line 27957 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1656;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr2052:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st809;
tr2055:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st809;
st809:
	if ( ++p == pe )
		goto _test_eof809;
case 809:
#line 27988 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1658;
		case 9: goto tr1659;
		case 10: goto tr1660;
		case 13: goto tr1661;
		case 32: goto tr1659;
		case 35: goto tr249;
		case 59: goto tr1658;
		case 123: goto tr1117;
	}
	goto tr1657;
tr1657:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 971; goto st22;} }
	goto st971;
tr1661:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 971; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st971;
st971:
	if ( ++p == pe )
		goto _test_eof971;
case 971:
#line 28019 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr2053;
		case 10: goto tr1656;
		case 13: goto tr2054;
		case 32: goto tr2053;
		case 35: goto tr2055;
		case 43: goto tr1109;
		case 59: goto st0;
		case 61: goto tr1110;
		case 97: goto tr1776;
		case 103: goto tr1777;
		case 123: goto tr240;
		case 125: goto tr1778;
	}
	goto tr241;
tr1662:
#line 141 "confscanner.rl"
	{line++;}
	goto st810;
tr1665:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 810; goto st22;} }
	goto st810;
tr1100:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st810;
tr1737:
#line 141 "confscanner.rl"
	{line++;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st810;
tr1739:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 810; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 141 "confscanner.rl"
	{line++;}
	goto st810;
tr1668:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 810; goto st22;} }
#line 141 "confscanner.rl"
	{line++;}
	goto st810;
st810:
	if ( ++p == pe )
		goto _test_eof810;
case 810:
#line 28096 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st553;
		case 10: goto tr1662;
		case 13: goto st811;
		case 32: goto st553;
		case 35: goto st812;
		case 43: goto tr173;
		case 61: goto st102;
		case 123: goto tr246;
	}
	goto st0;
st811:
	if ( ++p == pe )
		goto _test_eof811;
case 811:
	if ( (*p) == 10 )
		goto tr1662;
	goto st0;
st812:
	if ( ++p == pe )
		goto _test_eof812;
case 812:
	if ( (*p) == 35 )
		goto st0;
	goto tr1665;
tr1101:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st813;
st813:
	if ( ++p == pe )
		goto _test_eof813;
case 813:
#line 28135 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1100;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
tr1102:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st814;
st814:
	if ( ++p == pe )
		goto _test_eof814;
case 814:
#line 28160 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1665;
		case 9: goto tr1667;
		case 10: goto tr1668;
		case 13: goto tr1669;
		case 32: goto tr1667;
		case 35: goto tr239;
		case 59: goto tr1665;
		case 123: goto tr1670;
	}
	goto tr1666;
tr1671:
#line 141 "confscanner.rl"
	{line++;}
	goto st972;
tr1672:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 972; goto st22;} }
	goto st972;
tr1741:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 972; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 972; goto st886;} }
	goto st972;
tr1670:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 972; goto st22;} }
#line 228 "confscanner.rl"
	{ check_glob_level_up(); {stack[top++] = 972; goto st886;} }
	goto st972;
st972:
	if ( ++p == pe )
		goto _test_eof972;
case 972:
#line 28210 "confscanner.cc"
	switch( (*p) ) {
		case 9: goto st970;
		case 10: goto tr1671;
		case 13: goto st815;
		case 32: goto st970;
		case 35: goto st816;
		case 43: goto tr173;
		case 61: goto st102;
		case 97: goto st27;
		case 103: goto st127;
		case 123: goto tr246;
		case 125: goto tr1769;
	}
	goto st0;
st815:
	if ( ++p == pe )
		goto _test_eof815;
case 815:
	if ( (*p) == 10 )
		goto tr1671;
	goto st0;
st816:
	if ( ++p == pe )
		goto _test_eof816;
case 816:
	if ( (*p) == 35 )
		goto st0;
	goto tr1672;
tr1103:
#line 146 "confscanner.rl"
	{arg_to_be_added_ = true;}
	goto st817;
st817:
	if ( ++p == pe )
		goto _test_eof817;
case 817:
#line 28247 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 61: goto st818;
		case 123: goto tr240;
	}
	goto st134;
tr1676:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 818; goto st22;} }
	goto st818;
tr1679:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 818; goto st22;} }
	goto st818;
st818:
	if ( ++p == pe )
		goto _test_eof818;
case 818:
#line 28279 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1121;
		case 10: goto tr1122;
		case 13: goto tr1673;
		case 32: goto tr1121;
		case 35: goto tr1674;
		case 40: goto st664;
		case 59: goto st0;
		case 123: goto tr240;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1675;
	} else if ( (*p) >= 65 )
		goto tr1675;
	goto st134;
tr1673:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st819;
st819:
	if ( ++p == pe )
		goto _test_eof819;
case 819:
#line 28310 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1122;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st134;
tr1674:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st820;
st820:
	if ( ++p == pe )
		goto _test_eof820;
case 820:
#line 28335 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1618;
		case 9: goto tr1677;
		case 10: goto tr1678;
		case 13: goto tr1679;
		case 32: goto tr1677;
		case 35: goto tr239;
		case 59: goto tr1618;
		case 123: goto tr1680;
	}
	goto tr1676;
tr1675:
#line 173 "confscanner.rl"
	{tmp_p = p;}
	goto st821;
st821:
	if ( ++p == pe )
		goto _test_eof821;
case 821:
#line 28355 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1509;
		case 10: goto tr1510;
		case 13: goto tr1681;
		case 32: goto tr1509;
		case 35: goto tr1682;
		case 59: goto st0;
		case 61: goto tr1684;
		case 95: goto st821;
		case 123: goto tr240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st821;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st821;
	} else
		goto st821;
	goto st134;
tr398:
#line 237 "confscanner.rl"
	{/*cerr << "add:" << '\n';*/ tmp_p = p;}
	goto st822;
st822:
	if ( ++p == pe )
		goto _test_eof822;
case 822:
#line 28385 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 101: goto st823;
		case 123: goto tr240;
	}
	goto st134;
st823:
	if ( ++p == pe )
		goto _test_eof823;
case 823:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 116: goto st824;
		case 123: goto tr240;
	}
	goto st134;
st824:
	if ( ++p == pe )
		goto _test_eof824;
case 824:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 117: goto st825;
		case 123: goto tr240;
	}
	goto st134;
st825:
	if ( ++p == pe )
		goto _test_eof825;
case 825:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 114: goto st826;
		case 123: goto tr240;
	}
	goto st134;
st826:
	if ( ++p == pe )
		goto _test_eof826;
case 826:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr238;
		case 32: goto tr236;
		case 35: goto tr239;
		case 59: goto st0;
		case 110: goto st551;
		case 123: goto tr240;
	}
	goto st134;
st827:
	if ( ++p == pe )
		goto _test_eof827;
case 827:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 111: goto st828;
		case 123: goto tr240;
	}
	goto st136;
st828:
	if ( ++p == pe )
		goto _test_eof828;
case 828:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 117: goto st829;
		case 123: goto tr240;
	}
	goto st136;
st829:
	if ( ++p == pe )
		goto _test_eof829;
case 829:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 112: goto st830;
		case 123: goto tr240;
	}
	goto st136;
st830:
	if ( ++p == pe )
		goto _test_eof830;
case 830:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 115: goto st428;
		case 123: goto tr240;
	}
	goto st136;
tr311:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st831;
tr1699:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st831;
st831:
	if ( ++p == pe )
		goto _test_eof831;
case 831:
#line 28545 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1694;
		case 9: goto tr1695;
		case 10: goto tr1696;
		case 13: goto tr1697;
		case 32: goto tr1695;
		case 35: goto tr249;
		case 59: goto tr1694;
		case 123: goto tr463;
	}
	goto tr1693;
tr1693:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 832; goto st22;} }
	goto st832;
tr1697:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 832; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st832;
st832:
	if ( ++p == pe )
		goto _test_eof832;
case 832:
#line 28576 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr302;
		case 10: goto tr312;
		case 13: goto tr1698;
		case 32: goto tr302;
		case 34: goto tr310;
		case 35: goto tr1699;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto tr241;
tr304:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st833;
st833:
	if ( ++p == pe )
		goto _test_eof833;
case 833:
#line 28602 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1700;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr306:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st834;
st834:
	if ( ++p == pe )
		goto _test_eof834;
case 834:
#line 28627 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr436;
		case 9: goto tr1695;
		case 10: goto tr1702;
		case 13: goto tr1703;
		case 32: goto tr1695;
		case 35: goto tr249;
		case 59: goto tr436;
		case 123: goto tr1704;
	}
	goto tr1701;
tr1703:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 835; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st835;
st835:
	if ( ++p == pe )
		goto _test_eof835;
case 835:
#line 28654 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr302;
		case 10: goto tr1700;
		case 13: goto tr304;
		case 32: goto tr302;
		case 34: goto st162;
		case 35: goto tr306;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr283:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st836;
st836:
	if ( ++p == pe )
		goto _test_eof836;
case 836:
#line 28680 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1705;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr284:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st837;
st837:
	if ( ++p == pe )
		goto _test_eof837;
case 837:
#line 28705 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr411;
		case 9: goto tr296;
		case 10: goto tr1707;
		case 13: goto tr1708;
		case 32: goto tr296;
		case 35: goto tr249;
		case 59: goto tr411;
		case 123: goto tr1709;
	}
	goto tr1706;
tr1708:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 838; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st838;
st838:
	if ( ++p == pe )
		goto _test_eof838;
case 838:
#line 28732 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr281;
		case 10: goto tr1705;
		case 13: goto tr283;
		case 32: goto tr281;
		case 35: goto tr284;
		case 43: goto tr285;
		case 59: goto st0;
		case 61: goto st159;
		case 123: goto tr240;
	}
	goto st136;
tr271:
#line 237 "confscanner.rl"
	{/*cerr << "add:" << '\n';*/ tmp_p = p;}
	goto st839;
st839:
	if ( ++p == pe )
		goto _test_eof839;
case 839:
#line 28754 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 111: goto st840;
		case 123: goto tr240;
	}
	goto st136;
st840:
	if ( ++p == pe )
		goto _test_eof840;
case 840:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 99: goto st152;
		case 123: goto tr240;
	}
	goto st136;
tr272:
#line 237 "confscanner.rl"
	{/*cerr << "add:" << '\n';*/ tmp_p = p;}
	goto st841;
st841:
	if ( ++p == pe )
		goto _test_eof841;
case 841:
#line 28791 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 120: goto st842;
		case 123: goto tr240;
	}
	goto st136;
st842:
	if ( ++p == pe )
		goto _test_eof842;
case 842:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 116: goto st843;
		case 123: goto tr240;
	}
	goto st136;
st843:
	if ( ++p == pe )
		goto _test_eof843;
case 843:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 114: goto st844;
		case 123: goto tr240;
	}
	goto st136;
st844:
	if ( ++p == pe )
		goto _test_eof844;
case 844:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 97: goto st152;
		case 123: goto tr240;
	}
	goto st136;
tr273:
#line 237 "confscanner.rl"
	{/*cerr << "add:" << '\n';*/ tmp_p = p;}
	goto st845;
st845:
	if ( ++p == pe )
		goto _test_eof845;
case 845:
#line 28860 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 105: goto st846;
		case 123: goto tr240;
	}
	goto st136;
st846:
	if ( ++p == pe )
		goto _test_eof846;
case 846:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 101: goto st847;
		case 123: goto tr240;
	}
	goto st136;
st847:
	if ( ++p == pe )
		goto _test_eof847;
case 847:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 108: goto st848;
		case 123: goto tr240;
	}
	goto st136;
st848:
	if ( ++p == pe )
		goto _test_eof848;
case 848:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 100: goto st849;
		case 123: goto tr240;
	}
	goto st136;
st849:
	if ( ++p == pe )
		goto _test_eof849;
case 849:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 115: goto st850;
		case 123: goto tr240;
	}
	goto st136;
st850:
	if ( ++p == pe )
		goto _test_eof850;
case 850:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 41: goto tr1719;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1724:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 851; goto st22;} }
	goto st851;
tr1719:
#line 66 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    if(tmp_string == "fields")
      clistmap_ = &field_docu_;
  }
	goto st851;
st851:
	if ( ++p == pe )
		goto _test_eof851;
case 851:
#line 28969 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr476;
		case 10: goto tr477;
		case 13: goto tr1720;
		case 32: goto tr476;
		case 35: goto tr1721;
		case 43: goto tr1722;
		case 59: goto st0;
		case 61: goto st247;
		case 123: goto tr240;
	}
	goto st136;
tr1720:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st852;
st852:
	if ( ++p == pe )
		goto _test_eof852;
case 852:
#line 28996 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1723;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1721:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st853;
st853:
	if ( ++p == pe )
		goto _test_eof853;
case 853:
#line 29021 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1019;
		case 9: goto tr491;
		case 10: goto tr1725;
		case 13: goto tr1726;
		case 32: goto tr491;
		case 35: goto tr249;
		case 59: goto tr1019;
		case 123: goto tr1727;
	}
	goto tr1724;
tr1726:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 854; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st854;
st854:
	if ( ++p == pe )
		goto _test_eof854;
case 854:
#line 29048 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr476;
		case 10: goto tr1723;
		case 13: goto tr1720;
		case 32: goto tr476;
		case 35: goto tr1721;
		case 43: goto tr1722;
		case 59: goto st0;
		case 61: goto st247;
		case 123: goto tr240;
	}
	goto st136;
tr274:
#line 237 "confscanner.rl"
	{/*cerr << "add:" << '\n';*/ tmp_p = p;}
	goto st855;
st855:
	if ( ++p == pe )
		goto _test_eof855;
case 855:
#line 29070 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 97: goto st856;
		case 123: goto tr240;
	}
	goto st136;
st856:
	if ( ++p == pe )
		goto _test_eof856;
case 856:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 114: goto st857;
		case 123: goto tr240;
	}
	goto st136;
st857:
	if ( ++p == pe )
		goto _test_eof857;
case 857:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 97: goto st858;
		case 123: goto tr240;
	}
	goto st136;
st858:
	if ( ++p == pe )
		goto _test_eof858;
case 858:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 109: goto st859;
		case 123: goto tr240;
	}
	goto st136;
st859:
	if ( ++p == pe )
		goto _test_eof859;
case 859:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 115: goto st860;
		case 123: goto tr240;
	}
	goto st136;
st860:
	if ( ++p == pe )
		goto _test_eof860;
case 860:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 41: goto tr1733;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1738:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 861; goto st22;} }
	goto st861;
tr1733:
#line 53 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "docu_list: " << tmp_string << "\n";
    if(tmp_string == "params")
    {
      //cerr << "paramlist\n";
      clist_ = &param_list_;
    }
    else if(tmp_string == "return")
      clist_ = &return_list_;
  }
	goto st861;
st861:
	if ( ++p == pe )
		goto _test_eof861;
case 861:
#line 29185 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1099;
		case 10: goto tr1100;
		case 13: goto tr1734;
		case 32: goto tr1099;
		case 35: goto tr1735;
		case 43: goto tr1736;
		case 59: goto st0;
		case 61: goto st558;
		case 123: goto tr240;
	}
	goto st136;
tr1734:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st862;
st862:
	if ( ++p == pe )
		goto _test_eof862;
case 862:
#line 29212 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1737;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr1735:
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st863;
st863:
	if ( ++p == pe )
		goto _test_eof863;
case 863:
#line 29237 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1665;
		case 9: goto tr1114;
		case 10: goto tr1739;
		case 13: goto tr1740;
		case 32: goto tr1114;
		case 35: goto tr249;
		case 59: goto tr1665;
		case 123: goto tr1741;
	}
	goto tr1738;
tr1740:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 864; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st864;
st864:
	if ( ++p == pe )
		goto _test_eof864;
case 864:
#line 29264 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1099;
		case 10: goto tr1737;
		case 13: goto tr1734;
		case 32: goto tr1099;
		case 35: goto tr1735;
		case 43: goto tr1736;
		case 59: goto st0;
		case 61: goto st558;
		case 123: goto tr240;
	}
	goto st136;
tr275:
#line 237 "confscanner.rl"
	{/*cerr << "add:" << '\n';*/ tmp_p = p;}
	goto st865;
st865:
	if ( ++p == pe )
		goto _test_eof865;
case 865:
#line 29286 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 101: goto st866;
		case 123: goto tr240;
	}
	goto st136;
st866:
	if ( ++p == pe )
		goto _test_eof866;
case 866:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 116: goto st867;
		case 123: goto tr240;
	}
	goto st136;
st867:
	if ( ++p == pe )
		goto _test_eof867;
case 867:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 117: goto st868;
		case 123: goto tr240;
	}
	goto st136;
st868:
	if ( ++p == pe )
		goto _test_eof868;
case 868:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 114: goto st869;
		case 123: goto tr240;
	}
	goto st136;
st869:
	if ( ++p == pe )
		goto _test_eof869;
case 869:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr237;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 110: goto st860;
		case 123: goto tr240;
	}
	goto st136;
st870:
	if ( ++p == pe )
		goto _test_eof870;
case 870:
	if ( (*p) == 10 )
		goto tr1746;
	goto st0;
st871:
	if ( ++p == pe )
		goto _test_eof871;
case 871:
	if ( (*p) == 35 )
		goto st0;
	goto tr425;
tr244:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st872;
tr1752:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st872;
st872:
	if ( ++p == pe )
		goto _test_eof872;
case 872:
#line 29396 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1747;
		case 13: goto tr248;
		case 32: goto tr236;
		case 35: goto tr249;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto st136;
tr245:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
	goto st873;
tr1753:
#line 215 "confscanner.rl"
	{/*cerr << "glob list2";*/ tmp_p = p;}
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st873;
st873:
	if ( ++p == pe )
		goto _test_eof873;
case 873:
#line 29427 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto tr1749;
		case 9: goto tr256;
		case 10: goto tr1750;
		case 13: goto tr1751;
		case 32: goto tr256;
		case 35: goto tr249;
		case 59: goto tr1749;
		case 123: goto tr266;
	}
	goto tr1748;
tr1748:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 874; goto st22;} }
	goto st874;
tr1751:
#line 142 "confscanner.rl"
	{ /*cerr << "l: " << line << "\n";*/ p--;{stack[top++] = 874; goto st22;} }
#line 114 "confscanner.rl"
	{
    tmp_string.assign(tmp_p, p-tmp_p);
    //cerr << "glob: " << tmp_string << endl;
    // TODO: use globlist_map
    globlist_stack_.back().push_back(tmp_string);
  }
	goto st874;
st874:
	if ( ++p == pe )
		goto _test_eof874;
case 874:
#line 29458 "confscanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr236;
		case 10: goto tr1747;
		case 13: goto tr1752;
		case 32: goto tr236;
		case 35: goto tr1753;
		case 59: goto st0;
		case 123: goto tr240;
	}
	goto tr241;
st875:
	if ( ++p == pe )
		goto _test_eof875;
case 875:
	if ( (*p) == 111 )
		goto st876;
	goto st0;
st876:
	if ( ++p == pe )
		goto _test_eof876;
case 876:
	if ( (*p) == 117 )
		goto st877;
	goto st0;
st877:
	if ( ++p == pe )
		goto _test_eof877;
case 877:
	if ( (*p) == 112 )
		goto st878;
	goto st0;
st878:
	if ( ++p == pe )
		goto _test_eof878;
case 878:
	if ( (*p) == 115 )
		goto st452;
	goto st0;
	}
	_test_eof879: cs = 879; goto _test_eof; 
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
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof880: cs = 880; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof881: cs = 881; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof882: cs = 882; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof883: cs = 883; goto _test_eof; 
	_test_eof884: cs = 884; goto _test_eof; 
	_test_eof885: cs = 885; goto _test_eof; 
	_test_eof23: cs = 23; goto _test_eof; 
	_test_eof24: cs = 24; goto _test_eof; 
	_test_eof886: cs = 886; goto _test_eof; 
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
	_test_eof887: cs = 887; goto _test_eof; 
	_test_eof888: cs = 888; goto _test_eof; 
	_test_eof142: cs = 142; goto _test_eof; 
	_test_eof143: cs = 143; goto _test_eof; 
	_test_eof889: cs = 889; goto _test_eof; 
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
	_test_eof890: cs = 890; goto _test_eof; 
	_test_eof169: cs = 169; goto _test_eof; 
	_test_eof170: cs = 170; goto _test_eof; 
	_test_eof891: cs = 891; goto _test_eof; 
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
	_test_eof892: cs = 892; goto _test_eof; 
	_test_eof185: cs = 185; goto _test_eof; 
	_test_eof186: cs = 186; goto _test_eof; 
	_test_eof893: cs = 893; goto _test_eof; 
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
	_test_eof894: cs = 894; goto _test_eof; 
	_test_eof895: cs = 895; goto _test_eof; 
	_test_eof202: cs = 202; goto _test_eof; 
	_test_eof203: cs = 203; goto _test_eof; 
	_test_eof896: cs = 896; goto _test_eof; 
	_test_eof897: cs = 897; goto _test_eof; 
	_test_eof204: cs = 204; goto _test_eof; 
	_test_eof205: cs = 205; goto _test_eof; 
	_test_eof898: cs = 898; goto _test_eof; 
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
	_test_eof221: cs = 221; goto _test_eof; 
	_test_eof899: cs = 899; goto _test_eof; 
	_test_eof222: cs = 222; goto _test_eof; 
	_test_eof223: cs = 223; goto _test_eof; 
	_test_eof224: cs = 224; goto _test_eof; 
	_test_eof900: cs = 900; goto _test_eof; 
	_test_eof901: cs = 901; goto _test_eof; 
	_test_eof225: cs = 225; goto _test_eof; 
	_test_eof226: cs = 226; goto _test_eof; 
	_test_eof902: cs = 902; goto _test_eof; 
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
	_test_eof903: cs = 903; goto _test_eof; 
	_test_eof275: cs = 275; goto _test_eof; 
	_test_eof276: cs = 276; goto _test_eof; 
	_test_eof904: cs = 904; goto _test_eof; 
	_test_eof277: cs = 277; goto _test_eof; 
	_test_eof278: cs = 278; goto _test_eof; 
	_test_eof279: cs = 279; goto _test_eof; 
	_test_eof280: cs = 280; goto _test_eof; 
	_test_eof281: cs = 281; goto _test_eof; 
	_test_eof282: cs = 282; goto _test_eof; 
	_test_eof905: cs = 905; goto _test_eof; 
	_test_eof283: cs = 283; goto _test_eof; 
	_test_eof284: cs = 284; goto _test_eof; 
	_test_eof285: cs = 285; goto _test_eof; 
	_test_eof286: cs = 286; goto _test_eof; 
	_test_eof906: cs = 906; goto _test_eof; 
	_test_eof287: cs = 287; goto _test_eof; 
	_test_eof288: cs = 288; goto _test_eof; 
	_test_eof907: cs = 907; goto _test_eof; 
	_test_eof289: cs = 289; goto _test_eof; 
	_test_eof290: cs = 290; goto _test_eof; 
	_test_eof291: cs = 291; goto _test_eof; 
	_test_eof292: cs = 292; goto _test_eof; 
	_test_eof293: cs = 293; goto _test_eof; 
	_test_eof294: cs = 294; goto _test_eof; 
	_test_eof908: cs = 908; goto _test_eof; 
	_test_eof295: cs = 295; goto _test_eof; 
	_test_eof296: cs = 296; goto _test_eof; 
	_test_eof909: cs = 909; goto _test_eof; 
	_test_eof297: cs = 297; goto _test_eof; 
	_test_eof298: cs = 298; goto _test_eof; 
	_test_eof910: cs = 910; goto _test_eof; 
	_test_eof299: cs = 299; goto _test_eof; 
	_test_eof300: cs = 300; goto _test_eof; 
	_test_eof301: cs = 301; goto _test_eof; 
	_test_eof302: cs = 302; goto _test_eof; 
	_test_eof303: cs = 303; goto _test_eof; 
	_test_eof304: cs = 304; goto _test_eof; 
	_test_eof305: cs = 305; goto _test_eof; 
	_test_eof911: cs = 911; goto _test_eof; 
	_test_eof306: cs = 306; goto _test_eof; 
	_test_eof307: cs = 307; goto _test_eof; 
	_test_eof912: cs = 912; goto _test_eof; 
	_test_eof308: cs = 308; goto _test_eof; 
	_test_eof309: cs = 309; goto _test_eof; 
	_test_eof913: cs = 913; goto _test_eof; 
	_test_eof310: cs = 310; goto _test_eof; 
	_test_eof311: cs = 311; goto _test_eof; 
	_test_eof312: cs = 312; goto _test_eof; 
	_test_eof313: cs = 313; goto _test_eof; 
	_test_eof314: cs = 314; goto _test_eof; 
	_test_eof315: cs = 315; goto _test_eof; 
	_test_eof316: cs = 316; goto _test_eof; 
	_test_eof317: cs = 317; goto _test_eof; 
	_test_eof318: cs = 318; goto _test_eof; 
	_test_eof319: cs = 319; goto _test_eof; 
	_test_eof320: cs = 320; goto _test_eof; 
	_test_eof321: cs = 321; goto _test_eof; 
	_test_eof914: cs = 914; goto _test_eof; 
	_test_eof915: cs = 915; goto _test_eof; 
	_test_eof322: cs = 322; goto _test_eof; 
	_test_eof323: cs = 323; goto _test_eof; 
	_test_eof916: cs = 916; goto _test_eof; 
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
	_test_eof338: cs = 338; goto _test_eof; 
	_test_eof339: cs = 339; goto _test_eof; 
	_test_eof340: cs = 340; goto _test_eof; 
	_test_eof341: cs = 341; goto _test_eof; 
	_test_eof342: cs = 342; goto _test_eof; 
	_test_eof343: cs = 343; goto _test_eof; 
	_test_eof344: cs = 344; goto _test_eof; 
	_test_eof345: cs = 345; goto _test_eof; 
	_test_eof917: cs = 917; goto _test_eof; 
	_test_eof346: cs = 346; goto _test_eof; 
	_test_eof347: cs = 347; goto _test_eof; 
	_test_eof918: cs = 918; goto _test_eof; 
	_test_eof348: cs = 348; goto _test_eof; 
	_test_eof349: cs = 349; goto _test_eof; 
	_test_eof350: cs = 350; goto _test_eof; 
	_test_eof351: cs = 351; goto _test_eof; 
	_test_eof352: cs = 352; goto _test_eof; 
	_test_eof353: cs = 353; goto _test_eof; 
	_test_eof354: cs = 354; goto _test_eof; 
	_test_eof355: cs = 355; goto _test_eof; 
	_test_eof356: cs = 356; goto _test_eof; 
	_test_eof357: cs = 357; goto _test_eof; 
	_test_eof358: cs = 358; goto _test_eof; 
	_test_eof919: cs = 919; goto _test_eof; 
	_test_eof359: cs = 359; goto _test_eof; 
	_test_eof360: cs = 360; goto _test_eof; 
	_test_eof920: cs = 920; goto _test_eof; 
	_test_eof361: cs = 361; goto _test_eof; 
	_test_eof362: cs = 362; goto _test_eof; 
	_test_eof363: cs = 363; goto _test_eof; 
	_test_eof364: cs = 364; goto _test_eof; 
	_test_eof365: cs = 365; goto _test_eof; 
	_test_eof366: cs = 366; goto _test_eof; 
	_test_eof921: cs = 921; goto _test_eof; 
	_test_eof367: cs = 367; goto _test_eof; 
	_test_eof368: cs = 368; goto _test_eof; 
	_test_eof369: cs = 369; goto _test_eof; 
	_test_eof370: cs = 370; goto _test_eof; 
	_test_eof371: cs = 371; goto _test_eof; 
	_test_eof372: cs = 372; goto _test_eof; 
	_test_eof373: cs = 373; goto _test_eof; 
	_test_eof374: cs = 374; goto _test_eof; 
	_test_eof375: cs = 375; goto _test_eof; 
	_test_eof376: cs = 376; goto _test_eof; 
	_test_eof377: cs = 377; goto _test_eof; 
	_test_eof922: cs = 922; goto _test_eof; 
	_test_eof378: cs = 378; goto _test_eof; 
	_test_eof379: cs = 379; goto _test_eof; 
	_test_eof923: cs = 923; goto _test_eof; 
	_test_eof380: cs = 380; goto _test_eof; 
	_test_eof381: cs = 381; goto _test_eof; 
	_test_eof382: cs = 382; goto _test_eof; 
	_test_eof383: cs = 383; goto _test_eof; 
	_test_eof384: cs = 384; goto _test_eof; 
	_test_eof385: cs = 385; goto _test_eof; 
	_test_eof386: cs = 386; goto _test_eof; 
	_test_eof387: cs = 387; goto _test_eof; 
	_test_eof388: cs = 388; goto _test_eof; 
	_test_eof389: cs = 389; goto _test_eof; 
	_test_eof390: cs = 390; goto _test_eof; 
	_test_eof391: cs = 391; goto _test_eof; 
	_test_eof392: cs = 392; goto _test_eof; 
	_test_eof924: cs = 924; goto _test_eof; 
	_test_eof393: cs = 393; goto _test_eof; 
	_test_eof394: cs = 394; goto _test_eof; 
	_test_eof395: cs = 395; goto _test_eof; 
	_test_eof396: cs = 396; goto _test_eof; 
	_test_eof397: cs = 397; goto _test_eof; 
	_test_eof398: cs = 398; goto _test_eof; 
	_test_eof399: cs = 399; goto _test_eof; 
	_test_eof400: cs = 400; goto _test_eof; 
	_test_eof925: cs = 925; goto _test_eof; 
	_test_eof401: cs = 401; goto _test_eof; 
	_test_eof402: cs = 402; goto _test_eof; 
	_test_eof403: cs = 403; goto _test_eof; 
	_test_eof404: cs = 404; goto _test_eof; 
	_test_eof405: cs = 405; goto _test_eof; 
	_test_eof406: cs = 406; goto _test_eof; 
	_test_eof407: cs = 407; goto _test_eof; 
	_test_eof408: cs = 408; goto _test_eof; 
	_test_eof409: cs = 409; goto _test_eof; 
	_test_eof410: cs = 410; goto _test_eof; 
	_test_eof411: cs = 411; goto _test_eof; 
	_test_eof412: cs = 412; goto _test_eof; 
	_test_eof413: cs = 413; goto _test_eof; 
	_test_eof414: cs = 414; goto _test_eof; 
	_test_eof415: cs = 415; goto _test_eof; 
	_test_eof416: cs = 416; goto _test_eof; 
	_test_eof417: cs = 417; goto _test_eof; 
	_test_eof418: cs = 418; goto _test_eof; 
	_test_eof419: cs = 419; goto _test_eof; 
	_test_eof420: cs = 420; goto _test_eof; 
	_test_eof926: cs = 926; goto _test_eof; 
	_test_eof421: cs = 421; goto _test_eof; 
	_test_eof422: cs = 422; goto _test_eof; 
	_test_eof927: cs = 927; goto _test_eof; 
	_test_eof423: cs = 423; goto _test_eof; 
	_test_eof424: cs = 424; goto _test_eof; 
	_test_eof425: cs = 425; goto _test_eof; 
	_test_eof426: cs = 426; goto _test_eof; 
	_test_eof427: cs = 427; goto _test_eof; 
	_test_eof428: cs = 428; goto _test_eof; 
	_test_eof429: cs = 429; goto _test_eof; 
	_test_eof928: cs = 928; goto _test_eof; 
	_test_eof430: cs = 430; goto _test_eof; 
	_test_eof431: cs = 431; goto _test_eof; 
	_test_eof432: cs = 432; goto _test_eof; 
	_test_eof433: cs = 433; goto _test_eof; 
	_test_eof434: cs = 434; goto _test_eof; 
	_test_eof435: cs = 435; goto _test_eof; 
	_test_eof436: cs = 436; goto _test_eof; 
	_test_eof437: cs = 437; goto _test_eof; 
	_test_eof929: cs = 929; goto _test_eof; 
	_test_eof438: cs = 438; goto _test_eof; 
	_test_eof439: cs = 439; goto _test_eof; 
	_test_eof440: cs = 440; goto _test_eof; 
	_test_eof441: cs = 441; goto _test_eof; 
	_test_eof442: cs = 442; goto _test_eof; 
	_test_eof443: cs = 443; goto _test_eof; 
	_test_eof444: cs = 444; goto _test_eof; 
	_test_eof445: cs = 445; goto _test_eof; 
	_test_eof446: cs = 446; goto _test_eof; 
	_test_eof447: cs = 447; goto _test_eof; 
	_test_eof448: cs = 448; goto _test_eof; 
	_test_eof449: cs = 449; goto _test_eof; 
	_test_eof450: cs = 450; goto _test_eof; 
	_test_eof451: cs = 451; goto _test_eof; 
	_test_eof452: cs = 452; goto _test_eof; 
	_test_eof453: cs = 453; goto _test_eof; 
	_test_eof454: cs = 454; goto _test_eof; 
	_test_eof455: cs = 455; goto _test_eof; 
	_test_eof456: cs = 456; goto _test_eof; 
	_test_eof457: cs = 457; goto _test_eof; 
	_test_eof458: cs = 458; goto _test_eof; 
	_test_eof459: cs = 459; goto _test_eof; 
	_test_eof460: cs = 460; goto _test_eof; 
	_test_eof461: cs = 461; goto _test_eof; 
	_test_eof462: cs = 462; goto _test_eof; 
	_test_eof930: cs = 930; goto _test_eof; 
	_test_eof463: cs = 463; goto _test_eof; 
	_test_eof464: cs = 464; goto _test_eof; 
	_test_eof931: cs = 931; goto _test_eof; 
	_test_eof465: cs = 465; goto _test_eof; 
	_test_eof466: cs = 466; goto _test_eof; 
	_test_eof467: cs = 467; goto _test_eof; 
	_test_eof468: cs = 468; goto _test_eof; 
	_test_eof469: cs = 469; goto _test_eof; 
	_test_eof470: cs = 470; goto _test_eof; 
	_test_eof471: cs = 471; goto _test_eof; 
	_test_eof932: cs = 932; goto _test_eof; 
	_test_eof472: cs = 472; goto _test_eof; 
	_test_eof473: cs = 473; goto _test_eof; 
	_test_eof933: cs = 933; goto _test_eof; 
	_test_eof474: cs = 474; goto _test_eof; 
	_test_eof475: cs = 475; goto _test_eof; 
	_test_eof934: cs = 934; goto _test_eof; 
	_test_eof476: cs = 476; goto _test_eof; 
	_test_eof477: cs = 477; goto _test_eof; 
	_test_eof478: cs = 478; goto _test_eof; 
	_test_eof479: cs = 479; goto _test_eof; 
	_test_eof480: cs = 480; goto _test_eof; 
	_test_eof481: cs = 481; goto _test_eof; 
	_test_eof482: cs = 482; goto _test_eof; 
	_test_eof483: cs = 483; goto _test_eof; 
	_test_eof484: cs = 484; goto _test_eof; 
	_test_eof485: cs = 485; goto _test_eof; 
	_test_eof486: cs = 486; goto _test_eof; 
	_test_eof487: cs = 487; goto _test_eof; 
	_test_eof488: cs = 488; goto _test_eof; 
	_test_eof489: cs = 489; goto _test_eof; 
	_test_eof490: cs = 490; goto _test_eof; 
	_test_eof491: cs = 491; goto _test_eof; 
	_test_eof492: cs = 492; goto _test_eof; 
	_test_eof493: cs = 493; goto _test_eof; 
	_test_eof935: cs = 935; goto _test_eof; 
	_test_eof494: cs = 494; goto _test_eof; 
	_test_eof495: cs = 495; goto _test_eof; 
	_test_eof496: cs = 496; goto _test_eof; 
	_test_eof497: cs = 497; goto _test_eof; 
	_test_eof498: cs = 498; goto _test_eof; 
	_test_eof499: cs = 499; goto _test_eof; 
	_test_eof500: cs = 500; goto _test_eof; 
	_test_eof501: cs = 501; goto _test_eof; 
	_test_eof502: cs = 502; goto _test_eof; 
	_test_eof503: cs = 503; goto _test_eof; 
	_test_eof504: cs = 504; goto _test_eof; 
	_test_eof505: cs = 505; goto _test_eof; 
	_test_eof506: cs = 506; goto _test_eof; 
	_test_eof507: cs = 507; goto _test_eof; 
	_test_eof936: cs = 936; goto _test_eof; 
	_test_eof508: cs = 508; goto _test_eof; 
	_test_eof509: cs = 509; goto _test_eof; 
	_test_eof937: cs = 937; goto _test_eof; 
	_test_eof510: cs = 510; goto _test_eof; 
	_test_eof511: cs = 511; goto _test_eof; 
	_test_eof512: cs = 512; goto _test_eof; 
	_test_eof513: cs = 513; goto _test_eof; 
	_test_eof514: cs = 514; goto _test_eof; 
	_test_eof938: cs = 938; goto _test_eof; 
	_test_eof515: cs = 515; goto _test_eof; 
	_test_eof516: cs = 516; goto _test_eof; 
	_test_eof517: cs = 517; goto _test_eof; 
	_test_eof518: cs = 518; goto _test_eof; 
	_test_eof519: cs = 519; goto _test_eof; 
	_test_eof520: cs = 520; goto _test_eof; 
	_test_eof521: cs = 521; goto _test_eof; 
	_test_eof522: cs = 522; goto _test_eof; 
	_test_eof523: cs = 523; goto _test_eof; 
	_test_eof524: cs = 524; goto _test_eof; 
	_test_eof525: cs = 525; goto _test_eof; 
	_test_eof526: cs = 526; goto _test_eof; 
	_test_eof527: cs = 527; goto _test_eof; 
	_test_eof528: cs = 528; goto _test_eof; 
	_test_eof529: cs = 529; goto _test_eof; 
	_test_eof530: cs = 530; goto _test_eof; 
	_test_eof531: cs = 531; goto _test_eof; 
	_test_eof532: cs = 532; goto _test_eof; 
	_test_eof533: cs = 533; goto _test_eof; 
	_test_eof534: cs = 534; goto _test_eof; 
	_test_eof535: cs = 535; goto _test_eof; 
	_test_eof536: cs = 536; goto _test_eof; 
	_test_eof537: cs = 537; goto _test_eof; 
	_test_eof538: cs = 538; goto _test_eof; 
	_test_eof539: cs = 539; goto _test_eof; 
	_test_eof540: cs = 540; goto _test_eof; 
	_test_eof541: cs = 541; goto _test_eof; 
	_test_eof542: cs = 542; goto _test_eof; 
	_test_eof543: cs = 543; goto _test_eof; 
	_test_eof544: cs = 544; goto _test_eof; 
	_test_eof545: cs = 545; goto _test_eof; 
	_test_eof546: cs = 546; goto _test_eof; 
	_test_eof547: cs = 547; goto _test_eof; 
	_test_eof548: cs = 548; goto _test_eof; 
	_test_eof549: cs = 549; goto _test_eof; 
	_test_eof550: cs = 550; goto _test_eof; 
	_test_eof551: cs = 551; goto _test_eof; 
	_test_eof552: cs = 552; goto _test_eof; 
	_test_eof553: cs = 553; goto _test_eof; 
	_test_eof554: cs = 554; goto _test_eof; 
	_test_eof555: cs = 555; goto _test_eof; 
	_test_eof556: cs = 556; goto _test_eof; 
	_test_eof557: cs = 557; goto _test_eof; 
	_test_eof558: cs = 558; goto _test_eof; 
	_test_eof559: cs = 559; goto _test_eof; 
	_test_eof560: cs = 560; goto _test_eof; 
	_test_eof561: cs = 561; goto _test_eof; 
	_test_eof562: cs = 562; goto _test_eof; 
	_test_eof563: cs = 563; goto _test_eof; 
	_test_eof564: cs = 564; goto _test_eof; 
	_test_eof565: cs = 565; goto _test_eof; 
	_test_eof566: cs = 566; goto _test_eof; 
	_test_eof567: cs = 567; goto _test_eof; 
	_test_eof568: cs = 568; goto _test_eof; 
	_test_eof569: cs = 569; goto _test_eof; 
	_test_eof570: cs = 570; goto _test_eof; 
	_test_eof571: cs = 571; goto _test_eof; 
	_test_eof572: cs = 572; goto _test_eof; 
	_test_eof573: cs = 573; goto _test_eof; 
	_test_eof574: cs = 574; goto _test_eof; 
	_test_eof575: cs = 575; goto _test_eof; 
	_test_eof576: cs = 576; goto _test_eof; 
	_test_eof577: cs = 577; goto _test_eof; 
	_test_eof578: cs = 578; goto _test_eof; 
	_test_eof579: cs = 579; goto _test_eof; 
	_test_eof580: cs = 580; goto _test_eof; 
	_test_eof581: cs = 581; goto _test_eof; 
	_test_eof582: cs = 582; goto _test_eof; 
	_test_eof583: cs = 583; goto _test_eof; 
	_test_eof939: cs = 939; goto _test_eof; 
	_test_eof584: cs = 584; goto _test_eof; 
	_test_eof585: cs = 585; goto _test_eof; 
	_test_eof940: cs = 940; goto _test_eof; 
	_test_eof586: cs = 586; goto _test_eof; 
	_test_eof587: cs = 587; goto _test_eof; 
	_test_eof588: cs = 588; goto _test_eof; 
	_test_eof589: cs = 589; goto _test_eof; 
	_test_eof590: cs = 590; goto _test_eof; 
	_test_eof591: cs = 591; goto _test_eof; 
	_test_eof941: cs = 941; goto _test_eof; 
	_test_eof592: cs = 592; goto _test_eof; 
	_test_eof593: cs = 593; goto _test_eof; 
	_test_eof594: cs = 594; goto _test_eof; 
	_test_eof595: cs = 595; goto _test_eof; 
	_test_eof942: cs = 942; goto _test_eof; 
	_test_eof596: cs = 596; goto _test_eof; 
	_test_eof597: cs = 597; goto _test_eof; 
	_test_eof943: cs = 943; goto _test_eof; 
	_test_eof598: cs = 598; goto _test_eof; 
	_test_eof599: cs = 599; goto _test_eof; 
	_test_eof600: cs = 600; goto _test_eof; 
	_test_eof601: cs = 601; goto _test_eof; 
	_test_eof602: cs = 602; goto _test_eof; 
	_test_eof603: cs = 603; goto _test_eof; 
	_test_eof944: cs = 944; goto _test_eof; 
	_test_eof604: cs = 604; goto _test_eof; 
	_test_eof605: cs = 605; goto _test_eof; 
	_test_eof945: cs = 945; goto _test_eof; 
	_test_eof606: cs = 606; goto _test_eof; 
	_test_eof607: cs = 607; goto _test_eof; 
	_test_eof946: cs = 946; goto _test_eof; 
	_test_eof608: cs = 608; goto _test_eof; 
	_test_eof609: cs = 609; goto _test_eof; 
	_test_eof610: cs = 610; goto _test_eof; 
	_test_eof611: cs = 611; goto _test_eof; 
	_test_eof612: cs = 612; goto _test_eof; 
	_test_eof613: cs = 613; goto _test_eof; 
	_test_eof614: cs = 614; goto _test_eof; 
	_test_eof947: cs = 947; goto _test_eof; 
	_test_eof615: cs = 615; goto _test_eof; 
	_test_eof616: cs = 616; goto _test_eof; 
	_test_eof948: cs = 948; goto _test_eof; 
	_test_eof617: cs = 617; goto _test_eof; 
	_test_eof618: cs = 618; goto _test_eof; 
	_test_eof949: cs = 949; goto _test_eof; 
	_test_eof619: cs = 619; goto _test_eof; 
	_test_eof620: cs = 620; goto _test_eof; 
	_test_eof621: cs = 621; goto _test_eof; 
	_test_eof622: cs = 622; goto _test_eof; 
	_test_eof623: cs = 623; goto _test_eof; 
	_test_eof624: cs = 624; goto _test_eof; 
	_test_eof625: cs = 625; goto _test_eof; 
	_test_eof626: cs = 626; goto _test_eof; 
	_test_eof627: cs = 627; goto _test_eof; 
	_test_eof628: cs = 628; goto _test_eof; 
	_test_eof629: cs = 629; goto _test_eof; 
	_test_eof630: cs = 630; goto _test_eof; 
	_test_eof631: cs = 631; goto _test_eof; 
	_test_eof632: cs = 632; goto _test_eof; 
	_test_eof633: cs = 633; goto _test_eof; 
	_test_eof950: cs = 950; goto _test_eof; 
	_test_eof634: cs = 634; goto _test_eof; 
	_test_eof635: cs = 635; goto _test_eof; 
	_test_eof951: cs = 951; goto _test_eof; 
	_test_eof636: cs = 636; goto _test_eof; 
	_test_eof637: cs = 637; goto _test_eof; 
	_test_eof638: cs = 638; goto _test_eof; 
	_test_eof639: cs = 639; goto _test_eof; 
	_test_eof640: cs = 640; goto _test_eof; 
	_test_eof641: cs = 641; goto _test_eof; 
	_test_eof642: cs = 642; goto _test_eof; 
	_test_eof643: cs = 643; goto _test_eof; 
	_test_eof644: cs = 644; goto _test_eof; 
	_test_eof645: cs = 645; goto _test_eof; 
	_test_eof646: cs = 646; goto _test_eof; 
	_test_eof647: cs = 647; goto _test_eof; 
	_test_eof648: cs = 648; goto _test_eof; 
	_test_eof649: cs = 649; goto _test_eof; 
	_test_eof650: cs = 650; goto _test_eof; 
	_test_eof651: cs = 651; goto _test_eof; 
	_test_eof652: cs = 652; goto _test_eof; 
	_test_eof653: cs = 653; goto _test_eof; 
	_test_eof654: cs = 654; goto _test_eof; 
	_test_eof952: cs = 952; goto _test_eof; 
	_test_eof655: cs = 655; goto _test_eof; 
	_test_eof656: cs = 656; goto _test_eof; 
	_test_eof657: cs = 657; goto _test_eof; 
	_test_eof658: cs = 658; goto _test_eof; 
	_test_eof659: cs = 659; goto _test_eof; 
	_test_eof660: cs = 660; goto _test_eof; 
	_test_eof661: cs = 661; goto _test_eof; 
	_test_eof662: cs = 662; goto _test_eof; 
	_test_eof663: cs = 663; goto _test_eof; 
	_test_eof664: cs = 664; goto _test_eof; 
	_test_eof665: cs = 665; goto _test_eof; 
	_test_eof666: cs = 666; goto _test_eof; 
	_test_eof667: cs = 667; goto _test_eof; 
	_test_eof668: cs = 668; goto _test_eof; 
	_test_eof669: cs = 669; goto _test_eof; 
	_test_eof953: cs = 953; goto _test_eof; 
	_test_eof670: cs = 670; goto _test_eof; 
	_test_eof671: cs = 671; goto _test_eof; 
	_test_eof672: cs = 672; goto _test_eof; 
	_test_eof673: cs = 673; goto _test_eof; 
	_test_eof674: cs = 674; goto _test_eof; 
	_test_eof675: cs = 675; goto _test_eof; 
	_test_eof676: cs = 676; goto _test_eof; 
	_test_eof677: cs = 677; goto _test_eof; 
	_test_eof678: cs = 678; goto _test_eof; 
	_test_eof679: cs = 679; goto _test_eof; 
	_test_eof680: cs = 680; goto _test_eof; 
	_test_eof681: cs = 681; goto _test_eof; 
	_test_eof682: cs = 682; goto _test_eof; 
	_test_eof683: cs = 683; goto _test_eof; 
	_test_eof954: cs = 954; goto _test_eof; 
	_test_eof684: cs = 684; goto _test_eof; 
	_test_eof685: cs = 685; goto _test_eof; 
	_test_eof686: cs = 686; goto _test_eof; 
	_test_eof687: cs = 687; goto _test_eof; 
	_test_eof688: cs = 688; goto _test_eof; 
	_test_eof689: cs = 689; goto _test_eof; 
	_test_eof690: cs = 690; goto _test_eof; 
	_test_eof691: cs = 691; goto _test_eof; 
	_test_eof692: cs = 692; goto _test_eof; 
	_test_eof693: cs = 693; goto _test_eof; 
	_test_eof694: cs = 694; goto _test_eof; 
	_test_eof695: cs = 695; goto _test_eof; 
	_test_eof696: cs = 696; goto _test_eof; 
	_test_eof697: cs = 697; goto _test_eof; 
	_test_eof698: cs = 698; goto _test_eof; 
	_test_eof699: cs = 699; goto _test_eof; 
	_test_eof955: cs = 955; goto _test_eof; 
	_test_eof700: cs = 700; goto _test_eof; 
	_test_eof701: cs = 701; goto _test_eof; 
	_test_eof956: cs = 956; goto _test_eof; 
	_test_eof702: cs = 702; goto _test_eof; 
	_test_eof703: cs = 703; goto _test_eof; 
	_test_eof704: cs = 704; goto _test_eof; 
	_test_eof705: cs = 705; goto _test_eof; 
	_test_eof706: cs = 706; goto _test_eof; 
	_test_eof707: cs = 707; goto _test_eof; 
	_test_eof957: cs = 957; goto _test_eof; 
	_test_eof708: cs = 708; goto _test_eof; 
	_test_eof709: cs = 709; goto _test_eof; 
	_test_eof710: cs = 710; goto _test_eof; 
	_test_eof711: cs = 711; goto _test_eof; 
	_test_eof712: cs = 712; goto _test_eof; 
	_test_eof713: cs = 713; goto _test_eof; 
	_test_eof714: cs = 714; goto _test_eof; 
	_test_eof715: cs = 715; goto _test_eof; 
	_test_eof716: cs = 716; goto _test_eof; 
	_test_eof717: cs = 717; goto _test_eof; 
	_test_eof718: cs = 718; goto _test_eof; 
	_test_eof719: cs = 719; goto _test_eof; 
	_test_eof958: cs = 958; goto _test_eof; 
	_test_eof720: cs = 720; goto _test_eof; 
	_test_eof721: cs = 721; goto _test_eof; 
	_test_eof959: cs = 959; goto _test_eof; 
	_test_eof722: cs = 722; goto _test_eof; 
	_test_eof723: cs = 723; goto _test_eof; 
	_test_eof724: cs = 724; goto _test_eof; 
	_test_eof725: cs = 725; goto _test_eof; 
	_test_eof726: cs = 726; goto _test_eof; 
	_test_eof727: cs = 727; goto _test_eof; 
	_test_eof728: cs = 728; goto _test_eof; 
	_test_eof960: cs = 960; goto _test_eof; 
	_test_eof729: cs = 729; goto _test_eof; 
	_test_eof730: cs = 730; goto _test_eof; 
	_test_eof731: cs = 731; goto _test_eof; 
	_test_eof732: cs = 732; goto _test_eof; 
	_test_eof733: cs = 733; goto _test_eof; 
	_test_eof734: cs = 734; goto _test_eof; 
	_test_eof961: cs = 961; goto _test_eof; 
	_test_eof735: cs = 735; goto _test_eof; 
	_test_eof736: cs = 736; goto _test_eof; 
	_test_eof962: cs = 962; goto _test_eof; 
	_test_eof737: cs = 737; goto _test_eof; 
	_test_eof738: cs = 738; goto _test_eof; 
	_test_eof739: cs = 739; goto _test_eof; 
	_test_eof740: cs = 740; goto _test_eof; 
	_test_eof741: cs = 741; goto _test_eof; 
	_test_eof742: cs = 742; goto _test_eof; 
	_test_eof743: cs = 743; goto _test_eof; 
	_test_eof744: cs = 744; goto _test_eof; 
	_test_eof745: cs = 745; goto _test_eof; 
	_test_eof746: cs = 746; goto _test_eof; 
	_test_eof747: cs = 747; goto _test_eof; 
	_test_eof748: cs = 748; goto _test_eof; 
	_test_eof963: cs = 963; goto _test_eof; 
	_test_eof749: cs = 749; goto _test_eof; 
	_test_eof750: cs = 750; goto _test_eof; 
	_test_eof964: cs = 964; goto _test_eof; 
	_test_eof751: cs = 751; goto _test_eof; 
	_test_eof752: cs = 752; goto _test_eof; 
	_test_eof753: cs = 753; goto _test_eof; 
	_test_eof754: cs = 754; goto _test_eof; 
	_test_eof755: cs = 755; goto _test_eof; 
	_test_eof756: cs = 756; goto _test_eof; 
	_test_eof757: cs = 757; goto _test_eof; 
	_test_eof965: cs = 965; goto _test_eof; 
	_test_eof758: cs = 758; goto _test_eof; 
	_test_eof759: cs = 759; goto _test_eof; 
	_test_eof760: cs = 760; goto _test_eof; 
	_test_eof761: cs = 761; goto _test_eof; 
	_test_eof762: cs = 762; goto _test_eof; 
	_test_eof763: cs = 763; goto _test_eof; 
	_test_eof764: cs = 764; goto _test_eof; 
	_test_eof765: cs = 765; goto _test_eof; 
	_test_eof766: cs = 766; goto _test_eof; 
	_test_eof767: cs = 767; goto _test_eof; 
	_test_eof768: cs = 768; goto _test_eof; 
	_test_eof769: cs = 769; goto _test_eof; 
	_test_eof966: cs = 966; goto _test_eof; 
	_test_eof770: cs = 770; goto _test_eof; 
	_test_eof771: cs = 771; goto _test_eof; 
	_test_eof967: cs = 967; goto _test_eof; 
	_test_eof772: cs = 772; goto _test_eof; 
	_test_eof773: cs = 773; goto _test_eof; 
	_test_eof774: cs = 774; goto _test_eof; 
	_test_eof775: cs = 775; goto _test_eof; 
	_test_eof776: cs = 776; goto _test_eof; 
	_test_eof777: cs = 777; goto _test_eof; 
	_test_eof778: cs = 778; goto _test_eof; 
	_test_eof779: cs = 779; goto _test_eof; 
	_test_eof968: cs = 968; goto _test_eof; 
	_test_eof780: cs = 780; goto _test_eof; 
	_test_eof781: cs = 781; goto _test_eof; 
	_test_eof782: cs = 782; goto _test_eof; 
	_test_eof783: cs = 783; goto _test_eof; 
	_test_eof784: cs = 784; goto _test_eof; 
	_test_eof785: cs = 785; goto _test_eof; 
	_test_eof786: cs = 786; goto _test_eof; 
	_test_eof787: cs = 787; goto _test_eof; 
	_test_eof969: cs = 969; goto _test_eof; 
	_test_eof788: cs = 788; goto _test_eof; 
	_test_eof789: cs = 789; goto _test_eof; 
	_test_eof790: cs = 790; goto _test_eof; 
	_test_eof791: cs = 791; goto _test_eof; 
	_test_eof792: cs = 792; goto _test_eof; 
	_test_eof793: cs = 793; goto _test_eof; 
	_test_eof794: cs = 794; goto _test_eof; 
	_test_eof795: cs = 795; goto _test_eof; 
	_test_eof796: cs = 796; goto _test_eof; 
	_test_eof797: cs = 797; goto _test_eof; 
	_test_eof798: cs = 798; goto _test_eof; 
	_test_eof799: cs = 799; goto _test_eof; 
	_test_eof800: cs = 800; goto _test_eof; 
	_test_eof801: cs = 801; goto _test_eof; 
	_test_eof802: cs = 802; goto _test_eof; 
	_test_eof803: cs = 803; goto _test_eof; 
	_test_eof804: cs = 804; goto _test_eof; 
	_test_eof805: cs = 805; goto _test_eof; 
	_test_eof806: cs = 806; goto _test_eof; 
	_test_eof807: cs = 807; goto _test_eof; 
	_test_eof970: cs = 970; goto _test_eof; 
	_test_eof808: cs = 808; goto _test_eof; 
	_test_eof809: cs = 809; goto _test_eof; 
	_test_eof971: cs = 971; goto _test_eof; 
	_test_eof810: cs = 810; goto _test_eof; 
	_test_eof811: cs = 811; goto _test_eof; 
	_test_eof812: cs = 812; goto _test_eof; 
	_test_eof813: cs = 813; goto _test_eof; 
	_test_eof814: cs = 814; goto _test_eof; 
	_test_eof972: cs = 972; goto _test_eof; 
	_test_eof815: cs = 815; goto _test_eof; 
	_test_eof816: cs = 816; goto _test_eof; 
	_test_eof817: cs = 817; goto _test_eof; 
	_test_eof818: cs = 818; goto _test_eof; 
	_test_eof819: cs = 819; goto _test_eof; 
	_test_eof820: cs = 820; goto _test_eof; 
	_test_eof821: cs = 821; goto _test_eof; 
	_test_eof822: cs = 822; goto _test_eof; 
	_test_eof823: cs = 823; goto _test_eof; 
	_test_eof824: cs = 824; goto _test_eof; 
	_test_eof825: cs = 825; goto _test_eof; 
	_test_eof826: cs = 826; goto _test_eof; 
	_test_eof827: cs = 827; goto _test_eof; 
	_test_eof828: cs = 828; goto _test_eof; 
	_test_eof829: cs = 829; goto _test_eof; 
	_test_eof830: cs = 830; goto _test_eof; 
	_test_eof831: cs = 831; goto _test_eof; 
	_test_eof832: cs = 832; goto _test_eof; 
	_test_eof833: cs = 833; goto _test_eof; 
	_test_eof834: cs = 834; goto _test_eof; 
	_test_eof835: cs = 835; goto _test_eof; 
	_test_eof836: cs = 836; goto _test_eof; 
	_test_eof837: cs = 837; goto _test_eof; 
	_test_eof838: cs = 838; goto _test_eof; 
	_test_eof839: cs = 839; goto _test_eof; 
	_test_eof840: cs = 840; goto _test_eof; 
	_test_eof841: cs = 841; goto _test_eof; 
	_test_eof842: cs = 842; goto _test_eof; 
	_test_eof843: cs = 843; goto _test_eof; 
	_test_eof844: cs = 844; goto _test_eof; 
	_test_eof845: cs = 845; goto _test_eof; 
	_test_eof846: cs = 846; goto _test_eof; 
	_test_eof847: cs = 847; goto _test_eof; 
	_test_eof848: cs = 848; goto _test_eof; 
	_test_eof849: cs = 849; goto _test_eof; 
	_test_eof850: cs = 850; goto _test_eof; 
	_test_eof851: cs = 851; goto _test_eof; 
	_test_eof852: cs = 852; goto _test_eof; 
	_test_eof853: cs = 853; goto _test_eof; 
	_test_eof854: cs = 854; goto _test_eof; 
	_test_eof855: cs = 855; goto _test_eof; 
	_test_eof856: cs = 856; goto _test_eof; 
	_test_eof857: cs = 857; goto _test_eof; 
	_test_eof858: cs = 858; goto _test_eof; 
	_test_eof859: cs = 859; goto _test_eof; 
	_test_eof860: cs = 860; goto _test_eof; 
	_test_eof861: cs = 861; goto _test_eof; 
	_test_eof862: cs = 862; goto _test_eof; 
	_test_eof863: cs = 863; goto _test_eof; 
	_test_eof864: cs = 864; goto _test_eof; 
	_test_eof865: cs = 865; goto _test_eof; 
	_test_eof866: cs = 866; goto _test_eof; 
	_test_eof867: cs = 867; goto _test_eof; 
	_test_eof868: cs = 868; goto _test_eof; 
	_test_eof869: cs = 869; goto _test_eof; 
	_test_eof870: cs = 870; goto _test_eof; 
	_test_eof871: cs = 871; goto _test_eof; 
	_test_eof872: cs = 872; goto _test_eof; 
	_test_eof873: cs = 873; goto _test_eof; 
	_test_eof874: cs = 874; goto _test_eof; 
	_test_eof875: cs = 875; goto _test_eof; 
	_test_eof876: cs = 876; goto _test_eof; 
	_test_eof877: cs = 877; goto _test_eof; 
	_test_eof878: cs = 878; goto _test_eof; 

	_test_eof: {}
	_out: {}
	}

#line 429 "confscanner.rl"

    /* Check if we failed. */
    if ( cs == ConfFileScanner_error )
    {
      /* Machine failed before finding a token. */
      cerr << "in conffile: PARSE ERROR in line " << line << endl;
      exit(1);
    }

    have = rpe - pe;
    /* cerr << "memmove by " << have << "bytes\n";*/
    memmove( buf, pe, have );
  }

  return 0;
}
/* vim: set et sw=2 ft=ragel: */
