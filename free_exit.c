/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noshiro <noshiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:40:18 by panti             #+#    #+#             */
/*   Updated: 2023/01/27 06:57:57 by noshiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **a ,t_stack **b)
{
    t_stack *tmp;
    t_stack *a_node;

    (a_node) = (*a)->next;
    while(a_node->num != -1)
    {
        tmp = a_node;
        a_node = a_node->next;
        free(tmp);
    }
    free(*a);
    free(*b);
}

void free_char_arry(char **str)
{
    int i;    

    i = 0;
    while(str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
    str = NULL;
}

void error_exit()
{
    ft_putstr_fd("Error\n", 2);
    exit(1);
}