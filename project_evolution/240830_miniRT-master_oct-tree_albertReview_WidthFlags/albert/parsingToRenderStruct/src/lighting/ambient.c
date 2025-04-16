/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:08:29 by jaucarri          #+#    #+#             */
/*   Updated: 2024/09/01 11:28:38 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector3	ambient_light(int flag, t_vector3 new)
{
	static t_vector3	light = (t_vector3){0, 0, 0};

	if (flag == 1)
		light = new;
	return (light);
}
