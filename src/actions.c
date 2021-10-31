/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmota <marmota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:28:22 by mmota             #+#    #+#             */
/*   Updated: 2021/10/31 14:35:37 by marmota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	down(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y;
	if ((game->board[y + 1][x]) != '1')
	{
		++game->player.y;
		update_game_state(game, x, y);
	}
	if (game->board[y + 1][x] == 'E' && game->collectibles == 0)
		game_exit(game, "You Won");
}

void	right(t_game *game)
{
	int	x;
	int	y;

	game->player.direct = 0;
	x = game->player.x;
	y = game->player.y;
	if ((game->board[y][x + 1]) != '1')
	{
		++game->player.x;
		update_game_state(game, x, y);
	}
	if (game->board[y][x + 1] == 'E' && game->collectibles == 0)
		game_exit(game, "You Won");
}

void	up(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y;
	if ((game->board[y - 1][x]) != '1')
	{
		--game->player.y;
		update_game_state(game, x, y);
	}
	if (game->board[y - 1][x] == 'E' && game->collectibles == 0)
		game_exit(game, "You Won");
}

void	left(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y;
	game->player.direct = 1;
	if ((game->board[y][x - 1]) != '1')
	{
		--game->player.x;
		update_game_state(game, x, y);
	}
	if (game->board[y][x - 1] == 'E' && game->collectibles == 0)
		game_exit(game, "You Won");
}

int	handle_keypress(int key_code, t_game *game)
{
	if (key_code == MLX_KEY_ESC)
		x_close(game);
	if (key_code == MLX_KEY_S || key_code == MLX_KEY_DOWN)
		down(game);
	if (key_code == MLX_KEY_D || key_code == MLX_KEY_RIGHT)
		right(game);
	if (key_code == MLX_KEY_W || key_code == MLX_KEY_UP)
		up(game);
	if (key_code == MLX_KEY_A || key_code == MLX_KEY_LEFT)
		left(game);
	game->player.count++;
	player_animation(game);
	if (game->character_enemy != 0)
		enemy_actions(game, key_code);
	return (key_code);
}
