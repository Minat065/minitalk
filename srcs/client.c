/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 02:28:01 by mirokugo          #+#    #+#             */
/*   Updated: 2025/11/08 01:58:33 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_ack_received = 0;

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
	if (server_pid <= 1)
	{
		ft_printf("Error: Invalid PID\n");
		return (1);
	}
	signal(SIGUSR1, bit_ack_handler);
	signal(SIGUSR2, bit_ack_handler);
	send_string(server_pid, argv[2]);
	return (0);
}
