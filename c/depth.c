/*
 * Title: The annotated BASIC Listing
 *
 *  Listing of /home/alan/dev/BasicGames/source/base/depth/basic/depth.bas: 
 *
                   ++---- Routine IDs (Empty field=Inaccessible code, A=Main program).
                   || +-- Target status (G-GOSUB, T-GOTO, B-Both GOSUB and GOTO)
        Program    || |
        Address    vv v Original BASIC statement
    -------------- -- - ------------------------------------------------------------------------------
    0x564fc6b8bda0 ---------A   01000 PRINT "DEPTH CHARGE GAME" 
    0x564fc6b8be40 ---------A T 01010 PRINT
    0x564fc6b8bfa0 ---------A   01020 PRINT "DIMENSION OF SEARCH AREA"; 
    0x564fc6b8c100 ---------A   01030 INPUT G
    0x564fc6b8c190 ---------A   01040 PRINT
    0x564fc6b8c770 ---------A   01050 N=INT(LOG(G)/LOG(2))+1 
    0x564fc6b8c820 ---------A   01060 RANDOMIZE
    0x564fc6b8c9c0 ---------A   01070 PRINT "YOU ARE CAPTAIN OF THE DESTROYER USS DIGITAL AND AN ENEMY SUB HAS"
    0x564fc6b8cb60 ---------A   01080 PRINT "BEEN CAUSING  YOU  TROUBLE,  YOUR MISSION  IS TO DESTROY IT.  YOU"
    0x564fc6b91cd0 ---------A   01090 PRINT "HAVE "N" SHOTS.  SPECIFY DEPTH CHARGE EXPLOSION POINT WITH A TRIO "
    0x564fc6b91e30 ---------A   01100 PRINT "OF NUMBERS (DISTANCE NORTH, DISTANCE EAST, DEPTH FROM SURFACE)."
    0x564fc6b91e80 ---------A   01110 PRINT 
    0x564fc6b91fb0 ---------A   01120 PRINT "GOOD LUCK !" 
    0x564fc6b92020 ---------A   01130 PRINT
    0x564fc6b92350 ---------A   01140 A=INT(G*RND) 
    0x564fc6b92600 ---------A   01150 B=INT(G*RND) 
    0x564fc6b928b0 ---------A   01160 C=INT(G*RND)
    0x564fc6b92c10 ---------A   01170 FOR D=1 TO N 
    0x564fc6b92ca0 ---------A   01180 PRINT 
    0x564fc6b92e70 ---------A   01190 PRINT "TRIAL NUMBER ";D 
    0x564fc6b92fd0 ---------A   01200 PRINT "ENTER COORDINATES (N,E,D) : ";
    0x564fc6b93300 ---------A   01210 INPUT Y,X,Z
    0x564fc6b93980 ---------A   01220 IF ABS(X-A)+ABS(Y-B)+ABS(Z-C)=0 THEN 1300
    0x564fc6b93a00 ---------A   01230 GOSUB 1390
    0x564fc6b93a60 ---------A   01240 PRINT 
    0x564fc6b93b10 ---------A   01250 NEXT D
    0x564fc6b93bb0 ---------A   01260 PRINT 
    0x564fc6b93d20 ---------A   01270 PRINT "YOU HAVE BEEN TORPEDOED!  ABANDON SHIP!"
    0x564fc6b94190 ---------A   01280 PRINT "THE SUBMARINE WAS AT ";B,",";A,",";C
    0x564fc6b94200 ---------A   01290 GOTO 1340
    0x564fc6b94280 ---------A T 01300 PRINT 
    0x564fc6b94520 ---------A   01310 PRINT "B O O M ! !  YOU FOUND IT IN ";D;"TRIES!"
    0x564fc6b94590 ---------A   01320 PRINT 
    0x564fc6b94820 ---------A   01330 PRINT 
    0x564fc6b94970 ---------A T 01340 PRINT "ANOTHER GAME (Y OR N)";
    0x564fc6b94ad0 ---------A   01350 INPUT A$
    0x564fc6b94cd0 ---------A   01360 IF A$="Y" THEN 1010
    0x564fc6b94e20 ---------A   01370 PRINT "OK.  HOPE YOU ENJOYED YOURSELF " 
    0x564fc6b94ea0 ---------A   01380 GOTO 1650
    0x564fc6b94ff0 ---------B G 01390 PRINT "SONAR REPORTS SHOT WAS ";
    0x564fc6b95160 ---------B   01400 IF Y>B THEN 1470
    0x564fc6b952e0 ---------B   01410 IF Y<B THEN 1490
    0x564fc6b95460 ---------B T 01420 IF X>A THEN 1510
    0x564fc6b955e0 ---------B   01430 IF X<A THEN 1530
    0x564fc6b95760 ---------B T 01440 IF Y<>B THEN 1550
    0x564fc6b958e0 ---------B   01450 IF X<>A THEN 1550
    0x564fc6b95960 ---------B   01460 GOTO 1560
    0x564fc6b95aa0 ---------B T 01470 PRINT "NORTH";
    0x564fc6b95b10 ---------B   01480 GOTO 1420
    0x564fc6b95c50 ---------B T 01490 PRINT "SOUTH";
    0x564fc6b95cc0 ---------B   01500 GOTO 1420
    0x564fc6b95e00 ---------B T 01510 PRINT "EAST";
    0x564fc6b95e70 ---------B   01520 GOTO 1440
    0x564fc6b95fb0 ---------B T 01530 PRINT "WEST";
    0x564fc6b96020 ---------B   01540 GOTO 1440
    0x564fc6b96160 ---------B T 01550 PRINT " AND ";
    0x564fc6b962d0 ---------B T 01560 IF Z>C THEN 1590
    0x564fc6b96450 ---------B   01570 IF Z<C THEN 1610
    0x564fc6b965d0 ---------B   01580 IF Z=C THEN 1630
    0x564fc6b96710 ---------B T 01590 PRINT "TOO LOW"
    0x564fc6b96780 ---------B   01600 GOTO 1640
    0x564fc6b968a0 ---------B T 01610 PRINT "TOO HIGH"
    0x564fc6b96910 ---------B   01620 GOTO 1640
    0x564fc6b96a30 ---------B T 01630 PRINT "DEPTH OK"
    0x564fc6b96a80 ---------B T 01640 RETURN
    0x564fc6b96ef0 ---------A T 01650 END
 */

