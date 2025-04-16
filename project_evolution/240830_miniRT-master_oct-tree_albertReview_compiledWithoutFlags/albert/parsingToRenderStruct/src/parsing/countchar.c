/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 07:08:07 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/19 17:26:20 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

size_t	countchar(char *str, char c)
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
