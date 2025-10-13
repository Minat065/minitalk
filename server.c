/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 01:36:14 by mirokugo          #+#    #+#             */
/*   Updated: 2025/10/13 18:00:51 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

typedef struct	s_data
{
	char	current_char;
	int		bit_count;
}		t_data;

t_data	g_data;

void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
		g_data.current_char = (g_data.current_char << 1) | 0;
	else
		g_data.current_char = (g_data.current_char << 1) | 1;

	g_data.bit_count++;

	if (g_data.bit_count == 8)
	{
		write(1, &g_data.current_char, 1);
		g_data.current_char = 0;
		g_data.bit_count = 0;
	}
}

int	main(void)
{
	pid_t	server_pid;

	server_pid = getpid();

	printf("%d\n", (int)server_pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);

	while (1)
		pause();
	return (0);
}
