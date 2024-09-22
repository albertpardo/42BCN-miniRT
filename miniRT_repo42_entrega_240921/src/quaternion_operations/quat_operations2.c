/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_operations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:00:37 by jaucarri          #+#    #+#             */
/*   Updated: 2024/09/16 14:48:32 by apardo-m         ###   ########.fr       */
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

t_vector3	operation( t_vector3 vone, t_vector3 vtwo)
{
	t_vector3	ans;

	ans.x = vone.y * vtwo.z - vone.z * vtwo.y;
	ans.y = vone.z * vtwo.x - vone.x * vtwo.z;
	ans.z = vone.x * vtwo.y - vone.y * vtwo.x;
	return (ans);
}

void	normal_by_magnitude(t_vector3 *vect, float mag)
{
	vect->x /= mag;
	vect->y /= mag;
	vect->z /= mag;
}

float	vectmodule(t_vector3 vect)
{
	return (sqrtf(vect.x * vect.x + vect.y * vect.y + vect.z * vect.z));
}
