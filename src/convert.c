#include "so_long.h"

void	convert_to_exit(int past_tile_x, int past_tile_y, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit, \
past_tile_x * 100, past_tile_y * 100);
}

void	convert_to_player(int new_tile_x, int new_tile_y, t_game *game)
{
	if (game->player.direct)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->character_left, \
	new_tile_x * 100, new_tile_y * 100);
	else
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->character_right, \
	new_tile_x * 100, new_tile_y * 100);
}

void	convert_to_path(int past_tile_x, int past_tile_y, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->path, \
past_tile_x * 100, past_tile_y * 100);
}

void	convert_to_enemy(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->character_enemy, \
game->enemy.x * 100, game->enemy.y * 100);
}