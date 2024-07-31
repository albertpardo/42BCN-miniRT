/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isrgbstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:22:06 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/31 12:10:38 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
int	isrgbstr(char *rgbstr)
{
	char	**argb;
	int		ans;

	ans = 0;
	argb = NULL;	
	if (countchar(rgbstr, ',') == 2)
	{
		argb = ft_split(rgbstr, ',');
		if (ft_astrlen(argb) == 3)
		{
			if (isstringvalueinpositiverange(argb[0], CHAR_MAX_RGB) && \
					isstringvalueinpositiverange(argb[1], CHAR_MAX_RGB) && \
					isstringvalueinpositiverange(argb[2], CHAR_MAX_RGB))
				ans = 1;
			else
				ft_printf("\n\t[RGB] Some value is not in range [0,255]\n\t");
		}
		else
			ft_printf("\n\t[RGB] No valid RGB components:Not right values\n\t");
	}
	else
		ft_printf("\n\t[RGB] No valid RGB components (No 2 commas)\n\t");
	if (argb != NULL)
		freearrstr(argb);
	return (ans);
}
*/

int	isrgbstr(char *rgbstr)
{
	char	**argb;
	int		ans;

	ans = 0;
	argb = NULL;
	if (countchar(rgbstr, ',') == 2)
	{
		argb = ft_split(rgbstr, ',');
		if (argb && ft_astrlen(argb) == 3 && \
				isstringvalueinpositiverange(argb[0], CHAR_MAX_RGB) && \
				isstringvalueinpositiverange(argb[1], CHAR_MAX_RGB) && \
				isstringvalueinpositiverange(argb[2], CHAR_MAX_RGB))
			ans = 1;
	}
	if (argb)
		freearrstr(argb);
	return (ans);
}
