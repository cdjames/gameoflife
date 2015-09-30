#ifndef GLIDER_HPP
#define GLIDER_HPP

#include <curses.h>
class Glider
{
private:
	static const int SIZE = 4;
	// int SIZE;
	int startX;
	int startY;
	int rowSize;
	int colSize;
	int currentCell[SIZE][SIZE];
	int newCell[SIZE][SIZE];
	int xMove;
	int yMove;
	int currentState;
	WINDOW * win;

	void initArrays();
	void clearNewArray();
	void clearCurrentArray();
	void updateCycle();
	void countNeighbors();
	void initWindow(int y, int x);

public:
	Glider();
	Glider(int x, int y);
	~Glider();
	bool drawCells();
};

#endif