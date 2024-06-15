/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 00:14:33 by sooslee           #+#    #+#             */
/*   Updated: 2024/03/15 18:32:09 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substring;
	char		*empty;
	size_t		i;

	substring = malloc(len * sizeof(char) + 1);
	i = 0;
	if (!substring)
		return (NULL);
	if (len == 0 || start >= ft_strlen(s) || s == NULL)
	{
		empty = malloc(1 * sizeof(char));
		if (!empty)
			return (NULL);
		empty[0] = '\0';
		return (empty);
	}
	substring = malloc(len * sizeof(char) + 1);
	while (i < len)
	{
		substring[i] = s[start];
		i ++;
		start ++;
	}
	substring[i] = '\0';
	return (substring);
}
