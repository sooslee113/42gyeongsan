/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:41:20 by sooslee           #+#    #+#             */
/*   Updated: 2024/03/24 16:12:46 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putunsignn(unsigned int n)
{
	int	count;

	count = 1;
	if (n < 10)
	{
		n += '0';
		ft_printfc(n);
	}
	else if (n >= 10 && n <= (unsigned int)ULONG_MAX)
	{
		count += ft_putunsignn(n / 10);
		ft_putunsignn(n % 10);
	}
	return (count);
}
