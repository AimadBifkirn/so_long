/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abifkirn <abifkirn@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:57:47 by abifkirn          #+#    #+#             */
/*   Updated: 2025/02/26 12:57:18 by abifkirn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_coin_images(t_general **general)
{
	if ((*general)->coin[0])
		mlx_destroy_image((*general)->mlx, (*general)->coin[0]);
	if ((*general)->coin[1])
		mlx_destroy_image((*general)->mlx, (*general)->coin[1]);
	if ((*general)->coin[2])
		mlx_destroy_image((*general)->mlx, (*general)->coin[2]);
	if ((*general)->coin[3])
		mlx_destroy_image((*general)->mlx, (*general)->coin[3]);
	if ((*general)->coin[4])
		mlx_destroy_image((*general)->mlx, (*general)->coin[4]);
	if ((*general)->coin[5])
		mlx_destroy_image((*general)->mlx, (*general)->coin[5]);
	if ((*general)->coin[6])
		mlx_destroy_image((*general)->mlx, (*general)->coin[6]);
}

void	free_player_images(t_general **general)
{
	if ((*general)->player_w[0])
		mlx_destroy_image((*general)->mlx, (*general)->player_w[0]);
	if ((*general)->player_w[1])
		mlx_destroy_image((*general)->mlx, (*general)->player_w[1]);
	if ((*general)->player_w[2])
		mlx_destroy_image((*general)->mlx, (*general)->player_w[2]);
	if ((*general)->player_l[0])
		mlx_destroy_image((*general)->mlx, (*general)->player_l[0]);
	if ((*general)->player_l[1])
		mlx_destroy_image((*general)->mlx, (*general)->player_l[1]);
	if ((*general)->player_l[2])
		mlx_destroy_image((*general)->mlx, (*general)->player_l[2]);
	if ((*general)->player_f[0])
		mlx_destroy_image((*general)->mlx, (*general)->player_f[0]);
	if ((*general)->player_f[1])
		mlx_destroy_image((*general)->mlx, (*general)->player_f[1]);
	if ((*general)->player_f[2])
		mlx_destroy_image((*general)->mlx, (*general)->player_f[2]);
	if ((*general)->player_b[0])
		mlx_destroy_image((*general)->mlx, (*general)->player_b[0]);
	if ((*general)->player_b[1])
		mlx_destroy_image((*general)->mlx, (*general)->player_b[1]);
	if ((*general)->player_b[2])
		mlx_destroy_image((*general)->mlx, (*general)->player_b[2]);
}

void	free_door_images(t_general **general)
{
	if ((*general)->door)
		mlx_destroy_image((*general)->mlx, (*general)->door);
}

void	free_images(t_general **general)
{
	if ((*general)->wall)
		mlx_destroy_image((*general)->mlx, (*general)->wall);
	free_player_images(general);
	free_coin_images(general);
	free_door_images(general);
	if ((*general)->background)
		mlx_destroy_image((*general)->mlx, (*general)->background);
}

void	free_struct(t_general **general)
{
	if (*general)
	{
		if ((*general)->map)
			free_map(&(*general)->map);
		if ((*general)->copy_map)
			free_table((*general)->copy_map);
		free_images(general);
		if ((*general)->window)
			mlx_destroy_window((*general)->mlx, (*general)->window);
		if ((*general)->mlx)
		{
			mlx_destroy_display((*general)->mlx);
			free ((*general)->mlx);
		}
		free (*general);
		*general = NULL;
	}
}

void	free_table(char **table)
{
	int	i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
	table = NULL;
}

void	free_map(t_map **map)
{
	t_map	*tmp;

	while (*map)
	{
		tmp = *map;
		*map = (*map)->next;
		free(tmp->line);
		free(tmp);
	}
	*map = NULL;
}
