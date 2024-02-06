#include <cstdio> // only for ptintf


class Stack {
	struct stack_int {
		int value;
		stack_int *next;
	};
	stack_int *first;
	int total_value;
public:
	Stack()
	{
		first = new stack_int;
		first->next = 0; // nullptr
		total_value = 0;
	}

	~Stack()
	{
		stack_int *tmp;
		for(; first; )
		{
			tmp = first;
			first = first->next;
			delete tmp;
		}
		total_value = 0;
	}

	void Push(int val);
	int Pop();
	int getTotal() const;
};

inline void Stack::Push(int val)
{
	if(!total_value)
	{
		first->value = val;
	}
	else
	{
		stack_int *tmp;

		tmp = first;
		first = new stack_int;
		first->value = val;
		first->next = tmp;
	}
	total_value++;
}

inline int Stack::Pop()
{
	stack_int *tmp;
	int val;

	tmp = first;
	val = first->value;
	first = first->next;
	delete tmp;
	total_value--;

	return val;
}

inline int Stack::getTotal() const
{
	return total_value;
}

/*
	Test
*/
int main()
{
	Stack s;
	for(int i = 55; i < 63; i++)
	{
		s.Push(i);
	}

	int max = s.getTotal();
	for(int i = 0; i < max; i++)
	{
		printf("Stack: %d\n", s.Pop());
	}
	return 0;
}
