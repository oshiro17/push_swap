/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panti <panti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:55:32 by panti             #+#    #+#             */
/*   Updated: 2023/01/14 16:56:31 by panti            ###   ########.fr       */
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
	// printf("pointer B::%p\n",b_stack->next);
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
	// int i =0;
	// while(i<6)
	// {
	// 	printf("main)data.subjectnum:%ld\n", data.subject_num[i]);
	// 	i++;
	// }
	put_stack(data, &a_stack);
	
	// t_stack *tmp;
	// int i = 0;
	// tmp = (a_stack);
    // while(i < data.arry_count+1)
    // {
    //     printf("%d\n",(tmp)->num);
    //     tmp=tmp->next;
    //     i++;
    // }
	sort_stack(&a_stack, &b_stack);
	// system("leaks -q push_swap");
    return (0);

}