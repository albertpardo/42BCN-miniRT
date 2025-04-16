/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:54:06 by jaucarri          #+#    #+#             */
/*   Updated: 2024/09/03 17:29:22 by apardo-m         ###   ########.fr       */
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
	shadowray = (t_ray){closest.point, lightdir};
	shadow(1, 0);
	getshadow(global->root, shadowray, global, \
			vector3_distance(light.position, closest.point));
	return (shadow(0, 0));
}

t_vector3	calculateilumination(t_global *global, t_intersection closest,
		t_vector3 intensity)
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
			ilu = illuminate(closest, global->lights[i]);
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

	closest.hit = 0;
	objcolor = getvisibleobjectcolor(&closest, global, ray);
	if (closest.hit)
	{
		intensity = ambient_light(0, (t_vector3){0, 0, 0});
		intensity = calculateilumination(global, closest, intensity);
	}
	else
		intensity = (t_vector3){1, 1, 1};
	intensity = vector_mul(intensity, objcolor);
	clampintensity(&intensity);
	return (intensity);
}
