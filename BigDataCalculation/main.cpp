#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <assert.h>

typedef struct result
{
	int *num;
	int length;
}Result, *PResult;

result * bigNumAdd(int num1[], int len1, int num2[], int len2)
{
	if (num1 == NULL || num2 == NULL || len1 <= 0 || len2 <= 0)
		return NULL;

	int len = len1 > len2 ? len1 + 1 : len2 + 1;
	int *num = (int *)malloc(sizeof(len));
	assert(num != NULL);
	for (int i = 0; i < len; i++)
		num[i] = 0;

	PResult pResult = (PResult)malloc(sizeof(Result));
	assert(pResult != NULL);
	pResult->length = len;
	pResult->num = num;

	int smaller = len1 < len2 ? len1 : len2;

	int index = 0;
	for (; index < smaller; index++)
	{
		num[index] = num1[index] + num2[index];
	}

	if (len1 > len2)
	{
		for (; index < len1; index++)
		{
			num[index] = num1[index];
		}
	}
	else
	{
		for (; index < len2; index++)
		{
			num[index] = num2[index];
		}
	}

	int carry = 0;
	for (int i = 0; i < len; i++)
	{
		num[i] += carry;
		carry = num[i] / 10;
		num[i] %= 10;
	}

	return pResult;
}
int main()
{
	int num1[] = { 1, 2, 3, 4, 5 };
	int num2[] = { 6, 7, 8, 9 , 1};

	PResult pResult = bigNumAdd(num1, sizeof(num1) / sizeof(int), num2, sizeof(num2) / sizeof(int));


	printf("result:");
	for (int i = pResult->length - 1; i >= 0; i--)
	{
		printf("%d", pResult->num[i]);
	}

	return 0;
}