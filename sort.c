/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panti <panti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:34:54 by panti             #+#    #+#             */
/*   Updated: 2023/01/26 23:23:37 by panti            ###   ########.fr       */
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
void    resort3(t_stack **node, int arry_num)
{
	int min;

	min= (*node)->next->num;
	if((*node)->next->next->num < min)
		min = (*node)->next->next->num;
	if (arry_num ==3)
	{
		if((*node)->next->next->next->num < min)
		{	
			min = (*node)->next->next->next->num;
			(*node)->next->next->next->num = (*node)->next->next->next->num - min;	
		}
	}
	(*node)->next->num = (*node)->next->num - min;	
	(*node)->next->next->num = (*node)->next->next->num - min;	
	if (arry_num == 2)
	{
		if ((*node)->next->num == 0)
			sa(node,'a');
	}
	if(arry_num == 3)
	{
		if((*node)->next->num == 1)
		{
			if ((*node)->next->next->num == 2)
				sa(node,'a');
			if((*node)->next->next->num == 0)
				rra(node,'a');
		}
		if((*node)->next->num == 2)
		{
			if((*node)->next->next->num == 0)
			{
				sa(node,'a');
				ra(node,'a');
			}
		}
		if((*node)->next->num == 0)
		{
			if((*node)->next->next->num == 1)
			{
				sa(node,'a');
				rra(node,'a');
			}
			if((*node)->next->next->num == 2)
				ra(node,'a');
		}
	}
}
void    sort3(t_stack **node, int arry_num)
{
	int min;

	min= (*node)->next->num;
	if((*node)->next->next->num < min)
		min = (*node)->next->next->num;
	if (arry_num ==3)
	{
		if((*node)->next->next->next->num < min)
		{	
			min = (*node)->next->next->next->num;
			(*node)->next->next->next->num = (*node)->next->next->next->num - min;	
		}
	}
	(*node)->next->num = (*node)->next->num - min;	
	(*node)->next->next->num = (*node)->next->next->num - min;	
	if (arry_num == 2)
	{
		if ((*node)->next->num == 1)
		{
			sa(node,'a');
		}
	}
	if(arry_num == 3)
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
	if (arry_num ==3)
			(*node)->next->next->next->num = (*node)->next->next->next->num + min;	
	(*node)->next->num = (*node)->next->num + min;	
	(*node)->next->next->num = (*node)->next->next->num + min;
	
}

void sort6(t_stack **a, t_stack **b)
{
	int len;
	int i;

	i = 0;
	len = count_node(a);
	
	while(3 < count_node(a))
	{
		if(((*a)->next->num == i) || (len == 5 && (*a)->next->num < 2))
		{
			pb(a,b,'b');
			i++;
		}
		else
			ra(a,'a');
	}
	sort3(a,count_node(a));
	if (len == 5 && (*b)->next->num == 0)
			sa(b,'b');
	while(i--)
		pb(b,a,'a');

}

void    sort(t_stack **a, t_stack **b)
{
	int	node_num;

	node_num = count_node(a);
	if(node_num > 6)
		radix_sort(a,b,count_node(a));
	else if(node_num > 3)
		sort6(a,b);
	else
		sort3(a,node_num);
}