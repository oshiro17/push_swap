/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noshiro <noshiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:41:05 by noshiro           #+#    #+#             */
/*   Updated: 2022/06/19 21:10:42 by noshiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_overlong(long ret, int sign, char c)
{
	long	tmp;

	tmp = LONG_MIN / 10;
	if (sign == -1)
		c++;
	if (ret < tmp || (ret == tmp && LONG_MAX % 10 + 1 < c - '0'))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	ret;

	ret = 0;
	sign = -1;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (is_overlong(ret, sign, *str) && sign == -1)
			return ((int)(LONG_MAX));
		if (is_overlong(ret, sign, *str) && sign == 1)
			return ((int)(LONG_MIN));
		ret = (ret * 10) - ((int)*str - '0');
		str++;
	}
	return (ret * sign);
}

// // intの範囲を超える時は回っちゃう
// #include "stdio.h"
// #include "string.h"

// int main()
// {
// 	printf("original :%d\n", atoi("9223372036854775807"));
// 	printf("nonoka :%d\n", ft_atoi("9223372036854775807"));
// 	printf("original :%d\n", atoi("9223372036854775808"));
// 	printf("nonoka :%d\n", ft_atoi("9223372036854775808"));
// 	printf("original :%d\n", atoi("9223372036854775809"));
// 	printf("nonoka :%d\n", ft_atoi("9223372036854775809"));
// 	printf("original :%d\n", atoi("9223372036854775810"));
// 	printf("nonoka :%d\n", ft_atoi("9223372036854775810"));
// 	// printf("original :%d\n", atoi("-9223372036854775807"));
// 	// printf("nonoka :%d\n", ft_atoi("-9223372036854775807"));
// 	// printf("original :%d\n", atoi("-9223372036854775808"));
// 	// printf("nonoka :%d\n", ft_atoi("-9223372036854775808"));
// 	// printf("original :%d\n", atoi("-9223372036854775809"));
// 	// printf("nonoka :%d\n", ft_atoi("-9223372036854775809"));
// 	return 0;
// }