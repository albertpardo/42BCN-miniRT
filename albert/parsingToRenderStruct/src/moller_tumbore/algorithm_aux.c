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
	values->generalnormal = vert[6];
	values->indexes[0] = caps[1];
	values->indexes[1] = caps[2];
	values->indexes[2] = caps[3];
	values->use_caps = caps[4];
}

void	checkshadow(t_octree_node *node, t_global *global, t_ray ray,
		float dist)
{
	int				iter;
	int				i[5];
	t_vector3		vertex[7];
	t_intersection	intersection;

	intersection.hit = 0;
	iter = 0;
	while (iter < node->num_triangles)
	{
		initvertexs(vertex, global->objects[node->triangles[iter].objid], i,
			node->triangles[iter]);
		intersection = rayintersectstriangle(ray.origin,
				vector_normalize(ray.direction), vertex, i);
		if (intersection.hit == 1 && intersection.distance < dist
			&& node->triangles[iter].objid != getinter(0, 0).objindex)
			shadow(1, 1);
		iter++;
	}
}

void	checkcolor(t_octree_node *node, t_global *global, t_ray ray)
{
	int				iter;
	int				i[5];
	t_vector3		vertex[7];
	t_intersection	intersection;

	intersection.hit = 0;
	iter = 0;
	while (iter < node->num_triangles)
	{
		initvertexs(vertex, global->objects[node->triangles[iter].objid], i,
			node->triangles[iter]);
		intersection = rayintersectstriangle(ray.origin,
				vector_normalize(ray.direction), vertex, i);
		intersectioncheck(intersection, node->triangles[iter], global);
		iter++;
	}
}

void	intersectioncheck(t_intersection intersection, t_triangle tri,
		t_global *global)
{
	if (intersection.hit == 1 && intersection.distance < getinter(0,
			0).distance)
	{
		intersection.objindex = tri.objid;
		getinter(1, &intersection);
		getcol(1, &global->objects[tri.objid].color);
	}
}

void	initvertexs(t_vector3 vertex[7], t_object object, int i[5],
		t_triangle tri)
{
	i[1] = tri.index0;
	i[2] = tri.index1;
	i[3] = tri.index2;
	vertex[0] = tri.vert0;
	vertex[1] = tri.vert1;
	vertex[2] = tri.vert2;
	vertex[3] = tri.norm0;
	vertex[4] = tri.norm1;
	vertex[5] = tri.norm2;
	vertex[6] = object.normal;
	i[4] = tri.usecaps;
	i[4] = object.use_caps;
}
