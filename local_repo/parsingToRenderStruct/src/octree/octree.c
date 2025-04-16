/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:20:22 by jaucarri          #+#    #+#             */
/*   Updated: 2024/09/03 17:23:19 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
int	is_point_inside_bbox(t_vector3 point, t_bbox bbox)
{
	return (point.x >= bbox.min.x && point.x <= bbox.max.x
		&& point.y >= bbox.min.y && point.y <= bbox.max.y
		&& point.z >= bbox.min.z && point.z <= bbox.max.z);
}
*/

static void	check_bounds_values(t_bbox *bbox, t_vector3 v)
{
	if (v.x < bbox->min.x)
		bbox->min.x = v.x;
	if (v.y < bbox->min.y)
		bbox->min.y = v.y;
	if (v.z < bbox->min.z)
		bbox->min.z = v.z;
	if (v.x > bbox->max.x)
		bbox->max.x = v.x;
	if (v.y > bbox->max.y)
		bbox->max.y = v.y;
	if (v.z > bbox->max.z)
		bbox->max.z = v.z;
}

static void	init_bbox_values(t_bbox *bbox)
{
	bbox->min.x = INFINITY;
	bbox->min.y = INFINITY;
	bbox->min.z = INFINITY;
	bbox->max.x = -INFINITY;
	bbox->max.y = -INFINITY;
	bbox->max.z = -INFINITY;
}

static void	setinitialbbox(t_bbox *bbox, t_global *global)
{
	int	i;
	int	j;

	init_bbox_values(bbox);
	i = -1;
	while (++i < global->object_count)
	{
		if (global->objects[i].isplane == 0)
		{
			j = -1;
			while (++j < global->objects[i].vert_count)
				check_bounds_values(bbox, global->objects[i].vertices[j]);
		}
		else
			check_bounds_values(bbox, global->objects[i].planepos);
	}
	bbox->min.x -= 10;
	bbox->min.y -= 10;
	bbox->min.z -= 10;
	bbox->max.x += 10;
	bbox->max.y += 10;
	bbox->max.z += 10;
}

static void	set_tri_val(t_triangle *tri, t_global *global, int *iter)
{
	tri->index0 = global->objects[iter[0]].triangles[iter[1] * 3];
	tri->index1 = global->objects[iter[0]].triangles[iter[1] * 3 + 1];
	tri->index2 = global->objects[iter[0]].triangles[iter[1] * 3 + 2];
	tri->vert0 = global->objects[iter[0]].vertices[tri->index0];
	tri->vert1 = global->objects[iter[0]].vertices[tri->index1];
	tri->vert2 = global->objects[iter[0]].vertices[tri->index2];
	tri->norm0 = global->objects[iter[0]].normals[tri->index0];
	tri->norm1 = global->objects[iter[0]].normals[tri->index1];
	tri->norm2 = global->objects[iter[0]].normals[tri->index2];
	tri->objid = iter[0];
}

void	create_octree(t_global *global)
{
	int			iter[2];
	t_triangle	tri;
	t_bbox		root_bbox;

	iter[0] = -1;
	setinitialbbox(&root_bbox, global);
	global->root = create_octree_node(&root_bbox);
	while (++iter[0] < global->object_count)
	{
		iter[1] = -1;
		while (++iter[1] < global->objects[iter[0]].tri_count / 3)
		{
			set_tri_val(&tri, global, iter);
			tri.usecaps = global->objects[iter[0]].use_caps;
			insert_triangle(global->root, tri, global->objects[iter[0]]);
		}
	}
}
