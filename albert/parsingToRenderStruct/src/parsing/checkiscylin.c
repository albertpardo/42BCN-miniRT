/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkiscylin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:18:34 by apardo-m          #+#    #+#             */
/*   Updated: 2024/09/01 09:36:00 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

#define PLUS 1

int	checkiscylin(char **aelement)
{
	if (ft_astrlen(aelement) == 6)
		if (iscoordinatestr(aelement[1]) && isstrsgnfloat(aelement[3], PLUS) && \
				isstrsgnfloat(aelement[4], PLUS) && isrgbstr(aelement[5]))
			return (checkisnormal(aelement[2]));
	return (ERR_IN_FORMAT);
}
