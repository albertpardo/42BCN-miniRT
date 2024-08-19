/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isoklight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:49:50 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/19 17:31:33 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// RGB is only used in bonus . But must be for mandatory

int	isoklight(char **aelement)
{
	if (ft_astrlen(aelement) == 4)
	{
		if (iscoordinatestr(aelement[1]) && isstrfloatcerone(aelement[2]) && \
				isrgbstr(aelement[3]))
			return (1);
	}
	return (0);
}
