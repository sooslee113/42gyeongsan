/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:31:45 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/20 18:33:35 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *a)
{
	t_node	*temp;

	if (a == NULL || a->size == 1)
		return ;
	temp = a->head;
	a->head = a->head->next;
	temp->next = a->head->next;
	temp->prev = a->head;
	a->head->next = temp;
	a->head->prev = NULL;
	if (a->size == 3)
		a->tail->prev = temp;
	ft_printf("sa\n");
}

void	swap_b(t_stack *b)
{
	t_node	*temp;

	if (b == NULL || b->size == 1)
		return ;
	temp = b->head;
	b->head = b->head-> next;
	temp->next = b->head->next;
	temp->prev = b ->head;
	b->head->next = temp;
	b->head->prev = NULL;
	if (b->size == 3)
		b->tail->prev = temp;
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	swap_a(a);
	swap_b(b);
	ft_printf("ss\n");
}
