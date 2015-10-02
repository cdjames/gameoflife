#include "Gun.hpp"
#include <iostream>
#include <curses.h>

Gun::Gun(): Cell() {}

Gun::Gun(int y, int x, int size): Cell (y, x, size)
{
	initArrays();
}

Gun::~Gun()
{
	// delwin(win);	// delete the window
	// endwin();		// End curses mode
}

/*********************************************************************
** Description: 
** Sets up arrays
*********************************************************************/
void Gun::initArrays() 
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int x = 0; x < SIZE; x++)
		{		// build the spaceship
			if (   (x == 1 && i == 5) // left square
				|| (x == 1 && i == 6) // 
				|| (x == 2 && i == 5) // 
				|| (x == 2 && i == 6) //
				|| (x == 35 && i == 3) // right square
				|| (x == 35 && i == 4) // 
				|| (x == 36 && i == 3) // 
				|| (x == 36 && i == 4) //
				|| (x == 11 && i == 5) // left ship
				|| (x == 11 && i == 6) // 
				|| (x == 11 && i == 7) // 
				|| (x == 12 && i == 4) // 
				|| (x == 12 && i == 8) // 
				|| (x == 13 && i == 3) // 
				|| (x == 13 && i == 9) // 
				|| (x == 14 && i == 3) // 
				|| (x == 14 && i == 9) // 
				|| (x == 15 && i == 6) // 
				|| (x == 16 && i == 4) // 
				|| (x == 16 && i == 8) // 
				|| (x == 17 && i == 5) // 
				|| (x == 17 && i == 6) // 
				|| (x == 17 && i == 7) // 
				|| (x == 18 && i == 6) // 
				|| (x == 21 && i == 3) // right ship
				|| (x == 21 && i == 4) // 
				|| (x == 21 && i == 5) // 
				|| (x == 22 && i == 3) // 
				|| (x == 22 && i == 4) // 
				|| (x == 22 && i == 5) // 
				|| (x == 23 && i == 2) // 
				|| (x == 23 && i == 6) // 
				|| (x == 25 && i == 1) // 
				|| (x == 25 && i == 2) // 
				|| (x == 25 && i == 6) // 
				|| (x == 25 && i == 7) // 
				)
			{
				currentCell[i][x] = 1;
			}
			else
				currentCell[i][x] = 0;

			// all newCells get 0
			newCell[i][x] = 0;

			// std::cout << "i = " << i << ", x = " << x << std::endl;
			// std::cout << currentCell[i][x] << std::endl;
		}
	}
}

bool Gun::drawCells() 
{
	char ch = '-';
	for (int i = 0; i < SIZE; i++)
	{
		// clear the previous cell area
		for (int x = 0; x < SIZE; x++)
			mvwaddch(win, (i + startY + yMove-1), (x + startX + xMove-1), ch);
	}
	wrefresh(win); // update the window
	for (int i = 0; i < SIZE; i++)
	{
		for (int x = 0; x < SIZE; x++)
		{	
			if(currentCell[i][x] == 1)
				ch = '+';
			else
				ch = '-';
			if(i != SIZE-1 && x != SIZE-1)
				mvwaddch(win, (i + startY + yMove), (x + startX + xMove), ch); // put character on window		
			// std::cout << "xMove = " << xMove << ", yMove = " << yMove << std::endl;
		}
	}
	// std::cout << "currentState=" << currentState << std::endl;
	wrefresh(win); // update the window

	Cell::countNeighbors(); // figure out next generation

	updateCycle(); // copy new cells into 1st generation; clear new array
}

/*********************************************************************
** Description: 
** copy the new cell into the main cell and clear the new cell
*********************************************************************/
void Gun::updateCycle() 
{
	bool moveX = false;
	bool moveY = false;
	// Cell::clearCurrentArray(); // all zeroes
	Cell::clearArray(currentCell);

	for (int i = 0; i < SIZE; i++)
	{
		for (int x = 0; x < SIZE; x++)
			currentCell[i][x] = newCell[i][x];				
	}

	if(currentState < 4)
		currentState++;
	else
		currentState = 1;

	// Cell::clearNewArray(); // all zeroes
	Cell::clearArray(newCell);
}