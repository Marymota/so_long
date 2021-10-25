#include "so_long.h"

void counter_moves (t_game *game)
{
	char *count;
	count = ft_itoa(game->moves);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall, 0, 0);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall, 0, 100);
	mlx_string_put(game->mlx, game->mlx_win, 10, 20, 0xFFFFFF, "STEPS: ");
	mlx_string_put(game->mlx, game->mlx_win, 80, 20, 0xFFFFFF, count);
	free(count);
}

void	game_exit()
{
	ft_putstr_fd("EXIT\n", 1);
	//free(game->mlx_win);
	//free(game->mlx);
	//free(game);
	exit(EXIT_SUCCESS);

}

int	x_close()
{
	ft_putstr_fd("EXIT\n", 1);
	//free(game->mlx_win);
	//free(game->mlx);
	//free(game);
	exit(EXIT_SUCCESS);
}
