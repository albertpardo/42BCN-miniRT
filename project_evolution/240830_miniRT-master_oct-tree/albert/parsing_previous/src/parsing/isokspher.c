/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isokspher.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:07:46 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/02 17:13:42 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define PLUS 1

int	isokspher(char **aelement)
{
	if (ft_astrlen(aelement) == 4)
		if (iscoordinatestr(aelement[1]) && \
				isstrsgnfloat(aelement[2], PLUS) && isrgbstr(aelement[3]))
			return (1);
	return (0);
}
