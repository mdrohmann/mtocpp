
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


#line 25 "mfilescanner.cc"
static const int MFileScanner_start = 1608;
static const int MFileScanner_first_final = 1608;
static const int MFileScanner_error = 0;

static const int MFileScanner_en_in_comment_block = 1609;
static const int MFileScanner_en_funcline = 1610;
static const int MFileScanner_en_funcbody = 1632;
static const int MFileScanner_en_fill_list = 1637;
static const int MFileScanner_en_doxy_get_body = 1640;
static const int MFileScanner_en_doxyfunction_garble = 1648;
static const int MFileScanner_en_doxy_get_brief = 1649;
static const int MFileScanner_en_doxyheader = 222;
static const int MFileScanner_en_events = 1652;
static const int MFileScanner_en_methods = 243;
static const int MFileScanner_en_property = 1661;
static const int MFileScanner_en_properties = 786;
static const int MFileScanner_en_classbody = 1668;
static const int MFileScanner_en_expect_doxyblock = 1451;
static const int MFileScanner_en_script = 1452;
static const int MFileScanner_en_funct = 1453;
static const int MFileScanner_en_class = 1549;
static const int MFileScanner_en_class_classdef = 1561;
static const int MFileScanner_en_main = 1608;


#line 1107 "mfilescanner.rl"


void MFileScanner :: print_access_specifier(AccessEnum & access)
{
  if(access == Public)
    cout << "public:\n";
  else if(access == Protected)
    cout << "protected:\n";
  else if(access == Private)
    cout << "private:\n";
}

// constructor
MFileScanner :: MFileScanner(istream & fin, const std::string & filename,
                             const std::string & conffilename, bool latex_output) :
  fin_(fin), filename_(filename),
  latex_output_(latex_output), cscan_(filename_, conffilename),
  fnname_(filename),
  line(1),
  ts(0), have(0), top(0),
  opt(false), new_syntax_(false),
  is_script_(false), is_first_function_(true),
  is_class_(false), is_setter_(false), is_getter_(false),
  classname_(), funcindent_(0), eventindent_(0),
  class_part_(Header),
  access_(), propertyparams_(), methodparams_(), property_list_()
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

// run the scanner
int MFileScanner :: execute()
{
  std::ios::sync_with_stdio(false);

  
#line 99 "mfilescanner.cc"
	{
	cs = MFileScanner_start;
	top = 0;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 1154 "mfilescanner.rl"

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

    
#line 166 "mfilescanner.cc"
	{
	if ( p == pe )
		goto _test_eof;
	goto _resume;

_again:
	switch ( cs ) {
		case 1608: goto st1608;
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
		case 12: goto st12;
		case 13: goto st13;
		case 14: goto st14;
		case 15: goto st15;
		case 16: goto st16;
		case 17: goto st17;
		case 18: goto st18;
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
		case 1651: goto st1651;
		case 233: goto st233;
		case 234: goto st234;
		case 235: goto st235;
		case 236: goto st236;
		case 243: goto st243;
		case 244: goto st244;
		case 245: goto st245;
		case 246: goto st246;
		case 247: goto st247;
		case 248: goto st248;
		case 249: goto st249;
		case 1653: goto st1653;
		case 1654: goto st1654;
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
		case 1655: goto st1655;
		case 1656: goto st1656;
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
		case 314: goto st314;
		case 315: goto st315;
		case 316: goto st316;
		case 317: goto st317;
		case 318: goto st318;
		case 319: goto st319;
		case 320: goto st320;
		case 321: goto st321;
		case 322: goto st322;
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
		case 338: goto st338;
		case 339: goto st339;
		case 340: goto st340;
		case 341: goto st341;
		case 342: goto st342;
		case 343: goto st343;
		case 344: goto st344;
		case 345: goto st345;
		case 346: goto st346;
		case 347: goto st347;
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
		case 359: goto st359;
		case 360: goto st360;
		case 361: goto st361;
		case 362: goto st362;
		case 363: goto st363;
		case 364: goto st364;
		case 365: goto st365;
		case 366: goto st366;
		case 367: goto st367;
		case 368: goto st368;
		case 369: goto st369;
		case 370: goto st370;
		case 371: goto st371;
		case 372: goto st372;
		case 373: goto st373;
		case 374: goto st374;
		case 375: goto st375;
		case 1657: goto st1657;
		case 1658: goto st1658;
		case 376: goto st376;
		case 377: goto st377;
		case 378: goto st378;
		case 379: goto st379;
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
		case 393: goto st393;
		case 394: goto st394;
		case 395: goto st395;
		case 396: goto st396;
		case 397: goto st397;
		case 398: goto st398;
		case 399: goto st399;
		case 400: goto st400;
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
		case 421: goto st421;
		case 422: goto st422;
		case 423: goto st423;
		case 424: goto st424;
		case 425: goto st425;
		case 426: goto st426;
		case 427: goto st427;
		case 428: goto st428;
		case 429: goto st429;
		case 1659: goto st1659;
		case 1660: goto st1660;
		case 430: goto st430;
		case 431: goto st431;
		case 432: goto st432;
		case 433: goto st433;
		case 434: goto st434;
		case 435: goto st435;
		case 436: goto st436;
		case 437: goto st437;
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
		case 463: goto st463;
		case 464: goto st464;
		case 465: goto st465;
		case 466: goto st466;
		case 467: goto st467;
		case 468: goto st468;
		case 469: goto st469;
		case 470: goto st470;
		case 471: goto st471;
		case 472: goto st472;
		case 473: goto st473;
		case 474: goto st474;
		case 475: goto st475;
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
		case 508: goto st508;
		case 509: goto st509;
		case 510: goto st510;
		case 511: goto st511;
		case 512: goto st512;
		case 513: goto st513;
		case 514: goto st514;
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
		case 584: goto st584;
		case 585: goto st585;
		case 586: goto st586;
		case 587: goto st587;
		case 588: goto st588;
		case 589: goto st589;
		case 590: goto st590;
		case 591: goto st591;
		case 592: goto st592;
		case 593: goto st593;
		case 594: goto st594;
		case 595: goto st595;
		case 596: goto st596;
		case 597: goto st597;
		case 598: goto st598;
		case 599: goto st599;
		case 600: goto st600;
		case 601: goto st601;
		case 602: goto st602;
		case 603: goto st603;
		case 604: goto st604;
		case 605: goto st605;
		case 606: goto st606;
		case 607: goto st607;
		case 608: goto st608;
		case 609: goto st609;
		case 610: goto st610;
		case 611: goto st611;
		case 612: goto st612;
		case 613: goto st613;
		case 614: goto st614;
		case 615: goto st615;
		case 616: goto st616;
		case 617: goto st617;
		case 618: goto st618;
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
		case 634: goto st634;
		case 635: goto st635;
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
		case 700: goto st700;
		case 701: goto st701;
		case 702: goto st702;
		case 703: goto st703;
		case 704: goto st704;
		case 705: goto st705;
		case 706: goto st706;
		case 707: goto st707;
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
		case 720: goto st720;
		case 721: goto st721;
		case 722: goto st722;
		case 723: goto st723;
		case 724: goto st724;
		case 725: goto st725;
		case 726: goto st726;
		case 727: goto st727;
		case 728: goto st728;
		case 729: goto st729;
		case 730: goto st730;
		case 731: goto st731;
		case 732: goto st732;
		case 733: goto st733;
		case 734: goto st734;
		case 735: goto st735;
		case 736: goto st736;
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
		case 749: goto st749;
		case 750: goto st750;
		case 751: goto st751;
		case 752: goto st752;
		case 753: goto st753;
		case 754: goto st754;
		case 755: goto st755;
		case 756: goto st756;
		case 757: goto st757;
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
		case 770: goto st770;
		case 771: goto st771;
		case 772: goto st772;
		case 773: goto st773;
		case 774: goto st774;
		case 775: goto st775;
		case 776: goto st776;
		case 786: goto st786;
		case 787: goto st787;
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
		case 1662: goto st1662;
		case 1663: goto st1663;
		case 801: goto st801;
		case 802: goto st802;
		case 803: goto st803;
		case 804: goto st804;
		case 805: goto st805;
		case 806: goto st806;
		case 807: goto st807;
		case 808: goto st808;
		case 809: goto st809;
		case 810: goto st810;
		case 811: goto st811;
		case 812: goto st812;
		case 813: goto st813;
		case 814: goto st814;
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
		case 1664: goto st1664;
		case 1665: goto st1665;
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
		case 879: goto st879;
		case 880: goto st880;
		case 881: goto st881;
		case 882: goto st882;
		case 883: goto st883;
		case 884: goto st884;
		case 885: goto st885;
		case 886: goto st886;
		case 887: goto st887;
		case 888: goto st888;
		case 889: goto st889;
		case 890: goto st890;
		case 891: goto st891;
		case 892: goto st892;
		case 893: goto st893;
		case 894: goto st894;
		case 895: goto st895;
		case 896: goto st896;
		case 897: goto st897;
		case 898: goto st898;
		case 899: goto st899;
		case 900: goto st900;
		case 901: goto st901;
		case 902: goto st902;
		case 903: goto st903;
		case 904: goto st904;
		case 905: goto st905;
		case 906: goto st906;
		case 907: goto st907;
		case 908: goto st908;
		case 909: goto st909;
		case 910: goto st910;
		case 911: goto st911;
		case 912: goto st912;
		case 913: goto st913;
		case 914: goto st914;
		case 915: goto st915;
		case 916: goto st916;
		case 917: goto st917;
		case 918: goto st918;
		case 919: goto st919;
		case 920: goto st920;
		case 921: goto st921;
		case 922: goto st922;
		case 923: goto st923;
		case 924: goto st924;
		case 925: goto st925;
		case 926: goto st926;
		case 927: goto st927;
		case 928: goto st928;
		case 929: goto st929;
		case 930: goto st930;
		case 931: goto st931;
		case 1666: goto st1666;
		case 1667: goto st1667;
		case 932: goto st932;
		case 933: goto st933;
		case 934: goto st934;
		case 935: goto st935;
		case 936: goto st936;
		case 937: goto st937;
		case 938: goto st938;
		case 939: goto st939;
		case 940: goto st940;
		case 941: goto st941;
		case 942: goto st942;
		case 943: goto st943;
		case 944: goto st944;
		case 945: goto st945;
		case 946: goto st946;
		case 947: goto st947;
		case 948: goto st948;
		case 949: goto st949;
		case 950: goto st950;
		case 951: goto st951;
		case 952: goto st952;
		case 953: goto st953;
		case 954: goto st954;
		case 955: goto st955;
		case 956: goto st956;
		case 957: goto st957;
		case 958: goto st958;
		case 959: goto st959;
		case 960: goto st960;
		case 961: goto st961;
		case 962: goto st962;
		case 963: goto st963;
		case 964: goto st964;
		case 965: goto st965;
		case 966: goto st966;
		case 967: goto st967;
		case 968: goto st968;
		case 969: goto st969;
		case 970: goto st970;
		case 971: goto st971;
		case 972: goto st972;
		case 973: goto st973;
		case 974: goto st974;
		case 975: goto st975;
		case 976: goto st976;
		case 977: goto st977;
		case 978: goto st978;
		case 979: goto st979;
		case 980: goto st980;
		case 981: goto st981;
		case 982: goto st982;
		case 983: goto st983;
		case 984: goto st984;
		case 985: goto st985;
		case 986: goto st986;
		case 987: goto st987;
		case 988: goto st988;
		case 989: goto st989;
		case 990: goto st990;
		case 991: goto st991;
		case 992: goto st992;
		case 993: goto st993;
		case 994: goto st994;
		case 995: goto st995;
		case 996: goto st996;
		case 997: goto st997;
		case 998: goto st998;
		case 999: goto st999;
		case 1000: goto st1000;
		case 1001: goto st1001;
		case 1002: goto st1002;
		case 1003: goto st1003;
		case 1004: goto st1004;
		case 1005: goto st1005;
		case 1006: goto st1006;
		case 1007: goto st1007;
		case 1008: goto st1008;
		case 1009: goto st1009;
		case 1010: goto st1010;
		case 1011: goto st1011;
		case 1012: goto st1012;
		case 1013: goto st1013;
		case 1014: goto st1014;
		case 1015: goto st1015;
		case 1016: goto st1016;
		case 1017: goto st1017;
		case 1018: goto st1018;
		case 1019: goto st1019;
		case 1020: goto st1020;
		case 1021: goto st1021;
		case 1022: goto st1022;
		case 1023: goto st1023;
		case 1024: goto st1024;
		case 1025: goto st1025;
		case 1026: goto st1026;
		case 1027: goto st1027;
		case 1028: goto st1028;
		case 1029: goto st1029;
		case 1030: goto st1030;
		case 1031: goto st1031;
		case 1032: goto st1032;
		case 1033: goto st1033;
		case 1034: goto st1034;
		case 1035: goto st1035;
		case 1036: goto st1036;
		case 1037: goto st1037;
		case 1038: goto st1038;
		case 1039: goto st1039;
		case 1040: goto st1040;
		case 1041: goto st1041;
		case 1042: goto st1042;
		case 1043: goto st1043;
		case 1044: goto st1044;
		case 1045: goto st1045;
		case 1046: goto st1046;
		case 1047: goto st1047;
		case 1048: goto st1048;
		case 1049: goto st1049;
		case 1050: goto st1050;
		case 1051: goto st1051;
		case 1052: goto st1052;
		case 1053: goto st1053;
		case 1054: goto st1054;
		case 1055: goto st1055;
		case 1056: goto st1056;
		case 1057: goto st1057;
		case 1058: goto st1058;
		case 1059: goto st1059;
		case 1060: goto st1060;
		case 1061: goto st1061;
		case 1062: goto st1062;
		case 1063: goto st1063;
		case 1064: goto st1064;
		case 1065: goto st1065;
		case 1066: goto st1066;
		case 1067: goto st1067;
		case 1068: goto st1068;
		case 1069: goto st1069;
		case 1070: goto st1070;
		case 1071: goto st1071;
		case 1072: goto st1072;
		case 1073: goto st1073;
		case 1074: goto st1074;
		case 1075: goto st1075;
		case 1076: goto st1076;
		case 1077: goto st1077;
		case 1078: goto st1078;
		case 1079: goto st1079;
		case 1080: goto st1080;
		case 1081: goto st1081;
		case 1082: goto st1082;
		case 1083: goto st1083;
		case 1084: goto st1084;
		case 1085: goto st1085;
		case 1086: goto st1086;
		case 1087: goto st1087;
		case 1088: goto st1088;
		case 1089: goto st1089;
		case 1090: goto st1090;
		case 1091: goto st1091;
		case 1092: goto st1092;
		case 1093: goto st1093;
		case 1094: goto st1094;
		case 1095: goto st1095;
		case 1096: goto st1096;
		case 1097: goto st1097;
		case 1098: goto st1098;
		case 1099: goto st1099;
		case 1100: goto st1100;
		case 1101: goto st1101;
		case 1102: goto st1102;
		case 1103: goto st1103;
		case 1104: goto st1104;
		case 1105: goto st1105;
		case 1106: goto st1106;
		case 1107: goto st1107;
		case 1108: goto st1108;
		case 1109: goto st1109;
		case 1110: goto st1110;
		case 1111: goto st1111;
		case 1112: goto st1112;
		case 1113: goto st1113;
		case 1114: goto st1114;
		case 1115: goto st1115;
		case 1116: goto st1116;
		case 1117: goto st1117;
		case 1118: goto st1118;
		case 1119: goto st1119;
		case 1120: goto st1120;
		case 1121: goto st1121;
		case 1122: goto st1122;
		case 1123: goto st1123;
		case 1124: goto st1124;
		case 1125: goto st1125;
		case 1126: goto st1126;
		case 1127: goto st1127;
		case 1128: goto st1128;
		case 1129: goto st1129;
		case 1130: goto st1130;
		case 1131: goto st1131;
		case 1132: goto st1132;
		case 1133: goto st1133;
		case 1134: goto st1134;
		case 1135: goto st1135;
		case 1136: goto st1136;
		case 1137: goto st1137;
		case 1138: goto st1138;
		case 1139: goto st1139;
		case 1140: goto st1140;
		case 1141: goto st1141;
		case 1142: goto st1142;
		case 1143: goto st1143;
		case 1144: goto st1144;
		case 1145: goto st1145;
		case 1146: goto st1146;
		case 1147: goto st1147;
		case 1148: goto st1148;
		case 1149: goto st1149;
		case 1150: goto st1150;
		case 1151: goto st1151;
		case 1152: goto st1152;
		case 1153: goto st1153;
		case 1154: goto st1154;
		case 1155: goto st1155;
		case 1156: goto st1156;
		case 1157: goto st1157;
		case 1158: goto st1158;
		case 1159: goto st1159;
		case 1160: goto st1160;
		case 1161: goto st1161;
		case 1162: goto st1162;
		case 1163: goto st1163;
		case 1164: goto st1164;
		case 1165: goto st1165;
		case 1166: goto st1166;
		case 1167: goto st1167;
		case 1168: goto st1168;
		case 1169: goto st1169;
		case 1170: goto st1170;
		case 1171: goto st1171;
		case 1172: goto st1172;
		case 1173: goto st1173;
		case 1174: goto st1174;
		case 1175: goto st1175;
		case 1176: goto st1176;
		case 1177: goto st1177;
		case 1178: goto st1178;
		case 1179: goto st1179;
		case 1180: goto st1180;
		case 1181: goto st1181;
		case 1182: goto st1182;
		case 1183: goto st1183;
		case 1184: goto st1184;
		case 1185: goto st1185;
		case 1186: goto st1186;
		case 1187: goto st1187;
		case 1188: goto st1188;
		case 1189: goto st1189;
		case 1190: goto st1190;
		case 1191: goto st1191;
		case 1192: goto st1192;
		case 1193: goto st1193;
		case 1194: goto st1194;
		case 1195: goto st1195;
		case 1196: goto st1196;
		case 1197: goto st1197;
		case 1198: goto st1198;
		case 1199: goto st1199;
		case 1200: goto st1200;
		case 1201: goto st1201;
		case 1202: goto st1202;
		case 1203: goto st1203;
		case 1204: goto st1204;
		case 1205: goto st1205;
		case 1206: goto st1206;
		case 1207: goto st1207;
		case 1208: goto st1208;
		case 1209: goto st1209;
		case 1210: goto st1210;
		case 1211: goto st1211;
		case 1212: goto st1212;
		case 1213: goto st1213;
		case 1214: goto st1214;
		case 1215: goto st1215;
		case 1216: goto st1216;
		case 1217: goto st1217;
		case 1218: goto st1218;
		case 1219: goto st1219;
		case 1220: goto st1220;
		case 1221: goto st1221;
		case 1222: goto st1222;
		case 1223: goto st1223;
		case 1224: goto st1224;
		case 1225: goto st1225;
		case 1226: goto st1226;
		case 1227: goto st1227;
		case 1228: goto st1228;
		case 1229: goto st1229;
		case 1230: goto st1230;
		case 1231: goto st1231;
		case 1232: goto st1232;
		case 1233: goto st1233;
		case 1234: goto st1234;
		case 1235: goto st1235;
		case 1236: goto st1236;
		case 1237: goto st1237;
		case 1238: goto st1238;
		case 1239: goto st1239;
		case 1240: goto st1240;
		case 1241: goto st1241;
		case 1242: goto st1242;
		case 1243: goto st1243;
		case 1244: goto st1244;
		case 1245: goto st1245;
		case 1246: goto st1246;
		case 1247: goto st1247;
		case 1248: goto st1248;
		case 1249: goto st1249;
		case 1250: goto st1250;
		case 1251: goto st1251;
		case 1252: goto st1252;
		case 1253: goto st1253;
		case 1254: goto st1254;
		case 1255: goto st1255;
		case 1256: goto st1256;
		case 1257: goto st1257;
		case 1258: goto st1258;
		case 1259: goto st1259;
		case 1260: goto st1260;
		case 1261: goto st1261;
		case 1262: goto st1262;
		case 1263: goto st1263;
		case 1264: goto st1264;
		case 1265: goto st1265;
		case 1266: goto st1266;
		case 1267: goto st1267;
		case 1268: goto st1268;
		case 1269: goto st1269;
		case 1270: goto st1270;
		case 1271: goto st1271;
		case 1272: goto st1272;
		case 1273: goto st1273;
		case 1274: goto st1274;
		case 1275: goto st1275;
		case 1276: goto st1276;
		case 1277: goto st1277;
		case 1278: goto st1278;
		case 1279: goto st1279;
		case 1280: goto st1280;
		case 1281: goto st1281;
		case 1282: goto st1282;
		case 1283: goto st1283;
		case 1284: goto st1284;
		case 1285: goto st1285;
		case 1286: goto st1286;
		case 1287: goto st1287;
		case 1288: goto st1288;
		case 1289: goto st1289;
		case 1290: goto st1290;
		case 1291: goto st1291;
		case 1292: goto st1292;
		case 1293: goto st1293;
		case 1294: goto st1294;
		case 1295: goto st1295;
		case 1296: goto st1296;
		case 1297: goto st1297;
		case 1298: goto st1298;
		case 1299: goto st1299;
		case 1300: goto st1300;
		case 1301: goto st1301;
		case 1302: goto st1302;
		case 1303: goto st1303;
		case 1304: goto st1304;
		case 1305: goto st1305;
		case 1306: goto st1306;
		case 1307: goto st1307;
		case 1308: goto st1308;
		case 1309: goto st1309;
		case 1310: goto st1310;
		case 1311: goto st1311;
		case 1312: goto st1312;
		case 1313: goto st1313;
		case 1314: goto st1314;
		case 1315: goto st1315;
		case 1316: goto st1316;
		case 1317: goto st1317;
		case 1318: goto st1318;
		case 1319: goto st1319;
		case 1320: goto st1320;
		case 1321: goto st1321;
		case 1322: goto st1322;
		case 1323: goto st1323;
		case 1324: goto st1324;
		case 1325: goto st1325;
		case 1326: goto st1326;
		case 1327: goto st1327;
		case 1328: goto st1328;
		case 1329: goto st1329;
		case 1330: goto st1330;
		case 1331: goto st1331;
		case 1332: goto st1332;
		case 1333: goto st1333;
		case 1334: goto st1334;
		case 1335: goto st1335;
		case 1336: goto st1336;
		case 1337: goto st1337;
		case 1338: goto st1338;
		case 1339: goto st1339;
		case 1340: goto st1340;
		case 1341: goto st1341;
		case 1342: goto st1342;
		case 1343: goto st1343;
		case 1344: goto st1344;
		case 1345: goto st1345;
		case 1346: goto st1346;
		case 1347: goto st1347;
		case 1348: goto st1348;
		case 1349: goto st1349;
		case 1350: goto st1350;
		case 1351: goto st1351;
		case 1352: goto st1352;
		case 1353: goto st1353;
		case 1354: goto st1354;
		case 1355: goto st1355;
		case 1356: goto st1356;
		case 1357: goto st1357;
		case 1358: goto st1358;
		case 1359: goto st1359;
		case 1360: goto st1360;
		case 1361: goto st1361;
		case 1362: goto st1362;
		case 1363: goto st1363;
		case 1364: goto st1364;
		case 1365: goto st1365;
		case 1366: goto st1366;
		case 1367: goto st1367;
		case 1368: goto st1368;
		case 1369: goto st1369;
		case 1370: goto st1370;
		case 1371: goto st1371;
		case 1372: goto st1372;
		case 1373: goto st1373;
		case 1374: goto st1374;
		case 1375: goto st1375;
		case 1376: goto st1376;
		case 1377: goto st1377;
		case 1378: goto st1378;
		case 1379: goto st1379;
		case 1380: goto st1380;
		case 1381: goto st1381;
		case 1382: goto st1382;
		case 1383: goto st1383;
		case 1384: goto st1384;
		case 1385: goto st1385;
		case 1386: goto st1386;
		case 1387: goto st1387;
		case 1388: goto st1388;
		case 1389: goto st1389;
		case 1390: goto st1390;
		case 1391: goto st1391;
		case 1392: goto st1392;
		case 1393: goto st1393;
		case 1394: goto st1394;
		case 1395: goto st1395;
		case 1396: goto st1396;
		case 1397: goto st1397;
		case 1398: goto st1398;
		case 1399: goto st1399;
		case 1400: goto st1400;
		case 1401: goto st1401;
		case 1402: goto st1402;
		case 1403: goto st1403;
		case 1404: goto st1404;
		case 1405: goto st1405;
		case 1406: goto st1406;
		case 1407: goto st1407;
		case 1408: goto st1408;
		case 1409: goto st1409;
		case 1410: goto st1410;
		case 1411: goto st1411;
		case 1412: goto st1412;
		case 1413: goto st1413;
		case 1414: goto st1414;
		case 1415: goto st1415;
		case 1416: goto st1416;
		case 1451: goto st1451;
		case 1672: goto st1672;
		case 1452: goto st1452;
		case 1673: goto st1673;
		case 1453: goto st1453;
		case 1454: goto st1454;
		case 1455: goto st1455;
		case 1456: goto st1456;
		case 1457: goto st1457;
		case 1458: goto st1458;
		case 1459: goto st1459;
		case 1460: goto st1460;
		case 1461: goto st1461;
		case 1462: goto st1462;
		case 1463: goto st1463;
		case 1464: goto st1464;
		case 1465: goto st1465;
		case 1466: goto st1466;
		case 1467: goto st1467;
		case 1468: goto st1468;
		case 1469: goto st1469;
		case 1470: goto st1470;
		case 1471: goto st1471;
		case 1472: goto st1472;
		case 1674: goto st1674;
		case 1473: goto st1473;
		case 1474: goto st1474;
		case 1475: goto st1475;
		case 1476: goto st1476;
		case 1477: goto st1477;
		case 1478: goto st1478;
		case 1479: goto st1479;
		case 1480: goto st1480;
		case 1481: goto st1481;
		case 1482: goto st1482;
		case 1483: goto st1483;
		case 1484: goto st1484;
		case 1485: goto st1485;
		case 1486: goto st1486;
		case 1487: goto st1487;
		case 1488: goto st1488;
		case 1489: goto st1489;
		case 1490: goto st1490;
		case 1491: goto st1491;
		case 1492: goto st1492;
		case 1493: goto st1493;
		case 1494: goto st1494;
		case 1495: goto st1495;
		case 1496: goto st1496;
		case 1497: goto st1497;
		case 1498: goto st1498;
		case 1499: goto st1499;
		case 1500: goto st1500;
		case 1501: goto st1501;
		case 1502: goto st1502;
		case 1503: goto st1503;
		case 1504: goto st1504;
		case 1505: goto st1505;
		case 1506: goto st1506;
		case 1507: goto st1507;
		case 1508: goto st1508;
		case 1509: goto st1509;
		case 1510: goto st1510;
		case 1511: goto st1511;
		case 1512: goto st1512;
		case 1513: goto st1513;
		case 1514: goto st1514;
		case 1515: goto st1515;
		case 1516: goto st1516;
		case 1517: goto st1517;
		case 1518: goto st1518;
		case 1519: goto st1519;
		case 1520: goto st1520;
		case 1521: goto st1521;
		case 1522: goto st1522;
		case 1523: goto st1523;
		case 1524: goto st1524;
		case 1525: goto st1525;
		case 1526: goto st1526;
		case 1527: goto st1527;
		case 1528: goto st1528;
		case 1529: goto st1529;
		case 1530: goto st1530;
		case 1531: goto st1531;
		case 1532: goto st1532;
		case 1533: goto st1533;
		case 1534: goto st1534;
		case 1535: goto st1535;
		case 1536: goto st1536;
		case 1537: goto st1537;
		case 1538: goto st1538;
		case 1539: goto st1539;
		case 1540: goto st1540;
		case 1541: goto st1541;
		case 1542: goto st1542;
		case 1543: goto st1543;
		case 1544: goto st1544;
		case 1545: goto st1545;
		case 1546: goto st1546;
		case 1547: goto st1547;
		case 1548: goto st1548;
		case 1549: goto st1549;
		case 1550: goto st1550;
		case 1551: goto st1551;
		case 1552: goto st1552;
		case 1553: goto st1553;
		case 1554: goto st1554;
		case 1555: goto st1555;
		case 1556: goto st1556;
		case 1557: goto st1557;
		case 1558: goto st1558;
		case 1559: goto st1559;
		case 1560: goto st1560;
		case 1561: goto st1561;
		case 1562: goto st1562;
		case 1563: goto st1563;
		case 1564: goto st1564;
		case 1565: goto st1565;
		case 1566: goto st1566;
		case 1567: goto st1567;
		case 1568: goto st1568;
		case 1675: goto st1675;
		case 1569: goto st1569;
		case 1570: goto st1570;
		case 1571: goto st1571;
		case 1572: goto st1572;
		case 1573: goto st1573;
		case 1574: goto st1574;
		case 1575: goto st1575;
		case 1576: goto st1576;
		case 1577: goto st1577;
		case 1578: goto st1578;
		case 1579: goto st1579;
		case 1580: goto st1580;
		case 1581: goto st1581;
		case 1582: goto st1582;
		case 1583: goto st1583;
		case 1584: goto st1584;
		case 1585: goto st1585;
		case 1586: goto st1586;
		case 1587: goto st1587;
		case 1588: goto st1588;
		case 1589: goto st1589;
		case 1590: goto st1590;
		case 1591: goto st1591;
		case 1592: goto st1592;
		case 1593: goto st1593;
		case 1594: goto st1594;
		case 1595: goto st1595;
		case 1596: goto st1596;
		case 1597: goto st1597;
		case 1598: goto st1598;
		case 1599: goto st1599;
		case 1600: goto st1600;
		case 1601: goto st1601;
		case 1602: goto st1602;
		case 1603: goto st1603;
		case 1604: goto st1604;
		case 1605: goto st1605;
		case 1606: goto st1606;
		case 1607: goto st1607;
		case 1609: goto st1609;
		case 19: goto st19;
		case 1610: goto st1610;
		case 1611: goto st1611;
		case 1612: goto st1612;
		case 1613: goto st1613;
		case 20: goto st20;
		case 1614: goto st1614;
		case 21: goto st21;
		case 22: goto st22;
		case 23: goto st23;
		case 1615: goto st1615;
		case 24: goto st24;
		case 1616: goto st1616;
		case 25: goto st25;
		case 26: goto st26;
		case 1617: goto st1617;
		case 1618: goto st1618;
		case 1619: goto st1619;
		case 1620: goto st1620;
		case 1621: goto st1621;
		case 1622: goto st1622;
		case 1623: goto st1623;
		case 1624: goto st1624;
		case 1625: goto st1625;
		case 1626: goto st1626;
		case 1627: goto st1627;
		case 1628: goto st1628;
		case 1629: goto st1629;
		case 1630: goto st1630;
		case 1631: goto st1631;
		case 27: goto st27;
		case 28: goto st28;
		case 29: goto st29;
		case 30: goto st30;
		case 31: goto st31;
		case 32: goto st32;
		case 33: goto st33;
		case 34: goto st34;
		case 1632: goto st1632;
		case 35: goto st35;
		case 1633: goto st1633;
		case 36: goto st36;
		case 37: goto st37;
		case 38: goto st38;
		case 39: goto st39;
		case 40: goto st40;
		case 1634: goto st1634;
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
		case 1635: goto st1635;
		case 56: goto st56;
		case 1636: goto st1636;
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
		case 1637: goto st1637;
		case 1638: goto st1638;
		case 1639: goto st1639;
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
		case 1640: goto st1640;
		case 1641: goto st1641;
		case 1642: goto st1642;
		case 107: goto st107;
		case 1643: goto st1643;
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
		case 1644: goto st1644;
		case 206: goto st206;
		case 1645: goto st1645;
		case 1646: goto st1646;
		case 1647: goto st1647;
		case 207: goto st207;
		case 208: goto st208;
		case 209: goto st209;
		case 210: goto st210;
		case 1648: goto st1648;
		case 211: goto st211;
		case 212: goto st212;
		case 213: goto st213;
		case 214: goto st214;
		case 215: goto st215;
		case 216: goto st216;
		case 217: goto st217;
		case 218: goto st218;
		case 1649: goto st1649;
		case 1650: goto st1650;
		case 219: goto st219;
		case 220: goto st220;
		case 221: goto st221;
		case 1652: goto st1652;
		case 237: goto st237;
		case 238: goto st238;
		case 239: goto st239;
		case 240: goto st240;
		case 241: goto st241;
		case 242: goto st242;
		case 1661: goto st1661;
		case 777: goto st777;
		case 778: goto st778;
		case 779: goto st779;
		case 780: goto st780;
		case 781: goto st781;
		case 782: goto st782;
		case 783: goto st783;
		case 784: goto st784;
		case 785: goto st785;
		case 1668: goto st1668;
		case 1669: goto st1669;
		case 1417: goto st1417;
		case 1418: goto st1418;
		case 1670: goto st1670;
		case 1419: goto st1419;
		case 1420: goto st1420;
		case 1421: goto st1421;
		case 1422: goto st1422;
		case 1423: goto st1423;
		case 1671: goto st1671;
		case 1424: goto st1424;
		case 1425: goto st1425;
		case 1426: goto st1426;
		case 1427: goto st1427;
		case 1428: goto st1428;
		case 1429: goto st1429;
		case 1430: goto st1430;
		case 1431: goto st1431;
		case 1432: goto st1432;
		case 1433: goto st1433;
		case 1434: goto st1434;
		case 1435: goto st1435;
		case 1436: goto st1436;
		case 1437: goto st1437;
		case 1438: goto st1438;
		case 1439: goto st1439;
		case 1440: goto st1440;
		case 1441: goto st1441;
		case 1442: goto st1442;
		case 1443: goto st1443;
		case 1444: goto st1444;
		case 1445: goto st1445;
		case 1446: goto st1446;
		case 1447: goto st1447;
		case 1448: goto st1448;
		case 1449: goto st1449;
		case 1450: goto st1450;
	default: break;
	}

	if ( ++p == pe )
		goto _test_eof;
_resume:
	switch ( cs )
	{
tr15:
#line 1093 "mfilescanner.rl"
	{
                     p=tmp_p;
                     {goto st1561;}
                    }
	goto st1608;
tr22:
#line 1089 "mfilescanner.rl"
	{
                     p=tmp_p;
                     {goto st1453;}
                    }
	goto st1608;
st1608:
#line 1 "mfilescanner.rl"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof1608;
case 1608:
#line 1878 "mfilescanner.cc"
	goto tr2217;
tr2:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st1;
tr2217:
#line 1083 "mfilescanner.rl"
	{ p--; tmp_p = p; }
	goto st1;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
#line 1892 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st1;
		case 10: goto tr2;
		case 13: goto st2;
		case 32: goto st3;
		case 37: goto st4;
		case 99: goto st5;
		case 102: goto st12;
	}
	goto tr0;
tr0:
#line 1098 "mfilescanner.rl"
	{
    p=tmp_p;
    {goto st1452;}
  }
	goto st0;
tr24:
#line 44 "mfilescanner.rl"
	{
    cout << "*/\n";
    p--;
    {cs = stack[--top];goto _again;}
  }
	goto st0;
tr288:
#line 696 "mfilescanner.rl"
	{
        p = tmp_p - 2;
        {goto st1649;}
      }
	goto st0;
tr1944:
#line 903 "mfilescanner.rl"
	{
    p--;
    if(is_class_)
    {
      if(class_part_ == Header)
      {
        end_of_class_doc();
        {goto st1668;}
      } else if(class_part_ == Method)
        {goto st1632;}
      else if(class_part_ == Property)
      {
        end_of_property_doc();
        {goto st1661;}
      }
    }
    else
      {goto st1632;}
 }
	goto st0;
#line 1947 "mfilescanner.cc"
st0:
cs = 0;
	goto _out;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	if ( (*p) == 10 )
		goto tr2;
	goto st0;
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
	goto st0;
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
	if ( (*p) == 108 )
		goto st6;
	goto tr0;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
	if ( (*p) == 97 )
		goto st7;
	goto tr0;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
	if ( (*p) == 115 )
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
	if ( (*p) == 100 )
		goto st10;
	goto tr0;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
	if ( (*p) == 101 )
		goto st11;
	goto tr0;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
	if ( (*p) == 102 )
		goto tr15;
	goto tr0;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
	if ( (*p) == 117 )
		goto st13;
	goto tr0;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	if ( (*p) == 110 )
		goto st14;
	goto tr0;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
	if ( (*p) == 99 )
		goto st15;
	goto tr0;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
	if ( (*p) == 116 )
		goto st16;
	goto tr0;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
	if ( (*p) == 105 )
		goto st17;
	goto tr0;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
	if ( (*p) == 111 )
		goto st18;
	goto tr0;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
	if ( (*p) == 110 )
		goto tr22;
	goto tr0;
st222:
#line 1 "mfilescanner.rl"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof222;
case 222:
#line 2081 "mfilescanner.cc"
	if ( (*p) == 37 )
		goto st223;
	goto st0;
st223:
	if ( ++p == pe )
		goto _test_eof223;
case 223:
	switch( (*p) ) {
		case 9: goto st223;
		case 32: goto st223;
		case 102: goto st224;
	}
	goto tr288;
st224:
	if ( ++p == pe )
		goto _test_eof224;
case 224:
	if ( (*p) == 117 )
		goto st225;
	goto tr288;
st225:
	if ( ++p == pe )
		goto _test_eof225;
case 225:
	if ( (*p) == 110 )
		goto st226;
	goto tr288;
st226:
	if ( ++p == pe )
		goto _test_eof226;
case 226:
	if ( (*p) == 99 )
		goto st227;
	goto tr288;
st227:
	if ( ++p == pe )
		goto _test_eof227;
case 227:
	if ( (*p) == 116 )
		goto st228;
	goto tr288;
st228:
	if ( ++p == pe )
		goto _test_eof228;
case 228:
	if ( (*p) == 105 )
		goto st229;
	goto tr288;
st229:
	if ( ++p == pe )
		goto _test_eof229;
case 229:
	if ( (*p) == 111 )
		goto st230;
	goto tr288;
st230:
	if ( ++p == pe )
		goto _test_eof230;
case 230:
	if ( (*p) == 110 )
		goto st231;
	goto tr288;
st231:
	if ( ++p == pe )
		goto _test_eof231;
case 231:
	switch( (*p) ) {
		case 0: goto tr288;
		case 10: goto tr288;
		case 13: goto tr288;
		case 41: goto st232;
		case 46: goto st233;
		case 59: goto st232;
	}
	goto st231;
st232:
	if ( ++p == pe )
		goto _test_eof232;
case 232:
	switch( (*p) ) {
		case 0: goto tr288;
		case 10: goto tr299;
	}
	goto st232;
tr299:
#line 32 "mfilescanner.rl"
	{line++;}
#line 689 "mfilescanner.rl"
	{ {goto st1649;} }
	goto st1651;
tr302:
#line 32 "mfilescanner.rl"
	{line++;}
#line 692 "mfilescanner.rl"
	{ {goto st1648;} }
	goto st1651;
st1651:
	if ( ++p == pe )
		goto _test_eof1651;
case 1651:
#line 2182 "mfilescanner.cc"
	goto tr288;
st233:
	if ( ++p == pe )
		goto _test_eof233;
case 233:
	if ( (*p) == 46 )
		goto st234;
	goto tr288;
st234:
	if ( ++p == pe )
		goto _test_eof234;
case 234:
	if ( (*p) == 46 )
		goto st235;
	goto tr288;
st235:
	if ( ++p == pe )
		goto _test_eof235;
case 235:
	switch( (*p) ) {
		case 9: goto st235;
		case 10: goto tr302;
		case 13: goto st236;
		case 32: goto st235;
	}
	goto tr288;
st236:
	if ( ++p == pe )
		goto _test_eof236;
case 236:
	if ( (*p) == 10 )
		goto tr302;
	goto tr288;
tr1024:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st243;
tr333:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st243;
st243:
#line 1 "mfilescanner.rl"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof243;
case 243:
#line 2235 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st243;
		case 10: goto tr313;
		case 13: goto st250;
		case 32: goto st243;
		case 37: goto tr315;
		case 40: goto st252;
		case 46: goto st773;
	}
	goto st0;
tr313:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st244;
tr423:
#line 745 "mfilescanner.rl"
	{ access_.full = Private;
               access_.get = Private;
               access_.set = Private;
             }
#line 32 "mfilescanner.rl"
	{line++;}
	goto st244;
tr431:
#line 740 "mfilescanner.rl"
	{ access_.full = Protected;
               access_.get = Protected;
               access_.set = Protected;
             }
#line 32 "mfilescanner.rl"
	{line++;}
	goto st244;
tr437:
#line 735 "mfilescanner.rl"
	{ access_.full = Public;
               access_.get = Public;
               access_.set = Public;
             }
#line 32 "mfilescanner.rl"
	{line++;}
	goto st244;
tr474:
#line 729 "mfilescanner.rl"
	{ access_.full = access_.set;
               access_.get = Private;
             }
#line 32 "mfilescanner.rl"
	{line++;}
	goto st244;
tr482:
#line 724 "mfilescanner.rl"
	{ access_.full =
                 (access_.set == Public ? Public : Protected );
               access_.get = Protected;
             }
#line 32 "mfilescanner.rl"
	{line++;}
	goto st244;
tr488:
#line 720 "mfilescanner.rl"
	{ access_.full = Public;
               access_.get = Public;
             }
#line 32 "mfilescanner.rl"
	{line++;}
	goto st244;
tr547:
#line 714 "mfilescanner.rl"
	{ access_.full = access_.get;
               access_.set = Private;
             }
#line 32 "mfilescanner.rl"
	{line++;}
	goto st244;
tr555:
#line 709 "mfilescanner.rl"
	{ access_.full =
                 (access_.get == Public ? Public : Protected );
               access_.set = Protected;
             }
#line 32 "mfilescanner.rl"
	{line++;}
	goto st244;
tr561:
#line 705 "mfilescanner.rl"
	{ access_.full = Public;
               access_.set = Public;
             }
#line 32 "mfilescanner.rl"
	{line++;}
	goto st244;
st244:
	if ( ++p == pe )
		goto _test_eof244;
case 244:
#line 2331 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr318;
		case 10: goto tr319;
		case 13: goto tr320;
		case 32: goto tr318;
		case 101: goto tr321;
		case 102: goto tr322;
	}
	goto st0;
tr328:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st245;
tr318:
#line 813 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st245;
st245:
	if ( ++p == pe )
		goto _test_eof245;
case 245:
#line 2357 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st245;
		case 10: goto tr324;
		case 13: goto st247;
		case 32: goto st245;
		case 101: goto st248;
		case 102: goto tr327;
	}
	goto st0;
tr324:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st246;
tr319:
#line 813 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
#line 32 "mfilescanner.rl"
	{line++;}
	goto st246;
tr322:
#line 813 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
#line 807 "mfilescanner.rl"
	{
        tmp_string.assign(tmp_p, p - tmp_p);
        funcindent_ = tmp_string.find("f");
        p--;
        {goto st1453;}
       }
	goto st246;
tr327:
#line 807 "mfilescanner.rl"
	{
        tmp_string.assign(tmp_p, p - tmp_p);
        funcindent_ = tmp_string.find("f");
        p--;
        {goto st1453;}
       }
	goto st246;
tr329:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
#line 807 "mfilescanner.rl"
	{
        tmp_string.assign(tmp_p, p - tmp_p);
        funcindent_ = tmp_string.find("f");
        p--;
        {goto st1453;}
       }
	goto st246;
st246:
	if ( ++p == pe )
		goto _test_eof246;
case 246:
#line 2418 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr328;
		case 10: goto tr324;
		case 13: goto st247;
		case 32: goto tr328;
		case 101: goto st248;
		case 102: goto tr329;
	}
	goto st0;
tr320:
#line 813 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
	goto st247;
st247:
	if ( ++p == pe )
		goto _test_eof247;
case 247:
#line 2438 "mfilescanner.cc"
	if ( (*p) == 10 )
		goto tr324;
	goto st0;
tr321:
#line 813 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
	goto st248;
st248:
	if ( ++p == pe )
		goto _test_eof248;
case 248:
#line 2452 "mfilescanner.cc"
	if ( (*p) == 110 )
		goto st249;
	goto st0;
st249:
	if ( ++p == pe )
		goto _test_eof249;
case 249:
	if ( (*p) == 100 )
		goto st1653;
	goto st0;
st1653:
	if ( ++p == pe )
		goto _test_eof1653;
case 1653:
	if ( (*p) == 59 )
		goto tr2282;
	goto st0;
tr2282:
#line 817 "mfilescanner.rl"
	{
         {goto st1668;}
       }
	goto st1654;
st1654:
	if ( ++p == pe )
		goto _test_eof1654;
case 1654:
#line 2480 "mfilescanner.cc"
	goto st0;
tr424:
#line 745 "mfilescanner.rl"
	{ access_.full = Private;
               access_.get = Private;
               access_.set = Private;
             }
	goto st250;
tr432:
#line 740 "mfilescanner.rl"
	{ access_.full = Protected;
               access_.get = Protected;
               access_.set = Protected;
             }
	goto st250;
tr438:
#line 735 "mfilescanner.rl"
	{ access_.full = Public;
               access_.get = Public;
               access_.set = Public;
             }
	goto st250;
tr475:
#line 729 "mfilescanner.rl"
	{ access_.full = access_.set;
               access_.get = Private;
             }
	goto st250;
tr483:
#line 724 "mfilescanner.rl"
	{ access_.full =
                 (access_.set == Public ? Public : Protected );
               access_.get = Protected;
             }
	goto st250;
tr489:
#line 720 "mfilescanner.rl"
	{ access_.full = Public;
               access_.get = Public;
             }
	goto st250;
tr548:
#line 714 "mfilescanner.rl"
	{ access_.full = access_.get;
               access_.set = Private;
             }
	goto st250;
tr556:
#line 709 "mfilescanner.rl"
	{ access_.full =
                 (access_.get == Public ? Public : Protected );
               access_.set = Protected;
             }
	goto st250;
tr562:
#line 705 "mfilescanner.rl"
	{ access_.full = Public;
               access_.set = Public;
             }
	goto st250;
st250:
	if ( ++p == pe )
		goto _test_eof250;
case 250:
#line 2545 "mfilescanner.cc"
	if ( (*p) == 10 )
		goto tr313;
	goto st0;
tr315:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st251;
st251:
	if ( ++p == pe )
		goto _test_eof251;
case 251:
#line 2557 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr333;
	}
	goto st251;
tr344:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st252;
tr341:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st252;
st252:
	if ( ++p == pe )
		goto _test_eof252;
case 252:
#line 2580 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st252;
		case 32: goto st252;
		case 37: goto tr334;
		case 46: goto st254;
		case 65: goto st258;
		case 71: goto st665;
		case 72: goto st706;
		case 83: goto st718;
	}
	goto st0;
tr334:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st253;
st253:
	if ( ++p == pe )
		goto _test_eof253;
case 253:
#line 2600 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr341;
	}
	goto st253;
st254:
	if ( ++p == pe )
		goto _test_eof254;
case 254:
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
		case 10: goto tr344;
		case 13: goto st257;
		case 32: goto st256;
	}
	goto st0;
st257:
	if ( ++p == pe )
		goto _test_eof257;
case 257:
	if ( (*p) == 10 )
		goto tr344;
	goto st0;
st258:
	if ( ++p == pe )
		goto _test_eof258;
case 258:
	switch( (*p) ) {
		case 98: goto st259;
		case 99: goto st628;
	}
	goto st0;
st259:
	if ( ++p == pe )
		goto _test_eof259;
case 259:
	if ( (*p) == 115 )
		goto st260;
	goto st0;
st260:
	if ( ++p == pe )
		goto _test_eof260;
case 260:
	if ( (*p) == 116 )
		goto st261;
	goto st0;
st261:
	if ( ++p == pe )
		goto _test_eof261;
case 261:
	if ( (*p) == 114 )
		goto st262;
	goto st0;
st262:
	if ( ++p == pe )
		goto _test_eof262;
case 262:
	if ( (*p) == 97 )
		goto st263;
	goto st0;
st263:
	if ( ++p == pe )
		goto _test_eof263;
case 263:
	if ( (*p) == 99 )
		goto st264;
	goto st0;
st264:
	if ( ++p == pe )
		goto _test_eof264;
case 264:
	if ( (*p) == 116 )
		goto tr353;
	goto st0;
tr353:
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
	goto st265;
tr358:
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st265;
tr822:
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
#line 32 "mfilescanner.rl"
	{line++;}
	goto st265;
st265:
	if ( ++p == pe )
		goto _test_eof265;
case 265:
#line 2720 "mfilescanner.cc"
	switch( (*p) ) {
		case 37: goto tr354;
		case 41: goto st0;
		case 44: goto st269;
		case 46: goto tr356;
	}
	goto tr353;
tr357:
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
	goto st266;
tr354:
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st266;
st266:
	if ( ++p == pe )
		goto _test_eof266;
case 266:
#line 2746 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr353;
		case 10: goto tr358;
		case 37: goto tr354;
		case 41: goto st267;
		case 44: goto st435;
	}
	goto tr357;
tr363:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st267;
tr850:
#line 745 "mfilescanner.rl"
	{ access_.full = Private;
               access_.get = Private;
               access_.set = Private;
             }
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st267;
tr860:
#line 740 "mfilescanner.rl"
	{ access_.full = Protected;
               access_.get = Protected;
               access_.set = Protected;
             }
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st267;
tr868:
#line 735 "mfilescanner.rl"
	{ access_.full = Public;
               access_.get = Public;
               access_.set = Public;
             }
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st267;
tr907:
#line 729 "mfilescanner.rl"
	{ access_.full = access_.set;
               access_.get = Private;
             }
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st267;
tr917:
#line 724 "mfilescanner.rl"
	{ access_.full =
                 (access_.set == Public ? Public : Protected );
               access_.get = Protected;
             }
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st267;
tr925:
#line 720 "mfilescanner.rl"
	{ access_.full = Public;
               access_.get = Public;
             }
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st267;
tr982:
#line 714 "mfilescanner.rl"
	{ access_.full = access_.get;
               access_.set = Private;
             }
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st267;
tr992:
#line 709 "mfilescanner.rl"
	{ access_.full =
                 (access_.get == Public ? Public : Protected );
               access_.set = Protected;
             }
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st267;
tr1000:
#line 705 "mfilescanner.rl"
	{ access_.full = Public;
               access_.set = Public;
             }
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st267;
st267:
	if ( ++p == pe )
		goto _test_eof267;
case 267:
#line 2840 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
	}
	goto st267;
tr588:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st268;
tr361:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st268;
tr849:
#line 745 "mfilescanner.rl"
	{ access_.full = Private;
               access_.get = Private;
               access_.set = Private;
             }
	goto st268;
tr859:
#line 740 "mfilescanner.rl"
	{ access_.full = Protected;
               access_.get = Protected;
               access_.set = Protected;
             }
	goto st268;
tr867:
#line 735 "mfilescanner.rl"
	{ access_.full = Public;
               access_.get = Public;
               access_.set = Public;
             }
	goto st268;
tr906:
#line 729 "mfilescanner.rl"
	{ access_.full = access_.set;
               access_.get = Private;
             }
	goto st268;
tr916:
#line 724 "mfilescanner.rl"
	{ access_.full =
                 (access_.set == Public ? Public : Protected );
               access_.get = Protected;
             }
	goto st268;
tr924:
#line 720 "mfilescanner.rl"
	{ access_.full = Public;
               access_.get = Public;
             }
	goto st268;
tr981:
#line 714 "mfilescanner.rl"
	{ access_.full = access_.get;
               access_.set = Private;
             }
	goto st268;
tr991:
#line 709 "mfilescanner.rl"
	{ access_.full =
                 (access_.get == Public ? Public : Protected );
               access_.set = Protected;
             }
	goto st268;
tr999:
#line 705 "mfilescanner.rl"
	{ access_.full = Public;
               access_.set = Public;
             }
	goto st268;
st268:
	if ( ++p == pe )
		goto _test_eof268;
case 268:
#line 2922 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st268;
		case 32: goto st268;
		case 37: goto tr363;
		case 44: goto st269;
		case 46: goto st431;
	}
	goto st0;
tr375:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st269;
tr372:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st269;
tr851:
#line 745 "mfilescanner.rl"
	{ access_.full = Private;
               access_.get = Private;
               access_.set = Private;
             }
	goto st269;
tr861:
#line 740 "mfilescanner.rl"
	{ access_.full = Protected;
               access_.get = Protected;
               access_.set = Protected;
             }
	goto st269;
tr869:
#line 735 "mfilescanner.rl"
	{ access_.full = Public;
               access_.get = Public;
               access_.set = Public;
             }
	goto st269;
tr908:
#line 729 "mfilescanner.rl"
	{ access_.full = access_.set;
               access_.get = Private;
             }
	goto st269;
tr918:
#line 724 "mfilescanner.rl"
	{ access_.full =
                 (access_.set == Public ? Public : Protected );
               access_.get = Protected;
             }
	goto st269;
tr926:
#line 720 "mfilescanner.rl"
	{ access_.full = Public;
               access_.get = Public;
             }
	goto st269;
tr983:
#line 714 "mfilescanner.rl"
	{ access_.full = access_.get;
               access_.set = Private;
             }
	goto st269;
tr993:
#line 709 "mfilescanner.rl"
	{ access_.full =
                 (access_.get == Public ? Public : Protected );
               access_.set = Protected;
             }
	goto st269;
tr1001:
#line 705 "mfilescanner.rl"
	{ access_.full = Public;
               access_.set = Public;
             }
	goto st269;
st269:
	if ( ++p == pe )
		goto _test_eof269;
case 269:
#line 3007 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st269;
		case 32: goto st269;
		case 37: goto tr365;
		case 46: goto st271;
		case 65: goto st275;
		case 71: goto st325;
		case 72: goto st366;
		case 83: goto st377;
	}
	goto st0;
tr365:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st270;
st270:
	if ( ++p == pe )
		goto _test_eof270;
case 270:
#line 3027 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr372;
	}
	goto st270;
st271:
	if ( ++p == pe )
		goto _test_eof271;
case 271:
	if ( (*p) == 46 )
		goto st272;
	goto st0;
st272:
	if ( ++p == pe )
		goto _test_eof272;
case 272:
	if ( (*p) == 46 )
		goto st273;
	goto st0;
st273:
	if ( ++p == pe )
		goto _test_eof273;
case 273:
	switch( (*p) ) {
		case 9: goto st273;
		case 10: goto tr375;
		case 13: goto st274;
		case 32: goto st273;
	}
	goto st0;
st274:
	if ( ++p == pe )
		goto _test_eof274;
case 274:
	if ( (*p) == 10 )
		goto tr375;
	goto st0;
st275:
	if ( ++p == pe )
		goto _test_eof275;
case 275:
	switch( (*p) ) {
		case 98: goto st276;
		case 99: goto st288;
	}
	goto st0;
st276:
	if ( ++p == pe )
		goto _test_eof276;
case 276:
	if ( (*p) == 115 )
		goto st277;
	goto st0;
st277:
	if ( ++p == pe )
		goto _test_eof277;
case 277:
	if ( (*p) == 116 )
		goto st278;
	goto st0;
st278:
	if ( ++p == pe )
		goto _test_eof278;
case 278:
	if ( (*p) == 114 )
		goto st279;
	goto st0;
st279:
	if ( ++p == pe )
		goto _test_eof279;
case 279:
	if ( (*p) == 97 )
		goto st280;
	goto st0;
st280:
	if ( ++p == pe )
		goto _test_eof280;
case 280:
	if ( (*p) == 99 )
		goto st281;
	goto st0;
st281:
	if ( ++p == pe )
		goto _test_eof281;
case 281:
	if ( (*p) == 116 )
		goto tr384;
	goto st0;
tr384:
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
	goto st282;
tr388:
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
#line 813 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
	goto st282;
st282:
	if ( ++p == pe )
		goto _test_eof282;
case 282:
#line 3136 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr385;
		case 41: goto st0;
		case 44: goto st0;
	}
	goto tr384;
tr385:
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
#line 32 "mfilescanner.rl"
	{line++;}
	goto st283;
tr387:
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
#line 32 "mfilescanner.rl"
	{line++;}
#line 813 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
	goto st283;
st283:
	if ( ++p == pe )
		goto _test_eof283;
case 283:
#line 3167 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr386;
		case 10: goto tr387;
		case 13: goto tr388;
		case 32: goto tr386;
		case 41: goto st0;
		case 44: goto st0;
		case 101: goto tr389;
		case 102: goto tr390;
	}
	goto tr384;
tr391:
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
	goto st284;
tr386:
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
#line 813 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st284;
tr396:
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st284;
st284:
	if ( ++p == pe )
		goto _test_eof284;
case 284:
#line 3209 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr391;
		case 10: goto tr385;
		case 32: goto tr391;
		case 41: goto st0;
		case 44: goto st0;
		case 101: goto tr392;
		case 102: goto tr393;
	}
	goto tr384;
tr392:
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
	goto st285;
tr389:
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
#line 813 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
	goto st285;
st285:
	if ( ++p == pe )
		goto _test_eof285;
case 285:
#line 3240 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr385;
		case 41: goto st0;
		case 44: goto st0;
		case 110: goto tr394;
	}
	goto tr384;
tr394:
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
	goto st286;
st286:
	if ( ++p == pe )
		goto _test_eof286;
case 286:
#line 3258 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr385;
		case 41: goto st0;
		case 44: goto st0;
		case 100: goto tr395;
	}
	goto tr384;
tr395:
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
	goto st1655;
st1655:
	if ( ++p == pe )
		goto _test_eof1655;
case 1655:
#line 3276 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr385;
		case 41: goto st0;
		case 44: goto st0;
		case 59: goto tr2283;
	}
	goto tr384;
tr2283:
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
#line 817 "mfilescanner.rl"
	{
         {goto st1668;}
       }
	goto st1656;
st1656:
	if ( ++p == pe )
		goto _test_eof1656;
case 1656:
#line 3298 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr385;
		case 41: goto st0;
		case 44: goto st0;
	}
	goto tr384;
tr390:
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
#line 813 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
#line 807 "mfilescanner.rl"
	{
        tmp_string.assign(tmp_p, p - tmp_p);
        funcindent_ = tmp_string.find("f");
        p--;
        {goto st1453;}
       }
	goto st287;
tr393:
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
#line 807 "mfilescanner.rl"
	{
        tmp_string.assign(tmp_p, p - tmp_p);
        funcindent_ = tmp_string.find("f");
        p--;
        {goto st1453;}
       }
	goto st287;
tr397:
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
#line 807 "mfilescanner.rl"
	{
        tmp_string.assign(tmp_p, p - tmp_p);
        funcindent_ = tmp_string.find("f");
        p--;
        {goto st1453;}
       }
	goto st287;
st287:
	if ( ++p == pe )
		goto _test_eof287;
case 287:
#line 3356 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr396;
		case 10: goto tr385;
		case 32: goto tr396;
		case 41: goto st0;
		case 44: goto st0;
		case 101: goto tr392;
		case 102: goto tr397;
	}
	goto tr384;
st288:
	if ( ++p == pe )
		goto _test_eof288;
case 288:
	if ( (*p) == 99 )
		goto st289;
	goto st0;
st289:
	if ( ++p == pe )
		goto _test_eof289;
case 289:
	if ( (*p) == 101 )
		goto st290;
	goto st0;
st290:
	if ( ++p == pe )
		goto _test_eof290;
case 290:
	if ( (*p) == 115 )
		goto st291;
	goto st0;
st291:
	if ( ++p == pe )
		goto _test_eof291;
case 291:
	if ( (*p) == 115 )
		goto st292;
	goto st0;
tr409:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st292;
tr406:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st292;
st292:
	if ( ++p == pe )
		goto _test_eof292;
case 292:
#line 3412 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st292;
		case 32: goto st292;
		case 37: goto tr402;
		case 46: goto st294;
		case 61: goto st298;
	}
	goto st0;
tr402:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st293;
st293:
	if ( ++p == pe )
		goto _test_eof293;
case 293:
#line 3429 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr406;
	}
	goto st293;
st294:
	if ( ++p == pe )
		goto _test_eof294;
case 294:
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
		case 10: goto tr409;
		case 13: goto st297;
		case 32: goto st296;
	}
	goto st0;
st297:
	if ( ++p == pe )
		goto _test_eof297;
case 297:
	if ( (*p) == 10 )
		goto tr409;
	goto st0;
st298:
	if ( ++p == pe )
		goto _test_eof298;
case 298:
	switch( (*p) ) {
		case 9: goto st299;
		case 32: goto st299;
		case 37: goto tr412;
		case 46: goto st321;
	}
	goto st0;
st299:
	if ( ++p == pe )
		goto _test_eof299;
case 299:
	switch( (*p) ) {
		case 9: goto st299;
		case 32: goto st299;
		case 112: goto st300;
	}
	goto st0;
st300:
	if ( ++p == pe )
		goto _test_eof300;
case 300:
	switch( (*p) ) {
		case 114: goto st301;
		case 117: goto st314;
	}
	goto st0;
st301:
	if ( ++p == pe )
		goto _test_eof301;
case 301:
	switch( (*p) ) {
		case 105: goto st302;
		case 111: goto st307;
	}
	goto st0;
st302:
	if ( ++p == pe )
		goto _test_eof302;
case 302:
	if ( (*p) == 118 )
		goto st303;
	goto st0;
st303:
	if ( ++p == pe )
		goto _test_eof303;
case 303:
	if ( (*p) == 97 )
		goto st304;
	goto st0;
st304:
	if ( ++p == pe )
		goto _test_eof304;
case 304:
	if ( (*p) == 116 )
		goto st305;
	goto st0;
st305:
	if ( ++p == pe )
		goto _test_eof305;
case 305:
	if ( (*p) == 101 )
		goto st306;
	goto st0;
st306:
	if ( ++p == pe )
		goto _test_eof306;
case 306:
	switch( (*p) ) {
		case 10: goto tr423;
		case 13: goto tr424;
	}
	goto st0;
st307:
	if ( ++p == pe )
		goto _test_eof307;
case 307:
	if ( (*p) == 116 )
		goto st308;
	goto st0;
st308:
	if ( ++p == pe )
		goto _test_eof308;
case 308:
	if ( (*p) == 101 )
		goto st309;
	goto st0;
st309:
	if ( ++p == pe )
		goto _test_eof309;
case 309:
	if ( (*p) == 99 )
		goto st310;
	goto st0;
st310:
	if ( ++p == pe )
		goto _test_eof310;
case 310:
	if ( (*p) == 116 )
		goto st311;
	goto st0;
st311:
	if ( ++p == pe )
		goto _test_eof311;
case 311:
	if ( (*p) == 101 )
		goto st312;
	goto st0;
st312:
	if ( ++p == pe )
		goto _test_eof312;
case 312:
	if ( (*p) == 100 )
		goto st313;
	goto st0;
st313:
	if ( ++p == pe )
		goto _test_eof313;
case 313:
	switch( (*p) ) {
		case 10: goto tr431;
		case 13: goto tr432;
	}
	goto st0;
st314:
	if ( ++p == pe )
		goto _test_eof314;
case 314:
	if ( (*p) == 98 )
		goto st315;
	goto st0;
st315:
	if ( ++p == pe )
		goto _test_eof315;
case 315:
	if ( (*p) == 108 )
		goto st316;
	goto st0;
st316:
	if ( ++p == pe )
		goto _test_eof316;
case 316:
	if ( (*p) == 105 )
		goto st317;
	goto st0;
st317:
	if ( ++p == pe )
		goto _test_eof317;
case 317:
	if ( (*p) == 99 )
		goto st318;
	goto st0;
st318:
	if ( ++p == pe )
		goto _test_eof318;
case 318:
	switch( (*p) ) {
		case 10: goto tr437;
		case 13: goto tr438;
	}
	goto st0;
tr412:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st319;
st319:
	if ( ++p == pe )
		goto _test_eof319;
case 319:
#line 3639 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr440;
	}
	goto st319;
tr443:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st320;
tr440:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st320;
st320:
	if ( ++p == pe )
		goto _test_eof320;
case 320:
#line 3662 "mfilescanner.cc"
	if ( (*p) == 112 )
		goto st300;
	goto st0;
st321:
	if ( ++p == pe )
		goto _test_eof321;
case 321:
	if ( (*p) == 46 )
		goto st322;
	goto st0;
st322:
	if ( ++p == pe )
		goto _test_eof322;
case 322:
	if ( (*p) == 46 )
		goto st323;
	goto st0;
st323:
	if ( ++p == pe )
		goto _test_eof323;
case 323:
	switch( (*p) ) {
		case 9: goto st323;
		case 10: goto tr443;
		case 13: goto st324;
		case 32: goto st323;
	}
	goto st0;
st324:
	if ( ++p == pe )
		goto _test_eof324;
case 324:
	if ( (*p) == 10 )
		goto tr443;
	goto st0;
st325:
	if ( ++p == pe )
		goto _test_eof325;
case 325:
	if ( (*p) == 101 )
		goto st326;
	goto st0;
st326:
	if ( ++p == pe )
		goto _test_eof326;
case 326:
	if ( (*p) == 116 )
		goto st327;
	goto st0;
st327:
	if ( ++p == pe )
		goto _test_eof327;
case 327:
	if ( (*p) == 65 )
		goto st328;
	goto st0;
st328:
	if ( ++p == pe )
		goto _test_eof328;
case 328:
	if ( (*p) == 99 )
		goto st329;
	goto st0;
st329:
	if ( ++p == pe )
		goto _test_eof329;
case 329:
	if ( (*p) == 99 )
		goto st330;
	goto st0;
st330:
	if ( ++p == pe )
		goto _test_eof330;
case 330:
	if ( (*p) == 101 )
		goto st331;
	goto st0;
st331:
	if ( ++p == pe )
		goto _test_eof331;
case 331:
	if ( (*p) == 115 )
		goto st332;
	goto st0;
st332:
	if ( ++p == pe )
		goto _test_eof332;
case 332:
	if ( (*p) == 115 )
		goto st333;
	goto st0;
tr460:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st333;
tr457:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st333;
st333:
	if ( ++p == pe )
		goto _test_eof333;
case 333:
#line 3771 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st333;
		case 32: goto st333;
		case 37: goto tr453;
		case 46: goto st335;
		case 61: goto st339;
	}
	goto st0;
tr453:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st334;
st334:
	if ( ++p == pe )
		goto _test_eof334;
case 334:
#line 3788 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr457;
	}
	goto st334;
st335:
	if ( ++p == pe )
		goto _test_eof335;
case 335:
	if ( (*p) == 46 )
		goto st336;
	goto st0;
st336:
	if ( ++p == pe )
		goto _test_eof336;
case 336:
	if ( (*p) == 46 )
		goto st337;
	goto st0;
st337:
	if ( ++p == pe )
		goto _test_eof337;
case 337:
	switch( (*p) ) {
		case 9: goto st337;
		case 10: goto tr460;
		case 13: goto st338;
		case 32: goto st337;
	}
	goto st0;
st338:
	if ( ++p == pe )
		goto _test_eof338;
case 338:
	if ( (*p) == 10 )
		goto tr460;
	goto st0;
st339:
	if ( ++p == pe )
		goto _test_eof339;
case 339:
	switch( (*p) ) {
		case 9: goto st340;
		case 32: goto st340;
		case 37: goto tr463;
		case 46: goto st362;
	}
	goto st0;
st340:
	if ( ++p == pe )
		goto _test_eof340;
case 340:
	switch( (*p) ) {
		case 9: goto st340;
		case 32: goto st340;
		case 112: goto st341;
	}
	goto st0;
st341:
	if ( ++p == pe )
		goto _test_eof341;
case 341:
	switch( (*p) ) {
		case 114: goto st342;
		case 117: goto st355;
	}
	goto st0;
st342:
	if ( ++p == pe )
		goto _test_eof342;
case 342:
	switch( (*p) ) {
		case 105: goto st343;
		case 111: goto st348;
	}
	goto st0;
st343:
	if ( ++p == pe )
		goto _test_eof343;
case 343:
	if ( (*p) == 118 )
		goto st344;
	goto st0;
st344:
	if ( ++p == pe )
		goto _test_eof344;
case 344:
	if ( (*p) == 97 )
		goto st345;
	goto st0;
st345:
	if ( ++p == pe )
		goto _test_eof345;
case 345:
	if ( (*p) == 116 )
		goto st346;
	goto st0;
st346:
	if ( ++p == pe )
		goto _test_eof346;
case 346:
	if ( (*p) == 101 )
		goto st347;
	goto st0;
st347:
	if ( ++p == pe )
		goto _test_eof347;
case 347:
	switch( (*p) ) {
		case 10: goto tr474;
		case 13: goto tr475;
	}
	goto st0;
st348:
	if ( ++p == pe )
		goto _test_eof348;
case 348:
	if ( (*p) == 116 )
		goto st349;
	goto st0;
st349:
	if ( ++p == pe )
		goto _test_eof349;
case 349:
	if ( (*p) == 101 )
		goto st350;
	goto st0;
st350:
	if ( ++p == pe )
		goto _test_eof350;
case 350:
	if ( (*p) == 99 )
		goto st351;
	goto st0;
st351:
	if ( ++p == pe )
		goto _test_eof351;
case 351:
	if ( (*p) == 116 )
		goto st352;
	goto st0;
st352:
	if ( ++p == pe )
		goto _test_eof352;
case 352:
	if ( (*p) == 101 )
		goto st353;
	goto st0;
st353:
	if ( ++p == pe )
		goto _test_eof353;
case 353:
	if ( (*p) == 100 )
		goto st354;
	goto st0;
st354:
	if ( ++p == pe )
		goto _test_eof354;
case 354:
	switch( (*p) ) {
		case 10: goto tr482;
		case 13: goto tr483;
	}
	goto st0;
st355:
	if ( ++p == pe )
		goto _test_eof355;
case 355:
	if ( (*p) == 98 )
		goto st356;
	goto st0;
st356:
	if ( ++p == pe )
		goto _test_eof356;
case 356:
	if ( (*p) == 108 )
		goto st357;
	goto st0;
st357:
	if ( ++p == pe )
		goto _test_eof357;
case 357:
	if ( (*p) == 105 )
		goto st358;
	goto st0;
st358:
	if ( ++p == pe )
		goto _test_eof358;
case 358:
	if ( (*p) == 99 )
		goto st359;
	goto st0;
st359:
	if ( ++p == pe )
		goto _test_eof359;
case 359:
	switch( (*p) ) {
		case 10: goto tr488;
		case 13: goto tr489;
	}
	goto st0;
tr463:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st360;
st360:
	if ( ++p == pe )
		goto _test_eof360;
case 360:
#line 3998 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr491;
	}
	goto st360;
tr494:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st361;
tr491:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st361;
st361:
	if ( ++p == pe )
		goto _test_eof361;
case 361:
#line 4021 "mfilescanner.cc"
	if ( (*p) == 112 )
		goto st341;
	goto st0;
st362:
	if ( ++p == pe )
		goto _test_eof362;
case 362:
	if ( (*p) == 46 )
		goto st363;
	goto st0;
st363:
	if ( ++p == pe )
		goto _test_eof363;
case 363:
	if ( (*p) == 46 )
		goto st364;
	goto st0;
st364:
	if ( ++p == pe )
		goto _test_eof364;
case 364:
	switch( (*p) ) {
		case 9: goto st364;
		case 10: goto tr494;
		case 13: goto st365;
		case 32: goto st364;
	}
	goto st0;
st365:
	if ( ++p == pe )
		goto _test_eof365;
case 365:
	if ( (*p) == 10 )
		goto tr494;
	goto st0;
st366:
	if ( ++p == pe )
		goto _test_eof366;
case 366:
	if ( (*p) == 105 )
		goto st367;
	goto st0;
st367:
	if ( ++p == pe )
		goto _test_eof367;
case 367:
	if ( (*p) == 100 )
		goto st368;
	goto st0;
st368:
	if ( ++p == pe )
		goto _test_eof368;
case 368:
	if ( (*p) == 100 )
		goto st369;
	goto st0;
st369:
	if ( ++p == pe )
		goto _test_eof369;
case 369:
	if ( (*p) == 101 )
		goto st370;
	goto st0;
st370:
	if ( ++p == pe )
		goto _test_eof370;
case 370:
	if ( (*p) == 110 )
		goto st371;
	goto st0;
tr504:
#line 813 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
	goto st371;
st371:
	if ( ++p == pe )
		goto _test_eof371;
case 371:
#line 4102 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr501;
		case 41: goto st0;
		case 44: goto st0;
	}
	goto st371;
tr501:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st372;
tr503:
#line 32 "mfilescanner.rl"
	{line++;}
#line 813 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
	goto st372;
st372:
	if ( ++p == pe )
		goto _test_eof372;
case 372:
#line 4125 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr502;
		case 10: goto tr503;
		case 13: goto tr504;
		case 32: goto tr502;
		case 41: goto st0;
		case 44: goto st0;
		case 101: goto tr505;
		case 102: goto tr506;
	}
	goto st371;
tr512:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st373;
tr502:
#line 813 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st373;
st373:
	if ( ++p == pe )
		goto _test_eof373;
case 373:
#line 4153 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st373;
		case 10: goto tr501;
		case 32: goto st373;
		case 41: goto st0;
		case 44: goto st0;
		case 101: goto st374;
		case 102: goto tr509;
	}
	goto st371;
tr505:
#line 813 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
	goto st374;
st374:
	if ( ++p == pe )
		goto _test_eof374;
case 374:
#line 4174 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr501;
		case 41: goto st0;
		case 44: goto st0;
		case 110: goto st375;
	}
	goto st371;
st375:
	if ( ++p == pe )
		goto _test_eof375;
case 375:
	switch( (*p) ) {
		case 10: goto tr501;
		case 41: goto st0;
		case 44: goto st0;
		case 100: goto st1657;
	}
	goto st371;
st1657:
	if ( ++p == pe )
		goto _test_eof1657;
case 1657:
	switch( (*p) ) {
		case 10: goto tr501;
		case 41: goto st0;
		case 44: goto st0;
		case 59: goto tr2284;
	}
	goto st371;
tr2284:
#line 817 "mfilescanner.rl"
	{
         {goto st1668;}
       }
	goto st1658;
st1658:
	if ( ++p == pe )
		goto _test_eof1658;
case 1658:
#line 4214 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr501;
		case 41: goto st0;
		case 44: goto st0;
	}
	goto st371;
tr506:
#line 813 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
#line 807 "mfilescanner.rl"
	{
        tmp_string.assign(tmp_p, p - tmp_p);
        funcindent_ = tmp_string.find("f");
        p--;
        {goto st1453;}
       }
	goto st376;
tr509:
#line 807 "mfilescanner.rl"
	{
        tmp_string.assign(tmp_p, p - tmp_p);
        funcindent_ = tmp_string.find("f");
        p--;
        {goto st1453;}
       }
	goto st376;
tr513:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
#line 807 "mfilescanner.rl"
	{
        tmp_string.assign(tmp_p, p - tmp_p);
        funcindent_ = tmp_string.find("f");
        p--;
        {goto st1453;}
       }
	goto st376;
st376:
	if ( ++p == pe )
		goto _test_eof376;
case 376:
#line 4260 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr512;
		case 10: goto tr501;
		case 32: goto tr512;
		case 41: goto st0;
		case 44: goto st0;
		case 101: goto st374;
		case 102: goto tr513;
	}
	goto st371;
st377:
	if ( ++p == pe )
		goto _test_eof377;
case 377:
	switch( (*p) ) {
		case 101: goto st378;
		case 116: goto st421;
	}
	goto st0;
st378:
	if ( ++p == pe )
		goto _test_eof378;
case 378:
	switch( (*p) ) {
		case 97: goto st379;
		case 116: goto st382;
	}
	goto st0;
st379:
	if ( ++p == pe )
		goto _test_eof379;
case 379:
	if ( (*p) == 108 )
		goto st380;
	goto st0;
st380:
	if ( ++p == pe )
		goto _test_eof380;
case 380:
	if ( (*p) == 101 )
		goto st381;
	goto st0;
st381:
	if ( ++p == pe )
		goto _test_eof381;
case 381:
	if ( (*p) == 100 )
		goto st371;
	goto st0;
st382:
	if ( ++p == pe )
		goto _test_eof382;
case 382:
	if ( (*p) == 65 )
		goto st383;
	goto st0;
st383:
	if ( ++p == pe )
		goto _test_eof383;
case 383:
	if ( (*p) == 99 )
		goto st384;
	goto st0;
st384:
	if ( ++p == pe )
		goto _test_eof384;
case 384:
	if ( (*p) == 99 )
		goto st385;
	goto st0;
st385:
	if ( ++p == pe )
		goto _test_eof385;
case 385:
	if ( (*p) == 101 )
		goto st386;
	goto st0;
st386:
	if ( ++p == pe )
		goto _test_eof386;
case 386:
	if ( (*p) == 115 )
		goto st387;
	goto st0;
st387:
	if ( ++p == pe )
		goto _test_eof387;
case 387:
	if ( (*p) == 115 )
		goto st388;
	goto st0;
tr533:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st388;
tr530:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st388;
st388:
	if ( ++p == pe )
		goto _test_eof388;
case 388:
#line 4369 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st388;
		case 32: goto st388;
		case 37: goto tr526;
		case 46: goto st390;
		case 61: goto st394;
	}
	goto st0;
tr526:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st389;
st389:
	if ( ++p == pe )
		goto _test_eof389;
case 389:
#line 4386 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr530;
	}
	goto st389;
st390:
	if ( ++p == pe )
		goto _test_eof390;
case 390:
	if ( (*p) == 46 )
		goto st391;
	goto st0;
st391:
	if ( ++p == pe )
		goto _test_eof391;
case 391:
	if ( (*p) == 46 )
		goto st392;
	goto st0;
st392:
	if ( ++p == pe )
		goto _test_eof392;
case 392:
	switch( (*p) ) {
		case 9: goto st392;
		case 10: goto tr533;
		case 13: goto st393;
		case 32: goto st392;
	}
	goto st0;
st393:
	if ( ++p == pe )
		goto _test_eof393;
case 393:
	if ( (*p) == 10 )
		goto tr533;
	goto st0;
st394:
	if ( ++p == pe )
		goto _test_eof394;
case 394:
	switch( (*p) ) {
		case 9: goto st395;
		case 32: goto st395;
		case 37: goto tr536;
		case 46: goto st417;
	}
	goto st0;
st395:
	if ( ++p == pe )
		goto _test_eof395;
case 395:
	switch( (*p) ) {
		case 9: goto st395;
		case 32: goto st395;
		case 112: goto st396;
	}
	goto st0;
st396:
	if ( ++p == pe )
		goto _test_eof396;
case 396:
	switch( (*p) ) {
		case 114: goto st397;
		case 117: goto st410;
	}
	goto st0;
st397:
	if ( ++p == pe )
		goto _test_eof397;
case 397:
	switch( (*p) ) {
		case 105: goto st398;
		case 111: goto st403;
	}
	goto st0;
st398:
	if ( ++p == pe )
		goto _test_eof398;
case 398:
	if ( (*p) == 118 )
		goto st399;
	goto st0;
st399:
	if ( ++p == pe )
		goto _test_eof399;
case 399:
	if ( (*p) == 97 )
		goto st400;
	goto st0;
st400:
	if ( ++p == pe )
		goto _test_eof400;
case 400:
	if ( (*p) == 116 )
		goto st401;
	goto st0;
st401:
	if ( ++p == pe )
		goto _test_eof401;
case 401:
	if ( (*p) == 101 )
		goto st402;
	goto st0;
st402:
	if ( ++p == pe )
		goto _test_eof402;
case 402:
	switch( (*p) ) {
		case 10: goto tr547;
		case 13: goto tr548;
	}
	goto st0;
st403:
	if ( ++p == pe )
		goto _test_eof403;
case 403:
	if ( (*p) == 116 )
		goto st404;
	goto st0;
st404:
	if ( ++p == pe )
		goto _test_eof404;
case 404:
	if ( (*p) == 101 )
		goto st405;
	goto st0;
st405:
	if ( ++p == pe )
		goto _test_eof405;
case 405:
	if ( (*p) == 99 )
		goto st406;
	goto st0;
st406:
	if ( ++p == pe )
		goto _test_eof406;
case 406:
	if ( (*p) == 116 )
		goto st407;
	goto st0;
st407:
	if ( ++p == pe )
		goto _test_eof407;
case 407:
	if ( (*p) == 101 )
		goto st408;
	goto st0;
st408:
	if ( ++p == pe )
		goto _test_eof408;
case 408:
	if ( (*p) == 100 )
		goto st409;
	goto st0;
st409:
	if ( ++p == pe )
		goto _test_eof409;
case 409:
	switch( (*p) ) {
		case 10: goto tr555;
		case 13: goto tr556;
	}
	goto st0;
st410:
	if ( ++p == pe )
		goto _test_eof410;
case 410:
	if ( (*p) == 98 )
		goto st411;
	goto st0;
st411:
	if ( ++p == pe )
		goto _test_eof411;
case 411:
	if ( (*p) == 108 )
		goto st412;
	goto st0;
st412:
	if ( ++p == pe )
		goto _test_eof412;
case 412:
	if ( (*p) == 105 )
		goto st413;
	goto st0;
st413:
	if ( ++p == pe )
		goto _test_eof413;
case 413:
	if ( (*p) == 99 )
		goto st414;
	goto st0;
st414:
	if ( ++p == pe )
		goto _test_eof414;
case 414:
	switch( (*p) ) {
		case 10: goto tr561;
		case 13: goto tr562;
	}
	goto st0;
tr536:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st415;
st415:
	if ( ++p == pe )
		goto _test_eof415;
case 415:
#line 4596 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr564;
	}
	goto st415;
tr567:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st416;
tr564:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st416;
st416:
	if ( ++p == pe )
		goto _test_eof416;
case 416:
#line 4619 "mfilescanner.cc"
	if ( (*p) == 112 )
		goto st396;
	goto st0;
st417:
	if ( ++p == pe )
		goto _test_eof417;
case 417:
	if ( (*p) == 46 )
		goto st418;
	goto st0;
st418:
	if ( ++p == pe )
		goto _test_eof418;
case 418:
	if ( (*p) == 46 )
		goto st419;
	goto st0;
st419:
	if ( ++p == pe )
		goto _test_eof419;
case 419:
	switch( (*p) ) {
		case 9: goto st419;
		case 10: goto tr567;
		case 13: goto st420;
		case 32: goto st419;
	}
	goto st0;
st420:
	if ( ++p == pe )
		goto _test_eof420;
case 420:
	if ( (*p) == 10 )
		goto tr567;
	goto st0;
st421:
	if ( ++p == pe )
		goto _test_eof421;
case 421:
	if ( (*p) == 97 )
		goto st422;
	goto st0;
st422:
	if ( ++p == pe )
		goto _test_eof422;
case 422:
	if ( (*p) == 116 )
		goto st423;
	goto st0;
st423:
	if ( ++p == pe )
		goto _test_eof423;
case 423:
	if ( (*p) == 105 )
		goto st424;
	goto st0;
st424:
	if ( ++p == pe )
		goto _test_eof424;
case 424:
	if ( (*p) == 99 )
		goto tr572;
	goto st0;
tr572:
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
	goto st425;
tr576:
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
#line 813 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
	goto st425;
st425:
	if ( ++p == pe )
		goto _test_eof425;
case 425:
#line 4703 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr573;
		case 41: goto st0;
		case 44: goto st0;
	}
	goto tr572;
tr573:
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
#line 32 "mfilescanner.rl"
	{line++;}
	goto st426;
tr575:
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
#line 32 "mfilescanner.rl"
	{line++;}
#line 813 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
	goto st426;
st426:
	if ( ++p == pe )
		goto _test_eof426;
case 426:
#line 4734 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr574;
		case 10: goto tr575;
		case 13: goto tr576;
		case 32: goto tr574;
		case 41: goto st0;
		case 44: goto st0;
		case 101: goto tr577;
		case 102: goto tr578;
	}
	goto tr572;
tr579:
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
	goto st427;
tr574:
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
#line 813 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st427;
tr584:
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st427;
st427:
	if ( ++p == pe )
		goto _test_eof427;
case 427:
#line 4776 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr579;
		case 10: goto tr573;
		case 32: goto tr579;
		case 41: goto st0;
		case 44: goto st0;
		case 101: goto tr580;
		case 102: goto tr581;
	}
	goto tr572;
tr580:
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
	goto st428;
tr577:
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
#line 813 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
	goto st428;
st428:
	if ( ++p == pe )
		goto _test_eof428;
case 428:
#line 4807 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr573;
		case 41: goto st0;
		case 44: goto st0;
		case 110: goto tr582;
	}
	goto tr572;
tr582:
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
	goto st429;
st429:
	if ( ++p == pe )
		goto _test_eof429;
case 429:
#line 4825 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr573;
		case 41: goto st0;
		case 44: goto st0;
		case 100: goto tr583;
	}
	goto tr572;
tr583:
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
	goto st1659;
st1659:
	if ( ++p == pe )
		goto _test_eof1659;
case 1659:
#line 4843 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr573;
		case 41: goto st0;
		case 44: goto st0;
		case 59: goto tr2285;
	}
	goto tr572;
tr2285:
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
#line 817 "mfilescanner.rl"
	{
         {goto st1668;}
       }
	goto st1660;
st1660:
	if ( ++p == pe )
		goto _test_eof1660;
case 1660:
#line 4865 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr573;
		case 41: goto st0;
		case 44: goto st0;
	}
	goto tr572;
tr578:
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
#line 813 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
#line 807 "mfilescanner.rl"
	{
        tmp_string.assign(tmp_p, p - tmp_p);
        funcindent_ = tmp_string.find("f");
        p--;
        {goto st1453;}
       }
	goto st430;
tr581:
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
#line 807 "mfilescanner.rl"
	{
        tmp_string.assign(tmp_p, p - tmp_p);
        funcindent_ = tmp_string.find("f");
        p--;
        {goto st1453;}
       }
	goto st430;
tr585:
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
#line 807 "mfilescanner.rl"
	{
        tmp_string.assign(tmp_p, p - tmp_p);
        funcindent_ = tmp_string.find("f");
        p--;
        {goto st1453;}
       }
	goto st430;
st430:
	if ( ++p == pe )
		goto _test_eof430;
case 430:
#line 4923 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr584;
		case 10: goto tr573;
		case 32: goto tr584;
		case 41: goto st0;
		case 44: goto st0;
		case 101: goto tr580;
		case 102: goto tr585;
	}
	goto tr572;
tr852:
#line 745 "mfilescanner.rl"
	{ access_.full = Private;
               access_.get = Private;
               access_.set = Private;
             }
	goto st431;
tr862:
#line 740 "mfilescanner.rl"
	{ access_.full = Protected;
               access_.get = Protected;
               access_.set = Protected;
             }
	goto st431;
tr870:
#line 735 "mfilescanner.rl"
	{ access_.full = Public;
               access_.get = Public;
               access_.set = Public;
             }
	goto st431;
tr909:
#line 729 "mfilescanner.rl"
	{ access_.full = access_.set;
               access_.get = Private;
             }
	goto st431;
tr919:
#line 724 "mfilescanner.rl"
	{ access_.full =
                 (access_.set == Public ? Public : Protected );
               access_.get = Protected;
             }
	goto st431;
tr927:
#line 720 "mfilescanner.rl"
	{ access_.full = Public;
               access_.get = Public;
             }
	goto st431;
tr984:
#line 714 "mfilescanner.rl"
	{ access_.full = access_.get;
               access_.set = Private;
             }
	goto st431;
tr994:
#line 709 "mfilescanner.rl"
	{ access_.full =
                 (access_.get == Public ? Public : Protected );
               access_.set = Protected;
             }
	goto st431;
tr1002:
#line 705 "mfilescanner.rl"
	{ access_.full = Public;
               access_.set = Public;
             }
	goto st431;
st431:
	if ( ++p == pe )
		goto _test_eof431;
case 431:
#line 4997 "mfilescanner.cc"
	if ( (*p) == 46 )
		goto st432;
	goto st0;
st432:
	if ( ++p == pe )
		goto _test_eof432;
case 432:
	if ( (*p) == 46 )
		goto st433;
	goto st0;
st433:
	if ( ++p == pe )
		goto _test_eof433;
case 433:
	switch( (*p) ) {
		case 9: goto st433;
		case 10: goto tr588;
		case 13: goto st434;
		case 32: goto st433;
	}
	goto st0;
st434:
	if ( ++p == pe )
		goto _test_eof434;
case 434:
	if ( (*p) == 10 )
		goto tr588;
	goto st0;
st435:
	if ( ++p == pe )
		goto _test_eof435;
case 435:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st435;
		case 10: goto tr361;
		case 32: goto st435;
		case 37: goto tr590;
		case 46: goto st442;
		case 65: goto st446;
		case 71: goto st505;
		case 72: goto st551;
		case 83: goto st563;
	}
	goto st267;
tr590:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st436;
st436:
	if ( ++p == pe )
		goto _test_eof436;
case 436:
#line 5051 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr597;
	}
	goto st436;
tr602:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st437;
tr597:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st437;
st437:
	if ( ++p == pe )
		goto _test_eof437;
case 437:
#line 5074 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st437;
		case 32: goto st437;
		case 37: goto tr590;
		case 44: goto st269;
		case 46: goto st438;
		case 65: goto st275;
		case 71: goto st325;
		case 72: goto st366;
		case 83: goto st377;
	}
	goto st0;
st438:
	if ( ++p == pe )
		goto _test_eof438;
case 438:
	if ( (*p) == 46 )
		goto st439;
	goto st0;
st439:
	if ( ++p == pe )
		goto _test_eof439;
case 439:
	if ( (*p) == 46 )
		goto st440;
	goto st0;
st440:
	if ( ++p == pe )
		goto _test_eof440;
case 440:
	switch( (*p) ) {
		case 9: goto st440;
		case 10: goto tr602;
		case 13: goto st441;
		case 32: goto st440;
	}
	goto st0;
st441:
	if ( ++p == pe )
		goto _test_eof441;
case 441:
	if ( (*p) == 10 )
		goto tr602;
	goto st0;
st442:
	if ( ++p == pe )
		goto _test_eof442;
case 442:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 46: goto st443;
	}
	goto st267;
st443:
	if ( ++p == pe )
		goto _test_eof443;
case 443:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 46: goto st444;
	}
	goto st267;
st444:
	if ( ++p == pe )
		goto _test_eof444;
case 444:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st444;
		case 10: goto tr597;
		case 13: goto st445;
		case 32: goto st444;
	}
	goto st267;
st445:
	if ( ++p == pe )
		goto _test_eof445;
case 445:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr597;
	}
	goto st267;
st446:
	if ( ++p == pe )
		goto _test_eof446;
case 446:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 98: goto st447;
		case 99: goto st460;
	}
	goto st267;
st447:
	if ( ++p == pe )
		goto _test_eof447;
case 447:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 115: goto st448;
	}
	goto st267;
st448:
	if ( ++p == pe )
		goto _test_eof448;
case 448:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 116: goto st449;
	}
	goto st267;
st449:
	if ( ++p == pe )
		goto _test_eof449;
case 449:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 114: goto st450;
	}
	goto st267;
st450:
	if ( ++p == pe )
		goto _test_eof450;
case 450:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 97: goto st451;
	}
	goto st267;
st451:
	if ( ++p == pe )
		goto _test_eof451;
case 451:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 99: goto st452;
	}
	goto st267;
st452:
	if ( ++p == pe )
		goto _test_eof452;
case 452:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 116: goto tr614;
	}
	goto st267;
tr614:
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
	goto st453;
tr617:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
	goto st453;
st453:
	if ( ++p == pe )
		goto _test_eof453;
case 453:
#line 5249 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr384;
		case 10: goto tr615;
		case 41: goto st267;
		case 44: goto st267;
	}
	goto tr614;
tr615:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
	goto st454;
tr622:
#line 32 "mfilescanner.rl"
	{line++;}
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
	goto st454;
st454:
	if ( ++p == pe )
		goto _test_eof454;
case 454:
#line 5282 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr616;
		case 10: goto tr387;
		case 13: goto tr388;
		case 32: goto tr616;
		case 37: goto tr617;
		case 41: goto st0;
		case 44: goto st269;
		case 46: goto tr618;
		case 101: goto tr389;
		case 102: goto tr390;
	}
	goto tr384;
tr619:
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
	goto st455;
tr616:
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
#line 813 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st455;
st455:
	if ( ++p == pe )
		goto _test_eof455;
case 455:
#line 5318 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr619;
		case 10: goto tr385;
		case 32: goto tr619;
		case 37: goto tr617;
		case 41: goto st0;
		case 44: goto st269;
		case 46: goto tr618;
		case 101: goto tr392;
		case 102: goto tr393;
	}
	goto tr384;
tr618:
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
	goto st456;
st456:
	if ( ++p == pe )
		goto _test_eof456;
case 456:
#line 5341 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr385;
		case 41: goto st0;
		case 44: goto st0;
		case 46: goto tr620;
	}
	goto tr384;
tr620:
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
	goto st457;
st457:
	if ( ++p == pe )
		goto _test_eof457;
case 457:
#line 5359 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr385;
		case 41: goto st0;
		case 44: goto st0;
		case 46: goto tr621;
	}
	goto tr384;
tr621:
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
	goto st458;
st458:
	if ( ++p == pe )
		goto _test_eof458;
case 458:
#line 5377 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr621;
		case 10: goto tr622;
		case 13: goto tr623;
		case 32: goto tr621;
		case 41: goto st0;
		case 44: goto st0;
	}
	goto tr384;
tr623:
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
	goto st459;
st459:
	if ( ++p == pe )
		goto _test_eof459;
case 459:
#line 5397 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr622;
		case 41: goto st0;
		case 44: goto st0;
	}
	goto tr384;
st460:
	if ( ++p == pe )
		goto _test_eof460;
case 460:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 99: goto st461;
	}
	goto st267;
st461:
	if ( ++p == pe )
		goto _test_eof461;
case 461:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 101: goto st462;
	}
	goto st267;
st462:
	if ( ++p == pe )
		goto _test_eof462;
case 462:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 115: goto st463;
	}
	goto st267;
st463:
	if ( ++p == pe )
		goto _test_eof463;
case 463:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 115: goto st464;
	}
	goto st267;
st464:
	if ( ++p == pe )
		goto _test_eof464;
case 464:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st464;
		case 10: goto tr361;
		case 32: goto st464;
		case 37: goto tr628;
		case 46: goto st471;
		case 61: goto st475;
	}
	goto st267;
tr628:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st465;
st465:
	if ( ++p == pe )
		goto _test_eof465;
case 465:
#line 5466 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr632;
	}
	goto st465;
tr637:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st466;
tr632:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st466;
st466:
	if ( ++p == pe )
		goto _test_eof466;
case 466:
#line 5489 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st466;
		case 32: goto st466;
		case 37: goto tr628;
		case 44: goto st269;
		case 46: goto st467;
		case 61: goto st298;
	}
	goto st0;
st467:
	if ( ++p == pe )
		goto _test_eof467;
case 467:
	if ( (*p) == 46 )
		goto st468;
	goto st0;
st468:
	if ( ++p == pe )
		goto _test_eof468;
case 468:
	if ( (*p) == 46 )
		goto st469;
	goto st0;
st469:
	if ( ++p == pe )
		goto _test_eof469;
case 469:
	switch( (*p) ) {
		case 9: goto st469;
		case 10: goto tr637;
		case 13: goto st470;
		case 32: goto st469;
	}
	goto st0;
st470:
	if ( ++p == pe )
		goto _test_eof470;
case 470:
	if ( (*p) == 10 )
		goto tr637;
	goto st0;
st471:
	if ( ++p == pe )
		goto _test_eof471;
case 471:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 46: goto st472;
	}
	goto st267;
st472:
	if ( ++p == pe )
		goto _test_eof472;
case 472:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 46: goto st473;
	}
	goto st267;
st473:
	if ( ++p == pe )
		goto _test_eof473;
case 473:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st473;
		case 10: goto tr632;
		case 13: goto st474;
		case 32: goto st473;
	}
	goto st267;
st474:
	if ( ++p == pe )
		goto _test_eof474;
case 474:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr632;
	}
	goto st267;
st475:
	if ( ++p == pe )
		goto _test_eof475;
case 475:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st476;
		case 10: goto tr361;
		case 32: goto st476;
		case 37: goto tr643;
		case 46: goto st501;
	}
	goto st267;
st476:
	if ( ++p == pe )
		goto _test_eof476;
case 476:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st476;
		case 10: goto tr361;
		case 32: goto st476;
		case 112: goto st477;
	}
	goto st267;
st477:
	if ( ++p == pe )
		goto _test_eof477;
case 477:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 114: goto st478;
		case 117: goto st494;
	}
	goto st267;
st478:
	if ( ++p == pe )
		goto _test_eof478;
case 478:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 105: goto st479;
		case 111: goto st487;
	}
	goto st267;
st479:
	if ( ++p == pe )
		goto _test_eof479;
case 479:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 118: goto st480;
	}
	goto st267;
st480:
	if ( ++p == pe )
		goto _test_eof480;
case 480:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 97: goto st481;
	}
	goto st267;
st481:
	if ( ++p == pe )
		goto _test_eof481;
case 481:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 116: goto st482;
	}
	goto st267;
st482:
	if ( ++p == pe )
		goto _test_eof482;
case 482:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 101: goto st483;
	}
	goto st267;
st483:
	if ( ++p == pe )
		goto _test_eof483;
case 483:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr654;
		case 13: goto tr655;
	}
	goto st267;
tr658:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st484;
tr654:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 745 "mfilescanner.rl"
	{ access_.full = Private;
               access_.get = Private;
               access_.set = Private;
             }
	goto st484;
tr665:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 740 "mfilescanner.rl"
	{ access_.full = Protected;
               access_.get = Protected;
               access_.set = Protected;
             }
	goto st484;
tr671:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 735 "mfilescanner.rl"
	{ access_.full = Public;
               access_.get = Public;
               access_.set = Public;
             }
	goto st484;
tr712:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 729 "mfilescanner.rl"
	{ access_.full = access_.set;
               access_.get = Private;
             }
	goto st484;
tr720:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 724 "mfilescanner.rl"
	{ access_.full =
                 (access_.set == Public ? Public : Protected );
               access_.get = Protected;
             }
	goto st484;
tr726:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 720 "mfilescanner.rl"
	{ access_.full = Public;
               access_.get = Public;
             }
	goto st484;
tr785:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 714 "mfilescanner.rl"
	{ access_.full = access_.get;
               access_.set = Private;
             }
	goto st484;
tr793:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 709 "mfilescanner.rl"
	{ access_.full =
                 (access_.get == Public ? Public : Protected );
               access_.set = Protected;
             }
	goto st484;
tr799:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 705 "mfilescanner.rl"
	{ access_.full = Public;
               access_.set = Public;
             }
	goto st484;
st484:
	if ( ++p == pe )
		goto _test_eof484;
case 484:
#line 5804 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr656;
		case 10: goto tr319;
		case 13: goto tr320;
		case 32: goto tr656;
		case 37: goto tr363;
		case 44: goto st269;
		case 46: goto st431;
		case 101: goto tr321;
		case 102: goto tr322;
	}
	goto st0;
tr656:
#line 813 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st485;
st485:
	if ( ++p == pe )
		goto _test_eof485;
case 485:
#line 5829 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st485;
		case 10: goto tr324;
		case 13: goto st247;
		case 32: goto st485;
		case 37: goto tr363;
		case 44: goto st269;
		case 46: goto st431;
		case 101: goto st248;
		case 102: goto tr327;
	}
	goto st0;
tr655:
#line 745 "mfilescanner.rl"
	{ access_.full = Private;
               access_.get = Private;
               access_.set = Private;
             }
	goto st486;
tr666:
#line 740 "mfilescanner.rl"
	{ access_.full = Protected;
               access_.get = Protected;
               access_.set = Protected;
             }
	goto st486;
tr672:
#line 735 "mfilescanner.rl"
	{ access_.full = Public;
               access_.get = Public;
               access_.set = Public;
             }
	goto st486;
tr713:
#line 729 "mfilescanner.rl"
	{ access_.full = access_.set;
               access_.get = Private;
             }
	goto st486;
tr721:
#line 724 "mfilescanner.rl"
	{ access_.full =
                 (access_.set == Public ? Public : Protected );
               access_.get = Protected;
             }
	goto st486;
tr727:
#line 720 "mfilescanner.rl"
	{ access_.full = Public;
               access_.get = Public;
             }
	goto st486;
tr786:
#line 714 "mfilescanner.rl"
	{ access_.full = access_.get;
               access_.set = Private;
             }
	goto st486;
tr794:
#line 709 "mfilescanner.rl"
	{ access_.full =
                 (access_.get == Public ? Public : Protected );
               access_.set = Protected;
             }
	goto st486;
tr800:
#line 705 "mfilescanner.rl"
	{ access_.full = Public;
               access_.set = Public;
             }
	goto st486;
st486:
	if ( ++p == pe )
		goto _test_eof486;
case 486:
#line 5905 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr658;
	}
	goto st267;
st487:
	if ( ++p == pe )
		goto _test_eof487;
case 487:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 116: goto st488;
	}
	goto st267;
st488:
	if ( ++p == pe )
		goto _test_eof488;
case 488:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 101: goto st489;
	}
	goto st267;
st489:
	if ( ++p == pe )
		goto _test_eof489;
case 489:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 99: goto st490;
	}
	goto st267;
st490:
	if ( ++p == pe )
		goto _test_eof490;
case 490:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 116: goto st491;
	}
	goto st267;
st491:
	if ( ++p == pe )
		goto _test_eof491;
case 491:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 101: goto st492;
	}
	goto st267;
st492:
	if ( ++p == pe )
		goto _test_eof492;
case 492:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 100: goto st493;
	}
	goto st267;
st493:
	if ( ++p == pe )
		goto _test_eof493;
case 493:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr665;
		case 13: goto tr666;
	}
	goto st267;
st494:
	if ( ++p == pe )
		goto _test_eof494;
case 494:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 98: goto st495;
	}
	goto st267;
st495:
	if ( ++p == pe )
		goto _test_eof495;
case 495:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 108: goto st496;
	}
	goto st267;
st496:
	if ( ++p == pe )
		goto _test_eof496;
case 496:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 105: goto st497;
	}
	goto st267;
st497:
	if ( ++p == pe )
		goto _test_eof497;
case 497:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 99: goto st498;
	}
	goto st267;
st498:
	if ( ++p == pe )
		goto _test_eof498;
case 498:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr671;
		case 13: goto tr672;
	}
	goto st267;
tr643:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st499;
st499:
	if ( ++p == pe )
		goto _test_eof499;
case 499:
#line 6039 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr674;
	}
	goto st499;
tr674:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st500;
st500:
	if ( ++p == pe )
		goto _test_eof500;
case 500:
#line 6058 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st268;
		case 32: goto st268;
		case 37: goto tr363;
		case 44: goto st269;
		case 46: goto st431;
		case 112: goto st300;
	}
	goto st0;
st501:
	if ( ++p == pe )
		goto _test_eof501;
case 501:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 46: goto st502;
	}
	goto st267;
st502:
	if ( ++p == pe )
		goto _test_eof502;
case 502:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 46: goto st503;
	}
	goto st267;
st503:
	if ( ++p == pe )
		goto _test_eof503;
case 503:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st503;
		case 10: goto tr674;
		case 13: goto st504;
		case 32: goto st503;
	}
	goto st267;
st504:
	if ( ++p == pe )
		goto _test_eof504;
case 504:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr674;
	}
	goto st267;
st505:
	if ( ++p == pe )
		goto _test_eof505;
case 505:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 101: goto st506;
	}
	goto st267;
st506:
	if ( ++p == pe )
		goto _test_eof506;
case 506:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 116: goto st507;
	}
	goto st267;
st507:
	if ( ++p == pe )
		goto _test_eof507;
case 507:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 65: goto st508;
	}
	goto st267;
st508:
	if ( ++p == pe )
		goto _test_eof508;
case 508:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 99: goto st509;
	}
	goto st267;
st509:
	if ( ++p == pe )
		goto _test_eof509;
case 509:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 99: goto st510;
	}
	goto st267;
st510:
	if ( ++p == pe )
		goto _test_eof510;
case 510:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 101: goto st511;
	}
	goto st267;
st511:
	if ( ++p == pe )
		goto _test_eof511;
case 511:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 115: goto st512;
	}
	goto st267;
st512:
	if ( ++p == pe )
		goto _test_eof512;
case 512:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 115: goto st513;
	}
	goto st267;
st513:
	if ( ++p == pe )
		goto _test_eof513;
case 513:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st513;
		case 10: goto tr361;
		case 32: goto st513;
		case 37: goto tr686;
		case 46: goto st520;
		case 61: goto st524;
	}
	goto st267;
tr686:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st514;
st514:
	if ( ++p == pe )
		goto _test_eof514;
case 514:
#line 6211 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr690;
	}
	goto st514;
tr695:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st515;
tr690:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st515;
st515:
	if ( ++p == pe )
		goto _test_eof515;
case 515:
#line 6234 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st515;
		case 32: goto st515;
		case 37: goto tr686;
		case 44: goto st269;
		case 46: goto st516;
		case 61: goto st339;
	}
	goto st0;
st516:
	if ( ++p == pe )
		goto _test_eof516;
case 516:
	if ( (*p) == 46 )
		goto st517;
	goto st0;
st517:
	if ( ++p == pe )
		goto _test_eof517;
case 517:
	if ( (*p) == 46 )
		goto st518;
	goto st0;
st518:
	if ( ++p == pe )
		goto _test_eof518;
case 518:
	switch( (*p) ) {
		case 9: goto st518;
		case 10: goto tr695;
		case 13: goto st519;
		case 32: goto st518;
	}
	goto st0;
st519:
	if ( ++p == pe )
		goto _test_eof519;
case 519:
	if ( (*p) == 10 )
		goto tr695;
	goto st0;
st520:
	if ( ++p == pe )
		goto _test_eof520;
case 520:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 46: goto st521;
	}
	goto st267;
st521:
	if ( ++p == pe )
		goto _test_eof521;
case 521:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 46: goto st522;
	}
	goto st267;
st522:
	if ( ++p == pe )
		goto _test_eof522;
case 522:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st522;
		case 10: goto tr690;
		case 13: goto st523;
		case 32: goto st522;
	}
	goto st267;
st523:
	if ( ++p == pe )
		goto _test_eof523;
case 523:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr690;
	}
	goto st267;
st524:
	if ( ++p == pe )
		goto _test_eof524;
case 524:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st525;
		case 10: goto tr361;
		case 32: goto st525;
		case 37: goto tr701;
		case 46: goto st547;
	}
	goto st267;
st525:
	if ( ++p == pe )
		goto _test_eof525;
case 525:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st525;
		case 10: goto tr361;
		case 32: goto st525;
		case 112: goto st526;
	}
	goto st267;
st526:
	if ( ++p == pe )
		goto _test_eof526;
case 526:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 114: goto st527;
		case 117: goto st540;
	}
	goto st267;
st527:
	if ( ++p == pe )
		goto _test_eof527;
case 527:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 105: goto st528;
		case 111: goto st533;
	}
	goto st267;
st528:
	if ( ++p == pe )
		goto _test_eof528;
case 528:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 118: goto st529;
	}
	goto st267;
st529:
	if ( ++p == pe )
		goto _test_eof529;
case 529:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 97: goto st530;
	}
	goto st267;
st530:
	if ( ++p == pe )
		goto _test_eof530;
case 530:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 116: goto st531;
	}
	goto st267;
st531:
	if ( ++p == pe )
		goto _test_eof531;
case 531:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 101: goto st532;
	}
	goto st267;
st532:
	if ( ++p == pe )
		goto _test_eof532;
case 532:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr712;
		case 13: goto tr713;
	}
	goto st267;
st533:
	if ( ++p == pe )
		goto _test_eof533;
case 533:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 116: goto st534;
	}
	goto st267;
st534:
	if ( ++p == pe )
		goto _test_eof534;
case 534:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 101: goto st535;
	}
	goto st267;
st535:
	if ( ++p == pe )
		goto _test_eof535;
case 535:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 99: goto st536;
	}
	goto st267;
st536:
	if ( ++p == pe )
		goto _test_eof536;
case 536:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 116: goto st537;
	}
	goto st267;
st537:
	if ( ++p == pe )
		goto _test_eof537;
case 537:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 101: goto st538;
	}
	goto st267;
st538:
	if ( ++p == pe )
		goto _test_eof538;
case 538:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 100: goto st539;
	}
	goto st267;
st539:
	if ( ++p == pe )
		goto _test_eof539;
case 539:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr720;
		case 13: goto tr721;
	}
	goto st267;
st540:
	if ( ++p == pe )
		goto _test_eof540;
case 540:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 98: goto st541;
	}
	goto st267;
st541:
	if ( ++p == pe )
		goto _test_eof541;
case 541:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 108: goto st542;
	}
	goto st267;
st542:
	if ( ++p == pe )
		goto _test_eof542;
case 542:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 105: goto st543;
	}
	goto st267;
st543:
	if ( ++p == pe )
		goto _test_eof543;
case 543:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 99: goto st544;
	}
	goto st267;
st544:
	if ( ++p == pe )
		goto _test_eof544;
case 544:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr726;
		case 13: goto tr727;
	}
	goto st267;
tr701:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st545;
st545:
	if ( ++p == pe )
		goto _test_eof545;
case 545:
#line 6542 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr729;
	}
	goto st545;
tr729:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st546;
st546:
	if ( ++p == pe )
		goto _test_eof546;
case 546:
#line 6561 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st268;
		case 32: goto st268;
		case 37: goto tr363;
		case 44: goto st269;
		case 46: goto st431;
		case 112: goto st341;
	}
	goto st0;
st547:
	if ( ++p == pe )
		goto _test_eof547;
case 547:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 46: goto st548;
	}
	goto st267;
st548:
	if ( ++p == pe )
		goto _test_eof548;
case 548:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 46: goto st549;
	}
	goto st267;
st549:
	if ( ++p == pe )
		goto _test_eof549;
case 549:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st549;
		case 10: goto tr729;
		case 13: goto st550;
		case 32: goto st549;
	}
	goto st267;
st550:
	if ( ++p == pe )
		goto _test_eof550;
case 550:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr729;
	}
	goto st267;
st551:
	if ( ++p == pe )
		goto _test_eof551;
case 551:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 105: goto st552;
	}
	goto st267;
st552:
	if ( ++p == pe )
		goto _test_eof552;
case 552:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 100: goto st553;
	}
	goto st267;
st553:
	if ( ++p == pe )
		goto _test_eof553;
case 553:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 100: goto st554;
	}
	goto st267;
st554:
	if ( ++p == pe )
		goto _test_eof554;
case 554:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 101: goto st555;
	}
	goto st267;
st555:
	if ( ++p == pe )
		goto _test_eof555;
case 555:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 110: goto st556;
	}
	goto st267;
tr740:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st556;
st556:
	if ( ++p == pe )
		goto _test_eof556;
case 556:
#line 6670 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st371;
		case 10: goto tr738;
		case 41: goto st267;
		case 44: goto st267;
	}
	goto st556;
tr745:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st557;
tr738:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st557;
st557:
	if ( ++p == pe )
		goto _test_eof557;
case 557:
#line 6695 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr739;
		case 10: goto tr503;
		case 13: goto tr504;
		case 32: goto tr739;
		case 37: goto tr740;
		case 41: goto st0;
		case 44: goto st269;
		case 46: goto st559;
		case 101: goto tr505;
		case 102: goto tr506;
	}
	goto st371;
tr739:
#line 813 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st558;
st558:
	if ( ++p == pe )
		goto _test_eof558;
case 558:
#line 6721 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st558;
		case 10: goto tr501;
		case 32: goto st558;
		case 37: goto tr740;
		case 41: goto st0;
		case 44: goto st269;
		case 46: goto st559;
		case 101: goto st374;
		case 102: goto tr509;
	}
	goto st371;
st559:
	if ( ++p == pe )
		goto _test_eof559;
case 559:
	switch( (*p) ) {
		case 10: goto tr501;
		case 41: goto st0;
		case 44: goto st0;
		case 46: goto st560;
	}
	goto st371;
st560:
	if ( ++p == pe )
		goto _test_eof560;
case 560:
	switch( (*p) ) {
		case 10: goto tr501;
		case 41: goto st0;
		case 44: goto st0;
		case 46: goto st561;
	}
	goto st371;
st561:
	if ( ++p == pe )
		goto _test_eof561;
case 561:
	switch( (*p) ) {
		case 9: goto st561;
		case 10: goto tr745;
		case 13: goto st562;
		case 32: goto st561;
		case 41: goto st0;
		case 44: goto st0;
	}
	goto st371;
st562:
	if ( ++p == pe )
		goto _test_eof562;
case 562:
	switch( (*p) ) {
		case 10: goto tr745;
		case 41: goto st0;
		case 44: goto st0;
	}
	goto st371;
st563:
	if ( ++p == pe )
		goto _test_eof563;
case 563:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 101: goto st564;
		case 116: goto st612;
	}
	goto st267;
st564:
	if ( ++p == pe )
		goto _test_eof564;
case 564:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 97: goto st565;
		case 116: goto st568;
	}
	goto st267;
st565:
	if ( ++p == pe )
		goto _test_eof565;
case 565:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 108: goto st566;
	}
	goto st267;
st566:
	if ( ++p == pe )
		goto _test_eof566;
case 566:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 101: goto st567;
	}
	goto st267;
st567:
	if ( ++p == pe )
		goto _test_eof567;
case 567:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 100: goto st556;
	}
	goto st267;
st568:
	if ( ++p == pe )
		goto _test_eof568;
case 568:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 65: goto st569;
	}
	goto st267;
st569:
	if ( ++p == pe )
		goto _test_eof569;
case 569:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 99: goto st570;
	}
	goto st267;
st570:
	if ( ++p == pe )
		goto _test_eof570;
case 570:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 99: goto st571;
	}
	goto st267;
st571:
	if ( ++p == pe )
		goto _test_eof571;
case 571:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 101: goto st572;
	}
	goto st267;
st572:
	if ( ++p == pe )
		goto _test_eof572;
case 572:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 115: goto st573;
	}
	goto st267;
st573:
	if ( ++p == pe )
		goto _test_eof573;
case 573:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 115: goto st574;
	}
	goto st267;
st574:
	if ( ++p == pe )
		goto _test_eof574;
case 574:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st574;
		case 10: goto tr361;
		case 32: goto st574;
		case 37: goto tr759;
		case 46: goto st581;
		case 61: goto st585;
	}
	goto st267;
tr759:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st575;
st575:
	if ( ++p == pe )
		goto _test_eof575;
case 575:
#line 6913 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr763;
	}
	goto st575;
tr768:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st576;
tr763:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st576;
st576:
	if ( ++p == pe )
		goto _test_eof576;
case 576:
#line 6936 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st576;
		case 32: goto st576;
		case 37: goto tr759;
		case 44: goto st269;
		case 46: goto st577;
		case 61: goto st394;
	}
	goto st0;
st577:
	if ( ++p == pe )
		goto _test_eof577;
case 577:
	if ( (*p) == 46 )
		goto st578;
	goto st0;
st578:
	if ( ++p == pe )
		goto _test_eof578;
case 578:
	if ( (*p) == 46 )
		goto st579;
	goto st0;
st579:
	if ( ++p == pe )
		goto _test_eof579;
case 579:
	switch( (*p) ) {
		case 9: goto st579;
		case 10: goto tr768;
		case 13: goto st580;
		case 32: goto st579;
	}
	goto st0;
st580:
	if ( ++p == pe )
		goto _test_eof580;
case 580:
	if ( (*p) == 10 )
		goto tr768;
	goto st0;
st581:
	if ( ++p == pe )
		goto _test_eof581;
case 581:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 46: goto st582;
	}
	goto st267;
st582:
	if ( ++p == pe )
		goto _test_eof582;
case 582:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 46: goto st583;
	}
	goto st267;
st583:
	if ( ++p == pe )
		goto _test_eof583;
case 583:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st583;
		case 10: goto tr763;
		case 13: goto st584;
		case 32: goto st583;
	}
	goto st267;
st584:
	if ( ++p == pe )
		goto _test_eof584;
case 584:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr763;
	}
	goto st267;
st585:
	if ( ++p == pe )
		goto _test_eof585;
case 585:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st586;
		case 10: goto tr361;
		case 32: goto st586;
		case 37: goto tr774;
		case 46: goto st608;
	}
	goto st267;
st586:
	if ( ++p == pe )
		goto _test_eof586;
case 586:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st586;
		case 10: goto tr361;
		case 32: goto st586;
		case 112: goto st587;
	}
	goto st267;
st587:
	if ( ++p == pe )
		goto _test_eof587;
case 587:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 114: goto st588;
		case 117: goto st601;
	}
	goto st267;
st588:
	if ( ++p == pe )
		goto _test_eof588;
case 588:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 105: goto st589;
		case 111: goto st594;
	}
	goto st267;
st589:
	if ( ++p == pe )
		goto _test_eof589;
case 589:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 118: goto st590;
	}
	goto st267;
st590:
	if ( ++p == pe )
		goto _test_eof590;
case 590:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 97: goto st591;
	}
	goto st267;
st591:
	if ( ++p == pe )
		goto _test_eof591;
case 591:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 116: goto st592;
	}
	goto st267;
st592:
	if ( ++p == pe )
		goto _test_eof592;
case 592:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 101: goto st593;
	}
	goto st267;
st593:
	if ( ++p == pe )
		goto _test_eof593;
case 593:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr785;
		case 13: goto tr786;
	}
	goto st267;
st594:
	if ( ++p == pe )
		goto _test_eof594;
case 594:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 116: goto st595;
	}
	goto st267;
st595:
	if ( ++p == pe )
		goto _test_eof595;
case 595:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 101: goto st596;
	}
	goto st267;
st596:
	if ( ++p == pe )
		goto _test_eof596;
case 596:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 99: goto st597;
	}
	goto st267;
st597:
	if ( ++p == pe )
		goto _test_eof597;
case 597:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 116: goto st598;
	}
	goto st267;
st598:
	if ( ++p == pe )
		goto _test_eof598;
case 598:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 101: goto st599;
	}
	goto st267;
st599:
	if ( ++p == pe )
		goto _test_eof599;
case 599:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 100: goto st600;
	}
	goto st267;
st600:
	if ( ++p == pe )
		goto _test_eof600;
case 600:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr793;
		case 13: goto tr794;
	}
	goto st267;
st601:
	if ( ++p == pe )
		goto _test_eof601;
case 601:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 98: goto st602;
	}
	goto st267;
st602:
	if ( ++p == pe )
		goto _test_eof602;
case 602:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 108: goto st603;
	}
	goto st267;
st603:
	if ( ++p == pe )
		goto _test_eof603;
case 603:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 105: goto st604;
	}
	goto st267;
st604:
	if ( ++p == pe )
		goto _test_eof604;
case 604:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 99: goto st605;
	}
	goto st267;
st605:
	if ( ++p == pe )
		goto _test_eof605;
case 605:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr799;
		case 13: goto tr800;
	}
	goto st267;
tr774:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st606;
st606:
	if ( ++p == pe )
		goto _test_eof606;
case 606:
#line 7244 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr802;
	}
	goto st606;
tr802:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st607;
st607:
	if ( ++p == pe )
		goto _test_eof607;
case 607:
#line 7263 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st268;
		case 32: goto st268;
		case 37: goto tr363;
		case 44: goto st269;
		case 46: goto st431;
		case 112: goto st396;
	}
	goto st0;
st608:
	if ( ++p == pe )
		goto _test_eof608;
case 608:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 46: goto st609;
	}
	goto st267;
st609:
	if ( ++p == pe )
		goto _test_eof609;
case 609:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 46: goto st610;
	}
	goto st267;
st610:
	if ( ++p == pe )
		goto _test_eof610;
case 610:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st610;
		case 10: goto tr802;
		case 13: goto st611;
		case 32: goto st610;
	}
	goto st267;
st611:
	if ( ++p == pe )
		goto _test_eof611;
case 611:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr802;
	}
	goto st267;
st612:
	if ( ++p == pe )
		goto _test_eof612;
case 612:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 97: goto st613;
	}
	goto st267;
st613:
	if ( ++p == pe )
		goto _test_eof613;
case 613:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 116: goto st614;
	}
	goto st267;
st614:
	if ( ++p == pe )
		goto _test_eof614;
case 614:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 105: goto st615;
	}
	goto st267;
st615:
	if ( ++p == pe )
		goto _test_eof615;
case 615:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr361;
		case 99: goto tr809;
	}
	goto st267;
tr809:
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
	goto st616;
tr812:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
	goto st616;
st616:
	if ( ++p == pe )
		goto _test_eof616;
case 616:
#line 7372 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr572;
		case 10: goto tr810;
		case 41: goto st267;
		case 44: goto st267;
	}
	goto tr809;
tr810:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
	goto st617;
tr817:
#line 32 "mfilescanner.rl"
	{line++;}
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
	goto st617;
st617:
	if ( ++p == pe )
		goto _test_eof617;
case 617:
#line 7405 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr811;
		case 10: goto tr575;
		case 13: goto tr576;
		case 32: goto tr811;
		case 37: goto tr812;
		case 41: goto st0;
		case 44: goto st269;
		case 46: goto tr813;
		case 101: goto tr577;
		case 102: goto tr578;
	}
	goto tr572;
tr814:
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
	goto st618;
tr811:
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
#line 813 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st618;
st618:
	if ( ++p == pe )
		goto _test_eof618;
case 618:
#line 7441 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr814;
		case 10: goto tr573;
		case 32: goto tr814;
		case 37: goto tr812;
		case 41: goto st0;
		case 44: goto st269;
		case 46: goto tr813;
		case 101: goto tr580;
		case 102: goto tr581;
	}
	goto tr572;
tr813:
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
	goto st619;
st619:
	if ( ++p == pe )
		goto _test_eof619;
case 619:
#line 7464 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr573;
		case 41: goto st0;
		case 44: goto st0;
		case 46: goto tr815;
	}
	goto tr572;
tr815:
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
	goto st620;
st620:
	if ( ++p == pe )
		goto _test_eof620;
case 620:
#line 7482 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr573;
		case 41: goto st0;
		case 44: goto st0;
		case 46: goto tr816;
	}
	goto tr572;
tr816:
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
	goto st621;
st621:
	if ( ++p == pe )
		goto _test_eof621;
case 621:
#line 7500 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr816;
		case 10: goto tr817;
		case 13: goto tr818;
		case 32: goto tr816;
		case 41: goto st0;
		case 44: goto st0;
	}
	goto tr572;
tr818:
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
	goto st622;
st622:
	if ( ++p == pe )
		goto _test_eof622;
case 622:
#line 7520 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr817;
		case 41: goto st0;
		case 44: goto st0;
	}
	goto tr572;
tr356:
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
	goto st623;
st623:
	if ( ++p == pe )
		goto _test_eof623;
case 623:
#line 7537 "mfilescanner.cc"
	switch( (*p) ) {
		case 37: goto tr354;
		case 41: goto st0;
		case 44: goto st269;
		case 46: goto tr819;
	}
	goto tr353;
tr819:
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
	goto st624;
st624:
	if ( ++p == pe )
		goto _test_eof624;
case 624:
#line 7555 "mfilescanner.cc"
	switch( (*p) ) {
		case 37: goto tr354;
		case 41: goto st0;
		case 44: goto st269;
		case 46: goto tr820;
	}
	goto tr353;
tr820:
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
	goto st625;
st625:
	if ( ++p == pe )
		goto _test_eof625;
case 625:
#line 7573 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr821;
		case 10: goto tr822;
		case 13: goto tr823;
		case 32: goto tr821;
		case 37: goto tr354;
		case 41: goto st0;
		case 44: goto st269;
		case 46: goto tr820;
	}
	goto tr353;
tr821:
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
	goto st626;
st626:
	if ( ++p == pe )
		goto _test_eof626;
case 626:
#line 7595 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr821;
		case 10: goto tr822;
		case 13: goto tr823;
		case 32: goto tr821;
		case 37: goto tr354;
		case 41: goto st0;
		case 44: goto st269;
		case 46: goto tr356;
	}
	goto tr353;
tr823:
#line 756 "mfilescanner.rl"
	{
           methodparams_.abstr = true;
         }
	goto st627;
st627:
	if ( ++p == pe )
		goto _test_eof627;
case 627:
#line 7617 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr822;
		case 37: goto tr354;
		case 41: goto st0;
		case 44: goto st269;
		case 46: goto tr356;
	}
	goto tr353;
st628:
	if ( ++p == pe )
		goto _test_eof628;
case 628:
	if ( (*p) == 99 )
		goto st629;
	goto st0;
st629:
	if ( ++p == pe )
		goto _test_eof629;
case 629:
	if ( (*p) == 101 )
		goto st630;
	goto st0;
st630:
	if ( ++p == pe )
		goto _test_eof630;
case 630:
	if ( (*p) == 115 )
		goto st631;
	goto st0;
st631:
	if ( ++p == pe )
		goto _test_eof631;
case 631:
	if ( (*p) == 115 )
		goto st632;
	goto st0;
tr835:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st632;
tr832:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st632;
st632:
	if ( ++p == pe )
		goto _test_eof632;
case 632:
#line 7671 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st632;
		case 32: goto st632;
		case 37: goto tr828;
		case 46: goto st634;
		case 61: goto st638;
	}
	goto st0;
tr828:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st633;
st633:
	if ( ++p == pe )
		goto _test_eof633;
case 633:
#line 7688 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr832;
	}
	goto st633;
st634:
	if ( ++p == pe )
		goto _test_eof634;
case 634:
	if ( (*p) == 46 )
		goto st635;
	goto st0;
st635:
	if ( ++p == pe )
		goto _test_eof635;
case 635:
	if ( (*p) == 46 )
		goto st636;
	goto st0;
st636:
	if ( ++p == pe )
		goto _test_eof636;
case 636:
	switch( (*p) ) {
		case 9: goto st636;
		case 10: goto tr835;
		case 13: goto st637;
		case 32: goto st636;
	}
	goto st0;
st637:
	if ( ++p == pe )
		goto _test_eof637;
case 637:
	if ( (*p) == 10 )
		goto tr835;
	goto st0;
st638:
	if ( ++p == pe )
		goto _test_eof638;
case 638:
	switch( (*p) ) {
		case 9: goto st639;
		case 32: goto st639;
		case 37: goto tr838;
		case 46: goto st661;
	}
	goto st0;
st639:
	if ( ++p == pe )
		goto _test_eof639;
case 639:
	switch( (*p) ) {
		case 9: goto st639;
		case 32: goto st639;
		case 112: goto st640;
	}
	goto st0;
st640:
	if ( ++p == pe )
		goto _test_eof640;
case 640:
	switch( (*p) ) {
		case 114: goto st641;
		case 117: goto st654;
	}
	goto st0;
st641:
	if ( ++p == pe )
		goto _test_eof641;
case 641:
	switch( (*p) ) {
		case 105: goto st642;
		case 111: goto st647;
	}
	goto st0;
st642:
	if ( ++p == pe )
		goto _test_eof642;
case 642:
	if ( (*p) == 118 )
		goto st643;
	goto st0;
st643:
	if ( ++p == pe )
		goto _test_eof643;
case 643:
	if ( (*p) == 97 )
		goto st644;
	goto st0;
st644:
	if ( ++p == pe )
		goto _test_eof644;
case 644:
	if ( (*p) == 116 )
		goto st645;
	goto st0;
st645:
	if ( ++p == pe )
		goto _test_eof645;
case 645:
	if ( (*p) == 101 )
		goto st646;
	goto st0;
st646:
	if ( ++p == pe )
		goto _test_eof646;
case 646:
	switch( (*p) ) {
		case 9: goto tr849;
		case 32: goto tr849;
		case 37: goto tr850;
		case 44: goto tr851;
		case 46: goto tr852;
	}
	goto st0;
st647:
	if ( ++p == pe )
		goto _test_eof647;
case 647:
	if ( (*p) == 116 )
		goto st648;
	goto st0;
st648:
	if ( ++p == pe )
		goto _test_eof648;
case 648:
	if ( (*p) == 101 )
		goto st649;
	goto st0;
st649:
	if ( ++p == pe )
		goto _test_eof649;
case 649:
	if ( (*p) == 99 )
		goto st650;
	goto st0;
st650:
	if ( ++p == pe )
		goto _test_eof650;
case 650:
	if ( (*p) == 116 )
		goto st651;
	goto st0;
st651:
	if ( ++p == pe )
		goto _test_eof651;
case 651:
	if ( (*p) == 101 )
		goto st652;
	goto st0;
st652:
	if ( ++p == pe )
		goto _test_eof652;
case 652:
	if ( (*p) == 100 )
		goto st653;
	goto st0;
st653:
	if ( ++p == pe )
		goto _test_eof653;
case 653:
	switch( (*p) ) {
		case 9: goto tr859;
		case 32: goto tr859;
		case 37: goto tr860;
		case 44: goto tr861;
		case 46: goto tr862;
	}
	goto st0;
st654:
	if ( ++p == pe )
		goto _test_eof654;
case 654:
	if ( (*p) == 98 )
		goto st655;
	goto st0;
st655:
	if ( ++p == pe )
		goto _test_eof655;
case 655:
	if ( (*p) == 108 )
		goto st656;
	goto st0;
st656:
	if ( ++p == pe )
		goto _test_eof656;
case 656:
	if ( (*p) == 105 )
		goto st657;
	goto st0;
st657:
	if ( ++p == pe )
		goto _test_eof657;
case 657:
	if ( (*p) == 99 )
		goto st658;
	goto st0;
st658:
	if ( ++p == pe )
		goto _test_eof658;
case 658:
	switch( (*p) ) {
		case 9: goto tr867;
		case 32: goto tr867;
		case 37: goto tr868;
		case 44: goto tr869;
		case 46: goto tr870;
	}
	goto st0;
tr838:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st659;
st659:
	if ( ++p == pe )
		goto _test_eof659;
case 659:
#line 7907 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr872;
	}
	goto st659;
tr875:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st660;
tr872:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st660;
st660:
	if ( ++p == pe )
		goto _test_eof660;
case 660:
#line 7930 "mfilescanner.cc"
	if ( (*p) == 112 )
		goto st640;
	goto st0;
st661:
	if ( ++p == pe )
		goto _test_eof661;
case 661:
	if ( (*p) == 46 )
		goto st662;
	goto st0;
st662:
	if ( ++p == pe )
		goto _test_eof662;
case 662:
	if ( (*p) == 46 )
		goto st663;
	goto st0;
st663:
	if ( ++p == pe )
		goto _test_eof663;
case 663:
	switch( (*p) ) {
		case 9: goto st663;
		case 10: goto tr875;
		case 13: goto st664;
		case 32: goto st663;
	}
	goto st0;
st664:
	if ( ++p == pe )
		goto _test_eof664;
case 664:
	if ( (*p) == 10 )
		goto tr875;
	goto st0;
st665:
	if ( ++p == pe )
		goto _test_eof665;
case 665:
	if ( (*p) == 101 )
		goto st666;
	goto st0;
st666:
	if ( ++p == pe )
		goto _test_eof666;
case 666:
	if ( (*p) == 116 )
		goto st667;
	goto st0;
st667:
	if ( ++p == pe )
		goto _test_eof667;
case 667:
	if ( (*p) == 65 )
		goto st668;
	goto st0;
st668:
	if ( ++p == pe )
		goto _test_eof668;
case 668:
	if ( (*p) == 99 )
		goto st669;
	goto st0;
st669:
	if ( ++p == pe )
		goto _test_eof669;
case 669:
	if ( (*p) == 99 )
		goto st670;
	goto st0;
st670:
	if ( ++p == pe )
		goto _test_eof670;
case 670:
	if ( (*p) == 101 )
		goto st671;
	goto st0;
st671:
	if ( ++p == pe )
		goto _test_eof671;
case 671:
	if ( (*p) == 115 )
		goto st672;
	goto st0;
st672:
	if ( ++p == pe )
		goto _test_eof672;
case 672:
	if ( (*p) == 115 )
		goto st673;
	goto st0;
tr892:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st673;
tr889:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st673;
st673:
	if ( ++p == pe )
		goto _test_eof673;
case 673:
#line 8039 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st673;
		case 32: goto st673;
		case 37: goto tr885;
		case 46: goto st675;
		case 61: goto st679;
	}
	goto st0;
tr885:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st674;
st674:
	if ( ++p == pe )
		goto _test_eof674;
case 674:
#line 8056 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr889;
	}
	goto st674;
st675:
	if ( ++p == pe )
		goto _test_eof675;
case 675:
	if ( (*p) == 46 )
		goto st676;
	goto st0;
st676:
	if ( ++p == pe )
		goto _test_eof676;
case 676:
	if ( (*p) == 46 )
		goto st677;
	goto st0;
st677:
	if ( ++p == pe )
		goto _test_eof677;
case 677:
	switch( (*p) ) {
		case 9: goto st677;
		case 10: goto tr892;
		case 13: goto st678;
		case 32: goto st677;
	}
	goto st0;
st678:
	if ( ++p == pe )
		goto _test_eof678;
case 678:
	if ( (*p) == 10 )
		goto tr892;
	goto st0;
st679:
	if ( ++p == pe )
		goto _test_eof679;
case 679:
	switch( (*p) ) {
		case 9: goto st680;
		case 32: goto st680;
		case 37: goto tr895;
		case 46: goto st702;
	}
	goto st0;
st680:
	if ( ++p == pe )
		goto _test_eof680;
case 680:
	switch( (*p) ) {
		case 9: goto st680;
		case 32: goto st680;
		case 112: goto st681;
	}
	goto st0;
st681:
	if ( ++p == pe )
		goto _test_eof681;
case 681:
	switch( (*p) ) {
		case 114: goto st682;
		case 117: goto st695;
	}
	goto st0;
st682:
	if ( ++p == pe )
		goto _test_eof682;
case 682:
	switch( (*p) ) {
		case 105: goto st683;
		case 111: goto st688;
	}
	goto st0;
st683:
	if ( ++p == pe )
		goto _test_eof683;
case 683:
	if ( (*p) == 118 )
		goto st684;
	goto st0;
st684:
	if ( ++p == pe )
		goto _test_eof684;
case 684:
	if ( (*p) == 97 )
		goto st685;
	goto st0;
st685:
	if ( ++p == pe )
		goto _test_eof685;
case 685:
	if ( (*p) == 116 )
		goto st686;
	goto st0;
st686:
	if ( ++p == pe )
		goto _test_eof686;
case 686:
	if ( (*p) == 101 )
		goto st687;
	goto st0;
st687:
	if ( ++p == pe )
		goto _test_eof687;
case 687:
	switch( (*p) ) {
		case 9: goto tr906;
		case 32: goto tr906;
		case 37: goto tr907;
		case 44: goto tr908;
		case 46: goto tr909;
	}
	goto st0;
st688:
	if ( ++p == pe )
		goto _test_eof688;
case 688:
	if ( (*p) == 116 )
		goto st689;
	goto st0;
st689:
	if ( ++p == pe )
		goto _test_eof689;
case 689:
	if ( (*p) == 101 )
		goto st690;
	goto st0;
st690:
	if ( ++p == pe )
		goto _test_eof690;
case 690:
	if ( (*p) == 99 )
		goto st691;
	goto st0;
st691:
	if ( ++p == pe )
		goto _test_eof691;
case 691:
	if ( (*p) == 116 )
		goto st692;
	goto st0;
st692:
	if ( ++p == pe )
		goto _test_eof692;
case 692:
	if ( (*p) == 101 )
		goto st693;
	goto st0;
st693:
	if ( ++p == pe )
		goto _test_eof693;
case 693:
	if ( (*p) == 100 )
		goto st694;
	goto st0;
st694:
	if ( ++p == pe )
		goto _test_eof694;
case 694:
	switch( (*p) ) {
		case 9: goto tr916;
		case 32: goto tr916;
		case 37: goto tr917;
		case 44: goto tr918;
		case 46: goto tr919;
	}
	goto st0;
st695:
	if ( ++p == pe )
		goto _test_eof695;
case 695:
	if ( (*p) == 98 )
		goto st696;
	goto st0;
st696:
	if ( ++p == pe )
		goto _test_eof696;
case 696:
	if ( (*p) == 108 )
		goto st697;
	goto st0;
st697:
	if ( ++p == pe )
		goto _test_eof697;
case 697:
	if ( (*p) == 105 )
		goto st698;
	goto st0;
st698:
	if ( ++p == pe )
		goto _test_eof698;
case 698:
	if ( (*p) == 99 )
		goto st699;
	goto st0;
st699:
	if ( ++p == pe )
		goto _test_eof699;
case 699:
	switch( (*p) ) {
		case 9: goto tr924;
		case 32: goto tr924;
		case 37: goto tr925;
		case 44: goto tr926;
		case 46: goto tr927;
	}
	goto st0;
tr895:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st700;
st700:
	if ( ++p == pe )
		goto _test_eof700;
case 700:
#line 8275 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr929;
	}
	goto st700;
tr932:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st701;
tr929:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st701;
st701:
	if ( ++p == pe )
		goto _test_eof701;
case 701:
#line 8298 "mfilescanner.cc"
	if ( (*p) == 112 )
		goto st681;
	goto st0;
st702:
	if ( ++p == pe )
		goto _test_eof702;
case 702:
	if ( (*p) == 46 )
		goto st703;
	goto st0;
st703:
	if ( ++p == pe )
		goto _test_eof703;
case 703:
	if ( (*p) == 46 )
		goto st704;
	goto st0;
st704:
	if ( ++p == pe )
		goto _test_eof704;
case 704:
	switch( (*p) ) {
		case 9: goto st704;
		case 10: goto tr932;
		case 13: goto st705;
		case 32: goto st704;
	}
	goto st0;
st705:
	if ( ++p == pe )
		goto _test_eof705;
case 705:
	if ( (*p) == 10 )
		goto tr932;
	goto st0;
st706:
	if ( ++p == pe )
		goto _test_eof706;
case 706:
	if ( (*p) == 105 )
		goto st707;
	goto st0;
st707:
	if ( ++p == pe )
		goto _test_eof707;
case 707:
	if ( (*p) == 100 )
		goto st708;
	goto st0;
st708:
	if ( ++p == pe )
		goto _test_eof708;
case 708:
	if ( (*p) == 100 )
		goto st709;
	goto st0;
st709:
	if ( ++p == pe )
		goto _test_eof709;
case 709:
	if ( (*p) == 101 )
		goto st710;
	goto st0;
st710:
	if ( ++p == pe )
		goto _test_eof710;
case 710:
	if ( (*p) == 110 )
		goto st711;
	goto st0;
tr946:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st711;
tr942:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st711;
st711:
	if ( ++p == pe )
		goto _test_eof711;
case 711:
#line 8386 "mfilescanner.cc"
	switch( (*p) ) {
		case 37: goto tr939;
		case 41: goto st0;
		case 44: goto st269;
		case 46: goto st713;
	}
	goto st711;
tr939:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st712;
st712:
	if ( ++p == pe )
		goto _test_eof712;
case 712:
#line 8402 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st711;
		case 10: goto tr942;
		case 37: goto tr939;
		case 41: goto st267;
		case 44: goto st435;
	}
	goto st712;
st713:
	if ( ++p == pe )
		goto _test_eof713;
case 713:
	switch( (*p) ) {
		case 37: goto tr939;
		case 41: goto st0;
		case 44: goto st269;
		case 46: goto st714;
	}
	goto st711;
st714:
	if ( ++p == pe )
		goto _test_eof714;
case 714:
	switch( (*p) ) {
		case 37: goto tr939;
		case 41: goto st0;
		case 44: goto st269;
		case 46: goto st715;
	}
	goto st711;
st715:
	if ( ++p == pe )
		goto _test_eof715;
case 715:
	switch( (*p) ) {
		case 9: goto st716;
		case 10: goto tr946;
		case 13: goto st717;
		case 32: goto st716;
		case 37: goto tr939;
		case 41: goto st0;
		case 44: goto st269;
		case 46: goto st715;
	}
	goto st711;
st716:
	if ( ++p == pe )
		goto _test_eof716;
case 716:
	switch( (*p) ) {
		case 9: goto st716;
		case 10: goto tr946;
		case 13: goto st717;
		case 32: goto st716;
		case 37: goto tr939;
		case 41: goto st0;
		case 44: goto st269;
		case 46: goto st713;
	}
	goto st711;
st717:
	if ( ++p == pe )
		goto _test_eof717;
case 717:
	switch( (*p) ) {
		case 10: goto tr946;
		case 37: goto tr939;
		case 41: goto st0;
		case 44: goto st269;
		case 46: goto st713;
	}
	goto st711;
st718:
	if ( ++p == pe )
		goto _test_eof718;
case 718:
	switch( (*p) ) {
		case 101: goto st719;
		case 116: goto st762;
	}
	goto st0;
st719:
	if ( ++p == pe )
		goto _test_eof719;
case 719:
	switch( (*p) ) {
		case 97: goto st720;
		case 116: goto st723;
	}
	goto st0;
st720:
	if ( ++p == pe )
		goto _test_eof720;
case 720:
	if ( (*p) == 108 )
		goto st721;
	goto st0;
st721:
	if ( ++p == pe )
		goto _test_eof721;
case 721:
	if ( (*p) == 101 )
		goto st722;
	goto st0;
st722:
	if ( ++p == pe )
		goto _test_eof722;
case 722:
	if ( (*p) == 100 )
		goto st711;
	goto st0;
st723:
	if ( ++p == pe )
		goto _test_eof723;
case 723:
	if ( (*p) == 65 )
		goto st724;
	goto st0;
st724:
	if ( ++p == pe )
		goto _test_eof724;
case 724:
	if ( (*p) == 99 )
		goto st725;
	goto st0;
st725:
	if ( ++p == pe )
		goto _test_eof725;
case 725:
	if ( (*p) == 99 )
		goto st726;
	goto st0;
st726:
	if ( ++p == pe )
		goto _test_eof726;
case 726:
	if ( (*p) == 101 )
		goto st727;
	goto st0;
st727:
	if ( ++p == pe )
		goto _test_eof727;
case 727:
	if ( (*p) == 115 )
		goto st728;
	goto st0;
st728:
	if ( ++p == pe )
		goto _test_eof728;
case 728:
	if ( (*p) == 115 )
		goto st729;
	goto st0;
tr967:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st729;
tr964:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st729;
st729:
	if ( ++p == pe )
		goto _test_eof729;
case 729:
#line 8573 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st729;
		case 32: goto st729;
		case 37: goto tr960;
		case 46: goto st731;
		case 61: goto st735;
	}
	goto st0;
tr960:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st730;
st730:
	if ( ++p == pe )
		goto _test_eof730;
case 730:
#line 8590 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr964;
	}
	goto st730;
st731:
	if ( ++p == pe )
		goto _test_eof731;
case 731:
	if ( (*p) == 46 )
		goto st732;
	goto st0;
st732:
	if ( ++p == pe )
		goto _test_eof732;
case 732:
	if ( (*p) == 46 )
		goto st733;
	goto st0;
st733:
	if ( ++p == pe )
		goto _test_eof733;
case 733:
	switch( (*p) ) {
		case 9: goto st733;
		case 10: goto tr967;
		case 13: goto st734;
		case 32: goto st733;
	}
	goto st0;
st734:
	if ( ++p == pe )
		goto _test_eof734;
case 734:
	if ( (*p) == 10 )
		goto tr967;
	goto st0;
st735:
	if ( ++p == pe )
		goto _test_eof735;
case 735:
	switch( (*p) ) {
		case 9: goto st736;
		case 32: goto st736;
		case 37: goto tr970;
		case 46: goto st758;
	}
	goto st0;
st736:
	if ( ++p == pe )
		goto _test_eof736;
case 736:
	switch( (*p) ) {
		case 9: goto st736;
		case 32: goto st736;
		case 112: goto st737;
	}
	goto st0;
st737:
	if ( ++p == pe )
		goto _test_eof737;
case 737:
	switch( (*p) ) {
		case 114: goto st738;
		case 117: goto st751;
	}
	goto st0;
st738:
	if ( ++p == pe )
		goto _test_eof738;
case 738:
	switch( (*p) ) {
		case 105: goto st739;
		case 111: goto st744;
	}
	goto st0;
st739:
	if ( ++p == pe )
		goto _test_eof739;
case 739:
	if ( (*p) == 118 )
		goto st740;
	goto st0;
st740:
	if ( ++p == pe )
		goto _test_eof740;
case 740:
	if ( (*p) == 97 )
		goto st741;
	goto st0;
st741:
	if ( ++p == pe )
		goto _test_eof741;
case 741:
	if ( (*p) == 116 )
		goto st742;
	goto st0;
st742:
	if ( ++p == pe )
		goto _test_eof742;
case 742:
	if ( (*p) == 101 )
		goto st743;
	goto st0;
st743:
	if ( ++p == pe )
		goto _test_eof743;
case 743:
	switch( (*p) ) {
		case 9: goto tr981;
		case 32: goto tr981;
		case 37: goto tr982;
		case 44: goto tr983;
		case 46: goto tr984;
	}
	goto st0;
st744:
	if ( ++p == pe )
		goto _test_eof744;
case 744:
	if ( (*p) == 116 )
		goto st745;
	goto st0;
st745:
	if ( ++p == pe )
		goto _test_eof745;
case 745:
	if ( (*p) == 101 )
		goto st746;
	goto st0;
st746:
	if ( ++p == pe )
		goto _test_eof746;
case 746:
	if ( (*p) == 99 )
		goto st747;
	goto st0;
st747:
	if ( ++p == pe )
		goto _test_eof747;
case 747:
	if ( (*p) == 116 )
		goto st748;
	goto st0;
st748:
	if ( ++p == pe )
		goto _test_eof748;
case 748:
	if ( (*p) == 101 )
		goto st749;
	goto st0;
st749:
	if ( ++p == pe )
		goto _test_eof749;
case 749:
	if ( (*p) == 100 )
		goto st750;
	goto st0;
st750:
	if ( ++p == pe )
		goto _test_eof750;
case 750:
	switch( (*p) ) {
		case 9: goto tr991;
		case 32: goto tr991;
		case 37: goto tr992;
		case 44: goto tr993;
		case 46: goto tr994;
	}
	goto st0;
st751:
	if ( ++p == pe )
		goto _test_eof751;
case 751:
	if ( (*p) == 98 )
		goto st752;
	goto st0;
st752:
	if ( ++p == pe )
		goto _test_eof752;
case 752:
	if ( (*p) == 108 )
		goto st753;
	goto st0;
st753:
	if ( ++p == pe )
		goto _test_eof753;
case 753:
	if ( (*p) == 105 )
		goto st754;
	goto st0;
st754:
	if ( ++p == pe )
		goto _test_eof754;
case 754:
	if ( (*p) == 99 )
		goto st755;
	goto st0;
st755:
	if ( ++p == pe )
		goto _test_eof755;
case 755:
	switch( (*p) ) {
		case 9: goto tr999;
		case 32: goto tr999;
		case 37: goto tr1000;
		case 44: goto tr1001;
		case 46: goto tr1002;
	}
	goto st0;
tr970:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st756;
st756:
	if ( ++p == pe )
		goto _test_eof756;
case 756:
#line 8809 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1004;
	}
	goto st756;
tr1007:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st757;
tr1004:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st757;
st757:
	if ( ++p == pe )
		goto _test_eof757;
case 757:
#line 8832 "mfilescanner.cc"
	if ( (*p) == 112 )
		goto st737;
	goto st0;
st758:
	if ( ++p == pe )
		goto _test_eof758;
case 758:
	if ( (*p) == 46 )
		goto st759;
	goto st0;
st759:
	if ( ++p == pe )
		goto _test_eof759;
case 759:
	if ( (*p) == 46 )
		goto st760;
	goto st0;
st760:
	if ( ++p == pe )
		goto _test_eof760;
case 760:
	switch( (*p) ) {
		case 9: goto st760;
		case 10: goto tr1007;
		case 13: goto st761;
		case 32: goto st760;
	}
	goto st0;
st761:
	if ( ++p == pe )
		goto _test_eof761;
case 761:
	if ( (*p) == 10 )
		goto tr1007;
	goto st0;
st762:
	if ( ++p == pe )
		goto _test_eof762;
case 762:
	if ( (*p) == 97 )
		goto st763;
	goto st0;
st763:
	if ( ++p == pe )
		goto _test_eof763;
case 763:
	if ( (*p) == 116 )
		goto st764;
	goto st0;
st764:
	if ( ++p == pe )
		goto _test_eof764;
case 764:
	if ( (*p) == 105 )
		goto st765;
	goto st0;
st765:
	if ( ++p == pe )
		goto _test_eof765;
case 765:
	if ( (*p) == 99 )
		goto tr1012;
	goto st0;
tr1012:
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
	goto st766;
tr1020:
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
#line 32 "mfilescanner.rl"
	{line++;}
	goto st766;
tr1016:
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st766;
st766:
	if ( ++p == pe )
		goto _test_eof766;
case 766:
#line 8927 "mfilescanner.cc"
	switch( (*p) ) {
		case 37: goto tr1013;
		case 41: goto st0;
		case 44: goto st269;
		case 46: goto tr1014;
	}
	goto tr1012;
tr1015:
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
	goto st767;
tr1013:
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st767;
st767:
	if ( ++p == pe )
		goto _test_eof767;
case 767:
#line 8953 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr1012;
		case 10: goto tr1016;
		case 37: goto tr1013;
		case 41: goto st267;
		case 44: goto st435;
	}
	goto tr1015;
tr1014:
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
	goto st768;
st768:
	if ( ++p == pe )
		goto _test_eof768;
case 768:
#line 8972 "mfilescanner.cc"
	switch( (*p) ) {
		case 37: goto tr1013;
		case 41: goto st0;
		case 44: goto st269;
		case 46: goto tr1017;
	}
	goto tr1012;
tr1017:
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
	goto st769;
st769:
	if ( ++p == pe )
		goto _test_eof769;
case 769:
#line 8990 "mfilescanner.cc"
	switch( (*p) ) {
		case 37: goto tr1013;
		case 41: goto st0;
		case 44: goto st269;
		case 46: goto tr1018;
	}
	goto tr1012;
tr1018:
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
	goto st770;
st770:
	if ( ++p == pe )
		goto _test_eof770;
case 770:
#line 9008 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 32: goto tr1019;
		case 37: goto tr1013;
		case 41: goto st0;
		case 44: goto st269;
		case 46: goto tr1018;
	}
	goto tr1012;
tr1019:
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
	goto st771;
st771:
	if ( ++p == pe )
		goto _test_eof771;
case 771:
#line 9030 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 32: goto tr1019;
		case 37: goto tr1013;
		case 41: goto st0;
		case 44: goto st269;
		case 46: goto tr1014;
	}
	goto tr1012;
tr1021:
#line 760 "mfilescanner.rl"
	{
           methodparams_.statical = true;
         }
	goto st772;
st772:
	if ( ++p == pe )
		goto _test_eof772;
case 772:
#line 9052 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr1020;
		case 37: goto tr1013;
		case 41: goto st0;
		case 44: goto st269;
		case 46: goto tr1014;
	}
	goto tr1012;
st773:
	if ( ++p == pe )
		goto _test_eof773;
case 773:
	if ( (*p) == 46 )
		goto st774;
	goto st0;
st774:
	if ( ++p == pe )
		goto _test_eof774;
case 774:
	if ( (*p) == 46 )
		goto st775;
	goto st0;
st775:
	if ( ++p == pe )
		goto _test_eof775;
case 775:
	switch( (*p) ) {
		case 9: goto st775;
		case 10: goto tr1024;
		case 13: goto st776;
		case 32: goto st775;
	}
	goto st0;
st776:
	if ( ++p == pe )
		goto _test_eof776;
case 776:
	if ( (*p) == 10 )
		goto tr1024;
	goto st0;
tr1901:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st786;
tr1087:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st786;
st786:
#line 1 "mfilescanner.rl"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof786;
case 786:
#line 9112 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st786;
		case 10: goto tr1048;
		case 13: goto st802;
		case 32: goto st786;
		case 37: goto tr1050;
		case 40: goto st804;
		case 46: goto st1413;
	}
	goto st0;
tr1048:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st787;
tr1240:
#line 745 "mfilescanner.rl"
	{ access_.full = Private;
               access_.get = Private;
               access_.set = Private;
             }
#line 32 "mfilescanner.rl"
	{line++;}
	goto st787;
tr1248:
#line 740 "mfilescanner.rl"
	{ access_.full = Protected;
               access_.get = Protected;
               access_.set = Protected;
             }
#line 32 "mfilescanner.rl"
	{line++;}
	goto st787;
tr1254:
#line 735 "mfilescanner.rl"
	{ access_.full = Public;
               access_.get = Public;
               access_.set = Public;
             }
#line 32 "mfilescanner.rl"
	{line++;}
	goto st787;
tr1349:
#line 729 "mfilescanner.rl"
	{ access_.full = access_.set;
               access_.get = Private;
             }
#line 32 "mfilescanner.rl"
	{line++;}
	goto st787;
tr1357:
#line 724 "mfilescanner.rl"
	{ access_.full =
                 (access_.set == Public ? Public : Protected );
               access_.get = Protected;
             }
#line 32 "mfilescanner.rl"
	{line++;}
	goto st787;
tr1363:
#line 720 "mfilescanner.rl"
	{ access_.full = Public;
               access_.get = Public;
             }
#line 32 "mfilescanner.rl"
	{line++;}
	goto st787;
tr1405:
#line 714 "mfilescanner.rl"
	{ access_.full = access_.get;
               access_.set = Private;
             }
#line 32 "mfilescanner.rl"
	{line++;}
	goto st787;
tr1413:
#line 709 "mfilescanner.rl"
	{ access_.full =
                 (access_.get == Public ? Public : Protected );
               access_.set = Protected;
             }
#line 32 "mfilescanner.rl"
	{line++;}
	goto st787;
tr1419:
#line 705 "mfilescanner.rl"
	{ access_.full = Public;
               access_.set = Public;
             }
#line 32 "mfilescanner.rl"
	{line++;}
	goto st787;
tr1184:
#line 32 "mfilescanner.rl"
	{line++;}
#line 835 "mfilescanner.rl"
	{ cout << "\n";}
#line 835 "mfilescanner.rl"
	{ {goto st786;} }
	goto st787;
tr1191:
#line 32 "mfilescanner.rl"
	{line++;}
#line 831 "mfilescanner.rl"
	{
            cout << "\n/** @var " << property_list_.back() << "\n" << " * ";
            cout.write(tmp_p, p-tmp_p);
            cout << "*/";
          }
#line 835 "mfilescanner.rl"
	{ {goto st786;} }
	goto st787;
tr1180:
#line 32 "mfilescanner.rl"
	{line++;}
#line 67 "mfilescanner.rl"
	{ cout.write(tmp_p, p - tmp_p); }
#line 835 "mfilescanner.rl"
	{ cout << "\n";}
#line 835 "mfilescanner.rl"
	{ {goto st786;} }
	goto st787;
tr1188:
#line 32 "mfilescanner.rl"
	{line++;}
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
#line 831 "mfilescanner.rl"
	{
            cout << "\n/** @var " << property_list_.back() << "\n" << " * ";
            cout.write(tmp_p, p-tmp_p);
            cout << "*/";
          }
#line 835 "mfilescanner.rl"
	{ {goto st786;} }
	goto st787;
st787:
	if ( ++p == pe )
		goto _test_eof787;
case 787:
#line 9252 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr1053;
		case 10: goto tr1054;
		case 13: goto tr1055;
		case 32: goto tr1053;
		case 37: goto st801;
		case 95: goto tr1057;
		case 101: goto tr1058;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1057;
	} else if ( (*p) >= 65 )
		goto tr1057;
	goto st0;
tr1053:
#line 846 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
	goto st788;
st788:
	if ( ++p == pe )
		goto _test_eof788;
case 788:
#line 9278 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st788;
		case 10: goto tr1060;
		case 13: goto st790;
		case 32: goto st788;
		case 37: goto st801;
		case 95: goto tr1062;
		case 101: goto tr1063;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1062;
	} else if ( (*p) >= 65 )
		goto tr1062;
	goto st0;
tr1060:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st789;
tr1071:
#line 67 "mfilescanner.rl"
	{ cout.write(tmp_p, p - tmp_p); }
#line 32 "mfilescanner.rl"
	{line++;}
#line 835 "mfilescanner.rl"
	{ cout << "\n";}
#line 835 "mfilescanner.rl"
	{ {goto st786;} }
	goto st789;
tr1075:
#line 32 "mfilescanner.rl"
	{line++;}
#line 835 "mfilescanner.rl"
	{ cout << "\n";}
#line 835 "mfilescanner.rl"
	{ {goto st786;} }
	goto st789;
tr1079:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
#line 32 "mfilescanner.rl"
	{line++;}
#line 831 "mfilescanner.rl"
	{
            cout << "\n/** @var " << property_list_.back() << "\n" << " * ";
            cout.write(tmp_p, p-tmp_p);
            cout << "*/";
          }
#line 835 "mfilescanner.rl"
	{ {goto st786;} }
	goto st789;
tr1082:
#line 32 "mfilescanner.rl"
	{line++;}
#line 831 "mfilescanner.rl"
	{
            cout << "\n/** @var " << property_list_.back() << "\n" << " * ";
            cout.write(tmp_p, p-tmp_p);
            cout << "*/";
          }
#line 835 "mfilescanner.rl"
	{ {goto st786;} }
	goto st789;
tr1054:
#line 846 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
#line 32 "mfilescanner.rl"
	{line++;}
	goto st789;
st789:
	if ( ++p == pe )
		goto _test_eof789;
case 789:
#line 9354 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st789;
		case 10: goto tr1060;
		case 13: goto st790;
		case 32: goto st789;
		case 95: goto tr1062;
		case 101: goto tr1063;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1062;
	} else if ( (*p) >= 65 )
		goto tr1062;
	goto st0;
tr1055:
#line 846 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
	goto st790;
st790:
	if ( ++p == pe )
		goto _test_eof790;
case 790:
#line 9379 "mfilescanner.cc"
	if ( (*p) == 10 )
		goto tr1060;
	goto st0;
tr1062:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
#line 823 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            property_list_.push_back(s);
            cout << propertyparams_.ccprefix() << " " << s;
            }
	goto st791;
tr1066:
#line 823 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            property_list_.push_back(s);
            cout << propertyparams_.ccprefix() << " " << s;
            }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st791;
tr1057:
#line 846 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
#line 823 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            property_list_.push_back(s);
            cout << propertyparams_.ccprefix() << " " << s;
            }
	goto st791;
st791:
	if ( ++p == pe )
		goto _test_eof791;
case 791:
#line 9421 "mfilescanner.cc"
	switch( (*p) ) {
		case 59: goto tr1067;
		case 95: goto tr1066;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr1066;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1066;
	} else
		goto tr1066;
	goto tr1065;
tr1065:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st792;
st792:
	if ( ++p == pe )
		goto _test_eof792;
case 792:
#line 9443 "mfilescanner.cc"
	if ( (*p) == 59 )
		goto st793;
	goto st792;
tr1067:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st793;
st793:
	if ( ++p == pe )
		goto _test_eof793;
case 793:
#line 9455 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr1070;
		case 10: goto tr1071;
		case 13: goto tr1072;
		case 32: goto tr1070;
		case 37: goto tr1073;
	}
	goto st0;
tr1070:
#line 67 "mfilescanner.rl"
	{ cout.write(tmp_p, p - tmp_p); }
	goto st794;
st794:
	if ( ++p == pe )
		goto _test_eof794;
case 794:
#line 9472 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st794;
		case 10: goto tr1075;
		case 13: goto st795;
		case 32: goto st794;
		case 37: goto st796;
	}
	goto st0;
tr1072:
#line 67 "mfilescanner.rl"
	{ cout.write(tmp_p, p - tmp_p); }
	goto st795;
st795:
	if ( ++p == pe )
		goto _test_eof795;
case 795:
#line 9489 "mfilescanner.cc"
	if ( (*p) == 10 )
		goto tr1075;
	goto st0;
tr1073:
#line 67 "mfilescanner.rl"
	{ cout.write(tmp_p, p - tmp_p); }
	goto st796;
st796:
	if ( ++p == pe )
		goto _test_eof796;
case 796:
#line 9501 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1079;
		case 13: goto tr1080;
	}
	goto tr1078;
tr1078:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st797;
st797:
	if ( ++p == pe )
		goto _test_eof797;
case 797:
#line 9516 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1082;
		case 13: goto st798;
	}
	goto st797;
tr1080:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st798;
st798:
	if ( ++p == pe )
		goto _test_eof798;
case 798:
#line 9531 "mfilescanner.cc"
	if ( (*p) == 10 )
		goto tr1082;
	goto st0;
tr1063:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
#line 823 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            property_list_.push_back(s);
            cout << propertyparams_.ccprefix() << " " << s;
            }
	goto st799;
tr1058:
#line 846 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
#line 823 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            property_list_.push_back(s);
            cout << propertyparams_.ccprefix() << " " << s;
            }
	goto st799;
st799:
	if ( ++p == pe )
		goto _test_eof799;
case 799:
#line 9563 "mfilescanner.cc"
	switch( (*p) ) {
		case 59: goto tr1067;
		case 95: goto tr1066;
		case 110: goto tr1084;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr1066;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1066;
	} else
		goto tr1066;
	goto tr1065;
tr1084:
#line 823 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            property_list_.push_back(s);
            cout << propertyparams_.ccprefix() << " " << s;
            }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st800;
st800:
	if ( ++p == pe )
		goto _test_eof800;
case 800:
#line 9592 "mfilescanner.cc"
	switch( (*p) ) {
		case 59: goto tr1067;
		case 95: goto tr1066;
		case 100: goto tr1085;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr1066;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1066;
	} else
		goto tr1066;
	goto tr1065;
tr1085:
#line 823 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            property_list_.push_back(s);
            cout << propertyparams_.ccprefix() << " " << s;
            }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st1662;
st1662:
	if ( ++p == pe )
		goto _test_eof1662;
case 1662:
#line 9621 "mfilescanner.cc"
	switch( (*p) ) {
		case 59: goto tr2286;
		case 95: goto tr1066;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr1066;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1066;
	} else
		goto tr1066;
	goto tr1065;
tr2286:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
#line 850 "mfilescanner.rl"
	{
         {goto st1668;}
       }
	goto st1663;
st1663:
	if ( ++p == pe )
		goto _test_eof1663;
case 1663:
#line 9647 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr1070;
		case 10: goto tr1071;
		case 13: goto tr1072;
		case 32: goto tr1070;
		case 37: goto tr1073;
	}
	goto st0;
st801:
	if ( ++p == pe )
		goto _test_eof801;
case 801:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1048;
		case 13: goto st802;
	}
	goto st801;
tr1241:
#line 745 "mfilescanner.rl"
	{ access_.full = Private;
               access_.get = Private;
               access_.set = Private;
             }
	goto st802;
tr1249:
#line 740 "mfilescanner.rl"
	{ access_.full = Protected;
               access_.get = Protected;
               access_.set = Protected;
             }
	goto st802;
tr1255:
#line 735 "mfilescanner.rl"
	{ access_.full = Public;
               access_.get = Public;
               access_.set = Public;
             }
	goto st802;
tr1350:
#line 729 "mfilescanner.rl"
	{ access_.full = access_.set;
               access_.get = Private;
             }
	goto st802;
tr1358:
#line 724 "mfilescanner.rl"
	{ access_.full =
                 (access_.set == Public ? Public : Protected );
               access_.get = Protected;
             }
	goto st802;
tr1364:
#line 720 "mfilescanner.rl"
	{ access_.full = Public;
               access_.get = Public;
             }
	goto st802;
tr1406:
#line 714 "mfilescanner.rl"
	{ access_.full = access_.get;
               access_.set = Private;
             }
	goto st802;
tr1414:
#line 709 "mfilescanner.rl"
	{ access_.full =
                 (access_.get == Public ? Public : Protected );
               access_.set = Protected;
             }
	goto st802;
tr1420:
#line 705 "mfilescanner.rl"
	{ access_.full = Public;
               access_.set = Public;
             }
	goto st802;
st802:
	if ( ++p == pe )
		goto _test_eof802;
case 802:
#line 9729 "mfilescanner.cc"
	if ( (*p) == 10 )
		goto tr1048;
	goto st0;
tr1050:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st803;
st803:
	if ( ++p == pe )
		goto _test_eof803;
case 803:
#line 9741 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1087;
	}
	goto st803;
tr1101:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st804;
tr1098:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st804;
st804:
	if ( ++p == pe )
		goto _test_eof804;
case 804:
#line 9764 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st804;
		case 32: goto st804;
		case 37: goto tr1088;
		case 46: goto st806;
		case 65: goto st810;
		case 67: goto st1291;
		case 68: goto st1305;
		case 71: goto st1312;
		case 72: goto st1353;
		case 83: goto st1358;
		case 84: goto st1408;
	}
	goto st0;
tr1088:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st805;
st805:
	if ( ++p == pe )
		goto _test_eof805;
case 805:
#line 9787 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1098;
	}
	goto st805;
st806:
	if ( ++p == pe )
		goto _test_eof806;
case 806:
	if ( (*p) == 46 )
		goto st807;
	goto st0;
st807:
	if ( ++p == pe )
		goto _test_eof807;
case 807:
	if ( (*p) == 46 )
		goto st808;
	goto st0;
st808:
	if ( ++p == pe )
		goto _test_eof808;
case 808:
	switch( (*p) ) {
		case 9: goto st808;
		case 10: goto tr1101;
		case 13: goto st809;
		case 32: goto st808;
	}
	goto st0;
st809:
	if ( ++p == pe )
		goto _test_eof809;
case 809:
	if ( (*p) == 10 )
		goto tr1101;
	goto st0;
st810:
	if ( ++p == pe )
		goto _test_eof810;
case 810:
	switch( (*p) ) {
		case 98: goto st811;
		case 99: goto st1254;
	}
	goto st0;
st811:
	if ( ++p == pe )
		goto _test_eof811;
case 811:
	if ( (*p) == 115 )
		goto st812;
	goto st0;
st812:
	if ( ++p == pe )
		goto _test_eof812;
case 812:
	if ( (*p) == 116 )
		goto st813;
	goto st0;
st813:
	if ( ++p == pe )
		goto _test_eof813;
case 813:
	if ( (*p) == 114 )
		goto st814;
	goto st0;
st814:
	if ( ++p == pe )
		goto _test_eof814;
case 814:
	if ( (*p) == 97 )
		goto st815;
	goto st0;
st815:
	if ( ++p == pe )
		goto _test_eof815;
case 815:
	if ( (*p) == 99 )
		goto st816;
	goto st0;
st816:
	if ( ++p == pe )
		goto _test_eof816;
case 816:
	if ( (*p) == 116 )
		goto st817;
	goto st0;
tr1691:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st817;
tr1115:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st817;
st817:
	if ( ++p == pe )
		goto _test_eof817;
case 817:
#line 9893 "mfilescanner.cc"
	switch( (*p) ) {
		case 37: goto tr1111;
		case 41: goto st0;
		case 44: goto st821;
		case 46: goto st1249;
	}
	goto st817;
tr1111:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st818;
st818:
	if ( ++p == pe )
		goto _test_eof818;
case 818:
#line 9909 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st817;
		case 10: goto tr1115;
		case 37: goto tr1111;
		case 41: goto st819;
		case 44: goto st1044;
	}
	goto st818;
tr1120:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st819;
tr1719:
#line 745 "mfilescanner.rl"
	{ access_.full = Private;
               access_.get = Private;
               access_.set = Private;
             }
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st819;
tr1729:
#line 740 "mfilescanner.rl"
	{ access_.full = Protected;
               access_.get = Protected;
               access_.set = Protected;
             }
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st819;
tr1737:
#line 735 "mfilescanner.rl"
	{ access_.full = Public;
               access_.get = Public;
               access_.set = Public;
             }
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st819;
tr1798:
#line 729 "mfilescanner.rl"
	{ access_.full = access_.set;
               access_.get = Private;
             }
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st819;
tr1808:
#line 724 "mfilescanner.rl"
	{ access_.full =
                 (access_.set == Public ? Public : Protected );
               access_.get = Protected;
             }
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st819;
tr1816:
#line 720 "mfilescanner.rl"
	{ access_.full = Public;
               access_.get = Public;
             }
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st819;
tr1860:
#line 714 "mfilescanner.rl"
	{ access_.full = access_.get;
               access_.set = Private;
             }
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st819;
tr1870:
#line 709 "mfilescanner.rl"
	{ access_.full =
                 (access_.get == Public ? Public : Protected );
               access_.set = Protected;
             }
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st819;
tr1878:
#line 705 "mfilescanner.rl"
	{ access_.full = Public;
               access_.set = Public;
             }
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st819;
st819:
	if ( ++p == pe )
		goto _test_eof819;
case 819:
#line 10003 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
	}
	goto st819;
tr1441:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st820;
tr1118:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st820;
tr1718:
#line 745 "mfilescanner.rl"
	{ access_.full = Private;
               access_.get = Private;
               access_.set = Private;
             }
	goto st820;
tr1728:
#line 740 "mfilescanner.rl"
	{ access_.full = Protected;
               access_.get = Protected;
               access_.set = Protected;
             }
	goto st820;
tr1736:
#line 735 "mfilescanner.rl"
	{ access_.full = Public;
               access_.get = Public;
               access_.set = Public;
             }
	goto st820;
tr1797:
#line 729 "mfilescanner.rl"
	{ access_.full = access_.set;
               access_.get = Private;
             }
	goto st820;
tr1807:
#line 724 "mfilescanner.rl"
	{ access_.full =
                 (access_.set == Public ? Public : Protected );
               access_.get = Protected;
             }
	goto st820;
tr1815:
#line 720 "mfilescanner.rl"
	{ access_.full = Public;
               access_.get = Public;
             }
	goto st820;
tr1859:
#line 714 "mfilescanner.rl"
	{ access_.full = access_.get;
               access_.set = Private;
             }
	goto st820;
tr1869:
#line 709 "mfilescanner.rl"
	{ access_.full =
                 (access_.get == Public ? Public : Protected );
               access_.set = Protected;
             }
	goto st820;
tr1877:
#line 705 "mfilescanner.rl"
	{ access_.full = Public;
               access_.set = Public;
             }
	goto st820;
st820:
	if ( ++p == pe )
		goto _test_eof820;
case 820:
#line 10085 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st820;
		case 32: goto st820;
		case 37: goto tr1120;
		case 44: goto st821;
		case 46: goto st1040;
	}
	goto st0;
tr1135:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st821;
tr1132:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st821;
tr1720:
#line 745 "mfilescanner.rl"
	{ access_.full = Private;
               access_.get = Private;
               access_.set = Private;
             }
	goto st821;
tr1730:
#line 740 "mfilescanner.rl"
	{ access_.full = Protected;
               access_.get = Protected;
               access_.set = Protected;
             }
	goto st821;
tr1738:
#line 735 "mfilescanner.rl"
	{ access_.full = Public;
               access_.get = Public;
               access_.set = Public;
             }
	goto st821;
tr1799:
#line 729 "mfilescanner.rl"
	{ access_.full = access_.set;
               access_.get = Private;
             }
	goto st821;
tr1809:
#line 724 "mfilescanner.rl"
	{ access_.full =
                 (access_.set == Public ? Public : Protected );
               access_.get = Protected;
             }
	goto st821;
tr1817:
#line 720 "mfilescanner.rl"
	{ access_.full = Public;
               access_.get = Public;
             }
	goto st821;
tr1861:
#line 714 "mfilescanner.rl"
	{ access_.full = access_.get;
               access_.set = Private;
             }
	goto st821;
tr1871:
#line 709 "mfilescanner.rl"
	{ access_.full =
                 (access_.get == Public ? Public : Protected );
               access_.set = Protected;
             }
	goto st821;
tr1879:
#line 705 "mfilescanner.rl"
	{ access_.full = Public;
               access_.set = Public;
             }
	goto st821;
st821:
	if ( ++p == pe )
		goto _test_eof821;
case 821:
#line 10170 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st821;
		case 32: goto st821;
		case 37: goto tr1122;
		case 46: goto st823;
		case 65: goto st827;
		case 67: goto st904;
		case 68: goto st932;
		case 71: goto st939;
		case 72: goto st980;
		case 83: goto st985;
		case 84: goto st1035;
	}
	goto st0;
tr1122:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st822;
st822:
	if ( ++p == pe )
		goto _test_eof822;
case 822:
#line 10193 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1132;
	}
	goto st822;
st823:
	if ( ++p == pe )
		goto _test_eof823;
case 823:
	if ( (*p) == 46 )
		goto st824;
	goto st0;
st824:
	if ( ++p == pe )
		goto _test_eof824;
case 824:
	if ( (*p) == 46 )
		goto st825;
	goto st0;
st825:
	if ( ++p == pe )
		goto _test_eof825;
case 825:
	switch( (*p) ) {
		case 9: goto st825;
		case 10: goto tr1135;
		case 13: goto st826;
		case 32: goto st825;
	}
	goto st0;
st826:
	if ( ++p == pe )
		goto _test_eof826;
case 826:
	if ( (*p) == 10 )
		goto tr1135;
	goto st0;
st827:
	if ( ++p == pe )
		goto _test_eof827;
case 827:
	switch( (*p) ) {
		case 98: goto st828;
		case 99: goto st867;
	}
	goto st0;
st828:
	if ( ++p == pe )
		goto _test_eof828;
case 828:
	if ( (*p) == 115 )
		goto st829;
	goto st0;
st829:
	if ( ++p == pe )
		goto _test_eof829;
case 829:
	if ( (*p) == 116 )
		goto st830;
	goto st0;
st830:
	if ( ++p == pe )
		goto _test_eof830;
case 830:
	if ( (*p) == 114 )
		goto st831;
	goto st0;
st831:
	if ( ++p == pe )
		goto _test_eof831;
case 831:
	if ( (*p) == 97 )
		goto st832;
	goto st0;
st832:
	if ( ++p == pe )
		goto _test_eof832;
case 832:
	if ( (*p) == 99 )
		goto st833;
	goto st0;
st833:
	if ( ++p == pe )
		goto _test_eof833;
case 833:
	if ( (*p) == 116 )
		goto st834;
	goto st0;
tr1148:
#line 846 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
	goto st834;
st834:
	if ( ++p == pe )
		goto _test_eof834;
case 834:
#line 10292 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr1145;
		case 41: goto st0;
		case 44: goto st0;
	}
	goto st834;
tr1145:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st835;
tr1198:
#line 32 "mfilescanner.rl"
	{line++;}
#line 835 "mfilescanner.rl"
	{ cout << "\n";}
#line 835 "mfilescanner.rl"
	{ {goto st786;} }
	goto st835;
tr1205:
#line 32 "mfilescanner.rl"
	{line++;}
#line 831 "mfilescanner.rl"
	{
            cout << "\n/** @var " << property_list_.back() << "\n" << " * ";
            cout.write(tmp_p, p-tmp_p);
            cout << "*/";
          }
#line 835 "mfilescanner.rl"
	{ {goto st786;} }
	goto st835;
tr1147:
#line 32 "mfilescanner.rl"
	{line++;}
#line 846 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
	goto st835;
tr1194:
#line 32 "mfilescanner.rl"
	{line++;}
#line 67 "mfilescanner.rl"
	{ cout.write(tmp_p, p - tmp_p); }
#line 835 "mfilescanner.rl"
	{ cout << "\n";}
#line 835 "mfilescanner.rl"
	{ {goto st786;} }
	goto st835;
tr1202:
#line 32 "mfilescanner.rl"
	{line++;}
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
#line 831 "mfilescanner.rl"
	{
            cout << "\n/** @var " << property_list_.back() << "\n" << " * ";
            cout.write(tmp_p, p-tmp_p);
            cout << "*/";
          }
#line 835 "mfilescanner.rl"
	{ {goto st786;} }
	goto st835;
st835:
	if ( ++p == pe )
		goto _test_eof835;
case 835:
#line 10359 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr1146;
		case 10: goto tr1147;
		case 13: goto tr1148;
		case 32: goto tr1146;
		case 37: goto st837;
		case 41: goto st0;
		case 44: goto st0;
		case 95: goto tr1150;
		case 101: goto tr1151;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1150;
	} else if ( (*p) >= 65 )
		goto tr1150;
	goto st834;
tr1146:
#line 846 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
	goto st836;
st836:
	if ( ++p == pe )
		goto _test_eof836;
case 836:
#line 10387 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st836;
		case 10: goto tr1145;
		case 32: goto st836;
		case 37: goto st837;
		case 41: goto st0;
		case 44: goto st0;
		case 95: goto tr1153;
		case 101: goto tr1154;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1153;
	} else if ( (*p) >= 65 )
		goto tr1153;
	goto st834;
st837:
	if ( ++p == pe )
		goto _test_eof837;
case 837:
	switch( (*p) ) {
		case 0: goto st834;
		case 10: goto tr1145;
		case 13: goto st834;
		case 41: goto st801;
		case 44: goto st801;
	}
	goto st837;
tr1153:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
#line 823 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            property_list_.push_back(s);
            cout << propertyparams_.ccprefix() << " " << s;
            }
	goto st838;
tr1157:
#line 823 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            property_list_.push_back(s);
            cout << propertyparams_.ccprefix() << " " << s;
            }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st838;
tr1150:
#line 846 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
#line 823 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            property_list_.push_back(s);
            cout << propertyparams_.ccprefix() << " " << s;
            }
	goto st838;
st838:
	if ( ++p == pe )
		goto _test_eof838;
case 838:
#line 10454 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr1156;
		case 41: goto tr1065;
		case 44: goto tr1065;
		case 59: goto tr1158;
		case 95: goto tr1157;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr1157;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1157;
	} else
		goto tr1157;
	goto tr1155;
tr1155:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st839;
tr1164:
#line 846 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
	goto st839;
st839:
	if ( ++p == pe )
		goto _test_eof839;
case 839:
#line 10485 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr1160;
		case 41: goto st792;
		case 44: goto st792;
		case 59: goto st861;
	}
	goto st839;
tr1160:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st840;
tr1163:
#line 32 "mfilescanner.rl"
	{line++;}
#line 846 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
	goto st840;
tr1156:
#line 32 "mfilescanner.rl"
	{line++;}
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st840;
st840:
	if ( ++p == pe )
		goto _test_eof840;
case 840:
#line 10515 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr1162;
		case 10: goto tr1163;
		case 13: goto tr1164;
		case 32: goto tr1162;
		case 37: goto st842;
		case 41: goto st792;
		case 44: goto st792;
		case 59: goto st861;
		case 95: goto tr1150;
		case 101: goto tr1151;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1150;
	} else if ( (*p) >= 65 )
		goto tr1150;
	goto st839;
tr1162:
#line 846 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
	goto st841;
st841:
	if ( ++p == pe )
		goto _test_eof841;
case 841:
#line 10544 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st841;
		case 10: goto tr1160;
		case 32: goto st841;
		case 37: goto st842;
		case 41: goto st792;
		case 44: goto st792;
		case 59: goto st861;
		case 95: goto tr1153;
		case 101: goto tr1154;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1153;
	} else if ( (*p) >= 65 )
		goto tr1153;
	goto st839;
st842:
	if ( ++p == pe )
		goto _test_eof842;
case 842:
	switch( (*p) ) {
		case 0: goto st839;
		case 10: goto tr1160;
		case 13: goto st839;
		case 41: goto st843;
		case 44: goto st843;
		case 59: goto st855;
	}
	goto st842;
st843:
	if ( ++p == pe )
		goto _test_eof843;
case 843:
	switch( (*p) ) {
		case 0: goto st792;
		case 10: goto tr1169;
		case 13: goto st848;
		case 59: goto st849;
	}
	goto st843;
tr1169:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st844;
st844:
	if ( ++p == pe )
		goto _test_eof844;
case 844:
#line 10594 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr1172;
		case 10: goto tr1173;
		case 13: goto tr1174;
		case 32: goto tr1172;
		case 37: goto st843;
		case 59: goto st793;
		case 95: goto tr1057;
		case 101: goto tr1058;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1057;
	} else if ( (*p) >= 65 )
		goto tr1057;
	goto st792;
tr1172:
#line 846 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
	goto st845;
st845:
	if ( ++p == pe )
		goto _test_eof845;
case 845:
#line 10621 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st845;
		case 10: goto tr1176;
		case 13: goto st847;
		case 32: goto st845;
		case 37: goto st843;
		case 59: goto st793;
		case 95: goto tr1062;
		case 101: goto tr1063;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1062;
	} else if ( (*p) >= 65 )
		goto tr1062;
	goto st792;
tr1176:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st846;
tr1173:
#line 846 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
#line 32 "mfilescanner.rl"
	{line++;}
	goto st846;
st846:
	if ( ++p == pe )
		goto _test_eof846;
case 846:
#line 10654 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st846;
		case 10: goto tr1176;
		case 13: goto st847;
		case 32: goto st846;
		case 59: goto st793;
		case 95: goto tr1062;
		case 101: goto tr1063;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1062;
	} else if ( (*p) >= 65 )
		goto tr1062;
	goto st792;
tr1174:
#line 846 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
	goto st847;
st847:
	if ( ++p == pe )
		goto _test_eof847;
case 847:
#line 10680 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr1176;
		case 59: goto st793;
	}
	goto st792;
st848:
	if ( ++p == pe )
		goto _test_eof848;
case 848:
	switch( (*p) ) {
		case 10: goto tr1169;
		case 59: goto st793;
	}
	goto st792;
st849:
	if ( ++p == pe )
		goto _test_eof849;
case 849:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr1179;
		case 10: goto tr1180;
		case 13: goto tr1181;
		case 32: goto tr1179;
		case 37: goto tr1182;
	}
	goto st801;
tr1179:
#line 67 "mfilescanner.rl"
	{ cout.write(tmp_p, p - tmp_p); }
	goto st850;
st850:
	if ( ++p == pe )
		goto _test_eof850;
case 850:
#line 10716 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st850;
		case 10: goto tr1184;
		case 13: goto st851;
		case 32: goto st850;
		case 37: goto st852;
	}
	goto st801;
tr1181:
#line 67 "mfilescanner.rl"
	{ cout.write(tmp_p, p - tmp_p); }
	goto st851;
st851:
	if ( ++p == pe )
		goto _test_eof851;
case 851:
#line 10734 "mfilescanner.cc"
	if ( (*p) == 10 )
		goto tr1184;
	goto st0;
tr1182:
#line 67 "mfilescanner.rl"
	{ cout.write(tmp_p, p - tmp_p); }
	goto st852;
st852:
	if ( ++p == pe )
		goto _test_eof852;
case 852:
#line 10746 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1188;
		case 13: goto tr1189;
	}
	goto tr1187;
tr1187:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st853;
st853:
	if ( ++p == pe )
		goto _test_eof853;
case 853:
#line 10761 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1191;
		case 13: goto st854;
	}
	goto st853;
tr1189:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st854;
st854:
	if ( ++p == pe )
		goto _test_eof854;
case 854:
#line 10776 "mfilescanner.cc"
	if ( (*p) == 10 )
		goto tr1191;
	goto st0;
st855:
	if ( ++p == pe )
		goto _test_eof855;
case 855:
	switch( (*p) ) {
		case 0: goto st834;
		case 9: goto tr1193;
		case 10: goto tr1194;
		case 13: goto tr1195;
		case 32: goto tr1193;
		case 37: goto tr1196;
		case 41: goto st801;
		case 44: goto st801;
	}
	goto st837;
tr1193:
#line 67 "mfilescanner.rl"
	{ cout.write(tmp_p, p - tmp_p); }
	goto st856;
st856:
	if ( ++p == pe )
		goto _test_eof856;
case 856:
#line 10803 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st834;
		case 9: goto st856;
		case 10: goto tr1198;
		case 13: goto st857;
		case 32: goto st856;
		case 37: goto st858;
		case 41: goto st801;
		case 44: goto st801;
	}
	goto st837;
tr1195:
#line 67 "mfilescanner.rl"
	{ cout.write(tmp_p, p - tmp_p); }
	goto st857;
st857:
	if ( ++p == pe )
		goto _test_eof857;
case 857:
#line 10823 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr1198;
		case 41: goto st0;
		case 44: goto st0;
	}
	goto st834;
tr1196:
#line 67 "mfilescanner.rl"
	{ cout.write(tmp_p, p - tmp_p); }
	goto st858;
st858:
	if ( ++p == pe )
		goto _test_eof858;
case 858:
#line 10838 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st834;
		case 10: goto tr1202;
		case 13: goto tr1203;
		case 41: goto tr1187;
		case 44: goto tr1187;
	}
	goto tr1201;
tr1201:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st859;
st859:
	if ( ++p == pe )
		goto _test_eof859;
case 859:
#line 10855 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st834;
		case 10: goto tr1205;
		case 13: goto st860;
		case 41: goto st853;
		case 44: goto st853;
	}
	goto st859;
tr1203:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st860;
st860:
	if ( ++p == pe )
		goto _test_eof860;
case 860:
#line 10872 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr1205;
		case 41: goto st0;
		case 44: goto st0;
	}
	goto st834;
tr1158:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st861;
st861:
	if ( ++p == pe )
		goto _test_eof861;
case 861:
#line 10887 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr1207;
		case 10: goto tr1194;
		case 13: goto tr1195;
		case 32: goto tr1207;
		case 37: goto tr1208;
		case 41: goto st0;
		case 44: goto st0;
	}
	goto st834;
tr1207:
#line 67 "mfilescanner.rl"
	{ cout.write(tmp_p, p - tmp_p); }
	goto st862;
st862:
	if ( ++p == pe )
		goto _test_eof862;
case 862:
#line 10906 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st862;
		case 10: goto tr1198;
		case 13: goto st857;
		case 32: goto st862;
		case 37: goto st863;
		case 41: goto st0;
		case 44: goto st0;
	}
	goto st834;
tr1208:
#line 67 "mfilescanner.rl"
	{ cout.write(tmp_p, p - tmp_p); }
	goto st863;
st863:
	if ( ++p == pe )
		goto _test_eof863;
case 863:
#line 10925 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st834;
		case 10: goto tr1202;
		case 13: goto tr1203;
		case 41: goto tr1078;
		case 44: goto tr1078;
	}
	goto tr1211;
tr1211:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st864;
st864:
	if ( ++p == pe )
		goto _test_eof864;
case 864:
#line 10942 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st834;
		case 10: goto tr1205;
		case 13: goto st860;
		case 41: goto st797;
		case 44: goto st797;
	}
	goto st864;
tr1154:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
#line 823 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            property_list_.push_back(s);
            cout << propertyparams_.ccprefix() << " " << s;
            }
	goto st865;
tr1151:
#line 846 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
#line 823 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            property_list_.push_back(s);
            cout << propertyparams_.ccprefix() << " " << s;
            }
	goto st865;
st865:
	if ( ++p == pe )
		goto _test_eof865;
case 865:
#line 10979 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr1156;
		case 41: goto tr1065;
		case 44: goto tr1065;
		case 59: goto tr1158;
		case 95: goto tr1157;
		case 110: goto tr1213;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr1157;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1157;
	} else
		goto tr1157;
	goto tr1155;
tr1213:
#line 823 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            property_list_.push_back(s);
            cout << propertyparams_.ccprefix() << " " << s;
            }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st866;
st866:
	if ( ++p == pe )
		goto _test_eof866;
case 866:
#line 11011 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr1156;
		case 41: goto tr1065;
		case 44: goto tr1065;
		case 59: goto tr1158;
		case 95: goto tr1157;
		case 100: goto tr1214;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr1157;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1157;
	} else
		goto tr1157;
	goto tr1155;
tr1214:
#line 823 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            property_list_.push_back(s);
            cout << propertyparams_.ccprefix() << " " << s;
            }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st1664;
st1664:
	if ( ++p == pe )
		goto _test_eof1664;
case 1664:
#line 11043 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr1156;
		case 41: goto tr1065;
		case 44: goto tr1065;
		case 59: goto tr2287;
		case 95: goto tr1157;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr1157;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1157;
	} else
		goto tr1157;
	goto tr1155;
tr2287:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
#line 850 "mfilescanner.rl"
	{
         {goto st1668;}
       }
	goto st1665;
st1665:
	if ( ++p == pe )
		goto _test_eof1665;
case 1665:
#line 11072 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr1207;
		case 10: goto tr1194;
		case 13: goto tr1195;
		case 32: goto tr1207;
		case 37: goto tr1208;
		case 41: goto st0;
		case 44: goto st0;
	}
	goto st834;
st867:
	if ( ++p == pe )
		goto _test_eof867;
case 867:
	if ( (*p) == 99 )
		goto st868;
	goto st0;
st868:
	if ( ++p == pe )
		goto _test_eof868;
case 868:
	if ( (*p) == 101 )
		goto st869;
	goto st0;
st869:
	if ( ++p == pe )
		goto _test_eof869;
case 869:
	if ( (*p) == 115 )
		goto st870;
	goto st0;
st870:
	if ( ++p == pe )
		goto _test_eof870;
case 870:
	if ( (*p) == 115 )
		goto st871;
	goto st0;
tr1226:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st871;
tr1223:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st871;
st871:
	if ( ++p == pe )
		goto _test_eof871;
case 871:
#line 11128 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st871;
		case 32: goto st871;
		case 37: goto tr1219;
		case 46: goto st873;
		case 61: goto st877;
	}
	goto st0;
tr1219:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st872;
st872:
	if ( ++p == pe )
		goto _test_eof872;
case 872:
#line 11145 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1223;
	}
	goto st872;
st873:
	if ( ++p == pe )
		goto _test_eof873;
case 873:
	if ( (*p) == 46 )
		goto st874;
	goto st0;
st874:
	if ( ++p == pe )
		goto _test_eof874;
case 874:
	if ( (*p) == 46 )
		goto st875;
	goto st0;
st875:
	if ( ++p == pe )
		goto _test_eof875;
case 875:
	switch( (*p) ) {
		case 9: goto st875;
		case 10: goto tr1226;
		case 13: goto st876;
		case 32: goto st875;
	}
	goto st0;
st876:
	if ( ++p == pe )
		goto _test_eof876;
case 876:
	if ( (*p) == 10 )
		goto tr1226;
	goto st0;
st877:
	if ( ++p == pe )
		goto _test_eof877;
case 877:
	switch( (*p) ) {
		case 9: goto st878;
		case 32: goto st878;
		case 37: goto tr1229;
		case 46: goto st900;
	}
	goto st0;
st878:
	if ( ++p == pe )
		goto _test_eof878;
case 878:
	switch( (*p) ) {
		case 9: goto st878;
		case 32: goto st878;
		case 112: goto st879;
	}
	goto st0;
st879:
	if ( ++p == pe )
		goto _test_eof879;
case 879:
	switch( (*p) ) {
		case 114: goto st880;
		case 117: goto st893;
	}
	goto st0;
st880:
	if ( ++p == pe )
		goto _test_eof880;
case 880:
	switch( (*p) ) {
		case 105: goto st881;
		case 111: goto st886;
	}
	goto st0;
st881:
	if ( ++p == pe )
		goto _test_eof881;
case 881:
	if ( (*p) == 118 )
		goto st882;
	goto st0;
st882:
	if ( ++p == pe )
		goto _test_eof882;
case 882:
	if ( (*p) == 97 )
		goto st883;
	goto st0;
st883:
	if ( ++p == pe )
		goto _test_eof883;
case 883:
	if ( (*p) == 116 )
		goto st884;
	goto st0;
st884:
	if ( ++p == pe )
		goto _test_eof884;
case 884:
	if ( (*p) == 101 )
		goto st885;
	goto st0;
st885:
	if ( ++p == pe )
		goto _test_eof885;
case 885:
	switch( (*p) ) {
		case 10: goto tr1240;
		case 13: goto tr1241;
	}
	goto st0;
st886:
	if ( ++p == pe )
		goto _test_eof886;
case 886:
	if ( (*p) == 116 )
		goto st887;
	goto st0;
st887:
	if ( ++p == pe )
		goto _test_eof887;
case 887:
	if ( (*p) == 101 )
		goto st888;
	goto st0;
st888:
	if ( ++p == pe )
		goto _test_eof888;
case 888:
	if ( (*p) == 99 )
		goto st889;
	goto st0;
st889:
	if ( ++p == pe )
		goto _test_eof889;
case 889:
	if ( (*p) == 116 )
		goto st890;
	goto st0;
st890:
	if ( ++p == pe )
		goto _test_eof890;
case 890:
	if ( (*p) == 101 )
		goto st891;
	goto st0;
st891:
	if ( ++p == pe )
		goto _test_eof891;
case 891:
	if ( (*p) == 100 )
		goto st892;
	goto st0;
st892:
	if ( ++p == pe )
		goto _test_eof892;
case 892:
	switch( (*p) ) {
		case 10: goto tr1248;
		case 13: goto tr1249;
	}
	goto st0;
st893:
	if ( ++p == pe )
		goto _test_eof893;
case 893:
	if ( (*p) == 98 )
		goto st894;
	goto st0;
st894:
	if ( ++p == pe )
		goto _test_eof894;
case 894:
	if ( (*p) == 108 )
		goto st895;
	goto st0;
st895:
	if ( ++p == pe )
		goto _test_eof895;
case 895:
	if ( (*p) == 105 )
		goto st896;
	goto st0;
st896:
	if ( ++p == pe )
		goto _test_eof896;
case 896:
	if ( (*p) == 99 )
		goto st897;
	goto st0;
st897:
	if ( ++p == pe )
		goto _test_eof897;
case 897:
	switch( (*p) ) {
		case 10: goto tr1254;
		case 13: goto tr1255;
	}
	goto st0;
tr1229:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st898;
st898:
	if ( ++p == pe )
		goto _test_eof898;
case 898:
#line 11355 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1257;
	}
	goto st898;
tr1260:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st899;
tr1257:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st899;
st899:
	if ( ++p == pe )
		goto _test_eof899;
case 899:
#line 11378 "mfilescanner.cc"
	if ( (*p) == 112 )
		goto st879;
	goto st0;
st900:
	if ( ++p == pe )
		goto _test_eof900;
case 900:
	if ( (*p) == 46 )
		goto st901;
	goto st0;
st901:
	if ( ++p == pe )
		goto _test_eof901;
case 901:
	if ( (*p) == 46 )
		goto st902;
	goto st0;
st902:
	if ( ++p == pe )
		goto _test_eof902;
case 902:
	switch( (*p) ) {
		case 9: goto st902;
		case 10: goto tr1260;
		case 13: goto st903;
		case 32: goto st902;
	}
	goto st0;
st903:
	if ( ++p == pe )
		goto _test_eof903;
case 903:
	if ( (*p) == 10 )
		goto tr1260;
	goto st0;
st904:
	if ( ++p == pe )
		goto _test_eof904;
case 904:
	if ( (*p) == 111 )
		goto st905;
	goto st0;
st905:
	if ( ++p == pe )
		goto _test_eof905;
case 905:
	if ( (*p) == 110 )
		goto st906;
	goto st0;
st906:
	if ( ++p == pe )
		goto _test_eof906;
case 906:
	if ( (*p) == 115 )
		goto st907;
	goto st0;
st907:
	if ( ++p == pe )
		goto _test_eof907;
case 907:
	if ( (*p) == 116 )
		goto st908;
	goto st0;
st908:
	if ( ++p == pe )
		goto _test_eof908;
case 908:
	if ( (*p) == 97 )
		goto st909;
	goto st0;
st909:
	if ( ++p == pe )
		goto _test_eof909;
case 909:
	if ( (*p) == 110 )
		goto st910;
	goto st0;
st910:
	if ( ++p == pe )
		goto _test_eof910;
case 910:
	if ( (*p) == 116 )
		goto tr1268;
	goto st0;
tr1268:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
	goto st911;
tr1272:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 846 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
	goto st911;
st911:
	if ( ++p == pe )
		goto _test_eof911;
case 911:
#line 11483 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr1269;
		case 41: goto st0;
		case 44: goto st0;
	}
	goto tr1268;
tr1269:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 32 "mfilescanner.rl"
	{line++;}
	goto st912;
tr1271:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 32 "mfilescanner.rl"
	{line++;}
#line 846 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
	goto st912;
tr1293:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 32 "mfilescanner.rl"
	{line++;}
#line 67 "mfilescanner.rl"
	{ cout.write(tmp_p, p - tmp_p); }
#line 835 "mfilescanner.rl"
	{ cout << "\n";}
#line 835 "mfilescanner.rl"
	{ {goto st786;} }
	goto st912;
tr1297:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 32 "mfilescanner.rl"
	{line++;}
#line 835 "mfilescanner.rl"
	{ cout << "\n";}
#line 835 "mfilescanner.rl"
	{ {goto st786;} }
	goto st912;
tr1301:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 32 "mfilescanner.rl"
	{line++;}
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
#line 831 "mfilescanner.rl"
	{
            cout << "\n/** @var " << property_list_.back() << "\n" << " * ";
            cout.write(tmp_p, p-tmp_p);
            cout << "*/";
          }
#line 835 "mfilescanner.rl"
	{ {goto st786;} }
	goto st912;
tr1304:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 32 "mfilescanner.rl"
	{line++;}
#line 831 "mfilescanner.rl"
	{
            cout << "\n/** @var " << property_list_.back() << "\n" << " * ";
            cout.write(tmp_p, p-tmp_p);
            cout << "*/";
          }
#line 835 "mfilescanner.rl"
	{ {goto st786;} }
	goto st912;
st912:
	if ( ++p == pe )
		goto _test_eof912;
case 912:
#line 11574 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr1270;
		case 10: goto tr1271;
		case 13: goto tr1272;
		case 32: goto tr1270;
		case 37: goto tr1273;
		case 41: goto st0;
		case 44: goto st0;
		case 95: goto tr1274;
		case 101: goto tr1275;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1274;
	} else if ( (*p) >= 65 )
		goto tr1274;
	goto tr1268;
tr1276:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
	goto st913;
tr1270:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 846 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
	goto st913;
st913:
	if ( ++p == pe )
		goto _test_eof913;
case 913:
#line 11612 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr1276;
		case 10: goto tr1269;
		case 32: goto tr1276;
		case 37: goto tr1273;
		case 41: goto st0;
		case 44: goto st0;
		case 95: goto tr1277;
		case 101: goto tr1278;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1277;
	} else if ( (*p) >= 65 )
		goto tr1277;
	goto tr1268;
tr1273:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
	goto st914;
st914:
	if ( ++p == pe )
		goto _test_eof914;
case 914:
#line 11639 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr1268;
		case 10: goto tr1269;
		case 13: goto tr1268;
		case 41: goto st801;
		case 44: goto st801;
	}
	goto tr1273;
tr1274:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 846 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
#line 823 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            property_list_.push_back(s);
            cout << propertyparams_.ccprefix() << " " << s;
            }
	goto st915;
tr1277:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
#line 823 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            property_list_.push_back(s);
            cout << propertyparams_.ccprefix() << " " << s;
            }
	goto st915;
tr1281:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 823 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            property_list_.push_back(s);
            cout << propertyparams_.ccprefix() << " " << s;
            }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st915;
st915:
	if ( ++p == pe )
		goto _test_eof915;
case 915:
#line 11698 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr1280;
		case 41: goto tr1065;
		case 44: goto tr1065;
		case 59: goto tr1282;
		case 95: goto tr1281;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr1281;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1281;
	} else
		goto tr1281;
	goto tr1279;
tr1283:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
	goto st916;
tr1288:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 846 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
	goto st916;
tr1279:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st916;
st916:
	if ( ++p == pe )
		goto _test_eof916;
case 916:
#line 11743 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr1284;
		case 41: goto st792;
		case 44: goto st792;
		case 59: goto tr1285;
	}
	goto tr1283;
tr1284:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 32 "mfilescanner.rl"
	{line++;}
	goto st917;
tr1287:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 32 "mfilescanner.rl"
	{line++;}
#line 846 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
	goto st917;
tr1280:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 32 "mfilescanner.rl"
	{line++;}
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st917;
st917:
	if ( ++p == pe )
		goto _test_eof917;
case 917:
#line 11785 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr1286;
		case 10: goto tr1287;
		case 13: goto tr1288;
		case 32: goto tr1286;
		case 37: goto tr1289;
		case 41: goto st792;
		case 44: goto st792;
		case 59: goto tr1285;
		case 95: goto tr1274;
		case 101: goto tr1275;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1274;
	} else if ( (*p) >= 65 )
		goto tr1274;
	goto tr1283;
tr1290:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
	goto st918;
tr1286:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 846 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
	goto st918;
st918:
	if ( ++p == pe )
		goto _test_eof918;
case 918:
#line 11824 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr1290;
		case 10: goto tr1284;
		case 32: goto tr1290;
		case 37: goto tr1289;
		case 41: goto st792;
		case 44: goto st792;
		case 59: goto tr1285;
		case 95: goto tr1277;
		case 101: goto tr1278;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1277;
	} else if ( (*p) >= 65 )
		goto tr1277;
	goto tr1283;
tr1289:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
	goto st919;
st919:
	if ( ++p == pe )
		goto _test_eof919;
case 919:
#line 11852 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr1283;
		case 10: goto tr1284;
		case 13: goto tr1283;
		case 41: goto st843;
		case 44: goto st843;
		case 59: goto tr1291;
	}
	goto tr1289;
tr1291:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
	goto st920;
st920:
	if ( ++p == pe )
		goto _test_eof920;
case 920:
#line 11872 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr1268;
		case 9: goto tr1292;
		case 10: goto tr1293;
		case 13: goto tr1294;
		case 32: goto tr1292;
		case 37: goto tr1295;
		case 41: goto st801;
		case 44: goto st801;
	}
	goto tr1273;
tr1296:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
	goto st921;
tr1292:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 67 "mfilescanner.rl"
	{ cout.write(tmp_p, p - tmp_p); }
	goto st921;
st921:
	if ( ++p == pe )
		goto _test_eof921;
case 921:
#line 11902 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr1268;
		case 9: goto tr1296;
		case 10: goto tr1297;
		case 13: goto tr1298;
		case 32: goto tr1296;
		case 37: goto tr1299;
		case 41: goto st801;
		case 44: goto st801;
	}
	goto tr1273;
tr1298:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
	goto st922;
tr1294:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 67 "mfilescanner.rl"
	{ cout.write(tmp_p, p - tmp_p); }
	goto st922;
st922:
	if ( ++p == pe )
		goto _test_eof922;
case 922:
#line 11932 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr1297;
		case 41: goto st0;
		case 44: goto st0;
	}
	goto tr1268;
tr1299:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
	goto st923;
tr1295:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 67 "mfilescanner.rl"
	{ cout.write(tmp_p, p - tmp_p); }
	goto st923;
st923:
	if ( ++p == pe )
		goto _test_eof923;
case 923:
#line 11957 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr1268;
		case 10: goto tr1301;
		case 13: goto tr1302;
		case 41: goto tr1187;
		case 44: goto tr1187;
	}
	goto tr1300;
tr1303:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
	goto st924;
tr1300:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st924;
st924:
	if ( ++p == pe )
		goto _test_eof924;
case 924:
#line 11984 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr1268;
		case 10: goto tr1304;
		case 13: goto tr1305;
		case 41: goto st853;
		case 44: goto st853;
	}
	goto tr1303;
tr1305:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
	goto st925;
tr1302:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st925;
st925:
	if ( ++p == pe )
		goto _test_eof925;
case 925:
#line 12011 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr1304;
		case 41: goto st0;
		case 44: goto st0;
	}
	goto tr1268;
tr1285:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
	goto st926;
tr1282:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st926;
st926:
	if ( ++p == pe )
		goto _test_eof926;
case 926:
#line 12036 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr1306;
		case 10: goto tr1293;
		case 13: goto tr1294;
		case 32: goto tr1306;
		case 37: goto tr1307;
		case 41: goto st0;
		case 44: goto st0;
	}
	goto tr1268;
tr1308:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
	goto st927;
tr1306:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 67 "mfilescanner.rl"
	{ cout.write(tmp_p, p - tmp_p); }
	goto st927;
st927:
	if ( ++p == pe )
		goto _test_eof927;
case 927:
#line 12065 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr1308;
		case 10: goto tr1297;
		case 13: goto tr1298;
		case 32: goto tr1308;
		case 37: goto tr1309;
		case 41: goto st0;
		case 44: goto st0;
	}
	goto tr1268;
tr1309:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
	goto st928;
tr1307:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 67 "mfilescanner.rl"
	{ cout.write(tmp_p, p - tmp_p); }
	goto st928;
st928:
	if ( ++p == pe )
		goto _test_eof928;
case 928:
#line 12094 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr1268;
		case 10: goto tr1301;
		case 13: goto tr1302;
		case 41: goto tr1078;
		case 44: goto tr1078;
	}
	goto tr1310;
tr1311:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
	goto st929;
tr1310:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st929;
st929:
	if ( ++p == pe )
		goto _test_eof929;
case 929:
#line 12121 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr1268;
		case 10: goto tr1304;
		case 13: goto tr1305;
		case 41: goto st797;
		case 44: goto st797;
	}
	goto tr1311;
tr1275:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 846 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
#line 823 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            property_list_.push_back(s);
            cout << propertyparams_.ccprefix() << " " << s;
            }
	goto st930;
tr1278:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
#line 823 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            property_list_.push_back(s);
            cout << propertyparams_.ccprefix() << " " << s;
            }
	goto st930;
st930:
	if ( ++p == pe )
		goto _test_eof930;
case 930:
#line 12166 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr1280;
		case 41: goto tr1065;
		case 44: goto tr1065;
		case 59: goto tr1282;
		case 95: goto tr1281;
		case 110: goto tr1312;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr1281;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1281;
	} else
		goto tr1281;
	goto tr1279;
tr1312:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 823 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            property_list_.push_back(s);
            cout << propertyparams_.ccprefix() << " " << s;
            }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st931;
st931:
	if ( ++p == pe )
		goto _test_eof931;
case 931:
#line 12202 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr1280;
		case 41: goto tr1065;
		case 44: goto tr1065;
		case 59: goto tr1282;
		case 95: goto tr1281;
		case 100: goto tr1313;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr1281;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1281;
	} else
		goto tr1281;
	goto tr1279;
tr1313:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 823 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            property_list_.push_back(s);
            cout << propertyparams_.ccprefix() << " " << s;
            }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st1666;
st1666:
	if ( ++p == pe )
		goto _test_eof1666;
case 1666:
#line 12238 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr1280;
		case 41: goto tr1065;
		case 44: goto tr1065;
		case 59: goto tr2288;
		case 95: goto tr1281;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr1281;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1281;
	} else
		goto tr1281;
	goto tr1279;
tr2288:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
#line 850 "mfilescanner.rl"
	{
         {goto st1668;}
       }
	goto st1667;
st1667:
	if ( ++p == pe )
		goto _test_eof1667;
case 1667:
#line 12271 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr1306;
		case 10: goto tr1293;
		case 13: goto tr1294;
		case 32: goto tr1306;
		case 37: goto tr1307;
		case 41: goto st0;
		case 44: goto st0;
	}
	goto tr1268;
st932:
	if ( ++p == pe )
		goto _test_eof932;
case 932:
	if ( (*p) == 101 )
		goto st933;
	goto st0;
st933:
	if ( ++p == pe )
		goto _test_eof933;
case 933:
	if ( (*p) == 112 )
		goto st934;
	goto st0;
st934:
	if ( ++p == pe )
		goto _test_eof934;
case 934:
	if ( (*p) == 101 )
		goto st935;
	goto st0;
st935:
	if ( ++p == pe )
		goto _test_eof935;
case 935:
	if ( (*p) == 110 )
		goto st936;
	goto st0;
st936:
	if ( ++p == pe )
		goto _test_eof936;
case 936:
	if ( (*p) == 100 )
		goto st937;
	goto st0;
st937:
	if ( ++p == pe )
		goto _test_eof937;
case 937:
	if ( (*p) == 101 )
		goto st938;
	goto st0;
st938:
	if ( ++p == pe )
		goto _test_eof938;
case 938:
	if ( (*p) == 110 )
		goto st833;
	goto st0;
st939:
	if ( ++p == pe )
		goto _test_eof939;
case 939:
	if ( (*p) == 101 )
		goto st940;
	goto st0;
st940:
	if ( ++p == pe )
		goto _test_eof940;
case 940:
	if ( (*p) == 116 )
		goto st941;
	goto st0;
st941:
	if ( ++p == pe )
		goto _test_eof941;
case 941:
	if ( (*p) == 65 )
		goto st942;
	goto st0;
st942:
	if ( ++p == pe )
		goto _test_eof942;
case 942:
	if ( (*p) == 99 )
		goto st943;
	goto st0;
st943:
	if ( ++p == pe )
		goto _test_eof943;
case 943:
	if ( (*p) == 99 )
		goto st944;
	goto st0;
st944:
	if ( ++p == pe )
		goto _test_eof944;
case 944:
	if ( (*p) == 101 )
		goto st945;
	goto st0;
st945:
	if ( ++p == pe )
		goto _test_eof945;
case 945:
	if ( (*p) == 115 )
		goto st946;
	goto st0;
st946:
	if ( ++p == pe )
		goto _test_eof946;
case 946:
	if ( (*p) == 115 )
		goto st947;
	goto st0;
tr1335:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st947;
tr1332:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st947;
st947:
	if ( ++p == pe )
		goto _test_eof947;
case 947:
#line 12404 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st947;
		case 32: goto st947;
		case 37: goto tr1328;
		case 46: goto st949;
		case 61: goto st953;
	}
	goto st0;
tr1328:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st948;
st948:
	if ( ++p == pe )
		goto _test_eof948;
case 948:
#line 12421 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1332;
	}
	goto st948;
st949:
	if ( ++p == pe )
		goto _test_eof949;
case 949:
	if ( (*p) == 46 )
		goto st950;
	goto st0;
st950:
	if ( ++p == pe )
		goto _test_eof950;
case 950:
	if ( (*p) == 46 )
		goto st951;
	goto st0;
st951:
	if ( ++p == pe )
		goto _test_eof951;
case 951:
	switch( (*p) ) {
		case 9: goto st951;
		case 10: goto tr1335;
		case 13: goto st952;
		case 32: goto st951;
	}
	goto st0;
st952:
	if ( ++p == pe )
		goto _test_eof952;
case 952:
	if ( (*p) == 10 )
		goto tr1335;
	goto st0;
st953:
	if ( ++p == pe )
		goto _test_eof953;
case 953:
	switch( (*p) ) {
		case 9: goto st954;
		case 32: goto st954;
		case 37: goto tr1338;
		case 46: goto st976;
	}
	goto st0;
st954:
	if ( ++p == pe )
		goto _test_eof954;
case 954:
	switch( (*p) ) {
		case 9: goto st954;
		case 32: goto st954;
		case 112: goto st955;
	}
	goto st0;
st955:
	if ( ++p == pe )
		goto _test_eof955;
case 955:
	switch( (*p) ) {
		case 114: goto st956;
		case 117: goto st969;
	}
	goto st0;
st956:
	if ( ++p == pe )
		goto _test_eof956;
case 956:
	switch( (*p) ) {
		case 105: goto st957;
		case 111: goto st962;
	}
	goto st0;
st957:
	if ( ++p == pe )
		goto _test_eof957;
case 957:
	if ( (*p) == 118 )
		goto st958;
	goto st0;
st958:
	if ( ++p == pe )
		goto _test_eof958;
case 958:
	if ( (*p) == 97 )
		goto st959;
	goto st0;
st959:
	if ( ++p == pe )
		goto _test_eof959;
case 959:
	if ( (*p) == 116 )
		goto st960;
	goto st0;
st960:
	if ( ++p == pe )
		goto _test_eof960;
case 960:
	if ( (*p) == 101 )
		goto st961;
	goto st0;
st961:
	if ( ++p == pe )
		goto _test_eof961;
case 961:
	switch( (*p) ) {
		case 10: goto tr1349;
		case 13: goto tr1350;
	}
	goto st0;
st962:
	if ( ++p == pe )
		goto _test_eof962;
case 962:
	if ( (*p) == 116 )
		goto st963;
	goto st0;
st963:
	if ( ++p == pe )
		goto _test_eof963;
case 963:
	if ( (*p) == 101 )
		goto st964;
	goto st0;
st964:
	if ( ++p == pe )
		goto _test_eof964;
case 964:
	if ( (*p) == 99 )
		goto st965;
	goto st0;
st965:
	if ( ++p == pe )
		goto _test_eof965;
case 965:
	if ( (*p) == 116 )
		goto st966;
	goto st0;
st966:
	if ( ++p == pe )
		goto _test_eof966;
case 966:
	if ( (*p) == 101 )
		goto st967;
	goto st0;
st967:
	if ( ++p == pe )
		goto _test_eof967;
case 967:
	if ( (*p) == 100 )
		goto st968;
	goto st0;
st968:
	if ( ++p == pe )
		goto _test_eof968;
case 968:
	switch( (*p) ) {
		case 10: goto tr1357;
		case 13: goto tr1358;
	}
	goto st0;
st969:
	if ( ++p == pe )
		goto _test_eof969;
case 969:
	if ( (*p) == 98 )
		goto st970;
	goto st0;
st970:
	if ( ++p == pe )
		goto _test_eof970;
case 970:
	if ( (*p) == 108 )
		goto st971;
	goto st0;
st971:
	if ( ++p == pe )
		goto _test_eof971;
case 971:
	if ( (*p) == 105 )
		goto st972;
	goto st0;
st972:
	if ( ++p == pe )
		goto _test_eof972;
case 972:
	if ( (*p) == 99 )
		goto st973;
	goto st0;
st973:
	if ( ++p == pe )
		goto _test_eof973;
case 973:
	switch( (*p) ) {
		case 10: goto tr1363;
		case 13: goto tr1364;
	}
	goto st0;
tr1338:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st974;
st974:
	if ( ++p == pe )
		goto _test_eof974;
case 974:
#line 12631 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1366;
	}
	goto st974;
tr1369:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st975;
tr1366:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st975;
st975:
	if ( ++p == pe )
		goto _test_eof975;
case 975:
#line 12654 "mfilescanner.cc"
	if ( (*p) == 112 )
		goto st955;
	goto st0;
st976:
	if ( ++p == pe )
		goto _test_eof976;
case 976:
	if ( (*p) == 46 )
		goto st977;
	goto st0;
st977:
	if ( ++p == pe )
		goto _test_eof977;
case 977:
	if ( (*p) == 46 )
		goto st978;
	goto st0;
st978:
	if ( ++p == pe )
		goto _test_eof978;
case 978:
	switch( (*p) ) {
		case 9: goto st978;
		case 10: goto tr1369;
		case 13: goto st979;
		case 32: goto st978;
	}
	goto st0;
st979:
	if ( ++p == pe )
		goto _test_eof979;
case 979:
	if ( (*p) == 10 )
		goto tr1369;
	goto st0;
st980:
	if ( ++p == pe )
		goto _test_eof980;
case 980:
	if ( (*p) == 105 )
		goto st981;
	goto st0;
st981:
	if ( ++p == pe )
		goto _test_eof981;
case 981:
	if ( (*p) == 100 )
		goto st982;
	goto st0;
st982:
	if ( ++p == pe )
		goto _test_eof982;
case 982:
	if ( (*p) == 100 )
		goto st983;
	goto st0;
st983:
	if ( ++p == pe )
		goto _test_eof983;
case 983:
	if ( (*p) == 101 )
		goto st984;
	goto st0;
st984:
	if ( ++p == pe )
		goto _test_eof984;
case 984:
	if ( (*p) == 110 )
		goto st834;
	goto st0;
st985:
	if ( ++p == pe )
		goto _test_eof985;
case 985:
	if ( (*p) == 101 )
		goto st986;
	goto st0;
st986:
	if ( ++p == pe )
		goto _test_eof986;
case 986:
	if ( (*p) == 116 )
		goto st987;
	goto st0;
st987:
	if ( ++p == pe )
		goto _test_eof987;
case 987:
	switch( (*p) ) {
		case 65: goto st988;
		case 79: goto st1026;
	}
	goto st0;
st988:
	if ( ++p == pe )
		goto _test_eof988;
case 988:
	if ( (*p) == 99 )
		goto st989;
	goto st0;
st989:
	if ( ++p == pe )
		goto _test_eof989;
case 989:
	if ( (*p) == 99 )
		goto st990;
	goto st0;
st990:
	if ( ++p == pe )
		goto _test_eof990;
case 990:
	if ( (*p) == 101 )
		goto st991;
	goto st0;
st991:
	if ( ++p == pe )
		goto _test_eof991;
case 991:
	if ( (*p) == 115 )
		goto st992;
	goto st0;
st992:
	if ( ++p == pe )
		goto _test_eof992;
case 992:
	if ( (*p) == 115 )
		goto st993;
	goto st0;
tr1391:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st993;
tr1388:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st993;
st993:
	if ( ++p == pe )
		goto _test_eof993;
case 993:
#line 12800 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st993;
		case 32: goto st993;
		case 37: goto tr1384;
		case 46: goto st995;
		case 61: goto st999;
	}
	goto st0;
tr1384:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st994;
st994:
	if ( ++p == pe )
		goto _test_eof994;
case 994:
#line 12817 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1388;
	}
	goto st994;
st995:
	if ( ++p == pe )
		goto _test_eof995;
case 995:
	if ( (*p) == 46 )
		goto st996;
	goto st0;
st996:
	if ( ++p == pe )
		goto _test_eof996;
case 996:
	if ( (*p) == 46 )
		goto st997;
	goto st0;
st997:
	if ( ++p == pe )
		goto _test_eof997;
case 997:
	switch( (*p) ) {
		case 9: goto st997;
		case 10: goto tr1391;
		case 13: goto st998;
		case 32: goto st997;
	}
	goto st0;
st998:
	if ( ++p == pe )
		goto _test_eof998;
case 998:
	if ( (*p) == 10 )
		goto tr1391;
	goto st0;
st999:
	if ( ++p == pe )
		goto _test_eof999;
case 999:
	switch( (*p) ) {
		case 9: goto st1000;
		case 32: goto st1000;
		case 37: goto tr1394;
		case 46: goto st1022;
	}
	goto st0;
st1000:
	if ( ++p == pe )
		goto _test_eof1000;
case 1000:
	switch( (*p) ) {
		case 9: goto st1000;
		case 32: goto st1000;
		case 112: goto st1001;
	}
	goto st0;
st1001:
	if ( ++p == pe )
		goto _test_eof1001;
case 1001:
	switch( (*p) ) {
		case 114: goto st1002;
		case 117: goto st1015;
	}
	goto st0;
st1002:
	if ( ++p == pe )
		goto _test_eof1002;
case 1002:
	switch( (*p) ) {
		case 105: goto st1003;
		case 111: goto st1008;
	}
	goto st0;
st1003:
	if ( ++p == pe )
		goto _test_eof1003;
case 1003:
	if ( (*p) == 118 )
		goto st1004;
	goto st0;
st1004:
	if ( ++p == pe )
		goto _test_eof1004;
case 1004:
	if ( (*p) == 97 )
		goto st1005;
	goto st0;
st1005:
	if ( ++p == pe )
		goto _test_eof1005;
case 1005:
	if ( (*p) == 116 )
		goto st1006;
	goto st0;
st1006:
	if ( ++p == pe )
		goto _test_eof1006;
case 1006:
	if ( (*p) == 101 )
		goto st1007;
	goto st0;
st1007:
	if ( ++p == pe )
		goto _test_eof1007;
case 1007:
	switch( (*p) ) {
		case 10: goto tr1405;
		case 13: goto tr1406;
	}
	goto st0;
st1008:
	if ( ++p == pe )
		goto _test_eof1008;
case 1008:
	if ( (*p) == 116 )
		goto st1009;
	goto st0;
st1009:
	if ( ++p == pe )
		goto _test_eof1009;
case 1009:
	if ( (*p) == 101 )
		goto st1010;
	goto st0;
st1010:
	if ( ++p == pe )
		goto _test_eof1010;
case 1010:
	if ( (*p) == 99 )
		goto st1011;
	goto st0;
st1011:
	if ( ++p == pe )
		goto _test_eof1011;
case 1011:
	if ( (*p) == 116 )
		goto st1012;
	goto st0;
st1012:
	if ( ++p == pe )
		goto _test_eof1012;
case 1012:
	if ( (*p) == 101 )
		goto st1013;
	goto st0;
st1013:
	if ( ++p == pe )
		goto _test_eof1013;
case 1013:
	if ( (*p) == 100 )
		goto st1014;
	goto st0;
st1014:
	if ( ++p == pe )
		goto _test_eof1014;
case 1014:
	switch( (*p) ) {
		case 10: goto tr1413;
		case 13: goto tr1414;
	}
	goto st0;
st1015:
	if ( ++p == pe )
		goto _test_eof1015;
case 1015:
	if ( (*p) == 98 )
		goto st1016;
	goto st0;
st1016:
	if ( ++p == pe )
		goto _test_eof1016;
case 1016:
	if ( (*p) == 108 )
		goto st1017;
	goto st0;
st1017:
	if ( ++p == pe )
		goto _test_eof1017;
case 1017:
	if ( (*p) == 105 )
		goto st1018;
	goto st0;
st1018:
	if ( ++p == pe )
		goto _test_eof1018;
case 1018:
	if ( (*p) == 99 )
		goto st1019;
	goto st0;
st1019:
	if ( ++p == pe )
		goto _test_eof1019;
case 1019:
	switch( (*p) ) {
		case 10: goto tr1419;
		case 13: goto tr1420;
	}
	goto st0;
tr1394:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1020;
st1020:
	if ( ++p == pe )
		goto _test_eof1020;
case 1020:
#line 13027 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1422;
	}
	goto st1020;
tr1425:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st1021;
tr1422:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st1021;
st1021:
	if ( ++p == pe )
		goto _test_eof1021;
case 1021:
#line 13050 "mfilescanner.cc"
	if ( (*p) == 112 )
		goto st1001;
	goto st0;
st1022:
	if ( ++p == pe )
		goto _test_eof1022;
case 1022:
	if ( (*p) == 46 )
		goto st1023;
	goto st0;
st1023:
	if ( ++p == pe )
		goto _test_eof1023;
case 1023:
	if ( (*p) == 46 )
		goto st1024;
	goto st0;
st1024:
	if ( ++p == pe )
		goto _test_eof1024;
case 1024:
	switch( (*p) ) {
		case 9: goto st1024;
		case 10: goto tr1425;
		case 13: goto st1025;
		case 32: goto st1024;
	}
	goto st0;
st1025:
	if ( ++p == pe )
		goto _test_eof1025;
case 1025:
	if ( (*p) == 10 )
		goto tr1425;
	goto st0;
st1026:
	if ( ++p == pe )
		goto _test_eof1026;
case 1026:
	if ( (*p) == 98 )
		goto st1027;
	goto st0;
st1027:
	if ( ++p == pe )
		goto _test_eof1027;
case 1027:
	if ( (*p) == 115 )
		goto st1028;
	goto st0;
st1028:
	if ( ++p == pe )
		goto _test_eof1028;
case 1028:
	if ( (*p) == 101 )
		goto st1029;
	goto st0;
st1029:
	if ( ++p == pe )
		goto _test_eof1029;
case 1029:
	if ( (*p) == 114 )
		goto st1030;
	goto st0;
st1030:
	if ( ++p == pe )
		goto _test_eof1030;
case 1030:
	if ( (*p) == 118 )
		goto st1031;
	goto st0;
st1031:
	if ( ++p == pe )
		goto _test_eof1031;
case 1031:
	if ( (*p) == 97 )
		goto st1032;
	goto st0;
st1032:
	if ( ++p == pe )
		goto _test_eof1032;
case 1032:
	if ( (*p) == 98 )
		goto st1033;
	goto st0;
st1033:
	if ( ++p == pe )
		goto _test_eof1033;
case 1033:
	if ( (*p) == 108 )
		goto st1034;
	goto st0;
st1034:
	if ( ++p == pe )
		goto _test_eof1034;
case 1034:
	if ( (*p) == 101 )
		goto st834;
	goto st0;
st1035:
	if ( ++p == pe )
		goto _test_eof1035;
case 1035:
	if ( (*p) == 114 )
		goto st1036;
	goto st0;
st1036:
	if ( ++p == pe )
		goto _test_eof1036;
case 1036:
	if ( (*p) == 97 )
		goto st1037;
	goto st0;
st1037:
	if ( ++p == pe )
		goto _test_eof1037;
case 1037:
	if ( (*p) == 110 )
		goto st1038;
	goto st0;
st1038:
	if ( ++p == pe )
		goto _test_eof1038;
case 1038:
	if ( (*p) == 115 )
		goto st1039;
	goto st0;
st1039:
	if ( ++p == pe )
		goto _test_eof1039;
case 1039:
	if ( (*p) == 105 )
		goto st937;
	goto st0;
tr1721:
#line 745 "mfilescanner.rl"
	{ access_.full = Private;
               access_.get = Private;
               access_.set = Private;
             }
	goto st1040;
tr1731:
#line 740 "mfilescanner.rl"
	{ access_.full = Protected;
               access_.get = Protected;
               access_.set = Protected;
             }
	goto st1040;
tr1739:
#line 735 "mfilescanner.rl"
	{ access_.full = Public;
               access_.get = Public;
               access_.set = Public;
             }
	goto st1040;
tr1800:
#line 729 "mfilescanner.rl"
	{ access_.full = access_.set;
               access_.get = Private;
             }
	goto st1040;
tr1810:
#line 724 "mfilescanner.rl"
	{ access_.full =
                 (access_.set == Public ? Public : Protected );
               access_.get = Protected;
             }
	goto st1040;
tr1818:
#line 720 "mfilescanner.rl"
	{ access_.full = Public;
               access_.get = Public;
             }
	goto st1040;
tr1862:
#line 714 "mfilescanner.rl"
	{ access_.full = access_.get;
               access_.set = Private;
             }
	goto st1040;
tr1872:
#line 709 "mfilescanner.rl"
	{ access_.full =
                 (access_.get == Public ? Public : Protected );
               access_.set = Protected;
             }
	goto st1040;
tr1880:
#line 705 "mfilescanner.rl"
	{ access_.full = Public;
               access_.set = Public;
             }
	goto st1040;
st1040:
	if ( ++p == pe )
		goto _test_eof1040;
case 1040:
#line 13247 "mfilescanner.cc"
	if ( (*p) == 46 )
		goto st1041;
	goto st0;
st1041:
	if ( ++p == pe )
		goto _test_eof1041;
case 1041:
	if ( (*p) == 46 )
		goto st1042;
	goto st0;
st1042:
	if ( ++p == pe )
		goto _test_eof1042;
case 1042:
	switch( (*p) ) {
		case 9: goto st1042;
		case 10: goto tr1441;
		case 13: goto st1043;
		case 32: goto st1042;
	}
	goto st0;
st1043:
	if ( ++p == pe )
		goto _test_eof1043;
case 1043:
	if ( (*p) == 10 )
		goto tr1441;
	goto st0;
st1044:
	if ( ++p == pe )
		goto _test_eof1044;
case 1044:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1044;
		case 10: goto tr1118;
		case 32: goto st1044;
		case 37: goto tr1443;
		case 46: goto st1051;
		case 65: goto st1055;
		case 67: goto st1116;
		case 68: goto st1131;
		case 71: goto st1138;
		case 72: goto st1184;
		case 83: goto st1189;
		case 84: goto st1244;
	}
	goto st819;
tr1443:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1045;
st1045:
	if ( ++p == pe )
		goto _test_eof1045;
case 1045:
#line 13304 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1453;
	}
	goto st1045;
tr1458:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st1046;
tr1453:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st1046;
st1046:
	if ( ++p == pe )
		goto _test_eof1046;
case 1046:
#line 13327 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st1046;
		case 32: goto st1046;
		case 37: goto tr1443;
		case 44: goto st821;
		case 46: goto st1047;
		case 65: goto st827;
		case 67: goto st904;
		case 68: goto st932;
		case 71: goto st939;
		case 72: goto st980;
		case 83: goto st985;
		case 84: goto st1035;
	}
	goto st0;
st1047:
	if ( ++p == pe )
		goto _test_eof1047;
case 1047:
	if ( (*p) == 46 )
		goto st1048;
	goto st0;
st1048:
	if ( ++p == pe )
		goto _test_eof1048;
case 1048:
	if ( (*p) == 46 )
		goto st1049;
	goto st0;
st1049:
	if ( ++p == pe )
		goto _test_eof1049;
case 1049:
	switch( (*p) ) {
		case 9: goto st1049;
		case 10: goto tr1458;
		case 13: goto st1050;
		case 32: goto st1049;
	}
	goto st0;
st1050:
	if ( ++p == pe )
		goto _test_eof1050;
case 1050:
	if ( (*p) == 10 )
		goto tr1458;
	goto st0;
st1051:
	if ( ++p == pe )
		goto _test_eof1051;
case 1051:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 46: goto st1052;
	}
	goto st819;
st1052:
	if ( ++p == pe )
		goto _test_eof1052;
case 1052:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 46: goto st1053;
	}
	goto st819;
st1053:
	if ( ++p == pe )
		goto _test_eof1053;
case 1053:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1053;
		case 10: goto tr1453;
		case 13: goto st1054;
		case 32: goto st1053;
	}
	goto st819;
st1054:
	if ( ++p == pe )
		goto _test_eof1054;
case 1054:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1453;
	}
	goto st819;
st1055:
	if ( ++p == pe )
		goto _test_eof1055;
case 1055:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 98: goto st1056;
		case 99: goto st1074;
	}
	goto st819;
st1056:
	if ( ++p == pe )
		goto _test_eof1056;
case 1056:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 115: goto st1057;
	}
	goto st819;
st1057:
	if ( ++p == pe )
		goto _test_eof1057;
case 1057:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 116: goto st1058;
	}
	goto st819;
st1058:
	if ( ++p == pe )
		goto _test_eof1058;
case 1058:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 114: goto st1059;
	}
	goto st819;
st1059:
	if ( ++p == pe )
		goto _test_eof1059;
case 1059:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 97: goto st1060;
	}
	goto st819;
st1060:
	if ( ++p == pe )
		goto _test_eof1060;
case 1060:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 99: goto st1061;
	}
	goto st819;
st1061:
	if ( ++p == pe )
		goto _test_eof1061;
case 1061:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 116: goto st1062;
	}
	goto st819;
st1062:
	if ( ++p == pe )
		goto _test_eof1062;
case 1062:
	switch( (*p) ) {
		case 0: goto st834;
		case 10: goto tr1471;
		case 41: goto st819;
		case 44: goto st819;
	}
	goto st1062;
tr1485:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st1063;
tr1471:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st1063;
st1063:
	if ( ++p == pe )
		goto _test_eof1063;
case 1063:
#line 13515 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr1472;
		case 10: goto tr1147;
		case 13: goto tr1148;
		case 32: goto tr1472;
		case 37: goto tr1473;
		case 41: goto st0;
		case 44: goto st821;
		case 46: goto st1070;
		case 95: goto tr1150;
		case 101: goto tr1151;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1150;
	} else if ( (*p) >= 65 )
		goto tr1150;
	goto st834;
tr1472:
#line 846 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
	goto st1064;
st1064:
	if ( ++p == pe )
		goto _test_eof1064;
case 1064:
#line 13544 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st1064;
		case 10: goto tr1145;
		case 32: goto st1064;
		case 37: goto tr1473;
		case 41: goto st0;
		case 44: goto st821;
		case 46: goto st1070;
		case 95: goto tr1153;
		case 101: goto tr1154;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1153;
	} else if ( (*p) >= 65 )
		goto tr1153;
	goto st834;
tr1473:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1065;
st1065:
	if ( ++p == pe )
		goto _test_eof1065;
case 1065:
#line 13570 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st834;
		case 10: goto tr1471;
		case 13: goto st1062;
		case 41: goto st1066;
		case 44: goto st1066;
	}
	goto st1065;
tr1481:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1066;
st1066:
	if ( ++p == pe )
		goto _test_eof1066;
case 1066:
#line 13587 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1478;
		case 13: goto st1069;
	}
	goto st1066;
tr1478:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st1067;
tr1517:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 745 "mfilescanner.rl"
	{ access_.full = Private;
               access_.get = Private;
               access_.set = Private;
             }
	goto st1067;
tr1525:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 740 "mfilescanner.rl"
	{ access_.full = Protected;
               access_.get = Protected;
               access_.set = Protected;
             }
	goto st1067;
tr1531:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 735 "mfilescanner.rl"
	{ access_.full = Public;
               access_.get = Public;
               access_.set = Public;
             }
	goto st1067;
tr1595:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 729 "mfilescanner.rl"
	{ access_.full = access_.set;
               access_.get = Private;
             }
	goto st1067;
tr1603:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 724 "mfilescanner.rl"
	{ access_.full =
                 (access_.set == Public ? Public : Protected );
               access_.get = Protected;
             }
	goto st1067;
tr1609:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 720 "mfilescanner.rl"
	{ access_.full = Public;
               access_.get = Public;
             }
	goto st1067;
tr1655:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 714 "mfilescanner.rl"
	{ access_.full = access_.get;
               access_.set = Private;
             }
	goto st1067;
tr1663:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 709 "mfilescanner.rl"
	{ access_.full =
                 (access_.get == Public ? Public : Protected );
               access_.set = Protected;
             }
	goto st1067;
tr1669:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 705 "mfilescanner.rl"
	{ access_.full = Public;
               access_.set = Public;
             }
	goto st1067;
st1067:
	if ( ++p == pe )
		goto _test_eof1067;
case 1067:
#line 13729 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr1480;
		case 10: goto tr1054;
		case 13: goto tr1055;
		case 32: goto tr1480;
		case 37: goto tr1481;
		case 44: goto st821;
		case 46: goto st1040;
		case 95: goto tr1057;
		case 101: goto tr1058;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1057;
	} else if ( (*p) >= 65 )
		goto tr1057;
	goto st0;
tr1480:
#line 846 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
	goto st1068;
st1068:
	if ( ++p == pe )
		goto _test_eof1068;
case 1068:
#line 13757 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st1068;
		case 10: goto tr1060;
		case 13: goto st790;
		case 32: goto st1068;
		case 37: goto tr1481;
		case 44: goto st821;
		case 46: goto st1040;
		case 95: goto tr1062;
		case 101: goto tr1063;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1062;
	} else if ( (*p) >= 65 )
		goto tr1062;
	goto st0;
tr1518:
#line 745 "mfilescanner.rl"
	{ access_.full = Private;
               access_.get = Private;
               access_.set = Private;
             }
	goto st1069;
tr1526:
#line 740 "mfilescanner.rl"
	{ access_.full = Protected;
               access_.get = Protected;
               access_.set = Protected;
             }
	goto st1069;
tr1532:
#line 735 "mfilescanner.rl"
	{ access_.full = Public;
               access_.get = Public;
               access_.set = Public;
             }
	goto st1069;
tr1596:
#line 729 "mfilescanner.rl"
	{ access_.full = access_.set;
               access_.get = Private;
             }
	goto st1069;
tr1604:
#line 724 "mfilescanner.rl"
	{ access_.full =
                 (access_.set == Public ? Public : Protected );
               access_.get = Protected;
             }
	goto st1069;
tr1610:
#line 720 "mfilescanner.rl"
	{ access_.full = Public;
               access_.get = Public;
             }
	goto st1069;
tr1656:
#line 714 "mfilescanner.rl"
	{ access_.full = access_.get;
               access_.set = Private;
             }
	goto st1069;
tr1664:
#line 709 "mfilescanner.rl"
	{ access_.full =
                 (access_.get == Public ? Public : Protected );
               access_.set = Protected;
             }
	goto st1069;
tr1670:
#line 705 "mfilescanner.rl"
	{ access_.full = Public;
               access_.set = Public;
             }
	goto st1069;
st1069:
	if ( ++p == pe )
		goto _test_eof1069;
case 1069:
#line 13838 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1478;
	}
	goto st819;
st1070:
	if ( ++p == pe )
		goto _test_eof1070;
case 1070:
	switch( (*p) ) {
		case 10: goto tr1145;
		case 41: goto st0;
		case 44: goto st0;
		case 46: goto st1071;
	}
	goto st834;
st1071:
	if ( ++p == pe )
		goto _test_eof1071;
case 1071:
	switch( (*p) ) {
		case 10: goto tr1145;
		case 41: goto st0;
		case 44: goto st0;
		case 46: goto st1072;
	}
	goto st834;
st1072:
	if ( ++p == pe )
		goto _test_eof1072;
case 1072:
	switch( (*p) ) {
		case 9: goto st1072;
		case 10: goto tr1485;
		case 13: goto st1073;
		case 32: goto st1072;
		case 41: goto st0;
		case 44: goto st0;
	}
	goto st834;
st1073:
	if ( ++p == pe )
		goto _test_eof1073;
case 1073:
	switch( (*p) ) {
		case 10: goto tr1485;
		case 41: goto st0;
		case 44: goto st0;
	}
	goto st834;
st1074:
	if ( ++p == pe )
		goto _test_eof1074;
case 1074:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 99: goto st1075;
	}
	goto st819;
st1075:
	if ( ++p == pe )
		goto _test_eof1075;
case 1075:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 101: goto st1076;
	}
	goto st819;
st1076:
	if ( ++p == pe )
		goto _test_eof1076;
case 1076:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 115: goto st1077;
	}
	goto st819;
st1077:
	if ( ++p == pe )
		goto _test_eof1077;
case 1077:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 115: goto st1078;
	}
	goto st819;
st1078:
	if ( ++p == pe )
		goto _test_eof1078;
case 1078:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1078;
		case 10: goto tr1118;
		case 32: goto st1078;
		case 37: goto tr1491;
		case 46: goto st1085;
		case 61: goto st1089;
	}
	goto st819;
tr1491:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1079;
st1079:
	if ( ++p == pe )
		goto _test_eof1079;
case 1079:
#line 13951 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1495;
	}
	goto st1079;
tr1500:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st1080;
tr1495:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st1080;
st1080:
	if ( ++p == pe )
		goto _test_eof1080;
case 1080:
#line 13974 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st1080;
		case 32: goto st1080;
		case 37: goto tr1491;
		case 44: goto st821;
		case 46: goto st1081;
		case 61: goto st877;
	}
	goto st0;
st1081:
	if ( ++p == pe )
		goto _test_eof1081;
case 1081:
	if ( (*p) == 46 )
		goto st1082;
	goto st0;
st1082:
	if ( ++p == pe )
		goto _test_eof1082;
case 1082:
	if ( (*p) == 46 )
		goto st1083;
	goto st0;
st1083:
	if ( ++p == pe )
		goto _test_eof1083;
case 1083:
	switch( (*p) ) {
		case 9: goto st1083;
		case 10: goto tr1500;
		case 13: goto st1084;
		case 32: goto st1083;
	}
	goto st0;
st1084:
	if ( ++p == pe )
		goto _test_eof1084;
case 1084:
	if ( (*p) == 10 )
		goto tr1500;
	goto st0;
st1085:
	if ( ++p == pe )
		goto _test_eof1085;
case 1085:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 46: goto st1086;
	}
	goto st819;
st1086:
	if ( ++p == pe )
		goto _test_eof1086;
case 1086:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 46: goto st1087;
	}
	goto st819;
st1087:
	if ( ++p == pe )
		goto _test_eof1087;
case 1087:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1087;
		case 10: goto tr1495;
		case 13: goto st1088;
		case 32: goto st1087;
	}
	goto st819;
st1088:
	if ( ++p == pe )
		goto _test_eof1088;
case 1088:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1495;
	}
	goto st819;
st1089:
	if ( ++p == pe )
		goto _test_eof1089;
case 1089:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1090;
		case 10: goto tr1118;
		case 32: goto st1090;
		case 37: goto tr1506;
		case 46: goto st1112;
	}
	goto st819;
st1090:
	if ( ++p == pe )
		goto _test_eof1090;
case 1090:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1090;
		case 10: goto tr1118;
		case 32: goto st1090;
		case 112: goto st1091;
	}
	goto st819;
st1091:
	if ( ++p == pe )
		goto _test_eof1091;
case 1091:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 114: goto st1092;
		case 117: goto st1105;
	}
	goto st819;
st1092:
	if ( ++p == pe )
		goto _test_eof1092;
case 1092:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 105: goto st1093;
		case 111: goto st1098;
	}
	goto st819;
st1093:
	if ( ++p == pe )
		goto _test_eof1093;
case 1093:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 118: goto st1094;
	}
	goto st819;
st1094:
	if ( ++p == pe )
		goto _test_eof1094;
case 1094:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 97: goto st1095;
	}
	goto st819;
st1095:
	if ( ++p == pe )
		goto _test_eof1095;
case 1095:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 116: goto st1096;
	}
	goto st819;
st1096:
	if ( ++p == pe )
		goto _test_eof1096;
case 1096:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 101: goto st1097;
	}
	goto st819;
st1097:
	if ( ++p == pe )
		goto _test_eof1097;
case 1097:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1517;
		case 13: goto tr1518;
	}
	goto st819;
st1098:
	if ( ++p == pe )
		goto _test_eof1098;
case 1098:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 116: goto st1099;
	}
	goto st819;
st1099:
	if ( ++p == pe )
		goto _test_eof1099;
case 1099:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 101: goto st1100;
	}
	goto st819;
st1100:
	if ( ++p == pe )
		goto _test_eof1100;
case 1100:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 99: goto st1101;
	}
	goto st819;
st1101:
	if ( ++p == pe )
		goto _test_eof1101;
case 1101:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 116: goto st1102;
	}
	goto st819;
st1102:
	if ( ++p == pe )
		goto _test_eof1102;
case 1102:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 101: goto st1103;
	}
	goto st819;
st1103:
	if ( ++p == pe )
		goto _test_eof1103;
case 1103:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 100: goto st1104;
	}
	goto st819;
st1104:
	if ( ++p == pe )
		goto _test_eof1104;
case 1104:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1525;
		case 13: goto tr1526;
	}
	goto st819;
st1105:
	if ( ++p == pe )
		goto _test_eof1105;
case 1105:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 98: goto st1106;
	}
	goto st819;
st1106:
	if ( ++p == pe )
		goto _test_eof1106;
case 1106:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 108: goto st1107;
	}
	goto st819;
st1107:
	if ( ++p == pe )
		goto _test_eof1107;
case 1107:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 105: goto st1108;
	}
	goto st819;
st1108:
	if ( ++p == pe )
		goto _test_eof1108;
case 1108:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 99: goto st1109;
	}
	goto st819;
st1109:
	if ( ++p == pe )
		goto _test_eof1109;
case 1109:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1531;
		case 13: goto tr1532;
	}
	goto st819;
tr1506:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1110;
st1110:
	if ( ++p == pe )
		goto _test_eof1110;
case 1110:
#line 14282 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1534;
	}
	goto st1110;
tr1534:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st1111;
st1111:
	if ( ++p == pe )
		goto _test_eof1111;
case 1111:
#line 14301 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st820;
		case 32: goto st820;
		case 37: goto tr1120;
		case 44: goto st821;
		case 46: goto st1040;
		case 112: goto st879;
	}
	goto st0;
st1112:
	if ( ++p == pe )
		goto _test_eof1112;
case 1112:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 46: goto st1113;
	}
	goto st819;
st1113:
	if ( ++p == pe )
		goto _test_eof1113;
case 1113:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 46: goto st1114;
	}
	goto st819;
st1114:
	if ( ++p == pe )
		goto _test_eof1114;
case 1114:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1114;
		case 10: goto tr1534;
		case 13: goto st1115;
		case 32: goto st1114;
	}
	goto st819;
st1115:
	if ( ++p == pe )
		goto _test_eof1115;
case 1115:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1534;
	}
	goto st819;
st1116:
	if ( ++p == pe )
		goto _test_eof1116;
case 1116:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 111: goto st1117;
	}
	goto st819;
st1117:
	if ( ++p == pe )
		goto _test_eof1117;
case 1117:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 110: goto st1118;
	}
	goto st819;
st1118:
	if ( ++p == pe )
		goto _test_eof1118;
case 1118:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 115: goto st1119;
	}
	goto st819;
st1119:
	if ( ++p == pe )
		goto _test_eof1119;
case 1119:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 116: goto st1120;
	}
	goto st819;
st1120:
	if ( ++p == pe )
		goto _test_eof1120;
case 1120:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 97: goto st1121;
	}
	goto st819;
st1121:
	if ( ++p == pe )
		goto _test_eof1121;
case 1121:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 110: goto st1122;
	}
	goto st819;
st1122:
	if ( ++p == pe )
		goto _test_eof1122;
case 1122:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 116: goto tr1544;
	}
	goto st819;
tr1544:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
	goto st1123;
st1123:
	if ( ++p == pe )
		goto _test_eof1123;
case 1123:
#line 14432 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr1268;
		case 10: goto tr1545;
		case 41: goto st819;
		case 44: goto st819;
	}
	goto tr1544;
tr1545:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
	goto st1124;
tr1553:
#line 32 "mfilescanner.rl"
	{line++;}
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
	goto st1124;
st1124:
	if ( ++p == pe )
		goto _test_eof1124;
case 1124:
#line 14465 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr1546;
		case 10: goto tr1271;
		case 13: goto tr1272;
		case 32: goto tr1546;
		case 37: goto tr1547;
		case 41: goto st0;
		case 44: goto st821;
		case 46: goto tr1548;
		case 95: goto tr1274;
		case 101: goto tr1275;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1274;
	} else if ( (*p) >= 65 )
		goto tr1274;
	goto tr1268;
tr1549:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
	goto st1125;
tr1546:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 846 "mfilescanner.rl"
	{
            print_access_specifier(access_.full);
          }
	goto st1125;
st1125:
	if ( ++p == pe )
		goto _test_eof1125;
case 1125:
#line 14504 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr1549;
		case 10: goto tr1269;
		case 32: goto tr1549;
		case 37: goto tr1547;
		case 41: goto st0;
		case 44: goto st821;
		case 46: goto tr1548;
		case 95: goto tr1277;
		case 101: goto tr1278;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1277;
	} else if ( (*p) >= 65 )
		goto tr1277;
	goto tr1268;
tr1550:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
	goto st1126;
tr1547:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
	goto st1126;
st1126:
	if ( ++p == pe )
		goto _test_eof1126;
case 1126:
#line 14540 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr1268;
		case 10: goto tr1545;
		case 13: goto tr1544;
		case 41: goto st1066;
		case 44: goto st1066;
	}
	goto tr1550;
tr1548:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
	goto st1127;
st1127:
	if ( ++p == pe )
		goto _test_eof1127;
case 1127:
#line 14559 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr1269;
		case 41: goto st0;
		case 44: goto st0;
		case 46: goto tr1551;
	}
	goto tr1268;
tr1551:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
	goto st1128;
st1128:
	if ( ++p == pe )
		goto _test_eof1128;
case 1128:
#line 14577 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr1269;
		case 41: goto st0;
		case 44: goto st0;
		case 46: goto tr1552;
	}
	goto tr1268;
tr1552:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
	goto st1129;
st1129:
	if ( ++p == pe )
		goto _test_eof1129;
case 1129:
#line 14595 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr1552;
		case 10: goto tr1553;
		case 13: goto tr1554;
		case 32: goto tr1552;
		case 41: goto st0;
		case 44: goto st0;
	}
	goto tr1268;
tr1554:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
	goto st1130;
st1130:
	if ( ++p == pe )
		goto _test_eof1130;
case 1130:
#line 14615 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr1553;
		case 41: goto st0;
		case 44: goto st0;
	}
	goto tr1268;
st1131:
	if ( ++p == pe )
		goto _test_eof1131;
case 1131:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 101: goto st1132;
	}
	goto st819;
st1132:
	if ( ++p == pe )
		goto _test_eof1132;
case 1132:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 112: goto st1133;
	}
	goto st819;
st1133:
	if ( ++p == pe )
		goto _test_eof1133;
case 1133:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 101: goto st1134;
	}
	goto st819;
st1134:
	if ( ++p == pe )
		goto _test_eof1134;
case 1134:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 110: goto st1135;
	}
	goto st819;
st1135:
	if ( ++p == pe )
		goto _test_eof1135;
case 1135:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 100: goto st1136;
	}
	goto st819;
st1136:
	if ( ++p == pe )
		goto _test_eof1136;
case 1136:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 101: goto st1137;
	}
	goto st819;
st1137:
	if ( ++p == pe )
		goto _test_eof1137;
case 1137:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 110: goto st1061;
	}
	goto st819;
st1138:
	if ( ++p == pe )
		goto _test_eof1138;
case 1138:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 101: goto st1139;
	}
	goto st819;
st1139:
	if ( ++p == pe )
		goto _test_eof1139;
case 1139:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 116: goto st1140;
	}
	goto st819;
st1140:
	if ( ++p == pe )
		goto _test_eof1140;
case 1140:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 65: goto st1141;
	}
	goto st819;
st1141:
	if ( ++p == pe )
		goto _test_eof1141;
case 1141:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 99: goto st1142;
	}
	goto st819;
st1142:
	if ( ++p == pe )
		goto _test_eof1142;
case 1142:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 99: goto st1143;
	}
	goto st819;
st1143:
	if ( ++p == pe )
		goto _test_eof1143;
case 1143:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 101: goto st1144;
	}
	goto st819;
st1144:
	if ( ++p == pe )
		goto _test_eof1144;
case 1144:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 115: goto st1145;
	}
	goto st819;
st1145:
	if ( ++p == pe )
		goto _test_eof1145;
case 1145:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 115: goto st1146;
	}
	goto st819;
st1146:
	if ( ++p == pe )
		goto _test_eof1146;
case 1146:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1146;
		case 10: goto tr1118;
		case 32: goto st1146;
		case 37: goto tr1569;
		case 46: goto st1153;
		case 61: goto st1157;
	}
	goto st819;
tr1569:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1147;
st1147:
	if ( ++p == pe )
		goto _test_eof1147;
case 1147:
#line 14794 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1573;
	}
	goto st1147;
tr1578:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st1148;
tr1573:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st1148;
st1148:
	if ( ++p == pe )
		goto _test_eof1148;
case 1148:
#line 14817 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st1148;
		case 32: goto st1148;
		case 37: goto tr1569;
		case 44: goto st821;
		case 46: goto st1149;
		case 61: goto st953;
	}
	goto st0;
st1149:
	if ( ++p == pe )
		goto _test_eof1149;
case 1149:
	if ( (*p) == 46 )
		goto st1150;
	goto st0;
st1150:
	if ( ++p == pe )
		goto _test_eof1150;
case 1150:
	if ( (*p) == 46 )
		goto st1151;
	goto st0;
st1151:
	if ( ++p == pe )
		goto _test_eof1151;
case 1151:
	switch( (*p) ) {
		case 9: goto st1151;
		case 10: goto tr1578;
		case 13: goto st1152;
		case 32: goto st1151;
	}
	goto st0;
st1152:
	if ( ++p == pe )
		goto _test_eof1152;
case 1152:
	if ( (*p) == 10 )
		goto tr1578;
	goto st0;
st1153:
	if ( ++p == pe )
		goto _test_eof1153;
case 1153:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 46: goto st1154;
	}
	goto st819;
st1154:
	if ( ++p == pe )
		goto _test_eof1154;
case 1154:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 46: goto st1155;
	}
	goto st819;
st1155:
	if ( ++p == pe )
		goto _test_eof1155;
case 1155:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1155;
		case 10: goto tr1573;
		case 13: goto st1156;
		case 32: goto st1155;
	}
	goto st819;
st1156:
	if ( ++p == pe )
		goto _test_eof1156;
case 1156:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1573;
	}
	goto st819;
st1157:
	if ( ++p == pe )
		goto _test_eof1157;
case 1157:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1158;
		case 10: goto tr1118;
		case 32: goto st1158;
		case 37: goto tr1584;
		case 46: goto st1180;
	}
	goto st819;
st1158:
	if ( ++p == pe )
		goto _test_eof1158;
case 1158:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1158;
		case 10: goto tr1118;
		case 32: goto st1158;
		case 112: goto st1159;
	}
	goto st819;
st1159:
	if ( ++p == pe )
		goto _test_eof1159;
case 1159:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 114: goto st1160;
		case 117: goto st1173;
	}
	goto st819;
st1160:
	if ( ++p == pe )
		goto _test_eof1160;
case 1160:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 105: goto st1161;
		case 111: goto st1166;
	}
	goto st819;
st1161:
	if ( ++p == pe )
		goto _test_eof1161;
case 1161:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 118: goto st1162;
	}
	goto st819;
st1162:
	if ( ++p == pe )
		goto _test_eof1162;
case 1162:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 97: goto st1163;
	}
	goto st819;
st1163:
	if ( ++p == pe )
		goto _test_eof1163;
case 1163:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 116: goto st1164;
	}
	goto st819;
st1164:
	if ( ++p == pe )
		goto _test_eof1164;
case 1164:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 101: goto st1165;
	}
	goto st819;
st1165:
	if ( ++p == pe )
		goto _test_eof1165;
case 1165:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1595;
		case 13: goto tr1596;
	}
	goto st819;
st1166:
	if ( ++p == pe )
		goto _test_eof1166;
case 1166:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 116: goto st1167;
	}
	goto st819;
st1167:
	if ( ++p == pe )
		goto _test_eof1167;
case 1167:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 101: goto st1168;
	}
	goto st819;
st1168:
	if ( ++p == pe )
		goto _test_eof1168;
case 1168:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 99: goto st1169;
	}
	goto st819;
st1169:
	if ( ++p == pe )
		goto _test_eof1169;
case 1169:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 116: goto st1170;
	}
	goto st819;
st1170:
	if ( ++p == pe )
		goto _test_eof1170;
case 1170:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 101: goto st1171;
	}
	goto st819;
st1171:
	if ( ++p == pe )
		goto _test_eof1171;
case 1171:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 100: goto st1172;
	}
	goto st819;
st1172:
	if ( ++p == pe )
		goto _test_eof1172;
case 1172:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1603;
		case 13: goto tr1604;
	}
	goto st819;
st1173:
	if ( ++p == pe )
		goto _test_eof1173;
case 1173:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 98: goto st1174;
	}
	goto st819;
st1174:
	if ( ++p == pe )
		goto _test_eof1174;
case 1174:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 108: goto st1175;
	}
	goto st819;
st1175:
	if ( ++p == pe )
		goto _test_eof1175;
case 1175:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 105: goto st1176;
	}
	goto st819;
st1176:
	if ( ++p == pe )
		goto _test_eof1176;
case 1176:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 99: goto st1177;
	}
	goto st819;
st1177:
	if ( ++p == pe )
		goto _test_eof1177;
case 1177:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1609;
		case 13: goto tr1610;
	}
	goto st819;
tr1584:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1178;
st1178:
	if ( ++p == pe )
		goto _test_eof1178;
case 1178:
#line 15125 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1612;
	}
	goto st1178;
tr1612:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st1179;
st1179:
	if ( ++p == pe )
		goto _test_eof1179;
case 1179:
#line 15144 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st820;
		case 32: goto st820;
		case 37: goto tr1120;
		case 44: goto st821;
		case 46: goto st1040;
		case 112: goto st955;
	}
	goto st0;
st1180:
	if ( ++p == pe )
		goto _test_eof1180;
case 1180:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 46: goto st1181;
	}
	goto st819;
st1181:
	if ( ++p == pe )
		goto _test_eof1181;
case 1181:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 46: goto st1182;
	}
	goto st819;
st1182:
	if ( ++p == pe )
		goto _test_eof1182;
case 1182:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1182;
		case 10: goto tr1612;
		case 13: goto st1183;
		case 32: goto st1182;
	}
	goto st819;
st1183:
	if ( ++p == pe )
		goto _test_eof1183;
case 1183:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1612;
	}
	goto st819;
st1184:
	if ( ++p == pe )
		goto _test_eof1184;
case 1184:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 105: goto st1185;
	}
	goto st819;
st1185:
	if ( ++p == pe )
		goto _test_eof1185;
case 1185:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 100: goto st1186;
	}
	goto st819;
st1186:
	if ( ++p == pe )
		goto _test_eof1186;
case 1186:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 100: goto st1187;
	}
	goto st819;
st1187:
	if ( ++p == pe )
		goto _test_eof1187;
case 1187:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 101: goto st1188;
	}
	goto st819;
st1188:
	if ( ++p == pe )
		goto _test_eof1188;
case 1188:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 110: goto st1062;
	}
	goto st819;
st1189:
	if ( ++p == pe )
		goto _test_eof1189;
case 1189:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 101: goto st1190;
	}
	goto st819;
st1190:
	if ( ++p == pe )
		goto _test_eof1190;
case 1190:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 116: goto st1191;
	}
	goto st819;
st1191:
	if ( ++p == pe )
		goto _test_eof1191;
case 1191:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 65: goto st1192;
		case 79: goto st1235;
	}
	goto st819;
st1192:
	if ( ++p == pe )
		goto _test_eof1192;
case 1192:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 99: goto st1193;
	}
	goto st819;
st1193:
	if ( ++p == pe )
		goto _test_eof1193;
case 1193:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 99: goto st1194;
	}
	goto st819;
st1194:
	if ( ++p == pe )
		goto _test_eof1194;
case 1194:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 101: goto st1195;
	}
	goto st819;
st1195:
	if ( ++p == pe )
		goto _test_eof1195;
case 1195:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 115: goto st1196;
	}
	goto st819;
st1196:
	if ( ++p == pe )
		goto _test_eof1196;
case 1196:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 115: goto st1197;
	}
	goto st819;
st1197:
	if ( ++p == pe )
		goto _test_eof1197;
case 1197:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1197;
		case 10: goto tr1118;
		case 32: goto st1197;
		case 37: goto tr1629;
		case 46: goto st1204;
		case 61: goto st1208;
	}
	goto st819;
tr1629:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1198;
st1198:
	if ( ++p == pe )
		goto _test_eof1198;
case 1198:
#line 15348 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1633;
	}
	goto st1198;
tr1638:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st1199;
tr1633:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st1199;
st1199:
	if ( ++p == pe )
		goto _test_eof1199;
case 1199:
#line 15371 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st1199;
		case 32: goto st1199;
		case 37: goto tr1629;
		case 44: goto st821;
		case 46: goto st1200;
		case 61: goto st999;
	}
	goto st0;
st1200:
	if ( ++p == pe )
		goto _test_eof1200;
case 1200:
	if ( (*p) == 46 )
		goto st1201;
	goto st0;
st1201:
	if ( ++p == pe )
		goto _test_eof1201;
case 1201:
	if ( (*p) == 46 )
		goto st1202;
	goto st0;
st1202:
	if ( ++p == pe )
		goto _test_eof1202;
case 1202:
	switch( (*p) ) {
		case 9: goto st1202;
		case 10: goto tr1638;
		case 13: goto st1203;
		case 32: goto st1202;
	}
	goto st0;
st1203:
	if ( ++p == pe )
		goto _test_eof1203;
case 1203:
	if ( (*p) == 10 )
		goto tr1638;
	goto st0;
st1204:
	if ( ++p == pe )
		goto _test_eof1204;
case 1204:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 46: goto st1205;
	}
	goto st819;
st1205:
	if ( ++p == pe )
		goto _test_eof1205;
case 1205:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 46: goto st1206;
	}
	goto st819;
st1206:
	if ( ++p == pe )
		goto _test_eof1206;
case 1206:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1206;
		case 10: goto tr1633;
		case 13: goto st1207;
		case 32: goto st1206;
	}
	goto st819;
st1207:
	if ( ++p == pe )
		goto _test_eof1207;
case 1207:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1633;
	}
	goto st819;
st1208:
	if ( ++p == pe )
		goto _test_eof1208;
case 1208:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1209;
		case 10: goto tr1118;
		case 32: goto st1209;
		case 37: goto tr1644;
		case 46: goto st1231;
	}
	goto st819;
st1209:
	if ( ++p == pe )
		goto _test_eof1209;
case 1209:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1209;
		case 10: goto tr1118;
		case 32: goto st1209;
		case 112: goto st1210;
	}
	goto st819;
st1210:
	if ( ++p == pe )
		goto _test_eof1210;
case 1210:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 114: goto st1211;
		case 117: goto st1224;
	}
	goto st819;
st1211:
	if ( ++p == pe )
		goto _test_eof1211;
case 1211:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 105: goto st1212;
		case 111: goto st1217;
	}
	goto st819;
st1212:
	if ( ++p == pe )
		goto _test_eof1212;
case 1212:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 118: goto st1213;
	}
	goto st819;
st1213:
	if ( ++p == pe )
		goto _test_eof1213;
case 1213:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 97: goto st1214;
	}
	goto st819;
st1214:
	if ( ++p == pe )
		goto _test_eof1214;
case 1214:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 116: goto st1215;
	}
	goto st819;
st1215:
	if ( ++p == pe )
		goto _test_eof1215;
case 1215:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 101: goto st1216;
	}
	goto st819;
st1216:
	if ( ++p == pe )
		goto _test_eof1216;
case 1216:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1655;
		case 13: goto tr1656;
	}
	goto st819;
st1217:
	if ( ++p == pe )
		goto _test_eof1217;
case 1217:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 116: goto st1218;
	}
	goto st819;
st1218:
	if ( ++p == pe )
		goto _test_eof1218;
case 1218:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 101: goto st1219;
	}
	goto st819;
st1219:
	if ( ++p == pe )
		goto _test_eof1219;
case 1219:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 99: goto st1220;
	}
	goto st819;
st1220:
	if ( ++p == pe )
		goto _test_eof1220;
case 1220:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 116: goto st1221;
	}
	goto st819;
st1221:
	if ( ++p == pe )
		goto _test_eof1221;
case 1221:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 101: goto st1222;
	}
	goto st819;
st1222:
	if ( ++p == pe )
		goto _test_eof1222;
case 1222:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 100: goto st1223;
	}
	goto st819;
st1223:
	if ( ++p == pe )
		goto _test_eof1223;
case 1223:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1663;
		case 13: goto tr1664;
	}
	goto st819;
st1224:
	if ( ++p == pe )
		goto _test_eof1224;
case 1224:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 98: goto st1225;
	}
	goto st819;
st1225:
	if ( ++p == pe )
		goto _test_eof1225;
case 1225:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 108: goto st1226;
	}
	goto st819;
st1226:
	if ( ++p == pe )
		goto _test_eof1226;
case 1226:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 105: goto st1227;
	}
	goto st819;
st1227:
	if ( ++p == pe )
		goto _test_eof1227;
case 1227:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 99: goto st1228;
	}
	goto st819;
st1228:
	if ( ++p == pe )
		goto _test_eof1228;
case 1228:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1669;
		case 13: goto tr1670;
	}
	goto st819;
tr1644:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1229;
st1229:
	if ( ++p == pe )
		goto _test_eof1229;
case 1229:
#line 15679 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1672;
	}
	goto st1229;
tr1672:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st1230;
st1230:
	if ( ++p == pe )
		goto _test_eof1230;
case 1230:
#line 15698 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st820;
		case 32: goto st820;
		case 37: goto tr1120;
		case 44: goto st821;
		case 46: goto st1040;
		case 112: goto st1001;
	}
	goto st0;
st1231:
	if ( ++p == pe )
		goto _test_eof1231;
case 1231:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 46: goto st1232;
	}
	goto st819;
st1232:
	if ( ++p == pe )
		goto _test_eof1232;
case 1232:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 46: goto st1233;
	}
	goto st819;
st1233:
	if ( ++p == pe )
		goto _test_eof1233;
case 1233:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1233;
		case 10: goto tr1672;
		case 13: goto st1234;
		case 32: goto st1233;
	}
	goto st819;
st1234:
	if ( ++p == pe )
		goto _test_eof1234;
case 1234:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1672;
	}
	goto st819;
st1235:
	if ( ++p == pe )
		goto _test_eof1235;
case 1235:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 98: goto st1236;
	}
	goto st819;
st1236:
	if ( ++p == pe )
		goto _test_eof1236;
case 1236:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 115: goto st1237;
	}
	goto st819;
st1237:
	if ( ++p == pe )
		goto _test_eof1237;
case 1237:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 101: goto st1238;
	}
	goto st819;
st1238:
	if ( ++p == pe )
		goto _test_eof1238;
case 1238:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 114: goto st1239;
	}
	goto st819;
st1239:
	if ( ++p == pe )
		goto _test_eof1239;
case 1239:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 118: goto st1240;
	}
	goto st819;
st1240:
	if ( ++p == pe )
		goto _test_eof1240;
case 1240:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 97: goto st1241;
	}
	goto st819;
st1241:
	if ( ++p == pe )
		goto _test_eof1241;
case 1241:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 98: goto st1242;
	}
	goto st819;
st1242:
	if ( ++p == pe )
		goto _test_eof1242;
case 1242:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 108: goto st1243;
	}
	goto st819;
st1243:
	if ( ++p == pe )
		goto _test_eof1243;
case 1243:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 101: goto st1062;
	}
	goto st819;
st1244:
	if ( ++p == pe )
		goto _test_eof1244;
case 1244:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 114: goto st1245;
	}
	goto st819;
st1245:
	if ( ++p == pe )
		goto _test_eof1245;
case 1245:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 97: goto st1246;
	}
	goto st819;
st1246:
	if ( ++p == pe )
		goto _test_eof1246;
case 1246:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 110: goto st1247;
	}
	goto st819;
st1247:
	if ( ++p == pe )
		goto _test_eof1247;
case 1247:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 115: goto st1248;
	}
	goto st819;
st1248:
	if ( ++p == pe )
		goto _test_eof1248;
case 1248:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1118;
		case 105: goto st1136;
	}
	goto st819;
st1249:
	if ( ++p == pe )
		goto _test_eof1249;
case 1249:
	switch( (*p) ) {
		case 37: goto tr1111;
		case 41: goto st0;
		case 44: goto st821;
		case 46: goto st1250;
	}
	goto st817;
st1250:
	if ( ++p == pe )
		goto _test_eof1250;
case 1250:
	switch( (*p) ) {
		case 37: goto tr1111;
		case 41: goto st0;
		case 44: goto st821;
		case 46: goto st1251;
	}
	goto st817;
st1251:
	if ( ++p == pe )
		goto _test_eof1251;
case 1251:
	switch( (*p) ) {
		case 9: goto st1252;
		case 10: goto tr1691;
		case 13: goto st1253;
		case 32: goto st1252;
		case 37: goto tr1111;
		case 41: goto st0;
		case 44: goto st821;
		case 46: goto st1251;
	}
	goto st817;
st1252:
	if ( ++p == pe )
		goto _test_eof1252;
case 1252:
	switch( (*p) ) {
		case 9: goto st1252;
		case 10: goto tr1691;
		case 13: goto st1253;
		case 32: goto st1252;
		case 37: goto tr1111;
		case 41: goto st0;
		case 44: goto st821;
		case 46: goto st1249;
	}
	goto st817;
st1253:
	if ( ++p == pe )
		goto _test_eof1253;
case 1253:
	switch( (*p) ) {
		case 10: goto tr1691;
		case 37: goto tr1111;
		case 41: goto st0;
		case 44: goto st821;
		case 46: goto st1249;
	}
	goto st817;
st1254:
	if ( ++p == pe )
		goto _test_eof1254;
case 1254:
	if ( (*p) == 99 )
		goto st1255;
	goto st0;
st1255:
	if ( ++p == pe )
		goto _test_eof1255;
case 1255:
	if ( (*p) == 101 )
		goto st1256;
	goto st0;
st1256:
	if ( ++p == pe )
		goto _test_eof1256;
case 1256:
	if ( (*p) == 115 )
		goto st1257;
	goto st0;
st1257:
	if ( ++p == pe )
		goto _test_eof1257;
case 1257:
	if ( (*p) == 115 )
		goto st1258;
	goto st0;
tr1704:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st1258;
tr1701:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st1258;
st1258:
	if ( ++p == pe )
		goto _test_eof1258;
case 1258:
#line 15998 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st1258;
		case 32: goto st1258;
		case 37: goto tr1697;
		case 46: goto st1260;
		case 61: goto st1264;
	}
	goto st0;
tr1697:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1259;
st1259:
	if ( ++p == pe )
		goto _test_eof1259;
case 1259:
#line 16015 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1701;
	}
	goto st1259;
st1260:
	if ( ++p == pe )
		goto _test_eof1260;
case 1260:
	if ( (*p) == 46 )
		goto st1261;
	goto st0;
st1261:
	if ( ++p == pe )
		goto _test_eof1261;
case 1261:
	if ( (*p) == 46 )
		goto st1262;
	goto st0;
st1262:
	if ( ++p == pe )
		goto _test_eof1262;
case 1262:
	switch( (*p) ) {
		case 9: goto st1262;
		case 10: goto tr1704;
		case 13: goto st1263;
		case 32: goto st1262;
	}
	goto st0;
st1263:
	if ( ++p == pe )
		goto _test_eof1263;
case 1263:
	if ( (*p) == 10 )
		goto tr1704;
	goto st0;
st1264:
	if ( ++p == pe )
		goto _test_eof1264;
case 1264:
	switch( (*p) ) {
		case 9: goto st1265;
		case 32: goto st1265;
		case 37: goto tr1707;
		case 46: goto st1287;
	}
	goto st0;
st1265:
	if ( ++p == pe )
		goto _test_eof1265;
case 1265:
	switch( (*p) ) {
		case 9: goto st1265;
		case 32: goto st1265;
		case 112: goto st1266;
	}
	goto st0;
st1266:
	if ( ++p == pe )
		goto _test_eof1266;
case 1266:
	switch( (*p) ) {
		case 114: goto st1267;
		case 117: goto st1280;
	}
	goto st0;
st1267:
	if ( ++p == pe )
		goto _test_eof1267;
case 1267:
	switch( (*p) ) {
		case 105: goto st1268;
		case 111: goto st1273;
	}
	goto st0;
st1268:
	if ( ++p == pe )
		goto _test_eof1268;
case 1268:
	if ( (*p) == 118 )
		goto st1269;
	goto st0;
st1269:
	if ( ++p == pe )
		goto _test_eof1269;
case 1269:
	if ( (*p) == 97 )
		goto st1270;
	goto st0;
st1270:
	if ( ++p == pe )
		goto _test_eof1270;
case 1270:
	if ( (*p) == 116 )
		goto st1271;
	goto st0;
st1271:
	if ( ++p == pe )
		goto _test_eof1271;
case 1271:
	if ( (*p) == 101 )
		goto st1272;
	goto st0;
st1272:
	if ( ++p == pe )
		goto _test_eof1272;
case 1272:
	switch( (*p) ) {
		case 9: goto tr1718;
		case 32: goto tr1718;
		case 37: goto tr1719;
		case 44: goto tr1720;
		case 46: goto tr1721;
	}
	goto st0;
st1273:
	if ( ++p == pe )
		goto _test_eof1273;
case 1273:
	if ( (*p) == 116 )
		goto st1274;
	goto st0;
st1274:
	if ( ++p == pe )
		goto _test_eof1274;
case 1274:
	if ( (*p) == 101 )
		goto st1275;
	goto st0;
st1275:
	if ( ++p == pe )
		goto _test_eof1275;
case 1275:
	if ( (*p) == 99 )
		goto st1276;
	goto st0;
st1276:
	if ( ++p == pe )
		goto _test_eof1276;
case 1276:
	if ( (*p) == 116 )
		goto st1277;
	goto st0;
st1277:
	if ( ++p == pe )
		goto _test_eof1277;
case 1277:
	if ( (*p) == 101 )
		goto st1278;
	goto st0;
st1278:
	if ( ++p == pe )
		goto _test_eof1278;
case 1278:
	if ( (*p) == 100 )
		goto st1279;
	goto st0;
st1279:
	if ( ++p == pe )
		goto _test_eof1279;
case 1279:
	switch( (*p) ) {
		case 9: goto tr1728;
		case 32: goto tr1728;
		case 37: goto tr1729;
		case 44: goto tr1730;
		case 46: goto tr1731;
	}
	goto st0;
st1280:
	if ( ++p == pe )
		goto _test_eof1280;
case 1280:
	if ( (*p) == 98 )
		goto st1281;
	goto st0;
st1281:
	if ( ++p == pe )
		goto _test_eof1281;
case 1281:
	if ( (*p) == 108 )
		goto st1282;
	goto st0;
st1282:
	if ( ++p == pe )
		goto _test_eof1282;
case 1282:
	if ( (*p) == 105 )
		goto st1283;
	goto st0;
st1283:
	if ( ++p == pe )
		goto _test_eof1283;
case 1283:
	if ( (*p) == 99 )
		goto st1284;
	goto st0;
st1284:
	if ( ++p == pe )
		goto _test_eof1284;
case 1284:
	switch( (*p) ) {
		case 9: goto tr1736;
		case 32: goto tr1736;
		case 37: goto tr1737;
		case 44: goto tr1738;
		case 46: goto tr1739;
	}
	goto st0;
tr1707:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1285;
st1285:
	if ( ++p == pe )
		goto _test_eof1285;
case 1285:
#line 16234 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1741;
	}
	goto st1285;
tr1744:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st1286;
tr1741:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st1286;
st1286:
	if ( ++p == pe )
		goto _test_eof1286;
case 1286:
#line 16257 "mfilescanner.cc"
	if ( (*p) == 112 )
		goto st1266;
	goto st0;
st1287:
	if ( ++p == pe )
		goto _test_eof1287;
case 1287:
	if ( (*p) == 46 )
		goto st1288;
	goto st0;
st1288:
	if ( ++p == pe )
		goto _test_eof1288;
case 1288:
	if ( (*p) == 46 )
		goto st1289;
	goto st0;
st1289:
	if ( ++p == pe )
		goto _test_eof1289;
case 1289:
	switch( (*p) ) {
		case 9: goto st1289;
		case 10: goto tr1744;
		case 13: goto st1290;
		case 32: goto st1289;
	}
	goto st0;
st1290:
	if ( ++p == pe )
		goto _test_eof1290;
case 1290:
	if ( (*p) == 10 )
		goto tr1744;
	goto st0;
st1291:
	if ( ++p == pe )
		goto _test_eof1291;
case 1291:
	if ( (*p) == 111 )
		goto st1292;
	goto st0;
st1292:
	if ( ++p == pe )
		goto _test_eof1292;
case 1292:
	if ( (*p) == 110 )
		goto st1293;
	goto st0;
st1293:
	if ( ++p == pe )
		goto _test_eof1293;
case 1293:
	if ( (*p) == 115 )
		goto st1294;
	goto st0;
st1294:
	if ( ++p == pe )
		goto _test_eof1294;
case 1294:
	if ( (*p) == 116 )
		goto st1295;
	goto st0;
st1295:
	if ( ++p == pe )
		goto _test_eof1295;
case 1295:
	if ( (*p) == 97 )
		goto st1296;
	goto st0;
st1296:
	if ( ++p == pe )
		goto _test_eof1296;
case 1296:
	if ( (*p) == 110 )
		goto st1297;
	goto st0;
st1297:
	if ( ++p == pe )
		goto _test_eof1297;
case 1297:
	if ( (*p) == 116 )
		goto tr1752;
	goto st0;
tr1752:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
	goto st1298;
tr1760:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 32 "mfilescanner.rl"
	{line++;}
	goto st1298;
tr1756:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st1298;
st1298:
	if ( ++p == pe )
		goto _test_eof1298;
case 1298:
#line 16373 "mfilescanner.cc"
	switch( (*p) ) {
		case 37: goto tr1753;
		case 41: goto st0;
		case 44: goto st821;
		case 46: goto tr1754;
	}
	goto tr1752;
tr1755:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
	goto st1299;
tr1753:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1299;
st1299:
	if ( ++p == pe )
		goto _test_eof1299;
case 1299:
#line 16399 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr1752;
		case 10: goto tr1756;
		case 37: goto tr1753;
		case 41: goto st819;
		case 44: goto st1044;
	}
	goto tr1755;
tr1754:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
	goto st1300;
st1300:
	if ( ++p == pe )
		goto _test_eof1300;
case 1300:
#line 16418 "mfilescanner.cc"
	switch( (*p) ) {
		case 37: goto tr1753;
		case 41: goto st0;
		case 44: goto st821;
		case 46: goto tr1757;
	}
	goto tr1752;
tr1757:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
	goto st1301;
st1301:
	if ( ++p == pe )
		goto _test_eof1301;
case 1301:
#line 16436 "mfilescanner.cc"
	switch( (*p) ) {
		case 37: goto tr1753;
		case 41: goto st0;
		case 44: goto st821;
		case 46: goto tr1758;
	}
	goto tr1752;
tr1758:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
	goto st1302;
st1302:
	if ( ++p == pe )
		goto _test_eof1302;
case 1302:
#line 16454 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr1759;
		case 10: goto tr1760;
		case 13: goto tr1761;
		case 32: goto tr1759;
		case 37: goto tr1753;
		case 41: goto st0;
		case 44: goto st821;
		case 46: goto tr1758;
	}
	goto tr1752;
tr1759:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
	goto st1303;
st1303:
	if ( ++p == pe )
		goto _test_eof1303;
case 1303:
#line 16476 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr1759;
		case 10: goto tr1760;
		case 13: goto tr1761;
		case 32: goto tr1759;
		case 37: goto tr1753;
		case 41: goto st0;
		case 44: goto st821;
		case 46: goto tr1754;
	}
	goto tr1752;
tr1761:
#line 771 "mfilescanner.rl"
	{
           propertyparams_.constant = true;
         }
	goto st1304;
st1304:
	if ( ++p == pe )
		goto _test_eof1304;
case 1304:
#line 16498 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr1760;
		case 37: goto tr1753;
		case 41: goto st0;
		case 44: goto st821;
		case 46: goto tr1754;
	}
	goto tr1752;
st1305:
	if ( ++p == pe )
		goto _test_eof1305;
case 1305:
	if ( (*p) == 101 )
		goto st1306;
	goto st0;
st1306:
	if ( ++p == pe )
		goto _test_eof1306;
case 1306:
	if ( (*p) == 112 )
		goto st1307;
	goto st0;
st1307:
	if ( ++p == pe )
		goto _test_eof1307;
case 1307:
	if ( (*p) == 101 )
		goto st1308;
	goto st0;
st1308:
	if ( ++p == pe )
		goto _test_eof1308;
case 1308:
	if ( (*p) == 110 )
		goto st1309;
	goto st0;
st1309:
	if ( ++p == pe )
		goto _test_eof1309;
case 1309:
	if ( (*p) == 100 )
		goto st1310;
	goto st0;
st1310:
	if ( ++p == pe )
		goto _test_eof1310;
case 1310:
	if ( (*p) == 101 )
		goto st1311;
	goto st0;
st1311:
	if ( ++p == pe )
		goto _test_eof1311;
case 1311:
	if ( (*p) == 110 )
		goto st816;
	goto st0;
st1312:
	if ( ++p == pe )
		goto _test_eof1312;
case 1312:
	if ( (*p) == 101 )
		goto st1313;
	goto st0;
st1313:
	if ( ++p == pe )
		goto _test_eof1313;
case 1313:
	if ( (*p) == 116 )
		goto st1314;
	goto st0;
st1314:
	if ( ++p == pe )
		goto _test_eof1314;
case 1314:
	if ( (*p) == 65 )
		goto st1315;
	goto st0;
st1315:
	if ( ++p == pe )
		goto _test_eof1315;
case 1315:
	if ( (*p) == 99 )
		goto st1316;
	goto st0;
st1316:
	if ( ++p == pe )
		goto _test_eof1316;
case 1316:
	if ( (*p) == 99 )
		goto st1317;
	goto st0;
st1317:
	if ( ++p == pe )
		goto _test_eof1317;
case 1317:
	if ( (*p) == 101 )
		goto st1318;
	goto st0;
st1318:
	if ( ++p == pe )
		goto _test_eof1318;
case 1318:
	if ( (*p) == 115 )
		goto st1319;
	goto st0;
st1319:
	if ( ++p == pe )
		goto _test_eof1319;
case 1319:
	if ( (*p) == 115 )
		goto st1320;
	goto st0;
tr1783:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st1320;
tr1780:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st1320;
st1320:
	if ( ++p == pe )
		goto _test_eof1320;
case 1320:
#line 16629 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st1320;
		case 32: goto st1320;
		case 37: goto tr1776;
		case 46: goto st1322;
		case 61: goto st1326;
	}
	goto st0;
tr1776:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1321;
st1321:
	if ( ++p == pe )
		goto _test_eof1321;
case 1321:
#line 16646 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1780;
	}
	goto st1321;
st1322:
	if ( ++p == pe )
		goto _test_eof1322;
case 1322:
	if ( (*p) == 46 )
		goto st1323;
	goto st0;
st1323:
	if ( ++p == pe )
		goto _test_eof1323;
case 1323:
	if ( (*p) == 46 )
		goto st1324;
	goto st0;
st1324:
	if ( ++p == pe )
		goto _test_eof1324;
case 1324:
	switch( (*p) ) {
		case 9: goto st1324;
		case 10: goto tr1783;
		case 13: goto st1325;
		case 32: goto st1324;
	}
	goto st0;
st1325:
	if ( ++p == pe )
		goto _test_eof1325;
case 1325:
	if ( (*p) == 10 )
		goto tr1783;
	goto st0;
st1326:
	if ( ++p == pe )
		goto _test_eof1326;
case 1326:
	switch( (*p) ) {
		case 9: goto st1327;
		case 32: goto st1327;
		case 37: goto tr1786;
		case 46: goto st1349;
	}
	goto st0;
st1327:
	if ( ++p == pe )
		goto _test_eof1327;
case 1327:
	switch( (*p) ) {
		case 9: goto st1327;
		case 32: goto st1327;
		case 112: goto st1328;
	}
	goto st0;
st1328:
	if ( ++p == pe )
		goto _test_eof1328;
case 1328:
	switch( (*p) ) {
		case 114: goto st1329;
		case 117: goto st1342;
	}
	goto st0;
st1329:
	if ( ++p == pe )
		goto _test_eof1329;
case 1329:
	switch( (*p) ) {
		case 105: goto st1330;
		case 111: goto st1335;
	}
	goto st0;
st1330:
	if ( ++p == pe )
		goto _test_eof1330;
case 1330:
	if ( (*p) == 118 )
		goto st1331;
	goto st0;
st1331:
	if ( ++p == pe )
		goto _test_eof1331;
case 1331:
	if ( (*p) == 97 )
		goto st1332;
	goto st0;
st1332:
	if ( ++p == pe )
		goto _test_eof1332;
case 1332:
	if ( (*p) == 116 )
		goto st1333;
	goto st0;
st1333:
	if ( ++p == pe )
		goto _test_eof1333;
case 1333:
	if ( (*p) == 101 )
		goto st1334;
	goto st0;
st1334:
	if ( ++p == pe )
		goto _test_eof1334;
case 1334:
	switch( (*p) ) {
		case 9: goto tr1797;
		case 32: goto tr1797;
		case 37: goto tr1798;
		case 44: goto tr1799;
		case 46: goto tr1800;
	}
	goto st0;
st1335:
	if ( ++p == pe )
		goto _test_eof1335;
case 1335:
	if ( (*p) == 116 )
		goto st1336;
	goto st0;
st1336:
	if ( ++p == pe )
		goto _test_eof1336;
case 1336:
	if ( (*p) == 101 )
		goto st1337;
	goto st0;
st1337:
	if ( ++p == pe )
		goto _test_eof1337;
case 1337:
	if ( (*p) == 99 )
		goto st1338;
	goto st0;
st1338:
	if ( ++p == pe )
		goto _test_eof1338;
case 1338:
	if ( (*p) == 116 )
		goto st1339;
	goto st0;
st1339:
	if ( ++p == pe )
		goto _test_eof1339;
case 1339:
	if ( (*p) == 101 )
		goto st1340;
	goto st0;
st1340:
	if ( ++p == pe )
		goto _test_eof1340;
case 1340:
	if ( (*p) == 100 )
		goto st1341;
	goto st0;
st1341:
	if ( ++p == pe )
		goto _test_eof1341;
case 1341:
	switch( (*p) ) {
		case 9: goto tr1807;
		case 32: goto tr1807;
		case 37: goto tr1808;
		case 44: goto tr1809;
		case 46: goto tr1810;
	}
	goto st0;
st1342:
	if ( ++p == pe )
		goto _test_eof1342;
case 1342:
	if ( (*p) == 98 )
		goto st1343;
	goto st0;
st1343:
	if ( ++p == pe )
		goto _test_eof1343;
case 1343:
	if ( (*p) == 108 )
		goto st1344;
	goto st0;
st1344:
	if ( ++p == pe )
		goto _test_eof1344;
case 1344:
	if ( (*p) == 105 )
		goto st1345;
	goto st0;
st1345:
	if ( ++p == pe )
		goto _test_eof1345;
case 1345:
	if ( (*p) == 99 )
		goto st1346;
	goto st0;
st1346:
	if ( ++p == pe )
		goto _test_eof1346;
case 1346:
	switch( (*p) ) {
		case 9: goto tr1815;
		case 32: goto tr1815;
		case 37: goto tr1816;
		case 44: goto tr1817;
		case 46: goto tr1818;
	}
	goto st0;
tr1786:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1347;
st1347:
	if ( ++p == pe )
		goto _test_eof1347;
case 1347:
#line 16865 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1820;
	}
	goto st1347;
tr1823:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st1348;
tr1820:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st1348;
st1348:
	if ( ++p == pe )
		goto _test_eof1348;
case 1348:
#line 16888 "mfilescanner.cc"
	if ( (*p) == 112 )
		goto st1328;
	goto st0;
st1349:
	if ( ++p == pe )
		goto _test_eof1349;
case 1349:
	if ( (*p) == 46 )
		goto st1350;
	goto st0;
st1350:
	if ( ++p == pe )
		goto _test_eof1350;
case 1350:
	if ( (*p) == 46 )
		goto st1351;
	goto st0;
st1351:
	if ( ++p == pe )
		goto _test_eof1351;
case 1351:
	switch( (*p) ) {
		case 9: goto st1351;
		case 10: goto tr1823;
		case 13: goto st1352;
		case 32: goto st1351;
	}
	goto st0;
st1352:
	if ( ++p == pe )
		goto _test_eof1352;
case 1352:
	if ( (*p) == 10 )
		goto tr1823;
	goto st0;
st1353:
	if ( ++p == pe )
		goto _test_eof1353;
case 1353:
	if ( (*p) == 105 )
		goto st1354;
	goto st0;
st1354:
	if ( ++p == pe )
		goto _test_eof1354;
case 1354:
	if ( (*p) == 100 )
		goto st1355;
	goto st0;
st1355:
	if ( ++p == pe )
		goto _test_eof1355;
case 1355:
	if ( (*p) == 100 )
		goto st1356;
	goto st0;
st1356:
	if ( ++p == pe )
		goto _test_eof1356;
case 1356:
	if ( (*p) == 101 )
		goto st1357;
	goto st0;
st1357:
	if ( ++p == pe )
		goto _test_eof1357;
case 1357:
	if ( (*p) == 110 )
		goto st817;
	goto st0;
st1358:
	if ( ++p == pe )
		goto _test_eof1358;
case 1358:
	if ( (*p) == 101 )
		goto st1359;
	goto st0;
st1359:
	if ( ++p == pe )
		goto _test_eof1359;
case 1359:
	if ( (*p) == 116 )
		goto st1360;
	goto st0;
st1360:
	if ( ++p == pe )
		goto _test_eof1360;
case 1360:
	switch( (*p) ) {
		case 65: goto st1361;
		case 79: goto st1399;
	}
	goto st0;
st1361:
	if ( ++p == pe )
		goto _test_eof1361;
case 1361:
	if ( (*p) == 99 )
		goto st1362;
	goto st0;
st1362:
	if ( ++p == pe )
		goto _test_eof1362;
case 1362:
	if ( (*p) == 99 )
		goto st1363;
	goto st0;
st1363:
	if ( ++p == pe )
		goto _test_eof1363;
case 1363:
	if ( (*p) == 101 )
		goto st1364;
	goto st0;
st1364:
	if ( ++p == pe )
		goto _test_eof1364;
case 1364:
	if ( (*p) == 115 )
		goto st1365;
	goto st0;
st1365:
	if ( ++p == pe )
		goto _test_eof1365;
case 1365:
	if ( (*p) == 115 )
		goto st1366;
	goto st0;
tr1845:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st1366;
tr1842:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st1366;
st1366:
	if ( ++p == pe )
		goto _test_eof1366;
case 1366:
#line 17034 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st1366;
		case 32: goto st1366;
		case 37: goto tr1838;
		case 46: goto st1368;
		case 61: goto st1372;
	}
	goto st0;
tr1838:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1367;
st1367:
	if ( ++p == pe )
		goto _test_eof1367;
case 1367:
#line 17051 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1842;
	}
	goto st1367;
st1368:
	if ( ++p == pe )
		goto _test_eof1368;
case 1368:
	if ( (*p) == 46 )
		goto st1369;
	goto st0;
st1369:
	if ( ++p == pe )
		goto _test_eof1369;
case 1369:
	if ( (*p) == 46 )
		goto st1370;
	goto st0;
st1370:
	if ( ++p == pe )
		goto _test_eof1370;
case 1370:
	switch( (*p) ) {
		case 9: goto st1370;
		case 10: goto tr1845;
		case 13: goto st1371;
		case 32: goto st1370;
	}
	goto st0;
st1371:
	if ( ++p == pe )
		goto _test_eof1371;
case 1371:
	if ( (*p) == 10 )
		goto tr1845;
	goto st0;
st1372:
	if ( ++p == pe )
		goto _test_eof1372;
case 1372:
	switch( (*p) ) {
		case 9: goto st1373;
		case 32: goto st1373;
		case 37: goto tr1848;
		case 46: goto st1395;
	}
	goto st0;
st1373:
	if ( ++p == pe )
		goto _test_eof1373;
case 1373:
	switch( (*p) ) {
		case 9: goto st1373;
		case 32: goto st1373;
		case 112: goto st1374;
	}
	goto st0;
st1374:
	if ( ++p == pe )
		goto _test_eof1374;
case 1374:
	switch( (*p) ) {
		case 114: goto st1375;
		case 117: goto st1388;
	}
	goto st0;
st1375:
	if ( ++p == pe )
		goto _test_eof1375;
case 1375:
	switch( (*p) ) {
		case 105: goto st1376;
		case 111: goto st1381;
	}
	goto st0;
st1376:
	if ( ++p == pe )
		goto _test_eof1376;
case 1376:
	if ( (*p) == 118 )
		goto st1377;
	goto st0;
st1377:
	if ( ++p == pe )
		goto _test_eof1377;
case 1377:
	if ( (*p) == 97 )
		goto st1378;
	goto st0;
st1378:
	if ( ++p == pe )
		goto _test_eof1378;
case 1378:
	if ( (*p) == 116 )
		goto st1379;
	goto st0;
st1379:
	if ( ++p == pe )
		goto _test_eof1379;
case 1379:
	if ( (*p) == 101 )
		goto st1380;
	goto st0;
st1380:
	if ( ++p == pe )
		goto _test_eof1380;
case 1380:
	switch( (*p) ) {
		case 9: goto tr1859;
		case 32: goto tr1859;
		case 37: goto tr1860;
		case 44: goto tr1861;
		case 46: goto tr1862;
	}
	goto st0;
st1381:
	if ( ++p == pe )
		goto _test_eof1381;
case 1381:
	if ( (*p) == 116 )
		goto st1382;
	goto st0;
st1382:
	if ( ++p == pe )
		goto _test_eof1382;
case 1382:
	if ( (*p) == 101 )
		goto st1383;
	goto st0;
st1383:
	if ( ++p == pe )
		goto _test_eof1383;
case 1383:
	if ( (*p) == 99 )
		goto st1384;
	goto st0;
st1384:
	if ( ++p == pe )
		goto _test_eof1384;
case 1384:
	if ( (*p) == 116 )
		goto st1385;
	goto st0;
st1385:
	if ( ++p == pe )
		goto _test_eof1385;
case 1385:
	if ( (*p) == 101 )
		goto st1386;
	goto st0;
st1386:
	if ( ++p == pe )
		goto _test_eof1386;
case 1386:
	if ( (*p) == 100 )
		goto st1387;
	goto st0;
st1387:
	if ( ++p == pe )
		goto _test_eof1387;
case 1387:
	switch( (*p) ) {
		case 9: goto tr1869;
		case 32: goto tr1869;
		case 37: goto tr1870;
		case 44: goto tr1871;
		case 46: goto tr1872;
	}
	goto st0;
st1388:
	if ( ++p == pe )
		goto _test_eof1388;
case 1388:
	if ( (*p) == 98 )
		goto st1389;
	goto st0;
st1389:
	if ( ++p == pe )
		goto _test_eof1389;
case 1389:
	if ( (*p) == 108 )
		goto st1390;
	goto st0;
st1390:
	if ( ++p == pe )
		goto _test_eof1390;
case 1390:
	if ( (*p) == 105 )
		goto st1391;
	goto st0;
st1391:
	if ( ++p == pe )
		goto _test_eof1391;
case 1391:
	if ( (*p) == 99 )
		goto st1392;
	goto st0;
st1392:
	if ( ++p == pe )
		goto _test_eof1392;
case 1392:
	switch( (*p) ) {
		case 9: goto tr1877;
		case 32: goto tr1877;
		case 37: goto tr1878;
		case 44: goto tr1879;
		case 46: goto tr1880;
	}
	goto st0;
tr1848:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1393;
st1393:
	if ( ++p == pe )
		goto _test_eof1393;
case 1393:
#line 17270 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1882;
	}
	goto st1393;
tr1885:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st1394;
tr1882:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st1394;
st1394:
	if ( ++p == pe )
		goto _test_eof1394;
case 1394:
#line 17293 "mfilescanner.cc"
	if ( (*p) == 112 )
		goto st1374;
	goto st0;
st1395:
	if ( ++p == pe )
		goto _test_eof1395;
case 1395:
	if ( (*p) == 46 )
		goto st1396;
	goto st0;
st1396:
	if ( ++p == pe )
		goto _test_eof1396;
case 1396:
	if ( (*p) == 46 )
		goto st1397;
	goto st0;
st1397:
	if ( ++p == pe )
		goto _test_eof1397;
case 1397:
	switch( (*p) ) {
		case 9: goto st1397;
		case 10: goto tr1885;
		case 13: goto st1398;
		case 32: goto st1397;
	}
	goto st0;
st1398:
	if ( ++p == pe )
		goto _test_eof1398;
case 1398:
	if ( (*p) == 10 )
		goto tr1885;
	goto st0;
st1399:
	if ( ++p == pe )
		goto _test_eof1399;
case 1399:
	if ( (*p) == 98 )
		goto st1400;
	goto st0;
st1400:
	if ( ++p == pe )
		goto _test_eof1400;
case 1400:
	if ( (*p) == 115 )
		goto st1401;
	goto st0;
st1401:
	if ( ++p == pe )
		goto _test_eof1401;
case 1401:
	if ( (*p) == 101 )
		goto st1402;
	goto st0;
st1402:
	if ( ++p == pe )
		goto _test_eof1402;
case 1402:
	if ( (*p) == 114 )
		goto st1403;
	goto st0;
st1403:
	if ( ++p == pe )
		goto _test_eof1403;
case 1403:
	if ( (*p) == 118 )
		goto st1404;
	goto st0;
st1404:
	if ( ++p == pe )
		goto _test_eof1404;
case 1404:
	if ( (*p) == 97 )
		goto st1405;
	goto st0;
st1405:
	if ( ++p == pe )
		goto _test_eof1405;
case 1405:
	if ( (*p) == 98 )
		goto st1406;
	goto st0;
st1406:
	if ( ++p == pe )
		goto _test_eof1406;
case 1406:
	if ( (*p) == 108 )
		goto st1407;
	goto st0;
st1407:
	if ( ++p == pe )
		goto _test_eof1407;
case 1407:
	if ( (*p) == 101 )
		goto st817;
	goto st0;
st1408:
	if ( ++p == pe )
		goto _test_eof1408;
case 1408:
	if ( (*p) == 114 )
		goto st1409;
	goto st0;
st1409:
	if ( ++p == pe )
		goto _test_eof1409;
case 1409:
	if ( (*p) == 97 )
		goto st1410;
	goto st0;
st1410:
	if ( ++p == pe )
		goto _test_eof1410;
case 1410:
	if ( (*p) == 110 )
		goto st1411;
	goto st0;
st1411:
	if ( ++p == pe )
		goto _test_eof1411;
case 1411:
	if ( (*p) == 115 )
		goto st1412;
	goto st0;
st1412:
	if ( ++p == pe )
		goto _test_eof1412;
case 1412:
	if ( (*p) == 105 )
		goto st1310;
	goto st0;
st1413:
	if ( ++p == pe )
		goto _test_eof1413;
case 1413:
	if ( (*p) == 46 )
		goto st1414;
	goto st0;
st1414:
	if ( ++p == pe )
		goto _test_eof1414;
case 1414:
	if ( (*p) == 46 )
		goto st1415;
	goto st0;
st1415:
	if ( ++p == pe )
		goto _test_eof1415;
case 1415:
	switch( (*p) ) {
		case 9: goto st1415;
		case 10: goto tr1901;
		case 13: goto st1416;
		case 32: goto st1415;
	}
	goto st0;
st1416:
	if ( ++p == pe )
		goto _test_eof1416;
case 1416:
	if ( (*p) == 10 )
		goto tr1901;
	goto st0;
st1451:
#line 1 "mfilescanner.rl"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof1451;
case 1451:
#line 17465 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st1451;
		case 32: goto st1451;
		case 37: goto tr1946;
	}
	goto tr1944;
tr1946:
#line 105 "mfilescanner.rl"
	{ tmp_p = p + 1; }
#line 897 "mfilescanner.rl"
	{
        //cout << "/*";
        p--;
        {goto st222;}
      }
	goto st1672;
st1672:
	if ( ++p == pe )
		goto _test_eof1672;
case 1672:
#line 17486 "mfilescanner.cc"
	goto tr1944;
st1452:
#line 1 "mfilescanner.rl"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof1452;
case 1452:
#line 17494 "mfilescanner.cc"
	if ( (*p) == 0 )
		goto st0;
	goto tr1947;
tr1947:
#line 1005 "mfilescanner.rl"
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
       {goto st1451;}
     }
	goto st1673;
st1673:
	if ( ++p == pe )
		goto _test_eof1673;
case 1673:
#line 17519 "mfilescanner.cc"
	goto st0;
tr1949:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st1453;
tr1957:
#line 32 "mfilescanner.rl"
	{line++;}
#line 58 "mfilescanner.rl"
	{
    cout.write(tmp_p, p-tmp_p+1);
    {stack[top++] = 1453; goto st1609;}
  }
	goto st1453;
st1453:
#line 1 "mfilescanner.rl"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof1453;
case 1453:
#line 17540 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st1453;
		case 10: goto tr1949;
		case 13: goto st1454;
		case 32: goto st1455;
		case 37: goto st1456;
		case 102: goto st1458;
	}
	goto st0;
st1454:
	if ( ++p == pe )
		goto _test_eof1454;
case 1454:
	if ( (*p) == 10 )
		goto tr1949;
	goto st0;
st1455:
	if ( ++p == pe )
		goto _test_eof1455;
case 1455:
	switch( (*p) ) {
		case 9: goto st1455;
		case 10: goto tr1949;
		case 13: goto st1454;
		case 32: goto st1455;
		case 37: goto st1456;
	}
	goto st0;
st1456:
	if ( ++p == pe )
		goto _test_eof1456;
case 1456:
	switch( (*p) ) {
		case 0: goto st0;
		case 124: goto tr1955;
	}
	goto tr1954;
tr1954:
#line 94 "mfilescanner.rl"
	{ cout << "/*"; tmp_p = p; }
	goto st1457;
tr1955:
#line 91 "mfilescanner.rl"
	{ cout << "/**"; tmp_p = p+1; }
	goto st1457;
st1457:
	if ( ++p == pe )
		goto _test_eof1457;
case 1457:
#line 17590 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1957;
	}
	goto st1457;
st1458:
	if ( ++p == pe )
		goto _test_eof1458;
case 1458:
	if ( (*p) == 117 )
		goto st1459;
	goto st0;
st1459:
	if ( ++p == pe )
		goto _test_eof1459;
case 1459:
	if ( (*p) == 110 )
		goto st1460;
	goto st0;
st1460:
	if ( ++p == pe )
		goto _test_eof1460;
case 1460:
	if ( (*p) == 99 )
		goto st1461;
	goto st0;
st1461:
	if ( ++p == pe )
		goto _test_eof1461;
case 1461:
	if ( (*p) == 116 )
		goto st1462;
	goto st0;
st1462:
	if ( ++p == pe )
		goto _test_eof1462;
case 1462:
	if ( (*p) == 105 )
		goto st1463;
	goto st0;
st1463:
	if ( ++p == pe )
		goto _test_eof1463;
case 1463:
	if ( (*p) == 111 )
		goto st1464;
	goto st0;
st1464:
	if ( ++p == pe )
		goto _test_eof1464;
case 1464:
	if ( (*p) == 110 )
		goto st1465;
	goto st0;
tr1975:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st1465;
tr1972:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st1465;
st1465:
	if ( ++p == pe )
		goto _test_eof1465;
case 1465:
#line 17662 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st1465;
		case 32: goto st1465;
		case 37: goto tr1965;
		case 46: goto st1467;
		case 91: goto st1535;
		case 95: goto tr1967;
		case 103: goto tr1969;
		case 115: goto tr1970;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1967;
	} else if ( (*p) >= 65 )
		goto tr1967;
	goto st0;
tr1965:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1466;
st1466:
	if ( ++p == pe )
		goto _test_eof1466;
case 1466:
#line 17687 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1972;
	}
	goto st1466;
st1467:
	if ( ++p == pe )
		goto _test_eof1467;
case 1467:
	if ( (*p) == 46 )
		goto st1468;
	goto st0;
st1468:
	if ( ++p == pe )
		goto _test_eof1468;
case 1468:
	if ( (*p) == 46 )
		goto st1469;
	goto st0;
st1469:
	if ( ++p == pe )
		goto _test_eof1469;
case 1469:
	switch( (*p) ) {
		case 9: goto st1469;
		case 10: goto tr1975;
		case 13: goto st1470;
		case 32: goto st1469;
	}
	goto st0;
st1470:
	if ( ++p == pe )
		goto _test_eof1470;
case 1470:
	if ( (*p) == 10 )
		goto tr1975;
	goto st0;
tr1967:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st1471;
st1471:
	if ( ++p == pe )
		goto _test_eof1471;
case 1471:
#line 17733 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr1977;
		case 10: goto tr1978;
		case 13: goto tr1979;
		case 32: goto tr1977;
		case 37: goto tr1980;
		case 40: goto tr1981;
		case 46: goto tr1982;
		case 59: goto tr1984;
		case 61: goto tr1985;
		case 95: goto st1471;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st1471;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st1471;
	} else
		goto st1471;
	goto st0;
tr1977:
#line 175 "mfilescanner.rl"
	{
             string s(tmp_p, p - tmp_p);
             returnlist_.push_back(s);
             // add an empty docu block for single return value \a s
             return_list_[s] = DocuBlock();
           }
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
#line 932 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
	goto st1472;
tr1986:
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1472;
st1472:
	if ( ++p == pe )
		goto _test_eof1472;
case 1472:
#line 17779 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr1986;
		case 10: goto tr1987;
		case 13: goto st1473;
		case 32: goto tr1986;
		case 37: goto tr1989;
		case 40: goto tr1990;
		case 46: goto st1516;
		case 59: goto st1520;
		case 61: goto tr1993;
	}
	goto st0;
tr1978:
#line 932 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
#line 32 "mfilescanner.rl"
	{line++;}
#line 991 "mfilescanner.rl"
	{

                         if(!is_first_function_)
                           cout << "mtoc_subst_" << fnname_ << "_tsbus_cotm_";
                         else
                           cout << "noret::substitute ";
                         cout << cfuncname_ << "() {\n";
                         {goto st1451;}
                        }
	goto st1674;
tr1987:
#line 32 "mfilescanner.rl"
	{line++;}
#line 991 "mfilescanner.rl"
	{

                         if(!is_first_function_)
                           cout << "mtoc_subst_" << fnname_ << "_tsbus_cotm_";
                         else
                           cout << "noret::substitute ";
                         cout << cfuncname_ << "() {\n";
                         {goto st1451;}
                        }
	goto st1674;
tr2008:
#line 32 "mfilescanner.rl"
	{line++;}
#line 982 "mfilescanner.rl"
	{
             if(is_class_ && class_part_ == Method)
               cout << methodparams_.ccpostfix() << "\n";
             else
               cout << " {\n";
             // check for documentation block
             {goto st1451;}
           }
	goto st1674;
st1674:
	if ( ++p == pe )
		goto _test_eof1674;
case 1674:
#line 17842 "mfilescanner.cc"
	goto st0;
tr1979:
#line 932 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
	goto st1473;
st1473:
	if ( ++p == pe )
		goto _test_eof1473;
case 1473:
#line 17855 "mfilescanner.cc"
	if ( (*p) == 10 )
		goto tr1987;
	goto st0;
tr1989:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1474;
tr1980:
#line 932 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1474;
st1474:
	if ( ++p == pe )
		goto _test_eof1474;
case 1474:
#line 17876 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1995;
	}
	goto st1474;
tr2070:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st1475;
tr1995:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st1475;
tr2083:
#line 932 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
	goto st1475;
st1475:
	if ( ++p == pe )
		goto _test_eof1475;
case 1475:
#line 17906 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st1475;
		case 10: goto tr1987;
		case 13: goto st1473;
		case 32: goto st1475;
		case 37: goto tr1989;
		case 40: goto tr1990;
		case 46: goto st1516;
		case 59: goto st1520;
	}
	goto st0;
tr1981:
#line 932 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
#line 940 "mfilescanner.rl"
	{
                 if(is_getter_ || is_setter_)
                 {
                  cout << "/*\n";
                 }
                 if(is_class_ && class_part_ == Method)
                   cout << methodparams_.ccprefix();

                 // no return values?
                 if(!opt)
                 {
                   cout << "noret::substitute ";
                   opt=false;
                 }
                 else
                 {
                   // do we have a constructor?
                   if(is_class_ && (cfuncname_ == classname_))
                     returnlist_.clear();
                   else{
                     if(returnlist_.size() == 1)
                       cout << "ret::substitutestart::" << returnlist_[0] << "::retsubstituteend ";
                     else
                     {
                       cout << "rets::substitutestart::";
                       for(size_t i=0; i<returnlist_.size(); ++i)
                       {
                         cout << returnlist_[i] << "::";
                       }
                       cout << "retssubstituteend ";
                     }
                   }
                 }
                 if(!is_first_function_)
                   cout << "mtoc_subst_" << fnname_ << "_tsbus_cotm_";
                 cout << cfuncname_ << '(';
                 }
	goto st1476;
tr1990:
#line 940 "mfilescanner.rl"
	{
                 if(is_getter_ || is_setter_)
                 {
                  cout << "/*\n";
                 }
                 if(is_class_ && class_part_ == Method)
                   cout << methodparams_.ccprefix();

                 // no return values?
                 if(!opt)
                 {
                   cout << "noret::substitute ";
                   opt=false;
                 }
                 else
                 {
                   // do we have a constructor?
                   if(is_class_ && (cfuncname_ == classname_))
                     returnlist_.clear();
                   else{
                     if(returnlist_.size() == 1)
                       cout << "ret::substitutestart::" << returnlist_[0] << "::retsubstituteend ";
                     else
                     {
                       cout << "rets::substitutestart::";
                       for(size_t i=0; i<returnlist_.size(); ++i)
                       {
                         cout << returnlist_[i] << "::";
                       }
                       cout << "retssubstituteend ";
                     }
                   }
                 }
                 if(!is_first_function_)
                   cout << "mtoc_subst_" << fnname_ << "_tsbus_cotm_";
                 cout << cfuncname_ << '(';
                 }
	goto st1476;
st1476:
	if ( ++p == pe )
		goto _test_eof1476;
case 1476:
#line 18007 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st1477;
		case 10: goto tr1998;
		case 32: goto st1477;
		case 37: goto tr1999;
		case 41: goto tr2000;
		case 44: goto tr1998;
		case 46: goto st1486;
		case 61: goto st1500;
		case 95: goto tr2003;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2003;
	} else if ( (*p) >= 65 )
		goto tr2003;
	goto st0;
tr2020:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st1477;
tr2006:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st1477;
tr1998:
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1477;
tr2030:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1477;
tr2037:
#line 139 "mfilescanner.rl"
	{
         // do not print this pointer
         if(!paramlist_.empty() || !is_class_ || class_part_ != Method)
         {
           string s(tmp_p, p - tmp_p);
           // add an empty docu block for parameter \a s
           param_list_[s] = DocuBlock();
           paramlist_.push_back(s);
           cout << "matlabtypesubstitute " << s;
         }
       }
	goto st1477;
tr2038:
#line 139 "mfilescanner.rl"
	{
         // do not print this pointer
         if(!paramlist_.empty() || !is_class_ || class_part_ != Method)
         {
           string s(tmp_p, p - tmp_p);
           // add an empty docu block for parameter \a s
           param_list_[s] = DocuBlock();
           paramlist_.push_back(s);
           cout << "matlabtypesubstitute " << s;
         }
       }
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1477;
st1477:
	if ( ++p == pe )
		goto _test_eof1477;
case 1477:
#line 18087 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st1477;
		case 10: goto tr1998;
		case 32: goto st1477;
		case 37: goto tr1999;
		case 41: goto tr2000;
		case 44: goto tr1998;
		case 46: goto st1486;
		case 61: goto st1490;
		case 95: goto tr2003;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2003;
	} else if ( (*p) >= 65 )
		goto tr2003;
	goto st0;
tr1999:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1478;
tr2039:
#line 139 "mfilescanner.rl"
	{
         // do not print this pointer
         if(!paramlist_.empty() || !is_class_ || class_part_ != Method)
         {
           string s(tmp_p, p - tmp_p);
           // add an empty docu block for parameter \a s
           param_list_[s] = DocuBlock();
           paramlist_.push_back(s);
           cout << "matlabtypesubstitute " << s;
         }
       }
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1478;
st1478:
	if ( ++p == pe )
		goto _test_eof1478;
case 1478:
#line 18129 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr2006;
	}
	goto st1478;
tr2016:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st1479;
tr2013:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st1479;
tr2000:
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1479;
tr2040:
#line 139 "mfilescanner.rl"
	{
         // do not print this pointer
         if(!paramlist_.empty() || !is_class_ || class_part_ != Method)
         {
           string s(tmp_p, p - tmp_p);
           // add an empty docu block for parameter \a s
           param_list_[s] = DocuBlock();
           paramlist_.push_back(s);
           cout << "matlabtypesubstitute " << s;
         }
       }
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1479;
st1479:
	if ( ++p == pe )
		goto _test_eof1479;
case 1479:
#line 18172 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st1479;
		case 10: goto tr2008;
		case 13: goto st1480;
		case 32: goto st1479;
		case 37: goto tr2010;
		case 46: goto st1482;
		case 59: goto st1479;
	}
	goto st0;
st1480:
	if ( ++p == pe )
		goto _test_eof1480;
case 1480:
	if ( (*p) == 10 )
		goto tr2008;
	goto st0;
tr2010:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1481;
st1481:
	if ( ++p == pe )
		goto _test_eof1481;
case 1481:
#line 18198 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr2013;
	}
	goto st1481;
st1482:
	if ( ++p == pe )
		goto _test_eof1482;
case 1482:
	if ( (*p) == 46 )
		goto st1483;
	goto st0;
st1483:
	if ( ++p == pe )
		goto _test_eof1483;
case 1483:
	if ( (*p) == 46 )
		goto st1484;
	goto st0;
st1484:
	if ( ++p == pe )
		goto _test_eof1484;
case 1484:
	switch( (*p) ) {
		case 9: goto st1484;
		case 10: goto tr2016;
		case 13: goto st1485;
		case 32: goto st1484;
	}
	goto st0;
st1485:
	if ( ++p == pe )
		goto _test_eof1485;
case 1485:
	if ( (*p) == 10 )
		goto tr2016;
	goto st0;
tr2041:
#line 139 "mfilescanner.rl"
	{
         // do not print this pointer
         if(!paramlist_.empty() || !is_class_ || class_part_ != Method)
         {
           string s(tmp_p, p - tmp_p);
           // add an empty docu block for parameter \a s
           param_list_[s] = DocuBlock();
           paramlist_.push_back(s);
           cout << "matlabtypesubstitute " << s;
         }
       }
	goto st1486;
st1486:
	if ( ++p == pe )
		goto _test_eof1486;
case 1486:
#line 18254 "mfilescanner.cc"
	if ( (*p) == 46 )
		goto st1487;
	goto st0;
st1487:
	if ( ++p == pe )
		goto _test_eof1487;
case 1487:
	if ( (*p) == 46 )
		goto st1488;
	goto st0;
st1488:
	if ( ++p == pe )
		goto _test_eof1488;
case 1488:
	switch( (*p) ) {
		case 9: goto st1488;
		case 10: goto tr2020;
		case 13: goto st1489;
		case 32: goto st1488;
	}
	goto st0;
st1489:
	if ( ++p == pe )
		goto _test_eof1489;
case 1489:
	if ( (*p) == 10 )
		goto tr2020;
	goto st0;
tr2022:
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1490;
tr2026:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1490;
tr2035:
#line 32 "mfilescanner.rl"
	{line++;}
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1490;
st1490:
	if ( ++p == pe )
		goto _test_eof1490;
case 1490:
#line 18308 "mfilescanner.cc"
	switch( (*p) ) {
		case 37: goto tr2023;
		case 41: goto tr2000;
		case 44: goto tr1998;
		case 46: goto tr2024;
	}
	goto tr2022;
tr2025:
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1491;
tr2023:
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1491;
st1491:
	if ( ++p == pe )
		goto _test_eof1491;
case 1491:
#line 18330 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr2022;
		case 10: goto tr2026;
		case 37: goto tr2023;
		case 41: goto st1478;
		case 44: goto tr2027;
		case 61: goto tr2028;
	}
	goto tr2025;
tr2027:
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1492;
st1492:
	if ( ++p == pe )
		goto _test_eof1492;
case 1492:
#line 18348 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1492;
		case 10: goto tr2030;
		case 32: goto st1492;
		case 37: goto tr1999;
		case 44: goto tr2027;
		case 61: goto st1491;
	}
	goto st1478;
tr2028:
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1493;
st1493:
	if ( ++p == pe )
		goto _test_eof1493;
case 1493:
#line 18367 "mfilescanner.cc"
	switch( (*p) ) {
		case 37: goto tr2023;
		case 41: goto st1478;
		case 44: goto tr2027;
		case 46: goto tr2024;
	}
	goto tr2022;
tr2024:
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1494;
st1494:
	if ( ++p == pe )
		goto _test_eof1494;
case 1494:
#line 18383 "mfilescanner.cc"
	switch( (*p) ) {
		case 37: goto tr2023;
		case 41: goto tr2000;
		case 44: goto tr1998;
		case 46: goto tr2032;
	}
	goto tr2022;
tr2032:
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1495;
st1495:
	if ( ++p == pe )
		goto _test_eof1495;
case 1495:
#line 18399 "mfilescanner.cc"
	switch( (*p) ) {
		case 37: goto tr2023;
		case 41: goto tr2000;
		case 44: goto tr1998;
		case 46: goto tr2033;
	}
	goto tr2022;
tr2033:
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1496;
st1496:
	if ( ++p == pe )
		goto _test_eof1496;
case 1496:
#line 18415 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr2034;
		case 10: goto tr2035;
		case 13: goto tr2036;
		case 32: goto tr2034;
		case 37: goto tr2023;
		case 41: goto tr2000;
		case 44: goto tr1998;
		case 46: goto tr2033;
	}
	goto tr2022;
tr2034:
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1497;
st1497:
	if ( ++p == pe )
		goto _test_eof1497;
case 1497:
#line 18435 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr2034;
		case 10: goto tr2035;
		case 13: goto tr2036;
		case 32: goto tr2034;
		case 37: goto tr2023;
		case 41: goto tr2000;
		case 44: goto tr1998;
		case 46: goto tr2024;
	}
	goto tr2022;
tr2036:
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1498;
st1498:
	if ( ++p == pe )
		goto _test_eof1498;
case 1498:
#line 18455 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr2035;
		case 37: goto tr2023;
		case 41: goto tr2000;
		case 44: goto tr1998;
		case 46: goto tr2024;
	}
	goto tr2022;
tr2003:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st1499;
st1499:
	if ( ++p == pe )
		goto _test_eof1499;
case 1499:
#line 18472 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr2037;
		case 10: goto tr2038;
		case 32: goto tr2037;
		case 37: goto tr2039;
		case 41: goto tr2040;
		case 44: goto tr2038;
		case 46: goto tr2041;
		case 61: goto tr2043;
		case 95: goto st1499;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st1499;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st1499;
	} else
		goto st1499;
	goto st0;
tr2044:
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1500;
tr2048:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1500;
tr2066:
#line 32 "mfilescanner.rl"
	{line++;}
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1500;
tr2043:
#line 139 "mfilescanner.rl"
	{
         // do not print this pointer
         if(!paramlist_.empty() || !is_class_ || class_part_ != Method)
         {
           string s(tmp_p, p - tmp_p);
           // add an empty docu block for parameter \a s
           param_list_[s] = DocuBlock();
           paramlist_.push_back(s);
           cout << "matlabtypesubstitute " << s;
         }
       }
	goto st1500;
st1500:
	if ( ++p == pe )
		goto _test_eof1500;
case 1500:
#line 18532 "mfilescanner.cc"
	switch( (*p) ) {
		case 37: goto tr2045;
		case 41: goto tr2000;
		case 44: goto tr1998;
		case 46: goto tr2046;
		case 61: goto tr2022;
	}
	goto tr2044;
tr2047:
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1501;
tr2045:
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1501;
st1501:
	if ( ++p == pe )
		goto _test_eof1501;
case 1501:
#line 18555 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr2044;
		case 10: goto tr2048;
		case 37: goto tr2045;
		case 41: goto st1478;
		case 44: goto tr2049;
		case 61: goto tr2050;
	}
	goto tr2047;
tr2049:
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1502;
st1502:
	if ( ++p == pe )
		goto _test_eof1502;
case 1502:
#line 18573 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1502;
		case 10: goto tr2030;
		case 32: goto st1502;
		case 37: goto tr1999;
		case 44: goto tr2049;
		case 61: goto st1503;
	}
	goto st1478;
tr2053:
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1503;
tr2055:
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1503;
st1503:
	if ( ++p == pe )
		goto _test_eof1503;
case 1503:
#line 18598 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr2022;
		case 10: goto tr2054;
		case 37: goto tr2055;
		case 41: goto st1478;
		case 44: goto tr2049;
	}
	goto tr2053;
tr2056:
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1504;
tr2054:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1504;
tr2061:
#line 32 "mfilescanner.rl"
	{line++;}
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1504;
st1504:
	if ( ++p == pe )
		goto _test_eof1504;
case 1504:
#line 18632 "mfilescanner.cc"
	switch( (*p) ) {
		case 32: goto tr2056;
		case 37: goto tr2055;
		case 41: goto tr2000;
		case 44: goto tr1998;
		case 46: goto tr2057;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto tr2056;
	goto tr2022;
tr2057:
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1505;
st1505:
	if ( ++p == pe )
		goto _test_eof1505;
case 1505:
#line 18651 "mfilescanner.cc"
	switch( (*p) ) {
		case 37: goto tr2023;
		case 41: goto tr2000;
		case 44: goto tr1998;
		case 46: goto tr2058;
	}
	goto tr2022;
tr2058:
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1506;
st1506:
	if ( ++p == pe )
		goto _test_eof1506;
case 1506:
#line 18667 "mfilescanner.cc"
	switch( (*p) ) {
		case 37: goto tr2023;
		case 41: goto tr2000;
		case 44: goto tr1998;
		case 46: goto tr2059;
	}
	goto tr2022;
tr2059:
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1507;
st1507:
	if ( ++p == pe )
		goto _test_eof1507;
case 1507:
#line 18683 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr2060;
		case 10: goto tr2061;
		case 13: goto tr2062;
		case 32: goto tr2060;
		case 37: goto tr2023;
		case 41: goto tr2000;
		case 44: goto tr1998;
		case 46: goto tr2033;
	}
	goto tr2022;
tr2060:
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1508;
st1508:
	if ( ++p == pe )
		goto _test_eof1508;
case 1508:
#line 18703 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr2060;
		case 10: goto tr2061;
		case 13: goto tr2062;
		case 32: goto tr2060;
		case 37: goto tr2023;
		case 41: goto tr2000;
		case 44: goto tr1998;
		case 46: goto tr2024;
	}
	goto tr2022;
tr2062:
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1509;
st1509:
	if ( ++p == pe )
		goto _test_eof1509;
case 1509:
#line 18723 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr2061;
		case 37: goto tr2023;
		case 41: goto tr2000;
		case 44: goto tr1998;
		case 46: goto tr2024;
	}
	goto tr2022;
tr2050:
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1510;
st1510:
	if ( ++p == pe )
		goto _test_eof1510;
case 1510:
#line 18740 "mfilescanner.cc"
	switch( (*p) ) {
		case 37: goto tr2023;
		case 41: goto st1478;
		case 44: goto tr2049;
		case 46: goto tr2024;
	}
	goto tr2022;
tr2046:
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1511;
st1511:
	if ( ++p == pe )
		goto _test_eof1511;
case 1511:
#line 18756 "mfilescanner.cc"
	switch( (*p) ) {
		case 37: goto tr2045;
		case 41: goto tr2000;
		case 44: goto tr1998;
		case 46: goto tr2063;
		case 61: goto tr2022;
	}
	goto tr2044;
tr2063:
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1512;
st1512:
	if ( ++p == pe )
		goto _test_eof1512;
case 1512:
#line 18773 "mfilescanner.cc"
	switch( (*p) ) {
		case 37: goto tr2045;
		case 41: goto tr2000;
		case 44: goto tr1998;
		case 46: goto tr2064;
		case 61: goto tr2022;
	}
	goto tr2044;
tr2064:
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1513;
st1513:
	if ( ++p == pe )
		goto _test_eof1513;
case 1513:
#line 18790 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr2065;
		case 10: goto tr2066;
		case 13: goto tr2067;
		case 32: goto tr2065;
		case 37: goto tr2045;
		case 41: goto tr2000;
		case 44: goto tr1998;
		case 46: goto tr2064;
		case 61: goto tr2022;
	}
	goto tr2044;
tr2065:
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1514;
st1514:
	if ( ++p == pe )
		goto _test_eof1514;
case 1514:
#line 18811 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr2065;
		case 10: goto tr2066;
		case 13: goto tr2067;
		case 32: goto tr2065;
		case 37: goto tr2045;
		case 41: goto tr2000;
		case 44: goto tr1998;
		case 46: goto tr2046;
		case 61: goto tr2022;
	}
	goto tr2044;
tr2067:
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1515;
st1515:
	if ( ++p == pe )
		goto _test_eof1515;
case 1515:
#line 18832 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr2066;
		case 37: goto tr2045;
		case 41: goto tr2000;
		case 44: goto tr1998;
		case 46: goto tr2046;
		case 61: goto tr2022;
	}
	goto tr2044;
tr1982:
#line 932 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
	goto st1516;
st1516:
	if ( ++p == pe )
		goto _test_eof1516;
case 1516:
#line 18853 "mfilescanner.cc"
	if ( (*p) == 46 )
		goto st1517;
	goto st0;
st1517:
	if ( ++p == pe )
		goto _test_eof1517;
case 1517:
	if ( (*p) == 46 )
		goto st1518;
	goto st0;
st1518:
	if ( ++p == pe )
		goto _test_eof1518;
case 1518:
	switch( (*p) ) {
		case 9: goto st1518;
		case 10: goto tr2070;
		case 13: goto st1519;
		case 32: goto st1518;
	}
	goto st0;
st1519:
	if ( ++p == pe )
		goto _test_eof1519;
case 1519:
	if ( (*p) == 10 )
		goto tr2070;
	goto st0;
tr1984:
#line 932 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
	goto st1520;
st1520:
	if ( ++p == pe )
		goto _test_eof1520;
case 1520:
#line 18893 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr1987;
		case 13: goto st1473;
	}
	goto st0;
tr1985:
#line 175 "mfilescanner.rl"
	{
             string s(tmp_p, p - tmp_p);
             returnlist_.push_back(s);
             // add an empty docu block for single return value \a s
             return_list_[s] = DocuBlock();
           }
#line 927 "mfilescanner.rl"
	{opt=true;}
	goto st1521;
tr1993:
#line 927 "mfilescanner.rl"
	{opt=true;}
	goto st1521;
tr2078:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 927 "mfilescanner.rl"
	{opt=true;}
	goto st1521;
tr2081:
#line 32 "mfilescanner.rl"
	{line++;}
#line 927 "mfilescanner.rl"
	{opt=true;}
	goto st1521;
st1521:
	if ( ++p == pe )
		goto _test_eof1521;
case 1521:
#line 18935 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr1993;
		case 32: goto tr1993;
		case 37: goto tr2072;
		case 46: goto st1523;
		case 95: goto tr2074;
		case 103: goto tr2075;
		case 115: goto tr2076;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2074;
	} else if ( (*p) >= 65 )
		goto tr2074;
	goto st0;
tr2072:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1522;
st1522:
	if ( ++p == pe )
		goto _test_eof1522;
case 1522:
#line 18959 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr2078;
	}
	goto st1522;
st1523:
	if ( ++p == pe )
		goto _test_eof1523;
case 1523:
	if ( (*p) == 46 )
		goto st1524;
	goto st0;
st1524:
	if ( ++p == pe )
		goto _test_eof1524;
case 1524:
	if ( (*p) == 46 )
		goto st1525;
	goto st0;
st1525:
	if ( ++p == pe )
		goto _test_eof1525;
case 1525:
	switch( (*p) ) {
		case 9: goto st1525;
		case 10: goto tr2081;
		case 13: goto st1526;
		case 32: goto st1525;
	}
	goto st0;
st1526:
	if ( ++p == pe )
		goto _test_eof1526;
case 1526:
	if ( (*p) == 10 )
		goto tr2081;
	goto st0;
tr2074:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st1527;
st1527:
	if ( ++p == pe )
		goto _test_eof1527;
case 1527:
#line 19005 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr2083;
		case 10: goto tr1978;
		case 13: goto tr1979;
		case 32: goto tr2083;
		case 37: goto tr1980;
		case 40: goto tr1981;
		case 46: goto tr1982;
		case 59: goto tr1984;
		case 95: goto st1527;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st1527;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st1527;
	} else
		goto st1527;
	goto st0;
tr2075:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st1528;
st1528:
	if ( ++p == pe )
		goto _test_eof1528;
case 1528:
#line 19034 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr2083;
		case 10: goto tr1978;
		case 13: goto tr1979;
		case 32: goto tr2083;
		case 37: goto tr1980;
		case 40: goto tr1981;
		case 46: goto tr1982;
		case 59: goto tr1984;
		case 95: goto st1527;
		case 101: goto st1529;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st1527;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st1527;
	} else
		goto st1527;
	goto st0;
st1529:
	if ( ++p == pe )
		goto _test_eof1529;
case 1529:
	switch( (*p) ) {
		case 9: goto tr2083;
		case 10: goto tr1978;
		case 13: goto tr1979;
		case 32: goto tr2083;
		case 37: goto tr1980;
		case 40: goto tr1981;
		case 46: goto tr1982;
		case 59: goto tr1984;
		case 95: goto st1527;
		case 116: goto st1530;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st1527;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st1527;
	} else
		goto st1527;
	goto st0;
st1530:
	if ( ++p == pe )
		goto _test_eof1530;
case 1530:
	switch( (*p) ) {
		case 9: goto tr2083;
		case 10: goto tr1978;
		case 13: goto tr1979;
		case 32: goto tr2083;
		case 37: goto tr1980;
		case 40: goto tr1981;
		case 46: goto tr2087;
		case 59: goto tr1984;
		case 95: goto st1527;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st1527;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st1527;
	} else
		goto st1527;
	goto st0;
tr2087:
#line 929 "mfilescanner.rl"
	{is_getter_ = true;}
#line 932 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
	goto st1531;
tr2090:
#line 929 "mfilescanner.rl"
	{is_setter_=true;}
#line 932 "mfilescanner.rl"
	{
            cfuncname_.assign(tmp_p, p - tmp_p);
            is_script_ = false;
          }
	goto st1531;
st1531:
	if ( ++p == pe )
		goto _test_eof1531;
case 1531:
#line 19127 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto st1517;
		case 95: goto tr2074;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2074;
	} else if ( (*p) >= 65 )
		goto tr2074;
	goto st0;
tr2076:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st1532;
st1532:
	if ( ++p == pe )
		goto _test_eof1532;
case 1532:
#line 19146 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr2083;
		case 10: goto tr1978;
		case 13: goto tr1979;
		case 32: goto tr2083;
		case 37: goto tr1980;
		case 40: goto tr1981;
		case 46: goto tr1982;
		case 59: goto tr1984;
		case 95: goto st1527;
		case 101: goto st1533;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st1527;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st1527;
	} else
		goto st1527;
	goto st0;
st1533:
	if ( ++p == pe )
		goto _test_eof1533;
case 1533:
	switch( (*p) ) {
		case 9: goto tr2083;
		case 10: goto tr1978;
		case 13: goto tr1979;
		case 32: goto tr2083;
		case 37: goto tr1980;
		case 40: goto tr1981;
		case 46: goto tr1982;
		case 59: goto tr1984;
		case 95: goto st1527;
		case 116: goto st1534;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st1527;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st1527;
	} else
		goto st1527;
	goto st0;
st1534:
	if ( ++p == pe )
		goto _test_eof1534;
case 1534:
	switch( (*p) ) {
		case 9: goto tr2083;
		case 10: goto tr1978;
		case 13: goto tr1979;
		case 32: goto tr2083;
		case 37: goto tr1980;
		case 40: goto tr1981;
		case 46: goto tr2090;
		case 59: goto tr1984;
		case 95: goto st1527;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st1527;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st1527;
	} else
		goto st1527;
	goto st0;
tr2099:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st1535;
tr2096:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st1535;
tr2101:
#line 158 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            returnlist_.push_back(s);
            // add an empty docu block for return value \a s
            return_list_[s] = DocuBlock();
          }
	goto st1535;
st1535:
	if ( ++p == pe )
		goto _test_eof1535;
case 1535:
#line 19243 "mfilescanner.cc"
	switch( (*p) ) {
		case 32: goto st1535;
		case 37: goto tr2091;
		case 44: goto st1535;
		case 46: goto st1537;
		case 93: goto st1542;
		case 95: goto tr2093;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto st1535;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2093;
	} else
		goto tr2093;
	goto st0;
tr2091:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1536;
tr2102:
#line 158 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            returnlist_.push_back(s);
            // add an empty docu block for return value \a s
            return_list_[s] = DocuBlock();
          }
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1536;
st1536:
	if ( ++p == pe )
		goto _test_eof1536;
case 1536:
#line 19280 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr2096;
	}
	goto st1536;
tr2103:
#line 158 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            returnlist_.push_back(s);
            // add an empty docu block for return value \a s
            return_list_[s] = DocuBlock();
          }
	goto st1537;
st1537:
	if ( ++p == pe )
		goto _test_eof1537;
case 1537:
#line 19299 "mfilescanner.cc"
	if ( (*p) == 46 )
		goto st1538;
	goto st0;
st1538:
	if ( ++p == pe )
		goto _test_eof1538;
case 1538:
	if ( (*p) == 46 )
		goto st1539;
	goto st0;
st1539:
	if ( ++p == pe )
		goto _test_eof1539;
case 1539:
	switch( (*p) ) {
		case 9: goto st1539;
		case 10: goto tr2099;
		case 13: goto st1540;
		case 32: goto st1539;
	}
	goto st0;
st1540:
	if ( ++p == pe )
		goto _test_eof1540;
case 1540:
	if ( (*p) == 10 )
		goto tr2099;
	goto st0;
tr2093:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st1541;
st1541:
	if ( ++p == pe )
		goto _test_eof1541;
case 1541:
#line 19336 "mfilescanner.cc"
	switch( (*p) ) {
		case 32: goto tr2101;
		case 37: goto tr2102;
		case 44: goto tr2101;
		case 46: goto tr2103;
		case 93: goto tr2105;
		case 95: goto st1541;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr2101;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st1541;
		} else if ( (*p) >= 65 )
			goto st1541;
	} else
		goto st1541;
	goto st0;
tr2106:
#line 63 "mfilescanner.rl"
	{ cout << (*p); }
	goto st1542;
tr2105:
#line 158 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            returnlist_.push_back(s);
            // add an empty docu block for return value \a s
            return_list_[s] = DocuBlock();
          }
	goto st1542;
st1542:
	if ( ++p == pe )
		goto _test_eof1542;
case 1542:
#line 19374 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr2106;
		case 32: goto tr2106;
		case 61: goto tr1993;
	}
	goto st0;
tr1969:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st1543;
st1543:
	if ( ++p == pe )
		goto _test_eof1543;
case 1543:
#line 19389 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr1977;
		case 10: goto tr1978;
		case 13: goto tr1979;
		case 32: goto tr1977;
		case 37: goto tr1980;
		case 40: goto tr1981;
		case 46: goto tr1982;
		case 59: goto tr1984;
		case 61: goto tr1985;
		case 95: goto st1471;
		case 101: goto st1544;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st1471;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st1471;
	} else
		goto st1471;
	goto st0;
st1544:
	if ( ++p == pe )
		goto _test_eof1544;
case 1544:
	switch( (*p) ) {
		case 9: goto tr1977;
		case 10: goto tr1978;
		case 13: goto tr1979;
		case 32: goto tr1977;
		case 37: goto tr1980;
		case 40: goto tr1981;
		case 46: goto tr1982;
		case 59: goto tr1984;
		case 61: goto tr1985;
		case 95: goto st1471;
		case 116: goto st1545;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st1471;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st1471;
	} else
		goto st1471;
	goto st0;
st1545:
	if ( ++p == pe )
		goto _test_eof1545;
case 1545:
	switch( (*p) ) {
		case 9: goto tr1977;
		case 10: goto tr1978;
		case 13: goto tr1979;
		case 32: goto tr1977;
		case 37: goto tr1980;
		case 40: goto tr1981;
		case 46: goto tr2087;
		case 59: goto tr1984;
		case 61: goto tr1985;
		case 95: goto st1471;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st1471;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st1471;
	} else
		goto st1471;
	goto st0;
tr1970:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st1546;
st1546:
	if ( ++p == pe )
		goto _test_eof1546;
case 1546:
#line 19471 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr1977;
		case 10: goto tr1978;
		case 13: goto tr1979;
		case 32: goto tr1977;
		case 37: goto tr1980;
		case 40: goto tr1981;
		case 46: goto tr1982;
		case 59: goto tr1984;
		case 61: goto tr1985;
		case 95: goto st1471;
		case 101: goto st1547;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st1471;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st1471;
	} else
		goto st1471;
	goto st0;
st1547:
	if ( ++p == pe )
		goto _test_eof1547;
case 1547:
	switch( (*p) ) {
		case 9: goto tr1977;
		case 10: goto tr1978;
		case 13: goto tr1979;
		case 32: goto tr1977;
		case 37: goto tr1980;
		case 40: goto tr1981;
		case 46: goto tr1982;
		case 59: goto tr1984;
		case 61: goto tr1985;
		case 95: goto st1471;
		case 116: goto st1548;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st1471;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st1471;
	} else
		goto st1471;
	goto st0;
st1548:
	if ( ++p == pe )
		goto _test_eof1548;
case 1548:
	switch( (*p) ) {
		case 9: goto tr1977;
		case 10: goto tr1978;
		case 13: goto tr1979;
		case 32: goto tr1977;
		case 37: goto tr1980;
		case 40: goto tr1981;
		case 46: goto tr2090;
		case 59: goto tr1984;
		case 61: goto tr1985;
		case 95: goto st1471;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st1471;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st1471;
	} else
		goto st1471;
	goto st0;
tr2112:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st1549;
tr2120:
#line 32 "mfilescanner.rl"
	{line++;}
#line 58 "mfilescanner.rl"
	{
    cout.write(tmp_p, p-tmp_p+1);
    {stack[top++] = 1549; goto st1609;}
  }
	goto st1549;
st1549:
#line 1 "mfilescanner.rl"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof1549;
case 1549:
#line 19564 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st1549;
		case 10: goto tr2112;
		case 13: goto st1550;
		case 32: goto st1551;
		case 37: goto st1552;
		case 99: goto st1554;
	}
	goto st0;
st1550:
	if ( ++p == pe )
		goto _test_eof1550;
case 1550:
	if ( (*p) == 10 )
		goto tr2112;
	goto st0;
st1551:
	if ( ++p == pe )
		goto _test_eof1551;
case 1551:
	switch( (*p) ) {
		case 9: goto st1551;
		case 10: goto tr2112;
		case 13: goto st1550;
		case 32: goto st1551;
		case 37: goto st1552;
	}
	goto st0;
st1552:
	if ( ++p == pe )
		goto _test_eof1552;
case 1552:
	switch( (*p) ) {
		case 0: goto st0;
		case 124: goto tr2118;
	}
	goto tr2117;
tr2117:
#line 94 "mfilescanner.rl"
	{ cout << "/*"; tmp_p = p; }
	goto st1553;
tr2118:
#line 91 "mfilescanner.rl"
	{ cout << "/**"; tmp_p = p+1; }
	goto st1553;
st1553:
	if ( ++p == pe )
		goto _test_eof1553;
case 1553:
#line 19614 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr2120;
	}
	goto st1553;
st1554:
	if ( ++p == pe )
		goto _test_eof1554;
case 1554:
	if ( (*p) == 108 )
		goto st1555;
	goto st0;
st1555:
	if ( ++p == pe )
		goto _test_eof1555;
case 1555:
	if ( (*p) == 97 )
		goto st1556;
	goto st0;
st1556:
	if ( ++p == pe )
		goto _test_eof1556;
case 1556:
	if ( (*p) == 115 )
		goto st1557;
	goto st0;
st1557:
	if ( ++p == pe )
		goto _test_eof1557;
case 1557:
	if ( (*p) == 115 )
		goto st1558;
	goto st0;
st1558:
	if ( ++p == pe )
		goto _test_eof1558;
case 1558:
	if ( (*p) == 100 )
		goto st1559;
	goto st0;
st1559:
	if ( ++p == pe )
		goto _test_eof1559;
case 1559:
	if ( (*p) == 101 )
		goto st1560;
	goto st0;
st1560:
	if ( ++p == pe )
		goto _test_eof1560;
case 1560:
	if ( (*p) == 102 )
		goto st1561;
	goto st0;
tr2135:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st1561;
tr2132:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st1561;
st1561:
#line 1 "mfilescanner.rl"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof1561;
case 1561:
#line 19688 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st1561;
		case 32: goto st1561;
		case 37: goto tr2128;
		case 46: goto st1563;
		case 95: goto tr2130;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2130;
	} else if ( (*p) >= 65 )
		goto tr2130;
	goto st0;
tr2128:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1562;
st1562:
	if ( ++p == pe )
		goto _test_eof1562;
case 1562:
#line 19710 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr2132;
	}
	goto st1562;
st1563:
	if ( ++p == pe )
		goto _test_eof1563;
case 1563:
	if ( (*p) == 46 )
		goto st1564;
	goto st0;
st1564:
	if ( ++p == pe )
		goto _test_eof1564;
case 1564:
	if ( (*p) == 46 )
		goto st1565;
	goto st0;
st1565:
	if ( ++p == pe )
		goto _test_eof1565;
case 1565:
	switch( (*p) ) {
		case 9: goto st1565;
		case 10: goto tr2135;
		case 13: goto st1566;
		case 32: goto st1565;
	}
	goto st0;
st1566:
	if ( ++p == pe )
		goto _test_eof1566;
case 1566:
	if ( (*p) == 10 )
		goto tr2135;
	goto st0;
tr2130:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st1567;
st1567:
	if ( ++p == pe )
		goto _test_eof1567;
case 1567:
#line 19756 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr2137;
		case 10: goto tr2138;
		case 13: goto tr2139;
		case 32: goto tr2137;
		case 37: goto tr2140;
		case 40: goto tr2141;
		case 46: goto tr2142;
		case 60: goto tr2144;
		case 95: goto st1567;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st1567;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st1567;
	} else
		goto st1567;
	goto st0;
tr2215:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st1568;
tr2153:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st1568;
tr2137:
#line 1051 "mfilescanner.rl"
	{
            classname_.assign(tmp_p, p - tmp_p);
            is_class_ = true;
            cout << "class " << classname_;
          }
	goto st1568;
st1568:
	if ( ++p == pe )
		goto _test_eof1568;
case 1568:
#line 19802 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st1568;
		case 10: goto tr2146;
		case 13: goto st1569;
		case 32: goto st1568;
		case 37: goto tr2148;
		case 40: goto st1571;
		case 46: goto st1604;
		case 60: goto tr2151;
	}
	goto st0;
tr2138:
#line 1051 "mfilescanner.rl"
	{
            classname_.assign(tmp_p, p - tmp_p);
            is_class_ = true;
            cout << "class " << classname_;
          }
#line 32 "mfilescanner.rl"
	{line++;}
#line 1063 "mfilescanner.rl"
	{
        cout << " {\n";
        {goto st1451;}
      }
	goto st1675;
tr2146:
#line 32 "mfilescanner.rl"
	{line++;}
#line 1063 "mfilescanner.rl"
	{
        cout << " {\n";
        {goto st1451;}
      }
	goto st1675;
tr2174:
#line 1037 "mfilescanner.rl"
	{
             cout << "public ";
             cout.write(tmp_p, p - tmp_p);
           }
#line 32 "mfilescanner.rl"
	{line++;}
#line 1063 "mfilescanner.rl"
	{
        cout << " {\n";
        {goto st1451;}
      }
	goto st1675;
st1675:
	if ( ++p == pe )
		goto _test_eof1675;
case 1675:
#line 19856 "mfilescanner.cc"
	goto st0;
tr2139:
#line 1051 "mfilescanner.rl"
	{
            classname_.assign(tmp_p, p - tmp_p);
            is_class_ = true;
            cout << "class " << classname_;
          }
	goto st1569;
tr2175:
#line 1037 "mfilescanner.rl"
	{
             cout << "public ";
             cout.write(tmp_p, p - tmp_p);
           }
	goto st1569;
st1569:
	if ( ++p == pe )
		goto _test_eof1569;
case 1569:
#line 19877 "mfilescanner.cc"
	if ( (*p) == 10 )
		goto tr2146;
	goto st0;
tr2148:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1570;
tr2140:
#line 1051 "mfilescanner.rl"
	{
            classname_.assign(tmp_p, p - tmp_p);
            is_class_ = true;
            cout << "class " << classname_;
          }
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1570;
st1570:
	if ( ++p == pe )
		goto _test_eof1570;
case 1570:
#line 19899 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr2153;
	}
	goto st1570;
tr2141:
#line 1051 "mfilescanner.rl"
	{
            classname_.assign(tmp_p, p - tmp_p);
            is_class_ = true;
            cout << "class " << classname_;
          }
	goto st1571;
st1571:
	if ( ++p == pe )
		goto _test_eof1571;
case 1571:
#line 19917 "mfilescanner.cc"
	if ( (*p) == 41 )
		goto st1572;
	goto st1571;
tr2161:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st1572;
tr2158:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st1572;
st1572:
	if ( ++p == pe )
		goto _test_eof1572;
case 1572:
#line 19938 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st1572;
		case 10: goto tr2146;
		case 13: goto st1569;
		case 32: goto st1572;
		case 37: goto tr2155;
		case 46: goto st1574;
		case 60: goto tr2151;
	}
	goto st0;
tr2155:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1573;
st1573:
	if ( ++p == pe )
		goto _test_eof1573;
case 1573:
#line 19957 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr2158;
	}
	goto st1573;
st1574:
	if ( ++p == pe )
		goto _test_eof1574;
case 1574:
	if ( (*p) == 46 )
		goto st1575;
	goto st0;
st1575:
	if ( ++p == pe )
		goto _test_eof1575;
case 1575:
	if ( (*p) == 46 )
		goto st1576;
	goto st0;
st1576:
	if ( ++p == pe )
		goto _test_eof1576;
case 1576:
	switch( (*p) ) {
		case 9: goto st1576;
		case 10: goto tr2161;
		case 13: goto st1577;
		case 32: goto st1576;
	}
	goto st0;
st1577:
	if ( ++p == pe )
		goto _test_eof1577;
case 1577:
	if ( (*p) == 10 )
		goto tr2161;
	goto st0;
tr2171:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st1578;
tr2168:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st1578;
tr2144:
#line 1051 "mfilescanner.rl"
	{
            classname_.assign(tmp_p, p - tmp_p);
            is_class_ = true;
            cout << "class " << classname_;
          }
#line 1043 "mfilescanner.rl"
	{ cout << "\n  :"; }
	goto st1578;
tr2151:
#line 1043 "mfilescanner.rl"
	{ cout << "\n  :"; }
	goto st1578;
st1578:
	if ( ++p == pe )
		goto _test_eof1578;
case 1578:
#line 20026 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st1578;
		case 32: goto st1578;
		case 37: goto tr2164;
		case 46: goto st1580;
		case 95: goto tr2166;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2166;
	} else if ( (*p) >= 65 )
		goto tr2166;
	goto st0;
tr2164:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1579;
st1579:
	if ( ++p == pe )
		goto _test_eof1579;
case 1579:
#line 20048 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr2168;
	}
	goto st1579;
st1580:
	if ( ++p == pe )
		goto _test_eof1580;
case 1580:
	if ( (*p) == 46 )
		goto st1581;
	goto st0;
st1581:
	if ( ++p == pe )
		goto _test_eof1581;
case 1581:
	if ( (*p) == 46 )
		goto st1582;
	goto st0;
st1582:
	if ( ++p == pe )
		goto _test_eof1582;
case 1582:
	switch( (*p) ) {
		case 9: goto st1582;
		case 10: goto tr2171;
		case 13: goto st1583;
		case 32: goto st1582;
	}
	goto st0;
st1583:
	if ( ++p == pe )
		goto _test_eof1583;
case 1583:
	if ( (*p) == 10 )
		goto tr2171;
	goto st0;
tr2166:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st1584;
st1584:
	if ( ++p == pe )
		goto _test_eof1584;
case 1584:
#line 20094 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr2173;
		case 10: goto tr2174;
		case 13: goto tr2175;
		case 32: goto tr2173;
		case 37: goto tr2176;
		case 44: goto tr2177;
		case 46: goto tr2178;
		case 95: goto st1584;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st1584;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st1584;
	} else
		goto st1584;
	goto st0;
tr2211:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st1585;
tr2185:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st1585;
tr2173:
#line 1037 "mfilescanner.rl"
	{
             cout << "public ";
             cout.write(tmp_p, p - tmp_p);
           }
	goto st1585;
st1585:
	if ( ++p == pe )
		goto _test_eof1585;
case 1585:
#line 20138 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st1585;
		case 10: goto tr2146;
		case 13: goto st1569;
		case 32: goto st1585;
		case 37: goto tr2181;
		case 44: goto tr2182;
		case 46: goto st1600;
	}
	goto st0;
tr2181:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1586;
tr2176:
#line 1037 "mfilescanner.rl"
	{
             cout << "public ";
             cout.write(tmp_p, p - tmp_p);
           }
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1586;
st1586:
	if ( ++p == pe )
		goto _test_eof1586;
case 1586:
#line 20166 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr2185;
	}
	goto st1586;
tr2194:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st1587;
tr2191:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st1587;
tr2177:
#line 1037 "mfilescanner.rl"
	{
             cout << "public ";
             cout.write(tmp_p, p - tmp_p);
           }
#line 1044 "mfilescanner.rl"
	{ cout << ",\n   "; }
	goto st1587;
tr2182:
#line 1044 "mfilescanner.rl"
	{ cout << ",\n   "; }
	goto st1587;
st1587:
	if ( ++p == pe )
		goto _test_eof1587;
case 1587:
#line 20202 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st1587;
		case 32: goto st1587;
		case 37: goto tr2187;
		case 46: goto st1589;
		case 95: goto tr2189;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2189;
	} else if ( (*p) >= 65 )
		goto tr2189;
	goto st0;
tr2187:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1588;
st1588:
	if ( ++p == pe )
		goto _test_eof1588;
case 1588:
#line 20224 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr2191;
	}
	goto st1588;
st1589:
	if ( ++p == pe )
		goto _test_eof1589;
case 1589:
	if ( (*p) == 46 )
		goto st1590;
	goto st0;
st1590:
	if ( ++p == pe )
		goto _test_eof1590;
case 1590:
	if ( (*p) == 46 )
		goto st1591;
	goto st0;
st1591:
	if ( ++p == pe )
		goto _test_eof1591;
case 1591:
	switch( (*p) ) {
		case 9: goto st1591;
		case 10: goto tr2194;
		case 13: goto st1592;
		case 32: goto st1591;
	}
	goto st0;
st1592:
	if ( ++p == pe )
		goto _test_eof1592;
case 1592:
	if ( (*p) == 10 )
		goto tr2194;
	goto st0;
tr2189:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st1593;
st1593:
	if ( ++p == pe )
		goto _test_eof1593;
case 1593:
#line 20270 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr2196;
		case 10: goto tr2174;
		case 13: goto tr2175;
		case 32: goto tr2196;
		case 37: goto tr2197;
		case 44: goto tr2177;
		case 46: goto tr2198;
		case 95: goto st1593;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st1593;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st1593;
	} else
		goto st1593;
	goto st0;
tr2207:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st1594;
tr2204:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st1594;
tr2196:
#line 1037 "mfilescanner.rl"
	{
             cout << "public ";
             cout.write(tmp_p, p - tmp_p);
           }
	goto st1594;
st1594:
	if ( ++p == pe )
		goto _test_eof1594;
case 1594:
#line 20314 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st1594;
		case 10: goto tr2146;
		case 13: goto st1569;
		case 32: goto st1594;
		case 37: goto tr2201;
		case 46: goto st1596;
	}
	goto st0;
tr2201:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1595;
tr2197:
#line 1037 "mfilescanner.rl"
	{
             cout << "public ";
             cout.write(tmp_p, p - tmp_p);
           }
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1595;
st1595:
	if ( ++p == pe )
		goto _test_eof1595;
case 1595:
#line 20341 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr2204;
	}
	goto st1595;
tr2198:
#line 1037 "mfilescanner.rl"
	{
             cout << "public ";
             cout.write(tmp_p, p - tmp_p);
           }
	goto st1596;
st1596:
	if ( ++p == pe )
		goto _test_eof1596;
case 1596:
#line 20358 "mfilescanner.cc"
	if ( (*p) == 46 )
		goto st1597;
	goto st0;
st1597:
	if ( ++p == pe )
		goto _test_eof1597;
case 1597:
	if ( (*p) == 46 )
		goto st1598;
	goto st0;
st1598:
	if ( ++p == pe )
		goto _test_eof1598;
case 1598:
	switch( (*p) ) {
		case 9: goto st1598;
		case 10: goto tr2207;
		case 13: goto st1599;
		case 32: goto st1598;
	}
	goto st0;
st1599:
	if ( ++p == pe )
		goto _test_eof1599;
case 1599:
	if ( (*p) == 10 )
		goto tr2207;
	goto st0;
tr2178:
#line 1037 "mfilescanner.rl"
	{
             cout << "public ";
             cout.write(tmp_p, p - tmp_p);
           }
	goto st1600;
st1600:
	if ( ++p == pe )
		goto _test_eof1600;
case 1600:
#line 20398 "mfilescanner.cc"
	if ( (*p) == 46 )
		goto st1601;
	goto st0;
st1601:
	if ( ++p == pe )
		goto _test_eof1601;
case 1601:
	if ( (*p) == 46 )
		goto st1602;
	goto st0;
st1602:
	if ( ++p == pe )
		goto _test_eof1602;
case 1602:
	switch( (*p) ) {
		case 9: goto st1602;
		case 10: goto tr2211;
		case 13: goto st1603;
		case 32: goto st1602;
	}
	goto st0;
st1603:
	if ( ++p == pe )
		goto _test_eof1603;
case 1603:
	if ( (*p) == 10 )
		goto tr2211;
	goto st0;
tr2142:
#line 1051 "mfilescanner.rl"
	{
            classname_.assign(tmp_p, p - tmp_p);
            is_class_ = true;
            cout << "class " << classname_;
          }
	goto st1604;
st1604:
	if ( ++p == pe )
		goto _test_eof1604;
case 1604:
#line 20439 "mfilescanner.cc"
	if ( (*p) == 46 )
		goto st1605;
	goto st0;
st1605:
	if ( ++p == pe )
		goto _test_eof1605;
case 1605:
	if ( (*p) == 46 )
		goto st1606;
	goto st0;
st1606:
	if ( ++p == pe )
		goto _test_eof1606;
case 1606:
	switch( (*p) ) {
		case 9: goto st1606;
		case 10: goto tr2215;
		case 13: goto st1607;
		case 32: goto st1606;
	}
	goto st0;
st1607:
	if ( ++p == pe )
		goto _test_eof1607;
case 1607:
	if ( (*p) == 10 )
		goto tr2215;
	goto st0;
tr25:
#line 32 "mfilescanner.rl"
	{line++;}
#line 42 "mfilescanner.rl"
	{ cout.write(tmp_p, p - tmp_p+1); }
	goto st1609;
st1609:
#line 1 "mfilescanner.rl"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof1609;
case 1609:
#line 20480 "mfilescanner.cc"
	if ( (*p) == 37 )
		goto tr2218;
	goto tr24;
tr2218:
#line 39 "mfilescanner.rl"
	{ tmp_p = p+1; cout << " *"; }
	goto st19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
#line 20492 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr24;
		case 10: goto tr25;
	}
	goto st19;
tr26:
#line 348 "mfilescanner.rl"
	{{p = ((te))-1;}{ cout << (*p); }}
	goto st1610;
tr28:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 199 "mfilescanner.rl"
	{te = p+1;}
	goto st1610;
tr30:
#line 32 "mfilescanner.rl"
	{line++;}
#line 197 "mfilescanner.rl"
	{te = p+1;{ cout.write(ts, te-ts); }}
	goto st1610;
tr32:
#line 336 "mfilescanner.rl"
	{{p = ((te))-1;}{ cout.write(ts, te-ts); }}
	goto st1610;
tr34:
#line 256 "mfilescanner.rl"
	{{p = ((te))-1;}{
      // store fieldname
      string s(tmp_p, p - tmp_p+1);
      cout << tmp_string << "." << s;
      typedef DocuList     :: iterator list_iterator;
      typedef DocuListMap  :: iterator map_iterator;
      typedef DocuBlock    :: iterator iterator;

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
          // found match in retval list
          if(lit != (*rvoit).second.end())
            missing = false;
        }
        map_iterator moit = optional_list_.find(tmp_string);
        if(moit != optional_list_.end())
        {
          // found match in optional list
          list_iterator lit = (*moit).second.find(s);
          if(lit != (*moit).second.end())
            missing = false;
        }
        map_iterator roit = required_list_.find(tmp_string);
        if(roit != required_list_.end())
        {
          // found match in required list
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
	goto st1610;
tr37:
#line 212 "mfilescanner.rl"
	{te = p+1;{
      p--;
      // store fieldname
      string s(tmp_p, tmp_p2 - tmp_p);
      cout << tmp_string << "." << s << "=";
      // typedef of iterators
      typedef DocuList     :: iterator list_iterator;
      typedef DocuListMap  :: iterator map_iterator;
      typedef DocuBlock    :: iterator iterator;

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
        // if it is missing, add an empty docu block
        if(missing)
        {
          retval_list_[tmp_string][s] = DocuBlock();
        }
      }
    }}
	goto st1610;
tr49:
#line 32 "mfilescanner.rl"
	{line++;}
#line 320 "mfilescanner.rl"
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
	goto st1610;
tr2219:
#line 348 "mfilescanner.rl"
	{te = p+1;{ cout << (*p); }}
	goto st1610;
tr2221:
#line 32 "mfilescanner.rl"
	{line++;}
#line 352 "mfilescanner.rl"
	{te = p+1;{ cout << (*p); {goto st1632;} }}
	goto st1610;
tr2227:
#line 341 "mfilescanner.rl"
	{te = p+1;{ cout << '['; }}
	goto st1610;
tr2228:
#line 344 "mfilescanner.rl"
	{te = p+1;{ cout << ']'; }}
	goto st1610;
tr2229:
#line 194 "mfilescanner.rl"
	{te = p;p--;{ cout.write(ts, te-ts); }}
	goto st1610;
tr2230:
#line 348 "mfilescanner.rl"
	{te = p;p--;{ cout << (*p); }}
	goto st1610;
tr2232:
#line 336 "mfilescanner.rl"
	{te = p;p--;{ cout.write(ts, te-ts); }}
	goto st1610;
tr2234:
#line 256 "mfilescanner.rl"
	{te = p;p--;{
      // store fieldname
      string s(tmp_p, p - tmp_p+1);
      cout << tmp_string << "." << s;
      typedef DocuList     :: iterator list_iterator;
      typedef DocuListMap  :: iterator map_iterator;
      typedef DocuBlock    :: iterator iterator;

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
          // found match in retval list
          if(lit != (*rvoit).second.end())
            missing = false;
        }
        map_iterator moit = optional_list_.find(tmp_string);
        if(moit != optional_list_.end())
        {
          // found match in optional list
          list_iterator lit = (*moit).second.find(s);
          if(lit != (*moit).second.end())
            missing = false;
        }
        map_iterator roit = required_list_.find(tmp_string);
        if(roit != required_list_.end())
        {
          // found match in required list
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
	goto st1610;
st1610:
#line 1 "mfilescanner.rl"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof1610;
case 1610:
#line 1 "mfilescanner.rl"
	{ts = p;}
#line 20714 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1611;
		case 10: goto tr2221;
		case 13: goto st1612;
		case 32: goto st1611;
		case 37: goto tr2223;
		case 46: goto tr2224;
		case 95: goto tr2225;
		case 100: goto tr2226;
		case 123: goto tr2227;
		case 125: goto tr2228;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2225;
	} else if ( (*p) >= 65 )
		goto tr2225;
	goto tr2219;
st1611:
	if ( ++p == pe )
		goto _test_eof1611;
case 1611:
	switch( (*p) ) {
		case 9: goto st1611;
		case 32: goto st1611;
	}
	goto tr2229;
st1612:
	if ( ++p == pe )
		goto _test_eof1612;
case 1612:
	if ( (*p) == 10 )
		goto tr2221;
	goto tr2230;
tr2223:
#line 1 "mfilescanner.rl"
	{te = p+1;}
#line 199 "mfilescanner.rl"
	{ tmp_p = p + 1; }
	goto st1613;
st1613:
	if ( ++p == pe )
		goto _test_eof1613;
case 1613:
#line 20760 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr2230;
		case 10: goto tr28;
	}
	goto st20;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
	switch( (*p) ) {
		case 0: goto tr26;
		case 10: goto tr28;
	}
	goto st20;
tr2224:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st1614;
st1614:
	if ( ++p == pe )
		goto _test_eof1614;
case 1614:
#line 20783 "mfilescanner.cc"
	if ( (*p) == 46 )
		goto st21;
	goto tr2230;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
	if ( (*p) == 46 )
		goto st22;
	goto tr26;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
	switch( (*p) ) {
		case 9: goto st22;
		case 10: goto tr30;
		case 13: goto st23;
		case 32: goto st22;
	}
	goto tr26;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	if ( (*p) == 10 )
		goto tr30;
	goto tr26;
tr2225:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st1615;
st1615:
	if ( ++p == pe )
		goto _test_eof1615;
case 1615:
#line 20820 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr2233;
		case 95: goto tr2225;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr2225;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2225;
	} else
		goto tr2225;
	goto tr2232;
tr2233:
#line 205 "mfilescanner.rl"
	{tmp_string.assign(ts,p-ts);}
#line 249 "mfilescanner.rl"
	{tmp_string.assign(ts,p-ts);}
	goto st24;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
#line 20844 "mfilescanner.cc"
	if ( (*p) == 95 )
		goto tr33;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr33;
	} else if ( (*p) >= 65 )
		goto tr33;
	goto tr32;
tr33:
#line 1 "mfilescanner.rl"
	{te = p+1;}
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st1616;
tr2236:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st1616;
st1616:
	if ( ++p == pe )
		goto _test_eof1616;
case 1616:
#line 20867 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr2235;
		case 32: goto tr2235;
		case 46: goto tr2236;
		case 61: goto tr2237;
		case 95: goto tr2236;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr2236;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2236;
	} else
		goto tr2236;
	goto tr2234;
tr2235:
#line 208 "mfilescanner.rl"
	{tmp_p2 = p;}
	goto st25;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
#line 20892 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st25;
		case 32: goto st25;
		case 61: goto st26;
	}
	goto tr34;
tr2237:
#line 208 "mfilescanner.rl"
	{tmp_p2 = p;}
	goto st26;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
#line 20907 "mfilescanner.cc"
	if ( (*p) == 61 )
		goto tr34;
	goto tr37;
tr2226:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st1617;
st1617:
	if ( ++p == pe )
		goto _test_eof1617;
case 1617:
#line 20919 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr2233;
		case 95: goto tr2225;
		case 105: goto tr2238;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr2225;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2225;
	} else
		goto tr2225;
	goto tr2232;
tr2238:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st1618;
st1618:
	if ( ++p == pe )
		goto _test_eof1618;
case 1618:
#line 20942 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr2233;
		case 95: goto tr2225;
		case 115: goto tr2239;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr2225;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2225;
	} else
		goto tr2225;
	goto tr2232;
tr2239:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st1619;
st1619:
	if ( ++p == pe )
		goto _test_eof1619;
case 1619:
#line 20965 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr2233;
		case 95: goto tr2225;
		case 112: goto tr2240;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr2225;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2225;
	} else
		goto tr2225;
	goto tr2232;
tr2240:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st1620;
st1620:
	if ( ++p == pe )
		goto _test_eof1620;
case 1620:
#line 20988 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr2233;
		case 95: goto tr2241;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr2225;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2225;
	} else
		goto tr2225;
	goto tr2232;
tr2241:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st1621;
st1621:
	if ( ++p == pe )
		goto _test_eof1621;
case 1621:
#line 21010 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr2233;
		case 95: goto tr2225;
		case 100: goto tr2242;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr2225;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2225;
	} else
		goto tr2225;
	goto tr2232;
tr2242:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st1622;
st1622:
	if ( ++p == pe )
		goto _test_eof1622;
case 1622:
#line 21033 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr2233;
		case 95: goto tr2225;
		case 101: goto tr2243;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr2225;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2225;
	} else
		goto tr2225;
	goto tr2232;
tr2243:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st1623;
st1623:
	if ( ++p == pe )
		goto _test_eof1623;
case 1623:
#line 21056 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr2233;
		case 95: goto tr2225;
		case 112: goto tr2244;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr2225;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2225;
	} else
		goto tr2225;
	goto tr2232;
tr2244:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st1624;
st1624:
	if ( ++p == pe )
		goto _test_eof1624;
case 1624:
#line 21079 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr2233;
		case 95: goto tr2225;
		case 114: goto tr2245;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr2225;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2225;
	} else
		goto tr2225;
	goto tr2232;
tr2245:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st1625;
st1625:
	if ( ++p == pe )
		goto _test_eof1625;
case 1625:
#line 21102 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr2233;
		case 95: goto tr2225;
		case 101: goto tr2246;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr2225;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2225;
	} else
		goto tr2225;
	goto tr2232;
tr2246:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st1626;
st1626:
	if ( ++p == pe )
		goto _test_eof1626;
case 1626:
#line 21125 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr2233;
		case 95: goto tr2225;
		case 99: goto tr2247;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr2225;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2225;
	} else
		goto tr2225;
	goto tr2232;
tr2247:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st1627;
st1627:
	if ( ++p == pe )
		goto _test_eof1627;
case 1627:
#line 21148 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr2233;
		case 95: goto tr2225;
		case 97: goto tr2248;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr2225;
	} else if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr2225;
	} else
		goto tr2225;
	goto tr2232;
tr2248:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st1628;
st1628:
	if ( ++p == pe )
		goto _test_eof1628;
case 1628:
#line 21171 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr2233;
		case 95: goto tr2225;
		case 116: goto tr2249;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr2225;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2225;
	} else
		goto tr2225;
	goto tr2232;
tr2249:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st1629;
st1629:
	if ( ++p == pe )
		goto _test_eof1629;
case 1629:
#line 21194 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr2233;
		case 95: goto tr2225;
		case 101: goto tr2250;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr2225;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2225;
	} else
		goto tr2225;
	goto tr2232;
tr2250:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st1630;
st1630:
	if ( ++p == pe )
		goto _test_eof1630;
case 1630:
#line 21217 "mfilescanner.cc"
	switch( (*p) ) {
		case 46: goto tr2233;
		case 95: goto tr2225;
		case 100: goto tr2251;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr2225;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2225;
	} else
		goto tr2225;
	goto tr2232;
tr2251:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st1631;
st1631:
	if ( ++p == pe )
		goto _test_eof1631;
case 1631:
#line 21240 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st27;
		case 32: goto st27;
		case 40: goto st28;
		case 46: goto tr2233;
		case 59: goto tr40;
		case 95: goto tr2225;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr2225;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2225;
	} else
		goto tr2225;
	goto tr2232;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
	switch( (*p) ) {
		case 9: goto st27;
		case 32: goto st27;
		case 40: goto st28;
		case 59: goto tr40;
	}
	goto tr32;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
	switch( (*p) ) {
		case 9: goto st28;
		case 32: goto st28;
		case 39: goto st29;
	}
	goto tr32;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
	switch( (*p) ) {
		case 10: goto tr32;
		case 39: goto tr43;
	}
	goto tr42;
tr42:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st30;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
#line 21296 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr32;
		case 39: goto tr45;
	}
	goto st30;
tr43:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
#line 69 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st31;
tr45:
#line 69 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st31;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
#line 21316 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st31;
		case 32: goto st31;
		case 41: goto st32;
	}
	goto tr32;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
	switch( (*p) ) {
		case 9: goto st32;
		case 32: goto st32;
		case 59: goto st33;
	}
	goto tr32;
tr40:
#line 309 "mfilescanner.rl"
	{tmp_string.assign("");}
	goto st33;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
#line 21341 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st33;
		case 10: goto tr49;
		case 13: goto st34;
		case 32: goto st33;
	}
	goto tr32;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
	if ( (*p) == 10 )
		goto tr49;
	goto tr32;
tr53:
#line 32 "mfilescanner.rl"
	{line++;}
#line 380 "mfilescanner.rl"
	{te = p+1;{
          p = ts-1;
          // further parse the function body line
          {goto st1610;}
        }}
	goto st1632;
tr58:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 380 "mfilescanner.rl"
	{te = p+1;{
          p = ts-1;
          // further parse the function body line
          {goto st1610;}
        }}
	goto st1632;
tr62:
#line 380 "mfilescanner.rl"
	{{p = ((te))-1;}{
          p = ts-1;
          // further parse the function body line
          {goto st1610;}
        }}
	goto st1632;
tr64:
#line 32 "mfilescanner.rl"
	{line++;}
#line 373 "mfilescanner.rl"
	{te = p+1;{ cout << '\n'; }}
	goto st1632;
tr72:
#line 32 "mfilescanner.rl"
	{line++;}
#line 366 "mfilescanner.rl"
	{te = p+1;{
          cout.write(tmp_p, p - tmp_p+1);
          {stack[top++] = 1632; goto st1609;}
        }}
	goto st1632;
tr78:
#line 32 "mfilescanner.rl"
	{line++;}
#line 388 "mfilescanner.rl"
	{te = p+1;{
              if(is_class_ && class_part_ == Method)
              {
                tmp_string.assign(ts,te-ts);
                if(tmp_string.find("e") == funcindent_)
                {
                  end_function();
                  {goto st1668;}
                }
              }
              // else
              p=ts-1;
              // further parse the function body line
              {goto st1610;}
          }}
	goto st1632;
tr80:
#line 1 "mfilescanner.rl"
	{	switch( act ) {
	case 0:
	{{goto st0;}}
	break;
	case 15:
	{{p = ((te))-1;}
          p = ts-1;
          // further parse the function body line
          {goto st1610;}
        }
	break;
	}
	}
	goto st1632;
tr96:
#line 406 "mfilescanner.rl"
	{te = p+1;{
        p = ts-1;
        // end the previous function if existent
        end_function();
        {goto st1608;}
      }}
	goto st1632;
tr126:
#line 359 "mfilescanner.rl"
	{te = p+1;{
          new_syntax_ = true;
          cout << "*/\n"; //cout << "add to special group */\n";
        }}
#line 32 "mfilescanner.rl"
	{line++;}
	goto st1632;
tr2252:
#line 413 "mfilescanner.rl"
	{te = p+1;}
	goto st1632;
tr2254:
#line 380 "mfilescanner.rl"
	{te = p;p--;{
          p = ts-1;
          // further parse the function body line
          {goto st1610;}
        }}
	goto st1632;
st1632:
#line 1 "mfilescanner.rl"
	{ts = 0;}
#line 1 "mfilescanner.rl"
	{act = 0;}
	if ( ++p == pe )
		goto _test_eof1632;
case 1632:
#line 1 "mfilescanner.rl"
	{ts = p;}
#line 21480 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr2252;
		case 9: goto st42;
		case 10: goto tr64;
		case 13: goto st43;
		case 32: goto st42;
		case 37: goto st66;
		case 101: goto st46;
		case 102: goto st58;
	}
	goto st35;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1633;
		case 10: goto tr53;
		case 13: goto st36;
		case 32: goto st1633;
		case 37: goto tr55;
		case 46: goto st38;
	}
	goto st35;
st1633:
	if ( ++p == pe )
		goto _test_eof1633;
case 1633:
	switch( (*p) ) {
		case 9: goto st1633;
		case 32: goto st1633;
	}
	goto tr2254;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
	if ( (*p) == 10 )
		goto tr53;
	goto st0;
tr55:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st37;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
#line 21530 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr58;
	}
	goto st37;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1633;
		case 10: goto tr53;
		case 13: goto st36;
		case 32: goto st1633;
		case 37: goto tr55;
		case 46: goto st39;
	}
	goto st35;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1633;
		case 10: goto tr53;
		case 13: goto st36;
		case 32: goto st1633;
		case 37: goto tr55;
		case 46: goto st40;
	}
	goto st35;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr61;
		case 10: goto tr53;
		case 13: goto st36;
		case 32: goto tr61;
		case 37: goto tr55;
		case 46: goto st40;
	}
	goto st35;
tr61:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st1634;
st1634:
	if ( ++p == pe )
		goto _test_eof1634;
case 1634:
#line 21586 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr61;
		case 10: goto tr53;
		case 13: goto st41;
		case 32: goto tr61;
	}
	goto tr2254;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
	if ( (*p) == 10 )
		goto tr53;
	goto tr62;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st42;
		case 10: goto tr64;
		case 13: goto st43;
		case 32: goto st42;
		case 37: goto st44;
		case 101: goto st46;
		case 102: goto st58;
	}
	goto st35;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
	if ( (*p) == 10 )
		goto tr64;
	goto st0;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
	switch( (*p) ) {
		case 0: goto st0;
		case 124: goto tr70;
	}
	goto tr69;
tr69:
#line 94 "mfilescanner.rl"
	{ cout << "/*"; tmp_p = p; }
	goto st45;
tr70:
#line 91 "mfilescanner.rl"
	{ cout << "/**"; tmp_p = p+1; }
	goto st45;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
#line 21644 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr72;
	}
	goto st45;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1633;
		case 10: goto tr53;
		case 13: goto st36;
		case 32: goto st1633;
		case 37: goto tr55;
		case 46: goto st38;
		case 110: goto st47;
	}
	goto st35;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1633;
		case 10: goto tr53;
		case 13: goto st36;
		case 32: goto st1633;
		case 37: goto tr55;
		case 46: goto st38;
		case 100: goto st48;
	}
	goto st35;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st49;
		case 10: goto st0;
		case 13: goto st0;
		case 32: goto st49;
		case 37: goto tr76;
		case 46: goto st53;
	}
	goto st35;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
	switch( (*p) ) {
		case 9: goto st49;
		case 10: goto tr78;
		case 13: goto st50;
		case 32: goto st49;
	}
	goto st0;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
	if ( (*p) == 10 )
		goto tr78;
	goto tr80;
tr76:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st51;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
#line 21720 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr82;
	}
	goto st51;
tr88:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st52;
tr82:
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st52;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
#line 21743 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr78;
		case 13: goto st50;
	}
	goto tr80;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1633;
		case 10: goto tr53;
		case 13: goto st36;
		case 32: goto st1633;
		case 37: goto tr55;
		case 46: goto st54;
	}
	goto st35;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1633;
		case 10: goto tr53;
		case 13: goto st36;
		case 32: goto st1633;
		case 37: goto tr55;
		case 46: goto st55;
	}
	goto st35;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr85;
		case 10: goto tr86;
		case 13: goto st57;
		case 32: goto tr85;
		case 37: goto tr55;
		case 46: goto st40;
	}
	goto st35;
tr85:
#line 1 "mfilescanner.rl"
	{te = p+1;}
#line 380 "mfilescanner.rl"
	{act = 15;}
	goto st1635;
st1635:
	if ( ++p == pe )
		goto _test_eof1635;
case 1635:
#line 21801 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr85;
		case 10: goto tr88;
		case 13: goto st56;
		case 32: goto tr85;
	}
	goto tr2254;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
	if ( (*p) == 10 )
		goto tr88;
	goto tr62;
tr86:
#line 1 "mfilescanner.rl"
	{te = p+1;}
#line 32 "mfilescanner.rl"
	{line++;}
#line 380 "mfilescanner.rl"
	{act = 15;}
	goto st1636;
st1636:
	if ( ++p == pe )
		goto _test_eof1636;
case 1636:
#line 21828 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr78;
		case 13: goto st50;
	}
	goto tr2254;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
	if ( (*p) == 10 )
		goto tr86;
	goto st0;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1633;
		case 10: goto tr53;
		case 13: goto st36;
		case 32: goto st1633;
		case 37: goto tr55;
		case 46: goto st38;
		case 117: goto st59;
	}
	goto st35;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1633;
		case 10: goto tr53;
		case 13: goto st36;
		case 32: goto st1633;
		case 37: goto tr55;
		case 46: goto st38;
		case 110: goto st60;
	}
	goto st35;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1633;
		case 10: goto tr53;
		case 13: goto st36;
		case 32: goto st1633;
		case 37: goto tr55;
		case 46: goto st38;
		case 99: goto st61;
	}
	goto st35;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1633;
		case 10: goto tr53;
		case 13: goto st36;
		case 32: goto st1633;
		case 37: goto tr55;
		case 46: goto st38;
		case 116: goto st62;
	}
	goto st35;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1633;
		case 10: goto tr53;
		case 13: goto st36;
		case 32: goto st1633;
		case 37: goto tr55;
		case 46: goto st38;
		case 105: goto st63;
	}
	goto st35;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1633;
		case 10: goto tr53;
		case 13: goto st36;
		case 32: goto st1633;
		case 37: goto tr55;
		case 46: goto st38;
		case 111: goto st64;
	}
	goto st35;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st1633;
		case 10: goto tr53;
		case 13: goto st36;
		case 32: goto st1633;
		case 37: goto tr55;
		case 46: goto st38;
		case 110: goto st65;
	}
	goto st35;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
	switch( (*p) ) {
		case 0: goto st0;
		case 13: goto st0;
		case 32: goto tr96;
		case 37: goto st0;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st0;
	goto st35;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
	switch( (*p) ) {
		case 0: goto st0;
		case 32: goto tr97;
		case 124: goto tr70;
	}
	goto tr69;
tr97:
#line 94 "mfilescanner.rl"
	{ cout << "/*"; tmp_p = p; }
	goto st67;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
#line 21977 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr72;
		case 84: goto st68;
	}
	goto st45;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr72;
		case 79: goto st69;
	}
	goto st45;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr72;
		case 32: goto st70;
	}
	goto st45;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr72;
		case 66: goto st71;
	}
	goto st45;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr72;
		case 69: goto st72;
	}
	goto st45;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr72;
		case 32: goto st73;
	}
	goto st45;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr72;
		case 65: goto st74;
	}
	goto st45;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr72;
		case 68: goto st75;
	}
	goto st45;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr72;
		case 74: goto st76;
	}
	goto st45;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr72;
		case 85: goto st77;
	}
	goto st45;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr72;
		case 83: goto st78;
	}
	goto st45;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr72;
		case 84: goto st79;
	}
	goto st45;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr72;
		case 69: goto st80;
	}
	goto st45;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr72;
		case 68: goto st81;
	}
	goto st45;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr72;
		case 32: goto st82;
	}
	goto st45;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr72;
		case 84: goto st83;
	}
	goto st45;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr72;
		case 79: goto st84;
	}
	goto st45;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr72;
		case 32: goto st85;
	}
	goto st45;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr72;
		case 78: goto st86;
	}
	goto st45;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr72;
		case 69: goto st87;
	}
	goto st45;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr72;
		case 87: goto st88;
	}
	goto st45;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr72;
		case 32: goto st89;
	}
	goto st45;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr72;
		case 83: goto st90;
	}
	goto st45;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr72;
		case 89: goto st91;
	}
	goto st45;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr72;
		case 78: goto st92;
	}
	goto st45;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr72;
		case 84: goto st93;
	}
	goto st45;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr72;
		case 65: goto st94;
	}
	goto st45;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr72;
		case 88: goto st95;
	}
	goto st45;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr126;
	}
	goto st45;
tr127:
#line 1 "mfilescanner.rl"
	{	switch( act ) {
	case 0:
	{{goto st0;}}
	break;
	case 22:
	{{p = ((te))-1;}
      p =ts-1;
      // cout << "*/\n";
      {cs = stack[--top];goto _again;}
    }
	break;
	}
	}
	goto st1637;
tr130:
#line 32 "mfilescanner.rl"
	{line++;}
#line 452 "mfilescanner.rl"
	{te = p+1;{ /*cout << "empty line\n";*/ {cs = stack[--top];goto _again;} }}
	goto st1637;
tr135:
#line 32 "mfilescanner.rl"
	{line++;}
#line 444 "mfilescanner.rl"
	{te = p+1;{
      string s(tmp_p, p - tmp_p + 1);
      (*clist_)[tmp_string].push_back(s);
      /*cout << "add something results in\n" << (*clist_)[tmp_string];*/
    }}
	goto st1637;
tr145:
#line 32 "mfilescanner.rl"
	{line++;}
#line 425 "mfilescanner.rl"
	{te = p+1;{
      tmp_string.assign(tmp_p3, tmp_p2 - tmp_p3);
      //    std::cout << tmp_string << '\n';
      (*clist_)[tmp_string].push_back(string(tmp_p+1, p - tmp_p));
    }}
	goto st1637;
tr2257:
#line 456 "mfilescanner.rl"
	{te = p+1;{
      p =ts-1;
      // cout << "*/\n";
      {cs = stack[--top];goto _again;}
    }}
	goto st1637;
tr2259:
#line 32 "mfilescanner.rl"
	{line++;}
#line 456 "mfilescanner.rl"
	{te = p+1;{
      p =ts-1;
      // cout << "*/\n";
      {cs = stack[--top];goto _again;}
    }}
	goto st1637;
tr2262:
#line 456 "mfilescanner.rl"
	{te = p;p--;{
      p =ts-1;
      // cout << "*/\n";
      {cs = stack[--top];goto _again;}
    }}
	goto st1637;
st1637:
#line 1 "mfilescanner.rl"
	{ts = 0;}
#line 1 "mfilescanner.rl"
	{act = 0;}
	if ( ++p == pe )
		goto _test_eof1637;
case 1637:
#line 1 "mfilescanner.rl"
	{ts = p;}
#line 22341 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr2258;
		case 10: goto tr2259;
		case 13: goto st1639;
		case 32: goto tr2258;
		case 37: goto tr2261;
	}
	goto tr2257;
tr2258:
#line 1 "mfilescanner.rl"
	{te = p+1;}
#line 456 "mfilescanner.rl"
	{act = 22;}
	goto st1638;
st1638:
	if ( ++p == pe )
		goto _test_eof1638;
case 1638:
#line 22361 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr2262;
		case 9: goto tr2258;
		case 10: goto tr2259;
		case 13: goto st1639;
		case 32: goto tr2258;
		case 37: goto tr2261;
	}
	goto tr2257;
st1639:
	if ( ++p == pe )
		goto _test_eof1639;
case 1639:
	if ( (*p) == 10 )
		goto tr2259;
	goto tr2262;
tr2261:
#line 105 "mfilescanner.rl"
	{ tmp_p = p + 1; }
	goto st96;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
#line 22386 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr127;
		case 9: goto st96;
		case 10: goto tr130;
		case 13: goto st101;
		case 32: goto st96;
		case 39: goto st102;
		case 58: goto tr127;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr133;
	} else if ( (*p) >= 65 )
		goto tr133;
	goto st97;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
	switch( (*p) ) {
		case 0: goto tr127;
		case 9: goto st98;
		case 10: goto tr135;
		case 13: goto st100;
		case 32: goto st98;
		case 58: goto tr127;
	}
	goto st97;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
	switch( (*p) ) {
		case 9: goto st98;
		case 10: goto tr135;
		case 13: goto st100;
		case 32: goto st98;
		case 58: goto tr127;
	}
	goto st99;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
	switch( (*p) ) {
		case 0: goto tr127;
		case 10: goto tr135;
	}
	goto st99;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
	if ( (*p) == 10 )
		goto tr135;
	goto tr127;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
	if ( (*p) == 10 )
		goto tr130;
	goto tr127;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
	switch( (*p) ) {
		case 0: goto tr127;
		case 9: goto st98;
		case 10: goto tr135;
		case 13: goto st100;
		case 32: goto st98;
		case 58: goto tr127;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr133;
	} else if ( (*p) >= 65 )
		goto tr133;
	goto st97;
tr133:
#line 422 "mfilescanner.rl"
	{tmp_p3 = p;}
	goto st103;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
#line 22476 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr127;
		case 9: goto tr138;
		case 10: goto tr135;
		case 13: goto st100;
		case 32: goto tr138;
		case 39: goto tr139;
		case 44: goto st103;
		case 46: goto st103;
		case 58: goto tr141;
		case 93: goto st103;
		case 95: goto st103;
		case 125: goto st103;
	}
	if ( (*p) < 48 ) {
		if ( 40 <= (*p) && (*p) <= 41 )
			goto st103;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 123 )
				goto st103;
		} else if ( (*p) >= 65 )
			goto st103;
	} else
		goto st103;
	goto st97;
tr138:
#line 422 "mfilescanner.rl"
	{tmp_p2 = p;}
	goto st104;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
#line 22511 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st104;
		case 10: goto tr135;
		case 13: goto st100;
		case 32: goto st104;
		case 58: goto tr143;
	}
	goto st99;
tr143:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st105;
tr141:
#line 422 "mfilescanner.rl"
	{tmp_p2 = p;}
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st105;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
#line 22534 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr127;
		case 10: goto tr145;
	}
	goto st105;
tr139:
#line 422 "mfilescanner.rl"
	{tmp_p2 = p;}
	goto st106;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
#line 22548 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr127;
		case 9: goto st104;
		case 10: goto tr135;
		case 13: goto st100;
		case 32: goto st104;
		case 58: goto tr143;
	}
	goto st97;
tr146:
#line 580 "mfilescanner.rl"
	{{p = ((te))-1;}}
	goto st1640;
tr149:
#line 535 "mfilescanner.rl"
	{{p = ((te))-1;}{
        if(!docline)
        {
          docline = true;
          tmp_p = p;
        }
      }}
	goto st1640;
tr151:
#line 32 "mfilescanner.rl"
	{line++;}
#line 527 "mfilescanner.rl"
	{te = p+1;{
        /*cout << "*\n  ";*/
        docubody_.push_back("\n");
        docline = false;
      }}
	goto st1640;
tr182:
#line 32 "mfilescanner.rl"
	{line++;}
#line 499 "mfilescanner.rl"
	{te = p+1;{
        clist_ = &(retval_list_[tmp_string]);
        docline = false;
        {stack[top++] = 1640; goto st1637;}
      }}
	goto st1640;
tr208:
#line 32 "mfilescanner.rl"
	{line++;}
#line 486 "mfilescanner.rl"
	{te = p+1;{
        clist_ = &(optional_list_[tmp_string]);
        docline = false;
        {stack[top++] = 1640; goto st1637;}
      }}
	goto st1640;
tr220:
#line 32 "mfilescanner.rl"
	{line++;}
#line 509 "mfilescanner.rl"
	{te = p+1;{
        clist_ = &param_list_;
        docline = false;
        {stack[top++] = 1640; goto st1637;}
      }}
	goto st1640;
tr247:
#line 32 "mfilescanner.rl"
	{line++;}
#line 472 "mfilescanner.rl"
	{te = p+1;{
        //cout << tmp_string << '\n';
        clist_ = &(required_list_[tmp_string]);
        docline = false;
        {stack[top++] = 1640; goto st1637;}
      }}
	goto st1640;
tr260:
#line 32 "mfilescanner.rl"
	{line++;}
#line 519 "mfilescanner.rl"
	{te = p+1;{
        clist_ = &return_list_;
        docline = false;
        {stack[top++] = 1640; goto st1637;}
      }}
	goto st1640;
tr262:
#line 32 "mfilescanner.rl"
	{line++;}
#line 596 "mfilescanner.rl"
	{te = p+1;{
        // cout << "*/\n";
        if(! docline)
        {
          if(is_class_)
          {
            if(class_part_ == Header)
            {
              end_of_class_doc();
              {goto st1668;}
            } else if(class_part_ == Method)
              {goto st1632;}
            else if(class_part_ == Property)
            {
              end_of_property_doc();
              {goto st1661;}
            }
            else
              {goto st1632;}
          }
        }
        else
        {
          int offset = ( latex_begin ? 0 : 1 );
          docubody_.push_back(string(tmp_p+1, p - tmp_p - offset));
          docline = false;
        }
      }}
	goto st1640;
tr263:
#line 570 "mfilescanner.rl"
	{{p = ((te))-1;}{
        if(!docline)
        {
          p = ts-1;
          {goto st1632;}
        }
      }}
	goto st1640;
tr264:
#line 32 "mfilescanner.rl"
	{line++;}
#line 584 "mfilescanner.rl"
	{te = p+1;{
        if(! docline)
          {goto st1632;}
        else
        {
          docubody_.push_back("@par " + string(tmp_p+1, ts - tmp_p-1)+"\n");
          docline = false;
        }
      }}
	goto st1640;
tr265:
#line 560 "mfilescanner.rl"
	{{p = ((te))-1;}{
        if(!docline)
        {
          p = ts-1;
          {goto st1632;}
        }
      }}
	goto st1640;
tr269:
#line 545 "mfilescanner.rl"
	{te = p+1;{
        if(!docline)
        {
          p = ts-1;
          {goto st1632;}
        }
        string s;
        s.assign(tmp_p+1, ts - tmp_p-1);
        docubody_.push_back(s+"@sa ");
        tmp_p = p+1;
      }}
	goto st1640;
tr2268:
#line 560 "mfilescanner.rl"
	{te = p;p--;{
        if(!docline)
        {
          p = ts-1;
          {goto st1632;}
        }
      }}
	goto st1640;
tr2269:
#line 580 "mfilescanner.rl"
	{te = p;p--;}
	goto st1640;
tr2270:
#line 535 "mfilescanner.rl"
	{te = p;p--;{
        if(!docline)
        {
          docline = true;
          tmp_p = p;
        }
      }}
	goto st1640;
tr2271:
#line 570 "mfilescanner.rl"
	{te = p;p--;{
        if(!docline)
        {
          p = ts-1;
          {goto st1632;}
        }
      }}
	goto st1640;
st1640:
#line 1 "mfilescanner.rl"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof1640;
case 1640:
#line 1 "mfilescanner.rl"
	{ts = p;}
#line 22756 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr2264;
		case 10: goto tr262;
		case 13: goto st205;
		case 32: goto tr2264;
		case 37: goto tr148;
		case 58: goto tr2266;
		case 83: goto st1645;
		case 115: goto st1645;
	}
	goto st1641;
st1641:
	if ( ++p == pe )
		goto _test_eof1641;
case 1641:
	switch( (*p) ) {
		case 0: goto tr2268;
		case 13: goto tr2268;
		case 32: goto tr2268;
		case 37: goto tr2268;
		case 58: goto tr2268;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto tr2268;
	goto st1641;
tr2264:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st1642;
st1642:
	if ( ++p == pe )
		goto _test_eof1642;
case 1642:
#line 22791 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st107;
		case 32: goto st107;
		case 37: goto tr148;
	}
	goto tr2269;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
	switch( (*p) ) {
		case 9: goto st107;
		case 32: goto st107;
		case 37: goto tr148;
	}
	goto tr146;
tr148:
#line 1 "mfilescanner.rl"
	{te = p+1;}
#line 105 "mfilescanner.rl"
	{ tmp_p = p + 1; }
	goto st1643;
st1643:
	if ( ++p == pe )
		goto _test_eof1643;
case 1643:
#line 22818 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st108;
		case 10: goto tr151;
		case 13: goto st109;
		case 32: goto st108;
		case 71: goto st110;
		case 79: goto st134;
		case 80: goto st157;
		case 82: goto st169;
		case 103: goto st110;
		case 111: goto st134;
		case 112: goto st157;
		case 114: goto st169;
	}
	goto tr2270;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
	switch( (*p) ) {
		case 9: goto st108;
		case 10: goto tr151;
		case 13: goto st109;
		case 32: goto st108;
		case 71: goto st110;
		case 79: goto st134;
		case 80: goto st157;
		case 82: goto st169;
		case 103: goto st110;
		case 111: goto st134;
		case 112: goto st157;
		case 114: goto st169;
	}
	goto tr149;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
	if ( (*p) == 10 )
		goto tr151;
	goto tr149;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
	switch( (*p) ) {
		case 69: goto st111;
		case 101: goto st111;
	}
	goto tr149;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
	switch( (*p) ) {
		case 78: goto st112;
		case 110: goto st112;
	}
	goto tr149;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
	switch( (*p) ) {
		case 69: goto st113;
		case 101: goto st113;
	}
	goto tr149;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
	switch( (*p) ) {
		case 82: goto st114;
		case 114: goto st114;
	}
	goto tr149;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
	switch( (*p) ) {
		case 65: goto st115;
		case 97: goto st115;
	}
	goto tr149;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
	switch( (*p) ) {
		case 84: goto st116;
		case 116: goto st116;
	}
	goto tr149;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
	switch( (*p) ) {
		case 69: goto st117;
		case 101: goto st117;
	}
	goto tr149;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
	switch( (*p) ) {
		case 68: goto st118;
		case 100: goto st118;
	}
	goto tr149;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
	if ( (*p) == 32 )
		goto st119;
	goto tr149;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
	switch( (*p) ) {
		case 70: goto st120;
		case 102: goto st120;
	}
	goto tr149;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
	switch( (*p) ) {
		case 73: goto st121;
		case 105: goto st121;
	}
	goto tr149;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
	switch( (*p) ) {
		case 69: goto st122;
		case 101: goto st122;
	}
	goto tr149;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
	switch( (*p) ) {
		case 76: goto st123;
		case 108: goto st123;
	}
	goto tr149;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
	switch( (*p) ) {
		case 68: goto st124;
		case 100: goto st124;
	}
	goto tr149;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
	switch( (*p) ) {
		case 83: goto st125;
		case 115: goto st125;
	}
	goto tr149;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
	if ( (*p) == 32 )
		goto st126;
	goto tr149;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
	switch( (*p) ) {
		case 79: goto st127;
		case 111: goto st127;
	}
	goto tr149;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
	switch( (*p) ) {
		case 70: goto st128;
		case 102: goto st128;
	}
	goto tr149;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
	if ( (*p) == 32 )
		goto st129;
	goto tr149;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	if ( (*p) == 95 )
		goto tr176;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr176;
	} else if ( (*p) >= 65 )
		goto tr176;
	goto tr149;
tr176:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st130;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
#line 23045 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr177;
		case 32: goto tr177;
		case 58: goto tr179;
		case 95: goto st130;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st130;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st130;
	} else
		goto st130;
	goto tr149;
tr177:
#line 69 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st131;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
#line 23069 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st131;
		case 32: goto st131;
		case 58: goto st132;
	}
	goto tr149;
tr179:
#line 69 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st132;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
#line 23084 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st132;
		case 10: goto tr182;
		case 13: goto st133;
		case 32: goto st132;
	}
	goto tr149;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
	if ( (*p) == 10 )
		goto tr182;
	goto tr149;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
	switch( (*p) ) {
		case 80: goto st135;
		case 112: goto st135;
	}
	goto tr149;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
	switch( (*p) ) {
		case 84: goto st136;
		case 116: goto st136;
	}
	goto tr149;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
	switch( (*p) ) {
		case 73: goto st137;
		case 105: goto st137;
	}
	goto tr149;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
	switch( (*p) ) {
		case 79: goto st138;
		case 111: goto st138;
	}
	goto tr149;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
	switch( (*p) ) {
		case 78: goto st139;
		case 110: goto st139;
	}
	goto tr149;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
	switch( (*p) ) {
		case 65: goto st140;
		case 97: goto st140;
	}
	goto tr149;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
	switch( (*p) ) {
		case 76: goto st141;
		case 108: goto st141;
	}
	goto tr149;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
	if ( (*p) == 32 )
		goto st142;
	goto tr149;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
	switch( (*p) ) {
		case 70: goto st143;
		case 102: goto st143;
	}
	goto tr149;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
	switch( (*p) ) {
		case 73: goto st144;
		case 105: goto st144;
	}
	goto tr149;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
	switch( (*p) ) {
		case 69: goto st145;
		case 101: goto st145;
	}
	goto tr149;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
	switch( (*p) ) {
		case 76: goto st146;
		case 108: goto st146;
	}
	goto tr149;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
	switch( (*p) ) {
		case 68: goto st147;
		case 100: goto st147;
	}
	goto tr149;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
	switch( (*p) ) {
		case 83: goto st148;
		case 115: goto st148;
	}
	goto tr149;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
	if ( (*p) == 32 )
		goto st149;
	goto tr149;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
	switch( (*p) ) {
		case 79: goto st150;
		case 111: goto st150;
	}
	goto tr149;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
	switch( (*p) ) {
		case 70: goto st151;
		case 102: goto st151;
	}
	goto tr149;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
	if ( (*p) == 32 )
		goto st152;
	goto tr149;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
	if ( (*p) == 95 )
		goto tr202;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr202;
	} else if ( (*p) >= 65 )
		goto tr202;
	goto tr149;
tr202:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st153;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
#line 23275 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr203;
		case 32: goto tr203;
		case 58: goto tr205;
		case 95: goto st153;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st153;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st153;
	} else
		goto st153;
	goto tr149;
tr203:
#line 69 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st154;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
#line 23299 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st154;
		case 32: goto st154;
		case 58: goto st155;
	}
	goto tr149;
tr205:
#line 69 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st155;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
#line 23314 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st155;
		case 10: goto tr208;
		case 13: goto st156;
		case 32: goto st155;
	}
	goto tr149;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
	if ( (*p) == 10 )
		goto tr208;
	goto tr149;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
	switch( (*p) ) {
		case 65: goto st158;
		case 97: goto st158;
	}
	goto tr149;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
	switch( (*p) ) {
		case 82: goto st159;
		case 114: goto st159;
	}
	goto tr149;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
	switch( (*p) ) {
		case 65: goto st160;
		case 97: goto st160;
	}
	goto tr149;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
	switch( (*p) ) {
		case 77: goto st161;
		case 109: goto st161;
	}
	goto tr149;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
	switch( (*p) ) {
		case 69: goto st162;
		case 101: goto st162;
	}
	goto tr149;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
	switch( (*p) ) {
		case 84: goto st163;
		case 116: goto st163;
	}
	goto tr149;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
	switch( (*p) ) {
		case 69: goto st164;
		case 101: goto st164;
	}
	goto tr149;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
	switch( (*p) ) {
		case 82: goto st165;
		case 114: goto st165;
	}
	goto tr149;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
	switch( (*p) ) {
		case 83: goto st166;
		case 115: goto st166;
	}
	goto tr149;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
	switch( (*p) ) {
		case 9: goto st166;
		case 32: goto st166;
		case 58: goto st167;
	}
	goto tr149;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
	switch( (*p) ) {
		case 9: goto st167;
		case 10: goto tr220;
		case 13: goto st168;
		case 32: goto st167;
	}
	goto tr149;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
	if ( (*p) == 10 )
		goto tr220;
	goto tr149;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
	switch( (*p) ) {
		case 69: goto st170;
		case 101: goto st170;
	}
	goto tr149;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
	switch( (*p) ) {
		case 81: goto st171;
		case 84: goto st192;
		case 113: goto st171;
		case 116: goto st192;
	}
	goto tr149;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
	switch( (*p) ) {
		case 85: goto st172;
		case 117: goto st172;
	}
	goto tr149;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
	switch( (*p) ) {
		case 73: goto st173;
		case 105: goto st173;
	}
	goto tr149;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
	switch( (*p) ) {
		case 82: goto st174;
		case 114: goto st174;
	}
	goto tr149;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
	switch( (*p) ) {
		case 69: goto st175;
		case 101: goto st175;
	}
	goto tr149;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
	switch( (*p) ) {
		case 68: goto st176;
		case 100: goto st176;
	}
	goto tr149;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
	if ( (*p) == 32 )
		goto st177;
	goto tr149;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
	switch( (*p) ) {
		case 70: goto st178;
		case 102: goto st178;
	}
	goto tr149;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
	switch( (*p) ) {
		case 73: goto st179;
		case 105: goto st179;
	}
	goto tr149;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
	switch( (*p) ) {
		case 69: goto st180;
		case 101: goto st180;
	}
	goto tr149;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
	switch( (*p) ) {
		case 76: goto st181;
		case 108: goto st181;
	}
	goto tr149;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
	switch( (*p) ) {
		case 68: goto st182;
		case 100: goto st182;
	}
	goto tr149;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
	switch( (*p) ) {
		case 83: goto st183;
		case 115: goto st183;
	}
	goto tr149;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
	if ( (*p) == 32 )
		goto st184;
	goto tr149;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
	switch( (*p) ) {
		case 79: goto st185;
		case 111: goto st185;
	}
	goto tr149;
st185:
	if ( ++p == pe )
		goto _test_eof185;
case 185:
	switch( (*p) ) {
		case 70: goto st186;
		case 102: goto st186;
	}
	goto tr149;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
	if ( (*p) == 32 )
		goto st187;
	goto tr149;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
	if ( (*p) == 95 )
		goto tr241;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr241;
	} else if ( (*p) >= 65 )
		goto tr241;
	goto tr149;
tr241:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st188;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
#line 23616 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr242;
		case 32: goto tr242;
		case 58: goto tr244;
		case 95: goto st188;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st188;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st188;
	} else
		goto st188;
	goto tr149;
tr242:
#line 69 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st189;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
#line 23640 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st189;
		case 32: goto st189;
		case 58: goto st190;
	}
	goto tr149;
tr244:
#line 69 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p-tmp_p); }
	goto st190;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
#line 23655 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st190;
		case 10: goto tr247;
		case 13: goto st191;
		case 32: goto st190;
	}
	goto tr149;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
	if ( (*p) == 10 )
		goto tr247;
	goto tr149;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
	switch( (*p) ) {
		case 85: goto st193;
		case 117: goto st193;
	}
	goto tr149;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
	switch( (*p) ) {
		case 82: goto st194;
		case 114: goto st194;
	}
	goto tr149;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
	switch( (*p) ) {
		case 78: goto st195;
		case 110: goto st195;
	}
	goto tr149;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
	if ( (*p) == 32 )
		goto st196;
	goto tr149;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
	switch( (*p) ) {
		case 86: goto st197;
		case 118: goto st197;
	}
	goto tr149;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
	switch( (*p) ) {
		case 65: goto st198;
		case 97: goto st198;
	}
	goto tr149;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
	switch( (*p) ) {
		case 76: goto st199;
		case 108: goto st199;
	}
	goto tr149;
st199:
	if ( ++p == pe )
		goto _test_eof199;
case 199:
	switch( (*p) ) {
		case 85: goto st200;
		case 117: goto st200;
	}
	goto tr149;
st200:
	if ( ++p == pe )
		goto _test_eof200;
case 200:
	switch( (*p) ) {
		case 69: goto st201;
		case 101: goto st201;
	}
	goto tr149;
st201:
	if ( ++p == pe )
		goto _test_eof201;
case 201:
	switch( (*p) ) {
		case 83: goto st202;
		case 115: goto st202;
	}
	goto tr149;
st202:
	if ( ++p == pe )
		goto _test_eof202;
case 202:
	switch( (*p) ) {
		case 9: goto st202;
		case 32: goto st202;
		case 58: goto st203;
	}
	goto tr149;
st203:
	if ( ++p == pe )
		goto _test_eof203;
case 203:
	switch( (*p) ) {
		case 9: goto st203;
		case 10: goto tr260;
		case 13: goto st204;
		case 32: goto st203;
	}
	goto tr149;
st204:
	if ( ++p == pe )
		goto _test_eof204;
case 204:
	if ( (*p) == 10 )
		goto tr260;
	goto tr149;
st205:
	if ( ++p == pe )
		goto _test_eof205;
case 205:
	if ( (*p) == 10 )
		goto tr262;
	goto st0;
tr2266:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st1644;
st1644:
	if ( ++p == pe )
		goto _test_eof1644;
case 1644:
#line 23801 "mfilescanner.cc"
	switch( (*p) ) {
		case 10: goto tr264;
		case 13: goto st206;
	}
	goto tr2271;
st206:
	if ( ++p == pe )
		goto _test_eof206;
case 206:
	if ( (*p) == 10 )
		goto tr264;
	goto tr263;
st1645:
	if ( ++p == pe )
		goto _test_eof1645;
case 1645:
	switch( (*p) ) {
		case 0: goto tr2268;
		case 13: goto tr2268;
		case 32: goto tr2268;
		case 37: goto tr2268;
		case 58: goto tr2268;
		case 69: goto st1646;
		case 101: goto st1646;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto tr2268;
	goto st1641;
st1646:
	if ( ++p == pe )
		goto _test_eof1646;
case 1646:
	switch( (*p) ) {
		case 0: goto tr2268;
		case 13: goto tr2268;
		case 32: goto tr2268;
		case 37: goto tr2268;
		case 58: goto tr2268;
		case 69: goto tr2274;
		case 101: goto tr2274;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto tr2268;
	goto st1641;
tr2274:
#line 1 "mfilescanner.rl"
	{te = p+1;}
	goto st1647;
st1647:
	if ( ++p == pe )
		goto _test_eof1647;
case 1647:
#line 23854 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr2268;
		case 13: goto tr2268;
		case 32: goto st207;
		case 37: goto tr2268;
		case 58: goto tr2268;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto tr2268;
	goto st1641;
st207:
	if ( ++p == pe )
		goto _test_eof207;
case 207:
	switch( (*p) ) {
		case 65: goto st208;
		case 97: goto st208;
	}
	goto tr265;
st208:
	if ( ++p == pe )
		goto _test_eof208;
case 208:
	switch( (*p) ) {
		case 76: goto st209;
		case 108: goto st209;
	}
	goto tr265;
st209:
	if ( ++p == pe )
		goto _test_eof209;
case 209:
	switch( (*p) ) {
		case 83: goto st210;
		case 115: goto st210;
	}
	goto tr265;
st210:
	if ( ++p == pe )
		goto _test_eof210;
case 210:
	switch( (*p) ) {
		case 79: goto tr269;
		case 111: goto tr269;
	}
	goto tr265;
tr273:
#line 32 "mfilescanner.rl"
	{line++;}
#line 634 "mfilescanner.rl"
	{te = p+1;{ {goto st1649;} }}
	goto st1648;
tr278:
#line 32 "mfilescanner.rl"
	{line++;}
#line 631 "mfilescanner.rl"
	{te = p+1;}
	goto st1648;
st1648:
#line 1 "mfilescanner.rl"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof1648;
case 1648:
#line 1 "mfilescanner.rl"
	{ts = p;}
#line 23921 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st211;
		case 32: goto st211;
		case 37: goto tr271;
	}
	goto st0;
st211:
	if ( ++p == pe )
		goto _test_eof211;
case 211:
	switch( (*p) ) {
		case 9: goto st211;
		case 32: goto st211;
		case 37: goto tr271;
	}
	goto st0;
tr271:
#line 105 "mfilescanner.rl"
	{ tmp_p = p + 1; }
	goto st212;
st212:
	if ( ++p == pe )
		goto _test_eof212;
case 212:
#line 23946 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr273;
		case 46: goto st213;
	}
	goto st212;
st213:
	if ( ++p == pe )
		goto _test_eof213;
case 213:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr273;
		case 46: goto st214;
	}
	goto st212;
st214:
	if ( ++p == pe )
		goto _test_eof214;
case 214:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr273;
		case 46: goto st215;
	}
	goto st212;
st215:
	if ( ++p == pe )
		goto _test_eof215;
case 215:
	switch( (*p) ) {
		case 9: goto st216;
		case 10: goto tr278;
		case 13: goto st217;
		case 32: goto st216;
		case 46: goto st218;
	}
	goto st0;
st216:
	if ( ++p == pe )
		goto _test_eof216;
case 216:
	switch( (*p) ) {
		case 9: goto st216;
		case 10: goto tr278;
		case 13: goto st217;
		case 32: goto st216;
	}
	goto st0;
st217:
	if ( ++p == pe )
		goto _test_eof217;
case 217:
	if ( (*p) == 10 )
		goto tr278;
	goto st0;
st218:
	if ( ++p == pe )
		goto _test_eof218;
case 218:
	switch( (*p) ) {
		case 9: goto st216;
		case 10: goto tr278;
		case 13: goto st217;
		case 32: goto st216;
		case 46: goto st216;
	}
	goto st0;
tr281:
#line 1 "mfilescanner.rl"
	{	switch( act ) {
	case 0:
	{{goto st0;}}
	break;
	case 40:
	{{p = ((te))-1;}
        p--;
        //cout << "*/\n";
        if(is_class_)
        {
          if(class_part_ == Header)
          {
            end_of_class_doc();
            {goto st1668;}
          } else if(class_part_ == Method)
            {goto st1632;}
          else if(class_part_ == Property)
          {
            end_of_property_doc();
            {goto st1661;}
          }
        }
        else
          {goto st1632;}
      }
	break;
	}
	}
	goto st1649;
tr284:
#line 32 "mfilescanner.rl"
	{line++;}
#line 652 "mfilescanner.rl"
	{te = p+1;{
        /*cout << "*\n";*/
        {goto st1640;}
      }}
	goto st1649;
tr286:
#line 32 "mfilescanner.rl"
	{line++;}
#line 645 "mfilescanner.rl"
	{te = p+1;{
        /* cout << "*"; cout.write(tmp_p, p - tmp_p+1); */
        docuheader_.push_back(string(tmp_p, p - tmp_p+1));
      }}
	goto st1649;
tr2276:
#line 659 "mfilescanner.rl"
	{te = p+1;{
        p--;
        //cout << "*/\n";
        if(is_class_)
        {
          if(class_part_ == Header)
          {
            end_of_class_doc();
            {goto st1668;}
          } else if(class_part_ == Method)
            {goto st1632;}
          else if(class_part_ == Property)
          {
            end_of_property_doc();
            {goto st1661;}
          }
        }
        else
          {goto st1632;}
      }}
	goto st1649;
tr2279:
#line 659 "mfilescanner.rl"
	{te = p;p--;{
        p--;
        //cout << "*/\n";
        if(is_class_)
        {
          if(class_part_ == Header)
          {
            end_of_class_doc();
            {goto st1668;}
          } else if(class_part_ == Method)
            {goto st1632;}
          else if(class_part_ == Property)
          {
            end_of_property_doc();
            {goto st1661;}
          }
        }
        else
          {goto st1632;}
      }}
	goto st1649;
st1649:
#line 1 "mfilescanner.rl"
	{ts = 0;}
#line 1 "mfilescanner.rl"
	{act = 0;}
	if ( ++p == pe )
		goto _test_eof1649;
case 1649:
#line 1 "mfilescanner.rl"
	{ts = p;}
#line 24120 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr2277;
		case 32: goto tr2277;
		case 37: goto tr2278;
	}
	goto tr2276;
tr2277:
#line 1 "mfilescanner.rl"
	{te = p+1;}
#line 659 "mfilescanner.rl"
	{act = 40;}
	goto st1650;
st1650:
	if ( ++p == pe )
		goto _test_eof1650;
case 1650:
#line 24137 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr2277;
		case 32: goto tr2277;
		case 37: goto tr2278;
	}
	goto tr2276;
tr2278:
#line 105 "mfilescanner.rl"
	{ tmp_p = p + 1; }
	goto st219;
st219:
	if ( ++p == pe )
		goto _test_eof219;
case 219:
#line 24152 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr281;
		case 9: goto st219;
		case 10: goto tr284;
		case 13: goto st221;
		case 32: goto st219;
	}
	goto st220;
st220:
	if ( ++p == pe )
		goto _test_eof220;
case 220:
	switch( (*p) ) {
		case 0: goto tr281;
		case 10: goto tr286;
	}
	goto st220;
st221:
	if ( ++p == pe )
		goto _test_eof221;
case 221:
	if ( (*p) == 10 )
		goto tr284;
	goto tr281;
tr305:
#line 32 "mfilescanner.rl"
	{line++;}
	goto st1652;
tr310:
#line 32 "mfilescanner.rl"
	{line++;}
#line 795 "mfilescanner.rl"
	{ tmp_string.assign(tmp_p, p - tmp_p);
                if(tmp_string.find("e") == eventindent_)
                  { {goto st1668;} }
              }
	goto st1652;
st1652:
#line 1 "mfilescanner.rl"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof1652;
case 1652:
#line 24196 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto tr2280;
		case 10: goto tr305;
		case 32: goto tr2280;
		case 101: goto tr2281;
	}
	goto st237;
st237:
	if ( ++p == pe )
		goto _test_eof237;
case 237:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr305;
	}
	goto st237;
tr2280:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st238;
st238:
	if ( ++p == pe )
		goto _test_eof238;
case 238:
#line 24222 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st238;
		case 10: goto tr305;
		case 32: goto st238;
		case 101: goto st239;
	}
	goto st237;
tr2281:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st239;
st239:
	if ( ++p == pe )
		goto _test_eof239;
case 239:
#line 24239 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr305;
		case 110: goto st240;
	}
	goto st237;
st240:
	if ( ++p == pe )
		goto _test_eof240;
case 240:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr305;
		case 100: goto st241;
	}
	goto st237;
st241:
	if ( ++p == pe )
		goto _test_eof241;
case 241:
	switch( (*p) ) {
		case 0: goto st0;
		case 9: goto st241;
		case 10: goto tr310;
		case 13: goto st242;
		case 32: goto st241;
		case 59: goto st241;
	}
	goto st237;
st242:
	if ( ++p == pe )
		goto _test_eof242;
case 242:
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr310;
	}
	goto st237;
tr1034:
#line 67 "mfilescanner.rl"
	{ cout.write(tmp_p, p - tmp_p); }
#line 32 "mfilescanner.rl"
	{line++;}
#line 835 "mfilescanner.rl"
	{ cout << "\n";}
#line 835 "mfilescanner.rl"
	{ {goto st786;} }
	goto st1661;
tr1038:
#line 32 "mfilescanner.rl"
	{line++;}
#line 835 "mfilescanner.rl"
	{ cout << "\n";}
#line 835 "mfilescanner.rl"
	{ {goto st786;} }
	goto st1661;
tr1042:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
#line 32 "mfilescanner.rl"
	{line++;}
#line 831 "mfilescanner.rl"
	{
            cout << "\n/** @var " << property_list_.back() << "\n" << " * ";
            cout.write(tmp_p, p-tmp_p);
            cout << "*/";
          }
#line 835 "mfilescanner.rl"
	{ {goto st786;} }
	goto st1661;
tr1045:
#line 32 "mfilescanner.rl"
	{line++;}
#line 831 "mfilescanner.rl"
	{
            cout << "\n/** @var " << property_list_.back() << "\n" << " * ";
            cout.write(tmp_p, p-tmp_p);
            cout << "*/";
          }
#line 835 "mfilescanner.rl"
	{ {goto st786;} }
	goto st1661;
st1661:
#line 1 "mfilescanner.rl"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof1661;
case 1661:
#line 24328 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st777;
		case 32: goto st777;
		case 95: goto tr1027;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1027;
	} else if ( (*p) >= 65 )
		goto tr1027;
	goto st0;
st777:
	if ( ++p == pe )
		goto _test_eof777;
case 777:
	switch( (*p) ) {
		case 9: goto st777;
		case 32: goto st777;
		case 95: goto tr1027;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1027;
	} else if ( (*p) >= 65 )
		goto tr1027;
	goto st0;
tr1027:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
#line 823 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            property_list_.push_back(s);
            cout << propertyparams_.ccprefix() << " " << s;
            }
	goto st778;
tr1029:
#line 823 "mfilescanner.rl"
	{
            string s(tmp_p, p - tmp_p);
            property_list_.push_back(s);
            cout << propertyparams_.ccprefix() << " " << s;
            }
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st778;
st778:
	if ( ++p == pe )
		goto _test_eof778;
case 778:
#line 24379 "mfilescanner.cc"
	switch( (*p) ) {
		case 59: goto tr1030;
		case 95: goto tr1029;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr1029;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1029;
	} else
		goto tr1029;
	goto tr1028;
tr1028:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st779;
st779:
	if ( ++p == pe )
		goto _test_eof779;
case 779:
#line 24401 "mfilescanner.cc"
	if ( (*p) == 59 )
		goto st780;
	goto st779;
tr1030:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st780;
st780:
	if ( ++p == pe )
		goto _test_eof780;
case 780:
#line 24413 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr1033;
		case 10: goto tr1034;
		case 13: goto tr1035;
		case 32: goto tr1033;
		case 37: goto tr1036;
	}
	goto st0;
tr1033:
#line 67 "mfilescanner.rl"
	{ cout.write(tmp_p, p - tmp_p); }
	goto st781;
st781:
	if ( ++p == pe )
		goto _test_eof781;
case 781:
#line 24430 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto st781;
		case 10: goto tr1038;
		case 13: goto st782;
		case 32: goto st781;
		case 37: goto st783;
	}
	goto st0;
tr1035:
#line 67 "mfilescanner.rl"
	{ cout.write(tmp_p, p - tmp_p); }
	goto st782;
st782:
	if ( ++p == pe )
		goto _test_eof782;
case 782:
#line 24447 "mfilescanner.cc"
	if ( (*p) == 10 )
		goto tr1038;
	goto st0;
tr1036:
#line 67 "mfilescanner.rl"
	{ cout.write(tmp_p, p - tmp_p); }
	goto st783;
st783:
	if ( ++p == pe )
		goto _test_eof783;
case 783:
#line 24459 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1042;
		case 13: goto tr1043;
	}
	goto tr1041;
tr1041:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st784;
st784:
	if ( ++p == pe )
		goto _test_eof784;
case 784:
#line 24474 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto st0;
		case 10: goto tr1045;
		case 13: goto st785;
	}
	goto st784;
tr1043:
#line 65 "mfilescanner.rl"
	{ tmp_p = p; }
	goto st785;
st785:
	if ( ++p == pe )
		goto _test_eof785;
case 785:
#line 24489 "mfilescanner.cc"
	if ( (*p) == 10 )
		goto tr1045;
	goto st0;
tr1903:
#line 1 "mfilescanner.rl"
	{	switch( act ) {
	case 0:
	{{goto st0;}}
	break;
	case 41:
	{{p = ((te))-1;}
        cout.write(tmp_p, p - tmp_p+1);
        {stack[top++] = 1668; goto st1609;}
      }
	break;
	case 42:
	{{p = ((te))-1;}}
	break;
	}
	}
	goto st1668;
tr1915:
#line 863 "mfilescanner.rl"
	{{p = ((te))-1;}}
	goto st1668;
tr1917:
#line 32 "mfilescanner.rl"
	{line++;}
#line 858 "mfilescanner.rl"
	{te = p+1;{
        cout.write(tmp_p, p - tmp_p+1);
        {stack[top++] = 1668; goto st1609;}
      }}
	goto st1668;
tr1926:
#line 884 "mfilescanner.rl"
	{te = p+1;{
        std::string tmp_string(ts, te-ts);
        eventindent_ = tmp_string.find("e");
        class_part_ = Event;
        {goto st1652;}
      }}
	goto st1668;
tr1928:
#line 865 "mfilescanner.rl"
	{te = p+1;{
      {goto st1608;}
    }}
	goto st1668;
tr1934:
#line 877 "mfilescanner.rl"
	{te = p+1;{
        methodparams_ = MethodParams();
        access_ = AccessStruct();
        class_part_ = Method;
        {goto st243;}
      }}
	goto st1668;
tr1943:
#line 870 "mfilescanner.rl"
	{te = p+1;{
        propertyparams_ = PropParams();
        access_ = AccessStruct();
        class_part_ = Property;
        {goto st786;}
      }}
	goto st1668;
tr2295:
#line 863 "mfilescanner.rl"
	{te = p;p--;}
	goto st1668;
st1668:
#line 1 "mfilescanner.rl"
	{ts = 0;}
#line 1 "mfilescanner.rl"
	{act = 0;}
	if ( ++p == pe )
		goto _test_eof1668;
case 1668:
#line 1 "mfilescanner.rl"
	{ts = p;}
#line 24571 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr2289;
		case 32: goto tr2289;
		case 37: goto tr2290;
		case 46: goto st1420;
		case 101: goto st1434;
		case 109: goto st1436;
		case 112: goto st1442;
	}
	goto st0;
tr2289:
#line 1 "mfilescanner.rl"
	{te = p+1;}
#line 863 "mfilescanner.rl"
	{act = 42;}
	goto st1669;
st1669:
	if ( ++p == pe )
		goto _test_eof1669;
case 1669:
#line 24592 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr2289;
		case 32: goto tr2289;
		case 37: goto tr2290;
		case 46: goto st1420;
		case 101: goto st1429;
	}
	goto tr2295;
tr2290:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1417;
st1417:
	if ( ++p == pe )
		goto _test_eof1417;
case 1417:
#line 24609 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr1903;
		case 10: goto tr1905;
		case 124: goto tr1906;
	}
	goto tr1904;
tr2300:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1418;
tr1904:
#line 94 "mfilescanner.rl"
	{ cout << "/*"; tmp_p = p; }
	goto st1418;
tr1906:
#line 91 "mfilescanner.rl"
	{ cout << "/**"; tmp_p = p+1; }
	goto st1418;
st1418:
	if ( ++p == pe )
		goto _test_eof1418;
case 1418:
#line 24632 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr1903;
		case 10: goto tr1908;
	}
	goto st1418;
tr1908:
#line 1 "mfilescanner.rl"
	{te = p+1;}
#line 32 "mfilescanner.rl"
	{line++;}
#line 858 "mfilescanner.rl"
	{act = 41;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
	goto st1670;
tr1910:
#line 1 "mfilescanner.rl"
	{te = p+1;}
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 863 "mfilescanner.rl"
	{act = 42;}
	goto st1670;
tr1913:
#line 1 "mfilescanner.rl"
	{te = p+1;}
#line 32 "mfilescanner.rl"
	{line++;}
#line 863 "mfilescanner.rl"
	{act = 42;}
	goto st1670;
tr1920:
#line 1 "mfilescanner.rl"
	{te = p+1;}
#line 32 "mfilescanner.rl"
	{line++;}
#line 858 "mfilescanner.rl"
	{act = 41;}
	goto st1670;
tr2297:
#line 1 "mfilescanner.rl"
	{te = p+1;}
#line 863 "mfilescanner.rl"
	{act = 42;}
	goto st1670;
st1670:
	if ( ++p == pe )
		goto _test_eof1670;
case 1670:
#line 24690 "mfilescanner.cc"
	switch( (*p) ) {
		case 9: goto tr2297;
		case 32: goto tr2297;
		case 37: goto tr2298;
		case 46: goto st1420;
	}
	goto tr1903;
tr2298:
#line 118 "mfilescanner.rl"
	{ tmp_p = p+1; }
	goto st1419;
st1419:
	if ( ++p == pe )
		goto _test_eof1419;
case 1419:
#line 24706 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr1903;
		case 10: goto tr1910;
	}
	goto st1419;
st1420:
	if ( ++p == pe )
		goto _test_eof1420;
case 1420:
	if ( (*p) == 46 )
		goto st1421;
	goto tr1903;
st1421:
	if ( ++p == pe )
		goto _test_eof1421;
case 1421:
	if ( (*p) == 46 )
		goto st1422;
	goto tr1903;
st1422:
	if ( ++p == pe )
		goto _test_eof1422;
case 1422:
	switch( (*p) ) {
		case 9: goto st1422;
		case 10: goto tr1913;
		case 13: goto st1423;
		case 32: goto st1422;
	}
	goto tr1903;
st1423:
	if ( ++p == pe )
		goto _test_eof1423;
case 1423:
	if ( (*p) == 10 )
		goto tr1913;
	goto tr1903;
tr1905:
#line 1 "mfilescanner.rl"
	{te = p+1;}
#line 94 "mfilescanner.rl"
	{ cout << "/*"; tmp_p = p; }
#line 32 "mfilescanner.rl"
	{line++;}
#line 110 "mfilescanner.rl"
	{
        cout << "/* ";
        cout.write(tmp_p, p - tmp_p) << "*/\n";
      }
#line 863 "mfilescanner.rl"
	{act = 42;}
	goto st1671;
tr2299:
#line 1 "mfilescanner.rl"
	{te = p+1;}
#line 863 "mfilescanner.rl"
	{act = 42;}
	goto st1671;
st1671:
	if ( ++p == pe )
		goto _test_eof1671;
case 1671:
#line 24769 "mfilescanner.cc"
	switch( (*p) ) {
		case 0: goto tr2295;
		case 9: goto tr2299;
		case 10: goto tr1917;
		case 32: goto tr2299;
		case 37: goto tr2300;
		case 46: goto st1425;
	}
	goto st1424;
st1424:
	if ( ++p == pe )
		goto _test_eof1424;
case 1424:
	switch( (*p) ) {
		case 0: goto tr1915;
		case 10: goto tr1917;
	}
	goto st1424;
st1425:
	if ( ++p == pe )
		goto _test_eof1425;
case 1425:
	switch( (*p) ) {
		case 0: goto tr1915;
		case 10: goto tr1917;
		case 46: goto st1426;
	}
	goto st1424;
st1426:
	if ( ++p == pe )
		goto _test_eof1426;
case 1426:
	switch( (*p) ) {
		case 0: goto tr1915;
		case 10: goto tr1917;
		case 46: goto st1427;
	}
	goto st1424;
st1427:
	if ( ++p == pe )
		goto _test_eof1427;
case 1427:
	switch( (*p) ) {
		case 0: goto tr1915;
		case 9: goto st1427;
		case 10: goto tr1920;
		case 13: goto st1428;
		case 32: goto st1427;
	}
	goto st1424;
st1428:
	if ( ++p == pe )
		goto _test_eof1428;
case 1428:
	switch( (*p) ) {
		case 0: goto tr1915;
		case 10: goto tr1920;
	}
	goto st1424;
st1429:
	if ( ++p == pe )
		goto _test_eof1429;
case 1429:
	if ( (*p) == 118 )
		goto st1430;
	goto tr1915;
st1430:
	if ( ++p == pe )
		goto _test_eof1430;
case 1430:
	if ( (*p) == 101 )
		goto st1431;
	goto tr1903;
st1431:
	if ( ++p == pe )
		goto _test_eof1431;
case 1431:
	if ( (*p) == 110 )
		goto st1432;
	goto tr1903;
st1432:
	if ( ++p == pe )
		goto _test_eof1432;
case 1432:
	if ( (*p) == 116 )
		goto st1433;
	goto tr1903;
st1433:
	if ( ++p == pe )
		goto _test_eof1433;
case 1433:
	if ( (*p) == 115 )
		goto tr1926;
	goto tr1903;
st1434:
	if ( ++p == pe )
		goto _test_eof1434;
case 1434:
	switch( (*p) ) {
		case 110: goto st1435;
		case 118: goto st1430;
	}
	goto st0;
st1435:
	if ( ++p == pe )
		goto _test_eof1435;
case 1435:
	if ( (*p) == 100 )
		goto tr1928;
	goto st0;
st1436:
	if ( ++p == pe )
		goto _test_eof1436;
case 1436:
	if ( (*p) == 101 )
		goto st1437;
	goto st0;
st1437:
	if ( ++p == pe )
		goto _test_eof1437;
case 1437:
	if ( (*p) == 116 )
		goto st1438;
	goto st0;
st1438:
	if ( ++p == pe )
		goto _test_eof1438;
case 1438:
	if ( (*p) == 104 )
		goto st1439;
	goto st0;
st1439:
	if ( ++p == pe )
		goto _test_eof1439;
case 1439:
	if ( (*p) == 111 )
		goto st1440;
	goto st0;
st1440:
	if ( ++p == pe )
		goto _test_eof1440;
case 1440:
	if ( (*p) == 100 )
		goto st1441;
	goto st0;
st1441:
	if ( ++p == pe )
		goto _test_eof1441;
case 1441:
	if ( (*p) == 115 )
		goto tr1934;
	goto st0;
st1442:
	if ( ++p == pe )
		goto _test_eof1442;
case 1442:
	if ( (*p) == 114 )
		goto st1443;
	goto st0;
st1443:
	if ( ++p == pe )
		goto _test_eof1443;
case 1443:
	if ( (*p) == 111 )
		goto st1444;
	goto st0;
st1444:
	if ( ++p == pe )
		goto _test_eof1444;
case 1444:
	if ( (*p) == 112 )
		goto st1445;
	goto st0;
st1445:
	if ( ++p == pe )
		goto _test_eof1445;
case 1445:
	if ( (*p) == 101 )
		goto st1446;
	goto st0;
st1446:
	if ( ++p == pe )
		goto _test_eof1446;
case 1446:
	if ( (*p) == 114 )
		goto st1447;
	goto st0;
st1447:
	if ( ++p == pe )
		goto _test_eof1447;
case 1447:
	if ( (*p) == 116 )
		goto st1448;
	goto st0;
st1448:
	if ( ++p == pe )
		goto _test_eof1448;
case 1448:
	if ( (*p) == 105 )
		goto st1449;
	goto st0;
st1449:
	if ( ++p == pe )
		goto _test_eof1449;
case 1449:
	if ( (*p) == 101 )
		goto st1450;
	goto st0;
st1450:
	if ( ++p == pe )
		goto _test_eof1450;
case 1450:
	if ( (*p) == 115 )
		goto tr1943;
	goto st0;
	}
	_test_eof1608: cs = 1608; goto _test_eof; 
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
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
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
	_test_eof1651: cs = 1651; goto _test_eof; 
	_test_eof233: cs = 233; goto _test_eof; 
	_test_eof234: cs = 234; goto _test_eof; 
	_test_eof235: cs = 235; goto _test_eof; 
	_test_eof236: cs = 236; goto _test_eof; 
	_test_eof243: cs = 243; goto _test_eof; 
	_test_eof244: cs = 244; goto _test_eof; 
	_test_eof245: cs = 245; goto _test_eof; 
	_test_eof246: cs = 246; goto _test_eof; 
	_test_eof247: cs = 247; goto _test_eof; 
	_test_eof248: cs = 248; goto _test_eof; 
	_test_eof249: cs = 249; goto _test_eof; 
	_test_eof1653: cs = 1653; goto _test_eof; 
	_test_eof1654: cs = 1654; goto _test_eof; 
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
	_test_eof1655: cs = 1655; goto _test_eof; 
	_test_eof1656: cs = 1656; goto _test_eof; 
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
	_test_eof314: cs = 314; goto _test_eof; 
	_test_eof315: cs = 315; goto _test_eof; 
	_test_eof316: cs = 316; goto _test_eof; 
	_test_eof317: cs = 317; goto _test_eof; 
	_test_eof318: cs = 318; goto _test_eof; 
	_test_eof319: cs = 319; goto _test_eof; 
	_test_eof320: cs = 320; goto _test_eof; 
	_test_eof321: cs = 321; goto _test_eof; 
	_test_eof322: cs = 322; goto _test_eof; 
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
	_test_eof338: cs = 338; goto _test_eof; 
	_test_eof339: cs = 339; goto _test_eof; 
	_test_eof340: cs = 340; goto _test_eof; 
	_test_eof341: cs = 341; goto _test_eof; 
	_test_eof342: cs = 342; goto _test_eof; 
	_test_eof343: cs = 343; goto _test_eof; 
	_test_eof344: cs = 344; goto _test_eof; 
	_test_eof345: cs = 345; goto _test_eof; 
	_test_eof346: cs = 346; goto _test_eof; 
	_test_eof347: cs = 347; goto _test_eof; 
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
	_test_eof359: cs = 359; goto _test_eof; 
	_test_eof360: cs = 360; goto _test_eof; 
	_test_eof361: cs = 361; goto _test_eof; 
	_test_eof362: cs = 362; goto _test_eof; 
	_test_eof363: cs = 363; goto _test_eof; 
	_test_eof364: cs = 364; goto _test_eof; 
	_test_eof365: cs = 365; goto _test_eof; 
	_test_eof366: cs = 366; goto _test_eof; 
	_test_eof367: cs = 367; goto _test_eof; 
	_test_eof368: cs = 368; goto _test_eof; 
	_test_eof369: cs = 369; goto _test_eof; 
	_test_eof370: cs = 370; goto _test_eof; 
	_test_eof371: cs = 371; goto _test_eof; 
	_test_eof372: cs = 372; goto _test_eof; 
	_test_eof373: cs = 373; goto _test_eof; 
	_test_eof374: cs = 374; goto _test_eof; 
	_test_eof375: cs = 375; goto _test_eof; 
	_test_eof1657: cs = 1657; goto _test_eof; 
	_test_eof1658: cs = 1658; goto _test_eof; 
	_test_eof376: cs = 376; goto _test_eof; 
	_test_eof377: cs = 377; goto _test_eof; 
	_test_eof378: cs = 378; goto _test_eof; 
	_test_eof379: cs = 379; goto _test_eof; 
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
	_test_eof393: cs = 393; goto _test_eof; 
	_test_eof394: cs = 394; goto _test_eof; 
	_test_eof395: cs = 395; goto _test_eof; 
	_test_eof396: cs = 396; goto _test_eof; 
	_test_eof397: cs = 397; goto _test_eof; 
	_test_eof398: cs = 398; goto _test_eof; 
	_test_eof399: cs = 399; goto _test_eof; 
	_test_eof400: cs = 400; goto _test_eof; 
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
	_test_eof421: cs = 421; goto _test_eof; 
	_test_eof422: cs = 422; goto _test_eof; 
	_test_eof423: cs = 423; goto _test_eof; 
	_test_eof424: cs = 424; goto _test_eof; 
	_test_eof425: cs = 425; goto _test_eof; 
	_test_eof426: cs = 426; goto _test_eof; 
	_test_eof427: cs = 427; goto _test_eof; 
	_test_eof428: cs = 428; goto _test_eof; 
	_test_eof429: cs = 429; goto _test_eof; 
	_test_eof1659: cs = 1659; goto _test_eof; 
	_test_eof1660: cs = 1660; goto _test_eof; 
	_test_eof430: cs = 430; goto _test_eof; 
	_test_eof431: cs = 431; goto _test_eof; 
	_test_eof432: cs = 432; goto _test_eof; 
	_test_eof433: cs = 433; goto _test_eof; 
	_test_eof434: cs = 434; goto _test_eof; 
	_test_eof435: cs = 435; goto _test_eof; 
	_test_eof436: cs = 436; goto _test_eof; 
	_test_eof437: cs = 437; goto _test_eof; 
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
	_test_eof463: cs = 463; goto _test_eof; 
	_test_eof464: cs = 464; goto _test_eof; 
	_test_eof465: cs = 465; goto _test_eof; 
	_test_eof466: cs = 466; goto _test_eof; 
	_test_eof467: cs = 467; goto _test_eof; 
	_test_eof468: cs = 468; goto _test_eof; 
	_test_eof469: cs = 469; goto _test_eof; 
	_test_eof470: cs = 470; goto _test_eof; 
	_test_eof471: cs = 471; goto _test_eof; 
	_test_eof472: cs = 472; goto _test_eof; 
	_test_eof473: cs = 473; goto _test_eof; 
	_test_eof474: cs = 474; goto _test_eof; 
	_test_eof475: cs = 475; goto _test_eof; 
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
	_test_eof508: cs = 508; goto _test_eof; 
	_test_eof509: cs = 509; goto _test_eof; 
	_test_eof510: cs = 510; goto _test_eof; 
	_test_eof511: cs = 511; goto _test_eof; 
	_test_eof512: cs = 512; goto _test_eof; 
	_test_eof513: cs = 513; goto _test_eof; 
	_test_eof514: cs = 514; goto _test_eof; 
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
	_test_eof584: cs = 584; goto _test_eof; 
	_test_eof585: cs = 585; goto _test_eof; 
	_test_eof586: cs = 586; goto _test_eof; 
	_test_eof587: cs = 587; goto _test_eof; 
	_test_eof588: cs = 588; goto _test_eof; 
	_test_eof589: cs = 589; goto _test_eof; 
	_test_eof590: cs = 590; goto _test_eof; 
	_test_eof591: cs = 591; goto _test_eof; 
	_test_eof592: cs = 592; goto _test_eof; 
	_test_eof593: cs = 593; goto _test_eof; 
	_test_eof594: cs = 594; goto _test_eof; 
	_test_eof595: cs = 595; goto _test_eof; 
	_test_eof596: cs = 596; goto _test_eof; 
	_test_eof597: cs = 597; goto _test_eof; 
	_test_eof598: cs = 598; goto _test_eof; 
	_test_eof599: cs = 599; goto _test_eof; 
	_test_eof600: cs = 600; goto _test_eof; 
	_test_eof601: cs = 601; goto _test_eof; 
	_test_eof602: cs = 602; goto _test_eof; 
	_test_eof603: cs = 603; goto _test_eof; 
	_test_eof604: cs = 604; goto _test_eof; 
	_test_eof605: cs = 605; goto _test_eof; 
	_test_eof606: cs = 606; goto _test_eof; 
	_test_eof607: cs = 607; goto _test_eof; 
	_test_eof608: cs = 608; goto _test_eof; 
	_test_eof609: cs = 609; goto _test_eof; 
	_test_eof610: cs = 610; goto _test_eof; 
	_test_eof611: cs = 611; goto _test_eof; 
	_test_eof612: cs = 612; goto _test_eof; 
	_test_eof613: cs = 613; goto _test_eof; 
	_test_eof614: cs = 614; goto _test_eof; 
	_test_eof615: cs = 615; goto _test_eof; 
	_test_eof616: cs = 616; goto _test_eof; 
	_test_eof617: cs = 617; goto _test_eof; 
	_test_eof618: cs = 618; goto _test_eof; 
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
	_test_eof634: cs = 634; goto _test_eof; 
	_test_eof635: cs = 635; goto _test_eof; 
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
	_test_eof700: cs = 700; goto _test_eof; 
	_test_eof701: cs = 701; goto _test_eof; 
	_test_eof702: cs = 702; goto _test_eof; 
	_test_eof703: cs = 703; goto _test_eof; 
	_test_eof704: cs = 704; goto _test_eof; 
	_test_eof705: cs = 705; goto _test_eof; 
	_test_eof706: cs = 706; goto _test_eof; 
	_test_eof707: cs = 707; goto _test_eof; 
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
	_test_eof720: cs = 720; goto _test_eof; 
	_test_eof721: cs = 721; goto _test_eof; 
	_test_eof722: cs = 722; goto _test_eof; 
	_test_eof723: cs = 723; goto _test_eof; 
	_test_eof724: cs = 724; goto _test_eof; 
	_test_eof725: cs = 725; goto _test_eof; 
	_test_eof726: cs = 726; goto _test_eof; 
	_test_eof727: cs = 727; goto _test_eof; 
	_test_eof728: cs = 728; goto _test_eof; 
	_test_eof729: cs = 729; goto _test_eof; 
	_test_eof730: cs = 730; goto _test_eof; 
	_test_eof731: cs = 731; goto _test_eof; 
	_test_eof732: cs = 732; goto _test_eof; 
	_test_eof733: cs = 733; goto _test_eof; 
	_test_eof734: cs = 734; goto _test_eof; 
	_test_eof735: cs = 735; goto _test_eof; 
	_test_eof736: cs = 736; goto _test_eof; 
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
	_test_eof749: cs = 749; goto _test_eof; 
	_test_eof750: cs = 750; goto _test_eof; 
	_test_eof751: cs = 751; goto _test_eof; 
	_test_eof752: cs = 752; goto _test_eof; 
	_test_eof753: cs = 753; goto _test_eof; 
	_test_eof754: cs = 754; goto _test_eof; 
	_test_eof755: cs = 755; goto _test_eof; 
	_test_eof756: cs = 756; goto _test_eof; 
	_test_eof757: cs = 757; goto _test_eof; 
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
	_test_eof770: cs = 770; goto _test_eof; 
	_test_eof771: cs = 771; goto _test_eof; 
	_test_eof772: cs = 772; goto _test_eof; 
	_test_eof773: cs = 773; goto _test_eof; 
	_test_eof774: cs = 774; goto _test_eof; 
	_test_eof775: cs = 775; goto _test_eof; 
	_test_eof776: cs = 776; goto _test_eof; 
	_test_eof786: cs = 786; goto _test_eof; 
	_test_eof787: cs = 787; goto _test_eof; 
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
	_test_eof1662: cs = 1662; goto _test_eof; 
	_test_eof1663: cs = 1663; goto _test_eof; 
	_test_eof801: cs = 801; goto _test_eof; 
	_test_eof802: cs = 802; goto _test_eof; 
	_test_eof803: cs = 803; goto _test_eof; 
	_test_eof804: cs = 804; goto _test_eof; 
	_test_eof805: cs = 805; goto _test_eof; 
	_test_eof806: cs = 806; goto _test_eof; 
	_test_eof807: cs = 807; goto _test_eof; 
	_test_eof808: cs = 808; goto _test_eof; 
	_test_eof809: cs = 809; goto _test_eof; 
	_test_eof810: cs = 810; goto _test_eof; 
	_test_eof811: cs = 811; goto _test_eof; 
	_test_eof812: cs = 812; goto _test_eof; 
	_test_eof813: cs = 813; goto _test_eof; 
	_test_eof814: cs = 814; goto _test_eof; 
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
	_test_eof1664: cs = 1664; goto _test_eof; 
	_test_eof1665: cs = 1665; goto _test_eof; 
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
	_test_eof879: cs = 879; goto _test_eof; 
	_test_eof880: cs = 880; goto _test_eof; 
	_test_eof881: cs = 881; goto _test_eof; 
	_test_eof882: cs = 882; goto _test_eof; 
	_test_eof883: cs = 883; goto _test_eof; 
	_test_eof884: cs = 884; goto _test_eof; 
	_test_eof885: cs = 885; goto _test_eof; 
	_test_eof886: cs = 886; goto _test_eof; 
	_test_eof887: cs = 887; goto _test_eof; 
	_test_eof888: cs = 888; goto _test_eof; 
	_test_eof889: cs = 889; goto _test_eof; 
	_test_eof890: cs = 890; goto _test_eof; 
	_test_eof891: cs = 891; goto _test_eof; 
	_test_eof892: cs = 892; goto _test_eof; 
	_test_eof893: cs = 893; goto _test_eof; 
	_test_eof894: cs = 894; goto _test_eof; 
	_test_eof895: cs = 895; goto _test_eof; 
	_test_eof896: cs = 896; goto _test_eof; 
	_test_eof897: cs = 897; goto _test_eof; 
	_test_eof898: cs = 898; goto _test_eof; 
	_test_eof899: cs = 899; goto _test_eof; 
	_test_eof900: cs = 900; goto _test_eof; 
	_test_eof901: cs = 901; goto _test_eof; 
	_test_eof902: cs = 902; goto _test_eof; 
	_test_eof903: cs = 903; goto _test_eof; 
	_test_eof904: cs = 904; goto _test_eof; 
	_test_eof905: cs = 905; goto _test_eof; 
	_test_eof906: cs = 906; goto _test_eof; 
	_test_eof907: cs = 907; goto _test_eof; 
	_test_eof908: cs = 908; goto _test_eof; 
	_test_eof909: cs = 909; goto _test_eof; 
	_test_eof910: cs = 910; goto _test_eof; 
	_test_eof911: cs = 911; goto _test_eof; 
	_test_eof912: cs = 912; goto _test_eof; 
	_test_eof913: cs = 913; goto _test_eof; 
	_test_eof914: cs = 914; goto _test_eof; 
	_test_eof915: cs = 915; goto _test_eof; 
	_test_eof916: cs = 916; goto _test_eof; 
	_test_eof917: cs = 917; goto _test_eof; 
	_test_eof918: cs = 918; goto _test_eof; 
	_test_eof919: cs = 919; goto _test_eof; 
	_test_eof920: cs = 920; goto _test_eof; 
	_test_eof921: cs = 921; goto _test_eof; 
	_test_eof922: cs = 922; goto _test_eof; 
	_test_eof923: cs = 923; goto _test_eof; 
	_test_eof924: cs = 924; goto _test_eof; 
	_test_eof925: cs = 925; goto _test_eof; 
	_test_eof926: cs = 926; goto _test_eof; 
	_test_eof927: cs = 927; goto _test_eof; 
	_test_eof928: cs = 928; goto _test_eof; 
	_test_eof929: cs = 929; goto _test_eof; 
	_test_eof930: cs = 930; goto _test_eof; 
	_test_eof931: cs = 931; goto _test_eof; 
	_test_eof1666: cs = 1666; goto _test_eof; 
	_test_eof1667: cs = 1667; goto _test_eof; 
	_test_eof932: cs = 932; goto _test_eof; 
	_test_eof933: cs = 933; goto _test_eof; 
	_test_eof934: cs = 934; goto _test_eof; 
	_test_eof935: cs = 935; goto _test_eof; 
	_test_eof936: cs = 936; goto _test_eof; 
	_test_eof937: cs = 937; goto _test_eof; 
	_test_eof938: cs = 938; goto _test_eof; 
	_test_eof939: cs = 939; goto _test_eof; 
	_test_eof940: cs = 940; goto _test_eof; 
	_test_eof941: cs = 941; goto _test_eof; 
	_test_eof942: cs = 942; goto _test_eof; 
	_test_eof943: cs = 943; goto _test_eof; 
	_test_eof944: cs = 944; goto _test_eof; 
	_test_eof945: cs = 945; goto _test_eof; 
	_test_eof946: cs = 946; goto _test_eof; 
	_test_eof947: cs = 947; goto _test_eof; 
	_test_eof948: cs = 948; goto _test_eof; 
	_test_eof949: cs = 949; goto _test_eof; 
	_test_eof950: cs = 950; goto _test_eof; 
	_test_eof951: cs = 951; goto _test_eof; 
	_test_eof952: cs = 952; goto _test_eof; 
	_test_eof953: cs = 953; goto _test_eof; 
	_test_eof954: cs = 954; goto _test_eof; 
	_test_eof955: cs = 955; goto _test_eof; 
	_test_eof956: cs = 956; goto _test_eof; 
	_test_eof957: cs = 957; goto _test_eof; 
	_test_eof958: cs = 958; goto _test_eof; 
	_test_eof959: cs = 959; goto _test_eof; 
	_test_eof960: cs = 960; goto _test_eof; 
	_test_eof961: cs = 961; goto _test_eof; 
	_test_eof962: cs = 962; goto _test_eof; 
	_test_eof963: cs = 963; goto _test_eof; 
	_test_eof964: cs = 964; goto _test_eof; 
	_test_eof965: cs = 965; goto _test_eof; 
	_test_eof966: cs = 966; goto _test_eof; 
	_test_eof967: cs = 967; goto _test_eof; 
	_test_eof968: cs = 968; goto _test_eof; 
	_test_eof969: cs = 969; goto _test_eof; 
	_test_eof970: cs = 970; goto _test_eof; 
	_test_eof971: cs = 971; goto _test_eof; 
	_test_eof972: cs = 972; goto _test_eof; 
	_test_eof973: cs = 973; goto _test_eof; 
	_test_eof974: cs = 974; goto _test_eof; 
	_test_eof975: cs = 975; goto _test_eof; 
	_test_eof976: cs = 976; goto _test_eof; 
	_test_eof977: cs = 977; goto _test_eof; 
	_test_eof978: cs = 978; goto _test_eof; 
	_test_eof979: cs = 979; goto _test_eof; 
	_test_eof980: cs = 980; goto _test_eof; 
	_test_eof981: cs = 981; goto _test_eof; 
	_test_eof982: cs = 982; goto _test_eof; 
	_test_eof983: cs = 983; goto _test_eof; 
	_test_eof984: cs = 984; goto _test_eof; 
	_test_eof985: cs = 985; goto _test_eof; 
	_test_eof986: cs = 986; goto _test_eof; 
	_test_eof987: cs = 987; goto _test_eof; 
	_test_eof988: cs = 988; goto _test_eof; 
	_test_eof989: cs = 989; goto _test_eof; 
	_test_eof990: cs = 990; goto _test_eof; 
	_test_eof991: cs = 991; goto _test_eof; 
	_test_eof992: cs = 992; goto _test_eof; 
	_test_eof993: cs = 993; goto _test_eof; 
	_test_eof994: cs = 994; goto _test_eof; 
	_test_eof995: cs = 995; goto _test_eof; 
	_test_eof996: cs = 996; goto _test_eof; 
	_test_eof997: cs = 997; goto _test_eof; 
	_test_eof998: cs = 998; goto _test_eof; 
	_test_eof999: cs = 999; goto _test_eof; 
	_test_eof1000: cs = 1000; goto _test_eof; 
	_test_eof1001: cs = 1001; goto _test_eof; 
	_test_eof1002: cs = 1002; goto _test_eof; 
	_test_eof1003: cs = 1003; goto _test_eof; 
	_test_eof1004: cs = 1004; goto _test_eof; 
	_test_eof1005: cs = 1005; goto _test_eof; 
	_test_eof1006: cs = 1006; goto _test_eof; 
	_test_eof1007: cs = 1007; goto _test_eof; 
	_test_eof1008: cs = 1008; goto _test_eof; 
	_test_eof1009: cs = 1009; goto _test_eof; 
	_test_eof1010: cs = 1010; goto _test_eof; 
	_test_eof1011: cs = 1011; goto _test_eof; 
	_test_eof1012: cs = 1012; goto _test_eof; 
	_test_eof1013: cs = 1013; goto _test_eof; 
	_test_eof1014: cs = 1014; goto _test_eof; 
	_test_eof1015: cs = 1015; goto _test_eof; 
	_test_eof1016: cs = 1016; goto _test_eof; 
	_test_eof1017: cs = 1017; goto _test_eof; 
	_test_eof1018: cs = 1018; goto _test_eof; 
	_test_eof1019: cs = 1019; goto _test_eof; 
	_test_eof1020: cs = 1020; goto _test_eof; 
	_test_eof1021: cs = 1021; goto _test_eof; 
	_test_eof1022: cs = 1022; goto _test_eof; 
	_test_eof1023: cs = 1023; goto _test_eof; 
	_test_eof1024: cs = 1024; goto _test_eof; 
	_test_eof1025: cs = 1025; goto _test_eof; 
	_test_eof1026: cs = 1026; goto _test_eof; 
	_test_eof1027: cs = 1027; goto _test_eof; 
	_test_eof1028: cs = 1028; goto _test_eof; 
	_test_eof1029: cs = 1029; goto _test_eof; 
	_test_eof1030: cs = 1030; goto _test_eof; 
	_test_eof1031: cs = 1031; goto _test_eof; 
	_test_eof1032: cs = 1032; goto _test_eof; 
	_test_eof1033: cs = 1033; goto _test_eof; 
	_test_eof1034: cs = 1034; goto _test_eof; 
	_test_eof1035: cs = 1035; goto _test_eof; 
	_test_eof1036: cs = 1036; goto _test_eof; 
	_test_eof1037: cs = 1037; goto _test_eof; 
	_test_eof1038: cs = 1038; goto _test_eof; 
	_test_eof1039: cs = 1039; goto _test_eof; 
	_test_eof1040: cs = 1040; goto _test_eof; 
	_test_eof1041: cs = 1041; goto _test_eof; 
	_test_eof1042: cs = 1042; goto _test_eof; 
	_test_eof1043: cs = 1043; goto _test_eof; 
	_test_eof1044: cs = 1044; goto _test_eof; 
	_test_eof1045: cs = 1045; goto _test_eof; 
	_test_eof1046: cs = 1046; goto _test_eof; 
	_test_eof1047: cs = 1047; goto _test_eof; 
	_test_eof1048: cs = 1048; goto _test_eof; 
	_test_eof1049: cs = 1049; goto _test_eof; 
	_test_eof1050: cs = 1050; goto _test_eof; 
	_test_eof1051: cs = 1051; goto _test_eof; 
	_test_eof1052: cs = 1052; goto _test_eof; 
	_test_eof1053: cs = 1053; goto _test_eof; 
	_test_eof1054: cs = 1054; goto _test_eof; 
	_test_eof1055: cs = 1055; goto _test_eof; 
	_test_eof1056: cs = 1056; goto _test_eof; 
	_test_eof1057: cs = 1057; goto _test_eof; 
	_test_eof1058: cs = 1058; goto _test_eof; 
	_test_eof1059: cs = 1059; goto _test_eof; 
	_test_eof1060: cs = 1060; goto _test_eof; 
	_test_eof1061: cs = 1061; goto _test_eof; 
	_test_eof1062: cs = 1062; goto _test_eof; 
	_test_eof1063: cs = 1063; goto _test_eof; 
	_test_eof1064: cs = 1064; goto _test_eof; 
	_test_eof1065: cs = 1065; goto _test_eof; 
	_test_eof1066: cs = 1066; goto _test_eof; 
	_test_eof1067: cs = 1067; goto _test_eof; 
	_test_eof1068: cs = 1068; goto _test_eof; 
	_test_eof1069: cs = 1069; goto _test_eof; 
	_test_eof1070: cs = 1070; goto _test_eof; 
	_test_eof1071: cs = 1071; goto _test_eof; 
	_test_eof1072: cs = 1072; goto _test_eof; 
	_test_eof1073: cs = 1073; goto _test_eof; 
	_test_eof1074: cs = 1074; goto _test_eof; 
	_test_eof1075: cs = 1075; goto _test_eof; 
	_test_eof1076: cs = 1076; goto _test_eof; 
	_test_eof1077: cs = 1077; goto _test_eof; 
	_test_eof1078: cs = 1078; goto _test_eof; 
	_test_eof1079: cs = 1079; goto _test_eof; 
	_test_eof1080: cs = 1080; goto _test_eof; 
	_test_eof1081: cs = 1081; goto _test_eof; 
	_test_eof1082: cs = 1082; goto _test_eof; 
	_test_eof1083: cs = 1083; goto _test_eof; 
	_test_eof1084: cs = 1084; goto _test_eof; 
	_test_eof1085: cs = 1085; goto _test_eof; 
	_test_eof1086: cs = 1086; goto _test_eof; 
	_test_eof1087: cs = 1087; goto _test_eof; 
	_test_eof1088: cs = 1088; goto _test_eof; 
	_test_eof1089: cs = 1089; goto _test_eof; 
	_test_eof1090: cs = 1090; goto _test_eof; 
	_test_eof1091: cs = 1091; goto _test_eof; 
	_test_eof1092: cs = 1092; goto _test_eof; 
	_test_eof1093: cs = 1093; goto _test_eof; 
	_test_eof1094: cs = 1094; goto _test_eof; 
	_test_eof1095: cs = 1095; goto _test_eof; 
	_test_eof1096: cs = 1096; goto _test_eof; 
	_test_eof1097: cs = 1097; goto _test_eof; 
	_test_eof1098: cs = 1098; goto _test_eof; 
	_test_eof1099: cs = 1099; goto _test_eof; 
	_test_eof1100: cs = 1100; goto _test_eof; 
	_test_eof1101: cs = 1101; goto _test_eof; 
	_test_eof1102: cs = 1102; goto _test_eof; 
	_test_eof1103: cs = 1103; goto _test_eof; 
	_test_eof1104: cs = 1104; goto _test_eof; 
	_test_eof1105: cs = 1105; goto _test_eof; 
	_test_eof1106: cs = 1106; goto _test_eof; 
	_test_eof1107: cs = 1107; goto _test_eof; 
	_test_eof1108: cs = 1108; goto _test_eof; 
	_test_eof1109: cs = 1109; goto _test_eof; 
	_test_eof1110: cs = 1110; goto _test_eof; 
	_test_eof1111: cs = 1111; goto _test_eof; 
	_test_eof1112: cs = 1112; goto _test_eof; 
	_test_eof1113: cs = 1113; goto _test_eof; 
	_test_eof1114: cs = 1114; goto _test_eof; 
	_test_eof1115: cs = 1115; goto _test_eof; 
	_test_eof1116: cs = 1116; goto _test_eof; 
	_test_eof1117: cs = 1117; goto _test_eof; 
	_test_eof1118: cs = 1118; goto _test_eof; 
	_test_eof1119: cs = 1119; goto _test_eof; 
	_test_eof1120: cs = 1120; goto _test_eof; 
	_test_eof1121: cs = 1121; goto _test_eof; 
	_test_eof1122: cs = 1122; goto _test_eof; 
	_test_eof1123: cs = 1123; goto _test_eof; 
	_test_eof1124: cs = 1124; goto _test_eof; 
	_test_eof1125: cs = 1125; goto _test_eof; 
	_test_eof1126: cs = 1126; goto _test_eof; 
	_test_eof1127: cs = 1127; goto _test_eof; 
	_test_eof1128: cs = 1128; goto _test_eof; 
	_test_eof1129: cs = 1129; goto _test_eof; 
	_test_eof1130: cs = 1130; goto _test_eof; 
	_test_eof1131: cs = 1131; goto _test_eof; 
	_test_eof1132: cs = 1132; goto _test_eof; 
	_test_eof1133: cs = 1133; goto _test_eof; 
	_test_eof1134: cs = 1134; goto _test_eof; 
	_test_eof1135: cs = 1135; goto _test_eof; 
	_test_eof1136: cs = 1136; goto _test_eof; 
	_test_eof1137: cs = 1137; goto _test_eof; 
	_test_eof1138: cs = 1138; goto _test_eof; 
	_test_eof1139: cs = 1139; goto _test_eof; 
	_test_eof1140: cs = 1140; goto _test_eof; 
	_test_eof1141: cs = 1141; goto _test_eof; 
	_test_eof1142: cs = 1142; goto _test_eof; 
	_test_eof1143: cs = 1143; goto _test_eof; 
	_test_eof1144: cs = 1144; goto _test_eof; 
	_test_eof1145: cs = 1145; goto _test_eof; 
	_test_eof1146: cs = 1146; goto _test_eof; 
	_test_eof1147: cs = 1147; goto _test_eof; 
	_test_eof1148: cs = 1148; goto _test_eof; 
	_test_eof1149: cs = 1149; goto _test_eof; 
	_test_eof1150: cs = 1150; goto _test_eof; 
	_test_eof1151: cs = 1151; goto _test_eof; 
	_test_eof1152: cs = 1152; goto _test_eof; 
	_test_eof1153: cs = 1153; goto _test_eof; 
	_test_eof1154: cs = 1154; goto _test_eof; 
	_test_eof1155: cs = 1155; goto _test_eof; 
	_test_eof1156: cs = 1156; goto _test_eof; 
	_test_eof1157: cs = 1157; goto _test_eof; 
	_test_eof1158: cs = 1158; goto _test_eof; 
	_test_eof1159: cs = 1159; goto _test_eof; 
	_test_eof1160: cs = 1160; goto _test_eof; 
	_test_eof1161: cs = 1161; goto _test_eof; 
	_test_eof1162: cs = 1162; goto _test_eof; 
	_test_eof1163: cs = 1163; goto _test_eof; 
	_test_eof1164: cs = 1164; goto _test_eof; 
	_test_eof1165: cs = 1165; goto _test_eof; 
	_test_eof1166: cs = 1166; goto _test_eof; 
	_test_eof1167: cs = 1167; goto _test_eof; 
	_test_eof1168: cs = 1168; goto _test_eof; 
	_test_eof1169: cs = 1169; goto _test_eof; 
	_test_eof1170: cs = 1170; goto _test_eof; 
	_test_eof1171: cs = 1171; goto _test_eof; 
	_test_eof1172: cs = 1172; goto _test_eof; 
	_test_eof1173: cs = 1173; goto _test_eof; 
	_test_eof1174: cs = 1174; goto _test_eof; 
	_test_eof1175: cs = 1175; goto _test_eof; 
	_test_eof1176: cs = 1176; goto _test_eof; 
	_test_eof1177: cs = 1177; goto _test_eof; 
	_test_eof1178: cs = 1178; goto _test_eof; 
	_test_eof1179: cs = 1179; goto _test_eof; 
	_test_eof1180: cs = 1180; goto _test_eof; 
	_test_eof1181: cs = 1181; goto _test_eof; 
	_test_eof1182: cs = 1182; goto _test_eof; 
	_test_eof1183: cs = 1183; goto _test_eof; 
	_test_eof1184: cs = 1184; goto _test_eof; 
	_test_eof1185: cs = 1185; goto _test_eof; 
	_test_eof1186: cs = 1186; goto _test_eof; 
	_test_eof1187: cs = 1187; goto _test_eof; 
	_test_eof1188: cs = 1188; goto _test_eof; 
	_test_eof1189: cs = 1189; goto _test_eof; 
	_test_eof1190: cs = 1190; goto _test_eof; 
	_test_eof1191: cs = 1191; goto _test_eof; 
	_test_eof1192: cs = 1192; goto _test_eof; 
	_test_eof1193: cs = 1193; goto _test_eof; 
	_test_eof1194: cs = 1194; goto _test_eof; 
	_test_eof1195: cs = 1195; goto _test_eof; 
	_test_eof1196: cs = 1196; goto _test_eof; 
	_test_eof1197: cs = 1197; goto _test_eof; 
	_test_eof1198: cs = 1198; goto _test_eof; 
	_test_eof1199: cs = 1199; goto _test_eof; 
	_test_eof1200: cs = 1200; goto _test_eof; 
	_test_eof1201: cs = 1201; goto _test_eof; 
	_test_eof1202: cs = 1202; goto _test_eof; 
	_test_eof1203: cs = 1203; goto _test_eof; 
	_test_eof1204: cs = 1204; goto _test_eof; 
	_test_eof1205: cs = 1205; goto _test_eof; 
	_test_eof1206: cs = 1206; goto _test_eof; 
	_test_eof1207: cs = 1207; goto _test_eof; 
	_test_eof1208: cs = 1208; goto _test_eof; 
	_test_eof1209: cs = 1209; goto _test_eof; 
	_test_eof1210: cs = 1210; goto _test_eof; 
	_test_eof1211: cs = 1211; goto _test_eof; 
	_test_eof1212: cs = 1212; goto _test_eof; 
	_test_eof1213: cs = 1213; goto _test_eof; 
	_test_eof1214: cs = 1214; goto _test_eof; 
	_test_eof1215: cs = 1215; goto _test_eof; 
	_test_eof1216: cs = 1216; goto _test_eof; 
	_test_eof1217: cs = 1217; goto _test_eof; 
	_test_eof1218: cs = 1218; goto _test_eof; 
	_test_eof1219: cs = 1219; goto _test_eof; 
	_test_eof1220: cs = 1220; goto _test_eof; 
	_test_eof1221: cs = 1221; goto _test_eof; 
	_test_eof1222: cs = 1222; goto _test_eof; 
	_test_eof1223: cs = 1223; goto _test_eof; 
	_test_eof1224: cs = 1224; goto _test_eof; 
	_test_eof1225: cs = 1225; goto _test_eof; 
	_test_eof1226: cs = 1226; goto _test_eof; 
	_test_eof1227: cs = 1227; goto _test_eof; 
	_test_eof1228: cs = 1228; goto _test_eof; 
	_test_eof1229: cs = 1229; goto _test_eof; 
	_test_eof1230: cs = 1230; goto _test_eof; 
	_test_eof1231: cs = 1231; goto _test_eof; 
	_test_eof1232: cs = 1232; goto _test_eof; 
	_test_eof1233: cs = 1233; goto _test_eof; 
	_test_eof1234: cs = 1234; goto _test_eof; 
	_test_eof1235: cs = 1235; goto _test_eof; 
	_test_eof1236: cs = 1236; goto _test_eof; 
	_test_eof1237: cs = 1237; goto _test_eof; 
	_test_eof1238: cs = 1238; goto _test_eof; 
	_test_eof1239: cs = 1239; goto _test_eof; 
	_test_eof1240: cs = 1240; goto _test_eof; 
	_test_eof1241: cs = 1241; goto _test_eof; 
	_test_eof1242: cs = 1242; goto _test_eof; 
	_test_eof1243: cs = 1243; goto _test_eof; 
	_test_eof1244: cs = 1244; goto _test_eof; 
	_test_eof1245: cs = 1245; goto _test_eof; 
	_test_eof1246: cs = 1246; goto _test_eof; 
	_test_eof1247: cs = 1247; goto _test_eof; 
	_test_eof1248: cs = 1248; goto _test_eof; 
	_test_eof1249: cs = 1249; goto _test_eof; 
	_test_eof1250: cs = 1250; goto _test_eof; 
	_test_eof1251: cs = 1251; goto _test_eof; 
	_test_eof1252: cs = 1252; goto _test_eof; 
	_test_eof1253: cs = 1253; goto _test_eof; 
	_test_eof1254: cs = 1254; goto _test_eof; 
	_test_eof1255: cs = 1255; goto _test_eof; 
	_test_eof1256: cs = 1256; goto _test_eof; 
	_test_eof1257: cs = 1257; goto _test_eof; 
	_test_eof1258: cs = 1258; goto _test_eof; 
	_test_eof1259: cs = 1259; goto _test_eof; 
	_test_eof1260: cs = 1260; goto _test_eof; 
	_test_eof1261: cs = 1261; goto _test_eof; 
	_test_eof1262: cs = 1262; goto _test_eof; 
	_test_eof1263: cs = 1263; goto _test_eof; 
	_test_eof1264: cs = 1264; goto _test_eof; 
	_test_eof1265: cs = 1265; goto _test_eof; 
	_test_eof1266: cs = 1266; goto _test_eof; 
	_test_eof1267: cs = 1267; goto _test_eof; 
	_test_eof1268: cs = 1268; goto _test_eof; 
	_test_eof1269: cs = 1269; goto _test_eof; 
	_test_eof1270: cs = 1270; goto _test_eof; 
	_test_eof1271: cs = 1271; goto _test_eof; 
	_test_eof1272: cs = 1272; goto _test_eof; 
	_test_eof1273: cs = 1273; goto _test_eof; 
	_test_eof1274: cs = 1274; goto _test_eof; 
	_test_eof1275: cs = 1275; goto _test_eof; 
	_test_eof1276: cs = 1276; goto _test_eof; 
	_test_eof1277: cs = 1277; goto _test_eof; 
	_test_eof1278: cs = 1278; goto _test_eof; 
	_test_eof1279: cs = 1279; goto _test_eof; 
	_test_eof1280: cs = 1280; goto _test_eof; 
	_test_eof1281: cs = 1281; goto _test_eof; 
	_test_eof1282: cs = 1282; goto _test_eof; 
	_test_eof1283: cs = 1283; goto _test_eof; 
	_test_eof1284: cs = 1284; goto _test_eof; 
	_test_eof1285: cs = 1285; goto _test_eof; 
	_test_eof1286: cs = 1286; goto _test_eof; 
	_test_eof1287: cs = 1287; goto _test_eof; 
	_test_eof1288: cs = 1288; goto _test_eof; 
	_test_eof1289: cs = 1289; goto _test_eof; 
	_test_eof1290: cs = 1290; goto _test_eof; 
	_test_eof1291: cs = 1291; goto _test_eof; 
	_test_eof1292: cs = 1292; goto _test_eof; 
	_test_eof1293: cs = 1293; goto _test_eof; 
	_test_eof1294: cs = 1294; goto _test_eof; 
	_test_eof1295: cs = 1295; goto _test_eof; 
	_test_eof1296: cs = 1296; goto _test_eof; 
	_test_eof1297: cs = 1297; goto _test_eof; 
	_test_eof1298: cs = 1298; goto _test_eof; 
	_test_eof1299: cs = 1299; goto _test_eof; 
	_test_eof1300: cs = 1300; goto _test_eof; 
	_test_eof1301: cs = 1301; goto _test_eof; 
	_test_eof1302: cs = 1302; goto _test_eof; 
	_test_eof1303: cs = 1303; goto _test_eof; 
	_test_eof1304: cs = 1304; goto _test_eof; 
	_test_eof1305: cs = 1305; goto _test_eof; 
	_test_eof1306: cs = 1306; goto _test_eof; 
	_test_eof1307: cs = 1307; goto _test_eof; 
	_test_eof1308: cs = 1308; goto _test_eof; 
	_test_eof1309: cs = 1309; goto _test_eof; 
	_test_eof1310: cs = 1310; goto _test_eof; 
	_test_eof1311: cs = 1311; goto _test_eof; 
	_test_eof1312: cs = 1312; goto _test_eof; 
	_test_eof1313: cs = 1313; goto _test_eof; 
	_test_eof1314: cs = 1314; goto _test_eof; 
	_test_eof1315: cs = 1315; goto _test_eof; 
	_test_eof1316: cs = 1316; goto _test_eof; 
	_test_eof1317: cs = 1317; goto _test_eof; 
	_test_eof1318: cs = 1318; goto _test_eof; 
	_test_eof1319: cs = 1319; goto _test_eof; 
	_test_eof1320: cs = 1320; goto _test_eof; 
	_test_eof1321: cs = 1321; goto _test_eof; 
	_test_eof1322: cs = 1322; goto _test_eof; 
	_test_eof1323: cs = 1323; goto _test_eof; 
	_test_eof1324: cs = 1324; goto _test_eof; 
	_test_eof1325: cs = 1325; goto _test_eof; 
	_test_eof1326: cs = 1326; goto _test_eof; 
	_test_eof1327: cs = 1327; goto _test_eof; 
	_test_eof1328: cs = 1328; goto _test_eof; 
	_test_eof1329: cs = 1329; goto _test_eof; 
	_test_eof1330: cs = 1330; goto _test_eof; 
	_test_eof1331: cs = 1331; goto _test_eof; 
	_test_eof1332: cs = 1332; goto _test_eof; 
	_test_eof1333: cs = 1333; goto _test_eof; 
	_test_eof1334: cs = 1334; goto _test_eof; 
	_test_eof1335: cs = 1335; goto _test_eof; 
	_test_eof1336: cs = 1336; goto _test_eof; 
	_test_eof1337: cs = 1337; goto _test_eof; 
	_test_eof1338: cs = 1338; goto _test_eof; 
	_test_eof1339: cs = 1339; goto _test_eof; 
	_test_eof1340: cs = 1340; goto _test_eof; 
	_test_eof1341: cs = 1341; goto _test_eof; 
	_test_eof1342: cs = 1342; goto _test_eof; 
	_test_eof1343: cs = 1343; goto _test_eof; 
	_test_eof1344: cs = 1344; goto _test_eof; 
	_test_eof1345: cs = 1345; goto _test_eof; 
	_test_eof1346: cs = 1346; goto _test_eof; 
	_test_eof1347: cs = 1347; goto _test_eof; 
	_test_eof1348: cs = 1348; goto _test_eof; 
	_test_eof1349: cs = 1349; goto _test_eof; 
	_test_eof1350: cs = 1350; goto _test_eof; 
	_test_eof1351: cs = 1351; goto _test_eof; 
	_test_eof1352: cs = 1352; goto _test_eof; 
	_test_eof1353: cs = 1353; goto _test_eof; 
	_test_eof1354: cs = 1354; goto _test_eof; 
	_test_eof1355: cs = 1355; goto _test_eof; 
	_test_eof1356: cs = 1356; goto _test_eof; 
	_test_eof1357: cs = 1357; goto _test_eof; 
	_test_eof1358: cs = 1358; goto _test_eof; 
	_test_eof1359: cs = 1359; goto _test_eof; 
	_test_eof1360: cs = 1360; goto _test_eof; 
	_test_eof1361: cs = 1361; goto _test_eof; 
	_test_eof1362: cs = 1362; goto _test_eof; 
	_test_eof1363: cs = 1363; goto _test_eof; 
	_test_eof1364: cs = 1364; goto _test_eof; 
	_test_eof1365: cs = 1365; goto _test_eof; 
	_test_eof1366: cs = 1366; goto _test_eof; 
	_test_eof1367: cs = 1367; goto _test_eof; 
	_test_eof1368: cs = 1368; goto _test_eof; 
	_test_eof1369: cs = 1369; goto _test_eof; 
	_test_eof1370: cs = 1370; goto _test_eof; 
	_test_eof1371: cs = 1371; goto _test_eof; 
	_test_eof1372: cs = 1372; goto _test_eof; 
	_test_eof1373: cs = 1373; goto _test_eof; 
	_test_eof1374: cs = 1374; goto _test_eof; 
	_test_eof1375: cs = 1375; goto _test_eof; 
	_test_eof1376: cs = 1376; goto _test_eof; 
	_test_eof1377: cs = 1377; goto _test_eof; 
	_test_eof1378: cs = 1378; goto _test_eof; 
	_test_eof1379: cs = 1379; goto _test_eof; 
	_test_eof1380: cs = 1380; goto _test_eof; 
	_test_eof1381: cs = 1381; goto _test_eof; 
	_test_eof1382: cs = 1382; goto _test_eof; 
	_test_eof1383: cs = 1383; goto _test_eof; 
	_test_eof1384: cs = 1384; goto _test_eof; 
	_test_eof1385: cs = 1385; goto _test_eof; 
	_test_eof1386: cs = 1386; goto _test_eof; 
	_test_eof1387: cs = 1387; goto _test_eof; 
	_test_eof1388: cs = 1388; goto _test_eof; 
	_test_eof1389: cs = 1389; goto _test_eof; 
	_test_eof1390: cs = 1390; goto _test_eof; 
	_test_eof1391: cs = 1391; goto _test_eof; 
	_test_eof1392: cs = 1392; goto _test_eof; 
	_test_eof1393: cs = 1393; goto _test_eof; 
	_test_eof1394: cs = 1394; goto _test_eof; 
	_test_eof1395: cs = 1395; goto _test_eof; 
	_test_eof1396: cs = 1396; goto _test_eof; 
	_test_eof1397: cs = 1397; goto _test_eof; 
	_test_eof1398: cs = 1398; goto _test_eof; 
	_test_eof1399: cs = 1399; goto _test_eof; 
	_test_eof1400: cs = 1400; goto _test_eof; 
	_test_eof1401: cs = 1401; goto _test_eof; 
	_test_eof1402: cs = 1402; goto _test_eof; 
	_test_eof1403: cs = 1403; goto _test_eof; 
	_test_eof1404: cs = 1404; goto _test_eof; 
	_test_eof1405: cs = 1405; goto _test_eof; 
	_test_eof1406: cs = 1406; goto _test_eof; 
	_test_eof1407: cs = 1407; goto _test_eof; 
	_test_eof1408: cs = 1408; goto _test_eof; 
	_test_eof1409: cs = 1409; goto _test_eof; 
	_test_eof1410: cs = 1410; goto _test_eof; 
	_test_eof1411: cs = 1411; goto _test_eof; 
	_test_eof1412: cs = 1412; goto _test_eof; 
	_test_eof1413: cs = 1413; goto _test_eof; 
	_test_eof1414: cs = 1414; goto _test_eof; 
	_test_eof1415: cs = 1415; goto _test_eof; 
	_test_eof1416: cs = 1416; goto _test_eof; 
	_test_eof1451: cs = 1451; goto _test_eof; 
	_test_eof1672: cs = 1672; goto _test_eof; 
	_test_eof1452: cs = 1452; goto _test_eof; 
	_test_eof1673: cs = 1673; goto _test_eof; 
	_test_eof1453: cs = 1453; goto _test_eof; 
	_test_eof1454: cs = 1454; goto _test_eof; 
	_test_eof1455: cs = 1455; goto _test_eof; 
	_test_eof1456: cs = 1456; goto _test_eof; 
	_test_eof1457: cs = 1457; goto _test_eof; 
	_test_eof1458: cs = 1458; goto _test_eof; 
	_test_eof1459: cs = 1459; goto _test_eof; 
	_test_eof1460: cs = 1460; goto _test_eof; 
	_test_eof1461: cs = 1461; goto _test_eof; 
	_test_eof1462: cs = 1462; goto _test_eof; 
	_test_eof1463: cs = 1463; goto _test_eof; 
	_test_eof1464: cs = 1464; goto _test_eof; 
	_test_eof1465: cs = 1465; goto _test_eof; 
	_test_eof1466: cs = 1466; goto _test_eof; 
	_test_eof1467: cs = 1467; goto _test_eof; 
	_test_eof1468: cs = 1468; goto _test_eof; 
	_test_eof1469: cs = 1469; goto _test_eof; 
	_test_eof1470: cs = 1470; goto _test_eof; 
	_test_eof1471: cs = 1471; goto _test_eof; 
	_test_eof1472: cs = 1472; goto _test_eof; 
	_test_eof1674: cs = 1674; goto _test_eof; 
	_test_eof1473: cs = 1473; goto _test_eof; 
	_test_eof1474: cs = 1474; goto _test_eof; 
	_test_eof1475: cs = 1475; goto _test_eof; 
	_test_eof1476: cs = 1476; goto _test_eof; 
	_test_eof1477: cs = 1477; goto _test_eof; 
	_test_eof1478: cs = 1478; goto _test_eof; 
	_test_eof1479: cs = 1479; goto _test_eof; 
	_test_eof1480: cs = 1480; goto _test_eof; 
	_test_eof1481: cs = 1481; goto _test_eof; 
	_test_eof1482: cs = 1482; goto _test_eof; 
	_test_eof1483: cs = 1483; goto _test_eof; 
	_test_eof1484: cs = 1484; goto _test_eof; 
	_test_eof1485: cs = 1485; goto _test_eof; 
	_test_eof1486: cs = 1486; goto _test_eof; 
	_test_eof1487: cs = 1487; goto _test_eof; 
	_test_eof1488: cs = 1488; goto _test_eof; 
	_test_eof1489: cs = 1489; goto _test_eof; 
	_test_eof1490: cs = 1490; goto _test_eof; 
	_test_eof1491: cs = 1491; goto _test_eof; 
	_test_eof1492: cs = 1492; goto _test_eof; 
	_test_eof1493: cs = 1493; goto _test_eof; 
	_test_eof1494: cs = 1494; goto _test_eof; 
	_test_eof1495: cs = 1495; goto _test_eof; 
	_test_eof1496: cs = 1496; goto _test_eof; 
	_test_eof1497: cs = 1497; goto _test_eof; 
	_test_eof1498: cs = 1498; goto _test_eof; 
	_test_eof1499: cs = 1499; goto _test_eof; 
	_test_eof1500: cs = 1500; goto _test_eof; 
	_test_eof1501: cs = 1501; goto _test_eof; 
	_test_eof1502: cs = 1502; goto _test_eof; 
	_test_eof1503: cs = 1503; goto _test_eof; 
	_test_eof1504: cs = 1504; goto _test_eof; 
	_test_eof1505: cs = 1505; goto _test_eof; 
	_test_eof1506: cs = 1506; goto _test_eof; 
	_test_eof1507: cs = 1507; goto _test_eof; 
	_test_eof1508: cs = 1508; goto _test_eof; 
	_test_eof1509: cs = 1509; goto _test_eof; 
	_test_eof1510: cs = 1510; goto _test_eof; 
	_test_eof1511: cs = 1511; goto _test_eof; 
	_test_eof1512: cs = 1512; goto _test_eof; 
	_test_eof1513: cs = 1513; goto _test_eof; 
	_test_eof1514: cs = 1514; goto _test_eof; 
	_test_eof1515: cs = 1515; goto _test_eof; 
	_test_eof1516: cs = 1516; goto _test_eof; 
	_test_eof1517: cs = 1517; goto _test_eof; 
	_test_eof1518: cs = 1518; goto _test_eof; 
	_test_eof1519: cs = 1519; goto _test_eof; 
	_test_eof1520: cs = 1520; goto _test_eof; 
	_test_eof1521: cs = 1521; goto _test_eof; 
	_test_eof1522: cs = 1522; goto _test_eof; 
	_test_eof1523: cs = 1523; goto _test_eof; 
	_test_eof1524: cs = 1524; goto _test_eof; 
	_test_eof1525: cs = 1525; goto _test_eof; 
	_test_eof1526: cs = 1526; goto _test_eof; 
	_test_eof1527: cs = 1527; goto _test_eof; 
	_test_eof1528: cs = 1528; goto _test_eof; 
	_test_eof1529: cs = 1529; goto _test_eof; 
	_test_eof1530: cs = 1530; goto _test_eof; 
	_test_eof1531: cs = 1531; goto _test_eof; 
	_test_eof1532: cs = 1532; goto _test_eof; 
	_test_eof1533: cs = 1533; goto _test_eof; 
	_test_eof1534: cs = 1534; goto _test_eof; 
	_test_eof1535: cs = 1535; goto _test_eof; 
	_test_eof1536: cs = 1536; goto _test_eof; 
	_test_eof1537: cs = 1537; goto _test_eof; 
	_test_eof1538: cs = 1538; goto _test_eof; 
	_test_eof1539: cs = 1539; goto _test_eof; 
	_test_eof1540: cs = 1540; goto _test_eof; 
	_test_eof1541: cs = 1541; goto _test_eof; 
	_test_eof1542: cs = 1542; goto _test_eof; 
	_test_eof1543: cs = 1543; goto _test_eof; 
	_test_eof1544: cs = 1544; goto _test_eof; 
	_test_eof1545: cs = 1545; goto _test_eof; 
	_test_eof1546: cs = 1546; goto _test_eof; 
	_test_eof1547: cs = 1547; goto _test_eof; 
	_test_eof1548: cs = 1548; goto _test_eof; 
	_test_eof1549: cs = 1549; goto _test_eof; 
	_test_eof1550: cs = 1550; goto _test_eof; 
	_test_eof1551: cs = 1551; goto _test_eof; 
	_test_eof1552: cs = 1552; goto _test_eof; 
	_test_eof1553: cs = 1553; goto _test_eof; 
	_test_eof1554: cs = 1554; goto _test_eof; 
	_test_eof1555: cs = 1555; goto _test_eof; 
	_test_eof1556: cs = 1556; goto _test_eof; 
	_test_eof1557: cs = 1557; goto _test_eof; 
	_test_eof1558: cs = 1558; goto _test_eof; 
	_test_eof1559: cs = 1559; goto _test_eof; 
	_test_eof1560: cs = 1560; goto _test_eof; 
	_test_eof1561: cs = 1561; goto _test_eof; 
	_test_eof1562: cs = 1562; goto _test_eof; 
	_test_eof1563: cs = 1563; goto _test_eof; 
	_test_eof1564: cs = 1564; goto _test_eof; 
	_test_eof1565: cs = 1565; goto _test_eof; 
	_test_eof1566: cs = 1566; goto _test_eof; 
	_test_eof1567: cs = 1567; goto _test_eof; 
	_test_eof1568: cs = 1568; goto _test_eof; 
	_test_eof1675: cs = 1675; goto _test_eof; 
	_test_eof1569: cs = 1569; goto _test_eof; 
	_test_eof1570: cs = 1570; goto _test_eof; 
	_test_eof1571: cs = 1571; goto _test_eof; 
	_test_eof1572: cs = 1572; goto _test_eof; 
	_test_eof1573: cs = 1573; goto _test_eof; 
	_test_eof1574: cs = 1574; goto _test_eof; 
	_test_eof1575: cs = 1575; goto _test_eof; 
	_test_eof1576: cs = 1576; goto _test_eof; 
	_test_eof1577: cs = 1577; goto _test_eof; 
	_test_eof1578: cs = 1578; goto _test_eof; 
	_test_eof1579: cs = 1579; goto _test_eof; 
	_test_eof1580: cs = 1580; goto _test_eof; 
	_test_eof1581: cs = 1581; goto _test_eof; 
	_test_eof1582: cs = 1582; goto _test_eof; 
	_test_eof1583: cs = 1583; goto _test_eof; 
	_test_eof1584: cs = 1584; goto _test_eof; 
	_test_eof1585: cs = 1585; goto _test_eof; 
	_test_eof1586: cs = 1586; goto _test_eof; 
	_test_eof1587: cs = 1587; goto _test_eof; 
	_test_eof1588: cs = 1588; goto _test_eof; 
	_test_eof1589: cs = 1589; goto _test_eof; 
	_test_eof1590: cs = 1590; goto _test_eof; 
	_test_eof1591: cs = 1591; goto _test_eof; 
	_test_eof1592: cs = 1592; goto _test_eof; 
	_test_eof1593: cs = 1593; goto _test_eof; 
	_test_eof1594: cs = 1594; goto _test_eof; 
	_test_eof1595: cs = 1595; goto _test_eof; 
	_test_eof1596: cs = 1596; goto _test_eof; 
	_test_eof1597: cs = 1597; goto _test_eof; 
	_test_eof1598: cs = 1598; goto _test_eof; 
	_test_eof1599: cs = 1599; goto _test_eof; 
	_test_eof1600: cs = 1600; goto _test_eof; 
	_test_eof1601: cs = 1601; goto _test_eof; 
	_test_eof1602: cs = 1602; goto _test_eof; 
	_test_eof1603: cs = 1603; goto _test_eof; 
	_test_eof1604: cs = 1604; goto _test_eof; 
	_test_eof1605: cs = 1605; goto _test_eof; 
	_test_eof1606: cs = 1606; goto _test_eof; 
	_test_eof1607: cs = 1607; goto _test_eof; 
	_test_eof1609: cs = 1609; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof1610: cs = 1610; goto _test_eof; 
	_test_eof1611: cs = 1611; goto _test_eof; 
	_test_eof1612: cs = 1612; goto _test_eof; 
	_test_eof1613: cs = 1613; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof1614: cs = 1614; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof23: cs = 23; goto _test_eof; 
	_test_eof1615: cs = 1615; goto _test_eof; 
	_test_eof24: cs = 24; goto _test_eof; 
	_test_eof1616: cs = 1616; goto _test_eof; 
	_test_eof25: cs = 25; goto _test_eof; 
	_test_eof26: cs = 26; goto _test_eof; 
	_test_eof1617: cs = 1617; goto _test_eof; 
	_test_eof1618: cs = 1618; goto _test_eof; 
	_test_eof1619: cs = 1619; goto _test_eof; 
	_test_eof1620: cs = 1620; goto _test_eof; 
	_test_eof1621: cs = 1621; goto _test_eof; 
	_test_eof1622: cs = 1622; goto _test_eof; 
	_test_eof1623: cs = 1623; goto _test_eof; 
	_test_eof1624: cs = 1624; goto _test_eof; 
	_test_eof1625: cs = 1625; goto _test_eof; 
	_test_eof1626: cs = 1626; goto _test_eof; 
	_test_eof1627: cs = 1627; goto _test_eof; 
	_test_eof1628: cs = 1628; goto _test_eof; 
	_test_eof1629: cs = 1629; goto _test_eof; 
	_test_eof1630: cs = 1630; goto _test_eof; 
	_test_eof1631: cs = 1631; goto _test_eof; 
	_test_eof27: cs = 27; goto _test_eof; 
	_test_eof28: cs = 28; goto _test_eof; 
	_test_eof29: cs = 29; goto _test_eof; 
	_test_eof30: cs = 30; goto _test_eof; 
	_test_eof31: cs = 31; goto _test_eof; 
	_test_eof32: cs = 32; goto _test_eof; 
	_test_eof33: cs = 33; goto _test_eof; 
	_test_eof34: cs = 34; goto _test_eof; 
	_test_eof1632: cs = 1632; goto _test_eof; 
	_test_eof35: cs = 35; goto _test_eof; 
	_test_eof1633: cs = 1633; goto _test_eof; 
	_test_eof36: cs = 36; goto _test_eof; 
	_test_eof37: cs = 37; goto _test_eof; 
	_test_eof38: cs = 38; goto _test_eof; 
	_test_eof39: cs = 39; goto _test_eof; 
	_test_eof40: cs = 40; goto _test_eof; 
	_test_eof1634: cs = 1634; goto _test_eof; 
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
	_test_eof1635: cs = 1635; goto _test_eof; 
	_test_eof56: cs = 56; goto _test_eof; 
	_test_eof1636: cs = 1636; goto _test_eof; 
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
	_test_eof1637: cs = 1637; goto _test_eof; 
	_test_eof1638: cs = 1638; goto _test_eof; 
	_test_eof1639: cs = 1639; goto _test_eof; 
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
	_test_eof1640: cs = 1640; goto _test_eof; 
	_test_eof1641: cs = 1641; goto _test_eof; 
	_test_eof1642: cs = 1642; goto _test_eof; 
	_test_eof107: cs = 107; goto _test_eof; 
	_test_eof1643: cs = 1643; goto _test_eof; 
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
	_test_eof1644: cs = 1644; goto _test_eof; 
	_test_eof206: cs = 206; goto _test_eof; 
	_test_eof1645: cs = 1645; goto _test_eof; 
	_test_eof1646: cs = 1646; goto _test_eof; 
	_test_eof1647: cs = 1647; goto _test_eof; 
	_test_eof207: cs = 207; goto _test_eof; 
	_test_eof208: cs = 208; goto _test_eof; 
	_test_eof209: cs = 209; goto _test_eof; 
	_test_eof210: cs = 210; goto _test_eof; 
	_test_eof1648: cs = 1648; goto _test_eof; 
	_test_eof211: cs = 211; goto _test_eof; 
	_test_eof212: cs = 212; goto _test_eof; 
	_test_eof213: cs = 213; goto _test_eof; 
	_test_eof214: cs = 214; goto _test_eof; 
	_test_eof215: cs = 215; goto _test_eof; 
	_test_eof216: cs = 216; goto _test_eof; 
	_test_eof217: cs = 217; goto _test_eof; 
	_test_eof218: cs = 218; goto _test_eof; 
	_test_eof1649: cs = 1649; goto _test_eof; 
	_test_eof1650: cs = 1650; goto _test_eof; 
	_test_eof219: cs = 219; goto _test_eof; 
	_test_eof220: cs = 220; goto _test_eof; 
	_test_eof221: cs = 221; goto _test_eof; 
	_test_eof1652: cs = 1652; goto _test_eof; 
	_test_eof237: cs = 237; goto _test_eof; 
	_test_eof238: cs = 238; goto _test_eof; 
	_test_eof239: cs = 239; goto _test_eof; 
	_test_eof240: cs = 240; goto _test_eof; 
	_test_eof241: cs = 241; goto _test_eof; 
	_test_eof242: cs = 242; goto _test_eof; 
	_test_eof1661: cs = 1661; goto _test_eof; 
	_test_eof777: cs = 777; goto _test_eof; 
	_test_eof778: cs = 778; goto _test_eof; 
	_test_eof779: cs = 779; goto _test_eof; 
	_test_eof780: cs = 780; goto _test_eof; 
	_test_eof781: cs = 781; goto _test_eof; 
	_test_eof782: cs = 782; goto _test_eof; 
	_test_eof783: cs = 783; goto _test_eof; 
	_test_eof784: cs = 784; goto _test_eof; 
	_test_eof785: cs = 785; goto _test_eof; 
	_test_eof1668: cs = 1668; goto _test_eof; 
	_test_eof1669: cs = 1669; goto _test_eof; 
	_test_eof1417: cs = 1417; goto _test_eof; 
	_test_eof1418: cs = 1418; goto _test_eof; 
	_test_eof1670: cs = 1670; goto _test_eof; 
	_test_eof1419: cs = 1419; goto _test_eof; 
	_test_eof1420: cs = 1420; goto _test_eof; 
	_test_eof1421: cs = 1421; goto _test_eof; 
	_test_eof1422: cs = 1422; goto _test_eof; 
	_test_eof1423: cs = 1423; goto _test_eof; 
	_test_eof1671: cs = 1671; goto _test_eof; 
	_test_eof1424: cs = 1424; goto _test_eof; 
	_test_eof1425: cs = 1425; goto _test_eof; 
	_test_eof1426: cs = 1426; goto _test_eof; 
	_test_eof1427: cs = 1427; goto _test_eof; 
	_test_eof1428: cs = 1428; goto _test_eof; 
	_test_eof1429: cs = 1429; goto _test_eof; 
	_test_eof1430: cs = 1430; goto _test_eof; 
	_test_eof1431: cs = 1431; goto _test_eof; 
	_test_eof1432: cs = 1432; goto _test_eof; 
	_test_eof1433: cs = 1433; goto _test_eof; 
	_test_eof1434: cs = 1434; goto _test_eof; 
	_test_eof1435: cs = 1435; goto _test_eof; 
	_test_eof1436: cs = 1436; goto _test_eof; 
	_test_eof1437: cs = 1437; goto _test_eof; 
	_test_eof1438: cs = 1438; goto _test_eof; 
	_test_eof1439: cs = 1439; goto _test_eof; 
	_test_eof1440: cs = 1440; goto _test_eof; 
	_test_eof1441: cs = 1441; goto _test_eof; 
	_test_eof1442: cs = 1442; goto _test_eof; 
	_test_eof1443: cs = 1443; goto _test_eof; 
	_test_eof1444: cs = 1444; goto _test_eof; 
	_test_eof1445: cs = 1445; goto _test_eof; 
	_test_eof1446: cs = 1446; goto _test_eof; 
	_test_eof1447: cs = 1447; goto _test_eof; 
	_test_eof1448: cs = 1448; goto _test_eof; 
	_test_eof1449: cs = 1449; goto _test_eof; 
	_test_eof1450: cs = 1450; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 1611: goto tr2229;
	case 1612: goto tr2230;
	case 1613: goto tr2230;
	case 20: goto tr26;
	case 1614: goto tr2230;
	case 21: goto tr26;
	case 22: goto tr26;
	case 23: goto tr26;
	case 1615: goto tr2232;
	case 24: goto tr32;
	case 1616: goto tr2234;
	case 25: goto tr34;
	case 26: goto tr34;
	case 1617: goto tr2232;
	case 1618: goto tr2232;
	case 1619: goto tr2232;
	case 1620: goto tr2232;
	case 1621: goto tr2232;
	case 1622: goto tr2232;
	case 1623: goto tr2232;
	case 1624: goto tr2232;
	case 1625: goto tr2232;
	case 1626: goto tr2232;
	case 1627: goto tr2232;
	case 1628: goto tr2232;
	case 1629: goto tr2232;
	case 1630: goto tr2232;
	case 1631: goto tr2232;
	case 27: goto tr32;
	case 28: goto tr32;
	case 29: goto tr32;
	case 30: goto tr32;
	case 31: goto tr32;
	case 32: goto tr32;
	case 33: goto tr32;
	case 34: goto tr32;
	case 1633: goto tr2254;
	case 1634: goto tr2254;
	case 41: goto tr62;
	case 50: goto tr80;
	case 52: goto tr80;
	case 1635: goto tr2254;
	case 56: goto tr62;
	case 1636: goto tr2254;
	case 1638: goto tr2262;
	case 1639: goto tr2262;
	case 96: goto tr127;
	case 97: goto tr127;
	case 98: goto tr127;
	case 99: goto tr127;
	case 100: goto tr127;
	case 101: goto tr127;
	case 102: goto tr127;
	case 103: goto tr127;
	case 104: goto tr127;
	case 105: goto tr127;
	case 106: goto tr127;
	case 1641: goto tr2268;
	case 1642: goto tr2269;
	case 107: goto tr146;
	case 1643: goto tr2270;
	case 108: goto tr149;
	case 109: goto tr149;
	case 110: goto tr149;
	case 111: goto tr149;
	case 112: goto tr149;
	case 113: goto tr149;
	case 114: goto tr149;
	case 115: goto tr149;
	case 116: goto tr149;
	case 117: goto tr149;
	case 118: goto tr149;
	case 119: goto tr149;
	case 120: goto tr149;
	case 121: goto tr149;
	case 122: goto tr149;
	case 123: goto tr149;
	case 124: goto tr149;
	case 125: goto tr149;
	case 126: goto tr149;
	case 127: goto tr149;
	case 128: goto tr149;
	case 129: goto tr149;
	case 130: goto tr149;
	case 131: goto tr149;
	case 132: goto tr149;
	case 133: goto tr149;
	case 134: goto tr149;
	case 135: goto tr149;
	case 136: goto tr149;
	case 137: goto tr149;
	case 138: goto tr149;
	case 139: goto tr149;
	case 140: goto tr149;
	case 141: goto tr149;
	case 142: goto tr149;
	case 143: goto tr149;
	case 144: goto tr149;
	case 145: goto tr149;
	case 146: goto tr149;
	case 147: goto tr149;
	case 148: goto tr149;
	case 149: goto tr149;
	case 150: goto tr149;
	case 151: goto tr149;
	case 152: goto tr149;
	case 153: goto tr149;
	case 154: goto tr149;
	case 155: goto tr149;
	case 156: goto tr149;
	case 157: goto tr149;
	case 158: goto tr149;
	case 159: goto tr149;
	case 160: goto tr149;
	case 161: goto tr149;
	case 162: goto tr149;
	case 163: goto tr149;
	case 164: goto tr149;
	case 165: goto tr149;
	case 166: goto tr149;
	case 167: goto tr149;
	case 168: goto tr149;
	case 169: goto tr149;
	case 170: goto tr149;
	case 171: goto tr149;
	case 172: goto tr149;
	case 173: goto tr149;
	case 174: goto tr149;
	case 175: goto tr149;
	case 176: goto tr149;
	case 177: goto tr149;
	case 178: goto tr149;
	case 179: goto tr149;
	case 180: goto tr149;
	case 181: goto tr149;
	case 182: goto tr149;
	case 183: goto tr149;
	case 184: goto tr149;
	case 185: goto tr149;
	case 186: goto tr149;
	case 187: goto tr149;
	case 188: goto tr149;
	case 189: goto tr149;
	case 190: goto tr149;
	case 191: goto tr149;
	case 192: goto tr149;
	case 193: goto tr149;
	case 194: goto tr149;
	case 195: goto tr149;
	case 196: goto tr149;
	case 197: goto tr149;
	case 198: goto tr149;
	case 199: goto tr149;
	case 200: goto tr149;
	case 201: goto tr149;
	case 202: goto tr149;
	case 203: goto tr149;
	case 204: goto tr149;
	case 1644: goto tr2271;
	case 206: goto tr263;
	case 1645: goto tr2268;
	case 1646: goto tr2268;
	case 1647: goto tr2268;
	case 207: goto tr265;
	case 208: goto tr265;
	case 209: goto tr265;
	case 210: goto tr265;
	case 1650: goto tr2279;
	case 219: goto tr281;
	case 220: goto tr281;
	case 221: goto tr281;
	case 1669: goto tr2295;
	case 1417: goto tr1903;
	case 1418: goto tr1903;
	case 1670: goto tr1903;
	case 1419: goto tr1903;
	case 1420: goto tr1903;
	case 1421: goto tr1903;
	case 1422: goto tr1903;
	case 1423: goto tr1903;
	case 1671: goto tr2295;
	case 1424: goto tr1915;
	case 1425: goto tr1915;
	case 1426: goto tr1915;
	case 1427: goto tr1915;
	case 1428: goto tr1915;
	case 1429: goto tr1915;
	case 1430: goto tr1903;
	case 1431: goto tr1903;
	case 1432: goto tr1903;
	case 1433: goto tr1903;
	case 19: 
#line 44 "mfilescanner.rl"
	{
    cout << "*/\n";
    p--;
    {cs = stack[--top];goto _again;}
  }
	break;
	case 1453: 
	case 1454: 
	case 1455: 
	case 1456: 
	case 1457: 
	case 1458: 
	case 1459: 
	case 1460: 
	case 1461: 
	case 1462: 
	case 1463: 
	case 1464: 
	case 1465: 
	case 1466: 
	case 1467: 
	case 1468: 
	case 1469: 
	case 1470: 
	case 1471: 
	case 1472: 
	case 1473: 
	case 1474: 
	case 1475: 
	case 1476: 
	case 1477: 
	case 1478: 
	case 1479: 
	case 1480: 
	case 1481: 
	case 1482: 
	case 1483: 
	case 1484: 
	case 1485: 
	case 1486: 
	case 1487: 
	case 1488: 
	case 1489: 
	case 1490: 
	case 1491: 
	case 1492: 
	case 1493: 
	case 1494: 
	case 1495: 
	case 1496: 
	case 1497: 
	case 1498: 
	case 1499: 
	case 1500: 
	case 1501: 
	case 1502: 
	case 1503: 
	case 1504: 
	case 1505: 
	case 1506: 
	case 1507: 
	case 1508: 
	case 1509: 
	case 1510: 
	case 1511: 
	case 1512: 
	case 1513: 
	case 1514: 
	case 1515: 
	case 1516: 
	case 1517: 
	case 1518: 
	case 1519: 
	case 1520: 
	case 1521: 
	case 1522: 
	case 1523: 
	case 1524: 
	case 1525: 
	case 1526: 
	case 1527: 
	case 1528: 
	case 1529: 
	case 1530: 
	case 1531: 
	case 1532: 
	case 1533: 
	case 1534: 
	case 1535: 
	case 1536: 
	case 1537: 
	case 1538: 
	case 1539: 
	case 1540: 
	case 1541: 
	case 1542: 
	case 1543: 
	case 1544: 
	case 1545: 
	case 1546: 
	case 1547: 
	case 1548: 
	case 1632: 
	case 1674: 
#line 52 "mfilescanner.rl"
	{
    end_function();
  }
	break;
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
#line 696 "mfilescanner.rl"
	{
        p = tmp_p - 2;
        {goto st1649;}
      }
	break;
	case 1451: 
#line 903 "mfilescanner.rl"
	{
    p--;
    if(is_class_)
    {
      if(class_part_ == Header)
      {
        end_of_class_doc();
        {goto st1668;}
      } else if(class_part_ == Method)
        {goto st1632;}
      else if(class_part_ == Property)
      {
        end_of_property_doc();
        {goto st1661;}
      }
    }
    else
      {goto st1632;}
 }
	break;
	case 1: 
	case 5: 
	case 6: 
	case 7: 
	case 8: 
	case 9: 
	case 10: 
	case 11: 
	case 12: 
	case 13: 
	case 14: 
	case 15: 
	case 16: 
	case 17: 
	case 18: 
#line 1098 "mfilescanner.rl"
	{
    p=tmp_p;
    {goto st1452;}
  }
	break;
#line 27031 "mfilescanner.cc"
	}
	}

	_out: {}
	}

#line 1211 "mfilescanner.rl"

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

// escape '@' and '\' characters in string \a s
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

// standard brief text (replace '_' -> ' ' in s)
const string & MFileScanner::replace_underscore(std::string & s)
{
  string::size_type found = s.find("_");
  while(found != string::npos )
  {
    s[found] = ' ';
    found = s.find("_", found+1);
  }
  return s;
}

// pretty print the documentation block \a block
void MFileScanner::write_docu_block(const DocuBlock & block)
{
  bool add_prefix   = false;
  bool latex_begin  = true;
  bool not_verbatim = true;
  for( unsigned int i = 0; i < block.size(); i += 1 )
  {
    // begin all documentation lines after the first one with an asterisk
    if(add_prefix)
      cout << "* ";

    add_prefix = false;
    // read in new line of docu block
    const string & s = block[i];

    // parse for special comments
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
      // respect @code and @verbatim blocks
      if(s[i] == '@')
      {
        if(s.substr(i+1,4) == "code" || s.substr(i+1,8) == "verbatim")
          not_verbatim = false;
        else if(s.substr(i+1,7) == "endcode" || s.substr(i+1,11) == "endverbatim")
          not_verbatim = true;
        cout << s.substr(i,j-i);
      }
      // use typewriter fonts for words in single quotes
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
      // use latex output for words in backtick quotes
      else if(s[i] == '`' && not_verbatim)
      {
        string lout;
        if(!last_char_escaped)
        {
          // in case of double backtick quotes, use latex block
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
      // new line
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

// pretty print the documentation block list \a list for the list item named \a
// item_text. If docu blocks are empty, \a alternative is used. The alternative
// is normally read in by the confscanner.
void MFileScanner::write_docu_list(const DocuList & list,
                                   const string & item_text,
                                   const DocuList & alternative,
                                   const string separator = string())
{
  typedef DocuList :: const_iterator list_iterator;
  list_iterator lit = list.begin();
  // iterate over documentation blocks
  for(; lit != list.end(); ++lit)
  {
    cout << "* " << item_text << " " << (*lit).first << separator << "    ";
    const DocuBlock & block = (*lit).second;
    // block is empty?
    if(block.empty())
    {
      // then look for alternative documentation block form global
      // configuration file or use default text generated from variable name.
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

// pretty print a documentation block list map \a listmap with prepended title
// \a text. If listmap entry is empty, \a altlistmap is used instead.
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

void MFileScanner::end_of_class_doc()
{
  cout << "/** @class \"" << classname_ << "\"\n";

  cout_ingroup();

  cout << "* @brief ";
  cout_docuheader();
  cout << "*\n  ";
  cout_docubody();
  cout << "*\n ";
  cout_docuextra();
}

void MFileScanner::end_of_property_doc()
{
  cout << "/** @brief ";
  cout_docuheader();
  cout << "*\n  ";
  cout_docubody();
  cout << "*\n ";
  cout_docuextra();
}

void MFileScanner::cout_docuheader()
{
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
}

void MFileScanner :: cout_docubody()
{
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
}

void MFileScanner :: cout_docuextra()
{
  if(! cscan_.docuextra_.empty())
  {
    cout << "*\n  * ";
    write_docu_block(cscan_.docuextra_);
  }
  docuextra_.clear();
}

void MFileScanner :: cout_ingroup()
{
  typedef GroupSet     :: iterator group_iterator;
  // add @ingroup commands from the configuration file
  if((! groupset_.empty() || ! cscan_.groupset_.empty() ))
  {
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
}

// end a function and pretty print the documentation for this function
void MFileScanner::end_function()
{
  bool is_constructor = false;
  bool is_method = false;
  if(is_class_)
  {
    if(cfuncname_ == classname_)
      is_constructor = true;
    if(class_part_ == Method)
      is_method = true;
  }
  // end function
  cout << "}\n";
  if(is_getter_ || is_setter_)
    cout << "*/\n";
  // is the first function?
  if(is_first_function_)
  {
    if(! latex_output_ && ! is_class_)
    {
        // Then make a file documentation block
        cout << "/** @file \"" << filename_ << "\"\n  ";

      cout_ingroup();

      cout << "*/\n";
    }
  }
  cout << "/*";
  if(latex_output_ && !is_class_)
  {
    cout_ingroup();
    cout << "\n  ";
  }
  if(is_setter_ || is_getter_)
  {
    cout << "* @var " << cfuncname_ << "\n ";
    string temp = (is_setter_ ? "Setter" : "Getter");
    cout << "* @par " << temp << " is implemented \n * ";
  }
  else
  {
    // specify the @fn part
    cout << "* @fn ";
    if(returnlist_.size() == 0 && !is_constructor)
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

        if(is_method)
          first = true;
        else
          cout << "matlabtypesubstitute " << paramlist_[i];
      }
      paramlist_.clear();
      cout << ")\n  ";
    }

    // specify the @brief part
    cout << "* @brief ";
  }
  cout_docuheader();
  cout << "*\n  ";

  // specify the @details part

  // standard body definitions
  cout_docubody();

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
  cout_docuextra();
  if( new_syntax_ )
  {
    cout << "* @synupdate Syntax needs to be updated! \n  ";
  }
  cout << "*/\n";
  if(!is_method)
    is_first_function_ = false;
}

// main routine
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
    filename = filename.substr(cwd.size()+1);
  MFileScanner scanner(*fcin, filename, conffilename, latex_output);
  scanner.execute();
  return 0;
}

/* vim: set et sw=2 ft=ragel: */

