/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:16:40 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/14 15:44:51 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_argv(char *s)
{
	int	i;
	int	sign_cnt;

	i = 0;
	sign_cnt = 0;
	while (s[i] != '\0')
	{
		if ((s[i] >= 33 && s[i] <= 42) || s[i] == 44)
			return (0);
		else if ((s[i] >= 46 && s[i] <= 47) || (s[i] >= 58 && s[i] <= 126))
			return (0);
		else if (str[i] == '+' || str[i] == '-')
		{
			sign_cnt ++;
		}
		i ++;
	}
	if (sign_cnt >= 2)
		return (0);
	return (1);
}

int	num_check(long long num)
{
	if (num > 2147483647 || num < -2147483648)
	{
		return (0);
	}
	return (1);
}

int	dup_check(t_stack *a, int num)
{
	t_node	*current;

	current = a->head;
	while (current != NULL)
	{
		if (num == current ->data)
			return (0);
		current = current->next;
	}
	return (1);
}

int	already_sort(t_stack *a)
{
	int		max;
	t_node		*current;

	current = a->head;
	max = a->head->data;
	while (current->next != NULL)
	{
		if (max < current->next->data)
		{
			max = current->next->data;
			current = current->next;
		}
		else
			return (0);
	}
	return (1);
}
