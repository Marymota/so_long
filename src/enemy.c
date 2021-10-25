#include "so_long.h"

void	move_enemy_up(t_game *game, int x, int y)
{
	if (game->board[y + 1][x] != '1' && game->board[y + 1][x] != 'C' && game->board[y + 1][x] != 'E')
	{
		++game->enemy.y;
		game->board[y + 1][x] = 'X';
		update_enemy(game, y, x);
	}	
}

void	move_enemy_down(t_game *game, int x, int y)
{
	if (game->board[y][x - 1] != '1' && game->board[y][x - 1] != 'C' && game->board[y][x - 1] != 'E')
	{
		--game->enemy.x;
		game->board[y][x - 1] = 'X';
		update_enemy(game, y, x);
	}
}

void	move_enemy_left(t_game *game, int x, int y)
{
	if (game->board[y - 1][x] != '1' && game->board[y - 1][x] != 'C' && game->board[y - 1][x] != 'E')
	{
		--game->enemy.y;
		game->board[y - 1][x] = 'X';
		update_enemy(game, y, x);
	}
}

void	move_enemy_right(t_game *game, int x, int y)
{
	if (game->board[y][x + 1] != '1' && game->board[y][x + 1] != 'C' && game->board[y][x + 1] != 'E')
	{
		++game->enemy.x;
		game->board[y][x + 1] = 'X';
		update_enemy(game, y, x);		
	}
}

void enemy_actions(t_game *game, int key_code)
{
	int x;
	int y;

	x = game->enemy.x;
	y = game->enemy.y;
	if (key_code == MLX_KEY_W || key_code == MLX_KEY_UP)
		move_enemy_up(game, x, y);
	else if (key_code == MLX_KEY_D || key_code == MLX_KEY_RiGHT)
		move_enemy_down(game, x, y);
	else if (key_code == MLX_KEY_S || key_code == MLX_KEY_DOWN)
		move_enemy_left(game, x, y);
	else if (key_code == MLX_KEY_A || key_code == MLX_KEY_LEFT)
		move_enemy_right(game, x, y);
}
