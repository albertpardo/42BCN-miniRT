/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isstrsgnfloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 06:59:06 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/19 17:33:53 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

#define FLT_MAX_INT_CHAR "340282346638528859811704183484516925440"

/*
 * int isstrsgnfloat(char *str)
 *
 * str is valid with or whitout one point and digits
 * Checks in limits [-FLT_MAX_INT_CHAR, +FLT_MAX_INT_CHAR]
 *
 * TODO manage memory error when use ft_substr(..)
 */

static int	checkfloatlimits(char *str)
{
	int		ans;
	int		len;
	char	*tmp;

	ans = 0;
	len = ft_strichr(str, '.');
	if (len == -1)
		len = ft_strlen(str);
	tmp = ft_substr(str, 0, len);
	if (tmp != NULL)
	{
		if (len == (int) ft_strlen(FLT_MAX_INT_CHAR))
			ans = ft_strncmp(tmp, FLT_MAX_INT_CHAR, len) <= 0;
		if (len < (int) ft_strlen(FLT_MAX_INT_CHAR))
			ans = 1;
		free(tmp);
	}
	return (ans);
}

/* 
 * 	isstrsgnfloat(char *str, int onlyplus)
 *
 * if 'onlyplus == 1' only checks for valid positive float
 *	 else checks all positive and negative values
 */

int	isstrsgnfloat(char *str, int onlyplus)
{
	char	*tmp;

	if (*str == '+' || (onlyplus == 0 && *str == '-'))
		str++;
	if (countchar(str, '.') < 2)
	{
		tmp = str;
		if (ft_strlen(tmp) == 1 && *tmp == '.')
			return (0);
		while (tmp != NULL && *tmp != '\0' && (ft_isdigit(*tmp) || *tmp == '.'))
			tmp++;
		if (tmp != str && *tmp == '\0')
			return (checkfloatlimits(str));
	}
	return (0);
}
