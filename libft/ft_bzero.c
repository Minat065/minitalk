/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 22:10:50 by mirokugo          #+#    #+#             */
/*   Updated: 2024/05/03 17:59:40 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char s[10] = "123456789";
	char s2[10] = "123456789";
	ft_bzero(s, 5);
	bzero(s2, 5);
	printf("ft_bzero: %s\n", s);
	printf("bzero: %s\n", s2);
	return (0);
} */