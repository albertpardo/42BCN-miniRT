/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:50:29 by jaucarri          #+#    #+#             */
/*   Updated: 2024/08/06 15:50:30 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	translate_object(t_object *object, t_vector3 translation)
{
	int	i;

	i = 0;
	while (i < object->vert_count)
	{
		object->vertices[i].x += translation.x;
		object->vertices[i].y += translation.y;
		object->vertices[i].z += translation.z;
		i++;
	}
}
