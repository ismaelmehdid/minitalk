/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:53:50 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/18 18:55:24 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	signal_handler(int signum)
{
	(void)signum;
	write (1, "Message successfully received !\n", 33);
	exit(EXIT_SUCCESS);
}

static void	send_signals(int pid, char *str)
{
	int	i;
	int	j;
	int	lenght;

	j = 0;
	i = 0;
	if (!str)
		return ;
	lenght = ft_strlen(str);
	while (i <= lenght)
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

static int	is_pid(char *pid)
{
	int	i;

	i = 0;
	if (!pid)
		return (0);
	while (pid[i])
	{
		if (pid[i] > '9' || pid[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	(void)argc;
	server_pid = 0;
	if (argc != 3 || !is_pid(argv[1]))
	{
		ft_printf("\x1B[31mBad arguments: \x1B[32m./programName PID message\n");
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	signal(SIGUSR1, signal_handler);
	send_signals(server_pid, argv[2]);
	pause();
	return (0);
}
