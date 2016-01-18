#include "BinaryTree.h"

void test1()
{
	PNode pNode = NULL;
	assert(false == deleteNode(NULL, 10));
	assert(false == deleteNode(&pNode, 10));
}

void test2()
{
	PNode pNode = createNode(11);
	assert(deleteNode(&pNode, 10) == false);
	free(pNode);
}

void test3()
{
	PNode pNode = createNode(10);
	assert(deleteNode(&pNode, 10) == true);
	assert(pNode == NULL);
}

void test4()
{
	PNode pNode = NULL;
	assert(true == insertNode(&pNode, 10, NULL));
	assert(true == insertNode(&pNode, 20, NULL));
	assert(true == insertNode(&pNode, 30, NULL));
	assert(true == deleteNode(&pNode, 10));
	assert(pNode->data == 20);
	assert(pNode->parent == NULL);

	free(pNode->leftChild);
	free(pNode);
}


int main()
{
	PNode tree = NULL;
	int arr[] = { 12, 6, 4, 8, 16, 15, 18 };
	for (int i = 0; i < 7; i++)
	{
		if (insertNode(&tree, arr[i], NULL) == false)
			break;
	}

	printf("print the tree:\n");
	inorderTraversal(tree);
	
	printf("\nnode numbers:%d\n", countNodes(tree));

	printf("height of the tree:%d\n", calculateHeight(tree));

	test4();

	return 0;
}

