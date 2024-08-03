/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setelementinscene.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:25:32 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/03 14:05:47 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	setelementinscene(char **aelement, t_sceneinf *scene)
{
	int	len;

	ft_printf("\t>> setelementinscene :\n");
	len = ft_strlen(aelement[0]);
	if (len == 1 && ft_strncmp(aelement[0], "A", len) == 0)
		setambient(aelement, scene);
	else if (len == 1 && ft_strncmp(aelement[0], "C", len) == 0)
		setcamara(aelement, scene);
	else if (len == 1 && ft_strncmp(aelement[0], "L", len) == 0)
		setlight(aelement, scene);
	else if (len == 2 && ft_strncmp(aelement[0], "sp", len) == 0)
		setsphere(aelement, scene);
	else if (len == 2 && ft_strncmp(aelement[0], "pl", len) == 0)
		setplane(aelement, scene);
	else if (len == 2 && ft_strncmp(aelement[0], "cy", len) == 0)
		setcylinder(aelement, scene);
	else
		ft_printf("Error ! TODO evaluate this element : %s\n", aelement[0]);
}
