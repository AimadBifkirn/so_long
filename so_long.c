/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abifkirn <abifkirn@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:38:49 by abifkirn          #+#    #+#             */
/*   Updated: 2025/02/22 12:24:11 by abifkirn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_error(char *str, t_general **general)
{
	if (general && *general)
	{
		if ((*general)->map)
			free_map(&(*general)->map);
		if ((*general)->copy_map)
		{
			free((*general)->copy_map);
			(*general)->copy_map;
		}
		free (*general);
		*general = NULL;
	}
	write(2, str, ft_strlen(str));
	return (1);
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
		write(2, "Error\nMap is not rectangular\n", 29);
		return (1);
	}
	if (str[0] != '1' || str[len - 1] != '1')
	{
		write(2, "Error\nMap is not surrounded by walls\n", 37);
		return (1);
	}
	return (0);
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

int	main(int argc, char **argv)
{
	int			fd;
	t_general	*general;

	general = malloc(sizeof(t_general));
	if (!general)
		return (print_error("malloc failed\n", &general));
	if (argc == 2)
	{
		if (check_valid_file(argv[1]))
			return (print_error("Error\nuse a '.ber' file\n", &general));
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (print_error("Error\nopen() failed\n", &general));
		initialize_struct(&general, fd);
		check_valid_map(fd, &general);
		close(fd);
		flood_fill(general, general->copy_map, general->x, general->y);
		if (check_result(general->copy_map))
			return (print_error("Error\ncan't play in this map\n", &general));
	}
	else
		return (print_error("Error\nyou need only one argument\n", &general));
	free_struct(&general);
	return (0);
}
