/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panti <panti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:43:49 by panti             #+#    #+#             */
/*   Updated: 2023/01/08 23:29:14 by panti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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

void put_stack(t_data *data, t_stack **a_stack)
{
	t_stack *tmp;
	t_stack *nil;
	int		i;

	tmp = NULL;
	nil = ft_lstnew(-1);
	i = 0;
	ft_lstadd_back(a_stack, nil);
	while(i < data->arry_count)
	{
		tmp = ft_lstnew(data->subject_num[i]);
		if (!tmp)
			error_free_str_num(data);
		ft_lstadd_back(a_stack, tmp);

		i++;
	}
	nil->previous = ft_lstlast(*a_stack);
	(ft_lstlast(*a_stack))->next= nil;
	tmp = *a_stack;
	// printf("=====%d\n",tmp->num);
	// printf("=====%d\n",tmp->next->num);
	// while(tmp->next->num != -1)
	// {
	// 	tmp = tmp->next;
	// 	printf("%d\n",tmp->num);
	// }
	return;
}