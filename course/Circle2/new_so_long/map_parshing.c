/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parshing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:56:36 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/29 20:51:19 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	surround_wall(t_game *game)
{
	int	i;
	int	len;

	len = ft_strlen(game->str);
	i = 0;
	while (game->str[i] != '\0')
	{
		if (i < game->width - 1)
		{
			if (game->str[i] != '1')
				show_error("Error!\nThe map is not surrouned by walls");
		}
		else if (i % game->width == 0 || i % game->width == game->width - 2)
		{
			if (game->str[i] != '1')
				show_error("Error\nThe map is not surrouned by walls");
		}
		else if (i > len - game->width - 1 && game->str[i] != '\n')
		{
			if (game->str[i] != '1')
				show_error("Error\nThe map is not surrouned by walls");
		}
		i ++;
	}
}

void	check_pec(t_game *game)
{
	int	i;
	int	p_num;
	int	e_num;
	int	c_num;

	p_num = 0;
	e_num = 0;
	c_num = 0;
	i = 0;
	while (game->str[i])
	{
		if (game->str[i] == 'P')
			p_num ++;
		else if (game->str[i] == 'E')
			e_num ++;
		else if (game->str[i] == 'C')
			c_num ++;
		i ++;
	}
	game -> all_col = c_num;
	error_pec(p_num, e_num, c_num);
}

void	error_pec(int p_num, int e_num, int c_num)
{
	if (p_num != 1)
		show_error("Error\nThe player is not in the game or too many player");
	if (e_num != 1)
		show_error("Error\nThe exit must be on the map or too many exit");
	if (c_num == 0)
		show_error("Error\n Atleast one Collect must be on the map");
}

void	check_rec(t_game *game)
{
	int	area;

	area = ft_strlen(game->str);
	if (game->height * game->width != area + 1)
		show_error("Error\nIt is not a rectangle");
}

void	update_pos(t_game *game)
{
	char	**map;

	map = ft_split(game->str, '\n');
	ft_printf("%s", map[0]);
}
