/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abifkirn <abifkirn@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:23:00 by abifkirn          #+#    #+#             */
/*   Updated: 2025/02/27 16:39:54 by abifkirn         ###   ########.fr       */
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
	void		*wall;
	void		*p_w[3];
	void		*p_l[3];
	void		*p_f[3];
	void		*p_b[3];
	void		*coin[7];
	void		*door[2];
	void		*s[13];
	void		*back;
	void		*b_back;
	int			frame;
	int			coin_index;
	int			num_coin;
	int			anim_i;
	int			ske_i;
	int			score;
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
void	free_table(char **table);
void	initialize_struct(t_general **general, int fd);
void	flood_fill(t_general *general, char **str, int x, int y);
char	*trim_newline(char *line);
int		len_map(t_map **map);
int		print_error(char *str, t_general **general);
void	free_struct(t_general **general);
int		check_valid_map(int fd, t_general **general);
void	check_valid_file(char *file);
int		check_result(char **str);
int		rectangle_walls_check(char *str, int len);
void	free_map(t_map **map);
int		window_work(t_general **general);
char	*ft_strcpy(char *dest, char *src);
int		allocate_imags(t_general **general);
void	ft_putstr_fd(char *s, int fd);
int		allocate_imags_coins(t_general **general);
int		allocate_images_door(t_general **general);
int		allocate_images_enimies(t_general **general);
char	*ft_itoa(int n);
void	initialize_everything_with_0(t_general **general);
void	free_images(t_general **g);
int		check_next_move(t_general **general, char c);
int		handel_keys(int key, t_general **general);
int		handle_cross(t_general **g);
int		handel_animation(t_general **g);
void	print_score(t_general **g);
void	update_frame(t_general **general, int key);
void	door_open(t_general **g, t_map *map);

#endif