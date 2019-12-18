/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:13:34 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/18 15:16:40 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		draw_floor(t_mlx *data, int x, int y)
{
	while (y < data->height_img)
	{
		image_set_pixel(data->image, x, y, data->sol.value);
		image_set_pixel(data->image, x, data->height_img - y,
			data->plafond.value);
		y++;
	}
}

static t_image	*draw_column2(t_mlx *data, t_ray *ray, t_image *temp)
{
	if (ray->side == 1 && ray->y < 0)
		temp = data->tex_no;
	else if (ray->side == 1 && ray->y > 0)
		temp = data->tex_so;
	else if (ray->side == 0 && ray->x > 0)
		temp = data->tex_ea;
	else
		temp = data->tex_we;
	return (temp);
}

void			draw_column(t_mlx *data, t_ray *ray, int x)
{
	int			y;
	int			start;
	int			end;
	int			tex_y;
	t_image		*temp;

	if (ray->texture == NULL)
		return ;
	start = (data->height_img - ray->height) / 2;
	end = start + ray->height;
	if (start < 0)
		start = 0;
	if (end > data->height_img - 1)
		end = data->height_img - 1;
	y = start;
	while (y < end)
	{
		tex_y = ((y - data->height_img * 0.5f + ray->height * 0.5f)
			* ray->texture->height) / ray->height;
		temp = draw_column2(data, ray, temp);
		image_set_pixel(data->image, x, y,
			get_pixel(temp, ray->tex_x, tex_y).value);
		y++;
	}
	draw_floor(data, x, y);
}
