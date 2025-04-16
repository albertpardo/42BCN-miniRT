/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:10:43 by jaucarri          #+#    #+#             */
/*   Updated: 2024/08/04 18:10:45 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	my_mlx_pixel_put(t_renderer *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	render_scene(t_global *global)
{
	int			x;
	int			y;
	t_ray		primaryray;
	t_vector3	color;

	y = 0;
	while (y < global->renderer->height)
	{
		x = 0;
		while (x < global->renderer->width)
		{
			primaryray = create_primary_ray(global, x, y);
			color = render(primaryray, global);
			my_mlx_pixel_put(global->renderer, x, y, (int)(color.x
					* 255) << 16 | (int)(color.y * 255) << 8 | (int)(color.z
					* 255));
			x++;
		}
		y++;
	}
}
