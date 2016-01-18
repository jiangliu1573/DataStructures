#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <memory.h>


typedef struct node
{
	int data;
	node *prev;
	node *next;
}Node, *PNode;

PNode createNode(int data);
PNode addNode(PNode *pPNode, int data);
void printList(const PNode pNode);
bool findData(const PNode pNode, int data);
bool deleteNode(PNode *pPNode, int data);
bool destroyList(PNode *pPNode);
bool reverseList(PNode *pPNode);
