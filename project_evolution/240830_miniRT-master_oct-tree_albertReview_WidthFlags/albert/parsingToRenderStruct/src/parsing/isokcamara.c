/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isokcamara.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:46:06 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/19 17:30:55 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	isokcamara(char **aelement)
{
	if (ft_astrlen(aelement) == 4)
	{
		if (iscoordinatestr(aelement[1]) && isorientnormal(aelement[2]) && \
				isfov(aelement[3]))
			return (1);
	}
	return (0);
}
