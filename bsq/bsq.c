#include <unistd.h>
#include <stdio.h>
int g_height;
int g_width;
int map_min(int a, int b, int c)
{
	if (a <=  b && a <= c)
		return (a);
	else if (b <= c && b <= a)
		return (b);
	else 
		return (c);
}
int	*bsq(int matrix[g_height][g_width], int result[3])
{
	int	i;
	int	j;
	j = 0;
	i = 0;
	while (++i < g_height)
	{
		while (++j < g_width)
		{
			if (matrix[i][j] != 0)
			{
				matrix[i][j] = map_min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]) + 1;
				if (result[0] < matrix[i][j])
				{
					result[0] = matrix[i][j];
					result[1] = i;
					result[2] = j;
				}
			}
		}
		j = 0;
	}
	return (result);
}
int main(void)
{
	//int	width;
	//int	height;

	g_width = 4;
	g_height = 4;
	int matrix[4][4] = {{0, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {0, 0, 1, 0}};
	int result[3];
	int i = -1;
	while ( ++i < 3)
		result[i] = 0;
	bsq(matrix, result);
	printf("%d %d %d", result[0], result[1], result[2]);
	return (0);
}
