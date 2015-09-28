#ifndef OSCILLATOR_HPP
#define OSCILLATOR_HPP

#include <curses.h>
class Oscillator
{
private:
	static const int SIZE = 3;

	int startX;
	int startY;
	int rowSize;
	int colSize;
	int currentCell[3][3];
	int newCell[3][3];

	void initialState();
	void newState();
	int getState();
	void updateCycle();
	void countNeighbors();

	WINDOW * win;

public:
	Oscillator();
	Oscillator(int x, int y);
	bool drawCells();
};

#endif