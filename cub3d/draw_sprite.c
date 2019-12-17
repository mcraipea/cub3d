/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:33:14 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/17 18:50:11 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_init_draw_sprite(t_mlx *data, int *j, int *n_pixel, int hp)
{
	*n_pixel = 1;
	*j = 0;
	if (hp <= data->height_img)
		*j = (data->height_img / 2) - (hp / 2);
	else
	{
		*j = 0;
		*n_pixel = (hp - data->height_img) / 2;
	}
}

static void	ft_get_tex_ypixel_sprite(t_mlx *data, int *tab, unsigned char *color)
{
	int	ypixel;
	int	n_pixel;
	int	xpixel;
	int	hp;

	n_pixel = tab[2];
	xpixel = tab[1];
	hp = tab[0];
	ypixel = (int)(data->tex_s->height * n_pixel / hp);
	if (ypixel > data->tex_s->height - 1)
		ypixel = data->tex_s->height - 1;
	if (xpixel > data->tex_s->width - 1)
		xpixel = data->tex_s->width - 1;
	color[0] = data->tex_s->ptr[ypixel * data->tex_s->stride + (xpixel * 4)];
	color[1] = data->tex_s->ptr[ypixel * data->tex_s->stride + (xpixel * 4) + 1];
	color[2] = data->tex_s->ptr[ypixel * data->tex_s->stride + (xpixel * 4) + 2];
}

static void	ft_draw_a_colum_sprite(t_mlx *data, int i, int hp, int xpixel)
{
	int				j;
	int				tab[3];
	int				n_pixel;
	unsigned char	c[3];

	ft_init_draw_sprite(data, &j, &n_pixel, hp);
	tab[0] = hp;
	tab[1] = xpixel;
	tab[2] = n_pixel;
	while (j <= (data->height_img / 2) + (hp / 2) && j < data->height_img)
	{
		ft_get_tex_ypixel_sprite(data, tab, c);
		if (!(c[0] == 255 && c[1] == 255 && c[2] == 255))
		{
			data->image->ptr[j * data->image->stride + (data->width_img - 1 - i) * 4 + 0] = (char)c[0];
			data->image->ptr[j * data->image->stride + (data->width_img - 1 - i) * 4 + 1] = (char)c[1];
			data->image->ptr[j * data->image->stride + (data->width_img - 1 - i) * 4 + 2] = (char)c[2];
			data->image->ptr[j * data->image->stride + (data->width_img - 1 - i) * 4 + 3] = (char)0;
		}
		j++;
		n_pixel += 1;
		tab[2] = n_pixel;
	}
}

void	ft_draw_sprites(t_mlx *data, int pixel, t_sprite *sprite, float wall_dist)
{
	int		i;
	int		xpixel;
	float	x_pas;

	i = pixel;
	x_pas = data->tex_s->width / sprite->spriteHeight;
	xpixel = sprite->spriteHeight - sprite->spriteHeight;
	while (i < data->width_img && xpixel < sprite->spriteHeight)
	{
		if (sprite->dist < wall_dist)
			ft_draw_a_colum_sprite(data, i, sprite->spriteWidth,
			(int)(xpixel * data->tex_s->height / sprite->spriteWidth));
		i++;
		xpixel += 1;
	}
}
