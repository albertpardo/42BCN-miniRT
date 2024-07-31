/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isrgbstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:22:06 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/31 16:39:56 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
int	isstr(char *str)
{
	char	**astr;
	int		ans;

	ans = 0;
	astr = NULL;	
	if (countchar(str, ',') == 2)
	{
		astr = ft_split(str, ',');
		if (ft_astrlen(astr) == 3)
		{
			if (isstringvalueinpositiverange(astr[0], CHAR_MAX_RGB) && \
					isstringvalueinpositiverange(astr[1], CHAR_MAX_RGB) && \
					isstringvalueinpositiverange(astr[2], CHAR_MAX_RGB))
				ans = 1;
			else
				ft_printf("\n\t[RGB] Some value is not in range [0,255]\n\t");
		}
		else
			ft_printf("\n\t[RGB] No valid RGB components:Not right values\n\t");
	}
	else
		ft_printf("\n\t[RGB] No valid RGB components (No 2 commas)\n\t");
	if (astr != NULL)
		freearrstr(astr);
	return (ans);
}
*/

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
