#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct so_long
{
	char *line;
	struct so_long *next;
}	t_map;


char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(char *dst, char *src, size_t n);
void	add_node(t_map **map, char *readed);

#endif