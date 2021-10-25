#include "so_long.h"

void enemy_animation(t_game *game)
{
	if (game->enemy.count > 4)
		game->enemy.count = 1;
	if (game->enemy.count == 1)
		game->relative_path_enemy = "./assets/enemy/enemy.xpm";
	else if (game->enemy.count == 2)
		game->relative_path_enemy = "./assets/enemy/enemy1.xpm";
	else if (game->enemy.count == 3)
		game->relative_path_enemy = "./assets/enemy/enemy2.xpm";
	else if (game->enemy.count == 4)
		game->relative_path_enemy = "./assets/enemy/enemy3.xpm";
	game->character_enemy = mlx_xpm_file_to_image(game->mlx, game->relative_path_enemy, \
&game->img_width, &game->img_height);
}

void collectibles_animation(t_game *game)
{
	if (game->moves == 1)
		game->relative_path_collectible = "./assets/collect/seed.xpm";
	else if (game->moves == 2)
		game->relative_path_collectible = "./assets/collect/seed1.xpm";
	else if (game->moves == 4)
		game->relative_path_collectible = "./assets/collect/seed2.xpm";
	else if (game->moves == 8)
		game->relative_path_collectible = "./assets/collect/seed3.xpm";
	else if (game->moves == 16)
		game->relative_path_collectible = "./assets/collect/seed4.xpm";
	else if (game->moves == 32)
		game->relative_path_collectible = "./assets/collect/seed5.xpm";
}
