NAME = so_long

CC = cc

CFLAGS = -g -Wall -Werror -Wextra #-fsanitize=address

MLX = -Lminilibx-linux -lmlx -lXext -lX11

RM = rm -f

SRCS_MUST =  main.c \
		hook.c \
		map_read.c \
		error.c \
		map_parshing.c \
		check_route.c \
		checking_map.c  \
		lets_free.c \
	    ./libft/ft_split.c \
	    ./libft/ft_strncmp.c \
	    ./ft_printf/ft_printf.c \
	    ./ft_printf/ft_putptr.c \
	    ./ft_printf/ft_puthex.c \
	    ./ft_printf/ft_puthex2.c \
	    ./ft_printf/ft_putnbr.c \
	    ./ft_printf/ft_putunsignn.c \
	    ./ft_printf/ft_putchar.c \
	    ./ft_printf/ft_putstr.c \
	    ./get_next_line/get_next_line.c \
	    ./get_next_line/get_next_line_utils.c


SRCS = $(SRCS_MUST)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(MLX)

%.o: %.c
	@make -C ./minilibx-linux
	@make -C ./libft
	@make -C ./ft_printf
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
