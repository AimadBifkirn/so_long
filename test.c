int check_valid_map(int fd, t_map **map)
{
    char    *readed;
    t_map   *tmp = NULL;
    char    *str;
    int     first_line = 1;

    readed = get_next_line(fd);
    while (readed)
    {
        if (first_line)
        {
            if (!is_wall_line(readed))
            {
                free(readed);
                return (1);
            }
            first_line = 0;
        }
        str = trim_newline(readed);
        add_node(map, str);
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