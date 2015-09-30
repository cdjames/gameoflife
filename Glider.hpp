#ifndef GLIDER_HPP
#define GLIDER_HPP

#include "Cell.hpp"
#include <curses.h>
class Glider: public Cell
{
private:
	// static const int SIZE = 4;
	// // int SIZE;
	// int startX;
	// int startY;
	// int rowSize;
	// int colSize;
	// int currentCell[SIZE][SIZE];
	// int newCell[SIZE][SIZE];
	// int xMove;
	// int yMove;
	// int currentState;
	// WINDOW * win;

	void initArrays();
	// void clearNewArray();
	// void clearCurrentArray();
	void updateCycle();
	// void countNeighbors();
	
public:
	Glider();
	Glider(int x, int y, int size);
	~Glider();
	void initWindow(int y, int x);
	bool drawCells();
};

#endif