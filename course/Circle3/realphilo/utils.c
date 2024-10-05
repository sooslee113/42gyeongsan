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
	return (result * sign);
}

void    error_exit(const char *error)
{
    printf("%s", error);
}