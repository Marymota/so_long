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
	game->relative_path = "./chicken.xpm";
	game->img_width = 1;
	game->img_height = 20;
	game->img = mlx_xpm_file_to_image(game->mlx, game->relative_path, &game->img_width, &game->img_height);
}

void add_map(t_game *game)
{
	
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
		game.mapstr = ft_strjoin(game.mapstr, "\n");
		game.map_height++;
	}
	game.map_width = ft_strlen(line);
	printf("\nwidth: %i, height: %i\n", game.map_width, game.map_height);
	printf("\n%s\n", game.mapstr);
	free(line);
	close(fd);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, game.map_width * 100, game.map_height * 100, "soLong");
	game.img = mlx_new_image(game.mlx, 1920, 1080);
	game.addr = mlx_get_data_addr(game.img, &game.bits_per_pixel, &game.line_length, &game.endian);
	add_images(&game);

		
	mlx_put_image_to_window(game.mlx, game.mlx_win, game.img, 15, 15);
	mlx_put_image_to_window(game.mlx, game.mlx_win, game.img, 150, 15);
	mlx_loop(game.mlx);
}


