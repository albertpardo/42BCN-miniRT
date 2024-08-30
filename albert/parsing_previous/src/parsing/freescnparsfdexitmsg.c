/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freescnparsfdexitmsg.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:03:51 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/30 19:17:08 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 * freescnparsfdexitmsg(char *msg, t_sceneinf *scn, t_pars *pars, int fd)
 *
 *	str is a duplicate of 'msg'
 *	
 * 	Go to the end of  'fd' file before close it
 *  Frees : 
 *		- pars.ln :  a file line 
 *		- pars.cln : line without spaces
 *		- pars.astr: pointer to string from pars.cln
 *  Put error message 'str' and exits
 *
 *  COMMENT : File must be read until the EOF to avoid problems whith the buffer used in ǵet_next_line'
 */

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
