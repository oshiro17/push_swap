#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char const *argv[])
{
	// t_stack		*stack_a;
// t_stack		*stack_b;
    const char		**split;
	size_t      index;
	int		i;

	i = 0;
	if (argc < 2)
		exit(1);
	else if (argc == 2)
		index = 0;
	else
		index = 1;
	split = check_args(index, argv);

// //to_check
  	while(split[i])
	{
		printf("%s\n",split[i]);
		i++;
	}
// //to_check
    // put_stack(argc, str, &stack_a);

    return (0);
}