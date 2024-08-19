/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitifnotvalidfiletype.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:16:47 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/19 17:27:51 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
 *	fname 	: file name
 *	fext	: file extension
 *	msg		: message to print 
 */

void	exitifnotvalidfiletype(char *fname, char *fext, char *msg)
{
	int	lfn;
	int	lext;

	lfn = ft_strlen(fname);
	lext = ft_strlen(fext);
	if (lfn < (lext + 1) || ft_strncmp(&fname[lfn - lext], fext, lext))
		exiterror(msg);
}
