/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:11:47 by jaucarri          #+#    #+#             */
/*   Updated: 2024/08/07 13:11:48 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	allocate_normals_cylinder(t_object *cylinder)
{
	int			i;
	int			slices;
	float		x;
	float		z;
	t_vector3	norm;

	slices = (cylinder->vert_count / 2) - 1;
	cylinder->normals[0] = (t_vector3){0, -1, 0};
	cylinder->normals[1] = (t_vector3){0, 1, 0};
	i = 1;
	while (i <= slices)
	{
		x = cos((i - 1) * (2 * M_PI / slices));
		z = sin((i - 1) * (2 * M_PI / slices));
		x /= sqrt(x * x + z * z);
		z /= sqrt(x * x + z * z);
		norm = vector_sub((t_vector3){x, 0, z}, (t_vector3){0, 0, 0});
		cylinder->normals[i * 2] = vector_scale(vector_normalize(norm), -1);
		cylinder->normals[i * 2 + 1] = vector_scale(vector_normalize(norm), -1);
		i++;
	}
}

void	generate_auxiliar(t_object *cylinder, int *next, int slices, int *idx)
{
	int	i;

	i = 0;
	while (i < slices)
	{
		*next = (i + 1) % (slices + 1);
		cylinder->triangles[(*idx)++] = 0;
		cylinder->triangles[(*idx)++] = i * 2;
		cylinder->triangles[(*idx)++] = *next * 2;
		i++;
	}
	i = 0;
	while (i < slices)
	{
		*next = (i + 1) % (slices + 1);
		cylinder->triangles[(*idx)++] = 1;
		cylinder->triangles[(*idx)++] = *next * 2 + 1;
		cylinder->triangles[(*idx)++] = i * 2 + 1;
		i++;
	}
}

void	generate_triangles(t_object *cylinder, int *idx, int *next, int slices)
{
	int	i;

	i = 0;
	while (i < slices)
	{
		*next = (i + 1) % (slices + 1);
		cylinder->triangles[(*idx)++] = i * 2;
		cylinder->triangles[(*idx)++] = *next * 2;
		cylinder->triangles[(*idx)++] = i * 2 + 1;
		cylinder->triangles[(*idx)++] = i * 2 + 1;
		cylinder->triangles[(*idx)++] = *next * 2;
		cylinder->triangles[(*idx)++] = *next * 2 + 1;
		i++;
	}
	generate_auxiliar(cylinder, next, slices, idx);
}

void	generate_top_bottom(t_object *cylinder, int slices, int height,
		int radius)
{
	int		idx[2];
	float	angle;
	float	x;
	float	z;
	int		i;

	idx[0] = 0;
	idx[1] = 0;
	i = 0;
	while (i < cylinder->vert_count)
	{
		cylinder->normals[i] = (t_vector3){0, 0, 0};
		i++;
	}
	while (idx[1] <= slices)
	{
		angle = idx[1] * (2 * M_PI / slices);
		x = radius * cos(angle);
		z = radius * sin(angle);
		cylinder->vertices[idx[0]] = (t_vector3){x, 0, z};
		idx[0]++;
		cylinder->vertices[idx[0]] = (t_vector3){x, height, z};
		idx[0]++;
		idx[1]++;
	}
}

void	generate_cylinder(t_object *cylinder, float radius, float height,
		int slices)
{
	float	angle_step;
	int		next;
	int		idx;

	cylinder->vertices = (t_vector3 *)malloc(((slices + 1) * 2)
			* sizeof(t_vector3));
	cylinder->normals = (t_vector3 *)malloc(((slices + 1) * 2)
			* sizeof(t_vector3));
	cylinder->use_caps = 1;
	cylinder->vert_count = (slices + 1) * 2;
	cylinder->triangles = (int *)malloc((slices * 2 * 3) * 3 * sizeof(int));
	angle_step = 2 * M_PI / slices;
	generate_top_bottom(cylinder, slices, height, radius);
	idx = 0;
	generate_triangles(cylinder, &idx, &next, slices);
	cylinder->tri_count = idx;
	allocate_normals_cylinder(cylinder);
}
