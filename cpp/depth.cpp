
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


// TODO: Have hassling by enemy aircraft (which makes destroyer move position -- 
//       but the search space doesn't change -- so the captain has to traslate the
//       coordinates in their head.
// TODO: The complications might help the destroyer have more depth-charge tests 
//       before being hit by submarine.
// TODO: Allow the destroyer to abandon the search at any time (they don't know
//       how many depth-charges they have left so should get cowardice message
//       "You've abandoned the search with depth charges aboard. Headquarters is
//       not going to like this"
// TODO: Multiple subs. Maybe coming into and leaving search space.
// TODO: Subs kill destroyer after N+R where N is optimal binary search, and R is
//       some random number based on size of search area.
// TODO: Make the subs move.
// TODO: Make the subs go quiet.
// TODO: Make subs appear to die then become active again (oil spill).
// TODO: Allow destroyer to use SRS/LRS to determine where to search and make it a 
//       more involved game. 
// TODO: Encode text strings as compressed so they can't be read in exe:
//          cppbanner  BOOM! | chrcnt | grep -v " 0 "

void explain(int n)
{
    printf("\n\nYou are captain of the destroyer USS Digital and\n");
    printf("an enemy sub has been causing you trouble. Your mission\n"); 
    printf("is to destroy it. You have %d shots. Specify depth charge\n",n);
    printf("explosion point with a trio of numbers (distance north, \n");
    printf("east, and  depth from surface).\n");
    printf("GOOD LUCK !\n\n\n");
}

void boom()
{
    // TODO: Have more than one explosion type being displayed.
    printf("\n\n  ____                          \n");
    printf(" | __ )  ___   ___  _ __ ___    \n");
    printf(" |  _ \\ / _ \\ / _ \\| '_ ` _ \\   \n");
    printf(" | |_) | (_) | (_) | | | | | |  \n");
    printf(" |____/ \\___/ \\___/|_| |_| |_|  \n\n\n");
}

int main(void)
{
    int g, n;
    char ac;
    char ans[100];
    
    printf("DEPTH CHARGE GAME\n");
    srand(time(NULL));


    bool play=true;
    while(play){
        printf("\n\nSearch volume (side length): ");
        fgets(ans,100,stdin);
        ans[strlen(ans)-1]=0;
        g=atoi(ans);
        
        n = (int)(log(g) / log(2)) + 1;
        explain(n);

        int tx = (int)(g * (rand() / (RAND_MAX + 1.0)));
        int ty = (int)(g * (rand() / (RAND_MAX + 1.0)));
        int tz = (int)(g * (rand() / (RAND_MAX + 1.0)));
        //printf("tx=%d ty=%d tz=%d\n",tx,ty,tz);

        bool won=false;
        for(int d=1; (d<=n)&&(!won); d++) {
            printf("\nDepth Charge: %d\n", d);
            printf("  Enter coordinates (N,E,D) : ");
            fgets(ans,100,stdin);
            ans[strlen(ans)-1]=0;

            // TODO: Get seg fault if user doesn't enter all the coordinates.  Change
            //       the wild condition to account for these and make a random message
            //       be displayed.

            int x,y,z;
            if(*ans == 0){
                printf("    Depth charge WILD!!! Hit the deck!!!\n");
                x = (int)(g * (rand() / (RAND_MAX + 1.0)));
                y = (int)(g * (rand() / (RAND_MAX + 1.0)));
                z = (int)(g * (rand() / (RAND_MAX + 1.0)));
                printf("    Depth charge explodes at N,E,D=(%d,%d,%d)\n",x,y,z);

            }else{
                char* sx = strtok(ans,", \t");
                char* sy = strtok(nullptr,", \t");
                char* sz = strtok(nullptr,", \t");

                x = atoi(sx);
                y = atoi(sy);
                z = atoi(sz);
            }
            if (abs(x - tx) + abs(y - ty) + abs(z - tz) == 0) {

                boom();

                printf("\n\nYou see an eruption of oil and debris.\n");
                printf("As you watch you see what appears to be an enemy\n");
                printf("submarine keel over and disappear benieth the waves...\n");
                printf("You found it in %d tries! Congratulations!\n", d);
                won=true;
            } else {
                const char* ns="";
                const char* ew="";
                const char* ud="Depth OK";

                if(x<tx){
                    ns="South";
                }else if(x>tx){
                    ns="North";
                }

                if(y<ty){
                    ew="West";
                }else if(y>ty){
                    ew="East";
                }

                if(z<tz){
                    ud="Shallow";
                }else if(z>tz){
                    ud="Deep";
                }

                char buf[100];
                memset(buf,0,100);
                const char* sep1="";
                const char* sep2="";
                if((*ns!=0)&&(*ew!=0)) sep1=", ";
                if((*ns!=0)||(*ew!=0)) sep2=" and ";
                strcat(buf,ns); 
                strcat(buf,sep1); 
                strcat(buf,ew); 
                strcat(buf,sep2); 
                strcat(buf,ud); 

                printf("   Sonar reports shot was: %s\n",buf);
            }
        }
        if(!won){
            boom();

            printf("You have been torpedoed!  Water is gushing in \n");
            printf("through the torpedoe bays.  Pipes have burst! \n");
            printf("The captain and first boson are both dead.\n");
            printf("We are taking on too much water!  ABANDON SHIP!\n\n");
            printf("The submarine was at %d,%d,%d\n", tx, ty, tz);
            printf("\n\n\nAnother game (Y OR N)");
            fgets(ans,100,stdin);
            ans[strlen(ans)-1]=0;
            
            if(toupper(ans[0])!='Y'){
                printf("OK.  Hope you enjoyed yourself\n");
                play=false;
            }
        }
    }
    return 0;
}
