#include "LinkList.h"

void addNode(PNode *pLinkList, int data)
{
	PNode pTemp = (PNode)malloc(sizeof(Node));
	assert(pTemp != NULL);
	pTemp->data = data;
	pTemp->next = NULL;

	if (*pLinkList == NULL)
	{
		*pLinkList = pTemp;
	}
	else {
		PNode pNode = *pLinkList;
		while (pNode->next != NULL)
		{
			pNode = pNode->next;
		}
		pNode->next = pTemp;
	}
}

void printList(const PNode pLinkList)
{
	if (pLinkList == NULL)
	{
		return;
	}

	PNode pNode = pLinkList;
	while (pNode != NULL)
	{
		printf("%d\t", pNode->data);
		pNode = pNode->next;
	}

}

void revertList(PNode *pLinkList)
{
	if (pLinkList == NULL || *pLinkList == NULL)
	{
		return;
	}

	PNode pNodePrev;
	PNode pNodeNext;

	pNodeNext = (*pLinkList)->next;
	(*pLinkList)->next = NULL;

	while (pNodeNext != NULL)
	{
		pNodePrev = pNodeNext;
		pNodeNext = pNodeNext->next;
		pNodePrev->next = (*pLinkList);
		(*pLinkList) = pNodePrev;
	}
}
