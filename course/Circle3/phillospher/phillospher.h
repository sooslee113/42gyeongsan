#ifndef PHILLOSPHER_H
# define PHILLOSPHER_H

# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_philo
{
    pthread_t thread;
    int id;
    int eaten_times;
    long last_meal_time;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;

} t_philo;

typedef struct s_program
{
    int number_of_philo;
    int time_to_die;
    int tiem_to_eat;
    int time_to_sleep;
    int num_times_to_eat;
    t_philo *philo  ;
    pthread_mutex_t *forks;
    long start_time;
}   t_program;

void	show_error(char *errorno);
int ft_atoi(const char *nptr);
void	check_argv(int argc, char **argv);
int is_argv_num(char *argv);
void    init_argv(t_program **s_program, char **argv);
void	init_phillo(t_program *program);

#endif