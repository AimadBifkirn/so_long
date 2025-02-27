/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abifkirn <abifkirn@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:13:52 by abifkirn          #+#    #+#             */
/*   Updated: 2025/02/27 18:19:43 by abifkirn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0)
		return ;
	if (s != NULL)
		write(fd, s, ft_strlen(s));
}

int	print_error(char *str, t_general **general)
{
	free_struct(general);
	ft_putstr_fd(str, 2);
	exit (1);
}

void	print_score(t_general **g)
{
	char	*str;
	int		x;
	int		i;

	i = 0;
	str = ft_itoa ((*g)->score);
	str = ft_strjoin("score : ", str);
	x = (((*g)->width * 48) / 2) - (ft_strlen(str) * 3);
	while (i < (*g)->width)
	{
		mlx_put_image_to_window((*g)->mlx,
			(*g)->window, (*g)->b_back, i * 48, (*g)->lenght * 48);
		i++;
	}
	mlx_string_put((*g)->mlx, (*g)->window, x,
		(*g)->lenght * 48 + 14, 0xFFFF00, str);
	(*g)->score++;
	free(str);
}
