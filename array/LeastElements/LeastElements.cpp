/*
You are given coins of different denominations and a total amount of money amount.Write a function to compute the fewest number of coins that you need to make up that amount.
If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2 :
	coins = [2], amount = 3
	return -1.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< vector<int>> ss;

void findElementSet(int * array, vector<int> v, int remainder , int N) // cannot use &v, because 2 new subsets are deviated from original subset -> just use copy, no reference 
{
	if (remainder == 0)
	{
		ss.push_back(v);
		return;
	}

	if (remainder < 0)
		return;


	// not adding array[i] or adding empty {} to original subset
	for (int i = 0; i < N; i++) {
		vector<int> temp(v);
		temp.push_back(array[i]);
		findElementSet(array, temp, remainder - array[i], N);
	}
}

bool compare_size( vector<int> v1, vector<int> v2 )
{
	return v1.size() < v2.size();
}


int main()
{
	int array[] = { 5, 1 };


	int N = sizeof(array) / sizeof(array[0]);

	int remainder = 16;

	vector<int> v;
	findElementSet(array, v, remainder, N);

	for (auto v : ss) {
		for (auto i : v) { std::cout << i << ","; }
		std::cout << std::endl;
	}

	if (ss.empty())
		std::cout << "-1" << std::endl;

	// finished here

	//=====================================================================
	//						remove identical vectors
	//=====================================================================
	std::cout << "\n\n-------- sorting by size ----------\n\n" << std::endl;
	std::sort(ss.begin(), ss.end(), compare_size);
	for (auto it = ss.begin(); it!= ss.end(); it++)
	{
		auto v = *it;
		std::sort(v.begin(), v.end(), [](int x, int y) {return x < y; });
		*it = v;
	}

	for (auto v : ss) {
		for (auto i : v) { std::cout << i << ","; }
		std::cout << std::endl;

	}

	vector<int> removedIndex;
	vector< vector<int>> ss_norepeat;

	int i;
	for (i = 0; i < ss.size() -1; i++)
	{

		if (ss[i].size() < ss[i + 1].size()) {
			ss_norepeat.push_back(ss[i]);
				continue;
		}
		int j;
		for (j = 0; j < ss[i].size(); j++)
		{
			if (ss[i][j] !=  ss[i+1][j])
			{
				ss_norepeat.push_back(ss[i]);
				break;
			}
		}
		
		if (j == ss[i].size())
			removedIndex.push_back(i+1);
	
	}
	if( ss[i].size() > ss[i - 1].size())
		ss_norepeat.push_back(ss[i]);


	std::cout << "\n\n---------------------\n\n" << std::endl;

	std::cout << "\n Remove index:: " << std::endl;
	for (auto i : removedIndex)
		std::cout << i << ",";
	std::cout << std::endl;

	for (auto v : ss_norepeat) {
		for (auto i : v) { std::cout << i << ","; }
		std::cout << std::endl;
	}

	return 0;
}