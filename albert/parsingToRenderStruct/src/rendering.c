/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:09:17 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/21 14:18:45 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parstoglobal.h"

#define REND_WITH 1000
#define REND_HEIGHT 1000
#define REND_NAME "Ray Tracer"

int deal_key(int key, void *param)
{
    printf("key = %d, p = %p\n", key, param);
    return (0);
}

static void	setrederer(t_renderer *rdr)
{
	rdr->width = REND_WITH;
	rdr->height = REND_HEIGHT;
	rdr->mlx = mlx_init();
	rdr->win = mlx_new_window(rdr->mlx, rdr->width, rdr->height, REND_NAME);
	rdr->img = mlx_new_image(rdr->mlx, rdr->width, rdr->height);
	rdr->addr = mlx_get_data_addr(rdr->img, &rdr->bits_per_pixel, \
			&rdr->line_length, &rdr->endian);
}

void	rendering(t_sceneinf *scene)
{
	t_global	el_global;
	t_renderer	renderer;

	ft_memset(&renderer, 0, sizeof(t_global));
	setsceneglobal(scene, &renderer, &el_global);
	setrederer(&renderer);
    render_scene(&el_global);                                                   
	mlx_key_hook(renderer.win, deal_key, (void *) 0);
    mlx_put_image_to_window(renderer.mlx, renderer.win, renderer.img, 0, 0);
    mlx_loop(renderer.mlx);

	free(renderer.framebuffer);
	freetglobal(&el_global);
}
