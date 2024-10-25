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
static void tinking(t_philo *philo)
{
    write_status(THINKING, philo, DEBUG_MODE);

}
static void eat(t_philo *philo)
{
    // 1)
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

    wait_all_thread(philo->table);
    
    increase_long(&philo->table->table_mutex, &philo->table->threads_running_nbr);
    //syncro with monitor 
    //increase a table varible counter, with all threads running
    //set last meal time
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
        tinking (philo); //todo
    }
    return (NULL);
}

void    dinner_start(t_table *table)
{
    int i;
    
    i = 0;
    if (table -> nbr_limit_meals == 0)
        return ;
    else if (1 == table->philo_nbr)
        ;//todo
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
}
