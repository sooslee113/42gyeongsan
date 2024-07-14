/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:23:03 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/13 21:37:05 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_node(t_stack *a, int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->previous = NULL;
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
	new_node->previous = a->tail;
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

void    create_stack2(t_stack **a)
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


// void    lets_free(t_stack *a)
// {
//     t_node *current = a->head;

//     if(current != NULL)
//     {
//         a->head = current->next;
//         free(current);
//         lets_free(a);
//     }
// }


// int main()
// {
//     t_stack *a;
//     t_stack *b;

//     a =create_stack();
//     b =create_stack();
//     insert_node(a, 2);
//     insert_node(a, 1);
//     insert_node(a, 0);
//     //insert_node(a, 4);
//     //insert_node(a, 5);
//     // insert_node(a, 5);
//     // insert_node(a, 6);
    
//     // swap_a(a);
//     // swap_a(a);
//     // swap_a(a);
//     swap_a(a);
//     // printf("%d\n", a->head->data);
//     // printf("%d\n", a->head->next->data);
//     // printf("%d\n", a->tail->data);
//     reverse_rotate_a(a);
//     //  reverse_rotate_a(a);
//     // reverse_rotate_a(a);
//     //reverse_rotate_a(a);

    
//     //reverse_rotate_a(a);
//     //reverse_rotate_a(a);
//     print_stack(a);
//     // reverse_rotate_a(a);
//     // reverse_rotate_a(a);
//     // reverse_rotate_a(a);
//     // printf("a\n");
//     //  print_stack(a);
//     // printf("b\n");
//     // printf("그냥 출력 \n\n");
//     // //-------------------------------------------- //
//     // push_b(a, b);
//     // push_b(a, b);
//     // push_b(a, b);
//     // push_b(a, b);
//     // print_stack(a);
//     // printf("a\n");
//     // print_stack(b);
//     // printf("b\n");
//     // printf("push_b 후 출력 \n\n");
//     // //-------------------------------------------- //
//     // push_a(b, a);
//     // push_a(b, a);
//     // push_a(b, a);
//     // print_stack(a);
//     // printf("a\n");
//     // print_stack(b);
//     // printf("b\n");
//     // printf("push_a후 출력 \n\n");
//     // //-------------------------------------------- //
//         lets_free(a);
//         lets_free(b);
//         free(a);
//         free(b);
//     return (0);
// }
