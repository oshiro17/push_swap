#include "push_swap.h"
#include "libft/libft.h"

void free_str_num(char **str, size_t index, long *num)
{
    size_t  i;

    i = 0;
    if (index == 0)
    {   
        while(str[i])
        {
            free(str[i]);
            i++;
        }
        free(str);
    }
    ft_putstr_fd("Error\n", 2);
    if(num)
        free(num);
    exit(1);
}