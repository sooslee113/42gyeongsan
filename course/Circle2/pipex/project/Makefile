NAME = pipex

CC = cc
RM = rm -f
CFLAGS = -g -fsanitize=address -Wall -Wextra -Werror

SUBDIR = libft

SRCS_MUST = exexe6.c \
	    ./libft/ft_strnstr.c \
	    ./libft/ft_strjoin.c \
	    ./libft/ft_strlen.c \
	    ./libft/ft_substr.c \
	    ./libft/ft_strdup.c \
	    ./libft/ft_split.c	\
	    ./ft_printf/ft_printf.c \
	    ./ft_printf/ft_putptr.c \
	    ./ft_printf/ft_puthex.c \
	    ./ft_printf/ft_puthex2.c \
	    ./ft_printf/ft_putnbr.c \
	    ./ft_printf/ft_putunsignn.c \
	    ./ft_printf/ft_putchar.c \
	    ./ft_printf/ft_putstr.c

SRCS = $(SRCS_MUST)
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c 
	@make re -C ./libft
	@make re -C ./ft_printf
	$(CC) $(CFLAGS) -c  $< -o  $@

clean:
	@make clean -C ./libft
	@make clean -C ./ft_printf
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
