/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_astrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:40:48 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/30 16:14:37 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 * Return:
 *  Number of strings in **arrstr
 *
 */

int	ft_astrlen(char **arrstr)
{
	int	i;

	i = 0;
	while (arrstr && *arrstr)
	{
		arrstr++;
		i++;
	}
	return (i);
}
