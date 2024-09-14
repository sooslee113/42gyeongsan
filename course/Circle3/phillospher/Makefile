NAME = philo

CC = cc
RM = rm -f
CFLAGS = -g -Wall -Wextra -Werror

SUBDIR = libft

SRCS_MUST = main.c \
	    show_error.c \
	    utils.c \
		init.c

SRCS = $(SRCS_MUST)
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c 
	$(CC) $(CFLAGS) -c  $< -o  $@

clean:
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
