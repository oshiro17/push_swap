/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panti <panti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:34:49 by panti             #+#    #+#             */
/*   Updated: 2023/01/27 20:47:25 by panti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int get_log(int node_num)
{
	int i;

	i = 0;
	while (0 < node_num)
	{
		node_num /= 2;
		i++;
	}
	return (i);
}

void radix_sort(t_stack **a, t_stack **b, int node_num)
{
	int digit;
	int i;
	int	pb_count;
	t_stack *tmp;

	digit = 0;
	i = 0;
	while(digit < get_log(node_num))
	{
		pb_count = 0;
		while (i < node_num)
		{
			if((((*a)->next->num) >> digit & 1) == 1 )
				ra(a,'a');
			else 
			{
				pb(a,b,'b');
				pb_count++;
			}
			i++;
		}
		while(pb_count--)
			pb(b,a,'a');
		i = 0;
		digit++;
	tmp = *a;
    while(i < 10)
    {
        tmp=tmp->next;
        i++;
    }
	i = 0;
	}
}