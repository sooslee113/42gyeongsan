/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:37:44 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/16 23:52:20 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack *a)
{
	t_node	*temp;

	if (a->size <= 1)
		return ;
	temp = a->tail;
	a->tail = a->tail->prev;
	a->tail->next = NULL;
	a->head->prev = temp;
	temp->next = a->head;
	a->head = temp;
	a->head->prev = NULL;
	ft_printf("rra\n");
	return ;
}

void	reverse_rotate_b(t_stack *b)
{
	t_node	*temp;

	if (b->size <= 1)
		return ;
	temp = b->tail;
	b->tail = b->tail->prev;
	b->tail->next = NULL;
	b->head->prev = temp;
	temp->next = b->head;
	b->head = temp;
	b->head->prev = NULL;
	ft_printf("rra\n");
	return ;
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate_a(a);
	reverse_rotate_b(b);
	ft_printf("rrr\n");
}
