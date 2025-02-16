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

int	check_valid_map(int fd)
{
	char	*readed;
	int		i;

	i = 0;
	readed = get_next_line(fd);
	while (readed && readed[0] == '1')
	{
		
		free(readed);
		readed = NULL;
		readed = get_next_line(fd);
		i++;
	}
}

int main(int argc, char **argv)
{
	int	fd;


	if (argc == 2)
	{
		if (check_valid_file(argv[1]))
			print_error("only .ber file are valid");
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			print_error("file not found or permission denied");
		if (check_valid_map(fd))
			print_error("invalid map");
	}
	else
		print_error("you need only one argument");
	return (0);
}