/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 21:28:52 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/30 12:14:29 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images(t_game *game)
{
	if (game->cl)
		mlx_destroy_image(game->mlx, game->cl);
	if (game->ex)
		mlx_destroy_image(game->mlx, game->ex);
	if (game->fl)
		mlx_destroy_image(game->mlx, game->fl);
	if (game->pl)
		mlx_destroy_image(game->mlx, game->pl);
	if (game->wa)
		mlx_destroy_image(game->mlx, game->wa);
}

void	free_resources(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->str)
		free(game->str);
	if (game->mlx)
	{
		free(game->mlx);
	}
}

void	cleanup(t_game *game)
{
	free_images(game);
	free_resources(game);
}

void	clear_game(t_game *game)
{
	cleanup(game);
	exit(1);
}
