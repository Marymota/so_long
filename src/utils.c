#include "so_long.h"

void	game_exit(t_game *game)
{
	if (game->end)
	{
		ft_putstr_fd("EXIT\n", 1);
		free(game->mlx_win);
		free(game->mlx);
		exit(EXIT_SUCCESS);
	}
}
