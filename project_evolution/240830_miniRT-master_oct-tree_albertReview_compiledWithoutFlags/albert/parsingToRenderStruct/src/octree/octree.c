/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:20:22 by jaucarri          #+#    #+#             */
/*   Updated: 2024/08/30 16:20:23 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
/*

//1 ?DONDE SE USA ?




int	is_point_inside_bbox(t_vector3 point, t_bbox bbox)
{
	return (point.x >= bbox.min.x && point.x <= bbox.max.x
		&& point.y >= bbox.min.y && point.y <= bbox.max.y
		&& point.z >= bbox.min.z && point.z <= bbox.max.z);
}
*/

/*
//2
float	project_onto_axis(t_vector3 v, t_vector3 axis)
{
	return (v.x * axis.x + v.y * axis.y + v.z * axis.z);
}

//3
int	ranges_overlap(float min1, float max1, float min2, float max2)
{
	return (!(max1 < min2 || max2 < min1));
}
*/

/*
//4
void	init_bbox_vert(t_bbox bbox, t_vector3 *vert)
{
	vert[0] = (t_vector3){bbox.min.x, bbox.min.y, bbox.min.z};
	vert[1] = (t_vector3){bbox.min.x, bbox.min.y, bbox.max.z};
	vert[2] = (t_vector3){bbox.min.x, bbox.max.y, bbox.min.z};
	vert[3] = (t_vector3){bbox.min.x, bbox.max.y, bbox.max.z};
	vert[4] = (t_vector3){bbox.max.x, bbox.min.y, bbox.min.z};
	vert[5] = (t_vector3){bbox.max.x, bbox.min.y, bbox.max.z};
	vert[6] = (t_vector3){bbox.max.x, bbox.max.y, bbox.min.z};
	vert[7] = (t_vector3){bbox.max.x, bbox.max.y, bbox.max.z};
}

//5
void	init_triangle_edges(t_triangle triangle, t_vector3 *edge)
{
	edge[0] = (t_vector3){triangle.vert1.x - triangle.vert0.x, triangle.vert1.y
		- triangle.vert0.y, triangle.vert1.z - triangle.vert0.z};
	edge[1] = (t_vector3){triangle.vert2.x - triangle.vert1.x, triangle.vert2.y
		- triangle.vert1.y, triangle.vert2.z - triangle.vert1.z};
	edge[2] = (t_vector3){triangle.vert0.x - triangle.vert2.x, triangle.vert0.y
		- triangle.vert2.y, triangle.vert0.z - triangle.vert2.z};
}

//6
void	init_bbox_axes(t_vector3 *axes)
{
	axes[0] = (t_vector3){1, 0, 0};
	axes[1] = (t_vector3){0, 1, 0};
	axes[2] = (t_vector3){0, 0, 1};
}
*/

/*
//7
void	setrangeval(int *i, float *ranges, t_triangle triangle,
		t_vector3 *bbox_axes)
{
	float	projection;

	projection = project_onto_axis(triangle.vert0, bbox_axes[i[0]]);
	ranges[0] = fminf(ranges[0], projection);
	ranges[1] = fmaxf(ranges[1], projection);
	projection = project_onto_axis(triangle.vert1, bbox_axes[i[0]]);
	ranges[0] = fminf(ranges[0], projection);
	ranges[1] = fmaxf(ranges[1], projection);
	projection = project_onto_axis(triangle.vert2, bbox_axes[i[0]]);
	ranges[0] = fminf(ranges[0], projection);
	ranges[1] = fmaxf(ranges[1], projection);
}
*/

/*
//8
int	first_overlap(t_triangle triangle, t_vector3 *bbox_axes, float projection,
		t_vector3 *bbox_vertices)
{
	float	ranges[4];
	int		i[2];

	ranges[0] = INFINITY;
	ranges[1] = -INFINITY;
	ranges[2] = INFINITY;
	ranges[3] = -INFINITY;
	i[0] = -1;
	while (++i[0] < 3)
	{
		i[1] = -1;
		while (++i[1] < 3)
			setrangeval(i, ranges, triangle, bbox_axes);
		i[1] = -1;
		while (++i[1] < 8)
		{
			projection = project_onto_axis(bbox_vertices[i[1]],
					bbox_axes[i[0]]);
			ranges[2] = fminf(ranges[2], projection);
			ranges[3] = fmaxf(ranges[3], projection);
		}
		if (!ranges_overlap(ranges[0], ranges[1], ranges[2], ranges[3]))
			return (0);
	}
	return (1);
}
*/

