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


# include <signal.h>
# include "../lib/libft/libft.h"

int g_confirmation = 0;

void	error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

t_bool	check_args(const int argc, const char **argv)
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
	int i;

	bit = 0;
	while (bit < 8)
	{
		g_confirmation = 0;
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
		i = 0;
		while (i++ <= 1000)
		{
			if (g_confirmation)
                break;
            usleep(100);
		}
		if (!g_confirmation)
			error("No confirmation has been recived");
		bit++;
	}
}

static void	signal_handler(const int sig)
{
	(void)sig;
	g_confirmation = 1;
}

void send_message(const char** argv, const pid_t server_pid)
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

int    main(const int argc, const char **argv)
{
	struct sigaction	sa;
	pid_t server_pid;

	if (!check_args(argc, argv))
		return (ft_putstr_fd("Error\n", 2), 1);
	sa.sa_handler = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, 0) == -1)
		return (ft_putstr_fd("Error\n", 2), 1);
	server_pid = (pid_t)ft_atoi(argv[1]);
	send_message(argv, server_pid);
    return 0;
}
