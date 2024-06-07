/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:31:11 by serferna          #+#    #+#             */
/*   Updated: 2024/06/07 11:31:57 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

// write, getpid, kill, pause
# include <unistd.h>

// signal, sigaction, sigemptyset, sigaddset
# include <signal.h>

// ft_printf
# include "./lib/printf/src/ft_printf.h"

typedef struct s_bit_buffer
{
	int	byte;
	int	bit;
}		t_bit_buffer;

typedef enum s_bool
{
	FALSE,
	TRUE
}		t_bool;

#endif
