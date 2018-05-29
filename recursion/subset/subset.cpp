// [4,5,6] --> {} {4} {5} {6} {4,5} {4,6} {5,6} {4,5,6}
// subset of 3 = subset of 2 + new element ....
// recursion go from empty subset and add element in each step
// L1:             {}
// L2:           {}                      {4}
// L3:         {}  | {5}             {4} |{4,5}
// L4:   {}{} {}{6}| {5} {5,6}    {4} {4,6} | {4,5} {4,5,6}
// ...
// At each level, we add up something new deviated from the previous level. We stop whrn we have enough length
// All these features tell us it is recursion
// --> two new subsets are created by old subset added empty {} or add array[i]} recursively
// 
#include <iostream>
#include <vector>
using namespace std;

vector< vector<int>> ss;

void findSubSet(int * array, vector<int> v, int i, int N) // cannot use &v, because 2 new subsets are deviated from original subset -> just use copy, no reference 
{
	// return condition
	if (i > N)
	{
		ss.push_back(v);
		return;
	}
	
	// recursive in 2 directions
	// not adding array[i] i.e. adding empty {} to original subset
	findSubSet(array, v, i + 1, N);

	// adding array[i] to original subset
	v.push_back(array[i]);
	findSubSet(array, v, i + 1, N);

}

//-----------------------------------------------------------------
// List all the possibilities of sum of subsets in a set
// Input: {3, 5, 7}
// Output: 0, 3 , 5, 7
//         8, 10, 12, 
//         15
// Actually, we should look at it from LEVEL perpertive
// L1:      0,                 3
// L2:      0,  5             3,      8
// L3:    0, 7   5, 12       3, 10,  8, 15
// 
// At each level, we add up something new deviated from the previous level ({} and new element). We stop when we have no elements left to add up.
// All these features tell us it is recursion. --> two new sums are created by old sum added by 0 {} or add array[i]} recursively

vector<int> sumVec;
void sumSubSet(vector<int>& array, int sum, int i, int N)
{
	if (i >= N)
	{
		sumVec.push_back(sum);
		return;
	}

	sumSubSet(array, sum,            i + 1, N);
	sumSubSet(array, sum + array[i], i + 1, N);

}

void findSumSubSet(vector<int> &array)
{
	sumSubSet(array, 0, 0, array.size());
}
//-----------------------------------------------------------------

int main()
{
	int array[] = { 3,5,7 };
	int N = sizeof(array) / sizeof(array[0]);

	// subsets
	vector<int> v;
	findSubSet(array, v, 0, N - 1);

	for (auto v : ss) {
		std::cout << "{";
		for (auto i : v) { std::cout << i << " ,"; }
		std::cout << "} - ";
	}
	std::cout << std::endl << std::endl;


	// sum of subsets
	vector<int> arr{ 3,5,7 };
	findSumSubSet(arr);

	std::cout << "Sum of subset: " << std::endl;
	for (int i : sumVec)
		std::cout << i << ", ";
	std::cout << std::endl;

	return 0;
}