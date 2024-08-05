/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setcylinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:26:13 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/05 11:11:21 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 * setcylinder(char **aelement, t_sceneinf *scene)
 *
 * set memory for a 't_cylinder' type
 * 
 */ 

void	setcylinder(char **aelement, t_sceneinf *scene)
{
	t_list		*newnode;
	t_element	*newelem;
	t_cylinder	*newcyl;

	printf("set %s\n", aelement[0]);
	newelem = (t_element *) ft_calloc(1, sizeof(t_element));
	newcyl = (t_cylinder *) ft_calloc(1, sizeof(t_cylinder));
	if (newelem != NULL && newcyl != NULL)
	{
		//set newelem
		newelem->idelement = ft_strdup(aelement[0]);
		newelem->infoelement = newcyl;
		//set newcyl
		setvectorinelemtscene(aelement[1], &newcyl->center);	
		setvectorinelemtscene(aelement[2], &newcyl->normvector);	
		newcyl->diameter = ft_atof(aelement[3]);
		newcyl->height = ft_atof(aelement[4]);
		setvectorinelemtscene(aelement[5], &newcyl->f_rgb);
		//set newnode
		newnode = ft_lstnew(newelem);
		ft_lstadd_back(&(scene->elemlst), newnode);
	}
}
