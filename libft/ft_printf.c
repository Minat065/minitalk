/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:31:59 by mirokugo          #+#    #+#             */
/*   Updated: 2025/11/04 21:17:09 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(unsigned int n, char *base, int *count_char)
{
	unsigned int	base_len;

	base_len = ft_strlen(base);
	if (n >= base_len)
	{
		ft_putnbr_base(n / base_len, base, count_char);
		ft_putchar_fd(base[n % base_len], 1, count_char);
	}
	else
		ft_putchar_fd(base[n], 1, count_char);
}

void	ptr_to_hex(void *ptr, char *buffer)
{
	unsigned long	addr;
	char			temp[sizeof(void *) * 2 + 1];
	int				digit;
	int				i;
	int				start;

	i = 0;
	start = 0;
	addr = (unsigned long)ptr;
	while (i < (int) sizeof(void *) * 2)
	{
		digit = (addr >> ((sizeof(void *) * 2 - 1 - i) * 4)) & 0xf;
		if (digit < 10)
			temp[i] = '0' + digit;
		else
			temp[i] = 'a' + digit - 10;
		i++;
	}
	temp[i] = '\0';
	while (temp[start] == '0' && start < (int) sizeof(void *) * 2 - 1)
		start++;
	ft_strlcpy(buffer, temp + start, sizeof(void *) * 2 - start + 1);
}

void	ft_exist_formt_1(const char *format, va_list ap, int *count_char)
{
	char	*str;

	if (*format == 'd' || *format == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1, count_char);
	else if (*format == 's')
	{
		str = va_arg(ap, char *);
		if (str == NULL)
			ft_putstr_fd("(null)", 1, count_char);
		else
			ft_putstr_fd(str, 1, count_char);
	}
	else if (*format == 'c')
		ft_putchar_fd(va_arg(ap, int), 1, count_char);
	else if (*format == '%')
		ft_putchar_fd('%', 1, count_char);
}

void	ft_exist_formt_2(const char *format, va_list ap, int *count_char)
{
	char	buffer[16];
	void	*ptr;

	if (*format == 'u')
		ft_putnbr_base(va_arg(ap, unsigned int),
			"0123456789", count_char);
	else if (*format == 'x')
		ft_putnbr_base(va_arg(ap, unsigned int),
			"0123456789abcdef", count_char);
	else if (*format == 'X')
		ft_putnbr_base(va_arg(ap, unsigned int),
			"0123456789ABCDEF", count_char);
	else if (*format == 'p')
	{
		ptr = va_arg(ap, void *);
		if (ptr == NULL)
			ft_putstr_fd("(nil)", 1, count_char);
		else
		{
			ft_putstr_fd("0x", 1, count_char);
			ptr_to_hex(ptr, buffer);
			ft_putstr_fd(buffer, 1, count_char);
		}
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count_char;

	va_start(ap, format);
	count_char = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i' || *format == 's'
				|| *format == 'c' || *format == '%')
				ft_exist_formt_1(format, ap, &count_char);
			else if (*format == 'u' || *format == 'x' || *format == 'X'
				|| *format == 'p')
				ft_exist_formt_2(format, ap, &count_char);
		}
		else
			ft_putchar_fd(*format, 1, &count_char);
		format++;
	}
	va_end(ap);
	return (count_char);
}
