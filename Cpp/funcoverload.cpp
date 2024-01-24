#include <cstdio>

void print()
{
	printf("Hello, world!\n");
}

void print(int value)
{
	printf("[int] Value is %d\n", value);
}

void print(double value)
{
	printf("[double] Value is %.2f\n", value);
}

int main()
{
	print();
	print(15);
	print(3.14);
	print(3/2);
	print(3.0/2);
	return 0;
}