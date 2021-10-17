#ifndef SO_LONG_H
#define SO_LONG_H 

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../libs/minilibx-linux/mlx.h"
#include "../libs/minilibx_opengl_20191021/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
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

	int		collect_n;

	void	*wall;
	void	*character;
	void	*collectible;
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

}	t_game;


#endif