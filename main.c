#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char const *argv[])
{
	const char	**str;

	str = check_args(argc, argv);
	coordinate_compression(argc, str);
// 	put_stack(argc, (char **)str, &stack_a);

    return (0);
}