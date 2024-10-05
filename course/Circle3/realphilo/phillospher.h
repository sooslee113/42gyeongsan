#ifndef PHILLOSPHER_H
# define PHILLOSPHER_H

typedef pthread_mutex_t t_mutex;
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
/*
./philo '철학자 수', '죽는 시간', '먹는 시간'. '자는 시간'
*/

typedef struct s_fork
{
    t_mutex fork;
    int fork_id; 
} t_fork;

typedef struct s_philo
{
    int id;
    long meals_counter;
    bool full;
    long last_meal_time; // 마지막 식사후 경과된 시간을 추적한다.
    t_fork *right_fork;
    t_fork *left_fork;
    pthread_t thread;
    t_table *table;    
} t_philo;

typedef struct s_table
{
    long    philo_nbr;
    long    time_to_die;
    long    time_to_eat;
    long    time_to_sleep;
    long    nbr_limit_meals;
    long    start_time;
    bool    end_simulation; //모니터링
    t_fork *forks;
    t_philo *philos;
} t_table;

void    error_exit(const char *error);

#endif