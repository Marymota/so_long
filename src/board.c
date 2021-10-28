#include "so_long.h"

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

void	init_player(t_game *game, int y, int x)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->character_right, \
x * 100, y * 100);
	game->player.x = x;
	game->player.y = y;
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
			if (game->board[y][x] == 'C')
			{
				game->collectibles++;
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->collect, \
x * 100, y * 100);
			}
			if (game->board[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit, \
x * 100, y * 100);
			if (game->board[y][x] == 'P')
				init_player(game, y, x);
			if (game->board[y][x] == 'X')
				init_enemy(game, y, x);
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

void	read_board(t_game *game, char *board)
{
	int		fd;
	char	*line;
	int		ret;
	int		y;

	y = 0;
	count_board_units(game, board);
	ret = 1;
	fd = open(board, O_RDONLY);
	game->board = ft_calloc(game->board_height, sizeof(char *));
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ft_strlen(line) > 0)
			game->board[y++] = line;
		else
			free(line);
	}
	close(fd);
}

void	init_board(t_game *game)
{
	if (!board_close(game) || !board_elements(game))
	{
		ft_putstr_fd("Error\nGameboard is invalid", STDERR_FILENO);
		game_exit(game);
	}
	game->player.direct = 0;
	game->collectibles = 0;
	game->moves = 0;
	init_img(game);
	draw_background(game);
	draw_board(game);
}
