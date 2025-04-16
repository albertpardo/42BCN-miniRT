/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isfov.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:25:27 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/19 17:30:35 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	isfov(char *str)
{
	return (isstringvalueinpositiverange(str, CHAR_MAX_FOV));
}
