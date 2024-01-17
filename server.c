/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:58:13 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/17 19:35:49 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned int	g_current_byte = 0;

void	reset_static(int *bit_count, int *pid_byte_count, pid_t *client_pid)
{
	*bit_count = 0;
	*pid_byte_count = 0;
	*client_pid = 0;
}

void	send_signals(pid_t pid, char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		j = 0;
		while (j < 8)
		{
			if ((str[i] >> (7 - j)) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(1);
			j++;
		}
		i++;
	}
}

void	signal_handler(int signum)
{
	static int		bit_count;
	static int		pid_byte_count;
	static pid_t	client_pid;

	if (signum == SIGUSR1)
		g_current_byte |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		if (pid_byte_count < 4)
		{
			client_pid = (client_pid << 8) | g_current_byte;
			pid_byte_count++;
		}
		else if (g_current_byte == '\0')
		{
			kill(client_pid, SIGUSR1);
			write(1, "\n", 1);
			reset_static(&bit_count, &pid_byte_count, &client_pid);
		}
		else
			write(1, &g_current_byte, 1);
		bit_count = 0;
		g_current_byte = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("┌───────────────────────────────────────────┐\n");
	ft_printf("│Minitalk                                   │\n");
	ft_printf("│Ismael Mehdid                              │\n");
	ft_printf("│PID : %d                                │\n", pid);
	ft_printf("└───────────────────────────────────────────┘\n");
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
	{
	}
}
