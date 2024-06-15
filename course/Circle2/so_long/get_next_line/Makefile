# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sooslee <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 21:21:03 by sooslee           #+#    #+#              #
#    Updated: 2024/05/13 21:41:35 by sooslee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER = get_next_line.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = crs
NAME = get_next_line.a
SRCS_GNL = get_next_line.c \
       		get_next_line_utils.c
RM = rm -f

SRCS = $(SRCS_GNL)
OBJS= $(SRCS:.c=.o)
all : $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(AR) $(ARFLAGS) $@ $^
$.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
