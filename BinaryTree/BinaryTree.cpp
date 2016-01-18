#include "BinaryTree.h"

PNode createNode(int data)
{
	PNode pNode = NULL;
	pNode = (PNode)malloc(sizeof(Node));
	assert(pNode != NULL);

	memset(pNode, 0, sizeof(Node));
	pNode->data = data;

	return pNode;
}


bool insertNode(PNode *pPNode, int data, PNode parent)
{
	if (pPNode == NULL)
		return false;

	if (*pPNode == NULL)
	{
		*pPNode = createNode(data);
		(*pPNode)->parent = parent;
		return true;
	}

	if (data < (*pPNode)->data)
		return insertNode(&(*pPNode)->leftChild, data, *pPNode);
	else
		return insertNode(&(*pPNode)->rightChild, data, *pPNode);
}

void inorderTraversal(const PNode pNode)
{
	if (pNode == NULL)
		return;

	inorderTraversal(pNode->leftChild);
	printf("%d\t", pNode->data);
	inorderTraversal(pNode->rightChild);
}

PNode findData(const PNode pNode, int data)
{
	if (pNode == NULL)
		return NULL;

	if (data == pNode->data)
		return pNode;
	else if (data < pNode->data)
		return findData(pNode->leftChild, data);
	else
		return findData(pNode->rightChild, data);
}

int countNodes(const PNode pNode)
{
	if (pNode == NULL)
		return 0;

	return 1 + countNodes(pNode->leftChild) + countNodes(pNode->rightChild);
}

int calculateHeight(const PNode pNode)
{
	if (pNode == NULL)
		return 0;

	int left, right;

	left = calculateHeight(pNode->leftChild);
	right = calculateHeight(pNode->rightChild);

	return (left > right) ? left + 1 : right + 1;
}


PNode findMaximumNode(PNode *pPNode)
{
	if (pPNode == NULL || *pPNode == NULL)
		return NULL;

	PNode pMax = *pPNode;

	while (pMax->rightChild != NULL)
	{
		pMax = pMax->rightChild;
	}

	return pMax;
}

bool deleteNode(PNode *pPNode, int data)
{
	if (pPNode == NULL || *pPNode == NULL)
		return false;

	PNode pNode = findData(*pPNode, data);
	if (pNode == NULL)
	{
		return false;
	}

	if (pNode == *pPNode)
	{
		if (pNode->leftChild == NULL && pNode->rightChild == NULL)
		{
			*pPNode = NULL;
		}
		else if (pNode->leftChild != NULL && pNode->rightChild == NULL)
		{
			*pPNode = pNode->leftChild;
			pNode->leftChild->parent = NULL;
		}
		else if (pNode->leftChild == NULL && pNode->rightChild != NULL)
		{
			*pPNode = pNode->rightChild;
			pNode->rightChild->parent = NULL;
		}
		else {
			PNode pMax = findMaximumNode(&(pNode->leftChild));
			if (pMax == pNode->leftChild)
			{
				pMax->rightChild = pNode->rightChild;
				pNode->rightChild->parent = pMax;
				pMax->parent = NULL;
				*pPNode = pMax;
			}
			else {
				pMax->parent->rightChild = NULL;
				pMax->parent->leftChild = pMax->leftChild;
				pMax->leftChild = pNode->leftChild;
				pMax->rightChild = pNode->rightChild;
				pMax->parent = NULL;
				*pPNode = pMax;
			}
		}


		free(pNode);
		return true;
	}
	
	return deleteNode(pNode);
}

bool deleteNode(PNode pNode)
{
	if (pNode->leftChild == NULL && pNode->rightChild == NULL)
	{
		if (pNode == pNode->parent->leftChild)
			pNode->parent->leftChild = NULL;
		else 
			pNode->parent->rightChild = NULL;
	}
	else if (pNode->leftChild != NULL && pNode->rightChild == NULL)
	{
		pNode->leftChild->parent = pNode->parent;
		if (pNode = pNode->parent->leftChild)
			pNode->parent->leftChild = pNode->leftChild;
		else
			pNode->parent->rightChild = pNode->leftChild;
	}
	else if (pNode->leftChild == NULL && pNode->rightChild != NULL)
	{
		pNode->leftChild->parent = pNode->parent;
		if (pNode = pNode->parent->leftChild)
			pNode->parent->leftChild = pNode->leftChild;
		else
			pNode->parent->rightChild = pNode->leftChild;
	}
	else {
		PNode pMax = findMaximumNode(&pNode);
		if (pMax == pNode->leftChild) {
			if (pNode == pNode->parent->leftChild)
				pNode->parent->leftChild = pMax;
			else
				pNode->parent->rightChild = pMax;

			pMax->parent = pNode->parent;
			pMax->rightChild = pNode->rightChild;
			pNode->rightChild->parent = pMax;
			
		}
		else
		{
			pMax->parent->rightChild = pMax->leftChild;
			pMax->leftChild = pNode->leftChild;
			pMax->rightChild = pNode->rightChild;
			pMax->parent = pNode->parent;
			pNode->leftChild->parent = pMax;
			pNode->rightChild->parent = pMax;
		}
	}

	free(pNode);
	return true;
}