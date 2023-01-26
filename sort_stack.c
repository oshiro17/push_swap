/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noshiro <noshiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:21:43 by panti             #+#    #+#             */
/*   Updated: 2023/01/27 04:54:41 by noshiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_stack **a, char spell)
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
    ft_printf("rr%c\n",spell);
}

void ra(t_stack **a,char spell)
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
    ft_printf("r%c\n",spell);
}

void sa(t_stack **a_stack, char spell)
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
    ft_printf("s%c\n",spell);
}

void    pb(t_stack **a, t_stack **b, char spell)
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
    ft_printf("p%c\n",spell);
}    
