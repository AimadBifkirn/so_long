/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abifkirn <abifkirn@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:18:56 by abifkirn          #+#    #+#             */
/*   Updated: 2025/02/22 11:19:00 by abifkirn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_node(t_map **map, char *readed)
{
	t_map	*tmp;
	t_map	*node;

	node = (t_map *)malloc(sizeof(t_map));
	if (!node)
		return ;
	node->line = readed;
	node->next = NULL;
	if (*map == NULL)
	{
		*map = node;
		return ;
	}
	tmp = *map;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}
