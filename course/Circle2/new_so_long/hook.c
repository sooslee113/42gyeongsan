/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:55:48 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/29 21:21:50 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		move_w(game);
	else if (keycode == KEY_S)
		move_s(game);
	else if (keycode == KEY_A)
		move_a(game);
	else if (keycode == KEY_D)
		move_d(game);
	else if (keycode == KEY_ESC)
		clear_game(game);
	return (0);
}

void	move_w(t_game *game)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(game->str))
	{
		if (game->str[i] == 'P')
			break ;
		i++;
	}
	if (i < game->width)
		return ;
	if (game->str[i - game->width] == 'C')
		game->col_cnt++;
	if (game->str[i - game->width] == 'E' && game->all_col == game->col_cnt)
		clear_game(game);
	if (game->str[i - game->width] != '1' && game->str[i - game->width] != 'E')
	{
		game->str[i] = '0';
		game->str[i - game->width] = 'P';
		game->walk_cnt++;
		ft_printf("%d\n", game->walk_cnt);
		free_images(game);
		setting_img(game);
	}
}

void	move_s(t_game *game)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(game->str))
	{
		if (game->str[i] == 'P')
			break ;
		i++;
	}
	if (i >= (int)ft_strlen(game->str) - game->width)
		return ;
	if (game->str[i + game->width] == 'C')
		game->col_cnt++;
	if (game->str[i + game->width] == 'E' && game->all_col == game->col_cnt)
		clear_game(game);
	if (game->str[i + game->width] != '1' && game->str[i + game->width] != 'E')
	{
		game->str[i] = '0';
		game->str[i + game->width] = 'P';
		game->walk_cnt++;
		ft_printf("%d\n", game->walk_cnt);
		free_images(game);
		setting_img(game);
	}
}

void	move_a(t_game *game)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(game->str))
	{
		if (game->str[i] == 'P')
			break ;
		i++;
	}
	if (i % game->width == 0)
		return ;
	if (game->str[i - 1] == 'C')
		game->col_cnt++;
	if (game->str[i - 1] == 'E' && game->all_col == game->col_cnt)
		clear_game(game);
	if (game->str[i - 1] != '1' && game->str[i - 1] != 'E')
	{
		game->str[i] = '0';
		game->str[i - 1] = 'P';
		game->walk_cnt++;
		ft_printf("%d\n", game->walk_cnt);
		free_images(game);
		setting_img(game);
	}
}

void	move_d(t_game *game)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(game->str))
	{
		if (game->str[i] == 'P')
			break ;
		i++;
	}
	if (i % game->width == game->width - 1)
		return ;
	if (game->str[i + 1] == 'C')
		game->col_cnt++;
	if (game->str[i + 1] == 'E' && game->all_col == game->col_cnt)
		clear_game(game);
	if (game->str[i + 1] != '1' && game->str[i + 1] != 'E')
	{
		game->str[i] = '0';
		game->str[i + 1] = 'P';
		game->walk_cnt++;
		ft_printf("%d\n", game->walk_cnt);
		free_images(game);
		setting_img(game);
	}
}
