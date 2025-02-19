#include "so_long.h"
#include <stdio.h>

int print_error(char *str)
{
    write(2, str, ft_strlen(str));
    return (-1);
}

int check_valid_file(char *file)
{
    int len = ft_strlen(file);
    if (len < 4 || ft_strcmp(file + len - 4, ".ber") != 0)
        return (1);
    return (0);
}

int find_elem(char *str, int *p, int *c, int *e)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == 'P')
            (*p)++;
        else if (str[i] == 'C')
            (*c)++;
        else if (str[i] == 'E')
            (*e)++;
        else if (str[i] == '1' || str[i] == '0')
            ;
        else
        {
            printf("Error: Invalid character '%c' found in map\n", str[i]);
            return (1);
        }
        i++;
    }
    return (0);
}

char	*trim_newline(char *line)
{
    int len = ft_strlen(line);
    if (len > 0 && line[len - 1] == '\n')
    {
        line[len - 1] = '\0';
    }
    return (line);
}


int check_help(t_map *map)
{
    int p = 0, c = 0, e = 0, i =0;
	char	*str;
    str = trim_newline(map->line);
    int line_len = ft_strlen(str);
    while (map)
    {
		str = trim_newline(map->line);
        if (ft_strlen(str) != line_len)
        {
			printf("%d\n", i);
            write(2, "Error: Map is not rectangular\n", 30);
            return (1);
        }
        if (str[0] != '1' || str[line_len - 1] != '1')
        {
            write(2, "Error: Map is not surrounded by walls\n", 38);
            return (1);
        }
        if (find_elem(str, &p, &c, &e))
            return (1);
        map = map->next;
		i++;
    }
    if (p != 1 || c <= 0 || e != 1)
    {
        write(2, "Error: Invalid number of players, collectibles, or exits\n", 55);
        return (1);
    }
    return (0);
}

void free_map(t_map **map)
{
    t_map *tmp;
    while (*map)
    {
        tmp = *map;
        *map = (*map)->next;
		free(tmp->line);
        free(tmp);
    }
	*map = NULL;
}

int check_valid_map(int fd, t_map **map)
{
    char    *readed;
    t_map   *tmp = NULL;
    int     first_line = 1;
    int     line_len = 0;

    readed = get_next_line(fd);
    while (readed)
    {
        if (first_line)
        {
            line_len = ft_strlen(readed);
            if (!is_wall_line(readed))
            {
                free(readed);
                return (1);
            }
            first_line = 0;
        }
        add_node(map, readed);
        readed = get_next_line(fd);
    }
    if (!*map)
        return (1);
    tmp = *map;
    while (tmp->next)
        tmp = tmp->next;
    if (!is_wall_line(tmp->line))
    {
        free_map(map);
        return (1);
    }
    if (check_help(*map) == 1)
    {
        free_map(map);
        return (1);
    }
    return (0);
}


int main(int argc, char **argv)
{
    int fd;
    t_map   *map;
    
    map = NULL;
    if (argc == 2)
    {
        if (check_valid_file(argv[1]))
            return (print_error("Error\nonly .ber files are valid\n"));
        else
        {
            fd = open(argv[1], O_RDONLY);
            if (fd < 0)
                return (print_error("Error\nfile not found or permission denied\n"));
            else
            {
                if (check_valid_map(fd, &map))
                    return (print_error("Error\ninvalid map\n"));
                close(fd);
            }
            // if (flood_fill())
            //     return (print_error("can't play in this map"));
        }
    }
    else
        return (print_error("Error\nyou need only one argument\n"));
    free_map (&map);
    return (0);
}
