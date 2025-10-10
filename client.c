/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 02:28:01 by mirokugo          #+#    #+#             */
/*   Updated: 2025/10/11 02:45:24 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include "libft/libft.h"

void send_bit(pid_t pid, int bit)
{
		if (bit == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
}

int main(int argc, char **argv)
{
	int bit;
	pid_t server_pid;

	if (argc != 3)
		return (1);

	bit = ft_atoi(argv[2]);
	server_pid = ft_atoi(argv[1]);
	send_bit(server_pid, bit);
	return (0);
}
