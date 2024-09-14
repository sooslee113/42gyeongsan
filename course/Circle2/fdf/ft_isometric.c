/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isometric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 01:39:13 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/25 21:54:19 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_isometric(t_map *map)
{
	double	pi;
	int		i;
    int     j;
	float	xa;
	float	ya;

	i = 0;
    j = 0;
	pi = 3.1415926;
	xa = (map->x_angle * pi) / 180;
	ya = (map->y_angle * pi) / 180;
	while (i < map->height)
	{
        j = 0;
        while (j < map->width)
        {
		    map->pts[i][j].x = (map->pts[i][j].x * cos(xa)) - \
		    (map->pts[i][j].y * sin(xa));
		    map->pts[i][j].y = (map->pts[i][j].x * sin(ya)) + \
		    (map->pts[i][j].y * sin(ya) - map->pts[i][j].z);
            j ++;
        }
		i++;
	}
}