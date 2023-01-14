#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_data
{
	int			argc;
	char		**argv;
	int			index;
	const char	**str;
	int			arry_count;
	long		*subject_num;
}	t_data;


typedef struct s_stack
{
	int				num;
	long			index;
	struct s_stack	*next;
	struct s_stack	*previous;
}              t_stack;

void	free_char_arry(char **str);
int		main(int argc, char const *argv[]);
void	make_number_arry(t_data *data);
void	error_free_str_num(t_data *data);
void	coordinate_compression(t_data *data);
void put_stack(t_data data, t_stack **a_stack);
const char **make_char_arry(size_t index,char const **argv);
void sort_stack(t_stack **a_stack, t_stack **b_stack);
t_stack *ft_lstnew(int num);
#endif