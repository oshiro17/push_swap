/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panti <panti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:34:49 by panti             #+#    #+#             */
/*   Updated: 2023/01/24 21:47:12 by panti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void radix_sort(t_stack **a, t_stack **b, int node_num)
{
	int digit;
	int i;
	int	pb_count;
	t_stack *tmp;

	digit = 0;
	i = 0;
	
	while(digit < 32)
	{
		pb_count = 0;
		while (i < node_num)
		{
			if((((*a)->next->num) >> digit & 1) == 1 )
				ra(a,'a');
			else if((((*a)->next->num) >> digit & 1) == 0)
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