/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:33:19 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/14 15:47:18 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	empty_head_b(t_stack *a, t_stack *b, t_node *temp)
{
	b->head = temp;
	b->tail = temp;
	if (a->head) //헤드가 있으면 만약 a에 노드가 여러개 있으면 새로운 헤드의 프리비어스가 널이 된다. 
		     a->head->previous = NULL;
        temp->next = NULL;
        a->size --;
        b->size ++;
}

void    empty_head_a(t_stack *b, t_stack *a, t_node *temp)
{
        a ->head = temp;
        a->tail = temp;
        if (b->head) //헤드가 있으면 만약 a에 노드가 여러개 있으면 새로운 헤드의 프리비어스가 널이 된다. 
            b->head->previous = NULL;
        temp->next = NULL;
        b->size --;
        a->size ++;
        ft_printf("pa\n");
}
void    push_b(t_stack *a, t_stack *b)
{
    if (a->head == NULL)
        return ;
    t_node *temp;
    temp = a->head; // 왜 탬프를 둬야 할까?
    a->head = a->head->next;
    temp->previous = NULL;
    if (b->head == NULL) //b(push 할 장소)
    {
        empty_head_a(a, b, temp);
        ft_printf("pb\n");
    }
    else
    {
        b->head->previous = temp;
        temp->next = b->head;
        b->head = b->head->previous;
        a->size --;
        b->size ++;
        ft_printf("pb\n");
    }
}

void    push_a(t_stack *b, t_stack *a)
{
    if (b->head == NULL)
        return ;
    t_node *temp;
    temp = b->head; // 왜 탬프를 둬야 할까?
    b->head = b->head->next;
    temp->previous = NULL;
    if (a->head == NULL) //a(push 할 장소)
    {
        empty_head_a(a, b, temp);
        ft_printf("pa\n");
    }
    else
    {
        a->head->previous = temp;
        temp->next = a->head;
        a->head = temp;
        b->size --;
        a->size ++;
        ft_printf("pa\n");
    }
}
