/*********************************************************************
** Author: Collin James
** Date: 
** Description: 
*********************************************************************/

#include <iostream>
#include <iomanip>
#include "Oscillator.hpp"
#include <curses.h>
#include <stdlib.h>

int main()
{
	char ch;

	// initscr();			/* Start curses mode 		  */
	// timeout(500); // wait for user input then go to next call
	// noecho(); // don't print user input
	// printw("Press 'q' to quit.");	/* Print Hello World		  */
	// refresh();			/* Print it on to the real screen */

	Oscillator myOsc(10, 10); // starts drawing
	
	do
	{
		myOsc.drawCells();
	} while ((ch = getch()) != 'q');

	endwin();			/* End curses mode		  */

	return 0;
}
