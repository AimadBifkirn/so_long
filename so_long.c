#include "so_long.h"

void	print_error(char *str)
{
	write (2, str, ft_strlen(str));
	exit (1);
}

int	check_valid_file(char *file)
{
	int		i;
	int		j;
	char	*ber;

	i = 0;
	j = 0;
	ber = ".ber";
	while (file[i])
	{
		if (file[i + 1] && (file[i] == '/' && file[i + 1] == '.'))
			return (1);
		if (file[i] == '.')
		{
			while (file[i])
			{
				if (file[i] != ber[j])
					return (1);
				i++;
				j++;
			}
			return (0);
		}
		i++;
	}
	return (0);
}

int	find_elem(char *str, int *p, int *c, int *e)
{
	while (str[i])
	{
		if (str[i] == 'P')
			(*p)++;
		else if (str[i] == 'C')
			(*c)++;
		else if (str[i] == 'E')
			(*e)++;
		else if (str[i] != '1' || str[i++] != '0')
			return (1);
	}
	return (0);
}

int	check_help(t_map *map)
{
	int		p;
	int		c;
	int		e;
	char	*str;

	p = 0;
	c = 0;
	e = 0;
	while (map)
	{
		if (find_elem(map->line, &p, &c, &e))

		map = map->next;
	}
}

int	check_valid_map(int fd)
{
	char	*readed;
	t_map	*map;
	int		i;

	i = 0;
	map = NULL;
	readed = get_next_line(fd);
	while (readed && readed[0] == '1')
	{
		add_node(&map, readed);
		free(readed);
		readed = NULL;
		readed = get_next_line(fd);
		i++;
	}
	if (readed)
		free (readed);
	if (check_help(map) == 1)
		return (1);
	 return (0);
}

int main(int argc, char **argv)
{
	int	fd;


	if (argc == 2)
	{
		if (check_valid_file(argv[1]))
			print_error("Error\nonly .ber files are valid\n");
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			print_error("Error\nfile not found or permission denied\n");
		if (check_valid_map(fd))
			print_error("Error\ninvalid map\n");
	}
	else
		print_error("Error\nyou need only one argument\n");
	return (0);
}