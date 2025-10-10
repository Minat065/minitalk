/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 04:43:58 by mirokugo          #+#    #+#             */
/*   Updated: 2024/05/03 17:50:49 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0' || needle == NULL)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && haystack[i + j] == needle[j] && i + j < len)
			j++;
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	printf("1\n");
// 	char *haystack = "Hello, World!";
// 	char *needle = "World";
// 	char *ret = ft_strnstr(haystack, needle, 13);
// 	printf("ft_strnstr: %s\n", ret);
// 	ret = strnstr(haystack, needle, 13);
// 	printf("strnstr: %s\n", ret);

// 	printf("2\n");
// 	ret = ft_strnstr(haystack, needle, 0);
// 	printf("ft_strnstr: %s\n", ret);
// 	ret = strnstr(haystack, needle, 0);
// 	printf("strnstr: %s\n", ret);

// 	printf("3\n");
// 	ret = ft_strnstr(haystack, needle, 1);
// 	printf("ft_strnstr: %s\n", ret);
// 	ret = strnstr(haystack, needle, 1);
// 	printf("strnstr: %s\n", ret);

// 	printf("4\n");
// 	ret = ft_strnstr("", needle, 5);
// 	printf("ft_strnstr: %s\n", ret);
// 	ret = strnstr("", needle, 5);
// 	printf("strnstr: %s\n", ret);

// 	printf("5\n");
// 	ret = ft_strnstr(haystack, "", 5);
// 	printf("ft_strnstr: %s\n", ret);
// 	ret = strnstr(haystack, "", 5);
// 	printf("strnstr: %s\n", ret);

// 	printf("6\n");
// 	ret = ft_strnstr("", "", 5);
// 	printf("ft_strnstr: %s\n", ret);
// 	ret = strnstr("", "", 5);
// 	printf("strnstr: %s\n", ret);

// 	printf("7\n");
// 	ret = ft_strnstr("", "", 0);
// 	printf("ft_strnstr: %s\n", ret);
// 	ret = strnstr("", "", 0);
// 	printf("strnstr: %s\n", ret);

// 	printf("8\n");
// 	ret = ft_strnstr(haystack, "", 0);
// 	printf("ft_strnstr: %s\n", ret);
// 	ret = strnstr(haystack, "", 0);
// 	printf("strnstr: %s\n", ret);

// 	printf("9\n");
// 	ret = ft_strnstr("", needle, 0);
// 	printf("ft_strnstr: %s\n", ret);
// 	ret = strnstr("", needle, 0);
// 	printf("strnstr: %s\n", ret);

// 	printf("10\n");
// 	ret = ft_strnstr(NULL, needle, 5);
// 	printf("ft_strnstr: %s\n", ret);
// 	ret = strnstr(NULL, needle, 5);
// 	printf("strnstr: %s\n", ret);

// 	printf("11\n");
// 	ret = ft_strnstr(haystack, NULL, 5);
// 	printf("ft_strnstr: %s\n", ret);
// 	ret = strnstr(haystack, NULL, 5);
// 	printf("strnstr: %s\n", ret);

// 	printf("12\n");
// 	ret = ft_strnstr(NULL, NULL, 5);
// 	printf("ft_strnstr: %s\n", ret);
// 	ret = strnstr(NULL, NULL, 5);
// 	printf("strnstr: %s\n", ret);

// 	printf("13\n");
// 	ret = ft_strnstr(NULL, NULL, 0);
// 	printf("ft_strnstr: %s\n", ret);
// 	ret = strnstr(NULL, NULL, 0);
// 	printf("strnstr: %s\n", ret);

// 	printf("14\n");
// 	ret = ft_strnstr(haystack, NULL, 0);
// 	printf("ft_strnstr: %s\n", ret);
// 	ret = strnstr(haystack, NULL, 0);
// 	printf("strnstr: %s\n", ret);

// 	printf("15\n");
// 	ret = ft_strnstr(NULL, needle, 0);
// 	printf("ft_strnstr: %s\n", ret);
// 	ret = strnstr(NULL, needle, 0);
// 	printf("strnstr: %s\n", ret);

// 	return (0);
// }