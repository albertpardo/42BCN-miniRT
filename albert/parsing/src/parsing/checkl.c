/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:46:03 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/03 16:10:08 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	checkl(char **aelement)
{
	if (ft_astrlen(aelement) == 4)
	{
		if (iscoordinatestr(aelement[1]))
			ft_printf("[Light] Lightpoint is valid format\n");
		else
			ft_printf("[Light] Lightpoint is NOT VALID format\n");
		if (isstrfloatcerone(aelement[2]))
			ft_printf("[Light] Bright Ratio is valid format\n");
		else
			exiterror("[Light] Bright Ratio is NOT VALID format\n");
		if (isrgbstr(aelement[3]))
			ft_printf("[Light] RGB is valid format\n");
		else
			exiterror("[Light] RGB is NOT VALID format\n");
	}
	else
		exiterror(ERR_NUM_TYPELEM_LIGHT);
}
