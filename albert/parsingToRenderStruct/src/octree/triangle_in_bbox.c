/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_in_bbox.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:20:22 by jaucarri          #+#    #+#             */
/*   Updated: 2024/09/02 19:20:52 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	init_bbox_vert(t_bbox bbox, t_vector3 *vert)
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

static void	init_triangle_edges(t_triangle triangle, t_vector3 *edge)
{
	edge[0] = (t_vector3){triangle.vert1.x - triangle.vert0.x, triangle.vert1.y
		- triangle.vert0.y, triangle.vert1.z - triangle.vert0.z};
	edge[1] = (t_vector3){triangle.vert2.x - triangle.vert1.x, triangle.vert2.y
		- triangle.vert1.y, triangle.vert2.z - triangle.vert1.z};
	edge[2] = (t_vector3){triangle.vert0.x - triangle.vert2.x, triangle.vert0.y
		- triangle.vert2.y, triangle.vert0.z - triangle.vert2.z};
}

static void	init_bbox_axes(t_vector3 *axes)
{
	axes[0] = (t_vector3){1, 0, 0};
	axes[1] = (t_vector3){0, 1, 0};
	axes[2] = (t_vector3){0, 0, 1};
}

static int	triangle_intersects_bbox(t_triangle triangle, t_bbox bbox)
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

/*
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

int	triangle_in_bbox(const t_triangle triangle, const t_bbox *bbox)
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
