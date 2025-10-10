/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 05:55:00 by mirokugo          #+#    #+#             */
/*   Updated: 2024/05/09 06:45:02 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	if (c == ' ' || (9 <= c && c <= 13))
		return (1);
	return (0);
}

long	ft_strtol(const char *str)
{
	long	n;
	int		sign;

	n = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while ('0' <= *str && *str <= '9')
	{
		if (n > (LONG_MAX - (*str - '0')) / 10)
		{
			if (sign == 1)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
		n = n * 10 + *str - '0';
		str++;
	}
	return (n * sign);
}

int	ft_atoi(const char *str)
{
	return ((int)ft_strtol(str));
}

// int	main(void)
// {
// 	char	*str;

// 	str = "2147483647";
// 	printf("%d\n", ft_atoi(str));
// 	printf("%d\n", atoi(str));
// 	str = "-2147483648";
// 	printf("%d\n", ft_atoi(str));
// 	printf("%d\n", atoi(str));
// 	str = "2147483647";
// 	printf("%d\n", ft_atoi(str));
// 	printf("%d\n", atoi(str));
// 	str = "-1";
// 	printf("%d\n", ft_atoi(str));
// 	printf("%d\n", atoi(str));
// 	str = "0";
// 	printf("%d\n", ft_atoi(str));
// 	printf("%d\n", atoi(str));
// 	str = "42tokyo";
// 	printf("%d\n", ft_atoi(str));
// 	printf("%d\n", atoi(str));
// 	str = "tokyo42";
// 	printf("%d\n", ft_atoi(str));
// 	printf("%d\n", atoi(str));
// 	str = "000042";
// 	printf("%d\n", ft_atoi(str));
// 	printf("%d\n", atoi(str));
// 	str = "  -42";
// 	printf("%d\n", ft_atoi(str));
// 	printf("%d\n", atoi(str));
// 	str = "9223372036854775806";
// 	printf("%d\n", ft_atoi(str));
// 	printf("%d\n", atoi(str));
// 	printf("%ld\n", strtol(str, NULL, 10));
// 	printf("%d\n", (int)strtol(str, NULL, 10));
// 	str = "-9223372036854775807";
// 	printf("%d\n", ft_atoi(str));
// 	printf("%d\n", atoi(str));
// 	str = "9223372036854775808";
// 	printf("%d\n", ft_atoi(str));
// 	printf("%d\n", atoi(str));
// 	str = "-9223372036854775809";
// 	printf("%d\n", ft_atoi(str));
// 	printf("%d\n", atoi(str));
// 	str = "123456789012345678901234567890";
// 	printf("%d\n", ft_atoi(str));
// 	printf("%d\n", atoi(str));
// 	str = "-123456789012345678901234567890";
// 	printf("%d\n", ft_atoi(str));
// 	printf("%d\n", atoi(str));
// 	return (0);
// }
