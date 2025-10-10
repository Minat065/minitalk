/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:23:26 by mirokugo          #+#    #+#             */
/*   Updated: 2024/05/03 17:33:47 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	int i = -1;
// 	while (i < 130)
// 	{
// 		printf("c: %c, ft_isascii: %d, isascii: %d\n", i, ft_isascii(i),
// 			isascii(i));
// 		i++;
// 	}
// 	return (0);
// }