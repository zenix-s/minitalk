/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:31:11 by serferna          #+#    #+#             */
/*   Updated: 2024/06/12 16:01:47 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

// write, getpid, kill, pause
# include <unistd.h>

// sigaction, sigemptyset, sigaddset
# include <signal.h>

// libft
#include "./lib/libft/src/libft.h"

typedef struct s_bit_buffer
{
	int	byte;
	int	bit;
}		t_bit_buffer;


#endif
