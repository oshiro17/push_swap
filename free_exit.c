/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panti <panti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:40:18 by panti             #+#    #+#             */
/*   Updated: 2022/12/16 21:46:33 by panti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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

void error_free_str_num(t_data *data)
{
    if (data->str || data->index == 0)
        free_char_arry((char**)data->str);
    if(data->subject_num)
        free(data->subject_num);
    ft_putstr_fd("Error\n", 2);
    exit(1);
}