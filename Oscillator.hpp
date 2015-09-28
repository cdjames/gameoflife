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
	WINDOW * win;

	void initArrays();
	void clearNewArray();
	int getState();
	void updateCycle();
	void countNeighbors();
	void initWindow(int y, int x);

public:
	Oscillator();
	Oscillator(int x, int y);
	~Oscillator();
	bool drawCells();
};

#endif