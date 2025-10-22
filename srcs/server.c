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

int	get_utf8_length(unsigned char c)
{
	if ((c & 0x80) == 0x00)
		return (1);
	if ((c & 0xE0) == 0xC0)
		return (2);
	if ((c & 0xF0) == 0xE0)
		return (3);
	if ((c & 0xF8) == 0xF0)
		return (4);
	return (1);
}

int	is_utf8_continuation(unsigned char c)
{
	return ((c & 0xC0) == 0x80);
}

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static char	utf8_buffer[4];
	static int	expected_len = 0;
	static int	received_len = 0;

	(void)context;
	if (g_data.client_pid == 0)
		g_data.client_pid = info->si_pid;
	if (info->si_pid != g_data.client_pid)
		return ;
	if (sig == SIGUSR1)
		g_data.current_char = (g_data.current_char << 1) | 0;
	else
		g_data.current_char = (g_data.current_char << 1) | 1;
	g_data.bit_count++;
	if (g_data.bit_count == 8)
	{
		if (received_len == 0)
			expected_len = get_utf8_length((unsigned char)g_data.current_char);
		else if (!is_utf8_continuation((unsigned char)g_data.current_char))
		{
			received_len = 0;
			expected_len = get_utf8_length((unsigned char)g_data.current_char);
		}
		utf8_buffer[received_len++] = g_data.current_char;
		if (received_len == expected_len)
		{
			write(1, utf8_buffer, received_len);
			if (received_len == 1 && utf8_buffer[0] == '\n')
			{
				kill(info->si_pid, SIGUSR1);
				g_data.client_pid = 0;
			}
			else
				kill(info->si_pid, SIGUSR2);
			received_len = 0;
			expected_len = 0;
		}
		else
			kill(info->si_pid, SIGUSR2);
		g_data.current_char = 0;
		g_data.bit_count = 0;
		return ;
	}
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				server_pid;

	g_data.current_char = 0;
	g_data.bit_count = 0;
	g_data.client_pid = 0;
	server_pid = getpid();
	ft_printf("%d\n", (int)server_pid);
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
