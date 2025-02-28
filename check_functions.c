/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abifkirn <abifkirn@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:54:44 by abifkirn          #+#    #+#             */
/*   Updated: 2025/02/28 14:23:42 by abifkirn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_result(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'C' || str[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_valid_file(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4 || ft_strcmp(file + len - 4, ".ber") != 0)
	{
		write (2, "Error\nuse a '.ber' file\n", 25);
		exit (1);
	}
}

int	find_elem(char *str, int *p, int *c, int *e)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'P')
			(*p)++;
		else if (str[i] == 'C')
			(*c)++;
		else if (str[i] == 'E')
			(*e)++;
		else if (str[i] == '1' || str[i] == '0' || str[i] == 'B')
			;
		else
		{
			write (1, "Error\nInvalid character '", 26);
			write (1, &str[i], 1);
			write (1, "' found in map\n", 15);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_help(t_map *map)
{
	int	p;
	int	c;
	int	e;
	int	line_len;

	p = 0;
	c = 0;
	e = 0;
	line_len = ft_strlen(map->line);
	while (map)
	{
		if (rectangle_walls_check(map->line, line_len))
			return (1);
		if (find_elem(map->line, &p, &c, &e))
			return (1);
		map = map->next;
	}
	if (p != 1 || c <= 0 || e != 1)
	{
		write(2, "Error\nInvalid number of P, C, or E\n", 35);
		return (1);
	}
	return (0);
}

int	check_valid_map(t_general **general)
{
	int		first_line;
	t_map	*tmp;

	tmp = (*general)->map;
	first_line = 1;
	if (len_map(&(*general)->map) < 3)
		print_error("Error\nneed at least 3 lines\n", general);
	if (check_help((*general)->map) == 1)
		print_error("", general);
	while (tmp->next)
	{
		if (first_line)
		{
			if (is_wall_line(tmp->line))
				print_error("Error\n1 line must be all 1\n", general);
			first_line = 0;
		}
		tmp = tmp->next;
	}
	if (is_wall_line(tmp->line))
		print_error("last line must contain only <1>'s\n", general);
	return (0);
}
