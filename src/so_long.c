/*
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
*/
#include "so_long.h"

int handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(game->mlx, game->mlx_win);
}

int handle_no_event(void *game)
{
	(void)game;
	return (0);
}

//**** Add sprites to the board
void draw_board(t_game *game)
{
	int i = 0;
	int x = 0;
	int y = 0;

	while(y < game->board_height)
	{
		while (x < game->board_width)
		{
			if (game->board_str[i] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall, x * 100, y * 100);
			else if (game->board_str[i] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit, x * 100, y * 100);
			else if (game->board_str[i] == 'P')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->character, x * 100, y * 100);
			else if (game->board_str[i] == 'C')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->collectible, x * 100, y * 100);
			++i;
			++x;
		}
		++y;
		x = 0;
	}
}

//**** Add background tiles to the board
void draw_path(t_game *game)
{
	int i = 0;
	int x = 0;
	int y = 0;

	while(y < game->board_height)
	{
		while (x < game->board_width)
		{
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->path, x * 100, y * 100);
			++i;
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
	game->collectible = mlx_xpm_file_to_image(game->mlx, game->relative_path_collectible, &game->img_width, &game->img_height);
	game->relative_path_exit ="./assets/Exit.xpm";
	game->exit = mlx_xpm_file_to_image(game->mlx, game->relative_path_exit, &game->img_width, &game->img_height);
}

//** Read the map .ber file and convert it to a string to easy iteration
void read_board(t_game *game, char *board)
{
	int	fd;
	char *line;
	int flag;

	flag = 1;
	fd = open(board, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (!flag)
			game->board_str = ft_strjoin(game->board_str, line);
		else
			game->board_str = line;
		flag = 0;
		++game->board_height;
	}
	game->board_str = ft_strjoin(game->board_str, line);
	++game->board_height;
	game->board_width = ft_strlen(line);
	free(line);
	close(fd);
}

int main (int argc, char *argv[])
{
	t_game game;
	
	if (argc != 2)
		return (0);
	ft_memset(&game, 0, sizeof(t_game));
	read_board(&game, argv[1]);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, (game.board_width * 100), (game.board_height * 100), "soLong");
	if (game.mlx_win == NULL)
	{
		free(game.mlx_win);
		exit(EXIT_FAILURE);
	}
	init_img(&game);
	draw_path(&game);
	draw_board(&game);

	mlx_loop_hook(game.mlx, &handle_no_event, &game);
	mlx_hook(game.mlx_win, KeyPress, KeyPressMask, &handle_keypress, &game);


	mlx_loop(game.mlx);

	

	mlx_destroy_window(game.mlx, game.mlx_win);
	free(game.mlx);
	return (0);
}


