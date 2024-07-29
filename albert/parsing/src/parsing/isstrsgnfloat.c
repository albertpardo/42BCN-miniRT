/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isstrsgnfloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 07:17:05 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/29 12:39:24 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 * digits : X in [0,9] , Y in [1,9]
 *
 * Valid Cases:
 * - X
 * - YX
 */

int	isstrsgnfloat(char *str)
{
	size_t	len;
	size_t  i;
	char	*point;

	i = 0;
	if (*str == '+' || *str == '-')
		str++;
	len = ft_strlen(str);
	if (isstrfloat(str) && *str != '.' && str[len - 1] != '.')
	{
		point = ft_strchr(str, '.');
		//  X in [0,9] , Y in [1,9]
		// caso X , YX o 0.
//		if (*str != '0' || (*str == '0' && str[1] == '.')) 
		if (len == 1 || (len == 2 && *str != '0')) 
			return (1);
		//if ((len == 3 && str[1] == '.') || (len == 3 && *str != '0'))
		if (len == 3 && (str[1] == '.' || *str != '0'))
			return (1);
		if (point == NULL && *str != '0')
			return (1);
	}
	return (0);
}
