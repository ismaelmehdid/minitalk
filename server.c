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

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("┌───────────────────────────────────────────┐\n");
	ft_printf("│Minitalk                                   │\n");
	ft_printf("│Ismael Mehdid                              │\n");
	ft_printf("│PID : %d                                │\n", pid);
	ft_printf("└───────────────────────────────────────────┘\n");

	while (1)
		sleep(1);

}