/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panti <panti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:55:32 by panti             #+#    #+#             */
/*   Updated: 2023/01/24 22:02:44 by panti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char const *argv[])
{
	t_data	data;
	t_stack *a_stack;
	t_stack *b_stack;

	a_stack = ft_lstnew(-1);
	b_stack = ft_lstnew(-1);
	data.argc = argc;
	data.argv = (char **)argv;
	data.str = NULL;
	data.subject_num = NULL;
	if (data.argc < 2)
		error_free_str_num(&data);
	else if (data.argc == 2)
		data.index = 0;
	else
		data.index = 1;
	make_number_arry(&data);
	coordinate_compression(&data);
	put_stack(data, &a_stack);
	
	t_stack *tmp;
	int i = 0;
	sort(&a_stack, &b_stack);
	i = 0;
	tmp = (a_stack);
    while(i < data.arry_count+1)
    {
        printf("{main}%d\n",(tmp)->num);
        tmp=tmp->next;
        i++;
    }
	// // system("leaks -q push_swap");
    return (0);

}