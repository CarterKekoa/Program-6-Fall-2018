// Abstract Data Type Stack:
//    data object is a stack where the most-recently-added (or top) item
//                is most-easily accessible
//    operations on a stack:
//        create an empty stack
//        delete memory or "destroy" the stack
//        add a new item as the most-recently-added or top item
//        retrieve the most-recently-added or top item from the stack and copy
//        remove the most-recently-added or top item from the stack
//        check if the stack is empty
// Gonzaga University, CPSC 122, Dr. Yerion

#include "stack.h"
#include <iostream>
using namespace std;

struct Node
{
  ItemType item;
  Node* next;
};
//in analysis, there are n items on the stack

   // creates an empty stack (called the constructor)
   Stack::Stack()
   {
    topptr = nullptr; //t(n) = 1 constant-time
   }

   // destroys the stack (called the destructor)
   // cleans up the garbage of the nodes in the heap
   Stack::~Stack()
   {
		while(!isEmpty())
		{
			pop();
		}
   }

   // adds a new item as the most-recently added or top item
   // pre: newItem has been assigned; stack object exists
   // post: if the stack is not full, newItem is added at the top
   //          and isAdded is true; else isAdded is false
   void Stack::push (ItemType newItem, bool& isAdded)
   {
     Node* newptr;

     newptr = new Node;
	 if (newptr == nullptr) isAdded = false;
	 else
	 {
        newptr -> item = newItem;
        newptr -> next = topptr;
        topptr = newptr;
		isAdded = true;			//t(n) = 11
	 }
   }

   // removes the most-recently-added or top item
   // pre: stack object exists and is not empty
   // post: most-recently added or top item has been removed from the stack
   void Stack::pop()
   {
		Node* delptr;
		delptr = topptr;
		topptr = topptr -> next;
		delptr -> next = nullptr;
		delete delptr;			//t(n) 8 constant time
   }

   // copies the most-recently added or top item from the stack
   // pre: stack object exists and is not empty
   // post: top item has been copied into topItem. stack is unchanged.
   ItemType Stack::peek()
   {
     return topItem = topptr -> item; //t(n) = 3 constant time
   }

   // checks whether or not a stack is empty
   // pre: stack object exists
   // post: if stack object is empty then returns true; else returns false
   bool Stack::isEmpty()
   {
		return (topptr == nullptr); //t(n)= 2 constant time
   }

   void Stack::printStack(Node* topptr)
   {
	  while (topptr != nullptr)
		{
		cout << topptr -> item << endl;
		cout << "showing the stack" << endl << endl;
		topptr = topptr -> next;
		}
   }
   void Stack::print()
	{
		printStack(topptr);
	}
