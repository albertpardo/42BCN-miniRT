/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exiterror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:16:23 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/19 17:27:23 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	exiterror(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	if (errno != 0)
		perror(msg);
	else
	{
		ft_putstr_fd(msg, 2);
		ft_putstr_fd("\n", 2);
	}
	exit (EXIT_FAILURE);
}
