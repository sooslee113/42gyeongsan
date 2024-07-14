/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:13:53 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/13 21:25:57 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    reduce(t_stack *a, t_stack *b, t_node *min_node, t_node *current)
{
        current = a->head;
        min_node = a->head;
        while(current != NULL)
        {
            if (min_node->data > current-> data)    
                min_node = current;
            current = current->next;
        }
        while(min_node->previous != NULL)
        {
            reverse_rotate_a(a);
        }
        push_b(a, b);
}

void    size_two(t_stack *a)
{
    if (a->size == 2)
        swap_a(a);
}

void    size_three(t_stack *a)
{
        t_node *cur;
        t_node *tai;
        
        cur = a->head;
        tai = a->tail;
        if (already_sort(a) == 1)
            return;
        if (cur->rank < cur->next->rank && a->tail->rank > cur->rank)
        {
            swap_a(a);
            rotate_a(a);
        }
        else if (tai->rank > cur->rank && tai->rank > cur->next->rank)
            swap_a(a);
        else if(cur->rank < cur->next->rank && cur->rank > tai->rank)
            reverse_rotate_a(a);
        else if (cur->rank > cur->next->rank && cur->next->rank > tai->rank)
        {
            swap_a(a);
            reverse_rotate_a(a);
        }
        else if (cur->rank > cur->next->rank && cur->rank > tai->rank)
            rotate_a(a);
}

void    size_four(t_stack *a, t_stack *b)
{
        t_node *min_node;
        t_node *current;

        min_node = NULL;
        current = NULL;
        reduce(a , b, min_node, current);
        size_three(a);
        push_a(b, a);
}

void    size_five(t_stack *a, t_stack *b)
{
        t_node *min_node;
        t_node *current;

        min_node = NULL;
        current = NULL;
        reduce(a , b, min_node, current);
        reduce(a , b, min_node, current); 
        size_three(a);
        push_a(b, a);
        push_a(b, a);
}