/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:00:42 by sooslee           #+#    #+#             */
/*   Updated: 2024/06/05 22:49:08 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "so_long.h"

void    map_read(t_game *my_game)
{
    int fd;
    int fd2;
    int i;

    my_game -> height = 0;
    fd = open("./map/map2.ber", O_RDONLY); // 파일 오픈... 줄 갯수 세어려 보려고
    while((my_game -> line = get_next_line(fd)) != NULL)
    {   
        my_game -> height ++;
        free(my_game -> line);
    }
    close(fd);
    my_game->big_map = (char **)malloc(sizeof(char*) * my_game -> height); // 큰 배열 동적할당
    fd2 = open("./map/map2.ber", O_RDONLY); // 다시 오픈
    i = 0;
    while(i < my_game -> height) // 하나하나 동적할당
    {
        my_game -> line = get_next_line(fd2);
        my_game->big_map[i] = (char *)malloc(sizeof(char) * ft_strlen(my_game -> line));
        my_game->big_map[i] = my_game -> line;
        if(i > 0 &&(ft_strlen(my_game->big_map[i - 1]) != ft_strlen(my_game->big_map[i])))
            return ;
        //printf("%s", my_game -> line);
        i ++;
    }
    close(fd2);
    // i = 0;
    // while(i < my_game -> height)
    // {
    //     free(my_game->big_map[i]);
    //     i ++;
    // }
    // free(my_game->big_map);
    //printf("%c", my_game -> big_map[0][1]);
    return ;
}

// int main()
// {
//     t_game my_game;
//     map_read(&my_game);
//     //:printf("%d", watipid());
//     return 0;
// }