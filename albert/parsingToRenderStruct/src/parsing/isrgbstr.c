/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isrgbstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:22:06 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/19 17:32:34 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	isrgbstr(char *str)
{
	char	**astr;
	int		ans;

	ans = 0;
	astr = NULL;
	if (countchar(str, ',') == 2)
	{
		astr = ft_split(str, ',');
		if (astr && ft_astrlen(astr) == 3 && \
				isstringvalueinpositiverange(astr[0], CHAR_MAX_RGB) && \
				isstringvalueinpositiverange(astr[1], CHAR_MAX_RGB) && \
				isstringvalueinpositiverange(astr[2], CHAR_MAX_RGB))
			ans = 1;
	}
	if (astr)
		freearrstr(astr);
	return (ans);
}
