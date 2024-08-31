/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exiterror_line_freemsg.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 08:59:54 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/31 09:06:35 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minirt.h"

void	exiterror_line_freemsg(char *line, char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(line, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	free(msg);
	exit (EXIT_FAILURE);
}

