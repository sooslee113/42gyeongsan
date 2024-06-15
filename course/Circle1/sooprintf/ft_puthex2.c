/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:50:14 by sooslee           #+#    #+#             */
/*   Updated: 2024/03/24 16:12:14 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_puthex2(unsigned int n)
{
	char	*hex;
	int		count;

	count = 1;
	hex = "0123456789ABCDEF";
	if (n <= 15)
	{
		ft_printfc(hex[n]);
	}
	else
	{
		count += ft_puthex2(n / 16);
		ft_puthex2(n % 16);
	}
	return (count);
}
