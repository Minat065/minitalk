/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:59:34 by mirokugo          #+#    #+#             */
/*   Updated: 2024/06/23 14:54:46 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd, int *count_char)
{
	if (!s)
		return (0);
	write(fd, s, ft_strlen(s));
	*count_char += ft_strlen(s);
	return (*count_char);
}
