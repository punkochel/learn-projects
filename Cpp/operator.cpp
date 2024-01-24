#include <cstdio>

class Warehouse {
	int beef,
		pork,
		apple;
public:
	Warehouse(int a_beef, int a_pork, int a_apple)
	{
		beef = a_beef;
		pork = a_pork;
		apple = a_apple;
	}

	Warehouse operator+(Warehouse o)
	{
		Warehouse res(beef + o.beef, pork + o.pork, apple + o.apple);
		return res;
	}

	int getBeef() { return beef; }
	int getPork() { return pork; }
	int getApple() { return apple; }
};

int main()
{
	Warehouse obj1(100, 150, 70);
	Warehouse obj2(100, 150, 70);

	printf("[Total] Beef: %d | Pork: %d | Apple: %d\n",
		(obj1 + obj2).getBeef(),
		(obj1 + obj2).getPork(),
		(obj1 + obj2).getApple());
	return 0;
}