/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freetglobal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:07:08 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/21 15:07:12 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parstoglobal.h"

static void	freeobjects(t_global *glb)
{
	int	i;

	i = -1;
	while (++i < glb->object_count)
	{
		free(glb->objects[i].triangles);
		free(glb->objects[i].vertices);
		free(glb->objects[i].normals);
	}
	free(glb->objects);
}

void	freetglobal(t_global *glb)
{
	free(glb->camera);
	free(glb->lights);
	freeobjects(glb);
}
