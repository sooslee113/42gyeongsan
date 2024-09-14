#ifndef PHILLOSPHER_H
# define PHILLOSPHER_H

# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>
# include <stdlib.h>


typedef struct s_program
{
    int number_of_philo;
    int time_to_die;
    int tiem_to_eat;
    int time_to_sleep;
    int num_times_to_eat;
    pthread_mutex_t *forks;
    int monitor;
}   t_program;

typedef struct s_philo
{
    pthread_t thread;
    int id;
    int eaten_times;
    int left_fork;
    int right_fork;
    long last_meal_time;
    long start_time;
    t_program *program;
} t_philo;

void	show_error(char *errorno);
int ft_atoi(const char *nptr);
void	check_argv(int argc, char **argv);
int is_argv_num(char *argv);
void    init_argv(t_program **program, char **argv);
void	init_phillo(t_philo **philo, t_program *program);

#endif