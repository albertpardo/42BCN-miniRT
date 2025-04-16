/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isokambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:35:21 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/19 17:30:43 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	isokambient(char **aelement)
{
	if (ft_astrlen(aelement) == 3)
		if (isstrfloatcerone(aelement[1]) && isrgbstr(aelement[2]))
			return (1);
	return (0);
}
