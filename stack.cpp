#include <iostream>
#include "stack.h"
#include <cstdlib>
#include <cassert>
using namespace std;

typedef int item;

	//Destructor
	Stack:: ~Stack()
	{
		Node * temp;
		
		while(top != NULL)
		{
			temp = top;
			top = top -> next;
			delete temp;
		}
		
	}

//Precondition: a variable of the type int, as defined by the typedef, exists
//Postcondition: The entry is added to the stack.
void Stack::push(item& entry)
{
  Node * temp;
  
  temp = new Node;
  temp ->value = entry;
  temp -> next = top;
  temp -> is_value = true;
  top = temp;
  depth++;
}


void Stack::push(char entry)
{
  Node * temp;
  
  temp = new Node;
  temp ->optr = entry;
  temp -> next = top;
  temp -> is_value = false;
  top = temp;
  depth++;
}

//Precondition: stack object exists
//Postcondition: the value for the top position on a stack is returned
item Stack::pop()
{
	Node * temp;
	
	item pop;
	
	pop = top -> value;
	temp = top;
	top -> next;
	delete temp;
	depth --;
	return pop;
}

//Precondition: stack object exists
//Postcondition: the value for the top position on a stack is returned
char Stack:: chpop()
{
	Node * temp;
	
	char pop;
	
	pop = top -> optr;
	temp = top;
	top -> next;
	delete temp;
	depth --;
	return pop;
}


///Pre condition: stack object exits
// Postcondition: value of the next layer is shown.
item  Stack:: peek()
{
	if(top -> is_value) 
		return top -> value;
	else 
		return top -> optr;
}

// pre condition: a stack object exists 
// post condition: the type of the top value of the stack is returned. 
// True if it is an integer, false if it is a char.
bool Stack:: is_top_data()
{
	Node * temp; 
	temp = top;
	return temp -> is_value; 
}


// pre condition: A stack object exists 
// psot condition: The contents of the stack are displayed.
void Stack :: displayStack()
{
	Node *temp = top;
	while(temp -> next != NULL) 
	{
		if (temp ->is_value) 
			cout << temp -> value; 
		else 
			cout << temp -> optr; 
		temp = temp -> next;
	}
}