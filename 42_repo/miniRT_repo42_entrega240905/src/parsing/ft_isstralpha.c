/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstralpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:48:34 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/19 17:29:40 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
 * Returns:
 * - True if all chars in 'str' are alpha
 */

int	ft_isstralpha(char *str)
{
	while (str != NULL && *str != '\0' && ft_isalpha(*str))
		str++;
	if (str != NULL && *str == '\0')
		return (1);
	return (0);
}
