/*
Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"
Example 2:

Input: [3,30,34,5,9]
Output: "9534330"
Note: The result may be very large, so you need to return a string instead of an integer.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class Solution
{

public:
	std::string createLargestNum( int* array, int length ) 
	{
		if (!length) return "";
		if (length == 1) return std::to_string( array[0]);

		// sorting array using string comparison
		std::sort(array, array + length, compare);
		//std::vector<int> v(array, array + length);
		//std::sort(v.begin(), v.end(), compare);

		//concatinate to make a string
		std::string output_string = "";
		for (int i = 0; i < length; i++)
			output_string += std::to_string(array[i]);
		
		return output_string;
	}

	static bool compare(int a, int b) // 9 vs 13 -> 913 > 139 -> 9 > 13
	{
		return std::to_string(a) + std::to_string(b) > std::to_string(b) + std::to_string(a);
	}

};

int main()
{
	int arr[] = { 3, 30, 34, 5, 9 }; //{15, 3, 34, 30, 9, 7};
	for (int i : arr) std::cout << i << ", "; std::cout<<std::endl;

	Solution sln;
	std::string str  = sln.createLargestNum(arr, sizeof(arr)/sizeof(arr[0]));

	std::cout << str << std::endl;
	std::system("PAUSE");
	return 0;
}