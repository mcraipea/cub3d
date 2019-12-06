/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 20:23:57 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/05 20:34:47 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		draw_square(t_image *i, t_color c, t_vector v, int size)
{
	int	x;
	int	y;

	y = size * 2 + size * v.y;
	while (y < size * 2 + (size * (v.y + 1)))
	{
		x = size * 2 + size * v.x;
		while (x < size * 2 + (size * (v.x + 1)))
		{
			image_set_pixel(i, x, y, clerp(get_pixel(i, x, y), c, 0.5f).value);
			x++;
		}
		y++;
	}
}

void			draw_minimap(t_mlx *data)
{
	t_vector	v;
	int			size;

	size = data->height_img / 10 / data->map->width;
	v.x = 0;
	while (v.x < data->map->width)
	{
		v.y = 0;
		while (v.y < data->map->height)
		{
			if (get_position(data->map, v.x, v.y))
				draw_square(data->image, (t_color)0xFFFFFF, v, size);
			v.y++;
		}
		v.x++;
	}
	v.x = data->player.x - 0.5f;
	v.y = data->player.y - 0.5f;
	draw_square(data->image, (t_color)0x00, v, size);
	v.x += data->player.d.x;
	v.y += data->player.d.y;
	draw_square(data->image, (t_color)0xFF0000, v, size);
}