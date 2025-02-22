/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abifkirn <abifkirn@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:23:00 by abifkirn          #+#    #+#             */
/*   Updated: 2025/02/22 19:32:13 by abifkirn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct so_long
{
	struct map	*map;
	char		**copy_map;
	int			x;
	int			y;
	int			lenght;
	int			width;
	void		*mlx;
	void		*window;
}	t_general;

typedef struct map
{
	char		*line;
	struct map	*next;
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
void	flood_fill(t_general *general, char **str, int x, int y);
char	*trim_newline(char *line);
int		len_map(t_map **map);
int		print_error(char *str, t_general **general);
void	free_struct(t_general **general);
int		check_valid_map(int fd, t_general **general);
int		check_valid_file(char *file);
int		check_result(char **str);
int		rectangle_walls_check(char *str, int len);
void	free_map(t_map **map);

#endif