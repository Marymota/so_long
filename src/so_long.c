/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmota <mmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:29:11 by mmota             #+#    #+#             */
/*   Updated: 2021/10/29 13:13:18 by mmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_vars(t_game *game)
{
	game->board = 0;
	game->board_width = 0;
	game->board_height = 0;
	game->character_enemy = 0;
	game->img_width = 0;
	game->img_height = 0;
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
	game->character_right = mlx_xpm_file_to_image(game->mlx, \
	game->relative_path_character_right, &game->img_width, &game->img_height);
	game->relative_path_character_left = "./assets/player/left/player.xpm";
	game->character_left = mlx_xpm_file_to_image(game->mlx, \
	game->relative_path_character_left, &game->img_width, &game->img_height);
	game->relative_path_collectible = "./assets/collect/seed.xpm";
	game->collect = mlx_xpm_file_to_image(game->mlx, \
	game->relative_path_collectible, &game->img_width, &game->img_height);
	game->relative_path_exit = "./assets/exit.xpm";
	game->exit = mlx_xpm_file_to_image(game->mlx, game->relative_path_exit, \
&game->img_width, &game->img_height);
	game->relative_path_enemy = "./assets/enemy/enemy.xpm";
	game->character_enemy = mlx_xpm_file_to_image(game->mlx, \
	game->relative_path_enemy, &game->img_width, &game->img_height);
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->board_width * 100, \
game->board_height * 100, "soLong");
	if (!game->mlx || !game->mlx_win)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		game_exit(game, "Game can't be initiated");
	}
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		return (0);
	init_vars(&game);
	read_board(&game, argv[1]);
	init_game(&game);
	init_board(&game);
	mlx_hook(game.mlx_win, 17, (1L << 2), &x_close, &game);
	mlx_hook(game.mlx_win, 2, (1L << 0), &handle_keypress, &game);
	mlx_loop(game.mlx);
	return (0);
}
