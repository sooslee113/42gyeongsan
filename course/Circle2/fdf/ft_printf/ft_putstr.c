/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:50:27 by sooslee           #+#    #+#             */
/*   Updated: 2024/06/12 02:18:16 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (str == NULL)
	{
		count += ft_putstr("(null)");
		return (6);
	}
	while (str[i] != '\0')
	{
		count += ft_putchar(str[i]);
		i ++;
	}
	return (count);
}
