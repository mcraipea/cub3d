/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:42:22 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/17 18:55:17 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float	to_d(float radian)
{
	return (radian * (180 / 3.14159265));
}

/*static int		ft_raying_sprite(t_mlx *data, float angle_s)
{
	int	i;

	i = 0;
	(void)angle_s;
	while (i < data->width_img - 1)
	{
		//if (angle_s >= (cos(M_PI_2) * data->player.d.x - sin(M_PI_2) * data->player.d.y) && angle_s <= (cos(M_PI_2) * data->player.d.x - sin(M_PI_2) * data->player.d.y))
		return (i);
		i++;
	}
	return (-1);
}

static void	ft_zbuffer(t_mlx *data, t_sprite *sprite, float pas, float wall_dist)
{
	float	angle_s;
	int		size;
	int		pixel;

	pixel = -1;
	size = 0;
	angle_s = sprite->angle_f;
	while (size <= sprite->sizex)
	{
		pixel = ft_raying_sprite(data, angle_s);
		if (pixel != -1)
			break ;
		size++;
		angle_s += pas;
	}
	ft_draw_sprites(data, pixel, sprite->sizex - size, sprite, wall_dist);
}*/

static void	ft_init_dist_tsprite(t_mlx *data, float *distx, float *disty, int i)
{
	*distx = (data->tsprite[i].x + 0.5) - data->player.x;
	*disty = (data->tsprite[i].y + 0.5) - data->player.y;
	data->tsprite[i].dist = sqrt((*distx * *distx) + (*disty * *disty));
	data->tsprite[i].rotx = *distx / data->tsprite[i].dist;
	data->tsprite[i].roty = *disty / data->tsprite[i].dist;
}

void		ft_do_dist_sprite(t_mlx *data)
{
	int		i;
	float	distx;
	float	disty;

	i = 0;
	while (i < data->s_max)
	{
		ft_init_dist_tsprite(data, &distx, &disty, i);
		//printf("distx avec les sprite : %f\n", distx);
		if (distx > 0)
		{
			data->tsprite[i].angle = to_d(acos(fabsf(data->tsprite[i].rotx)));
			//printf("distx avec les sprite : %f\n", distx);
			if (disty > 0)
				data->tsprite[i].angle = 360 - data->tsprite[i].angle;
		}
		else
		{
			data->tsprite[i].angle = to_d(acos(fabsf(data->tsprite[i].rotx)));
			if (disty < 0)
				data->tsprite[i].angle = 90 + (90 - data->tsprite[i].angle);
			else
				data->tsprite[i].angle = 180 + data->tsprite[i].angle;
		}
		i++;
	}
	ft_do_sort_sprite(data);
}

/*static float		lissage_angle(float angle)
{
	if (angle < 0)
		angle = 360 + angle;
	else if (angle > 359)
		angle = angle - 359;
	if (angle < 0)
		angle = 360 + angle;
	else if (angle > 359)
		angle = angle - 359;
	return (angle);
}*/

void				ft_check_if_visible(t_mlx *data, float wall_dist)
{
	int		i;
	int		j;
	float	pas;
	float	invDet;
	float	transformX;
	float	transformY;

	i = 0;
	pas = 60 / (float)data->width_img;
	//printf("nb de sprite : %i\n", data->s_max);
	//printf("pas : %f\n", pas);
	while (i < data->s_max)
	{
		data->tsprite[i].spriteX = data->tsprite[i].x - data->player.x;
		data->tsprite[i].spriteY = data->tsprite[i].y - data->player.y;
		
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
		printf("drawStartX : %i\n", data->tsprite[i].drawStartX);
		data->tsprite[i].drawEndX = data->tsprite[i].spriteWidth / 2 + data->tsprite[i].spriteScreenX;
		if (data->tsprite[i].drawEndX >= data->width_img)
			data->tsprite[i].drawEndX = data->width_img - 1;
		j = data->tsprite[i].drawStartX;
		while (j < data->tsprite[i].drawEndX)
		{
			ft_draw_sprites(data, data->tsprite[i].spriteScreenX, data->tsprite, wall_dist);
			j++;
		}
		i++;
	}
}
