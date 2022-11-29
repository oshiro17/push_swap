#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char const *argv[])
{
	// t_stack		*stack_a;
//	t_stack		*stack_b;
	const char		**str;
	// size_t      index;
	// int		i;
	// int 	k;
	// int		*num;


	// k=0;
	// i = 0;
	// if (argc < 2)
	// 	exit(1);
	// else if (argc == 2)
	// 	index = 0;
	// else
	// 	index = 1;
	str = check_args(argc, argv);


 coordinate_compression(argc, str);
// to_check
  	// while(k < 10)
	// {
	// 	printf("%d\n",num[i]);
	// 	i++;
	// 	k++;
	// }
//to_check

// 	put_stack(argc, (char **)str, &stack_a);

    return (0);
}