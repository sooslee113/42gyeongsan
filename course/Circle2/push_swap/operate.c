/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:23:03 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/16 23:52:24 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_node(t_stack *a, int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->prev = NULL;
	new_node->data = data;
	new_node->rank = 0;
	new_node->next = NULL;
	if (a->head == NULL)
	{
		a->head = new_node;
		a->tail = new_node;
		a->size ++;
		return ;
	}
	a->tail->next = new_node;
	new_node->prev = a->tail;
	a->tail = new_node;
	a->size++;
}

void	making_rank(t_stack *a)
{
	t_node	*current;
	t_node	*next_node;

	current = a->head;
	while (current != NULL)
	{
		next_node = a->head;
		while (next_node != NULL)
		{
			if (current->data > next_node->data)
				(current->rank)++;
			next_node = next_node->next;
		}
		current = current->next;
	}
}
/*
void	print_rank(t_stack *a)
{
	t_node	*current;

	current = a->head;
	while (current != NULL)
	{
		ft_printf("%d \n", current->rank);
		current = current->next;
	}
	printf("-----\n");
}*/

void	create_stack2(t_stack **a)
{
	(*a) = (t_stack *)malloc(sizeof(t_stack));
	(*a)->head = NULL;
	(*a)->size = 0;
	(*a)->tail = NULL;
}

// t_stack	*create_stack() //스택 만들기;
// {
// 	t_stack	*new_stack;
// 	new_stack = (t_stack *)malloc(sizeof(t_stack));
// 	if(!new_stack)
// 	{
// 		ft_printf("making fail\n");
// 		return NULL;
// 	}
// 	new_stack->head = NULL;
// 	new_stack->size = 0;
// 	new_stack->tail = NULL;
// 	return (new_stack);
// }

// void    print_stack(t_stack *stack) // 출력
// {
//     t_node *current = stack->head;
//     while(current != NULL)
//     {
//         printf(" %d \n", current->data);
//         current = current->next;
//     }
//     printf("----\n");
// }
