#include "so_long.h"

int	allocate_imags(t_general **general)
{
	int	lenght;
	int	width;
	(*general)->wall = mlx_xpm_file_to_image((*general)->mlx, "./imags/wall.xpm", &width, &lenght);
	(*general)->player_l[0] = mlx_xpm_file_to_image((*general)->mlx, "./imags/player_l.xpm", &width, &lenght);
	(*general)->player_l[1] = mlx_xpm_file_to_image((*general)->mlx, "./imags/player_l2.xpm", &width, &lenght);
	(*general)->player_l[2] = mlx_xpm_file_to_image((*general)->mlx, "./imags/player_l3.xpm", &width, &lenght);
	(*general)->player_f[0] = mlx_xpm_file_to_image((*general)->mlx, "./imags/player_f.xpm", &width, &lenght);
	(*general)->player_f[1] = mlx_xpm_file_to_image((*general)->mlx, "./imags/player_f2.xpm", &width, &lenght);
	(*general)->player_f[2] = mlx_xpm_file_to_image((*general)->mlx, "./imags/player_f3.xpm", &width, &lenght);
	(*general)->player_w[0] = mlx_xpm_file_to_image((*general)->mlx, "./imags/player_w.xpm", &width, &lenght);
	(*general)->player_w[1] = mlx_xpm_file_to_image((*general)->mlx, "./imags/player_w2.xpm", &width, &lenght);
	(*general)->player_w[2] = mlx_xpm_file_to_image((*general)->mlx, "./imags/player_w3.xpm", &width, &lenght);
	(*general)->player_b[0] = mlx_xpm_file_to_image((*general)->mlx, "./imags/player_b.xpm", &width, &lenght);
	(*general)->player_b[1] = mlx_xpm_file_to_image((*general)->mlx, "./imags/player_b2.xpm", &width, &lenght);
	(*general)->player_b[2] = mlx_xpm_file_to_image((*general)->mlx, "./imags/player_b3.xpm", &width, &lenght);
	(*general)->background = mlx_xpm_file_to_image((*general)->mlx, "./imags/background.xpm", &width, &lenght);
	(*general)->black_backg = mlx_xpm_file_to_image((*general)->mlx, "./imags/black_backg.xpm", &width, &lenght);
	if (!(*general)->player_b[0] || !(*general)->player_b[1] || !(*general)->player_b[2] || !(*general)->player_w[0]
		|| !(*general)->player_w[1] || !(*general)->player_w[2] || !(*general)->player_f[0] || !(*general)->player_f[1]
		|| !(*general)->player_f[2] || !(*general)->player_l[0] || !(*general)->player_l[1] || !(*general)->player_l[2]
		|| !(*general)->black_backg)
		return (1);
	return (0);
}

int allocate_imags_coins(t_general **general)
{
	int	lenght;
	int	width;
	(*general)->coin[0] = mlx_xpm_file_to_image((*general)->mlx, "./imags/coins/coin0.xpm", &width, &lenght);
	(*general)->coin[1] = mlx_xpm_file_to_image((*general)->mlx, "./imags/coins/coin1.xpm", &width, &lenght);
	(*general)->coin[2] = mlx_xpm_file_to_image((*general)->mlx, "./imags/coins/coin2.xpm", &width, &lenght);
	(*general)->coin[3] = mlx_xpm_file_to_image((*general)->mlx, "./imags/coins/coin3.xpm", &width, &lenght);
	(*general)->coin[4] = mlx_xpm_file_to_image((*general)->mlx, "./imags/coins/coin4.xpm", &width, &lenght);
	(*general)->coin[5] = mlx_xpm_file_to_image((*general)->mlx, "./imags/coins/coin5.xpm", &width, &lenght);
	(*general)->coin[6] = mlx_xpm_file_to_image((*general)->mlx, "./imags/coins/coin6.xpm", &width, &lenght);
	if (!(*general)->coin[0] || !(*general)->coin[1] || !(*general)->coin[2] || !(*general)->coin[3]
		 || !(*general)->coin[4] || !(*general)->coin[5] || !(*general)->coin[6])
		return (1);
	return (0);
}

int	allocate_images_door(t_general **general)
{
	int	lenght;
	int	width;
	(*general)->door[0] = mlx_xpm_file_to_image((*general)->mlx, "./imags/door/door0.xpm", &width, &lenght);
	(*general)->door[1] = mlx_xpm_file_to_image((*general)->mlx, "./imags/door/door3.xpm", &width, &lenght);
	if (!(*general)->door[0] || !(*general)->door[1])
		return (1);
	return (0);
}
int	allocate_images_enimies(t_general **general)
{
	int	lenght;
	int	width;
	(*general)->skeleton[0] = mlx_xpm_file_to_image((*general)->mlx, "./imags/enimies/skeleton0.xpm", &width, &lenght);
	(*general)->skeleton[1] = mlx_xpm_file_to_image((*general)->mlx, "./imags/enimies/skeleton1.xpm", &width, &lenght);
	(*general)->skeleton[2] = mlx_xpm_file_to_image((*general)->mlx, "./imags/enimies/skeleton2.xpm", &width, &lenght);
	(*general)->skeleton[3] = mlx_xpm_file_to_image((*general)->mlx, "./imags/enimies/skeleton3.xpm", &width, &lenght);
	(*general)->skeleton[4] = mlx_xpm_file_to_image((*general)->mlx, "./imags/enimies/skeleton4.xpm", &width, &lenght);
	(*general)->skeleton[5] = mlx_xpm_file_to_image((*general)->mlx, "./imags/enimies/skeleton5.xpm", &width, &lenght);
	(*general)->skeleton[6] = mlx_xpm_file_to_image((*general)->mlx, "./imags/enimies/skeleton6.xpm", &width, &lenght);
	(*general)->skeleton[7] = mlx_xpm_file_to_image((*general)->mlx, "./imags/enimies/skeleton7.xpm", &width, &lenght);
	(*general)->skeleton[8] = mlx_xpm_file_to_image((*general)->mlx, "./imags/enimies/skeleton8.xpm", &width, &lenght);
	(*general)->skeleton[9] = mlx_xpm_file_to_image((*general)->mlx, "./imags/enimies/skeleton9.xpm", &width, &lenght);
	(*general)->skeleton[10] = mlx_xpm_file_to_image((*general)->mlx, "./imags/enimies/skeleton10.xpm", &width, &lenght);
	(*general)->skeleton[11] = mlx_xpm_file_to_image((*general)->mlx, "./imags/enimies/skeleton11.xpm", &width, &lenght);
	(*general)->skeleton[12] = mlx_xpm_file_to_image((*general)->mlx, "./imags/enimies/skeleton12.xpm", &width, &lenght);
	if (!(*general)->skeleton[0] || !(*general)->skeleton[1] || !(*general)->skeleton[2] || !(*general)->skeleton[3] || !(*general)->skeleton[4]
		|| !(*general)->skeleton[5] || !(*general)->skeleton[6] || !(*general)->skeleton[7] || !(*general)->skeleton[8]
		|| !(*general)->skeleton[9] || !(*general)->skeleton[10] || !(*general)->skeleton[11] || !(*general)->skeleton[12])
		return (1);
	return (0);
}
