/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:42:22 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/18 21:10:14 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_do_dist_sprite(t_mlx *data)
{
	int		i;

	i = 0;
	while (i < data->s_max)
	{
		data->tsprite[i].sprite_x = data->tsprite[i].x - data->player.x + 0.5;
		data->tsprite[i].sprite_y = data->tsprite[i].y - data->player.y + 0.5;
		data->tsprite[i].dist = sqrt((data->tsprite[i].sprite_x *
			data->tsprite[i].sprite_x) + (data->tsprite[i].sprite_y *
				data->tsprite[i].sprite_y));
		i++;
	}
	if (data->s_max > 1)
		ft_do_sort_sprite(data);
}

static void		ft_sprite2(t_mlx *data, t_sprite *s)
{
	s->invdet = 1.0 / (data->player.p.x * data->player.d.y - data->player.d.x
		* data->player.p.y);
	s->trans_x = s->invdet * (data->player.d.y * s->sprite_x - data->player.d.x
		* s->sprite_y);
	s->trans_y = s->invdet * (-data->player.p.y * s->sprite_x + data->player.p.x
		* s->sprite_y);
	s->sp_screen_x = (int)((data->width_img / 2) * (1 + s->trans_x /
		s->trans_y));
	s->sp_height = abs((int)(data->height_img / s->trans_y));
	s->draw_s_y = -s->sp_height / 2 + data->height_img / 2;
	if (s->draw_s_y < 0)
		s->draw_s_y = 0;
	s->draw_e_y = s->sp_height / 2 + data->height_img / 2;
	if (s->draw_e_y > data->height_img)
		s->draw_e_y = data->height_img - 1;
	s->sp_width = abs((int)(data->height_img / (s->trans_y)));
	s->draw_s_x = -s->sp_width / 2 + s->sp_screen_x;
	if (s->draw_s_x < 0)
		s->draw_s_x = 0;
	s->draw_e_x = s->sp_width / 2 + s->sp_screen_x;
	if (s->draw_e_x >= data->width_img)
		s->draw_e_x = data->width_img - 1;
}

static void		ft_sprite3(t_mlx *d, int tex_x, int i, int j)
{
	int		k;
	int		dr;
	int		tex_y;

	k = d->tsprite[i].draw_s_y - 1;
	while (++k < d->tsprite[i].draw_e_y)
	{
		dr = k * 256 - d->height_img * 128 +
			d->tsprite[i].sp_height * 128;
		tex_y = dr * 109 / d->tsprite[i].sp_height / 256;
		if ((get_pixel(d->tex_s, tex_x, tex_y).value) != 16777215)
			image_set_pixel(d->image, j, k, get_pixel(d->tex_s,
				tex_x, tex_y).value);
	}
}

void			ft_check_if_visible(t_mlx *d, float *z_buffer)
{
	int		i;
	int		j;
	int		tex_x;

	i = -1;
	while (++i < d->s_max)
	{
		ft_sprite2(d, &d->tsprite[i]);
		j = d->tsprite[i].draw_s_x - 1;
		while (++j < d->tsprite[i].draw_e_x)
		{
			tex_x = (int)(256 * (j - (-d->tsprite[i].sp_width / 2 +
				d->tsprite[i].sp_screen_x)) * 109 / d->tsprite[i].sp_width)
					/ 256;
			if (d->tsprite[i].trans_y > 0 && j > 0 && j < d->width_img
				&& d->tsprite[i].trans_y < z_buffer[j])
				ft_sprite3(d, tex_x, i, j);
		}
	}
}
