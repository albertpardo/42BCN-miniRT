/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit_normalcero.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 09:40:15 by apardo-m          #+#    #+#             */
/*   Updated: 2024/09/01 09:39:00 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
 *  COMMENT : File must be read until the EOF to avoid problems whith the 
 *  buffer used in get_next_line'
 */

void	free_exit_normalcero(char *msg, t_sceneinf *scn, t_pars *pars, int fd)
{
	char	*str;

	str = ft_strdup(msg);
	free_scnparsfd(scn, pars, fd);
	exiterror_line_freemsg(MSG_ERR_NORM_VECTOR_CERO, str);
}
