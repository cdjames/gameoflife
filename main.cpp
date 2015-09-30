/*********************************************************************
** Author: Collin James
** Date: 
** Description: 
*********************************************************************/

#include <iostream>
#include "Oscillator.hpp"
#include "Glider.hpp"
#include <curses.h>
// #include <stdlib.h>
void getUserPrefs(char &pref, int &x, int &y);

int main()
{
	char prefs, ch;
	int x=0, y=0;
	Oscillator* myOsc;
	// myOsc = new Oscillator(x, y, 3);
	Glider* myGlider;
	// myGlider = new Glider(x, y, 4);

	getUserPrefs(prefs, x, y);

	if(prefs == 'o') 
	{
		myOsc = new Oscillator(x, y, 3);
		myOsc->initWindow(2, 0);		// starts ncurses mode and draws box
	}
		
	if(prefs == 'g') 
	{
		myGlider = new Glider(x, y, 4);
		myGlider->initWindow(2, 0);	// starts ncurses mode and draws box
	}
	
	do
	{
		if(prefs == 'o')
			myOsc->drawCells();
		if(prefs == 'g')
			myGlider->drawCells(); // draws the cell
	} while ((ch = getch()) != 'q'); // loop until the user enters 'q'
	// for (int i = 0; i < 3; i++) // for testing
		// myOsc.drawCells(); // draws the cell
	// sleep(10);

	delete myOsc; 
	delete myGlider; 
	myOsc = 0;
	myGlider = 0;

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