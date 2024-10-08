/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:46:53 by sooslee           #+#    #+#             */
/*   Updated: 2024/09/19 14:42:11 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

long get_time(void)
{
	struct timeval time;
	long what_time;

	gettimeofday(&time, NULL);
	what_time = ((size_t)time.tv_sec * 1000) + ((size_t)time.tv_usec / 1000);
	return (what_time);
}