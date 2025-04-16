/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 09:10:31 by jaucarri          #+#    #+#             */
/*   Updated: 2024/08/18 09:10:34 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	initnormals(t_vector3 *vert, int caps[5], t_calcs *values)
{
	values->normals[0] = vert[3];
	values->normals[1] = vert[4];
	values->normals[2] = vert[5];
	values->indexes[0] = caps[1];
	values->indexes[1] = caps[2];
	values->indexes[2] = caps[3];
	values->use_caps = caps[4];
}

void	initvertexs(t_vector3 vertex[6], t_object *object, int i[5])
{
	vertex[0] = object->vertices[object->triangles[i[0] * 3]];
	vertex[1] = object->vertices[object->triangles[i[0] * 3 + 1]];
	vertex[2] = object->vertices[object->triangles[i[0] * 3 + 2]];
	vertex[3] = object->normals[object->triangles[i[0] * 3]];
	vertex[4] = object->normals[object->triangles[i[0] * 3 + 1]];
	vertex[5] = object->normals[object->triangles[i[0] * 3 + 2]];
	i[1] = object->triangles[i[0] * 3];
	i[2] = object->triangles[i[0] * 3 + 1];
	i[3] = object->triangles[i[0] * 3 + 2];
	i[4] = object->use_caps;
}
