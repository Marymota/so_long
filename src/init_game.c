#include "so_long.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->board_width * 100, \
game->board_height * 100, "soLong");
	if (!game->mlx || !game->mlx_win)
	{
		ft_putstr_fd("Error\nGame can't be initiated", STDERR_FILENO);
		free(game->mlx_win);
		exit(EXIT_FAILURE);
	}
}

void	check_board_form(t_game *game, char *line, size_t len)
{
	++game->board_height;
	game->board_width = ft_strlen(line);
	printf("%i\n", (int)ft_strlen(line));
	if (len != ft_strlen(line))
	{
		ft_putstr_fd("Error\nMap is not rectangular", 2);
		exit(EXIT_FAILURE);
	}
}

void	count_board_units(t_game *game, char *board)
{
	int		fd;
	char	*line;
	size_t	line_size;

	line_size = 0;
	fd = open(board, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (!line_size)
			line_size = ft_strlen(line);
		if (line && *line)
			game->board_str = ft_strjoin(game->board_str, line);
		else
		{
			ft_putstr_fd("Error\nBoard can't be read", 1);
			exit(EXIT_FAILURE);
		}
		check_board_form(game, line, line_size);
	}
	check_board_form(game, line, line_size);
	free(line);
	close(fd);
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
		free(game->mlx_win);
		exit(EXIT_FAILURE);
	}
	game->player.direct = 0;
	game->collectibles = 0;
	game->moves = 0;
	init_img(game);
	draw_background(game);
	draw_board(game);
}
