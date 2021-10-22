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
	if (game->moves == 2)
		game->relative_path_collectible = "./assets/seeds/seed1.xpm";
	else if (game->moves == 2)
		game->relative_path_collectible = "./assets/seeds/seed2.xpm";
	else if (game->moves == 4)
		game->relative_path_collectible = "./assets/seeds/seed3.xpm";
	else if (game->moves == 8)
		game->relative_path_collectible = "./assets/seeds/seed4.xpm";
	else if (game->moves == 16)
		game->relative_path_collectible = "./assets/seeds/seed5.xpm";
	update_collectibles(game);
}

void	update_game_state(t_game *game, int x, int y)
{
	game->moves++;
	convert_to_path(x, y, game);
	update_map(y, x, game);
	convert_to_player(game->player.x, game->player.y, game);
}
