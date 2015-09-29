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
	WINDOW * win;

	void initArrays();
	void clearNewArray();
	int getState();
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