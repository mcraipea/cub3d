/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:42:22 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/11 18:53:15 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			sort(t_mlx *data, int nb_sprite)
{
	int i;
	int j;

	i = 0;
	while (data->tab_sprite[i].distance)
	{
		j = i + 1;
		while (data->tab_sprite[j].distance)
		{
			if (data->tab_sprite[i].distance < data->tab_sprite[j].distance)
				ft_swap(data->tab_sprite[i], data->tab_sprite[j]);
			j++;		
		}
	}
}


int			sprite_compare(int dist1, int dist2)
{
	return (dist1 - dist2);
}

void			sort_sprites(t_mlx *data)
{
	int i;
	
	i = 0;
	while (i < data->tab_sprite->nb_sprite)
		data->tab_sprite[i].distance = ((data->player.x - data->tab_sprite[i].pos_x) * (data->player.x - 
		data->tab_sprite[i].pos_x) + (data->player.y - data->tab_sprite[i].pos_y) *
		(data->player.y - data->tab_sprite[i].pos_y));
	ft_sort(data, data->tab_sprite->nb_sprite);
}

void			draw_sprites(t_mlx *data)
{
	sort_sprites(data);
	sprt.x = -1;
	while (++sprt.x < data->map->nb_sprite)
	{
		game_draw_sprites_init(&sprt, game);
		while (++sprt.stripe <= sprt.drawendx)
		{
			sprt.texx = (int)(256 * (sprt.stripe - (-sprt.spritewidth / 2 +
			sprt.spritescreenx)) * 512 / sprt.spritewidth / 256);
			if (sprt.transformy > 0 && sprt.stripe > 0 && sprt.stripe <
				(GAME_LX) && sprt.transformy < game->zbuffer[sprt.stripe])
			{
				sprt.y = sprt.drawstarty - 1;
				while (++sprt.y < sprt.drawendy)
					game_draw_sprites_draw(&sprt, game);
			}
		}
	}
}
