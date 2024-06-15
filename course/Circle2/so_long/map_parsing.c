/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:54:44 by sooslee           #+#    #+#             */
/*   Updated: 2024/06/05 23:32:51 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
char*    checking_wall(t_game *my_game)
{
    int i;
    int j;
    
    i = 1;
    j = 0;
    if(!ft_strchr(my_game->big_map[0], 1) && !ft_strchr(my_game->big_map[my_game -> height], 1))
        return ("Map is not surrouned by wall");
    while(i < my_game -> height - 1)
    {
        while(j < my_game -> width)
        {
            if(!ft_strchr(my_game->big_map[i][j], 1));
                return ("Map is not surrouned by wall");
            j ++;
        }
        i ++;
    }
}

void    map_parsing(t_game *my_game)
{
    checking_wall(&my_game);   
}