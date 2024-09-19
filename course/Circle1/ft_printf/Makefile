NAME = libftprintf.a

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = crs

SRCS_MUST = ft_printf.c	\
	    ft_putptr.c \
	    ft_puthex2.c \
	    ft_puthex.c \
	    ft_putnbr.c \
	    ft_putstr.c \
	    ft_putunsignn.c\
	    ft_putchar.c

OBJS = $(SRCS_MUST:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

