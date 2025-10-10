/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:08:37 by mirokugo          #+#    #+#             */
/*   Updated: 2024/05/07 10:55:33 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_negative(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_reverse_str(char *str)
{
	int	len;
	int	i;
	int	j;

	len = ft_strlen(str);
	i = 0;
	j = len - 1;
	while (i < j)
	{
		str[i] = str[i] ^ str[j];
		str[j] = str[i] ^ str[j];
		str[i] = str[i] ^ str[j];
		i++;
		j--;
	}
	return (str);
}

int	check_digits(int n)
{
	int	digits;

	digits = 1;
	while (n / 10)
	{
		n = n / 10;
		digits++;
	}
	if (n < 0)
		digits++;
	return (digits);
}

char	*ft_itoaprocess(int n, int digits, int negcheck, char *c)
{
	char	*str;
	int		i;

	i = 0;
	if (n == 0)
	{
		c[0] = '0';
		c[1] = '\0';
		return (c);
	}
	if (negcheck)
		n = n * -1;
	while (n > 0)
	{
		c[i++] = (n % 10) + 48;
		n = n / 10;
	}
	if (negcheck)
		c[i++] = '-';
	c[i] = '\0';
	str = ft_reverse_str(c);
	str[digits] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		digits;
	int		negcheck;
	char	*c;
	char	*str;

	negcheck = ft_is_negative(n);
	digits = check_digits(n);
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	c = (char *)malloc(sizeof(char) * (digits + 1));
	if (!c)
		return (NULL);
	str = ft_itoaprocess(n, digits, negcheck, c);
	return (str);
}
//
// XOR交換アルゴリズム
// int	main(void)
// {
// 	int		n;
// 	char	*str;

// 	str = (char *)malloc(sizeof(char) * 12);
// 	n = 42;
// 	printf("%s\n", ft_itoa(n));
// 	n = -42;
// 	printf("%s\n", ft_itoa(n));
// 	n = 0;
// 	printf("%s\n", ft_itoa(n));
// 	n = INT_MIN;
// 	printf("%s\n", ft_itoa(n));
// 	n = INT_MAX;
// 	printf("%s\n", ft_itoa(n));
// 	return (0);
// }
