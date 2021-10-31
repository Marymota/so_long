/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keys.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmota <mmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:29:34 by mmota             #+#    #+#             */
/*   Updated: 2021/10/29 13:16:00 by mmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_KEYS_H
# define MLX_KEYS_H

# ifdef __linux__

#  define MLX_KEY_ESC 65307
#  define MLX_KEY_TAB 64289
#  define MLX_KEY_SPC 32
#  define MLX_KEY_ENTER 65293
#  define MLX_KEY_BCKSPC 65288
#  define MLX_KEY_LSHIFT 65505
#  define MLX_KEY_LCTRL 65507
#  define MLX_KEY_LOPT_ALT 65513
#  define MLX_KEY_RSHIFT 65506
#  define MLX_KEY_RCTRL 65508
#  define MLX_KEY_ROPT_ALT 65514
#  define MLX_KEY_LEFT 65361
#  define MLX_KEY_UP 65362
#  define MLX_KEY_RIGHT 65363
#  define MLX_KEY_DOWN 65364
#  define MLX_KEY_1 49
#  define MLX_KEY_2 50
#  define MLX_KEY_3 51
#  define MLX_KEY_4 52
#  define MLX_KEY_5 53
#  define MLX_KEY_6 54
#  define MLX_KEY_7 55
#  define MLX_KEY_8 56
#  define MLX_KEY_9 57
#  define MLX_KEY_0 48
#  define MLX_KEY_MINUS 45
#  define MLX_KEY_EQ 61
#  define MLX_KEY_Q 113
#  define MLX_KEY_W 119
#  define MLX_KEY_E 101
#  define MLX_KEY_R 114
#  define MLX_KEY_T 116
#  define MLX_KEY_Y 121
#  define MLX_KEY_U 117
#  define MLX_KEY_I 105
#  define MLX_KEY_O 111
#  define MLX_KEY_P 112
#  define MLX_KEY_A 97
#  define MLX_KEY_S 115
#  define MLX_KEY_D 100
#  define MLX_KEY_F 102
#  define MLX_KEY_G 103
#  define MLX_KEY_H 104
#  define MLX_KEY_J 106
#  define MLX_KEY_K 107
#  define MLX_KEY_L 108

// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_
// #  define MLX_KEY_

# else
#  ifdef __APPLE__

#   define MLX_KEY_ESC 53
#   define MLX_KEY_TAB 48
#   define MLX_KEY_SPC 49
#   define MLX_KEY_ENTER 36
#   define MLX_KEY_BCKSPC 51
#   define MLX_KEY_LSHIFT 257
#   define MLX_KEY_LCTRL 256
#   define MLX_KEY_LOPT_ALT 261
#   define MLX_KEY_RSHIFT 258
#   define MLX_KEY_RCTRL 269
#   define MLX_KEY_ROPT_ALT 262
#   define MLX_KEY_LEFT 123
#   define MLX_KEY_UP 126
#   define MLX_KEY_RIGHT 124
#   define MLX_KEY_DOWN 125
#   define MLX_KEY_1 18
#   define MLX_KEY_2 19
#   define MLX_KEY_3 20
#   define MLX_KEY_4 21
#   define MLX_KEY_5 23
#   define MLX_KEY_6 22
#   define MLX_KEY_7 26
#   define MLX_KEY_8 28
#   define MLX_KEY_9 25
#   define MLX_KEY_0 29
#   define MLX_KEY_MINUS 27
#   define MLX_KEY_EQ 24
#   define MLX_KEY_Q 12
#   define MLX_KEY_W 13
#   define MLX_KEY_E 14
#   define MLX_KEY_R 15
#   define MLX_KEY_T 17
#   define MLX_KEY_Y 16
#   define MLX_KEY_U 32
#   define MLX_KEY_I 34
#   define MLX_KEY_O 31
#   define MLX_KEY_P 35
#   define MLX_KEY_A 0
#   define MLX_KEY_S 1
#   define MLX_KEY_D 2
#   define MLX_KEY_F 3
#   define MLX_KEY_G 5
#   define MLX_KEY_H 4
#   define MLX_KEY_J 38
#   define MLX_KEY_K 40
#   define MLX_KEY_L 37

// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_
// #   define MLX_KEY_

#  endif
# endif

#endif
