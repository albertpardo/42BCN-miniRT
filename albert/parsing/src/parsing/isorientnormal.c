/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isorientnormal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:43:11 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/31 15:55:48 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	isorientnormal(char *str)
{
	char	**astr;
	int		ans;

	ans = 0;
	astr = NULL;
	if (countchar(str, ',') == 2)
	{
		astr = ft_split(str, ',');
		if (astr && ft_astrlen(astr) == 3 && \
				isstrfloatsgnone(astr[0]) && \
				isstrfloatsgnone(astr[1]) && \
				isstrfloatsgnone(astr[2]))
			ans = 1;
	}
	if (astr)
		freearrstr(astr);
	return (ans);
}
