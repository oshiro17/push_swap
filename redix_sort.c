/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noshiro <noshiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:34:49 by panti             #+#    #+#             */
/*   Updated: 2023/01/27 23:45:36 by noshiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_log(int node_num)
{
	int	i;

	i = 0;
	while (0 < node_num)
	{
		node_num /= 2;
		i++;
	}
	return (i);
}

int	check_bina(t_stack **a, t_stack **b, int num, int digit)
{
	int	pb_count;

	pb_count = 0;
	if ((num >> digit & 1) == 1)
		ra(a, 'a');
	else
	{
		pb(a, b, 'b');
		pb_count++;
	}
	return (pb_count);
}

void	radix_sort(t_stack **a, t_stack **b, int node_num)
{
	int		digit;
	int		i;
	int		pb_count;

	digit = 0;
	while (digit < get_log(node_num))
	{
		i = 0;
		pb_count = 0;
		while (i < node_num)
		{
			pb_count = (check_bina(a, b, (*a)->next->num, digit)) \
			+ pb_count;
			i++;
		}
		while (pb_count--)
			pb(b, a, 'a');
		digit++;
	}
}
