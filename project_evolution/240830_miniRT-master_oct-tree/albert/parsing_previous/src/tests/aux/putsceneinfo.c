#include "minirt.h"

static void	putsp(t_element *elem)
{
	t_sphere	*sph;

	sph = elem->infoelement;
	printf("\tscene->elemlst->idelement = %s\n", elem->idelement);
	printf("\t\tscene->elemlst->infoelement->center.x = %f\n", sph->center.x);
	printf("\t\tscene->elemlst->infoelement->center.y = %f\n", sph->center.y);
	printf("\t\tscene->elemlst->infoelement->center.z = %f\n", sph->center.z);
	printf("\t\tscene->elemlst->infoelement->diameter = %f\n", sph->diameter);
	printf("\t\tscene->elemlst->infoelement->f_rgb.x = %f\n", sph->f_rgb.x);
	printf("\t\tscene->elemlst->infoelement->f_rgb.y = %f\n", sph->f_rgb.y);
	printf("\t\tscene->elemlst->infoelement->f_rgb.z = %f\n", sph->f_rgb.z);
}

static void putpl(t_element *elem)
{
	t_plane		*pla;

	pla = elem->infoelement;
	printf("\tscene->elemlst->idelement = %s\n", elem->idelement);
	printf("\t\tscene->elemlst->infoelement->point.x = %f\n", pla->point.x);
	printf("\t\tscene->elemlst->infoelement->point.y = %f\n", pla->point.y);
	printf("\t\tscene->elemlst->infoelement->point.z = %f\n", pla->point.z);
	printf("\t\tscene->elemlst->infoelement->normal.x = %f\n", pla->normal.x);
	printf("\t\tscene->elemlst->infoelement->normal.y = %f\n", pla->normal.y);
	printf("\t\tscene->elemlst->infoelement->normal.z = %f\n", pla->normal.z);
	printf("\t\tscene->elemlst->infoelement->f_rgb.x = %f\n", pla->f_rgb.x);
	printf("\t\tscene->elemlst->infoelement->f_rgb.y = %f\n", pla->f_rgb.y);
	printf("\t\tscene->elemlst->infoelement->f_rgb.z = %f\n", pla->f_rgb.z);
}

static void	putcyl(t_element *elem)
{
	t_cylinder	*cyl;

	cyl = elem->infoelement;
	printf("\tscene->elemlst->idelement = %s\n", elem->idelement);
	printf("\t\tscene->elemlst->infoelement->center.x = %f\n", cyl->center.x);
	printf("\t\tscene->elemlst->infoelement->center.y = %f\n", cyl->center.y);
	printf("\t\tscene->elemlst->infoelement->center.z = %f\n", cyl->center.z);
	printf("\t\tscene->elemlst->infoelement->normvector.x = %f\n", cyl->normvector.x);
	printf("\t\tscene->elemlst->infoelement->normvector.y = %f\n", cyl->normvector.y);
	printf("\t\tscene->elemlst->infoelement->normvector.z = %f\n", cyl->normvector.z);
	printf("\t\tscene->elemlst->infoelement->diameter = %f\n", cyl->diameter);
	printf("\t\tscene->elemlst->infoelement->height = %f\n", cyl->height);
	printf("\t\tscene->elemlst->infoelement->f_rgb.x = %f\n", cyl->f_rgb.x);
	printf("\t\tscene->elemlst->infoelement->f_rgb.y = %f\n", cyl->f_rgb.y);
	printf("\t\tscene->elemlst->infoelement->f_rgb.z = %f\n", cyl->f_rgb.z);
}

static void	putelements(t_list *lst)
{
	t_element	*elem;

	if (!lst)
		printf("\tscene->elemlst : %p\n", lst);
	else
	{
 		while (lst != NULL)
		{
			elem = (t_element *) lst->content;
			if (ft_strncmp(elem->idelement, "sp", 2) == 0)
				putsp(elem);
			else if (ft_strncmp(elem->idelement, "pl", 2) == 0)
				putpl(elem);
			else if (ft_strncmp(elem->idelement, "cy", 2) == 0)
				putcyl(elem);
			else
				printf("TODO:  %s\n", elem->idelement);
			lst = lst->next;
		}
	}
}

void putsceneinfo(t_sceneinf *scene)
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
	}	
}
