/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:44:31 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/01 18:09:23 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define PLUS 1

void	checksp(char **aelement)
{
	ft_printf("Element is sphere\n");
	if (ft_astrlen(aelement) == 4)
	{
		if (iscoordinatestr(aelement[1]))
			ft_printf("[Sphere] Center is valid format\n");
		else
			ft_printf("[Sphere] Center is NOT VALID format\n");
		if (isstrsgnfloat(aelement[2], PLUS))
			ft_printf("[Sphere] Diameter is valid format\n");
		else
			exiterror("[Sphere] Diameter is NOT VALID format\n");
		if (isrgbstr(aelement[3]))
			ft_printf("[Sphere] RGB is valid format\n");
		else
			exiterror("[Sphere] RGB is NOT VALID format\n");
	}
	else
		exiterror(ERR_NUM_TYPELEM_SPHERE);
}
