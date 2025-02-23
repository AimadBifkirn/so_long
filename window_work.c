#include "so_long.h"

void	put_walls(t_general **general)
{
	int 	y;
	int 	x;
	t_map	*tmp;

	y = 0;
	tmp = (*general)->map;
	while (tmp)
	{
		x = 0;
		while (tmp->line[x])
		{
			if (tmp->line[x] == '1')
				mlx_put_image_to_window((*general)->mlx, (*general)->window, (*general)->wall, x * 48, y * 48);
			x++;
		}
		tmp = tmp->next;
		y++;
	}
}

void	window_work(t_general **general)
{
	put_walls(general);
	mlx_loop((*general)->mlx);
}