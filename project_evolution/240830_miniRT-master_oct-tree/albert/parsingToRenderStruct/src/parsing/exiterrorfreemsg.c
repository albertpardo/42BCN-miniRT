/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exiterrorfreemsg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:30:23 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/19 17:27:33 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	exiterrorfreemsg(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(ERR_TYPO_ELEM, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	free(msg);
	exit (EXIT_FAILURE);
}
