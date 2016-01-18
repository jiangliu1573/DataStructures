#include"LinearQueue.h"

int main()
{
	PQueue pQueue = allocate_queue(10);
	for (int i = 0; i < 10; i++)
	{
		insert_data(pQueue, i);
	}

	printf("print the queue: \n");
	int value;
	for (int i = 0; i < 10; i++)
	{
		if (get_data(pQueue, &value))
		{
			printf("%d\t", value);
		}
	}
}