NAME = philo

CC = cc
RM = rm -f
CFLAGS =  -Wall -Wextra -Werror	-lpthread

SRCS_MUST = main.c \
		utils.c \
		safer.c \
		init.c \
		dinner.c \
		getter_setter.c \
		write.c \
		synchro_utils.c \
		monitor.c 


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
