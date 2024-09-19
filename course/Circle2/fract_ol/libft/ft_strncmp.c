/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:15:14 by sooslee           #+#    #+#             */
/*   Updated: 2024/03/11 13:53:14 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*str3;
	unsigned char	*str4;
	size_t			i;

	str3 = (unsigned char *) str1;
	str4 = (unsigned char *) str2;
	i = 0;
	while (i < n && ((str4[i] != '\0') || (str3[i] != '\0')))
	{
		if (str3[i] != str4[i])
			return (str3[i] - str4[i]);
		i ++;
	}
	return (0);
}