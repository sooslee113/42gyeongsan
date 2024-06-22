/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 01:33:00 by sooslee           #+#    #+#             */
/*   Updated: 2024/06/22 20:44:19 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i ++;
	}
	free (str);
	return (NULL);
}

char	wordcont(char const *s, char c)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (i != 0 && s[i -1] == c && s[i] != c))
			cnt ++;
		i ++;
	}
	return (cnt);
}

int	wrdlen(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
	{
		len ++;
	}
	return (len);
}

char	*assign(const char *s, char c)
{
	char	*ary;
	int		i;
	int		len;

	len = wrdlen(s, c);
	ary = (char *)malloc(sizeof(char) * (len + 1));
	if (! ary)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		ary[i] = s[i];
		i ++;
	}
	ary[i] = '\0';
	return (ary);
}

char	**ft_split(char	const *s, char c)
{
	char	**array;
	int		wrdcnt;
	int		i;
	int		aryi;

	wrdcnt = wordcont(s, c);
	array = (char **)malloc(sizeof(char *) * (wrdcnt + 1));
	if (!array)
		return (NULL);
	i = 0;
	aryi = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (i != 0 && s[i - 1] == c && s[i] != c))
		{
			array[aryi] = assign(&s[i], c);
			if (array[aryi] == NULL)
				return (ft_free (array));
			aryi ++;
		}
		i ++;
	}
	array[aryi] = NULL;
	return (array);
}

// #include <stdio.h>
// int 	main(int argc, char **argv)
// {
// 	char ** test;

// 	test = ft_split(argv[1], ' ');
// 	int i = 0;
// 	while(test[i])
// 	{
// 		printf("%s\n", test[i]);
// 		i ++;
// 	}

// }
