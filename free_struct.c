/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abifkirn <abifkirn@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:57:47 by abifkirn          #+#    #+#             */
/*   Updated: 2025/02/27 14:06:54 by abifkirn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_struct(t_general **g)
{
	if (*g)
	{
		if ((*g)->map)
			free_map(&(*g)->map);
		if ((*g)->copy_map)
			free_table((*g)->copy_map);
		free_images(g);
		if ((*g)->window)
			mlx_destroy_window((*g)->mlx, (*g)->window);
		if ((*g)->mlx)
		{
			mlx_destroy_display((*g)->mlx);
			free ((*g)->mlx);
		}
		free (*g);
		*g = NULL;
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
