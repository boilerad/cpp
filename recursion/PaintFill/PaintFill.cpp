/*
Input is a matrix with 0s and 1s. 1s are the edge of a closed shape.
Task: Fill ‘1’ inside a closed shape, given the center of the shape is also the center of the matrix
*/

#include <iostream>
#include <vector>
using namespace std;

void fill(vector < vector<int> > &matrix, int row, int col)
{
	// using recursion to fill 1 from center, return when hit 1
	if (matrix[row][col])
		return;
	matrix[row][col] = 1;
	fill(matrix, row + 1, col);
	fill(matrix, row - 1, col);
	fill(matrix, row, col + 1);
	fill(matrix, row, col - 1);

}

vector < vector<int> > fillShape( vector <vector<int>> matrix) {

	int row = matrix.size() / 2;
	int col = matrix[0].size() / 2;

	fill(matrix, row, col); // recursion
	return matrix;
}

void printMatrix(vector <vector<int>> &matrix)
{
	for (auto v : matrix) {
		for (auto i : v)
			cout << i << " ";
		cout << endl;
	}
}

int main()
{
	vector <vector<int>> matrix;	
	matrix.emplace_back(vector<int>{0, 0, 0, 0, 0, 0, 0, 0});
	matrix.emplace_back(vector<int>{0, 1, 1, 1, 1, 1, 1, 0});
	matrix.emplace_back(vector<int>{0, 1, 0, 0, 0, 0, 1, 0});
	matrix.emplace_back(vector<int>{0, 1, 0, 0, 0, 1, 0, 0});
	matrix.emplace_back(vector<int>{0, 0, 1, 0, 0, 1, 0, 0});
	matrix.emplace_back(vector<int>{0, 1, 0, 0, 0, 0, 1, 0});
	matrix.emplace_back(vector<int>{0, 1, 1, 0, 0, 1, 1, 0});
	matrix.emplace_back(vector<int>{0, 0, 0, 1, 1, 0, 0, 0});

	vector <vector<int>> matrix_out = fillShape(matrix);

	printMatrix(matrix);

	cout << "\n\n";

	printMatrix(matrix_out);
		
	return 1;
}
