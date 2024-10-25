#include "phillospher.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	unsigned long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (('\b' <= nptr[i] && nptr[i] <= '\r') || (nptr[i] == ' '))
	{
		i ++;
	}
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i ++;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9') && nptr[i])
	{
		result = result * 10 + nptr[i] - '0';
		i ++;
	}
	return (int)(result * sign);
}

void    show_error(const char *error)
{
    printf("%s", error);
	exit(EXIT_FAILURE);
}

long get_time(void)
{
	struct timeval time;
	long what_time;

	gettimeofday(&time, NULL);
	what_time = ((size_t)time.tv_sec * 1000) + ((size_t)time.tv_usec / 1000);
	return (what_time);
}

	/* precise usleep, the real one suk
	1) usleep the majority of time, not CPU intensive
	2) refine last microsec with spinlock

 */
void	ft_usleep(long usec, t_table *table)
{
	long start;
	long elapsed;
	long rem;
	start = get_time();
	while (get_time() - start < usec)
	{
		if (simulation_finished(table))
			break;
		elapsed = get_time() - start;
		rem = usec - elapsed;
		if (rem > 1e3)
			usleep(rem / 2);
		else
		{
			while(get_time() - start < usec)
				;
		}
	}
}