/*
 * Line reference table:
 *

    Target
   Line Num.    Referencing line number (Reference is T-GOTO or G-GOSUB).
   ---------    -------------------------------------------------------------------
     01010      01360T
     01300      01220T
     01340      01290T
     01390      01230G
     01420      01480T, 01500T
     01440      01520T, 01540T
     01470      01400T
     01490      01410T
     01510      01420T
     01530      01430T
     01550      01440T, 01450T
     01560      01460T
     01590      01560T
     01610      01570T
     01630      01580T
     01640      01600T, 01620T
     01650      01380T

 */

/* 
 * Routine Start, Target, Return and End Program Addresses 
 * 

  Rtn      Start           Target           Return             End    
  --- --------------   --------------   --------------   -------------- 
   A) 0x564fc6b8bda0   0x564fc6b8bda0   0x564fc6b96ef0   0x564fc6b96ef0 
   B) 0x564fc6b94ff0   0x564fc6b94ff0   0x564fc6b96a80   0x564fc6b96a80 

    NOTE: Routine B overlaps, or is tangled with, routine A!

 */



/*
 * Free line number map.
 *
     Start    End    # Lines in Gap
     -----   -----   ------------------
     00000 - 00990     100 
     01660 - 10000    8350 

 */



/*
 *  Symbol Table Listing for '/home/alan/dev/BasicGames/source/base/depth/basic/depth.bas'
 *
    A              Integer 
    A$             String  
    ABS   Function Integer     args=1, int   
    B              Integer 
    C              Integer 
    D              Integer 
    G              Integer 
    INT   Function Integer     args=1, float 
    LOG   Function Integer     args=1, int   
    N              Integer 
    RND   Function Integer     args=1, int   
    X              Integer 
    Y              Integer 
    Z              Integer 

 */


