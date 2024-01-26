#include <cstdio>

template <class T>
T getMax(const T *array, const int len)
{
	T max = array[0];
	for(int i = 1; i < len; i++)
	{
		if(max < array[i])
			max = array[i];
	}
	return max;
}

int main()
{
	int arr1[] = {1, 33, 91, -36};
	double arr2[] = {0.3, 1.4, 3.14, -3.5};
	char arr3[] = {'a', 'z', 'c', 'y'};

	printf("[Int] Max: %d\n", getMax<int>(arr1, 4));
	printf("[Double] Max: %.2f\n", getMax<double>(arr2, 4));
	printf("[Char] Max: %c\n", getMax<char>(arr3, 4));
	return 0;
}

/*
	Print:
	[Int] Max: 91
	[Double] Max: 3.14
	[Char] Max: z
*/
