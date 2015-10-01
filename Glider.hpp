#ifndef GLIDER_HPP
#define GLIDER_HPP

#include "Cell.hpp"
#include <curses.h>
class Glider: public Cell
{
private:
	void initArrays();
	void updateCycle();
	
public:
	Glider();
	Glider(int x, int y, int size);
	~Glider();
	bool drawCells();
};

#endif