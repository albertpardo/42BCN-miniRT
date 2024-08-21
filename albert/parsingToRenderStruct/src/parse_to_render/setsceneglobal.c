/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setsceneglobal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:28:35 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/21 10:58:39 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parstoglobal.h"

#define LIGHT_RADIUS 6.0f
#define LIGTH_INTENSITY_CT 60.0f

#define PLANE_WEIGHT 20.0f
#define PLANE_HIGHT 20.0f

#define CYL_SEGMENT	18

static void	getambientscene(t_amb *amb)
{
	(void) amb;
	ft_printf("\nTODO ambient in render ( Consult Jaume)\n");
}

static t_camera	*getcamerascene(t_cam *cam)
{
	t_camera	*newcam;

	newcam = (t_camera *)ft_calloc(1, sizeof(t_camera));
	if (newcam != NULL)
	{
		newcam->position = cam->viewpoint;
		newcam->rotation = (t_quaternion){-0.2164396, 0, 0, 0.976296};
		newcam->near_plane = 0.000001f;
		newcam->far_plane = 100.0f;
		newcam->fov = cam->fov;
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

static void	getsphere(t_sphere *sp, t_object *obj)
{
	create_sphere_mesh(obj, sp->diameter / 2.0f);
	translate_object(obj, sp->center);
	obj->color = sp->f_rgb;
}

static void	getplane(t_plane *pl, t_object *obj)
{
	create_plane_mesh(obj, PLANE_WEIGHT, PLANE_HIGHT);
	translate_object(obj, pl->point);
	obj->color = pl->f_rgb;
}

static void	getcylinder(t_cylinder *cy, t_object *obj)
{
	generate_cylinder(obj, cy->height, cy->diameter / 2.0f, CYL_SEGMENT);
	translate_object(obj, cy->center);
	obj->color = cy->f_rgb;
}

static t_object	*getelementscene(t_list *lst)
{
	t_object	*newaobj;
	t_element	*elem;
	int			i;

	i = 0;
	newaobj = (t_object *) ft_calloc(ft_lstsize(lst), sizeof(t_object));
	if (newaobj != NULL)
	{
		while (lst != NULL)
		{
			elem = (t_element *) lst->content;
			if (ft_strncmp(elem->idelement, "sp", 2) == 0)
				getsphere(elem->infoelement, &newaobj[i]);
			else if (ft_strncmp(elem->idelement, "pl", 2) == 0)
				getplane(elem->infoelement, &newaobj[i]);
			else if (ft_strncmp(elem->idelement, "cy", 2) == 0)
				getcylinder(elem->infoelement, &newaobj[i]);
			else
				printf("TODO:  %s\n", elem->idelement);
			lst = lst->next;
		}
	}
	return (newaobj);
}

/*
 *  void setsceneglobal(t_sceneinf *scene, t_renderer *renderer, t_global glb)
 *
 * 	Set render and all elements in scene (get after parsing) 
 * 		to struct 't_global' 
 */
void	setsceneglobal(t_sceneinf *scene, t_renderer *renderer, t_global *glb)
{
	ft_memset(glb, 0, sizeof(t_global));
	glb->renderer = renderer;
	getambientscene(&(scene->amb));
	glb->camera = getcamerascene(&(scene->cam));
	glb->light_count = 1;
	glb->lights = getlightscene(&(scene->light));
	glb->object_count = ft_lstsize(scene->elemlst);
	glb->objects = getelementscene(scene->elemlst);
	ft_printf("\n elements = %d.\n", glb->object_count);
}
