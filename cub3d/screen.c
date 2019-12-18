/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 21:24:52 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/18 15:16:30 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		castfloor(t_ray *ray, t_cast *cast)
{
	ray->fx = (float)cast->map_x + (ray->side ? cast->wall_d : 0) +
		(!ray->side && ray->x < 0 ? 1.0f : 0);
	ray->fy = (float)cast->map_y + (ray->side ? 0 : cast->wall_d) +
		(ray->side && ray->y < 0 ? 1.0f : 0);
}

static int		hit_test(t_ray *ray, t_cast *cast, t_map *map)
{
	int		hit;

	hit = 0;
	while (!hit)
	{
		if (cast->s_dist_x < cast->s_dist_y)
		{
			cast->s_dist_x += cast->d_dis_x;
			cast->map_x += cast->step_x;
			ray->side = 0;
		}
		else
		{
			cast->s_dist_y += cast->d_dis_y;
			cast->map_y += cast->step_y;
			ray->side = 1;
		}
		if (cast->map_x < 0 || cast->map_y < 0 || cast->map_x >= map->width ||
			cast->map_y >= map->height)
			break ;
		hit = get_position(map, cast->map_x, cast->map_y);
	}
	return (hit);
}

static float	cast(t_ray *ray, t_map *map, t_player *p, t_image *tex[])
{
	t_cast		c;
	int			hit;

	c.map_x = (int)p->x;
	c.map_y = (int)p->y;
	c.d_dis_x = sqrt((ray->y * ray->y) / (ray->x * ray->x) + 1);
	c.d_dis_y = sqrt((ray->x * ray->x) / (ray->y * ray->y) + 1);
	c.step_x = (ray->x < 0 ? -1 : 1);
	c.step_y = (ray->y < 0 ? -1 : 1);
	c.s_dist_x = (ray->x < 0 ? p->x - c.map_x : c.map_x - p->x + 1) * c.d_dis_x;
	c.s_dist_y = (ray->y < 0 ? p->y - c.map_y : c.map_y - p->y + 1) * c.d_dis_y;
	ray->height = 0;
	if ((hit = hit_test(ray, &c, map)))
	{
		ray->dist = (ray->side ? (c.map_y - p->y + (1 - c.step_y) / 2) /
			ray->y : (c.map_x - p->x + (1 - c.step_x) / 2) / ray->x);
		ray->texture = tex[hit];
		c.wall_d = (ray->side ? p->x + ray->dist * ray->x : p->y +
			ray->dist * ray->y);
		c.wall_d -= floor(c.wall_d);
		ray->tex_x = (int)(c.wall_d * ray->texture->width);
		castfloor(ray, &c);
	}
	return (c.wall_d);
}

void			camera(t_mlx *data)
{
	int			x;
	t_ray		ray;
	float		cam;
	float		wall_dist;
	float		z_buffer[data->width_img];

	clear_image(data->image);
	x = 0;
	while (x < data->width_img)
	{
		cam = (float)(2.0f * x / data->width_img - 1.0f);
		ray.x = data->player.d.x + data->player.p.x * cam;
		ray.y = data->player.d.y + data->player.p.y * cam;
		wall_dist = cast(&ray, data->map, &data->player, &data->tex_no);
		ray.height = (int)floor(data->height_img / ray.dist);
		z_buffer[x] = ray.dist;
		draw_column(data, &ray, x);
		x++;
	}
	ft_do_dist_sprite(data);
	ft_check_if_visible(data, z_buffer);
	mlx_put_image_to_window(data->mlx, data->window, data->image->image, 0, 0);
}
