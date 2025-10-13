/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 01:36:14 by mirokugo          #+#    #+#             */
/*   Updated: 2025/10/13 22:05:37 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_data	g_data;

void signal_handler(int sig)
{
	static pid_t temp_pid = 0;

	if (g_data.client_pid == 0)
	{
		if (sig == SIGUSR1)
			temp_pid = (temp_pid << 1) | 0;
		else
			temp_pid = (temp_pid << 1) | 1;
		
		g_data.bit_count++;
		
		if (g_data.bit_count == 32)
		{
			g_data.client_pid = temp_pid;
			temp_pid = 0;  // ← ここでリセット！
			g_data.bit_count = 0;
			write(1, "PID OK\n", 7);
		}
	}
	else
	{
		if (sig == SIGUSR1)
			g_data.current_char = (g_data.current_char << 1) | 0;
		else
			g_data.current_char = (g_data.current_char << 1) | 1;
		
		g_data.bit_count++;
		
		if (g_data.bit_count == 8)
		{
			if (g_data.current_char == '\n')
			{
				write(1, "\n", 1);
				kill(g_data.client_pid, SIGUSR1);
				g_data.client_pid = 0;  // 次のクライアントに備える
			}
			else
				write(1, &g_data.current_char, 1);
			
			g_data.current_char = 0;
			g_data.bit_count = 0;
		}
	}
}

int	main(void)
{
	g_data.server_pid = getpid();
	g_data.current_char = 0;

	ft_printf("%d\n", (int)g_data.server_pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);

	while (1)
		pause();
	return (0);
}
