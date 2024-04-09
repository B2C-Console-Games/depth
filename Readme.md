This Basic version of DepthCharge is a fairly trivial program.  It allows the player
to specify a N x N x N volume below the surface of the player's ship.  The player
then specifies (repeatedly) the coordinates of the detonation of the depth charges with coordinates
North, East and Depth from the surface.  This puts the destroyer at the 
South-West corner of the search space on the surface.  

The number of depth-charges is limited and is determined by the side-length, N, of the volume
and the assumption of a binary search.  

The best solution is to do a binary search on each of the coordinates of the search space.

This isn't a terribly gripping game but now that it is in C/C++ we can improve it in 
numerous directions.

But first lets look a what a typical session of the game looks like.

Example session with depth.c which is the immediate (b2c) copy of the program depth.bas

        DEPTH CHARGE GAME

        DIMENSION OF SEARCH AREA ? 10

        YOU ARE CAPTAIN OF THE DESTROYER USS DIGITAL AND AN ENEMY SUB HAS
        BEEN CAUSING  YOU  TROUBLE,  YOUR MISSION  IS TO DESTROY IT.  YOU
        HAVE  4  SHOTS.  SPECIFY DEPTH CHARGE EXPLOSION POINT WITH A TRIO 
        OF NUMBERS (DISTANCE NORTH, DISTANCE EAST, DEPTH FROM SURFACE).

        GOOD LUCK !


        TRIAL NUMBER  1 
        ENTER COORDINATES (N,E,D) :  ? 5,5,5
        SONAR REPORTS SHOT WAS WEST AND TOO HIGH


        TRIAL NUMBER  2 
        ENTER COORDINATES (N,E,D) :  ? 5,7,7
        SONAR REPORTS SHOT WAS EAST AND TOO LOW


        TRIAL NUMBER  3 
        ENTER COORDINATES (N,E,D) :  ? 5,6,6

        B O O M ! !  YOU FOUND IT IN  3 TRIES!


        ANOTHER GAME (Y OR N) ? n
        OK.  HOPE YOU ENJOYED YOURSELF 


A slightly improved version (depth.cpp) produces a session like:

        DEPTH CHARGE GAME


        Search volume (side length): 10


        You are captain of the destroyer USS Digital and
        an enemy sub has been causing you trouble. Your mission
        is to destroy it. You have 4 shots. Specify depth charge
        explosion point with a trio of numbers (distance north, 
        east, and  depth from surface).
        GOOD LUCK !



        Depth Charge: 1
          Enter coordinates (N,E,D) : 5,5,5
           Sonar reports shot was: East and Shallow

        Depth Charge: 2
          Enter coordinates (N,E,D) : 5,3,7
           Sonar reports shot was: East and Shallow

        Depth Charge: 3
          Enter coordinates (N,E,D) : 5,1,8
           Sonar reports shot was: Shallow

        Depth Charge: 4
          Enter coordinates (N,E,D) : 5,1,9


          ____                          
         | __ )  ___   ___  _ __ ___    
         |  _ \ / _ \ / _ \| '_ ` _ \   
         | |_) | (_) | (_) | | | | | |  
         |____/ \___/ \___/|_| |_| |_|  




        You see an eruption of oil and debris.
        As you watch you see what appears to be an enemy
        submarine keel over and disappear benieth the waves...
        You found it in 4 tries! Congratulations!

The code structure has been cleaned up a little, and the messages to the 
player have been converted into, as Hugh would say, "Tasteful dual case".

### April 07,2024

The cpp version has continued to be developed adding message files (generated
mostly by ChatGPT) to add some variety.  These are loaded and the strings picked
at random by two new routines. The program has also been commented a little better.

		DEPTH CHARGE GAME
		
		
		Search volume (side length): 20
		
		Captain, aboard the USS Digitalis, you embark on a mission of utmost
		importance: to eliminate the hostile submarine endangering our naval
		supremacy. Armed with just 5 depth charges, the odds may seem
		daunting, but your courage and skill will prevail. Navigate the
		waters with precision and specify the detonation coordinates using a
		trio of numbers: distance north, east, and depth from the surface.
		Victory awaits the bold. Good luck, Captain!
		
		
		
		
		
		Depth Charge: 1
		  Enter coordinates (N,E,D) : 
		    Depth charge WILD!!! Red alert!!!
		
		    Depth charge explodes at N,E,D=(17,2,12)
		    Sonar reports shot was: North, West and Deep
		
		Depth Charge: 2
		  Enter coordinates (N,E,D) : 8,11,6 
		    Sonar reports shot was: North, East and Deep
		
		Depth Charge: 3
		  Enter coordinates (N,E,D) : 4,7,3
		    Sonar reports shot was: South, West and Shallow
		
		Depth Charge: 4
		  Enter coordinates (N,E,D) : 6,9,4
		    Sonar reports shot was: South, East and Depth OK
		
		Depth Charge: 5
		  Enter coordinates (N,E,D) : 7,8,4
		 _  __           ____                        
		| |/ /__ _      | __ )  ___   ___  _ __ ___  
		| ' // _` |_____|  _ \ / _ \ / _ \| '_ ` _ \ 
		| . \ (_| |_____| |_) | (_) | (_) | | | | | |
		|_|\_\__,_|     |____/ \___/ \___/|_| |_| |_|
		                                             
		
		
		
		
		You see an eruption of oil and debris.
		As you watch you see what appears to be an enemy
		submarine keel over and disappear benieth the waves...
		 
		
		
		You found it in 5 tries! Congratulations!
		
		
		Search volume (side length):

