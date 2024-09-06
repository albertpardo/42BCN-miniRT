/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putsceneinfoinline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:33:43 by apardo-m          #+#    #+#             */
/*   Updated: 2024/09/04 16:58:54 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	putelements(t_list *lst);

static void	put_ambient(t_sceneinf *scene)
{
	printf("Ambient Info:\n");
	printf("  %d", scene->amb.isset);
	if (scene->amb.id)
		printf(" \"%s\"", scene->amb.id);
	else
		printf(" %p", scene->amb.id);
	printf(" %f", scene->amb.ratio);
	printf(" %f,%f,%f\n", scene->amb.f_rgb.x, scene->amb.f_rgb.y, \
			scene->amb.f_rgb.z);
}

static void	put_camera(t_sceneinf *scene)
{
	printf("Camara Info:\n");
	printf("  %d", scene->cam.isset);
	if (scene->cam.id)
		printf(" \"%s\"", scene->cam.id);
	else
		printf(" %p", scene->cam.id);
	printf(" %f,%f,%f", scene->cam.viewpoint.x, scene->cam.viewpoint.y, \
			scene->cam.viewpoint.z);
	printf(" %f,%f,%f", scene->cam.orient.x, scene->cam.orient.y, \
			scene->cam.orient.z);
	printf(" %f\n", scene->cam.fov);
}

static void	put_ligth(t_sceneinf *scene)
{
	printf("Light Info:\n");
	printf("  %d", scene->light.isset);
	if (scene->light.id)
		printf(" \"%s\"", scene->light.id);
	else
		printf(" %p", scene->light.id);
	printf(" %f,%f,%f", scene->light.lightpoint.x, \
			scene->light.lightpoint.y, scene->light.lightpoint.z);
	printf("  %f", scene->light.ratio);
	printf(" %f,%f,%f\n", scene->light.f_rgb.x, scene->light.f_rgb.y, \
			scene->light.f_rgb.z);
}

void	putsceneinfoinline(t_sceneinf *scene)
{
	printf("\n--- Info Scene ---\n");
	if (scene)
	{
		put_ambient(scene);
		put_camera(scene);
		put_ligth(scene);
		putelements(scene->elemlst);
	}
}
