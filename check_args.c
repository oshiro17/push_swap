#include "push_swap.h"
#include "libft/libft.h"


// void	free_exit()

//同じ数字がないかどうか
bool	check_isdup(long *num, size_t arry_num)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < arry_num)
	{
		j = 1;
		while ((i + j) < arry_num)
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
bool    check_isnum(const char **str, size_t index)
{
    size_t  j;

    while (str[index])
    {
        j = 0;
        if (str[index][j] == '-' || str[index][j] == '+')
		{
			if(str[index][j + 1] == '-' || str[index][j+1] == '+' || str[index][j+1] == '0')
				return (false);
			j++;
		}
        while (str[index][j])

        {
            if (str[index][j] < '0' || '9' < str[index][j])
                return (false);
            j++;
        }
        index++;
    }
    return (true);
}

static size_t	count_arry(const char **str, size_t index)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	i = i - index;
	return (i);
}
//intの範囲?数字？同じ数字ない？
void    check_str(const char **str, size_t index)
{
    size_t      arry_num;
    long        *num;
	size_t		i;


	i = 0;
    arry_num = count_arry(str, index);
    if(!check_isnum(str, index))
        error_free_str_num((char **)str,index,NULL);
    num = malloc(sizeof(long) * arry_num);
	if (!num)
		error_free_str_num((char **)str,index,NULL);
    while(str[index])
    {
		// printf("%s\n",str[index]);
        num[i] = ft_atol(str[index]);
			// printf("%s\n",str[index]);
        if (num[i] >= INT_MAX || num[i] <= INT_MIN)
        	error_free_str_num((char **)str,index,num);
        i++;
        index++;
    }
    if(!check_isdup(num,arry_num))
		error_free_str_num((char **)str, index, NULL);
	free(num);
	return ;
}

const char **check_args(size_t index, char const **argv)
{
	const char	**str;

	if (index == 0)
	{
		str = (const char **)ft_split(argv[1], ' ');
		if (!str || !(str[1]))
        {   
			ft_putstr_fd("Error\n", 2);
		    exit(1);
        }
	}
	else
		str = argv;
    check_str(str, index);
	return (str);
}

// gcc check_args.c libft/ft_atol.c libft/ft_putstr_fd.c free_exit.c libft/ft_putchar_fd.c libft/ft_split.c libft/ft_substr.c libft/ft_strlen.c
// int main(int argc, char const *argv[])
// {
// 	char **str;
// 	int	i;

// 	i = 0;
// 	str = (char **)(check_args(argc, argv));
// 	while(str[i])
// 	{
// 		printf("%s\n",str[i]);
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

