/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:02:16 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/19 04:05:20 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi(const char *nptr)
{
	long long	i;
	long long	sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == ' '))
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
