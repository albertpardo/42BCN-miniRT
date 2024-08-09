/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkpl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:45:31 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/09 08:39:38 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	checkpl(char **aelement)
{
	ft_printf("Element is plane\n");
	if (ft_astrlen(aelement) == 4)
	{
		if (iscoordinatestr(aelement[1]))
			ft_printf("[Plane] Point in Plane is valid format\n");
		else
			ft_printf("[Plane] Point in Plane is NOT VALID format\n");
		if (isorientnormal(aelement[2]))
			ft_printf("[Plane] Normalized Normal is valid format\n");
		else
			ft_printf("[Plane] Normalized Normal is NOT VALID format\n");
		if (isrgbstr(aelement[3]))
			ft_printf("[Plane] RGB is valid format\n");
		else
			exiterror("[Plane] RGB is NOT VALID format\n");
	}
	else
		exiterror(ERR_TYPO_PLANE);
}
