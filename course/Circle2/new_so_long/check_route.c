/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_route.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 03:32:53 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/29 20:53:10 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_hei(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	dfs_collect(int x, int y, char **map, int *found_c)
{
	if (x < 0 || x >= (int)ft_strlen(map[0]) || y < 0 || y >= get_hei(map) || \
			map[y][x] == '1' || map[y][x] == 'V' || map[y][x] == 'E')
		return ;
	if (map[y][x] == 'C')
		(*found_c)++;
	map[y][x] = 'V';
	dfs_collect(x - 1, y, map, found_c);
	dfs_collect(x + 1, y, map, found_c);
	dfs_collect(x, y - 1, map, found_c);
	dfs_collect(x, y + 1, map, found_c);
}

int	dfs_exit(int x, int y, char **map)
{
	if (x < 0 || x >= (int)ft_strlen(map[0]) || y < 0 || y >= get_hei(map) || \
			map[y][x] == '1' || map[y][x] == 'V')
		return (0);
	if (map[y][x] == 'E')
		return (1);
	map[y][x] = 'V';
	if (dfs_exit(x - 1, y, map) || dfs_exit(x + 1, y, map) || \
			dfs_exit(x, y - 1, map) || dfs_exit(x, y + 1, map))
		return (1);
	return (0);
}

int	has_valid_path(t_game *game)
{
	char	**map_temp_c;
	char	**map_temp_e;
	int		found_c;
	int		can_reach_exit;

	found_c = 0;
	map_temp_c = ft_split(game->str, '\n');
	map_temp_e = ft_split(game->str, '\n');
	dfs_collect(game->p_x, game->p_y, map_temp_c, &found_c);
	if (found_c != game->all_col)
	{
		double_free(map_temp_c);
		double_free(map_temp_e);
		return (0);
	}
	can_reach_exit = dfs_exit(game->p_x, game->p_y, map_temp_e);
	double_free(map_temp_c);
	double_free(map_temp_e);
	return (can_reach_exit);
}
