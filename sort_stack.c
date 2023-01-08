/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panti <panti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:21:43 by panti             #+#    #+#             */
/*   Updated: 2023/01/08 21:29:04 by panti            ###   ########.fr       */
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

    // t_stack *tmp;
    // tmp = (*a_stack);
    // while(tmp->next->num != -1)
	// {
	// 	tmp = tmp->next;
	// 	printf("<while> %d\n",tmp->num);
	// }
    // first->next = second;
    // second->next = first;
    // first->next = third;
    // third->previous = first;
    // first->previous = second;
    // second->previous = first;
    printf("=before=\n");
    printf("----<%d>\n", nil->num);
    printf("---<%d>\n",first->num);
    printf("---<%d>\n",second->num);
    printf("---<%d>\n",third->num);
    printf("---<%d>\n",third->next->num);

    first->next = third;
    third->previous = first;
    second->next = first;
    second->previous = nil;
    nil->next = second;
    first->previous = second;
    t_stack *tmp;
    tmp = (*a_stack);
    while(tmp->next->num != -1)
	{
		tmp = tmp->next;
		printf("<while> %d\n",tmp->num);
	}
// a->next = second;
// 	second->next = first;
// 	first->next = third;
// 	third->prev = first;
// 	first->prev = second;
// 	second->prev = a;
    printf("=after=\n");
    
  
}

void sort_stack(t_data *data, t_stack **a_stack, t_stack **b_stack)
{
    (void)data;
    (void)b_stack;
    printf("<%d>\n",(*a_stack)->num);
    sa(a_stack);
    printf("<%d>\n",(*a_stack)->num);
}
