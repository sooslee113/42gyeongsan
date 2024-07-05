/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:39:14 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/05 19:55:22 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int dup_check(t_stack *a,int num)
{
    t_node * current = a -> head;
    while(current != NULL)
    {
        if (num == current ->data)
            return (0);
        current = current -> next;
    }
    return (1);
}

void    lets_free(t_stack *a)
{
    t_node *current = a -> head;

    if(current != NULL)
    {
        a -> head = current -> next;
        free(current);
        lets_free(a);
    }
}

int check_argv(char *str)
{
    int i = 0;
    int sign_cnt = 0;
    while(str[i] != '\0')
    {
        if ((str[i] >= 33 && str[i] <= 42) || str[i] == 44)
                return (0);
        else if ((str[i] >= 46 && str[i] <= 47)||(str[i] >= 58 && str[i] <= 126))
                return (0);
        else if (str[i] == '+' || str[i] == '-')
        {
            sign_cnt ++;
        }
        i ++;
    }
    if (sign_cnt >= 2)
        return (0);
    return (1);
}

int num_check(long long num)
{
    if (num > 2147483647 || num < -2147483648)
    {
        return (0);
    }
    return (1);
}

int main(int argc, char **argv)
{
    int i = 1;
    long long num;
    t_stack *a;
    //t_stack *b;

    a = create_stack();
    //b = create_stack();
    if (argc >= 2)
    {
        while (i < argc)
        {
            if (!check_argv(argv[i]))
            {
                lets_free(a);
                ft_printf("argv is invaild");
                exit(-1);
            }
            num = ft_atoi(argv[i]);
            if (dup_check(a, num) == 0 || num_check((long long)num) == 0)
            {
                lets_free(a);
                ft_printf("error");
                exit(-1);
            }
            insert_node (a, num);
            i ++;
        }
    }
    print_stack(a);
    return (0);
}