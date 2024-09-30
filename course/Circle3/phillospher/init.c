/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:51:49 by sooslee           #+#    #+#             */
/*   Updated: 2024/09/27 14:33:13 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phillospher.h"

void    init_argv(t_program **program, char **argv)
{
	(*program) = malloc(sizeof(t_program)); // 메모리 동적 할당
	if (*program == NULL) 
    	return ;
	(*program) -> number_of_philo = ft_atoi(argv[1]);
	(*program) -> time_to_die = ft_atoi(argv[2]);
	(*program) -> time_to_eat = ft_atoi(argv[3]);
	(*program) -> time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		(*program) -> eat_num = ft_atoi(argv[5]);
	else
		(*program) -> eat_num = -42;
	(*program) -> monitor = 0;
	(*program) -> start_time = 0;
	making_mutex(*program);
}
void	init_phillo(t_philo **philo, t_program *program)
{
	int i;
	
	*philo = malloc(sizeof(t_philo) * program -> number_of_philo);
	if (philo == NULL)
		return ;
	i = 0;
	while (i < program->number_of_philo)
	{
		(*philo)[i].id = i + 1;
		(*philo)[i].eaten_times = 0;
		(*philo)[i].last_meal_time = 0;
		(*philo)[i].left_fork = i;
		(*philo)[i].right_fork = (i + 1) % program->number_of_philo;
		(*philo)[i].program = program;
		i++;
	}
}

void	making_mutex(t_program *program)
{
	int	i;
	i = 0;

	if (pthread_mutex_init(&(program->mutex), NULL) == -1)
    	return;
	program -> forks = malloc(sizeof(pthread_mutex_t) * program -> number_of_philo);
	if (! program->forks)
		return ;
	while (i < program -> number_of_philo)
	{
		if (pthread_mutex_init(&(program -> forks[i]), NULL) == -1)
			return ;
		i ++;
	}
}
