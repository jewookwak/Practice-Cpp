#include <iostream>
#include <stack>
using namespace std;
// Container Adapters: An Example of Stack
int main()
{
	stack<int> stack;
	//push 4, 5, 6 to stack
	stack.push(4);
	stack.push(5);
	stack.push(6);
	
	cout << "stack size: " << stack.size() << endl; //stack size
	cout << stack.top() << endl; //get top element of stack
	stack.pop(); //remove top element of stack

	cout << stack.top() << endl;
	stack.pop();

	cout << stack.top() << endl;
	stack.pop();

	//check if stack is empty
	if (stack.empty()) {
		cout << "stack is empty " << endl;
	}

	return 0;
}