#include "so_long.h"

void counter_moves (t_game *game)
{
	char *count;
	count = ft_itoa(game->moves);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall, 0, 0);
	mlx_string_put(game->mlx, game->mlx_win, 20, game->board_height + 50, 0x000000, "STEPS: ");
	mlx_string_put(game->mlx, game->mlx_win, 70, game->board_height + 50, 0x000000, count);
	free(count);
}

void	game_exit()
{
	ft_putstr_fd("\nEXIT\n", 1);
	exit(EXIT_SUCCESS);

}

int	x_close()
{
	ft_putstr_fd("\nEXIT\n", 1);
	exit(EXIT_SUCCESS);
}
