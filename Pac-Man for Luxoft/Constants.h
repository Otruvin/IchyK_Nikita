#pragma once
#include <Windows.h>

namespace Constants
{
	enum colors
	{
	
		COLOR_TEXT = FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN,
		COLOR_TABLETS = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
		COLOR_PAC_MAN = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
		COLOR_PINKY = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN,
		COLOR_BLINKY = FOREGROUND_RED | BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN,
		COLOR_INKY = FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN,
		COLOR_CLYDE = FOREGROUND_RED | FOREGROUND_GREEN
	};

	enum size
	{
		WINDOW_HEIGHT = 20,
	    WINDOW_WIDTH = 100,
		WINDOW_HEIGHT_FOR_GAME = 40,
		WINDOW_WIDTH_FOR_GAME = 60,
		MAP_HEIGHT = 31,
		MAP_WIDTH = 28,
		NUM_LEVELS = 256
	};

	const int MAP1[Constants::MAP_HEIGHT][Constants::MAP_WIDTH] = {
		{5, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 11, 11, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 6},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 5, 9, 9, 6, 0, 5, 9, 9, 9, 6, 0, 1, 1, 0, 5, 9, 9, 9, 6, 0, 5, 9, 9, 6, 0, 1},
		{1, 2, 1, 10, 10, 1, 0, 1, 10, 10, 10, 1, 0, 1, 1, 0, 1, 10, 10, 10, 1, 0, 1, 10, 10, 1, 2, 1},
		{1, 0, 8, 9, 9, 7, 0, 8, 9, 9, 9, 7, 0, 8, 7, 0, 8, 9, 9, 9, 7, 0, 8, 9, 9, 7, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 5, 9, 9, 6, 0, 5, 6, 0, 5, 9, 9, 9, 9, 9, 9, 6, 0, 5, 6, 0, 5, 9, 9, 6, 0, 1},
		{1, 0, 8, 9, 9, 7, 0, 1, 1, 0, 8, 9, 9, 6, 5, 9, 9, 7, 0, 1, 1, 0, 8, 9, 9, 7, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
		{14, 9, 9, 9, 9, 6, 0, 1, 8, 9, 9, 6, 3, 1, 1, 3, 5, 9, 9, 7, 1, 0, 5, 9, 9, 9, 9, 13},
		{1, 10, 10, 10, 10, 1, 0, 1, 5, 9, 9, 7, 3, 8, 7, 3, 8, 9, 9, 6, 1, 0, 1, 10, 10, 10, 10, 1},
		{1, 10, 10, 10, 10, 1, 0, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 0, 1, 10, 10, 10, 10, 1},
		{1, 10, 10, 10, 10, 1, 0, 1, 1, 3, 5, 9, 9, 4, 4, 9, 9, 6, 3, 1, 1, 0, 1, 10, 10, 10, 10, 1},
		{8, 9, 9, 9, 9, 7, 0, 8, 7, 3, 1, 3, 3, 3, 3, 3, 3, 1, 3, 8, 7, 0, 8, 9, 9, 9, 9, 7},
		{16, 3, 3, 3, 3, 3, 0, 3, 3, 3, 1, 3, 3, 3, 3, 3, 3, 1, 3, 3, 3, 0, 3, 3, 3, 3, 3, 15},
		{5, 9, 9, 9, 9, 6, 0, 5, 6, 3, 1, 3, 3, 3, 3, 3, 3, 1, 3, 5, 6, 0, 5, 9, 9, 9, 9, 6},
		{1, 10, 10, 10, 10, 1, 0, 1, 1, 3, 8, 9, 9, 9, 9, 9, 9, 7, 3, 1, 1, 0, 1, 10, 10, 10, 10, 1},
		{1, 10, 10, 10, 10, 1, 0, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 0, 1, 10, 10, 10, 10, 1},
		{1, 10, 10, 10, 10, 1, 0, 1, 1, 3, 5, 9, 9, 9, 9, 9, 9, 6, 3, 1, 1, 0, 1, 10, 10, 10, 10, 1},
		{14, 9, 9, 9, 9, 7, 0, 8, 7, 3, 8, 9, 9, 6, 5, 9, 9, 7, 3, 8, 7, 0, 8, 9, 9, 9, 9, 13},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 5, 9, 9, 6, 0, 5, 9, 9, 9, 6, 0, 1, 1, 0, 5, 9, 9, 9, 6, 0, 5, 9, 9, 6, 0, 1},
		{1, 0, 8, 9, 6, 1, 0, 8, 9, 9, 9, 7, 0, 8, 7, 0, 8, 9, 9, 9, 7, 0, 1, 5, 9, 7, 0, 1},
		{1, 2, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 1},
		{14, 9, 6, 0, 1, 1, 0, 5, 6, 0, 5, 9, 9, 9, 9, 9, 9, 6, 0, 5, 6, 0, 1, 1, 0, 5, 9, 13},
		{14, 9, 7, 0, 8, 7, 0, 1, 1, 0, 8, 9, 9, 6, 5, 9, 9, 7, 0, 1, 1, 0, 8, 7, 0, 8, 9, 13},
		{1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 5, 9, 9, 9, 9, 7, 8, 9, 9, 6, 0, 1, 1, 0, 5, 9, 9, 7, 8, 9, 9, 9, 9, 6, 0, 1},
		{1, 0, 8, 9, 9, 9, 9, 9, 9, 9, 9, 7, 0, 8, 7, 0, 8, 9, 9, 9, 9, 9, 9, 9, 9, 7, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 7}
	};
}