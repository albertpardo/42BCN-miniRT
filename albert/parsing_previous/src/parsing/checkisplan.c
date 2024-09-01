/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkisplan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:02:29 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/30 16:04:44 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	checkisplan(char **aelement)
{
	if (ft_astrlen(aelement) == 4)
		if (iscoordinatestr(aelement[1]) && isrgbstr(aelement[3]))
			return (checkisnormal(aelement[2]));
	return (ERR_IN_FORMAT);
}
