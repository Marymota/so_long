/*
	* Include the <mlx.h> header
	* mlx_init(): Establishes a connection to the correct graphical system and returns a 'void *'
		which holds the location of our current MLX instance. 
	* mlx_new_window(): Initializes a window
	** Open map; read it line-by-line "get_next_line()"; Store the height and width;
	** Store map into a string; free() the get_next_line() argument 'line'; close() map;

*/
#include "so_long.h"

void add_images(t_game *game)
{
	int i = 0;
	int x = 0;
	int y = 0;

	while(y < 800)
	{
		while (x < 1000)
		{
			if (game->mapstr[i++] == '1')
			{
				game->relative_path = "./assets/path.xpm";
				game->img = mlx_xpm_file_to_image(game->mlx, game->relative_path, &game->img_width, &game->img_height);
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, x, y);
			}
			x += 100;
		}
		y += 100;
		x = 0;
	}

}

int main (int argc, char *argv[])
{
	int	fd;
	char *line;
	t_game game;

	int ret = 1;
	
	if (argc != 2)
		return (0);

	fd = open(argv[1], O_RDONLY);
	while (ret)
	{
		ret = get_next_line(fd, &line);
		game.mapstr = ft_strjoin(game.mapstr, line);
		game.map_height++;
	}
	game.map_width = ft_strlen(line);
	free(line);
	close(fd);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, game.map_width * 100, game.map_height * 100, "soLong");

	game.img = mlx_new_image(game.mlx, game.map_width, game.map_height);
	game.addr = mlx_get_data_addr(game.img, &game.bits_per_pixel, &game.line_length, &game.endian);
	add_images(&game);
	
	mlx_loop(game.mlx);
}


