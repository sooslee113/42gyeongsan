/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:39:03 by sooslee           #+#    #+#             */
/*   Updated: 2024/10/28 21:08:24 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phillospher.h"

/*
먹기 순서
1.포크를 집는다
2. 먹기 : 먹었는 거 출력, 마지막 식사 시간 업데이트, 먹은 횟수 업데이트, 
3. 포크 집기
*/
/*
./philo '철학자 수', '죽는 시간', '먹는 시간'. '자는 시간', [철학자가 먹어야 하는 끼니]
*/
// TODO
void	*lone_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_all_threads(philo->table);
	set_long(&philo->philo_mutex, &philo->last_meal_time, get_time());
	increase_long(&philo->table->table_mutex, \
			&philo->table->threads_running_nbr);
	write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
	while (simulation_finished(philo->table))
		usleep(2000);
	//ft_usleep(philo->table->time_to_die, philo->table);
	set_bool(&philo->table->table_mutex, &philo->table->end_simulation, true);
	return (NULL);
}

void	thinking(t_philo *philo, bool pre_simulation)
{
	long	t_eat;
	long	t_sleep;
	long	t_think;

	if (!pre_simulation)
		write_status(THINKING, philo, DEBUG_MODE);
	if (philo->table->philo_nbr % 2 == 0)
		return ;

	t_eat = philo->table->time_to_eat;
	t_sleep = philo->table->time_to_sleep;
	t_think = t_eat * 2 - t_sleep;

	if (t_think < 0)
		t_think = 0;
	ft_usleep(t_think * 0.42, philo->table);
}

static void	eat(t_philo *philo)
{
    safe_mutex_handle(&philo->first_fork->fork, LOCK);
    write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
    safe_mutex_handle(&philo->second_fork->fork, LOCK);
    write_status(TAKE_SECOND_FORK, philo, DEBUG_MODE);
    // 2)
    set_long(&philo->philo_mutex, &philo->last_meal_time , get_time());
    philo->meals_counter ++;
    write_status(EATING, philo, DEBUG_MODE);
    ft_usleep(philo->table->time_to_eat, philo->table);
    if (philo->table->nbr_limit_meals > 0 
    && philo->meals_counter == philo->table->nbr_limit_meals)
        set_bool(&philo->philo_mutex, &philo->full, true);
    //3)
    safe_mutex_handle(&philo->first_fork->fork, UNLOCK);
    safe_mutex_handle(&philo->second_fork->fork, UNLOCK);
}
void    *dinner_simulation(void *data)
{
    t_philo *philo;
    philo = (t_philo *)data;
    wait_all_threads(philo->table);
    set_long(&philo->philo_mutex, &philo->last_meal_time, get_time());
    increase_long(&philo->table->table_mutex, &philo->table->threads_running_nbr); //todo
    de_synchronize_philos(philo);
    while(!simulation_finished(philo->table))
    {
        
        //check list
        // 1) Am I full?
        if (philo->full) //Todo thread safe?
            break;
        // 2) eat
        eat(philo);
        // 3) sleep -> write_status & precise usleep
        write_status(SLEEPING, philo, DEBUG_MODE);
        ft_usleep(philo->table->time_to_sleep, philo->table);
        // 4) thinking
        thinking (philo, false); //todo
    }
    return (NULL);
}
void    dinner_start(t_table *table)
{
    int i;
    i = 0;
    if (0 == table -> nbr_limit_meals)
        return ;
    else if (1 == table->philo_nbr)
        safe_thread_handle(&table->philos[0].thread, lone_philo, &table->philos[0], CREATE);//todo
    else
    {
        while(i < table->philo_nbr)
        {
            safe_thread_handle(&table->philos[i].thread, dinner_simulation, &table->philos[i], CREATE);
            i ++;
        }
    }
    safe_thread_handle(&table->monitor, monitor_dinner, table, CREATE); // TODO
    /*start simulation*/
    table->start_time = get_time();
    // thread ready
    set_bool(&table->table_mutex, &table->all_threads_ready, true);
    i = -1;
    while(++i < table->philo_nbr)
        safe_thread_handle(&table->philos[i].thread, NULL, NULL, JOIN);
    //all philos are full
    set_bool(&table->table_mutex, &table->end_simulation, true);
    safe_thread_handle(&table->monitor, NULL, NULL, JOIN);
}
