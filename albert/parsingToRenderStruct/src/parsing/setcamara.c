/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setcamara.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:21:20 by apardo-m          #+#    #+#             */
/*   Updated: 2024/09/01 09:40:14 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	setcamara(char **aelement, t_sceneinf *scene)
{
	scene->cam.isset = 1;
	scene->cam.id = ft_strdup(aelement[0]);
	setvectorinelemtscene(aelement[1], &scene->cam.viewpoint);
	setvectorinelemtscene(aelement[2], &scene->cam.orient);
	scene->cam.fov = ft_atof(aelement[3]);
}
