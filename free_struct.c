/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abifkirn <abifkirn@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:57:47 by abifkirn          #+#    #+#             */
/*   Updated: 2025/02/22 19:19:00 by abifkirn         ###   ########.fr       */
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
			free((*general)->copy_map);
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
