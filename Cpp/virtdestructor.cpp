#include <cstdio> // only for printf

class A {
	int id;
	int form;
public:
	A() : id(99), form(15)
	{
	}

	virtual ~A()
	{
		printf("[~A] Complete\n");
	}

	int getId() const
	{
		return id;
	}

	virtual int getForm() const
	{
		return form;
	}
};

class B : public A {
	int form;
public:
	B() : form(30)
	{	
	}

	~B()
	{
		printf("[~B] Complete\n");
	}

	int getForm() const
	{
		return form;
	}
};

int main()
{
	A *obj1 = new A;
	A *obj2 = new B;

	printf("[A] form: %d | id: %d\n[B] form: %d | id: %d\n",
		obj1->getForm(), obj1->getId(),
		obj2->getForm(), obj2->getId());

	delete obj1;
	delete obj2;
	return 0;
}

/*
	Print:
	[A] form: 15 | id: 99
	[B] form: 30 | id: 99
	[~A] Complete
	[~B] Complete
	[~A] Complete
*/