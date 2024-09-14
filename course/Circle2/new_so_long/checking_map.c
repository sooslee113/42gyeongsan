/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 21:21:10 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/29 20:52:26 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_xy(t_game *game)
{
	char	**map;
	int		y;
	int		x;

	map = ft_split(game->str, '\n');
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				game->p_x = x;
				game->p_y = y;
				break ;
			}
			x++;
		}
		y++;
	}
	double_free(map);
}

void	map_element(t_game *game)
{
	char	**map;
	int		y;
	int		x;

	map = ft_split(game->str, '\n');
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'C' \
					&& map[y][x] != 'E' && map[y][x] != 'P')
			{
				double_free(map);
				show_error("Error\nThe map must be composed of 10CEP");
			}
			x++;
		}
		y++;
	}
	double_free(map);
}

void	is_ber(char *str)
{
	int	len;

	len = ft_strlen(str) - 1;
	if (!(str[len] == 'r' && str[len - 1] == 'e' \
				&& str[len - 2] == 'b' && str[len - 3] == '.'))
	{
		show_error("Error\nber error");
	}
}
