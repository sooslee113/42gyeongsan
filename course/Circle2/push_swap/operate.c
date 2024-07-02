/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:23:03 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/02 16:23:33 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

// ---------------------------- 여기부터 swap ----------------------------- //
void    swap_a(t_stack *a)
{
    t_node *temp;
    if (a == NULL || a -> size == 1)
        return ;
    temp = a->head;
    a -> head = a->head->next;
    temp -> next = a -> head -> next;
    temp -> previous = a -> head -> previous;
    a -> head -> next = temp;
    a -> head -> previous = NULL;
}

void    swap_b(t_stack *b)
{
    t_node *temp;
    if (b == NULL || b -> size == 1)
        return ;
    temp = b->head;
    b->head = b->head-> next;
    temp->next = b->head->next;
    temp->previous = b ->head-> previous;
    b->head->next = temp;
    b->head->previous = NULL;
}

void    ss(t_stack *a, t_stack *b)
{
    swap_a(a);
    swap_b(b);
}
// ---------------------------- 여기까지가 swap ----------------------------- //

// ---------------------------- 여기부터 push ----------------------------- //

void    push_b(t_stack *a, t_stack *b)
{
    if (a -> head == NULL)
        return ;
    t_node *temp;
    temp = a -> head; // 왜 탬프를 둬야 할까?
    a -> head = a -> head -> next;
    if (b -> head == NULL) //b(push 할 장소)
    {
        b -> head = temp;
        b -> tail = temp;
        if (a -> head) //헤드가 있으면 만약 a에 노드가 여러개 있으면 새로운 헤드의 프리비어스가 널이 된다. 
            a -> head -> previous = NULL;
        temp -> next = NULL;
        a -> size --;
        b -> size ++;
        return ;
    }
    a -> head -> previous = NULL;
    b -> head -> previous = temp;
    temp -> next = b -> head;
    b -> head = temp;
}

void    push_a(t_stack *b, t_stack *a)
{
    if (b -> head == NULL)
        return ;
    t_node *temp;
    temp = b -> head; // 왜 탬프를 둬야 할까?
    b -> head = b -> head -> next;
    if (a -> head == NULL) //b(push 할 장소)
    {
        a -> head = temp;
        a -> tail = temp;
        if (b -> head) //헤드가 있으면 만약 a에 노드가 여러개 있으면 새로운 헤드의 프리비어스가 널이 된다. 
            b -> head -> previous = NULL;
        temp -> next = NULL;
        b -> size --;
        a -> size ++;
        return ;
    }
    b -> head -> previous = NULL;
    a -> head -> previous = temp;
    temp -> next = a -> head;
    a -> head = temp;
    a -> size ++;
    b -> size --;
}

// ---------------------------- 여기까지 push ----------------------------- //

void    rotate_a(t_stack *a)
{
    if (a -> head -> next == NULL || a == NULL)
        return ;
    t_node *temp_head;
    t_node *temp_tail;
    temp_tail = a -> tail;
    temp_head = a -> head;
    a -> tail = temp_head;
    a -> head = a -> head -> next;
    a -> head -> previous = NULL;
    a ->  tail -> next = NULL;
    a -> tail -> previous = temp_tail;
    temp_tail -> next = a -> tail;
    return ;
}

void    insert_node(t_stack *a, int data) // 노드 삽입
{
    t_node *new_node;
    new_node = (t_node *)malloc(sizeof(t_node));
    new_node -> previous = NULL;
    new_node -> data = data;
    new_node -> next = NULL;
    if (a->head == NULL)
    {
        a -> head = new_node;
        a -> tail = new_node;
        a -> size ++;
        return ;
    }
    new_node -> next = a -> head;
    a -> head -> previous = new_node;
    a -> head = new_node;
    a -> size ++;
}

void    creat_stack(t_stack *a)
{
    a = (t_stack *)malloc(sizeof(t_stack));
    a -> head = NULL;
    a -> size = 0;
    a -> tail = NULL;
}
t_stack     *create_stack() //스택 만들기;
{
    t_stack *new_stack;
    new_stack = (t_stack *)malloc(sizeof(t_stack));
    if(!new_stack)
        {
            printf("making fail\n");
            return NULL;
        }
    new_stack -> head = NULL;
    new_stack -> size = 0;
    new_stack -> tail = NULL;
    return (new_stack);
}

void    print_stack(t_stack *stack) // 출력
{
    t_node *current = stack -> head;
    while(current != NULL)
    {
        printf(" %d \n", current -> data);
        current = current -> next;
    }
    printf("----\n");

}

int main()
{
    t_stack *a;
    t_stack *b;

    a = create_stack();
    insert_node(a, 1);
    insert_node(a, 2);
    insert_node(a, 3);
    insert_node(a, 4);
    insert_node(a, 5);
    print_stack(a);
    printf(" a\n");
    rotate_a(a);
    print_stack(a);
    printf(" a\n");
    free(a);
    //free(b);
    return (0);
}