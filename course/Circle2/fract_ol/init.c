/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:29:16 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/25 00:33:37 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		window_init(t_mlx *mlx)
{
	if (!(mlx->mlx_ptr = mlx_init()))
		return (0);
	if (!(mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "test")))
		return (0);
	if (!(mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT)))
		return (0);
	if (!(mlx->img.data = mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp, &mlx->img.size_l, &mlx->img.endian)))
		return (0);
	return (1);
}
