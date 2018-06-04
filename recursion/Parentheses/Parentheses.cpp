/*
Given n pairs of parentheses, write a function to generate all combinations of well - formed parentheses.
For example, given n = 3, a solution set is :
[
"((()))",
"(()())",
"(())()",
"()(())",
"()()()"
]
Soln: recursion: keep track of the number of opening and closing brackets we have placed so far.
At any time, the number of closing brackets need not be greater than the number of opening brackets
L1: ( 
L2: () or ((
L3: ()(   ((( or (() ...
...
At each level, we add up something new deviated from the previous level. We stop when we have enough length
All these features tell us it is recursion
*/

#include <iostream>
#include <string>
#include <vector>


class Solution {
public:
	Solution(int n)
	{
		this->n = n;
	}

	std::vector<std::string> generateParenthesis()
	{
		strVec.clear();
		generate("", 0, 0, n);
		return strVec;
	}

private:
	void generate(std::string s, int open, int close, int n)
	{
		// return condition of recursion
		if (s.length() == 2 * n)
		{
			strVec.push_back(s);
			return;  
		}

		if (open < n)
			generate(s + "(", open + 1, close, n);

		if (close < open) // at any time, the number of closing brackets need not be greater than the number of opening brackets
			generate(s + ")", open, close + 1, n);
	}

	int n;
	std::vector<std::string> strVec;
};


int main()
{
	Solution sln(3);
	std::vector<std::string> v = sln.generateParenthesis();

	// printing out
	std::vector<std::string>::iterator it;
	for (it = v.begin(); it < v.end(); it++)
		std::cout << *it << ", ";
	std::cout << std::endl << std::endl;;
	
	std::system("PAUSE");
	return 0;
}

