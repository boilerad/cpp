// Write a program to swap odd and even bits in an integer
#include <iostream>

int swap( int x )
{
	int mask_odd = 0xAAAAAAAA;          // 1010 == 0xA
	int odds  = x & mask_odd;           // take bits 1 3 5 7 
	int mask_even = 0x55555555;         // 0101 == 0x5
	int evens = x & mask_even;          // take bits 0 2 4 6
	return odds >> 1 | evens << 1;      // swapping odds and evens 
}

int main()
{
	
	std::cout << swap(6) << std::endl;  // 0110 --> 1001 = 9
	std::cout << swap(22) << std::endl; // 10110 --> 101001 = 41


	return 0;
}