#include "so_long.h"

int	handel_keys(int key, t_general **general)
{
	if (key == 65307)
	{
		free_struct(general);
		exit (0);
	}
	return (0);
}

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
			if (tmp->line[x] != '1')
				mlx_put_image_to_window((*general)->mlx, (*general)->window, (*general)->background, x * 48, y * 48);
			if (tmp->line[x] == 'P')
				mlx_put_image_to_window((*general)->mlx, (*general)->window, (*general)->player, x * 48, y * 48);
			x++;
		}
		tmp = tmp->next;
		y++;
	}
}

void	window_work(t_general **general)
{
	put_walls(general);
	mlx_key_hook((*general)->window, handel_keys, general);
	mlx_loop((*general)->mlx);
}