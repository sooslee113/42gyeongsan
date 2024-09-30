    /* ************************************************************************** */
    /*                                                                            */
    /*                                                        :::      ::::::::   */
    /*   acting.c                                           :+:      :+:    :+:   */
    /*                                                    +:+ +:+         +:+     */
    /*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
    /*                                                +#+#+#+#+#+   +#+           */
    /*   Created: 2024/09/06 13:27:26 by sooslee           #+#    #+#             */
    /*   Updated: 2024/09/27 14:35:09 by sooslee          ###   ########.fr       */
    /*                                                                            */
    /* ************************************************************************** */

    #include "phillospher.h"

    int    ft_philo_printf(t_program *program, int id, char *msg)
    {
        long current_time;

        current_time = get_time();
        if (current_time == -1)
            return (-1);
        pthread_mutex_lock(&(program->mutex));
        if (! program -> monitor)
        {
            printf("%ld %d %s\n", current_time - program->start_time, id, msg);
        }
        pthread_mutex_unlock(&(program->mutex));
        return(0);
    }

    void    monitoring(t_program *program, t_philo *philo)
    {
        int i;
        long current_time;

        while(!program->monitor)
        {
            if (program->eat_num != 0 && philo->eaten_times == program->eat_num)
            {
                program->monitor = 1;
                break ;
            }
            i = 0;
            while (i < program -> number_of_philo)
            {
                current_time = get_time();
                if (current_time - philo[i].last_meal_time >= program->time_to_die)
                {
                    ft_philo_printf(program, philo[i].id, "is died");
                    program -> monitor = 1;
                }
                i ++;
            }
            usleep(10); 
        }
    }

    int ft_philo_action(t_program *program, t_philo *philo)
    {
        pthread_mutex_lock(&(program->forks[philo->left_fork]));
        if (program->number_of_philo != 1)
        {
            pthread_mutex_lock(&(program->forks[philo->right_fork]));
            ft_philo_printf(program, philo->id, "is has taken a fork");
            ft_philo_printf(program, philo->id, "is eatting");
            philo->last_meal_time = get_time();
            philo->eaten_times += 1;
            pthread_mutex_unlock(&(program->forks[philo->right_fork]));
        }
        pthread_mutex_unlock(&(program->forks[philo->left_fork]));
        return(0);
    }

void	ft_pass_time(long wait_time, t_program *arg)
{
	long	start;
	long	now;

	start = get_time();
	while (!(arg->monitor))
	{
		now = get_time();
		if ((now - start) >= wait_time)
			break ;
		usleep(10);
	}
}