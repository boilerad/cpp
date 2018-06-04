#include <iostream>
#include<string>
#include<sstream>


//** C - string ends with '\0' 
int string_to_int(char * str)
{
	std::cout << " char* " << std::endl;
	int num = 0;
	int i = 0;
	while (str[i] != '\0') {
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return num;
}

// C - atoi
int string_to_int_atoi(char * str)
{
	std::cout << " atoi " << std::endl;
	return atoi(str);
}


// ** C++ 
int string_to_int(std::string str)
{
	int num = 0;
	for (int i = 0; i < str.size(); i++)  
		num = num * 10 + (str[i] - '0');
	return num;
}

//C++
int string_to_int_ss(std::string str)
{
	std::stringstream ss(str);
	int num = 0;
	ss >> num;
	return num;

}
int main()
{
	//C
	char tmp[10] = "123";
	std::cout << string_to_int(tmp) * 2 << std::endl <<std::endl;

	std::cout << string_to_int_atoi(tmp) * 2 << std::endl << std::endl;    
	
	
	//C++
	std::cout << string_to_int("45") * 2 << std::endl << std::endl;

	std::cout << string_to_int_ss("45") * 2 << std::endl << std::endl;
	
	return 1;
}