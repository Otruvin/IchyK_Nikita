#pragma once

class ConsoleAdapter
{
public:
	void setWindowSize(int windowWidth, int windowHeight);
	void setWindowTitle();
	static void setScreenColor(int color, int windowWidth, int windowHeight);
	static void setCursorPosition(int x, int y);
	static void setTextColor(int color);
	void setCursorVisability(bool visible);
	void initMainMenu();
};
