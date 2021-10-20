#ifndef SO_LONG_H
#define SO_LONG_H 

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../libs/minilibx-linux/mlx.h"
#include "../libs/minilibx_opengl_20191021/mlx.h"
//#include <X11/X.h>
//#include <X11/keysym.h>
#include "../libs/libft/src/libft.h"

typedef struct	s_player
{
	int	x;
	int	y;
}				t_player;

typedef struct	s_game 
{
	t_player player;

	void 	*mlx;
	void 	*mlx_win;
	
	char	**board;
	int		board_width;
	int		board_height;
	char	*board_str;

	void	*img;

	void	*collect;
	int		collectibles;
	int		collected;
	int		end;

	void	*wall;
	void	*character;
	void	*path;
	void	*exit;

	char 	*relative_path_path;
	char 	*relative_path_wall;
	char 	*relative_path_character;
	char 	*relative_path_collectible;
	char 	*relative_path_exit;

	int 	img_width;
	int		img_height;

	char	*addr;
	char 	*relative_path;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	int		moves;

}	t_game;

void	init_game (t_game *game);
void	init_board (t_game *game);
void	read_board(t_game *game, char *board);
void	count_board_units(t_game *game, char *board);
void	check_board_form(t_game *game, char *line, size_t len);

int		handle_keypress(int key_code, t_game *game);
void	up(t_game *game);
void	down(t_game *game);
void	left(t_game *game);
void	right(t_game *game);

void	convert_to_player(int new_tile_x, int new_tile_y, t_game *game);
void	convert_to_path(int past_tile_x, int past_tile_y, t_game *game);
void	update_map(int past_tile_y, int past_tile_x, t_game *game);
void	update_game_state(t_game *game, int x, int y);

void	init_img(t_game *game);
int		valid_board(t_game *game);
void	draw_board(t_game *game);
void	draw_background(t_game *game);

void	game_exit(t_game *game);
void	printf_board(t_game *game);


#endif