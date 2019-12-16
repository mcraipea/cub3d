/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:42:22 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/16 18:16:54 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float	to_d(float radian)
{
	return (radian * (180 / 3.14159265));
}

static int		ft_raying_sprite(t_mlx *data, float angle_s)
{
	int	i;

	i = 0;
	while (i < data->width_img - 1)
	{
		if (angle_s >= data->player.p.x && angle_s <= data->player.d.x)
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
}

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
		if (distx > 0)
		{
			data->tsprite[i].angle = to_d(acos(fabsf(data->tsprite[i].rotx)));
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

static float		lissage_angle(float angle)
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
}

void				ft_check_if_visible(t_mlx *data, float wall_dist)
{
	int		i;
	float	pas;

	i = 0;
	pas = 60 / (float)data->width_img;
	while (i < data->s_max)
	{
		data->tsprite[i].sizey = (int)(data->height_img / data->tsprite[i].dist);
		data->tsprite[i].sizex = data->tsprite[i].sizey * 1.33;
		data->tsprite[i].angle_f = data->tsprite[i].angle - (pas *
			(data->tsprite[i].sizex / 2));
		data->tsprite[i].angle_l = data->tsprite[i].angle + (pas *
			(data->tsprite[i].sizex / 2));
		data->tsprite[i].angle_f = lissage_angle(data->tsprite[i].angle_f);
		data->tsprite[i].angle_l = lissage_angle(data->tsprite[i].angle_l);
		ft_zbuffer(data, &data->tsprite[i], pas, wall_dist);
		i++;
	}
}
