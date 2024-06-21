/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:30:53 by serferna          #+#    #+#             */
/*   Updated: 2024/06/07 11:30:55 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include <stdlib.h>

void	error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

t_bool	check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
		return (FALSE);
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
			return (FALSE);
		i++;
	}
	if (ft_atoi(argv[1]) <= 0)
		return (FALSE);
	return (TRUE);
}

void	send_signal(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
		{
			if (kill(pid, SIGUSR2) == -1)
				error("Error occurred: failed to send signal");
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				error("Error occurred: failed to send signal");
		}
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	byte;

	if (!check_args(argc, argv))
		error("Error occurred: invalid arguments");
	byte = 0;
	while (argv[2][byte])
	{
		send_signal(ft_atoi(argv[1]), argv[2][byte]);
		byte++;
	}
	send_signal(ft_atoi(argv[1]), '\0');
	return (0);
}
