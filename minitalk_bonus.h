/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 21:05:14 by mirokugo          #+#    #+#             */
/*   Updated: 2025/10/13 21:09:36 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include "./libft/libft.h"

typedef struct  s_data
{
	char	current_char;
	int		bit_count;
    pid_t  client_pid;
    pid_t  server_pid;
}		t_data;

#endif