/*
//9
void	init_axis(t_vector3 *axis, t_vector3 triangle_edges,
		t_vector3 bbox_axes)
{
	axis[0] = (t_vector3){triangle_edges.y * bbox_axes.z - triangle_edges.z
		* bbox_axes.y, triangle_edges.z * bbox_axes.x - triangle_edges.x
		* bbox_axes.z, triangle_edges.x * bbox_axes.y - triangle_edges.y
		* bbox_axes.x};
}

//10
void	setrangevaltwo(float *range, t_triangle triangle, t_vector3 axis,
		float projection)
{
	projection = project_onto_axis(triangle.vert0, axis);
	range[0] = fminf(range[0], projection);
	range[1] = fmaxf(range[1], projection);
	projection = project_onto_axis(triangle.vert1, axis);
	range[0] = fminf(range[0], projection);
	range[1] = fmaxf(range[1], projection);
	projection = project_onto_axis(triangle.vert2, axis);
	range[0] = fminf(range[0], projection);
	range[1] = fmaxf(range[1], projection);
}

//11
int	second_overlap(t_vector3 triangle_edges, t_vector3 bbox_axes,
		t_triangle triangle, t_vector3 *bbox_vertices)
{
	t_vector3	axis;
	float		range[4];
	float		projection;
	int			k;

	k = -1;
	init_axis(&axis, triangle_edges, bbox_axes);
	range[0] = INFINITY;
	range[1] = -INFINITY;
	range[2] = INFINITY;
	range[3] = -INFINITY;
	while (++k < 3)
		setrangevaltwo(range, triangle, axis, 0);
	k = -1;
	while (++k < 8)
	{
		projection = project_onto_axis(bbox_vertices[k], axis);
		range[2] = fminf(range[2], projection);
		range[3] = fmaxf(range[3], projection);
	}
	if (!ranges_overlap(range[0], range[1], range[2], range[3]))
		return (0);
	return (1);
}
*/

/*
//12
int	triangle_intersects_bbox(t_triangle triangle, t_bbox bbox)
{
	t_vector3	bbox_vertices[8];
	t_vector3	triangle_edges[3];
	t_vector3	bbox_axes[3];
	int			i[2];

	init_bbox_vert(bbox, bbox_vertices);
	init_triangle_edges(triangle, triangle_edges);
	init_bbox_axes(bbox_axes);
	if (first_overlap(triangle, bbox_axes, 0, bbox_vertices) == 0)
		return (0);
	i[0] = -1;
	while (++i[0] < 3)
	{
		i[1] = -1;
		while (++i[1] < 3)
		{
			if (second_overlap(triangle_edges[i[0]], bbox_axes[i[1]], triangle,
					bbox_vertices) == 0)
				return (0);
		}
	}
	return (1);
}

//13
int	triangle_in_bbox(const t_triangle triangle, const t_bbox *bbox,
		t_object obj)
{
	t_vector3	v0;
	t_vector3	v1;
	t_vector3	v2;

	v0 = triangle.vert0;
	v1 = triangle.vert1;
	v2 = triangle.vert2;
	if (v0.x >= bbox->min.x && v0.x <= bbox->max.x && v0.y >= bbox->min.y
		&& v0.y <= bbox->max.y && v0.z >= bbox->min.z && v0.z <= bbox->max.z)
	{
		return (1);
	}
	if (v1.x >= bbox->min.x && v1.x <= bbox->max.x && v1.y >= bbox->min.y
		&& v1.y <= bbox->max.y && v1.z >= bbox->min.z && v1.z <= bbox->max.z)
	{
		return (1);
	}
	if (v2.x >= bbox->min.x && v2.x <= bbox->max.x && v2.y >= bbox->min.y
		&& v2.y <= bbox->max.y && v2.z >= bbox->min.z && v2.z <= bbox->max.z)
	{
		return (1);
	}
	if (triangle_intersects_bbox(triangle, *bbox))
		return (1);
	return (0);
}
*/

/*
//14
t_octree_node	*create_octree_node(const t_bbox *bbox)
{
	t_octree_node	*node;
	int				i;

	node = (t_octree_node *)malloc(sizeof(t_octree_node));
	node->bbox = *bbox;
	node->triangles = (t_triangle *)malloc(42 * sizeof(t_triangle));
	node->num_triangles = 0;
	node->is_leaf = 1;
	i = 0;
	while (i < 8)
		node->children[i++] = NULL;
	return (node);
}
*/

