/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abifkirn <abifkirn@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:38:49 by abifkirn          #+#    #+#             */
/*   Updated: 2025/02/25 15:44:39 by abifkirn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	print_error(char *str, t_general **general)
{
	if (general && *general)
	{
		if ((*general)->map)
			free_map(&(*general)->map);
		if ((*general)->copy_map)
		{
			free_table((*general)->copy_map);
			(*general)->copy_map = NULL;
		}
		free (*general);
		*general = NULL;
	}
	ft_putstr_fd(str, 2);
	exit (1);
}

char	*trim_newline(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
	{
		line[len - 1] = '\0';
	}
	return (line);
}

int	rectangle_walls_check(char *str, int len)
{
	if (ft_strlen(str) != len)
	{
		ft_putstr_fd("Error\nMap is not rectangular\n", 2);
		return (1);
	}
	if (str[0] != '1' || str[len - 1] != '1')
	{
		ft_putstr_fd("Error\nMap is not surrounded by walls\n", 2);
		return (1);
	}
	return (0);
}

void	check_argc(int argc)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\nyou need only one argument\n", 2);
		exit (1);
	}
}

void	open_fd(int *fd, char *file)
{
	*fd = open(file, O_RDONLY);
	if ((*fd) < 0)
	{
		ft_putstr_fd("Error\nopen() failed\n", 2);
		exit (1);
	}
}

int	main(int argc, char **argv)
{
	int			fd;
	t_general	*general;

	check_argc(argc);
	check_valid_file(argv[1]);
	open_fd(&fd, argv[1]);
	initialize_struct(&general, fd);
	check_valid_map(fd, &general);
	close(fd);
	flood_fill(general, general->copy_map, general->y, general->x);
	if (check_result(general->copy_map))
		print_error("Error\ncan't play in this map\n", &general);
	if (window_work(&general))
		ft_putstr_fd("Error\nhave you changed the imags !!\n", 2);
	free_struct(&general);
	return (0);
}
