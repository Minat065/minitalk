/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:33:04 by mirokugo          #+#    #+#             */
/*   Updated: 2024/05/03 17:49:43 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*c;
	int		i;

	if (*s == '\0')
	{
		c = (char *)malloc(sizeof(char) * 1);
		if (!c)
			return (NULL);
		c[0] = '\0';
		return (c);
	}
	if (!*s || !f)
		return (NULL);
	c = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!c)
		return (NULL);
	i = 0;
	while (s[i])
	{
		c[i] = f(i, s[i]);
		i++;
	}
	c[i] = '\0';
	return (c);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*s;
// 	char	*c;

// 	s = "hello";
// 	c = ft_strmapi(s, function);
// 	printf("%s\n", c);
// 	return (0);
// }
