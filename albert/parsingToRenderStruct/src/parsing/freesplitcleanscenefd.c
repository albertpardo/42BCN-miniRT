/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freesplitcleanscenefd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:23:24 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/07 18:28:31 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	freesplitcleanscenefd(char **arr, char *str, t_sceneinf *scn, int fd)
{
	freearrstr(arr);
	free(str);
	clearscene(scn);
	close(fd);
}
