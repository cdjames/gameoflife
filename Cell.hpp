#ifndef CELL_HPP
#define CELL_HPP

#include <curses.h>
class Cell
{
protected:
	// static const int SIZE = 4;
	int SIZE;
	int startX;
	int startY;
	int rowSize;
	int colSize;
	// int currentCell[SIZE][SIZE];
	// int newCell[SIZE][SIZE];
	int** currentCell;
	int** newCell;
	int xMove;
	int yMove;
	int currentState;
	WINDOW * win;

	void clearNewArray();
	void clearCurrentArray();
	void countNeighbors();
	// void updateCycle();
	
public:
	Cell();
	Cell(int x, int y, int size);
	~Cell();
	void initWindow(int y, int x);
};

#endif