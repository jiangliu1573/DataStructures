#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <memory.h>

typedef struct stack
{
	int *data;
	int length;
	int top;
} Stack, *PStack;

typedef  int STATUS;

#define TRUE 1
#define FALSE 0

PStack allocate_stack(int length);
STATUS free_stack(PStack pStack);
STATUS stack_push(PStack pStack, int data);
STATUS stack_pop(PStack pStack, int *value);