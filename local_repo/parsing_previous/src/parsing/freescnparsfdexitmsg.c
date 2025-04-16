/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freescnparsfdexitmsg.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:03:51 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/31 10:19:12 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	freescnparsfdexitmsg(char *msg, t_sceneinf *scn, t_pars *pars, int fd)
{
	char	*str;

	str = ft_strdup(msg);
	while (pars->ln != NULL)
	{
		free(pars->ln);
		pars->ln = get_next_line(fd);
	}
	close(fd);
	free(pars->cln);
	freearrstr(pars->astr);
	clearscene(scn);
	exiterrorfreemsg(str);
}
