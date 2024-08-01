/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:49:59 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/01 14:50:21 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	checkc(char **aelement)
{
	ft_printf("Element is Camara\n");
	if (ft_astrlen(aelement) == 4)
	{
		if (iscoordinatestr(aelement[1]))
			ft_printf("[Camara] Viewport is valid format\n");
		else
			ft_printf("[Camara] Viewport is NOT VALID format\n");
		if (isorientnormal(aelement[2]))
			ft_printf("[Camara] Orientation is valid format\n");
		else
			ft_printf("[Camara] Orientation is NOT VALID format\n");
		if (isfov(aelement[3]))
			ft_printf("[Camara] FOV is valid format\n");
		else
			ft_printf("[Camara] FOV is NOT VALID format\n");
	}
	else
		exiterror(ERR_NUM_TYPELEM_CAMARA);
}
