/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:05:37 by mirokugo          #+#    #+#             */
/*   Updated: 2025/11/08 04:11:05 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_data	g_data;

void	reset_data(void)
{
	g_data.current_char = 0;
	g_data.bit_count = 0;
	g_data.client_pid = 0;
}

int	process_bit(int sig)
{
	if (sig == SIGUSR1)
		g_data.current_char = (g_data.current_char << 1) | 0;
	else
		g_data.current_char = (g_data.current_char << 1) | 1;
	g_data.bit_count++;
	return (g_data.bit_count == 8);
}

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static char	utf8_buffer[4];
	static int	expected_len = 0;
	static int	received_len = 0;

	(void)context;
	(void)info;
	if (g_data.client_pid != 0 && info->si_pid != g_data.client_pid)
	{
		kill(g_data.client_pid, SIGTERM);
		reset_data();
		expected_len = 0;
		received_len = 0;
		g_data.client_pid = info->si_pid;
	}
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

void	send_acknowledgment(pid_t client_pid, int is_final)
{
	if (is_final)
	{
		kill(client_pid, SIGUSR1);
		g_data.client_pid = 0;
	}
	else
	{
		kill(client_pid, SIGUSR2);
	}
}

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
