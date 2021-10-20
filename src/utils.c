#include "so_long.h"

void	game_exit(t_game *game)
{
	if (game->end)
	{
		printf("Exit\n");
		exit(EXIT_SUCCESS);
	}
}

void	printf_board(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->board_height)
	{
		x = 0;
		while (x < game->board_width)
		{
			printf("%c", game->board[y][x]);
			x++;
		}
		y++;
		printf("%c", '\n');
	}
	printf("%c", '\n');
}
