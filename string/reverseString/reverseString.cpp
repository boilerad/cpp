// Example program
#include <iostream>
#include <string>
#include <map>

class ReversedString
{
public:
	ReversedString(std::string str)
	{
		this->str = str;
	}

	std::string reverse()
	{
		unsigned L = str.length();
		for (unsigned i = 0; i< L / 2; ++i)
		{
			char t = str[L - i - 1];
			str[L - i - 1] = str[i];
			str[i] = t;
		}
		return str;
	}

private:
	std::string str;

};

int main()
{
	std::string str = "hello world!";
	ReversedString rs(str);
	std::string resString = rs.reverse();

	std::cout << str << "\n";
	std::cout << resString << "\n";
	std::system("PAUSE");
}
