/*
Conversion: Write a function to determine the number of bits you would need to flip to convert integer A to integer B.
	Input : 29 (or : 11101, 15 (01111)
	Output: 2		
*/

#include <iostream>

int convert(int a, int b)
{
	int c = a ^ b;       // xor detects bit differences 0 ^ 1 = 1 ^ 0 = 1
	int count = 0;
	while (c)
	{
		count += c & 1;  // count number of setbits
		c = c >> 1;
	}
	return count;
}

int convert_optimal(int a, int b)
{
	int count = 0;
	int c = a ^ b;
	while (c & (c-1)) // c & (c-1) will erase the least significant bit (the right most bit 1)
	{
		count += 1;
		c = c - 1;
	} // if there are only 2 bits 1s, while loops only twice compared with n times like convert() above

	return count;
}

int main()
{
	std::cout << convert(29, 15) << std::endl;
	std::cout << convert(0x1d, 0xF) << std::endl;

	std::cout << convert_optimal(29, 15) << std::endl;

	
	return 0;
}