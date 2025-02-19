#include "so_long.h"

int is_wall_line(char *line)
{
    int i;

    i = 0;
    while (line[i] && line[i] != '\n')
    {
        if (line[i] != '1')
            return (0);
        i++;
    }
    return (1);
}