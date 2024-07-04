/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 01:13:32 by serferna          #+#    #+#             */
/*   Updated: 2024/07/04 00:20:00 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int			g_confirmation = 0;

void	wait_confirmation(void)
{
	int	i;

	i = 0;
	while (i++ <= 1000)
	{
		if (g_confirmation)
			break ;
		usleep(100);
	}
	if (!g_confirmation)
		exit_error("No confirmation has been recived");
}

void	send_signal(const int pid, const char c)
{
	int	bit;

	bit = -1;
	while (++bit < 8)
	{
		g_confirmation = 0;
		if (c & (1 << bit))
		{
			if (kill(pid, SIGUSR2) == -1)
				exit_error("failed to send signal");
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				exit_error("failed to send signal");
		}
		wait_confirmation();
	}
}

static void	signal_handler(const int sig)
{
	(void)sig;
	g_confirmation = 1;
}

void	send_message(const pid_t server_pid, const char **argv)
{
	int	byte;

	byte = 0;
	while (argv[2][byte])
	{
		send_signal(server_pid, argv[2][byte]);
		byte++;
	}
	send_signal(server_pid, '\0');
}

int	main(const int argc, const char **argv)
{
	struct sigaction	sa;
	pid_t				server_pid;

	if (!check_args(argc, argv))
		return (exit_error("Error\n"), 1);
	sa.sa_handler = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, 0) == -1)
		return (exit_error("Error\n"), 1);
	server_pid = ft_atoi(argv[1]);
	send_message(server_pid, argv);
	return (0);
}
