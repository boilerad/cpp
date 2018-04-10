
/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. 
In other words, one of the first string's permutations is the substring of the second string.

Example 1:
Input:s1 = "ab" s2 = "eidbaooo"
Output : True
Explanation : s2 contains one permutation of s1("ba").

Example 2 :
Input : s1 = "ab" s2 = "eidboaoo"
Output : False
*/
// keywords: substring, sort, string compare

#include <iostream>
#include <string>
#include <map>
#include <algorithm> //sort

#define HASH_ARRAY_LEN 26*2

class SubStringPermutation
{
public:
	SubStringPermutation(std::string s1, std::string s2)
	{
		this->s1 = s1;
		this->s2 = s2;
	}
	bool SubStringPermutation::isAPermutation_UsingSubString();
	bool SubStringPermutation::isAPermutation_UsingHashMap();


private:
	std::string s1;
	std::string s2;
};


bool SubStringPermutation::isAPermutation_UsingSubString()
{
	if (s1.length() > s2.length())
		return false;

	// sort s1
	std::sort(s1.begin(), s1.end());
	std::cout << "s1 = " << s1 << ", s2 = " << s2 << "\n";

	// for each chunk of length s1 in s2, 
	// sort this chunk and compare with sorted s1
	// if they are the same, s1 is a permuatated substring of s2
	for ( unsigned i = 0; i < s2.length() - s1.length() + 1; ++i )
	{
		std::cout << "i = " << i << std::endl;
		std::cout << "s2.substr: " << s2.substr(i, s1.length()); 

		std::string substring_s2 = s2.substr(i, s1.length());
		std::sort(substring_s2.begin(), substring_s2.end());

		std::cout << "  --> " << substring_s2 << std::endl << std::endl;

		if ( !s1.compare( substring_s2 ) ) // 0 --> same string
			return true;
	}
	return false;
}
/*--------------------------------------------------------------------------*/


/* M2
Instead of making use of a special HashMap datastructure just to store the frequency of occurence of characters,
we can use a simpler array data structure to store the frequencies.Given strings contains only lowercase alphabets('a' to 'z', 'A' to 'Z').
So we need to take an array of size 26x2. The rest of the process remains the same as the last approach.
*/

void hash(int* hash_array, std::string s)
{
	// store char frequency in an array 26 x 2 : 'ABC...Zabc..z'
	for (unsigned i = 0; i < s.length(); ++i)
	{
		char c = s[i];
		if (c >= 'a')
			hash_array[c - 'a' + HASH_ARRAY_LEN/2] += 1;  // 'a' = 97 in ASCII
		else
			hash_array[c - 'A'] += 1;                     // 'A' = 65 in ASCII
	}
}

bool match(int* hash_array_1, int* hash_array_2)
{
	// print out 2 hash maps
	for (unsigned i = 0; i < HASH_ARRAY_LEN; ++i)
		std::cout << hash_array_1[i] << " ";
	std::cout << std::endl;

	for (unsigned i = 0; i < HASH_ARRAY_LEN; ++i)
		std::cout << hash_array_2[i] << " ";
	std::cout << std::endl <<std::endl;
	
	// check if 2 hash maps match
	for (unsigned i = 0; i < HASH_ARRAY_LEN; ++i)
	{
		if (hash_array_1[i] != hash_array_2[i])
			return false;
	}
	return true;
}


bool SubStringPermutation::isAPermutation_UsingHashMap() {
	if (s1.length() > s2.length())
		return false;

	int hash_s1 [ HASH_ARRAY_LEN ] = { 0 };
	hash(hash_s1, s1);

	// for each chunk of length s1 in s2, 
	// find hash map of this chink and compare with hash map of s1
	// if they are the same, s1 is a permuatated substring of s2
	for (unsigned i = 0; i < s2.length() - s1.length() + 1; ++i)
	{
		int hash_subs2 [ HASH_ARRAY_LEN ] = { 0 };
		std::string sub_s2 = s2.substr(i, s1.length());
		hash( hash_subs2, sub_s2 );
		if ( match(hash_s1, hash_subs2) )
				return true;
	}
	return false;

}

/*--------------------------------------------------------------------------*/
int main()
{
	std::string s1 = "baa", s2 = "oinhaba";
	SubStringPermutation sp( s1, s2 );
	std::cout << (sp.isAPermutation_UsingSubString()? "Is a permuatation!\n" : " is NOT a permuatation!\n");
	std::cout << " --- \n\n" << std::endl;

	SubStringPermutation sp2("baa", "oinhaba");
	std::cout << (sp2.isAPermutation_UsingHashMap() ? "Is a permuatation!\n" : " is NOT a permuatation!\n");

	std::system("PAUSE");
	return 0;
}



