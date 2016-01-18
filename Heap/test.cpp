#include <stdio.h>

void swap(int arr[], int x, int y)
{
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void siftdown(int arr[], int i, int largestIndex)
{
	int t, flag = 0;

	while (i * 2 <= largestIndex && flag == 0)
	{
		if (arr[i] < arr[i * 2])
			t = i * 2;
		else
			t = i;

		if (i * 2 + 1 <= largestIndex)
		{
			if (arr[t] < arr[i * 2 + 1])
				t = i * 2 + 1;
		}

		if (t != i)
		{
			swap(arr, t, i);
			i = t;
		}
		else
		{
			flag = 1;
		}
	}
}

void create(int arr[], int largetIndex)
{
	int i = largetIndex / 2;
	for (; i >= 0; i--)
	{
		siftdown(arr, i, largetIndex);
	}
}

void heapsort(int arr[], int largestIndex)
{
	while (largestIndex > 0)
	{
		swap(arr, 0, largestIndex);
		largestIndex--;
		siftdown(arr, 0, largestIndex);
	}
}

int main()
{
	int arr[10] = {1, 2, 10, 11, 40, 20, 7, 8, 9, 20 };

	create(arr, 9);

	heapsort(arr, 9);
	printf("print the heap:\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d\t", arr[i]);
	}

	return 0;
}