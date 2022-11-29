/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_compression.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panti <panti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:40:49 by panti             #+#    #+#             */
/*   Updated: 2022/11/30 00:43:08 by panti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int *str_to_num(int argc,const char **str)
{
	int *num;
	int elem;
	int index;
	
	elem = 0;
	if(argc == 2)
	{
		index = 0;
		while(str[elem])
			elem++;
		num = malloc(sizeof(int) * (size_t)elem);		
	}
	else
	{	
		index = 1;
		num = malloc(sizeof(int)*argc);
	}
	elem = 0;
	while(str[index])
	{
		num[elem] = ft_atol(str[index]);
		index++;
		elem++;
	}
	return(num);
}

void	*coordinate_compression(int argc, const char **str)
{
	int	*num;
	int i;

	i=0;
	num = str_to_num(argc,str);
	while(num[i])
	{
		printf("{%d}\n",num[i]);
		i++;
	}
	return (num);
}