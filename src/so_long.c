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
	
	*** Add map error checking
	*** Add different sprites for different moves
	*** Add enemy
	*** Add screen moves count
	*** 

*/
#include "so_long.h"

void game_exit(t_game *game)
{
	if (game->end)
	{
		printf("Exit\n");
		exit(EXIT_SUCCESS);
	}
}

void printf_board(t_game *game)
{
	int x;
	printf("**** read board *****\n******************\n");
	int y = 0;
	while (y < game->board_height)
	{
		x = 0;
		while (x < game->board_width)
		{
			printf("%c", game->board[y][x]);
			x++;
		}
		y++;
		printf("%c", '\n');
	}
	printf("%c", '\n');
}

void convert_to_player(int new_tile_x, int new_tile_y, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->character, new_tile_x * 100, new_tile_y * 100);
}

void convert_to_path(int past_tile_x, int past_tile_y, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->path, past_tile_x * 100, past_tile_y * 100);
}

void update_map(int past_tile_y, int past_tile_x, t_game *game)
{
	if (game->board[game->player.y][game->player.x] == 'C')
	{
		++game->collected;
		--game->collectibles;
		//printf("collected: %i collectible: %i\n", game->collected, game->collectibles);
		if (game->collectibles == 0)
			game->end = 1;
	}
	game->board[game->player.y][game->player.x] = 'P';
	game->board[past_tile_y][past_tile_x] = '0';
	printf("%d\n", game->moves);
}

void down(t_game *game)
{
	int x;
	int y;
	
	//printf("down\n");
	x = game->player.x;
	y = game->player.y;
	if ((game->board[y + 1][x]) != '1' && ((game->board[y + 1][x]) != 'E'))
	{
		game->moves++;
		++game->player.y;
		convert_to_path(x, y, game);
		update_map(y, x, game);
		convert_to_player(game->player.x, game->player.y, game);
	}
	if (game->board[y + 1][x] == 'E')
		game_exit(game);	
}

void right(t_game *game)
{
	int x;
	int y;
	
	//printf("right\n");
	x = game->player.x;
	y = game->player.y;
	
	if ((game->board[y][x + 1]) != '1' && ((game->board[y][x + 1]) != 'E'))
	{
		game->moves++;
		++game->player.x;
		convert_to_path(x, y, game);
		update_map(y, x, game);
		convert_to_player(game->player.x, game->player.y, game);
	}
	if (game->board[y][x + 1] == 'E')
		game_exit(game);	
}

void up(t_game *game)
{
	int x;
	int y;
	
	//printf("up\n");
	x = game->player.x;
	y = game->player.y;

	if ((game->board[y - 1][x]) != '1' && ((game->board[y - 1][x]) != 'E'))
	{
		game->moves++;
		--game->player.y;
		convert_to_path(x, y, game);
		update_map(y, x, game);
		convert_to_player(game->player.x, game->player.y, game);
	}
	if (game->board[y - 1][x] == 'E')
		game_exit(game);	
}

void left(t_game *game)
{
	int x;
	int y;
	
	//printf("left\n");
	x = game->player.x;
	y = game->player.y;
	if ((game->board[y][x - 1]) != '1' && ((game->board[y][x - 1]) != 'E'))
	{
		game->moves++;
		--game->player.x;
		convert_to_path(x, y, game);
		update_map(y, x, game);
		convert_to_player(game->player.x, game->player.y, game);
	}
	if (game->board[y][x - 1] == 'E')
		game_exit(game);	
}

int handle_no_event(void *game)
{
	(void) game;
	return (0);
}

// Print the key that was selected
int handle_keypress(int key_code, t_game *game)
{
	if (key_code == 53)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		exit(EXIT_SUCCESS);
	}
	if (key_code == 1) //linux 115 mac 1
	{
		//printf("Keypress: %d\n", key_code);
		down(game);	
	}
	if (key_code == 2) //linux 100 mac 2
	{
		//printf("Keypress: %d\n", key_code);
		right(game);
	}
	if (key_code == 13) //linux 119 mac 13
	{
		//printf("Keypress: %d\n", key_code);
		up(game);
	}
	if (key_code == 0) //linux 97 mac 0
	{
		//printf("Keypress: %d\n", key_code);
		left(game);
	}
	return (0);
}

