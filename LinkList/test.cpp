#include "LinkList.h"

int main()
{
	PNode pLinkList = NULL;
	
	for (int i = 0; i < 10; i++)
	{
		addNode(&pLinkList, i);
	}
	printf("print the list:\n");
	printList(pLinkList);

	revertList(&pLinkList);

	printf("\n after being reverted:\n");
	printList(pLinkList);
	return 0;
}