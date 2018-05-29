/*
Write a recursive function to multiply two positive integers without using
the * operator (or / operator). You can use addition, subtraction, and bit shifting, but you should
minimize the number of those operations.
*/

// A * B = A + A + ... + A : ( B times )

//=======================================================================
// return -> void
void productMin(int& result, int x, int y) // use & to store result 
{
	if (x == 0 || y == 0) {
		result = 0;
		return;
	}
	if (x == 1) { result = y; return; }
	if (x % 2)  {
		productMin(result, x>>1, y);
		result =  (result << 1) + y;
	}
	else {
		productMin(result, x >> 1, y);
		result = result << 1;
	}
}

void product(int& sum, int x, int y)
{
	x < y ? productMin(sum, x, y) : productMin(sum, y, x);
}


//=======================================================================
// return -> int

int productMin(int x, int y)
{
	if (x == 0 || y == 0) 	return 0;
	if (x == 1)  return y;
	if (x % 2) {
		int z = productMin(x >> 1, y);
		return (z << 1) + y;                // * 2 + y
	}
	else 
	{
		int z  = productMin(x >> 1, y);     // * 2
		return z << 1;
	}
}

int product(int x, int y)
{
	return x < y ? productMin(x, y) : productMin(y, x);
}


int main()
{
	int p1 = 1;
	product(p1, 9, 5);

	int p2 = product(9, 5);  // 5 * 9 == productMin(2, 9) * 2 + 9, productMin(2,9) == productMin(1,9) * 2, productMin(1,9) == 9
	return 0;
}