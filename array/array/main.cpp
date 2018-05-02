#include <iostream>
using namespace std;

int main()
{	
	// size of array
	// cannot use a pointer to calculate size of array it's pointing to
	int x[] = { 1, 2, 3 };
	int*p = x;
	
	printf("sizeof(x)/ sizeof(x[0]) = %d/%d = %d \n", sizeof(x), sizeof(x[0]), sizeof(x) / sizeof(x[0]));
	printf("sizeof(p)/ sizeof(p[0]) = %d/%d = %d \n", sizeof(p), sizeof(p[0]), sizeof(p) / sizeof(p[0]));
	printf("sizeof(x)/ sizeof(x[0]) = %d/%d = %d \n", sizeof(int*), sizeof(int), sizeof(int*) / sizeof(int));

	std::system("PAUSE");
	return 0;
}