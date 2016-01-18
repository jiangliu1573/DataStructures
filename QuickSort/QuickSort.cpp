#include <stdio.h>

void quickSort(int arr[], int left, int right)
{
	if (left > right)
		return;

	int i = left;
	int j = right;
	int temp = arr[left];


	while (i != j)
	{

		while (temp <= arr[j] && i < j)
			j--;

		while (temp >= arr[i] && i < j)
			i++;


		if (i < j)
		{
			int t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
		}
	}

	if (arr[i] < temp)
	{
		arr[left] = arr[i];
		arr[i] = temp;
	}
		
	quickSort(arr, left, i - 1);
	quickSort(arr, i + 1, right);

}
int main()
{

	int arr[10] = { 1, 2, 10, 11, 40, 20, 7, 8, 9, 20 };

	quickSort(arr, 0, 9);

	printf("print the arr:\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d\t", arr[i]);
	}

	printf("\n");

	return 0;
}