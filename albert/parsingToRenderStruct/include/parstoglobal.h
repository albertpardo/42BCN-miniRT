/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parstoglobal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:17:08 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/21 17:26:24 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSTOGLOBAL_H
# define PARSTOGLOBAL_H

# include "miniRT.h"
# include "parsing.h"

// ---- t_sceneinf to struct used in render ---- //

void		freetglobal(t_global *glb);
t_object	*getelementscene(t_list *lst);
void		setsceneglobal(t_sceneinf *scene, t_global *glb);

#endif
