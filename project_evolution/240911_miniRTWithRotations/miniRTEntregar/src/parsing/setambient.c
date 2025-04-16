/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setambient.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:39:43 by apardo-m          #+#    #+#             */
/*   Updated: 2024/09/01 09:40:00 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	setambient(char **aelement, t_sceneinf *scene)
{
	scene->amb.isset = 1;
	scene->amb.id = ft_strdup(aelement[0]);
	scene->amb.ratio = ft_atof(aelement[1]);
	setnormalrgb(aelement[2], &scene->amb.f_rgb);
}
