/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:39:14 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/13 18:47:09 by sooslee          ###   ########.fr       */
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

void    show_error(t_stack *a)
{
        lets_free(a);
        ft_printf("argv is invaild");
        exit(-1);
}

void    double_free(char **split)
{
    int i = 0;
    while(split[i])
    {
        free(split[i]);
        i ++;
    }
    free (split);
}

int    find_max_digit(int rank)
{
    int i = 0;
    int cnt = 0;
    while((rank >> i) != 0)
    {
        i ++;
        cnt ++;
    }
    return (cnt);
}

int     find_max(t_stack *a)
{
    t_node *current = a -> head;
    int max; 
    max = current -> rank;
    while(current != NULL)
    {
        if (max < current -> rank)
            max = current -> rank;
        current = current -> next;
    }
    return (max);
}

int already_sort(t_stack *a)
{
    int max;
    t_node *current;

    current = a -> head;
    max = a -> head -> data;
    while(current -> next != NULL)
    {
        if (max < current -> next -> data)
        {
            max = current -> next -> data;
            current = current -> next;
        }
        else
            return (0);
    }
    return (1);
}

void    bin_radix(t_stack **a, t_stack **b)
{
    int i = 0;
    int max;
    int max_digit;

    max = find_max(*a);
    max_digit = find_max_digit(max);
    t_node * a_current;
    t_node * b_current;
    while(i < max_digit)
    {
        // print_rank(*a);
        // printf("a\n");
        // print_rank(*b);
        // printf("b\n");
        // printf("%d번째 이동 \n", i);
        a_current = (*a) -> head;
        
        int origin_asize = (*a) -> size;
        // printf("origin_asize : %d\n", origin_asize);
        int ac = 0;
        while(ac < origin_asize)
        {
            //t_node *next_node = a_current->next;
            // printf("ac : %d\n", ac);
            // printf("a_current -> rank의 값: %d\n", a_current -> rank);
            // printf("head의 값 : %d\n", (*a) -> head -> rank);
            if ((((a_current -> rank) >> i) & 1) == 0)
            {
                push_b(*a, *b);
            }
            else
            {
                rotate_a(*a);
            }
            
            a_current = (*a) -> head;
            // printf("hello world\n");
            // print_rank(*a);
            // printf("%d회전 후 a 랭크\n", ac);
            // print_rank(*b);
            // printf("%d회전 후 b 랭크\n", ac); 
            // printf("%d 회전 후 head의 값 : %d\n", ac,(*a) -> head -> rank);
            // printf("%d 회전 후 a_current -> rank의 값: %d\n", ac,a_current -> rank);
            // printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
            ac ++; 
        }
        // print_rank(*a);
        // printf("a\n");
        // print_rank(*b);
        // printf("b\n");
        // printf("push_b 한 후 \n");
        b_current = (*b) -> head;
        //int bc = 1;
        int b_size = (*b) -> size;
        while (b_size > 0) // 2번 순서
        {
            t_node *next_node = a_current->next;
            // printf("bc : %d\n", bc ++);
            //reverse_rotate_b(*b);
            // print_rank(*b);
            // printf("rra 한 후 b의 랭크\n");
            push_a(*b, *a);
            b_current = next_node;
            b_size --;
        }
        // print_rank(*a);
        // printf("a\n");
        // print_rank(*b);
        // printf("b\n");
        // printf("push_a 한 후 \n");
        // printf("i의 값 : %d ,max_digit의 값 : %d\n", i, max_digit);
        i ++;
    }
}
void    max(t_stack *a)
{
    int max;
    t_node *current = a -> head;
    
    max = a -> head -> data;
    while(current -> next != NULL)
    {
        if (max < current -> next -> data)    
           max = current -> next -> data;
        current = current -> next;
    }
}

void    size_two(t_stack *a)
{
    if (a -> size == 2)
        swap_a(a);
}

