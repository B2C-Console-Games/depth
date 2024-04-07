
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include <vector>


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

std::vector<const char* > msg_introduction;
std::vector<const char* > msg_victory;
std::vector<const char* > msg_failure;
std::vector<const char* > msg_location;

void load_file(const char* fn,std::vector< const char* >& list)
{
    char buf[1000];
    FILE* fh=fopen(fn,"r");
    if(fh!=nullptr){
        char* str=nullptr;
        while((str=fgets(buf,1000,fh))!=nullptr){
            if((buf[0]!='#')||(buf[0]!=0)){
                for(int c=0;c<strlen(buf);c++) if(buf[c]=='|') buf[c]='\n';
                list.push_back(strdup(buf));
            }
        }
        fclose(fh);
    }else{
        fprintf(stderr,"ERROR: Failed to open file %s!\n",fn);
    }
}

const char* pick_string(std::vector< const char* >& list)
{
    return(list[rand()%(list.size())]);
}

void explain(int n)
{
    const char* str=pick_string(msg_introduction);
    printf("\n");
    printf(str,n);
    printf("\n\n\n");
}

void boom()
{
    // TODO: Have more than one explosion sub_eastpe being displayed.
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

    load_file("msg/introduction.txt",msg_introduction);    
    load_file("msg/victory.txt",msg_victory);    
    load_file("msg/failure.txt",msg_failure);    
    load_file("msg/location.txt",msg_location);    

    bool play=true;
    while(play){
        // Get the search volume side-length
        printf("\n\nSearch volume (side length): ");
        fgets(ans,100,stdin);
        ans[strlen(ans)-1]=0;
        g=atoi(ans);
        
        n = (int)(log(g) / log(2)) + 1;
        explain(n);

        // Locate the submarine in our volume.
        int sub_north = (int)(g * (rand() / (RAND_MAX + 1.0)));
        int sub_east = (int)(g * (rand() / (RAND_MAX + 1.0)));
        int sub_depth = (int)(g * (rand() / (RAND_MAX + 1.0)));
        //printf("sub_north=%d sub_east=%d sub_depth=%d\n",sub_north,sub_east,sub_depth);

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

            // Check for difference in location of depth-charge explosion and submarine.
            if (abs(x-sub_north) + abs(y-sub_east) + abs(z-sub_depth) == 0) {

                // DC hit the submarine.
                boom();
                const char* str=pick_string(msg_victory);
                printf("\n\n\n%s\n\n",str);
                printf("You found it in %d tries! Congratulations!\n", d);
                won=true;

            } else {

                const char* ns="";
                const char* ew="";
                const char* ud="Depth OK";

                if(x<sub_north){
                    ns="South";
                }else if(x>sub_north){
                    ns="North";
                }

                if(y<sub_east){
                    ew="West";
                }else if(y>sub_east){
                    ew="East";
                }

                if(z<sub_depth){
                    ud="Shallow";
                }else if(z>sub_depth){
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

                printf("    Sonar reports shot was: %s\n",buf);
            }
        }

        // Check for victory conditions.
        if(!won){
            boom();

            const char* str=pick_string(msg_failure);
            printf("\n\n%s",str);

            str=pick_string(msg_location); 
            printf(str,sub_north,sub_east,sub_depth,sub_depth*10);

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
