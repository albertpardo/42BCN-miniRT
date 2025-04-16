/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_overlap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:20:22 by jaucarri          #+#    #+#             */
/*   Updated: 2024/08/30 16:20:23 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	setrangeval(int *i, float *ranges, t_triangle triangle,
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
