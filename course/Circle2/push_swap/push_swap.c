/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:39:14 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/13 21:31:29 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void    show_error(t_stack *a)
{
        lets_free(a);
        ft_printf("argv is invaild");
        exit(-1);
}

void    parshing(int argc, char **argv, t_stack *a)
{
    int i;
    long long num;
    char **split;
    int j;

    i = 1;
        while (i < argc)
        {
            if (!check_argv(argv[i]))
                show_error(a);
            split = ft_split(argv[i], ' ');
            j = 0;
            while(split[j])
            {
                num = ft_atoi(split[j]);
                    if (dup_check(a, num) == 0 || num_check(num) == 0)
                    show_error(a);
                insert_node (a, num);
                j++;
            }
            double_free(split);
            i ++;
        }
        if (already_sort(a) == 1)
            show_error(a);
}
void    bin_radix(t_stack *a, t_stack *b)
{
    int i;
    int max;
    int max_digit;
    t_node * a_current;
    t_node * b_current;

    i = 0;
    max = find_max(a);
    max_digit = find_max_digit(max);
    while(i < max_digit)
    {
        a_current = a->head;
        bin0(a, b, &i, a_current);

        b_current = (b)->head;
        bin1(a, b, a_current, b_current);
        i ++;
    }
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    create_stack2(&a);
    create_stack2(&b);
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
        //print_rank(a);
        lets_free(a);
        lets_free(b);
        free(a);
        free(b);
    }
    return (0);
}