/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:08:49 by jaucarri          #+#    #+#             */
/*   Updated: 2024/08/04 14:08:50 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector3	vector_add(t_vector3 a, t_vector3 b)
{
	t_vector3	val;

	val.x = a.x + b.x;
	val.y = a.y + b.y;
	val.z = a.z + b.z;
	return (val);
}

t_vector3	vector_sub(t_vector3 a, t_vector3 b)
{
	t_vector3	val;

	val.x = a.x - b.x;
	val.y = a.y - b.y;
	val.z = a.z - b.z;
	return (val);
}

t_vector3	vector_scale(t_vector3 v, float scale)
{
	t_vector3	val;

	val.x = v.x * scale;
	val.y = v.y * scale;
	val.z = v.z * scale;
	return (val);
}

float	vector_dot(t_vector3 a, t_vector3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vector3	vector_mul(t_vector3 a, t_vector3 b)
{
	t_vector3	val;

	val.x = a.x * b.x;
	val.y = a.y * b.y;
	val.z = a.z * b.z;
	return (val);
}
