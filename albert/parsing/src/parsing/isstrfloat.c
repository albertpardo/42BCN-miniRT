/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isstrfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 06:59:06 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/28 07:07:40 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
/*
static size_t	countchar(char *str, char c)
{
	size_t	i;
	char	*tmp;

	tmp = str;
	i = 0;
	while (tmp != NULL && *tmp != '\0')
	{
		if (*tmp == c)
			i++;
		tmp++;
	}
	return (i);
}
*/

/*
 * int isstrfloat(char *str)
 *
 * str is valid with or whitout one point and digits
 * No checks limits
 *
 */

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
