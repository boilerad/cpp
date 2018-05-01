/*
Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element.
The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number.
If it doesn't exist, output -1 for this number.

Example 1:
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2;
The number 2 can't find next greater number;
The second 1's next greater number needs to search circularly, which is also 2.
*/
#include <iostream>
#include <vector>
#include <unordered_map>>
#include <stack>

using namespace std;

class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		int n = nums.size();
		vector<int> next(n, -1);
		stack<int> s; // index stack
		for (int i = 0; i < n * 2; i++) { // circular array --> need to x2
			int num = nums[i % n];
			while (!s.empty() && nums[s.top()] < num) { // just need to store index of elements that are greater than the current pointing value  
				next[s.top()] = num;					// if they are smaller, then the current pointed value is their NextGreaterELe, and we pop all of these indices out 
				s.pop();
			}
			if (i < n) s.push(i); // store index, not value
		}
		return next;
	}


	vector<int> nextGreaterElements_map(vector<int>& nums) {
		stack<int> s;
		unordered_map<int, int> m;
		for (int n : nums) {
			while (!s.empty() && s.top() < n) { // at any time, stack only contains elements > current pointed (left to right, current pointed value is the right most)  
				m[s.top()] = n;
				s.pop();
			}
			s.push(n);
		}
		vector<int> ans;
		for (int n : nums) ans.push_back(m.count(n) ? m[n] : -1);
		return ans;

	}
};

int main()
{
	
	Solution sln;
	vector <int>v { 3,1,6,2,5 };
	vector<int> o;
	o = sln.nextGreaterElements(v);
	
	for (int num : v)	std::cout << num << ", ";
	std::cout << std::endl;

	for(int num : o)	std::cout << num << ", ";
	std::cout << std::endl;
	
	o = sln.nextGreaterElements_map(v);
	for (int num : o)	std::cout << num << ", ";
	std::cout << std::endl;

	
	std::system("PAUSE");
	return 0;
}