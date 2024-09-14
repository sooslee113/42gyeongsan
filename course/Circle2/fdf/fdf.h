/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:22:51 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/23 15:17:20 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "minilibx-linux/mlx.h"
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
#include "./get_next_line/get_next_line.h"

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>
#include <math.h>

typedef struct     s_data 
{
    void        *image;
    char        *addr;
    int            bits_per_pixel;
    int            line_length;
    int            endian;
}   t_data;

typedef struct s_point
{
    int x;
    int y;
    int z;
    int color;
}   t_point;

typedef struct s_map
{
    int width; //너비
    int height; // 높이
    int size;
    int x_angle;
    int y_angle;
    int gap;
    t_point **pts;
}   t_map;

int     create_trgb(int t, int r, int g, int b);
int     name_check(char *s);
char    *map_parshing(char **argv, t_map *map);
void    find_wh(t_map *map, char *content);
int     ft_atoifdf(char **nptr, t_map *map, int i, int j);
void    init_xyz(t_map *map, int i, int j, char *content);
void	ft_isometric(t_map *map);
void    init_xy(t_map *map);

#endif