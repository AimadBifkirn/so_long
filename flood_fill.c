#include "so_long.h"

int	flood_fill(char **str, int x, int y)
{
	if (x < 0 || x < 0)
		return ;
	if (str[x][y] == 'E')
		str[x][y] == '1';
	if (str[x][y] == '0' || str[x][y] == 'P' || str[x][y] == 'C' || str[x][y] == '')
	{
		str[x][y] = 'F';
		flood_fill(str[x][y], x + 1, y);
		flood_fill(str[x][y], x - 1, y);
		flood_fill(str[x][y], x, y + 1);
		flood_fill(str[x][y], x, y - 1);
	}
}
777