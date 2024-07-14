/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:31:45 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/13 21:25:55 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_a(t_stack *a)
{
    t_node *temp;
    if (a == NULL || a->size == 1)
        return ;
    temp = a->head;
    a->head = a->head->next;
    temp->next = a->head->next;
    temp->previous = a->head; //temp->previous = a->head->previous; 처음에 이렇게 했는데 이러면 자기 자신을 가르키게 된다.
    a->head->next = temp;
    a->head->previous = NULL;
    if (a->size ==3)
        a->tail->previous = temp;
    ft_printf("sa\n");
}

void    swap_b(t_stack *b)
{
    t_node *temp;
    if (b == NULL || b->size == 1)
        return ;
    temp = b->head;
    b->head = b->head-> next;
    temp->next = b->head->next;
    temp->previous = b ->head;
    b->head->next = temp;
    b->head->previous = NULL;
    ft_printf("sb\n");
}

void    ss(t_stack *a, t_stack *b)
{
    swap_a(a);
    swap_b(b);
    ft_printf("ss\n");
}