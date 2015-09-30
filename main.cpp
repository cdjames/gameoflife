/*********************************************************************
** Author: Collin James
** Date: 
** Description: 
*********************************************************************/

#include <iostream>
#include <iomanip>
#include "Oscillator.hpp"
#include "Glider.hpp"
#include <curses.h>
// #include <stdlib.h>
void getUserPrefs(char &pref, int &x, int &y);

int main()
{
	char prefs, ch;
	int x=0, y=0;
	// getUserPrefs(prefs, x, y);

	// Oscillator myOsc(x, y); // starts ncurses mode and draws box
	Glider myGlider(x, y);
	
	do
	{
		myGlider.drawCells(); // draws the cell
	} while ((ch = getch()) != 'q'); // loop until the user enters 'q'
	// for (int i = 0; i < 3; i++) // for testing
		// myOsc.drawCells(); // draws the cell
	// sleep(10);
	return 0;
}

/*********************************************************************
** Description: 
** Get the preference for type of cell, starting x and y
*********************************************************************/
void getUserPrefs(char &pref, int &x, int &y)
{
	std::cout 	<< "What kind of cell to start with? 'o' for Oscillator, 'g' for Glider, 'c' for Gun"
				<< std::endl;
	do
		std::cin >> pref;
	while (pref != 'o' && pref != 'g' && pref != 'c');

	std::cout	<< "Choose x/y coordinates for cell. \nViewable X range is between 0 and 37. Y is between 0 and 17.\n"
				<< "Choose x" << std::endl;
	std::cin >> x;
	std::cout 	<< "Choose y" << std::endl;
	std::cin >> y;
}

// void makeWindow()
// {
// 	initscr();					// Start curses mode
// 	win = newwin(20, 40, y, x); // make a new window
// 	timeout(500); 				// wait for user input then go to next getch() call
// 	noecho(); 					// don't print user input
// 	printw("Press 'q' to quit.");	// instructions at top of screen
// 	refresh();					// put the printw on the screen

// 	/* create a 40 x 20 "window" */
// 	for (int i = 0; i < 20; i++)
// 	{
// 		for (int x = 0; x < 40; x++)
// 		{
// 			mvwaddch(win, i, x, '-');	// move and add a character to the coords
// 		}
// 	}
// 	wrefresh(win);	// draw the window
// }