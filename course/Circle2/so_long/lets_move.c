/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 23:20:12 by sooslee           #+#    #+#             */
/*   Updated: 2024/05/22 17:20:53 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void			find_p(t_game *my_game, int *i, int *j)
{

	*i = 0;
	while(my_game -> big_map[*i])
	{
		*j = 0;
		while(my_game -> big_map[*i][*j])
		{
			if (my_game -> big_map[*i][*j] == 'P')
				return ;
			j ++;
		}
		i ++;
	}
	my_game -> x = *j;
	my_game -> y = *i;

}

int				key_press(int keycode, t_game *my_game)
{
	if (keycode == KEY_W)
		my_game-> y++;
	else if (keycode == KEY_S)
		my_game->y--;
	else if (keycode == KEY_A)
		my_game->x--;
	else if (keycode == KEY_D)
		my_game->x++;
	else if (keycode == KEY_ESC)
		exit(0);
	my_game->big_map[my_game -> y][my_game -> x] = 'P';
	return (0);
}

void	lets_move(t_game *my_game)
{

	mlx_key_hook(my_game -> win_ptr, &key_press, my_game);
	while (1)
	{
		my_game->big_map[my_game -> y][my_game -> x] = 'P';
	}
}

