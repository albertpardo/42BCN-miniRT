/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setsphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:32:12 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/05 11:13:10 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 * 	setsphere(char **aelement, t_sceneinf *scene)
 *
 * set memory for a 't_sphere' type
 */

void	setsphere(char **aelement, t_sceneinf *scene)
{
	t_list		*newnode;
	t_element	*newelem;
	t_sphere	*newsph;

	printf("set %s\n", aelement[0]);
	newelem = (t_element *) ft_calloc(1, sizeof(t_element));
	newsph = (t_sphere *) ft_calloc(1, sizeof(t_sphere));
	if (newelem != NULL && newsph != NULL)
	{
		//set newelem
		newelem->idelement = ft_strdup(aelement[0]);
		newelem->infoelement = newsph;
		//set newsph
		setvectorinelemtscene(aelement[1], &newsph->center);	
		newsph->diameter = ft_atof(aelement[2]);
		setvectorinelemtscene(aelement[3], &newsph->f_rgb);
		//set newnode
		newnode = ft_lstnew(newelem);
		ft_lstadd_back(&(scene->elemlst), newnode);
	}
}
