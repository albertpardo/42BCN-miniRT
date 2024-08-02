/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearscene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:43:10 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/02 14:43:21 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void clearscene(t_sceneinf *scene)
{
	free(scene->amb.id);
	free(scene->cam.id);
	free(scene->light.id);
	if (scene->elemlst)
		printf("TODO : free 'scene->elemlst'\n");
}
