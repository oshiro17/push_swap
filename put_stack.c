/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noshiro <noshiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:43:49 by panti             #+#    #+#             */
/*   Updated: 2023/01/27 06:27:55 by noshiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_stack **a_stack, t_stack *new)
{
	t_stack	*last;

	if (!*a_stack)
	{
		*a_stack = new;
		return ;
	}
	last = ft_lstlast(*a_stack);
	last->next = new;
	new->previous=last;
	return ;
}

t_stack *ft_lstnew(int num)
{
	t_stack *new;
	
	new = malloc(sizeof(t_stack));
	if(!new)
		return(NULL);
	new->num = num;
	new->next = NULL;
	new->previous = NULL;
	return (new);
}

void put_stack(t_data data, t_stack **a_stack)
{
	t_stack *tmp;
	int		i;

	tmp = NULL;
	i = 0;
	while(i < data.arry_count)
	{
		tmp = ft_lstnew(data.subject_num[i]);
		if (!tmp)
			error_exit();
		ft_lstadd_back(a_stack, tmp);
		i++;
	}
	(*a_stack)->previous = ft_lstlast(*a_stack);
	(ft_lstlast(*a_stack))->next= (*a_stack);
	tmp = *a_stack;
	free(data.subject_num);
	return;
}