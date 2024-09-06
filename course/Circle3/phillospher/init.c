/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:51:49 by sooslee           #+#    #+#             */
/*   Updated: 2024/09/06 19:22:12 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phillospher.h"

void    init_argv(t_program **s_program, char **argv)
{
	*s_program = malloc(sizeof(t_program)); // 메모리 동적 할당
	if (s_program == NULL) 
    	return ;

	(*s_program) -> number_of_philo = ft_atoi(argv[1]);
	(*s_program) -> time_to_die = ft_atoi(argv[2]);
	(*s_program) -> tiem_to_eat = ft_atoi(argv[3]);
	(*s_program) -> time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		(*s_program) -> num_times_to_eat = ft_atoi(argv[5]);
	else
		(*s_program) -> num_times_to_eat = -42;
	(*s_program) -> philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if ((*s_program)-> philo == NULL) 
		return ;
	(*s_program)->forks = malloc(sizeof(pthread_mutex_t) * (*s_program)->number_of_philo);
    if ((*s_program)->forks == NULL)
		return ;

	(*s_program) -> start_time = 0;
}
void	init_phillo(t_program *program)
{
	int i;
	
	i = 0;
	while (i < program->number_of_philo)
	{
		program->philo[i].id = i + 1;
		program->philo[i].eaten_times = 0;
		program->philo[i].last_meal_time = program->start_time;
		// 포크 초기화
		program->philo[i].left_fork = &program->forks[i];
		program->philo[i].right_fork = &program->forks[(i + 1) % program->number_of_philo];

		pthread_mutex_init(program->philo[i].left_fork, NULL);
		pthread_mutex_init(program->philo[i].right_fork, NULL);
		i++;
	}
}