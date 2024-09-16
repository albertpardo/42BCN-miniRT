/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:14:43 by jaucarri          #+#    #+#             */
/*   Updated: 2024/08/05 15:14:54 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	setpixelscreen(float pixels[2], float ndc[2], float scale,
		t_global *global)
{
	pixels[0] = (2.0f * ndc[0] - 1.0f) * ((float)global->renderer->width
			/ global->renderer->height) * scale;
	pixels[1] = (1.0f - 2.0f * ndc[1]) * scale;
}

t_ray	create_primary_ray(t_global *global, int x, int y)
{
	t_ray		ray;
	float		pixelscreen[2];
	float		ndc[2];
	float		rotation_matrix[4][4];
	t_vector3	pixel_camera_space;

	ray.origin = global->camera->position;
	ndc[0] = (x + 0.5f) / (float)global->renderer->width;
	ndc[1] = (y + 0.5f) / (float)global->renderer->height;
	setpixelscreen(pixelscreen, ndc, tan((global->camera->fov * (PI / 180.0f))
			* 0.5f) * global->camera->near_plane, global);
	pixel_camera_space = (t_vector3){pixelscreen[0], pixelscreen[1],
		-global->camera->near_plane};
	quaternion_to_rotation_matrix(&global->camera->rotation, rotation_matrix);
	ray.direction = vector_normalize((t_vector3){rotation_matrix[0][0]
			* pixel_camera_space.x + rotation_matrix[0][1]
			* pixel_camera_space.y + rotation_matrix[0][2]
			* pixel_camera_space.z, rotation_matrix[1][0] * pixel_camera_space.x
			+ rotation_matrix[1][1] * pixel_camera_space.y
			+ rotation_matrix[1][2] * pixel_camera_space.z,
			rotation_matrix[2][0] * pixel_camera_space.x + rotation_matrix[2][1]
			* pixel_camera_space.y + rotation_matrix[2][2]
			* pixel_camera_space.z});
	return (ray);
}
