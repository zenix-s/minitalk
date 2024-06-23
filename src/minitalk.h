/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:31:11 by serferna          #+#    #+#             */
/*   Updated: 2024/06/24 01:05:55 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

// signal, sigaction, sigemptyset, sigaddset
# include <signal.h>

// ft_printf
//# include "./lib/printf/src/ft_printf.h"
# include "./lib/libft/libft.h"

typedef struct s_bit_buffer
{
	int	byte;
	int	bit;
}		t_bit_buffer;


#endif
