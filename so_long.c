#include "so_long.h"

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