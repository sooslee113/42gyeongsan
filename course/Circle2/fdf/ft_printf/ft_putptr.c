/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:32:39 by sooslee           #+#    #+#             */
/*   Updated: 2024/06/13 01:14:42 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthexptr(unsigned long long n)
{
	char	*hex;
	int		count;

	count = 1;
	hex = "0123456789abcdef";
	if (n <= 15)
	{
		ft_putchar(hex[n]);
	}
	else if (n >= 16 && n <= ULLONG_MAX)
	{
		count += ft_puthexptr(n / 16);
		ft_puthexptr(n % 16);
	}
	return (count);
}

int	ft_putptr(void *ptr)
{
	unsigned long long	numptr;

	numptr = (unsigned long long)ptr;
	if (ptr == NULL)
	{
		ft_putstr("(nil)");
		return (5);
	}
	write(1, "0x", 2);
	return (ft_puthexptr(numptr) + 2);
}