void    size_three(t_stack *a)
{
        // t_node *min_node = NULL;
        // t_node *current = NULL;
    
        // current = (a) -> head;
        // min_node = (a) -> head;
        // while(current != NULL)
        // {
        //     if (min_node -> data > current-> data)    
        //         min_node = current;
        //     current = current -> next;
        // }
        // while(min_node -> previous != NULL)
        // {
        //     reverse_rotate_a(a);
        // }
        // push_b(a, b);
        // if ((a) -> head -> rank > (a) -> tail -> rank)
        //     swap_a(a);
        // push_a(b, a);
        // while(already_sort(a) == 0)
        // {
            if (already_sort(a) == 1)
                return;
            if (a -> head -> rank < a -> head -> next -> rank && a -> tail -> rank > a -> head -> rank)
            {
                swap_a(a);
                rotate_a(a);
                return;
            }
            else if (a -> tail -> rank > a -> head -> rank && a -> tail -> rank > a -> head -> next -> rank)
            {
                swap_a(a);
                return;
            }
            else if(a -> head -> rank < a -> head -> next -> rank && a -> head -> rank > a -> tail -> rank)
            {
                reverse_rotate_a(a);
            }
            else if (a -> head -> rank > a -> head -> next -> rank && a -> head -> next -> rank > a -> tail-> rank)
            {
                swap_a(a);
                reverse_rotate_a(a);
            }
            else if (a -> head -> rank > a -> head -> next -> rank && a -> head -> rank > a -> tail -> rank)
            {
                rotate_a(a);
            }
            //reverse_rotate_a(a);
        //}
}

void    reduce(t_stack *a, t_stack *b, t_node *min_node, t_node *current)
{
        current = a -> head;
        min_node = a -> head;
        while(current != NULL)
        {
            if (min_node -> data > current-> data)    
                min_node = current;
            current = current -> next;
            //printf("min_node -> data : %d\n", min_node -> data);
            //print_rank(a);
        }
        while(min_node -> previous != NULL)
        {
            reverse_rotate_a(a);
            //print_rank(a);
        }
        push_b(a, b);
        //print_rank(a);
}

void    size_four(t_stack *a, t_stack *b)
{
        t_node *min_node = NULL;
        t_node *current = NULL;
    
        reduce(a , b, min_node, current);
        size_three(a);
        push_a(b, a);
}

void    size_five(t_stack *a, t_stack *b)
{
        t_node *min_node = NULL;
        t_node *current = NULL;

        reduce(a , b, min_node, current);
        reduce(a , b, min_node, current); 
        size_three(a);
        push_a(b, a);
        push_a(b, a);
        //push_a(b, a);
}

int main(int argc, char **argv)
{
    int i = 1;
    long long num;
    t_stack *a;
    t_stack *b;
    char    **split;
    a = create_stack();
    b = create_stack();
    if (argc >= 2) /* 쪼갤거*/
    {
/*************************** 여기까지가 파싱************************************/
        while (i < argc)
        {
            if (!check_argv(argv[i]))
                show_error(a);
            split = ft_split(argv[i], ' ');
            int j = 0;
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
        /*************************** 여기까지가 파싱************************************/
        making_rank(a);
        if (a -> size == 2)
            size_two(a);
        else if (a -> size == 3)
            size_three(a);
        else if (a -> size == 4)
            size_four(a, b);
        else if (a -> size == 5)
            size_five(a, b);
        else
            bin_radix(&(a), &(b));
        print_rank(a);
        // printf("a\n");        
        // print_stack(a);
        // print_rank(a);
        // printf("a\n");
        // print_stack(b);
        // printf("b\n");
        // printf("push_b 한 후 결과\n");
        // push_b(a, b);
        // push_b(a, b);
        // print_stack(a);
        // printf("a\n");
        // print_stack(b);
        // printf("b\n");
        // printf("push_a 한 후 결과\n");
        // push_a(b, a);
        // print_stack(a);
        // printf("a\n");
        // print_stack(b);
        // printf("b\n");
        lets_free(a);
        lets_free(b);
        free(a);
        free(b);
    }
    return (0);
}