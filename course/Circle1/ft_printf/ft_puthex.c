/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:15:52 by sooslee           #+#    #+#             */
/*   Updated: 2024/03/24 21:36:46 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_puthex(unsigned int n)
{
	char	*sixteen;
	int		count;

	count = 1;
	sixteen = "0123456789abcdef";
	if (n <= 15)
	{
		ft_printfc(sixteen[n]);
	}
	else
	{
		count += ft_puthex(n / 16);
		ft_puthex(n % 16);
	}
	return (count);
}
