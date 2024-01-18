/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:58:13 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/18 18:59:25 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned int	g_current_byte = 0;

static void	signal_handler(int signum)
{
	static int		bit_count;

	if (signum == SIGUSR1)
		g_current_byte |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		if (g_current_byte == '\0')
			write(1, "\n", 1);
		else
			write(1, &g_current_byte, 1);
		bit_count = 0;
		g_current_byte = 0;
	}
}

int	main(void)
{
	pid_t				pid;

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
	return (0);
}
