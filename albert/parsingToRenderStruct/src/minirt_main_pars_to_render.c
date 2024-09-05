/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_main_pars_to_render.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:15:00 by apardo-m          #+#    #+#             */
/*   Updated: 2024/09/05 12:27:50 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "rendering.h"
#include "putscene.h"

int	main(int argc, char *argv[])
{
	t_sceneinf	scene;

	setsceneorexit(argc, argv[1], &scene);
	printf("\n ==== Scene Width valid Values ====");
	putsceneinfoinline(&scene);
	rendering(&scene);
	return (0);
}
