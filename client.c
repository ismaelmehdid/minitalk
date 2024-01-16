/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:58:30 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/16 23:08:56 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signals(int pid, char *str)
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
			j++;
		}
		i++;
	}
}

int	isPid(char *pid)
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

int main(int argc, char **argv)
{
	pid_t	pid;

	pid = 0;
	if (argc != 3 || !isPid(argv[1]))
	{
		ft_printf("\x1B[31mBad arguments: \x1B[32m./programName PID message\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	send_signals(pid, argv[2]);
}