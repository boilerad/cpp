#include <iostream>
#include<stack>

using namespace std;
int calc(std::string str)
{
	stack<double> num_stack;
	stack<char> char_stack;
	for (char i : str)
	{
		bool do_math = true;
		if (i >= '0' && i <= '9')
		{
			num_stack.push(i - '0');
			if (!char_stack.empty() && (char_stack.top() == '*' || char_stack.top() == '/'))
			{
				double x1 = num_stack.top();
				num_stack.pop();
				
				double x2 = num_stack.top();
				num_stack.pop();

				num_stack.push( (char_stack.top() == '*') ? x1 * x2 : x1/x2 );
				char_stack.pop(); // '* or /'
			}
		}
		else if (i == '(')
		{ 
			char_stack.push(i);
		}
		else if (i == ')')
		{ 
			//pop all the way back to '('
			double x1 = num_stack.top();
			num_stack.pop();

			double x2 = num_stack.top();
			num_stack.pop();

			num_stack.push((char_stack.top() == '*') ? x1 * x2 : x1 / x2);
			char_stack.pop(); // '* or /'
			char_stack.pop(); // '('


		}
		else if (i == '*' || i == '/' )
		{
			char_stack.push(i);
			do_math = false;
		}
		else if (i == '+' || i == '-')
		{ 
			char_stack.push(i);
			do_math = false;
		}


		while (do_math && !char_stack.empty() && (char_stack.top() == '*' || char_stack.top() == '/'))
		{
			double x1 = num_stack.top();
			num_stack.pop();

			double x2 = num_stack.top();
			num_stack.pop();

			num_stack.push((char_stack.top() == '*') ? x1 * x2 : x1 / x2);
			char_stack.pop();

		}
		
	}

	while (!char_stack.empty())
	{
		double x1 = num_stack.top();
		num_stack.pop();

		double x2 = num_stack.top();
		num_stack.pop();

		num_stack.push((char_stack.top() == '+') ? x1 + x2 : x1 - x2);
		char_stack.pop();
	}

	return num_stack.top();

}

int main()
{

	int x = calc("1+2*3*4+7*2");

	return 1;
}
