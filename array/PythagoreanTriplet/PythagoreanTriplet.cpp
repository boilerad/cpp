#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
	int* getTriplet(int* array, int N)
	{
		// int N = sizeof(array) / sizeof(array[0]); // wrong, size of pointer is always 4 (int)
		
		// sorting O(nlongn)
		std::sort(array, array+N);

	
		// - - - - - --- - - - 
		//   l           r   i 
		//   ->         
		// using 2 pointers left and right, and move them right and left respectively for each value starting from the right most sorted array
		// Worst case: n times * each time move along the entire n-1 steps
		//			   O(n^2)
		for (int i = N-1; i > 1; i--)
		{

			int l = 0, r = i - 1;

			int current = array[i] * array[i];
			while ( l < r )
			{
				if ( (array[l] * array[l]) + (array[r] * array[r]) == (array[i] * array[i]) )
				{
					arr[0] = array[l];
					arr[1] = array[r];
					arr[2] = array[i];
					return arr;
				}
				else if ((array[l] * array[l]) + (array[r] * array[r]) < (array[i] * array[i]))
					l++; // move l only 
				else
					r--; // move r only
			}
			
		}

		return arr;

	}
	Solution() { arr = new int[3]{-1,-1,-1}; }
	~Solution(){ delete arr; }
private:
	int* arr;
};

int main()
{
	int a[] = { 3,1,8,4,5,7,10};
	Solution sln;
	int *arr = sln.getTriplet( a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < 3; i++)
		std::cout << arr[i] << ",";
	std::cout << std::endl;


	std::system("PAUSE");
	return 0;
}

/*
	O(N^3)
for (int i=0; i<n; i++)
{
	for (int j=i+1; j<n; j++)
	{
		for (int k=j+1; k<n; k++)
		{
			// Calculate square of array elements
			int x = ar[i]*ar[i], y = ar[j]*ar[j], z = ar[k]*ar[k];
			if (x == y + z || y == x + z || z == x + y)
			return true;
		}
	}
}
*/