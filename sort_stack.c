/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panti <panti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:21:43 by panti             #+#    #+#             */
/*   Updated: 2023/01/14 17:22:17 by panti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

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

// printf("pointer B::%p\n",(*b)->next);    
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

    // pb(a_stack,b_stack);
    // pb(a_stack,b_stack);
    // printf("pointer B::%p\n",(*b_stack)->next);
    // printf("pointer B::%p\n",(*b_stack)->next);
    // printf("pointer B::%p\n",(*b_stack)->next);
    tmp = (*a_stack);
    while(i < 15)
    {
        printf("a:::%d\n",tmp->num);
        tmp = tmp->next;
        i++;
    }
    i = 0;
    tmp = (*b_stack);
    while(i < 15)
    {
        printf("b:::%d\n",tmp->num);
        tmp=tmp->next;
        i++;
    }
}
