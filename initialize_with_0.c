/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_with_0.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abifkirn <abifkirn@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 09:42:33 by abifkirn          #+#    #+#             */
/*   Updated: 2025/02/27 12:06:16 by abifkirn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initial_images(t_general **general)
{
	(*general)->player_b[0] = NULL;
	(*general)->player_b[1] = NULL;
	(*general)->player_b[2] = NULL;
	(*general)->player_l[0] = NULL;
	(*general)->player_l[1] = NULL;
	(*general)->player_l[2] = NULL;
	(*general)->player_f[0] = NULL;
	(*general)->player_f[1] = NULL;
	(*general)->player_f[2] = NULL;
	(*general)->player_w[0] = NULL;
	(*general)->player_w[1] = NULL;
	(*general)->player_w[2] = NULL;
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
	(*general)->background = NULL;
	(*general)->black_backg = NULL;
}

void	initial_skeleton_mages(t_general **general)
{
	(*general)->skeleton[0] = NULL;
	(*general)->skeleton[1] = NULL;
	(*general)->skeleton[2] = NULL;
	(*general)->skeleton[3] = NULL;
	(*general)->skeleton[4] = NULL;
	(*general)->skeleton[5] = NULL;
	(*general)->skeleton[6] = NULL;
	(*general)->skeleton[7] = NULL;
	(*general)->skeleton[8] = NULL;
	(*general)->skeleton[9] = NULL;
	(*general)->skeleton[10] = NULL;
	(*general)->skeleton[11] = NULL;
	(*general)->skeleton[12] = NULL;
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
