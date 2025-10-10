/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 04:54:16 by mirokugo          #+#    #+#             */
/*   Updated: 2024/05/03 17:47:22 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	dst_len = 0;
	src_len = 0;
	if (dst)
		dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	if (dstsize > dst_len + 1)
	{
		i = dst_len;
		j = 0;
		while (src[j] && i < dstsize - 1)
			dst[i++] = src[j++];
		dst[i] = '\0';
	}
	return (dst_len + src_len);
}

// int	main(void)
// {
// 	size_t	dstsize;
// 	size_t	ret1;
// 	size_t	ret2;

// 	dstsize = 11;
// 	ret1 = strlcat(NULL, "Hello", dstsize);
// 	ret2 = ft_strlcat(NULL, "Hello", dstsize);
// 	//	printf("strlcat: %zu\n", ret1);
// 	// printf("ft_strlcat: %zu\n", ret2);
// 	if (ret1 == ret2)
// 		printf("OK\n");
// 	else
// 		printf("NG\n");
// 	ret1 = strlcat(NULL, NULL, dstsize);
// 	ret2 = ft_strlcat(NULL, NULL, dstsize);
// 	//	printf("strlcat: %zu\n", ret1);
// 	// printf("ft_strlcat: %zu\n", ret2);
// 	if (ret1 == ret2)
// 		printf("OK\n");
// 	else
// 		printf("NG\n");
// 	ret1 = strlcat("Hello", NULL, dstsize);
// 	ret2 = ft_strlcat("Hello", NULL, dstsize);
// 	//	printf("strlcat: %zu\n", ret1);
// 	// printf("ft_strlcat: %zu\n", ret2);
// 	if (ret1 == ret2)
// 		printf("OK\n");
// 	else
// 		printf("NG\n");
// 	return (0);
// }
