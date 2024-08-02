#include "minirt.h"
#include "testaux.h"

/*
void deletecontent(void *content)
{
	t_vector3 *cont;

	cont = (t_vector3 *) content;

	printf("No delete: (%f, %f, %f)\n", cont->x, cont->y, cont->z);
}
*/

int	main(void)
{
	t_sceneinf	scene;

	//scene.elemlst = NULL;

	ft_memset(&scene, 0, sizeof(scene));
	putscene(&scene);
//	printf("\n--- Delete Lista ---\n");
//	ft_lstclear(&lst, deletecontent);
	return (0);
}
