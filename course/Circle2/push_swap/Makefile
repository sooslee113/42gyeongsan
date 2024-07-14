NAME = push_swap

CC = cc

CFLAGS = -g -fsanitize=address -Wall -Werror -Wextra

RM= rm -f

SRCS_MUST = 	push_swap.c \
		operate.c \
		ft_atoi.c \
		ft_split.c \
		./ft_printf/ft_printf.c \
	    	./ft_printf/ft_putptr.c \
	    	./ft_printf/ft_puthex.c \
	    	./ft_printf/ft_puthex2.c \
	    	./ft_printf/ft_putnbr.c \
	    	./ft_printf/ft_putunsignn.c \
	    	./ft_printf/ft_putchar.c \
	    	./ft_printf/ft_putstr.c \
		parsing.c \
		under_five.c \
		radix_sort.c \
		push.c \
		swap.c \
		rotate.c \
		reverse_rotate.c \
		let_me_free.c

SRCS = $(SRCS_MUST)
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	@make re -C ./ft_printf
	$(CC) $(CFLAGS) -c $< -o $@


clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
