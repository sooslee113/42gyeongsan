/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:33:19 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/17 00:05:35 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	empty_head_b(t_stack *a, t_stack *b, t_node *temp)
{
	b->head = temp;
	b->tail = temp;
	if (a->head)
		a->head->prev = NULL;
	temp->next = NULL;
	a->size --;
	b->size ++;
}

void	empty_head_a(t_stack *b, t_stack *a, t_node *temp)
{
	a ->head = temp;
	a->tail = temp;
	if (b->head)
		b->head->prev = NULL;
	temp->next = NULL;
	b->size --;
	a->size ++;
	ft_printf("pa\n");
}

void	push_b(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (a->head == NULL)
		return ;
	temp = a->head;
	a->head = a->head->next;
	temp->prev = NULL;
	if (b->head == NULL)
	{
		empty_head_a(a, b, temp);
		ft_printf("pb\n");
	}
	else
	{
		b->head->prev = temp;
		temp->next = b->head;
		b->head = b->head->prev;
		a->size --;
		b->size ++;
		ft_printf("pb\n");
	}
}

void	push_a(t_stack *b, t_stack *a)
{
	t_node	*temp;

	if (b->head == NULL)
		return ;
	temp = b->head;
	b->head = b->head->next;
	temp->prev = NULL;
	if (a->head == NULL)
	{
		empty_head_a(a, b, temp);
		ft_printf("pa\n");
	}
	else
	{
		a->head->prev = temp;
		temp->next = a->head;
		a->head = temp;
		b->size --;
		a->size ++;
		ft_printf("pa\n");
	}
}
