/*
Eight Queens: Write an algorithm to print all ways of arranging eight queens on an 8x8 chess board
so that none of them share the same row, column, or diagonal. In this case, "diagonal" means all
diagonals, not just the two that bisect the board.

L1:   1  2
L2:  12  13  16  18 
L3: 121  124 127  
 ...

 when a problem can be divided into different levels, first level is connected to many possibilities in L2. 
 1 element in L2 is then connected to many options in L3 ... and this stops at the last level. The output got bigger and bigger when adding one more level
 We know this is recursion.
*/

#include <iostream>
#include <vector>
using namespace std;

#define SIZE 8
vector<vector<int>> cols;  // store outputs, colums[row] = col whereas matrix[row][c] != 0, if c == col, 
						   //   									   matrix[row][c] == 0, if c != col
                           //                                                                  row = 0,..,SIZE

bool isValid(int r, int c, vector<int>& columns);

void placeQueen(int row, vector<int> & columns)  // reference also works, deep copy also works, in fact deep copy is safer when we are not sure how different possibilities relate to ones another
{
	// return condition
	if (row == SIZE)
	{
		for (auto col : cols)
			if (col == columns) return;  // no need to store a duplicate
		
		cols.push_back( columns );
		return;
	}

	// for each column in row "row", explore all possibilities and add it as a viable output if the position (row, col) is valid 
	for (int col = 0; col < SIZE; col++)  
	{

		if (isValid(row, col, columns)) { // if it a valid row, col then add it to a possibile output and go deeper to the next level in recursion. 
			columns[row] = col;           // Notice no break here, we always explore column 0,...,SIZE no matter what
			placeQueen(row + 1, columns);
		}
	}
}

// check if (row, col) is valid by looing at its columns and diaginals
bool isValid(int r, int c, vector<int> &columns)
{
	for (int i = 0; i < r; i++)                               //just need to check uppper level row = 0 to r because r+1 isn't explored yet
	{
		if (c == columns[i]) return false;                    // same column
		if (abs(i - r) == abs(c - columns[i])) return false;  // same diagonal 
	}
	return true;
}


int main()
{
	
	vector<int> columns{ -1,-1,-1,-1,-1,-1,-1,-1 };   // columns is store valid row r, colmn col; can use int* columns instead of vector and copy.
	placeQueen(0, columns);


	// print all outputs
	for (auto v : cols)
	{
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++)
				std::cout << (v[i] == j ? "x " : "_ ");
			std::cout << std::endl;
		}
		std::cout << std::endl << std::endl;
	}
	return 1;
}