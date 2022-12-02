/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_compression.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panti <panti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:40:49 by panti             #+#    #+#             */
/*   Updated: 2022/12/02 20:10:09 by panti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	*compression(int *num,int elem)
{
	int	i;
	int j;
	int number;
	int *new_num;

	new_num = malloc(sizeof(int)*elem);
	if(!new_num)
		return(NULL);
	number = 0;
	i = 0;
	while(i < elem)
	{
		j = 0;
		while (j < elem)
		{
			if (num[i] > num[j])
				number++;
			j++;
		}
		new_num[i] = number;
		number = 0;
		i++;
	}
	num = new_num;
	free(new_num);
	return(num);
}

int *str_to_num(int argc,const char **str,int elem)
{
	int *num;
	int index;
	int k;

	if(argc == 2)
		index = 0;
	else
		index = 1;
	num = malloc(sizeof(int) * (size_t)elem);
		if (!num)
			return (NULL);
	k = 0;
	while(str[index])
	{
		num[k] = ft_atol(str[index]);
		index++;
		k++;
	}
	return(num);
}

void	coordinate_compression(int argc, const char **str)
{
	int	*num;
	int i;
	int elem;

	i=0;
	elem = 0;
	if(argc == 2)
	{
		while(str[elem])
			elem++;	
	}
	else
		elem = argc - 1;
	num = str_to_num(argc,str,elem);
	if(!num)
		error_free_str_num(str,index,NULL);
	free(str);
	num = compression(num,elem);
	
	i = 0;
	while(i<elem)
	{
		printf("{%d}\n",num[i]);
		i++;
	}
	return;
}