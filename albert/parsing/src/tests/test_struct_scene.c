#include "minirt.h"
#include "testaux.h"

static void	startAmbient(t_sceneinf *scene)
{
	scene->amb.isset = 1;
	scene->amb.id = ft_strdup("A");
	scene->amb.ratio = 0.2f;
	scene->amb.f_rgb.x = 255;
	scene->amb.f_rgb.y = 255;	
	scene->amb.f_rgb.z = 255;
}

static void	startCamara(t_sceneinf *scene)
{
	scene->cam.isset = 1;
	scene->cam.id = ft_strdup("C");
	scene->cam.viewpoint.x = -50.0f;
	scene->cam.viewpoint.y = 0;
	scene->cam.viewpoint.z = 20;
	scene->cam.orient.x = 0;
	scene->cam.orient.y = 0;
	scene->cam.orient.z = 1;
	scene->cam.fov = 70;
}

static void	startLight(t_sceneinf *scene)
{
	scene->light.isset = 1;
	scene->light.id = ft_strdup("L");
	scene->light.lightpoint.x = -40.0f;
	scene->light.lightpoint.y = 0;
	scene->light.lightpoint.z = 50.0f;
	scene->light.ratio = 0.6;
	scene->light.f_rgb.x = 10;
	scene->light.f_rgb.y = 0;
	scene->light.f_rgb.z = 255;
}

void clearscene(t_sceneinf *scene)
{
	free(scene->amb.id);
	free(scene->cam.id);
	free(scene->light.id);
	if (scene->elemlst)
		printf("TODO : free 'scene->elemlst'\n");
}

int	main(void)
{
	t_sceneinf	scene;

	//scene.elemlst = NULL;

	printf("==== Initiaize empty scene ====");
	ft_memset(&scene, 0, sizeof(scene));
	putscene(&scene);
	printf("\n ==== Initialize scene with Subject values ====");
	startAmbient(&scene);
	startCamara(&scene);
	startLight(&scene);
	putscene(&scene);
	printf("\n--- Clear Scene values alloc with malloc ---\n");
	clearscene(&scene);
	return (0);
}
