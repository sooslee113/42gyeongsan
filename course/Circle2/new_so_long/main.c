/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:49:17 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/29 20:52:51 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	double_free(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	game_init(t_game *g)
{
	g->mlx = NULL;
	g->win = NULL;
	g->height = 0;
	g->width = 0;
	g->str = NULL;
	g->cl = NULL;
	g->ex = NULL;
	g->fl = NULL;
	g->pl = NULL;
	g->wa = NULL;
	g->open_exit = NULL;
	g->i_w = 0;
	g->i_h = 0;
	g->walk_cnt = 0;
	g->col_cnt = 0;
	g->all_col = 0;
	g->p_x = 0;
	g->p_y = 0;
}

int	main(int argc, char **argv)
{
	t_game	*g;

	if (argc == 2)
	{
		g = malloc(sizeof(t_game));
		if (!g)
			return (0);
		game_init(g);
		map_read(argv[1], g);
		if (has_valid_path(g) == 0)
			show_error("Error\nThe route is strange");
		g->mlx = mlx_init();
		g->win = mlx_new_window(g->mlx, g->width * 47, g->height * 50, "test");
		setting_img(g);
		mlx_key_hook(g->win, key_press, g);
		mlx_hook(g->win, 17, 0, (void *)clear_game, g);
		mlx_loop(g->mlx);
		free(g);
	}
	else
		show_error("Error\nNo map");
	return (0);
}
