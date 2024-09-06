/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_octree_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:20:22 by jaucarri          #+#    #+#             */
/*   Updated: 2024/08/30 16:20:23 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_octree_node	*create_octree_node(const t_bbox *bbox)
{
	t_octree_node	*node;
	int				i;

	node = (t_octree_node *)malloc(sizeof(t_octree_node));
	node->bbox = *bbox;
	node->triangles = (t_triangle *)malloc(42 * sizeof(t_triangle));
	node->num_triangles = 0;
	node->is_leaf = 1;
	i = 0;
	while (i < 8)
		node->children[i++] = NULL;
	return (node);
}
