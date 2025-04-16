/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:28:58 by jaucarri          #+#    #+#             */
/*   Updated: 2024/08/05 15:28:59 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	allocate_memory_for_sphere(t_object *sphere, int segment_count)
{
	int	vertex_count;
	int	triangle_count;

	vertex_count = (segment_count + 1) * (segment_count + 1);
	triangle_count = segment_count * segment_count * 2;
	sphere->vertices = (t_vector3 *)malloc(sizeof(t_vector3) * vertex_count);
	sphere->normals = (t_vector3 *)malloc(sizeof(t_vector3) * vertex_count);
	sphere->triangles = (int *)malloc(sizeof(int) * triangle_count * 3);
}

void	allocate_normals_sphere(t_object *sphere)
{
	int	i;

	i = 0;
	while (i < sphere->vert_count)
		sphere->normals[i++] = (t_vector3){0, 0, 0};
	i = 0;
	while (i < sphere->tri_count / 3)
	{
		spherenormalscalc(sphere,
			vector_cross(vector_sub(sphere->vertices[sphere->triangles[i * 3
					+ 1]], sphere->vertices[sphere->triangles[i * 3]]),
				vector_sub(sphere->vertices[sphere->triangles[i * 3 + 2]],
					sphere->vertices[sphere->triangles[i * 3]])), i);
		i++;
	}
	i = 0;
	while (i < sphere->vert_count)
	{
		sphere->normals[i] = vector_divide(sphere->normals[i],
				sphere->tri_count);
		sphere->normals[i] = vector_normalize(sphere->normals[i]);
		i++;
	}
}

void	allocate_vertices_sphere(float values[5], float radius,
		t_object *sphere, int *vertexcount)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 10)
	{
		j = 0;
		while (j <= 10)
		{
			values[0] = (float)i / 10 * PI;
			values[1] = (float)j / 10 * 2.0f * PI;
			values[2] = radius * sinf(values[0]) * cosf(values[1]);
			values[3] = radius * cosf(values[0]);
			values[4] = radius * sinf(values[0]) * sinf(values[1]);
			sphere->vertices[(*vertexcount)++] = (t_vector3){values[2],
				values[3], values[4]};
			j++;
		}
		i++;
	}
}

void	allocate_triangles_sphere(t_object *sphere, int *trianglecount)
{
	int	first;
	int	second;
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			first = (i * (10 + 1)) + j;
			second = first + 10 + 1;
			sphere->triangles[(*trianglecount)++] = first;
			sphere->triangles[(*trianglecount)++] = second;
			sphere->triangles[(*trianglecount)++] = first + 1;
			sphere->triangles[(*trianglecount)++] = second;
			sphere->triangles[(*trianglecount)++] = second + 1;
			sphere->triangles[(*trianglecount)++] = first + 1;
			j++;
		}
		i++;
	}
}

void	create_sphere_mesh(t_object *sphere, float radius)
{
	int		vertexcount;
	int		trianglecount;
	float	values[5];

	allocate_memory_for_sphere(sphere, 10);
	vertexcount = 0;
	trianglecount = 0;
	sphere->use_caps = 0;
	allocate_vertices_sphere(values, radius, sphere, &vertexcount);
	sphere->vert_count = vertexcount;
	allocate_triangles_sphere(sphere, &trianglecount);
	sphere->tri_count = trianglecount;
	allocate_normals_sphere(sphere);
}
