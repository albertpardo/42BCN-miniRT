/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkiscamara.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:45:45 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/30 15:59:30 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int checkiscamara(char **aelement)
{
	if (ft_astrlen(aelement) == 4)
	{
		if (iscoordinatestr(aelement[1]) && isorientnormal(aelement[2]) && \
				isfov(aelement[3]))
			return (VALID_ELEMENT);
	}
	return (ERR_IN_FORMAT);
}
