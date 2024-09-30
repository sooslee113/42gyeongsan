/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:32:03 by sooslee           #+#    #+#             */
/*   Updated: 2024/09/27 21:41:43 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phillospher.h"

void *thread_f(void *data)
{
    t_philo *philo;
    t_program *program;

    philo = data;
    program = philo->program;
    while(!program->monitor)
    {
        ft_philo_action(program, philo);
        ft_philo_printf(program, philo->id, "is sleeping");
        ft_pass_time((long)program->time_to_sleep, program);
        ft_philo_printf(program, philo->id, "is thinking");
    }
    return (0);
}

int making_thread(t_program *program, t_philo *philo)
{
    int i;
    i = 0;

    while(i < program -> number_of_philo)
    {
        pthread_mutex_lock(&philo->program->mutex);
        philo[i].last_meal_time = get_time();
        pthread_mutex_unlock(&philo->program->mutex);
        pthread_mutex_lock(&philo->program->mutex);
        philo[i].start_time = get_time();
        pthread_mutex_unlock(&philo->program->mutex);
        if (pthread_create(&(philo[i].thread), NULL, thread_f, &philo[i]))
            return (1);
        i ++;
    }
    monitoring(program, philo);
    i = 0;
    while (i < program->number_of_philo)
        pthread_join(philo[i++].thread, NULL);
    return (0);
}