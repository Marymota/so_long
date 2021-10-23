#ifndef	SO_LONG_H
#define	SO_LONG_H 

#include <stdlib.h>
#include <fcntl.h>
#include "../libs/minilibx-linux/mlx.h"
#include "../libs/minilibx_opengl_20191021/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include "../libs/libft/src/libft.h"
#include "mlx_keys.h"

typedef struct	s_player
{
	int	x;
	int	y;
	int direct;
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

	void	*collect;
	int		collectibles;
	int		collected;
	int		end;

	void	*wall;
	void	*character_right;
	void	*character_left;
	void	*path;
	void	*exit;

	char 	*relative_path_path;
	char 	*relative_path_wall;
	char 	*relative_path_character_right;
	char 	*relative_path_character_left;
	char 	*relative_path_collectible;
	char 	*relative_path_exit;

	int 	img_width;
	int		img_height;

	int		moves;

}	t_game;

// Board
int		check_board_elements(t_game *game);
int		board_close(t_game *game);
int		board_elements(t_game *game);
void	init_img(t_game *game);
void	draw_board(t_game *game);
void	draw_background(t_game *game);
// Init
void	init_game(t_game *game);
void	check_board_form(t_game *game, char *line, size_t len);
void	count_board_units(t_game *game, char *board);
void	read_board(t_game *game, char *board);
void	init_board(t_game *game);
// Update
void	convert_to_player(int new_tile_x, int new_tile_y, t_game *game);
void	convert_to_path(int past_tile_x, int past_tile_y, t_game *game);
void	convert_to_exit(int new_tile_x, int new_tile_y, t_game *game);
void	update_map(int past_tile_y, int past_tile_x, t_game *game);
void	update_game_state(t_game *game, int x, int y);
// Actions
int		handle_keypress(int key_code, t_game *game);
void	up(t_game *game);
void	down(t_game *game);
void	left(t_game *game);
void	right(t_game *game);

// Utils
void	game_exit(t_game *game);
void	printf_board(t_game *game);

#endif