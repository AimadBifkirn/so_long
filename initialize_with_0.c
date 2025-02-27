/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_with_0.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abifkirn <abifkirn@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 09:42:33 by abifkirn          #+#    #+#             */
/*   Updated: 2025/02/27 14:13:08 by abifkirn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initial_images(t_general **general)
{
	(*general)->p_b[0] = NULL;
	(*general)->p_b[1] = NULL;
	(*general)->p_b[2] = NULL;
	(*general)->p_l[0] = NULL;
	(*general)->p_l[1] = NULL;
	(*general)->p_l[2] = NULL;
	(*general)->p_f[0] = NULL;
	(*general)->p_f[1] = NULL;
	(*general)->p_f[2] = NULL;
	(*general)->p_w[0] = NULL;
	(*general)->p_w[1] = NULL;
	(*general)->p_w[2] = NULL;
	(*general)->coin[0] = NULL;
	(*general)->coin[1] = NULL;
	(*general)->coin[2] = NULL;
	(*general)->coin[3] = NULL;
	(*general)->coin[4] = NULL;
	(*general)->coin[5] = NULL;
	(*general)->coin[6] = NULL;
	(*general)->door[0] = NULL;
	(*general)->door[1] = NULL;
	(*general)->wall = NULL;
	(*general)->back = NULL;
	(*general)->b_back = NULL;
}

void	initial_skeleton_mages(t_general **general)
{
	(*general)->s[0] = NULL;
	(*general)->s[1] = NULL;
	(*general)->s[2] = NULL;
	(*general)->s[3] = NULL;
	(*general)->s[4] = NULL;
	(*general)->s[5] = NULL;
	(*general)->s[6] = NULL;
	(*general)->s[7] = NULL;
	(*general)->s[8] = NULL;
	(*general)->s[9] = NULL;
	(*general)->s[10] = NULL;
	(*general)->s[11] = NULL;
	(*general)->s[12] = NULL;
}

void	initialize_everything_with_0(t_general **general)
{
	initial_images(general);
	initial_skeleton_mages(general);
	(*general)->mlx = NULL;
	(*general)->window = NULL;
	(*general)->map = NULL;
	(*general)->copy_map = NULL;
	(*general)->frame = 0;
	(*general)->coin_index = 0;
	(*general)->num_coin = 0;
	(*general)->anim_i = 0;
	(*general)->ske_i = 0;
	(*general)->score = 0;
}
