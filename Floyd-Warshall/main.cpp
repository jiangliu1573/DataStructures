/**Floyd-Warshall×î¶ÌÂ·¾¶Ëã·¨ */
#include <stdio.h>

#define NODE_COUNT 4
#define INFINITY 9999

int map[NODE_COUNT][NODE_COUNT] = {
	{ 0, 2, 6, 4},
	{ INFINITY, 0, 3, INFINITY},
	{ 7, INFINITY, 0, 1},
	{ 5, INFINITY, 12, 0 }
};

int main()
{
	for (int k = 0; k < NODE_COUNT; k++)
	{
		for (int i = 0; i < NODE_COUNT; i++)
		{
			for (int j = 0; j < NODE_COUNT; j++)
			{
				if (map[i][k] < INFINITY && map[k][j] < INFINITY && map[i][j] > map[i][k] + map[k][j])
					map[i][j] = map[i][k] + map[k][j];
			}
		}
	}

	for (int i = 0; i < NODE_COUNT; i++)
	{
		for (int j = 0; j < NODE_COUNT; j++)
		{
			printf("%d\t", map[i][j]);
		}

		printf("\n");
	}
}
