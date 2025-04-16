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

t_quaternion calculate_quaternion(t_vector3 desired, t_vector3 actual) {
    t_quaternion q;
    float mag_desired = sqrtf(desired.x * desired.x + desired.y * desired.y + desired.z * desired.z);
    float mag_actual = sqrtf(actual.x * actual.x + actual.y * actual.y + actual.z * actual.z);

    desired.x /= mag_desired;
    desired.y /= mag_desired;
    desired.z /= mag_desired;

    actual.x /= mag_actual;
    actual.y /= mag_actual;
    actual.z /= mag_actual;
    float dot = desired.x * actual.x + desired.y * actual.y + desired.z * actual.z;
    if (dot < -0.999999) {
        t_vector3 perp = {1.0f, 0.0f, 0.0f};
        if (fabs(desired.x) > 0.9f) {
            perp = (t_vector3){0.0f, 1.0f, 0.0f};
        }
        t_vector3 axis = {
            desired.y * perp.z - desired.z * perp.y,
            desired.z * perp.x - desired.x * perp.z,
            desired.x * perp.y - desired.y * perp.x
        };
        float mag_axis = sqrtf(axis.x * axis.x + axis.y * axis.y + axis.z * axis.z);
        axis.x /= mag_axis;
        axis.y /= mag_axis;
        axis.z /= mag_axis;
        q.w = 0.0f;
        q.x = axis.x;
        q.y = axis.y;
        q.z = axis.z;
    } else {
        t_vector3 cross = {
            actual.y * desired.z - actual.z * desired.y,
            actual.z * desired.x - actual.x * desired.z,
            actual.x * desired.y - actual.y * desired.x
        };
        q.w = sqrtf((1.0f + dot) * 2.0f) * 0.5f;
        float s = 0.5f / q.w;
        q.x = cross.x * s;
        q.y = cross.y * s;
        q.z = cross.z * s;
    }

    return q;
}

void	rotate_camera(t_camera *cam, t_vector3 orient)
{
	t_vector3	forward;

	forward = (t_vector3){0,0,-1};
	cam->rotation = calculate_quaternion(orient, forward);
}

void	rotate_object(t_object *obj, t_vector3 normal)
{
	int				i;
	t_quaternion	rot;
	float			dist;

	normal.x *= -1;
	normal.z *= -1;
	dist = acosf(vector_dot(normal, (t_vector3){0, 1, 0}));
	rot = angleaxistoquaternion(dist,
			vector_cross((t_vector3){0, 1, 0}, normal));
	i = 0;
	while (i < obj->vert_count)
	{
		obj->vertices[i] = quaternionmultiplyvector3(rot,
				obj->vertices[i]);
		obj->normals[i] = quaternionmultiplyvector3(rot,
				obj->normals[i]);
		i++;
	}
}
