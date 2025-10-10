/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 04:11:30 by mirokugo          #+#    #+#             */
/*   Updated: 2024/05/03 17:36:56 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		if (*ptr == (unsigned char)c)
			return (ptr);
		ptr++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char *s = "Hello, World!";
// 	int c = 'W';
// 	size_t n = 5;
// 	printf("ft_memchr: %s\n", ft_memchr(s, c, n));
// 	printf("   memchr: %s\n", memchr(s, c, n));

// 	char *s2 = "Hello, World!";
// 	int c2 = 'W';
// 	size_t n2 = 10;
// 	printf("ft_memchr: %s\n", ft_memchr(s2, c2, n2));
// 	printf("   memchr: %s\n", memchr(s2, c2, n2));

// 	char *s3 = "Hello, World!";
// 	int c3 = 'H';
// 	size_t n3 = 15;
// 	printf("ft_memchr: %s\n", ft_memchr(s3, c3, n3));
// 	printf("   memchr: %s\n", memchr(s3, c3, n3));

// 	char *s4 = "Hello, World!";
// 	int c4 = 'W';
// 	size_t n4 = 0;
// 	printf("ft_memchr: %s\n", ft_memchr(s4, c4, n4));
// 	printf("   memchr: %s\n", memchr(s4, c4, n4));

// 	char *s5 = "Hello, World!";
// 	int c5 = 'W';
// 	size_t n5 = 1;
// 	printf("ft_memchr: %s\n", ft_memchr(s5, c5, n5));
// 	printf("   memchr: %s\n", memchr(s5, c5, n5));

// 	char *s6 = "Hello, World!";
// 	int c6 = 'H';
// 	size_t n6 = 5;
// 	printf("ft_memchr: %s\n", ft_memchr(s6, c6, n6));
// 	printf("   memchr: %s\n", memchr(s6, c6, n6));

// 	return (0);
// }