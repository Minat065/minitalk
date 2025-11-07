/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 01:36:14 by mirokugo          #+#    #+#             */
/*   Updated: 2025/11/08 03:56:24 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	is_utf8_continuation(unsigned char c)
{
	return ((c & 0xC0) == 0x80);
}

int	handle_utf8_byte(char byte, char *utf8_buffer,
	int *expected_len, int *received_len)
{
	if (*received_len == 0)
		*expected_len = get_utf8_length((unsigned char)byte);
	else if (!is_utf8_continuation((unsigned char)byte))
	{
		*received_len = 0;
		*expected_len = get_utf8_length((unsigned char)byte);
	}
	utf8_buffer[(*received_len)++] = byte;
	return (*received_len == *expected_len);
}

int	get_utf8_length(unsigned char c)
{
	if ((c & 0x80) == 0x00)
		return (1);
	if ((c & 0xE0) == 0xC0)
		return (2);
	if ((c & 0xF0) == 0xE0)
		return (3);
	if ((c & 0xF8) == 0xF0)
		return (4);
	return (1);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				server_pid;

	server_pid = getpid();
	ft_printf("%d\n", (int)server_pid);
	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Error: sigaction for SIGUSR1 failed\n");
		return (1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error: sigaction for SIGUSR2 failed\n");
		return (1);
	}
	while (1)
		pause();
	return (0);
}
