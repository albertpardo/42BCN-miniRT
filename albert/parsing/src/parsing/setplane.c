/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setplane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:30:28 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/05 13:26:38 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 * setplane(char **aelement, t_sceneinf *scene)
 *
 * set memory for a 't_plane' type
 */

void	setplane(char **aelement, t_sceneinf *scene)
{
	t_list		*newnode;
	t_element	*newelem;
	t_plane		*newpl;

	printf("set %s\n", aelement[0]);
	newelem = (t_element *) ft_calloc(1, sizeof(t_element));
	newpl = (t_plane *) ft_calloc(1, sizeof(t_plane));
	if (newelem != NULL && newpl != NULL)
	{
		newnode = ft_lstnew(newelem);
		ft_lstadd_back(&(scene->elemlst), newnode);
		newelem->idelement = ft_strdup(aelement[0]);
		newelem->infoelement = newpl;
		setvectorinelemtscene(aelement[1], &newpl->point);
		setvectorinelemtscene(aelement[2], &newpl->normal);
		setvectorinelemtscene(aelement[3], &newpl->f_rgb);
	}
}
