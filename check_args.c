#include "push_swap.h"
#include "libft/libft.h"
#include <string.h>
#include <stdio.h>

// bool    check_isnum(const char **str, size_t index)
// {
//     size_t  j;

//     while (str[index])
//     {
//         j = 0;
//         if (str[index][j] == '-' || str[index][j] == '+')
//             j++;
//         while (str[index][j])
//         {
//             if (str[index][j] < '0' || '9' < str[index][j])
//             {
//                 return (false);
//             }
//             j++;
//         }
//         index++;
//     }
//     return (true);
// }

// bool    check_str(const char **str, size_t index)
// {
//     check_isnum();
//     check_isoverint();
//     check_is();

// }

const char **check_args(int argc, char const **argv)
{
	const char	**str;
    // size_t      index;

	if (argc < 2)
		exit(1);
	else if (argc == 2)
	{
		str = (const char **)ft_split(argv[1], ' ');
		if (!str)
		    exit(1);
        // index = 0;
	}
	else
    {
        str = argv;
        // index = 1;
    }
    // check_str(str, index);
        // str = make_char_arry(argc,argv);
	return (str);
}


// int main(int argc, char const *argv[])
// {
//     const char    **str;

//     str = malloc(sizeof(char *) * 6);
//     for (int i = 0; i < 6; i++)
//     {
//         str[i] = malloc(sizeof(char) * 10);
//     }
//     str[5] = NULL;
    
//     strcpy((char *)str[0], "-0");
//     strcpy((char *)str[1], "+1");
//     strcpy((char *)str[2], "2");
//     strcpy((char *)str[3], "3");
//     strcpy((char *)str[4], "4");
//     printf("%d\n", check_isnum(str, 0));
//     return 0;
// }

