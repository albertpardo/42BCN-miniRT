/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkcy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:47:45 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/09 08:37:52 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define PLUS 1

void	checkcy(char **aelement)
{
	ft_printf("Element is cilinder\n");
	if (ft_astrlen(aelement) == 6)
	{
		if (iscoordinatestr(aelement[1]))
			ft_printf("[Cylinder] Center is valid format\n");
		else
			ft_printf("[Cylinder] Center is NOT VALID format\n");
		if (isorientnormal(aelement[2]))
			ft_printf("[Cylinder] Normalized Vector is valid format\n");
		else
			ft_printf("[Cylinder] Normalized Vector is NOT VALID format\n");
		if (isstrsgnfloat(aelement[3], PLUS))
			ft_printf("[Cylinder] Diameter is valid format\n");
		else
			exiterror("[Cylinder] Diameter is NOT VALID format\n");
		if (isstrsgnfloat(aelement[4], PLUS))
			ft_printf("[Cylinder] Height is valid format\n");
		else
			exiterror("[Cylinder] Height is NOT VALID format\n");
		if (isrgbstr(aelement[5]))
			ft_printf("[Cylinder] RGB is valid format\n");
		else
			exiterror("[Cylinder] RGB is NOT VALID forimat\n");
	}
	else
		exiterror(ERR_TYPO_PLANE);
}
