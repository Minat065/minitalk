/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:21:13 by mirokugo          #+#    #+#             */
/*   Updated: 2024/05/03 17:41:21 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char s[10] = "123456789";
// 	char s2[10] = "123456789";
// 	printf("ft_memset: %s\n", ft_memset(s, 'a', 5));
// 	printf("memset: %s\n", memset(s2, 'a', 5));
// 	return (0);
// }
