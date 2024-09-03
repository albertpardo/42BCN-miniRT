/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:20:22 by jaucarri          #+#    #+#             */
/*   Updated: 2024/09/02 19:31:31 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	set_node_bounds(t_octree_node *node, t_bbox *child_bbox, \
	float mid[3], int i)
{
	if (i & 1)
		child_bbox->min.x = mid[0];
	else
		child_bbox->min.x = node->bbox.min.x;
	if (i & 1)
		child_bbox->max.x = node->bbox.max.x;
	else
		child_bbox->max.x = mid[0];
	if (i & 2)
		child_bbox->min.y = mid[1];
	else
		child_bbox->min.y = node->bbox.min.y;
	if (i & 2)
		child_bbox->max.y = node->bbox.max.y;
	else
		child_bbox->max.y = mid[1];
	if (i & 4)
		child_bbox->min.z = mid[2];
	else
		child_bbox->min.z = node->bbox.min.z;
	if (i & 4)
		child_bbox->max.z = node->bbox.max.z;
	else
		child_bbox->max.z = mid[2];
}

static void	subdivide_node(t_octree_node *node)
{
	float	mid[3];
	t_bbox	child_bbox;
	int		i;

	mid[0] = (node->bbox.min.x + node->bbox.max.x) * 0.5f;
	mid[1] = (node->bbox.min.y + node->bbox.max.y) * 0.5f;
	mid[2] = (node->bbox.min.z + node->bbox.max.z) * 0.5f;
	i = 0;
	while (i < 8)
	{
		child_bbox = node->bbox;
		set_node_bounds(node, &child_bbox, mid, i);
		node->children[i] = create_octree_node(&child_bbox);
		i++;
	}
	node->is_leaf = 0;
}

/*
static void	insert_to_childs(t_octree_node *node, t_triangle tri, t_object obj)
{
	int	j;

	j = -1;
	while (++j < 8)
	{
		if (triangle_in_bbox(tri, &node->children[j]->bbox, obj))
		{
			insert_triangle(node->children[j], tri, obj);
		}
	}
}
*/

static void	insert_to_childs(t_octree_node *node, t_triangle tri, t_object obj)
{
	int	j;

	j = -1;
	while (++j < 8)
	{
		if (triangle_in_bbox(tri, &node->children[j]->bbox))
		{
			insert_triangle(node->children[j], tri, obj);
		}
	}
}

/*
void	insert_triangle(t_octree_node *node, t_triangle tri, t_object obj)
{
	int	i[2];

	if (node->num_triangles < 42)
		node->triangles[node->num_triangles++] = tri;
	else
	{
		if (node->is_leaf)
		{
			subdivide_node(node);
			i[0] = -1;
			while (++i[0] < node->num_triangles)
			{
				i[1] = -1;
				while (++i[1] < 8)
					if (triangle_in_bbox(node->triangles[i[0]],
							&node->children[i[1]]->bbox, obj))
						insert_triangle(node->children[i[1]],
							node->triangles[i[0]], obj);
			}
			insert_to_childs(node, tri, obj);
		}
		else
			insert_to_childs(node, tri, obj);
	}
}
*/

void	insert_triangle(t_octree_node *node, t_triangle tri, t_object obj)
{
	int	i[2];

	if (node->num_triangles < 42)
		node->triangles[node->num_triangles++] = tri;
	else
	{
		if (node->is_leaf)
		{
			subdivide_node(node);
			i[0] = -1;
			while (++i[0] < node->num_triangles)
			{
				i[1] = -1;
				while (++i[1] < 8)
					if (triangle_in_bbox(node->triangles[i[0]],
							&node->children[i[1]]->bbox))
						insert_triangle(node->children[i[1]],
							node->triangles[i[0]], obj);
			}
			insert_to_childs(node, tri, obj);
		}
		else
			insert_to_childs(node, tri, obj);
	}
}
