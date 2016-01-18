#include <stdio.h>

int fibonacci(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
	{
		int n1 = 0;
		int n2 = 1;
		int fn = 0;

		for (int i = 2; i < n; i++)
		{
			fn = n1 + n2;
			n1 = n2;
			n2 = fn;
		}

		return fn;
	}
}

int main()
{
	printf("%d result:%d\n", 5, fibonacci(5));
	
	return 0;
}