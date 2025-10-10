/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 01:36:14 by mirokugo          #+#    #+#             */
/*   Updated: 2025/10/11 02:49:13 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

void signal_handler(int sig)
{
		if (sig == SIGUSR1)
			printf("0を受信した\n");
		else if (sig == SIGUSR2)
			printf("1を受信した\n");
}

int main()
{
	pid_t server_pid;

	server_pid = getpid();

	printf("%d\n", (int)server_pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);

	while (1)
		pause();
	return 0;
}
