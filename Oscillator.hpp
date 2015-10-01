#ifndef OSCILLATOR_HPP
#define OSCILLATOR_HPP

#include "Cell.hpp"
#include <curses.h>
class Oscillator: public Cell
{
private:
	void initArrays();
	void updateCycle();

public:
	Oscillator();
	Oscillator(int x, int y, int size);
	~Oscillator();
	bool drawCells();
};

#endif