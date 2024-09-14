NAME = fract_ol

CC = cc

CFLAGS = -g -fsanitize=address -Wall -Werror -Wextra

MLX = -Lminilibx-linux -lmlx -lXext -lX11

RM = rm -f

SRCS_MUST =  main.c \
	     init.c \
	     key.c \
	     mandelbrot.c 
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
