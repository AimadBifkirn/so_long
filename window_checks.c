/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abifkirn <abifkirn@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:31:46 by abifkirn          #+#    #+#             */
/*   Updated: 2025/02/28 14:25:08 by abifkirn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	actual_check(t_general **general, char c)
{
	if (c == 'B')
	{
		free_struct(general);
		exit (1);
	}
	if (c == '1')
		return (1);
	else if (c == 'E')
	{
		if ((*general)->num_coin == 0)
		{
			free_struct(general);
			exit (0);
		}
		return (1);
	}
	else if (c == 'C')
	{
		(*general)->num_coin--;
		if ((*general)->num_coin == 0)
			door_open(general, (*general)->map);
		return (2);
	}
	return (0);
}

int	check_next_help(t_general **general, int x, int y)
{
	int		i;
	t_map	*tmp;
	int		res;

	tmp = (*general)->map;
	i = 0;
	while (tmp)
	{
		if (y == i)
		{
			res = actual_check(general, tmp->line[x]);
			if (res == 1)
				return (1);
			else if (res == 2)
			{
				tmp->line[x] = '0';
				return (0);
			}
			else
				return (0);
		}
		i++;
		tmp = tmp->next;
	}
	return (0);
}

int	check_next_move(t_general **general, char c)
{
	int		x;
	int		y;

	x = (*general)->x;
	y = (*general)->y;
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
	if (check_next_help(general, x, y))
		return (1);
	return (0);
}
