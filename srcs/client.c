/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 02:28:01 by mirokugo          #+#    #+#             */
/*   Updated: 2025/10/16 23:33:51 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include "libft.h"

volatile sig_atomic_t	g_ack_received = 0;

void	ack_handler(int sig)
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
	int digit;

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

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc != 3)
	{
		ft_printf("Error: Invalid arguments\n");
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_printf("Error: Invalid PID\n");
		return (1);
	}
	signal(SIGUSR1, ack_handler);
	send_string(server_pid, argv[2]);
	return (0);
}
