#ifndef OSCILLATOR_HPP
#define OSCILLATOR_HPP

// #include "Cell.hpp"
#include <curses.h>
// class Oscillator: public Cell
class Oscillator
{
private:
	static const int SIZE = 3;
	// int SIZE;
	int startX;
	int startY;
	int rowSize;
	int colSize;
	int currentCell[SIZE][SIZE];
	int newCell[SIZE][SIZE];
	WINDOW * win;

	void initArrays();
	void clearNewArray();
	void updateCycle();
	void countNeighbors();

public:
	Oscillator();
	Oscillator(int x, int y);
	~Oscillator();
	void initWindow(int y, int x);
	bool drawCells();
};

#endif