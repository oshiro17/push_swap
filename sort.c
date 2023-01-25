/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panti <panti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:34:54 by panti             #+#    #+#             */
/*   Updated: 2023/01/25 12:38:39 by panti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int count_node (t_stack **node)
{
    int i;
	t_stack *tmp;

	tmp = (*node)->next;
    i = 0;
    while(tmp->num != -1)
    {
        i++;
        tmp = tmp->next;
    }
    return(i);
}

void    sort3(t_stack **node, int num)
{
	//一番小さいの見つける
	int min;

	min= (*node)->next->num;
	if((*node)->next->next->num < min)
		min = (*node)->next->next->num;
	if((*node)->next->next->next->num < min)
		min = (*node)->next->next->next->num;
	
	(*node)->next->num = (*node)->next->num - min;	
	(*node)->next->next->num = (*node)->next->next->num - min;	
	(*node)->next->next->next->num = (*node)->next->next->next->num - min;	

	if (num == 2)
	{
		if ((*node)->next->num == 4)
		{
			(*node)->next->num = 3;
			(*node)->next->num = 4;
			sa(node,'a');
		}
		if ((*node)->next->num == 1)
		{
			(*node)->next->num = 0;
			(*node)->next->num = 1;
			sa(node,'a');
		}
	}
	if(num == 3)
	{
		if((*node)->next->num == 1)
		{
			if ((*node)->next->next->num == 0)
				sa(node,'a');
			if((*node)->next->next->num == 2)
				rra(node,'a');
		}
		if((*node)->next->num == 0)
		{
			if((*node)->next->next->num == 2)
			{
				sa(node,'a');
				ra(node,'a');
			}
		}
		if((*node)->next->num == 2)
		{
			if((*node)->next->next->num == 1)
			{
				sa(node,'a');
				rra(node,'a');
			}
			if((*node)->next->next->num == 0)
				ra(node,'a');
		}
	}
}

void sort6(t_stack **a, t_stack **b)
{
	int i;

	i = 0;
	while(3 < count_node(a))
	{
		printf("(*a)->next->num;%d\n",(*a)->next->num);
		if((*a)->next->num == i)
		{	
			pb(a,b,'b');
			i++;
		}
		else
			ra(a,'a');
	}
	sort3(a,count_node(a));
	while(i--)
	{
		pb(b,a,'b');
	}
	
}

void    sort(t_stack **a, t_stack **b)
{
	int	node_num;

	node_num = count_node(a);
	if(node_num > 6)
	{
		radix_sort(a,b,count_node(a));
	}
	else if(node_num > 3)
		sort6(a,b);
	else
		sort3(a,node_num);
}