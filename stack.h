#include <iostream>
using namespace std;

class Stack
{
typedef int item;
public:
  Stack() {top = NULL; depth = 0;} 
  ~Stack();
  void push(item& entry);
  void push(char entry);
  item pop();
  bool is_top_data();
  char chpop();
  void displayStack();

  int size() {return depth;}  // Inline
  bool is_empty() {return top == NULL;}  // Inline
  item peek();

private:
	struct Node
	{
	  int value;
	  char optr;
	  bool is_value;
	  Node *next;
	};
	int depth;
	Node * top;
};