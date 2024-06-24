/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 01:13:40 by serferna          #+#    #+#             */
/*   Updated: 2024/06/24 12:31:00 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <signal.h>

# include "../lib/libft/libft.h"


static void	signal_handler(const int sig, siginfo_t *info, void *context)
{
    (void)context;
    ft_printf("Hola: %d from %d\n", sig, (int)info->si_pid);
	kill(info->si_pid, SIGUSR1);
}

void	init_sigaction(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
}

int    main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Id del servidor: %d\n", pid);
	init_sigaction();

	while(1)
		pause();
    return 0;
}
