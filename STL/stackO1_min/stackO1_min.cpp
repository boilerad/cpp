/*
Question: Design a Data Structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin()
which should return minimum element from the SpecialStack. All these operations of SpecialStack must be O(1).
To implement SpecialStack, you should only use standard Stack data structure and no other data structure like arrays, list, .. etc.

Soln: Using 2 stacks: one is for regular, one is for stacking the updated min value.
*/

#include <iostream>
#include <stack>

using namespace std;

class MyStack
{
public:
	MyStack(){}
	~MyStack(){}
	void push( int x );
	void pop();
	int getMin();

private:
	stack<int> normalStack, minStack;
};


// only push into minStack when new value is <= minstack.top()
// "=" is because in case of multiple equal min values

void MyStack::push(int x)
{
	normalStack.push(x);
	if( minStack.empty() ) minStack.push(x);

	if (x <= minStack.top())
		minStack.push(x);
}

// only pop minStack when its top value is the same as popped value. 
// Otherwise, minStack.top() is the still the min value and needs not popped 
void MyStack::pop()
{
	if(normalStack.empty())	return;
	if (normalStack.top() == minStack.top())	minStack.pop();
	normalStack.pop();
}

int MyStack::getMin()
{
	if (minStack.empty()) return 1000;
	return minStack.top();
}


int main()
{
	MyStack s;
	s.push(3);
	s.push(2);
	s.push(1);
	s.push(5);
	s.push(1);
	cout << "3,2,1,5,1, s::min -> " << s.getMin() << std::endl;
	s.pop();
	cout << "3,2,1,5,   s::min -> " << s.getMin() << std::endl;
	s.pop();
	cout << "3,2,1,     s::min -> " << s.getMin() << std::endl;
	s.pop();
	cout << "3,2,       s::min -> " << s.getMin() << std::endl;

	std::system("PAUSE");
	return 0;
}