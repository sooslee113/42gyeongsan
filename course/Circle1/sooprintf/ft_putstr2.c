/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:50:27 by sooslee           #+#    #+#             */
/*   Updated: 2024/03/24 16:12:34 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putstr2(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (str == NULL)
	{
		count += ft_putstr2("(null)");
		return (6);
	}
	while (str[i] != '\0')
	{
		count += ft_printfc(str[i]);
		i ++;
	}
	return (count);
}
