/*
	* Include the <mlx.h> header
	* mlx_init(): Establishes a connection to the correct graphical system and returns a 'void *'
		which holds the location of our current MLX instance. 
	* mlx_new_window(): Initializes a window
	** Open board; read it line-by-line "get_next_line()"; Store the height and width;
	** Store board into a string; free() the get_next_line() argument 'line'; close() board;

*/
#include "so_long.h"

void draw_board(t_game *game)
{
	int i = 0;
	int x = 0;
	int y = 0;

	printf("\n%i, %i\n", game->img_height, game->img_width);
	while(y < game->board_height)
	{
		while (x < game->board_width)
		{
			if (game->board_str[i] == '1')
			{
				game->relative_path = "./assets/path.xpm";
				game->img = mlx_xpm_file_to_image(game->mlx, game->relative_path, &game->img_width, &game->img_height);
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, x * 100, y * 100);
			}
			else if (game->board_str[i] == 'E')
			{
				game->relative_path = "./assets/Exit.xpm";
				game->img = mlx_xpm_file_to_image(game->mlx, game->relative_path, &game->img_width, &game->img_height);
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, x * 100, y * 100);
			}
			else if (game->board_str[i] == 'P')
			{
				game->relative_path = "./assets/character.xpm";
				game->img = mlx_xpm_file_to_image(game->mlx, game->relative_path, &game->img_width, &game->img_height);
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, x * 100, y * 100);
			}
			else if (game->board_str[i] == 'C')
			{
				game->relative_path = "./assets/collectibles.xpm";
				game->img = mlx_xpm_file_to_image(game->mlx, game->relative_path, &game->img_width, &game->img_height);
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, x * 100, y * 100);
			}
			++i;
			++x;
		}
		++y;
		x = 0;
	}
}

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
	printf("\n%s\n", game->board_str);
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
	game.mlx_win = mlx_new_window(game.mlx, game.board_width * 100, game.board_height * 100, "soLong");
	draw_board(&game);

	game.img = mlx_new_image(game.mlx, game.board_width, game.board_height);
	game.addr = mlx_get_data_addr(game.img, &game.bits_per_pixel, &game.line_length, &game.endian);
	//add_images(&game);
	mlx_loop(game.mlx);
}


