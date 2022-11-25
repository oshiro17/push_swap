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

typedef struct s_stack
{
	int				num;
	long			index;
	struct s_stack	*next;
	struct s_stack	*previous;
}              t_stack;

int		main(int argc, char const *argv[]);
const char	**check_args(int i, char const **argv);
void	error_free_str_num(char **str, size_t index, long *num);
// void	coordinate_compression(argc, str, &stack_a);
void	put_stack(size_t index, char **str, t_stack **stack);
const char **make_char_arry(size_t index,char const **argv);

#endif