/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoifdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:02:16 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/25 21:53:09 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(char **nptr)
{
	int	result;
	int i;

	i = 0;
	result = 0x0;
	while(ft_isdigit(**nptr) || ft_isalpha(**nptr))
	{
		if (**nptr >= 'A' && **nptr <= 'F')
			i = 10 + **nptr - 'A';
		else if (**nptr >= 'a' && **nptr <= 'f')
			i = 10 + **nptr - 'a';
		else
			i = **nptr - '0';
		result *= 16;
		result += i;
		(*nptr)++;
	}
		return (result);
}

int	ft_atoifdf(char **nptr, t_map *map, int i, int j)
{
	int	sign;
	int	result;
	sign = 1;
	result = 0;
	if (**nptr == '+' || **nptr == '-')
	{
		if (**nptr == '-')
			sign = -1;
		(*nptr) ++;
	}
	while ((**nptr >= '0' && **nptr <= '9') && **nptr)
	{
		result = result * 10 + **nptr - '0';
		(*nptr) ++;
	}
	if (!ft_strncmp(",0x", *nptr, 3) || !ft_strncmp(",0X", *nptr, 3))
	{
		(*nptr) += 3;
		map->pts[i][j].color = get_color(nptr);
	}
	else
		map->pts[i][j].color = 0x00FFFFFF;
	return (result * sign);
}
