// a client program of Stack
// Gonzaga University, CPSC 122, Dr. Yerion

#include "stack.h"
#include <iostream>
#include <string>
using namespace std;

void enterLISPstring(string& lispstring);
bool isBalanced(string lispstring);
void printMessage (bool isBalanced);
void printNewLines(int desiredNumber);
void printStack(Stack& pstack);

int main()
{
	Stack storage; //constructor called automatically
	bool isBalancedSoFar;
	bool isAdded;
	int index;
	string lispstring;
	char nextChar;

	cout << "Enter your LISP string: ";
	cin >> lispstring;

	isBalancedSoFar = true;
	index = 0;
	while (isBalancedSoFar and index < lispstring.length())
	{
	    nextChar = lispstring.at(index);
        if (nextChar == '(')
		{
           storage.push(nextChar, isAdded);	// need to check isAdded
		   storage.print();
		}
        else if (nextChar == ')')
		{
			if (not storage.isEmpty())
				storage.pop();
			else
				isBalancedSoFar = false;
		}
		printStack(storage);
		index++;
	}
	if (isBalancedSoFar and storage.isEmpty())
		cout << "your LISP string is balanced" << endl;
	else
		cout << "your LISP string is NOT balanced" << endl;

	//destructor automatically called

	return 0;

}

void printStack(Stack& pstack)
{
	itemType topItem;
	Stack copyStack;

	while(not pstack.isEmpty())
	{
		topItem = pstack.peek();
		cout << topItem << endl;
		pstack.pop();
		copyStack.push(topItem, isAdded);
	}

	while (not copyStack.isEmpty())
	{
		topItem = copyStack.peek();
		pstack.push(topItem, is Added);
		copyStack.pop();
	}
}

//clang++ -std=c++11 lispclient.cpp stack.cpp -o go
