/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_compression.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panti <panti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:40:49 by panti             #+#    #+#             */
/*   Updated: 2023/01/14 16:35:40 by panti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void compression(t_data *data)
{
	int	i;
	int j;
	int number;
	long *new_num;

	new_num = malloc(sizeof(long) * data->arry_count);
	if(!new_num)
		error_free_str_num(data);
	number = 0;
	i = 0;
	while(i < data->arry_count)
	{
		j = 0;
		while (j < data->arry_count)
		{
			if (data->subject_num[i] > data->subject_num[j])
				number++;
			j++;
		}
		new_num[i] = number;
		number = 0;
		i++;
	}
	data->subject_num = new_num;
}

void str_to_num(t_data *data)
{
	int index;
	int i;

	index = data->index;
	data->subject_num = (long *)malloc(sizeof(int) * data->arry_count);
		if (!data->subject_num)
			error_free_str_num(data);
	i = 0;
	while(data->str[index])
	{
		data->subject_num[i] = ft_atol(data->str[index]);
		index++;
		i++;
	}
	if (data->index == 0)
		free_char_arry((char **)data->str);
	return;
}

void	coordinate_compression(t_data *data)
{
	str_to_num(data);
	compression(data);
	return;
}