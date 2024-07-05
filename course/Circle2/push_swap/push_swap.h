/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:27:11 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/05 19:52:38 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include "./ft_printf/ft_printf.h"

typedef struct o_node
{
    struct o_node *previous;
    int data;
    struct o_node *next;
} t_node;

typedef struct  o_stack
{
    struct o_node *head;
    struct o_node *tail;
    int size;

} t_stack;

/* ----------- operate ---------------------*/
void    swap_a(t_stack *a);
void    swap_b(t_stack *b);
void    push_b(t_stack *a, t_stack *b);
void    push_a(t_stack *b, t_stack *a);
void    rotate_a(t_stack *a);
void    rotate_b(t_stack *b);
void    rr(t_stack *a, t_stack *b);
void    reverse_rotate_a(t_stack *a);
void    reverse_rotate_b(t_stack *b);
void    rrr(t_stack *a, t_stack *b);

/* stack*/

t_stack     *create_stack();
void    insert_node(t_stack *a, int data);
void    print_stack(t_stack *stack);
long long	    ft_atoi(const char *nptr);








#endif
