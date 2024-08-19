/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checka.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:50:40 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/09 08:37:20 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	checka(char **aelement)
{
	ft_printf("Element is Ambient\n");
	if (ft_astrlen(aelement) == 3)
	{
		if (isstrfloatcerone(aelement[1]))
			ft_printf("[Ambient] Scale is valid format\n");
		else
			exiterror("[Ambient] Scale is NOT VALID format\n");
		if (isrgbstr(aelement[2]))
			ft_printf("[Ambient] RGB is valid format\n");
		else
			exiterror("[Ambient] RGB is NOT VALID format\n");
	}
	else
		exiterror(ERR_TYPO_AMBIENT);
}