/*
 * Title: Display of final 'clean' BASIC listing.
 *
 *  Listing of /home/alan/dev/BasicGames/source/base/depth/basic/depth.bas: 
 *
                   ++---- Routine IDs (Empty field=Inaccessible code, A=Main program).
                   || +-- Target status (G-GOSUB, T-GOTO, B-Both GOSUB and GOTO)
        Program    || |
        Address    vv v Original BASIC statement
    -------------- -- - ------------------------------------------------------------------------------
    0x564fc6b8bda0 ---------A   01000 PRINT "DEPTH CHARGE GAME" 
    0x564fc6b8be40 ---------A T 01010 PRINT
    0x564fc6b8bfa0 ---------A   01020 PRINT "DIMENSION OF SEARCH AREA"; 
    0x564fc6b8c100 ---------A   01030 INPUT G
    0x564fc6b8c190 ---------A   01040 PRINT
    0x564fc6b8c770 ---------A   01050 N=INT(LOG(G)/LOG(2))+1 
    0x564fc6b8c820 ---------A   01060 RANDOMIZE
    0x564fc6b8c9c0 ---------A   01070 PRINT "YOU ARE CAPTAIN OF THE DESTROYER USS DIGITAL AND AN ENEMY SUB HAS"
    0x564fc6b8cb60 ---------A   01080 PRINT "BEEN CAUSING  YOU  TROUBLE,  YOUR MISSION  IS TO DESTROY IT.  YOU"
    0x564fc6b91cd0 ---------A   01090 PRINT "HAVE "N" SHOTS.  SPECIFY DEPTH CHARGE EXPLOSION POINT WITH A TRIO "
    0x564fc6b91e30 ---------A   01100 PRINT "OF NUMBERS (DISTANCE NORTH, DISTANCE EAST, DEPTH FROM SURFACE)."
    0x564fc6b91e80 ---------A   01110 PRINT 
    0x564fc6b91fb0 ---------A   01120 PRINT "GOOD LUCK !" 
    0x564fc6b92020 ---------A   01130 PRINT
    0x564fc6b92350 ---------A   01140 A=INT(G*RND) 
    0x564fc6b92600 ---------A   01150 B=INT(G*RND) 
    0x564fc6b928b0 ---------A   01160 C=INT(G*RND)
    0x564fc6b92c10 ---------A   01170 FOR D=1 TO N 
    0x564fc6b92ca0 ---------A   01180 PRINT 
    0x564fc6b92e70 ---------A   01190 PRINT "TRIAL NUMBER ";D 
    0x564fc6b92fd0 ---------A   01200 PRINT "ENTER COORDINATES (N,E,D) : ";
    0x564fc6b93300 ---------A   01210 INPUT Y,X,Z
    0x564fc6b93980 ---------A   01220 IF ABS(X-A)+ABS(Y-B)+ABS(Z-C)=0 THEN 1300
    0x564fc6b93a00 ---------A   01230 GOSUB 1400
    0x564fc6b93a60 ---------A   01240 PRINT 
    0x564fc6b93b10 ---------A   01250 NEXT D
    0x564fc6b93bb0 ---------A   01260 PRINT 
    0x564fc6b93d20 ---------A   01270 PRINT "YOU HAVE BEEN TORPEDOED!  ABANDON SHIP!"
    0x564fc6b94190 ---------A   01280 PRINT "THE SUBMARINE WAS AT ";B,",";A,",";C
    0x564fc6b94200 ---------A   01290 GOTO 1340
    0x564fc6b94280 ---------A T 01300 PRINT 
    0x564fc6b94520 ---------A   01310 PRINT "B O O M ! !  YOU FOUND IT IN ";D;"TRIES!"
    0x564fc6b94590 ---------A   01320 PRINT 
    0x564fc6b94820 ---------A   01330 PRINT 
    0x564fc6b94970 ---------A T 01340 PRINT "ANOTHER GAME (Y OR N)";
    0x564fc6b94ad0 ---------A   01350 INPUT A$
    0x564fc6b94cd0 ---------A   01360 IF A$="Y" THEN 1010
    0x564fc6b94e20 ---------A   01370 PRINT "OK.  HOPE YOU ENJOYED YOURSELF " 
    0x564fc6b94ea0 ---------A   01380 GOTO 1390
    0x564fc6b96ef0 ---------A T 01390 END
    0x564fc6b94ff0 ---------B G 01400 PRINT "SONAR REPORTS SHOT WAS ";
    0x564fc6b95160 ---------B   01410 IF Y>B THEN 1480
    0x564fc6b952e0 ---------B   01420 IF Y<B THEN 1500
    0x564fc6b95460 ---------B T 01430 IF X>A THEN 1520
    0x564fc6b955e0 ---------B   01440 IF X<A THEN 1540
    0x564fc6b95760 ---------B T 01450 IF Y<>B THEN 1560
    0x564fc6b958e0 ---------B   01460 IF X<>A THEN 1560
    0x564fc6b95960 ---------B   01470 GOTO 1570
    0x564fc6b95aa0 ---------B T 01480 PRINT "NORTH";
    0x564fc6b95b10 ---------B   01490 GOTO 1430
    0x564fc6b95c50 ---------B T 01500 PRINT "SOUTH";
    0x564fc6b95cc0 ---------B   01510 GOTO 1430
    0x564fc6b95e00 ---------B T 01520 PRINT "EAST";
    0x564fc6b95e70 ---------B   01530 GOTO 1450
    0x564fc6b95fb0 ---------B T 01540 PRINT "WEST";
    0x564fc6b96020 ---------B   01550 GOTO 1450
    0x564fc6b96160 ---------B T 01560 PRINT " AND ";
    0x564fc6b962d0 ---------B T 01570 IF Z>C THEN 1600
    0x564fc6b96450 ---------B   01580 IF Z<C THEN 1620
    0x564fc6b965d0 ---------B   01590 IF Z=C THEN 1640
    0x564fc6b96710 ---------B T 01600 PRINT "TOO LOW"
    0x564fc6b96780 ---------B   01610 GOTO 1650
    0x564fc6b968a0 ---------B T 01620 PRINT "TOO HIGH"
    0x564fc6b96910 ---------B   01630 GOTO 1650
    0x564fc6b96a30 ---------B T 01640 PRINT "DEPTH OK"
    0x564fc6b96a80 ---------B T 01650 RETURN
 */

