#include "Oscillator.hpp"
// #include "Cell.hpp"
#include <iostream>
#include <curses.h>

Oscillator::Oscillator(): Cell() {}

Oscillator::Oscillator(int y, int x, int size): Cell (y, x, size)
{
	initArrays();
}

Oscillator::~Oscillator()
{
	// delwin(win);	// delete the window
	// endwin();		/* End curses mode		  */
}

/*********************************************************************
** Description: 
** Sets up arrays
*********************************************************************/
void Oscillator::initArrays() 
{
	// int size = currentCell.size();
	for (int i = 0; i < SIZE; i++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			if (i == SIZE/2)
				currentCell[i][x] = 1;
			else
				currentCell[i][x] = 0;

			newCell[i][x] = 0;

			// std::cout << "i = " << i << ", x = " << x << std::endl;
			// std::cout << currentCell[i][x] << std::endl;
		}
	}
}

bool Oscillator::drawCells() 
{
	// initscr();
	char ch;
	for (int i = 0; i < SIZE; i++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			if(currentCell[i][x] == 0)
				ch = '-';
			else
				ch = '+';
			mvwaddch(win, i+startY, x+startX, ch); // put character on window		
			// std::cout << "i = " << i << ", x = " << x << std::endl;
			// std::cout << currentCell[i][x] << std::endl;
		}
	}
	wrefresh(win); // update the window

	Cell::countNeighbors(); // figure out next generation

	updateCycle(); // copy new cells into 1st generation; clear new array

}

/*********************************************************************
** Description: 
** copy the new cell into the main cell and clear the new cell
*********************************************************************/
void Oscillator::updateCycle() 
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			currentCell[i][x] = newCell[i][x];
		}
	}
			
	Cell::clearNewArray();
}