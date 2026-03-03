/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 02:28:01 by mirokugo          #+#    #+#             */
/*   Updated: 2025/11/08 03:25:56 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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
