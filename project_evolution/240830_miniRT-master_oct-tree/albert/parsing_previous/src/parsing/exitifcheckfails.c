/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitifcheckfails.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:16:33 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/25 12:16:36 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	exitifcheckfails(int val, char *msg)
{
	if (val == -1)
		exiterror(msg);
}
