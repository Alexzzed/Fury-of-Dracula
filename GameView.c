// GameView.c ... GameView ADT implementation

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Globals.h"
#include "Game.h"
#include "GameView.h"
#include <string.c>
#include "Map.h"
     
struct gameView {
    char* pastPlays;
    int trails[NUM_PLAYERS][TRAIL_SIZE];
};
     
static void updateTrail(GameView gameView, PlayerID p, LocationID location){
	int i = TRAIL_SIZE - 2;
	while (i >= 0) {
	   gameView->trails[p][i+1] = gameView->trails[p][i];
       i--;	   		
	}
	gameView->trails[p][0] = location;
}

// Creates a new GameView to summarise the current state of the game
GameView newGameView(char *pastPlays, PlayerMessage messages[])
{
    GameView gameView = malloc(sizeof(struct gameView));
    gameView->pastPlays=strdup(pastPlays);
    
    int i = 0;
    int j = 0;
    while (i < NUM_PLAYER) {
       while (j < TRAIL_SIZE){
          gameView->trails[i][j] = UNKNOWN_LOCATION;
          j++;
       }
       i++;
    }
    
    return gameView;
}
     
     
// Frees all memory previously allocated for the GameView toBeDeleted
void disposeGameView(GameView toBeDeleted)
{
    free( toBeDeleted );
}


//// Functions to return simple information about the current state of the game

// Get the current round
Round getRound(GameView currentView)
{
    int turn = (strlen (currentView->pastPlays) + 1) / 8;
    int roun = turn / 5;
    return roun;
}

// Get the id of current player - ie whose turn is it?
PlayerID getCurrentPlayer(GameView currentView)
{
    int turn = (strlen (currentView->pastPlays) + 1) / 8;
    int currPlayer = turn % 5;
    return currPlayer;
}

// Get the current score
int getScore(GameView currentView)
{
    //REPLACE THIS WITH YOUR OWN IMPLEMENTATION
    return 0;
}

// Get the current health points for a given player
int getHealth(GameView currentView, PlayerID player)
{
    //REPLACE THIS WITH YOUR OWN IMPLEMENTATION
    return 0;
}

// Get the current location id of a given player
LocationID getLocation(GameView currentView, PlayerID player)
{
   // go through pastPlays
   int cur = 0;
   int strlen = strlen(pastPlays);
   while (cur < strlen) {
	   PlayerID p = 0;
	   switch (pastPlays[cur]) {
		 case G: p = PLAYER_LORD_GODALMING;
		 break;
           case S: p = PLAYER_DR_SEWARD;
           break;
           case H: p = PLAYER_VAN_HELSING;
           break;
           case M: p = PLAYER_MINA_HARKER;
           break;
           case D: p = PLAYER_DRACULA;
           break;
           default: break;		   
	   }
	   
	  char string[3] = {pastPlays[cur + 1], pastPlays[cur + 2], '\0'};
      	 if (p == PLAYER_DRACULA) {
			 if (!strcmp("C?", string)) {
				 updateTrail(gameView, p, CITY_UNKNOWN);
		      } else if (!strcmp("S?", string)) {
				 updateTrail(gameView, p, SEA_UNKNOWN);
			 } else if (!strcmp("HI", string)) {
				 updateTrail(gameView, p, HIDE);
			 } else if (!strcmp("D1", string)) {
				 updateTrail(gameView, p, DOUBLE_BACK_1);
			 } else if (!strcmp("D2", string)) {
				 updateTrail(gameView, p, DOUBLE_BACK_2);
			 } else if (!strcmp("D3", string)) {
				 updateTrail(gameView, p, DOUBLE_BACK_3);
			 } else if (!strcmp("D4", string)) {
				 updateTrail(gameView, p, DOUBLE_BACK_4);
			 } else if (!strcmp("D5", string)) {
				 updateTrail(gameView, p, DOUBLE_BACK_5);
			 } else if (!strcmp("TP", string)) {
				 updateTrail(gameView, p, TELEPORT);
			 }				 
		 } else {
			 updateTrail(gameView, p, abbrevToID(string)); //in place.c
		 }  
   }
        
    return currentView->trails[player][0];// go through pastPlays
  
}

//// Functions that return information about the history of the game

// Fills the trail array with the location ids of the last 6 turns
void getHistory(GameView currentView, PlayerID player,
                            LocationID trail[TRAIL_SIZE])
{
    int roun = getRound (currentView);
    if ((roun * NUM_PLAYERS + player + 1) * 8 <= strlen (currentView->pastPlays) + 1) roun ++;
    int start = ((roun - 6) * NUM_PLAYERS + player) * 8;
    for (int counter = 6; counter > 0; counter --) {
       char locationCode[2];
       locationCode[0] = currentView->pastPlays[start + 1];
       locationCode[1] = currentView->pastPlays[start + 2];
       trail[counter - 1] = abbrevToID (locationCode);
       start += (NUM_PLAYERS * 8);
    }
}

//// Functions that query the map to find information about connectivity

// Returns an array of LocationIDs for all directly connected locations

LocationID *connectedLocations(GameView currentView, int *numLocations,
                               LocationID from, PlayerID player, Round round,
                               int road, int rail, int sea)
{
    //REPLACE THIS WITH YOUR OWN IMPLEMENTATION
    return NULL;
}
