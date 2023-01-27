/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noshiro <noshiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:55:32 by panti             #+#    #+#             */
/*   Updated: 2023/01/28 02:33:02 by noshiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_num(char *arry)
{
	int	i;

	i = 0;
	if ((arry[i] == '+' || arry[i] == '-') \
	&& i == 0 && arry[i + 1])
		i = 1;
	while (arry[i])
	{
		if (!ft_isdigit(arry[i]))
			return (false);
		i++;
	}
	return (true);
}

void	put_data(t_data *data, int argc, char **argv)
{
	data->argc = argc;
	data->argv = argv;
	data->str = NULL;
	data->subject_num = NULL;
	if (data->argc < 2)
		exit(1);
	else if (data->argc == 2)
	{
		data->index = 0;
		if (ft_atol(argv[1]) > INT_MAX || ft_atol(argv[1]) > INT_MIN)
			error_exit();
		if (check_num(argv[1]))
			exit(1);
	}
	else
		data->index = 1;
}

int	main(int argc, char const **argv)
{
	t_data	data;
	t_stack	*a_stack;
	t_stack	*b_stack;

	a_stack = ft_lstnew(-1);
	if (!a_stack)
		error_exit();
	b_stack = ft_lstnew(-1);
	if (!b_stack)
		error_exit();
	put_data(&data, argc, (char **)argv);
	make_number_arry(&data);
	coordinate_compression(&data);
	put_stack(data, &a_stack);
	sort(&a_stack, &b_stack);
	free_stack(&a_stack, &b_stack);
	return (0);
}
