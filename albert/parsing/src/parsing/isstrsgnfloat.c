/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isstrsgnfloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 06:59:06 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/29 16:39:09 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define FLT_MAX_INT_CHAR "340282346638528859811704183484516925440"

/*
 * int isstrsgnfloat(char *str)
 *
 * str is valid with or whitout one point and digits
 * Checks in limits [-FLT_MAX_INT_CHAR, +FLT_MAX_INT_CHAR]
 *
 * TODO manage memory error when use ft_substr(..)
 */

/*
int	isstrsgnfloat(char *str)
{
	char	*tmp;
	int		np;
	int		len;
	int 	ans;

	len = 0;
	ans = 0;
	if (*str == '+' || *str == '-')
		str++;
	tmp = str;
	np = countchar(str, '.');
	if (np < 2)
	{
		while (tmp != NULL && *tmp != '\0' && (ft_isdigit(*tmp) || *tmp == '.'))
			tmp++;
		if (tmp != str && *tmp == '\0')
		{
			len = ft_strlen(str);
			if (np == 1)
				len = ft_strichr(str, '.');
			tmp = ft_substr(str, 0, len);
			if (tmp != NULL)
			{
				if(ft_strlen(FLT_MAX_INT_CHAR) == ft_strlen(tmp))
				{
					ans = ft_strncmp(tmp, FLT_MAX_INT_CHAR, ft_strlen(tmp)) <= 0;
					free(tmp);
					return (ans);
				}
				if(ft_strlen(FLT_MAX_INT_CHAR) > ft_strlen(tmp))
					return (1);
			}
		}
	}
	return (ans);
}
*/

static int	checkfloatlimits(char *str)
{
	int		ans;
	int		len;
	char	*tmp;

	len = ft_strichr(str, '.');
	if (len == -1)
		len = ft_strlen(str);
	tmp = ft_substr(str, 0, len);
	if (tmp != NULL)
	{
		if (len == (int) ft_strlen(FLT_MAX_INT_CHAR))
		{
			ans = ft_strncmp(tmp, FLT_MAX_INT_CHAR, len) <= 0;
			free(tmp);
			return (ans);
		}
		if (len < (int) ft_strlen(FLT_MAX_INT_CHAR))
			return (1);
		return (0);
	}
	return (0);
}

int	isstrsgnfloat(char *str)
{
	char	*tmp;

	if (*str == '+' || *str == '-')
		str++;
	tmp = str;
	if (countchar(str, '.') < 2)
	{
		while (tmp != NULL && *tmp != '\0' && (ft_isdigit(*tmp) || *tmp == '.'))
			tmp++;
		if (tmp != str && *tmp == '\0')
			return (checkfloatlimits(str));
	}
	return (0);
}
