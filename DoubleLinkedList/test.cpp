#include "DoubleLinkList.h"

int main()
{
	PNode pDoubleList = createNode(0);

	for (int i = 1; i < 20; i++)
	{
		if (!addNode(&pDoubleList, i))
			break;
	}

	printf("print the list:\n");
	printList(pDoubleList);

	/*printf("\n");
	if (findData(pDoubleList, 20))
		printf("got it\n");
	else
		printf("got nothing\n");*/

	printf("\n\n");
	if (deleteNode(&pDoubleList, 20))
	{
		printf("deleted successfully!\n");
		printf("print the list:\n");
		printList(pDoubleList);
	}
	else
	{
		printf("hoops, didn't find it\n");
	}

	reverseList(&pDoubleList);
	printf("print the list:\n");
	printList(pDoubleList);
}