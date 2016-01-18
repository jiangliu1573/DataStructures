#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <memory.h>

typedef struct node {
	int data;
	node *parent;
	node *leftChild;
	node *rightChild;
}Node, *PNode;

PNode createNode(int data);
bool insertNode(PNode *pPNode, int data, PNode parent);
void inorderTraversal(const PNode pNode);
PNode findData(const PNode pNode, int data);
int countNodes(const PNode pNode);
int calculateHeight(const PNode pNode);
bool deleteNode(PNode *pPNode, int data);
bool deleteNode(PNode pNode);
PNode findMaximumNode(PNode *pPNode);
