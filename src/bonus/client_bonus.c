/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 01:13:32 by serferna          #+#    #+#             */
/*   Updated: 2024/06/25 12:30:44 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include <signal.h>

# include "../lib/libft/libft.h"

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
		pause();
		usleep(100);
		bit++;
	}
}

static void	signal_handler(const int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	ft_printf("Hola: %d\n", sig);
}

int    main(const int argc, const char **argv)
{
	(void)argv;
	struct sigaction	sa;
	int	byte;
	int server_id;

	pid_t	pid;

	pid = getpid();
	ft_printf("Id del servidor: %d\n", pid);

	sa.sa_sigaction = &signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);

	if (!check_args(argc, argv))
		error("Error occurred: invalid arguments");
	server_id = ft_atoi(argv[1]);
	byte = 0;
	while (argv[2][byte])
	{
		send_signal(server_id, argv[2][byte]);
		byte++;
	}
	send_signal(server_id, '\0');



	// byte = 0;
	// while (argv[2][byte])
	// {
	// 	send_signal(ft_atoi(argv[1]), argv[2][byte]);
	// 	byte++;
	// }
	// send_signal(ft_atoi(argv[1]), '\0');

	// while(1)
	// 	pause();
    return 0;
}
