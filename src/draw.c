#include "so_long.h"

void my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char *dst;

	dst = game->addr + (y * game->line_length + x * (game->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_square(t_game *game, int x, int y, int color)
{
	int i = 0;
	int j = 0;

	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			my_mlx_pixel_put(game->img, i, j, color);
			j++;
		}
		++i;
	}
}
//draw_square(&img, 250, 250, 0x00FF0000);		
	
void draw_triangle(t_game *game, int x, int y, int color)
{
	int i = 0;
	int j = 0;

	while (i < x)
	{
		j = i + 1;
		while (j < y)
		{
			my_mlx_pixel_put(game->img, i, j, color);
			j++;
		}
		++i;
	}
}
//draw_triangle(&img, 150, 150, 0x00FF0000);