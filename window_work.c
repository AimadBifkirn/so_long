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

void	update_frame(t_general **general, int i, int key)
{
	(*general)->frame++;
	if ((*general)->frame == 3)
		(*general)->frame = 0;
	if (!check_next_move(general, key))
	{
		mlx_put_image_to_window((*general)->mlx, (*general)->window, (*general)->background, (*general)->x * 48, (*general)->y * 48);
		if (i == 0)
			(*general)->x++;
		else if (i == 1)
			(*general)->x--;
		else if (i == 2)
			(*general)->y--;
		else if (i == 3)
			(*general)->y++;
	}
}

void	update_player_pos(t_general **general, int key)
{
	mlx_put_image_to_window((*general)->mlx, (*general)->window, (*general)->background, (*general)->x * 48, (*general)->y * 48);
	if (key == 'd')
	{
		update_frame(general, 0, key);
		mlx_put_image_to_window((*general)->mlx, (*general)->window, (*general)->player_w[(*general)->frame], (*general)->x * 48, (*general)->y * 48);
	}
	else if (key == 'a')
	{
		update_frame(general, 1, key);
		mlx_put_image_to_window((*general)->mlx, (*general)->window, (*general)->player_l[(*general)->frame], (*general)->x * 48, (*general)->y * 48);
	}
	else if (key == 'w')
	{
		update_frame(general, 2, key);
		mlx_put_image_to_window((*general)->mlx, (*general)->window, (*general)->player_b[(*general)->frame], (*general)->x * 48, (*general)->y * 48);
	}
	else if (key == 's')
	{
		update_frame(general, 3, key);
		mlx_put_image_to_window((*general)->mlx, (*general)->window, (*general)->player_f[(*general)->frame], (*general)->x * 48, (*general)->y * 48);
	}
}

int	handel_keys(int key, t_general **general)
{
	if (key == 65307)
	{
		free_struct(general);
		exit (0);
	}
	if (key == 'w' || key == 'a' || key == 's' || key == 'd')
		update_player_pos(general, key);
	return (0);
}

// void	put_coin(t_general **general, int *i, int x, int y)
// {
// 	if ((*i) == 7)
// 		(*i) = 0;
// 	mlx_put_image_to_window((*general)->mlx, (*general)->window, (*general)->coin[(*i)], x * 48 + 8, y * 48 + 8);
// 	(*i)++;
// }

void	put_help(t_general **general, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window((*general)->mlx, (*general)->window, (*general)->wall, x * 48, y * 48);
	if (c != '1')
		mlx_put_image_to_window((*general)->mlx, (*general)->window, (*general)->background, x * 48, y * 48);
	if (c == 'P')
		mlx_put_image_to_window((*general)->mlx, (*general)->window, (*general)->player_w[0], x * 48, y * 48);
	if (c == 'C')
	{
		if ((*general)->coin_index == 7)
			(*general)->coin_index = 0;
		mlx_put_image_to_window((*general)->mlx, (*general)->window, (*general)->coin[(*general)->coin_index], x * 48 + 8, y * 48 + 8);
		(*general)->coin_index++;
	}
}

void	put_walls(t_general **general)
{
	int 	y;
	int 	x;
	int		i;
	t_map	*tmp;

	y = 0;
	i = 0;
	tmp = (*general)->map;
	while (tmp)
	{
		x = 0;
		while (tmp->line[x])
		{
			put_help(general, tmp->line[x], x, y);
			x++;
		}
		tmp = tmp->next;
		y++;
	}
}

int	window_work(t_general **general)
{
	(*general)->mlx = mlx_init();
	(*general)->window = mlx_new_window((*general)->mlx, (*general)->width * 48, (*general)->lenght * 48, "so_long");
	if (allocate_imags(general) || allocate_imags_coins(general))
		return(1);
	put_walls(general);
	mlx_key_hook((*general)->window, handel_keys, general);
	mlx_loop((*general)->mlx);
	return (0);
}