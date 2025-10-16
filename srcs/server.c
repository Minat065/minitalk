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
#include <sys/types.h>
#include "libft.h"

typedef struct	s_data
{
	char	current_char;
	int		bit_count;
	pid_t	client_pid;
}		t_data;

t_data	g_data;

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	g_data.client_pid = info->si_pid;
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
	kill(g_data.client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				server_pid;

	server_pid = getpid();
	ft_printf("%d\n", (int)server_pid);
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
