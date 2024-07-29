/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isstrfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 06:59:06 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/29 15:37:39 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	isstrfloat(char *str)
{
	char	*tmp;

	tmp = str;
	if (countchar(str, '.') < 2)
	{
		while (tmp != NULL && *tmp != '\0' && (ft_isdigit(*tmp) || *tmp == '.'))
			tmp++;
		if (tmp != str && *tmp == '\0')
			return (1);
	}
	return (0);
}
