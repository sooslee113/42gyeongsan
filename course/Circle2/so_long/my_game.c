/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:05:53 by sooslee           #+#    #+#             */
/*   Updated: 2024/05/19 02:52:48 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "minilibx-linux/mlx.h"

int main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();//mlx 포인터 생성
	win_ptr = mlx_new_window(mlx_ptr , 720, 480, "10bird's adventure");// 윈도우 띄우기
	mlx_loop(mlx_ptr);
}