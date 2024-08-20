/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parstoglobal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:17:08 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/20 14:23:40 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSTOGLOBAL_H
# define PARSTOGLOBAL_H

#include "miniRT.h"
#include "parsing.h"

// ---- t_sceneinf to struct used in render ---- //

void    setsceneglobal(t_sceneinf *scene, t_renderer *renderer, t_global *glb);

#endif
