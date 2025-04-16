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

void generate_auxiliar(t_object *cylinder, int *next, int slices, int *idx)
{
    int i = 0;

    while (i < slices)
    {
        *next = (i + 1) % slices;
        cylinder->triangles[(*idx)++] = 0;
        cylinder->triangles[(*idx)++] = 2 + i * 2;
        cylinder->triangles[(*idx)++] = 2 + (*next) * 2;
        i++;
    }
    i = 0;
    while (i < slices)
    {
        *next = (i + 1) % slices;
        cylinder->triangles[(*idx)++] = 1;
        cylinder->triangles[(*idx)++] = 3 + (*next) * 2;
        cylinder->triangles[(*idx)++] = 3 + i * 2;
        i++;
    }
}

void	generate_triangles(t_object *cylinder, int *idx, int *next, int slices)
{
	int	i;

	i = 0;
	while (i <= slices)
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

void generate_top_bottom(t_object *cylinder, int slices, int height, float radius)
{
    int idx[2];
    float angle;
    float x, z;

    idx[0] = 0;
    idx[1] = 0;
    cylinder->vertices[idx[0]] = (t_vector3){0, 0, 0};
    cylinder->normals[idx[0]] = (t_vector3){0, -1, 0};
    idx[0]++;
    cylinder->vertices[idx[0]] = (t_vector3){0, height, 0};
    cylinder->normals[idx[0]] = (t_vector3){0, 1, 0};
    idx[0]++;
    while (idx[1] <= slices)
    {
        angle = (float)idx[1] * (2 * M_PI / (float)slices);
        x = radius * cos(angle);
        z = radius * sin(angle);
        cylinder->vertices[idx[0]] = (t_vector3){x, 0, z};
        cylinder->normals[idx[0]] = (t_vector3){x, 0, z};
        idx[0]++;
        cylinder->vertices[idx[0]] = (t_vector3){x, height, z};
        cylinder->normals[idx[0]] = (t_vector3){x, 0, z};
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

	cylinder->vertices = (t_vector3 *)malloc(((slices + 2) * 2)
			* sizeof(t_vector3));
	cylinder->normals = (t_vector3 *)malloc(((slices + 2) * 2)
			* sizeof(t_vector3));
	cylinder->use_caps = 1;
	cylinder->vert_count = (slices + 1) * 2;
	cylinder->triangles = (int *)malloc((slices * 2 * 3) * 3 * sizeof(int));
	angle_step = 2 * M_PI / slices;
	generate_top_bottom(cylinder, slices, height, radius);
	idx = 0;
	generate_triangles(cylinder, &idx, &next, slices);
	cylinder->tri_count = idx;
}
