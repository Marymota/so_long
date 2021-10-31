/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmota <mmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:28:57 by mmota             #+#    #+#             */
/*   Updated: 2021/10/29 16:06:16 by mmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_enemy(t_game *game, int x, int y)
{
	if (game->board[y][x] != '1' && game->board[y][x] != 'E')
	{
		game->enemy.y = y;
		game->enemy.x = x;
		if (game->board[y][x] != 'C')
			game->board[y][x] = 'X';
		return (1);
	}
	return (0);
}

void	enemy_actions(t_game *game, int key_code)
{
	int	x;
	int	y;
	int	update;

	x = game->enemy.x;
	y = game->enemy.y;
	update = 0;
	if (key_code == MLX_KEY_W || key_code == MLX_KEY_UP)
		update = move_enemy(game, x, y + 1);
	else if (key_code == MLX_KEY_D || key_code == MLX_KEY_RIGHT)
		update = move_enemy(game, x - 1, y);
	else if (key_code == MLX_KEY_S || key_code == MLX_KEY_DOWN)
		update = move_enemy(game, x, y - 1);
	else if (key_code == MLX_KEY_A || key_code == MLX_KEY_LEFT)
		update = move_enemy(game, x + 1, y);
	if (update)
		update_enemy(game, y, x);
}

void	init_enemy(t_game *game, int y, int x)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->character_enemy, \
x * 100, y * 100);
	game->enemy.x = x;
	game->enemy.y = y;
}
