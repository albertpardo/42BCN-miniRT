/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setelementinscene.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:25:32 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/19 17:35:23 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	setelementinscene(char **aelement, t_sceneinf *scene)
{
	int	len;

	len = ft_strlen(aelement[0]);
	if (len == 1 && aelement[0][0] == 'A')
		setambient(aelement, scene);
	else if (len == 1 && aelement[0][0] == 'C')
		setcamara(aelement, scene);
	else if (len == 1 && aelement[0][0] == 'L')
		setlight(aelement, scene);
	else if (len == 2 && ft_strncmp(aelement[0], "sp", len) == 0)
		setsphere(aelement, scene);
	else if (len == 2 && ft_strncmp(aelement[0], "pl", len) == 0)
		setplane(aelement, scene);
	else if (len == 2 && ft_strncmp(aelement[0], "cy", len) == 0)
		setcylinder(aelement, scene);
}
