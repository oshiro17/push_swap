/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noshiro <noshiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 01:37:20 by noshiro           #+#    #+#             */
/*   Updated: 2023/01/28 01:53:43 by noshiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_node(t_stack **node)
{
	int		i;
	t_stack	*tmp;

	tmp = (*node)->next;
	i = 0;
	while (tmp->num != -1)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

static void	sort3help(int first, int second, int arry_num, t_stack **node)
{
	if (arry_num == 2 && first == 1)
		sa(node, 'a');
	if (arry_num == 3)
	{
		if (first == 1 && second == 0)
			sa(node, 'a');
		if (first == 0 && second == 2)
		{
			sa(node, 'a');
			ra(node, 'a');
		}
		if (first == 2 && second == 1)
		{
			sa(node, 'a');
			rra(node, 'a');
		}
		if (first == 2 && second == 0)
			ra(node, 'a');
		if (first == 1 && second == 2)
			rra(node, 'a');
	}	
}

void	sort3(t_stack **node, int arry_num)
{
	int	min;
	int	first;
	int	second;
	int	third;

	first = (*node)->next->num;
	second = (*node)->next->next->num;
	third = (*node)->next->next->next->num;
	min = first;
	if (second < min)
		min = second;
	if (arry_num == 3 && third < min)
		min = third;
	first = first - min;
	second = second - min;
	sort3help(first, second, arry_num, node);
}
