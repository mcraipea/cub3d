/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 21:24:52 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/06 15:17:10 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_color	c(int v)
{
	t_color c;

	c.value = v;
	return (c);
}

static void		castfloor(t_ray *ray, t_cast *cast)
{
	ray->fx = (float)cast->mapX + (ray->side ? cast->wallDist : 0) + (!ray->side && ray->x < 0 ? 1.0f : 0);
	ray->fy = (float)cast->mapY + (ray->side ? 0 : cast->wallDist) + (ray->side && ray->y < 0 ? 1.0f : 0);
}

static int		hit_test(t_ray *ray, t_cast *cast, t_map *map)
{
	int		hit;
	int		blockdist;

	hit = 0;
	blockdist = 0;
	while (!hit && blockdist < VIEW_DIST)
	{
		if (cast->sideDistX < cast->sideDistY)
		{
			cast->sideDistX += cast->deltaDistX;
			cast->mapX += cast->stepX;
			ray->side = 0;
		}
		else
		{
			cast->sideDistY += cast->deltaDistY;
			cast->mapY += cast->stepY;
			ray->side = 1;
		}
		if (cast->mapX < 0 || cast->mapY < 0 || cast->mapX >= map->width || cast->mapY >= map->height)
			break ;
		hit = get_position(map, cast->mapX, cast->mapY);
		blockdist++;
	}
	return (hit);
}

void			cast(t_ray *ray, t_map *map, t_player *player, t_image *tex[], int height_img)
{
	t_cast		cast;
	int			hit;

	cast.mapX = (int)player->x;
	cast.mapY = (int)player->y;
	cast.deltaDistX = sqrt((ray->y * ray->y) / (ray->x * ray->x) + 1);
	cast.deltaDistY = sqrt((ray->x * ray->x) / (ray->y * ray->y) + 1);
	cast.stepX = (ray->x < 0 ? -1 : 1);
	cast.stepY = (ray->y < 0 ? -1 : 1);
	cast.sideDistX = (ray->x < 0 ? player->x - cast.mapX : cast.mapX - player->x + 1) * cast.deltaDistX;
	cast.sideDistY = (ray->y < 0 ? player->y - cast.mapY : cast.mapY - player->y + 1) * cast.deltaDistY;
	ray->height = 0;
	if ((hit = hit_test(ray, &cast, map)))
	{
		ray->dist = (ray->side ? (cast.mapY - player->y + (1 - cast.stepY) / 2) / ray->y : (cast.mapX - player->x + (1 - cast.stepY) / 2) / ray->x);
		ray->height = (int)floor(height_img / ray->dist);
		ray->light = 1.0f * (1.0f - ray->dist / VIEW_DIST) * (ray->side ? 0.9f : 1.f);
		ray->texture = tex[hit];
		cast.wallDist = (ray->side ? player->x + ray->dist * ray->x : player->y + ray->dist * ray->y);
		cast.wallDist -= floor(cast.wallDist);
//		ray->tex_x = (int)(cast.wallDist * ray->texture->width);
		castfloor(ray, &cast);
	}
}

/*static void		draw_floor(t_mlx *data, t_ray *ray, int x, int y)
{
	float	cur;
	float	weight;
	int		fx;
	int		fy;

	while (y < data->height_img)
	{
		cur = data->height_img / (2.0f * y - data->height_img);
		weight = cur / ray->dist;
		fx = (int)((weight * ray->fx + (1.0f - weight) * data->player.x) * data->floor->width) % data->floor->width;
		fy = (int)((weight * ray->fy + (1.0f - weight) * data->player.y) * data->floor->height) % data->floor->height;
		image_set_pixel(data->image, x, y, clerp(c(0x0), get_pixel(data->floor, fx, fy), 1.0f - cur / VIEW_DIST).value);
		fx = (int)((weight * ray->fx + (1.0f - weight) * data->player.x) * data->ceiling->width) % data->ceiling->width;
		fy = (int)((weight * ray->fy + (1.0f - weight) * data->player.y) * data->ceiling->height) % data->ceiling->height;
		image_set_pixel(data->image, x, data->height_img - y, clerp(c(0x0), get_pixel(data->ceiling, fx, fy), 1.0f - cur / VIEW_DIST).value);
		y++;
	}
}*/

static void		draw_column(t_mlx *data, t_ray *ray, int x)
{
	int			y;
	int			start;
	int			end;
	int			tex_y;

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
		tex_y = ((y - data->height_img * 0.5f + ray->height * 0.5f) * ray->texture->height) / ray->height;
		image_set_pixel(data->image, x, y++, clerp(c(0x0), get_pixel(ray->texture, ray->tex_x, tex_y), ray->light).value);
	}
//	draw_floor(data, ray, x, y);
}

void		camera(t_mlx *data)
{
	int			x;
	t_ray		ray;
	float		camera;

	camera = 0.f;
	clear_image(data->image);
	x = 0;
	while (x < data->width_img)
	{
		camera = 2.0f * x / data->width_img - 1.0f;
		ray.x = data->player.d.x + data->player.p.x * camera;
		ray.y = data->player.d.y + data->player.p.y * camera;
		cast(&ray, data->map, &data->player, data->tex, data->height_img);
		draw_column(data, &ray, x);
		x++;
	}
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx, data->window, data->image->image, 0, 0);
}
