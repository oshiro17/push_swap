#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char const *argv[])
{
	t_data	data;

	data.argc = argc;
	data.argv = (char **)argv;
	data.str = NULL;
	data.subject_num = NULL;
	if (data.argc < 2)
		error_free_str_num(&data);
	else if (data.argc == 2)
		data.index = 0;
	else
		data.index = 1;
	make_number_arry(&data);
	printf("str[0]:%s\n",data.str[0]);
	printf("arry_count:%d\n",data.arry_count);
	coordinate_compression(&data);
	// 	put_stack(argc, (char **)str, &stack_a);

    return (0);
}