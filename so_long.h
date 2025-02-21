#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>


typedef struct so_long
{
	t_map 	*map;
	char	**copy_map;
	int		x;
	int		y;
	int		lenght;
	int		width;
}	t_general;


typedef struct map
{
	char *line;
	struct map *next;
}	t_map;


char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(char *dst, char *src, size_t n);
void	add_node(t_map **map, char *readed);
int		ft_strcmp(char *s1, char *s2);
int		is_wall_line(char *line);
void	free_map(t_map **map);
void	free_table(char **table);
void	initialize_struct(t_general **general, int fd);
int	flood_fill(char **str, int x, int y);

#endif