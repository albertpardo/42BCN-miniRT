/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_onto_axis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:20:22 by jaucarri          #+#    #+#             */
/*   Updated: 2024/08/30 16:20:23 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

float	project_onto_axis(t_vector3 v, t_vector3 axis)
{
	return (v.x * axis.x + v.y * axis.y + v.z * axis.z);
}
