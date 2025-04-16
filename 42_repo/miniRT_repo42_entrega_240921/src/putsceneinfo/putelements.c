/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putelements.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:57:33 by apardo-m          #+#    #+#             */
/*   Updated: 2024/09/04 17:07:55 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	putpl(t_element *elem)
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
	printf(" %f,%f,%f", cyl->normvector.x, cyl->normvector.y, \
			cyl->normvector.z);
	printf(" %f %f", cyl->diameter, cyl->height);
	printf(" %f,%f,%f\n", cyl->f_rgb.x, cyl->f_rgb.y, cyl->f_rgb.z);
}

void	putelements(t_list *lst)
{
	t_element	*elem;

	printf("Elements Info:\n");
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
