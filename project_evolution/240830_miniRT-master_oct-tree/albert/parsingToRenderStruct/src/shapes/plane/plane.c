/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:56:13 by jaucarri          #+#    #+#             */
/*   Updated: 2024/08/06 18:56:15 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	fill_triangles_plane(t_object *plane)
{
	int	i[3];
	int	top[2];
	int	bottom[2];

	i[2] = 0;
	i[0] = 0;
	while (i[0] < 2)
	{
		i[1] = 0;
		while (i[1] < 2)
		{
			top[0] = i[0] * (2 + 1) + i[1];
			top[1] = top[0] + 1;
			bottom[0] = top[0] + (2 + 1);
			bottom[1] = bottom[0] + 1;
			plane->triangles[i[2]++] = top[0];
			plane->triangles[i[2]++] = bottom[0];
			plane->triangles[i[2]++] = top[1];
			plane->triangles[i[2]++] = top[1];
			plane->triangles[i[2]++] = bottom[0];
			plane->triangles[i[2]++] = bottom[1];
			i[1]++;
		}
		i[0]++;
	}
}

void	create_plane_mesh(t_object *plane, float width, float height)
{
	int	vertexindex;
	int	i[2];

	i[0] = 0;
	vertexindex = 0;
	plane->tri_count = 2 * 2 * 2;
	plane->use_caps = 0;
	plane->vert_count = (2 + 1) * (2 + 1);
	plane->vertices = (t_vector3 *)malloc(
			sizeof(t_vector3) * plane->vert_count);
	plane->normals = (t_vector3 *)malloc(sizeof(t_vector3) * plane->vert_count);
	plane->triangles = (int *)malloc(sizeof(int) * plane->tri_count * 3);
	fill_triangles_plane(plane);
	while (i[0] <= 2)
	{
		i[1] = 0;
		while (i[1] <= 2)
		{
			plane->normals[vertexindex] = (t_vector3){0, -1, 0};
			plane->vertices[vertexindex++] = (t_vector3){i[1] * (width / 2)
				- (width / 2.0f), 0, i[0] * (height / 2) - (height / 2.0f)};
			i[1]++;
		}
		i[0]++;
	}
}
