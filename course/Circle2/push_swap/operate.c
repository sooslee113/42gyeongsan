/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:23:03 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/05 19:49:36 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// ---------------------------- 여기부터 rotate ----------------------------- //
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

void    rotate_b(t_stack *b)
{
    if (b -> head -> next == NULL || b == NULL)
        return ;
    t_node *temp_head;
    t_node *temp_tail;
    temp_tail = b -> tail;
    temp_head = b -> head;
    b -> tail = temp_head;
    b -> head = b -> head -> next;
    b -> head -> previous = NULL;
    b ->  tail -> next = NULL;
    b -> tail -> previous = temp_tail;
    temp_tail -> next = b -> tail;
    return ;
}

void    rr(t_stack *a, t_stack *b)
{
    rotate_a(a);
    rotate_b(b);
}

// ---------------------------- 여기까지 rotate ----------------------------- //

// -----------------------------여기부터  rrotate --------------------------//


void    reverse_rotate_a(t_stack *a)
{
    if (a -> head -> next == NULL || a == NULL)
    return ;
    t_node *temp_head;
    t_node *temp_tail;
    temp_head = a -> head;
    temp_tail = a -> tail;
    a -> tail = a -> tail -> previous;
    a -> tail -> next = NULL; 
    a -> head = temp_tail;
    a -> head -> previous = NULL;
    a -> head -> next = temp_head;
    temp_head -> previous = temp_tail;
    return ;
}

void    reverse_rotate_b(t_stack *b)
{
    if (b -> head -> next == NULL || b == NULL)
    return ;
    t_node *temp_head;
    t_node *temp_tail;
    temp_head = b -> head;
    temp_tail = b -> tail;
    b -> tail = b -> tail -> previous;
    b -> tail -> next = NULL; 
    b -> head = temp_tail;
    b -> head -> previous = NULL;
    b -> head -> next = temp_head;
    temp_head -> previous = temp_tail;
    return ;
}

void    rrr(t_stack *a, t_stack *b)
{
    reverse_rotate_a(a);
    reverse_rotate_a(b);
}

// ---------------------------- 여기까지 rrotate ----------------------------- //

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
    new_node -> previous = a -> head;
    a -> tail -> next = new_node;
    a -> tail = new_node;
    a -> size ++;
}

// void    create_stack2(t_stack **a)
// {
//     (*a) = (t_stack *)malloc(sizeof(t_stack));
//     printf("함수에 들어 온 a 주소 :%p\n", *a);
//     (*a) -> head = NULL;
//     (*a) -> size = 0;
//     (*a) -> tail = NULL;
// }

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

// int main()
// {
//     t_stack *a;
//     t_stack *b;

//     a =create_stack();
//     b =create_stack();
//     insert_node(a, 1);
//     insert_node(a, 2);
//     insert_node(a, 3);
//     insert_node(a, 4);
//     insert_node(a, 5);
//     print_stack(a);
//     printf("그냥 출력 a\n");
//     push_b(a, b);
//     push_b(a, b);
//     print_stack(a);
//     printf("rrotate a\n");
//     print_stack(b);
//     printf("b\n");
//     free(a);
//     free(b);
//     return (0);
// }