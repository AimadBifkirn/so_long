#include "so_long.h"
#include <stdio.h>

int print_error(char *str, t_general **general)
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
    return (-1);
}

int check_valid_file(char *file)
{
    int len = ft_strlen(file);
    if (len < 4 || ft_strcmp(file + len - 4, ".ber") != 0)
        return (1);
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

int find_elem(char *str, int *p, int *c, int *e)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == 'P')
            (*p)++;
        if (str[i] == 'C')
            (*c)++;
        if (str[i] == 'E')
            (*e)++;
        if (!(str[i] == '1' || str[i] == '0'))
        {           
            printf("Error: Invalid character '%c' found in map\n", str[i]);
            return (1);
        }
        i++;
        printf("p: %d, e: %d, c: %d\n", *p, *e, *c);
    }
    return (0);
}


int check_help(t_map *map)
{
    int p = 0, c = 0, e = 0, i =0;

    int line_len = ft_strlen(map->line);
    while (map)
    {
        if (ft_strlen(map->line) != line_len)
        {
			printf("%d\n", i);
            write(2, "Error: Map is not rectangular\n", 30);
            return (1);
        }
        if (map->line[0] != '1' || map->line[line_len - 1] != '1')
        {
            write(2, "Error: Map is not surrounded by walls\n", 38);
            return (1);
        }
        if (find_elem(map->line, &p, &c, &e))
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

int check_valid_map(int fd, t_map *map)
{
    int     first_line;
    
    first_line = 1;
    while (map->next)
    {
        if (first_line)
        {
            if (!is_wall_line(map->line))
                return (1);
            first_line = 0;
        }
        map = map->next;
    }
    if (!is_wall_line(map->line))
        return (1);
    if (check_help(map) == 1)
        return (1);
    return (0);
}

// just for testing
// void    print_arry()

int main(int argc, char **argv)
{
    int fd;
    t_general  *general;
    
    general = malloc(sizeof(t_general));
    if (!general)
        return (print_error("Memory allocation failed\n", &general));
    if (argc == 2)
    {
        if (check_valid_file(argv[1]))
            return (print_error("Error\nonly .ber files are valid\n", &general));
        else
        {
            fd = open(argv[1], O_RDONLY);
            if (fd < 0)
                return (print_error("Error\nfile not found or permission denied\n", &general));
            else
            {
                initialize_struct(&general, fd);
                if (check_valid_map(fd, general->map))
                    return (print_error("Error\ninvalid map\n", &general));
                close(fd);
            }
            flood_fill(general ,general->copy_map, general->x, general->y);
        }
    }
    else
        return (print_error("Error\nyou need only one argument\n", &general));
    // free_map (&map);
    return (0);
}
