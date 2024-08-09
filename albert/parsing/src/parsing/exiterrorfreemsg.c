/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exiterrorfreemsg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:30:23 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/09 09:59:26 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	exiterrorfreemsg(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("The next element line has information errors:\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	free(msg);
	exit (EXIT_FAILURE);
}
