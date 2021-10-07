/*
	Include the <mlx.h> header
	mlx_init(): Establishes a connection to the correct graphical system and returns a 'void *'
		which holds the location of our current MLX instance. 
	mlx_new_window(): Initializes a window
*/
#include <stdio.h>
#include <fcntl.h>
#include <mlx.h>
#include "../libs/libft/src/libft.h"

typedef struct s_game {
	char	**map;
	int		img_height;
	int 	img_width;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_game;


int main (int argc, char *argv[])
{
	int	fd;
	char *line;
	t_game game;
	void *mlx;
	void *mlx_win;
	char *relative_path = "./chicken.xpm";
	int img_width = 1;
	int img_height = 20;
	int ret = 1;

	if (argc != 2)
		return (0);

	fd = open(argv[1], O_RDONLY);
	while (ret)
	{
		ret = get_next_line(fd, &line);
		printf("%s\n", line);
	}
	
	close(fd);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1000, "Hello World!");
	game.img = mlx_new_image(mlx, 1920, 1080);

	game.addr = mlx_get_data_addr(game.img, &game.bits_per_pixel, &game.line_length, &game.endian);

	game.img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	//draw_square(&img, 250, 250, 0x00FF0000);		
	//draw_triangle(&img, 150, 150, 0x00FF0000);		
	mlx_put_image_to_window(mlx, mlx_win, game.img, 15, 15);
	mlx_put_image_to_window(mlx, mlx_win, game.img, 150, 15);
	mlx_loop(mlx);
}

//static void my_mlx_pixel_put(t_data *data, int x, int y, int color)
//{
//	char *dst;
//
//	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//	*(unsigned int*)dst = color;
//}

//void draw_square(t_data *data, int x, int y, int color)
//{
//	int i = 0;
//	int j = 0;
//
//	while (i < 100)
//	{
//		j = 0;
//		while (j < 100)
//		{
//			my_mlx_pixel_put(&data->img, i, j, 0x00FF0000);
//			j++;
//		}
//		++i;
//	}
//}
//
//void draw_triangle(t_data *data, int x, int y, int color)
//{
//	int i = 0;
//	int j = 0;
//
//	while (i < x)
//	{
//		j = i + 1;
//		while (j < y)
//		{
//			my_mlx_pixel_put(&data->img, i, j, 0x00FF0000);
//			j++;
//		}
//		++i;
//	}
//}