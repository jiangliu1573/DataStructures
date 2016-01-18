#include "LinearStack.h"

PStack allocate_stack(int length)
{
	if (length == 0)
	{
		return NULL;
	}

	PStack pStack = (PStack)malloc(sizeof(Stack));
	assert(pStack != NULL);
	memset(pStack, 0, sizeof(Stack));

	pStack->data = (int *)malloc(sizeof(int) * length);
	assert(pStack->data != NULL);

	pStack->length = length;
	pStack->top = -1;

	return pStack;
}

STATUS free_stack(PStack pStack)
{
	if (pStack == NULL)
	{
		return FALSE;
	}

	assert(pStack->data != NULL);

	free(pStack->data);
	free(pStack);

	return TRUE;
}

STATUS stack_push(PStack pStack, int data)
{
	if (pStack == NULL)
	{
		return FALSE;
	}

	if (pStack->length == pStack->top + 1)
	{
		return FALSE;
	}

	pStack->top++;
	pStack->data[pStack->top] = data;
	
	return TRUE;
}

STATUS stack_pop(PStack pStack, int *value)
{
	if (pStack == NULL)
	{
		return FALSE;
	}

	if (pStack->top == -1)
	{
		return FALSE;
	}

	*value = pStack->data[pStack->top];
	pStack->top--;

	return TRUE;
}
