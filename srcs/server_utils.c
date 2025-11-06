/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:05:37 by mirokugo          #+#    #+#             */
/*   Updated: 2025/11/06 22:36:55 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

int	process_bit(int sig)
{
	if (sig == SIGUSR1)
		g_data.current_char = (g_data.current_char << 1) | 0;
	else
		g_data.current_char = (g_data.current_char << 1) | 1;
	g_data.bit_count++;
	return (g_data.bit_count == 8);
}

int	handle_utf8_byte(char byte, char *utf8_buffer,
	int *expected_len, int *received_len)
{
	if (*received_len == 0)
		*expected_len = get_utf8_length((unsigned char)byte);
	else if (!is_utf8_continuation((unsigned char)byte))
	{
		*received_len = 0;
		*expected_len = get_utf8_length((unsigned char)byte);
	}
	utf8_buffer[(*received_len)++] = byte;
	return (*received_len == *expected_len);
}

void	send_acknowledgment(pid_t client_pid, int is_final)
{
	if (is_final)
	{
		kill(client_pid, SIGUSR1);
		g_data.client_pid = 0;
	}
	else
	{
		kill(client_pid, SIGUSR2);
	}
}
