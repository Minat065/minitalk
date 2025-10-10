/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 03:59:36 by mirokugo          #+#    #+#             */
/*   Updated: 2024/05/03 17:50:16 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*s1 != *s2 || *s1 == '\0')
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

// int	main(void)
// {
// 	char *s1 = "Hello, World!";
// 	char *s2 = "Hello, World!";
// 	size_t n = 5;
// 	printf("ft_strncmp: %d\n", ft_strncmp(s1, s2, n));
// 	printf("   strncmp: %d\n", strncmp(s1, s2, n));

// 	char *s3 = "Hello, World!";
// 	char *s4 = "Hello, World!";
// 	size_t n2 = 10;
// 	printf("ft_strncmp: %d\n", ft_strncmp(s3, s4, n2));
// 	printf("   strncmp: %d\n", strncmp(s3, s4, n2));

// 	char *s5 = "Hello, World!";
// 	char *s6 = "Hello, World!";
// 	size_t n3 = 15;
// 	printf("ft_strncmp: %d\n", ft_strncmp(s5, s6, n3));
// 	printf("   strncmp: %d\n", strncmp(s5, s6, n3));

// 	char *s7 = "Hello, World!";
// 	char *s8 = "Hello, World!";
// 	size_t n4 = 0;
// 	printf("ft_strncmp: %d\n", ft_strncmp(s7, s8, n4));
// 	printf("   strncmp: %d\n", strncmp(s7, s8, n4));

// 	char *s9 = "Hello, World!";
// 	char *s10 = "Hello, World!";
// 	size_t n5 = 1;
// 	printf("ft_strncmp: %d\n", ft_strncmp(s9, s10, n5));
// 	printf("   strncmp: %d\n", strncmp(s9, s10, n5));

// 	char *s11 = "";
// 	char *s12 = "Hello, World!";
// 	size_t n6 = 5;
// 	printf("ft_strncmp: %d\n", ft_strncmp(s11, s12, n6));
// 	printf("   strncmp: %d\n", strncmp(s11, s12, n6));

// 	char *s13 = "Hello, World!";
// 	char *s14 = "";
// 	size_t n7 = 5;
// 	printf("ft_strncmp: %d\n", ft_strncmp(s13, s14, n7));
// 	printf("   strncmp: %d\n", strncmp(s13, s14, n7));

// 	char *s15 = "";
// 	char *s16 = "";
// 	size_t n8 = 5;
// 	printf("ft_strncmp: %d\n", ft_strncmp(s15, s16, n8));
// 	printf("   strncmp: %d\n", strncmp(s15, s16, n8));

// 	return (0);
// }