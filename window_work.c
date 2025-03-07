/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_work.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abifkirn <abifkirn@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:36:45 by abifkirn          #+#    #+#             */
/*   Updated: 2025/03/01 13:53:36 by abifkirn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	door_open(t_general **g, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map)
	{
		j = 0;
		while (map->line[j])
		{
			if (map->line[j] == 'E')
			{
				mlx_put_image_to_window((*g)->mlx, (*g)->window,
					(*g)->door[1], j * 48, i * 48);
				return ;
			}
			j++;
		}
		map = map->next;
		i++;
	}
}

void	update_frame(t_general **general, int key)
{
	(*general)->frame++;
	if ((*general)->frame == 3)
		(*general)->frame = 0;
	if (!check_next_move(general, key))
	{
		if (key == 'd')
			(*general)->x++;
		else if (key == 'a')
			(*general)->x--;
		else if (key == 'w')
			(*general)->y--;
		else if (key == 's')
			(*general)->y++;
		print_score(general);
	}
}

void	put_help(t_general **g, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window((*g)->mlx,
			(*g)->window, (*g)->wall, x * 48, y * 48);
	if (c != '1')
		mlx_put_image_to_window((*g)->mlx,
			(*g)->window, (*g)->back, x * 48, y * 48);
	if (c == 'P')
		mlx_put_image_to_window((*g)->mlx,
			(*g)->window, (*g)->p_f[0], x * 48, y * 48);
	if (c == 'C')
	{
		if ((*g)->coin_index == 7)
			(*g)->coin_index = 0;
		mlx_put_image_to_window((*g)->mlx, (*g)->window,
			(*g)->coin[(*g)->coin_index], x * 48 + 8, y * 48 + 8);
		(*g)->coin_index++;
		(*g)->num_coin++;
	}
	if (c == 'E')
		mlx_put_image_to_window((*g)->mlx,
			(*g)->window, (*g)->door[0], x * 48, y * 48);
}

void	put_all(t_general **general)
{
	int		y;
	int		x;
	t_map	*tmp;

	y = 0;
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

int	window_work(t_general **g)
{
	(*g)->mlx = mlx_init();
	if (!(*g)->mlx)
		print_error("problem with mlx_init", g);
	if (allocate_imags(g) || allocate_imags_coins(g)
		|| allocate_images_door(g) || allocate_images_enimies(g))
		return (1);
	(*g)->window = mlx_new_window((*g)->mlx,
			(*g)->width * 48, (*g)->lenght * 48 + 20, "so_long");
	if (!(*g)->window)
		print_error("problem creating window", g);
	put_all(g);
	mlx_loop_hook((*g)->mlx, handel_animation, g);
	print_score(g);
	mlx_hook((*g)->window, 2, 1L << 0, handel_keys, g);
	mlx_hook((*g)->window, 17, 0, handle_cross, g);
	mlx_loop((*g)->mlx);
	return (0);
}
