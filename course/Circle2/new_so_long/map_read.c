/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:51:33 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/30 12:30:18 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_read(char *file_name, t_game *g)
{
	char	*line;
	int		fd;

	is_ber(file_name);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		show_error("Error\nopen fail");
	line = get_next_line(fd);
	if (!line)
		show_error("Error\nempty file");
	g -> height = 0;
	g -> width = ft_strlen(line);
	g -> str = ft_strdup(line);
	free(line);
	while (line)
	{
		g->height ++;
		line = get_next_line(fd);
		if (line)
			g->str = ft_strjoin(g->str, line);
		free(line);
	}
	close(fd);
	check_map(g);
}

void	check_map(t_game *g)
{
	check_rec(g);
	surround_wall(g);
	check_pec(g);
	update_xy(g);
	map_element(g);
}

void	load_image(t_game *g)
{
	g->cl = mlx_xpm_file_to_image(g->mlx, "./img/co.xpm", &(g->i_w), &(g->i_h));
	g->ex = mlx_xpm_file_to_image(g->mlx, "./img/ex.xpm", &(g->i_w), &(g->i_h));
	g->fl = mlx_xpm_file_to_image(g->mlx, "./img/fl.xpm", &(g->i_w), &(g->i_h));
	g->pl = mlx_xpm_file_to_image(g->mlx, "./img/pl.xpm", &(g->i_w), &(g->i_h));
	g->wa = mlx_xpm_file_to_image(g->mlx, "./img/wa.xpm", &(g->i_w), &(g->i_h));
	if (!g->cl || !g->ex || !g->fl || !g->pl || !g->wa)
	{
		perror("Error!\nimage_load_error");
		exit(1);
	}
}

void	reduce(t_game *g, int hei, int wid)
{
	if (g->str[hei * g->width + wid] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->wa, wid * 50, hei * 50);
	else if (g->str[hei * g->width + wid] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->cl, wid * 50, hei * 50);
	else if (g->str[hei * g->width + wid] == 'P')
		mlx_put_image_to_window(g->mlx, g->win, g->pl, wid * 50, hei * 50);
	else if (g->str[hei * g->width + wid] == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->ex, wid * 50, hei * 50);
	else
		mlx_put_image_to_window(g->mlx, g->win, g->fl, wid * 50, hei * 50);
}

void	setting_img(t_game *g)
{
	int	hei;
	int	wid;

	load_image(g);
	hei = 0;
	while (hei < g->height)
	{
		wid = 0;
		while (wid < g->width - 1)
		{
			reduce(g, hei, wid);
			wid++;
		}
		hei++;
	}
}
