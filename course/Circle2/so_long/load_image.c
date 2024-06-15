/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:18:49 by sooslee           #+#    #+#             */
/*   Updated: 2024/05/19 02:59:27 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "so_long.h"


void load_image(t_game *my_game)
{
    my_game -> win_ptr = mlx_new_window(my_game -> mlx_ptr , 720, 480, "10bird's adventure");
    my_game -> front = mlx_xpm_file_to_image(my_game -> mlx_ptr, "images/front.xpm",  &my_game->img_width, &my_game->img_height);
    my_game -> back = mlx_xpm_file_to_image(my_game -> mlx_ptr, "images/back.xpm",  &my_game->img_width, &my_game->img_height);
    my_game -> right = mlx_xpm_file_to_image (my_game -> mlx_ptr, "images/right.xpm",  &my_game->img_width, &my_game->img_height);
    my_game -> left = mlx_xpm_file_to_image(my_game -> mlx_ptr, "images/left.xpm", &my_game->img_width, &my_game->img_height);
    my_game -> skull = mlx_xpm_file_to_image(my_game -> mlx_ptr, "images/2.xpm", &my_game->img_width, &my_game->img_height);
    my_game -> collect = mlx_xpm_file_to_image(my_game -> mlx_ptr, "images/collect.xpm",  &my_game->img_width, &my_game->img_height);
    my_game -> wall = mlx_xpm_file_to_image(my_game -> mlx_ptr, "images/wall.xpm",  &my_game->img_width, &my_game->img_height);
    my_game -> exit = mlx_xpm_file_to_image(my_game -> mlx_ptr, "images/exit.xpm",  &my_game->img_width, &my_game->img_height);
    my_game -> open_exit = mlx_xpm_file_to_image(my_game -> mlx_ptr, "images/o_exit.xpm",  &my_game->img_width, &my_game->img_height);
    my_game -> floor = mlx_xpm_file_to_image(my_game -> mlx_ptr, "images/floor.xpm",  &my_game->img_width, &my_game->img_height);

    return ;
}