/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmota <mmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:29:21 by mmota             #+#    #+#             */
/*   Updated: 2021/10/29 13:14:21 by mmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	counter_moves(t_game *game)
{
	char	*count;

	count = ft_itoa(game->moves);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall, 0, 0);
	mlx_string_put(game->mlx, game->mlx_win, 20, \
game->board_height + 50, 0x000000, "STEPS: ");
	mlx_string_put(game->mlx, game->mlx_win, 70, \
game->board_height + 50, 0x000000, count);
	free(count);
}

void	game_exit(t_game *game, char *message)
{
	int	i;

	ft_putstr_fd(message, 1);
	i = -1;
	while (++i < game->board_height)
		if (game->board && game->board[i])
			free(game->board[i]);
	if (game->board)
		free(game->board);
	if (game->mlx_win)
		free(game->mlx_win);
	if (game->mlx)
		free(game->mlx);
	exit(EXIT_SUCCESS);
}

int	x_close(t_game *game)
{
	int	i;

	if (game->mlx_win)
		free(game->mlx_win);
	i = -1;
	while (++i < game->board_height)
		if (game->board && game->board[i])
			free(game->board[i]);
	if (game->board)
		free(game->board);
	exit(EXIT_SUCCESS);
}
