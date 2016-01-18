#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right)
{
	int size = right - left + 1;
	int *temp = (int *)malloc(sizeof(int) * size);
	if (temp == NULL)
	{
		exit(1);
	}
	int left_index = left;
	int right_index = mid + 1;
	int counter = 0;

	while (left_index <= mid && right_index <= right)
	{
		if (arr[left_index] <= arr[right_index])
		{
			temp[counter] = arr[left_index];
			left_index++;
		}
		else
		{
			temp[counter] = arr[right_index];
			right_index++;
		}

		counter++;
	}

	while (left_index <= mid)
	{
		temp[counter] = arr[left_index];
		left_index++;
		counter++;
	}

	while (right_index <= right)
	{
		temp[counter] = arr[right_index];
		right_index++;
		counter++;
	}

	for (int i = 0; i < size; i++)
	{
		arr[left + i] = temp[i];
	}

	free(temp);
}

void merge_sort(int arr[], int left, int right)
{
	if (left >= right) {
		return;
	}

	int mid = (left + right) / 2;

	merge_sort(arr, left, mid);
	merge_sort(arr, mid + 1, right);
	
	merge(arr, left, mid, right);
}

int main()
{
	int arr[] = {10, 9, 100, 1, 99, 2, 3, 99, 5};

	merge_sort(arr, 0, 8);

	printf("after being sorted: \n");
	for (int i = 0; i <= 8; i++)
	{
		printf("%d\t", arr[i]);
	}

	return 0;
}