/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 20:07:42 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/25 22:57:46 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->data + (x * img->bpp / 8) + (y * img->size_l);
	*(unsigned int *)dst = color;
}

void	put_pixel(t_img *img)
{
	int		iter;
	int		color;
	int		count_w;
	int 	count_h;

	count_h = -1;
	while(++count_h <= WIN_HEIGHT)
	{
		count_w = -1;
		while(++count_w <= WIN_WIDTH)
		{
			iter = mandelbrot(count_w, count_h, 0);

			if (iter < ITER_MAX)
			{
				color = color_set(iter);
				my_mlx_pixel_put(img, count_w, count_h, color);
			}
			else 
				my_mlx_pixel_put(img, count_w, count_h, 0x00000000);
		}
	}
}

int		color_set(int iter)
{
	double	r;
	double	g;
	double	b;
	int		color;

	r = sin(0.3 * (double)iter);
	g = sin(0.3 * (double)iter + 3) * 127 + 128;
	b = sin(0.3 * (double)iter + 3) * 127 + 128;
	color = ((int)(255.999 * r) << 16) + ((int)(255.999 * g) << 8) + ((int)(255.999 * b));
	return (color);
}

int main(void)
{
    t_mlx mlx;

    if (!window_init(&mlx))
		return (0);
    mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_hook(mlx.win, X_EVENT_KEY_EXIT, 0, lets_exit, &mlx);
	put_pixel(&mlx.img);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);
    mlx_loop(mlx.mlx_ptr);

	return (0);
}
