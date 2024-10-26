#include "phillospher.h"

static bool philo_died(t_philo *philo)
{
    long    elapsed;
    long    t_to_die;

    elapsed = get_time() - get_long(&philo->philo_mutex, &philo->last_meal_time);
    t_to_die = philo->table->time_to_die;

    if(elapsed > t_to_die)
        return(true);
    return (false);
}

void    *monitor_dinner(void *data)
{
    t_table *table;

    table = (t_table *)data;
    //make sure all philo running
    //spinlock till all thread run 
    while(!all_threads_running(&table->table_mutex, &table->threads_running_nbr, table->philo_nbr))

    while(!simulation_finished(table))
    {
        int i;

        i = -1;
        if(philo_died(table->philos + i))
        {
            set_bool(&table->table_mutex, &table->end_simulation, true);
            write_status(DIED, table->philos + i, DEBUG_MODE);
        }
    }
    return (NULL);
}