/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:21:13 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/18 19:23:30 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_position2(t_player *p)
{
	if (p->angle_start == 180)
	{
		p->d.x = 0.0f;
		p->d.y = 1.0f;
		p->p.x = -2.0f / 3.0f;
		p->p.y = 0.0f;
	}
	if (p->angle_start == 270)
	{
		p->d.x = -1.0f;
		p->d.y = 0.0f;
		p->p.x = 0.0f;
		p->p.y = -2.0f / 3.0f;
	}
}

void		init_position(t_player *p)
{
	p->x += 0.5f;
	p->y += 0.5f;
	if (p->angle_start == 90)
	{
		p->d.x = 1.0f;
		p->d.y = 0.0f;
		p->p.x = 0.0f;
		p->p.y = 2.0f / 3.0f;
	}
	if (p->angle_start == 0)
	{
		p->d.x = 0.0f;
		p->d.y = -1.0f;
		p->p.x = 2.0f / 3.0f;
		p->p.y = 0.0f;
	}
	init_position2(p);
}
