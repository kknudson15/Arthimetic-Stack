/* 
Kyle Knudson
CSCI 591
cs301188
due: 3/21/18
This file contains the main program that reads in data from file entered by a user.  This file 
contains expressions that are written in prefix form and the program uses a pointer based stack 
to evaluate the expressions in the file.  The value of the expressions are outputted to the terminal.
The stack uses nodes so that it is able to handle both characters and digits in the expressions.   
*/

#include "stack.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int applyOperation(int &v1, int &v2, char op);

int main()
{
	Stack s;
	char ch;
	string name;
	char dec;
	int v1, v2, result;
	int numCount = 0;
	int opCount = 0;
	char oprtr;
	ifstream in_file;


	cout << "Enter the name of the file: ";
	cin >> name;
	in_file.open(name.c_str());


	in_file.get(ch);
	while (!in_file.eof())
	{
		if (isdigit(ch))
		{
			s.push(ch - '0');
			numCount++;
		}
		else
		{
			s.push(ch);
			opCount++;
		}

		if (numCount > opCount)
		{
			cout << "Expression: ";
			s.displayStack();
			while (s.size() != 1)
			{
				v1 = s.pop();
				v2 = s.pop();
				oprtr = s.chpop();
				result = applyOperation(n2, n1, oprtr);
				s.push(result);
			}
			cout << "\n Result: ";
			cout << s.pop() << endl;
		}

		in_file.get(ch);

	}
	
	cout << "Stack initialized, press p to pop: ";
	cin >> dec;
	do
	{
		if (s.is_top_data() == false)
			cout << s.chpop() << endl;
		else
			cout << s.pop() << endl;

		cout << "Stack initialized, press p to pop: ";
		cin >> dec;
	} while (dec != 'f');



    return 0;
}

int applyOperation(int &v1, int &v2, char op)
{
	if (op == '+')
	{
		return v1 + v2;
	}
	else if (op == '-')
	{
		return v1 - v2;
	}
	else if (op == '*')
	{
		return v1 * v2;
	}
	else if (op == '/')
	{
		return v1 / v2;
	}
}


