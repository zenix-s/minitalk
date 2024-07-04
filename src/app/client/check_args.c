/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:49:36 by serferna          #+#    #+#             */
/*   Updated: 2024/07/04 19:49:49 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"

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
