/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:58:30 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/15 22:12:08 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	//pid_t	pid;

	//pid = 0;
	if (argc != 3 || !isPid(argv[1]))
	{
		ft_printf("\x1B[31mBad arguments: \x1B[32m./programName PID message\n");
		exit(EXIT_FAILURE);
	}
	//pid = ft_atoi(argv[1]);
}