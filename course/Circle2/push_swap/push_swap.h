/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:27:11 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/19 02:59:24 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "./ft_printf/ft_printf.h"

typedef struct o_node
{
	struct o_node	*prev;
	struct o_node	*next;
	int				data;
	int				rank;
}	t_node;

typedef struct o_stack
{
	struct o_node	*head;
	struct o_node	*tail;
	int				size;
}	t_stack;

/* operate*/
long long	ft_atoi(const char *nptr);
void		insert_node(t_stack *a, int data);
void		making_rank(t_stack *a);
void		create_stack2(t_stack **a);
/*push*/
void		empty_head_b(t_stack *a, t_stack *b, t_node *temp);
void		empty_head_a(t_stack *b, t_stack *a, t_node *temp);
void		push_b(t_stack *a, t_stack *b);
void		push_a(t_stack *b, t_stack *a);
/*reverse_rotate*/
void		reverse_rotate_a(t_stack *a);
void		reverse_rotate_b(t_stack *b);
void		rrr(t_stack *a, t_stack *b);
/*rotate*/
void		rotate_a(t_stack *a);
void		rotate_b(t_stack *b);
void		rr(t_stack *a, t_stack *b);
/*swap*/
void		swap_a(t_stack *a);
void		swap_b(t_stack *b);
void		ss(t_stack *a, t_stack *b);
/*etc*/
char		**ft_split(char	const *s, char c);
void		show_error(t_stack *a);
void		bin_radix(t_stack *a, t_stack *b);
/* tt */
/*free*/
void		lets_free(t_stack *a);
void		double_free(char **split);

/*parshing*/
int			check(char *s);
int			num_check(long long num);
int			dup_ch(t_stack *a, int num);
int			already_sort(t_stack *a);
void		parshing(int argc, char **argv, t_stack *a);

/*sort*/
int			find_max_digit(int rank);
int			find_max(t_stack *a);
void		bin0(t_stack *a, t_stack *b, int *i, t_node *a_current);
void		bin1(t_stack *a, t_stack *b, t_node *a_current, t_node *b_current);
void		max(t_stack *a);
/*hard_coding*/
void		size_five(t_stack *a, t_stack *b);
void		size_four(t_stack *a, t_stack *b);
void		size_three(t_stack *a);
void		size_two(t_stack *a);
void		reduce(t_stack *a, t_stack *b, t_node *min_node, t_node *current);

#endif
