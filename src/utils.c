#include "so_long.h"

void counter_moves (t_game *game)
{
	char *count;
	count = ft_itoa(game->moves);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall, game->board_width * 90, game->board_height - 10);
	mlx_string_put(game->mlx, game->mlx_win, game->board_width * 90 + 20, game->board_height + 50, 0x000000, "STEPS: ");
	mlx_string_put(game->mlx, game->mlx_win, game->board_width * 90 + 70, game->board_height + 50, 0x000000, count);
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
