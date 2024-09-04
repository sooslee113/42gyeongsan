#ifndef PHILLOSPHER_H
# define PHILLOSPHER_H

# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>

void	show_error(char *errorno);
int ft_atoi(const char *nptr);
void	check_argv(char **argv);
int is_argv_num(char *argv);

#endif