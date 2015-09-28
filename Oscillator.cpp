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
		}
	}
}

void Oscillator::countNeighbors() 
{
	// for (int i = 0; i < SIZE; i++)
	// {
	// 	for (int x = 0; x < SIZE; x++)
	// 	{
	// 		int count = 0;

	// 		if(x)

	// 	}	
	// }
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
}
void Oscillator::updateCycle() {}