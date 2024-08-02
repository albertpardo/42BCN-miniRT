/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iselement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:36:57 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/02 16:55:18 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	isvalidid(char **aelement)
{
	int	len;

	ft_printf("\t>> Check id :\n");
	len = ft_strlen(aelement[0]);
	if (len == 1 && ft_strncmp(aelement[0], "A", len) == 0)
		return (isokambient(aelement));
	else if (len == 1 && ft_strncmp(aelement[0], "C", len) == 0)
		return (isokcamara(aelement));
	else if (len == 1 && ft_strncmp(aelement[0], "L", len) == 0)
		return (isoklight(aelement));
	else if (len == 2 && ft_strncmp(aelement[0], "sp", len) == 0)
		return (isokspher(aelement));
	else if (len == 2 && ft_strncmp(aelement[0], "pl", len) == 0)
		return (isokplan(aelement));
	else if (len == 2 && ft_strncmp(aelement[0], "cy", len) == 0)
		return (isokcylin(aelement));
	else
		return (0);
}

int	iselement(char **elem)
{
	printf("\n>> iselement(...) :\n");
	if (elem != NULL && *elem != NULL && ft_isstralpha(elem[0]))
		return (isvalidid(elem));
	return (0);
}