//---------------------------------------------------------------------------
// $Header$ 
//
// NOTE: This program has been automatically tranlated by b2c
//
// $Log$ 
// 
//---------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
//---------------------------------------------------------------------------
// Global data area.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------




typedef enum {TYPE_None,TYPE_Integer,TYPE_Float,TYPE_String}t_type;
typedef struct{
    int    LineNum;
    int    Size;
    char** SData;
}t_data;
t_data ProgramData[] = {
    {    0,  0,nullptr       }
};

#include "intrinsics.h"


//---------------------------------------------------------------------------
// Global variable area.
//
// NOTE: Variable names are long to allow for easy editing.
//---------------------------------------------------------------------------
int   Submarine_East;   // Comments?
char* A_str;        // Comments?
int   Submarine_North;  // Comments?
int   Submarine_Depth;  // Comments?
int   Turn;         // Comments?
int   VolSide;      // Comments?
int   NumTurns;     // Comments?
int   Grid_East;    // Comments?
int   Grid_North;   // Comments?
int   Grid_Depth;   // Comments?
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
char* GLBpStr=nullptr;
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// Subroutine Prototypes.
//---------------------------------------------------------------------------
void SonarReport();

//---------------------------------------------------------------------------
// Program Functions.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// Program Subroutines.
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// Routine B
//---------------------------------------------------------------------------

