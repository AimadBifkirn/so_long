/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abifkirn <abifkirn@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:23:01 by abifkirn          #+#    #+#             */
/*   Updated: 2025/02/27 13:49:34 by abifkirn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	allocate_imags(t_general **g)
{
	int	l;
	int	w;

	(*g)->wall = mlx_xpm_file_to_image((*g)->mlx, "./ima/wall.xpm", &w, &l);
	(*g)->p_l[0] = mlx_xpm_file_to_image((*g)->mlx, "./ima/p_l.xpm", &w, &l);
	(*g)->p_l[1] = mlx_xpm_file_to_image((*g)->mlx, "./ima/p_l2.xpm", &w, &l);
	(*g)->p_l[2] = mlx_xpm_file_to_image((*g)->mlx, "./ima/p_l3.xpm", &w, &l);
	(*g)->p_f[0] = mlx_xpm_file_to_image((*g)->mlx, "./ima/p_f.xpm", &w, &l);
	(*g)->p_f[1] = mlx_xpm_file_to_image((*g)->mlx, "./ima/p_f2.xpm", &w, &l);
	(*g)->p_f[2] = mlx_xpm_file_to_image((*g)->mlx, "./ima/p_f3.xpm", &w, &l);
	(*g)->p_w[0] = mlx_xpm_file_to_image((*g)->mlx, "./ima/p_w.xpm", &w, &l);
	(*g)->p_w[1] = mlx_xpm_file_to_image((*g)->mlx, "./ima/p_w2.xpm", &w, &l);
	(*g)->p_w[2] = mlx_xpm_file_to_image((*g)->mlx, "./ima/p_w3.xpm", &w, &l);
	(*g)->p_b[0] = mlx_xpm_file_to_image((*g)->mlx, "./ima/p_b.xpm", &w, &l);
	(*g)->p_b[1] = mlx_xpm_file_to_image((*g)->mlx, "./ima/p_b2.xpm", &w, &l);
	(*g)->p_b[2] = mlx_xpm_file_to_image((*g)->mlx, "./ima/p_b3.xpm", &w, &l);
	(*g)->back = mlx_xpm_file_to_image((*g)->mlx, "./ima/back.xpm", &w, &l);
	(*g)->b_back = mlx_xpm_file_to_image((*g)->mlx, "./ima/b_back.xpm", &w, &l);
	if (!(*g)->p_b[0] || !(*g)->p_b[1] || !(*g)->p_b[2] || !(*g)->p_w[0]
		|| !(*g)->p_w[1] || !(*g)->p_w[2] || !(*g)->p_f[0] || !(*g)->p_f[1]
		|| !(*g)->p_f[2] || !(*g)->p_l[0] || !(*g)->p_l[1] || !(*g)->p_l[2]
		|| !(*g)->b_back || !(*g)->back)
		return (1);
	return (0);
}

int	allocate_imags_coins(t_general **g)
{
	int	l;
	int	w;

	(*g)->coin[0] = mlx_xpm_file_to_image((*g)->mlx, "./ima/c/c0.xpm", &w, &l);
	(*g)->coin[1] = mlx_xpm_file_to_image((*g)->mlx, "./ima/c/c1.xpm", &w, &l);
	(*g)->coin[2] = mlx_xpm_file_to_image((*g)->mlx, "./ima/c/c2.xpm", &w, &l);
	(*g)->coin[3] = mlx_xpm_file_to_image((*g)->mlx, "./ima/c/c3.xpm", &w, &l);
	(*g)->coin[4] = mlx_xpm_file_to_image((*g)->mlx, "./ima/c/c4.xpm", &w, &l);
	(*g)->coin[5] = mlx_xpm_file_to_image((*g)->mlx, "./ima/c/c5.xpm", &w, &l);
	(*g)->coin[6] = mlx_xpm_file_to_image((*g)->mlx, "./ima/c/c6.xpm", &w, &l);
	if (!(*g)->coin[0] || !(*g)->coin[1] || !(*g)->coin[2] || !(*g)->coin[3]
		|| !(*g)->coin[4] || !(*g)->coin[5] || !(*g)->coin[6])
		return (1);
	return (0);
}

int	allocate_images_door(t_general **g)
{
	int	l;
	int	w;

	(*g)->door[0] = mlx_xpm_file_to_image((*g)->mlx, "./ima/e/e0.xpm", &w, &l);
	(*g)->door[1] = mlx_xpm_file_to_image((*g)->mlx, "./ima/e/e3.xpm", &w, &l);
	if (!(*g)->door[0] || !(*g)->door[1])
		return (1);
	return (0);
}

int	allocate_images_enimies(t_general **g)
{
	int	l;
	int	w;

	(*g)->s[0] = mlx_xpm_file_to_image((*g)->mlx, "./ima/b/s0.xpm", &w, &l);
	(*g)->s[1] = mlx_xpm_file_to_image((*g)->mlx, "./ima/b/s1.xpm", &w, &l);
	(*g)->s[2] = mlx_xpm_file_to_image((*g)->mlx, "./ima/b/s2.xpm", &w, &l);
	(*g)->s[3] = mlx_xpm_file_to_image((*g)->mlx, "./ima/b/s3.xpm", &w, &l);
	(*g)->s[4] = mlx_xpm_file_to_image((*g)->mlx, "./ima/b/s4.xpm", &w, &l);
	(*g)->s[5] = mlx_xpm_file_to_image((*g)->mlx, "./ima/b/s5.xpm", &w, &l);
	(*g)->s[6] = mlx_xpm_file_to_image((*g)->mlx, "./ima/b/s6.xpm", &w, &l);
	(*g)->s[7] = mlx_xpm_file_to_image((*g)->mlx, "./ima/b/s7.xpm", &w, &l);
	(*g)->s[8] = mlx_xpm_file_to_image((*g)->mlx, "./ima/b/s8.xpm", &w, &l);
	(*g)->s[9] = mlx_xpm_file_to_image((*g)->mlx, "./ima/b/s9.xpm", &w, &l);
	(*g)->s[10] = mlx_xpm_file_to_image((*g)->mlx, "./ima/b/s10.xpm", &w, &l);
	(*g)->s[11] = mlx_xpm_file_to_image((*g)->mlx, "./ima/b/s11.xpm", &w, &l);
	(*g)->s[12] = mlx_xpm_file_to_image((*g)->mlx, "./ima/b/s12.xpm", &w, &l);
	if (!(*g)->s[0] || !(*g)->s[1] || !(*g)->s[2] || !(*g)->s[3] || !(*g)->s[4]
		|| !(*g)->s[5] || !(*g)->s[6] || !(*g)->s[7] || !(*g)->s[8]
		|| !(*g)->s[9] || !(*g)->s[10] || !(*g)->s[11] || !(*g)->s[12])
		return (1);
	return (0);
}
