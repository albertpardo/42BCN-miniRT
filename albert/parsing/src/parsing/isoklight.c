/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isoklight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:49:50 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/02 17:25:15 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//DUDA subject dice que RGB es usado en el bonus pero parece que tambien debe
// aparecer en el mandatory
// Esta funcion solo lo evalua si aparece

int	isoklight(char **aelement)
{
	int		l;

	l = ft_astrlen(aelement);
	if (l == 3)
	{
		if (iscoordinatestr(aelement[1]) && isstrfloatcerone(aelement[2]))
			return (1);
	}
	else if (l == 4)
		if (isrgbstr(aelement[3]))
			return (1);
	return (0);
}
