/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:08:18 by jaucarri          #+#    #+#             */
/*   Updated: 2024/09/01 11:51:55 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <time.h>
# include <assert.h>
# include <unistd.h>

# include "vector3.h"

//# define PI 22/7   Put result in next line
# define PI 3.1428571428571
# define EPSILON 0.000001

typedef struct vector2
{
	float	x;
	float	y;
}	t_vector2;

typedef struct s_quaternion
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_quaternion;

typedef struct s_camera
{
	t_vector3		position;
	t_quaternion	rotation;
	float			near_plane;
	float			far_plane;
	float			fov;
}	t_camera;

typedef struct s_object
{
	int			*triangles;
	t_vector3	*vertices;
	t_vector3	*normals;
	int			use_caps;
	int			vert_count;
	int			tri_count;
	t_vector3	color;
	t_vector3	normal;
	t_vector3	planepos;
	int			isplane;
}	t_object;

//octree
typedef struct s_triangle
{
	int			index0;
	int			index1;
	int			index2;
	t_vector3	vert0;
	t_vector3	vert1;
	t_vector3	vert2;
	t_vector3	norm0;
	t_vector3	norm1;
	t_vector3	norm2;
	int			usecaps;
	int			objid;
}	t_triangle;

/*
 * typedef struct s_bbox
 * 
 * min : Minimum coordinates (x, y, z) 
 * max : Maximum coordinates (x, y, z)
 */

typedef struct s_bbox
{
	t_vector3	min;
	t_vector3	max;
}	t_bbox;

typedef struct s_octree_node
{
	t_bbox					bbox;
	struct s_octree_node	*children[8];
	t_triangle				*triangles;
	int						num_triangles;
	int						is_leaf;
}	t_octree_node;

//
typedef struct s_pointlight
{
	t_vector3	position;
	float		radius;
	float		intensity;
}	t_pointlight;

typedef struct s_renderer
{
	void	*mlx;
	void	*win;
	void	*img;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*addr;
	int		width;
	int		height;
	int		*framebuffer;
}	t_renderer;

typedef struct s_global
{
	t_renderer		*renderer;
	t_camera		*camera;
	t_object		*objects;
	int				object_count;
	t_pointlight	*lights;
	int				light_count;
	t_octree_node	*root;
}	t_global;

typedef struct s_ray
{
	t_vector3	origin;
	t_vector3	direction;
}	t_ray;

typedef struct s_intersection
{
	int			hit;
	int			objindex;
	float		distance;
	t_vector3	point;
	t_vector3	normal;
	t_vector3	rawnormal;
	float		tnear;
	t_vector3	vert[3];
}	t_intersection;

typedef struct s_calcs
{
	t_vector3		edge1;
	t_vector3		edge2;
	t_vector3		h;
	float			a;
	float			f;
	t_vector3		s;
	float			u;
	t_vector3		q;
	float			v;
	float			t;
	t_intersection	result;
	t_vector3		normals[3];
	int				indexes[3];
	int				use_caps;
	t_vector3		generalnormal;
}	t_calcs;

float			clamp(float value, float min, float max);
t_vector3		illuminate(t_ray ray, t_intersection intersection, \
		t_pointlight light);
t_intersection	intersectrayobject(t_ray ray, t_object *object);
t_vector3		getvisibleobjectcolor(t_intersection *closest, \
		t_global *global, int objectcount, t_ray ray);
void			quaternion_to_rotation_matrix(const t_quaternion *q, \
		float matrix[4][4]);
t_vector3		quaternionmultiplyvector3(t_quaternion q, t_vector3 v);
void			quaternion_to_matrix(t_quaternion q, float matrix[3][3]);
t_quaternion	angleaxistoquaternion(float angle, t_vector3 axis);
t_ray			create_primary_ray(t_global *global, int x, int y);
t_vector3		render(t_ray ray, t_global *global);
void			render_scene(t_global *global);
void			generate_cylinder(t_object *cylinder, float radius, \
		float height, int slices);
void			create_plane_mesh(t_object *plane, float width, float height);
void			create_sphere_mesh(t_object *sphere, float radius);
t_vector3		vector_add(t_vector3 a, t_vector3 b);
t_vector3		vector_sub(t_vector3 a, t_vector3 b);
t_vector3		vector_scale(t_vector3 v, float scale);
float			vector_dot(t_vector3 a, t_vector3 b);
t_vector3		vector_mul(t_vector3 a, t_vector3 b);
t_vector3		vector_cross(t_vector3 a, t_vector3 b);
t_vector3		vector3_scale_add(t_vector3 a, float scale, t_vector3 b);
t_vector3		vector_normalize(t_vector3 v);
float			vector_length(t_vector3 v);
float			vector_area(t_vector3 a, t_vector3 b, t_vector3 c);
void			translate_object(t_object *object, t_vector3 translation);
float			vector3_distance(t_vector3 a, t_vector3 b);
t_vector3		vector_divide(t_vector3 v, float divisor);
t_quaternion	conjugate(t_quaternion q);
void			initvertexs(t_vector3 vertex[7], t_object object, int i[5], \
		t_triangle tri);
void			initnormals(t_vector3 *vert, int caps[5], t_calcs *values);
void			spherenormalscalc(t_object *sphere, t_vector3 facenorm, int i);
t_quaternion	quaternion_multiply(t_quaternion *q1, t_quaternion *q2);
void			rotate_object(t_object *obj, t_vector3 normal);
t_vector3		ambient_light(int flag, t_vector3 new);
t_vector3		transform_vector(t_vector3 v, float matrix[3][3]);
void			rotate_camera(t_camera *cam, t_vector3 orient);
void			create_octree(t_global *global);
t_octree_node	*find_nearest_node_with_triangles(t_octree_node *node, \
		const t_ray *ray);
int				ray_intersects_bbox(t_vector3 origin, t_vector3 direction, \
		t_bbox bbox);
void			getshadow(t_octree_node *node, t_ray ray, t_global *global, \
		float dist);
t_intersection	getinter(int flag, t_intersection *new);
int				shadow(int flag, int val);
t_vector3		getcol(int flag, t_vector3 *new);
void			intersectioncheck(t_intersection intersection, t_triangle tri, \
		t_global *global);
void			checkshadow(t_octree_node *node, t_global *global, t_ray ray, \
		float dist);
void			checkcolor(t_octree_node *node, t_global *global, t_ray ray);
t_intersection	rayintersectstriangle(t_vector3 og, t_vector3 dir, \
		t_vector3 *vert, int caps[5]);
void			insert_triangle(t_octree_node *node, t_triangle tri, \
		t_object obj);

float			project_onto_axis(t_vector3 v, t_vector3 axis);
int				ranges_overlap(float min1, float max1, float min2, float max2);
int				first_overlap(t_triangle triangle, t_vector3 *bbox_axes, \
		float projection, t_vector3 *bbox_vertices);
int				second_overlap(t_vector3 triangle_edges, t_vector3 bbox_axes, \
		t_triangle triangle, t_vector3 *bbox_vertices);
t_octree_node	*create_octree_node(const t_bbox *bbox);
int				triangle_in_bbox(const t_triangle triangle, \
		const t_bbox *bbox, t_object obj);
void			insert_triangle(t_octree_node *node, t_triangle tri, t_object obj);

#endif
