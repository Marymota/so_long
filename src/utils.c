#include "so_long.h"

void	counter_moves (t_game *game)
{
	char	*count;

	count = ft_itoa(game->moves);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall, 0, 0);
	mlx_string_put(game->mlx, game->mlx_win, 20, \
game->board_height + 50, 0x000000, "STEPS: ");
	mlx_string_put(game->mlx, game->mlx_win, 70, \
game->board_height + 50, 0x000000, count);
	free(count);
}

void	game_exit(t_game *game, char *message)
{
	int	i;

	ft_putstr_fd(message, 1);
	if (game->mlx_win)
		free(game->mlx_win);
	i = -1;
	while (++i < game->board_height)
		if (game->board && game->board[i])
			free(game->board[i]);
	if (game->board_str)
		free(game->board_str);
	if (game->board)
		free(game->board);
	if (game->mlx)
		free(game->mlx);
	exit(EXIT_SUCCESS);
}

int	x_close(t_game *game)
{
	int	i;

	ft_putstr_fd("\nEXIT\n", 1);
	if (game->mlx_win)
		free(game->mlx_win);
	i = -1;
	while (++i < game->board_height)
		if (game->board && game->board[i])
			free(game->board[i]);
	if (game->board_str)
		free(game->board_str);
	if (game->board)
		free(game->board);
	if (game->mlx)
		free(game->mlx);
	exit(EXIT_SUCCESS);
}
