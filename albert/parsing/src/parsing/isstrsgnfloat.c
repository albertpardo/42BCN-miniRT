/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isstrsgnfloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 07:17:05 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/28 09:57:53 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	isstrsgnfloat(char *str)
{
	size_t	len;
	size_t  i;

	i = 0;
	len = ft_strlen(str);
	if (*str == '+' || *str == '-')
		str++;
	if (isstrfloat(str) && *str != '.' && str[len - 1] != '.')
	{
		// caso 0 o 0.
		if (*str != '0' || (*str == '0' && str[1] == '.')) 
			return (1);
	}
	return (0);
}
