#ifndef OSCILLATOR_HPP
#define OSCILLATOR_HPP

class Oscillator
{
private:
	static const int SIZE = 3;

	int startX;
	int startY;
	int rowSize;
	int colSize;
	int currentCell[3][3];
	int newCell[3][3];

	int getState();
	

public:
	Oscillator();
	Oscillator(int x, int y);
	void initialState();
	void countNeighbors();
	bool drawCells();
	void updateCycle();
};

#endif