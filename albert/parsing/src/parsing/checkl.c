/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:46:03 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/01 14:53:41 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	checkl(char **aelement)
{
	int		l;

	l = ft_astrlen(aelement);
	if (l == 3)
	{
		if (iscoordinatestr(aelement[1]))
			ft_printf("[Light] Lightpoint is valid format\n");
		else
			ft_printf("[Light] Lightpoint is NOT VALID format\n");
		if (isstrfloatcerone(aelement[2]))
			ft_printf("[Light] Bright Ratio is valid format\n");
		else
			exiterror("[Light] Bright Ratio is NOT VALID format\n");
	}
	else if (l == 4)
	{
		if (isrgbstr(aelement[3]))
			ft_printf("[Light] RGB is valid format\n");
		else
			exiterror("[Light] RGB is NOT VALID format\n");
	}
	else
		exiterror(ERR_NUM_TYPELEM_LIGHT);
}
