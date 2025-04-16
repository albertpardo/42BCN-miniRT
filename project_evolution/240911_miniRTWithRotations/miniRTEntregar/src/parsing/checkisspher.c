/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkisspher.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:53:24 by apardo-m          #+#    #+#             */
/*   Updated: 2024/09/01 09:37:40 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

#define PLUS 1

int	checkisspher(char **aelement)
{
	if (ft_astrlen(aelement) == 4)
		if (iscoordinatestr(aelement[1]) && \
				isstrsgnfloat(aelement[2], PLUS) && isrgbstr(aelement[3]))
			return (VALID_ELEMENT);
	return (ERR_IN_FORMAT);
}
