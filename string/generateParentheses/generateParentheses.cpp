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
		if (s.length() == 2 * n)
		{
			strVec.push_back(s);
			return;  // ending condition of recursion
		}

		if (open < n)
			generate(s + "(", open + 1, close, n);

		if (close < open) // at any time, the number of closing brackets need not be greater than the number of opening brackets
			generate(s + ")", open, close + 1, n);
		return; // no need tbh, function returns void at the end of function
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
	std::cout << std::endl;

	//
	std::system("PAUSE");
	return 0;
}

