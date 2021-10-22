//if (key_code == 1) // keysym 115 mac 1
//if (key_code == 2) // keysym 100 mac 2
//if (key_code == 13) // keysym 119 mac 13
//if (key_code == 0) // keysym 97 mac 0

#include "so_long.h"

void	down(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y;
	if ((game->board[y + 1][x]) != '1' && ((game->board[y + 1][x]) != 'E'))
	{
		++game->player.y;
		update_game_state(game, x, y);
	}
	if (game->board[y + 1][x] == 'E')
		game_exit(game);
}

void	right(t_game *game)
{
	int	x;
	int	y;

	game->player.direct = 0;
	x = game->player.x;
	y = game->player.y;
	if ((game->board[y][x + 1]) != '1' && ((game->board[y][x + 1]) != 'E'))
	{
		++game->player.x;
		update_game_state(game, x, y);
	}
	if (game->board[y][x + 1] == 'E')
		game_exit(game);
}

void	up(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y;
	if ((game->board[y - 1][x]) != '1' && ((game->board[y - 1][x]) != 'E'))
	{
		--game->player.y;
		update_game_state(game, x, y);
	}
	if (game->board[y - 1][x] == 'E')
		game_exit(game);
}

void	left(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y;
	game->player.direct = 1;
	if ((game->board[y][x - 1]) != '1' && ((game->board[y][x - 1]) != 'E'))
	{
		--game->player.x;
		update_game_state(game, x, y);
	}
	if (game->board[y][x - 1] == 'E')
		game_exit(game);
}

int	handle_keypress(int key_code, t_game *game)
{
	if (key_code == 53)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		exit(EXIT_SUCCESS);
	}
	if (key_code == 1)
		down(game);
	if (key_code == 2)
		right(game);
	if (key_code == 13)
		up(game);
	if (key_code == 0)
		left(game);
	return (0);
}
