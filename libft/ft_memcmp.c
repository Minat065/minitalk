/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 04:23:31 by mirokugo          #+#    #+#             */
/*   Updated: 2024/05/03 17:39:47 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (n--)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char *s1 = "Hello, World!";
// 	char *s2 = "Hello, Wold!";
// 	size_t n = 5;
// 	printf("ft_memcmp: %d\n", ft_memcmp(s1, s2, n));
// 	printf("   memcmp: %d\n", memcmp(s1, s2, n));

// 	char *s3 = "Hello, World!";
// 	char *s4 = "Hello, Wold!";
// 	size_t n2 = 10;
// 	printf("ft_memcmp: %d\n", ft_memcmp(s3, s4, n2));
// 	printf("   memcmp: %d\n", memcmp(s3, s4, n2));

// 	char *s5 = "Hello, World!";
// 	char *s6 = "Hello, Wold!";
// 	size_t n3 = 15;
// 	printf("ft_memcmp: %d\n", ft_memcmp(s5, s6, n3));
// 	printf("   memcmp: %d\n", memcmp(s5, s6, n3));

// 	char *s7 = "Hello, World!";
// 	char *s8 = "Hello, Wold!";
// 	size_t n4 = 0;
// 	printf("ft_memcmp: %d\n", ft_memcmp(s7, s8, n4));
// 	printf("   memcmp: %d\n", memcmp(s7, s8, n4));

// 	char *s9 = "Hello, World!";
// 	char *s10 = "Hello, Wold!";
// 	size_t n5 = 1;
// 	printf("ft_memcmp: %d\n", ft_memcmp(s9, s10, n5));
// 	printf("   memcmp: %d\n", memcmp(s9, s10, n5));

// 	char *s11 = "";
// 	char *s12 = "Hello, World!";
// 	size_t n6 = 5;
// 	printf("ft_memcmp: %d\n", ft_memcmp(s11, s12, n6));
// 	printf("   memcmp: %d\n", memcmp(s11, s12, n6));

// 	char *s13 = "Hello, World!";
// 	char *s14 = "";
// 	size_t n7 = 5;
// 	printf("ft_memcmp: %d\n", ft_memcmp(s13, s14, n7));
// 	printf("   memcmp: %d\n", memcmp(s13, s14, n7));

// 	char *s15 = "";
// 	char *s16 = "";
// 	size_t n8 = 5;
// 	printf("ft_memcmp: %d\n", ft_memcmp(s15, s16, n8));
// 	printf("   memcmp: %d\n", memcmp(s15, s16, n8));

// 	return (0);
// }