#include <iostream>

/*
This method shifts 1 over by i bits, creating a value that looks like 00010000. By performing an AND with
num, we clear all bits other than the bit at bit i. Finally, we compare that to e. If that new value is not zero,
then bit i must have a 1. Otherwise, bit i is a O.
*/
bool getBit(int num, int i)
{
	return num & (1 << i); // 000 1 0000
}

/*
SetBit shifts lover by i bits, creating a value like 0001000. By performing an OR with num, only the
value at bit i will change. All other bits of the mask are zero and will not affect num.
*/
int setBit(int num, int i)
{
	return num | (1 << i);    // 000 1 0000
}


/*
This method operates in almostthe reverse of setBit . First, we create a number like 11101111 by creating
the reverse of it (00010000) and negating it. Then, we perform an AND with num. This will clear the ith bit
and leave the remainder unchanged
*/
int clearBit(int num, int i)
{
	return num & (~(1 << i)); // 1111 0 1111 == ~ 000 1 0000
}

/*
To clear all bits from the most significant bit through i (inclusive), we create a mask with a 1 at the ith bit (1<< i). 
Then, we subtract 1 from it, giving us a sequence of 0s followed by i 1s. We then AND our number
with this mask to leave just the last i bits.
*/
int clearBitsMSBtoI(int num, int i)  // 00001111: clear bits MSB to i  == 00001111 = 00010000 - 1
{
	return num & ( (1 << i) - 1 );
}


/*
To clear all bits from i through 0 (inclusive), we take a sequence of all1s (which is -1) and shift it left by i+1 bits. 
This gives us a sequence of 1 s (in the most significant bits) followed by i 0 bits.
*/
int clearBitIto0(int num, int i)
{
	return num & ( -1 << (i + 1));   //-1 = 0xFFFF FFFF
	//return num & ~((1 << (i + 1)) - 1);
}

int main()
{
	std::cout << "clearBitsMSBtoI(0xF9, 4); ... " << clearBitsMSBtoI(0xF9, 4) << std::endl; // 1111 1001 --> 0000 1001  = 9
	std::cout << "clearBitsMSBtoI(0xF9, 3); ... " << clearBitsMSBtoI(0xF9, 3) << std::endl; // 1111 1001 --> 0000 0001  = 1
	std::cout << "clearBitsMSBtoI(0xF9, 5); ... " << clearBitsMSBtoI(0xF9, 5) << std::endl; // 1111 1001 --> 0001 1001  = 25

	std::cout << "clearBitIto0(0xF9, 3); ... " << clearBitIto0(0xF9, 3) << std::endl; // 1111 1001 --> 1111 0000  = 240


	return 0;
}
