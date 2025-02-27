/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abifkirn <abifkirn@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:04:27 by abifkirn          #+#    #+#             */
/*   Updated: 2025/02/27 14:54:54 by abifkirn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_coin_images(t_general **g)
{
	if ((*g)->coin[0])
		mlx_destroy_image((*g)->mlx, (*g)->coin[0]);
	if ((*g)->coin[1])
		mlx_destroy_image((*g)->mlx, (*g)->coin[1]);
	if ((*g)->coin[2])
		mlx_destroy_image((*g)->mlx, (*g)->coin[2]);
	if ((*g)->coin[3])
		mlx_destroy_image((*g)->mlx, (*g)->coin[3]);
	if ((*g)->coin[4])
		mlx_destroy_image((*g)->mlx, (*g)->coin[4]);
	if ((*g)->coin[5])
		mlx_destroy_image((*g)->mlx, (*g)->coin[5]);
	if ((*g)->coin[6])
		mlx_destroy_image((*g)->mlx, (*g)->coin[6]);
}

void	free_player_images(t_general **g)
{
	if ((*g)->p_w[0])
		mlx_destroy_image((*g)->mlx, (*g)->p_w[0]);
	if ((*g)->p_w[1])
		mlx_destroy_image((*g)->mlx, (*g)->p_w[1]);
	if ((*g)->p_w[2])
		mlx_destroy_image((*g)->mlx, (*g)->p_w[2]);
	if ((*g)->p_l[0])
		mlx_destroy_image((*g)->mlx, (*g)->p_l[0]);
	if ((*g)->p_l[1])
		mlx_destroy_image((*g)->mlx, (*g)->p_l[1]);
	if ((*g)->p_l[2])
		mlx_destroy_image((*g)->mlx, (*g)->p_l[2]);
	if ((*g)->p_f[0])
		mlx_destroy_image((*g)->mlx, (*g)->p_f[0]);
	if ((*g)->p_f[1])
		mlx_destroy_image((*g)->mlx, (*g)->p_f[1]);
	if ((*g)->p_f[2])
		mlx_destroy_image((*g)->mlx, (*g)->p_f[2]);
	if ((*g)->p_b[0])
		mlx_destroy_image((*g)->mlx, (*g)->p_b[0]);
	if ((*g)->p_b[1])
		mlx_destroy_image((*g)->mlx, (*g)->p_b[1]);
	if ((*g)->p_b[2])
		mlx_destroy_image((*g)->mlx, (*g)->p_b[2]);
}

void	free_door_images(t_general **g)
{
	if ((*g)->door[0])
		mlx_destroy_image((*g)->mlx, (*g)->door[0]);
	if ((*g)->door[1])
		mlx_destroy_image((*g)->mlx, (*g)->door[1]);
	if ((*g)->s[12])
		mlx_destroy_image((*g)->mlx, (*g)->s[12]);
}

void	free_enimie_images(t_general **g)
{
	if ((*g)->s[0])
		mlx_destroy_image((*g)->mlx, (*g)->s[0]);
	if ((*g)->s[1])
		mlx_destroy_image((*g)->mlx, (*g)->s[1]);
	if ((*g)->s[2])
		mlx_destroy_image((*g)->mlx, (*g)->s[2]);
	if ((*g)->s[3])
		mlx_destroy_image((*g)->mlx, (*g)->s[3]);
	if ((*g)->s[4])
		mlx_destroy_image((*g)->mlx, (*g)->s[4]);
	if ((*g)->s[5])
		mlx_destroy_image((*g)->mlx, (*g)->s[5]);
	if ((*g)->s[6])
		mlx_destroy_image((*g)->mlx, (*g)->s[6]);
	if ((*g)->s[7])
		mlx_destroy_image((*g)->mlx, (*g)->s[7]);
	if ((*g)->s[8])
		mlx_destroy_image((*g)->mlx, (*g)->s[8]);
	if ((*g)->s[9])
		mlx_destroy_image((*g)->mlx, (*g)->s[9]);
	if ((*g)->s[10])
		mlx_destroy_image((*g)->mlx, (*g)->s[10]);
	if ((*g)->s[11])
		mlx_destroy_image((*g)->mlx, (*g)->s[11]);
}

void	free_images(t_general **g)
{
	if ((*g)->wall)
		mlx_destroy_image((*g)->mlx, (*g)->wall);
	free_player_images(g);
	free_coin_images(g);
	free_enimie_images(g);
	free_door_images(g);
	if ((*g)->back)
		mlx_destroy_image((*g)->mlx, (*g)->back);
	if ((*g)->b_back)
		mlx_destroy_image((*g)->mlx, (*g)->b_back);
}
