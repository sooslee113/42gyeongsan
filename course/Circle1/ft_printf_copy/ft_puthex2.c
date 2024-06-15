/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:50:14 by sooslee           #+#    #+#             */
/*   Updated: 2024/03/23 18:04:31 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ftprintf.h"

int	ft_puthex2(int n)
{
	char	*hex;
	int		count;

	count = 1;
	hex = "0123456789ABCDEF";
	if (n >= 0 && n <= 15)
	{
		ft_printfc(hex[n]);
	}
	else if (n >= 10 && n <= 2147483647)
	{
		count += ft_puthex2(n / 16);
		ft_puthex2(n % 16);
	}
	return (count);
}
