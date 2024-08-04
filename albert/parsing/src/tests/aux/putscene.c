#include "minirt.h"

static void	putelements(t_list *elemlst)
{
	if (!elemlst)
		printf("\tscene->elemlst : %p\n", elemlst);
	else
		printf("\tTODO scene->elemlst\n");

}

void putscene(t_sceneinf *scene)
{
	printf("\n--- Info Scene ---\n");
	if (scene)
	{
		printf("Ambient Info:\n");
		printf("\tscene->amb.isset = %d\n", scene->amb.isset);
		if (scene->amb.id)
			printf("\tscene->amb.id = \"%s\"\n", scene->amb.id);
		else
			printf("\tscene->amb.id = %p\n", scene->amb.id);
		printf("\tscene->amb.ratio = %f\n", scene->amb.ratio);
		printf("\tscene->amb.f_rgb info:\n");
		printf("\t\tscene->amb.f_rgb.r = %f\n", scene->amb.f_rgb.x);
		printf("\t\tscene->amb.f_rgb.g = %f\n", scene->amb.f_rgb.y);
		printf("\t\tscene->amb.f_rgb.b = %f\n", scene->amb.f_rgb.z);
		printf("Camara Info:\n");
		printf("\tscene->cam.isset = %d\n", scene->cam.isset);
		if (scene->cam.id)
			printf("\tscene->cam.id = \"%s\"\n", scene->cam.id);
		else
			printf("\tscene->cam.id = %p\n", scene->cam.id);
		printf("\tscene->cam.viewpoint info:\n");
		printf("\t\tscene->cam.viewpoint.x = %f\n", scene->cam.viewpoint.x);
		printf("\t\tscene->cam.viewpoint.y = %f\n", scene->cam.viewpoint.y);
		printf("\t\tscene->cam.viewpoint.z = %f\n", scene->cam.viewpoint.z);
		printf("\tscene->cam.orient info:\n");
		printf("\t\tscene->cam.orient.x = %f\n", scene->cam.orient.x);
		printf("\t\tscene->cam.orient.y = %f\n", scene->cam.orient.y);
		printf("\t\tscene->cam.orient.z = %f\n", scene->cam.orient.z);
		printf("\tscene->cam.fov = %f\n", scene->cam.fov);
		printf("Light Info:\n");
		printf("\tscene->light.isset = %d\n", scene->light.isset);
		if (scene->light.id)
			printf("\tscene->light.id = \"%s\"\n", scene->light.id);
		else
			printf("\tscene->light.id = %p\n", scene->light.id);
		printf("\tscene->light.lightpoint info:\n");
		printf("\t\tscene->light.lightpoint.x = %f\n", scene->light.lightpoint.x);
		printf("\t\tscene->light.lightpoint.y = %f\n", scene->light.lightpoint.y);
		printf("\t\tscene->light.lightpoint.z = %f\n", scene->light.lightpoint.z);
		printf("\tscene->light.ratio = %f\n", scene->light.ratio);
		printf("\tscene->light.f_rgb info:\n");
		printf("\t\tscene->light.f_rgb.r = %f\n", scene->light.f_rgb.x);
		printf("\t\tscene->light.f_rgb.g = %f\n", scene->light.f_rgb.y);
		printf("\t\tscene->light.f_rgb.b = %f\n", scene->light.f_rgb.z);
		printf("Elements Info:\n");
		putelements(scene->elemlst);
/*	
		if (!scene->elemlst)
			printf("\tscene->elemlst : %p\n", scene->elemlst);
		else
			printf("\tTODO scene->elemlst\n");
*/
	}	
}
