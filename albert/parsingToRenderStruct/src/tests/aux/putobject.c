#include "miniRT.h"

void	putobject(t_object *obj)
{
	printf("\n-- putobject-- \n");
	printf("triangles = %d\n",*obj->triangles);
	printf("*vertices = %p\n", obj->vertices);
	printf("*normals = %p\n", obj->normals);
	printf("use_caps = %d\n", obj->use_caps);
	printf("vert_count = %d\n", obj->vert_count);
	printf("tri_count = %d\n", obj->tri_count);
	printf("color = (%f, %f, %f)\n", obj->color.x, obj->color.y, obj->color.z);
}
