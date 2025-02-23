/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abifkirn <abifkirn@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:57:47 by abifkirn          #+#    #+#             */
/*   Updated: 2025/02/23 15:33:56 by abifkirn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_struct(t_general **general)
{
	if (*general)
	{
		if ((*general)->map)
			free_map(&(*general)->map);
		if ((*general)->copy_map)
			free_table((*general)->copy_map);
		if ((*general)->wall)
			mlx_destroy_image((*general)->mlx, (*general)->wall);
		if ((*general)->player)
			mlx_destroy_image((*general)->mlx, (*general)->player);
			if ((*general)->background)
			mlx_destroy_image((*general)->mlx, (*general)->background);
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
