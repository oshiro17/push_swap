#include "push_swap.h"
#include "libft/libft.h"

// typedef struct s_stack
// {
// 	int				num;
// 	long			index;
// 	struct s_stack	*next;
// 	struct s_stack	*previous;
// }		t_stack;

void	put_stack(size_t index, char **str, t_stack **stack)
				   // 0or1   {12 24 32 43}or{./a.out 3 2 4 1}  t_stack
{
    t_stack		*tmp;
	t_stack		*last;

    while (str[index])
    {
		tmp = malloc(sizeof(t_stack));
        if (!tmp)
		{
			free(stack);
			error_free_str_num(**str, index, NULL);
		}
		tmp->num = ft_atol(str[index]);
		// tmp->index = -1;
		tmp->next = NULL;
		tmp->previous = NULL;
		if (!*stack)
			*stack = *tmp;
		else
		{
			*last = *stack;
			while (last->next)
				last = last->next;
			last->next = *tmp;
			tmp->previous = *last;
		}
		index++;
		return ;
    }
}
