/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_compression.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panti <panti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:40:49 by panti             #+#    #+#             */
/*   Updated: 2022/11/30 00:13:04 by panti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	*coordinate_compression(int argc, const char **str)
{
	int index;
	int	*num;
	int i;
	int k;

	i = 0;
	k = 0;
	while (str[k])
	{
		k++;
	}
    if (argc == 2)
	{
		index = 0;
		num = malloc(sizeof(int) * (size_t)k);
	}
	else
	{
		index = 1;
		num = malloc(sizeof(int) * ((size_t)argc - 1));
	}
	while ((k > index) && *(str[index]))
	{
		num[i] = ft_atol(str[index]);
		index++;
		i++;
	}
	i = 0;
	//to_check
	// while(num[i])
	// {
	// 	printf("{%d}\n",num[i]);
	// 	i++;
	// }
	return (num);
}