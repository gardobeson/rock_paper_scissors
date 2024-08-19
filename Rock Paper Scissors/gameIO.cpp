#include "gameIO.h"
#include "gameLogic.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#define NOMINMAX
#include <windows.h>

//IO functions for getting positions from player and CPU

char getPositionPlayer()
{
	char positionPlayer{};
	std::cin >> positionPlayer;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return positionPlayer;
}

char getPositionCPU()
{
	char positions[3] = { 'r','p','s' };
	int randomPick = rand() % 3;
	char positionCPU{};
	positionCPU = positions[randomPick];


	return positionCPU;
}

void loadingSpinner(int spinSeconds)
 {
		static char const spinChars[] = "/-\\|";
		unsigned long i, numIterations = (static_cast<unsigned long>(spinSeconds) * 10);
		for (i = 0; i < numIterations; ++i) {
			putchar(spinChars[i % sizeof(spinChars)]);
			fflush(stdout);
			Sleep(50);
			putchar('\b');
		}
	}
   