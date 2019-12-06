/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 12:48:48 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/05 19:43:19 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_position(t_player *p)
{
	p->x = 2.0f + 0.5f;
	p->y = 2.0f + 0.5f;
	p->d.x = 1.0f;
	p->d.y = 0.0f;
	p->p.x = 0.0f;
	p->p.y = 2.0f / 3.0f;
}

static void	rotate(t_vector *v, float angle)
{
	float x;
	float c;
	float s;

	x = v->x;
	c = cos(angle);
	s = sin(angle);
	v->x = v->x * c - v->y * s;
	v->y = x * s + v->y * c;
}

void		rotate_player(t_player *p, float angle)
{
	rotate(&p->d, angle);
	rotate(&p->p, angle);
}

void		move_player(t_player *p, t_map *m, float distance)
{
	if (!get_position(m, p->x + distance * p->d.x, p->y))
		p->x += distance * p->d.x;
	if (!get_position(m, p->x, p->y + distance * p->d.y))
		p->y += distance * p->d.y;
}
