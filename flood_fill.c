/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abifkirn <abifkirn@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:58:07 by abifkirn          #+#    #+#             */
/*   Updated: 2025/02/26 18:03:07 by abifkirn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_general *general, char **str, int y, int x)
{
	if (y < 0 || x < 0 || y > general->lenght || x > general->width)
		return ;
	if (str[y][x] == 'E' || str[y][x] == 'B')
		str[y][x] = '1';
	if (str[y][x] == '0' || str[y][x] == 'P' || str[y][x] == 'C')
	{
		str[y][x] = 'F';
		flood_fill(general, str, y + 1, x);
		flood_fill(general, str, y - 1, x);
		flood_fill(general, str, y, x + 1);
		flood_fill(general, str, y, x - 1);
	}
}
