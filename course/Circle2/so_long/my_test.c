#include "so_long.h"
#include <stdio.h>
int main()
{
    t_game my_game;
    
    my_game.mlx_ptr = mlx_init();
    map_read(&my_game);
    my_game.win_ptr = mlx_new_window(my_game.mlx_ptr , ft_strlen(my_game.line) * (size_t)50, my_game.height * (size_t)50, "10bird's adventure");
    setting_img(&my_game);
    mlx_loop(my_game.mlx_ptr);
    return 0;
}