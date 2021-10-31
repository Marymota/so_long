/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmota <mmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:29:40 by mmota             #+#    #+#             */
/*   Updated: 2021/10/29 13:20:33 by mmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H 

# include <stdlib.h>
# include <fcntl.h>
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/minilibx_opengl_20191021/mlx.h"
# include "../libs/libft/src/libft.h"
# include "mlx_keys.h"

typedef struct s_player
{
	int	x;
	int	y;
	int	direct;
	int	count;
}				t_player;

typedef struct s_enemy
{
	int	x;
	int	y;
	int	count;
}				t_enemy;

typedef struct s_game
{
	t_player	player;
	t_enemy		enemy;
	void		*mlx;
	void		*mlx_win;
	char		**board;
	int			board_width;
	int			board_height;
	void		*collect;
	int			collectibles;
	int			collected;
	int			end;
	int			collect_flag;		
	void		*wall;
	void		*character_right;
	void		*character_left;
	void		*character_enemy;
	void		*path;
	void		*exit;		
	char		*relative_path_path;
	char		*relative_path_wall;
	char		*relative_path_character_right;
	char		*relative_path_character_left;
	char		*relative_path_enemy;
	char		*relative_path_collectible;
	char		*relative_path_exit;		
	int			img_width;
	int			img_height;		
	int			moves;
}				t_game;

//	so_long
void	init_game(t_game *game);
void	init_vars(t_game *game);
void	init_img(t_game *game);
// Check Board
void	count_board_units(t_game *game, char *board);
void	check_board_form(t_game *game, char *line, size_t len);
int		board_close(t_game *game);
int		board_elements(t_game *game);
// Board
void	init_board(t_game *game);
void	read_board(t_game *game, char *board);
void	draw_background(t_game *game);
void	init_player(t_game *game, int y, int x);
void	draw_board(t_game *game);
//	Key_Actions
int		handle_keypress(int key_code, t_game *game);
void	up(t_game *game);
void	left(t_game *game);
void	down(t_game *game);
void	right(t_game *game);
// Update
void	update_game_state(t_game *game, int x, int y);
void	update_enemy(t_game *game, int y, int x);
void	update_map(int past_tile_y, int past_tile_x, t_game *game);
void	update_collectibles(t_game *game);
// Convert
void	convert_to_collectible(int past_tile_x, int past_tile_y, t_game *game);
void	convert_to_player(int new_tile_x, int new_tile_y, t_game *game);
void	convert_to_enemy(t_game *game);
void	convert_to_path(int past_tile_x, int past_tile_y, t_game *game);
void	convert_to_exit(int new_tile_x, int new_tile_y, t_game *game);
//	Enemy
void	init_enemy(t_game *game, int y, int x);
void	enemy_actions(t_game *game, int key_code);
int		move_enemy(t_game *game, int x, int y);
//	Animations
void	enemy_animation(t_game *game);
void	collectibles_animation(t_game *game);
void	player_animation(t_game *game);
void	player_animations_right(t_game *game);
void	player_animations_left(t_game *game);
// Utils
void	game_exit(t_game *game, char *message);
int		x_close(t_game *game);
void	counter_moves(t_game *game);

#endif