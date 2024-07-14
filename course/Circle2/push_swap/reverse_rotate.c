/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:37:44 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/13 21:25:54 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    reverse_rotate_a(t_stack *a)
{
    if (a->size <= 1)
        return ;
    t_node *temp;
    temp = a->tail;
    a->tail = a->tail->previous;
    a->tail->next = NULL;
    a->head->previous = temp;
    temp->next = a->head;
    a->head = temp;
    a->head->previous = NULL;
    ft_printf("rra\n");
    return ;
}

void    reverse_rotate_b(t_stack *b)
{
    if (b->size <= 1)
        return ;
    t_node *temp;
    temp = b->tail;
    b->tail = b->tail->previous;
    b->tail->next = NULL;
    b->head->previous = temp;
    temp->next = b->head;
    b->head = temp;
    b->head->previous = NULL;
    ft_printf("rra\n");
    return ;
}

void    rrr(t_stack *a, t_stack *b)
{
    reverse_rotate_a(a);
    reverse_rotate_b(b);
    ft_printf("rrr\n");
}
