/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkislight.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:50:32 by apardo-m          #+#    #+#             */
/*   Updated: 2024/09/01 09:36:37 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

// RGB is only used in bonus . But must be check for mandatory

int	checkislight(char **aelement)
{
	if (ft_astrlen(aelement) == 4)
	{
		if (iscoordinatestr(aelement[1]) && isstrfloatcerone(aelement[2]) && \
				isrgbstr(aelement[3]))
			return (VALID_ELEMENT);
	}
	return (ERR_IN_FORMAT);
}
