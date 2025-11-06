/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 22:38:10 by mirokugo          #+#    #+#             */
/*   Updated: 2025/11/06 22:54:58 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bit_ack_handler(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

void	send_bit(pid_t pid, int bit)
{
	g_ack_received = 0;
	if (bit == 1)
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
	while (!g_ack_received)
		usleep(50);
}

void	send_char(pid_t pid, char c)
{
	int		digit;

	digit = 7;
	while (digit >= 0)
	{
		send_bit(pid, (c >> digit) & 1);
		digit--;
	}
}

void	send_string(pid_t server_pid, char *str)
{
	while (*str)
	{
		send_char(server_pid, *str);
		str++;
	}
	send_char(server_pid, '\n');
}
