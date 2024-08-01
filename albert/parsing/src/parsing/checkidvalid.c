/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkidvalid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:42:32 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/01 14:42:33 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	checkid(char **aelement)
{
	int	len;

	ft_printf("\t>> Check id :\n");
	len = ft_strlen(aelement[0]);
	if (len == 1 && ft_strncmp(aelement[0], "A", len) == 0)
		checka(aelement);
	else if (len == 1 && ft_strncmp(aelement[0], "C", len) == 0)
		checkc(aelement);
	else if (len == 1 && ft_strncmp(aelement[0], "L", len) == 0)
		checkl(aelement);
	else if (len == 2 && ft_strncmp(aelement[0], "sp", len) == 0)
		checksp(aelement);
	else if (len == 2 && ft_strncmp(aelement[0], "pl", len) == 0)
		checkpl(aelement);
	else if (len == 2 && ft_strncmp(aelement[0], "cy", len) == 0)
		checkcy(aelement);
	else
		ft_printf("TODO evaluate this element : %s\n", aelement[0]);
}

/*
void	checkidvalid(char **elem)
{
	printf("\n>> checkidvalid(...) :\n");
	if (elem != NULL && *elem != NULL)
	{
		if (ft_isstralpha(elem[0]))
			checkid(elem);
		else
			exiterror(ID_ERROR_NOALPHA);
	}
	else
		exiterror(NO_ELEMENT);
}
*/

void	checkidvalid(char **elem)
{
	printf("\n>> checkidvalid(...) :\n");
	if (elem != NULL && *elem != NULL)
	{
		if (ft_isstralpha(elem[0]))
			checkid(elem);
		else
			exiterror(ID_ERROR_NOALPHA);
	}
}
