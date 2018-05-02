#include <iostream>

class BST
{



public:
	BST(){}

	// O(logn) > Linear search: O(n)
	// recursion
	int BinarySearch(int* array, int l, int r, int val) {
	
		if (l > r)
			return -1;

		int mid = (l + r)/ 2;
		
		if (val == array[mid])  return mid;
		if(val > array[mid]) 	
			BinarySearch( array, mid+1, r, val );
		else 
			BinarySearch( array, l, mid-1, val );
	
	}

	// while 
	int BinarySearch_v2(int* array, int l, int r, int val) {

		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (val == array[mid])  return mid;
			if (val > array[mid])
				l = mid + 1;
			else
				r = mid - 1;
		}
		return -1;
	}
};


int main() {

	int array[] = { 1,2,5,6 };
	int val = 5;
	int N = sizeof(array) / sizeof(array[0]);

	BST b;
	int foundIndex    = b.BinarySearch   (array, 0, N - 1, val);
	int foundIndex_v2 = b.BinarySearch_v2(array, 0, N - 1, val);

	std::system("PAUSE");
	return 0;
}