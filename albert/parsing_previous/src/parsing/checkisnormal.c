/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkisnormal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:45:45 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/31 10:09:31 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* 
 * Returns:
 * VALID_ELEMENT  - All correct
 * ERR_IN_FORMAT  - for no valid format
 * ERR_NORM_VECTOR_CERO - When x,y,z are all 0.0f
 *
 */

int	checkisnormal(char *str)
{
	char	**astr;
	int		ans;

	ans = ERR_IN_FORMAT;
	astr = NULL;
	if (countchar(str, ',') == 2)
	{
		astr = ft_split(str, ',');
		if (astr && ft_astrlen(astr) == 3 && isstrfloatsgnone(astr[0]) && \
				isstrfloatsgnone(astr[1]) && isstrfloatsgnone(astr[2]))
		{
			if (ft_atof(astr[0]) == 0.0f && ft_atof(astr[1]) == 0.0f && \
							ft_atof(astr[2]) == 0.0f)
				ans = ERR_NORM_VECTOR_CERO;
			else
				ans = VALID_ELEMENT;
		}
	}
	if (astr)
		freearrstr(astr);
	return (ans);
}
