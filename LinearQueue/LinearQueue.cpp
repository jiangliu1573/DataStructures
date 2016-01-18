#include "LinearQueue.h"

PQueue allocate_queue(int length)
{
	if (length == 0)
	{
		return NULL;
	}

	PQueue pQueue = (PQueue)malloc(sizeof(Queue));
	assert(pQueue != NULL);
	memset(pQueue, 0, sizeof(Queue));

	pQueue->data = (int *)malloc(sizeof(int) * length);
	if (pQueue->data == NULL)
	{
		free(pQueue);
		return NULL;
	}

	pQueue->length = length;

	return pQueue;
}

STATUS insert_data(PQueue pQueue, int data)
{
	if (pQueue == NULL)
	{
		return FALSE;
	}

	if (pQueue->length == pQueue->count)
	{
		return FALSE;
	}

	pQueue->data[pQueue->tail] = data;
	pQueue->tail++;
	pQueue->count++;

	return TRUE;
}

STATUS get_data(PQueue pQueue, int *value)
{
	if (pQueue == NULL || value == NULL)
	{
		return FALSE;
	}

	if (pQueue->count == 0)
	{
		return FALSE;
	}

	*value = pQueue->data[pQueue->head];
	pQueue->head++;
	pQueue->count--;

	return TRUE;
}

STATUS delete_queue(PQueue pQueue)
{
	if (pQueue == NULL)
	{
		return false;
	}

	assert(pQueue->data != NULL);

	free(pQueue->data);
	free(pQueue);

	return TRUE;
}
