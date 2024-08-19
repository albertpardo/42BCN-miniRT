/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:00:37 by jaucarri          #+#    #+#             */
/*   Updated: 2024/08/19 12:00:39 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_quaternion	quaternion_multiply(t_quaternion *q1, t_quaternion *q2)
{
	t_quaternion	result;

	result.w = q1->w * q2->w - q1->x * q2->x - q1->y * q2->y - q1->z * q2->z;
	result.x = q1->x * q2->w + q1->w * q2->x + q1->y * q2->z - q1->z * q2->y;
	result.y = q1->w * q2->y - q1->x * q2->z + q1->y * q2->w + q1->z * q2->x;
	result.z = q1->w * q2->z + q1->x * q2->y - q1->y * q2->x + q1->z * q2->w;
	return (result);
}

void	rotate_object(t_object *obj, t_vector3 normal)
{
	int				i;
	t_quaternion	rot;
	float			dist;

	normal.x = -normal.x;
	normal.z = -normal.z;
	dist = acos(vector_dot((t_vector3){0, 1, 0}, normal));
	rot = angleaxistoquaternion(dist,
			vector_normalize(vector_cross((t_vector3){0, 1, 0}, normal)));
	i = 0;
	while (i < obj->vert_count)
	{
		obj->vertices[i] = quaternionmultiplyvector3(conjugate(rot),
				obj->vertices[i]);
		obj->normals[i] = quaternionmultiplyvector3(conjugate(rot),
				obj->normals[i]);
		i++;
	}
}
