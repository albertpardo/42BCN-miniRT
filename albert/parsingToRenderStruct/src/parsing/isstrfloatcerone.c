/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isstrfloatcerone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:58:07 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/01 16:08:00 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 * int	isstrfloatcerone(char *str)
 * 
 * checks if str is in range [0.0,1.0]
 */

int	isstrfloatcerone(char *str)
{
	float	num;

	if (isstrsgnfloat(str, 1))
	{
		num = ft_atof(str);
		if (num >= 0.0f && num <= 1.0f)
			return (1);
	}
	return (0);
}
