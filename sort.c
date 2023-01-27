/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noshiro <noshiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:34:54 by panti             #+#    #+#             */
/*   Updated: 2023/01/28 01:39:55 by noshiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort6(t_stack **a, t_stack **b)
{
	int	len;
	int	i;

	i = 0;
	len = count_node(a);
	while (3 < count_node(a))
	{
		if (((*a)->next->num == i) || (len == 5 && (*a)->next->num < 2))
		{
			pb(a, b, 'b');
			i++;
		}
		else
			ra(a, 'a');
	}
	sort3(a, count_node(a));
	if (len == 5 && (*b)->next->num == 0)
		sa(b, 'b');
	while (i--)
		pb(b, a, 'a');
}

static bool	is_sort(t_stack **a)
{
	t_stack	*tmp;

	tmp = (*a)->next;
	while (tmp->next->num != -1)
	{
		if (tmp->num > tmp->next->num)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

void	sort(t_stack **a, t_stack **b)
{
	int	node_num;

	node_num = count_node(a);
	if (is_sort(a))
		exit(1);
	if (node_num > 6)
		radix_sort(a, b, count_node(a));
	else if (node_num > 3)
		sort6(a, b);
	else
		sort3(a, node_num);
}
