// [4,5,6] --> {} {4} {5} {6} {4,5} {4,6} {5,6} {4,5,6}
// subset of 3 = subset of 2 + new element ....
// recursion go from empty subset and add element in each step
// notice :             {}
//          {}                      {4}
//          {}  | {5}             {4} |{4,5}
//    {}{} {}{6}| {5} {5,6}    {4} {4,6} | {4,5} {4,5,6}
//
//  --> two new subsets are created by old subset added empty {} recursively or add array[i]} recursively
// 
#include <iostream>
#include <vector>
using namespace std;

vector< vector<int>> ss;

void findSubSet(int * array, vector<int> v, int i, int N) // cannot use &v, because 2 new subsets are deviated from original subset -> just use copy, no reference 
{
	if (i > N)
	{
		ss.push_back(v);
		return;
	}
	// recursive in 2 directions

	// not adding array[i] or adding empty {} to original subset
	findSubSet(array, v,  i + 1, N);
	
	// adding array[i] to original subset
	v.push_back(array[i]);
	findSubSet(array, v, i + 1, N);

}

//-----------------------------------------------------------------
vector<int> sumVec;
void sumSubSet(int * array, int sum, int i, int N)
{
	if (i > N)
	{
		sumVec.push_back(sum);
		return;
	}

	sumSubSet(array, sum           , i + 1, N);
	sumSubSet(array, sum + array[i], i + 1, N);

}


int main()
{
	int array[] = { 3,5,7 };
	int N = sizeof(array) / sizeof(array[0]);

	// subsets
	vector<int> v;
	findSubSet(array, v,  0, N-1);

	for(auto v : ss){
		std::cout << "{";
		for (auto i : v) { std::cout << i << " ,"; }
		std::cout << "} - ";
	}
	std::cout << std::endl << std::endl;
	

	// sum of subsets
	sumSubSet(array, 0, 0, N-1);
	
	std::cout << "Sum of subset: " <<std::endl;
	for(int i : sumVec)
		std::cout << i << ", ";
	std::cout << std::endl;
		
	return 0;
 }
 
 
 