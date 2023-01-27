/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panti <panti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:55:32 by panti             #+#    #+#             */
/*   Updated: 2023/01/27 18:36:15 by panti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void put_data(t_data *data, int argc, char **argv)
{
	data->argc = argc;
	data->argv = (char **)argv;
	data->str = NULL;
	data->subject_num = NULL;
	if (data->argc < 2)
		exit(1);
	else if (data->argc == 2)
		data->index = 0;
	else
		data->index = 1;
}

int	main(int argc, char const *argv[])
{
	t_data	data;
	t_stack *a_stack;
	t_stack *b_stack;

	a_stack = ft_lstnew(-1);
	if(!a_stack)
		error_exit();
	b_stack = ft_lstnew(-1);
	if(!b_stack)
		error_exit();
	put_data(&data,argc,(char **)argv);
	make_number_arry(&data);
	coordinate_compression(&data);
	put_stack(data, &a_stack);	
	sort(&a_stack, &b_stack);
	free_stack(&a_stack,&b_stack);
	// system("leaks -q push_swap");
    return (0);

}