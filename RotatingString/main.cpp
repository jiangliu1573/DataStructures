/**����������
*	����һ���ַ�����Ҫ����ַ���ǰ������ɸ��ַ��ƶ����ַ�����β����
*	����ַ�����abcdef��ǰ���2���ַ�'a'��'b'�ƶ����ַ�����β����ʹ��ԭ�ַ�������ַ�����cdefab��,
*	��дһ��������ɴ˹��ܣ�Ҫ��Գ���Ϊn���ַ���������ʱ�临�Ӷ�Ϊ O(n)���ռ临�Ӷ�Ϊ O(1)��
*/
#include <stdio.h>
#include <string.h>

/* �ⷨ1��������λ��. */
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

//������ת��
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

	// ������λ��
	//solutionOne(str, strlen(str) - 1, 2);

	//������ת��
	solutionTwo(str, strlen(str), 3);

	printf("after being rotating: %s\n", str);

	return 0;
}