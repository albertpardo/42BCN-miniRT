/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isstringvalueinpositiverange.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:28:45 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/28 06:37:04 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	alldigits(char *str)
{
	char	*tmp;

	tmp = str;
	while (tmp != NULL && *tmp != '\0' && ft_isdigit(*tmp))
		tmp++;
	if (tmp != str && *tmp == '\0')
		return (1);
	return (0);
}

/*
 * 'str' must be all digits
 * True if str is a integer >= 0 and <= 'maxintval'
 * Valid values: (X in 0 to 9)
 * - "0"
 * - "0X"
 * - "00X"
 * - "XXX"
 *
 * If 'str' contains '+' as first char and rest are digits is NOT VALID
 */

int	isstringvalueinpositiverange(char *str, char *maxintval)
{
	int	len_str;
	int	len_max;

	len_str = ft_strlen(str);
	len_max = ft_strlen(maxintval);
	if (len_str <= len_max && alldigits(str))
		if (len_str < len_max || \
			(len_str == len_max && ft_strncmp(str, maxintval, len_max) <= 0))
			return (1);
	return (0);
}
