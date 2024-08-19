#include "gameIO.h"
#include "gameLogic.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#define NOMINMAX
#include <windows.h>

char cpuPosition{};
char playerPosition{};
int winCase{};
int playerScore{ 0 };
int cpuScore{ 0 };
int matchCounter{ 0 };
int gameState{ 1 };

int gameLogic()
{
    //get CPU position first to avoid memory loads

    cpuPosition = getPositionCPU();

    //calls function to display progress bar, inserts line breaking up the rounds

    loadingSpinner(2);
    std::cout << "===============NEW ROUND===============\n";

    //get player position, state round number and score

    //std::cout << "Current round is: " << matchCounter << '\n';
    std::cout << "Player: " << playerScore << "   ||    CPU: " << cpuScore << '\n';
    std::cout << "Player enter position: ";
    playerPosition = getPositionPlayer();

    //evaluate the relative positions of the CPU and the player

    if (playerPosition == 'x')
    {
        winCase = 4;
    }

    else if ((playerPosition == 'r') ||
        (playerPosition == 'p') ||
        (playerPosition == 's'))
    {

        //state CPUs and player positions and evaluate

        std::cout << "Your position is: " << playerPosition << '\n';
        std::cout << "The CPUs position is: " << cpuPosition << '\n';

        if ((playerPosition == 'r' && cpuPosition == 's') ||
            (playerPosition == 's' && cpuPosition == 'p') ||
            (playerPosition == 'p' && cpuPosition == 'r'))
        {
            winCase = 1;
        }

        else if ((playerPosition == 's' && cpuPosition == 'r') ||
            (playerPosition == 'p' && cpuPosition == 's') ||
            (playerPosition == 'r' && cpuPosition == 'p'))
        {
            winCase = 2;
        }

        else
        {
            winCase = 3;
        }

    }
    else
    {
        winCase = 5;
    }

    switch (winCase) {
    case 1:
        std::cout << "Player Wins!\n";
        playerScore++;
        matchCounter++;
        gameState = 1;
        break;
    case 2:
        std::cout << "Player Loses :(\n";
        cpuScore++;
        matchCounter++;
        gameState = 1;
        break;
    case 3:
        std::cout << "Player Ties\n";
        matchCounter++;
        gameState = 1;
        break;
    case 4:
        std::cout << "Game Over\n";
        gameState = 0;
        break;
    case 5:
        std::cout << "Invalid Entry\n";
        gameState = 1;
        break;
    }
    return gameState;
}