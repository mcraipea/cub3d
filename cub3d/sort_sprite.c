/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:40:17 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/17 19:13:12 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_swap_sprite(t_sprite *a, t_sprite *b)
{
	float	f_b;
	int		i_b;

	i_b = a->x;
	a->x = b->x;
	b->x = i_b;
	i_b = a->y;
	a->y = b->y;
	b->y = i_b;
	f_b = a->dist;
	a->dist = b->dist;
	b->dist = f_b;
}

void		ft_do_sort_sprite(t_mlx *data)
{
	int	i;

	i = 0;
	while (i < data->s_max - 1)
	{
		if (data->tsprite[i].dist < data->tsprite[i + 1].dist)
		{
			ft_swap_sprite(&data->tsprite[i], &data->tsprite[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}
