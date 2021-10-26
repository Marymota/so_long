#include "so_long.h"

int	board_elements(t_game *game)
{
	int	x;
	int	y;
	int	board[3];

	y = -1;
	while (++y < game->board_height)
	{
		x = -1;
		while (++x < game->board_width)
		{
			if (x < 3 && y == 0)
				board[x] = 0;
			if (game->board[y][x] == 'E')
				board[0] = 1;
			if (game->board[y][x] == 'P')
				++board[1];
			if (game->board[y][x] == 'C')
				board[2] = 1;
		}
	}
	x = -1;
	while (++x < 3)
		if (board[x] != 1)
			return (0);
	return (1);
}

int	board_close(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->board_height)
	{
		x = -1;
		while (++x < game->board_width)
			if ((y == 0 || x == 0) && (game->board[y][x] != '1'))
				return (0);
	}
	y = -1;
	while (++y < game->board_height)
		if (game->board[y][game->board_width - 1] != '1')
			return (0);
	x = -1;
	while (++x < game->board_width)
		if (game->board[game->board_height - 1][x] != '1')
			return (0);
	return (1);
}

void	init_img(t_game *game)
{
	game->relative_path_path = "./assets/path.xpm";
	game->path = mlx_xpm_file_to_image(game->mlx, game->relative_path_path, \
&game->img_width, &game->img_height);
	game->relative_path_wall = "./assets/wall.xpm";
	game->wall = mlx_xpm_file_to_image(game->mlx, game->relative_path_wall, \
&game->img_width, &game->img_height);
	game->relative_path_character_right = "./assets/player/right/player.xpm";
	game->character_right = mlx_xpm_file_to_image(game->mlx, game->relative_path_character_right, \
&game->img_width, &game->img_height);
	game->relative_path_character_left = "./assets/player/left/player.xpm";
	game->character_left = mlx_xpm_file_to_image(game->mlx, game->relative_path_character_left, \
&game->img_width, &game->img_height);
	game->relative_path_collectible = "./assets/collect/seed.xpm";
	game->collect = mlx_xpm_file_to_image(game->mlx, game->relative_path_collectible, \
&game->img_width, &game->img_height);
	game->relative_path_exit = "./assets/exit.xpm";
	game->exit = mlx_xpm_file_to_image(game->mlx, game->relative_path_exit, \
&game->img_width, &game->img_height);
	game->relative_path_enemy = "./assets/enemy/enemy.xpm";
	game->character_enemy = mlx_xpm_file_to_image(game->mlx, game->relative_path_enemy, \
&game->img_width, &game->img_height);
}

void	draw_board(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->board_height)
	{
		x = -1;
		while (++x < game->board_width)
		{
			if (game->board[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit, \
x * 100, y * 100);
			if (game->board[y][x] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->character_right, \
x * 100, y * 100);
				game->player.x = x;
				game->player.y = y;
			}
			if (game->board[y][x] == 'C')
			{
				game->collectibles++;
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->collect, \
x * 100, y * 100);
			}
			if (game->board[y][x] == 'X')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->character_enemy, \
x * 100, y * 100);
				game->enemy.x = x;
				game->enemy.y = y;
			}
		}
	}
}

void	draw_background(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->board_height)
	{
		x = -1;
		while (++x < game->board_width)
		{
			if (game->board[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall, \
x * 100, y * 100);
			else
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->path, \
x * 100, y * 100);
		}
	}
	counter_moves(game);
}
