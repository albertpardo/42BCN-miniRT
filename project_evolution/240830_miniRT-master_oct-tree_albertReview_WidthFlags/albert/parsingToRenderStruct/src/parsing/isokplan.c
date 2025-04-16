/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isokplan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:45:31 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/19 17:31:45 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	isokplan(char **aelement)
{
	if (ft_astrlen(aelement) == 4)
		if (iscoordinatestr(aelement[1]) && isorientnormal(aelement[2]) && \
				isrgbstr(aelement[3]))
			return (1);
	return (0);
}
