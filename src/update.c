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

void	update_game_state(t_game *game, int x, int y)
{
	game->moves++;
	printf("p1 x: %i p1 y: %i\n", game->player.x, game->player.y);
	printf("e1 x: %i e1 y: %i\n", game->enemy.x, game->enemy.y);
	if (game->player.x == game->enemy.x && game->player.y == game->enemy.y)
	{
		game->end = 1;
		game_exit(game);
	}
	convert_to_path(x, y, game);
	update_map(y, x, game);
	convert_to_player(game->player.x, game->player.y, game);
}
