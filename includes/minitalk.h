/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 22:39:57 by mirokugo          #+#    #+#             */
/*   Updated: 2025/11/06 22:50:37 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include "../libft/libft.h"

typedef struct s_data
{
	volatile unsigned char		current_char;
	volatile int				bit_count;
	volatile pid_t				client_pid;
}							t_data;

extern t_data	g_data;
extern volatile sig_atomic_t	g_ack_received;

int		get_utf8_length(unsigned char c);
int		is_utf8_continuation(unsigned char c);
int		process_bit(int sig);
int		handle_utf8_byte(char byte, char *utf8_buffer,
			int *expected_len, int *received_len);
void	send_acknowledgment(pid_t client_pid, int is_final);
void	signal_handler(int sig, siginfo_t *info, void *context);
void	bit_ack_handler(int sig);
void	final_ack_handler(int sig);
void	send_bit(pid_t pid, int bit);
void	send_char(pid_t pid, char c);
void	send_string(pid_t server_pid, char *str);

#endif