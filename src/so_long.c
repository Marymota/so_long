/*
RESOURCES:
	aurelienbrabant.fr/blog/getting-started-with-the-minilibx
	harm-smits.github.io/42docs/libs/minilibx
	github.com/AmberLawr/so_long
	xahlee.info/linux/linux_show_keycode_keysym.html

	* Include the <mlx.h> header
	* mlx_init(): Establishes a connection to the correct graphical system and returns a 'void *'
		which holds the location of our current MLX instance.
	* mlx_new_window(): Initializes a window
	** Open board; read it line-by-line "get_next_line()"; Store the height and width;
	** Store board into a string; free() the get_next_line() argument 'line'; close() board;
	*** Create path to XPM file and convert it to image before adding it to the display
	**** Add background tiles to the board
	**** Add sprites to the board
	***** move player sprite

	! I am iterating through the board using a string... and probrably should use a 2D array
	but I am not being able to convert it without segmentation fault...
		draw_board and read map needs to be re-writen for this...
		and then being able to "move" the player sprite

	! Player coordinates are inverted and that causes problems when changing tiles during movements...
		The problem was that I was sending the coordinates inverted in the convert_to_player()

	***	Smooth window (changing to another window, minimizing, etc);
	*** Close the window and quit the program when clicking in the red cross
	*** Add map error checking (Done)
	******BONUS****
	*** Add different sprites for different moves
	*** Add enemy
	*** Add screen moves count
	*** Add player animation on release (maybe)
	*** Exit in red cross - keycode 17 1L << 2 EVEN_EXIT_

	! Enemy colision not detected if there was a square between sprites before de colision...
	@ SOLVED "A" key does not work in movin enemies - if (keycode)
	@ Exit and seeds disapear if the enemy pass them
	@ Exit disapeares if I pass it before collecting all seeds
*/

#include "so_long.h"

void	init_vars(t_game *game)
{
	game->board = 0;
	game->board_width = 0;
	game->board_height = 0;
	game->collect = 0;
	game->collectibles = 0;
	game->collected = 0;
	game->character_enemy = 0;
	game->img_width = 0;
	game->img_height = 0;
	game->moves = 0;
	game->collect_flag = 0;
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
