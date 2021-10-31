/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmota <mmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:28:47 by mmota             #+#    #+#             */
/*   Updated: 2021/10/29 13:03:39 by mmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_board_form(t_game *game, char *line, size_t len)
{
	++game->board_height;
	game->board_width = ft_strlen(line);
	if (len != ft_strlen(line))
	{
		ft_putstr_fd("Error\nMap is not rectangular", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

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

void	count_board_units(t_game *game, char *board)
{
	int		fd;
	char	*line;
	size_t	line_size;

	line_size = 0;
	fd = open(board, O_RDONLY);
	if (!fd)
		game_exit(game, "No board");
	while (get_next_line(fd, &line))
	{
		if (!line_size)
			line_size = ft_strlen(line);
		check_board_form(game, line, line_size);
	}
	check_board_form(game, line, line_size);
	free(line);
	close(fd);
}
