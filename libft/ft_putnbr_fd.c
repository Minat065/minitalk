/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:31:53 by mirokugo          #+#    #+#             */
/*   Updated: 2024/06/23 18:20:27 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	putmin(int nb, int fd, int *count_char)
{
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		*count_char += 11;
	}
	else if (nb == 0)
	{
		write(fd, "0", 1);
		*count_char += 1;
	}
}

int	ft_putnbr_fd(int nb, int fd, int *count_char)
{
	int		i;
	char	nmb[10];

	putmin(nb, fd, count_char);
	if (nb == -2147483648 || nb == 0)
		return (*count_char);
	else if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar_fd('-', fd, count_char);
	}
	i = 0;
	while (nb != 0)
	{
		nmb[i] = (nb % 10) + 48;
		nb = nb / 10;
		i++;
	}
	i--;
	while (i >= 0)
		ft_putchar_fd(nmb[i--], fd, count_char);
	return (*count_char);
}

// int	main(void)
// {
// 	int	count_char;

// 	count_char = 0;
// 	ft_putnbr_fd(42, 1, &count_char);
// 	ft_putchar_fd('\n', 1, &count_char);
// 	ft_putnbr_fd(0, 1, &count_char);
// 	ft_putchar_fd('\n', 1, &count_char);
// 	ft_putnbr_fd(-42, 1, &count_char);
// 	ft_putchar_fd('\n', 1, &count_char);
// 	ft_putnbr_fd(-2147483648, 1, &count_char);
// 	ft_putchar_fd('\n', 1, &count_char);
// 	printf("count_char: %d\n", count_char);
// 	return (0);
// }
