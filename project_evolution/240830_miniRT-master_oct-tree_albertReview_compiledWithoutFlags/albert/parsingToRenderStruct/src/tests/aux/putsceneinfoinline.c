#include "parsing.h"

static void	putsp(t_element *elem)
{
	t_sphere	*sph;

	sph = elem->infoelement;
	printf("  \"%s\"", elem->idelement);
	printf(" %f,%f,%f", sph->center.x, sph->center.y, sph->center.z);
	printf(" %f", sph->diameter);
	printf(" %f,%f,%f\n", sph->f_rgb.x, sph->f_rgb.y, sph->f_rgb.z);
}

static void putpl(t_element *elem)
{
	t_plane		*pla;

	pla = elem->infoelement;
	printf("  \"%s\"", elem->idelement);
	printf(" %f,%f,%f", pla->point.x, pla->point.y, pla->point.z);
	printf(" %f,%f,%f", pla->normal.x, pla->normal.y, pla->normal.z);
	printf(" %f,%f,%f\n", pla->f_rgb.x, pla->f_rgb.y, pla->f_rgb.z);
}

static void	putcyl(t_element *elem)
{
	t_cylinder	*cyl;

	cyl = elem->infoelement;
	printf("  \"%s\"", elem->idelement);
	printf(" %f,%f,%f", cyl->center.x, cyl->center.y, cyl->center.z);
	printf(" %f,%f,%f", cyl->normvector.x, cyl->normvector.y, cyl->normvector.z);
	printf(" %f %f", cyl->diameter, cyl->height);
	printf(" %f,%f,%f\n", cyl->f_rgb.x, cyl->f_rgb.y, cyl->f_rgb.z);
}

static void	putelements(t_list *lst)
{
	t_element	*elem;

	if (!lst)
		printf("  scene->elemlst : %p\n", lst);
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

void putsceneinfoinline(t_sceneinf *scene)
{
	printf("\n--- Info Scene ---\n");
	if (scene)
	{
		printf("Ambient Info:\n");
		printf("  %d", scene->amb.isset);
		if (scene->amb.id)
			printf(" \"%s\"", scene->amb.id);
		else
			printf(" %p", scene->amb.id);
		printf(" %f", scene->amb.ratio);
		printf(" %f,%f,%f\n", scene->amb.f_rgb.x, scene->amb.f_rgb.y, scene->amb.f_rgb.z);
		printf("Camara Info:\n");
		printf("  %d", scene->cam.isset);
		if (scene->cam.id)
			printf(" \"%s\"", scene->cam.id);
		else
			printf(" %p", scene->cam.id);
		printf(" %f,%f,%f", scene->cam.viewpoint.x, scene->cam.viewpoint.y, scene->cam.viewpoint.z);
		printf(" %f,%f,%f", scene->cam.orient.x, scene->cam.orient.y, scene->cam.orient.z);
		printf(" %f\n", scene->cam.fov);
		printf("Light Info:\n");
		printf("  %d", scene->light.isset);
		if (scene->light.id)
			printf(" \"%s\"", scene->light.id);
		else
			printf(" %p", scene->light.id);
		printf(" %f,%f,%f", scene->light.lightpoint.x, scene->light.lightpoint.y, scene->light.lightpoint.z);
		printf("  %f", scene->light.ratio);
		printf(" %f,%f,%f\n", scene->light.f_rgb.x, scene->light.f_rgb.y, scene->light.f_rgb.z);
		printf("Elements Info:\n");
		putelements(scene->elemlst);
	}	
}
