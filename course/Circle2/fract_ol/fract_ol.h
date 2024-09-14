/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 20:41:06 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/25 23:27:16 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

#include "minilibx-linux/mlx.h"
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"

# include <X11/keysymdef.h>
# include <X11/X.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>
#include <math.h>

# define 	XK_MISCELLANY
# define	X_EVENT_KEY_EXIT		17
# define	WIN_WIDTH				800
# define	WIN_HEIGHT				600
# define    ESC 65307
# define    UP 126
# define    DOWN 125
# define    LEFT 123
# define    RIGHT 124
# define    R 15
# define    C 8
# define    H 4
# define    J 38
# define    P 35
# define    M 46
# define	ITER_MAX 100


typedef	struct	s_img{
	void		*img_ptr;
	char		*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef	struct	s_mlx{
	void		*mlx_ptr;
	void		*win;
	t_img		img;
}				t_mlx;

int     key_hook(int key_code);
int		mandelbrot(int count_w, int count_h, int iter);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	put_pixel(t_img *img);
int		window_init(t_mlx *mlx);
int		color_set(int iter);
int     mouse_hook(int mouse_code);
int     lets_exit(int mouse_code);

#endif