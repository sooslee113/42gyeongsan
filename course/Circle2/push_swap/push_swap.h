/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:27:11 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/13 21:33:00 by sooslee          ###   ########.fr       */
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
    int rank;
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

void    create_stack2(t_stack **a);
void    insert_node(t_stack *a, int data);
void    print_stack(t_stack *stack);
long long	    ft_atoi(const char *nptr);
char	**ft_split(char	const *s, char c);
void    making_rank(t_stack *a);
void    print_rank(t_stack *a);

void    bin_radix(t_stack *a, t_stack *b);
int     find_max(t_stack *a);
int    find_max_digit(int rank);
void    double_free(char **split);
void    show_error(t_stack *a);
int num_check(long long num);
int check_argv(char *str);
void    lets_free(t_stack *a);
int dup_check(t_stack *a,int num);

int already_sort(t_stack *a);
void    size_five(t_stack *a, t_stack *b);
void    size_four(t_stack *a, t_stack *b);
void    size_three(t_stack *a);
void    size_two(t_stack *a);

void    reduce(t_stack *a, t_stack *b, t_node *min_node, t_node *current);
void    bin_radix(t_stack *a, t_stack *b);
void    bin1(t_stack *a, t_stack *b, t_node *a_current, t_node *b_current);
void    bin0(t_stack *a, t_stack *b, int *i, t_node *a_current);
int     find_max(t_stack *a);
int    find_max_digit(int rank);
void    max(t_stack *a);

void    push_a(t_stack *b, t_stack *a);
void    push_b(t_stack *a, t_stack *b);
void    empty_head_a(t_stack *b, t_stack *a, t_node *temp);
void    empty_head_b(t_stack *a, t_stack *b, t_node *temp);

#endif
