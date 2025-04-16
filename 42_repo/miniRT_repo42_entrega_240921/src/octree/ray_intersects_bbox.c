/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersects_bbox.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:20:22 by jaucarri          #+#    #+#             */
/*   Updated: 2024/09/02 16:13:02 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	ray_inter_bbox_init(t_vector3 origin, t_vector3 direction, \
	t_bbox bbox, float *values)
{
	values[0] = (bbox.min.x - origin.x) / direction.x;
	values[1] = (bbox.max.x - origin.x) / direction.x;
	if (values[0] > values[1])
	{
		values[2] = values[0];
		values[0] = values[1];
		values[1] = values[2];
	}
	values[3] = (bbox.min.y - origin.y) / direction.y;
	values[4] = (bbox.max.y - origin.y) / direction.y;
	if (values[3] > values[4])
	{
		values[2] = values[3];
		values[3] = values[4];
		values[4] = values[2];
	}
}

int	ray_intersects_bbox(t_vector3 origin, t_vector3 direction, t_bbox bbox)
{
	float	values[7];

	ray_inter_bbox_init(origin, direction, bbox, values);
	if ((values[0] > values[4]) || (values[3] > values[1]))
		return (0);
	if (values[3] > values[0])
		values[0] = values[3];
	if (values[4] < values[1])
		values[1] = values[4];
	values[5] = (bbox.min.z - origin.z) / direction.z;
	values[6] = (bbox.max.z - origin.z) / direction.z;
	if (values[5] > values[6])
	{
		values[2] = values[5];
		values[5] = values[6];
		values[6] = values[2];
	}
	if ((values[0] > values[6]) || (values[5] > values[1]))
		return (0);
	if (values[5] > values[0])
		values[0] = values[5];
	if (values[6] < values[1])
		values[1] = values[6];
	return (1);
}
