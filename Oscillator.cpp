#include "Oscillator.hpp"
#include <iostream>

Oscillator::Oscillator()
{
	rowSize = colSize = SIZE;
	startX = startY = 0;
	initialState();
}

Oscillator::Oscillator(int x, int y)
{
	rowSize = colSize = SIZE;
	startX = x;
	startY = y;
	initialState();
}

void Oscillator::initialState() 
{
	// int size = currentCell.size();
	for (int i = 0; i < SIZE; i++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			if (i == 1)
				currentCell[i][x] = 1;
			else
				currentCell[i][x] = 0;

			newCell[i][x] = 0;
		}
	}
}

void Oscillator::newState() 
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

int Oscillator::getState()
{

}

void Oscillator::countNeighbors() 
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
			
			std::cout << "i" << i << " x" << x << " count = " << count << std::endl;

			/* now copy into new cell */
			if (count <= 1 || count > 3)
				newCell[i][x] = 0; // kill cell
			else if (count == 3)
				newCell[i][x] = 1; // birth new cell
			else
				newCell[i][x] = currentCell[i][x];
		}	
	}
}

bool Oscillator::drawCells() 
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			std::cout << currentCell[i][x] << std::endl;
		}
	}
	countNeighbors();

	updateCycle();
}

void Oscillator::updateCycle() 
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			currentCell[i][x] = newCell[i][x];
		}
	}
			
	newState();
}