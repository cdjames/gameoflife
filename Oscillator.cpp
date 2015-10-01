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

void Oscillator::initWindow(int y, int x)
{
	initscr();					// Start curses mode
	win = newwin(20, 40, y, x); // make a new window
	timeout(500); 				// wait for user input then go to next getch() call
	noecho(); 					// don't print user input
	printw("Press 'q' to quit.");	// instructions at top of screen
	refresh();					// put the printw on the screen

	/* create a 40 x 20 "window" */
	for (int i = 0; i < 20; i++)
	{
		for (int x = 0; x < 40; x++)
		{
			mvwaddch(win, i, x, '-');	// move and add a character to the coords
		}
	}
	wrefresh(win);	// draw the window
}