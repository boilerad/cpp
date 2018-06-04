#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

// use >> or getline() to parse string by a delimiter 

void stringstrean_foo()
{
	std::cout << "-- stringstream -- \n\n";

	/// stringstream
	std::string str("mqn a b 123!");
	std::stringstream ss(str);

	// using >> to read each word separated by a space
	std::string tmp;
	while (ss >> tmp)
		std::cout << tmp << ", ";
	std::cout << std::endl;

	// clear stringsream
	ss.str(""); ss.clear();

	// using getline with delimiter (char)
	ss.str(str);
	while (std::getline(ss, tmp, ' '))
		std::cout << tmp << "/ ";
	std::cout << std::endl;
}

void read_file_foo()
{
	std::cout << "\n\n-- read FILE -- \n\n";

	std::ifstream  fs;
	fs.open("text.txt");

	// using >> to read each word separated by a space
	std::string tmp;
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

}

void write_file_foo()
{
	std::cout << "\n\n-- write FILE -- \n\n";

	std::ofstream of("text_write.txt", std::ofstream::app);
	of << "writing output.\n";
	of.close();
}


void keyboard_foo()
{
	std::cout << "\n\n-- keyboard -- \n\n";
	std::cout << "Please input a number: " << std::endl;
	int num;
	std::cin >> num;
	std::cout << "Square of the number is " << num * num << std::endl;
}
int main()
{
	
	//stringstrean_foo();

	//read_file_foo();

	keyboard_foo();
	return 0;

}