#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

// use >> or getline() to parse string by a delimiter 

int main()
{
	std::cout << "\n\n  -- stringstream -- \n";
	/// stringstream
	std::string str("mqn a b 123!");
	std::stringstream ss( str );

	// using >> to read each word separated by a space
	std::string tmp;
	while (ss >> tmp)
		std::cout << tmp << ", ";
	std::cout << std::endl;

	ss.str(""); ss.clear();


	// using getline with delimiter (char)
	ss.str(str);
	while ( std::getline(ss, tmp, ' ') )
		std::cout << tmp << "/ ";
	std::cout << std::endl;
	std::cout << "\n\n  -- FILE : read -- \n";


	//-------------------------------------------------------------
	/// FIlE read
	std::ifstream  fs; 

	// using >> to read each word separated by a space
	fs.open("text.txt");
	while (fs >> tmp)
		std::cout << tmp << ", ";
	std::cout << std::endl;
	fs.close();


	// using getline with delimiter (char)
	fs.open("text.txt");
	while (std::getline(fs, tmp, ' '))
		std::cout << tmp << "/ ";
	std::cout << std::endl;
	fs.close();


	//-------------------------------------------------------------
	/// FILE write
	std::ofstream of("text_write.txt", std::ofstream::app);
	of << "writing output.\n";
	of.close();
	std::system("PAUSE");
	return 0;
}