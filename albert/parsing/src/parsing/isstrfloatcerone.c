/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isstrfloatcerone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:58:07 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/27 16:41:26 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

/*
 * int isstrfloat(char *str)
 *
 * str is valid with or whitout one point and digits
 * No checks limits
 *
 */

static int	isstrfloat(char *str)
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

/*
 * int	isstrfloatcerone(char *str)
 * 
 * checks if str is in range [0.0,1.0]
 * str is valid with or whitout one point and digitis
 * Cases: ( 'X' from 1 to 9, '*' from 1 to any number of digits in range [0,9])
 * 
 * No limit for number of digits after point
 * No valid start or end point: 
 *	- '.*'
 *	- '*.'
 *
 * Cases: 
 * 	- '1.0'  		VALID
 * 	- '1'			VALID
 * 	- '0'			VALID
 * 	- '0.0'			VALID
 * 	- '0.0X__X00'	VALID (from last X to the end all chars are 0)
 * 	- '0.00_0'		NO VALID (all 0)
 * 	- '1.0*'		NO VALID
 * 	- '1.X'  		NO VALID
 */

int	isstrfloatcerone(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (isstrfloat(str) && (*str != '.' || str[len - 1] != '.'))
	{
		if (len == 3 && \
				(!ft_strncmp(str, "1.0", 3) || !ft_strncmp(str, "0.0", 3)))
			return (1);
		if ((*str == '0' || *str == '1') && str[1] == '\0')
			return (1);
		if (*str == '0' && str[1] == '.' && \
				countchar(&str[2], '0') != (len - 2))
			return (1);
	}
	return (0);
}
