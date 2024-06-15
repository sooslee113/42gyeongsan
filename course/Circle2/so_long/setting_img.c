/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 23:42:44 by sooslee           #+#    #+#             */
/*   Updated: 2024/05/20 04:16:44 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void load_image2(t_game *my_game)
{
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

void    setting_img(t_game *my_game)
{
    int hei;
    int wid;
    load_image2(my_game);

    hei = 0;
    while(my_game->big_map[hei])
    {
        wid = 0;
        while(my_game->big_map[hei][wid] != '\n')
        {
            if(my_game->big_map[hei][wid] == '1')
                mlx_put_image_to_window(my_game->mlx_ptr, my_game->win_ptr, my_game->wall, wid * 50, hei * 50);
            else if (my_game->big_map[hei][wid] == 'C')
                mlx_put_image_to_window(my_game->mlx_ptr, my_game->win_ptr, my_game->collect, wid * 50, hei * 50);
            else if (my_game->big_map[hei][wid] == 'E')
                mlx_put_image_to_window(my_game->mlx_ptr, my_game->win_ptr, my_game->open_exit, wid * 50, hei * 50);
            else if (my_game->big_map[hei][wid] == 'P')
                mlx_put_image_to_window(my_game->mlx_ptr, my_game->win_ptr, my_game->front, wid * 50, hei * 50);
            else //if (my_game->big_map[hei][wid] == '0')
                mlx_put_image_to_window(my_game->mlx_ptr, my_game->win_ptr, my_game->floor , wid * 50, hei * 50);
            wid ++;
        }
        hei ++;
    }
    return ;
}