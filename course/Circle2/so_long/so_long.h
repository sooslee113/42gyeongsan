/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:17:19 by sooslee           #+#    #+#             */
/*   Updated: 2024/06/05 23:18:04 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"
#include <stdio.h>
//#include "libft/libft.h"

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define KEY_ESC		65307
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100

typedef struct s_game
{
    int height; // 게임 창 길이
    int width; // 게임 창 너비
    char *line; // 게임 한줄 읽기
    char    **big_map; // 큰 배열
    void    *mlx_ptr; 
    void    *win_ptr;
    void    *front; // 앞 모습
    void    *back;
    void    *right;
    void    *left;
    void    *skull;
    void    *collect;
    void    *wall;
    void    *exit;
    void    *open_exit;
    void    *floor;

    int img_width; // 이미지 x좌표
    int img_height; // 이미지 y좌표 

    int x;
    int y;
} t_game;

void    load_image(t_game *my_game);
void    map_read(t_game *my_game);
void    setting_img(t_game *my_game);
void    load_image2(t_game *my_game);
void    map_parsing(t_game *my_game);

#endif