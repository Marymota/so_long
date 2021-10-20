#include "so_long.h"

void	convert_to_player(int new_tile_x, int new_tile_y, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->character, \
new_tile_x * 100, new_tile_y * 100);
}

void	convert_to_path(int past_tile_x, int past_tile_y, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->path, \
past_tile_x * 100, past_tile_y * 100);
}

void	update_map(int past_tile_y, int past_tile_x, t_game *game)
{
	if (game->board[game->player.y][game->player.x] == 'C')
	{
		++game->collected;
		--game->collectibles;
		if (game->collectibles == 0)
			game->end = 1;
	}
	game->board[game->player.y][game->player.x] = 'P';
	game->board[past_tile_y][past_tile_x] = '0';
	printf("%d\n", game->moves);
}

void	update_game_state(t_game *game, int x, int y)
{
	game->moves++;
	convert_to_path(x, y, game);
	update_map(y, x, game);
	convert_to_player(game->player.x, game->player.y, game);
}
