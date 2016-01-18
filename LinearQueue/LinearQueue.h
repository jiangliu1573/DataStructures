#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <memory.h>

typedef struct queue 
{
	int *data;
	int length;
	int head;
	int tail;
	int count;

}Queue, *PQueue;

typedef  int STATUS;

#define TRUE 1
#define FALSE 0

PQueue allocate_queue(int length);
STATUS insert_data(PQueue pQueue, int data);
STATUS get_data(PQueue pQueue, int *value);
STATUS delete_queue(PQueue pQueue);


