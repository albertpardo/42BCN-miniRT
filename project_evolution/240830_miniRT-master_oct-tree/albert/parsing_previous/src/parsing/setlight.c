/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setlight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:29:31 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/13 11:05:46 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	setlight(char **aelement, t_sceneinf *scene)
{
	//ft_printf("set %s\n", aelement[0]);
	scene->light.isset = 1;
	scene->light.id = ft_strdup(aelement[0]);
	setvectorinelemtscene(aelement[1], &scene->light.lightpoint);
	scene->light.ratio = ft_atof(aelement[2]);
	if (ft_astrlen(aelement) == 4)
		//setvectorinelemtscene(aelement[3], &scene->light.f_rgb);
		setnormalrgb(aelement[3], &scene->light.f_rgb);
}
