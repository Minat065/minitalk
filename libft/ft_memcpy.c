/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 23:28:08 by mirokugo          #+#    #+#             */
/*   Updated: 2024/05/03 17:40:15 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

// int	main(void)
// {
// 	char s[10] = "123456789";
// 	char s2[10] = "123456789";
// 	printf("ft_memcpy: %s\n", ft_memcpy(s, "abc", 5));
// 	printf("memcpy: %s\n", memcpy(s2, "abc", 5));

// 	printf("ft_memcpy: %s\n", ft_memcpy("", "", 3));
// 	printf("memcpy: %s\n", memcpy("", "", 3));

// 	return (0);
// }