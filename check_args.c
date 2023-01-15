#include "push_swap.h"
#include "libft/libft.h"

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
        error_free_str_num(data);
    num = malloc(sizeof(long) * data->arry_count);
	if (!num)
		error_free_str_num(data);
    while(data->str[index])
    {
        num[i] = ft_atol(data->str[index]);
        if (num[i] >= INT_MAX || num[i] <= INT_MIN)
        {
			free(num);
			error_free_str_num(data);
		}
		i++;
        index++;
    }
    if(!check_isdup(num,data->arry_count))
		error_free_str_num(data);
	free(num);
	return ;
}

void make_number_arry(t_data *data)
{
	if (data->index == 0)
	{
		data->str = (const char **)ft_split(data->argv[1], ' ');
		if (!data->str||!data->str[0])
        {   
			ft_putstr_fd("Error\n", 2);
		    exit(1);
        }
			if(!(data->str[1]))
			exit(1);
	}
	else
		data->str = (char const**)data->argv;
    check_str(data);
	return ;
}

// // gcc check_args.c libft/ft_atol.c libft/ft_putstr_fd.c free_exit.c libft/ft_putchar_fd.c libft/ft_split.c libft/ft_substr.c libft/ft_strlen.c
// int main(int argc, char const *argv[])
// {
// 	t_data data;
// 	int i;

// 	i = 0;
// 	data.argc = argc;
// 	data.argv = (char **)argv;
// 	if (data.argc < 2)
// 		exit(1);
// 	else if (data.argc == 2)
// 		data.index = 0;
// 	else
// 		data.index = 1;
// 	check_args(&data);
// 	while(data.str[i])
// 	{
// 		printf("%s\n",data.str[i]);
// 		i++;
// 	}
// 	return(0);
// }


// int main(int argc, char const *argv[])
// {
//     const char    **str;

//     str = malloc(sizeof(char *) * 6);
//     for (int i = 0; i < 6; i++)
//     {
//         str[i] = malloc(sizeof(char) * 10);
//     }
//     str[5] = NULL;
    
//     strcpy((char *)str[0], "a");
//     strcpy((char *)str[1], "+1");
//     strcpy((char *)str[2], "2");
//     strcpy((char *)str[3], "-3");
//     strcpy((char *)str[4], "4");
//     printf("%d\n", check_isnum(str, 0));
//     return 0;
// }

