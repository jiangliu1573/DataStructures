/**问题描述：
*	给定一个字符串，要求把字符串前面的若干个字符移动到字符串的尾部，
*	如把字符串“abcdef”前面的2个字符'a'和'b'移动到字符串的尾部，使得原字符串变成字符串“cdefab”,
*	请写一个函数完成此功能，要求对长度为n的字符串操作的时间复杂度为 O(n)，空间复杂度为 O(1)。
*/
#include <stdio.h>
#include <string.h>

/* 解法1：暴力移位法. */
void solutionOne(char *str, int lastIndex, int rotatingNum)
{
	rotatingNum %= (lastIndex + 1);

	for (int i = 0; i < rotatingNum; i++)
	{
		char c = str[0];
		for (int j = 0; j < lastIndex; j++)
		{
			str[j] = str[j + 1];
		}

		str[lastIndex] = c;
	}
}

void reverseString(char *str, int from, int to)
{
	while (from < to)
	{
		char t = str[from];
		str[from++] = str[to];
		str[to--] = t;
	}
}

//三步翻转法
void solutionTwo(char *str, int stringLen, int rotatingNum)
{
	rotatingNum %= stringLen;
	reverseString(str, 0, rotatingNum - 1);
	reverseString(str, rotatingNum, stringLen - 1);
	reverseString(str, 0, stringLen - 1);
}

int main()
{
	char str[] = "abcdef";
	printf("source: %s\n", str);

	// 暴力移位法
	//solutionOne(str, strlen(str) - 1, 2);

	//三步翻转法
	solutionTwo(str, strlen(str), 3);

	printf("after being rotating: %s\n", str);

	return 0;
}