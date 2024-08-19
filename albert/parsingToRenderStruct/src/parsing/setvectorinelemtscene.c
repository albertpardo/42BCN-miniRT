/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setvectorinelemtscene.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:46:45 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/19 17:37:25 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	setvectorinelemtscene(char *str, t_vector3 *vec3)
{
	char	**astr;

	astr = ft_split(str, ',');
	vec3->x = ft_atof(astr[0]);
	vec3->y = ft_atof(astr[1]);
	vec3->z = ft_atof(astr[2]);
	if (astr)
		freearrstr(astr);
}
