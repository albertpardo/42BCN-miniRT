/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getelementscene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:53:19 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/21 14:57:02 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parstoglobal.h"

#define CYL_SEGMENT	18

#define PLANE_WEIGHT 1000.0f
#define PLANE_HIGHT 1000.0f

static void	getsphere(t_sphere *sp, t_object *obj)
{
	create_sphere_mesh(obj, sp->diameter / 2.0f);
	translate_object(obj, sp->center);
	obj->color = sp->f_rgb;
	obj->use_caps = 0;
	obj->isplane = 0;
}

static void	getplane(t_plane *pl, t_object *obj)
{
	create_plane_mesh(obj, PLANE_WEIGHT, PLANE_HIGHT);
	translate_object(obj, (t_vector3) {(PLANE_WEIGHT)*0.5*0.5, 0, (PLANE_HIGHT) * 0.5 * 0.5});
	rotate_object(obj, vector_normalize(pl->normal));
	translate_object(obj, pl->point);
	obj->color = pl->f_rgb;
	obj->use_caps = 0;
	obj->planepos = pl->point;
	obj->isplane = 1;
}

static void	getcylinder(t_cylinder *cy, t_object *obj)
{
	generate_cylinder(obj, (float)cy->diameter * 0.5, cy->height, CYL_SEGMENT);
	translate_object(obj, (t_vector3) {0, -cy->height * 0.5, 0});
	rotate_object(obj, vector_normalize(cy->normvector)); 
	translate_object(obj, cy->center);
	obj->color = cy->f_rgb;
	obj->normal = vector_normalize(cy->normvector);
	obj->use_caps = 1;
	obj->isplane = 0;
}

t_object	*getelementscene(t_list *lst)
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
			lst = lst->next;
			i++;
		}
	}
	return (newaobj);
}
