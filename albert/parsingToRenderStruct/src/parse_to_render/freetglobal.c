
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
