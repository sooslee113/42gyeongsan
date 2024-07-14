/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:36:28 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/13 21:25:55 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate_a(t_stack *a)
{
    if (a->size == 1 || a == NULL)
        return ;
    t_node *temp_head;
    t_node *temp_tail;
    
    temp_tail = a->tail;
    temp_head = a->head;
    a->tail = temp_head;
    a->head = a->head->next;
    a->head->previous = NULL;
    a->tail->next = NULL;
    a->tail->previous = temp_tail;
    temp_tail->next = a->tail;
    ft_printf("ra\n");
}

void    rotate_b(t_stack *b)
{
    if (b->head->next == NULL || b == NULL)
        return ;
    t_node *temp_head;
    t_node *temp_tail;

    temp_tail = b->tail;
    temp_head = b->head;
    b->tail = temp_head;
    b->head = b->head->next;
    b->head->previous = NULL;
    b-> tail->next = NULL;
    b->tail->previous = temp_tail;
    temp_tail->next = b->tail;
    ft_printf("rb\n");
}

void    rr(t_stack *a, t_stack *b)
{
    rotate_a(a);
    rotate_b(b);
    ft_printf("rr\n");
}
