/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:58:13 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/18 18:21:09 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned int	g_current_byte = 0;

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int		bit_count;
	static pid_t	client_pid;

	(void)context;
	client_pid = info->si_pid;
	if (signum == SIGUSR1)
		g_current_byte |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		if (g_current_byte == '\0')
		{
			kill(client_pid, SIGUSR1);
			write(1, "\n", 1);
		}
		else
			write(1, &g_current_byte, 1);
		bit_count = 0;
		g_current_byte = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("┌───────────────────────────────────────────┐\n");
	ft_printf("│Minitalk                                   │\n");
	ft_printf("│Ismael Mehdid                              │\n");
	ft_printf("│PID : %d                                │\n", pid);
	ft_printf("└───────────────────────────────────────────┘\n");
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	while (1)
	{
	}
	return (0);
}
