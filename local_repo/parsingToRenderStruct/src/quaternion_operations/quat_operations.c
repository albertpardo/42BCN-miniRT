/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:07:59 by jaucarri          #+#    #+#             */
/*   Updated: 2024/09/16 14:22:10 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	quaternion_to_matrix(t_quaternion q, float matrix[3][3])
{
	matrix[0][0] = 1 - 2 * q.y * q.y - 2 * q.z * q.z;
	matrix[0][1] = 2 * q.x * q.y - 2 * q.z * q.w;
	matrix[0][2] = 2 * q.x * q.z + 2 * q.y * q.w;
	matrix[1][0] = 2 * q.x * q.y + 2 * q.z * q.w;
	matrix[1][1] = 1 - 2 * q.x * q.x - 2 * q.z * q.z;
	matrix[1][2] = 2 * q.y * q.z - 2 * q.x * q.w;
	matrix[2][0] = 2 * q.x * q.z - 2 * q.y * q.w;
	matrix[2][1] = 2 * q.y * q.z + 2 * q.x * q.w;
	matrix[2][2] = 1 - 2 * q.x * q.x - 2 * q.y * q.y;
}

t_vector3	quaternionmultiplyvector3(t_quaternion q, t_vector3 v)
{
	t_vector3	qv;
	t_vector3	result;
	t_vector3	uv;
	t_vector3	uuv;

	qv = (t_vector3){q.x, q.y, q.z};
	uv.x = qv.y * v.z - qv.z * v.y;
	uv.y = qv.z * v.x - qv.x * v.z;
	uv.z = qv.x * v.y - qv.y * v.x;
	uuv.x = qv.y * uv.z - qv.z * uv.y;
	uuv.y = qv.z * uv.x - qv.x * uv.z;
	uuv.z = qv.x * uv.y - qv.y * uv.x;
	uv.x *= 2.0f * q.w;
	uv.y *= 2.0f * q.w;
	uv.z *= 2.0f * q.w;
	uuv.x *= 2.0f;
	uuv.y *= 2.0f;
	uuv.z *= 2.0f;
	result.x = v.x + uv.x + uuv.x;
	result.y = v.y + uv.y + uuv.y;
	result.z = v.z + uv.z + uuv.z;
	return (result);
}

void	quaternion_to_rotation_matrix(const t_quaternion *q, float matrix[4][4])
{
	matrix[0][0] = 1.0f - 2.0f * (q->y * q->y + q->z * q->z);
	matrix[0][1] = 2.0f * (q->x * q->y - q->w * q->z);
	matrix[0][2] = 2.0f * (q->x * q->z + q->w * q->y);
	matrix[0][3] = 0.0f;
	matrix[1][0] = 2.0f * (q->x * q->y + q->w * q->z);
	matrix[1][1] = 1.0f - 2.0f * (q->x * q->x + q->z * q->z);
	matrix[1][2] = 2.0f * (q->y * q->z - q->w * q->x);
	matrix[1][3] = 0.0f;
	matrix[2][0] = 2.0f * (q->x * q->z - q->w * q->y);
	matrix[2][1] = 2.0f * (q->y * q->z + q->w * q->x);
	matrix[2][2] = 1.0f - 2.0f * (q->x * q->x + q->y * q->y);
	matrix[2][3] = 0.0f;
	matrix[3][0] = 0.0f;
	matrix[3][1] = 0.0f;
	matrix[3][2] = 0.0f;
	matrix[3][3] = 1.0f;
}
