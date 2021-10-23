#include "so_long.h"

void enemy_animation(t_game *game)
{
	if (game->enemy.count > 4)
		game->enemy.count = 1;
	if (game->enemy.count == 1)
		game->relative_path_enemy = "./assets/enemy/enemy.xpm";
	else if (game->enemy.count == 2)
		game->relative_path_enemy = "./assets/enemy/enemy1.xpm";
	else if (game->enemy.count == 3)
		game->relative_path_enemy = "./assets/enemy/enemy2.xpm";
	else if (game->enemy.count == 4)
		game->relative_path_enemy = "./assets/enemy/enemy3.xpm";
	game->character_enemy = mlx_xpm_file_to_image(game->mlx, game->relative_path_enemy, \
&game->img_width, &game->img_height);
}

void	move_enemy(t_game *game, int y, int x)
{
	game->board[y][x] = '0';
	game->enemy.count++;
	enemy_animation(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->character_enemy, \
game->enemy.x * 100, game->enemy.y * 100);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->path, \
x * 100, y * 100);
}

void enemy_moves(t_game *game, int key_code)
{
	int x;
	int y;

	x = game->enemy.x;
	y = game->enemy.y;

	if (key_code)
	{
		if (key_code == MLX_KEY_W || key_code == MLX_KEY_UP)
		{

			
			if (game->board[y + 1][x] != '1')
			{
				if (game->board[y + 1][x] != 'C')
				{
					++game->enemy.y;
					game->board[y + 1][x] = 'X';
					move_enemy(game, y, x);
				}
			}
		}
		else if (key_code == MLX_KEY_D || key_code == MLX_KEY_RiGHT)
		{
			if (game->board[y][x - 1] != '1')
			{
				if (game->board[y][x - 1] != 'C')
				{
					--game->enemy.x;
					game->board[y][x - 1] = 'X';
					move_enemy(game, y, x);
				}
			}
		}
		else if (key_code == MLX_KEY_S || key_code == MLX_KEY_DOWN)
		{
			if (game->board[y - 1][x] != '1')
			{
				if (game->board[y -1][x] != 'C')
				{
					--game->enemy.y;
					game->board[y - 1][x] = 'X';
					move_enemy(game, y, x);
				}			
			}
		}
		else if (key_code == MLX_KEY_A || key_code == MLX_KEY_LEFT)
		{
			if (game->board[y][x + 1] != '1')
			{
				if (game->board[y][x + 1] != 'C')
				{
					++game->enemy.x;
					game->board[y][x + 1] = 'X';
					move_enemy(game, y, x);
				}			
			}
		}
	}
}


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
	if (game->board[y + 1][x] == 'E' || game->board[y + 1][x] == 'X')
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
	if (game->board[y][x + 1] == 'E' || game->board[y][x + 1] == 'X')
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
	if (game->board[y - 1][x] == 'E' || game->board[y - 1][x] == 'X')
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
	if (game->board[y][x - 1] == 'E' || game->board[y][x - 1] == 'X')
		game_exit(game);
}

int	handle_keypress(int key_code, t_game *game)
{
	if (key_code == MLX_KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		exit(EXIT_SUCCESS);
	}
	if (key_code == MLX_KEY_S || key_code == MLX_KEY_DOWN)
		down(game);
	if (key_code == MLX_KEY_D || key_code == MLX_KEY_RiGHT)
		right(game);
	if (key_code == MLX_KEY_W || key_code == MLX_KEY_UP)
		up(game);
	if (key_code == MLX_KEY_A || key_code == MLX_KEY_LEFT)
		left(game);
	enemy_moves(game, key_code);
	return (0);
}



