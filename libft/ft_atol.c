/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
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

long	ft_atol(const char *str)
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
			return (LONG_MAX);
		if (is_overlong(ret, sign, *str) && sign == 1)
			return (LONG_MIN);
		ret = (ret * 10) - ((int)*str - '0');
		str++;
	}
	return (ret * sign);
}

// int main()
// {
// 	printf("origin :%ld\n", atol("9223372036854775806"));
// 	printf("nonoka :%ld\n", ft_atol("9223372036854775806"));
// 	printf("origin :%ld\n", atol("9223372036854775807"));
// 	printf("nonoka :%ld\n", ft_atol("9223372036854775807"));
// 	printf("origin :%ld\n", atol("9223372036854775808"));
// 	printf("nonoka :%ld\n", ft_atol("9223372036854775808"));
// 	printf("origin :%ld\n", atol("9223372036854775809"));
// 	printf("nonoka :%ld\n", ft_atol("9223372036854775809"));
// 	printf("origin :%ld\n", atol("9223372036854775810"));
// 	printf("nonoka :%ld\n", ft_atol("9223372036854775810"));
// 	printf("origin :%ld\n", atol("-9223372036854775806"));
// 	printf("nonoka :%ld\n", ft_atol("-9223372036854775806"));
// 	printf("origin :%ld\n", atol("-9223372036854775807"));
// 	printf("nonoka :%ld\n", ft_atol("-9223372036854775807"));
// 	printf("origin :%ld\n", atol("-9223372036854775808"));
// 	printf("nonoka :%ld\n", ft_atol("-9223372036854775808"));
// 	printf("origin :%ld\n", atol("-9223372036854775809"));
// 	printf("nonoka :%ld\n", ft_atol("-9223372036854775809"));
// 	printf("origin :%ld\n", atol("-9223372036854775810"));
// 	printf("nonoka :%ld\n", ft_atol("-9223372036854775810"));
// 	return 0;
// }

// // 2147483647 < 