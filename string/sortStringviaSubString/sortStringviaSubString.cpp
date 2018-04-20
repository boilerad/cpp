#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

/*
S and T are strings composed of lowercase letters. In S, no letter occurs more than once.
S was sorted in some custom order previously. We want to permute the characters of T so that they match the order that S was sorted. 
More specifically, if x occurs before y in S, then x should occur before y in the returned string.
Return any permutation of T (as a string) that satisfies this property.

Example :
Input:
	S = "cba"
	T = "abcd"
Output: "cbad"

Explanation:
"a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c", "b", and "a".
Since "d" does not appear in S, it can be at any position in T. "dcba", "cdba", "cbda" are also valid outputs.

*/

class Solution
{
public:
	Solution(std::string s1, std::string s2): s1(s1), s2(s2){}
	
	std::string sortString()
	{
		std::sort(s2.begin(), s2.end(), [&s1 = s1] (char i, char j) ->bool { return s1.find(i) < s1.find(j); }); // auto &s1 = s1; // C++14, first s1 is local varible of lamda function
		return s2;																								 // second s1 is this->s1
	}
	
	// similar to above but used a tempory variable to capture the class member variable
	std::string sortString_v2()
	{
		auto &s = s1;
		std::sort(s2.begin(), s2.end(), [&s](char i, char j) { return s.find(i) < s.find(j); });
		return s2;
	}

	// use "this" in lamda function
	std::string sortString_v3()
	{
		std::sort(s2.begin(), s2.end(), [this](char i, char j) { return s1.find(i) < s1.find(j); });			// error if no "this"
		return s2;
	}

	std::string sortString_v4()
	{
		std::unordered_map<char, int> order;
		int i = 1;
		std::for_each(s1.begin(), s1.end(), [&](char c) { order[c] += i++; });  // get order of chars in s1

		// print out M1
		auto it = order.begin(); // std::unordered_map<char, int>::iterator it = order.begin();
		for (; it != order.end(); it++)	std::cout << it->first << ":" << it->second << ", ";
		std::cout << std::endl;

		for (auto p : order) { std::cout << p.first << ":" << p.second << ", ";} // p is not iterator but an element of a map which is std::pair<char, int>
		std::cout << std::endl;

		std::sort(s2.begin(), s2.end(), [&]( char ci, char cj ) {return order[ ci ] < order[ cj ]; });
		return s2;
	}



private:
	std::string s1, s2;
};


int main()
{
	Solution sln("abc", "bedcggwga");
	std::cout << sln.sortString() << std::endl;

	Solution sln_v2("abc", "bedcggwga");
	std::cout << sln_v2.sortString_v2() << std::endl;

	Solution sln_v3("abc", "bedcggwga");
	std::cout << sln_v3.sortString_v3() << std::endl;

	Solution sln_v4("abc", "bedcggwga");
	std::cout << sln_v4.sortString_v4() << std::endl;

	std:system("PAUSE");
	return 0;
}