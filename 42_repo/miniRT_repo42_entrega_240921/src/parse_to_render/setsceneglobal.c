/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setsceneglobal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:28:35 by apardo-m          #+#    #+#             */
/*   Updated: 2024/09/16 14:21:05 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parstoglobal.h"

#define LIGHT_RADIUS 6.0f
#define LIGTH_INTENSITY_CT 60.0f

static void	getambientscene(t_amb *amb)
{
	ambient_light(1, vector_scale(amb->f_rgb, amb->ratio));
}

static t_camera	*getcamerascene(t_cam *cam)
{
	t_camera	*newcam;

	newcam = (t_camera *)ft_calloc(1, sizeof(t_camera));
	if (newcam != NULL)
	{
		newcam->position = cam->viewpoint;
		rotate_camera(newcam, vector_normalize(cam->orient));
		newcam->near_plane = 0.000001f;
		newcam->far_plane = 100.0f;
		newcam->fov = clamp(cam->fov, 0, 179.92757);
	}
	return (newcam);
}

static t_pointlight	*getlightscene(t_light *light)
{
	t_pointlight	*newlight;

	newlight = (t_pointlight *) ft_calloc(1, sizeof(t_pointlight));
	if (newlight != NULL)
	{
		newlight->position = light->lightpoint;
		newlight->radius = LIGHT_RADIUS;
		newlight->intensity = light->ratio * LIGTH_INTENSITY_CT;
	}
	return (newlight);
}

/*
 *  void setsceneglobal(t_sceneinf *scene, t_global glb)
 *
 * 	Set render and all elements in scene (get after parsing) 
 * 		to struct 't_global' 
 */

void	setsceneglobal(t_sceneinf *scene, t_global *glb)
{
	ft_memset(glb, 0, sizeof(t_global));
	getambientscene(&(scene->amb));
	glb->camera = getcamerascene(&(scene->cam));
	glb->light_count = 1;
	glb->lights = getlightscene(&(scene->light));
	glb->object_count = ft_lstsize(scene->elemlst);
	glb->objects = getelementscene(scene->elemlst);
	ft_printf("\n elements = %d.\n", glb->object_count);
}
