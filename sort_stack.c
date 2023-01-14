/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panti <panti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:21:43 by panti             #+#    #+#             */
/*   Updated: 2023/01/14 19:38:27 by panti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void rra(t_stack **a)
{
	t_stack *go_first;
	t_stack *first_now;

	first_now = (*a)->next;
	go_first = (*a)->previous;

	(*a)->previous = go_first->previous;
	(*a)->next = go_first;
	(*a)->previous->next = (*a);
	go_first->next = first_now;
	go_first->previous = (*a);
	first_now->previous = go_first; 
}

void ra(t_stack **a)
{
	t_stack *go_last;
	t_stack *last_now;

	go_last = (*a)->next;
	last_now = (*a)->previous;

	(*a)->next = go_last->next;
	(*a)->previous = go_last;
	(*a)->next->previous = (*a);
	go_last->previous = last_now;
	go_last->next = (*a);
	last_now->next = go_last;
}

void sa(t_stack **a_stack)
{

    t_stack *nil =(*a_stack);
    t_stack *first =(*a_stack)->next;
    t_stack *second =(*a_stack)->next->next;
    t_stack *third =(*a_stack)->next->next->next;

    first->next = third;
    third->previous = first;
    second->next = first;
    second->previous = nil;
    nil->next = second;
    first->previous = second;
}

void    pb(t_stack **a, t_stack **b)
{
    t_stack *push;

    push = (*a)->next;
    push->next->previous = push->previous;
    push->previous->next = push ->next;
    push->previous = (*b);
    if((*b)->next == NULL)
    {
        push->next = (*b);
        (*b)->next = push;
        (*b)->previous = push;       
    }
    else
    {
        push->next = (*b)->next;
        (*b)->next = push;
        push->next->previous = push;
    }
}    

void    sort_stack(t_stack **a_stack, t_stack **b_stack)
{
    int i = 0; 
    t_stack *tmp;
    // rra(a_stack);
	// sa(a_stack);
    //pb(a_stack,b_stack);

	sa(a_stack);//sa
	pb(a_stack,b_stack);//pb
	pb(a_stack,b_stack);//pb
	pb(a_stack,b_stack);//pb
	ra(a_stack);//ra
	ra(b_stack);//rb
	rra(a_stack);//rra
	rra(b_stack);//rrb
	sa(a_stack);//sa
	pb(b_stack,a_stack);//pa
	pb(b_stack,a_stack);//pa
	pb(b_stack,a_stack);//pa





    tmp = (*a_stack);
    while(i < 15)
    {
        printf("a:::%d\n",tmp->num);
        tmp = tmp->next;
        i++;
    }
    // i = 0;
    // tmp = (*b_stack);
    // while(i < 15)
    // {
    //     printf("b:::%d\n",tmp->num);
    //     tmp=tmp->next;
    //     i++;
    // }
}
