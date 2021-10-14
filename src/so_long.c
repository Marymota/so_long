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
		
*/
#include "so_long.h"



void convert_to_player(int y, int x, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->character, x * 100, y * 100);
}

void convert_to_path(int y, int x, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->path, x * 100, y * 100);
}


void update_curr(int y, int x, t_game *game)
{
	int y_next;
	int x_next;

	y_next = game->player.y;
	x_next = game->player.x;
	convert_to_path(y, x, game);
	convert_to_player(x_next, y_next, game);
} 

void update_map(int y, int x, t_game *game)
{
	int y_next;
	int x_next;

	y_next = game->player.y;
	x_next = game->player.x;
	if (game->board[x][y] == 'E')
	{
		game->board[x][y] = 'E';
		game->board[y_next][x_next] = 'P';
	}
	else
	{
		game->board[x][y] = '0';
		game->board[x_next][y_next] = 'P';
	}
}

void down(t_game *game)
{
	int y;
	int x;

	y = game->player.y;
	x = game->player.x;
	
	if (game->board[y + 1][x] == '0')
	{	
		++game->player.y;
		update_map(y, x, game);
		update_curr(y, x, game);
	}
}

int handle_no_event(void *game)
{
	(void) game;
	return (0);
}

// Print the key that was selected
int handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (keysym == 115)
		printf("\n%c\n", game->board[0][0]);
	printf("Keypress: %d\n", keysym);
	return (0);
}

//**** Add sprites to the board
void draw_board(t_game *game)
{
	int x = 0;
	int y = 0;
	printf("**** draw board *****\n******************\n");
	while(y < game->board_height)
	{
		x = 0;
		while (x < game->board_width)
		{
			printf("%c", game->board[y][x]);
			if (game->board[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall, x * 100, y * 100);
			if (game->board[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit, x * 100, y * 100);
			if (game->board[y][x] == 'P')
			{
				game->player.x = x;
				game->player.y = y;
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->character, x * 100, y * 100);
			}
			if (game->board[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->collectible, x * 100, y * 100);
			++x;
		}
		printf("%c", '\n');
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
	game->collectible = mlx_xpm_file_to_image(game->mlx, game->relative_path_collectible, &game->img_width, &game->img_height);
	game->relative_path_exit ="./assets/Exit.xpm";
	game->exit = mlx_xpm_file_to_image(game->mlx, game->relative_path_exit, &game->img_width, &game->img_height);
}

void count_board_units(t_game *game, char *board)
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
	int x;

	y = 0;
	count_board_units(game, board);
	ret = 1;
	fd = open(board, O_RDONLY);
	game->board = ft_calloc(game->board_height, sizeof(char *));
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ft_strlen(line) > 0)
			game->board[y] = line;
		++y;
	}
	printf("**** read board *****\n******************\n");
	y = 0;
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
	mlx_hook(game.mlx_win, KeyPress, KeyPressMask, &handle_keypress, &game);

	mlx_loop(game.mlx);
	mlx_destroy_display(game.mlx);
	free(game.mlx);
	return (0);
}


