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
	*** Add map error checking (Done)
	*** Add different sprites for different moves
	*** Add enemy
	*** Add screen moves count
	*** 

*/
#include "so_long.h"

int	handle_no_event(void *game)
{
	(void) game;
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		return (0);
	ft_memset(&game, 0, sizeof(t_game));
	read_board(&game, argv[1]);
	init_game(&game);
	init_board(&game);
	mlx_loop_hook(game.mlx, &handle_no_event, &game);
	mlx_hook(game.mlx_win, 2, (1L << 0), &handle_keypress, &game);
	mlx_loop(game.mlx);
	mlx_destroy_window(game.mlx, game.mlx_win);
	free(game.mlx);
	return (0);
}
