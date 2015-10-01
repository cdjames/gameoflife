#include "Cell.hpp"
#include <iostream>
#include <curses.h>

Cell::Cell()
{
	rowSize = colSize = SIZE = 3;
	currentCell = new int* [SIZE];
	newCell = new int *[SIZE];
	for( int i = 0 ; i < SIZE ; i++ ){
		currentCell[i] = new int[SIZE];
		newCell[i] = new int[SIZE];
	}
	startX = startY = xMove = yMove = 0;
	currentState = 1;
}

Cell::Cell(int x, int y, int size) // need to change elsewhere
{
	rowSize = colSize = SIZE = size;
	currentCell = new int* [SIZE];
	newCell = new int *[SIZE];
	for( int i = 0 ; i < SIZE ; i++ ){
		currentCell[i] = new int[SIZE];
		newCell[i] = new int[SIZE];
	}
	startX = x;
	startY = y;
	xMove = yMove = 0;
	currentState = 1;
}

Cell::~Cell()
{
	for( int i = 0 ; i < SIZE ; i++ ){
		delete [] currentCell[i];
		delete [] newCell[i];
		currentCell[i] = 0;
		newCell[i] = 0;
	}
	delete [] currentCell;
	delete [] newCell;
	currentCell = 0;
	newCell = 0;
	delwin(win);	// delete the window
	endwin();		// End curses mode
}

/*********************************************************************
** Description: 
** Put all 0s into new cell array
*********************************************************************/
void Cell::clearNewArray() 
{
	// int size = currentCell.size();
	for (int i = 0; i < SIZE; i++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			newCell[i][x] = 0;
		}
	}
}

void Cell::clearCurrentArray() 
{
	// int size = currentCell.size();
	for (int i = 0; i < SIZE; i++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			currentCell[i][x] = 0;
		}
	}
}

// void Cell::updateCycle(){}

/*********************************************************************
** Description: 
** This is the main algorithm. Loop through both dimensions of array
** and check neighbors of each cell. Rules are: 
1.	If an occupied cell has zero or one neighbor, it dies of loneliness. 
2.	If an occupied cell has more than three neighbors, it dies of overcrowding. 
3.	If an empty cell has exactly three occupied neighbor cells, there is a birth of a new cell
to replace the empty cell. 
4.	Births and deaths are instantaneous and occur at the changes of generation.
*********************************************************************/
void Cell::countNeighbors() 
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			int count = 0;

			if(i < SIZE-1) { // count when i is 0 or 1
				if( x < SIZE-1) // count when x is 0 or 1
					count += currentCell[i+1][x+1];

				if (x > 0) // count when x is 1 or 2
					count += currentCell[i+1][x-1];
				
				count += currentCell[i+1][x]; // always count
			}

			if (i > 0) // count when i is 1 or 2
			{
				if( x < SIZE-1) // count when x is 0 or 1
					count += currentCell[i-1][x+1];
				if (x > 0) // count when x is 1 or 2
					count += currentCell[i-1][x-1];

				count += currentCell[i-1][x]; // always count
			}

			// count when i is 0, 1, and 2
			if( x < SIZE-1) // and x is 0 or 1
				count += currentCell[i][x+1];

			if (x > 0) // and x is 1 or 2
				count += currentCell[i][x-1];
			
			// std::cout << "i" << i << " x" << x << " count = " << count << std::endl;

			/* now copy into new cell */
			if (count <= 1 || count > 3)
				newCell[i][x] = 0; // kill cell
			else if (count == 3)
				newCell[i][x] = 1; // birth new cell
			else
				newCell[i][x] = currentCell[i][x];
		}	
	}

	// updateCycle(); // copy new cells into 1st generation; clear new array
}

void Cell::initWindow(int y, int x)
{
	initscr();					// Start curses mode
	win = newwin(20, 40, y, x); // make a new window
	timeout(200); 				// wait for user input then go to next getch() call
	noecho(); 					// don't print user input
	curs_set(0);				// make cursor invisible if possible
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