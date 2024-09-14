/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:22:53 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/19 03:01:37 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_digit(int rank)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while ((rank >> i) != 0)
	{
		i ++;
		cnt ++;
	}
	return (cnt);
}

int	find_max(t_stack *a)
{
	t_node	*current;
	int		max;

	current = a->head;
	max = current->rank;
	while (current != NULL)
	{
		if (max < current->rank)
			max = current->rank;
		current = current->next;
	}
	return (max);
}

void	bin0(t_stack *a, t_stack *b, int *i, t_node *a_current)
{
	int	origin_asize;
	int	ac;

	origin_asize = a->size;
	ac = 0;
	while (ac < origin_asize)
	{
		if ((((a_current->rank) >> *i) & 1) == 0)
			push_b(a, b);
		else
			rotate_a(a);
		a_current = (a)->head;
		ac ++;
	}
}

void	bin1(t_stack *a, t_stack *b, t_node *a_current, t_node *b_current)
{
	t_node	*next_node;
	int		b_size;

	b_size = (b)->size;
	while (b_size > 0)
	{
		next_node = a_current->next;
		push_a(b, a);
		b_current = next_node;
		b_size --;
	}
}

void	max(t_stack *a)
{
	t_node	*current;
	int		max;

	current = a -> head;
	max = a->head->data;
	while (current->next != NULL)
	{
		if (max < current->next->data)
			max = current->next->data;
		current = current->next;
	}
}
