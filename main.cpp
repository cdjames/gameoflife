/*********************************************************************
** Author: Collin James
** Date: 
** Description: 
*********************************************************************/

#include <iostream>
#include <iomanip>
#include "Oscillator.hpp"

int main()
{
	Oscillator myOsc;
	// Oscillator myOsc2(1, 2);

	for (int i = 0; i < 3; i++)
	{
		myOsc.drawCells();
	}
	// myOsc.countNeighbors();
	// myOsc2.drawCells();

}
