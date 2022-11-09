#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>

typedef struct s_stack
{
	int				num;
	long			index;
	struct s_stack	*next;
	struct s_stack	*previous;
}              t_stack;

int main(int argc, char const *argv[]);
const char **check_args(int argc, char const **argv);
const char **make_char_arry(int argc,char const **argv);

#endif