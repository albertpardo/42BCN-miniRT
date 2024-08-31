/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit_elementerr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 09:09:32 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/31 09:35:26 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	str is a duplicate of 'msg'
 *	
 * 	Go to the end of  'fd' file before close it
 *  Frees : 
 *		- pars.ln :  a file line 
 *		- pars.cln : line without spaces
 *		- pars.astr: pointer to string from pars.cln
 *  Put error message 'str' and exits
 *
 *  COMMENT : File must be read until the EOF to avoid problems whith the buffer used in get_next_line'
 */

void	free_exit_elementerr(char *msg, t_sceneinf *scn, t_pars *pars, int fd)
{
	char	*str;

	str = ft_strdup(msg);
	free_scnparsfd(scn, pars, fd);
	exiterror_line_freemsg(MSG_ERR_IN_FORMAT, str);
}