void SonarReport(){
    // 01400 PRINT "SONAR REPORTS SHOT WAS ";
    b2c_fprintf(stdout,"SONAR REPORTS SHOT WAS "); 
    // 01410 IF Y>B THEN 1480
    if(Grid_North>Submarine_North)goto Err_North;
    // 01420 IF Y<B THEN 1500
    if(Grid_North<Submarine_North)goto Err_South;

  Sonar_Test_East:
    // 01430 IF X>A THEN 1520
    if(Grid_East>Submarine_East)goto Err_East;
    // 01440 IF X<A THEN 1540
    if(Grid_East<Submarine_East)goto Err_West;

  Test_For_Conjunction:
    // 01450 IF Y<>B THEN 1560
    if(Grid_North!=Submarine_North)goto Add_Conjunction;
    // 01460 IF X<>A THEN 1560
    if(Grid_East!=Submarine_East)goto Add_Conjunction;
    // 01470 GOTO 1570
    goto Sonar_Test_Depth;

  Err_North:
    // 01480 PRINT "NORTH";
    b2c_fprintf(stdout,"NORTH"); 
    // 01490 GOTO 1430
    goto Sonar_Test_East;

  Err_South:
    // 01500 PRINT "SOUTH";
    b2c_fprintf(stdout,"SOUTH"); 
    // 01510 GOTO 1430
    goto Sonar_Test_East;

  Err_East:
    // 01520 PRINT "EAST";
    b2c_fprintf(stdout,"EAST"); 
    // 01530 GOTO 1450
    goto Test_For_Conjunction;

  Err_West:
    // 01540 PRINT "WEST";
    b2c_fprintf(stdout,"WEST"); 
    // 01550 GOTO 1450
    goto Test_For_Conjunction;

  Add_Conjunction:
    // 01560 PRINT " AND ";
    b2c_fprintf(stdout," AND "); 

  Sonar_Test_Depth:
    // 01570 IF Z>C THEN 1600
    if(Grid_Depth>Submarine_Depth)goto Err_Low;
    // 01580 IF Z<C THEN 1620
    if(Grid_Depth<Submarine_Depth)goto Err_High;
    // 01590 IF Z=C THEN 1640
    if(Grid_Depth==Submarine_Depth)goto Err_DepthOK;

  Err_Low:
    // 01600 PRINT "TOO LOW"
    b2c_fprintf(stdout,"TOO LOW"); b2c_fprintf(stdout,"\n");
    // 01610 GOTO 1650
    goto Sonar_Report_Complete;

  Err_High:
    // 01620 PRINT "TOO HIGH"
    b2c_fprintf(stdout,"TOO HIGH"); b2c_fprintf(stdout,"\n");
    // 01630 GOTO 1650
    goto Sonar_Report_Complete;

  Err_DepthOK:
    // 01640 PRINT "DEPTH OK"
    b2c_fprintf(stdout,"DEPTH OK"); b2c_fprintf(stdout,"\n");

  Sonar_Report_Complete:
    // 01650 RETURN
    return;
};

