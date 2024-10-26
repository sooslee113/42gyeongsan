#ifndef PHILLOSPHER_H
# define PHILLOSPHER_H

# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <errno.h>

#define DEBUG_MODE 1
/*
./philo '철학자 수', '죽는 시간', '먹는 시간'. '자는 시간', [철학자가 먹어야 하는 끼니]
*/
typedef pthread_mutex_t t_mutex;
typedef struct s_table t_table;

typedef enum e_opcode
{
    LOCK,
    UNLOCK,
    INIT,
    DESTORY,
    CREATE,
    JOIN,
    DETACH,
}   t_opcode;

typedef enum e_status
{
    EATING,
    SLEEPING,
    THINKING,
    TAKE_FIRST_FORK,
    TAKE_SECOND_FORK,
    DIED,
}   t_philo_status;

typedef struct s_fork
{
    t_mutex fork;
    int fork_id; 
} t_fork;

typedef struct s_philo
{
    int id;
    long meals_counter;
    bool full; // 철학자가 밥을 다 먹었나 안먹었나 판별해주기 위해서
    long last_meal_time; // 마지막 식사후 경과된 시간을 추적한다.
    t_fork *first_fork;
    t_fork *second_fork;
    pthread_t thread;
    t_mutex philo_mutex; //useful for races with the monitor;
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
    bool    all_threads_ready;
    bool    threads_running_nbr;
    pthread_t monitor;
    t_mutex table_mutex;
    t_mutex write_mutex;
    t_fork *forks;
    t_philo *philos;
} t_table;

typedef enum e_time_code
{
    SECOND,
    MULLISECOND,
    MICROSECOND,
}   t_time_code;

void    show_error(const char *error);
void	check_argv(int argc, char **argv);
int     ft_atoi(const char *nptr);
void    *safe_malloc(size_t bytes);
void    safe_mutex_handle(t_mutex *mutex, t_opcode opcode);
void    safe_thread_handle(pthread_t *thread, void*(*foo)(void *),void *data, t_opcode opcode);
void    data_init(t_table *table, char **argv);
void    set_bool(t_mutex *mutex, bool *dest, bool value);
bool    get_bool(t_mutex *mutex, bool *value); // 안전하게 읽기
void    set_long(t_mutex *mutex, long *dest, long value);
long    get_long(t_mutex *mutex, long *value); // 안전하게 읽기
bool	simulation_finished(t_table *table);
long    get_time(void);
void	ft_usleep(long usec, t_table *table);
void    write_status(t_philo_status status, t_philo *philo, bool debug);
void    dinner_start(t_table *table);
bool    all_threads_running(t_mutex *mutex, long *threads, long philo_nbr);

#endif