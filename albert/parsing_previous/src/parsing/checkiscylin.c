/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkiscylin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:18:34 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/30 16:19:13 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define PLUS 1

int	checkiscylin(char **aelement)
{
	if (ft_astrlen(aelement) == 6)
		if (iscoordinatestr(aelement[1]) && isorientnormal(aelement[2]) && \
				isstrsgnfloat(aelement[3], PLUS) && \
				isstrsgnfloat(aelement[4], PLUS) && isrgbstr(aelement[5]))
			return (VALID_ELEMENT);
	return (ERR_IN_FORMAT);
}
