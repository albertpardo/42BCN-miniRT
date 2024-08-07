/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freelinscenfdexitbymalloc.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:31:51 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/07 18:35:06 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	freelinscenfdexitbymalloc(char *line, t_sceneinf *scene, int fd)
{
	free(line);
	clearscene(scene);
	close(fd);
	exiterror(MALLOC_ERROR);
}
