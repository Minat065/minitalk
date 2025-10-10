/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:32:17 by mirokugo          #+#    #+#             */
/*   Updated: 2024/05/03 17:34:31 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	for (int i = 0; i < 128; i++)
// 	{
// 		if (isprint(i) != ft_isprint(i))
// 			printf("NG\n");
// 	}
// 	printf("OK\n");
// 	return (0);
// }