/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmota <marmota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:28:14 by mmota             #+#    #+#             */
/*   Updated: 2021/10/31 14:33:47 by marmota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_collectibles(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->board_height)
	{
		x = -1;
		while (++x < game->board_width)
		{
			if (game->board[y][x] == 'C')
			{
				if (game->enemy.x != x && game->enemy.y != y)
				{
					mlx_put_image_to_window(game->mlx, game->mlx_win, \
					game->collect, x * 100, y * 100);
					game->collect = mlx_xpm_file_to_image(game->mlx, \
game->relative_path_collectible, &game->img_width, &game->img_height);
				}
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
	if (game->board[game->player.y][game->player.x] != 'E')
	{
		game->board[game->player.y][game->player.x] = 'P';
		game->board[past_tile_y][past_tile_x] = '0';
	}
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
		game_exit(game, "You died");
	}
	game->enemy.count++;
	if (game->character_enemy != 0)
		enemy_animation(game);
	if (game->board[y][x] != 'C')
		convert_to_path(x, y, game);
	else if (game->board[y][x] == 'C')
	{
		convert_to_path(x, y, game);
		convert_to_collectible(x, y, game);
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->character_enemy, \
game->enemy.x * 100, game->enemy.y * 100);
}

void	update_game_state(t_game *game, int x, int y)
{
	game->moves++;
	counter_moves(game);
	if (game->player.x == game->enemy.x && game->player.y == game->enemy.y)
	{
		game->end = 1;
		game_exit(game, "You died");
	}
	if (game->board[y][x] != 'E')
	{
		convert_to_path(x, y, game);
		update_map(y, x, game);
	}
	else if (game->board[y][x] == 'E')
		convert_to_exit(x, y, game);
	convert_to_player(game->player.x, game->player.y, game);
}
