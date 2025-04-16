/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:09:09 by jaucarri          #+#    #+#             */
/*   Updated: 2024/08/04 14:09:10 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	vector3_distance(t_vector3 a, t_vector3 b)
{
	float	dx;
	float	dy;
	float	dz;

	dx = a.x - b.x;
	dy = a.y - b.y;
	dz = a.z - b.z;
	return (sqrt(dx * dx + dy * dy + dz * dz));
}

t_vector3	vector_divide(t_vector3 v, float divisor)
{
	return ((t_vector3){v.x / divisor, v.y / divisor, v.z / divisor});
}

t_vector3	transform_vector(t_vector3 v, float matrix[3][3])
{
	return ((t_vector3){
		v.x * matrix[0][0] + v.y * matrix[0][1] + v.z * matrix[0][2],
		v.x * matrix[1][0] + v.y * matrix[1][1] + v.z * matrix[1][2],
		v.x * matrix[2][0] + v.y * matrix[2][1] + v.z * matrix[2][2]
	});
}
