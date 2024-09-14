/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:47:50 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/30 12:31:00 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include "libft/libft.h"

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define KEY_ESC		65307
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	*str;
	void	*cl;
	void	*ex;
	void	*fl;
	void	*pl;
	void	*wa;
	void	*open_exit;
	int		height;
	int		width;
	int		i_w;
	int		i_h;
	int		walk_cnt;
	int		col_cnt;
	int		all_col;
	int		p_x;
	int		p_y;
}	t_game;

void	map_read(char *file_name, t_game *game);
void	load_image(t_game *game);
void	setting_img(t_game *game);
void	move_w(t_game *game);
void	move_a(t_game *game);
void	move_s(t_game *game);
void	move_d(t_game *game);
void	clear_game(t_game *game);
void	cleanup(t_game *game);
void	show_error(char *str);
void	surround_wall(t_game *game);
void	check_pec(t_game *game);
void	check_rec(t_game *game);
void	check_map(t_game *game);
void	update_xy(t_game *game);
void	double_free(char **split);
void	map_element(t_game *game);
void	check_is_ber(char *str);
void	is_ber(char *str);
void	error_pec(int p_num, int e_num, int c_num);
void	reduce(t_game *g, int hei, int wid);
void	dfs_collect(int x, int y, char **map, int *found_c);
int		key_press(int keycode, t_game *game);
void	free_images(t_game *game);
int		has_valid_path(t_game *game);
int		dfs(int x, int y, char **map, char find_char);
int		dfs_exit(int x, int y, char **map);
int		get_hei(char **map);

#endif
