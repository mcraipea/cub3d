/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:51:28 by mcraipea          #+#    #+#             */
/*   Updated: 2019/11/28 18:29:56 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	place_player(t_player *player, t_map *map)
{
	int	x;
	int	y;
	int	f;
			map->height = 200;
			map->width = 200;

	y = 0;
	f = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (!(f = get_tile(map, x, y)))
				break ;
			x++;
		}
		if (!f)
			break ;
		y++;
	}
	player->x = x + 0.5f;
	player->y = y + 0.5f;
}

void		init_player(t_player *player, t_map *map)
{
	place_player(player, map);
	player->d.x = 1.0f;
	player->d.y = 0.0f;
	player->p.x = 0.0f;
	player->p.y = 2.0f / 3.0f;
}

int		get_tile(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x > map->width - 1 || y > map->height - 1)
		return (0);
	return (map->values[y][x]);
}

void		rotate_player(t_player *player, float angle)
{
	player->d.x = player->d.x * cos(angle) - player->d.y * sin(angle);
	player->d.y = player->d.y * sin(angle) + player->d.y * cos(angle);
	player->p.x = player->p.x * cos(angle) - player->p.y * sin(angle);
	player->p.y = player->p.y * sin(angle) + player->p.y * cos(angle);
}

void		move_player(t_player *player, t_map *map, float distance)
{
	if (!get_tile(map, player->x + distance * player->d.x, player->y))
		player->x += distance * player->d.x;
	if (!get_tile(map, player->x, player->y + distance * player->d.y))
		player->y += distance * player->d.y;
}

int		hook_keydown(int key, data_t data)
{
	if (key == K_ESC)
		exit(EXIT_SUCCESS);
	if (key == K_LEFT)
		rotate_player(&data.player, -2.0f / 180.0f * M_PI);
	if (key == K_RIGHT)
		rotate_player(&data.player, 2.0f / 180.0f * M_PI);
	if (key == K_W)
		move_player(&data.player, &data.map, 0.05f);
	if (key == K_S)
		move_player(&data.player, &data.map, -0.05f);
	if (key == K_A)
		move_player(&data.player, &data.map, -0.05f);
	if (key == K_D)
		move_player(&data.player, &data.map, -0.05f);
//	render(data);
	return (0);
}
