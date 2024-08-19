/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isokcylin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:15:24 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/19 17:31:24 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

#define PLUS 1

int	isokcylin(char **aelement)
{
	if (ft_astrlen(aelement) == 6)
		if (iscoordinatestr(aelement[1]) && isorientnormal(aelement[2]) && \
				isstrsgnfloat(aelement[3], PLUS) && \
				isstrsgnfloat(aelement[4], PLUS) && isrgbstr(aelement[5]))
			return (1);
	return (0);
}
