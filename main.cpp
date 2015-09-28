/*********************************************************************
** Author: Collin James
** Date: 
** Description: 
*********************************************************************/

#include <iostream>
#include <iomanip>
#include "Oscillator.hpp"
#include <curses.h>
// #include <stdlib.h>
void getUserPrefs(char &pref, int &x, int &y);

int main()
{
	char pref, ch;
	int x, y;
	getUserPrefs(ch, x, y);

	Oscillator myOsc(y, x); // starts ncurses mode and draws box
	
	do
	{
		myOsc.drawCells(); // draws the cell
	} while ((ch = getch()) != 'q');

	return 0;
}

void getUserPrefs(char &pref, int &x, int &y)
{
	std::cout 	<< "What kind of cell to start with? 'o' for Oscillator, 'g' for Glider, 'c' for Gun"
				<< std::endl;
	do
		std::cin >> pref;
	while (pref != 'o' && pref != 'g' && pref != 'c');

	std::cout	<< "Choose x/y coordinates for cell. X range is between 0 and 37. Y is between 0 and 17.\n"
				<< "Choose x" << std::endl;
	std::cin >> x;
	std::cout 	<< "Choose y" << std::endl;
	std::cin >> y;
}