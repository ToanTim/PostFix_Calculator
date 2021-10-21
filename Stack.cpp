#include <iostream>
using namespace std;

#include "Utility.hpp"
#include "Stack.hpp"

Error_code Stack::push(const Stack_entry& item)
/*
Pre:  None.
Post: If the Stack is not full, item is added to the top
      of the Stack.  If the Stack is full,
      an Error_code of overflow is returned and the Stack is left unchanged.
*/

{
    Error_code outcome = success;
    if (count >= maxstack)
        outcome = overflow;
    else
        entry[count++] = item;
    return outcome;
}


Error_code Stack::pop()
/*
Pre:  None.
Post: If the Stack is not empty, the top of
      the Stack is removed.  If the Stack
      is empty, an Error_code of underflow is returned.
*/
{
    Error_code outcome = success;
    if (count == 0)
        outcome = underflow;
    else --count;
    return outcome;
}


Error_code Stack::top(Stack_entry& item) const
/*
Pre:  None.
Post: If the Stack is not empty, the top of
      the Stack is returned in item.  If the Stack
      is empty an Error_code of underflow is returned.
*/

{
    Error_code outcome = success;
    if (count == 0)
        outcome = underflow;
    else
        item = entry[count - 1];
    return outcome;
}

Error_code Stack::copy_stack_ver1(Stack& dest, Stack& source)
{
    Error_code outcome = success;
    
    cout << "         copy stack version 1"<<endl;
    dest = source;
    cout << "size of stack dest: " << dest.size() << endl;
    cout << "items in stack dest after copy: ";
    dest.print_stack();
    cout << "\n------------------------------------------------------------" << endl;



    return outcome;
    
}

Error_code Stack::copy_stack_ver2(Stack& dest, Stack& source)
{
    Error_code outcome = success;

    for (int a = 0; a < source.size(); a++)
    {
        dest.push(source.entry[a]);
    }

    cout << "         copy stack version 3" << endl;
    dest = source;
    cout << "size of stack dest: " << dest.size() << endl;
    cout << "items in stack dest after copy: ";
    dest.print_stack();
    cout << "\n------------------------------------------------------------" << endl;

    return outcome;
}

//Error_code Stack::copy_stack_ver3(Stack& dest, Stack& source)
//{
//    Error_code outcome = success;
//
//    return outcome;
//}

Error_code Stack::print_stack()
{
    Error_code outcome = success;

   
    if (count == 0)
        outcome = underflow;
    else
    {
        for (int a = 0; a < size(); a++)
        {
            cout << entry[a] << " ";
        }
    }
    return outcome;
}

bool Stack::empty() const
/*
Pre:  None.
Post: If the Stack is empty, true is returned.
      Otherwise false is returned.
*/

{
    bool outcome = true;
    if (count > 0) outcome = false;
    return outcome;
}

Stack::Stack()
/*
Pre:  None.
Post: The stack is initialized to be empty.
*/
{
    count = 0;
}

int Stack::size() const
{
    return count;
}

void Stack::clear()
{
    while(!empty())
    {
        pop();
    }
}

bool Stack::full() const
{
    if (count < maxstack)
    {
        return true;
    }
    else return false;
}

