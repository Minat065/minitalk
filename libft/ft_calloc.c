/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 06:22:36 by mirokugo          #+#    #+#             */
/*   Updated: 2024/05/07 07:10:40 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*ptr;
	long long	i;

	i = count * size;
	if (i == 0)
		i = 1;
	else if (i / size != count)
		return (NULL);
	ptr = malloc(i);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, i);
	return (ptr);
}

/* #include <libc.h>
#include <stdio.h>

int	main(void)
{
	int *ptr;
	int *ptr2;

	ptr = (int *)calloc(5, sizeof(int));
	ptr2 = (int *)ft_calloc(5, sizeof(int));
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", ptr[i]);
		printf("%d\n", ptr2[i]);
	}
	free(ptr);
	free(ptr2);

	return (0);
} */