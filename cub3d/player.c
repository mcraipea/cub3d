/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 12:48:48 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/18 19:21:45 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void		translate_player(t_player *p, t_map *m, float distance)
{
	t_vector	vec;

	vec.x = cos(M_PI_2) * p->d.x - sin(M_PI_2) * p->d.y;
	vec.y = cos(M_PI_2) * p->d.y + sin(M_PI_2) * p->d.x;
	if (!get_position(m, p->x + distance * vec.x, p->y))
		p->x += distance * (vec.x);
	if (!get_position(m, p->x, p->y + distance * vec.y))
		p->y += distance * (vec.y);
}
