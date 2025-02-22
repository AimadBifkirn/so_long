#include "so_long.h"

void	flood_fill(t_general *general ,char **str, int x, int y)
{
	if (x < 0 || y < 0 || x >= general->lenght || y >= general->width)
		return ;
	if (str[x][y] == 'E')
		str[x][y] = '1';
	if (str[x][y] == '0' || str[x][y] == 'P' || str[x][y] == 'C')
	{
		str[x][y] = 'F';
		flood_fill(general ,str, x + 1, y);
		flood_fill(general ,str, x - 1, y);
		flood_fill(general ,str, x, y + 1);
		flood_fill(general ,str, x, y - 1);
	}
}
