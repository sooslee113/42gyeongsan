/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:15:52 by sooslee           #+#    #+#             */
/*   Updated: 2024/03/23 18:04:51 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ftprintf.h"

int	ft_puthex(int n)
{
	char	*sixteen;
	int		count;

	count = 1;
	sixteen = "0123456789abcdef";
	if (n >= 0 && n <= 15)
	{
		ft_printfc(sixteen[n]);
	}
	else if (n >= 15 && n <= 2147483647)
	{
		count += ft_puthex(n / 16);
		ft_puthex(n % 16);
	}
	return (count);
}
