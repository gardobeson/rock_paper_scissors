#include "gameIO.h"
#include "gameLogic.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#define NOMINMAX
#include <windows.h>

int main()
{
    int gameState{};

    //seeds rand
 
    srand((unsigned int)time(NULL));

    do
    {
        gameState = gameLogic();
    } 
    
    while (gameState != 0 );

    return 0; 
}