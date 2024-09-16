/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:00:37 by jaucarri          #+#    #+#             */
/*   Updated: 2024/09/13 14:46:24 by apardo-m         ###   ########.fr       */
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

static t_vector3	operation( t_vector3 vone, t_vector3 vtwo)
{
	t_vector3	ans;

	ans.x = vone.y * vtwo.z - vone.z * vtwo.y;
	ans.y = vone.z * vtwo.x - vone.x * vtwo.z;
	ans.z = vone.x * vtwo.y - vone.y * vtwo.x;
	return (ans);
}

static void	normal_by_magnitude(t_vector3 *vect, float mag)
{
	vect->x /= mag;
	vect->y /= mag;
	vect->z /= mag;
}

static float	vectmodule(t_vector3 vect)
{
	return (sqrtf(vect.x * vect.x + vect.y * vect.y + vect.z * vect.z));
}

/*
 * get_q1(t_vector3 desired)
 *
 * Used when dot < -0.999999
 */

static void	get_q1(t_quaternion *q, t_vector3 desired)
{
	float			mag_axis;
	t_vector3		axis;
	t_vector3		perp;

	perp = (t_vector3){1.0f, 0.0f, 0.0f};
	if (fabs(desired.x) > 0.9f)
		perp = (t_vector3){0.0f, 1.0f, 0.0f};
	axis = operation(desired, perp);
	mag_axis = vectmodule(axis);
	normal_by_magnitude(&axis, mag_axis);
	q->w = 0.0f;
	q->x = axis.x;
	q->y = axis.y;
	q->z = axis.z;
}

/*
 * get_q2(t_quaternion *q, t_vector3 act, t_vector3 desir, float dot)
 *
 * Used when dot >= -0.999999
 */

static void	get_q2(t_quaternion *q, t_vector3 act, t_vector3 desir, float dot)
{
	t_vector3		cross;
	float			s;

	cross = operation(act, desir);
	q->w = sqrtf((1.0f + dot) * 2.0f) * 0.5f;
	s = 0.5f / q->w;
	q->x = cross.x * s;
	q->y = cross.y * s;
	q->z = cross.z * s;
}

t_quaternion	calculate_quaternion(t_vector3 desired, t_vector3 actual)
{
	t_quaternion	q;
	float			mag_desired;
	float			mag_actual;
	float			dot;

	mag_desired = vectmodule(desired);
	mag_actual = vectmodule(actual);
	normal_by_magnitude(&desired, mag_desired);
	normal_by_magnitude(&actual, mag_actual);
	dot = desired.x * actual.x + desired.y * actual.y + desired.z * actual.z;
	if (dot < -0.999999)
		get_q1(&q, desired);
	else
		get_q2(&q, actual, desired, dot);
	return (q);
}

void	rotate_camera(t_camera *cam, t_vector3 orient)
{
	t_vector3	forward;

	forward = (t_vector3){0, 0, -1};
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
