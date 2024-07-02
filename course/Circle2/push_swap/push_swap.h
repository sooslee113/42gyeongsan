/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:27:11 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/01 17:37:02 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>

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


#endif
