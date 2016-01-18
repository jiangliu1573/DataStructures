#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 26  
#define FILE_NAME_LENGTH 20  

struct file
{
	char name[FILE_NAME_LENGTH];
	file *next;

};

file *files[HASH_SIZE];


void init()
{
	for (int i = 0; i < HASH_SIZE; i++)
		files[i] = NULL;
}

char caseInsensitive(char ch)
{
	if (ch <= 'Z')
		return ch + 32;

	return ch;
}

int hash(char *fileName)
{
	return caseInsensitive(fileName[0]) - 'a';
}

bool search(char *fileName)
{
	int num = hash(fileName);
	file *p = files[num];
	while (p != NULL)
	{
		if (strcmp(p->name, fileName) == 0)
			return true;
		p = p->next;
	}

	return false;
}

void insert(char *fileName)
{
	if (search(fileName) == false)
	{
		int num = hash(fileName);
		file *newNode = (file *)malloc(sizeof(file));
		if (newNode == NULL)
			exit(0);

		strcpy_s(newNode->name, fileName);
	
		if (files[num] == NULL)
		{
			files[num] = newNode;
			newNode->next = NULL;
		}
		else
		{
			newNode->next = files[num];
			files[num] = newNode;
		}

	}
}

void showAll()
{
	file *p = NULL;
	for (int i = 0; i < HASH_SIZE; i++)
	{
		p = files[i];
		if (p != NULL)
		{
			printf("file begin with %c:\n", 'a' + i);
			while (p != NULL)
			{
				printf("%s\n", p->name);
				p = p->next;
			}

			printf("\n");
		} 
	}
}

int main()
{
	char *fileNames[] = { "apple","because","song","Dan","discuz","cartoon","nobody","android","information","love","like","No","nothing","like","alone","nothing" };
	int len = sizeof(fileNames) / sizeof(char *);

	init();

	for (int i = 0; i < len; i++)
	{
		insert(fileNames[i]);
	}

	showAll();
}
