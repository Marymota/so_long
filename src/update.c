#include "so_long.h"

void update_collectibles(t_game *game)
{
	int y;
	int x;

	y = -1;
	while (++y < game->board_height)
	{
		x = -1;
		while (++x < game->board_width)
		{
			if (game->board[y][x] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->collect, \
x * 100, y * 100);
				game->collect = mlx_xpm_file_to_image(game->mlx, game->relative_path_collectible, \
&game->img_width, &game->img_height);
			}
		}
	}
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
	ft_putnbr_fd(game->moves, 1);
	ft_putchar_fd('\n', 1);
	collectibles_animation(game);
	update_collectibles(game);
}

void	update_enemy(t_game *game, int y, int x)
{
	if (game->player.x == game->enemy.x && game->player.y == game->enemy.y)
	{
		game->end = 1;
		game_exit(game);
	}
	game->enemy.count++;
	enemy_animation(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->character_enemy, \
game->enemy.x * 100, game->enemy.y * 100);
	convert_to_path(x, y, game);
}

void	update_game_state(t_game *game, int x, int y)
{
	game->moves++;
	counter_moves(game);
	if (game->player.x == game->enemy.x && game->player.y == game->enemy.y)
	{
		game->end = 1;
		game_exit(game);
	}
	convert_to_path(x, y, game);
	update_map(y, x, game);
	convert_to_player(game->player.x, game->player.y, game);
}