//**** Add sprites to the board
void draw_board(t_game *game)
{
	int x = 0;
	int y = 0;
	game->collectibles = 0;
	game->moves = 0;
	while(y < game->board_height)
	{
		x = 0;
		while (x < game->board_width)
		{
			//printf("%c", game->board[y][x]);
			if (game->board[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit, x * 100, y * 100);
			if (game->board[y][x] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->character, x * 100, y * 100);
				game->player.x = x;
				game->player.y = y;
			}
			if (game->board[y][x] == 'C')
			{
				game->collectibles++;
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->collect, x * 100, y * 100);
			}
			++x;
		}
		++y;
	}
}

//**** Add background tiles to the board
void draw_background(t_game *game)
{
	int x = 0;
	int y = 0;
	
	while(y < game->board_height)
	{
		while (x < game->board_width)
		{
			if (game->board[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall, x * 100, y * 100);
			else 
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->path, x * 100, y * 100);
			++x;
		}
		++y;
		x = 0;
	}
}

//*** Create path to XPM file and convert it to image before adding it to the display
void init_img(t_game *game)
{
	game->relative_path_path = "./newassets/wall.xpm";
	game->path = mlx_xpm_file_to_image(game->mlx, game->relative_path_path, &game->img_width, &game->img_height);
	game->relative_path_wall = "./assets/path.xpm";
	game->wall = mlx_xpm_file_to_image(game->mlx, game->relative_path_wall, &game->img_width, &game->img_height);
	game->relative_path_character = "./newassets/character_small_1.xpm";
	game->character = mlx_xpm_file_to_image(game->mlx, game->relative_path_character, &game->img_width, &game->img_height);
	game->relative_path_collectible = "./newassets/seedsr.xpm";
	game->collect = mlx_xpm_file_to_image(game->mlx, game->relative_path_collectible, &game->img_width, &game->img_height);
	game->relative_path_exit ="./assets/Exit.xpm";
	game->exit = mlx_xpm_file_to_image(game->mlx, game->relative_path_exit, &game->img_width, &game->img_height);
}

void count_board_units(t_game *game, char *board)
{
	int	fd;
	char *line;

	fd = open(board, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (line && *line)
			game->board_str = ft_strjoin(game->board_str, line);
		else
			ft_putstr_fd("Error\nBoard can't be read", 1);
		++game->board_height;
	}
	++game->board_height;
	game->board_width = ft_strlen(line);
	free(line);
	close(fd);
}

//** Read the map .ber file and convert it to a string to easy iteration
void read_board(t_game *game, char *board)
{
	int	fd;
	char *line;
	int ret;
	int y;

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

int main (int argc, char *argv[])
{
	t_game game;
	
	if (argc != 2)
		return (0);
	ft_memset(&game, 0, sizeof(t_game));
	
	read_board(&game, argv[1]);
	if (!(game.mlx = mlx_init()))
		return (-1);
	
	if (!(game.mlx_win = mlx_new_window(game.mlx, (game.board_width * 100), (game.board_height * 100), "soLong")))
	{
		free(game.mlx_win);
		exit(EXIT_FAILURE);
	}
	init_img(&game);
	draw_background(&game);
	draw_board(&game);
	/* Setup hooks */
	mlx_loop_hook(game.mlx, &handle_no_event, &game);
	mlx_hook(game.mlx_win, 2, (1L<<0), &handle_keypress, &game);
	mlx_loop(game.mlx);
	mlx_destroy_window(game.mlx, game.mlx_win);
	//mlx_destroy_display(game.mlx);
	free(game.mlx);
	return (0);
}


