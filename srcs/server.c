/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 01:36:14 by mirokugo          #+#    #+#             */
/*   Updated: 2025/11/06 22:36:34 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_data	g_data;

void	handle_complete_byte(pid_t client_pid, char *utf8_buffer,
		int *expected_len, int *received_len)
{
	int	is_char_complete;

	is_char_complete = handle_utf8_byte(g_data.current_char,
			utf8_buffer, expected_len, received_len);
	if (is_char_complete)
	{
		write(1, utf8_buffer, *received_len);
		send_acknowledgment(client_pid,
			(*received_len == 1 && utf8_buffer[0] == '\n'));
		*received_len = 0;
		*expected_len = 0;
	}
	else
		kill(client_pid, SIGUSR2);
	g_data.current_char = 0;
	g_data.bit_count = 0;
}

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static char	utf8_buffer[4];
	static int	expected_len = 0;
	static int	received_len = 0;

	(void)context;
	if (g_data.client_pid == 0)
		g_data.client_pid = info->si_pid;
	if (info->si_pid != g_data.client_pid)
		return ;
	if (process_bit(sig))
	{
		handle_complete_byte(info->si_pid, utf8_buffer,
			&expected_len, &received_len);
		return ;
	}
	kill(info->si_pid, SIGUSR2);
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
