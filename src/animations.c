/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmota <mmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:28:33 by mmota             #+#    #+#             */
/*   Updated: 2021/10/29 13:09:56 by mmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_animation(t_game *game)
{
	if (game->enemy.count > 4)
		game->enemy.count = 1;
	if (game->enemy.count == 1)
		game->relative_path_enemy = "./assets/enemy/enemy.xpm";
	else if (game->enemy.count == 2)
		game->relative_path_enemy = "./assets/enemy/enemy1.xpm";
	else if (game->enemy.count == 3)
		game->relative_path_enemy = "./assets/enemy/enemy2.xpm";
	else if (game->enemy.count == 4)
		game->relative_path_enemy = "./assets/enemy/enemy3.xpm";
	game->character_enemy = \
	mlx_xpm_file_to_image(game->mlx, \
	game->relative_path_enemy, &game->img_width, &game->img_height);
}

void	collectibles_animation(t_game *game)
{
	if (game->moves == 1)
		game->relative_path_collectible = "./assets/collect/seed.xpm";
	else if (game->moves == 2)
		game->relative_path_collectible = "./assets/collect/seed1.xpm";
	else if (game->moves == 4)
		game->relative_path_collectible = "./assets/collect/seed2.xpm";
	else if (game->moves == 8)
		game->relative_path_collectible = "./assets/collect/seed3.xpm";
	else if (game->moves == 16)
		game->relative_path_collectible = "./assets/collect/seed4.xpm";
	else if (game->moves == 32)
		game->relative_path_collectible = "./assets/collect/seed5.xpm";
}

void	player_animation(t_game *game)
{
	if (game->player.count > 4)
		game->player.count = 1;
	if (game->player.direct == 0)
		player_animations_right(game);
	else
		player_animations_left(game);
}

void	player_animations_right(t_game *game)
{
	if (game->player.count == 1)
		game->relative_path_character_right = \
	"./assets/player/right/player.xpm";
	else if (game->player.count == 2)
		game->relative_path_character_right = \
	"./assets/player/right/player1.xpm";
	else if (game->player.count == 3)
		game->relative_path_character_right = \
	"./assets/player/right/player2.xpm";
	else if (game->player.count == 4)
		game->relative_path_character_right = \
	"./assets/player/right/player3.xpm";
	game->character_right = mlx_xpm_file_to_image(game->mlx, \
	game->relative_path_character_right, \
	&game->img_width, &game->img_height);
}

void	player_animations_left(t_game *game)
{
	if (game->player.count == 1)
		game->relative_path_character_left = \
		"./assets/player/left/player.xpm";
	else if (game->player.count == 2)
		game->relative_path_character_left = \
		"./assets/player/left/player1.xpm";
	else if (game->player.count == 3)
		game->relative_path_character_left = \
		"./assets/player/left/player2.xpm";
	else if (game->player.count == 4)
		game->relative_path_character_left = \
		"./assets/player/left/player3.xpm";
	game->character_left = mlx_xpm_file_to_image(game->mlx, \
	game->relative_path_character_left, \
	&game->img_width, &game->img_height);
}
