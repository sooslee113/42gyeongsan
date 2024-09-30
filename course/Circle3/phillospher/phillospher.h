#ifndef PHILLOSPHER_H
# define PHILLOSPHER_H

# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>


typedef struct s_program
{
    int number_of_philo; // 철학자 수
    int time_to_die; // 죽는시간
    int time_to_eat; //먹는 시간
    int time_to_sleep; // 자는 시간
    int eat_num; // 철학자가 먹어야 하는 횟수
    pthread_mutex_t *forks; // 포크 뮤텍스
    pthread_mutex_t mutex;  
    int monitor; // 모니터 함수
    int start_time;
}   t_program;

typedef struct s_philo
{
    pthread_t thread; // 쓰레드
    int id; // 철학자 번호
    int eaten_times; // 먹은 횟수
    int left_fork; // 왼쪽 포크
    int right_fork; // 오른쪽 포크
    long last_meal_time; // 마지막으로 먹은시간
    long start_time; //시작 시간
    t_program *program; // 프로그램
} t_philo;

void	show_error(char *errorno);
int ft_atoi(const char *nptr);
void	check_argv(int argc, char **argv);
int is_argv_num(char *argv);
void    init_argv(t_program **program, char **argv);
void	init_phillo(t_philo **philo, t_program *program);
long    get_time(void);
void	making_mutex(t_program *program);
void    monitoring(t_program *program, t_philo *philo);
int    ft_philo_printf(t_program *program, int id, char *msg);
int ft_philo_action(t_program *program, t_philo *philo);
int making_thread(t_program *program, t_philo *philo);
void *thread_f(void *data);
void	ft_pass_time(long wait_time, t_program *arg);

#endif