/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 02:28:01 by mirokugo          #+#    #+#             */
/*   Updated: 2025/10/13 22:14:28 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_data	g_data;

void	ack_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("Message received by server!\n");
		exit(0);
	}
}

void	send_bit(pid_t pid, int bit)
{
	if (bit == 1)
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
	usleep(500);
}

void	send_pid(pid_t server_pid, pid_t client_pid)
{
	int	digit;

	digit = 31;
	while (digit >= 0)
	{
		send_bit(server_pid, (client_pid >> digit) & 1);
		digit--;
	}
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
	g_data.client_pid = getpid();

	if (argc != 3)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		ft_printf("Note: Use quotes for messages with spaces\n");
		ft_printf("Example: ./client_bonus 12345 \"Hello World\"\n");
		return (1);
	}

	g_data.server_pid = ft_atoi(argv[1]);
	signal(SIGUSR1, ack_handler);
	send_pid(g_data.server_pid, g_data.client_pid);
	send_string(g_data.server_pid, argv[2]);

	pause();
	return (0);
}