//---------------------------------------------------------------------------
// Main Program.
//---------------------------------------------------------------------------
#pragma argsused
int main(int argc,char *argv[])
{
    // 01000 PRINT "DEPTH CHARGE GAME" 
    b2c_fprintf(stdout,"DEPTH CHARGE GAME"); b2c_fprintf(stdout,"\n");

  StartGame:
    // 01010 PRINT
    b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");
    // 01020 PRINT "DIMENSION OF SEARCH AREA"; 
    b2c_fprintf(stdout,"DIMENSION OF SEARCH AREA"); 
    // 01030 INPUT G
    // Start of Basic INPUT statement 01030
    printf(" ? ");
    char inpbuf_01030[100];
    if(fgets(inpbuf_01030,100,stdin)==nullptr){
        fprintf(stderr,"ERROR: End of file on input.\n");
        exit(2);
    }else{
        char *ps_01030=strtok(inpbuf_01030," ,\t\n");
        // This may cause problems if BASIC programmer expected
        // input strings to be copied instead of just pointing
        // to the input buffer (ie. strings can be over written).
        if(ps_01030==nullptr){
            VolSide = 0;
        }else{
            VolSide = atof(ps_01030);
        };
    }; // End of Basic INPUT statement 01030
    // 01040 PRINT
    b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");
    // 01050 N=INT(LOG(G)/LOG(2))+1 
    NumTurns = INT(LOG(VolSide)/LOG(2))+1;
    // 01060 RANDOMIZE
    RANDOMIZE();
    // 01070 PRINT "YOU ARE CAPTAIN OF THE DESTROYER USS DIGITAL AND AN ENEMY SUB HAS"
    b2c_fprintf(stdout,"YOU ARE CAPTAIN OF THE DESTROYER USS DIGITAL AND AN ENEMY SUB HAS"); b2c_fprintf(stdout,"\n");
    // 01080 PRINT "BEEN CAUSING  YOU  TROUBLE,  YOUR MISSION  IS TO DESTROY IT.  YOU"
    b2c_fprintf(stdout,"BEEN CAUSING  YOU  TROUBLE,  YOUR MISSION  IS TO DESTROY IT.  YOU"); b2c_fprintf(stdout,"\n");
    // 01090 PRINT "HAVE "N" SHOTS.  SPECIFY DEPTH CHARGE EXPLOSION POINT WITH A TRIO "
    b2c_fprintf(stdout,"HAVE  %d  SHOTS.  SPECIFY DEPTH CHARGE EXPLOSION POINT WITH A TRIO ",NumTurns); b2c_fprintf(stdout,"\n");
    // 01100 PRINT "OF NUMBERS (DISTANCE NORTH, DISTANCE EAST, DEPTH FROM SURFACE)."
    b2c_fprintf(stdout,"OF NUMBERS (DISTANCE NORTH, DISTANCE EAST, DEPTH FROM SURFACE)."); b2c_fprintf(stdout,"\n");
    // 01110 PRINT 
    b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");
    // 01120 PRINT "GOOD LUCK !" 
    b2c_fprintf(stdout,"GOOD LUCK !"); b2c_fprintf(stdout,"\n");
    // 01130 PRINT
    b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");
    // 01140 A=INT(G*RND) 
    Submarine_East = INT(VolSide*RND());
    // 01150 B=INT(G*RND) 
    Submarine_North = INT(VolSide*RND());
    // 01160 C=INT(G*RND)
    Submarine_Depth = INT(VolSide*RND());
    // 01170 FOR D=1 TO N 
    for(Turn=1;Turn<=NumTurns;Turn++){
        // 01180 PRINT 
        b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");
        // 01190 PRINT "TRIAL NUMBER ";D 
        b2c_fprintf(stdout,"TRIAL NUMBER  %d ",Turn); b2c_fprintf(stdout,"\n");
        // 01200 PRINT "ENTER COORDINATES (N,E,D) : ";
        b2c_fprintf(stdout,"ENTER COORDINATES (N,E,D) : "); 
        // 01210 INPUT Y,X,Z
        // Start of Basic INPUT statement 01210
        printf(" ? ");
        char inpbuf_01210[100];
        if(fgets(inpbuf_01210,100,stdin)==nullptr){
            fprintf(stderr,"ERROR: End of file on input.\n");
            exit(2);
        }else{
            char *ps_01210=strtok(inpbuf_01210," ,\t\n");
            // This may cause problems if BASIC programmer expected
            // input strings to be copied instead of just pointing
            // to the input buffer (ie. strings can be over written).
            if(ps_01210==nullptr){
                Grid_North = 0;
            }else{
                Grid_North = atof(ps_01210);
            };
            ps_01210=strtok(nullptr," ,\t\n");
            if(ps_01210==nullptr){
                Grid_East = 0;
            }else{
                Grid_East = atof(ps_01210);
            };
            ps_01210=strtok(nullptr," ,\t\n");
            if(ps_01210==nullptr){
                Grid_Depth = 0;
            }else{
                Grid_Depth = atof(ps_01210);
            };
        }; // End of Basic INPUT statement 01210
        // 01220 IF ABS(X-A)+ABS(Y-B)+ABS(Z-C)=0 THEN 1300
        if(ABS(Grid_East-Submarine_East)+ABS(Grid_North-Submarine_North)+ABS(Grid_Depth-Submarine_Depth)==0)goto SubmarineHit;
        // 01230 GOSUB 1400
        SonarReport();
        // 01240 PRINT 
        b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");
        // 01250 NEXT D
        int dummy_1250=0; // Ignore this line.
    }; // End-For(Turn)
    // 01260 PRINT 
    b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");
    // 01270 PRINT "YOU HAVE BEEN TORPEDOED!  ABANDON SHIP!"
    b2c_fprintf(stdout,"YOU HAVE BEEN TORPEDOED!  ABANDON SHIP!"); b2c_fprintf(stdout,"\n");
    // 01280 PRINT "THE SUBMARINE WAS AT ";B,",";A,",";C
    b2c_fprintf(stdout,"THE SUBMARINE WAS AT  %d @, %d @, %d ",Submarine_North,Submarine_East,Submarine_Depth); b2c_fprintf(stdout,"\n");
    // 01290 GOTO 1340
    goto QAnotherGame;

  SubmarineHit:
    // 01300 PRINT 
    b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");
    // 01310 PRINT "B O O M ! !  YOU FOUND IT IN ";D;"TRIES!"
    b2c_fprintf(stdout,"B O O M ! !  YOU FOUND IT IN  %d TRIES!",Turn); b2c_fprintf(stdout,"\n");
    // 01320 PRINT 
    b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");
    // 01330 PRINT 
    b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");

  QAnotherGame:
    // 01340 PRINT "ANOTHER GAME (Y OR N)";
    b2c_fprintf(stdout,"ANOTHER GAME (Y OR N)"); 
    // 01350 INPUT A$
    // Start of Basic INPUT statement 01350
    printf(" ? ");
    char inpbuf_01350[100];
    if(fgets(inpbuf_01350,100,stdin)==nullptr){
        fprintf(stderr,"ERROR: End of file on input.\n");
        exit(2);
    }else{
        char *ps_01350=strtok(inpbuf_01350," ,\t\n");
        // This may cause problems if BASIC programmer expected
        // input strings to be copied instead of just pointing
        // to the input buffer (ie. strings can be over written).
        if(ps_01350==nullptr){
            A_str = "";
        }else{
            A_str = ps_01350;
        };
    }; // End of Basic INPUT statement 01350
    // 01360 IF A$="Y" THEN 1010
    if(strcmp(A_str,"Y")==0)goto StartGame;
    // 01370 PRINT "OK.  HOPE YOU ENJOYED YOURSELF " 
    b2c_fprintf(stdout,"OK.  HOPE YOU ENJOYED YOURSELF "); b2c_fprintf(stdout,"\n");
    // 01380 GOTO 1390
    goto ExitGame;

  ExitGame:
    // 01390 END
   return(0);
};

//---------------------------------------------------------------------------
// End of $RCSfile$ 
//---------------------------------------------------------------------------
