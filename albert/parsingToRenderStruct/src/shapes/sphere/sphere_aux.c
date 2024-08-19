/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 09:38:11 by jaucarri          #+#    #+#             */
/*   Updated: 2024/08/18 09:38:13 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	spherenormalscalc(t_object *sphere, t_vector3 facenorm, int i)
{
	sphere->normals[sphere->triangles[i
		* 3]] = vector_add(sphere->normals[sphere->triangles[i * 3]],
			facenorm);
	sphere->normals[sphere->triangles[i * 3
		+ 1]] = vector_add(sphere->normals[sphere->triangles[i * 3 + 1]],
			facenorm);
	sphere->normals[sphere->triangles[i * 3
		+ 2]] = vector_add(sphere->normals[sphere->triangles[i * 3 + 2]],
			facenorm);
}
