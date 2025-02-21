#include "so_long.h"

void general_initialize_map(t_general **general, int fd, int sit)
{
    char    *read;

    read = NULL;
    (*general)->map = NULL;
    read = get_next_line(fd);
    while (read)
    {
        add_node(&(*general)->map, trim_newline(read));
        read = get_next_line(fd);
    }
}

void general_initialize_coyp_map(t_general **general)
{
    t_map   *map;
    int     i;

    i = 0;
    (*general)->copy_map = NULL;
    map = (*general)->map;
    while (map)
    {
        (*general)->copy_map[i] = map->line;
        map = map->next;
        i++;
    }
    i = 0;
}

void	start_position(t_general **general)
{
	char	**str;

	str = (*general)->copy_map;
	(*general)->x = 0;
	(*general)->y = 0;

	while (str[(*general)->x])
	{
		while (str[(*general)->x][(*general)->y])
		{
			if (str[(*general)->x][(*general)->y] == 'P')
				return ;
			(*general)->y++;
		}
		(*general)->x++;
	}
}

void	lenght_width(t_general **general)
{
	char	**str;
	int		lenght;
	int		width;

	lenght = 0;
	width = 0;
	str = (*general)->copy_map;

	while (str[lenght])
	{
		while (str[lenght][width])
		{
			width++;
		}
		lenght++;
	}
	(*general)->lenght = lenght;
	(*general)->width = width;
}

void initialize_struct(t_general **general, int fd)
{
	general_initialize_map(general, fd);
	general_initialize_coyp_map(general);
	start_position(general);
	lenght_width(general);
}