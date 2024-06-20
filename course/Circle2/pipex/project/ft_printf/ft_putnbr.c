/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:16:41 by sooslee           #+#    #+#             */
/*   Updated: 2024/06/12 02:19:12 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 1;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		count = 11;
		return (count);
	}
	else if (n < 0)
	{
		n *= -1;
		count += ft_putchar('-');
	}
	if (0 <= n && n < 10)
	{
		n += '0';
		ft_putchar(n);
	}
	else if (n >= 10 && n <= 2147483647)
	{
		count += ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	return (count);
}
