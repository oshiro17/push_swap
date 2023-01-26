/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noshiro <noshiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 04:55:06 by noshiro           #+#    #+#             */
/*   Updated: 2023/01/27 05:20:22 by noshiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//同じ数字がないかどうか
bool	check_isdup(long *num, size_t arry_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < arry_count)
	{
		j = 1;
		while ((i + j) < arry_count)
		{
		if (num[i] == num[i + j])
			return (false);
		j++;	
		}
		i++;
	}
	return(true);
}

//数字かどうか
bool    check_isnum(t_data *data)
{
    size_t  j;
	int	index;

	index = data->index;
    while (data->str[index])
    {
        j = 0;
        if (data->str[index][j] == '-' || data->str[index][j] == '+')
		{
			if(data->str[index][j + 1] == '-' || data->str[index][j+1] == '+' || data->str[index][j+1] == '0')
				return (false);
			j++;
		}
        while (data->str[index][j])

        {
            if (data->str[index][j] < '0' || '9' < data->str[index][j])
                return (false);
            j++;
        }
        index++;
    }
    return (true);
}

void	count_arry(t_data *data)
{
	int	i;

	i = 0;
	while (data->str[i])
		i++;
	data->arry_count = i - data->index;
}

//intの範囲?数字？同じ数字ない？
void    check_str(t_data *data)
{
    long        *num;
	size_t		i;
	int			index;

	index = data->index;
	i = 0;
    count_arry(data);
    if(!check_isnum(data))
        error_exit();
    num = malloc(sizeof(long) * data->arry_count);
	if (!num)
		error_exit();
    while(data->str[index])
    {
        num[i] = ft_atol(data->str[index]);
        if (num[i] >= INT_MAX || num[i] <= INT_MIN)
			error_exit();
		i++;
        index++;
    }
    if(!check_isdup(num,data->arry_count))
		error_exit();
	free(num);
	return ;
}

void make_number_arry(t_data *data)
{
	if (data->index == 0)
	{
		data->str = (const char **)ft_split(data->argv[1], ' ');
		if (!data->str)
			error_exit();
		if(!data->str[0] || !data->str[1])
			exit(1);
	}
	else
		data->str = (char const**)data->argv;
    check_str(data);
	return ;
}
