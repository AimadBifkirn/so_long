/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abifkirn <abifkirn@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:00:32 by abifkirn          #+#    #+#             */
/*   Updated: 2025/02/26 14:53:45 by abifkirn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	general_initialize_map(t_general **general, int fd)
{
	char	*read;

	(*general)->map = NULL;
	read = get_next_line(fd);
	while (read)
	{
		add_node(&(*general)->map, trim_newline(read));
		read = get_next_line(fd);
	}
	if ((*general)->map == NULL)
		return (1);
	return (0);
}

void	general_initialize_coyp_map(t_general **general)
{
	t_map	*map;
	int		i;
	int		len;

	i = 0;
	len = len_map(&((*general)->map));
	(*general)->copy_map = malloc(sizeof(char *) * (len + 1));
	if (!(*general)->copy_map)
		exit (print_error("malloc failled", general));
	map = (*general)->map;
	while (map)
	{
		(*general)->copy_map[i] = ft_strcpy((*general)->copy_map[i], map->line);
		map = map->next;
		i++;
	}
	(*general)->copy_map[i] = NULL;
}

void	start_position(t_general **general)
{
	char	**str;

	str = (*general)->copy_map;
	(*general)->y = 0;
	while (str[(*general)->y])
	{
		(*general)->x = 0;
		while (str[(*general)->y][(*general)->x])
		{
			if (str[(*general)->y][(*general)->x] == 'P')
				return ;
			(*general)->x++;
		}
		(*general)->y++;
	}
}

void	lenght_width(t_general **general)
{
	char	**str;
	int		width;
	int		i;

	width = 0;
	i = 0;
	str = (*general)->copy_map;
	(*general)->lenght = len_map(&(*general)->map);
	while (str[i] && i < 1)
	{
		while (str[i][width])
			width++;
		i++;
	}
	(*general)->width = width;
}

void	initialize_struct(t_general **general, int fd)
{
	(*general) = malloc(sizeof(t_general));
	if (!(*general))
	{
		ft_putstr_fd("Erro\nmalloc failed\n", 2);
		exit (1);	
	}
	if (general_initialize_map(general, fd))
		exit (print_error("Error\nmap is empthy\n", general));
	general_initialize_coyp_map(general);
	start_position(general);
	lenght_width(general);
	(*general)->frame = 0;
	(*general)->coin_index = 0;
	(*general)->num_coin = 0;
}
