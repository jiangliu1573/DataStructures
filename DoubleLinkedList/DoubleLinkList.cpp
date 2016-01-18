
#include "DoubleLinkList.h"

PNode createNode(int data)
{
	PNode pNode = (PNode)malloc(sizeof(Node));
	assert(pNode != NULL);
	
	memset(pNode, 0, sizeof(Node));
	pNode->data = data;

	return pNode;
}


PNode addNode(PNode *pPNode, int data)
{
	if (pPNode == NULL || *pPNode == NULL)
		return false;

	PNode pNodeNew = createNode(data);

	PNode pNode = *pPNode;
	while (pNode->next != NULL)
	{
		pNode = pNode->next;
	}

	pNode->next = pNodeNew;
	pNodeNew->prev = pNode;

}

void printList(const PNode pNode)
{
	if (pNode == NULL)
	{
		printf("the list is empty!\n");
		return;
	}

	PNode pNodeTemp = pNode;
	while (pNodeTemp != NULL)
	{
		printf("%d\t", pNodeTemp->data);
		pNodeTemp = pNodeTemp->next;
	}
}

bool findData(const PNode pNode, int data)
{
	if (pNode == NULL)
	{
		return false;
	}

	PNode pTemp = pNode;
	while (pTemp != NULL)
	{
		if (data == pTemp->data)
			return true;

		pTemp = pTemp->next;
	}

	return false;
}

bool deleteNode(PNode *pPNode, int data)
{
	if (pPNode == NULL || *pPNode == NULL)
	{
		return false;
	}

	PNode pNode = (*pPNode);
	if (pNode->data == data)
	{
		*pPNode = pNode->next;
		(*pPNode)->prev = NULL;
		free(pNode);
		return true;
	}

	PNode pPrev = (*pPNode);
	pNode = (*pPNode)->next;
	while (pNode != NULL)
	{
		if (pNode->data == data)
		{
			pPrev->next = pNode->next;
			pNode->next->prev = pPrev;
			free(pNode);
			return true;
		}

		pPrev = pNode;
		pNode = pNode->next;
	}

	return false;
}

bool destroyList(PNode *pPNode)
{
	if (pPNode == NULL || *pPNode == NULL)
	{
		return false;
	}

	PNode pNode = (*pPNode);
	while (pNode != NULL)
	{
		PNode pNodeTemp = pNode;
		pNode = pNode->next;
		free(pNode);
	}

	*pPNode = NULL;

	return true;
}

bool reverseList(PNode *pPNode)
{
	if (pPNode == NULL || *pPNode == NULL)
	{
		return false;
	}

	PNode pNodeNext = (*pPNode)->next;
	(*pPNode)->next = NULL;

	while (pNodeNext != NULL)
	{
		PNode pNodePrev = pNodeNext;
		pNodeNext = pNodeNext->next;
		pNodePrev->next = *pPNode;
		*pPNode = pNodePrev;
	}
}