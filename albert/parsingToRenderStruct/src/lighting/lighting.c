/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:08:29 by jaucarri          #+#    #+#             */
/*   Updated: 2024/09/03 17:00:35 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	attenuate_no_cusp(float distance, float radius, float max_intensity,
		float falloff)
{
	float	s;
	float	s2;

	s = distance / radius;
	if (s >= 1.0)
		return (0.0);
	s2 = sqrt(s);
	return (max_intensity * sqrt(1 - s2) / (1 + falloff * s2));
}

t_vector3	illuminate(t_intersection intersection, t_pointlight light)
{
	float		r2;
	float		atenuation;
	t_vector3	lightint;
	float		smooth;

	r2 = vector3_distance(light.position, intersection.point);
	if (r2 <= 0 || r2 > light.radius)
		return ((t_vector3){0, 0, 0});
	lightint = (t_vector3){0.1, 0.1, 0.1};
	smooth = fmax(0.0,vector_dot(vector_normalize(intersection.normal),
				vector_normalize(vector_sub(intersection.point,
						light.position))));
	if (smooth > 0.99)
		smooth = 0;
	atenuation = 1 - (r2 / light.radius);
	if (atenuation < 0.0f)
		atenuation = 0.0f;
	lightint = vector_scale(lightint, light.intensity * atenuation * 2
			* smooth);
	lightint = vector_scale(lightint, 0.5 / M_PI);
	lightint.x = clamp(lightint.x, 0.0, 1.0);
	lightint.y = clamp(lightint.y, 0.0, 1.0);
	lightint.z = clamp(lightint.z, 0.0, 1.0);
	return (lightint);
}
