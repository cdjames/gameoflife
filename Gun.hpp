#ifndef GUN_HPP
#define GUN_HPP

#include "Cell.hpp"
#include <curses.h>
class Gun: public Cell
{
private:
	void initArrays();
	void updateCycle();
	
public:
	Gun();
	Gun(int x, int y, int size);
	~Gun();
	bool drawCells();
};

#endif