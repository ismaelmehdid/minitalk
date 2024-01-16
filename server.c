/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:58:13 by ismaelmehdi       #+#    #+#             */
/*   Updated: s2024/01/15 17:13:04 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char current_byte = 0;
int	bit_count = 0;


void signal_handler2(int signum)
{
	(void)signum;

	bit_count++;
	if (bit_count == 8)
	{
		ft_putchar_fd(current_byte, 1);
		bit_count = 0;
		current_byte = 0;
	}
}
void signal_handler1(int signum)
{
	(void)signum;

	current_byte |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		ft_putchar_fd(current_byte, 1);
		bit_count = 0;
		current_byte = 0;
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
	
	signal(SIGUSR1, signal_handler1);
	signal(SIGUSR2, signal_handler2);

	while (1)
	{
		pause();
	}
}