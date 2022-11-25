#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char const *argv[])
{
	// t_stack		*stack_a;
//	t_stack		*stack_b;
    const char		**str;
	// size_t      index;
	int		i;

	i = 0;
	// if (argc < 2)
	// 	exit(1);
	// else if (argc == 2)
	// 	index = 0;
	// else
	// 	index = 1;
	str = check_args(argc, argv);

// to_check
  	while(str[i])
	{
		printf("%s\n",str[i]);
		i++;
	}
//to_check
// coordinate_compression(argc, (char **)str, &stack_a);


// 	put_stack(argc, (char **)str, &stack_a);

    return (0);
}