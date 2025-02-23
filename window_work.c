#include "so_long.h"
#include <stdio.h>

int	check_next_move(t_general **general, char c)
{
	int		x;
	int		y;
	int		i;
	t_map	*tmp;

	x = (*general)->x;
	y = (*general)->y;
	tmp = (*general)->map;
	i = 0;
	if (c == 'd')
		x++;
	else if (c == 'w')
		y--;
	else if (c == 's')
		y++;
	else if (c == 'a')
		x--;
	else
		return (1);
	while (tmp)
	{
		if (y == i)
		{
			if (tmp->line[x] == '1' || tmp->line[x] == 'E')
				return (1);
			else
				break ;
		}
		i++;
		tmp = tmp->next;
	}
	return (0);
}

void	update_player_pos(t_general **general, int key)
{
	if (check_next_move(general, key))
		return ;
	mlx_put_image_to_window((*general)->mlx, (*general)->window, (*general)->background, (*general)->x * 48, (*general)->y * 48);
	if (key == 'd')
	{
		(*general)->x++;
		mlx_put_image_to_window((*general)->mlx, (*general)->window, (*general)->player, (*general)->x * 48, (*general)->y * 48);
	}
	else if (key == 'a')
	{
		(*general)->x--;
		mlx_put_image_to_window((*general)->mlx, (*general)->window, (*general)->player, (*general)->x * 48, (*general)->y * 48);
	}
	else if (key == 'w')
	{
		(*general)->y--;
		mlx_put_image_to_window((*general)->mlx, (*general)->window, (*general)->player, (*general)->x * 48, (*general)->y * 48);
	}
	else if (key == 's')
	{
		(*general)->y++;
		mlx_put_image_to_window((*general)->mlx, (*general)->window, (*general)->player, (*general)->x * 48, (*general)->y * 48);
	}
}

int	handel_keys(int key, t_general **general)
{
	printf("%d\n", key);
	if (key == 65307)
	{
		free_struct(general);
		exit (0);
	}
	update_player_pos(general, key);
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