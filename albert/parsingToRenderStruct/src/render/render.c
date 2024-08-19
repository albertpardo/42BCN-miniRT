/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:54:06 by jaucarri          #+#    #+#             */
/*   Updated: 2024/08/04 17:54:07 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	clampintensity(t_vector3 *intensity)
{
	intensity->x = clamp(intensity->x, 0.0, 1.0);
	intensity->y = clamp(intensity->y, 0.0, 1.0);
	intensity->z = clamp(intensity->z, 0.0, 1.0);
}

int	isshadowed(t_vector3 lightdir, t_intersection closest, t_global *global,
		t_pointlight light)
{
	t_ray			shadowray;
	t_intersection	shadowintersection;
	int				j;

	j = 0;
	shadowintersection.hit = 0;
	shadowray = (t_ray){vector_add(closest.point,
			vector_scale(vector_normalize(lightdir), 0.001)), lightdir};
	while (j < global->object_count)
	{
		shadowintersection = intersectrayobject(shadowray, &global->objects[j]);
		if (shadowintersection.hit
			&& shadowintersection.distance < vector3_distance(light.position,
				closest.point))
		{
			return (1);
		}
		j++;
	}
	return (0);
}

t_vector3	calculateilumination(t_global *global, t_intersection closest,
		t_ray ray, t_vector3 intensity)
{
	int			i;
	t_vector3	lightdir;
	t_vector3	ilu;

	i = 0;
	while (i < global->light_count)
	{
		lightdir = vector_normalize(vector_sub(global->lights[i].position,
					closest.point));
		if (!isshadowed(lightdir, closest, global, global->lights[i]))
		{
			ilu = illuminate(ray, closest, global->lights[i]);
			lightdir = vector_sub(global->lights[i].position, closest.point);
			lightdir = vector_normalize(lightdir);
			intensity = vector_add(intensity, ilu);
			clampintensity(&intensity);
		}
		i++;
	}
	return (intensity);
}

t_vector3	render(t_ray ray, t_global *global)
{
	t_intersection	closest;
	t_vector3		objcolor;
	t_vector3		intensity;
	t_vector3		lightdir;

	closest.hit = 0;
	objcolor = getvisibleobjectcolor(&closest, global->objects,
			global->object_count, ray);
	if (closest.hit)
	{
		intensity = ambient_light(0, (t_vector3) {0 , 0, 0});
		intensity = calculateilumination(global, closest, ray, intensity);
	}
	else
		intensity = (t_vector3){1, 1, 1};
	intensity = vector_mul(intensity, objcolor);
	clampintensity(&intensity);
	return (intensity);
}
