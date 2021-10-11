#ifndef SO_LONG_H
#define SO_LONG_H 

#include <stdio.h>
#include <fcntl.h>
#include <mlx.h>
#include "../libs/libft/src/libft.h"

typedef struct	s_game 
{
	void 	*mlx;
	void 	*mlx_win;
	char	**board;
	int		board_width;
	int		board_height;
	char	*board_str;
	void	*img;
	int 	img_width;
	int		img_height;
	char	*addr;
	char 	*relative_path;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_game;


#endif