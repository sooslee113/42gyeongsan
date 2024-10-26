#include "phillospher.h"


/*
*SPINLOCK to Synchronize philos start
*/
void    wait_all_threads(t_table *table)
{
    while(!get_bool(&table->table_mutex, table->all_threads_ready))
        ;
}

/*
*Monitor busy waits until
all threads are running
*/
bool    all_threads_running(t_mutex *mutex, long *threads, long philo_nbr)
{
    bool ret;
    ret = false;
    safe_mutex_handle(mutex, LOCK);
    if (*threads == philo_nbr)
        ret = true;
    safe_mutex_handle(mutex, UNLOCK);
    return (ret);
}

void  increase_long(t_mutex *mutex, long *value)
{
    safe_mutex_handle(mutex, LOCK);
    (*value)++;
    safe_mutex_handle(mutex, UNLOCK);
}