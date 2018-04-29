/*
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

#include <iostream>
#include <string>
using namespace std;

void removeKdigits(int K, int start, std::string &array, int length)
{
	if (!K)
		return;

	int i = start;
	while (i < length-1  && array[i ] <= array[i + 1])
	{
		i++;
	}
	
	cout << "Digit [" << i << "] : " << array[i] << " removed. --> ";

	int j = i;
	while (j)
	{
		array[j] = array[j - 1];
		j--;
	}
	
	cout << array << endl << endl;
	removeKdigits(K - 1, start + 1, array, length);

}

int main()
{
	string array = "1432219";
	int L = array.length();
	cout << "Input: "<< array << endl;

	int K = 3;
	removeKdigits(K, 0, array, L);
	cout << "Result after removing " << K << " digits" << endl;
	cout << array.substr(K) << endl;

	std::system("PAUSE");

	return 0;
}