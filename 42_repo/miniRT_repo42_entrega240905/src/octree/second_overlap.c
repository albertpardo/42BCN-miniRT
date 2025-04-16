/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_overlap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:20:22 by jaucarri          #+#    #+#             */
/*   Updated: 2024/08/30 16:20:23 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	init_axis(t_vector3 *axis, t_vector3 triangle_edges,
		t_vector3 bbox_axes)
{
	axis[0] = (t_vector3){triangle_edges.y * bbox_axes.z - triangle_edges.z
		* bbox_axes.y, triangle_edges.z * bbox_axes.x - triangle_edges.x
		* bbox_axes.z, triangle_edges.x * bbox_axes.y - triangle_edges.y
		* bbox_axes.x};
}

static void	setrangevaltwo(float *range, t_triangle triangle, t_vector3 axis,
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
