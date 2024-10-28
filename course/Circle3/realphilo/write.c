/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:23:51 by sooslee           #+#    #+#             */
/*   Updated: 2024/10/28 20:29:08 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phillospher.h"

static void	write_status_debug(t_philo_status status, t_philo *philo, \
		long elapsed)
{
	if ((TAKE_FIRST_FORK == status && !simulation_finished(philo->table)))
		printf("%ld, %d has taken a fork1\n", elapsed, philo->id);
	else if (TAKE_SECOND_FORK == status && !simulation_finished(philo->table))
		printf("%ld, %d has taken a fork2 \n", elapsed, philo->id);
	else if (EATING == status && !simulation_finished(philo->table))
		printf("%ld, %d is eatting\n", elapsed, philo->id);
	else if (SLEEPING == status && !simulation_finished(philo->table))
		printf("%ld, %d is sleeping\n", elapsed, philo->id);
	else if (THINKING == status && !simulation_finished(philo->table))
		printf("%ld, %d is thinking\n", elapsed, philo->id);
	else if (DIED == status && simulation_finished(philo->table))
		printf("%ld, %d is died\n", elapsed, philo->id);
}

void	write_status(t_philo_status status, t_philo *philo, bool debug)
{
	long	elapsed;

	elapsed = get_time() - philo->table->start_time;
	safe_mutex_handle(&philo->table->write_mutex, LOCK);
	if (debug)
		write_status_debug(status, philo, elapsed);
	else
	{
		if (((TAKE_FIRST_FORK == status || TAKE_SECOND_FORK == status) \
					&& !simulation_finished(philo->table)))
			printf("%ld %d has taken a fork\n", elapsed, philo->id);
		else if (EATING == status && !simulation_finished(philo->table))
			printf("%ld %d is eating\n", elapsed, philo->id);
		else if (SLEEPING == status && !simulation_finished(philo->table))
			printf("%ld %d is sleeping\n", elapsed, philo->id);
		else if (THINKING == status && !simulation_finished(philo->table))
			printf("%ld %d is thinking\n", elapsed, philo->id);
		else if (DIED == status && simulation_finished(philo->table))
			printf("%ld %d is died\n", elapsed, philo->id);
	}
	safe_mutex_handle(&philo->table->write_mutex, UNLOCK);
}
