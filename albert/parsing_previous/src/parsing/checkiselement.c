/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkiselement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:19:27 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/31 10:18:07 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 * Checks if element 'elem' from 'rt' file has a valid format
 *
 * Return :
 * 	integer with tye of error. 
 * 		- 0 Valid format
 * 		- 1 ERR_IN_FORMAT
 */

static int	checkisvalidid(char **aelement)
{
	int	len;

	len = ft_strlen(aelement[0]);
	if (len == 1 && ft_strncmp(aelement[0], "A", len) == 0)
		return (checkisambient(aelement));
	else if (len == 1 && ft_strncmp(aelement[0], "C", len) == 0)
		return (checkiscamara(aelement));
	else if (len == 1 && ft_strncmp(aelement[0], "L", len) == 0)
		return (checkislight(aelement));
	else if (len == 2 && ft_strncmp(aelement[0], "sp", len) == 0)
		return (checkisspher(aelement));
	else if (len == 2 && ft_strncmp(aelement[0], "pl", len) == 0)
		return (checkisplan(aelement));
	else if (len == 2 && ft_strncmp(aelement[0], "cy", len) == 0)
		return (checkiscylin(aelement));
	else
		return (ERR_IN_FORMAT);
}

int	checkiselement(char **elem)
{
	if (elem != NULL && *elem != NULL && ft_isstralpha(elem[0]))
		return (checkisvalidid(elem));
	return (ERR_IN_FORMAT);
}
