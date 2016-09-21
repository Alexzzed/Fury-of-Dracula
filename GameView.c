// GameView.c ... GameView ADT implementation

#include <stdlib.h>
#include <assert.h>
#include "Globals.h"
#include "Game.h"
#include "GameView.h"
#include <string.c>
#include "Map.h"
     
struct gameView {
    char* pastPlays;
};
     

// Creates a new GameView to summarise the current state of the game
GameView newGameView(char *pastPlays, PlayerMessage messages[])
{
    GameView gameView = malloc(sizeof(struct gameView));
    gameView->pastPlays=strdup(pastPlays);
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
    //REPLACE THIS WITH YOUR OWN IMPLEMENTATION
    return 0;
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
