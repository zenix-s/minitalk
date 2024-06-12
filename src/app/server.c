/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:31:03 by serferna          #+#    #+#             */
/*   Updated: 2024/06/07 23:10:28 by serferna         ###   ########.fr       */
/*                                                                            */ /* ************************************************************************** */

#include "../minitalk.h"
#include <signal.h>
#include <unistd.h>

t_bit_buffer	g_bit_buffer = {0, 0};

static void	signal_handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (sig == SIGUSR1)
	{
		g_bit_buffer.byte |= (0 << g_bit_buffer.bit);
	}
	else if (sig == SIGUSR2)
	{
		g_bit_buffer.byte |= (1 << g_bit_buffer.bit);
	}
	g_bit_buffer.bit++;
	if (g_bit_buffer.bit >= 8)
	{
		if (g_bit_buffer.byte != 0)
		{
			write(1, &g_bit_buffer.byte, 1);
		}
		g_bit_buffer.byte = 0;
		g_bit_buffer.bit = 0;
	}
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

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Id del servidor: %d\n", pid);
	while (1)
	{
		init_sigaction();
	}
	return (0);
}
