/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parshing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 00:41:19 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/25 23:30:16 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
void    alloc_map(t_map **map)
{
    *map = (t_map *)malloc(sizeof(t_map));
    (*map) -> width = 0;
    (*map) -> height = 0;
    (*map) -> size = 0;
    (*map) -> x_angle = 30;
    (*map) -> y_angle = 31;
    (*map) -> gap = 20;
}

void    double_free(char **split)
{
    int i;
    i = 0;
    while(split[i])
    {
        free(split[i]);
        i ++;
    }
    free (split);
}

void    fdf_error(char *str)
{
    printf("%s", str);
    exit(1);
}

char    *map_parshing(char **argv, t_map *map)
{
    int fd;
    char *line;
    char *content;
    char *temp;

    content = ft_strdup("");
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        //ft_printf("file open error");
        exit(1);
    }
    while((line = get_next_line(fd)) != NULL)
    {
        temp = content;
        content = ft_strjoin(content, line);
        free(temp);
        printf("%s", line);
        free(line);
    }
    printf("content \n%s", content);    
    map -> height = 18;
    return (content);
}

int	fdf_is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\0')
		return (1);
	return (0);
}

void    find_wh(t_map *map, char *content)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while(*content != '\0')
    {
        if (*content != ' ' && *content != '\n' && fdf_is_space(*(content+ 1)))
            x ++;
        if ((*content == '\n') || (*(content + 1) == '\0'))
        {
            if (map -> width == 0)
                map -> width = x;
            if ((map->width != x && map->width != 0) || x == 0)
            {
                ////ft_printf("error");
                exit(1);                
            }
            x = 0;
            y ++;
        }
        content ++;
    }
    map->height = y;
}

void init_xyz(t_map *map, int i, int j, char *content)
{
    int screen_width = 1920;
    int screen_height = 1080;

    map->pts[i][j].x = j * (map->gap) + (screen_width / 2) - ((map->gap * (map->width - 1)) / 2);
    map->pts[i][j].y = i * (map->gap) + (screen_height / 2) - ((map->gap * (map->height - 1)) / 2);
    map->pts[i][j].z = ft_atoifdf(&content, map, i, j);  
}


void    put_point(t_map *map, char *content)
{
    int i;
    int j;

    j = 0;
    i = 0;
    map -> size = (map->width) * (map->height);
    map -> pts = (t_point **)malloc(sizeof(t_point*)*(map->height) + 1);
    while(i < map->height)
    {
        map->pts[i] = (t_point *)malloc(sizeof(t_point)*(map->width) + 1);
        i ++;
    }
    if (!(map -> pts))
        fdf_error("malloc error");
    i = 0;
    while(i < map->height)
    {
        j = 0;
        while(j < map->width)
        {
            while (*content == '\n' || *content == ' ')
			    content++;
            init_xyz(map, i, j, content);
            while (*content && *content != ' ' && *content != '\n')
                 content++;
            j ++;   
        }
        i ++;
    }
}

int		create_argb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;
    
    if (x >= 0 && y >= 0 && x < 1920 && y < 1080)
    { 
        dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int*)dst = color;
    }
}

int        create_trgb(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 | g << 8 | b);
}
 
// decoding
int        get_t(int trgb)
{
    return (trgb & (0xFF << 24));
}
int        get_r(int trgb)
{
    return (trgb & (0xFF << 16));
}
int        get_g(int trgb)
{
    return (trgb & (0xFF << 8));
}
int        get_b(int trgb)
{
    return (trgb & 0xFF);
}


int main(int argc, char **argv)
{
    void    *mlx;
    void    *win;
    t_map   *map;
    char    *content;
    t_data  img;
    alloc_map(&map);
    if (argc != 2)
    {
        //ft_printf("error");
        exit(1);
    }
    if (argc == 2)
    {
        content = map_parshing(argv, map);
        if (content == NULL)
		    fdf_error("READ MAP ERROR");
        find_wh(map, content);
        put_point(map, content);
        ft_isometric(map);
        //init_xy(map);   
        
        for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            printf("Point[%d][%d]: y=%d, x=%d, z=%d, color=%X\n", i, j,  map->pts[i][j].y, map->pts[i][j].x, map->pts[i][j].z, map->pts[i][j].color);
        }
        mlx = mlx_init();
        win = mlx_new_window(mlx, 1920, 1080, "test");
        img.image = mlx_new_image(mlx, 1920, 1080);
        img.addr = mlx_get_data_addr(img.image, &img.bits_per_pixel, &img.line_length, &img.endian);
        int i = 0;
        while(i < map->height)
        {
            int j = 0;
            while(j < map->width)
            {
                my_mlx_pixel_put(&img, map->pts[i][j].x, map->pts[i][j].y, map->pts[i][j].color);
                j ++;
            }
            i ++;
        }
        mlx_put_image_to_window(mlx, win, img.image, 0, 0);
        mlx_loop(mlx);
    }
    free(map);
    return(0);
    }
}
