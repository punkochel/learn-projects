#include <iostream> // only for std out;

using namespace std;

enum {
	SIZE = 26
};

class stack {
	char stck[SIZE];
	int tos;
	int id;
public:
	stack(int a_id)
	{
		tos = 0;
		id = a_id;
		cout << "Stack initialization. ID:" << id << endl; 
	}

	~stack()
	{
		cout << "Stack destruction. ID:" << id << endl; 
	}

	void init()
	{
		tos = 0;
	}

	void push(char ch);
	char pop();
};

inline void stack::push(char ch)
{
	if(tos == SIZE)
	{
		cout << "Stack is fully!" << endl;
		return;
	}
	stck[tos] = ch;
	tos++;
}

inline char stack::pop()
{
	if(tos == 0)
	{
		cout << "Stack is empty!" << endl;
		return 0;
	}
	tos--;
	return stck[tos];
}

int main()
{
	stack s1(1), s2(2);
	int i;

	s1.push('a');
	s2.push('b');
	s1.push('c');
	s2.push('d');
	s1.push('e');
	s2.push('f');

	for(i = 0; i < 3; i++)
		cout << s1.pop() << " ";
	cout << endl;

	for(i = 0; i < 3; i++)
		cout << s2.pop() << " ";
	cout << endl;
	return 0;
}