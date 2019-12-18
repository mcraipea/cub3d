/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:42:22 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/18 13:06:07 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_do_dist_sprite(t_mlx *data)
{
	int		i;

	i = 0;
	while (i < data->s_max)
	{
		data->tsprite[i].spriteX = data->tsprite[i].x - data->player.x;
		data->tsprite[i].spriteY = data->tsprite[i].y - data->player.y;
		data->tsprite[i].dist = sqrt((data->tsprite[i].spriteX * data->tsprite[i].spriteX)
			+ (data->tsprite[i].spriteY * data->tsprite[i].spriteY));
		i++;
	}
	ft_do_sort_sprite(data);
}

void				ft_check_if_visible(t_mlx *data, float *zBuffer)
{
	int		i;
	int		j;
	int		k;
	int		d;
	float	invDet;
	float	transformX;
	float	transformY;
	int		tex_x;
	int		tex_y;

	i = 0;
	while (i < data->s_max)
	{
		invDet = 1.0 / (data->player.p.x * data->player.d.y - data->player.d.x * data->player.p.y);

		transformX = invDet * (data->player.d.y * data->tsprite[i].spriteX - data->player.d.x * data->tsprite[i].spriteY);
		transformY = invDet * (- data->player.p.y * data->tsprite[i].spriteX + data->player.p.x * data->tsprite[i].spriteY);

		data->tsprite[i].spriteScreenX = (int)((data->width_img / 2) * (1 + transformX / transformY));

		data->tsprite[i].spriteHeight = abs((int)(data->height_img / transformY));
		
		data->tsprite[i].drawStartY = - data->tsprite[i].spriteHeight / 2 + data->height_img / 2;
		if (data->tsprite[i].drawStartY < 0)
			data->tsprite[i].drawStartY = 0;
		data->tsprite[i].drawEndY = data->tsprite[i].spriteHeight / 2 + data->height_img / 2;
		if (data->tsprite[i].drawEndY > data->height_img)
			data->tsprite[i].drawEndY = data->height_img - 1;
		
		data->tsprite[i].spriteWidth = abs((int) (data->height_img / (transformY)));
		data->tsprite[i].drawStartX = - data->tsprite[i].spriteWidth / 2 + data->tsprite[i].spriteScreenX;
		if (data->tsprite[i].drawStartX < 0)
			data->tsprite[i].drawStartX = 0;
		data->tsprite[i].drawEndX = data->tsprite[i].spriteWidth / 2 + data->tsprite[i].spriteScreenX;
		if (data->tsprite[i].drawEndX >= data->width_img)
			data->tsprite[i].drawEndX = data->width_img - 1;
		j = data->tsprite[i].drawStartX;
		while (j < data->tsprite[i].drawEndX)
		{
			tex_x = (int)(256 * (j - (- data->tsprite[i].spriteWidth / 2 + data->tsprite[i].spriteScreenX)) * 109 / data->tsprite[i].spriteWidth) / 256;
			if (transformY > 0 && j > 0 && j < data->width_img && transformY < zBuffer[j])
			{
				k = data->tsprite[i].drawStartY;
				while (k < data->tsprite[i].drawEndY)
				{
					d = k * 256 - data->height_img * 128 + data->tsprite[i].spriteHeight * 128;
           			tex_y = d * 109 / data->tsprite[i].spriteHeight / 256;
					if ((get_pixel(data->tex_s, tex_x, tex_y).value) != 16777215)
						image_set_pixel(data->image, j, k, get_pixel(data->tex_s, tex_x, tex_y).value);
					k++;
				}
			}
			j++;
		}
		i++;
	}
}
