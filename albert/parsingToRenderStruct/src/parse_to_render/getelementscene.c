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
}

static void	getplane(t_plane *pl, t_object *obj)
{
	create_plane_mesh(obj, PLANE_WEIGHT, PLANE_HIGHT);  // Modificar punto inicio plano to Jaume
	//rotate_object(obj, pl->normal);      // Rotación del plano to Jaume 
	translate_object(obj, pl->point);
	obj->color = pl->f_rgb;
}

static void	getcylinder(t_cylinder *cy, t_object *obj)
{
	generate_cylinder(obj, cy->height, cy->diameter / 2.0f, CYL_SEGMENT);
	//rotate_object(obj, cy->normal);      // Rotación del cilindro to Jaume 
	translate_object(obj, cy->center);
	obj->color = cy->f_rgb;
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
