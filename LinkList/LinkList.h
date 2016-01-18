#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <memory.h>

typedef struct node {
	int data;
	node * next;
}Node, *PNode;

void addNode(PNode *pPNode, int data);
void printList(const PNode pNode);
void revertList(PNode *pPNode);