#include <iostream>
#include <string>
#include <vector>
using namespace std;

// a + b -> ab , ba
// ab + c -> cab, acb, abc
// ba + c -> cba, bca, bac 


vector<string> vec;

void PermNoDups(string s, string sub, int i)  // i in s[i], each time adding a  different character in s[i] to the sub. sub will grow at the same time
{

	if (i == s.size())
	{
		vec.emplace_back(sub);
		return;
	}

	// newsub = sub + s[i] where s[i] could be at any location in sub => for loop
	for (int j = 0; j <= sub.size(); j++)  // = is included, if sub.size == 2, we have 3 outputs
	{
		string newsub = sub.substr(0, j) + s[i] + sub.substr(j);
		PermNoDups(s, newsub, i + 1);
	}

}

void Perm(string s)
{
	PermNoDups(s, "", 0);
}
int main()
{

	Perm("abc");
	for(auto ss : vec)
		cout << ss << ", ";
	cout << endl;
	return 0;
}

/*
Time complexity:
suppose n-character string
first for loop:

n-1                   n            .....             1..              0 
n-2 n-3 ...1       n-1  n-2                          0
n-3 n-4 ....


7 times:                     -----7----- 
6 times for each 7-call : --6-- --6-- --6-- --6-- --6-- --6--
5 times for each 6-call : --5-- --5--
each of n for-loop has another n-1 for-loops 
O(n * n!)
if stringcat O(n) then finally O(n^2 * n!) 
*/