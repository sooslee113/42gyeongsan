/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:39:14 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/19 23:17:22 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_error(t_stack *a)
{
	lets_free(a);
	ft_printf("Error");
	exit(-1);
}

void	parshing(int argc, char **argv, t_stack *a)
{
	char			**split;
	long long		num;
	int				i;
	int				j;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (split[0] == NULL)
			exit(1);
		j = 0;
		while (split[j])
		{
			num = ft_atoi(split[j]);
			if (dup_ch(a, num) == 0 || num_check(num) == 0 || !check(split[j]))
				show_error(a);
			insert_node (a, num);
			j++;
		}
		double_free(split);
		i ++;
	}
	if (already_sort(a) == 1)
		exit(1);
}

void	bin_radix(t_stack *a, t_stack *b)
{
	t_node		*a_current;
	t_node		*b_current;
	int			i;
	int			max;
	int			max_digit;

	i = 0;
	max = find_max(a);
	max_digit = find_max_digit(max);
	while (i < max_digit)
	{
		a_current = a->head;
		bin0(a, b, &i, a_current);
		b_current = (b)->head;
		bin1(a, b, a_current, b_current);
		i ++;
	}
}

void	freego(t_stack *a, t_stack *b)
{
	lets_free(a);
	lets_free(b);
	free(a);
	free(b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	create_stack2(&a);
	create_stack2(&b);
	if (argc == 1)
		exit (1);
	if (argc >= 2)
	{
		parshing(argc, argv, a);
		making_rank(a);
		if (a->size == 2)
			size_two(a);
		else if (a->size == 3)
			size_three(a);
		else if (a->size == 4)
			size_four(a, b);
		else if (a->size == 5)
			size_five(a, b);
		else
			bin_radix((a), (b));
	}
	freego(a, b);
	return (0);
}
