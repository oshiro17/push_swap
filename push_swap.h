/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noshiro <noshiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:34:58 by panti             #+#    #+#             */
/*   Updated: 2023/01/28 01:59:45 by noshiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

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
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

void		free_char_arry(char **str);
int			main(int argc, char const *argv[]);
void		make_number_arry(t_data *data);
void		free_stack(t_stack **a, t_stack **b);
void		error_exit(void);
void		coordinate_compression(t_data *data);
void		put_stack(t_data data, t_stack **a_stack);
const char	**make_char_arry(size_t index, char const **argv);
t_stack		*ft_lstnew(int num);
void		sort(t_stack **a_stack, t_stack**b_stack);
void		rra(t_stack **a, char spell);
void		ra(t_stack **a, char spell);
void		sa(t_stack **a_stack, char spell);
void		pb(t_stack **a, t_stack **b, char spell);
void		radix_sort(t_stack **a, t_stack **b, int node_num);
void		put_data(t_data *data, int argc, char **argv);
int			count_node(t_stack **node);
void		sort3(t_stack **node, int arry_num);

#endif