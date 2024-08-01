/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iscoordinatestr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:41:00 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/01 18:01:31 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	iscoordinatestr(char *str)
{
	char	**astr;
	int		ans;

	ans = 0;
	astr = NULL;
	if (countchar(str, ',') == 2)
	{
		astr = ft_split(str, ',');
		if (astr && ft_astrlen(astr) == 3 && \
				isstrsgnfloat(astr[0], 0) && \
				isstrsgnfloat(astr[1], 0) && \
				isstrsgnfloat(astr[2], 0))
			ans = 1;
	}
	if (astr)
		freearrstr(astr);
	return (ans);
}
