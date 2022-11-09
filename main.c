#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char const *argv[])
{
	// t_stack		*stack_a;
	// t_stack		*stack_b;
    const char        **split;

	// stack_a = NULL;
	// stack_b = NULL;
    split = check_args(argc, argv);

    //to check
    printf("%s\n", split[0]);
    printf("%s\n", split[1]); 
    //to check
	return (0);
}