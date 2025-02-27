/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abifkirn <abifkirn@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:34:17 by abifkirn          #+#    #+#             */
/*   Updated: 2025/02/27 16:35:34 by abifkirn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handel_anim_help(t_general **g, t_map *str, int y)
{
	int	i;

	i = 0;
	while (str->line[i])
	{
		if (str->line[i] == 'B')
			mlx_put_image_to_window((*g)->mlx,
				(*g)->window, (*g)->s[(*g)->ske_i], i * 48, y * 48);
		i++;
	}
}

int	handel_animation(t_general **g)
{
	t_map	*map;
	int		y;

	map = (*g)->map;
	if ((*g)->anim_i == 20000)
	{
		if ((*g)->ske_i == 13)
			(*g)->ske_i = 0;
		y = 0;
		while (map)
		{
			handel_anim_help(g, map, y);
			map = map->next;
			y++;
		}
		(*g)->ske_i++;
		(*g)->anim_i = 0;
	}
	(*g)->anim_i++;
	return (0);
}

int	handle_cross(t_general **g)
{
	free_struct(g);
	exit(0);
	return (0);
}

void	update_player_pos(t_general **g, int key)
{
	mlx_put_image_to_window((*g)->mlx, (*g)->window,
		(*g)->back, (*g)->x * 48, (*g)->y * 48);
	update_frame(g, key);
	if (key == 'd')
		mlx_put_image_to_window((*g)->mlx, (*g)->window,
			(*g)->p_w[(*g)->frame], (*g)->x * 48, (*g)->y * 48);
	else if (key == 'a')
		mlx_put_image_to_window((*g)->mlx, (*g)->window,
			(*g)->p_l[(*g)->frame], (*g)->x * 48, (*g)->y * 48);
	else if (key == 'w')
		mlx_put_image_to_window((*g)->mlx, (*g)->window,
			(*g)->p_b[(*g)->frame], (*g)->x * 48, (*g)->y * 48);
	else if (key == 's')
		mlx_put_image_to_window((*g)->mlx, (*g)->window,
			(*g)->p_f[(*g)->frame], (*g)->x * 48, (*g)->y * 48);
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
