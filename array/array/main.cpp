#include <iostream>
using namespace std;

// Example program
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Complete the customSort function below.
void customSort(vector<int> arr) {
	sort(arr.begin(), arr.end());
	vector<int> index(arr.size()), freqs(arr.size(), 1);

	int i = 0;
	int j;
	for (int i = 0; i < arr.size(); i++)
	{
		index[i] = i;
	}

	i = 0;
	while (i < arr.size()-1)
	{
		if (arr[i] < arr[i + 1])
		{
			i++;
			continue;
		}
		j = i;
		while (i < arr.size()-1 && arr[i] == arr[i + 1]) {
			i++;
		}
		for (int k = j; k <= i; k++)
		{
			freqs[k] = i - j + 1;
		}

	}

	sort(index.begin(), index.end(), [&freqs](int i, int j) { return freqs[i] < freqs[j]; });

	for (int i = 0; i < arr.size(); i++)
		cout << arr[index[i]] << endl;
}



int main()
{
	vector<int> arr{ 2,2,1,1, 3 };
	customSort(arr);

	std::cout << " ";

}

/*
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

*/