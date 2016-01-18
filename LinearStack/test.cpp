#include "LinearStack.h"

int main()
{
	PStack pStack = allocate_stack(10);
	for (int i = 0; i < 10; i++)
	{
		if (!stack_push(pStack, i))
		{
			break;
		}
	}

	printf("print the stack:\n");
	int value;
	for (int i = 0; i < 10; i++)
	{
		if (stack_pop(pStack, &value))
		{
			printf("%d\t", value);
		}
		else
		{
			break;
		}
	}

	free_stack(pStack);

	return 0;
}