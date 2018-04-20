/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
*/

#include <iostream>
#include <deque>
#include <string>
#include <sstream>      // std::stringstream

class simplifyPath 
{
public:
	simplifyPath( std::string str ):str(str){}
	std::string simplify() {
		std::stringstream ss(str); 
		std::string tmp;
		std::deque<std::string> dq;
		while( std::getline(ss, tmp, '/') ) 
		{
			if ( tmp == "" ||  tmp == "."   )   continue;           // skip when "" or "."
			if ( tmp == ".." && !dq.empty() )	dq.pop_back();      // pop when its not empty
			else if (tmp != "..") dq.push_back(tmp);                // push all others except ".." and empty()
		}
		
		std::string output;
		for(int i = 0; i < dq.size(); i++) 
			output = output + dq[i] + "/";
		/*
		//  use front() and pop_front() to print out a deque
			while(!dq.empty())
			{
				output = output + dq.front() + "/" ; 
				dq.pop_front();
			}
		//  can also  use a vector with pop_back
		//  and for loop to print out vector
		*/

		return output;
	}


private:
	std::string str;
};

int main()
{
	simplifyPath sp("/a/././//b/../c/");
	std::cout << sp.simplify() <<std::endl;
	
	std::system("PAUSE");
	return 0;
}