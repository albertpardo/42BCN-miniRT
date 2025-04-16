/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:09:00 by jaucarri          #+#    #+#             */
/*   Updated: 2024/08/04 14:09:01 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector3	vector_cross(t_vector3 a, t_vector3 b)
{
	t_vector3	val;

	val.x = a.y * b.z - a.z * b.y;
	val.y = a.z * b.x - a.x * b.z;
	val.z = a.x * b.y - a.y * b.x;
	return (val);
}

t_vector3	vector3_scale_add(t_vector3 a, float scale, t_vector3 b)
{
	t_vector3	scaled_a;

	scaled_a = vector_scale(a, scale);
	return (vector_add(scaled_a, b));
}

t_vector3	vector_normalize(t_vector3 v)
{
	float		length;
	t_vector3	val;

	length = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
	val.x = v.x / length;
	val.y = v.y / length;
	val.z = v.z / length;
	return (val);
}

float	vector_length(t_vector3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

float	vector_area(t_vector3 a, t_vector3 b, t_vector3 c)
{
	t_vector3	ab;
	t_vector3	ac;

	ab = vector_sub(b, a);
	ac = vector_sub(c, a);
	return (vector_length(vector_cross(ab, ac)) * 0.5f);
}
