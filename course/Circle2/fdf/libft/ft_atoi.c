/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:02:16 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/20 23:40:35 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

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