/*
//15
void	set_node_bounds(t_octree_node *node, t_bbox *child_bbox, float mid[3],
		int i)
{
	if (i & 1)
		child_bbox->min.x = mid[0];
	else
		child_bbox->min.x = node->bbox.min.x;
	if (i & 1)
		child_bbox->max.x = node->bbox.max.x;
	else
		child_bbox->max.x = mid[0];
	if (i & 2)
		child_bbox->min.y = mid[1];
	else
		child_bbox->min.y = node->bbox.min.y;
	if (i & 2)
		child_bbox->max.y = node->bbox.max.y;
	else
		child_bbox->max.y = mid[1];
	if (i & 4)
		child_bbox->min.z = mid[2];
	else
		child_bbox->min.z = node->bbox.min.z;
	if (i & 4)
		child_bbox->max.z = node->bbox.max.z;
	else
		child_bbox->max.z = mid[2];
}

//16
void	subdivide_node(t_octree_node *node)
{
	float	mid[3];
	t_bbox	child_bbox;
	int		i;

	mid[0] = (node->bbox.min.x + node->bbox.max.x) * 0.5f;
	mid[1] = (node->bbox.min.y + node->bbox.max.y) * 0.5f;
	mid[2] = (node->bbox.min.z + node->bbox.max.z) * 0.5f;
	i = 0;
	while (i < 8)
	{
		child_bbox = node->bbox;
		set_node_bounds(node, &child_bbox, mid, i);
		node->children[i] = create_octree_node(&child_bbox);
		i++;
	}
	node->is_leaf = 0;
}

//17
void	insert_to_childs(t_octree_node *node, t_triangle tri, t_object obj)
{
	int	j;

	j = -1;
	while (++j < 8)
	{
		if (triangle_in_bbox(tri, &node->children[j]->bbox, obj))
		{
			insert_triangle(node->children[j], tri, obj);
		}
	}
}

//18
void	insert_triangle(t_octree_node *node, t_triangle tri, t_object obj)
{
	int	i[2];

	if (node->num_triangles < 42)
		node->triangles[node->num_triangles++] = tri;
	else
	{
		if (node->is_leaf)
		{
			subdivide_node(node);
			i[0] = -1;
			while (++i[0] < node->num_triangles)
			{
				i[1] = -1;
				while (++i[1] < 8)
					if (triangle_in_bbox(node->triangles[i[0]],
							&node->children[i[1]]->bbox, obj))
						insert_triangle(node->children[i[1]],
							node->triangles[i[0]], obj);
			}
			insert_to_childs(node, tri, obj);
		}
		else
			insert_to_childs(node, tri, obj);
	}
}
*/

/*
//19
void	ray_inter_bbox_init(t_vector3 origin, t_vector3 direction, t_bbox bbox,
		float *values)
{
	values[0] = (bbox.min.x - origin.x) / direction.x;
	values[1] = (bbox.max.x - origin.x) / direction.x;
	if (values[0] > values[1])
	{
		values[2] = values[0];
		values[0] = values[1];
		values[1] = values[2];
	}
	values[3] = (bbox.min.y - origin.y) / direction.y;
	values[4] = (bbox.max.y - origin.y) / direction.y;
	if (values[3] > values[4])
	{
		values[2] = values[3];
		values[3] = values[4];
		values[4] = values[2];
	}
}

//20
int	ray_intersects_bbox(t_vector3 origin, t_vector3 direction, t_bbox bbox)
{
	float	values[7];

	ray_inter_bbox_init(origin, direction, bbox, values);
	if ((values[0] > values[4]) || (values[3] > values[1]))
		return (0);
	if (values[3] > values[0])
		values[0] = values[3];
	if (values[4] < values[1])
		values[1] = values[4];
	values[5] = (bbox.min.z - origin.z) / direction.z;
	values[6] = (bbox.max.z - origin.z) / direction.z;
	if (values[5] > values[6])
	{
		values[2] = values[5];
		values[5] = values[6];
		values[6] = values[2];
	}
	if ((values[0] > values[6]) || (values[5] > values[1]))
		return (0);
	if (values[5] > values[0])
		values[0] = values[5];
	if (values[6] < values[1])
		values[1] = values[6];
	return (1);
}
*/

//21
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

//22
static void	init_bbox_values(t_bbox *bbox)
{
	bbox->min.x = INFINITY;
	bbox->min.y = INFINITY;
	bbox->min.z = INFINITY;
	bbox->max.x = -INFINITY;
	bbox->max.y = -INFINITY;
	bbox->max.z = -INFINITY;
}

//23
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

//24
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

//25
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
