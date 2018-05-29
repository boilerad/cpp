#include <iostream>
#include <vector>
// Given an innnite number of quarters(25 cents), dimes(10 cents), nickels(5 cents), and
// pennies(1 cent), write code to calculate the number of ways of representing n cents.

std::vector<std::vector<int>> coins;
void getCoins(int n, int sum, int quarters, int dimes, int nickles, int pennies)
{
	if (sum == n)
	{
		std::vector<int> tmp{ quarters, dimes, nickles, pennies };
		for (auto c : coins) { if (c == tmp) return; } //exclude duplicates
		coins.push_back( tmp );
		return;
	}
	if( sum + 25 <= n) 	getCoins(n, sum + 25, quarters + 1, dimes    , nickles    , pennies    );
	if (sum + 10 <= n) 	getCoins(n, sum + 10, quarters    , dimes + 1, nickles    , pennies    );
	if (sum +  5 <= n) 	getCoins(n, sum +  5, quarters    , dimes    , nickles + 1, pennies    );
	if (sum +  1 <= n) 	getCoins(n, sum +  1, quarters    , dimes    , nickles    , pennies + 1);

}





/*
Triple Step : A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3
steps at a time.Implement a method to count how many possible ways the child can run up the
stairs.
*/

std::vector<std::vector<int>> steps;
void getSteps(int n, int sum, int one, int two, int three)
{
	if (sum == n)
	{
		std::vector<int> tmp = {one, two, three};
		for (auto s : steps) { if (tmp == s) return; }
		steps.push_back(tmp);
		return;
	}
	if(sum + 1 <= n) getSteps(n, sum + 1, one + 1, two    , three   );
	if(sum + 2 <= n) getSteps(n, sum + 2, one    , two + 1, three   );
	if(sum + 3 <= n) getSteps(n, sum + 3, one    , two    , three + 1);
}

int main()
{
	// coins
	int num_coins = 17;
	getCoins(num_coins, 0, 0, 0, 0, 0);

	std::cout << "Num of steps = " << num_coins << std::endl;
	std::cout << "x25 x10 x5 x1" << std::endl;
	for (auto c : coins) {
		for (auto i : c)
			std::cout << i << "  ,";
		std::cout << std::endl;
	}

	std::cout << "\n\n--------------------\n\n";

	//steps
	int num_steps = 10;
	getSteps(num_steps, 0, 0, 0, 0);

	std::cout << "Num of steps = " << num_steps << std::endl;
	std::cout << "x1 x2 x3" << std::endl;
	for (auto ss : steps) {
		for (auto i : ss)
			std::cout << i << "  ,";
		std::cout << std::endl;
	}
	return 1;
}