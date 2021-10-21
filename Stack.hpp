#ifndef _STACK_H
#define _STACK_H

#include "Utility.hpp"

// Section 2.2:

typedef double Stack_entry;

const int maxstack = 50;   //  small value for testing

class Stack {
public:
	Stack();
	bool empty() const;
	Error_code pop();
	Error_code top(Stack_entry& item) const;
	Error_code push(const Stack_entry& item);
	void clear(); // Reset the stack to be empty.
	bool full() const; // If the stack is full, 
						 // return true; else return false.
	int size() const; // Return the number of entries 
					   // in the stack.
	Error_code copy_stack_ver1(Stack& dest, Stack& source);
	Error_code copy_stack_ver2(Stack& dest, Stack& source);

	Error_code print_stack();
private:
	int count;
	Stack_entry entry[maxstack];
};
#endif