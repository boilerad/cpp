/*
Robot in a Grid: Imagine a robot sitting on the upper left corner of grid with r rows and c columns.
The robot can only move in two directions, right and down, but certain cells are "off limits" such that
the robot cannot step on them. Design an algorithm to find a path for the robot from the top left to
the bottom right.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define SIZE 8

struct Point
{
	int r;
	int c;
};

vector< vector<Point>> paths;

void getPath(vector <vector<char>> &maze, int row, int col, vector<Point> path)
{
	if ( row < 0 || col < 0 || row >= SIZE || col >= SIZE || maze[row][col] == 'X')
		return;

	if (row == SIZE - 1 && col == SIZE - 1)    // get to the gate
	{
		path.emplace_back(Point{ row, col });  // add point
		paths.push_back(path);                 // add path
		return;
	}
	
	// recusrion
	path.emplace_back( Point{row, col} );      // adda valid point before going deeper to another level of recursion

	getPath(maze, row + 1, col, path);       // go down
		//getPath(maze, row - 1, col, path);
	getPath(maze, row, col + 1, path);       // go right
		//getPath(maze, row, col - 1, path);

}


void printMaze(vector <vector<char>> & maze)
{
	for (auto v : maze) {
		for (auto i : v)
			cout << i << " ";
		cout << endl;
	}
}

void printPath(vector <vector<char>>&maze, vector <vector<Point>> & paths)
{
	for(auto a_path: paths)
		std::sort(a_path.begin(), a_path.end(), [](Point x, Point y) {return x.r < y.r || (x.r == y.r &&  x.c < y.c); });

	for (auto a_path : paths) {
		// print a path in paths 
		auto a_maze = maze;
		for (auto point : a_path) {
			cout << "(" << point.r << "," << point.c << "), ";
			a_maze[point.r][point.c] = '|';
		}
		cout << "\n\n";
		printMaze(a_maze);
		cout << "\n\n\n";
	}
}

int main()
{
	vector <vector<char>> maze;
	maze.emplace_back(vector<char>{ ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X'});
	maze.emplace_back(vector<char>{ 'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X'});
	maze.emplace_back(vector<char>{ 'X', 'X', 'X', ' ', 'X', 'X', 'X', 'X'});
	maze.emplace_back(vector<char>{ 'X', ' ', 'X', ' ', ' ', 'X', ' ', 'X'});
	maze.emplace_back(vector<char>{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X'});
	maze.emplace_back(vector<char>{ 'X', 'X', 'X', 'X', ' ', 'X', ' ', 'X'});
	maze.emplace_back(vector<char>{ 'X', ' ', ' ', ' ', ' ', 'X', ' ', ' '});
	maze.emplace_back(vector<char>{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' '});
	
	
	vector<Point> path;
	getPath(maze, 0, 0, path);

	printMaze(maze);

	cout << "\n\n";

	printPath(maze, paths);

	return 1;
}

// Complexity: 
// If we walk through the algorithm, we'll see that we are visiting squares multiple times. In fact, we visit
// each square many, many times.After all, we have rc squares but we're doing O(2NC) work ==> exponential 
// 
// Tips: indor to reduce cost, we can just look at a point only once by recording its position if it's already visited.
// This method, however, will only guarantee one solution if viable solutions cross their paths