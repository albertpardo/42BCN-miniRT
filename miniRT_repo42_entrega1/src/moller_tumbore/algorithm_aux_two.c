/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_aux_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:13:44 by jaucarri          #+#    #+#             */
/*   Updated: 2024/09/03 17:02:28 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_intersection	getinter(int flag, t_intersection *new)
{
	static t_intersection	ret;

	if (flag == 1)
	{
		ret = *new;
	}
	return (ret);
}

t_vector3	getcol(int flag, t_vector3 *new)
{
	static t_vector3	ret;

	if (flag == 1)
		ret = *new;
	return (ret);
}

int	shadow(int flag, int val)
{
	static int	sh = 0;

	if (flag == 1)
		sh = val;
	return (sh);
}

void	getshadow(t_octree_node *node, t_ray ray, t_global *global, float dist)
{
	int				j;

	if (node->is_leaf == 0)
	{
		j = 0;
		while (j < 8)
		{
			if (ray_intersects_bbox(ray.origin, ray.direction,
					node->children[j]->bbox))
				getshadow(node->children[j], ray, global, dist);
			j++;
		}
	}
	else
		checkshadow(node, global, ray, dist);
}
