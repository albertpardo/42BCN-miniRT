/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scnparsfd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 09:20:03 by apardo-m          #+#    #+#             */
/*   Updated: 2024/09/01 09:39:13 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
 * 	Go to the end of  'fd' file before close it
 *  Frees : 
 *		- pars.ln :  a file line 
 *		- pars.cln : line without spaces
 *		- pars.astr: pointer to string from pars.cln
 */

void	free_scnparsfd(t_sceneinf *scn, t_pars *pars, int fd)
{
	while (pars->ln != NULL)
	{
		free(pars->ln);
		pars->ln = get_next_line(fd);
	}
	close(fd);
	free(pars->cln);
	freearrstr(pars->astr);
	clearscene(scn);
}
